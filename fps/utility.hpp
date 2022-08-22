#pragma once
#include "../modulo/binomial.hpp"
#include "./formal-power-series.hpp"

template <typename mint>
FormalPowerSeries<mint> Pi(vector<FormalPowerSeries<mint>> v) {
  using fps = FormalPowerSeries<mint>;
  if ((int)v.size() == 0) return fps{mint(1)};
  sort(begin(v), end(v), [](fps& a, fps& b) { return a.size() < b.size(); });
  queue<fps> q;
  for (auto& f : v) q.push(f);
  while ((int)q.size() > 1) {
    fps a = q.front();
    q.pop();
    fps b = q.front();
    q.pop();
    q.push(a * b);
  }
  return q.front();
}

template <typename mint>
void OGFtoEGF(FormalPowerSeries<mint>& f, Binomial<mint>& C) {
  for (int i = 0; i < (int)f.size(); i++) f[i] *= C.finv(i);
}

template <typename mint>
void EGFtoOGF(FormalPowerSeries<mint>& f, Binomial<mint>& C) {
  for (int i = 0; i < (int)f.size(); i++) f[i] *= C.fac(i);
}

template <typename mint>
FormalPowerSeries<mint> e_x(int deg, Binomial<mint>& C) {
  while ((int)C.g.size() < deg) C.extend();
  FormalPowerSeries<mint> ret{begin(C.g), begin(C.g) + deg};
  return ret;
}

// f *= (1 + c x^n)
template <typename mint>
void sparse_mul(FormalPowerSeries<mint>& f, int n, mint c, int expand = true) {
  if (expand) f.resize(f.size() + n);
  for (int i = (int)f.size() - 1; i >= 0; --i) {
    if (i - n >= 0) f[i] += f[i - n] * c;
  }
}

// f /= (1 + c x^n)
template <typename mint>
void sparse_div(FormalPowerSeries<mint>& f, int n, mint c) {
  for (int i = 0; i < (int)f.size(); ++i) {
    if (i + n < (int)f.size()) f[i + n] -= f[i] * c;
  }
}
