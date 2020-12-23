#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "../../template/template.hpp"
//
#include "../../modint/montgomery-modint.hpp"
using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
using vvm = vector<vm>;

#include "../../matrix/black-box-linear-algebra.hpp"

using namespace Nyaan;
void Nyaan::solve() {
  ini(N);
  ModMatrix<mint> mat(N);
  in(mat);
  out(fast_det<mint, ModMatrix<mint>>(mat));
}
