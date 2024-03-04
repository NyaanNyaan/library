#pragma once

#include "./formal-power-series.hpp"

namespace poly_gcd {

template <typename mint>
using FPS = FormalPowerSeries<mint>;
template <typename mint>
using Arr = pair<FPS<mint>, FPS<mint>>;

template <typename mint>
struct Mat {
  using fps = FPS<mint>;
  fps a00, a01, a10, a11;

  Mat() = default;
  Mat(const fps& a00_, const fps& a01_, const fps& a10_, const fps& a11_)
      : a00(a00_), a01(a01_), a10(a10_), a11(a11_) {}

  Mat& operator*=(const Mat& r) {
    fps A00 = a00 * r.a00 + a01 * r.a10;
    fps A01 = a00 * r.a01 + a01 * r.a11;
    fps A10 = a10 * r.a00 + a11 * r.a10;
    fps A11 = a10 * r.a01 + a11 * r.a11;
    A00.shrink();
    A01.shrink();
    A10.shrink();
    A11.shrink();
    swap(A00, a00);
    swap(A01, a01);
    swap(A10, a10);
    swap(A11, a11);
    return *this;
  }

  static Mat I() { return Mat(fps{mint(1)}, fps(), fps(), fps{mint(1)}); }

  Mat operator*(const Mat& r) const { return Mat(*this) *= r; }
};

template <typename mint>
Arr<mint> operator*(const Mat<mint>& m, const Arr<mint>& a) {
  using fps = FPS<mint>;
  fps b0 = m.a00 * a.first + m.a01 * a.second;
  fps b1 = m.a10 * a.first + m.a11 * a.second;
  b0.shrink();
  b1.shrink();
  return {b0, b1};
};

template <typename mint>
void InnerNaiveGCD(Mat<mint>& m, Arr<mint>& p) {
  using fps = FPS<mint>;
  fps quo = p.first / p.second;
  fps rem = p.first - p.second * quo;
  fps b10 = m.a00 - m.a10 * quo;
  fps b11 = m.a01 - m.a11 * quo;
  rem.shrink();
  b10.shrink();
  b11.shrink();
  swap(b10, m.a10);
  swap(b11, m.a11);
  swap(b10, m.a00);
  swap(b11, m.a01);
  p = {p.second, rem};
}

template <typename mint>
Mat<mint> InnerHalfGCD(Arr<mint> p) {
  int n = p.first.size(), m = p.second.size();
  int k = (n + 1) / 2;
  if (m <= k) return Mat<mint>::I();
  Mat<mint> m1 = InnerHalfGCD(make_pair(p.first >> k, p.second >> k));
  p = m1 * p;
  if ((int)p.second.size() <= k) return m1;
  InnerNaiveGCD(m1, p);
  if ((int)p.second.size() <= k) return m1;
  int l = (int)p.first.size() - 1;
  int j = 2 * k - l;
  p.first = p.first >> j;
  p.second = p.second >> j;
  return InnerHalfGCD(p) * m1;
}

template <typename mint>
Mat<mint> InnerPolyGCD(const FPS<mint>& a, const FPS<mint>& b) {
  Arr<mint> p{a, b};
  p.first.shrink();
  p.second.shrink();
  int n = p.first.size(), m = p.second.size();
  if (n < m) {
    Mat<mint> mat = InnerPolyGCD(p.second, p.first);
    swap(mat.a00, mat.a01);
    swap(mat.a10, mat.a11);
    return mat;
  }

  Mat<mint> res = Mat<mint>::I();
  while (1) {
    Mat<mint> m1 = InnerHalfGCD(p);
    p = m1 * p;
    if (p.second.empty()) return m1 * res;
    InnerNaiveGCD(m1, p);
    if (p.second.empty()) return m1 * res;
    res = m1 * res;
  }
}

// 多項式 GCD, 非零の場合 monic なものを返す
template <typename mint>
FPS<mint> PolyGCD(const FPS<mint>& a, const FPS<mint>& b) {
  Arr<mint> p(a, b);
  Mat<mint> m = InnerPolyGCD(a, b);
  p = m * p;
  if (!p.first.empty()) {
    mint coeff = p.first.back().inverse();
    for (auto& x : p.first) x *= coeff;
  }
  return p.first;
}

template <typename mint>
pair<int, FPS<mint>> PolyInv(const FPS<mint>& f, const FPS<mint>& g) {
  using fps = FPS<mint>;
  pair<fps, fps> p(f, g);
  Mat<mint> m = InnerPolyGCD(f, g);
  fps gcd_ = (m * p).first;
  if (gcd_.size() != 1) return {false, fps()};
  pair<fps, fps> x(fps{mint(1)}, g);
  return {true, ((m * x).first % g) * gcd_[0].inverse()};
}

}  // namespace poly_gcd
using poly_gcd::PolyGCD;
using poly_gcd::PolyInv;

/**
 * @brief 多項式GCD
 * @docs docs/fps/polynomial-gcd.md
 */
