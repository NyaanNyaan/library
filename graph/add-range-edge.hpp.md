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
  bundledCode: "#line 2 \"graph/add-range-edge.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// do not forget setting graph_size !!\nstruct RangeEdges\
    \ {\n  int N, idx;\n\n private:\n  int graph_size_;\n\n public:\n  RangeEdges(int\
    \ n, int q) {\n    N = 1;\n    while (N < n) N *= 2;\n    graph_size_ = N * 3\
    \ + q * __builtin_ctz(N) + 10;\n    idx = 3 * N;\n  };\n\n  int graph_size() const\
    \ { return graph_size_; }\n\n  template <typename F>\n  void build(const F& add_edge)\
    \ {\n    for (int i = 0; i < N; i++) {\n      if (i) {\n        add_edge(N + i,\
    \ N + (i >> 1) + 0);\n        add_edge(N + i, N + (i >> 1) + 1);\n        add_edge((N\
    \ << 1) + (i >> 1) + 0, (N << 1) + i);\n        add_edge((N << 1) + (i >> 1) +\
    \ 1, (N << 1) + i);\n      }\n      add_edge(i + N, i);\n      add_edge(i, i +\
    \ (N << 1));\n    }\n  }\n\n  // from [fl, fr) to [to, tr)\n  template <typename\
    \ F>\n  void range_add(const F& add_edge, int fl, int fr, int tl, int tr) {\n\
    \    int fn = idx++;\n    int tn = idx++;\n    add_edge(tn, fn);\n    for (fl\
    \ += N, fr += N; fl < fr; fl >>= 1, fr >>= 1) {\n      if (fl & 1) add_edge(fn,\
    \ N + (fl++));\n      if (fr & 1) add_edge(fn, N + (--fr));\n    }\n    for (tl\
    \ += N, tr += N; tl < tr; tl >>= 1, tr >>= 1) {\n      if (tl & 1) add_edge((tl++)\
    \ + (N << 1), tn);\n      if (tr & 1) add_edge((--tr) + (N << 1), tn);\n    }\n\
    \  }\n\n  // from [fl, fr) to [to, tr)\n  template <typename C, typename F>\n\
    \  void weighted_range_add(const F& add_edge, int fl, int fr, int tl, int tr,\n\
    \                          C cost) {\n    int fn = idx++;\n    int tn = idx++;\n\
    \    add_edge(tn, fn, cost);\n    for (fl += N, fr += N; fl < fr; fl >>= 1, fr\
    \ >>= 1) {\n      if (fl & 1) add_edge(fn, N + (fl++), C(0));\n      if (fr &\
    \ 1) add_edge(fn, N + (--fr), C(0));\n    }\n    for (tl += N, tr += N; tl < tr;\
    \ tl >>= 1, tr >>= 1) {\n      if (tl & 1) add_edge((tl++) + (N << 1), tn, C(0));\n\
    \      if (tr & 1) add_edge((--tr) + (N << 1), tn, C(0));\n    }\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// do not\
    \ forget setting graph_size !!\nstruct RangeEdges {\n  int N, idx;\n\n private:\n\
    \  int graph_size_;\n\n public:\n  RangeEdges(int n, int q) {\n    N = 1;\n  \
    \  while (N < n) N *= 2;\n    graph_size_ = N * 3 + q * __builtin_ctz(N) + 10;\n\
    \    idx = 3 * N;\n  };\n\n  int graph_size() const { return graph_size_; }\n\n\
    \  template <typename F>\n  void build(const F& add_edge) {\n    for (int i =\
    \ 0; i < N; i++) {\n      if (i) {\n        add_edge(N + i, N + (i >> 1) + 0);\n\
    \        add_edge(N + i, N + (i >> 1) + 1);\n        add_edge((N << 1) + (i >>\
    \ 1) + 0, (N << 1) + i);\n        add_edge((N << 1) + (i >> 1) + 1, (N << 1) +\
    \ i);\n      }\n      add_edge(i + N, i);\n      add_edge(i, i + (N << 1));\n\
    \    }\n  }\n\n  // from [fl, fr) to [to, tr)\n  template <typename F>\n  void\
    \ range_add(const F& add_edge, int fl, int fr, int tl, int tr) {\n    int fn =\
    \ idx++;\n    int tn = idx++;\n    add_edge(tn, fn);\n    for (fl += N, fr +=\
    \ N; fl < fr; fl >>= 1, fr >>= 1) {\n      if (fl & 1) add_edge(fn, N + (fl++));\n\
    \      if (fr & 1) add_edge(fn, N + (--fr));\n    }\n    for (tl += N, tr += N;\
    \ tl < tr; tl >>= 1, tr >>= 1) {\n      if (tl & 1) add_edge((tl++) + (N << 1),\
    \ tn);\n      if (tr & 1) add_edge((--tr) + (N << 1), tn);\n    }\n  }\n\n  //\
    \ from [fl, fr) to [to, tr)\n  template <typename C, typename F>\n  void weighted_range_add(const\
    \ F& add_edge, int fl, int fr, int tl, int tr,\n                          C cost)\
    \ {\n    int fn = idx++;\n    int tn = idx++;\n    add_edge(tn, fn, cost);\n \
    \   for (fl += N, fr += N; fl < fr; fl >>= 1, fr >>= 1) {\n      if (fl & 1) add_edge(fn,\
    \ N + (fl++), C(0));\n      if (fr & 1) add_edge(fn, N + (--fr), C(0));\n    }\n\
    \    for (tl += N, tr += N; tl < tr; tl >>= 1, tr >>= 1) {\n      if (tl & 1)\
    \ add_edge((tl++) + (N << 1), tn, C(0));\n      if (tr & 1) add_edge((--tr) +\
    \ (N << 1), tn, C(0));\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/add-range-edge.hpp
  requiredBy: []
  timestamp: '2020-08-15 17:28:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/add-range-edge.hpp
layout: document
redirect_from:
- /library/graph/add-range-edge.hpp
- /library/graph/add-range-edge.hpp.html
title: graph/add-range-edge.hpp
---
