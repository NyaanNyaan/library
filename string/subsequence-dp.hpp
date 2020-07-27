#pragma once
#ifndef Nyaan_template
#include "../competitive-template.hpp"
#endif

vector<vector<int>> CalcNext(const string &S, char offset = 'a', int w = 26) {
  int n = (int)S.size();
  vector<vector<int>> res(n + 1, vector<int>(w, n));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < w; ++j) res[i][j] = res[i + 1][j];
    res[i][S[i] - offset] = i;
  }
  return res;
};

template <typename T>
vector<T> SubSequenceDP(const string &S, char offset = 'a', int w = 26) {
  auto nxt = CalcNext(S, offset, w);
  int n = S.size();
  vector<T> dp(n + 1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < w; j++) {
      if (nxt[i][j] >= n) continue;
      dp[nxt[i][j] + 1] += dp[i];
    }
  }
  dp.erase(begin(dp));
  return dp;
}