#pragma once

#include "formal-power-series.hpp"
#include "taylor-shift.hpp"
#include "../modulo/binomial.hpp"

// 新しい方
// 入力 : f/(x-b_1)(x-b_2)...(x-b_n), f は n-1 次, b_i は distinct
// 出力 : a_1/(x-b_1) + ... + a_n/(x-b_n)
template <typename mint>
vector<mint> PartialFractionDecomposition(const FormalPowerSeries<mint>& f,
                                          const vector<mint>& b) {
  using fps = FormalPowerSeries<mint>;
  int N = b.size();
  assert((int)f.size() <= N);
  int B = 1;
  while (B < N) B *= 2;
  vector<fps> mod(2 * B, fps{1});
  for (int i = 0; i < N; i++) mod[B + i] = fps{-b[i], 1};
  for (int i = B - 1; i; i--) mod[i] = mod[2 * i] * mod[2 * i + 1];
  vector<mint> ans(N);
  auto dfs = [&](auto rc, int i, int l, int r, fps g, fps h) -> void {
    if (N <= l) return;
    if (l + 1 == r) {
      ans[l] = g.eval(0) / h.eval(0);
      return;
    }
    int m = (l + r) / 2;
    rc(rc, i * 2 + 0, l, m, g % mod[i * 2 + 0],
       h * mod[i * 2 + 1] % mod[i * 2]);
    rc(rc, i * 2 + 1, m, r, g % mod[i * 2 + 1],
       h * mod[i * 2] % mod[i * 2 + 1]);
  };
  dfs(dfs, 1, 0, B, f, fps{1});
  return ans;
}

// 古い方
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
