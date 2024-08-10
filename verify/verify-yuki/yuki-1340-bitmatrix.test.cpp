#define PROBLEM "https://yukicoder.me/problems/no/1340"
//
#include "../../template/template.hpp"
//
using namespace Nyaan;

#include "../../matrix/f2-matrix.hpp"

using M = F2_Matrix<100, 128>;

void Nyaan::solve() {
  ll n, m, t;
  in(n, m, t);
  M mat(n, n);
  rep(i, m) {
    int a, b;
    in(a, b);
    mat[a][b] = 1;
  }

  M a = M::I(n);
  {
    while (t) {
      if (t & 1) a = and_or_product(a, mat);
      mat = and_or_product(mat, mat);
      t >>= 1;
    }
  }
  int ans = 0;
  rep(i, n) if (a[0][i] != 0) ans++;
  out(ans);
}
