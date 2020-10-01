#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace fast_gcd {
using u64 = uint64_t;
using u32 = uint32_t;

__attribute__((target("bmi"))) u64 binary_gcd(u64 a, u64 b) {
  if (a == 0 || b == 0) return a + b;
  int n = __builtin_ctzll(a);
  int m = __builtin_ctzll(b);
  a >>= n;
  b >>= m;
  while (a != b) {
    int m = __builtin_ctzll(a - b);
    bool f = a > b;
    u64 c = f ? a : b;
    b = f ? b : a;
    a = (c - b) >> m;
  }
  return a << min(n, m);
}
}  // namespace fast_gcd

namespace fast_gcd {
#include "misc/timer.hpp"

uint64_t naive_gcd(uint64_t a, uint64_t b) {
  while (b) swap(a %= b, b);
  return a;
}

u64 x_;
void rng_init() { x_ = 88172645463325252ULL; }
u64 rng() { return x_ = x_ ^ (x_ << 7), x_ = x_ ^ (x_ >> 9); }

void test_inner(u64 (*f)(u64, u64)) {
  auto test = [](u64 (*f)(u64, u64), int n, u64 upper, string s) {
    assert((upper & (upper - 1)) == 0);
    --upper;

    // set timer
    Timer timer;
    timer.reset();

    // calculation
    u64 res = 0;
    while (n--) {
      u64 a = rng() & upper;
      u64 b = rng() & upper;
      res += f(a, b);
    }

    // output results
    cerr << s << " " << res << " " << timer.elapsed() << endl;
  };

  rng_init();
  test(f, 1e7, 1LL << 16, "small");
  test(f, 1e7, 1LL << 32, "medium");
  test(f, 1e7, 0, "large");
}

void unit_test() {
  using P = pair<u64, u64>;
  using F = u64 (*)(u64, u64);

  vector<P> testcase{P(2, 4),
                     P(100000, 10000),
                     P(998244353, 1000000007),
                     P(1LL << 40, 1LL << 60),
                     P((1LL << 61) - 1, 11111111111111111),
                     P((1LL << 60) + 1, (1LL << 59) + 1),
                     P(1LL << 63, 1LL << 63),
                     P(1LL << 63, 1LL << 62),
                     P(3LL << 61, 9LL << 60)};
  for (u64 i = 1000; i--;)
    for (u64 j = 1000; j--;) testcase.emplace_back(i, j);
  rng_init();
  for (u64 n = 10000; n--;) {
    u64 i = rng(), j = rng();
    testcase.emplace_back(i, j);
  }

  vector<F> functions{
      std::__gcd<uint64_t>,
      naive_gcd,
      binary_gcd,
  };

  for (auto p : testcase) {
    unordered_set<u64> s;
    for (auto &f : functions) {
      s.insert(f(p.first, p.second));
    }
    if (s.size() != 1u) {
      cerr << "verify failed." << endl;
      cerr << "case : " << p.first << " " << p.second << endl;
      cerr << "output : ";
      for (auto &f : functions) cerr << f(p.first, p.second) << ", ";
      cerr << endl;
      exit(1);
    }
  }
  cerr << "verify passed." << endl;

  // std::__gcd
  cerr << "std::__gcd" << endl;
  test_inner(std::__gcd<uint64_t>);

  // naive-gcd
  cerr << "naive-gcd" << endl;
  test_inner(naive_gcd);

  // binary-gcd
  cerr << "binary-gcd" << endl;
  test_inner(binary_gcd);
}

}  // namespace fast_gcd
