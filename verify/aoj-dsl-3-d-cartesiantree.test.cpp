#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include "../competitive-template.cpp"
#include "../graph/cartesian-tree.cpp"
#include "../graph/heavy-light-decomposition.cpp"
void solve() {
  ini(N, L);
  vi a(N);
  in(a);
  vvi g;
  int root;
  tie(g, root) = CartesianTree<int>(a);
  trc(root);
  trc(g);
  HeavyLightDecomposition<vvi> hld(g, root);
  vi ans(N - L + 1);
  rep(i, N - L + 1) { 
    trc(hld.lca(i,i+L-1));
    ans[i] = a[hld.lca(i, i + L - 1)]; 
  }
  out(ans);
}