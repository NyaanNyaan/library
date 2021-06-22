#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"
//
#include "../../template/template.hpp"
//
#include "../../matrix/inverse-matrix.hpp"
//
#include "../../modint/montgomery-modint.hpp"
using mint = LazyMontgomeryModInt<998244353>;

using namespace Nyaan;

void Nyaan::solve() {
  int N;
  cin >> N;
  vector<vector<mint>> a(N, vector(N, mint(0)));

  for (auto& v : a)
    for (auto& x : v) cin >> x;

  auto inv = inverse_matrix(a);

  if (inv.empty()) {
    cout << "-1\n";
    return;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << inv[i][j] << " \n"[j == N - 1];
    }
  }
}
