#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"
//
#include "../../template/template.hpp"
//
#include "../../fps/online-fps.hpp"

using namespace Nyaan;

using ofps = OnlineFormalPowerSeries;

void q() {
  ini(N);
  fps f(N);
  in(f);
  ofps F;
  F.set_corner(f);
  ofps G = F.inv();
  rep(i, N) cout << G[i] << " \n"[i + 1 == N];
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
