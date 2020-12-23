#define PROBLEM "https://judge.yosupo.jp/problem/sparse_matrix_det"

#include "../../template/template.hpp"
//
#include "../../modint/montgomery-modint.hpp"
using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
using vvm = vector<vm>;
#include "../../modulo/binomial.hpp"
Binomial<mint> C;

#include "../../matrix/black-box-linear-algebra.hpp"

using namespace Nyaan;
void Nyaan::solve() {
  ini(N, K);
  SparseMatrix<mint> mat(N);
  rep(_, K) {
    ini(a, b, c);
    mat.add(a, b, c);
  }
  out(fast_det<mint, SparseMatrix<mint>>(mat));
}
