#pragma once

#include "formal-power-series.hpp"
#include "taylor-shift.hpp"
#include "../modulo/binomial.hpp"

template <typename mint>
vector<pair<mint, vector<mint>>> PartialFractionDecomposition(
    FormalPowerSeries<mint> numer, vector<pair<mint, int>> denom) {
  using fps = FormalPowerSeries<mint>;

  if (denom.empty()) return {};

  sort(begin(denom), end(denom),
       [](auto p1, auto p2) { return p1.second < p2.second; });
  Binomial<mint> C(denom[0].second + 1);

  int s = 1;
  while (s < (int)denom.size()) s *= 2;
  vector<fps> fs(2 * s);
  for (int i = 0; i < s; i++) {
    if ((int)denom.size() <= i) {
      fs[s + i] = fps{1};
      continue;
    }
    auto [m, d] = denom[i];
    fps f(denom[i].second + 1);
    mint buf = 1;
    for (int j = d; j >= 0; j--) {
      f[j] = buf * C(d, j);
      buf *= m;
    }
    fs[s + i] = f;
  }
  for (int i = s - 1; i; i--) {
    fs[i] = fs[2 * i + 0] * fs[2 * i + 1];
  }

  vector<fps> F(2 * s);
  vector<fps> G(2 * s);
  F[1] = numer % fs[1];
  G[1] = fps{1};
  for (int i = 1; i < s; i++) {
    F[i * 2 + 0] = F[i] % fs[i * 2 + 0];
    F[i * 2 + 1] = F[i] % fs[i * 2 + 1];
    G[i * 2 + 0] = G[i] * fs[i * 2 + 1] % fs[i * 2 + 0];
    G[i * 2 + 1] = G[i] * fs[i * 2 + 0] % fs[i * 2 + 1];
  }

  vector<pair<mint, vector<mint>>> res;
  for (int i = s; i - s < (int)denom.size(); i++) {
    auto [m, d] = denom[i - s];
    F[i] = TaylorShift<mint>(F[i], -m, C);
    G[i] = TaylorShift<mint>(G[i], -m, C);
    fps f = (F[i] * G[i].inv()).pre(d);
    if ((int)f.size() < d) f.resize(d);
    f = f.rev();
    res.emplace_back(m, vector<mint>{begin(f), end(f)});
  }
  return res;
}

/**
 * @brief 部分分数分解(分母が1次式の積で表せる場合)
 */
