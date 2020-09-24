#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BinaryLifting {
  using Data = pair<int, T>;

  const int N, LOG;
  vector<vector<Data>> table;
  T I;

  BinaryLifting(int n, int64_t lim, const T I_ = T())
      : N(n), LOG(__lg(lim) + 2), I(I_) {
    table.resize(n, vector<Data>(LOG, Data(-1, I)));
  }

  void set_next(int k, int nxt, const T& t) { table[k][0] = Data(nxt, t); }

  void build() {
    for (int k = 0; k + 1 < LOG; ++k)
      for (int i = 0; i < N; ++i) {
        int pre = table[i][k].first;
        if (pre == -1) {
          table[i][k + 1] = table[i][k];
        } else {
          table[i][k + 1].first = table[pre][k].first;
          table[i][k + 1].second = table[i][k].second + table[pre][k].second;
        }
      }
  }

  // from i, move t times
  Data query(int i, int64_t t) const {
    T d = I;
    for (int k = LOG - 1; k >= 0; k--) {
      if ((t >> k) & 1) {
        d = d + table[i][k].second;
        i = table[i][k].first;
      }
      if (i == -1) break;
    }
    return Data(i, d);
  }

  // query(i, pow(2, k))
  inline Data query_pow(int i, int k) const { return table[i][k]; }

  // assuming graph is DAG ( edge(u, v) <-> u < v )
  // find max j | j <= t, path from i to j exists
  inline Data binary_search(int i, int t) {
    int thres = i;
    T d = I;
    for (int k = LOG - 1; k >= 0; k--) {
      int nxt = table[thres][k].first;
      if(nxt != -1 && nxt <= t) {
        d = d + table[thres][k].second;
        thres = nxt;
      }
    }
    return Data(thres, d);
  }
};

template <typename T>
using Doubling = BinaryLifting<T>;

/**
 * @brief Binary Lifting(ダブリング)
 * @docs docs/misc/doubling.md
 */
