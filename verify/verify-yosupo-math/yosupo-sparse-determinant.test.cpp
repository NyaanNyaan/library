#define PROBLEM "https://judge.yosupo.jp/problem/sparse_matrix_det"

#include "../../competitive-template.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/gauss-elimination.hpp"

using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
void solve() {
  ini(N,M);
  V<vm> a(N,vm(N));
  rep(_,M){
    inl(x,y,z);
    a[x][y]=z;
  }
  out(Gauss::determinant(a));
}