#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "../../template/template.hpp"
//
#include "../../matrix/matrix-fast.hpp"
namespace hoge {
#include "../../matrix/matrix.hpp"
}
#include "../../modint/montgomery-modint.hpp"
using mint = LazyMontgomeryModInt<998244353>;

using namespace Nyaan;

void Nyaan::solve() {
  using Mat1 = Matrix<mint, 500, 500>;
  using Mat2 = hoge::Matrix<mint>;

  ini(n);
  Mat1 m1;
  Mat2 m2(n);
  rep(i, n) rep(j, n) {
    ini(x);
    m1[i][j] = m2[i][j] = x;
  }
  mint det1 = m1.determinant(n);
  mint det2 = m2.determinant();
  assert(det1 == det2);
  out(det1);

  {
    Mat1 a,b;
    a *= b;
    a += b;
    a -= b;
  }
}
