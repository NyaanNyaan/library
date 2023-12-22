#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../matrix/matrix.hpp"
#include "../../matrix/gauss-elimination.hpp"
//
namespace Normal {
#include "../../matrix/linear-equation.hpp"
}  // namespace Normal
namespace Fast {
#include "../../modulo/gauss-elimination-fast.hpp"
}  // namespace Fast

#include "../../misc/rng.hpp"
#include "../../modint/montgomery-modint.hpp"

using namespace Nyaan;

using mint = LazyMontgomeryModInt<998244353>;

void test(int n, int m, bool sparse) {
  Matrix<mint> a(n, m);
  each(v, a.A) {
    each(x, v) {
      if (sparse) {
        if (randint(0, m) == 0) x = rng();
      } else {
        x = rng();
      }
    }
  }
  // trc(n, m, sparse);
  // trc(a);

  if (n == m) {
    mint det1, det2, det3;
    {
      auto b = a;
      det1 = b.determinant();
    }
    {
      auto b = a;
      det2 = GaussElimination<mint>(b.A).second;
    }
    {
      auto b = a;
      det3 = Fast::determinant(b.A);
    }
    // trc(det1, det2, det3);
    assert(det1 == det2 and det2 == det3);
  }
  vector<mint> c(n);
  if (rng() & 1) each(x, c) x = rng();

  vector<vector<mint>> sol1, sol2;
  {
    auto b = a;
    sol1 = Normal::LinearEquation<mint>(b.A, c);
    // trc(sol1);
  }
  {
    auto b = a;
    sol2 = Fast::LinearEquation<mint>(b.A, c);
    // trc(sol2);
  }
  assert(sol1 == sol2);
}

void Nyaan::solve() {
  rep(i, TEN(5)) test(randint(1, 17), randint(1, 17), rng() % 2 == 1);

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}