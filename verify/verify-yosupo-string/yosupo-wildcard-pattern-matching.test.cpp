#define PROBLEM "https://judge.yosupo.jp/problem/wildcard_pattern_matching"
//
#include "../../template/template.hpp"
//
#include "../../string/wildcard-pattern-matching.hpp"
using namespace Nyaan;

void q() {
  ins(S, T);
  auto ans = wildcard_pattern_matching(S, T, '*');
  each(x, ans) cout << x;
  cout << "\n";
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
