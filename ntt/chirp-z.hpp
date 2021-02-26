#pragma once

#include "arbitrary-ntt.hpp"

// return F(n) = sum {k=0...N-1} f(k) W^{nk} (W != 0)
template <typename mint>
vector<mint> ChirpZ(vector<mint> f, mint W) {
  assert(W != mint(0));
  int N = f.size();
  vector<mint> wc(2 * N), iwc(N);
  mint ws = 1, iW = W.inverse(), iws = 1;
  wc[0] = 1, iwc[0] = 1;
  for (int i = 1; i < 2 * N; i++) wc[i] = ws * wc[i - 1], ws *= W;
  for (int i = 1; i < N; i++) iwc[i] = iws * iwc[i - 1], iws *= iW;
  for (int i = 0; i < N; i++) f[i] *= iwc[i];
  f.push_back(0);
  reverse(begin(f), end(f));
  vector<mint> g;
  int s = f.size() + wc.size() - 1;
  if ((1 << __builtin_ctz(mint::get_mod() - 1)) >= s) {
    NTT<mint> ntt;
    g = ntt.multiply(f, wc);
  } else {
    g = ArbitraryNTT::multiply<mint>(f, wc);
  }
  vector<mint> F{begin(g) + N, begin(g) + 2 * N};
  for (int i = 0; i < N; i++) F[i] *= iwc[i];
  return F;
}

/**
 * @brief Chirp Z-transform
 */
