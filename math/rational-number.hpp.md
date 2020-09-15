---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"math/rational-number.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nstruct RationalNumber {\n  pair<long long, long long> a;\n\
    \n  RationalNumber(pair<long long, long long> p) { a = init(p.first, p.second);\
    \ }\n  RationalNumber(long long x, long long y) { a = init(x, y); }\n\n  pair<long\
    \ long, long long> init(long long x, long long y) {\n    if (x == 0 && y == 0)\
    \ return pair<long long, long long>(0, 0);\n    long long g = this->gcd(abs(x),\
    \ abs(y));\n    x /= g;\n    y /= g;\n    if (x < 0) x = -x, y = -y;\n    if (x\
    \ == 0 && y < 0) y = -y;\n    return pair<long long, long long>(x, y);\n  }\n\n\
    \  long long gcd(long long x, long long y) {\n    long long z;\n    if (x > y)\
    \ swap(x, y);\n    while (x) {\n      x = y % (z = x);\n      y = z;\n    }\n\
    \    return y;\n  }\n  bool zero() const { return a.first == 0 && a.second ==\
    \ 0; }\n  RationalNumber orth() const { return RationalNumber{-a.second, a.first};\
    \ }\n};\nnamespace std {\nbool operator<(const RationalNumber &x, const RationalNumber\
    \ &y) {\n  return x.a < y.a;\n}\nbool operator==(const RationalNumber &x, const\
    \ RationalNumber &y) {\n  return x.a == y.a;\n}\nbool operator!=(const RationalNumber\
    \ &x, const RationalNumber &y) {\n  return x.a != y.a;\n}\n}  // namespace std\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct RationalNumber\
    \ {\n  pair<long long, long long> a;\n\n  RationalNumber(pair<long long, long\
    \ long> p) { a = init(p.first, p.second); }\n  RationalNumber(long long x, long\
    \ long y) { a = init(x, y); }\n\n  pair<long long, long long> init(long long x,\
    \ long long y) {\n    if (x == 0 && y == 0) return pair<long long, long long>(0,\
    \ 0);\n    long long g = this->gcd(abs(x), abs(y));\n    x /= g;\n    y /= g;\n\
    \    if (x < 0) x = -x, y = -y;\n    if (x == 0 && y < 0) y = -y;\n    return\
    \ pair<long long, long long>(x, y);\n  }\n\n  long long gcd(long long x, long\
    \ long y) {\n    long long z;\n    if (x > y) swap(x, y);\n    while (x) {\n \
    \     x = y % (z = x);\n      y = z;\n    }\n    return y;\n  }\n  bool zero()\
    \ const { return a.first == 0 && a.second == 0; }\n  RationalNumber orth() const\
    \ { return RationalNumber{-a.second, a.first}; }\n};\nnamespace std {\nbool operator<(const\
    \ RationalNumber &x, const RationalNumber &y) {\n  return x.a < y.a;\n}\nbool\
    \ operator==(const RationalNumber &x, const RationalNumber &y) {\n  return x.a\
    \ == y.a;\n}\nbool operator!=(const RationalNumber &x, const RationalNumber &y)\
    \ {\n  return x.a != y.a;\n}\n}  // namespace std"
  dependsOn: []
  isVerificationFile: false
  path: math/rational-number.hpp
  requiredBy: []
  timestamp: '2020-07-28 11:29:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/rational-number.hpp
layout: document
redirect_from:
- /library/math/rational-number.hpp
- /library/math/rational-number.hpp.html
title: math/rational-number.hpp
---
