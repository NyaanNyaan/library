#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

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
      for (int j = 0; j < N; j++)
        for (int k = 0; k < N; k++) C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
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

// old version (using std::vector)
/*
template <typename T, typename F, typename G>
struct Mat {
  using rig = semiring<T, F, G>;
  vector<vector<rig> > A;
  Mat() {}
  Mat(int n, int m) : A(n, vector<rig>(m, rig::id0)) {}
  Mat(int n) : A(n, vector<rig>(n, rig::id0)){};

  int height() const { return (A.size()); }

  int width() const { return (A[0].size()); }

  inline const vector<rig> &operator[](int k) const { return (A.at(k)); }

  inline vector<rig> &operator[](int k) { return (A.at(k)); }

  static Mat I(int n) {
    Mat m(n);
    for (int i = 0; i < n; i++) m[i][i] = rig::id1;
    return (m);
  }

  Mat &operator+=(const Mat &B) {
    int n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) (*this)[i][j] += B[i][j];
    return (*this);
  }

  Mat &operator*=(const Mat &B) {
    int n = height(), m = B.width(), p = width();
    assert(p == B.height());
    vector<vector<rig> > C(n, vector<rig>(m, rig::id0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        for (int k = 0; k < p; k++)
          C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
    A.swap(C);
    return (*this);
  }

  Mat &operator^=(long long k) {
    Mat B = Mat::I(height());
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
*/

// max-plus semiring
/**/
using U = long long;
U ID0 = -infLL;
U ID1 = 0;
auto Add = [](U a, U b) -> U { return max(a, b); };
auto Mul = [](U a, U b) -> U { return a + b; };
//*/

// min-plus semiring
/**
using U = ll;
U ID0 = infLL;
U ID1 = 0;
auto Add = [](U a, U b) -> U { return min(a, b); };
auto Mul = [](U a, U b) -> U { return a + b; };
//*/

// xor-and semiring
/**
using U = unsigned long long;
constexpr U ID0 = 0;
constexpr U ID1 = U(-1);
auto Add = [](U a, U b) -> U { return a ^ b; };
auto Mul = [](U a, U b) -> U { return a & b; };
//*/

template <typename T, typename F, typename G>
T semiring<T, F, G>::id0 = ID0;
template <typename T, typename F, typename G>
T semiring<T, F, G>::id1 = ID1;
template <typename T, typename F, typename G>
F semiring<T, F, G>::add = Add;
template <typename T, typename F, typename G>
G semiring<T, F, G>::mul = Mul;
using rig = semiring<U, decltype(Add), decltype(Mul)>;
template <int N>
using mat = Mat<U, decltype(Add), decltype(Mul), N>;