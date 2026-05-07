#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix_mod_2"
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
  auto [f, ans] = m.inverse();
  if (!f) {
    out(-1);
  } else {
    rep(i, N) out(Rev(ans[i].to_string()));
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
