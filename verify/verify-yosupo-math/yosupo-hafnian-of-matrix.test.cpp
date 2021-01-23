#define PROBLEM "https://judge.yosupo.jp/problem/hafnian_of_matrix"

#include "../../template/template.hpp"
//
using namespace Nyaan;
//
#include "../../matrix/hafnian.hpp"
//
#include "../../modint/montgomery-modint.hpp"
using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
using vvm = vector<vm>;

void Nyaan::solve() {
  ini(n);
  vvm m(n, vm(n));
  in(m);
  out(Hafnian(m));
}
