#pragma once

#include <functional>
#include <vector>
using namespace std;

// https://noshi91.hatenablog.com/entry/2023/02/18/005856
// 辺コストが monge である DAG の 0 - i 最短路
template <typename T>
vector<T> monge_shortest_path(int N, const function<T(int, int)>& f) {
  T INF = (T{1} << (sizeof(T) * 8 - 2)) - 1;
  vector<T> dp(N + 1, INF);
  vector<int> x(N + 1, 0);
  auto check = [&](int from, int to) {
    if (from >= to) return;
    T cost = f(from, to);
    if (dp[from] + cost < dp[to]) dp[to] = dp[from] + cost, x[to] = from;
  };
  auto dfs = [&](auto rc, int l, int r) -> void {
    if (l + 1 >= r) return;
    int m = (l + r) / 2;
    for (int i = x[l]; i <= x[r]; i++) check(i, m);
    rc(rc, l, m);
    for (int i = l + 1; i <= m; i++) check(i, r);
    rc(rc, m, r);
  };
  dp[0] = 0, check(0, N), dfs(dfs, 0, N);
  return dp;
}

/**
 * @brief monge グラフ上の最短路
 */
