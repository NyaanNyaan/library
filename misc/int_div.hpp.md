---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/int-div.test.cpp
    title: verify/verify-unit-test/int-div.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/int_div.hpp\"\n\n// a/b \u4EE5\u4E0B\u306E\u6700\u5927\
    \u306E\u6574\u6570\nlong long floor(long long a, long long b) {\n  assert(b !=\
    \ 0);\n  if (b < 0) a = -a, b = -b;\n  return a / b - (a % b < 0);\n}\n// a/b\
    \ \u672A\u6E80\u306E\u6700\u5927\u306E\u6574\u6570\nlong long under(long long\
    \ a, long long b) {\n  assert(b != 0);\n  if (b < 0) a = -a, b = -b;\n  return\
    \ a / b - (a % b <= 0);\n}\n// a/b \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u6574\u6570\
    \nlong long ceil(long long a, long long b) {\n  assert(b != 0);\n  if (b < 0)\
    \ a = -a, b = -b;\n  return a / b + (a % b > 0);\n}\n// a/b \u8D85\u904E\u306E\
    \u6700\u5C0F\u306E\u6574\u6570\nlong long over(long long a, long long b) {\n \
    \ assert(b != 0);\n  if (b < 0) a = -a, b = -b;\n  return a / b + (a % b >= 0);\n\
    }\n"
  code: "#pragma once\n\n// a/b \u4EE5\u4E0B\u306E\u6700\u5927\u306E\u6574\u6570\n\
    long long floor(long long a, long long b) {\n  assert(b != 0);\n  if (b < 0) a\
    \ = -a, b = -b;\n  return a / b - (a % b < 0);\n}\n// a/b \u672A\u6E80\u306E\u6700\
    \u5927\u306E\u6574\u6570\nlong long under(long long a, long long b) {\n  assert(b\
    \ != 0);\n  if (b < 0) a = -a, b = -b;\n  return a / b - (a % b <= 0);\n}\n//\
    \ a/b \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u6574\u6570\nlong long ceil(long long\
    \ a, long long b) {\n  assert(b != 0);\n  if (b < 0) a = -a, b = -b;\n  return\
    \ a / b + (a % b > 0);\n}\n// a/b \u8D85\u904E\u306E\u6700\u5C0F\u306E\u6574\u6570\
    \nlong long over(long long a, long long b) {\n  assert(b != 0);\n  if (b < 0)\
    \ a = -a, b = -b;\n  return a / b + (a % b >= 0);\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/int_div.hpp
  requiredBy: []
  timestamp: '2021-08-10 23:14:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/int-div.test.cpp
documentation_of: misc/int_div.hpp
layout: document
redirect_from:
- /library/misc/int_div.hpp
- /library/misc/int_div.hpp.html
title: misc/int_div.hpp
---
