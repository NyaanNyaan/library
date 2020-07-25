#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../competitive-template.cpp"
#include "../data-structure/sparse-table.cpp"

void solve(){
  ini(N,Q);
  vl a(N);
  in(a);
  SparseTable<ll> sparse(a);
  rep(i,Q){
    ini(l,r);
    out(sparse.query(l,r));
  }
}