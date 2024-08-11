---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/erasable-priority-queue.test.cpp
    title: verify/verify-unit-test/erasable-priority-queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/erasable-priority-queue.hpp\"\n\n#include\
    \ <queue>\n#include <type_traits>\nusing namespace std;\n\ntemplate <typename\
    \ T, bool Minimize = true>\nstruct ErasablePriorityQueue {\n  using Queue =\n\
    \      conditional_t<Minimize, priority_queue<T, vector<T>, greater<T>>,\n   \
    \                 priority_queue<T>>;\n  Queue Q, Q2;\n\n  ErasablePriorityQueue()\
    \ = default;\n\n  void push(const T& t) { Q.push(t); }\n  T top() {\n    normalize();\n\
    \    assert(!Q.empty());\n    return Q.top();\n  }\n  void pop() {\n    normalize();\n\
    \    assert(!Q.empty());\n    Q.pop();\n  }\n  void erase(const T& t) { Q2.push(t);\
    \ }\n\n private:\n  void normalize() {\n    while (!Q.empty() and !Q2.empty()\
    \ and Q.top() == Q2.top()) {\n      Q.pop(), Q2.pop();\n    }\n  }\n};\n"
  code: "#pragma once\n\n#include <queue>\n#include <type_traits>\nusing namespace\
    \ std;\n\ntemplate <typename T, bool Minimize = true>\nstruct ErasablePriorityQueue\
    \ {\n  using Queue =\n      conditional_t<Minimize, priority_queue<T, vector<T>,\
    \ greater<T>>,\n                    priority_queue<T>>;\n  Queue Q, Q2;\n\n  ErasablePriorityQueue()\
    \ = default;\n\n  void push(const T& t) { Q.push(t); }\n  T top() {\n    normalize();\n\
    \    assert(!Q.empty());\n    return Q.top();\n  }\n  void pop() {\n    normalize();\n\
    \    assert(!Q.empty());\n    Q.pop();\n  }\n  void erase(const T& t) { Q2.push(t);\
    \ }\n\n private:\n  void normalize() {\n    while (!Q.empty() and !Q2.empty()\
    \ and Q.top() == Q2.top()) {\n      Q.pop(), Q2.pop();\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/erasable-priority-queue.hpp
  requiredBy: []
  timestamp: '2024-08-10 13:03:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/erasable-priority-queue.test.cpp
documentation_of: data-structure/erasable-priority-queue.hpp
layout: document
redirect_from:
- /library/data-structure/erasable-priority-queue.hpp
- /library/data-structure/erasable-priority-queue.hpp.html
title: data-structure/erasable-priority-queue.hpp
---
