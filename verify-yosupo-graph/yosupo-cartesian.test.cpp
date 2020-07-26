#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include "../competitive-template.cpp"
#include "../tree/cartesian-tree.cpp"

void solve(){
  ini(N);
  vl a(N);
  in(a);
  auto [g, root] = CartesianTree<ll>(a);
  vl ans(N);
  ans[root] = root;
  rep(i,N){
    each(j,g[i]) ans[j] = i;
  }
  out(ans);
}