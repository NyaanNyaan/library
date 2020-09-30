#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace fast_inv {
using u64 = uint64_t;
using u32 = uint32_t;
using i32 = int32_t;
constexpr u32 MOD = 998244353;

struct Pre {
  u32 a[64];
  constexpr Pre() : a() {
    static_assert(MOD & 1);
    a[0] = 1;
    for (int i = 1; i < 64; i++) a[i] = u64(a[i - 1]) * ((MOD + 1) >> 1) % MOD;
  }
} constexpr pre;

__attribute__((target("bmi"))) u32 bgcd_inv(u32 a) {
  u32 b = MOD, s = 1, t = 0;
  int n = __builtin_ctz(a);
  a >>= n;
  if(a < 1 << 20) {
    if(a == 1) return pre.a[n];
    t -= b / a;
    b %= a;
    int m = __builtin_ctz(b);
    b >>= m;
    s <<= m;
    n += m;
  }
  while (a != b){
    int m = __builtin_ctz(a - b);
    n += m;
    if (a > b) {
      a -= b;
      s -= t;
      a >>= m;
      t <<= m;
    } else {
      b -= a;
      t -= s;
      b >>= m;
      s <<= m;
    }
  } 
  return u64(s) * pre.a[n] % MOD;
}

}  // namespace fast_inv

namespace fast_inv {

#include "misc/timer.hpp"

u32 pow_inv(u32 a) {
  u32 ret = 1;
  for (u32 p = MOD - 2; p; a = u64(a) * a % MOD, p >>= 1)
    if (p & 1) ret = u64(ret) * a % MOD;
  return ret;
}

u32 egcd_inv(u32 a) {
  u32 b = MOD, s = 1, t = 0;
  while (true) {
    if (a == 1) return s;
    t -= b / a * s;
    b %= a;
    if (b == 1) return t + MOD;
    s -= a / b * t;
    a %= b;
  }
}

u64 x_;
void rng_init() { x_ = 88172645463325252ULL; }
u64 rng() { return x_ = x_ ^ (x_ << 7), x_ = x_ ^ (x_ >> 9); }

void test_inner(u32 (*f)(u32)) {
  auto test = [](u32 (*f)(u32), int n, u32 upper, string s) {
    assert((upper & (upper - 1)) == 0);
    --upper;

    // set timer
    Timer timer;
    timer.reset();

    // calculation
    u64 res = 0;
    while (n--) {
      u32 a;
      do {
        a = rng() & upper;
        a = a >= MOD ? a - MOD : a;
      } while (a == 0);
      res += f(a);
    }

    // output results
    cerr << s << " " << res << " " << timer.elapsed() << endl;
  };

  rng_init();
  test(f, 1e7, 1 << 10, "small");
  test(f, 1e7, 1 << 20, "medium");
  test(f, 1e7, 1 << 30, "large");
}

void unit_test() {
  using F = u32 (*)(u32);

  vector<u32> testcase;
  for (u32 i = 1; i <= 100000; ++i) testcase.emplace_back(i);
  rng_init();
  for (u32 loop = 100000; --loop;) {
    u32 r = rng() % MOD;
    if (r != 0) testcase.emplace_back(r);
  }
  vector<F> functions = {pow_inv, egcd_inv, bgcd_inv};

  for (auto t : testcase) {
    unordered_set<u32> s;
    for (auto &f : functions) {
      s.insert(f(t));
    }
    if (s.size() != 1u) {
      cerr << "verify failed." << endl;
      cerr << "case : " << t << endl;
      cerr << "output : ";
      for (auto &f : functions) cerr << f(t) << ", ";
      cerr << endl;
      exit(1);
    }
  }
  cerr << "verify passed." << endl;

  // pow-inv
  cerr << "pow-inv" << endl;
  test_inner(pow_inv);

  // extgcd-inv
  cerr << "extgcd-inv" << endl;
  test_inner(egcd_inv);

  // binary-gcd-inv
  cerr << "binary-gcd-inv" << endl;
  test_inner(bgcd_inv);
}

}  // namespace fast_inv