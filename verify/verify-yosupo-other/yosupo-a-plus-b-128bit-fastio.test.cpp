#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"
//
#include "../../template/template.hpp"
//
#include "../../misc/fastio.hpp"
using namespace Nyaan;

void q() {
  int T;
  rd(T);
  while (T--) {
    i128 a, b;
    rd(a, b);
    wtn(a + b);
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
