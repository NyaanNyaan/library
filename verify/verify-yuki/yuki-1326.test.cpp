#define PROBLEM "https://yukicoder.me/problems/no/1326"

#include "../../template/template.hpp"
//
#include "../../tree/block-cut-tree.hpp"
#include "../../graph/graph-template.hpp"
#include "../../tree/heavy-light-decomposition.hpp"

using namespace Nyaan;
void Nyaan::solve() {
  ini(n, m);
  auto g = graph(n, m);

  BlockCutTree<vvi> bct(g);
  HeavyLightDecomposition<vvi> hld(bct.aux);

  ini(Q);
  rep(i, Q) {
    ini(u, v);
    --u, --v;
    if (u == v) {
      out(0);
      continue;
    }
    int ans = hld.depth[bct.id(u)];
    ans += hld.depth[bct.id(v)];
    ans -= hld.depth[hld.lca(bct.id(u), bct.id(v))] * 2;
    ans -= bct.is_arti(u);
    ans -= bct.is_arti(v);
    out(ans / 2);
  }
}
