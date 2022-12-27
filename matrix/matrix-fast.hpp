#pragma once

template <typename T, int H, int W>
struct Matrix {
  using Array = array<array<T, W>, H>;
  Array A;

  Matrix() : A() {
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++) (*this)[i][j] = T();
  }

  int height() const { return H; }

  int width() const { return W; }

  inline const array<T, W> &operator[](int k) const { return A[k]; }

  inline array<T, W> &operator[](int k) { return A[k]; }

  static Matrix I() {
    assert(H == W);
    Matrix mat;
    for (int i = 0; i < H; i++) mat[i][i] = 1;
    return (mat);
  }

  Matrix &operator+=(const Matrix &B) {
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++) A[i][j] += B[i][j];
    return (*this);
  }

  Matrix &operator-=(const Matrix &B) {
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++) A[i][j] -= B[i][j];
    return (*this);
  }

  Matrix &operator*=(const Matrix &B) {
    assert(H == W);
    Matrix C;
    for (int i = 0; i < H; i++)
      for (int k = 0; k < H; k++)
        for (int j = 0; j < H; j++) C[i][j] += A[i][k] * B[k][j];
    A.swap(C.A);
    return (*this);
  }

  Matrix &operator^=(long long k) {
    Matrix B = Matrix::I();
    while (k > 0) {
      if (k & 1) B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return (*this);
  }

  Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); }

  Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }

  Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); }

  Matrix operator^(const long long k) const { return (Matrix(*this) ^= k); }

  bool operator==(const Matrix &B) const {
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++)
        if (A[i][j] != B[i][j]) return false;
    return true;
  }

  bool operator!=(const Matrix &B) const {
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++)
        if (A[i][j] != B[i][j]) return true;
    return false;
  }

  friend ostream &operator<<(ostream &os,const Matrix &p) {
    for (int i = 0; i < H; i++) {
      os << "[";
      for (int j = 0; j < W; j++) {
        os << p[i][j] << (j + 1 == W ? "]\n" : ",");
      }
    }
    return (os);
  }

  T determinant(int n = -1) {
    if (n == -1) n = H;
    Matrix B(*this);
    T ret = 1;
    for (int i = 0; i < n; i++) {
      int idx = -1;
      for (int j = i; j < n; j++) {
        if (B[j][i] != 0) {
          idx = j;
          break;
        }
      }
      if (idx == -1) return 0;
      if (i != idx) {
        ret *= T(-1);
        swap(B[i], B[idx]);
      }
      ret *= B[i][i];
      T inv = T(1) / B[i][i];
      for (int j = 0; j < n; j++) {
        B[i][j] *= inv;
      }
      for (int j = i + 1; j < n; j++) {
        T a = B[j][i];
        if (a == 0) continue;
        for (int k = i; k < n; k++) {
          B[j][k] -= B[i][k] * a;
        }
      }
    }
    return (ret);
  }
};

/**
 * @brief 行列ライブラリ(std::array版)
 */
