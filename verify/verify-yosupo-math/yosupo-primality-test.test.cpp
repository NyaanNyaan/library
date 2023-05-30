#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
//
#include "../../template/template.hpp"
//
#include "../../misc/fastio.hpp"
//
#include "../../prime/miller-rabin.hpp"
using namespace Nyaan;

void q() {
  u64 N;
  rd(N);
  wtn(is_prime(N) ? "Yes" : "No");
}

void Nyaan::solve() {
  int t = 1;
  rd(t);
  while (t--) q();
}
