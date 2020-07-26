#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

#include "./graph-template.cpp"

// LowLink ... enumerate bridge and articulation point
// bridge ... 橋 articulation point ... 関節点
template <typename G>
struct LowLink {
  int N;
  const G &g;
  vector<int> ord, low, articulation;
  vector<pair<int, int> > bridge;
  
  LowLink(const G &g) : g(g) {
    N = g.size();
    ord.resize(N, -1);
    low.resize(N, -1);
    articulation.reserve(N);
    bridge.reserve(N);
    int k = 0;
    for (int i = 0; i < N; i++) {
      if (!(~ord[i])) k = dfs(i, k, -1);
    }
    articulation.shrink_to_fit();
    bridge.shrink_to_fit();
  }

  int dfs(int idx, int k, int par) {
    low[idx] = (ord[idx] = k++);
    int cnt = 0;
    bool is_arti = false;
    for (auto &to : g[idx]) {
      if (ord[to] == -1) {
        cnt++;
        k = dfs(to, k, idx);
        low[idx] = min(low[idx], low[to]);
        is_arti |= (par != -1) && (low[to] >= ord[idx]);
        if (ord[idx] < low[to]) {
          bridge.emplace_back(minmax(idx, (int)to));
        }
      } else if (to != par) {
        low[idx] = min(low[idx], ord[to]);
      }
    }
    is_arti |= par == -1 && cnt > 1;
    if (is_arti) articulation.push_back(idx);
    return k;
  }
};