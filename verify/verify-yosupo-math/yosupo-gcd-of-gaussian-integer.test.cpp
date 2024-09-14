#define PROBLEM "https://judge.yosupo.jp/problem/gcd_of_gaussian_integers"
//
#include "../../template/template.hpp"
//
#include "../../math/gaussian-integer.hpp"

using namespace Nyaan;

void q() {
  inl(a1, b1, a2, b2);
  Gaussian_Integer<ll> z1{a1, b1}, z2{a2, b2};
  out(gcd(z1, z2));
}

void Nyaan::solve() {
  int t = 1;
  in(t);
  while (t--) q();
}
