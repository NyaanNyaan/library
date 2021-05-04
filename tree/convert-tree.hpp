#pragma once

#include "../graph/graph-template.hpp"

template <typename T>
struct has_cost {
 private:
  template <typename U>
  static auto confirm(U u) -> decltype(u.cost, std::true_type());
  static auto confirm(...) -> std::false_type;

 public:
  enum : bool { value = decltype(confirm(std::declval<T>()))::value };
};

template <typename T>
vector<vector<T>> inverse_tree(const vector<vector<T>>& g) {
  int N = (int)g.size();
  vector<vector<T>> rg(N);
  for (int i = 0; i < N; i++) {
    for (auto& e : g[i]) {
      if constexpr (is_same<T, int>::value) {
        rg[e].push_back(i);
      } else if constexpr (has_cost<T>::value) {
        rg[e].emplace_back(e.to, i, e.cost);
      } else {
        assert(0);
      }
    }
  }
  return rg;
}

template <typename T>
vector<vector<T>> rooted_tree(const vector<vector<T>>& g, int root = 0) {
  int N = (int)g.size();
  vector<vector<T>> rg(N);
  vector<char> v(N, false);
  v[root] = true;
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
