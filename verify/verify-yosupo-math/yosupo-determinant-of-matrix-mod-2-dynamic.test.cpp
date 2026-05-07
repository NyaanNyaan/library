#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det_mod_2"
//
#include "../../template/template.hpp"
//
#include "../../matrix/f2-dynamic-matrix.hpp"

using namespace Nyaan;

void q() {
  ini(N);
  F2_Dynamic_Matrix m(N, N);
  rep(i, N) {
    ins(S);
    m[i] = tr2::dynamic_bitset<>{Rev(S)};
  }
  out(m.determinant());
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
