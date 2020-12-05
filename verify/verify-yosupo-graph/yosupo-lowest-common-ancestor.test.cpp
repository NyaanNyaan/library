#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../template/template.hpp"
//
#include "../../graph/graph-utility.hpp"
#include "../../tree/heavy-light-decomposition.hpp"

using namespace Nyaan;
void Nyaan::solve() {
  ini(N, Q);
  vvi g(N);
  rep1(i, N - 1) {
    ini(j);
    g[j].push_back(i);
  }
  HeavyLightDecomposition<vvi> hld(g);
  rep(_, Q) {
    ini(u, v);
    out(hld.lca(u, v));
  }
}