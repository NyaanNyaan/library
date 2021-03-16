#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../matrix/polynomial-matrix-prefix-prod.hpp"
#include "../../misc/rng.hpp"
#include "../../modint/montgomery-modint.hpp"
//
using namespace Nyaan;

using mint = LazyMontgomeryModInt<998244353>;
using fps = FormalPowerSeries<mint>;
using fmat = Matrix<fps>;
using mat = Matrix<mint>;

mat eval(fmat& f, mint x) {
  mat m(f.H(), f.W());
  rep(i, f.H()) rep(j, f.W()) m[i][j] = f[i][j].eval(x);
  return m;
}

void test() {
  int n = randint(1, 6);
  int d = randint(1, 11);
  // cerr << " n : " << n << " d : " << d << endl;
  fmat m(n);
  rep(i, n) rep(j, n) {
    fps f(d);
    each(x, f) x = rng();
    m[i][j] = f;
  }

  mat prod = mat::I(n);
  rep(k, 1000) {
    // if(k % 200 == 0 and k) cerr << k << " finished." << endl;
    mat m2 = polynomial_matrix_prod(m, k);
    assert(prod == m2);
    prod = eval(m, k) * prod;
  }
  // cerr << "ok" << endl;
}

void Nyaan::solve() {
  test();
  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
