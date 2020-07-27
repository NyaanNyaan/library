#pragma once
#ifndef Nyaan_template
#include "../competitive-template.hpp"
#endif

#include "../graph/graph-template.hpp"

template <typename G, typename UPDATE, typename QUERY, typename CLEAR,
          typename RESET>
struct DSUonTree {
  G &g;
  int N;
  vector<int> sub_sz, euler, li, ri;
  int idx;
  UPDATE &update;
  QUERY &query;
  CLEAR &clear;
  RESET &reset;

  DSUonTree(G &_g, UPDATE &_update, QUERY &_query, CLEAR &_clear, RESET &_reset)
      : g(_g),
        N(_g.size()),
        sub_sz(_g.size()),
        euler(_g.size()),
        li(_g.size()),
        ri(_g.size()),
        idx(0),
        update(_update),
        query(_query),
        clear(_clear),
        reset(_reset) {
    dfs1();
    dfs2();
  }

  int dfs1(int cur = 0, int par = -1) {
    sub_sz[cur] = 1;
    if ((int)g[cur].size() >= 2 and g[cur][0] == par) {
      swap(g[cur][0], g[cur][1]);
    }
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      sub_sz[cur] += dfs1(dst, cur);
      if (sub_sz[dst] > sub_sz[g[cur][0]]) swap(dst, g[cur][0]);
    }
    return sub_sz[cur];
  }

  void dfs2(int cur = 0, int par = -1) {
    euler[idx] = cur;
    li[cur] = idx++;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      dfs2(dst, cur);
    }
    ri[cur] = idx;
  }

  void dsu(int cur = 0, int par = -1, int keep = 1) {
    // light edge -> run dfs and clear data
    for (int i = 1; i < (int)g[cur].size(); i++)
      if (g[cur][i] != par) dsu(g[cur][i], cur, false);

    // heavy edge -> run dfs and reserve data
    if (sub_sz[cur] != 1) dsu(g[cur][0], cur, true);

    // light edge -> reserve data
    if (sub_sz[cur] != 1)
      for (int i = ri[g[cur][0]]; i < ri[cur]; i++) update(euler[i]);

    // current node -> reserve data
    update(cur);

    // answer queries related to subtree of current node
    query(cur);

    // if keep is false, clear all data
    if (!keep) {
      for (int i = li[cur]; i < ri[cur]; i++) clear(euler[i]);
      reset();
    }
    return;
  }

  void run() { dsu(); }
};

/*
  // reflect data of node i
  auto update = [&](int i) {

  };
  // answer queries of subtree i
  auto query = [&](int i) {

  };
  // below two function are called if all data must be deleted
  // delete data of node i (if necesarry)
  auto clear = [&](int i) {

  };
  // delete data related to all (if necesarry)
  auto reset = [&]() {

  };
  DSUonTree<decltype(g), decltype(update), decltype(query), decltype(clear),
            decltype(reset)>
      dsu(g, update, query, clear, reset);
  dsu.run();
*/