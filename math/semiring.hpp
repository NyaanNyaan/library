#pragma once

template <typename T, T (*add)(T, T), T (*mul)(T, T), T (*I0)(), T (*I1)()>
struct semiring {
  T x;
  semiring() : x(I0()) {}
  semiring(T y) : x(y) {}
  static T id0() { return I0(); }
  static T id1() { return I1(); }

  semiring &operator+=(const semiring &p) {
    if (x == I0()) return *this = p;
    if (p.x == I0()) return *this;
    return *this = add(x, p.x);
  }

  semiring &operator*=(const semiring &p) {
    if (x == I0() || p.x == I0()) return *this = I0();
    if (x == I1()) return *this = p;
    if (p.x == I1()) return *this;
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

template <typename rig, int N>
struct Mat {
  using Array = array<array<rig, N>, N>;
  Array A;

  Mat() {
    for (int i = 0; i < N; i++) A[i].fill(rig::id0());
  }
  int height() const { return N; }
  int width() const { return N; }
  inline const array<rig, N> &operator[](int k) const { return A[k]; }
  inline array<rig, N> &operator[](int k) { return A[k]; }

  static Mat I() {
    Mat m;
    for (int i = 0; i < N; i++) m[i][i] = rig::id1();
    return m;
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
        for (int j = 0; j < N; j++) C[i][j] += A[i][k] * B[k][j];
    A.swap(C.A);
    return (*this);
  }

  Mat &operator^=(long long k) {
    Mat B = Mat::I();
    for (; k; *this *= *this, k >>= 1)
      if (k & 1) B *= *this;
    A.swap(B.A);
    return (*this);
  }

  Mat operator+(const Mat &B) const { return (Mat(*this) += B); }
  Mat operator*(const Mat &B) const { return (Mat(*this) *= B); }
  Mat operator^(long long k) const { return (Mat(*this) ^= k); }

  friend ostream &operator<<(ostream &os, Mat &p) {
    for (int i = 0; i < N; i++) {
      os << "[";
      for (int j = 0; j < N; j++) {
        os << p[i][j].x << (j == N - 1 ? "]\n" : ",");
      }
    }
    return (os);
  }
};

/**
 * @brief 半環ライブラリ
 * @docs docs/math/semiring.md
 */
