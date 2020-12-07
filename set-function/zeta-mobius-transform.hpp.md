---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: set-function/and-convolution.hpp
    title: AND Convoluion
  - icon: ':x:'
    path: set-function/or-convolution.hpp
    title: OR Convoluion
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-unit-test/set-function.test.cpp
    title: verify/verify-unit-test/set-function.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Zeta Transform / Moebius Transform
    links: []
  bundledCode: "#line 2 \"set-function/zeta-mobius-transform.hpp\"\n\ntemplate <typename\
    \ T>\nvoid superset_zeta_transform(vector<T>& f) {\n  int n = f.size();\n  assert((n\
    \ & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0;\
    \ j < n; j++) {\n      if ((j & i) == 0) {\n        f[j] += f[j | i];\n      }\n\
    \    }\n  }\n}\n\ntemplate <typename T>\nvoid superset_mobius_transform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j] -= f[j | i];\n      }\n    }\n  }\n}\n\ntemplate <typename T>\n\
    void subset_zeta_transform(vector<T>& f) {\n  int n = f.size();\n  assert((n &\
    \ (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0; j\
    \ < n; j++) {\n      if ((j & i) == 0) {\n        f[j | i] += f[j];\n      }\n\
    \    }\n  }\n}\n\ntemplate <typename T>\nvoid subset_mobius_transform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j | i] -= f[j];\n      }\n    }\n  }\n}\n\n/**\n * @brief Zeta\
    \ Transform / Moebius Transform\n */\n"
  code: "#pragma once\n\ntemplate <typename T>\nvoid superset_zeta_transform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j] += f[j | i];\n      }\n    }\n  }\n}\n\ntemplate <typename T>\n\
    void superset_mobius_transform(vector<T>& f) {\n  int n = f.size();\n  assert((n\
    \ & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0;\
    \ j < n; j++) {\n      if ((j & i) == 0) {\n        f[j] -= f[j | i];\n      }\n\
    \    }\n  }\n}\n\ntemplate <typename T>\nvoid subset_zeta_transform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j | i] += f[j];\n      }\n    }\n  }\n}\n\ntemplate <typename T>\n\
    void subset_mobius_transform(vector<T>& f) {\n  int n = f.size();\n  assert((n\
    \ & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0;\
    \ j < n; j++) {\n      if ((j & i) == 0) {\n        f[j | i] -= f[j];\n      }\n\
    \    }\n  }\n}\n\n/**\n * @brief Zeta Transform / Moebius Transform\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: set-function/zeta-mobius-transform.hpp
  requiredBy:
  - set-function/and-convolution.hpp
  - set-function/or-convolution.hpp
  timestamp: '2020-12-07 13:36:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-unit-test/set-function.test.cpp
documentation_of: set-function/zeta-mobius-transform.hpp
layout: document
redirect_from:
- /library/set-function/zeta-mobius-transform.hpp
- /library/set-function/zeta-mobius-transform.hpp.html
title: Zeta Transform / Moebius Transform
---
