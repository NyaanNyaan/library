#pragma once

#include <utility>
#include <vector>
using namespace std;

#include "../graph/graph-template.hpp"

// return value : pair<graph, root>
template <typename T>
pair<vector<vector<int>>, int> CartesianTree(vector<T> &a) {
  int N = (int)a.size();
  vector<vector<int>> g(N);
  vector<int> p(N, -1), st;
  st.reserve(N);
  for (int i = 0; i < N; i++) {
    int prv = -1;
    while (!st.empty() && a[i] < a[st.back()]) {
      prv = st.back();
      st.pop_back();
    }
    if (prv != -1) p[prv] = i;
    if (!st.empty()) p[i] = st.back();
    st.push_back(i);
  }
  int root = -1;
  for (int i = 0; i < N; i++) {
    if (p[i] != -1)
      g[p[i]].push_back(i);
    else
      root = i;
  }
  return make_pair(g, root);
}

/**
 * @brief Cartesian Tree
 * @docs docs/tree/cartesian-tree.md
 */