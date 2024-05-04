#pragma once

#include <utility>
#include <vector>
using namespace std;

template <typename G>
vector<int> centroid(const G &g) {
  const int N = (int)g.size();

  vector<pair<int, int> > st;
  st.emplace_back(0, -1);
  vector<int> sz(N), par(N);
  while (!st.empty()) {
    auto p = st.back();
    if (sz[p.first] == 0) {
      sz[p.first] = 1;
      for (auto &to : g[p.first])
        if (to != p.second) st.emplace_back(to, p.first);
    } else {
      for (auto &to : g[p.first])
        if (to != p.second) sz[p.first] += sz[to];
      par[p.first] = p.second;
      st.pop_back();
    }
  }

  vector<int> ret;
  int size = N;
  for (int i = 0; i < N; i++) {
    int val = N - sz[i];
    for (auto &to : g[i])
      if (to != par[i]) val = max(val, sz[to]);
    if (val < size) size = val, ret.clear();
    if (val == size) ret.emplace_back(i);
  }

  return ret;
}
