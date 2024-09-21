---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: dp/monge-d-edge-shortest-path.hpp
    title: "monge \u30B0\u30E9\u30D5\u4E0A\u306E d-\u8FBA\u6700\u77ED\u8DEF"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-3086.test.cpp
    title: verify/verify-aoj-other/aoj-3086.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0703.test.cpp
    title: verify/verify-yuki/yuki-0703.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0704.test.cpp
    title: verify/verify-yuki/yuki-0704.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0705.test.cpp
    title: verify/verify-yuki/yuki-0705.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0952.test.cpp
    title: verify/verify-yuki/yuki-0952.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "monge \u30B0\u30E9\u30D5\u4E0A\u306E\u6700\u77ED\u8DEF"
    links:
    - https://noshi91.hatenablog.com/entry/2023/02/18/005856
  bundledCode: "#line 2 \"dp/monge-shortest-path.hpp\"\n\n#include <functional>\n\
    #include <vector>\nusing namespace std;\n\n// https://noshi91.hatenablog.com/entry/2023/02/18/005856\n\
    // \u8FBA\u30B3\u30B9\u30C8\u304C monge \u3067\u3042\u308B DAG \u306E 0 - i \u6700\
    \u77ED\u8DEF\ntemplate <typename T>\nvector<T> monge_shortest_path(int N, const\
    \ function<T(int, int)>& f) {\n  T INF = (T{1} << (sizeof(T) * 8 - 2)) - 1;\n\
    \  vector<T> dp(N + 1, INF);\n  vector<int> x(N + 1, 0);\n  auto check = [&](int\
    \ from, int to) {\n    if (from >= to) return;\n    T cost = f(from, to);\n  \
    \  if (dp[from] + cost < dp[to]) dp[to] = dp[from] + cost, x[to] = from;\n  };\n\
    \  auto dfs = [&](auto rc, int l, int r) -> void {\n    if (l + 1 >= r) return;\n\
    \    int m = (l + r) / 2;\n    for (int i = x[l]; i <= x[r]; i++) check(i, m);\n\
    \    rc(rc, l, m);\n    for (int i = l + 1; i <= m; i++) check(i, r);\n    rc(rc,\
    \ m, r);\n  };\n  dp[0] = 0, check(0, N), dfs(dfs, 0, N);\n  return dp;\n}\n\n\
    /**\n * @brief monge \u30B0\u30E9\u30D5\u4E0A\u306E\u6700\u77ED\u8DEF\n */\n"
  code: "#pragma once\n\n#include <functional>\n#include <vector>\nusing namespace\
    \ std;\n\n// https://noshi91.hatenablog.com/entry/2023/02/18/005856\n// \u8FBA\
    \u30B3\u30B9\u30C8\u304C monge \u3067\u3042\u308B DAG \u306E 0 - i \u6700\u77ED\
    \u8DEF\ntemplate <typename T>\nvector<T> monge_shortest_path(int N, const function<T(int,\
    \ int)>& f) {\n  T INF = (T{1} << (sizeof(T) * 8 - 2)) - 1;\n  vector<T> dp(N\
    \ + 1, INF);\n  vector<int> x(N + 1, 0);\n  auto check = [&](int from, int to)\
    \ {\n    if (from >= to) return;\n    T cost = f(from, to);\n    if (dp[from]\
    \ + cost < dp[to]) dp[to] = dp[from] + cost, x[to] = from;\n  };\n  auto dfs =\
    \ [&](auto rc, int l, int r) -> void {\n    if (l + 1 >= r) return;\n    int m\
    \ = (l + r) / 2;\n    for (int i = x[l]; i <= x[r]; i++) check(i, m);\n    rc(rc,\
    \ l, m);\n    for (int i = l + 1; i <= m; i++) check(i, r);\n    rc(rc, m, r);\n\
    \  };\n  dp[0] = 0, check(0, N), dfs(dfs, 0, N);\n  return dp;\n}\n\n/**\n * @brief\
    \ monge \u30B0\u30E9\u30D5\u4E0A\u306E\u6700\u77ED\u8DEF\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/monge-shortest-path.hpp
  requiredBy:
  - dp/monge-d-edge-shortest-path.hpp
  timestamp: '2023-05-23 20:26:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-other/aoj-3086.test.cpp
  - verify/verify-yuki/yuki-0705.test.cpp
  - verify/verify-yuki/yuki-0952.test.cpp
  - verify/verify-yuki/yuki-0704.test.cpp
  - verify/verify-yuki/yuki-0703.test.cpp
documentation_of: dp/monge-shortest-path.hpp
layout: document
redirect_from:
- /library/dp/monge-shortest-path.hpp
- /library/dp/monge-shortest-path.hpp.html
title: "monge \u30B0\u30E9\u30D5\u4E0A\u306E\u6700\u77ED\u8DEF"
---
