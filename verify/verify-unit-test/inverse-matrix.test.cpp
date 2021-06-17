#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

#include "../../matrix/gauss-elimination.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../matrix/inverse-matrix.hpp"

template <typename mint>
void verify(const vector<vector<mint>>& a, const vector<vector<mint>>& b) {
  int N = a.size();
  auto _a = a;
  auto [rank, det] = GaussElimination(_a);

  if (det == 0 or rank != N) {
    assert(det == 0 and rank != N);
    if (!b.empty()) {
      assert(false and "b is not empty is spite of det == 0.");
    }
    return;
  }
  assert(!b.empty());
  vector<vector<mint>> c(N, vector<mint>(N));
  for (int i = 0; i < N; i++) {
    for (int k = 0; k < N; k++) {
      for (int j = 0; j < N; j++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      assert(c[i][j] == (i == j));
    }
  }
}

using mint = LazyMontgomeryModInt<998244353>;

void test() {
  int testcase = 1000;

  long long _x = 1;
  auto rng = [&]() { return _x = _x * 100000 % 998244353; };

  for (int t = 0; t < testcase; t++) {
    int N = t % 30 + 1;
    vector<vector<mint>> a(N, vector<mint>(N));
    for (auto& v : a) {
      for (auto& x : v) {
        x = rng();
      }
    }
    auto b = inverse_matrix(a);
    verify(a, b);
  }
}

int main() {
  test();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}