#define PROBLEM "https://judge.yosupo.jp/problem/characteristic_polynomial"
//
#include "../../template/template.hpp"
//
#include "../../matrix/characteristric-polynomial.hpp"

#include "../../modint/montgomery-modint.hpp"
using mint = LazyMontgomeryModInt<998244353>;

using namespace Nyaan;

void Nyaan::solve() {
  int N;
  cin >> N;
  vector<vector<mint>> a(N, vector(N, mint(0)));

  for (auto& v : a)
    for (auto& x : v) cin >> x;

  auto charpoly = CharacteristicPolynomial(a);

  if (charpoly.back() != 1) {
    for (auto& x : charpoly) x = -x;
  }

  for (int i = 0; i <= N; i++) {
    cout << charpoly[i] << " \n"[i == N];
  }
}
