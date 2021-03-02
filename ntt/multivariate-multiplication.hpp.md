---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-multiplicative-convolution.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-multiplicative-convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: ntt/multivariate-multiplication.md
    document_title: Multivariate Multiplication
    links: []
  bundledCode: "#line 2 \"ntt/multivariate-multiplication.hpp\"\n\ntemplate <typename\
    \ fps>\nfps multivariate_multiplication(const fps& f, const fps& g,\n        \
    \                        const vector<int>& base) {\n  int n = f.size(), s = base.size(),\
    \ W = 1;\n  if (s == 0) return fps{f[0] * g[0]};\n  while (W < 2 * n) W *= 2;\n\
    \n  vector<int> chi(n);\n  for (int i = 0; i < n; i++) {\n    int x = i;\n   \
    \ for (int j = 0; j < s - 1; j++) chi[i] += (x /= base[j]);\n    chi[i] %= s;\n\
    \  }\n\n  vector<fps> F(s, fps(W)), G(s, fps(W));\n  for (int i = 0; i < n; i++)\
    \ F[chi[i]][i] = f[i], G[chi[i]][i] = g[i];\n\n  for (auto& x : F) x.ntt();\n\
    \  for (auto& x : G) x.ntt();\n  fps a(s);\n  for (int k = 0; k < W; k++) {\n\
    \    fill(begin(a), end(a), typename fps::value_type());\n    for (int i = 0;\
    \ i < s; i++)\n      for (int j = 0; j < s; j++) {\n        a[i + j - (i + j >=\
    \ s ? s : 0)] += F[i][k] * G[j][k];\n      }\n    for (int i = 0; i < s; i++)\
    \ F[i][k] = a[i];\n  }\n  for (auto& x : F) x.intt();\n  fps h(n);\n  for (int\
    \ i = 0; i < n; i++) h[i] = F[chi[i]][i];\n  return h;\n}\n\n/**\n * @brief Multivariate\
    \ Multiplication\n * @docs ntt/multivariate-multiplication.md\n */\n"
  code: "#pragma once\n\ntemplate <typename fps>\nfps multivariate_multiplication(const\
    \ fps& f, const fps& g,\n                                const vector<int>& base)\
    \ {\n  int n = f.size(), s = base.size(), W = 1;\n  if (s == 0) return fps{f[0]\
    \ * g[0]};\n  while (W < 2 * n) W *= 2;\n\n  vector<int> chi(n);\n  for (int i\
    \ = 0; i < n; i++) {\n    int x = i;\n    for (int j = 0; j < s - 1; j++) chi[i]\
    \ += (x /= base[j]);\n    chi[i] %= s;\n  }\n\n  vector<fps> F(s, fps(W)), G(s,\
    \ fps(W));\n  for (int i = 0; i < n; i++) F[chi[i]][i] = f[i], G[chi[i]][i] =\
    \ g[i];\n\n  for (auto& x : F) x.ntt();\n  for (auto& x : G) x.ntt();\n  fps a(s);\n\
    \  for (int k = 0; k < W; k++) {\n    fill(begin(a), end(a), typename fps::value_type());\n\
    \    for (int i = 0; i < s; i++)\n      for (int j = 0; j < s; j++) {\n      \
    \  a[i + j - (i + j >= s ? s : 0)] += F[i][k] * G[j][k];\n      }\n    for (int\
    \ i = 0; i < s; i++) F[i][k] = a[i];\n  }\n  for (auto& x : F) x.intt();\n  fps\
    \ h(n);\n  for (int i = 0; i < n; i++) h[i] = F[chi[i]][i];\n  return h;\n}\n\n\
    /**\n * @brief Multivariate Multiplication\n * @docs ntt/multivariate-multiplication.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: ntt/multivariate-multiplication.hpp
  requiredBy: []
  timestamp: '2021-03-03 00:41:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ntt/yosupo-multiplicative-convolution.test.cpp
documentation_of: ntt/multivariate-multiplication.hpp
layout: document
redirect_from:
- /library/ntt/multivariate-multiplication.hpp
- /library/ntt/multivariate-multiplication.hpp.html
title: Multivariate Multiplication
---
