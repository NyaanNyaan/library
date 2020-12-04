#pragma once

template <size_t N>
bitset<N> gcd(bitset<N> x, bitset<N> y) {
  int xm = int(N) - 1, ym = int(N) - 1;
  while (xm != -1 && x[xm] == 0) xm--;
  while (ym != -1 && y[ym] == 0) ym--;
  if (xm < ym) swap(x, y), swap(xm, ym);
  while (ym >= 0) {
    x ^= y << (xm - ym);
    while (xm != -1 && x[xm] == 0) xm--;
    while (ym != -1 && y[ym] == 0) ym--;
    if (xm < ym) swap(x, y), swap(xm, ym);
  }
  return x;
}

template <size_t MAX_H, size_t MAX_W>
struct BitMat {
  int H, W;
  bitset<MAX_W> a[MAX_H];
  BitMat(int h, int w) : H(h), W(w) {}
  inline bitset<MAX_W> &operator[](int i) { return a[i]; }
};

template <size_t MAX_H, size_t MAX_W>
int Gauss(BitMat<MAX_H, MAX_W> &A, bool is_greater = true,
          bool is_extended = false) {
  int rank = 0, H = A.H, W = (is_extended ? A.W - 1 : A.W);
  for (int j = (is_greater ? W - 1 : 0); j != (is_greater ? -1 : W);
       j += (is_greater ? -1 : 1)) {
    for (int i = rank; i < H; i++) {
      if (A[i][j] == 1) {
        swap(A[rank], A[i]);
        for (int k = 0; k < H; k++) {
          if (k != rank && A[k][j]) A[k] ^= A[rank];
        }
        rank++;
        break;
      }
    }
  }
  if (is_extended) {
    for (int i = rank; i < H; i++)
      if (A[i][W] == 1) return -1;
  }
  return rank;
}
template <size_t MAX_H, size_t MAX_W>
void OrthogonalComplement(BitMat<MAX_H, MAX_W> &A, int N) {
  int rank = 0;
  while (rank < N && A[rank].any()) rank++;
  for (int i = 0; i < rank; i++) {
    int j = A[i]._Find_first();
    if (j != i)
      for (int k = 0; k < rank; k++) {
        int buf = A[k][i];
        A[k][i] = A[k][j];
        A[k][j] = buf;
      }
  }
  for (int i = rank; i < N; i++) {
    for (int j = 0; j < N; j++) {
      A[i][j] = (j < rank ? A[j][i] : i == j);
    }
  }
}