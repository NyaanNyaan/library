#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include "../../template/template.hpp"
#include "../../tree/cartesian-tree.hpp"
#include "../../tree/heavy-light-decomposition.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(N, L);
  vi a(N);
  in(a);
  vvi g;
  int root;
  tie(g, root) = CartesianTree<int>(a);
  HeavyLightDecomposition<vvi> hld(g, root);
  vi ans(N - L + 1);
  rep(i, N - L + 1) ans[i] = a[hld.lca(i, i + L - 1)];
  out(ans);
}