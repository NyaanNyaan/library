#pragma once

template <typename mint>
vector<mint> subset_convolution(const vector<mint>& a, const vector<mint>& b) {
  int N = a.size();
  assert(a.size() == b.size() && (N & (N - 1)) == 0);
  int l = __builtin_ctz(N);

  auto conv = [&](vector<mint>& a, vector<mint>& b) -> void {
    for (int k = l; k >= 0; --k) {
      mint n = mint(0);
      for (int i = 0; i <= k; ++i) n += a[i] * b[k - i];
      a[k] = n;
    }
  };

  vector<vector<mint>> A(N, vector<mint>(l + 1)), B(N, vector<mint>(l + 1));
  for (int i = 0; i < N; i++) A[i][0] = a[i], B[i][0] = b[i];
  vector<mint> buf(l + 1);

  for (int n = N / 2, d = 1; n; n >>= 1, ++d) {
    for (int i = 0; i < N; i += 2 * n) {
      for (int j = i; j < i + n; j++) {
        // A[j + n] = A[j] + A[j + n] * x
        buf[0] = A[j][0];
        for (int k = 1; k <= d; k++) buf[k] = A[j][k] + A[j + n][k - 1];
        copy(begin(buf), end(buf), begin(A[j + n]));
        buf[0] = B[j][0];
        for (int k = 1; k <= d; k++) buf[k] = B[j][k] + B[j + n][k - 1];
        copy(begin(buf), end(buf), begin(B[j + n]));
      }
    }
  }

  for (int i = 0; i < N; i++) conv(A[i], B[i]);
  
  for (int n = 1, d = 0; n < N; n <<= 1, ++d) {
    for (int i = 0; i < N; i += 2 * n) {
      for (int j = i; j < i + n; j++) {
        // A[j + n] -= A[j]
        for (int k = d; k <= l; k++) A[j + n][k] -= A[j][k];
        // A[j] *= x
        for (int k = l; k > d; --k) A[j][k] = A[j][k - 1];
        A[j][0] = mint(0);
      }
    }
  }

  vector<mint> C(N);
  for (int i = 0; i < N; i++) C[i] = A[i][l];
  return C;
}

/**
 * @brief Subset Convolution
 * @docs docs/set-function/subset-convolution.md
 */
