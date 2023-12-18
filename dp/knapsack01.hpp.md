---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dpl/aoj-dpl-1-b.test.cpp
    title: verify/verify-aoj-dpl/aoj-dpl-1-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dpl/aoj-dpl-1-f.test.cpp
    title: verify/verify-aoj-dpl/aoj-dpl-1-f.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dpl/aoj-dpl-1-h.test.cpp
    title: verify/verify-aoj-dpl/aoj-dpl-1-h.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/dp/knapsack01.md
    document_title: "0-1\u30CA\u30C3\u30D7\u30B5\u30C3\u30AF\u554F\u984C"
    links: []
  bundledCode: "#line 2 \"dp/knapsack01.hpp\"\n\nlong long knapsack01(const vector<long\
    \ long>& v, const vector<long long>& w,\n                     long long W) {\n\
    \  double v_sum = 0;\n  for (auto& x : v) v_sum += x;\n  double cond1 = log2(double(W)\
    \ * (v.size() + 1));\n  double cond2 = log2(v_sum * (v.size() + 1));\n  double\
    \ cond3 = ((v.size() + 1) / 2) + log2(v.size() + 1);\n  double cond_min = min({cond1,\
    \ cond2, cond3});\n  long long inf = numeric_limits<long long>::max() / 2.1;\n\
    \n  if (cond_min == cond1) {\n    vector<long long> dp(W + 1);\n    for (int i\
    \ = 0; i < (int)v.size(); i++) {\n      long long s = v[i], t = w[i];\n      for\
    \ (int j = W - t; j >= 0; --j) dp[j + t] = max(dp[j + t], dp[j] + s);\n    }\n\
    \    return *max_element(begin(dp), end(dp));\n  }\n  if (cond_min == cond2) {\n\
    \    long long vs = accumulate(begin(v), end(v), 0LL);\n    vector<long long>\
    \ dp(vs + 1, inf);\n    dp[0] = 0;\n    for (int i = 0; i < (int)v.size(); i++)\
    \ {\n      long long s = v[i], t = w[i];\n      for (int j = vs - s; j >= 0; --j)\
    \ dp[j + s] = min(dp[j + s], dp[j] + t);\n    }\n    long long ans = 0;\n    for\
    \ (long long i = 0; i <= vs; i++)\n      if (dp[i] <= W) ans = max(ans, i);\n\
    \    return ans;\n  }\n\n  using P = pair<long long, long long>;\n  auto enumerate\
    \ = [&](int l, int r) -> vector<P> {\n    vector<P> res(1 << (r - l));\n    res[0]\
    \ = P{0, 0};\n    for (int i = 0; i < r - l; i++) {\n      int b = 1 << i;\n \
    \     for (int j = 0; j < b; j++) {\n        res[b + j] = P{res[j].first + w[l\
    \ + i], res[j].second + v[l + i]};\n      }\n    }\n    sort(begin(res), end(res));\n\
    \    for (int i = 1; i < (int)res.size(); i++)\n      res[i].second = max(res[i].second,\
    \ res[i - 1].second);\n    return res;\n  };\n  auto a = enumerate(0, (int)v.size()\
    \ / 2);\n  auto b = enumerate(v.size() / 2, v.size());\n  reverse(begin(a), end(a));\n\
    \  b.emplace_back(inf, inf);\n  long long ans = 0, id = -1;\n  for (auto& [t,\
    \ s] : a) {\n    while (t + b[id + 1].first <= W) ++id;\n    if (id != -1) ans\
    \ = max(ans, s + b[id].second);\n  }\n  return ans;\n}\n\n/**\n * @brief 0-1\u30CA\
    \u30C3\u30D7\u30B5\u30C3\u30AF\u554F\u984C\n * @docs docs/dp/knapsack01.md\n */\n"
  code: "#pragma once\n\nlong long knapsack01(const vector<long long>& v, const vector<long\
    \ long>& w,\n                     long long W) {\n  double v_sum = 0;\n  for (auto&\
    \ x : v) v_sum += x;\n  double cond1 = log2(double(W) * (v.size() + 1));\n  double\
    \ cond2 = log2(v_sum * (v.size() + 1));\n  double cond3 = ((v.size() + 1) / 2)\
    \ + log2(v.size() + 1);\n  double cond_min = min({cond1, cond2, cond3});\n  long\
    \ long inf = numeric_limits<long long>::max() / 2.1;\n\n  if (cond_min == cond1)\
    \ {\n    vector<long long> dp(W + 1);\n    for (int i = 0; i < (int)v.size();\
    \ i++) {\n      long long s = v[i], t = w[i];\n      for (int j = W - t; j >=\
    \ 0; --j) dp[j + t] = max(dp[j + t], dp[j] + s);\n    }\n    return *max_element(begin(dp),\
    \ end(dp));\n  }\n  if (cond_min == cond2) {\n    long long vs = accumulate(begin(v),\
    \ end(v), 0LL);\n    vector<long long> dp(vs + 1, inf);\n    dp[0] = 0;\n    for\
    \ (int i = 0; i < (int)v.size(); i++) {\n      long long s = v[i], t = w[i];\n\
    \      for (int j = vs - s; j >= 0; --j) dp[j + s] = min(dp[j + s], dp[j] + t);\n\
    \    }\n    long long ans = 0;\n    for (long long i = 0; i <= vs; i++)\n    \
    \  if (dp[i] <= W) ans = max(ans, i);\n    return ans;\n  }\n\n  using P = pair<long\
    \ long, long long>;\n  auto enumerate = [&](int l, int r) -> vector<P> {\n   \
    \ vector<P> res(1 << (r - l));\n    res[0] = P{0, 0};\n    for (int i = 0; i <\
    \ r - l; i++) {\n      int b = 1 << i;\n      for (int j = 0; j < b; j++) {\n\
    \        res[b + j] = P{res[j].first + w[l + i], res[j].second + v[l + i]};\n\
    \      }\n    }\n    sort(begin(res), end(res));\n    for (int i = 1; i < (int)res.size();\
    \ i++)\n      res[i].second = max(res[i].second, res[i - 1].second);\n    return\
    \ res;\n  };\n  auto a = enumerate(0, (int)v.size() / 2);\n  auto b = enumerate(v.size()\
    \ / 2, v.size());\n  reverse(begin(a), end(a));\n  b.emplace_back(inf, inf);\n\
    \  long long ans = 0, id = -1;\n  for (auto& [t, s] : a) {\n    while (t + b[id\
    \ + 1].first <= W) ++id;\n    if (id != -1) ans = max(ans, s + b[id].second);\n\
    \  }\n  return ans;\n}\n\n/**\n * @brief 0-1\u30CA\u30C3\u30D7\u30B5\u30C3\u30AF\
    \u554F\u984C\n * @docs docs/dp/knapsack01.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/knapsack01.hpp
  requiredBy: []
  timestamp: '2021-11-17 23:54:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-dpl/aoj-dpl-1-f.test.cpp
  - verify/verify-aoj-dpl/aoj-dpl-1-b.test.cpp
  - verify/verify-aoj-dpl/aoj-dpl-1-h.test.cpp
documentation_of: dp/knapsack01.hpp
layout: document
redirect_from:
- /library/dp/knapsack01.hpp
- /library/dp/knapsack01.hpp.html
title: "0-1\u30CA\u30C3\u30D7\u30B5\u30C3\u30AF\u554F\u984C"
---
## 0-1ナップサック問題

### 概要

> 0-1ナップサック問題
>
> 品物が$N$個(品物$0$から品物$N-1$)あり、品物$i$は価値$v_i$重さ$w_i$である。重さの総和が$W$以下となるようにいくつかの品物を選んだとき、選んだ品物の価値の総和の最大値$V_{\max}$を求めよ。

### 使い方

- `knapsack01(v,w,W)`: 数列$v=\{v_i\}$,$w=\{w_i\}$と値$W$を与えると、0-1ナップサック問題を解いて解$V_{\max}$を返す。計算量$\mathrm{O}(\min \lbrace N W , N \sum v_i , N 2^{\frac{N}{2}} \rbrace )$
