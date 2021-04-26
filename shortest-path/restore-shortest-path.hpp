#pragma once

#include "../graph/graph-utility.hpp"

// restore shortest path from S to G
template <typename T>
vector<int> restore_shortest_path(WeightedGraph<T> &g, vector<T> &d, int S,
                                  int G) {
  int N = g.size();
  WeightedGraph<T> rev(g.size());
  for (int i = 0; i < N; i++)
    for (auto &e : g[i]) rev[e.to].emplace_back(e.to, i, e.cost);
  vector<int> ret;
  ret.push_back(G);
  int p = G;
  T dist = d[G];
  vector<int> vis(N, 0);
  vis[G] = 1;
  do {
    int nxt = -1;
    T nval = numeric_limits<T>::max() / 2;
    for (auto &e : rev[p]) {
      if (vis[e.to] || d[e.to] + e.cost != dist) continue;
      if (d[e.to] != -1 && d[e.to] < nval) nval = d[e.to], nxt = e.to;
    }
    ret.push_back((vis[nxt] = 1, dist = nval, p = nxt));
  } while (p != S);
  reverse(begin(ret), end(ret));
  return ret;
}
