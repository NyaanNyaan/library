#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

#include "binary-indexed-tree.cpp"

template <typename T>
struct RangeAddRangeSumBIT {
  BinaryIndexedTree<T> a, b;
  RMQandRAQ(int N) : a(N + 1), b(N + 1) {}

  // [l, r)
  void add(int l, int r, T x) {
    a.add(l, x);
    a.add(r, -x);
    b.add(l, x * (1 - l));
    b.add(r, x * (r - 1));
  }

  // [l, r)
  T sum(T l, T r) {
    --r, --l;
    return a.sum(r) * r + b.sum(r) - a.sum(l) * l - b.sum(l);
  }
};