#pragma once



pair<vector<long long>, vector<long long>> pi_table(long long N) {
  using i64 = long long;
  vector<i64> ns{0};
  for (i64 i = N; i > 0; i = N / (N / i + 1)) ns.push_back(i);
  vector<i64> h(ns);
  for (auto &x : h) --x;
  for (i64 x = 2, sq = sqrtl(N), nsz = ns.size(); x <= sq; ++x) {
    if (h[nsz - x] == h[nsz - x + 1]) continue;
    i64 x2 = x * x, pi = h[nsz - x + 1];
    for (i64 i = 1, n = ns[i]; i < nsz && n >= x2; n = ns[++i])
      h[i] -= h[i * x <= sq ? i * x : nsz - n / x] - pi;
  }
  return {ns, h};
}

long long prime_counting(long long N) {
  if (N < 2) return 0;
  return pi_table(N).second[1];
}

/**
 * @brief 素数カウント( $\mathrm{O}(\frac{N^{\frac{3}{4}}}{\log N})$ )
 * @docs docs/multiplicative-function/prime-counting.md
 */
