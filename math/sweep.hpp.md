---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/nimber-to-field.hpp
    title: "Nimber <-> \u591A\u9805\u5F0F\u74B0"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/nimber-to-field.test.cpp
    title: verify/verify-unit-test/nimber-to-field.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6383\u304D\u51FA\u3057\u6CD5(\u5FA9\u5143\u4ED8\u304D)"
    links: []
  bundledCode: "#line 2 \"math/sweep.hpp\"\n\ntemplate <typename T>\nstruct Sweep\
    \ {\n  using P = pair<T, unordered_set<int>>;\n  vector<P> basis;\n  int num;\n\
    \n  Sweep() : num(0) {}\n  Sweep(const vector<T>& v) : num(0) {\n    for (auto&\
    \ x : v) add(x, num++);\n  }\n\n  void apply(P& p, const P& o) {\n    p.first\
    \ ^= o.first;\n    for (auto& x : o.second) apply(p.second, x);\n  }\n  void apply(unordered_set<int>&\
    \ s, int x) {\n    if (s.count(x)) {\n      s.erase(x);\n    } else {\n      s.insert(x);\n\
    \    }\n  }\n\n  void add(T x, int id) {\n    P v{x, {id}};\n    for (P& b : basis)\
    \ {\n      if (v.first > (v.first ^ b.first)) apply(v, b);\n    }\n    if (v.first\
    \ != T{}) basis.push_back(v);\n  }\n\n  pair<bool, vector<int>> restore(T x) {\n\
    \    P v{x, {}};\n    for (P& b : basis) {\n      if (v.first > (v.first ^ b.first))\
    \ apply(v, b);\n    }\n    if (v.first != T{}) return {false, {}};\n    vector<int>\
    \ res;\n    for (auto& n : v.second) res.push_back(n);\n    sort(begin(res), end(res));\n\
    \    return {true, res};\n  }\n};\n\n/**\n * @brief \u6383\u304D\u51FA\u3057\u6CD5\
    (\u5FA9\u5143\u4ED8\u304D)\n */\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct Sweep {\n  using P = pair<T,\
    \ unordered_set<int>>;\n  vector<P> basis;\n  int num;\n\n  Sweep() : num(0) {}\n\
    \  Sweep(const vector<T>& v) : num(0) {\n    for (auto& x : v) add(x, num++);\n\
    \  }\n\n  void apply(P& p, const P& o) {\n    p.first ^= o.first;\n    for (auto&\
    \ x : o.second) apply(p.second, x);\n  }\n  void apply(unordered_set<int>& s,\
    \ int x) {\n    if (s.count(x)) {\n      s.erase(x);\n    } else {\n      s.insert(x);\n\
    \    }\n  }\n\n  void add(T x, int id) {\n    P v{x, {id}};\n    for (P& b : basis)\
    \ {\n      if (v.first > (v.first ^ b.first)) apply(v, b);\n    }\n    if (v.first\
    \ != T{}) basis.push_back(v);\n  }\n\n  pair<bool, vector<int>> restore(T x) {\n\
    \    P v{x, {}};\n    for (P& b : basis) {\n      if (v.first > (v.first ^ b.first))\
    \ apply(v, b);\n    }\n    if (v.first != T{}) return {false, {}};\n    vector<int>\
    \ res;\n    for (auto& n : v.second) res.push_back(n);\n    sort(begin(res), end(res));\n\
    \    return {true, res};\n  }\n};\n\n/**\n * @brief \u6383\u304D\u51FA\u3057\u6CD5\
    (\u5FA9\u5143\u4ED8\u304D)\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/sweep.hpp
  requiredBy:
  - math/nimber-to-field.hpp
  timestamp: '2021-12-23 23:20:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/nimber-to-field.test.cpp
documentation_of: math/sweep.hpp
layout: document
redirect_from:
- /library/math/sweep.hpp
- /library/math/sweep.hpp.html
title: "\u6383\u304D\u51FA\u3057\u6CD5(\u5FA9\u5143\u4ED8\u304D)"
---
