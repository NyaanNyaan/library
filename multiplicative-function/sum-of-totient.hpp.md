---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/sum-of-mf.test.cpp
    title: verify/verify-unit-test/sum-of-mf.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-sum-of-totient.test.cpp
    title: verify/verify-yosupo-math/yosupo-sum-of-totient.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570\u306E\u548C"
    links: []
  bundledCode: "#line 2 \"multiplicative-function/sum-of-totient.hpp\"\n\ntemplate\
    \ <typename T>\nT sum_of_totient(long long N) {\n  if (N < 2) return N;\n  using\
    \ i64 = long long;\n\n  auto f = [](i64 v, i64 p, i64) -> i64 { return v / p *\
    \ (p - 1); };\n  vector<i64> ns{0}, p;\n  for (i64 i = N; i > 0; i = N / (N /\
    \ i + 1)) ns.push_back(i);\n  i64 s = ns.size(), sq = sqrt(N);\n  auto idx = [&](i64\
    \ n) { return n <= sq ? s - n : N / n; };\n\n  vector<T> h0(s), h1(s), buf(s);\n\
    \  for (int i = 0; i < s; i++) {\n    T x = ns[i];\n    h0[i] = x - 1;\n    h1[i]\
    \ = x * (x + 1) / 2 - 1;\n  }\n\n  for (i64 x = 2; x <= sq; ++x) {\n    if (h0[s\
    \ - x] == h0[s - x + 1]) continue;\n    p.push_back(x);\n    i64 x2 = x * x;\n\
    \    for (i64 i = 1, n = ns[i]; i < s && n >= x2; n = ns[++i]) {\n      int id\
    \ = (i * x <= sq ? i * x : s - n / x);\n      h0[i] -= h0[id] - h0[s - x + 1];\n\
    \      h1[i] -= (h1[id] - h1[s - x + 1]) * x;\n    }\n  }\n\n  for (int i = 0;\
    \ i < s; i++) buf[i] = h1[i] - h0[i];\n  T ans = buf[idx(N)] + 1;\n\n  auto dfs\
    \ = [&](auto rec, int i, int c, i64 v, i64 lim, T cur) -> void {\n    ans += cur\
    \ * f(p[i] * v, p[i], c + 1);\n    if (lim >= p[i] * p[i]) rec(rec, i, c + 1,\
    \ p[i] * v, lim / p[i], cur);\n    cur *= f(v, p[i], c);\n    ans += cur * (buf[idx(lim)]\
    \ - buf[idx(p[i])]);\n    for (int j = i + 1; j < (int)p.size() && p[j] * p[j]\
    \ <= lim; j++) {\n      rec(rec, j, 1, p[j], lim / p[j], cur);\n    }\n  };\n\n\
    \  for (int i = 0; i < (int)p.size(); i++) dfs(dfs, i, 1, p[i], N / p[i], 1);\n\
    \  return ans;\n}\n\n/**\n * @brief \u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\
    \u6570\u306E\u548C\n */\n"
  code: "#pragma once\n\ntemplate <typename T>\nT sum_of_totient(long long N) {\n\
    \  if (N < 2) return N;\n  using i64 = long long;\n\n  auto f = [](i64 v, i64\
    \ p, i64) -> i64 { return v / p * (p - 1); };\n  vector<i64> ns{0}, p;\n  for\
    \ (i64 i = N; i > 0; i = N / (N / i + 1)) ns.push_back(i);\n  i64 s = ns.size(),\
    \ sq = sqrt(N);\n  auto idx = [&](i64 n) { return n <= sq ? s - n : N / n; };\n\
    \n  vector<T> h0(s), h1(s), buf(s);\n  for (int i = 0; i < s; i++) {\n    T x\
    \ = ns[i];\n    h0[i] = x - 1;\n    h1[i] = x * (x + 1) / 2 - 1;\n  }\n\n  for\
    \ (i64 x = 2; x <= sq; ++x) {\n    if (h0[s - x] == h0[s - x + 1]) continue;\n\
    \    p.push_back(x);\n    i64 x2 = x * x;\n    for (i64 i = 1, n = ns[i]; i <\
    \ s && n >= x2; n = ns[++i]) {\n      int id = (i * x <= sq ? i * x : s - n /\
    \ x);\n      h0[i] -= h0[id] - h0[s - x + 1];\n      h1[i] -= (h1[id] - h1[s -\
    \ x + 1]) * x;\n    }\n  }\n\n  for (int i = 0; i < s; i++) buf[i] = h1[i] - h0[i];\n\
    \  T ans = buf[idx(N)] + 1;\n\n  auto dfs = [&](auto rec, int i, int c, i64 v,\
    \ i64 lim, T cur) -> void {\n    ans += cur * f(p[i] * v, p[i], c + 1);\n    if\
    \ (lim >= p[i] * p[i]) rec(rec, i, c + 1, p[i] * v, lim / p[i], cur);\n    cur\
    \ *= f(v, p[i], c);\n    ans += cur * (buf[idx(lim)] - buf[idx(p[i])]);\n    for\
    \ (int j = i + 1; j < (int)p.size() && p[j] * p[j] <= lim; j++) {\n      rec(rec,\
    \ j, 1, p[j], lim / p[j], cur);\n    }\n  };\n\n  for (int i = 0; i < (int)p.size();\
    \ i++) dfs(dfs, i, 1, p[i], N / p[i], 1);\n  return ans;\n}\n\n/**\n * @brief\
    \ \u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570\u306E\u548C\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: multiplicative-function/sum-of-totient.hpp
  requiredBy: []
  timestamp: '2021-12-20 21:46:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-sum-of-totient.test.cpp
  - verify/verify-unit-test/sum-of-mf.test.cpp
documentation_of: multiplicative-function/sum-of-totient.hpp
layout: document
redirect_from:
- /library/multiplicative-function/sum-of-totient.hpp
- /library/multiplicative-function/sum-of-totient.hpp.html
title: "\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570\u306E\u548C"
---
