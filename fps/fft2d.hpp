#pragma once

#include <cassert>
#include <vector>
using namespace std;

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

template <typename mint>
vector<FormalPowerSeries<mint>> transpose(vector<FormalPowerSeries<mint>> f) {
  int H = f.size(), W = f[0].size();
  for (auto& v : f) assert((int)v.size() == W);
  vector<FormalPowerSeries<mint>> g(W, FormalPowerSeries<mint>(H));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) g[j][i] = f[i][j];
  }
  return g;
};

template <typename mint>
vector<FormalPowerSeries<mint>> multiply2d_naive(
    vector<FormalPowerSeries<mint>> a, vector<FormalPowerSeries<mint>> b) {
  using fps = FormalPowerSeries<mint>;
  using fps2d = vector<fps>;
  if (a.empty() or b.empty()) return {};
  if (a[0].empty() or b[0].empty()) return {};
  int Ha = a.size(), Wa = a[0].size();
  int Hb = b.size(), Wb = b[0].size();
  for (auto& v : a) assert((int)v.size() == Wa);
  for (auto& v : b) assert((int)v.size() == Wb);
  fps2d c(Ha + Hb - 1, fps(Wa + Wb - 1));
  for (int ia = 0; ia < Ha; ia++) {
    for (int ja = 0; ja < Wa; ja++) {
      for (int ib = 0; ib < Hb; ib++) {
        for (int jb = 0; jb < Wb; jb++) {
          c[ia + ib][ja + jb] += a[ia][ja] * b[ib][jb];
        }
      }
    }
  }
  return c;
}

template <typename mint>
vector<FormalPowerSeries<mint>> multiply2d_partially_naive(
    vector<FormalPowerSeries<mint>> a, vector<FormalPowerSeries<mint>> b) {
  using fps = FormalPowerSeries<mint>;
  using fps2d = vector<fps>;
  if (a.empty() or b.empty()) return {};
  if (a[0].empty() or b[0].empty()) return {};
  int Ha = a.size(), Wa = a[0].size();
  int Hb = b.size(), Wb = b[0].size();
  for (auto& v : a) assert((int)v.size() == Wa);
  for (auto& v : b) assert((int)v.size() == Wb);

  if (min(Ha, Hb) * min(Wa, Wb) <= 40) {
    return multiply2d_naive(a, b);
  }

  int W = 1;
  while (W < Wa + Wb - 1) W *= 2;

  if (W >= 64 and Wa + Wb - 1 <= W / 2 + 20) {
    if (Wa <= 20) swap(a, b), swap(Ha, Hb), swap(Wa, Wb);
    int d = Wa + Wb - 1 - W / 2;
    fps2d a1(Ha), a2(Ha);
    for (int i = 0; i < Ha; i++) {
      a1[i] = fps{begin(a[i]), end(a[i]) - d};
      a2[i] = fps{end(a[i]) - d, end(a[i])};
    }
    fps2d c1 = multiply2d_partially_naive(a1, b);
    fps2d c2 = multiply2d_partially_naive(a2, b);
    for (int i = 0; i < Ha + Hb - 1; i++) {
      c1[i] += c2[i] << (Wa - d);
      c1[i].resize(Wa + Wb - 1);
    }
    return c1;
  }

  for (auto& v : a) v.resize(W), v.ntt();
  for (auto& v : b) v.resize(W), v.ntt();
  fps2d cT;
  for (int j = 0; j < W; j++) {
    fps bufa(Ha), bufb(Hb);
    for (int i = 0; i < Ha; i++) bufa[i] = a[i][j];
    for (int i = 0; i < Hb; i++) bufb[i] = b[i][j];
    cT.push_back(bufa * bufb);
  }
  fps2d c = transpose(cT);
  for (auto& v : c) v.intt(), v.resize(Wa + Wb - 1);
  return c;
}

template <typename mint>
vector<FormalPowerSeries<mint>> multiply2d(vector<FormalPowerSeries<mint>> a,
                                           vector<FormalPowerSeries<mint>> b) {
  using fps = FormalPowerSeries<mint>;
  using fps2d = vector<fps>;

  if (a.empty() or b.empty()) return {};
  if (a[0].empty() or b[0].empty()) return {};
  int Ha = a.size(), Wa = a[0].size();
  int Hb = b.size(), Wb = b[0].size();
  for (auto& v : a) assert((int)v.size() == Wa);
  for (auto& v : b) assert((int)v.size() == Wb);

  if (min(Ha, Hb) * min(Wa, Wb) <= 40) {
    return multiply2d_naive(a, b);
  }
  if (min(Ha, Hb) <= 40) {
    return multiply2d_partially_naive(a, b);
  }
  if (min(Wa, Wb) <= 40) {
    auto aT = transpose(a), bT = transpose(b);
    auto cT = multiply2d_partially_naive(aT, bT);
    return transpose(cT);
  }

  int H = 1, W = 1;
  while (H < Ha + Hb - 1) H *= 2;
  while (W < Wa + Wb - 1) W *= 2;

  if (Wa + Wb - 1 < W / 2 + 20) {
    int d = Wa + Wb - 1 - W / 2;
    fps2d a1(Ha), a2(Ha);
    for (int i = 0; i < Ha; i++) {
      a1[i] = fps{begin(a[i]), end(a[i]) - d};
      a2[i] = fps{end(a[i]) - d, end(a[i])};
    }
    fps2d c1 = multiply2d(a1, b);
    fps2d c2 = multiply2d(a2, b);
    for (int i = 0; i < Ha + Hb - 1; i++) {
      c1[i] += c2[i] << (Wa - d);
      c1[i].resize(Wa + Wb - 1);
    }
    return c1;
  }
  if (Ha + Hb - 1 < H / 2 + 20) {
    auto aT = transpose(a), bT = transpose(b);
    auto cT = multiply2d(aT, bT);
    return transpose(cT);
  }

  a.resize(H), b.resize(H);
  for (auto& v : a) v.resize(W);
  for (auto& v : b) v.resize(W);
  fft2d(a), fft2d(b);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) a[i][j] *= b[i][j];
  }
  ifft2d(a);
  a.resize(Ha + Hb - 1);
  for (auto& v : a) v.resize(Wa + Wb - 1);
  return a;
}
