#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "../../competitive-template.hpp"
#include "../../math/two-sat.hpp"

void solve() {
  ins(p, cnf);
  ini(N, M);
  TwoSAT sat(N);
  rep(_, M) {
    ini(a, b, c);
    sat.add_cond(abs(a) - 1, a > 0, abs(b) - 1, b > 0);
  }
  auto ans = sat.run();
  if (ans.empty()) {
    out("s UNSATISFIABLE");
    return;
  }
  out("s SATISFIABLE");
  cout << "v ";
  rep(i, N) cout << (ans[i] ? (i + 1) : -(i + 1)) << " ";
  cout << "0\n";
}