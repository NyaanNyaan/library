---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"matrix/linear-equation-hashmap.hpp\"\n\n\nvector<mint> LinearEquation_hashmap(vector<HashMap<int,\
    \ mint>> A,\n                                    vector<mint> b, int upper = -1)\
    \ {\n  int H = A.size(), W = b.size();\n  if (upper = -1) upper = W;\n  vector<int>\
    \ pivots(W, -1);\n  int rank = 0, je = W;\n  for (int j = 0; j < je; j++) {\n\
    \    int idx = -1;\n    for (int i = rank; i < H; i++) {\n      auto it = A[i].find(j);\n\
    \      if (it != end(A[i]) and it->second != mint{}) {\n        idx = i;\n   \
    \     break;\n      }\n    }\n    if (idx == -1) continue;\n    if (rank != idx)\
    \ {\n      swap(A[rank], A[idx]);\n      swap(b[rank], b[idx]);\n    }\n    pivots[j]\
    \ = rank;\n    vector<pair<int, mint>> arank;\n    {\n      mint coeff = A[rank][j].inverse();\n\
    \      if (coeff * A[rank][j] != 1) return {};\n      for (auto& [k, v] : A[rank])\
    \ {\n        if (v != mint{}) {\n          v *= coeff;\n          arank.emplace_back(k,\
    \ v);\n        }\n      }\n      b[rank] *= coeff;\n    }\n    for (int i = rank\
    \ + 1; i < min(H, rank + upper + 1); i++) {\n      auto it = A[i].find(j);\n \
    \     if (it != end(A[i]) and it->second != mint{}) {\n        mint coeff = (it->second);\n\
    \        for (auto& [k, v] : arank) A[i][k] -= v * coeff;\n        b[i] -= b[rank]\
    \ * coeff;\n      }\n    }\n    rank++;\n  }\n  vector<mint> res(W);\n  for (int\
    \ j = W - 1; j >= 0; j--) {\n    if (pivots[j] != -1) {\n      int i = pivots[j];\n\
    \      for (auto& [k, v] : A[i]) b[i] -= v * res[k];\n      res[j] = b[i];\n \
    \   }\n  }\n  for (int i = rank; i < H; i++) {\n    mint l = 0;\n    for (auto&\
    \ [k, v] : A[i]) l += res[k] * v;\n    if (l != b[i]) return {};\n  }\n  return\
    \ res;\n}\n"
  code: "#pragma once\n\n\nvector<mint> LinearEquation_hashmap(vector<HashMap<int,\
    \ mint>> A,\n                                    vector<mint> b, int upper = -1)\
    \ {\n  int H = A.size(), W = b.size();\n  if (upper = -1) upper = W;\n  vector<int>\
    \ pivots(W, -1);\n  int rank = 0, je = W;\n  for (int j = 0; j < je; j++) {\n\
    \    int idx = -1;\n    for (int i = rank; i < H; i++) {\n      auto it = A[i].find(j);\n\
    \      if (it != end(A[i]) and it->second != mint{}) {\n        idx = i;\n   \
    \     break;\n      }\n    }\n    if (idx == -1) continue;\n    if (rank != idx)\
    \ {\n      swap(A[rank], A[idx]);\n      swap(b[rank], b[idx]);\n    }\n    pivots[j]\
    \ = rank;\n    vector<pair<int, mint>> arank;\n    {\n      mint coeff = A[rank][j].inverse();\n\
    \      if (coeff * A[rank][j] != 1) return {};\n      for (auto& [k, v] : A[rank])\
    \ {\n        if (v != mint{}) {\n          v *= coeff;\n          arank.emplace_back(k,\
    \ v);\n        }\n      }\n      b[rank] *= coeff;\n    }\n    for (int i = rank\
    \ + 1; i < min(H, rank + upper + 1); i++) {\n      auto it = A[i].find(j);\n \
    \     if (it != end(A[i]) and it->second != mint{}) {\n        mint coeff = (it->second);\n\
    \        for (auto& [k, v] : arank) A[i][k] -= v * coeff;\n        b[i] -= b[rank]\
    \ * coeff;\n      }\n    }\n    rank++;\n  }\n  vector<mint> res(W);\n  for (int\
    \ j = W - 1; j >= 0; j--) {\n    if (pivots[j] != -1) {\n      int i = pivots[j];\n\
    \      for (auto& [k, v] : A[i]) b[i] -= v * res[k];\n      res[j] = b[i];\n \
    \   }\n  }\n  for (int i = rank; i < H; i++) {\n    mint l = 0;\n    for (auto&\
    \ [k, v] : A[i]) l += res[k] * v;\n    if (l != b[i]) return {};\n  }\n  return\
    \ res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: matrix/linear-equation-hashmap.hpp
  requiredBy: []
  timestamp: '2022-08-22 19:46:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/linear-equation-hashmap.hpp
layout: document
redirect_from:
- /library/matrix/linear-equation-hashmap.hpp
- /library/matrix/linear-equation-hashmap.hpp.html
title: matrix/linear-equation-hashmap.hpp
---
