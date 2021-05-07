---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-abstruct-range-tree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-abstruct-range-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-bit2d.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-bit2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-dseg2d.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-dseg2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-rtree-fenwick.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-rtree-fenwick.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp
    title: verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/compress.hpp\"\n\ntemplate <class T>\nstruct compress\
    \ {\n  vector<T> xs;\n  compress(const vector<T>& v) {\n    xs.reserve(v.size());\n\
    \    for (T x : v) xs.push_back(x);\n    sort(xs.begin(), xs.end());\n    xs.erase(unique(xs.begin(),\
    \ xs.end()), xs.end());\n  }\n  int get(const T& x) const {\n    return lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n  }\n  inline int operator()(const T& x) const {\
    \ return get(x); }\n  T operator[](int i) { return xs[i]; }\n  int size() const\
    \ { return xs.size(); }\n};\n\n/**\n * \u5EA7\u6A19\u5727\u7E2E\n */\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct compress {\n  vector<T> xs;\n\
    \  compress(const vector<T>& v) {\n    xs.reserve(v.size());\n    for (T x : v)\
    \ xs.push_back(x);\n    sort(xs.begin(), xs.end());\n    xs.erase(unique(xs.begin(),\
    \ xs.end()), xs.end());\n  }\n  int get(const T& x) const {\n    return lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n  }\n  inline int operator()(const T& x) const {\
    \ return get(x); }\n  T operator[](int i) { return xs[i]; }\n  int size() const\
    \ { return xs.size(); }\n};\n\n/**\n * \u5EA7\u6A19\u5727\u7E2E\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/compress.hpp
  requiredBy: []
  timestamp: '2021-01-15 18:15:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-abstruct-range-tree.test.cpp
  - verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-dseg2d.test.cpp
  - verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp
  - verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-bit2d.test.cpp
  - verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-rtree-fenwick.test.cpp
documentation_of: misc/compress.hpp
layout: document
redirect_from:
- /library/misc/compress.hpp
- /library/misc/compress.hpp.html
title: misc/compress.hpp
---
