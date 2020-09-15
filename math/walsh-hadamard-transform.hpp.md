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
  bundledCode: "#line 2 \"math/walsh-hadamard-transform.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename T>\nvoid walsh_hadamard_transform(vector<T>&\
    \ f, int inverse = false) {\n  int n = f.size();\n  for (int i = 1; i < n; i <<=\
    \ 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0) {\n       \
    \ T x = f[j], y = f[j | i];\n        f[j] = x + y, f[j | i] = x - y;\n       \
    \ if (inverse) f[j] /= 2, f[j | i] /= 2;\n      }\n    }\n  }\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename T>\nvoid walsh_hadamard_transform(vector<T>& f, int inverse = false)\
    \ {\n  int n = f.size();\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j\
    \ = 0; j < n; j++) {\n      if ((j & i) == 0) {\n        T x = f[j], y = f[j |\
    \ i];\n        f[j] = x + y, f[j | i] = x - y;\n        if (inverse) f[j] /= 2,\
    \ f[j | i] /= 2;\n      }\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/walsh-hadamard-transform.hpp
  requiredBy: []
  timestamp: '2020-08-03 00:31:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/walsh-hadamard-transform.hpp
layout: document
redirect_from:
- /library/math/walsh-hadamard-transform.hpp
- /library/math/walsh-hadamard-transform.hpp.html
title: math/walsh-hadamard-transform.hpp
---
