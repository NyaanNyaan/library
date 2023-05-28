---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/monotone-minima.hpp
    title: monotone minima
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0952.test.cpp
    title: verify/verify-yuki/yuki-0952.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "monge \u30B0\u30E9\u30D5\u4E0A\u306E d-\u8FBA\u6700\u77ED\u8DEF\
      \u306E d=1,...,N \u306B\u304A\u3051\u308B\u5217\u6319"
    links: []
  bundledCode: "#line 2 \"dp/monge-d-edge-shortest-path-enumerate.hpp\"\n\n#include\
    \ <functional>\n#include <vector>\nusing namespace std;\n\n#line 2 \"dp/monotone-minima.hpp\"\
    \n\n#line 5 \"dp/monotone-minima.hpp\"\nusing namespace std;\n\n// NxN \u884C\u5217\
    \u304C\u3042\u308B\n// m_i := argmin_j (A_{i,j}) \u304C\u5358\u8ABF\u5897\u52A0\
    \u3067\u3042\u308B\u3068\u304D\u306B m_i \u3092\u5217\u6319\u3059\u308B\n// A(i,\
    \ j) : A[i][j] \u3092\u8FD4\u3059\u95A2\u6570\ntemplate <typename T>\nvector<int>\
    \ monotone_minima(int N, const function<T(int, int)>& A) {\n  vector<int> res(N);\n\
    \  auto dfs = [&](auto rc, int is, int ie, int l, int r) -> void {\n    if (is\
    \ == ie) return;\n    int i = (is + ie) / 2;\n    int m = l;\n    T fim = A(i,\
    \ m);\n    for (int k = l + 1; k < r; k++) {\n      T fik = A(i, k);\n      if\
    \ (fik < fim) fim = fik, m = k;\n    }\n    res[i] = m;\n    rc(rc, is, i, l,\
    \ m + 1);\n    rc(rc, i + 1, ie, m, r);\n  };\n  dfs(dfs, 0, N, 0, N);\n  return\
    \ res;\n}\n\n/**\n * @brief monotone minima\n */\n#line 8 \"dp/monge-d-edge-shortest-path-enumerate.hpp\"\
    \n\n// \u8FBA\u30B3\u30B9\u30C8\u304C monge \u3067\u3042\u308B DAG \u306E D \u8FBA\
    \ 0-N \u6700\u77ED\u8DEF\nvector<long long> enumerate_monge_d_edge_shortest_path(\n\
    \    int N, const function<long long(int, int)>& f,\n    long long unreached =\
    \ (1LL << 62) - 1) {\n  using T = __int128_t;\n  T INF = (T{1} << (sizeof(T) *\
    \ 8 - 2)) - 1;\n  vector<long long> ans(N + 1, unreached);\n  vector<T> dp(N +\
    \ 1, INF);\n  dp[0] = 0;\n  for (int d = 1; d <= N; d++) {\n    vector<int> midx\
    \ = monotone_minima<T>(N + 1, [&](int j, int i) -> T {\n      return i < j ? dp[i]\
    \ + f(i, j) : INF;\n    });\n    for (int i = N; i >= d; i--) dp[i] = dp[midx[i]]\
    \ + f(midx[i], i);\n    ans[d] = dp[N];\n  }\n  return ans;\n}\n\n/**\n * @brief\
    \ monge \u30B0\u30E9\u30D5\u4E0A\u306E d-\u8FBA\u6700\u77ED\u8DEF\u306E d=1,...,N\
    \ \u306B\u304A\u3051\u308B\u5217\u6319\n */\n"
  code: "#pragma once\n\n#include <functional>\n#include <vector>\nusing namespace\
    \ std;\n\n#include \"monotone-minima.hpp\"\n\n// \u8FBA\u30B3\u30B9\u30C8\u304C\
    \ monge \u3067\u3042\u308B DAG \u306E D \u8FBA 0-N \u6700\u77ED\u8DEF\nvector<long\
    \ long> enumerate_monge_d_edge_shortest_path(\n    int N, const function<long\
    \ long(int, int)>& f,\n    long long unreached = (1LL << 62) - 1) {\n  using T\
    \ = __int128_t;\n  T INF = (T{1} << (sizeof(T) * 8 - 2)) - 1;\n  vector<long long>\
    \ ans(N + 1, unreached);\n  vector<T> dp(N + 1, INF);\n  dp[0] = 0;\n  for (int\
    \ d = 1; d <= N; d++) {\n    vector<int> midx = monotone_minima<T>(N + 1, [&](int\
    \ j, int i) -> T {\n      return i < j ? dp[i] + f(i, j) : INF;\n    });\n   \
    \ for (int i = N; i >= d; i--) dp[i] = dp[midx[i]] + f(midx[i], i);\n    ans[d]\
    \ = dp[N];\n  }\n  return ans;\n}\n\n/**\n * @brief monge \u30B0\u30E9\u30D5\u4E0A\
    \u306E d-\u8FBA\u6700\u77ED\u8DEF\u306E d=1,...,N \u306B\u304A\u3051\u308B\u5217\
    \u6319\n */\n"
  dependsOn:
  - dp/monotone-minima.hpp
  isVerificationFile: false
  path: dp/monge-d-edge-shortest-path-enumerate.hpp
  requiredBy: []
  timestamp: '2023-05-28 11:24:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-0952.test.cpp
documentation_of: dp/monge-d-edge-shortest-path-enumerate.hpp
layout: document
redirect_from:
- /library/dp/monge-d-edge-shortest-path-enumerate.hpp
- /library/dp/monge-d-edge-shortest-path-enumerate.hpp.html
title: "monge \u30B0\u30E9\u30D5\u4E0A\u306E d-\u8FBA\u6700\u77ED\u8DEF\u306E d=1,...,N\
  \ \u306B\u304A\u3051\u308B\u5217\u6319"
---
