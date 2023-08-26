#pragma once

#include <cassert>
#include <utility>
#include <vector>
using namespace std;

#include "formal-power-series.hpp"

// 多項式 f に exp(cx) 代入
// 次数 : mod x^{deg} まで計算, 指定がない場合 f と同じ長さ計算
template <typename mint>
FormalPowerSeries<mint> composite_exp(FormalPowerSeries<mint> f, mint c = 1,
                                      int deg = -1) {
  using fps = FormalPowerSeries<mint>;
  assert(c != 0);
  if (deg == -1) deg = f.size();

  if (f.empty()) return {};
  int N = f.size();
  vector<pair<fps, fps>> fs;
  for (int i = 0; i < N; i++) fs.emplace_back(fps{f[i]}, fps{1, -c * i});
  while (fs.size() > 1u) {
    vector<pair<fps, fps>> nx;
    for (int i = 0; i + 1 < (int)fs.size(); i += 2) {
      pair<fps, fps>& f0 = fs[i];
      pair<fps, fps>& f1 = fs[i + 1];
      fps s = f0.first * f1.second + f1.first * f0.second;
      fps t = f0.second * f1.second;
      nx.emplace_back(s, t);
    }
    if (fs.size() % 2) nx.push_back(fs.back());
    fs = nx;
  }
  fps g = (fs[0].first * fs[0].second.inv(deg)).pre(deg);
  mint b = 1;
  for (int i = 0; i < deg; i++) g[i] *= b, b /= i + 1;
  return g;
}

// 入力 f(x) = sum_{0 <= k < N} a_i exp(ckx) を満たす g(x) (mod x^N)
// 出力 a(x) = sum_{0 <= k < N} a_i x^i
template <typename mint>
FormalPowerSeries<mint> inverse_of_composite_exp(FormalPowerSeries<mint> f,
                                                 mint c = 1) {
  using fps = FormalPowerSeries<mint>;
  if (f.empty()) return {};
  int N = f.size();
  mint b = 1;
  for (int i = 0; i < N; i++) f[i] *= b, b *= i + 1;

  int B = 1;
  while (B < N) B *= 2;
  vector<fps> mod(2 * B, fps{1});
  for (int i = 0; i < N; i++) mod[B + i] = fps{-c * i, 1};
  for (int i = B - 1; i; i--) mod[i] = mod[2 * i] * mod[2 * i + 1];
  fps denom = mod[1].rev();
  fps numer = (f * denom).pre(N);

  vector<mint> a(N);
  auto dfs = [&](auto rc, int i, int l, int r, fps g) -> void {
    if (N <= l) return;
    if (l + 1 == r) {
      a[l] = g.eval(0);
      return;
    }
    int m = (l + r) / 2;
    rc(rc, i * 2 + 0, l, m, g % mod[i * 2 + 0]);
    rc(rc, i * 2 + 1, m, r, g % mod[i * 2 + 1]);
  };
  dfs(dfs, 1, 0, B, numer.rev());

  vector<mint> fac(N);
  fac[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * c * i;
  for (int i = 0; i < N; i++) {
    a[i] /= fac[N - 1 - i] * fac[i] * ((N - 1 - i) % 2 ? -1 : 1);
  }
  return fps{begin(a), end(a)};
}

/**
 * @brief $f(exp(cx))$ の計算
 */
