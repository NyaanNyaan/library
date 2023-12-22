#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../fps/stirling-matrix.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
// #include "fps/arbitrary-fps.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;
using fps = FormalPowerSeries<mint>;

void q() {
  {
    fps f{0, 0, 1, 0, 0, 0};
    fps g = pascal_matrix(f);
    trc(g);
    fps h = pascal_matrix(g, true);
    trc(h);
    assert(f == h);
  }

  {
    fps f{0, 0, 0, 0, 1, 0};
    fps g = pascal_matrix_trans(f);
    trc(g);
    fps h = pascal_matrix_trans(g, true);
    trc(h);
    assert(f == h);
  }

  {
    fps f{0, 0, 0, 0, 0, 0, 1, 0};
    fps g = stirling_matrix_trans(f);
    fps h = stirling_matrix_trans(g, true);
    trc(g);
    trc(h);
    assert(f == h);
  }

  {
    fps f{0, 0, 0, 1, 0, 0, 0, 0};
    fps g = stirling_matrix(f);
    trc(g);
    fps h = stirling_matrix(g, true);
    trc(h);
    assert(f == h);
  }
}

void Nyaan::solve() {
  q();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
