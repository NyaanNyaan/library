#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../data-structure/radix-heap.hpp"

template <typename T>
struct FastGraph {
 private:
  struct E {
    int v;
    T c;
    E() {}
    E(const int& _v, const T& _c) : v(_v), c(_c) {}
  };
  template <typename It>
  struct Es {
    It b, e;
    It begin() const { return b; }
    It end() const { return e; }
    int size() const { return int(e - b); }
  };

  int N, M, ec;
  vector<int> head;
  vector<pair<int, E>> buf;
  vector<E> es;

  void build() {
    partial_sum(begin(head), end(head), begin(head));
    es.resize(M);
    for (auto&& [u, e] : buf) es[--head[u]] = e;
  }

 public:
  FastGraph(int _n, int _m) : N(_n), M(_m), ec(0), head(N + 1, 0) {
    buf.reserve(M);
  }
  void add_edge(int u, int v, T c) {
    buf.emplace_back(u, E{v, c});
    ++head[u];
    if ((int)buf.size() == M) build();
  }
  Es<typename vector<E>::iterator> operator[](int u) {
    return {begin(es) + head[u], begin(es) + head[u + 1]};
  }
  const Es<typename vector<E>::const_iterator> operator[](int u) const {
    return {begin(es) + head[u], begin(es) + head[u + 1]};
  }
  int size() const { return N; }
};

template <typename T>
struct DijkstraGraph {
  FastGraph<T> g;

  DijkstraGraph(int _n, int _m) : g(_n, _m) {}

  void add_edge(int u, int v, T c) { g.add_edge(u, v, c); }

  vector<T> dijkstra(int start = 0) {
    vector<T> d(g.size(), T(-1));
    RadixHeap<T, int> Q;
    d[start] = 0;
    Q.push(0, start);
    while (!Q.empty()) {
      auto p = Q.pop();
      int u = p.second;
      if (d[u] < T(p.first)) continue;
      T du = d[u];
      for (auto& [v, c] : g[u]) {
        if (d[v] == T(-1) or du + c < d[v]) {
          d[v] = du + c;
          Q.push(d[v], v);
        }
      }
    }
    return d;
  }
};

/*
 * @brief ダイクストラ法(定数倍高速化)
 * @docs docs/shortest-path/dijkstra-fast.md
 **/
