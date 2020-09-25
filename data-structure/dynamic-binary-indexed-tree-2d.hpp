#pragma once
#include <bits/stdc++.h>
#include <immintrin.h>
using namespace std;

#include "hash-map-variable-length.hpp"

template <typename T>
struct DynamicBinaryIndexedTree2D {
  using i32 = int32_t;
  using u32 = uint32_t;
  using u64 = uint64_t;
  u32 N, M;
  HashMap<u64, T> dat;

  DynamicBinaryIndexedTree2D() = default;
  DynamicBinaryIndexedTree2D(u32 n, u32 m) : N(n + 1), M(m + 1) {
    assert(N < (1LL << 30));
    assert(M < (1LL << 30));
  }

 private:
  inline u64 id(u32 n, u32 m) const { return (u64(n) << 32) | u32(m); }

  inline u64 get(u32 n, u32 m) const {
    T* p = dat.find(id(n, m));
    return p ? *p : T();
  }

 public:
  __attribute__((target("bmi"))) void add(u32 n, u32 m, T k) {
    for (++n, ++m; n <= N; n += _blsi_u32(n))
      for (u32 j = m; j <= M; j += _blsi_u32(j)) dat[id(n, j)] += k;
  }

  __attribute__((target("bmi"))) T sum(i32 n, i32 m) const {
    if (n < 0 || m < 0) return T();
    T ret = T();
    for (u32 i = n; i > 0; i = _blsr_u32(i))
      for (u32 j = m; j > 0; j = _blsr_u32(j)) ret += get(i, j);
    return ret;
  }

  T sum(i32 nl, i32 ml, i32 nr, i32 mr) const {
    return sum(nr, mr) - sum(nr, ml) - sum(nl, mr) + sum(nl, ml);
  }
};
