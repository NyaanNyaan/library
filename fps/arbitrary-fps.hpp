#pragma once

#include "../ntt/arbitrary-ntt.hpp"
#include "./formal-power-series.hpp"

template <typename mint>
void FormalPowerSeries<mint>::set_fft() {
  ntt_ptr = nullptr;
}

template <typename mint>
void FormalPowerSeries<mint>::ntt() {
  exit(1);
}

template <typename mint>
void FormalPowerSeries<mint>::intt() {
  exit(1);
}

template <typename mint>
void FormalPowerSeries<mint>::ntt_doubling() {
  exit(1);
}

template <typename mint>
int FormalPowerSeries<mint>::ntt_pr() {
  exit(1);
}

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
FormalPowerSeries<mint> FormalPowerSeries<mint>::inv(int deg) const {
  assert((*this)[0] != mint(0));
  if (deg == -1) deg = (*this).size();
  FormalPowerSeries<mint> ret({mint(1) / (*this)[0]});
  for (int i = 1; i < deg; i <<= 1)
    ret = (ret + ret - ret * ret * (*this).pre(i << 1)).pre(i << 1);
  return ret.pre(deg);
}

template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::exp(int deg) const {
  assert((*this).size() == 0 || (*this)[0] == mint(0));
  if (deg == -1) deg = (int)this->size();
  FormalPowerSeries<mint> ret({mint(1)});
  for (int i = 1; i < deg; i <<= 1) {
    ret = (ret * (pre(i << 1) + mint(1) - ret.log(i << 1))).pre(i << 1);
  }
  return ret.pre(deg);
}
