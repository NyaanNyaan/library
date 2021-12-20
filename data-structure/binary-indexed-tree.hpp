#pragma once

template <typename T>
struct BinaryIndexedTree {
  int N;
  vector<T> data;

  BinaryIndexedTree() = default;

  BinaryIndexedTree(int size) { init(size); }

  void init(int size) {
    N = size + 2;
    data.assign(N + 1, {});
  }

  // get sum of [0,k]
  T sum(int k) const {
    if (k < 0) return T{};  // return 0 if k < 0
    T ret{};
    for (++k; k > 0; k -= k & -k) ret += data[k];
    return ret;
  }

  // getsum of [l,r]
  inline T sum(int l, int r) const { return sum(r) - sum(l - 1); }

  // get value of k
  inline T operator[](int k) const { return sum(k) - sum(k - 1); }

  // data[k] += x
  void add(int k, T x) {
    for (++k; k < N; k += k & -k) data[k] += x;
  }

  // range add x to [l,r]
  void imos(int l, int r, T x) {
    add(l, x);
    add(r + 1, -x);
  }

  // minimize i s.t. sum(i) >= w
  int lower_bound(T w) {
    if (w <= 0) return 0;
    int x = 0;
    for (int k = 1 << __lg(N); k; k >>= 1) {
      if (x + k <= N - 1 && data[x + k] < w) {
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }

  // minimize i s.t. sum(i) > w
  int upper_bound(T w) {
    if (w < 0) return 0;
    int x = 0;
    for (int k = 1 << __lg(N); k; k >>= 1) {
      if (x + k <= N - 1 && data[x + k] <= w) {
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }
};

/**
 * @brief Binary Indexed Tree(Fenwick Tree)
 * @docs docs/data-structure/binary-indexed-tree.md
 */
