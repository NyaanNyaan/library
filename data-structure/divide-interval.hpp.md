---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-3506.test.cpp
    title: verify/verify-aoj-other/aoj-3506.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1170-divide-interval.test.cpp
    title: verify/verify-yuki/yuki-1170-divide-interval.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/divide-interval.hpp\"\n\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n\n// \u30BB\u30B0\u6728\u72B6\u306B\u533A\
    \u9593\u3092\u5206\u5272\u3057\u305F\u3068\u304D\u306E\u51E6\u7406\n//\n// 2*B\
    \ \u500B\u306E\u9802\u70B9\u3092\u6301\u3064\u30B0\u30E9\u30D5\u3092\u8003\u3048\
    \u308B\n// B+i \u304C\u5143\u306E\u30B0\u30E9\u30D5\u306E\u9802\u70B9 i \u306B\
    \u5BFE\u5FDC\u3059\u308B\nstruct DivideInterval {\n  int N, B;\n  DivideInterval(int\
    \ n) : N(n), B(1) {\n    while (B < N) B *= 2;\n  }\n  // \u521D\u671F\u5316\n\
    \n  // O(N) \u6839\u304B\u3089\u8449\u65B9\u5411\u3078 push \u3059\u308B\n  //\
    \ f(p, c) : p -> c \u3078\u4F1D\u64AD\n  template <typename F>\n  void push(const\
    \ F& f) {\n    for (int p = 1; p < B; p++) {\n      f(p, p * 2 + 0);\n      f(p,\
    \ p * 2 + 1);\n    }\n  }\n  // O(N) \u8449\u304B\u3089\u6839\u306E\u65B9\u5411\
    \u306B update \u3059\u308B\n  // f(p, c1, c2) : c1 \u3068 c2 \u306E\u7D50\u679C\
    \u3092 p \u3078\u30DE\u30FC\u30B8\n  template <typename F>\n  void update(const\
    \ F& f) {\n    for (int p = B - 1; p > 0; p--) {\n      f(p, p * 2 + 0, p * 2\
    \ + 1);\n    }\n  }\n\n  // [l, r) \u306B\u5BFE\u5FDC\u3059\u308B index \u306E\
    \u5217\u3092\u8FD4\u3059\n  // \u9806\u756A\u306F\u5DE6\u304B\u3089\u53F3\u3078\
    \u4E26\u3093\u3067\u3044\u308B\n  // \u4F8B: [1, 11) : [1, 2), [2, 4), [4, 8),\
    \ [8, 10), [10, 11)\n  vector<int> range(int l, int r) {\n    assert(0 <= l and\
    \ l <= r and r <= N);\n    vector<int> L, R;\n    for (l += B, r += B; l < r;\
    \ l >>= 1, r >>= 1) {\n      if (l & 1) L.push_back(l), l++;\n      if (r & 1)\
    \ r--, R.push_back(r);\n    }\n    for (int i = (int)R.size() - 1; i >= 0; i--)\
    \ L.push_back(R[i]);\n    return L;\n  }\n  // [l, r) \u306B\u5BFE\u5FDC\u3059\
    \u308B index \u306B\u5BFE\u3057\u3066\u30AF\u30A8\u30EA\u3092\u6295\u3052\u308B\
    (\u533A\u9593\u306F\u6607\u9806)\n  // f(i) : \u533A\u9593 i \u306B\u30AF\u30A8\
    \u30EA\u3092\u6295\u3052\u308B\n  template <typename F>\n  void apply(int l, int\
    \ r, const F& f) {\n    assert(0 <= l and l <= r and r <= N);\n    for (int i\
    \ : range(l, r)) f(i);\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \n// \u30BB\u30B0\u6728\u72B6\u306B\u533A\u9593\u3092\u5206\u5272\u3057\u305F\u3068\
    \u304D\u306E\u51E6\u7406\n//\n// 2*B \u500B\u306E\u9802\u70B9\u3092\u6301\u3064\
    \u30B0\u30E9\u30D5\u3092\u8003\u3048\u308B\n// B+i \u304C\u5143\u306E\u30B0\u30E9\
    \u30D5\u306E\u9802\u70B9 i \u306B\u5BFE\u5FDC\u3059\u308B\nstruct DivideInterval\
    \ {\n  int N, B;\n  DivideInterval(int n) : N(n), B(1) {\n    while (B < N) B\
    \ *= 2;\n  }\n  // \u521D\u671F\u5316\n\n  // O(N) \u6839\u304B\u3089\u8449\u65B9\
    \u5411\u3078 push \u3059\u308B\n  // f(p, c) : p -> c \u3078\u4F1D\u64AD\n  template\
    \ <typename F>\n  void push(const F& f) {\n    for (int p = 1; p < B; p++) {\n\
    \      f(p, p * 2 + 0);\n      f(p, p * 2 + 1);\n    }\n  }\n  // O(N) \u8449\u304B\
    \u3089\u6839\u306E\u65B9\u5411\u306B update \u3059\u308B\n  // f(p, c1, c2) :\
    \ c1 \u3068 c2 \u306E\u7D50\u679C\u3092 p \u3078\u30DE\u30FC\u30B8\n  template\
    \ <typename F>\n  void update(const F& f) {\n    for (int p = B - 1; p > 0; p--)\
    \ {\n      f(p, p * 2 + 0, p * 2 + 1);\n    }\n  }\n\n  // [l, r) \u306B\u5BFE\
    \u5FDC\u3059\u308B index \u306E\u5217\u3092\u8FD4\u3059\n  // \u9806\u756A\u306F\
    \u5DE6\u304B\u3089\u53F3\u3078\u4E26\u3093\u3067\u3044\u308B\n  // \u4F8B: [1,\
    \ 11) : [1, 2), [2, 4), [4, 8), [8, 10), [10, 11)\n  vector<int> range(int l,\
    \ int r) {\n    assert(0 <= l and l <= r and r <= N);\n    vector<int> L, R;\n\
    \    for (l += B, r += B; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) L.push_back(l),\
    \ l++;\n      if (r & 1) r--, R.push_back(r);\n    }\n    for (int i = (int)R.size()\
    \ - 1; i >= 0; i--) L.push_back(R[i]);\n    return L;\n  }\n  // [l, r) \u306B\
    \u5BFE\u5FDC\u3059\u308B index \u306B\u5BFE\u3057\u3066\u30AF\u30A8\u30EA\u3092\
    \u6295\u3052\u308B(\u533A\u9593\u306F\u6607\u9806)\n  // f(i) : \u533A\u9593 i\
    \ \u306B\u30AF\u30A8\u30EA\u3092\u6295\u3052\u308B\n  template <typename F>\n\
    \  void apply(int l, int r, const F& f) {\n    assert(0 <= l and l <= r and r\
    \ <= N);\n    for (int i : range(l, r)) f(i);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/divide-interval.hpp
  requiredBy: []
  timestamp: '2023-05-26 23:34:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1170-divide-interval.test.cpp
  - verify/verify-aoj-other/aoj-3506.test.cpp
documentation_of: data-structure/divide-interval.hpp
layout: document
redirect_from:
- /library/data-structure/divide-interval.hpp
- /library/data-structure/divide-interval.hpp.html
title: data-structure/divide-interval.hpp
---
