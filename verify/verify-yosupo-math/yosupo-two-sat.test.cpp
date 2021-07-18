#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "../../math/two-sat.hpp"
#include "../../template/template.hpp"

using namespace Nyaan;
void Nyaan::solve() {
  ins(p, cnf);
  ini(N, M);
  two_sat sat(N);
  rep(_, M) {
    ini(a, b, c);
    int A = abs(a) - 1, B = abs(b) - 1;
    if (a < 0) A = ~A;
    if (b < 0) B = ~B;
    sat.add_clause(A, B);
  }

  auto ans = sat.answer();
  if (ans.empty()) {
    out("s UNSATISFIABLE");
    return;
  }
  out("s SATISFIABLE");
  cout << "v ";
  rep(i, N) cout << (ans[i] ? (i + 1) : -(i + 1)) << " ";
  cout << "0\n";
}
