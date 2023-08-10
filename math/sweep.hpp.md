---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-3277.test.cpp
    title: verify/verify-aoj-other/aoj-3277.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6383\u304D\u51FA\u3057\u6CD5"
    links: []
  bundledCode: "#line 2 \"math/sweep.hpp\"\n\n#include <array>\n#include <vector>\n\
    using namespace std;\n\n// MAX bit\ntemplate <typename Int, int MAX>\nstruct Basis\
    \ {\n  array<Int, MAX> v;\n\n  Basis() : _size(0) { fill(begin(v), end(v), Int{0});\
    \ }\n  Basis(const vector<Int>& a) : _size(0) {\n    fill(begin(v), end(v), Int{0});\n\
    \    for (auto& x : a) add(x);\n  }\n  const Int operator[](int i) const { return\
    \ v[i]; }\n\n  // \u8FFD\u52A0\u6210\u529F\u304B\u3069\u3046\u304B\u3092\u8FD4\
    \u3059\n  bool add(Int x) {\n    int t = _msb(x);\n    assert(t < MAX);\n    while\
    \ (t != -1 && v[t]) t = _msb(x ^= v[t]);\n    return t == -1 ? false : (v[t] =\
    \ x, _size++, true);\n  }\n\n  // rhs \u3068\u306E\u548C\u3092\u6C42\u3081\u308B\
    \n  void merge(const Basis& rhs) {\n    for (int _t = MAX - 1; _t >= 0; _t--)\
    \ {\n      if (rhs.v[_t] == Int{0}) continue;\n      int t = _t;\n      Int x\
    \ = rhs.v[t];\n      while (t != -1 && v[t]) t = _msb(x ^= v[t]);\n      if (x)\
    \ v[t] = x, _size++;\n    }\n  }\n\n  // \u6B63\u898F\u5316\u3055\u308C\u305F\u57FA\
    \u5E95\u3092\u5F97\u308B (O(MAX^2))\n  vector<Int> get_basis() {\n    normalize();\n\
    \    vector<Int> res;\n    for (int t = 0; t < MAX; t++) {\n      if (v[t]) res.push_back(v[t]);\n\
    \    }\n    reverse(begin(res), end(res));\n    return res;\n  }\n\n  // x \u3092\
    \u4F5C\u308C\u308B\u304B\uFF1F TODO:verify\n  bool test(Int x) {\n    if (x ==\
    \ 0) return true;\n    int t = _msb(x);\n    if (t >= MAX) return false;\n   \
    \ while (t != -1 && v[t]) t = _msb(x ^= v[t]);\n    return x == 0;\n  }\n\n  //\
    \ \u4F5C\u308C\u308B x \u306E\u6700\u5927\u5024 TODO:verify\n  Int get_max() const\
    \ {\n    Int res = 0;\n    for (int t = MAX - 1; t >= 0; t--) res = max(res, res\
    \ ^ v[t]);\n    return res;\n  }\n\n  // \u884C\u5217\u3092\u6A19\u6E96\u5316\u3059\
    \u308B\n  void normalize() {\n    for (int t = MAX - 1; t >= 0; t--) {\n     \
    \ if (v[t]) {\n        for (int u = MAX - 1; u > t; u--) v[u] = min(v[u], v[u]\
    \ ^ v[t]);\n      }\n    }\n  }\n\n  vector<Int> orthogonal_complement(int N =\
    \ MAX) {\n    normalize();\n    vector<int> b;\n    for (int t = N - 1; t >= 0;\
    \ t--) {\n      if (v[t]) b.push_back(t);\n    }\n    int rank = b.size();\n \
    \   for (int t = N - 1; t >= 0; t--) {\n      if (!v[t]) b.push_back(t);\n   \
    \ }\n    vector<Int> res(N - rank);\n    for (int i = rank; i < N; i++) {\n  \
    \    for (int j = 0; j < N; j++) {\n        if (j < rank ? ((v[b[j]] >> b[i])\
    \ & 1) : i == j) {\n          res[i - rank] |= Int{1} << b[j];\n        }\n  \
    \    }\n    }\n    return res;\n  }\n\n  int size() const { return _size; }\n\n\
    \  friend ostream& operator<<(ostream& os, const Basis<Int, MAX>& b) {\n    os\
    \ << \"{ \";\n    for (int i = 0; i < MAX; i++) {\n      if (b.v[i]) os << b.v[i]\
    \ << \", \";\n    }\n    return os << \"}\";\n  }\n\n private:\n  int _size;\n\
    \  int _msb(Int x) { return x ? 63 - __builtin_clzll(x) : -1; }\n};\n\n/*\n *\
    \ @brief \u6383\u304D\u51FA\u3057\u6CD5\n */\n"
  code: "#pragma once\n\n#include <array>\n#include <vector>\nusing namespace std;\n\
    \n// MAX bit\ntemplate <typename Int, int MAX>\nstruct Basis {\n  array<Int, MAX>\
    \ v;\n\n  Basis() : _size(0) { fill(begin(v), end(v), Int{0}); }\n  Basis(const\
    \ vector<Int>& a) : _size(0) {\n    fill(begin(v), end(v), Int{0});\n    for (auto&\
    \ x : a) add(x);\n  }\n  const Int operator[](int i) const { return v[i]; }\n\n\
    \  // \u8FFD\u52A0\u6210\u529F\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\n  bool\
    \ add(Int x) {\n    int t = _msb(x);\n    assert(t < MAX);\n    while (t != -1\
    \ && v[t]) t = _msb(x ^= v[t]);\n    return t == -1 ? false : (v[t] = x, _size++,\
    \ true);\n  }\n\n  // rhs \u3068\u306E\u548C\u3092\u6C42\u3081\u308B\n  void merge(const\
    \ Basis& rhs) {\n    for (int _t = MAX - 1; _t >= 0; _t--) {\n      if (rhs.v[_t]\
    \ == Int{0}) continue;\n      int t = _t;\n      Int x = rhs.v[t];\n      while\
    \ (t != -1 && v[t]) t = _msb(x ^= v[t]);\n      if (x) v[t] = x, _size++;\n  \
    \  }\n  }\n\n  // \u6B63\u898F\u5316\u3055\u308C\u305F\u57FA\u5E95\u3092\u5F97\
    \u308B (O(MAX^2))\n  vector<Int> get_basis() {\n    normalize();\n    vector<Int>\
    \ res;\n    for (int t = 0; t < MAX; t++) {\n      if (v[t]) res.push_back(v[t]);\n\
    \    }\n    reverse(begin(res), end(res));\n    return res;\n  }\n\n  // x \u3092\
    \u4F5C\u308C\u308B\u304B\uFF1F TODO:verify\n  bool test(Int x) {\n    if (x ==\
    \ 0) return true;\n    int t = _msb(x);\n    if (t >= MAX) return false;\n   \
    \ while (t != -1 && v[t]) t = _msb(x ^= v[t]);\n    return x == 0;\n  }\n\n  //\
    \ \u4F5C\u308C\u308B x \u306E\u6700\u5927\u5024 TODO:verify\n  Int get_max() const\
    \ {\n    Int res = 0;\n    for (int t = MAX - 1; t >= 0; t--) res = max(res, res\
    \ ^ v[t]);\n    return res;\n  }\n\n  // \u884C\u5217\u3092\u6A19\u6E96\u5316\u3059\
    \u308B\n  void normalize() {\n    for (int t = MAX - 1; t >= 0; t--) {\n     \
    \ if (v[t]) {\n        for (int u = MAX - 1; u > t; u--) v[u] = min(v[u], v[u]\
    \ ^ v[t]);\n      }\n    }\n  }\n\n  vector<Int> orthogonal_complement(int N =\
    \ MAX) {\n    normalize();\n    vector<int> b;\n    for (int t = N - 1; t >= 0;\
    \ t--) {\n      if (v[t]) b.push_back(t);\n    }\n    int rank = b.size();\n \
    \   for (int t = N - 1; t >= 0; t--) {\n      if (!v[t]) b.push_back(t);\n   \
    \ }\n    vector<Int> res(N - rank);\n    for (int i = rank; i < N; i++) {\n  \
    \    for (int j = 0; j < N; j++) {\n        if (j < rank ? ((v[b[j]] >> b[i])\
    \ & 1) : i == j) {\n          res[i - rank] |= Int{1} << b[j];\n        }\n  \
    \    }\n    }\n    return res;\n  }\n\n  int size() const { return _size; }\n\n\
    \  friend ostream& operator<<(ostream& os, const Basis<Int, MAX>& b) {\n    os\
    \ << \"{ \";\n    for (int i = 0; i < MAX; i++) {\n      if (b.v[i]) os << b.v[i]\
    \ << \", \";\n    }\n    return os << \"}\";\n  }\n\n private:\n  int _size;\n\
    \  int _msb(Int x) { return x ? 63 - __builtin_clzll(x) : -1; }\n};\n\n/*\n *\
    \ @brief \u6383\u304D\u51FA\u3057\u6CD5\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/sweep.hpp
  requiredBy: []
  timestamp: '2023-08-10 13:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-other/aoj-3277.test.cpp
documentation_of: math/sweep.hpp
layout: document
redirect_from:
- /library/math/sweep.hpp
- /library/math/sweep.hpp.html
title: "\u6383\u304D\u51FA\u3057\u6CD5"
---
