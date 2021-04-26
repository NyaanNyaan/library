#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient"
//
#include "../../template/template.hpp"
//
#include "../../modulo/arbitrary-mod-binomial.hpp"

using namespace Nyaan;

void Nyaan::solve() {
  int T, M;
  cin >> T >> M;
  arbitrary_mod_binomial C(M);
  while (T--) {
    long long n, k;
    cin >> n >> k;
    cout << C.C(n, k) << '\n';
  }
}
