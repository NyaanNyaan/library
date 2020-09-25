#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "data-structure/hash-map-variable-length.hpp"

template <typename idx_t, typename data_t>
struct DynamicFenwickTree {
  idx_t N;
  HashMap<idx_t, data_t> data;
  DynamicFenwickTree(idx_t size) { N = size += 3; }

  void add(idx_t k, data_t x) {
    for (k++; k < N; k += k & -k) data[k] += x;
  }

  data_t sum(idx_t k) {
    if (k < 0) return 0;
    data_t ret = 0;
    for (k++; k > 0; k -= k & -k) ret += data[k];
    return ret;
  }

  data_t sum(idx_t a, idx_t b) { return sum(b) - sum(a - 1); }

  data_t operator[](idx_t k) { return sum(k) - sum(k - 1); }

  idx_t lower_bound(data_t w) {
    if (w <= 0) return 0;
    idx_t x = 0;
    for (idx_t k = 1 << __lg(x); k > 0; k /= 2) {
      if (x + k <= N - 1 && data[x + k] < w) {
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }

  void merge(DynamicFenwickTree<idx_t, data_t>& other) {
    if (data.size() < other.data.size()) data.swap(other.data);
    for (auto& x : other.data) data[x.fi] += x.se;
  }
};
