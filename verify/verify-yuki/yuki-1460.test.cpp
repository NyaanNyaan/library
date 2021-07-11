#define PROBLEM "https://yukicoder.me/problems/no/1460"
//
#include "../../template/template.hpp"
//
#include "../../math/semiring-linear-recursive.hpp"
#include "../../math/semiring.hpp"

using namespace Nyaan;

using U = long long;
U add(U a, U b) { return max(a, b); }
U mul(U a, U b) { return min(a, b); }
U i0() { return -infLL; }
U i1() { return infLL; }
using rig = semiring<U, add, mul, i0, i1>;

void Nyaan::solve() {
  inl(K, N);
  V<rig> a(K), b(K);
  for (auto& x : a) cin >> x.x;
  for (auto& x : b) cin >> x.x;
  reverse(all(b));
  LinearRecursive<rig> lr(b);
  out(lr.kth_term(a, N));
}
