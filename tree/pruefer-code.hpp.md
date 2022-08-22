---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/tree-path.test.cpp
    title: verify/verify-unit-test/tree-path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Pruefer Code
    links: []
  bundledCode: "#line 2 \"tree/pruefer-code.hpp\"\n\n#line 2 \"misc/rng.hpp\"\n\n\
    namespace my_rand {\nusing i64 = long long;\nusing u64 = unsigned long long;\n\
    \n// [0, 2^64 - 1)\nu64 rng() {\n  static u64 _x =\n      u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \              chrono::high_resolution_clock::now().time_since_epoch())\n    \
    \          .count()) *\n      10150724397891781847ULL;\n  _x ^= _x << 7;\n  return\
    \ _x ^= _x >> 9;\n}\n\n// [l, r]\ni64 rng(i64 l, i64 r) {\n  assert(l <= r);\n\
    \  return l + rng() % (r - l + 1);\n}\n\n// [l, r)\ni64 randint(i64 l, i64 r)\
    \ {\n  assert(l < r);\n  return l + rng() % (r - l);\n}\n\n// choose n numbers\
    \ from [l, r) without overlapping\nvector<i64> randset(i64 l, i64 r, i64 n) {\n\
    \  assert(l <= r && n <= r - l);\n  unordered_set<i64> s;\n  for (i64 i = n; i;\
    \ --i) {\n    i64 m = randint(l, r + 1 - i);\n    if (s.find(m) != s.end()) m\
    \ = r - i;\n    s.insert(m);\n  }\n  vector<i64> ret;\n  for (auto& x : s) ret.push_back(x);\n\
    \  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() { return rng() * 5.42101086242752217004e-20;\
    \ }\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n\
    \  for (int i = 1; i < n; i++) swap(v[i], v[randint(0, i + 1)]);\n}\n\n}  // namespace\
    \ my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\nusing my_rand::randshf;\n\
    using my_rand::rnd;\nusing my_rand::rng;\n#line 4 \"tree/pruefer-code.hpp\"\n\n\
    // input: [c \\in [0, n)] * (n-2), n>=3\nvector<vector<int>> pruefer_code(const\
    \ vector<int>& code) {\n  int n = code.size() + 2;\n  assert(n > 2);\n  vector<vector<int>>\
    \ g(n);\n  vector<int> deg(n, 1);\n  int e = 0;\n  for (auto& x : code) deg[x]++;\n\
    \  for (auto& i : code) {\n    for (int j = 0; j < n; j++) {\n      if (deg[j]\
    \ == 1) {\n        g[i].push_back(j);\n        g[j].push_back(i);\n        deg[i]--,\
    \ deg[j]--;\n        e++;\n        break;\n      }\n    }\n  }\n  int u = -1,\
    \ v = -1;\n  for (int i = 0; i < n; i++) {\n    if (deg[i] == 1) (u == -1 ? u\
    \ : v) = i;\n  }\n  assert(u != -1 and v != -1);\n  g[u].push_back(v);\n  g[v].push_back(u);\n\
    \  e++;\n  assert(e == n - 1);\n  return g;\n}\n\nvector<vector<int>> random_tree(int\
    \ n) {\n  if (n <= 2) {\n    vector<vector<int>> g(n);\n    if (n == 2) {\n  \
    \    g[0].push_back(1);\n      g[1].push_back(0);\n    }\n    return g;\n  }\n\
    \  vector<int> pruefer(n - 2);\n  for (auto& x : pruefer) x = randint(0, n);\n\
    \  return pruefer_code(pruefer);\n}\n\n/**\n * @brief Pruefer Code\n */\n"
  code: "#pragma once\n\n#include \"../misc/rng.hpp\"\n\n// input: [c \\in [0, n)]\
    \ * (n-2), n>=3\nvector<vector<int>> pruefer_code(const vector<int>& code) {\n\
    \  int n = code.size() + 2;\n  assert(n > 2);\n  vector<vector<int>> g(n);\n \
    \ vector<int> deg(n, 1);\n  int e = 0;\n  for (auto& x : code) deg[x]++;\n  for\
    \ (auto& i : code) {\n    for (int j = 0; j < n; j++) {\n      if (deg[j] == 1)\
    \ {\n        g[i].push_back(j);\n        g[j].push_back(i);\n        deg[i]--,\
    \ deg[j]--;\n        e++;\n        break;\n      }\n    }\n  }\n  int u = -1,\
    \ v = -1;\n  for (int i = 0; i < n; i++) {\n    if (deg[i] == 1) (u == -1 ? u\
    \ : v) = i;\n  }\n  assert(u != -1 and v != -1);\n  g[u].push_back(v);\n  g[v].push_back(u);\n\
    \  e++;\n  assert(e == n - 1);\n  return g;\n}\n\nvector<vector<int>> random_tree(int\
    \ n) {\n  if (n <= 2) {\n    vector<vector<int>> g(n);\n    if (n == 2) {\n  \
    \    g[0].push_back(1);\n      g[1].push_back(0);\n    }\n    return g;\n  }\n\
    \  vector<int> pruefer(n - 2);\n  for (auto& x : pruefer) x = randint(0, n);\n\
    \  return pruefer_code(pruefer);\n}\n\n/**\n * @brief Pruefer Code\n */\n"
  dependsOn:
  - misc/rng.hpp
  isVerificationFile: false
  path: tree/pruefer-code.hpp
  requiredBy: []
  timestamp: '2022-08-22 19:46:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/tree-path.test.cpp
documentation_of: tree/pruefer-code.hpp
layout: document
redirect_from:
- /library/tree/pruefer-code.hpp
- /library/tree/pruefer-code.hpp.html
title: Pruefer Code
---
