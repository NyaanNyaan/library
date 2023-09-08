---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: dp/concave-min-plus-convolution.hpp
    title: dp/concave-min-plus-convolution.hpp
  - icon: ':heavy_check_mark:'
    path: dp/monge-d-edge-shortest-path-enumerate.hpp
    title: "monge \u30B0\u30E9\u30D5\u4E0A\u306E d-\u8FBA\u6700\u77ED\u8DEF\u306E\
      \ d=1,...,N \u306B\u304A\u3051\u308B\u5217\u6319"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-concave-min-plus-convolution-1.test.cpp
    title: verify/verify-yosupo-math/yosupo-concave-min-plus-convolution-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-concave-min-plus-convolution-2.test.cpp
    title: verify/verify-yosupo-math/yosupo-concave-min-plus-convolution-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0952.test.cpp
    title: verify/verify-yuki/yuki-0952.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: monotone minima
    links: []
  bundledCode: "#line 2 \"dp/monotone-minima.hpp\"\n\n#include <functional>\n#include\
    \ <vector>\nusing namespace std;\n\n// NxN \u884C\u5217\u304C\u3042\u308B\n//\
    \ m_i := argmin_j (A_{i,j}) \u304C\u5358\u8ABF\u5897\u52A0\u3067\u3042\u308B\u3068\
    \u304D\u306B m_i \u3092\u5217\u6319\u3059\u308B\n// f(i, j, k) :\n// A[i][j] \u3068\
    \ A[i][k] \u3092\u6BD4\u8F03 (j < k \u304C\u4FDD\u8A3C\u3055\u308C\u3066\u3044\
    \u308B)\n// A[i][j] <= A[i][k] \u306E\u3068\u304D true \u3092\u8FD4\u3059\u95A2\
    \u6570\u3092\u5165\u308C\u308B (\u7B49\u53F7\u306F\u3069\u3061\u3089\u3067\u3082\
    \u3088\u3044)\nvector<int> monotone_minima(int N, int M,\n                   \
    \         const function<bool(int, int, int)>& f) {\n  vector<int> res(N);\n \
    \ auto dfs = [&](auto rc, int is, int ie, int l, int r) -> void {\n    if (is\
    \ == ie) return;\n    int i = (is + ie) / 2;\n    int m = l;\n    for (int k =\
    \ l + 1; k < r; k++) {\n      if (!f(i, m, k)) m = k;\n    }\n    res[i] = m;\n\
    \    rc(rc, is, i, l, m + 1);\n    rc(rc, i + 1, ie, m, r);\n  };\n  dfs(dfs,\
    \ 0, N, 0, M);\n  return res;\n}\n\n// NxM \u884C\u5217\u304C\u3042\u308B\n//\
    \ m_i := argmin_j (A_{i,j}) \u304C\u5358\u8ABF\u5897\u52A0\u3067\u3042\u308B\u3068\
    \u304D\u306B m_i \u3092\u5217\u6319\u3059\u308B\n// A(i, j) : A[i][j] \u3092\u8FD4\
    \u3059\u95A2\u6570\ntemplate <typename T>\nvector<int> monotone_minima(int N,\
    \ int M, const function<T(int, int)>& A) {\n  function<bool(int, int, int)> f\
    \ = [&](int i, int j, int k) -> bool {\n    return A(i, j) <= A(i, k);\n  };\n\
    \  return monotone_minima(N, M, f);\n}\n\n/**\n * @brief monotone minima\n */\n"
  code: "#pragma once\n\n#include <functional>\n#include <vector>\nusing namespace\
    \ std;\n\n// NxN \u884C\u5217\u304C\u3042\u308B\n// m_i := argmin_j (A_{i,j})\
    \ \u304C\u5358\u8ABF\u5897\u52A0\u3067\u3042\u308B\u3068\u304D\u306B m_i \u3092\
    \u5217\u6319\u3059\u308B\n// f(i, j, k) :\n// A[i][j] \u3068 A[i][k] \u3092\u6BD4\
    \u8F03 (j < k \u304C\u4FDD\u8A3C\u3055\u308C\u3066\u3044\u308B)\n// A[i][j] <=\
    \ A[i][k] \u306E\u3068\u304D true \u3092\u8FD4\u3059\u95A2\u6570\u3092\u5165\u308C\
    \u308B (\u7B49\u53F7\u306F\u3069\u3061\u3089\u3067\u3082\u3088\u3044)\nvector<int>\
    \ monotone_minima(int N, int M,\n                            const function<bool(int,\
    \ int, int)>& f) {\n  vector<int> res(N);\n  auto dfs = [&](auto rc, int is, int\
    \ ie, int l, int r) -> void {\n    if (is == ie) return;\n    int i = (is + ie)\
    \ / 2;\n    int m = l;\n    for (int k = l + 1; k < r; k++) {\n      if (!f(i,\
    \ m, k)) m = k;\n    }\n    res[i] = m;\n    rc(rc, is, i, l, m + 1);\n    rc(rc,\
    \ i + 1, ie, m, r);\n  };\n  dfs(dfs, 0, N, 0, M);\n  return res;\n}\n\n// NxM\
    \ \u884C\u5217\u304C\u3042\u308B\n// m_i := argmin_j (A_{i,j}) \u304C\u5358\u8ABF\
    \u5897\u52A0\u3067\u3042\u308B\u3068\u304D\u306B m_i \u3092\u5217\u6319\u3059\u308B\
    \n// A(i, j) : A[i][j] \u3092\u8FD4\u3059\u95A2\u6570\ntemplate <typename T>\n\
    vector<int> monotone_minima(int N, int M, const function<T(int, int)>& A) {\n\
    \  function<bool(int, int, int)> f = [&](int i, int j, int k) -> bool {\n    return\
    \ A(i, j) <= A(i, k);\n  };\n  return monotone_minima(N, M, f);\n}\n\n/**\n *\
    \ @brief monotone minima\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/monotone-minima.hpp
  requiredBy:
  - dp/monge-d-edge-shortest-path-enumerate.hpp
  - dp/concave-min-plus-convolution.hpp
  timestamp: '2023-09-02 22:21:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-0952.test.cpp
  - verify/verify-yosupo-math/yosupo-concave-min-plus-convolution-2.test.cpp
  - verify/verify-yosupo-math/yosupo-concave-min-plus-convolution-1.test.cpp
documentation_of: dp/monotone-minima.hpp
layout: document
redirect_from:
- /library/dp/monotone-minima.hpp
- /library/dp/monotone-minima.hpp.html
title: monotone minima
---
