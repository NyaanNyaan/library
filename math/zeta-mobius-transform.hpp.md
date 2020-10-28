---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/zeta-mobius-transform.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename T>\nvoid superset_zeta_transform(vector<T>&\
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
    \    }\n  }\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename T>\nvoid superset_zeta_transform(vector<T>& f) {\n  int n = f.size();\n\
    \  assert((n & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int\
    \ j = 0; j < n; j++) {\n      if ((j & i) == 0) {\n        f[j] += f[j | i];\n\
    \      }\n    }\n  }\n}\n\ntemplate <typename T>\nvoid superset_mobius_transform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j] -= f[j | i];\n      }\n    }\n  }\n}\n\ntemplate <typename T>\n\
    void subset_zeta_transform(vector<T>& f) {\n  int n = f.size();\n  assert((n &\
    \ (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0; j\
    \ < n; j++) {\n      if ((j & i) == 0) {\n        f[j | i] += f[j];\n      }\n\
    \    }\n  }\n}\n\ntemplate <typename T>\nvoid subset_mobius_transform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j | i] -= f[j];\n      }\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/zeta-mobius-transform.hpp
  requiredBy: []
  timestamp: '2020-10-28 22:59:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/zeta-mobius-transform.hpp
layout: document
redirect_from:
- /library/math/zeta-mobius-transform.hpp
- /library/math/zeta-mobius-transform.hpp.html
title: math/zeta-mobius-transform.hpp
---
