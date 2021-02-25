#pragma once

#include "../modulo/binomial.hpp"

// given  : f(0)...f(k) (deg(f) = k), a, n
// return : sum_{i=0...n-1} a^i f(i)
template <typename mint>
mint sum_of_exp(const vector<mint>& f, mint a, long long n,
                Binomial<mint>& C) {
  if (n == 0) return mint(0);
  if (a == mint(0)) return f[0];
  if (a == mint(1)) {
    vector<mint> g(f.size() + 1, mint(0));
    for (int i = 1; i < (int)g.size(); i++) g[i] = g[i - 1] + f[i - 1];
    return lagrange_interpolation(g, n, C);
  }
  int K = f.size() - 1;
  vector<mint> g(f.size());
  mint buf = 1;
  for (int i = 0; i < (int)g.size(); i++) g[i] = f[i] * buf, buf *= a;
  for (int i = 1; i < (int)g.size(); i++) g[i] += g[i - 1];
  mint c = 0, buf2 = 1;
  for (int i = 0; i <= K; i++) c += C.C(K + 1, i) * buf2 * g[K - i], buf2 *= -a;
  c /= (-a + 1).pow(K + 1);
  mint buf3 = 1, ia = a.inverse();
  for (int i = 0; i < (int)g.size(); i++) g[i] = (g[i] - c) * buf3, buf3 *= ia;
  mint tn = lagrange_interpolation(g, n - 1, C);
  return tn * a.pow(n - 1) + c;
}

// given  : f(0)...f(k) (deg(f) = k), a
// return : sum_{i=0...infty} a^i f(i)
template <typename mint>
mint sum_of_exp_limit(const vector<mint>& f, mint a, Binomial<mint>& C) {
  if (a == mint(0)) return f[0];
  int K = f.size() - 1;
  vector<mint> g(f.size());
  mint buf = 1;
  for (int i = 0; i < (int)g.size(); i++) g[i] = f[i] * buf, buf *= a;
  for (int i = 1; i < (int)g.size(); i++) g[i] += g[i - 1];
  mint c = 0, buf2 = 1;
  for (int i = 0; i <= K; i++) c += C.C(K + 1, i) * buf2 * g[K - i], buf2 *= -a;
  c /= (-a + 1).pow(K + 1);
  return c;
}

// given  : p, n
// return : (0^p, 1^p, ... , n^p)
template <typename mint>
vector<mint> exp_enamurate(int p, int n) {
  vector<mint> f(n + 1, mint(0));
  if (!p) {
    f[0] = 1;
    return std::move(f);
  }
  f[1] = 1;
  vector<bool> sieve(n + 1, false);
  vector<int> ps;
  for (int i = 2; i <= n; i++) {
    if (!sieve[i]) {
      f[i] = mint(i).pow(p);
      ps.push_back(i);
    }
    for (int j = 0; j < (int)ps.size() && i * ps[j] <= n; j++) {
      sieve[i * ps[j]] = 1;
      f[i * ps[j]] = f[i] * f[ps[j]];
      if (i % ps[j] == 0) break;
    }
  }
  return std::move(f);
}

// given  : d, r, n
// return : sum_{i=0...n-1} r^i i^d
template <typename mint>
mint sum_of_exp2(int d, mint r, long long n, Binomial<mint>& C) {
  vector<mint> f = exp_enamurate<mint>(d, d);
  return sum_of_exp(f, r, n, C);
}

// given  : d, r
// return : sum_{i=0...infty} r^i i^d
template <typename mint>
mint sum_of_exp_limit2(int d, mint r, Binomial<mint>& C) {
  vector<mint> f = exp_enamurate<mint>(d, d);
  return sum_of_exp_limit(f, r, C);
}

/**
 * @brief $\sum_{i}a^i f(i)$
 * @docs docs/fps/sum-of-exponential-times-poly.md
 */
