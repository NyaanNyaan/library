#pragma once

#include "../data-structure/rollback-union-find.hpp"
#include "../hashmap/hashmap.hpp"

struct OffLineDynamicConnectivity {
  int N, Q, segsz;
  RollbackUnionFind uf;
  vector<vector<pair<int, int>>> seg, qadd, qdel;
  HashMap<pair<int, int>, pair<int, int>> cnt;

  OffLineDynamicConnectivity(int n, int q)
      : N(n), Q(q), uf(n), qadd(q), qdel(q) {
    segsz = 1;
    while (segsz < Q) segsz *= 2;
    seg.resize(segsz * 2);
  }

  void add_edge(int t, int u, int v) { qadd[t].emplace_back(u, v); }
  void del_edge(int t, int u, int v) { qdel[t].emplace_back(u, v); }

  void build() {
    for (int i = 0; i < Q; i++) {
      for (auto& e : qadd[i]) {
        auto& dat = cnt[e];
        if (dat.second++ == 0) dat.first = i;
      }
      for (auto& e : qdel[i]) {
        auto& dat = cnt[e];
        if (--dat.second == 0) segment(e, dat.first, i);
      }
    }
    for (auto& [e, dat] : cnt) {
      if (dat.second != 0) segment(e, dat.first, Q);
    }
  }

  template <typename ADD, typename DEL, typename QUERY>
  void dfs(const ADD& add, const DEL& del, const QUERY& query, int id, int l,
           int r) {
    if (Q <= l) return;
    int state = uf.get_state();
    vector<pair<int, int>> es;
    for (auto& [u, v] : seg[id]) {
      if (!uf.same(u, v)) {
        uf.unite(u, v);
        add(u, v);
        es.emplace_back(u, v);
      }
    }
    if (l + 1 == r) {
      query(l);
    } else {
      dfs(add, del, query, id * 2 + 0, l, (l + r) >> 1);
      dfs(add, del, query, id * 2 + 1, (l + r) >> 1, r);
    }
    for (auto& [u, v] : es) del(u, v);
    uf.rollback(state);
  }

  template <typename ADD, typename DEL, typename QUERY>
  void run(const ADD& add, const DEL& del, const QUERY& query) {
    dfs(add, del, query, 1, 0, segsz);
  }

 private:
  void segment(pair<int, int>& e, int l, int r) {
    int L = l + segsz;
    int R = r + segsz;
    while (L < R) {
      if (L & 1) seg[L++].push_back(e);
      if (R & 1) seg[--R].push_back(e);
      L >>= 1, R >>= 1;
    }
  }
};