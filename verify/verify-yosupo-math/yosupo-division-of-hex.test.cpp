#define PROBLEM "https://judge.yosupo.jp/problem/division_of_hex_big_integers"
//
#include "../../template/template.hpp"
//
#include "../../misc/timer.hpp"
//
#include "../../math/bigint-to-hex.hpp"
#include "../../math/bigint.hpp"
using namespace Nyaan;

void q() {
  Timer t;
  ins(A, B);
  bigint a = HtoB(A), b = HtoB(B);
  bigint q = a / b;
  bigint r = a - q * b;
  out(BtoH(q), BtoH(r));
}

void Nyaan::solve() {
  int t = 1;
  in(t);
  while (t--) q();
}
