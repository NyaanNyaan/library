#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"
//
#include "../../template/template.hpp"
//
using namespace Nyaan;

void q() {
  i128 a, b;
  in(a, b);
  out(a + b);
}

void Nyaan::solve() {
  int t = 1;
  in(t);
  while (t--) q();
}
