#pragma once

#include <vector>

#include "../data-structure/union-find.hpp"
#include "../tree/heavy-light-decomposition.hpp"
#include "graph-template.hpp"

using namespace std;

template <typename T>
struct Namori {
  using G = WeightedGraph<T>;

  int n;
  G g;

  // 部分グラフ
  vector<G> aux;

  // ループ部分の(頂点,辺の重み)
  // loop[i].se は loop[i] と loop[i+1] の間の辺
  vector<pair<int, T>> loop;

  // 頂点の対応関係
  vector<pair<int, int>> mp;

  // HL分解
  vector<HeavyLightDecomposition<G>> hld;

  Namori(int _n = 0) : _uf(_n) { init(_n); }

  void init(int _n) {
    n = _n;
    g.resize(n);
    _uf.data.resize(n);
    fill(begin(_uf.data), end(_uf.data), -1);
    _is_loop.resize(n, false);
    mp.resize(n, make_pair(-1, -1));
  }

  void add_edge(int u, int v, T w = 1) {
    assert(_built == false);
    if (_uf.same(u, v)) {
      _root = u, _adj = v, _w = w;
    } else {
      _uf.unite(u, v);
      g[u].emplace_back(u, v, w);
      g[v].emplace_back(v, u, w);
    }
    if (++_es == n) build();
  }

  void build() {
    if (_built) return;

    _buf.resize(n, -1);
    dfs1(_root, -1);

    for (int c = _adj; c >= 0; c = _buf[c]) {
      loop.emplace_back(c, -1);
      _is_loop[c] = true;
      for (auto& e : g[c]) {
        if (e == _buf[c]) loop.back().second = e.cost;
      }
    }
    assert(loop.back().first == _root);
    loop.back().second = _w;

    _h.resize(n);
    for (auto& [i, _] : loop) dfs2(i, -1);

    fill(begin(_buf), end(_buf), 0);
    for (auto& [i, _] : loop) dfs3(i);

    _uf.data.clear();
    _buf.clear();
    _is_loop.clear();

    aux.resize(loop.size());
    for (int i = 0; i < (int)loop.size(); i++) {
      int k = loop[i].first, j = 0;
      dfs4(k, i, j);
      aux[i].resize(j);

      dfs5(k);
      hld.emplace_back(aux[i]);
    }

    _h.clear();
    _built = true;
  }

  pair<int, int> idx(int i) const { return mp[i]; }

  int root(int i) const { return loop[mp[i].first].first; }

 private:
  // 初期化用の状態変数
  UnionFind _uf;
  vector<int> _buf;
  vector<bool> _is_loop;
  int _root = -1, _adj = -1, _es = 0;
  bool _built = false;
  T _w = 0;
  G _h;

  // parをメモする
  void dfs1(int c, int p) {
    for (auto& d : g[c]) {
      if (d != p) {
        _buf[d] = c;
        dfs1(d, c);
      }
    }
  }

  // _h で有向木を作る
  void dfs2(int c, int p) {
    for (auto& d : g[c]) {
      if (d == p or _is_loop[d]) continue;
      _h[c].emplace_back(c, d, d.cost);
      dfs2(d, c);
    }
  }

  // HLD用に順番替え
  void dfs3(int c) {
    _buf[c] = 1;
    for (auto& d : _h[c]) {
      dfs3(d);
      _buf[c] += _buf[d];
      if (_buf[d] > _buf[_h[c][0]]) {
        swap(_h[c][0], d);
      }
    }
  }

  // 順番をつける
  void dfs4(int c, int i, int& j) {
    mp[c] = make_pair(i, j++);
    for (auto& d : _h[c]) {
      dfs4(d, i, j);
    }
  }

  // 部分グラフを作る
  void dfs5(int c) {
    for (auto& d : _h[c]) {
      dfs5(d);
      auto [i, j] = mp[c];
      auto [_, k] = mp[d];
      aux[i][j].emplace_back(j, k, d.cost);
      // 逆辺も入れたいときはここをオンにする(動くか不明)
      // aux[i][k].emplace_back(k, j, d.cost);
    }
  }
};

/**
 * @brief Functional Graph(なもりグラフ)の分解
 * @docs docs/graph/functional-graph.md
 */
