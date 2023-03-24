#pragma once

#include "../misc/rng.hpp"

// input: [c \in [0, n)] * (n-2), n>=3
vector<vector<int>> pruefer_code(const vector<int>& code) {
  int n = code.size() + 2;
  assert(n > 2);
  vector<vector<int>> g(n);
  vector<int> deg(n, 1);
  int e = 0;
  for (auto& x : code) deg[x]++;
  set<int> ps;
  for (int j = 0; j < n; j++) {
    if (deg[j] == 1) ps.insert(j);
  }
  for (auto& i : code) {
    if (ps.empty()) break;
    int j = *begin(ps);
    ps.erase(j);
    g[i].push_back(j);
    g[j].push_back(i);
    if (deg[i] == 1) ps.erase(i);
    deg[i]--, deg[j]--;
    if (deg[i] == 1) ps.insert(i);
    e++;
  }
  int u = -1, v = -1;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 1) (u == -1 ? u : v) = i;
  }
  assert(u != -1 and v != -1);
  g[u].push_back(v);
  g[v].push_back(u);
  e++;
  assert(e == n - 1);
  return g;
}

vector<vector<int>> random_tree(int n) {
  if (n <= 2) {
    vector<vector<int>> g(n);
    if (n == 2) {
      g[0].push_back(1);
      g[1].push_back(0);
    }
    return g;
  }
  vector<int> pruefer(n - 2);
  for (auto& x : pruefer) x = randint(0, n);
  return pruefer_code(pruefer);
}

/**
 * @brief Pruefer Code
 */
