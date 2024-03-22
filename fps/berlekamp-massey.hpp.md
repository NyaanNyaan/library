---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/nth-term.hpp
    title: "\u7DDA\u5F62\u56DE\u5E30\u6570\u5217\u306E\u9AD8\u901F\u8A08\u7B97(Berlekamp-Massey/Bostan-Mori)"
  - icon: ':heavy_check_mark:'
    path: matrix/black-box-linear-algebra.hpp
    title: Black Box Linear Algebra
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp
    title: verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-determinant-of-matrix-bbla.test.cpp
    title: verify/verify-yosupo-math/yosupo-determinant-of-matrix-bbla.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-determinant-of-sparse-matrix-bbla.test.cpp
    title: verify/verify-yosupo-math/yosupo-determinant-of-sparse-matrix-bbla.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0215-nth-term.test.cpp
    title: verify/verify-yuki/yuki-0215-nth-term.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1112-sparse.test.cpp
    title: verify/verify-yuki/yuki-1112-sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1112.test.cpp
    title: verify/verify-yuki/yuki-1112.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/berlekamp-massey.hpp\"\n\ntemplate <typename mint>\n\
    vector<mint> BerlekampMassey(const vector<mint> &s) {\n  const int N = (int)s.size();\n\
    \  vector<mint> b, c;\n  b.reserve(N + 1);\n  c.reserve(N + 1);\n  b.push_back(mint(1));\n\
    \  c.push_back(mint(1));\n  mint y = mint(1);\n  for (int ed = 1; ed <= N; ed++)\
    \ {\n    int l = int(c.size()), m = int(b.size());\n    mint x = 0;\n    for (int\
    \ i = 0; i < l; i++) x += c[i] * s[ed - l + i];\n    b.emplace_back(mint(0));\n\
    \    m++;\n    if (x == mint(0)) continue;\n    mint freq = x / y;\n    if (l\
    \ < m) {\n      auto tmp = c;\n      c.insert(begin(c), m - l, mint(0));\n   \
    \   for (int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];\n      b\
    \ = tmp;\n      y = x;\n    } else {\n      for (int i = 0; i < m; i++) c[l -\
    \ 1 - i] -= freq * b[m - 1 - i];\n    }\n  }\n  reverse(begin(c), end(c));\n \
    \ return c;\n}\n"
  code: "#pragma once\n\ntemplate <typename mint>\nvector<mint> BerlekampMassey(const\
    \ vector<mint> &s) {\n  const int N = (int)s.size();\n  vector<mint> b, c;\n \
    \ b.reserve(N + 1);\n  c.reserve(N + 1);\n  b.push_back(mint(1));\n  c.push_back(mint(1));\n\
    \  mint y = mint(1);\n  for (int ed = 1; ed <= N; ed++) {\n    int l = int(c.size()),\
    \ m = int(b.size());\n    mint x = 0;\n    for (int i = 0; i < l; i++) x += c[i]\
    \ * s[ed - l + i];\n    b.emplace_back(mint(0));\n    m++;\n    if (x == mint(0))\
    \ continue;\n    mint freq = x / y;\n    if (l < m) {\n      auto tmp = c;\n \
    \     c.insert(begin(c), m - l, mint(0));\n      for (int i = 0; i < m; i++) c[m\
    \ - 1 - i] -= freq * b[m - 1 - i];\n      b = tmp;\n      y = x;\n    } else {\n\
    \      for (int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];\n    }\n\
    \  }\n  reverse(begin(c), end(c));\n  return c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/berlekamp-massey.hpp
  requiredBy:
  - fps/nth-term.hpp
  - matrix/black-box-linear-algebra.hpp
  timestamp: '2020-12-05 08:16:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-determinant-of-sparse-matrix-bbla.test.cpp
  - verify/verify-yosupo-math/yosupo-determinant-of-matrix-bbla.test.cpp
  - verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp
  - verify/verify-yuki/yuki-1112-sparse.test.cpp
  - verify/verify-yuki/yuki-1112.test.cpp
  - verify/verify-yuki/yuki-0215-nth-term.test.cpp
documentation_of: fps/berlekamp-massey.hpp
layout: document
redirect_from:
- /library/fps/berlekamp-massey.hpp
- /library/fps/berlekamp-massey.hpp.html
title: fps/berlekamp-massey.hpp
---
