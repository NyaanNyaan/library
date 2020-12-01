#pragma once
#include <bits/stdc++.h>
using namespace std;

// input: [c \in [0, n)] * (n-2), n>=3
vector<vector<int>> pruefer_code(const vector<int>& code) {
  int n = code.size() + 2;
  assert(n > 2);
  vector<vector<int>> g(n);
  vector<int> deg(n, 1);
  for (auto& x : code) deg[x]++;
  for (auto& i : code) {
    for (int j = 0; j < n; j++) {
      if (deg[j] == 1) {
        g[i].push_back(j);
        g[j].push_back(i);
        deg[i]--, deg[j]--;
      }
    }
  }
  int u = -1, v = -1;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 1) (u == -1 ? u : v) = i;
  }
  g[u].push_back(v);
  g[v].push_back(u);
  return g;
}

/**
 * @brief Pruefer Code
 */
