#define PROBLEM "https://yukicoder.me/problems/no/1340"
//
#include "../../template/template.hpp"
//
using namespace Nyaan;

#include "../../matrix/bitmatrix.hpp"
#include "../../misc/fastio.hpp"

using M = BitMatrix<100, 100>;
void Nyaan::solve() {
  ll n, m, t;
  rd(n, m, t);
  M mat;
  rep(i, m) {
    int a, b;
    rd(a, b);
    mat[a][b] = 1;
  }
  mat ^= t;
  int ans = 0;
  rep(i, n) if (mat[0][i] != 0) ans++;
  wtn(ans);
}
