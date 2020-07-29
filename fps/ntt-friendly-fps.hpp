#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../ntt/ntt-avx2.hpp"
#include "./formal-power-series.hpp"

template <typename mint>
void FormalPowerSeries<mint>::set_fft() {
  if (!ntt_ptr) ntt_ptr = new NTT<mint>;
}

template <typename mint>
FormalPowerSeries<mint>& FormalPowerSeries<mint>::operator*=(
    const FormalPowerSeries<mint>& r) {
  if (this->empty() || r.empty()) {
    this->clear();
    return *this;
  }
  set_fft();
  auto ret = static_cast<NTT<mint>*>(ntt_ptr)->multiply(*this, r);
  return *this = FormalPowerSeries<mint>(ret.begin(), ret.end());
}

template <typename mint>
void FormalPowerSeries<mint>::ntt() {
  set_fft();
  static_cast<NTT<mint>*>(ntt_ptr)->ntt(*this);
}

template <typename mint>
void FormalPowerSeries<mint>::intt() {
  set_fft();
  static_cast<NTT<mint>*>(ntt_ptr)->intt(*this);
}

template <typename mint>
void FormalPowerSeries<mint>::ntt_doubling() {
  set_fft();
  static_cast<NTT<mint>*>(ntt_ptr)->ntt_doubling(*this);
}

template <typename mint>
int FormalPowerSeries<mint>::ntt_pr() {
  set_fft();
  return static_cast<NTT<mint>*>(ntt_ptr)->pr;
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
  assert((*this)[0] == mint(0));
  if (deg == -1) deg = (int)this->size();
  FormalPowerSeries<mint> ret({mint(1)});
  for (int i = 1; i < deg; i <<= 1) {
    ret = (ret * (pre(i << 1) + mint(1) - ret.log(i << 1))).pre(i << 1);
  }
  return ret.pre(deg);
}
