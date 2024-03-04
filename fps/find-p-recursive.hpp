#pragma once

#include "../matrix/linear-equation.hpp"
#include "../matrix/polynomial-matrix-prefix-prod.hpp"
#include "formal-power-series.hpp"

// return polynomial coefficient s.t. sum_{j=k...0} f_j(i) a_{i+j} = 0
// (In more details, read verification code.)
template <typename mint>
vector<FormalPowerSeries<mint>> find_p_recursive(vector<mint>& a, int d) {
  using fps = FormalPowerSeries<mint>;
  int n = a.size();
  int k = (n + 2) / (d + 2) - 1;
  if (k <= 0) return {};
  int m = (k + 1) * (d + 1);
  vector<vector<mint>> M(m - 1, vector<mint>(m));
  for (int i = 0; i < m - 1; i++) {
    for (int j = 0; j <= k; j++) {
      mint base = 1;
      for (int l = 0; l <= d; l++) {
        M[i][(d + 1) * j + l] = base * a[i + j];
        base *= i + j;
      }
    }
  }
  auto gauss = LinearEquation<mint>(M, vector<mint>(m - 1, 0));
  if (gauss.size() <= 1) return {};
  auto c = gauss[1];
  while (all_of(end(c) - d - 1, end(c), [](mint x) { return x == mint(0); })) {
    c.erase(end(c) - d - 1, end(c));
  }
  k = c.size() / (d + 1) - 1;
  vector<fps> res;
  for (int i = 0, j = 0; i < (int)c.size(); i += d + 1, j++) {
    fps f{1}, base{j, 1};
    fps sm;
    for (int l = 0; l <= d; l++) sm += f * c[i + l], f *= base;
    res.push_back(sm);
  }
  reverse(begin(res), end(res));
  return res;
}

template <typename mint>
mint kth_term_of_p_recursive(vector<mint>& a, long long k, int d) {
  if (k < (int)a.size()) return a[k];
  if (all_of(begin(a), end(a), [](mint x) { return x == mint(0); })) return 0;
  auto fs = find_p_recursive(a, d);
  assert(fs.empty() == false);
  int deg = fs.size() - 1;
  assert(deg >= 1);
  Matrix<FormalPowerSeries<mint>> m(deg), denom(1);
  for (int i = 0; i < deg; i++) m[0][i] = -fs[i + 1];
  for (int i = 1; i < deg; i++) m[i][i - 1] = fs[0];
  denom[0][0] = fs[0];
  Matrix<mint> a0(deg);
  for (int i = 0; i < deg; i++) a0[i][0] = a[deg - 1 - i];
  mint res = (polynomial_matrix_prod(m, k - deg + 1) * a0)[0][0];
  res /= polynomial_matrix_prod(denom, k - deg + 1)[0][0];
  return res;
}

// K 項列挙
template <typename mint>
vector<mint> kth_term_of_p_recursive_enumerate(vector<mint>& a, long long K,
                                               int d) {
  if (K < (int)a.size()) return {begin(a), begin(a) + K};
  if (all_of(begin(a), end(a), [](mint x) { return x == mint(0); }))
    return vector<mint>(K, 0);
  auto fs = find_p_recursive(a, d);
  if (fs.empty()) return {};

  int k = fs.size() - 1, is = a.size();
  a.resize(K);
  for (auto& f : fs) f.shrink();
  reverse(begin(fs), end(fs));
  for (int ipk = is; ipk < K; ipk++) {
    int i = ipk - k;
    mint s = 0;
    for (int j = 0; j < k; j++) {
      if (i + j >= 0) s += a[i + j] * fs[j].eval(i);
    }
    a[ipk] = -s / fs[k].eval(i);
  }
  return a;
}

template <typename mint>
mint kth_term_of_p_recursive(vector<mint>& a, long long k) {
  if (k < (int)a.size()) return a[k];
  if (all_of(begin(a), end(a), [](mint x) { return x == mint(0); })) return 0;

  int n = a.size() - 1;
  vector<mint> b{begin(a), end(a) - 1};

  for (int d = 0;; d++) {
#ifdef NyaanLocal
    cerr << "d = " << d << endl;
#endif
    if ((n + 2) / (d + 2) <= 1) break;
    if (kth_term_of_p_recursive(b, n, d) == a.back()) {
#ifdef NyaanLocal
      cerr << "Found, d = " << d << endl;
#endif
      return kth_term_of_p_recursive(a, k, d);
    }
  }
  cerr << "Failed." << endl;
  exit(1);
}



/**
 * @brief P-recursiveの高速計算
 * @docs docs/fps/find-p-recursive.md
 */
