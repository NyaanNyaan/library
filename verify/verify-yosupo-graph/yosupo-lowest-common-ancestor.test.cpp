#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../competitive-template.hpp"
#include "../../graph/graph-utility.hpp"
#include "../../tree/heavy-light-decomposition.hpp"

void solve(){
  ini(N,Q);
  vvi g(N);
  rep1(i,N-1){
    ini(j);
    g[j].pb(i);
  }
  HeavyLightDecomposition<vvi> hld(g);
  rep(_,Q){
    ini(u,v);
    out(hld.lca(u,v));
  }
}