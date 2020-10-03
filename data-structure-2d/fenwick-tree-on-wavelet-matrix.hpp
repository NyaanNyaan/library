#include <immintrin.h>
#include <x86intrin.h>
//
#include <bits/stdc++.h>

using namespace std;

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
  __attribute__((optimize("O3", "unroll-loops"))) void init(int _n) {
    n = zeros = _n;
    block.resize(n / w + 1, 0);
    count.resize(block.size(), 0);
  }

  __attribute__((target("popcnt"))) void build() {
    for (u32 i = 1; i < block.size(); ++i)
      count[i] = count[i - 1] + _popcnt64(block[i - 1]);
    zeros = rank0(n);
  }

  inline u32 rank0(u32 i) const { return i - rank1(i); }
  __attribute__((target("bmi2", "popcnt"))) inline u32 rank1(u32 i) const {
    return count[i / w] + _popcnt64(_bzhi_u64(block[i / w], i % w));
  }
};

template <typename S, typename T>
struct WaveletMatrix {
  using u32 = uint32_t;
  using i64 = int64_t;
  using u64 = uint64_t;

  struct BIT {
    int N;
    vector<T> data;

    BIT() = default;
    BIT(int size) { init(size); }

    void init(int size) {
      N = size;
      data.assign(N + 1, 0);
    }

    void add(int k, T x) {
      for (++k; k <= N; k += k & -k) data[k] += x;
    }

    T sum(int k) const {
      T ret = T();
      for (; k; k -= k & -k) ret += data[k];
      return ret;
    }

    inline T sum(int l, int r) const {
      T ret = T();
      while (l != r) {
        if (l < r) {
          ret += data[r];
          r -= r & -r;
        } else {
          ret -= data[l];
          l -= l & -l;
        }
      }
      return ret;
    }
  };

  using P = pair<S, S>;
  int n, lg;
  vector<bit_vector> bv;
  vector<BIT> bit;
  vector<P> ps;
  vector<S> ys;

  WaveletMatrix() {}

  void add_point(S x, S y) {
    ps.emplace_back(x, y);
    ys.emplace_back(y);
  }

  __attribute__((optimize("O3"))) void build() {
    sort(begin(ps), end(ps));
    ps.erase(unique(begin(ps), end(ps)), end(ps));
    n = ps.size();
    sort(begin(ys), end(ys));
    ys.erase(unique(begin(ys), end(ys)), end(ys));
    vector<u32> cur(n), nxt(n);
    for (int i = 0; i < n; ++i) cur[i] = yid(ps[i].second);
    lg = __lg(max(int(n) - 1, 1)) + 1;
    bv.assign(lg, n);
    bit.assign(lg + 1, n);
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
    assert(ps[i] == P(x, y));
    bit[lg].add(i, val);
    for (int h = lg - 1; h >= 0; --h) {
      int i0 = bv[h].rank0(i);
      if (bv[h].get(i))
        i += bv[h].zeros - i0;
      else
        i = i0;
      bit[h].add(i, val);
    }
  }

  T sum(int l, int r, u32 upper) const {
    trc(l, r, upper);
    if (upper >= u32(1 << lg)) return bit[lg].sum(l, r);
    T res = 0;
    for (int h = lg; h--;) {
      int l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
      if ((upper >> h) & 1) {
        res += bit[h].sum(l0, r0);
        l += bv[h].zeros - l0;
        r += bv[h].zeros - r0;
      } else {
        l = l0, r = r0;
      }
    }
    return res;
  }

  T sum(S lx, S ly, S rx, S ry) const {
    int l = xid(lx), r = xid(rx);
    return sum(l, r, yid(ry)) - sum(l, r, yid(ly));
  }
};