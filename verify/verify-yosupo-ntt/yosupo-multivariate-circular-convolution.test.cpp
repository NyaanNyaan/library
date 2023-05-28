#define PROBLEM "https://judge.yosupo.jp/problem/multivariate_convolution_cyclic"
//
#include "../../template/template.hpp"
//
#include "../../ntt/multivariate-circular-convolution.hpp"
//
#include "../../fps/arbitrary-fps.hpp"
//
using namespace Nyaan;

void q() {
  using mint = ArbitraryModInt;
  using fps = FormalPowerSeries<mint>;

  inl(p, K);
  mint::set_mod(p);
  vi base(K);
  in(base);
  int prod = 1;
  each(x, base) prod *= x;
  fps f(prod), g(prod);
  in(f, g);
  out(multivariate_circular_convolution(f, g, base));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
