#include "../../template/template.hpp"

template <size_t N>
struct F2 : bitset<N> {
  template <typename... Args>
  F2(Args... args) : bitset<N>(args...) {}

  union raw_cast {
    array<uint64_t, (N + 63) / 64> a;
    F2 b;
  };

  bool operator<(const F2& r) {
    return ((raw_cast*)(this))->a < ((raw_cast*)(&r))->a;
  }

  int _Find_last() {
    auto& a = ((raw_cast*)(this))->a;
    int n = (N + 63) / 64 - 1;
    for (; n >= 4; n -= 4) {
      bool f0 = !!a[n];
      bool f1 = !!a[n - 1];
      bool f2 = !!a[n - 2];
      bool f3 = !!a[n - 3];
      bool f = f0 | f1 | f2 | f3;
      if (f) return f0 ? n : f1 ? n - 1 : f2 ? n - 2 : n - 3;
    }
    for (; n >= 0; --n) {
      if (!!a[n]) return n;
    }
    return -1;
  }
};
