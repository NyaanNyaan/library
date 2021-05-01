#pragma once

#include "../inner/inner-hash.hpp"

template <typename G>
struct TreeHash {
  using H = inner::Hash<8>;
  using u64 = unsigned long long;

  const G& g;
  int n;
  vector<H> hash;
  vector<u64> xs;
  vector<int> depth;

  TreeHash(const G& _g, int root = 0) : g(_g), n(g.size()) {
    auto rand_time =
        chrono::duration_cast<chrono::nanoseconds>(
            chrono::high_resolution_clock::now().time_since_epoch())
            .count();
    mt19937_64 rng(rand_time);

    hash.resize(n);
    depth.resize(n, 0);
    xs.resize(n);
    for (auto& i : xs) i = rng() % H::md;
    dfs(root, -1);
  }

 private:
  int dfs(int c, int p) {
    int dep = 0;
    for (auto& d : g[c]) {
      if (d != p) dep = max(dep, dfs(d, c) + 1);
    }
    H x = H::set(xs[dep]), h = H::set(1);
    for (auto& d : g[c]) {
      if (d != p) h = h * (x + hash[d]);
    }
    hash[c] = h;
    return depth[c] = dep;
  }
};

/**
 * @brief 根付き木のハッシュ
 */
