#pragma once

#include <functional>
#include <vector>
using namespace std;

#include "monotone-minima.hpp"

// 辺コストが monge である DAG の D 辺 0-N 最短路
vector<long long> enumerate_monge_d_edge_shortest_path(
    int N, const function<long long(int, int)>& f,
    long long unreached = (1LL << 62) - 1) {
  using T = __int128_t;
  T INF = (T{1} << (sizeof(T) * 8 - 2)) - 1;
  vector<long long> ans(N + 1, unreached);
  vector<T> dp(N + 1, INF);
  dp[0] = 0;
  for (int d = 1; d <= N; d++) {
    vector<int> midx = monotone_minima<T>(N + 1, N + 1, [&](int j, int i) -> T {
      return i < j ? dp[i] + f(i, j) : INF;
    });
    for (int i = N; i >= d; i--) dp[i] = dp[midx[i]] + f(midx[i], i);
    ans[d] = dp[N];
  }
  return ans;
}

/**
 * @brief monge グラフ上の d-辺最短路の d=1,...,N における列挙
 */
