#pragma once



template <typename T = uint32_t, typename U = uint64_t, T MAX = 1000000000>
T tetration(uint64_t a, uint64_t b, uint64_t m) {
  auto prime_table = [](T m) -> vector<int> {
    T thres = sqrt(m) + 1;
    vector<bool> flg(thres + 1);
    for (T i = 2; i * i <= thres; ++i) {
      if (!flg[i])
        for (T j = i * i; j <= thres; j += i) flg[j] = 1;
    }
    vector<int> ret;
    for (T i = 2; i <= thres; i++)
      if (!flg[i]) ret.push_back(i);
    return ret;
  };

  static const vector<int> ps = prime_table(MAX);

  auto totient = [&](T n) -> T {
    T ret = n;
    for (auto& p : ps) {
      if (p * p > n) break;
      if (n % p == 0) {
        ret = ret / p * (p - 1);
        while (n % p == 0) n /= p;
      }
    }
    if (n != 1) ret = ret / n * (n - 1);
    return ret;
  };

  auto mpow = [](U a, U p, T m) -> pair<T, int> {
    U ret = 1 % m;
    int flg = true;
    for (; p; p >>= 1) {
      if (p & 1)
        if ((ret *= a) >= m) flg = 0, ret %= m;
      if (p == 1) break;
      if ((a *= a) >= m) flg = 0, a %= m;
    }
    return {ret, flg};
  };

  auto calc = [&](auto rec, T a, U b, T m) -> pair<T, int> {
    if (a == 0) return {!(b & 1), true};
    if (a == 1) return {1, true};
    if (m == 1) return {0, false};
    if (b == 0) return {1, true};
    if (b == 1) return {a % m, a < m};
    T phi_m = totient(m), pre, ret;
    int flg1, flg2;
    tie(pre, flg1) = rec(rec, a, b - 1, phi_m);
    tie(ret, flg2) = mpow(a % m, U(pre) + (flg1 ? 0 : phi_m), m);
    return {ret, flg1 && flg2};
  };

  return calc(calc, a, b, m).first % m;
}

/**
 * @brief tetration
 * @docs docs/modulo/tetration.md
 */
