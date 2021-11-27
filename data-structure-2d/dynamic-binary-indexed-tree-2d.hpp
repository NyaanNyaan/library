#pragma once

#include "../data-structure/dynamic-binary-indexed-tree.hpp"

template <typename T>
struct DynamicFenwickTree2D {
  using BIT = DynamicFenwickTree<int, T>;
  int N, M;
  vector<BIT*> bit;
  DynamicFenwickTree2D() = default;
  DynamicFenwickTree2D(int n, int m) : N(n + 1), M(m) {
    for (int _ = 0; _ < N; ++_) bit.push_back(new BIT(M));
  }
  
  void add(int i, int j, const T& x) {
    for (++i; i < N; i += i & -i) (*bit[i]).add(j, x);
  }

  // i = [0, n), j = [0, m)
  T sum(int n, int m) const {
    if (n < 0 || m < 0) return T();
    T ret = T();
    for (; n; n -= n & -n) ret += (*bit[n]).sum(m);
    return ret;
  }

  // i = [nl, nr), j = [ml, mr)
  T sum(int nl, int ml, int nr, int mr) const {
    T ret = T();
    while (nl != nr) {
      if (nl < nr) {
        ret += (*bit[nr]).sum(ml, mr);
        nr -= nr & -nr;
      } else {
        ret -= (*bit[nl]).sum(ml, mr);
        nl -= nl & -nl;
      }
    }
    return ret;
  }
};

/*
 * @brief 動的二次元Binary Indexed Tree
 */
