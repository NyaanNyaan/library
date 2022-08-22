---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/nimber-to-field.hpp
    title: "Nimber <-> \u591A\u9805\u5F0F\u74B0"
  - icon: ':question:'
    path: math/nimber.hpp
    title: Nim Product
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/garner.test.cpp
    title: verify/verify-unit-test/garner.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/karatsuba.test.cpp
    title: verify/verify-unit-test/karatsuba.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/nimber-to-field.test.cpp
    title: verify/verify-unit-test/nimber-to-field.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/nimber.test.cpp
    title: verify/verify-unit-test/nimber.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-nim-product.test.cpp
    title: verify/verify-yosupo-math/yosupo-nim-product.test.cpp
  - icon: ':x:'
    path: verify/verify-yuki/yuki-1775.test.cpp
    title: verify/verify-yuki/yuki-1775.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Garner's algorithm
    links: []
  bundledCode: "#line 2 \"math/garner.hpp\"\n\n// input  : a, M (0 < a < M)\n// output\
    \ : pair(g, x) s.t. g = gcd(a, M), xa = g (mod M), 0 <= x < b/g\ntemplate <typename\
    \ uint>\npair<uint, uint> gcd_inv(uint a, uint M) {\n  assert(M != 0 && 0 < a);\n\
    \  a %= M;\n  uint b = M, s = 1, t = 0;\n  while (true) {\n    if (a == 0) return\
    \ {b, t + M};\n    t -= b / a * s;\n    b %= a;\n    if (b == 0) return {a, s};\n\
    \    s -= a / b * t;\n    a %= b;\n  }\n}\n\n// \u5165\u529B : 0 <= rem[i] < mod[i],\
    \ 1 <= mod[i]\n// \u5B58\u5728\u3059\u308B\u3068\u304D   : return {rem, mod}\n\
    // \u5B58\u5728\u3057\u306A\u3044\u3068\u304D : return {0, 0}\ntemplate <typename\
    \ T, typename U>\npair<unsigned long long, unsigned long long> garner(const vector<T>&\
    \ rem,\n                                                    const vector<U>& mod)\
    \ {\n  assert(rem.size() == mod.size());\n  using u64 = unsigned long long;\n\
    \  u64 r0 = 0, m0 = 1;\n  for (int i = 0; i < (int)rem.size(); i++) {\n    assert(1\
    \ <= mod[i]);\n    assert(0 <= rem[i] && rem[i] < mod[i]);\n    u64 m1 = mod[i],\
    \ r1 = rem[i] % m1;\n    if (m0 < m1) swap(r0, r1), swap(m0, m1);\n    if (m0\
    \ % m1 == 0) {\n      if (r0 % m1 != r1) return {0, 0};\n      continue;\n   \
    \ }\n    u64 g, im;\n    tie(g, im) = gcd_inv(m0, m1);\n    u64 y = r0 < r1 ?\
    \ r1 - r0 : r0 - r1;\n    if (y % g != 0) return {0, 0};\n    u64 u1 = m1 / g;\n\
    \    y = y / g % u1;\n    if (r0 > r1 && y != 0) y = u1 - y;\n    u64 x = y *\
    \ im % u1;\n    r0 += x * m0;\n    m0 *= u1;\n  }\n  return {r0, m0};\n}\n\n/**\n\
    \ * @brief Garner's algorithm\n */\n"
  code: "#pragma once\n\n// input  : a, M (0 < a < M)\n// output : pair(g, x) s.t.\
    \ g = gcd(a, M), xa = g (mod M), 0 <= x < b/g\ntemplate <typename uint>\npair<uint,\
    \ uint> gcd_inv(uint a, uint M) {\n  assert(M != 0 && 0 < a);\n  a %= M;\n  uint\
    \ b = M, s = 1, t = 0;\n  while (true) {\n    if (a == 0) return {b, t + M};\n\
    \    t -= b / a * s;\n    b %= a;\n    if (b == 0) return {a, s};\n    s -= a\
    \ / b * t;\n    a %= b;\n  }\n}\n\n// \u5165\u529B : 0 <= rem[i] < mod[i], 1 <=\
    \ mod[i]\n// \u5B58\u5728\u3059\u308B\u3068\u304D   : return {rem, mod}\n// \u5B58\
    \u5728\u3057\u306A\u3044\u3068\u304D : return {0, 0}\ntemplate <typename T, typename\
    \ U>\npair<unsigned long long, unsigned long long> garner(const vector<T>& rem,\n\
    \                                                    const vector<U>& mod) {\n\
    \  assert(rem.size() == mod.size());\n  using u64 = unsigned long long;\n  u64\
    \ r0 = 0, m0 = 1;\n  for (int i = 0; i < (int)rem.size(); i++) {\n    assert(1\
    \ <= mod[i]);\n    assert(0 <= rem[i] && rem[i] < mod[i]);\n    u64 m1 = mod[i],\
    \ r1 = rem[i] % m1;\n    if (m0 < m1) swap(r0, r1), swap(m0, m1);\n    if (m0\
    \ % m1 == 0) {\n      if (r0 % m1 != r1) return {0, 0};\n      continue;\n   \
    \ }\n    u64 g, im;\n    tie(g, im) = gcd_inv(m0, m1);\n    u64 y = r0 < r1 ?\
    \ r1 - r0 : r0 - r1;\n    if (y % g != 0) return {0, 0};\n    u64 u1 = m1 / g;\n\
    \    y = y / g % u1;\n    if (r0 > r1 && y != 0) y = u1 - y;\n    u64 x = y *\
    \ im % u1;\n    r0 += x * m0;\n    m0 *= u1;\n  }\n  return {r0, m0};\n}\n\n/**\n\
    \ * @brief Garner's algorithm\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/garner.hpp
  requiredBy:
  - math/nimber-to-field.hpp
  - math/nimber.hpp
  timestamp: '2021-12-23 18:55:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/verify-unit-test/nimber.test.cpp
  - verify/verify-unit-test/garner.test.cpp
  - verify/verify-unit-test/karatsuba.test.cpp
  - verify/verify-unit-test/nimber-to-field.test.cpp
  - verify/verify-yuki/yuki-1775.test.cpp
  - verify/verify-yosupo-math/yosupo-nim-product.test.cpp
documentation_of: math/garner.hpp
layout: document
redirect_from:
- /library/math/garner.hpp
- /library/math/garner.hpp.html
title: Garner's algorithm
---
