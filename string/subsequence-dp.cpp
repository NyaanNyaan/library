#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

vector<vector<int>> SubsequenceDP(const string &S) {
  int n = (int)S.size();
  vector<vector<int>> res(n + 1, vector<int>(26, n));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) res[i][j] = res[i + 1][j];
    res[i][S[i] - 'a'] = i;
  }
  return res;
};