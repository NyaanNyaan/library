---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/z-algorithm.hpp
    title: Z algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-run-enumerate.test.cpp
    title: verify/verify-yosupo-string/yosupo-run-enumerate.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/run-enumerate.hpp\"\n\n#include <algorithm>\n#include\
    \ <set>\n#include <utility>\n#include <vector>\nusing namespace std;\n\n#line\
    \ 2 \"string/z-algorithm.hpp\"\n\ntemplate <typename Container>\nvector<int> z_algorithm(const\
    \ Container& s) {\n  int n = s.size();\n  if(n == 0) return {};\n  vector<int>\
    \ a(n);\n  a[0] = n;\n  int i = 1, j = 0;\n  while (i < n) {\n    while (i + j\
    \ < n && s[j] == s[i + j]) j++;\n    a[i] = j;\n    if (j == 0) {\n      i++;\n\
    \      continue;\n    }\n    int k = 1;\n    while (i + k < n && k + a[k] < j)\
    \ a[i + k] = a[k], k++;\n    i += k, j -= k;\n  }\n  return a;\n}\n\n/**\n * @brief\
    \ Z algorithm\n */\n#line 10 \"string/run-enumerate.hpp\"\n\n// (p, l, r) : S[l,\
    \ r) \u306F\u5468\u671F p \u304B\u3064\u6975\u5927\n// sum_{(p,l,r)} 1 <= n\n\
    // sum_{(p,l,r)} (r-l)/p <= 3n\n// sum_{(p,l,r)} (r-l+1-2*p) = O(n log n)\ntemplate\
    \ <typename C>\nvector<tuple<int, int, int>> run_enumerate(const C& S) {\n  int\
    \ N = S.size();\n  using T = tuple<int, int, int>;\n  vector<vector<pair<int,\
    \ int>>> by_p(N + 1);\n\n  auto solve_sub = [&](const C& l, const C& r) {\n  \
    \  vector<T> res;\n    int n = l.size(), m = r.size();\n    C s = l, t = r;\n\
    \    t.insert(end(t), begin(l), end(l));\n    t.insert(end(t), begin(r), end(r));\n\
    \    reverse(begin(s), end(s));\n    auto ZS = z_algorithm(s), ZT = z_algorithm(t);\n\
    \    for (int p = 1; p <= n; p++) {\n      int a = p == n ? p : min(ZS[p] + p,\
    \ n);\n      int b = min(ZT[n + m - p], m);\n      if (a + b < 2 * p) continue;\n\
    \      res.emplace_back(p, a, b);\n    }\n    return res;\n  };\n\n  auto dfs\
    \ = [&](auto rc, int L, int R) -> void {\n    if (R - L <= 1) return;\n    int\
    \ M = (L + R) / 2;\n    rc(rc, L, M), rc(rc, M, R);\n    C SL{begin(S) + L, begin(S)\
    \ + M};\n    C SR{begin(S) + M, begin(S) + R};\n    auto sub_res1 = solve_sub(SL,\
    \ SR);\n    for (auto& [p, a, b] : sub_res1) by_p[p].emplace_back(M - a, M + b);\n\
    \    reverse(begin(SL), end(SL));\n    reverse(begin(SR), end(SR));\n    auto\
    \ sub_res2 = solve_sub(SR, SL);\n    for (auto& [p, a, b] : sub_res2) by_p[p].emplace_back(M\
    \ - b, M + a);\n  };\n  dfs(dfs, 0, N);\n\n  vector<T> res;\n  set<pair<int, int>>\
    \ done;\n  for (int p = 0; p <= N; p++) {\n    auto& LR = by_p[p];\n    sort(begin(LR),\
    \ end(LR), [](auto& x, auto& y) {\n      if (x.first == y.first) return x.second\
    \ > y.second;\n      return x.first < y.first;\n    });\n    int r = -1;\n   \
    \ for (auto& lr : LR) {\n      if (r >= lr.second) continue;\n      r = lr.second;\n\
    \      if (!done.count(lr)) {\n        done.insert(lr);\n        res.emplace_back(p,\
    \ lr.first, lr.second);\n      }\n    }\n  }\n  return res;\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <set>\n#include <utility>\n\
    #include <vector>\nusing namespace std;\n\n#include \"z-algorithm.hpp\"\n\n//\
    \ (p, l, r) : S[l, r) \u306F\u5468\u671F p \u304B\u3064\u6975\u5927\n// sum_{(p,l,r)}\
    \ 1 <= n\n// sum_{(p,l,r)} (r-l)/p <= 3n\n// sum_{(p,l,r)} (r-l+1-2*p) = O(n log\
    \ n)\ntemplate <typename C>\nvector<tuple<int, int, int>> run_enumerate(const\
    \ C& S) {\n  int N = S.size();\n  using T = tuple<int, int, int>;\n  vector<vector<pair<int,\
    \ int>>> by_p(N + 1);\n\n  auto solve_sub = [&](const C& l, const C& r) {\n  \
    \  vector<T> res;\n    int n = l.size(), m = r.size();\n    C s = l, t = r;\n\
    \    t.insert(end(t), begin(l), end(l));\n    t.insert(end(t), begin(r), end(r));\n\
    \    reverse(begin(s), end(s));\n    auto ZS = z_algorithm(s), ZT = z_algorithm(t);\n\
    \    for (int p = 1; p <= n; p++) {\n      int a = p == n ? p : min(ZS[p] + p,\
    \ n);\n      int b = min(ZT[n + m - p], m);\n      if (a + b < 2 * p) continue;\n\
    \      res.emplace_back(p, a, b);\n    }\n    return res;\n  };\n\n  auto dfs\
    \ = [&](auto rc, int L, int R) -> void {\n    if (R - L <= 1) return;\n    int\
    \ M = (L + R) / 2;\n    rc(rc, L, M), rc(rc, M, R);\n    C SL{begin(S) + L, begin(S)\
    \ + M};\n    C SR{begin(S) + M, begin(S) + R};\n    auto sub_res1 = solve_sub(SL,\
    \ SR);\n    for (auto& [p, a, b] : sub_res1) by_p[p].emplace_back(M - a, M + b);\n\
    \    reverse(begin(SL), end(SL));\n    reverse(begin(SR), end(SR));\n    auto\
    \ sub_res2 = solve_sub(SR, SL);\n    for (auto& [p, a, b] : sub_res2) by_p[p].emplace_back(M\
    \ - b, M + a);\n  };\n  dfs(dfs, 0, N);\n\n  vector<T> res;\n  set<pair<int, int>>\
    \ done;\n  for (int p = 0; p <= N; p++) {\n    auto& LR = by_p[p];\n    sort(begin(LR),\
    \ end(LR), [](auto& x, auto& y) {\n      if (x.first == y.first) return x.second\
    \ > y.second;\n      return x.first < y.first;\n    });\n    int r = -1;\n   \
    \ for (auto& lr : LR) {\n      if (r >= lr.second) continue;\n      r = lr.second;\n\
    \      if (!done.count(lr)) {\n        done.insert(lr);\n        res.emplace_back(p,\
    \ lr.first, lr.second);\n      }\n    }\n  }\n  return res;\n}\n"
  dependsOn:
  - string/z-algorithm.hpp
  isVerificationFile: false
  path: string/run-enumerate.hpp
  requiredBy: []
  timestamp: '2024-09-14 20:40:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-string/yosupo-run-enumerate.test.cpp
documentation_of: string/run-enumerate.hpp
layout: document
redirect_from:
- /library/string/run-enumerate.hpp
- /library/string/run-enumerate.hpp.html
title: string/run-enumerate.hpp
---
