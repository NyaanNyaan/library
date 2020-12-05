---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/timer.hpp
    title: misc/timer.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/fast-inv-gcd.test.cpp
    title: verify/verify-unit-test/fast-inv-gcd.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/trial/fast-gcd.md
    document_title: "\u9AD8\u901FGCD"
    links: []
  bundledCode: "#line 2 \"trial/fast-gcd.hpp\"\n\n\n\n#line 2 \"misc/timer.hpp\"\n\
    \n\n\nstruct Timer {\n  chrono::high_resolution_clock::time_point st;\n\n  Timer()\
    \ { reset(); }\n\n  void reset() { st = chrono::high_resolution_clock::now();\
    \ }\n\n  chrono::milliseconds::rep elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n\
    \    return chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n\
    };\n#line 6 \"trial/fast-gcd.hpp\"\n\nnamespace fast_gcd {\nusing u64 = uint64_t;\n\
    using u32 = uint32_t;\n\n__attribute__((target(\"bmi\"))) u64 binary_gcd(u64 a,\
    \ u64 b) {\n  if (a == 0 || b == 0) return a + b;\n  int n = __builtin_ctzll(a);\n\
    \  int m = __builtin_ctzll(b);\n  a >>= n;\n  b >>= m;\n  while (a != b) {\n \
    \   int m = __builtin_ctzll(a - b);\n    bool f = a > b;\n    u64 c = f ? a :\
    \ b;\n    b = f ? b : a;\n    a = (c - b) >> m;\n  }\n  return a << min(n, m);\n\
    }\n}  // namespace fast_gcd\n\nnamespace fast_gcd {\n\nuint64_t naive_gcd(uint64_t\
    \ a, uint64_t b) {\n  while (b) swap(a %= b, b);\n  return a;\n}\n\nu64 x_;\n\
    void rng_init() { x_ = 88172645463325252ULL; }\nu64 rng() { return x_ = x_ ^ (x_\
    \ << 7), x_ = x_ ^ (x_ >> 9); }\n\nvoid test_inner(u64 (*f)(u64, u64)) {\n  auto\
    \ test = [&](u64 (*f)(u64, u64), int n, u64 upper, string s) {\n    assert((upper\
    \ & (upper - 1)) == 0);\n    --upper;\n\n    // set timer\n    Timer timer;\n\
    \    timer.reset();\n\n    // calculation\n    u64 res = 0;\n    while (n--) {\n\
    \      u64 a = rng() & upper;\n      u64 b = rng() & upper;\n      res += f(a,\
    \ b);\n    }\n\n    // output results\n    cerr << s << \" \" << res << \" \"\
    \ << timer.elapsed() << endl;\n  };\n\n  rng_init();\n  test(f, 1e5, 1LL << 16,\
    \ \"small\");\n  test(f, 1e5, 1LL << 32, \"medium\");\n  test(f, 1e5, 0, \"large\"\
    );\n}\n\nvoid unit_test() {\n  using P = pair<u64, u64>;\n  using F = u64 (*)(u64,\
    \ u64);\n\n  vector<P> testcase{P(2, 4),\n                     P(100000, 10000),\n\
    \                     P(998244353, 1000000007),\n                     P(1LL <<\
    \ 40, 1LL << 60),\n                     P((1LL << 61) - 1, 11111111111111111),\n\
    \                     P((1LL << 60) + 1, (1LL << 59) + 1),\n                 \
    \    P(1LL << 63, 1LL << 63),\n                     P(1LL << 63, 1LL << 62),\n\
    \                     P(3LL << 61, 9LL << 60)};\n  for (u64 i = 1000; i--;)\n\
    \    for (u64 j = 1000; j--;) testcase.emplace_back(i, j);\n  rng_init();\n  for\
    \ (u64 n = 10000; n--;) {\n    u64 i = rng(), j = rng();\n    testcase.emplace_back(i,\
    \ j);\n  }\n\n  vector<F> functions{\n      std::__gcd<uint64_t>,\n      naive_gcd,\n\
    \      binary_gcd,\n  };\n\n  for (auto p : testcase) {\n    unordered_set<u64>\
    \ s;\n    for (auto &f : functions) {\n      s.insert(f(p.first, p.second));\n\
    \    }\n    if (s.size() != 1u) {\n      cerr << \"verify failed.\" << endl;\n\
    \      cerr << \"case : \" << p.first << \" \" << p.second << endl;\n      cerr\
    \ << \"output : \";\n      for (auto &f : functions) cerr << f(p.first, p.second)\
    \ << \", \";\n      cerr << endl;\n      exit(1);\n    }\n  }\n  cerr << \"verify\
    \ passed.\" << endl;\n\n  // std::__gcd\n  cerr << \"std::__gcd\" << endl;\n \
    \ test_inner(std::__gcd<uint64_t>);\n\n  // naive-gcd\n  cerr << \"naive-gcd\"\
    \ << endl;\n  test_inner(naive_gcd);\n\n  // binary-gcd\n  cerr << \"binary-gcd\"\
    \ << endl;\n  test_inner(binary_gcd);\n}\n\n}  // namespace fast_gcd\n\n/**\n\
    \ * @brief \u9AD8\u901FGCD\n * @docs docs/trial/fast-gcd.md\n */\n"
  code: "#pragma once\n\n\n\n#include \"../misc/timer.hpp\"\n\nnamespace fast_gcd\
    \ {\nusing u64 = uint64_t;\nusing u32 = uint32_t;\n\n__attribute__((target(\"\
    bmi\"))) u64 binary_gcd(u64 a, u64 b) {\n  if (a == 0 || b == 0) return a + b;\n\
    \  int n = __builtin_ctzll(a);\n  int m = __builtin_ctzll(b);\n  a >>= n;\n  b\
    \ >>= m;\n  while (a != b) {\n    int m = __builtin_ctzll(a - b);\n    bool f\
    \ = a > b;\n    u64 c = f ? a : b;\n    b = f ? b : a;\n    a = (c - b) >> m;\n\
    \  }\n  return a << min(n, m);\n}\n}  // namespace fast_gcd\n\nnamespace fast_gcd\
    \ {\n\nuint64_t naive_gcd(uint64_t a, uint64_t b) {\n  while (b) swap(a %= b,\
    \ b);\n  return a;\n}\n\nu64 x_;\nvoid rng_init() { x_ = 88172645463325252ULL;\
    \ }\nu64 rng() { return x_ = x_ ^ (x_ << 7), x_ = x_ ^ (x_ >> 9); }\n\nvoid test_inner(u64\
    \ (*f)(u64, u64)) {\n  auto test = [&](u64 (*f)(u64, u64), int n, u64 upper, string\
    \ s) {\n    assert((upper & (upper - 1)) == 0);\n    --upper;\n\n    // set timer\n\
    \    Timer timer;\n    timer.reset();\n\n    // calculation\n    u64 res = 0;\n\
    \    while (n--) {\n      u64 a = rng() & upper;\n      u64 b = rng() & upper;\n\
    \      res += f(a, b);\n    }\n\n    // output results\n    cerr << s << \" \"\
    \ << res << \" \" << timer.elapsed() << endl;\n  };\n\n  rng_init();\n  test(f,\
    \ 1e5, 1LL << 16, \"small\");\n  test(f, 1e5, 1LL << 32, \"medium\");\n  test(f,\
    \ 1e5, 0, \"large\");\n}\n\nvoid unit_test() {\n  using P = pair<u64, u64>;\n\
    \  using F = u64 (*)(u64, u64);\n\n  vector<P> testcase{P(2, 4),\n           \
    \          P(100000, 10000),\n                     P(998244353, 1000000007),\n\
    \                     P(1LL << 40, 1LL << 60),\n                     P((1LL <<\
    \ 61) - 1, 11111111111111111),\n                     P((1LL << 60) + 1, (1LL <<\
    \ 59) + 1),\n                     P(1LL << 63, 1LL << 63),\n                 \
    \    P(1LL << 63, 1LL << 62),\n                     P(3LL << 61, 9LL << 60)};\n\
    \  for (u64 i = 1000; i--;)\n    for (u64 j = 1000; j--;) testcase.emplace_back(i,\
    \ j);\n  rng_init();\n  for (u64 n = 10000; n--;) {\n    u64 i = rng(), j = rng();\n\
    \    testcase.emplace_back(i, j);\n  }\n\n  vector<F> functions{\n      std::__gcd<uint64_t>,\n\
    \      naive_gcd,\n      binary_gcd,\n  };\n\n  for (auto p : testcase) {\n  \
    \  unordered_set<u64> s;\n    for (auto &f : functions) {\n      s.insert(f(p.first,\
    \ p.second));\n    }\n    if (s.size() != 1u) {\n      cerr << \"verify failed.\"\
    \ << endl;\n      cerr << \"case : \" << p.first << \" \" << p.second << endl;\n\
    \      cerr << \"output : \";\n      for (auto &f : functions) cerr << f(p.first,\
    \ p.second) << \", \";\n      cerr << endl;\n      exit(1);\n    }\n  }\n  cerr\
    \ << \"verify passed.\" << endl;\n\n  // std::__gcd\n  cerr << \"std::__gcd\"\
    \ << endl;\n  test_inner(std::__gcd<uint64_t>);\n\n  // naive-gcd\n  cerr << \"\
    naive-gcd\" << endl;\n  test_inner(naive_gcd);\n\n  // binary-gcd\n  cerr << \"\
    binary-gcd\" << endl;\n  test_inner(binary_gcd);\n}\n\n}  // namespace fast_gcd\n\
    \n/**\n * @brief \u9AD8\u901FGCD\n * @docs docs/trial/fast-gcd.md\n */\n"
  dependsOn:
  - misc/timer.hpp
  isVerificationFile: false
  path: trial/fast-gcd.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/fast-inv-gcd.test.cpp
documentation_of: trial/fast-gcd.hpp
layout: document
redirect_from:
- /library/trial/fast-gcd.hpp
- /library/trial/fast-gcd.hpp.html
title: "\u9AD8\u901FGCD"
---
## Binary GCD

高速なGCDの高速な実装に関する実験。

#### 概要・結果

$10^7$回ずつ計算したものを速度比較した。

- CPU: Intel core i5-8350U
- コンパイルオプション : `-Wl,-stack,1073741824 -O2`

| アルゴリズム | $\sim 2^{16}$ | $\sim 2^{32}$ | $\sim 2^{64}$    |
| -------- | -------- | -------- | --- |
| std::__gcd()  | 1066    | 2037     | 3960   |
| naive  | 1074    | 2040     |  3977   |
| binary-gcd  | 292 | 512 |  953   |

結論：binary-gcd一択
