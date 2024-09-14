#pragma once

template <typename T>
struct BinaryLifting {
  using Data = pair<int, T>;

  const int N, LOG;
  vector<vector<Data>> table;
  T I;

  BinaryLifting(int n, uint64_t lim, const T I_ = T())
      : N(n), LOG(__lg(max<uint64_t>(lim, 1)) + 2), I(I_) {
    table.resize(LOG, vector<Data>(n, Data(-1, I)));
  }

  void set_next(int k, int nxt, const T& t) { table[0][k] = Data(nxt, t); }

  void build() {
    for (int k = 0; k + 1 < LOG; ++k)
      for (int i = 0; i < N; ++i) {
        int pre = table[k][i].first;
        if (pre == -1) {
          table[k + 1][i] = table[k][i];
        } else {
          table[k + 1][i].first = table[k][pre].first;
          table[k + 1][i].second = table[k][i].second + table[k][pre].second;
        }
      }
  }

  // i から t 回進んだ先, (地点, モノイド和) を返す
  Data query(int i, uint64_t t) const {
    T d = I;
    for (int k = LOG - 1; k >= 0; k--) {
      if ((t >> k) & 1) {
        d = d + table[k][i].second;
        i = table[k][i].first;
      }
      if (i == -1) break;
    }
    return Data(i, d);
  }

  // query(i, pow(2, k))
  inline Data query_pow(int i, int k) const { return table[k][i]; }

  // assuming graph is DAG ( edge(u, v) <-> u < v )
  // find max j | j <= t, path from i to j exists
  inline pair<uint64_t, Data> binary_search(int i, int t) {
    int thres = i;
    T d = I;
    uint64_t times = 0;
    for (int k = LOG - 1; k >= 0; k--) {
      int nxt = table[k][thres].first;
      if (nxt != -1 && nxt <= t) {
        d = d + table[k][thres].second;
        thres = nxt;
        times += 1LL << k;
      }
    }
    return make_pair(times, Data(thres, d));
  }

  // assuming graph is DAG ( edge(u, v) <-> u < v )
  // find min j | j >= t, path from i to j exists
  inline pair<uint64_t, Data> binary_search2(int i, int t) {
    int thres = i;
    T d = I;
    uint64_t times = 0;
    for (int k = LOG - 1; k >= 0; k--) {
      int nxt = table[k][thres].first;
      if (nxt != -1 && nxt >= t) {
        d = d + table[k][thres].second;
        thres = nxt;
        times += 1LL << k;
      }
    }
    return make_pair(times, Data(thres, d));
  }
};

template <typename T>
using Doubling = BinaryLifting<T>;

/**
 * @brief Binary Lifting(ダブリング)
 * @docs docs/misc/doubling.md
 */
