#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank_mod_2"
//
#include "../../template/template.hpp"
//
#include "../../matrix/f2-dynamic-matrix.hpp"

using namespace Nyaan;

void q() {
  ini(N, M);
  F2_Dynamic_Matrix m(min(N, M), max(N, M));
  rep(i, N) {
    ins(S);
    rep(j, M) m[N < M ? i : j][N < M ? j : i] = S[j] - '0';
  }
  out(m.sweep());
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
