#pragma once

#include <vector>
using namespace std;

template <typename mint>
vector<vector<mint>> binomial_table(int n) {
  n += 10;
  vector dp(n, vector(n, mint{0}));
  dp[0][0] = 1;
  for (int i = 0; i + 1 < n; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i + 1][j + 0] += dp[i][j];
      dp[i + 1][j + 1] += dp[i][j];
    }
  }
  return dp;
}
