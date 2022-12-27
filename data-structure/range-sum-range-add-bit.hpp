#pragma once

#include "binary-indexed-tree.hpp"

template <typename T>
struct RangeAddRangeSumBIT {
  BinaryIndexedTree<T> a, b;
  RangeAddRangeSumBIT(int N) : a(N + 1), b(N + 1) {}

  // add x to [l, r)
  void add(int l, int r, T x) {
    a.add(l, x);
    a.add(r, -x);
    b.add(l, x * (1 - l));
    b.add(r, x * (r - 1));
  }

  // return sum of [l, r)
  T sum(int l, int r) {
    --r, --l;
    return a.sum(r) * r + b.sum(r) - a.sum(l) * l - b.sum(l);
  }
};