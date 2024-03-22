---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2281.test.cpp
    title: verify/verify-yuki/yuki-2281.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2333.test.cpp
    title: verify/verify-yuki/yuki-2333.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segment-tree/segment-tree-max-of-interval.hpp\"\n\n#include\
    \ <algorithm>\nusing namespace std;\n\n// \u30BB\u30B0\u6728\u7528\u306E\u30E2\
    \u30CE\u30A4\u30C9 (\u533A\u9593\u66F4\u65B0\u7528\u306E\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\u3082\u3042\u308B)\n//\n// sum : \u5168\u4F53\u306E sum\n//\
    \ max, lmax, rmax : (\u9023\u7D9A\u90E8\u5206\u5217\u306E\u8981\u7D20\u306E\u548C\
    )\u306E max (\u7A7A\u306E\u533A\u9593\u3092\u8A8D\u3081\u306A\u3044)\n// min,\
    \ lmin, rmin : (\u9023\u7D9A\u90E8\u5206\u5217\u306E\u8981\u7D20\u306E\u548C)\u306E\
    \ min (\u7A7A\u306E\u533A\u9593\u3092\u8A8D\u3081\u306A\u3044)\n// num : \u533A\
    \u9593\u306E\u9577\u3055\ntemplate <typename T>\nstruct MaxInterval {\n  T sum,\
    \ max, lmax, rmax, min, lmin, rmin;\n  long long num;\n  MaxInterval()\n     \
    \ : sum(0), max(0), lmax(0), rmax(0), min(0), lmin(0), rmin(0), num(0) {}\n  //\
    \ [x] 1 \u500B\u304B\u3089\u306A\u308B\u533A\u9593\n  MaxInterval(T x)\n     \
    \ : sum(x), max(x), lmax(x), rmax(x), min(x), lmin(x), rmin(x), num(1) {}\n  //\
    \ [x] num \u500B\u304B\u3089\u306A\u308B\u533A\u9593\n  MaxInterval(T x, long\
    \ long _num) {\n    if (_num == 0) {\n      sum = max = lmax = rmax = min = lmin\
    \ = rmin = num = 0;\n    } else {\n      sum = x * _num;\n      max = lmax = rmax\
    \ = (x > 0 ? x * _num : x);\n      min = lmin = rmin = (x < 0 ? x * _num : x);\n\
    \      num = _num;\n    }\n  }\n  bool operator==(const MaxInterval& rhs) const\
    \ {\n    return sum == rhs.sum && max == rhs.max && lmax == rhs.lmax &&\n    \
    \       rmax == rhs.rmax && min == rhs.min && lmin == rhs.lmin &&\n          \
    \ rmin == rhs.rmin && num == rhs.num;\n  }\n  bool operator!=(const MaxInterval&\
    \ rhs) const { return !(*this == rhs); }\n\n  // \u533A\u9593\u306E\u30DE\u30FC\
    \u30B8\n  friend MaxInterval merge(const MaxInterval& a, const MaxInterval& b)\
    \ {\n    if (a == MaxInterval{}) return b;\n    if (b == MaxInterval{}) return\
    \ a;\n    MaxInterval c;\n    c.sum = a.sum + b.sum;\n    c.max = ::max({a.max,\
    \ b.max, a.rmax + b.lmax});\n    c.lmax = ::max(a.lmax, a.sum + b.lmax);\n   \
    \ c.rmax = ::max(b.rmax, b.sum + a.rmax);\n    c.min = ::min({a.min, b.min, a.rmin\
    \ + b.lmin});\n    c.lmin = ::min(a.lmin, a.sum + b.lmin);\n    c.rmin = ::min(b.rmin,\
    \ b.sum + a.rmin);\n    c.num = a.num + b.num;\n    return c;\n  }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\nusing namespace std;\n\n// \u30BB\u30B0\
    \u6728\u7528\u306E\u30E2\u30CE\u30A4\u30C9 (\u533A\u9593\u66F4\u65B0\u7528\u306E\
    \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3082\u3042\u308B)\n//\n// sum : \u5168\
    \u4F53\u306E sum\n// max, lmax, rmax : (\u9023\u7D9A\u90E8\u5206\u5217\u306E\u8981\
    \u7D20\u306E\u548C)\u306E max (\u7A7A\u306E\u533A\u9593\u3092\u8A8D\u3081\u306A\
    \u3044)\n// min, lmin, rmin : (\u9023\u7D9A\u90E8\u5206\u5217\u306E\u8981\u7D20\
    \u306E\u548C)\u306E min (\u7A7A\u306E\u533A\u9593\u3092\u8A8D\u3081\u306A\u3044\
    )\n// num : \u533A\u9593\u306E\u9577\u3055\ntemplate <typename T>\nstruct MaxInterval\
    \ {\n  T sum, max, lmax, rmax, min, lmin, rmin;\n  long long num;\n  MaxInterval()\n\
    \      : sum(0), max(0), lmax(0), rmax(0), min(0), lmin(0), rmin(0), num(0) {}\n\
    \  // [x] 1 \u500B\u304B\u3089\u306A\u308B\u533A\u9593\n  MaxInterval(T x)\n \
    \     : sum(x), max(x), lmax(x), rmax(x), min(x), lmin(x), rmin(x), num(1) {}\n\
    \  // [x] num \u500B\u304B\u3089\u306A\u308B\u533A\u9593\n  MaxInterval(T x, long\
    \ long _num) {\n    if (_num == 0) {\n      sum = max = lmax = rmax = min = lmin\
    \ = rmin = num = 0;\n    } else {\n      sum = x * _num;\n      max = lmax = rmax\
    \ = (x > 0 ? x * _num : x);\n      min = lmin = rmin = (x < 0 ? x * _num : x);\n\
    \      num = _num;\n    }\n  }\n  bool operator==(const MaxInterval& rhs) const\
    \ {\n    return sum == rhs.sum && max == rhs.max && lmax == rhs.lmax &&\n    \
    \       rmax == rhs.rmax && min == rhs.min && lmin == rhs.lmin &&\n          \
    \ rmin == rhs.rmin && num == rhs.num;\n  }\n  bool operator!=(const MaxInterval&\
    \ rhs) const { return !(*this == rhs); }\n\n  // \u533A\u9593\u306E\u30DE\u30FC\
    \u30B8\n  friend MaxInterval merge(const MaxInterval& a, const MaxInterval& b)\
    \ {\n    if (a == MaxInterval{}) return b;\n    if (b == MaxInterval{}) return\
    \ a;\n    MaxInterval c;\n    c.sum = a.sum + b.sum;\n    c.max = ::max({a.max,\
    \ b.max, a.rmax + b.lmax});\n    c.lmax = ::max(a.lmax, a.sum + b.lmax);\n   \
    \ c.rmax = ::max(b.rmax, b.sum + a.rmax);\n    c.min = ::min({a.min, b.min, a.rmin\
    \ + b.lmin});\n    c.lmin = ::min(a.lmin, a.sum + b.lmin);\n    c.rmin = ::min(b.rmin,\
    \ b.sum + a.rmin);\n    c.num = a.num + b.num;\n    return c;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/segment-tree-max-of-interval.hpp
  requiredBy: []
  timestamp: '2023-05-29 20:16:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-2333.test.cpp
  - verify/verify-yuki/yuki-2281.test.cpp
documentation_of: segment-tree/segment-tree-max-of-interval.hpp
layout: document
redirect_from:
- /library/segment-tree/segment-tree-max-of-interval.hpp
- /library/segment-tree/segment-tree-max-of-interval.hpp.html
title: segment-tree/segment-tree-max-of-interval.hpp
---
