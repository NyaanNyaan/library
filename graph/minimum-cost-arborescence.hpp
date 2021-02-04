#pragma once

#include "../data-structure/skew-heap.hpp"
#include "../data-structure/union-find.hpp"
#include "graph-template.hpp"

template <typename T>
Edges<T> MinimumCostArborescence(int N, int root, const Edges<T> &es) {
  using Heap = SkewHeap<T>;
  using Ptr = typename Heap::Ptr;
  UnionFind uf(N);
  vector<int> used(N, -1), from(N);
  vector<T> from_cost(N);
  vector<Ptr> come(N, nullptr);

  used[root] = root;
  vector<int> par_e(es.size(), -1), stem(N, -1), idxs;

  for (int i = 0; i < (int)es.size(); i++) {
    auto &e = es[i];
    come[e] = Heap::push(come[e], e.cost, i);
  }

  T costs = 0;

  for (int start = 0; start < N; start++) {
    if (used[start] != -1) continue;
    int cur = start;
    vector<int> chi_e;
    int cycle = 0;
    while (used[cur] == -1 || used[cur] == start) {
      used[cur] = start;
      if (come[cur] == nullptr) return {};
      int src = uf.find(es[come[cur]->idx].src);
      T cost = come[cur]->key + come[cur]->laz;
      int idx = come[cur]->idx;
      come[cur] = Heap::pop(come[cur]);
      if (src == cur) continue;

      from[cur] = src;
      from_cost[cur] = cost;
      if (stem[cur] == -1) stem[cur] = idx;
      costs += cost;
      idxs.push_back(idx);
      while (cycle) {
        par_e[chi_e.back()] = idx;
        chi_e.pop_back();
        --cycle;
      }
      chi_e.push_back(idx);

      if (used[src] == start) {
        int p = cur;
        do {
          if (come[p]) Heap::apply(come[p], -from_cost[p]);
          if (p != cur) {
            uf.unite(p, cur);
            Ptr newheap = Heap::meld(come[cur], come[p]);
            come[cur = uf.find(cur)] = newheap;
          }
          p = uf.find(from[p]);
          ++cycle;
        } while (p != cur);
      } else {
        cur = src;
      }
    }
  }

  vector<int> used_e(es.size());
  Edges<T> res;
  for (int _ = (int)idxs.size(); _--;) {
    int idx = idxs[_];
    if (used_e[idx]) continue;
    auto &e = es[idx];
    res.push_back(e);
    int x = stem[e.to];
    while (x != idx) {
      used_e[x] = true;
      x = par_e[x];
    }
  }
  return res;
}
