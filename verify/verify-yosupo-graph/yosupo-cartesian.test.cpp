#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include "../../template/template.hpp"
#include "../../tree/cartesian-tree.hpp"

using namespace Nyaan; void Nyaan::solve(){
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