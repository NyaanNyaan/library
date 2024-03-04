#define PROBLEM "https://judge.yosupo.jp/problem/counting_squarefrees"
//
#include "../../template/template.hpp"
//
#include "../../multiplicative-function/count-square-free.hpp"
using namespace Nyaan;

void q() {
  inl(N);
  out(count_square_free(N));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
