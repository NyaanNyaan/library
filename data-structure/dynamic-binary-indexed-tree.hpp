#pragma once

#include "hash-map-variable-length.hpp"

template <typename S, typename T>
struct DynamicFenwickTree {
  S N;
  HashMap<S, T> data;
  explicit DynamicFenwickTree() = default;
  explicit DynamicFenwickTree(S size) { N = size + 1; }

  void add(S k, T x) {
    for (++k; k < N; k += k & -k) data[k] += x;
  }

  // [0, k)
  T sum(S k) const {
    if (k < 0) return 0;
    T ret = T();
    for (; k > 0; k -= k & -k) {
      const T* p = data.find(k);
      ret += p ? *p : T();
    }
    return ret;
  }

  // [a, b)
  T sum(S a, S b) const { return sum(b) - sum(a); }

  T operator[](S k) const { return sum(k + 1) - sum(k); }

  S lower_bound(T w) {
    if (w <= 0) return 0;
    S x = 0;
    for (S k = 1 << __lg(N); k; k >>= 1) {
      if (x + k <= N - 1 && data[x + k] < w) {
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }
};

/**
 * @brief 動的Binary Indexed Tree
 * @docs docs/data-structure/dynamic-binary-indexed-tree.md
 */
