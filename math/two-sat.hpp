#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../graph/strongly-connected-components.hpp"

struct TwoSAT {
  int N;
  vector<vector<int>> g;

  TwoSAT(int n) : N(n), g(2 * n) {}

  inline int id(int node, int cond) { return node + (cond ? N : 0); }

  void add_cond(int s, int fs, int t, int ft) {
    g[id(s, !(fs))].push_back(id(t, ft));
    g[id(t, !(ft))].push_back(id(s, fs));
  };

  vector<int> run() {
    StronglyConnectedComponents<decltype(g)> scc(g);
    vector<int> ret(N);
    for (int i = 0; i < N; i++) {
      if (scc[i] == scc[N + i])
        return {};
      else
        ret[i] = scc[i] < scc[N + i];
    }
    return ret;
  }
};