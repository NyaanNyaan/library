#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

#include "../math/enumerate-quotient.hpp"
#include "../math/isqrt.hpp"
#include "mf-famous-series.hpp"

long long count_square_free(long long N) {
  long long B = pow(N, 0.4);

  auto pre = mobius_function<int>(B + 1);
  for (int i = 1; i <= B; i++) pre[i] += pre[i - 1];
  unordered_map<long long, long long> dp;
  auto mu = [&](auto rc, long long n) -> long long {
    if (n <= B) return pre[n];
    if (dp.count(n)) return dp[n];
    long long cur = 1;
    enumerate_quotient(n, [&](long long q, long long l, long long r) {
      if (q != n) cur -= rc(rc, q) * (r - l);
    });
    return dp[n] = cur;
  };

  long long ans = 0;
  long long upper = isqrt(N);
  for (long long i = 1; upper > B; i++) {
    long long nxt = isqrt(N / (i + 1));
    ans += i * (mu(mu, upper) - mu(mu, nxt));
    upper = nxt;
  }
  while (upper > 0) {
    ans += (pre[upper] - pre[upper - 1]) * (N / (upper * upper));
    upper--;
  }
  return ans;
}

/**
 * @brief 無平方数の数え上げ
 */
