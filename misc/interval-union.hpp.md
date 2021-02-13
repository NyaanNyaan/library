---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/verify-unit-test/interval-union.cpp
    title: verify/verify-unit-test/interval-union.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/interval-union.hpp\"\n\n// Union of [a_1, b_1), [a_2,\
    \ b_2), ...\ntemplate <typename T>\nvector<pair<T, T>> interval_union(const vector<pair<T,\
    \ T>> &v) {\n  vector<pair<T, T>> buf{v}, res;\n  sort(begin(buf), end(buf));\n\
    \  for (auto &p : buf) {\n    res.push_back(p);\n    while ((int)res.size() >=\
    \ 2) {\n      int n = res.size();\n      if (res[n - 2].second < res[n - 1].first)\
    \ break;\n      pair<T, T> q;\n      q.first = res[n - 2].first;\n      q.second\
    \ = max<T>(res[n - 2].second, res[n - 1].second);\n      res.pop_back();\n   \
    \   res.pop_back();\n      res.push_back(q);\n    }\n  }\n  return res;\n}\n"
  code: "#pragma once\n\n// Union of [a_1, b_1), [a_2, b_2), ...\ntemplate <typename\
    \ T>\nvector<pair<T, T>> interval_union(const vector<pair<T, T>> &v) {\n  vector<pair<T,\
    \ T>> buf{v}, res;\n  sort(begin(buf), end(buf));\n  for (auto &p : buf) {\n \
    \   res.push_back(p);\n    while ((int)res.size() >= 2) {\n      int n = res.size();\n\
    \      if (res[n - 2].second < res[n - 1].first) break;\n      pair<T, T> q;\n\
    \      q.first = res[n - 2].first;\n      q.second = max<T>(res[n - 2].second,\
    \ res[n - 1].second);\n      res.pop_back();\n      res.pop_back();\n      res.push_back(q);\n\
    \    }\n  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/interval-union.hpp
  requiredBy:
  - verify/verify-unit-test/interval-union.cpp
  timestamp: '2021-02-14 00:11:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/interval-union.hpp
layout: document
redirect_from:
- /library/misc/interval-union.hpp
- /library/misc/interval-union.hpp.html
title: misc/interval-union.hpp
---
