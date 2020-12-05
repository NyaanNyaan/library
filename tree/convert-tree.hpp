#pragma once

vector<vector<int>> inverse_tree(const vector<vector<int>>& g, int root = 0) {
  int N = (int)g.size();
  vector<vector<int>> rg(N);
  vector<char> v(N);
  for (int i = 0; i < N; i++)
    for (auto& j : g[i]) {
      rg[j].push_back(i);
    }
  return rg;
}

vector<vector<int>> rooted_tree(const vector<vector<int>>& g, int root = 0) {
  int N = (int)g.size();
  vector<vector<int>> rg(N);
  vector<bool> v(N, false);
  v[root] = 1;
  queue<int> que;
  que.emplace(root);
  while (!que.empty()) {
    auto p = que.front();
    que.pop();
    for (auto& e : g[p]) {
      if (v[e] == false) {
        v[e] = true;
        que.push(e);
        rg[p].push_back(e);
      }
    }
  }
  return rg;
}

/**
 * @brief 根付き木・逆辺からなる木への変換
 */
