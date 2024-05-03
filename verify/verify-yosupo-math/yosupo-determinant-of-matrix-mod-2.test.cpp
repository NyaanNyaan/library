#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det_mod_2"
//
#include "../../template/template.hpp"
//
#include "../../matrix/f2_matrix.hpp"
using namespace Nyaan;

void q() {
  ini(N);
  F2_Matrix<4096, 4096> m(N, N);
  rep(i, N) {
    ins(S);
    m[i] = bitset<4096>{Rev(S)};
  }
  int d = m.determinant();
  out(d);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
