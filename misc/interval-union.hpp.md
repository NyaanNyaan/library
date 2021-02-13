---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/interval-union.test.cpp
    title: verify/verify-unit-test/interval-union.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u533A\u9593\u306E\u96C6\u5408\u306E\u76F4\u548C"
    links: []
  bundledCode: "#line 2 \"misc/interval-union.hpp\"\n\n// Union of [a_1, b_1), [a_2,\
    \ b_2), ...\ntemplate <typename T>\nvector<pair<T, T>> interval_union(const vector<pair<T,\
    \ T>> &v) {\n  vector<pair<T, T>> buf{v}, res;\n  sort(begin(buf), end(buf));\n\
    \  for (auto &p : buf) {\n    res.push_back(p);\n    while ((int)res.size() >=\
    \ 2) {\n      int n = res.size();\n      if (res[n - 2].second < res[n - 1].first)\
    \ break;\n      pair<T, T> q;\n      q.first = res[n - 2].first;\n      q.second\
    \ = max<T>(res[n - 2].second, res[n - 1].second);\n      res.pop_back();\n   \
    \   res.pop_back();\n      res.push_back(q);\n    }\n  }\n  return res;\n}\n\n\
    /**\n * @brief \u533A\u9593\u306E\u96C6\u5408\u306E\u76F4\u548C\n */\n"
  code: "#pragma once\n\n// Union of [a_1, b_1), [a_2, b_2), ...\ntemplate <typename\
    \ T>\nvector<pair<T, T>> interval_union(const vector<pair<T, T>> &v) {\n  vector<pair<T,\
    \ T>> buf{v}, res;\n  sort(begin(buf), end(buf));\n  for (auto &p : buf) {\n \
    \   res.push_back(p);\n    while ((int)res.size() >= 2) {\n      int n = res.size();\n\
    \      if (res[n - 2].second < res[n - 1].first) break;\n      pair<T, T> q;\n\
    \      q.first = res[n - 2].first;\n      q.second = max<T>(res[n - 2].second,\
    \ res[n - 1].second);\n      res.pop_back();\n      res.pop_back();\n      res.push_back(q);\n\
    \    }\n  }\n  return res;\n}\n\n/**\n * @brief \u533A\u9593\u306E\u96C6\u5408\
    \u306E\u76F4\u548C\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/interval-union.hpp
  requiredBy: []
  timestamp: '2021-02-14 00:25:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/interval-union.test.cpp
documentation_of: misc/interval-union.hpp
layout: document
redirect_from:
- /library/misc/interval-union.hpp
- /library/misc/interval-union.hpp.html
title: "\u533A\u9593\u306E\u96C6\u5408\u306E\u76F4\u548C"
---
