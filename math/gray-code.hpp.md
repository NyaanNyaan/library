---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/math.test.cpp
    title: verify/verify-unit-test/math.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Gray code
    links: []
  bundledCode: "#line 2 \"math/gray-code.hpp\"\n\n\n\nvector<int> gray_code(int n)\
    \ {\n  vector<int> ret(1 << n);\n  for (int i = 0; i < (int)ret.size(); i++) ret[i]\
    \ = i ^ (i >> 1);\n  return ret;\n};\n\n/**\n * @brief Gray code\n */ \n"
  code: "#pragma once\n\n\n\nvector<int> gray_code(int n) {\n  vector<int> ret(1 <<\
    \ n);\n  for (int i = 0; i < (int)ret.size(); i++) ret[i] = i ^ (i >> 1);\n  return\
    \ ret;\n};\n\n/**\n * @brief Gray code\n */ \n"
  dependsOn: []
  isVerificationFile: false
  path: math/gray-code.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/math.test.cpp
documentation_of: math/gray-code.hpp
layout: document
redirect_from:
- /library/math/gray-code.hpp
- /library/math/gray-code.hpp.html
title: Gray code
---
