---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-unit-test/tree-path.test.cpp
    title: verify/verify-unit-test/tree-path.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Pruefer Code
    links: []
  bundledCode: "#line 2 \"tree/pruefer-code.hpp\"\n\n#line 2 \"misc/rng.hpp\"\n\n\
    namespace my_rand {\n\n// [0, 2^64 - 1)\nuint64_t rng() {\n  static uint64_t x_\
    \ =\n      uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n            \
    \       chrono::high_resolution_clock::now().time_since_epoch())\n           \
    \        .count()) *\n      10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return\
    \ x_ ^= x_ >> 9;\n}\n\n// [l, r)\nint64_t randint(int64_t l, int64_t r) {\n  assert(l\
    \ < r);\n  return l + rng() % (r - l);\n}\n\n// choose n numbers from [l, r) without\
    \ overlapping\nvector<int64_t> randset(int64_t l, int64_t r, int64_t n) {\n  assert(l\
    \ <= r && n <= r - l);\n  unordered_set<int64_t> s;\n  for (int64_t i = n; i;\
    \ --i) {\n    int64_t m = randint(l, r + 1 - i);\n    if (s.find(m) != s.end())\
    \ m = r - i;\n    s.insert(m);\n  }\n  vector<int64_t> ret;\n  for (auto& x :\
    \ s) ret.push_back(x);\n  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() {\n  union\
    \ raw_cast {\n    double t;\n    uint64_t u;\n  };\n  constexpr uint64_t p = uint64_t(1023\
    \ - 64) << 52;\n  return rng() * ((raw_cast*)(&p))->t;\n}\n\ntemplate <typename\
    \ T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n  for (int loop = 0;\
    \ loop < 2; loop++)\n    for (int i = 0; i < n; i++) swap(v[i], v[randint(0, n)]);\n\
    }\n\n}  // namespace my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\n\
    using my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n#line 4 \"\
    tree/pruefer-code.hpp\"\n\n// input: [c \\in [0, n)] * (n-2), n>=3\nvector<vector<int>>\
    \ pruefer_code(const vector<int>& code) {\n  int n = code.size() + 2;\n  assert(n\
    \ > 2);\n  vector<vector<int>> g(n);\n  vector<int> deg(n, 1);\n  int e = 0;\n\
    \  for (auto& x : code) deg[x]++;\n  for (auto& i : code) {\n    for (int j =\
    \ 0; j < n; j++) {\n      if (deg[j] == 1) {\n        g[i].push_back(j);\n   \
    \     g[j].push_back(i);\n        deg[i]--, deg[j]--;\n        e++;\n        break;\n\
    \      }\n    }\n  }\n  int u = -1, v = -1;\n  for (int i = 0; i < n; i++) {\n\
    \    if (deg[i] == 1) (u == -1 ? u : v) = i;\n  }\n  assert(u != -1 and v != -1);\n\
    \  g[u].push_back(v);\n  g[v].push_back(u);\n  e++;\n  assert(e == n - 1);\n \
    \ return g;\n}\n\nvector<vector<int>> random_tree(int n) {\n  if (n <= 2) {\n\
    \    vector<vector<int>> g(n);\n    if (n == 2) {\n      g[0].push_back(1);\n\
    \      g[1].push_back(0);\n    }\n    return g;\n  }\n  vector<int> pruefer(n\
    \ - 2);\n  for (auto& x : pruefer) x = randint(0, n);\n  return pruefer_code(pruefer);\n\
    }\n\n/**\n * @brief Pruefer Code\n */\n"
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
  timestamp: '2020-12-08 00:23:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-unit-test/tree-path.test.cpp
documentation_of: tree/pruefer-code.hpp
layout: document
redirect_from:
- /library/tree/pruefer-code.hpp
- /library/tree/pruefer-code.hpp.html
title: Pruefer Code
---
