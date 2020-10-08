---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: atcoder/maxflow.hpp
    title: atcoder/maxflow.hpp
  - icon: ':heavy_check_mark:'
    path: flow/flow-on-bipartite-graph.hpp
    title: flow/flow-on-bipartite-graph.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp
    title: verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"atcoder/internal_queue.hpp\"\n#include <vector>\n\nnamespace\
    \ atcoder {\n\nnamespace internal {\n\ntemplate <class T>\nstruct simple_queue\
    \ {\n  std::vector<T> payload;\n  int pos = 0;\n  void reserve(int n) { payload.reserve(n);\
    \ }\n  int size() const { return int(payload.size()) - pos; }\n  bool empty()\
    \ const { return pos == int(payload.size()); }\n  void push(const T& t) { payload.push_back(t);\
    \ }\n  T& front() { return payload[pos]; }\n  void clear() {\n    payload.clear();\n\
    \    pos = 0;\n  }\n  void pop() { pos++; }\n};\n\n}  // namespace internal\n\n\
    }  // namespace atcoder\n"
  code: "#pragma once\n#include <vector>\n\nnamespace atcoder {\n\nnamespace internal\
    \ {\n\ntemplate <class T>\nstruct simple_queue {\n  std::vector<T> payload;\n\
    \  int pos = 0;\n  void reserve(int n) { payload.reserve(n); }\n  int size() const\
    \ { return int(payload.size()) - pos; }\n  bool empty() const { return pos ==\
    \ int(payload.size()); }\n  void push(const T& t) { payload.push_back(t); }\n\
    \  T& front() { return payload[pos]; }\n  void clear() {\n    payload.clear();\n\
    \    pos = 0;\n  }\n  void pop() { pos++; }\n};\n\n}  // namespace internal\n\n\
    }  // namespace atcoder\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/internal_queue.hpp
  requiredBy:
  - flow/flow-on-bipartite-graph.hpp
  - atcoder/maxflow.hpp
  timestamp: '2020-09-08 18:51:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp
documentation_of: atcoder/internal_queue.hpp
layout: document
redirect_from:
- /library/atcoder/internal_queue.hpp
- /library/atcoder/internal_queue.hpp.html
title: atcoder/internal_queue.hpp
---
