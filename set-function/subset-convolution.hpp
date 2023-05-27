#pragma once

#include <array>
#include <vector>
using namespace std;

template <typename mint, int _s>
struct SubsetConvolution {
  using fps = array<mint, _s + 1>;
  static constexpr int s = _s;
  vector<int> pc;

  SubsetConvolution() : pc(1 << s) {
    for (int i = 1; i < (1 << s); i++) pc[i] = pc[i - (i & -i)] + 1;
  }

  void add(fps& l, const fps& r, int d) {
    for (int i = 0; i < d; ++i) l[i] += r[i];
  }

  void sub(fps& l, const fps& r, int d) {
    for (int i = d; i <= s; ++i) l[i] -= r[i];
  }

  void zeta(vector<fps>& a) {
    int n = a.size();
    for (int w = 1; w < n; w *= 2) {
      for (int k = 0; k < n; k += w * 2) {
        for (int i = 0; i < w; ++i) {
          add(a[k + w + i], a[k + i], pc[k + w + i]);
        }
      }
    }
  }

  void mobius(vector<fps>& a) {
    int n = a.size();
    for (int w = n >> 1; w; w >>= 1) {
      for (int k = 0; k < n; k += w * 2) {
        for (int i = 0; i < w; ++i) {
          sub(a[k + w + i], a[k + i], pc[k + w + i]);
        }
      }
    }
  }

  vector<fps> lift(const vector<mint>& a) {
    vector<fps> A(a.size());
    for (int i = 0; i < (int)a.size(); i++) {
      fill(begin(A[i]), end(A[i]), mint());
      A[i][pc[i]] = a[i];
    }
    return A;
  }

  vector<mint> unlift(const vector<fps>& A) {
    vector<mint> a(A.size());
    for (int i = 0; i < (int)A.size(); i++) a[i] = A[i][pc[i]];
    return a;
  }

  void prod(vector<fps>& A, const vector<fps>& B) {
    int n = A.size(), d = __builtin_ctz(n);
    for (int i = 0; i < n; i++) {
      fps c{};
      for (int j = 0; j <= d; j++) {
        for (int k = 0; k <= d - j; k++) {
          c[j + k] += A[i][j] * B[i][k];
        }
      }
      A[i].swap(c);
    }
  }

  vector<mint> multiply(const vector<mint>& a, const vector<mint>& b) {
    vector<fps> A = lift(a), B = lift(b);
    zeta(A), zeta(B);
    prod(A, B);
    mobius(A);
    return unlift(A);
  }
};

/**
 * @brief Subset Convolution
 * @docs docs/set-function/subset-convolution.md
 */
