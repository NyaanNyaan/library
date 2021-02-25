#pragma once

#include "formal-power-series.hpp"

template <typename mint>
void fft2d(vector<FormalPowerSeries<mint>>& a) {
  int H = a.size(), W = a[0].size();
  assert((H & (H - 1)) == 0);
  assert((W & (W - 1)) == 0);
  for (int i = 0; i < H; i++) {
    bool ok = false;
    for (auto& x : a[i]) {
      if (x != mint()) {
        ok = true;
        break;
      }
    }
    if (ok) a[i].ntt();
  }
  FormalPowerSeries<mint> buf(H);
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) buf[j] = a[j][i];
    buf.ntt();
    for (int j = 0; j < H; j++) a[j][i] = buf[j];
  }
}

template <typename mint>
void ifft2d(vector<FormalPowerSeries<mint>>& a) {
  int H = a.size(), W = a[0].size();
  assert((H & (H - 1)) == 0);
  assert((W & (W - 1)) == 0);
  FormalPowerSeries<mint> buf(H);
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) buf[j] = a[j][i];
    buf.intt();
    for (int j = 0; j < H; j++) a[j][i] = buf[j];
  }
  for (int i = 0; i < H; i++) {
    bool ok = false;
    for (auto& x : a[i]) {
      if (x != mint()) {
        ok = true;
        break;
      }
    }
    if (ok) a[i].intt();
  }
}
