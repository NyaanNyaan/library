#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

template <typename T>
vector<int> TopologicalSort(T &g) {
  int N = g.size();
  vector<int> marked(N, 0), temp(N, 0), v;
  auto visit = [&](auto f, int i) -> bool {
    if (temp[i] == 1) return false;
    if (marked[i] == 0) {
      temp[i] = 1;
      for (auto &e : g[i]) {
        if (f(f, e) == false) return false;
      }
      marked[i] = 1;
      v.push_back(i);
      temp[i] = 0;
    }
    return true;
  };
  for (int i = 0; i < N; i++) {
    if (marked[i] == 0) {
      if (visit(visit, i) == false) return vector<int>();
    }
  }
  reverse(v.begin(), v.end());
  return v;
}

vector<int> GrundyNumber(vector<vector<int>> &g) {
  vector<int> topo = TopologicalSort(g);
  if ((int)topo.size() == 0) return vector<int>();
  vector<int> grundy(g.size(), 0);
  vector<int> memo(g.size() + 1, 0);
  for (int _ = (int)g.size() - 1; _ >= 0; _--) {
    int i = topo[_];
    if (g[i].size() == 0) continue;
    for (auto &x : g[i]) {
      memo[grundy[x]]++;
    }
    while (memo[grundy[i]] > 0) grundy[i]++;
    for (auto &x : g[i]) {
      memo[grundy[x]]--;
    }
  }
  return grundy;
};