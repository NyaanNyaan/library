#pragma once

template <size_t MAX_H, size_t MAX_W>
struct BitMatrix {
  int H, W;
  bitset<MAX_W> A[MAX_H];
  BitMatrix() : H(MAX_H), W(MAX_W) {}
  BitMatrix(int h, int w) : H(h), W(w) {}
  inline bitset<MAX_W> &operator[](int i) { return A[i]; }
  inline const bitset<MAX_W> &operator[](int i) const { return A[i]; }
  int height() { return H; }
  int size() { return H; }
  int width() { return W; }

  static BitMatrix I(int n) {
    BitMatrix mat(n, n);
    for (int i = 0; i < n; i++) mat[i][i] = true;
    return (mat);
  }

  BitMatrix &operator*=(const BitMatrix &B) {
    BitMatrix C(H, B.W);
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (A[i][j]) C[i] |= B[j];
      }
    }
    swap(A, C.A);
    return *this;
  }
  BitMatrix &operator^=(long long k) {
    BitMatrix B = BitMatrix::I(height());
    while (k) {
      if (k & 1) B *= *this;
      *this *= *this;
      k >>= 1;
    }
    swap(A, B.A);
    return (*this);
  }

  BitMatrix operator*(BitMatrix &B) const { return BitMatrix(*this) *= B; }
  BitMatrix operator^(const long long k) const { return BitMatrix(*this) ^= k; }
};
