#define PROBLEM "https://yukicoder.me/problems/no/1340"
//
#include "../../template/template.hpp"
//
using namespace Nyaan;

#include "../../math/semiring.hpp"

using U = unsigned long long;
U add(U a, U b) { return a | b; }
U mul(U a, U b) { return a & b; }
U i0() { return 0; }
U i1() { return U(-1); }
using rig = semiring<U, add, mul, i0, i1>;
using M = Mat<rig, 100>;

void Nyaan::solve() {
  inl(n, m, t);
  M mat;
  rep(i, m) {
    ini(a, b);
    mat[a][b] = 1;
  }
  mat ^= t;
  int ans = 0;
  rep(i, n) if (mat[0][i] != 0) ans++;
  out(ans);
}
