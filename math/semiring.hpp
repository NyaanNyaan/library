#pragma once

template <typename T, typename F, typename G>
struct semiring {
  T x;
  static T id0, id1;
  static F add;
  static G mul;
  semiring() : x(id0) {}
  semiring(T y) : x(y) {}

  semiring &operator+=(const semiring &p) {
    if (x == id0) return *this = p;
    if (p == id0) return *this;
    return *this = add(x, p.x);
  }

  semiring &operator*=(const semiring &p) {
    if (x == id0 || p == id0) return *this = id0;
    if (x == id1) return *this = p;
    if (p == id1) return *this;
    return *this = mul(x, p.x);
  }

  semiring operator+(const semiring &p) const { return semiring(*this) += p; }

  semiring operator*(const semiring &p) const { return semiring(*this) *= p; }

  bool operator==(const semiring &p) const { return x == p.x; }

  bool operator!=(const semiring &p) const { return x != p.x; }

  friend ostream &operator<<(ostream &os, const semiring &p) {
    return os << p.x;
  }
};

template <typename T, typename F, typename G, int N>
struct Mat {
  using rig = semiring<T, F, G>;
  using Array = array<array<rig, N>, N>;
  Array A;
  Mat() {
    for (int i = 0; i < N; i++) A[i].fill(rig::id0);
  }
  int height() const { return N; }

  int width() const { return N; }

  inline const array<rig, N> &operator[](int k) const { return A[k]; }

  inline array<rig, N> &operator[](int k) { return A[k]; }

  static Mat I() {
    Mat m;
    for (int i = 0; i < N; i++) m[i][i] = rig::id1;
    return (m);
  }

  Mat &operator+=(const Mat &B) {
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) A[i][j] += B[i][j];
    return (*this);
  }

  Mat &operator*=(const Mat &B) {
    Mat C;
    for (int i = 0; i < N; i++)
      for (int k = 0; k < N; k++)
        for (int j = 0; j < N; j++) C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
    A.swap(C.A);
    return (*this);
  }

  Mat &operator^=(long long k) {
    Mat B = Mat::I();
    while (k > 0) {
      if (k & 1) B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return (*this);
  }

  Mat operator+(const Mat &B) const { return (Mat(*this) += B); }

  Mat operator*(const Mat &B) const { return (Mat(*this) *= B); }

  Mat operator^(const long long k) const { return (Mat(*this) ^= k); }
};

/**
 * @brief 半環ライブラリ
 * @docs docs/math/semiring.md
 */
