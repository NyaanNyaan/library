---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/timer.hpp
    title: misc/timer.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"trial/fast-inv.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nnamespace fast_inv {\nusing u64 = uint64_t;\nusing u32 = uint32_t;\n\
    using i32 = int32_t;\nconstexpr u32 MOD = 998244353;\n\nstruct Pre {\n  u32 a[64];\n\
    \  constexpr Pre() : a() {\n    static_assert(MOD & 1);\n    a[0] = 1;\n    for\
    \ (int i = 1; i < 64; i++) a[i] = u64(a[i - 1]) * ((MOD + 1) >> 1) % MOD;\n  }\n\
    } constexpr pre;\n\n__attribute__((target(\"bmi\"))) u32 bgcd_inv(u32 a) {\n \
    \ u32 b = MOD, s = 1, t = 0;\n  int n = __builtin_ctz(a);\n  a >>= n;\n  if (__builtin_expect(a\
    \ < 1 << 20, false)) {\n    if (a == 1) return pre.a[n];\n    t = -(b / a);\n\
    \    b %= a;\n    int m = __builtin_ctz(b);\n    b >>= m;\n    s = 1u << m;\n\
    \    n += m;\n  }\n  while (a != b) {\n    int m = __builtin_ctz(a - b);\n   \
    \ n += m;\n    if (a > b) {\n      a -= b;\n      s -= t;\n      a >>= m;\n  \
    \    t <<= m;\n    } else {\n      b -= a;\n      t -= s;\n      b >>= m;\n  \
    \    s <<= m;\n    }\n  }\n  return u64(s) * pre.a[n] % MOD;\n}\n\n}  // namespace\
    \ fast_inv\n\nnamespace fast_inv {\n\n#line 3 \"misc/timer.hpp\"\nusing namespace\
    \ std;\n\nstruct Timer {\n  chrono::high_resolution_clock::time_point st;\n\n\
    \  Timer() { reset(); }\n\n  void reset() { st = chrono::high_resolution_clock::now();\
    \ }\n\n  chrono::milliseconds::rep elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n\
    \    return chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n\
    };\n#line 56 \"trial/fast-inv.hpp\"\n__attribute__((optimize(\"unroll-loops\"\
    ))) u32 pow_inv(u32 a) {\n  u32 ret = 1;\n  for (u32 p = MOD - 2; p; a = u64(a)\
    \ * a % MOD, p >>= 1)\n    if (p & 1) ret = u64(ret) * a % MOD;\n  return ret;\n\
    }\n\nu32 egcd_inv(u32 a) {\n  u32 b = MOD, s = 1, t = 0;\n  while (true) {\n \
    \   if (a == 1) return s;\n    t -= b / a * s;\n    b %= a;\n    if (b == 1) return\
    \ t + MOD;\n    s -= a / b * t;\n    a %= b;\n  }\n}\n\nu32 reduce(const u64 &b)\
    \ { return (b + u64(u32(b) * 998244351u) * MOD) >> 32; }\n\nu32 mul(const u32\
    \ &a, const u32 &b) { return reduce(u64(a) * b); }\n\n__attribute__((optimize(\"\
    unroll-loops\"))) u32 montgomery_pow_inv(u32 a) {\n  u32 ret = 301989884u;\n \
    \ for (u32 p = MOD - 2; p; a = mul(a, a), p >>= 1)\n    if (p & 1) ret = mul(ret,\
    \ a);\n  return reduce(reduce(ret));\n}\n\nu64 x_;\nvoid rng_init() { x_ = 88172645463325252ULL;\
    \ }\nu64 rng() { return x_ = x_ ^ (x_ << 7), x_ = x_ ^ (x_ >> 9); }\n\nvoid test_inner(u32\
    \ (*f)(u32)) {\n  auto test = [](u32 (*f)(u32), int n, u32 upper, string s) {\n\
    \    assert((upper & (upper - 1)) == 0);\n    --upper;\n\n    // set timer\n \
    \   Timer timer;\n    timer.reset();\n\n    // calculation\n    u64 res = 0;\n\
    \    while (n--) {\n      u32 a;\n      do {\n        a = rng() & upper;\n   \
    \     a = a >= MOD ? a - MOD : a;\n      } while (a == 0);\n      res += f(a);\n\
    \    }\n\n    // output results\n    cerr << s << \" \" << res << \" \" << timer.elapsed()\
    \ << endl;\n  };\n\n  rng_init();\n  test(f, 1e7, 1 << 10, \"small\");\n  test(f,\
    \ 1e7, 1 << 20, \"medium\");\n  test(f, 1e7, 1 << 30, \"large\");\n}\n\nvoid unit_test()\
    \ {\n  using F = u32 (*)(u32);\n\n  vector<u32> testcase;\n  for (u32 i = 1; i\
    \ <= 100000; ++i) testcase.emplace_back(i);\n  rng_init();\n  for (u32 loop =\
    \ 100000; --loop;) {\n    u32 r = rng() % MOD;\n    if (r != 0) testcase.emplace_back(r);\n\
    \  }\n  vector<F> functions = {pow_inv, egcd_inv, montgomery_pow_inv, bgcd_inv};\n\
    \n  for (auto t : testcase) {\n    unordered_set<u32> s;\n    for (auto &f : functions)\
    \ {\n      s.insert(f(t));\n    }\n    if (s.size() != 1u) {\n      cerr << \"\
    verify failed.\" << endl;\n      cerr << \"case : \" << t << endl;\n      cerr\
    \ << \"output : \";\n      for (auto &f : functions) cerr << f(t) << \", \";\n\
    \      cerr << endl;\n      exit(1);\n    }\n  }\n  cerr << \"verify passed.\"\
    \ << endl;\n\n  // pow-inv\n  cerr << \"pow-inv\" << endl;\n  test_inner(pow_inv);\n\
    \n  // extgcd-inv\n  cerr << \"extgcd-inv\" << endl;\n  test_inner(egcd_inv);\n\
    \n  // montgomery-inv\n  cerr << \"montgomery-inv\" << endl;\n  test_inner(montgomery_pow_inv);\n\
    \n  // binary-gcd-inv\n  cerr << \"binary-gcd-inv\" << endl;\n  test_inner(bgcd_inv);\n\
    }\n\n}  // namespace fast_inv\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nnamespace\
    \ fast_inv {\nusing u64 = uint64_t;\nusing u32 = uint32_t;\nusing i32 = int32_t;\n\
    constexpr u32 MOD = 998244353;\n\nstruct Pre {\n  u32 a[64];\n  constexpr Pre()\
    \ : a() {\n    static_assert(MOD & 1);\n    a[0] = 1;\n    for (int i = 1; i <\
    \ 64; i++) a[i] = u64(a[i - 1]) * ((MOD + 1) >> 1) % MOD;\n  }\n} constexpr pre;\n\
    \n__attribute__((target(\"bmi\"))) u32 bgcd_inv(u32 a) {\n  u32 b = MOD, s = 1,\
    \ t = 0;\n  int n = __builtin_ctz(a);\n  a >>= n;\n  if (__builtin_expect(a <\
    \ 1 << 20, false)) {\n    if (a == 1) return pre.a[n];\n    t = -(b / a);\n  \
    \  b %= a;\n    int m = __builtin_ctz(b);\n    b >>= m;\n    s = 1u << m;\n  \
    \  n += m;\n  }\n  while (a != b) {\n    int m = __builtin_ctz(a - b);\n    n\
    \ += m;\n    if (a > b) {\n      a -= b;\n      s -= t;\n      a >>= m;\n    \
    \  t <<= m;\n    } else {\n      b -= a;\n      t -= s;\n      b >>= m;\n    \
    \  s <<= m;\n    }\n  }\n  return u64(s) * pre.a[n] % MOD;\n}\n\n}  // namespace\
    \ fast_inv\n\nnamespace fast_inv {\n\n#include \"misc/timer.hpp\"\n__attribute__((optimize(\"\
    unroll-loops\"))) u32 pow_inv(u32 a) {\n  u32 ret = 1;\n  for (u32 p = MOD - 2;\
    \ p; a = u64(a) * a % MOD, p >>= 1)\n    if (p & 1) ret = u64(ret) * a % MOD;\n\
    \  return ret;\n}\n\nu32 egcd_inv(u32 a) {\n  u32 b = MOD, s = 1, t = 0;\n  while\
    \ (true) {\n    if (a == 1) return s;\n    t -= b / a * s;\n    b %= a;\n    if\
    \ (b == 1) return t + MOD;\n    s -= a / b * t;\n    a %= b;\n  }\n}\n\nu32 reduce(const\
    \ u64 &b) { return (b + u64(u32(b) * 998244351u) * MOD) >> 32; }\n\nu32 mul(const\
    \ u32 &a, const u32 &b) { return reduce(u64(a) * b); }\n\n__attribute__((optimize(\"\
    unroll-loops\"))) u32 montgomery_pow_inv(u32 a) {\n  u32 ret = 301989884u;\n \
    \ for (u32 p = MOD - 2; p; a = mul(a, a), p >>= 1)\n    if (p & 1) ret = mul(ret,\
    \ a);\n  return reduce(reduce(ret));\n}\n\nu64 x_;\nvoid rng_init() { x_ = 88172645463325252ULL;\
    \ }\nu64 rng() { return x_ = x_ ^ (x_ << 7), x_ = x_ ^ (x_ >> 9); }\n\nvoid test_inner(u32\
    \ (*f)(u32)) {\n  auto test = [](u32 (*f)(u32), int n, u32 upper, string s) {\n\
    \    assert((upper & (upper - 1)) == 0);\n    --upper;\n\n    // set timer\n \
    \   Timer timer;\n    timer.reset();\n\n    // calculation\n    u64 res = 0;\n\
    \    while (n--) {\n      u32 a;\n      do {\n        a = rng() & upper;\n   \
    \     a = a >= MOD ? a - MOD : a;\n      } while (a == 0);\n      res += f(a);\n\
    \    }\n\n    // output results\n    cerr << s << \" \" << res << \" \" << timer.elapsed()\
    \ << endl;\n  };\n\n  rng_init();\n  test(f, 1e7, 1 << 10, \"small\");\n  test(f,\
    \ 1e7, 1 << 20, \"medium\");\n  test(f, 1e7, 1 << 30, \"large\");\n}\n\nvoid unit_test()\
    \ {\n  using F = u32 (*)(u32);\n\n  vector<u32> testcase;\n  for (u32 i = 1; i\
    \ <= 100000; ++i) testcase.emplace_back(i);\n  rng_init();\n  for (u32 loop =\
    \ 100000; --loop;) {\n    u32 r = rng() % MOD;\n    if (r != 0) testcase.emplace_back(r);\n\
    \  }\n  vector<F> functions = {pow_inv, egcd_inv, montgomery_pow_inv, bgcd_inv};\n\
    \n  for (auto t : testcase) {\n    unordered_set<u32> s;\n    for (auto &f : functions)\
    \ {\n      s.insert(f(t));\n    }\n    if (s.size() != 1u) {\n      cerr << \"\
    verify failed.\" << endl;\n      cerr << \"case : \" << t << endl;\n      cerr\
    \ << \"output : \";\n      for (auto &f : functions) cerr << f(t) << \", \";\n\
    \      cerr << endl;\n      exit(1);\n    }\n  }\n  cerr << \"verify passed.\"\
    \ << endl;\n\n  // pow-inv\n  cerr << \"pow-inv\" << endl;\n  test_inner(pow_inv);\n\
    \n  // extgcd-inv\n  cerr << \"extgcd-inv\" << endl;\n  test_inner(egcd_inv);\n\
    \n  // montgomery-inv\n  cerr << \"montgomery-inv\" << endl;\n  test_inner(montgomery_pow_inv);\n\
    \n  // binary-gcd-inv\n  cerr << \"binary-gcd-inv\" << endl;\n  test_inner(bgcd_inv);\n\
    }\n\n}  // namespace fast_inv"
  dependsOn:
  - misc/timer.hpp
  isVerificationFile: false
  path: trial/fast-inv.hpp
  requiredBy: []
  timestamp: '2020-10-01 23:30:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: trial/fast-inv.hpp
layout: document
redirect_from:
- /library/trial/fast-inv.hpp
- /library/trial/fast-inv.hpp.html
title: trial/fast-inv.hpp
---
