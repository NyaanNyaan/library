#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
//
#include "../../template/template.hpp"
//
#include "../../prime/miller-rabin.hpp"
//
using namespace Nyaan;

void q() {
  u64 N;
  in(N);
  bool f1 = fast_factorize::miller_rabin_u64(N);
  out(f1 ? "Yes" : "No");
}

void Nyaan::solve() {
  int t = 1;
  in(t);
  while (t--) q();
}
