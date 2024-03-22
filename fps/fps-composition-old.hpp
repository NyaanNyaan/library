#pragma once

#include "../modulo/binomial.hpp"
#include "./formal-power-series.hpp"

// find Q(P(x)) mod x ^ min(deg(P), deg(Q))
template <typename mint>
FormalPowerSeries<mint> Composition(FormalPowerSeries<mint> P,
                                    FormalPowerSeries<mint> Q,
                                    Binomial<mint>& C, int deg = -1) {
  using fps = FormalPowerSeries<mint>;
  int N = (deg == -1) ? min(P.size(), Q.size()) : deg;
  if (N == 0) return fps{};
  P.shrink();
  if (P.size() == 0) {
    fps R(N, mint(0));
    R[0] = Q.empty() ? mint(0) : Q[0];
    return R;
  }
  if (N == 1) return fps{Q.eval(P[0])};

  P.resize(N, mint(0));
  Q.resize(N, mint(0));
  int M = max<int>(2, sqrt(N / log2(N)));
  int L = (N + M - 1) / M;
  fps Pm = fps{begin(P), begin(P) + M};
  fps Pr = fps{begin(P) + M, end(P)};

  int J = 31 - __builtin_clz(N - 1) + 1;
  vector<fps> pms(J);
  pms[0] = Pm;
  for (int i = 1; i < J; i++) pms[i] = (pms[i - 1] * pms[i - 1]).pre(N);

  auto comp = [&](auto rec, int left, int j) -> fps {
    if (j == 1) {
      mint Q1 = left + 0 < (int)Q.size() ? Q[left + 0] : mint(0);
      mint Q2 = left + 1 < (int)Q.size() ? Q[left + 1] : mint(0);
      return (pms[0].pre(N) * Q2 + Q1).pre(N);
    }
    if (N <= left) return fps{};
    fps Q1 = rec(rec, left, j - 1);
    fps Q2 = rec(rec, left + (1 << (j - 1)), j - 1);
    return (Q1 + pms[j - 1].pre(N) * Q2).pre(N);
  };

  fps QPm = comp(comp, 0, J);
  fps R = QPm;
  fps pw_Pr{mint(1)};
  fps dPm = Pm.diff();
  dPm.shrink();
  // if dPm[0] == 0, dPm.inv() is undefined
  int deg_dPm = 0;
  while (deg_dPm != (int)dPm.size() && dPm[deg_dPm] == mint(0)) deg_dPm++;
  fps idPm = dPm.empty() ? fps{} : (dPm >> deg_dPm).inv(N);

  for (int l = 1, d = M; l <= L && d < N; l++, d += M) {
    pw_Pr = (pw_Pr * Pr).pre(N - d);
    if (dPm.empty()) {
      R += (pw_Pr * Q[l]) << d;
    } else {
      idPm.resize(N - d);
      QPm = ((QPm.diff() >> deg_dPm) * idPm).pre(N - d);
      R += ((QPm * pw_Pr).pre(N - d) * C.finv(l)) << d;
    };
  }
  R.resize(N, mint(0));
  return R;
}

/**
 * @brief 関数の合成( $\mathrm{O}\left((N \log N)^{\frac{3}{2}}\right)$ )
 * @docs docs/fps/fps-composition-old.md
 */
