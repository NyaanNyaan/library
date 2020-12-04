#pragma once

template <int m>
vector<int> max_independent_set(const vector<vector<int>> &g) {
  constexpr int M = (m + 63) / 64 * 64;
  int N = g.size();
  vector<bitset<M>> bs(N);
  for (int i = 0; i < N; i++)
    for (auto &j : g[i]) bs[i][j] = bs[j][i] = 1;
  bitset<M> res, cur, ignore;
  auto dfs = [&](auto rec, int i) -> void {
    if (i == N) {
      if (cur.count() > res.count()) res = cur;
      return;
    }
    if ((bs[i] & cur).any() || (bs[i] & ~ignore).count() >= 2) {
      ignore[i] = 1;
      rec(rec, i + 1);
      ignore[i] = 0;
    }
    if ((bs[i] & cur).none()) {
      cur[i] = 1;
      rec(rec, i + 1);
      cur[i] = 0;
    }
  };
  dfs(dfs, 0);
  vector<int> res2;
  for (int i = 0; i < N; i++)
    if (res[i]) res2.push_back(i);
  return res2;
}