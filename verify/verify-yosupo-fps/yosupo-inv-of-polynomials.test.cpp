#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_polynomials"

#include <immintrin.h>
//
#include <bits/stdc++.h>
using namespace std;

#include "../../misc/fastio.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../fps/polynomial-gcd.hpp"
#include "../../modint/montgomery-modint.hpp"

int main() {
  using mint = LazyMontgomeryModInt<998244353>;
  using fps = FormalPowerSeries<mint>;
  int N, M;
  rd(N, M);
  fps f(N), g(M);
  for (int i = 0; i < N; i++) {
    int n;
    rd(n);
    f[i] = n;
  }
  for (int i = 0; i < M; i++) {
    int n;
    rd(n);
    g[i] = n;
  }

  auto [flg, h] = PolyInv(f, g);
  if (flg) {
    wtn(h.size());
    if (h.size()) {
      for (int i = 0; i < (int)h.size(); i++) {
        if (i) wt(' ');
        wt(h[i].get());
      }
      wt('\n');
    }
  } else {
    wtn(-1);
  }
}