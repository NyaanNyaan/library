---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-itp/aoj-itp2-11-b.test.cpp
    title: verify/verify-aoj-itp/aoj-itp2-11-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-itp/aoj-itp2-11-c.test.cpp
    title: verify/verify-aoj-itp/aoj-itp2-11-c.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4E0B\u4F4D\u96C6\u5408/\u4E0A\u4F4D\u96C6\u5408\u306E\u5217\
      \u6319"
    links: []
  bundledCode: "#line 2 \"set-function/enumerate-set.hpp\"\n\n\n\n// enumerate x :\
    \ x \\subset b\nvector<int> enumerate_subset(int b) {\n  vector<int> res;\n  for\
    \ (int i = b; i >= 0; --i) res.push_back(i &= b);\n  return res;\n};\n\n// enumerate\
    \ x : x \\in {n} and x \\superset b\nvector<int> enumerate_superset(int b, int\
    \ n) {\n  vector<int> res;\n  for (int i = b; i < (1 << n); i = (i + 1) | b) res.push_back(i);\n\
    \  return res;\n}\n\n/**\n * @brief \u4E0B\u4F4D\u96C6\u5408/\u4E0A\u4F4D\u96C6\
    \u5408\u306E\u5217\u6319\n */\n"
  code: "#pragma once\n\n\n\n// enumerate x : x \\subset b\nvector<int> enumerate_subset(int\
    \ b) {\n  vector<int> res;\n  for (int i = b; i >= 0; --i) res.push_back(i &=\
    \ b);\n  return res;\n};\n\n// enumerate x : x \\in {n} and x \\superset b\nvector<int>\
    \ enumerate_superset(int b, int n) {\n  vector<int> res;\n  for (int i = b; i\
    \ < (1 << n); i = (i + 1) | b) res.push_back(i);\n  return res;\n}\n\n/**\n *\
    \ @brief \u4E0B\u4F4D\u96C6\u5408/\u4E0A\u4F4D\u96C6\u5408\u306E\u5217\u6319\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: set-function/enumerate-set.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-itp/aoj-itp2-11-b.test.cpp
  - verify/verify-aoj-itp/aoj-itp2-11-c.test.cpp
documentation_of: set-function/enumerate-set.hpp
layout: document
redirect_from:
- /library/set-function/enumerate-set.hpp
- /library/set-function/enumerate-set.hpp.html
title: "\u4E0B\u4F4D\u96C6\u5408/\u4E0A\u4F4D\u96C6\u5408\u306E\u5217\u6319"
---
