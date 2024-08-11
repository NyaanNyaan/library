#pragma once

#include <array>
#include <bitset>
using namespace std;

namespace std {
template <size_t N>
bool operator<(const bitset<N> &a, const bitset<N> &b) {
  int f = (a ^ b)._Find_first();
  return f == N ? false : a[f];
}
}  // namespace std

template <size_t H_MAX, size_t W_MAX>
struct F2_Matrix {
  using Mat = F2_Matrix;

  int H, W;
  array<bitset<W_MAX>, H_MAX> A;
  F2_Matrix(int h = H_MAX, int w = W_MAX) : H(h), W(w) {
    assert(0 <= h and h <= (int)H_MAX);
    assert(0 <= w and w <= (int)W_MAX);
    for (int i = 0; i < (int)H_MAX; i++) A[i].reset();
  }
  inline bitset<W_MAX> &operator[](int i) { return A[i]; }
  inline const bitset<W_MAX> &operator[](int i) const { return A[i]; }

  static Mat I(int n) {
    Mat a(n, n);
    for (int i = 0; i < n; i++) a[i][i] = true;
    return a;
  }

  // (AND, XOR) 半環
  // (AND, OR) 半環には operator/ を割り当てた
  Mat &operator*=(const Mat &B) {
    Mat C(H, B.W);
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (A[i][j]) C[i] ^= B[j];
      }
    }
    swap(A, C.A);
    return *this;
  }
  Mat operator*(const Mat &B) const { return Mat(*this) *= B; }

  // (AND, OR) 半環
  friend Mat and_or_product(const Mat &A, const Mat &B) {
    Mat C(A.H, B.W);
    for (int i = 0; i < A.H; i++) {
      for (int j = 0; j < A.W; j++) {
        if (A[i][j]) C[i] |= B[j];
      }
    }
    return C;
  }

  // [0, wr) の範囲で掃き出し, rank を返す
  int sweep(int wr = -1) {
    if (wr == -1) wr = W;
    int t = 0;
    for (int u = 0; u < wr; u++) {
      int piv = -1;
      for (int i = t; i < H; i++) {
        if (A[i][u]) {
          piv = i;
          break;
        }
      }
      if (piv == -1) continue;
      if (piv != t) swap(A[piv], A[t]);
      for (int i = 0; i < H; i++) {
        if (i != t && A[i][u]) A[i] ^= A[t];
      }
      t++;
    }
    return t;
  }

  pair<bool, Mat> inverse() const {
    assert(H == W);
    int N = H;
    F2_Matrix<H_MAX, W_MAX * 2> c(H, W * 2);
    for (int i = 0; i < N; i++) {
      c[i][i + N] = 1;
      for (int j = 0; j < N; j++) {
        c[i][j] = A[i][j];
      }
    }
    int r = c.sweep(N);
    if (r != N) return {false, Mat{N, N}};
    Mat b(H, W);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        b[i][j] = c[i][j + N];
      }
    }
    return {true, b};
  }

  int determinant() const {
    assert(H == W);
    F2_Matrix<H_MAX, W_MAX> c{*this};
    int r = c.sweep();
    return r == H ? 1 : 0;
  }

  bool operator<(const Mat &rhs) const {
    if (H != rhs.H) return H < rhs.H;
    if (W != rhs.W) return W < rhs.W;
    return A < rhs.A;
  }
  bool operator==(const Mat &rhs) const {
    return H == rhs.H and W == rhs.W and A == rhs.A;
  }

  friend ostream &operator<<(ostream &os, const Mat &b) {
    for (int i = 0; i < b.H; i++) {
      os << "[ ";
      for (int j = 0; j < b.W; j++) {
        os << b[i][j] << ", ";
      }
      os << "],\n";
    }
    return os;
  }
};
