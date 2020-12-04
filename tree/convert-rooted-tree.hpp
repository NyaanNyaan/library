#pragma once



template <typename G>
G convert_rooted_tree(const G& g, int root = 0, bool inverse = false) {
  int N = (int)g.size();
  G rg(N);
  vector<char> v(N);
  v[root] = 1;
  queue<int> que;
  que.emplace(root);
  while (!que.empty()) {
    auto p = que.front();
    que.pop();
    for (auto& to : g[p]) {
      if (v[to] == 0) {
        v[to] = 1;
        que.emplace(to);
        if (inverse)
          rg[to].emplace_back(p);
        else
          rg[p].emplace_back(to);
      }
    }
  }
  return rg;
}