---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/walsh-hadamard-transform.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename T>\nvoid walsh_hadamard_transform(vector<T>&\
    \ f, bool inverse = false) {\n  int n = f.size();\n  for (int i = 1; i < n; i\
    \ <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0) {\n   \
    \     T x = f[j], y = f[j | i];\n        f[j] = x + y, f[j | i] = x - y;\n   \
    \   }\n    }\n  }\n  if (inverse) {\n    T invn = T(1) / T(f.size());\n    for\
    \ (auto& x : f) x *= invn;\n  }\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename T>\nvoid walsh_hadamard_transform(vector<T>& f, bool inverse = false)\
    \ {\n  int n = f.size();\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j\
    \ = 0; j < n; j++) {\n      if ((j & i) == 0) {\n        T x = f[j], y = f[j |\
    \ i];\n        f[j] = x + y, f[j | i] = x - y;\n      }\n    }\n  }\n  if (inverse)\
    \ {\n    T invn = T(1) / T(f.size());\n    for (auto& x : f) x *= invn;\n  }\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: math/walsh-hadamard-transform.hpp
  requiredBy: []
  timestamp: '2020-10-01 11:55:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/walsh-hadamard-transform.hpp
layout: document
redirect_from:
- /library/math/walsh-hadamard-transform.hpp
- /library/math/walsh-hadamard-transform.hpp.html
title: math/walsh-hadamard-transform.hpp
---
