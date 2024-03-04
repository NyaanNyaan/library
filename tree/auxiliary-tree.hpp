#pragma once

#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

#include "heavy-light-decomposition.hpp"

template <typename G>
struct AuxiliaryTree {
  G g;
  HeavyLightDecomposition<G> hld;
  AuxiliaryTree(const G& _g, int root = 0) : g(_g), hld(g, root) {}

  // ps : 頂点集合
  // 返り値 : (aux tree, aux tree の頂点と g の頂点の対応表)
  // aux tree は 親->子 の向きの辺のみ含まれる
  // ps が空の場合は空のグラフを返す
  pair<vector<vector<int>>, vector<int>> get(vector<int> ps) {
    if (ps.empty()) return {};
    auto comp = [&](int i, int j) { return hld.down[i] < hld.down[j]; };
    sort(begin(ps), end(ps), comp);
    for (int i = 0, ie = ps.size(); i + 1 < ie; i++) {
      ps.push_back(hld.lca(ps[i], ps[i + 1]));
    }
    sort(begin(ps), end(ps), comp);
    ps.erase(unique(begin(ps), end(ps)), end(ps));

    vector<vector<int>> aux(ps.size());
    vector<int> rs;
    rs.push_back(0);
    for (int i = 1; i < (int)ps.size(); i++) {
      int l = hld.lca(ps[rs.back()], ps[i]);
      while (ps[rs.back()] != l) rs.pop_back();
      aux[rs.back()].push_back(i);
      rs.push_back(i);
    }
    return make_pair(aux, ps);
  }
};

/**
 * @brief Auxiliary Tree
 */
