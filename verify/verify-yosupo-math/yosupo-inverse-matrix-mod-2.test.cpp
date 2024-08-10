#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix_mod_2"
//
#include "../../template/template.hpp"
//
#include "../../matrix/f2-matrix.hpp"
using namespace Nyaan;

void q() {
  ini(N);
  F2_Matrix<4096, 4096> m(N, N);
  rep(i, N) {
    ins(S);
    m[i] = bitset<4096>{Rev(S)};
  }
  auto [f, ans] = m.inverse();
  if (!f) {
    out(-1);
  } else {
    rep(i, N) cout << Rev(ans[i].to_string()).substr(0, N) << "\n";
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
