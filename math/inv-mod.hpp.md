---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/math.test.cpp
    title: verify/verify-unit-test/math.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/inv-mod.hpp\"\n\n#include <cassert>\n#include <type_traits>\n\
    using namespace std;\n\n// gcd(a, m) != 1 \u306E\u3068\u304D 0 \u9664\u7B97\u3067\
    \ RE \u3059\u308B\ntemplate <typename T>\nT inv_mod(T a, T m) {\n  if (m == 1)\
    \ return 0;\n  if (a >= m) a %= m;\n  if (a < 0) a += m;\n  T b = m, s = 1, t\
    \ = 0;\n  while (true) {\n    if (a == 1) return s;\n    t -= b / a * s;\n   \
    \ b %= a;\n    if (b == 1) return t + m;\n    s -= a / b * t;\n    a %= b;\n \
    \ }\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include <type_traits>\nusing namespace\
    \ std;\n\n// gcd(a, m) != 1 \u306E\u3068\u304D 0 \u9664\u7B97\u3067 RE \u3059\u308B\
    \ntemplate <typename T>\nT inv_mod(T a, T m) {\n  if (m == 1) return 0;\n  if\
    \ (a >= m) a %= m;\n  if (a < 0) a += m;\n  T b = m, s = 1, t = 0;\n  while (true)\
    \ {\n    if (a == 1) return s;\n    t -= b / a * s;\n    b %= a;\n    if (b ==\
    \ 1) return t + m;\n    s -= a / b * t;\n    a %= b;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/inv-mod.hpp
  requiredBy: []
  timestamp: '2023-04-11 20:58:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/math.test.cpp
documentation_of: math/inv-mod.hpp
layout: document
redirect_from:
- /library/math/inv-mod.hpp
- /library/math/inv-mod.hpp.html
title: math/inv-mod.hpp
---
