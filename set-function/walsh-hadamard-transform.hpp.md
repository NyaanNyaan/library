---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: set-function/xor-convolution.hpp
    title: AND Convoluion
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-unit-test/set-function.test.cpp
    title: verify/verify-unit-test/set-function.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Walsh Hadamard Transform
    links: []
  bundledCode: "#line 2 \"set-function/walsh-hadamard-transform.hpp\"\n\ntemplate\
    \ <typename T>\nvoid walsh_hadamard_transform(vector<T>& f, bool inverse = false)\
    \ {\n  int n = f.size();\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j\
    \ = 0; j < n; j++) {\n      if ((j & i) == 0) {\n        T x = f[j], y = f[j |\
    \ i];\n        f[j] = x + y, f[j | i] = x - y;\n      }\n    }\n  }\n  if (inverse)\
    \ {\n    if constexpr (is_integral<T>::value) {\n      for (auto& x : f) x /=\
    \ n;\n    } else {\n      T invn = T(1) / T(f.size());\n      for (auto& x : f)\
    \ x *= invn;\n    }\n  }\n}\n\n/**\n * @brief Walsh Hadamard Transform\n */\n"
  code: "#pragma once\n\ntemplate <typename T>\nvoid walsh_hadamard_transform(vector<T>&\
    \ f, bool inverse = false) {\n  int n = f.size();\n  for (int i = 1; i < n; i\
    \ <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0) {\n   \
    \     T x = f[j], y = f[j | i];\n        f[j] = x + y, f[j | i] = x - y;\n   \
    \   }\n    }\n  }\n  if (inverse) {\n    if constexpr (is_integral<T>::value)\
    \ {\n      for (auto& x : f) x /= n;\n    } else {\n      T invn = T(1) / T(f.size());\n\
    \      for (auto& x : f) x *= invn;\n    }\n  }\n}\n\n/**\n * @brief Walsh Hadamard\
    \ Transform\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: set-function/walsh-hadamard-transform.hpp
  requiredBy:
  - set-function/xor-convolution.hpp
  timestamp: '2020-12-07 13:36:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-unit-test/set-function.test.cpp
documentation_of: set-function/walsh-hadamard-transform.hpp
layout: document
redirect_from:
- /library/set-function/walsh-hadamard-transform.hpp
- /library/set-function/walsh-hadamard-transform.hpp.html
title: Walsh Hadamard Transform
---
