---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum.test-bit2d.cpp
    title: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum.test-bit2d.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp
    title: verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"misc/compress.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate<class T>\nstruct compress{\n  vector<T> xs;\n  compress(const\
    \ vector<T>& v){\n    xs.reserve(v.size());\n    for(T x : v) xs.push_back(x);\n\
    \    sort(xs.begin(),xs.end());\n    xs.erase(unique(xs.begin(),xs.end()) , xs.end());\n\
    \  }\n\n  int get(const T& x){\n    return lower_bound(xs.begin(),xs.end(),x)\
    \ - xs.begin();\n  }\n  int size(){\n    return xs.size();\n  }\n  T& operator[](int\
    \ i){\n    return xs[i];\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<class\
    \ T>\nstruct compress{\n  vector<T> xs;\n  compress(const vector<T>& v){\n   \
    \ xs.reserve(v.size());\n    for(T x : v) xs.push_back(x);\n    sort(xs.begin(),xs.end());\n\
    \    xs.erase(unique(xs.begin(),xs.end()) , xs.end());\n  }\n\n  int get(const\
    \ T& x){\n    return lower_bound(xs.begin(),xs.end(),x) - xs.begin();\n  }\n \
    \ int size(){\n    return xs.size();\n  }\n  T& operator[](int i){\n    return\
    \ xs[i];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/compress.hpp
  requiredBy:
  - verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum.test-bit2d.cpp
  timestamp: '2020-07-28 11:29:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp
documentation_of: misc/compress.hpp
layout: document
redirect_from:
- /library/misc/compress.hpp
- /library/misc/compress.hpp.html
title: misc/compress.hpp
---