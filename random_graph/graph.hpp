#pragma once

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdint>
#include <functional>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

#include "random.hpp"

using namespace std;

// 辺の重みはlong long決め打ち
using W = long long;

// 辺の情報を格納する構造体
struct Edge {
  int u, v;
  W w;
  int idx;
  Edge(int _u, int _v, W _w = 1, int _idx = -1)
      : u(_u), v(_v), w(_w), idx(_idx) {}
};

// グラフの情報を格納する構造体
struct Graph {
 private:
  int n, m;
  vector<Edge> es;
  bool weighted;

 public:
  Graph(int _n = 0, bool _weighted = false)
      : n(_n), m(0), weighted(_weighted) {}

  int edges_size() const { return m; }

  // u -> v, 重み w の辺を追加
  // 0-indexed で追加する必要あり
  void add_directed_edge(int u, int v, W w = 1, int idx = -1) {
    es.emplace_back(u, v, w, idx);
    m++;
  }

  // min(u,v) -> max(u,v), 重み w の辺を追加
  // 0-indexed で追加する必要あり
  void add_undirected_edge(int u, int v, W w = 1, int idx = -1) {
    int mn = min(u, v), mx = max(u, v);
    add_directed_edge(mn, mx, w, idx);
  }

  // 隣接リストを返す
  vector<vector<Edge>> adjacent_list(bool directed = false) const {
    vector<vector<Edge>> g(n);
    for (auto& [u, v, w, i] : es) {
      g[u].emplace_back(u, v, w, i);
      if (!directed) g[v].emplace_back(v, u, w, i);
    }
    return g;
  }

  // 隣接行列を返す
  vector<vector<W>> adjacent_matrix(bool directed = false) const {
    vector<vector<W>> g(n, vector<W>(n, 0));
    for (auto& [u, v, w, _] : es) {
      g[u][v] = w;
      if (!directed) g[v][u] = w;
    }
    return g;
  }

  // グラフを隣接行列の形式で出力
  void print_matrix(ostream& os, bool directed = false) const {
    auto g = adjacent_matrix(directed);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        os << g[i][j] << " \n"[j == n - 1];
      }
    }
  }

  // グラフの辺情報を一般的な形式で出力
  void print_edge(ostream& os, bool origin_0 = false) const {
    for (auto& e : es) {
      os << e.u + (origin_0 ? 0 : 1);
      os << " " << e.v + (origin_0 ? 0 : 1);
      if (weighted) os << " " << e.w;
      os << "\n";
    }
  }

  // グラフを一般的な形式で出力
  void print(ostream& os, bool origin_0 = false) const {
    os << n << " " << m << "\n";
    print_edge(os, origin_0);
  }

  friend ostream& operator<<(ostream& os, const Graph& g) {
    g.print(os);
    return os;
  }
};
