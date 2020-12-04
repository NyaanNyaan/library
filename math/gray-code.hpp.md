---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Gray code
    links: []
  bundledCode: "#line 2 \"math/gray-code.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nvector<int> gray_code(int n) {\n  vector<int> ret(1 << n);\n  for (int\
    \ i = 0; i < (int)ret.size(); i++) ret[i] = i ^ (i >> 1);\n  return ret;\n};\n\
    \n/**\n * @brief Gray code\n */ \n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nvector<int>\
    \ gray_code(int n) {\n  vector<int> ret(1 << n);\n  for (int i = 0; i < (int)ret.size();\
    \ i++) ret[i] = i ^ (i >> 1);\n  return ret;\n};\n\n/**\n * @brief Gray code\n\
    \ */ \n"
  dependsOn: []
  isVerificationFile: false
  path: math/gray-code.hpp
  requiredBy: []
  timestamp: '2020-12-04 23:12:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/gray-code.hpp
layout: document
redirect_from:
- /library/math/gray-code.hpp
- /library/math/gray-code.hpp.html
title: Gray code
---
