#define PROBLEM "https://judge.yosupo.jp/problem/two_square_sum"
//
#include "../../template/template.hpp"
//
#include "../../math/two-square.hpp"
using namespace Nyaan;

void q() {
  inl(N);
  auto ans = two_square(N);
  out(sz(ans));
  each(p, ans) out(p);
}

void Nyaan::solve() {
  int t = 1;
  in(t);
  while (t--) q();
}
