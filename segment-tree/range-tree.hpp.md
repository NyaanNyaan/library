---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"segment-tree/range-tree.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// DS ... pointer ?\n// T ... value_type\ntemplate <typename\
    \ DS, typename T>\nstruct SegmentTree2D {\n  using NEW = function<DS(void)>;\n\
    \  using ADD = function<void(DS&, int, const T&)>;\n  using SUM = function<T(DS&,\
    \ int, int)>;\n\n  int N, M;\n  const NEW ds_new;\n  const ADD ds_add;\n  const\
    \ SUM ds_sum;\n  vector<DS> dat;\n  SegmentTree2D(int n, int m, const NEW& nw,\
    \ const ADD& ad, const SUM& sm)\n      : N(n), M(m), ds_new(nw), ds_add(ad), ds_sum(sm)\
    \ {\n    for (int i = 0; i < N; i++) dat.push_back(ds_new);\n  }\n\n  void add(int\
    \ i,const T& x) {\n    \n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// DS ...\
    \ pointer ?\n// T ... value_type\ntemplate <typename DS, typename T>\nstruct SegmentTree2D\
    \ {\n  using NEW = function<DS(void)>;\n  using ADD = function<void(DS&, int,\
    \ const T&)>;\n  using SUM = function<T(DS&, int, int)>;\n\n  int N, M;\n  const\
    \ NEW ds_new;\n  const ADD ds_add;\n  const SUM ds_sum;\n  vector<DS> dat;\n \
    \ SegmentTree2D(int n, int m, const NEW& nw, const ADD& ad, const SUM& sm)\n \
    \     : N(n), M(m), ds_new(nw), ds_add(ad), ds_sum(sm) {\n    for (int i = 0;\
    \ i < N; i++) dat.push_back(ds_new);\n  }\n\n  void add(int i,const T& x) {\n\
    \    \n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/range-tree.hpp
  requiredBy: []
  timestamp: '2020-09-26 23:59:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment-tree/range-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/range-tree.hpp
- /library/segment-tree/range-tree.hpp.html
title: segment-tree/range-tree.hpp
---
