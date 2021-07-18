#pragma once

struct BitMatrix {
  using u64 = unsigned long long;
  int H, W, B;  // B : 一行あたりに必要なu64の個数
  vector<u64> a;
  static u64 maskbit(size_t i) { return u64(1) << i; }
  BitMatrix(int h, int w) : H(h), W(w), B((w + 63) / 64), a(H * B) {}
  bool operator()(int i, int j) const {
    return (a[i * B + j / 64] & maskbit(j % 64)) != 0;
  }
  bool test(int i, int j) const {
    return (a[i * B + j / 64] & maskbit(j % 64)) != 0;
  }
  void set(int i, int j) { a[i * B + j / 64] |= maskbit(j % 64); }
  void reset(int i, int j) { a[i * B + j / 64] &= ~maskbit(j % 64); }
  void flip(int i, int j) { a[i * B + j / 64] ^= maskbit(j % 64); }
  __attribute__((optimize("O3,unroll-loops"))) void swap_row(int i1, int i2) {
    for (int j = 0; j < B; j++) swap(a[i1 * B + j], a[i2 * B + j]);
  }
  __attribute__((optimize("O3,unroll-loops"))) void apply_xor(int i1, int i2) {
    for (int j = 0; j < B; j++) a[i1 * B + j] ^= a[i2 * B + j];
  }
};

int GaussJordan(BitMatrix &A, bool is_extended = false) {
  int rank = 0;
  for (int col = 0; col < A.W; ++col) {
    if (is_extended && col == A.W - 1) break;
    int pivot = -1;
    for (int row = rank; row < A.H; ++row) {
      if (A.test(row, col) == true) {
        pivot = row;
        break;
      }
    }
    if (pivot == -1) continue;
    if (pivot != rank) A.swap_row(pivot, rank);
    for (int row = rank + 1; row < A.H; ++row) {
      if (A.test(row, col) == true) A.apply_xor(row, rank);
    }
    ++rank;
  }
  return rank;
}
