
#include <immintrin.h>
//

struct bit_vector {
  using u32 = uint32_t;
  using i64 = int64_t;
  using u64 = uint64_t;

  static constexpr u32 w = 64;
  vector<u64> block;
  vector<u32> count;
  u32 n, zeros;

  inline u32 get(u32 i) const { return u32(block[i / w] >> (i % w)) & 1u; }
  inline void set(u32 i) { block[i / w] |= 1LL << (i % w); }

  bit_vector() {}
  bit_vector(int _n) { init(_n); }
  __attribute__((optimize("O3,unroll-loops"))) void init(int _n) {
    n = zeros = _n;
    block.resize(n / w + 1, 0);
    count.resize(block.size(), 0);
  }

  __attribute__((target("popcnt"))) void build() {
    for (u32 i = 1; i < block.size(); ++i)
      count[i] = count[i - 1] + _mm_popcnt_u64(block[i - 1]);
    zeros = rank0(n);
  }

  inline u32 rank0(u32 i) const { return i - rank1(i); }

  __attribute__((target("bmi2,popcnt"))) inline u32 rank1(u32 i) const {
    return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i / w], i % w));
  }
};

template <typename S, typename T, T (*f)(T, T), T (*I)()>
struct WaveletMatrix {
  using u32 = uint32_t;
  using i64 = int64_t;
  using u64 = uint64_t;

  struct SegTree {
    int N;
    int size;
    vector<T> data;

    SegTree(int _n) { init(_n); }

    void init(int _N) {
      N = _N;
      size = 1;
      while (size < N) size <<= 1;
      data.assign(2 * size, I());
    }

    void set(int k, T x) { data[k + size] = x; }

    void build() {
      for (int k = size - 1; k > 0; k--) {
        data[k] = f(data[2 * k], data[2 * k + 1]);
      }
    }

    void update(int k, T x) {
      k += size;
      data[k] = x;
      while (k >>= 1) {
        data[k] = f(data[2 * k], data[2 * k + 1]);
      }
    }

    void add(int k, T x) {
      k += size;
      data[k] += x;
      while (k >>= 1) {
        data[k] = f(data[2 * k], data[2 * k + 1]);
      }
    }

    // query to [a, b)
    T query(int a, int b) const {
      T L = I(), R = I();
      for (a += size, b += size; a < b; a >>= 1, b >>= 1) {
        if (a & 1) L = f(L, data[a++]);
        if (b & 1) R = f(data[--b], R);
      }
      return f(L, R);
    }
  };

  using P = pair<S, S>;
  int n, lg;
  vector<bit_vector> bv;
  vector<SegTree> seg;
  vector<P> ps;
  vector<S> ys;

  WaveletMatrix() {}

  void add_point(S x, S y) {
    ps.emplace_back(x, y);
    ys.emplace_back(y);
  }

  void build() {
    sort(begin(ps), end(ps));
    ps.erase(unique(begin(ps), end(ps)), end(ps));
    n = ps.size();
    sort(begin(ys), end(ys));
    ys.erase(unique(begin(ys), end(ys)), end(ys));
    vector<u32> cur(n), nxt(n);
    for (int i = 0; i < n; ++i) cur[i] = yid(ps[i].second);
    lg = __lg(max(n, 1)) + 1;
    bv.assign(lg, n);
    seg.assign(lg, n);
    for (int h = lg - 1; h >= 0; --h) {
      for (int i = 0; i < n; ++i)
        if ((cur[i] >> h) & 1) bv[h].set(i);
      bv[h].build();
      array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt) + bv[h].zeros};
      for (int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];
      swap(cur, nxt);
    }
  }

  int xid(S x) const {
    return lower_bound(
               begin(ps), end(ps), make_pair(x, S()),
               [](const P& a, const P& b) { return a.first < b.first; }) -
           begin(ps);
  }

  int yid(S y) const { return lower_bound(begin(ys), end(ys), y) - begin(ys); }

  void add(S x, S y, T val) {
    int i = lower_bound(begin(ps), end(ps), P{x, y}) - begin(ps);
    for (int h = lg - 1; h >= 0; --h) {
      int i0 = bv[h].rank0(i);
      if (bv[h].get(i))
        i += bv[h].zeros - i0;
      else
        i = i0;
      seg[h].add(i, val);
    }
  }

  T _sum(int l, int r, u32 upper) const {
    T res = I();
    for (int h = lg; h--;) {
      int l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
      if ((upper >> h) & 1) {
        res = f(res, seg[h].query(l0, r0));
        l += bv[h].zeros - l0;
        r += bv[h].zeros - r0;
      } else {
        l = l0, r = r0;
      }
    }
    return res;
  }

  T sum(S L, S D, S R, S U) const {
    int l = xid(L), r = xid(R);
    return _sum(l, r, yid(U)) - _sum(l, r, yid(D));
  }
};
