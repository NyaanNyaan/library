#define PROBLEM "https://judge.yosupo.jp/problem/runenumerate"
//
#include "../../template/template.hpp"
//
#include "../../string/run-enumerate.hpp"
using namespace Nyaan;

void q() {
  ins(S);
  auto ans = run_enumerate(S);
  out(sz(ans));
  for (auto& [t, l, r] : ans) out(t, l, r);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
