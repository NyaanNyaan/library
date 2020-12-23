#define PROBLEM "https://yukicoder.me/problems/no/1112"

#include "../../template/template.hpp"

using namespace Nyaan;

#include "../../matrix/black-box-linear-algebra.hpp"
//
#include "../../fps/arbitrary-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
using mint = LazyMontgomeryModInt<1000000007>;
Binomial<mint> C;
using vm = vector<mint>;
using vvm = vector<vm>;
using fps = FormalPowerSeries<mint>;

void Nyaan::solve() {
  inl(K, M, N);
  SparseMatrix<mint> m(K * K);
  rep(i, M) {
    ini(p, q, r);
    p--, q--, r--;
    m.add(p * K + q, q * K + r, 1);
  }
  fps b(K * K);
  rep(i, K) b[i * K] = 1;
  auto res = fast_pow(m, b, N - 2);
  out(accumulate(begin(res), begin(res) + K, mint(0)));
}