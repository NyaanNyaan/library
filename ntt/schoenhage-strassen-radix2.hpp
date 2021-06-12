#pragma once

template <typename T>
struct Schoenhage_Strassen_radix2 {
  T* buf = nullptr;

  void rot(T* dst, T* src, int s, int d) {
    assert(0 <= d and d < 2 * s);
    bool f = s <= d;
    if (s <= d) d -= s;
    int i = 0;
    if (f) {
      for (; i < s - d; i++) dst[i + d] = -src[i];
      for (; i < s; i++) dst[i + d - s] = src[i];
    } else {
      for (; i < s - d; i++) dst[i + d] = src[i];
      for (; i < s; i++) dst[i + d - s] = -src[i];
    }
  }

  void in_add(T* dst, T* src, int s) {
    for (int i = 0; i < s; i++) dst[i] += src[i];
  }
  void in_sub(T* dst, T* src, int s) {
    for (int i = 0; i < s; i++) dst[i] -= src[i];
  }

  void cp(T* dst, T* src, int s) { memcpy(dst, src, s * sizeof(T)); }
  void reset(T* dst, int s) { fill(dst, dst + s, T()); }

  // R[x] / (1 + x^(2^m)) 上の長さ2^LのFFT
  void fft(T* a, int l, int m) {
    if (l == 0) return;
    int L = 1 << l, M = 1 << m;
    assert(M * 2 >= L);
    assert(buf != nullptr);

    vector<int> dw(l - 1);
    for (int i = 0; i < l - 1; i++) {
      dw[i] = (1 << (l - 2 - i)) + (1 << (l - 1 - i)) - (1 << (l - 1));
      if (dw[i] < 0) dw[i] += L;
      if (L == M) dw[i] *= 2;
      if (2 * L == M) dw[i] *= 4;
    }

    for (int d = L; d >>= 1;) {
      int w = 0;
      for (int s = 0, k = 0;;) {
        for (int i = s, j = s + d; i < s + d; ++i, ++j) {
          T *ai = a + i * M, *aj = a + j * M;
          rot(buf, aj, M, w);
          cp(aj, ai, M);
          in_add(ai, buf, M);
          in_sub(aj, buf, M);
        }
        if ((s += 2 * d) >= L) break;
        w += dw[__builtin_ctz(++k)];
        if (w >= 2 * M) w -= 2 * M;
      }
    }
  }

  // R[x] / (1 + x^(2^m)) 上の長さ2^LのIFFT
  void ifft(T* a, int l, int m) {
    if (l == 0) return;
    int L = 1 << l, M = 1 << m;
    assert(M * 2 >= L);
    assert(buf != nullptr);

    vector<int> dw(l - 1);
    for (int i = 0; i < l - 1; i++) {
      dw[i] = (1 << (l - 2 - i)) + (1 << (l - 1 - i)) - (1 << (l - 1));
      if (dw[i] < 0) dw[i] += L;
      if (L == M) dw[i] *= 2;
      if (2 * L == M) dw[i] *= 4;
    }

    for (int d = 1; d < L; d *= 2) {
      int w = 0;
      for (int s = 0, k = 0;;) {
        for (int i = s, j = s + d; i < s + d; ++i, ++j) {
          T *ai = a + i * M, *aj = a + j * M;
          cp(buf, ai, M);
          in_add(ai, aj, M);
          in_sub(buf, aj, M);
          rot(aj, buf, M, w);
        }
        if ((s += 2 * d) >= L) break;
        w -= dw[__builtin_ctz(++k)];
        if (w < 0) w += 2 * M;
      }
    }
  }

  // a <- ab / (x^(2^n)+1)
  int naive_mul(T* a, T* b, int n) {
    int N = 1 << n;
    reset(buf, N);
    for (int i = 0; i < N; i++) {
      int j = 0;
      for (; j < N - i; j++) buf[i + j] += a[i] * b[j];
      for (; j < N; j++) buf[i + j - N] -= a[i] * b[j];
    }
    cp(a, buf, N);
    return 0;
  }

  // a <- ab / (x^(2^n)+1)
  int inplace_mul(T* a, T* b, int n) {
    if (n <= 5) {
      naive_mul(a, b, n);
      return 0;
    }

    int l = (n + 1) / 2;
    int m = n / 2;
    int L = 1 << l, M = 1 << m, N = 1 << n;
    int cnt = 0;

    // R[x] (x^(2^(m+1))-1) R[y] (y^(2^l)-1)
    vector<T> A(N * 2), B(N * 2);
    reset(buf + M, M);
    for (int i = 0, s = 0, ds = 2 * M / L; i < L; i++) {
      // y -> x^{2m/r} y
      cp(buf, a + i * M, M);
      rot(A.data() + i * M * 2, buf, 2 * M, s);
      cp(buf, b + i * M, M);
      rot(B.data() + i * M * 2, buf, 2 * M, s);
      s += ds;
      if (s >= 4 * M) s -= 4 * M;
    }

    fft(A.data(), l, m + 1);
    fft(B.data(), l, m + 1);
    for (int i = 0; i < L; i++) {
      cnt = inplace_mul(A.data() + i * M * 2, B.data() + i * M * 2, m + 1);
    }
    ifft(A.data(), l, m + 1);

    for (int i = 0, s = 0, ds = 2 * M / L; i < L; i++) {
      // y -> x^{-2m/r} y
      cp(buf, A.data() + i * M * 2, 2 * M);
      rot(A.data() + i * M * 2, buf, 2 * M, s);
      s -= ds;
      if (s < 0) s += 4 * M;
    }

    for (int i = 0; i < L; i++) {
      for (int j = 0; j < M; j++) {
        a[i * M + j] = A[i * M * 2 + j];
        if (i == 0) {
          a[i * M + j] -= A[(L - 1) * M * 2 + M + j];
        } else {
          a[i * M + j] += A[(i - 1) * M * 2 + M + j];
        }
      }
    }
    return cnt + l;
  }

  // a <- ab / (x^(2^n)-1)
  int inplace_mul2(T* a, T* b, int n) {
    if (n <= 5) {
      naive_mul(a, b, n);
      return 0;
    }

    int l = (n + 1) / 2;
    int m = n / 2;
    int L = 1 << l, M = 1 << m, N = 1 << n;
    int cnt = 0;

    // R[x] (x^(2^(m+1))-1) R[y] (y^(2^l)-1)
    vector<T> A(N * 2), B(N * 2);
    for (int i = 0; i < L; i++) {
      cp(A.data() + i * M * 2, a + i * M, M);
      cp(B.data() + i * M * 2, b + i * M, M);
    }
    fft(A.data(), l, m + 1);
    fft(B.data(), l, m + 1);
    for (int i = 0; i < L; i++) {
      cnt = inplace_mul(A.data() + i * M * 2, B.data() + i * M * 2, m + 1);
    }
    ifft(A.data(), l, m + 1);
    for (int i = 0; i < L; i++) {
      for (int j = 0; j < M; j++) {
        a[i * M + j] = A[i * M * 2 + j];
        a[i * M + j] += A[(i ? i - 1 : L - 1) * M * 2 + M + j];
      }
    }
    return cnt + l;
  }

  pair<vector<T>, int> multiply(const vector<T>& a, const vector<T>& b) {
    int L = a.size() + b.size() - 1;
    int M = 1, m = 0;
    while (M < L) M *= 2, m++;
    buf = new T[M];
    vector<T> s(M), t(M);
    for (int i = 0; i < (int)a.size(); i++) s[i] = a[i];
    for (int i = 0; i < (int)b.size(); i++) t[i] = b[i];
    int cnt = inplace_mul2(s.data(), t.data(), m);
    vector<T> u(L);
    for (int i = 0; i < L; i++) u[i] = s[i];
    delete[] buf;
    return make_pair(u, cnt);
  }
};

/**
 * @brief Schönhage-Strassen Algorithm(radix-2)
 */
