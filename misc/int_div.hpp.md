---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/int_div.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nlong long floor(long long a,long long b) {\n  assert(b > 0);\n  return\
    \ (a / b) - (a < 0 && !!(a % b));\n}\n\nlong long ceil(long long a,long long b)\
    \ {\n  assert(b > 0);\n  return (a / b) + (a > 0 && !!(a % b));\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nlong long\
    \ floor(long long a,long long b) {\n  assert(b > 0);\n  return (a / b) - (a <\
    \ 0 && !!(a % b));\n}\n\nlong long ceil(long long a,long long b) {\n  assert(b\
    \ > 0);\n  return (a / b) + (a > 0 && !!(a % b));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/int_div.hpp
  requiredBy: []
  timestamp: '2020-11-30 18:57:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/int_div.hpp
layout: document
redirect_from:
- /library/misc/int_div.hpp
- /library/misc/int_div.hpp.html
title: misc/int_div.hpp
---
