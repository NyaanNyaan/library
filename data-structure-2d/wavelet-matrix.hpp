#pragma once

#include <immintrin.h>

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
      count[i] = count[i - 1] + _mm_popcnt_u64(block[i - 1]);
    zeros = rank0(n);
  }

  inline u32 rank0(u32 i) const { return i - rank1(i); }
  __attribute__((target("bmi2,popcnt"))) inline u32 rank1(u32 i) const {
    return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i / w], i % w));
  }
};

template <typename T>
struct WaveletMatrix {
  using u32 = uint32_t;
  using i64 = int64_t;
  using u64 = uint64_t;

  int n, lg;
  vector<T> a;
  vector<bit_vector> bv;

  WaveletMatrix(u32 _n) : n(max<u32>(_n, 1)), a(n) {}
  WaveletMatrix(const vector<T>& _a) : n(_a.size()), a(_a) { build(); }

  __attribute__((optimize("O3"))) void build() {
    lg = __lg(max<T>(*max_element(begin(a), end(a)), 1)) + 1;
    bv.assign(lg, n);
    vector<T> cur = a, nxt(n);
    for (int h = lg - 1; h >= 0; --h) {
      for (int i = 0; i < n; ++i)
        if ((cur[i] >> h) & 1) bv[h].set(i);
      bv[h].build();
      array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt) + bv[h].zeros};
      for (int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];
      swap(cur, nxt);
    }
    return;
  }

  void set(u32 i, const T& x) { 
    assert(x >= 0);
    a[i] = x; 
  }

  inline pair<u32, u32> succ0(int l, int r, int h) const {
    return make_pair(bv[h].rank0(l), bv[h].rank0(r));
  }

  inline pair<u32, u32> succ1(int l, int r, int h) const {
    u32 l0 = bv[h].rank0(l);
    u32 r0 = bv[h].rank0(r);
    u32 zeros = bv[h].zeros;
    return make_pair(l + zeros - l0, r + zeros - r0);
  }

  // return a[k]
  T access(u32 k) const {
    T ret = 0;
    for (int h = lg - 1; h >= 0; --h) {
      u32 f = bv[h].get(k);
      ret |= f ? T(1) << h : 0;
      k = f ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);
    }
    return ret;
  }

  // k-th (0-indexed) smallest number in a[l, r)
  T kth_smallest(u32 l, u32 r, u32 k) const {
    T res = 0;
    for (int h = lg - 1; h >= 0; --h) {
      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
      if (k < r0 - l0)
        l = l0, r = r0;
      else {
        k -= r0 - l0;
        res |= (T)1 << h;
        l += bv[h].zeros - l0;
        r += bv[h].zeros - r0;
      }
    }
    return res;
  }

  // k-th (0-indexed) largest number in a[l, r)
  T kth_largest(int l, int r, int k) {
    return kth_smallest(l, r, r - l - k - 1);
  }

  // count i s.t. (l <= i < r) && (v[i] < upper)
  int range_freq(int l, int r, T upper) {
    if (upper >= (T(1) << lg)) return r - l;
    int ret = 0;
    for (int h = lg - 1; h >= 0; --h) {
      bool f = (upper >> h) & 1;
      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
      if (f) {
        ret += r0 - l0;
        l += bv[h].zeros - l0;
        r += bv[h].zeros - r0;
      } else {
        l = l0;
        r = r0;
      }
    }
    return ret;
  }

  int range_freq(int l, int r, T lower, T upper) {
    return range_freq(l, r, upper) - range_freq(l, r, lower);
  }

  // max v[i] s.t. (l <= i < r) && (v[i] < upper)
  T prev_value(int l, int r, T upper) {
    int cnt = range_freq(l, r, upper);
    return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);
  }

  // min v[i] s.t. (l <= i < r) && (lower <= v[i])
  T next_value(int l, int r, T lower) {
    int cnt = range_freq(l, r, lower);
    return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);
  }
};

/*
 * @brief Wavelet Matrix
 * @docs docs/data-structure-2d/wavelet-matrix.md
 */
