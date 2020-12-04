#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
#include "../../prime/fast-factorize.hpp"
#include "../../prime/osak.hpp"

unsigned long long rng2() {
  static unsigned long long x_ =
      chrono::duration_cast<chrono::nanoseconds>(
          chrono::high_resolution_clock::now().time_since_epoch())
          .count();
  x_ = x_ ^ (x_ << 7);
  return x_ = x_ ^ (x_ >> 9);
}

using namespace Nyaan; void Nyaan::solve() {
  int a, b;
  cin >> a >> b;
  cout << (a + b) << '\n';

  using u64 = fast_factorize::u64;
  using i64 = fast_factorize::i64;

  auto test = [](uint32_t n) {
    vector<u64> naive_ds;
    for (uint32_t i = 1; i * i <= n; ++i) {
      if (n % i == 0) {
        naive_ds.push_back(i);
        if (i * i != n) naive_ds.push_back(n / i);
      }
    }
    sort(all(naive_ds));
    assert(naive_ds == fast_factorize::divisors(n));

    map<u64, i64> naive_factor;
    uint32_t m = n;
    for (uint32_t i = 2; i * i <= n; ++i) {
      while (m % i == 0) {
        naive_factor[i]++;
        m /= i;
      }
    }
    if (m > 1) naive_factor[m]++;

    assert(naive_factor == fast_factorize::factor_count(n));
  };

  rep(i, 10000) { 
    uint32_t n = (rng() & ((1 << 30) - 1)) + 1; 
    test(i);
    test(n);
  }
}