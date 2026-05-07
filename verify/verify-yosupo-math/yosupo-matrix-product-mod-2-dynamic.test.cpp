#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product_mod_2"
//
#include "../../template/template.hpp"
//
#include "../../matrix/f2-dynamic-matrix.hpp"

using namespace Nyaan;

void q() {
  ini(N, M, K);
  F2_Dynamic_Matrix A(N, M), B(M, K);
  rep(i, N) {
    ins(S);
    A[i] = tr2::dynamic_bitset<>{Rev(S)};
  }
  rep(i, M) {
    ins(S);
    B[i] = tr2::dynamic_bitset<>{Rev(S)};
  }
  auto C = A * B;
  rep(i, N) out(Rev(C[i].to_string()));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
