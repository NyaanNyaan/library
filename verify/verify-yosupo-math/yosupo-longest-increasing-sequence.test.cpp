#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"
//
#include "../../template/template.hpp"
//
#include "../../dp/longest-increasing-sequence.hpp"

using namespace Nyaan;
void q() {
  ini(N);
  vl a(N);
  in(a);
  auto ans = longest_increasing_sequence(a);
  out(sz(ans));
  out(ans);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
