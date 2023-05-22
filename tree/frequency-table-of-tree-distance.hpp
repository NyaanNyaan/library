#pragma once

#include "../ntt/arbitrary-ntt-mod18446744069414584321.hpp"
#include "../ntt/arbitrary-ntt.hpp"
#include "./centroid-decomposition.hpp"

template <typename G>
struct FrequencyTableOfTreeDistance : CentroidDecomposition<G> {
  using CentroidDecomposition<G>::g;
  using CentroidDecomposition<G>::v;
  using CentroidDecomposition<G>::get_size;
  using CentroidDecomposition<G>::get_centroid;

  FrequencyTableOfTreeDistance(const G &_g)
      : CentroidDecomposition<G>(_g, false) {}

  vector<long long> count, self;

  void dfs_depth(int cur, int par, int d) {
    while ((int)count.size() <= d) count.emplace_back(0);
    while ((int)self.size() <= d) self.emplace_back(0);
    ++count[d];
    ++self[d];
    for (int dst : g[cur]) {
      if (par == dst || v[dst]) continue;
      dfs_depth(dst, cur, d + 1);
    }
  };

  vector<long long> get(int start = 0) {
    queue<int> Q;
    Q.push(get_centroid(start, -1, get_size(start, -1) / 2));
    vector<long long> ans;
    ans.reserve(g.size());
    count.reserve(g.size());
    self.reserve(g.size());

    while (!Q.empty()) {
      int r = Q.front();
      Q.pop();
      count.clear();
      v[r] = 1;
      for (auto &c : g[r]) {
        if (v[c]) continue;
        self.clear();
        Q.emplace(get_centroid(c, -1, get_size(c, -1) / 2));
        dfs_depth(c, r, 1);
        auto self2 = ntt18446744069414584321.multiply(self, self);
        while (self2.size() > ans.size()) ans.emplace_back(0);
        for (int i = 0; i < (int)self2.size(); i++) ans[i] -= self2[i];
      }
      if (count.empty()) continue;
      ++count[0];
      auto count2 = ntt18446744069414584321.multiply(count, count);
      while (count2.size() > ans.size()) ans.emplace_back(0);
      for (int i = 0; i < (int)count2.size(); i++) ans[i] += count2[i];
    }

    for (auto &x : ans) x >>= 1;
    return ans;
  }
};

/**
 * @brief 頂点間の距離の度数分布
 * @docs docs/tree/frequency-table-of-tree-distance.md
 */
