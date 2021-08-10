#pragma once

#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <functional>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

#include "graph.hpp"
#include "random.hpp"

// ジェネレータ本体
struct UndirectedGraphGenerator {
 private:
  // 乱数生成器 (staticメンバ変数の代わり)
  Random& _gen() {
    static Random gen{};
    return gen;
  }
  // [l, r]上の一様乱数を生成
  long long random(long long l, long long r) {
    assert(l <= r && "UndirectedGraphGenerator::random(l, r)");
    return _gen().uniform(l, r);
  }
  // vをランダムにシャッフル
  template <typename U>
  void random_shuffle(vector<U>& v) {
    _gen().shuffle(begin(v), end(v));
  }

  W _w_min, _w_max;

  // 辺の重みを設定
  void set_weight(bool weighted, W w_min, W w_max) {
    _w_min = w_min, _w_max = w_max;
    if (!weighted) _w_min = _w_max = 1;
  }

  // 辺を追加
  void add_edge(Graph& g, int i, int j) {
    W w = _w_min == _w_max ? _w_min : random(_w_min, _w_max);
    g.add_undirected_edge(i, j, w);
  }

  // 乱数生成s
  unsigned long long random_seed() const {
    unsigned long long seed =
        chrono::duration_cast<chrono::nanoseconds>(
            chrono::high_resolution_clock::now().time_since_epoch())
            .count();
    return seed;
  }

 public:
  UndirectedGraphGenerator(unsigned long long seed = 0) : _w_min(1), _w_max(1) {
    if (seed == 0) seed = random_seed();
    set_seed(seed);
  }

  // シードを設定する
  void set_seed(unsigned long long seed) { _gen() = Random{seed ^ 1333uLL}; }

  /**
   * ランダムケース生成用。
   *  条件を満たす全ての関数の中からランダムに1つを選んでグラフを生成。
   */
  Graph test(int n, bool is_tree = true, bool weighted = false, W w_min = 1,
             W w_max = 1) {
    using F = Graph (UndirectedGraphGenerator::*)(int, bool, W, W);
    vector<F> f{tree, path, star, perfect, simple, namori, simple_sparse};
    int mx = is_tree ? 2 : 6;
    return (this->*f[random(0, mx)])(n, weighted, w_min, w_max);
  }

  // ランダムな無向の木を出力
  Graph tree(int n, bool weighted = false, W w_min = 1, W w_max = 1) {
    set_weight(weighted, w_min, w_max);
    Graph g(n, weighted);
    if (n == 2) add_edge(g, 0, 1);
    if (n <= 2) return g;
    vector<int> code(n - 2), deg(n, 1);
    for (auto& i : code) i = random(0, n - 1), deg[i]++;
    set<int> js;
    for (int j = 0; j < n; j++) {
      if (deg[j] == 1) js.insert(j);
    }
    for (auto& i : code) {
      int j = *js.begin();
      add_edge(g, i, j);
      js.erase(begin(js));
      if (--deg[i] == 1) js.insert(i);
      deg[j]--;
    }
    int u = *js.begin(), v = *next(js.begin());
    add_edge(g, u, v);
    assert(g.edges_size() == n - 1);
    return g;
  }

  // ランダムな無向のパスグラフを出力
  Graph path(int n, bool weighted = false, W w_min = 1, W w_max = 1) {
    set_weight(weighted, w_min, w_max);
    vector<int> ord(n);
    iota(begin(ord), end(ord), 0);
    random_shuffle(ord);
    Graph g(n, weighted);
    for (int i = 0; i < n - 1; i++) add_edge(g, ord[i], ord[i + 1]);
    return g;
  }

  // ランダムな無向のスターグラフを出力
  Graph star(int n, bool weighted = false, W w_min = 1, W w_max = 1) {
    set_weight(weighted, w_min, w_max);
    vector<int> ord(n);
    iota(begin(ord), end(ord), 0);
    random_shuffle(ord);
    Graph g(n, weighted);
    for (int i = 1; i < n; i++) add_edge(g, ord[0], ord[i]);
    return g;
  }

  // 完全グラフ
  Graph perfect(int n, bool weighted = false, W w_min = 1, W w_max = 1) {
    set_weight(weighted, w_min, w_max);
    Graph g(n, weighted);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) add_edge(g, i, j);
    }
    return g;
  }

  // 単純グラフ
  Graph simple(int n, bool weighted = false, W w_min = 1, W w_max = 1) {
    set_weight(weighted, w_min, w_max);
    Graph g(n, weighted);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (random(0, 1) == 1) add_edge(g, i, j);
      }
    }
    return g;
  }

  // なもりグラフ
  Graph namori(int n, bool weighted = false, W w_min = 1, W w_max = 1) {
    set_weight(weighted, w_min, w_max);
    Graph g(n, weighted);
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        add_edge(g, i, random(1, n - 1));
      } else {
        add_edge(g, i, random(0, i - 1));
      }
    }
    return g;
  }

  // 疎な単純グラフ
  Graph simple_sparse(int n, bool weighted = false, W w_min = 1, W w_max = 1) {
    set_weight(weighted, w_min, w_max);
    if (n == 0) return Graph{};
    int m = random(0, n - 1);
    set<pair<int, int>> es;
    while ((int)es.size() < m) {
      int i = random(0, n - 1);
      int j = random(0, n - 1);
      if (i >= j) continue;
      es.emplace(i, j);
    }
    Graph g(n, weighted);
    for (auto& [i, j] : es) add_edge(g, i, j);
    return g;
  }
} undirected;
