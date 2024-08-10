#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product_mod_2"
//
#include "../../template/template.hpp"
//
#include "../../matrix/f2-matrix.hpp"
using namespace Nyaan;

void q() {
  ini(N, M, K);
  using Mat = F2_Matrix<4096, 4096>;
  Mat a(N, M), b(M, K);
  rep(i, N) {
    ins(S);
    a.A[i] = bitset<4096>{Rev(S)};
  }
  rep(i, M) {
    ins(S);
    b.A[i] = bitset<4096>{Rev(S)};
  }
  Mat c = a * b;
  rep(i, N) out(Rev(c.A[i].to_string()).substr(0, K));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
