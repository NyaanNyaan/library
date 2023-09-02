---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-deque-operate-all-composite.test.cpp
    title: verify/verify-yosupo-ds/yosupo-deque-operate-all-composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Slide Window Aggrigation (deque)
    links: []
  bundledCode: "#line 2 \"data-structure/slide-window-aggregation-deque.hpp\"\n\n\
    #include <vector>\nusing namespace std;\n\ntemplate <typename T, typename F>\n\
    struct SlideWindowAggregationDeque {\n  vector<T> a0, a1, r0, r1;\n  F f;\n  T\
    \ I;\n\n  SlideWindowAggregationDeque(F _f, T _i) : f(_f), I(_i) {}\n\n private:\n\
    \  T get0() const { return r0.empty() ? I : r0.back(); }\n  T get1() const { return\
    \ r1.empty() ? I : r1.back(); }\n\n  void push0(const T &x) {\n    a0.push_back(x);\n\
    \    r0.push_back(f(x, get0()));\n  }\n  void push1(const T &x) {\n    a1.push_back(x);\n\
    \    r1.push_back(f(get1(), x));\n  }\n  void rebalance() {\n    int n = a0.size()\
    \ + a1.size();\n    int s0 = n / 2 + (a0.empty() ? n % 2 : 0);\n    vector<T>\
    \ a{a0};\n    reverse(begin(a), end(a));\n    copy(begin(a1), end(a1), back_inserter(a));\n\
    \    a0.clear(), r0.clear();\n    a1.clear(), r1.clear();\n    for (int i = s0\
    \ - 1; i >= 0; i--) push0(a[i]);\n    for (int i = s0; i < n; i++) push1(a[i]);\n\
    \  }\n\n public:\n  void push_front(const T &t) { push0(t); }\n  void push_back(const\
    \ T &t) { push1(t); }\n  T front() const { return a0.empty() ? a1.front() : a0.back();\
    \ }\n  T back() const { return a1.empty() ? a0.front() : a1.back(); }\n  void\
    \ pop_front() {\n    if (a0.empty()) rebalance();\n    assert(!a0.empty());\n\
    \    a0.pop_back(), r0.pop_back();\n  }\n  void pop_back() {\n    if (a1.empty())\
    \ rebalance();\n    assert(!a1.empty());\n    a1.pop_back(), r1.pop_back();\n\
    \  }\n  T query() { return f(get0(), get1()); }\n};\n\n/**\n * @brief Slide Window\
    \ Aggrigation (deque)\n */\n"
  code: "#pragma once\n\n#include <vector>\nusing namespace std;\n\ntemplate <typename\
    \ T, typename F>\nstruct SlideWindowAggregationDeque {\n  vector<T> a0, a1, r0,\
    \ r1;\n  F f;\n  T I;\n\n  SlideWindowAggregationDeque(F _f, T _i) : f(_f), I(_i)\
    \ {}\n\n private:\n  T get0() const { return r0.empty() ? I : r0.back(); }\n \
    \ T get1() const { return r1.empty() ? I : r1.back(); }\n\n  void push0(const\
    \ T &x) {\n    a0.push_back(x);\n    r0.push_back(f(x, get0()));\n  }\n  void\
    \ push1(const T &x) {\n    a1.push_back(x);\n    r1.push_back(f(get1(), x));\n\
    \  }\n  void rebalance() {\n    int n = a0.size() + a1.size();\n    int s0 = n\
    \ / 2 + (a0.empty() ? n % 2 : 0);\n    vector<T> a{a0};\n    reverse(begin(a),\
    \ end(a));\n    copy(begin(a1), end(a1), back_inserter(a));\n    a0.clear(), r0.clear();\n\
    \    a1.clear(), r1.clear();\n    for (int i = s0 - 1; i >= 0; i--) push0(a[i]);\n\
    \    for (int i = s0; i < n; i++) push1(a[i]);\n  }\n\n public:\n  void push_front(const\
    \ T &t) { push0(t); }\n  void push_back(const T &t) { push1(t); }\n  T front()\
    \ const { return a0.empty() ? a1.front() : a0.back(); }\n  T back() const { return\
    \ a1.empty() ? a0.front() : a1.back(); }\n  void pop_front() {\n    if (a0.empty())\
    \ rebalance();\n    assert(!a0.empty());\n    a0.pop_back(), r0.pop_back();\n\
    \  }\n  void pop_back() {\n    if (a1.empty()) rebalance();\n    assert(!a1.empty());\n\
    \    a1.pop_back(), r1.pop_back();\n  }\n  T query() { return f(get0(), get1());\
    \ }\n};\n\n/**\n * @brief Slide Window Aggrigation (deque)\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/slide-window-aggregation-deque.hpp
  requiredBy: []
  timestamp: '2023-09-02 22:21:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-deque-operate-all-composite.test.cpp
documentation_of: data-structure/slide-window-aggregation-deque.hpp
layout: document
redirect_from:
- /library/data-structure/slide-window-aggregation-deque.hpp
- /library/data-structure/slide-window-aggregation-deque.hpp.html
title: Slide Window Aggrigation (deque)
---
