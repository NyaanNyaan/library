#pragma once

#include "../../template/template.hpp"

template <size_t N>
struct F2 : bitset<N> {
  template <typename... Args>
  F2(Args... args) : bitset<N>(args...) {}

  union raw_cast {
    array<uint64_t, (N + 63) / 64> a;
    F2 b;
  };

  int _Find_prev(size_t i) {
    if (i == 0) return -1;
    int n = --i / 64;
    auto& a = ((raw_cast*)(this))->a;
    // [64n, i)は中途半端なので別に処理する
    // TODO
    for (; n >= 0; --n) {
    }
    return -1;
  }

  inline int _Find_last() const { return _Find_prev(N); }

  inline int topbit(uint64_t& b, int l) {}
  inline int botbit(uint64_t& b, int l) {}

  int popcnt(size_t l, size_t r) {
    int L = l / 64, R = r / 64;
    if (L == R) {
      // TODO
    }
  }

  friend bool cmpbot(const F2& l, const F2& r) {
    return ((raw_cast*)(&l))->a < ((raw_cast*)(&r))->a;
  }

  friend bool cmptop(const F2& l, const F2& r) {
    
  }
};
