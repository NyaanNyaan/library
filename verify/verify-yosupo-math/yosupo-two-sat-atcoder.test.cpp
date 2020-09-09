#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "../../competitive-template.hpp"
#include "../../atcoder/two-sat.hpp"

void solve() {
   ins(p, cnf);
  ini(N, M);
  two_sat sat(N);
  rep(_, M) {
    ini(a, b, c);
    sat.add_clause(abs(a) - 1, a > 0, abs(b) - 1, b > 0);
  }
  int flg = sat.satisfiable();
  if(!flg){
    out("s UNSATISFIABLE");
    return;
  }
  auto ans = sat.answer();
  out("s SATISFIABLE");
  cout<<"v ";
  rep(i,N) cout << (ans[i] ? (i + 1) : -(i + 1)) << " ";
  cout << "0\n";
}
