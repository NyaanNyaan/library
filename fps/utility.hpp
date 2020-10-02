#pragma once
#include "./formal-power-series.hpp"
#include "../modulo/binomial.hpp"

template <typename mint>
FormalPowerSeries<mint> Pi(vector<FormalPowerSeries<mint>> v) {
  using fps = FormalPowerSeries<mint>;
  if((int)v.size() == 0) return fps{mint(1)};
  sort(begin(v), end(v), [](fps &a, fps &b) { return a.size() < b.size(); });
  vector<fps> w;
  w.reserve(sz(v) / 2 + 1);
  while ((int)v.size() > 1) {
    for (int i = 0; i < (int)v.size(); i += 2) {
      if (i + 1 == (int)v.size()) {
        w.emplace_back(v.back());
      } else {
        w.emplace_back(v[i] * v[i + 1]);
      }
    }
    swap(v, w);
    w.clear();
  }
  return v[0];
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
  FormalPowerSeries<mint> ret{begin(C.finv_), begin(C.finv_) + deg};
  return std::move(ret);
}
