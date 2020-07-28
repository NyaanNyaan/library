#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../ntt/arbitrary-ntt.hpp"
#include "./formal-power-series.hpp"

template <typename mint>
FormalPowerSeries<mint>& FormalPowerSeries<mint>::operator*=(
    const FormalPowerSeries<mint>& r) {
  if (this->empty() || r.empty()) {
    this->clear();
    return *this;
  }
  auto ret = ArbitraryNTT::multiply(*this, r);
  return *this = FormalPowerSeries<mint>(ret.begin(), ret.end());
}

template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::ntt() const {
  exit(1);
}

template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::intt() const {
  exit(1);
}

template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::inv(int deg) const {
  assert((*this)[0] != mint(0));
  if (deg == -1) deg = (*this).size();
  FormalPowerSeries<mint> ret({mint(1) / (*this)[0]});
  for (int i = 1; i < deg; i <<= 1)
    ret = (ret + ret - ret * ret * (*this).pre(i << 1)).pre(i << 1);
  return ret.pre(deg);
}

template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::log(int deg) const {
  assert((*this)[0] == mint(1));
  if (deg == -1) deg = (int)this->size();
  return (this->diff() * this->inv()).pre(deg - 1).integral();
}

template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::exp(int deg) const {
  assert((*this)[0] == mint(0));
  if (deg == -1) deg = (int)this->size();
  FormalPowerSeries<mint> ret({mint(1)});
  for (int i = 1; i < deg; i <<= 1) {
    ret = (ret * (pre(i << 1) + mint(1) - ret.log(i << 1))).pre(i << 1);
  }
  return ret.pre(deg);
}

template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::pow(int64_t k, int deg) const {
  const int n = (int)this->size();
  if (deg == -1) deg = n;
  for (int i = 0; i < n; i++) {
    if ((*this)[i] != mint(0)) {
      if (i * k > deg) return FormalPowerSeries<mint>(deg, mint(0));
      mint rev = mint(1) / (*this)[i];
      FormalPowerSeries<mint> ret =
          (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));
      ret = (ret << (i * k)).pre(deg);
      if (ret.size() < deg) ret.resize(deg, mint(0));
      return ret;
    }
  }
  return *this;
}