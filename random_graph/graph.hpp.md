---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: random_graph/random.hpp
    title: random_graph/random.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: random_graph/gen.hpp
    title: random_graph/gen.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ random_graph/random.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <array>\n#include <cassert>\n\
    #include <cstdint>\n#include <functional>\n#include <iostream>\n#include <numeric>\n\
    #include <random>\n#include <set>\n#include <vector>\n\n#include \"random.hpp\"\
    \n\nusing namespace std;\n\n// \u8FBA\u306E\u91CD\u307F\u306Flong long\u6C7A\u3081\
    \u6253\u3061\nusing W = long long;\n\n// \u8FBA\u306E\u60C5\u5831\u3092\u683C\u7D0D\
    \u3059\u308B\u69CB\u9020\u4F53\nstruct Edge {\n  int u, v;\n  W w;\n  int idx;\n\
    \  Edge(int _u, int _v, W _w = 1, int _idx = -1)\n      : u(_u), v(_v), w(_w),\
    \ idx(_idx) {}\n};\n\n// \u30B0\u30E9\u30D5\u306E\u60C5\u5831\u3092\u683C\u7D0D\
    \u3059\u308B\u69CB\u9020\u4F53\nstruct Graph {\n private:\n  int n, m;\n  vector<Edge>\
    \ es;\n  bool weighted;\n\n public:\n  Graph(int _n = 0, bool _weighted = false)\n\
    \      : n(_n), m(0), weighted(_weighted) {}\n\n  int edges_size() const { return\
    \ m; }\n\n  // u -> v, \u91CD\u307F w \u306E\u8FBA\u3092\u8FFD\u52A0\n  // 0-indexed\
    \ \u3067\u8FFD\u52A0\u3059\u308B\u5FC5\u8981\u3042\u308A\n  void add_directed_edge(int\
    \ u, int v, W w = 1, int idx = -1) {\n    es.emplace_back(u, v, w, idx);\n   \
    \ m++;\n  }\n\n  // min(u,v) -> max(u,v), \u91CD\u307F w \u306E\u8FBA\u3092\u8FFD\
    \u52A0\n  // 0-indexed \u3067\u8FFD\u52A0\u3059\u308B\u5FC5\u8981\u3042\u308A\n\
    \  void add_undirected_edge(int u, int v, W w = 1, int idx = -1) {\n    int mn\
    \ = min(u, v), mx = max(u, v);\n    add_directed_edge(mn, mx, w, idx);\n  }\n\n\
    \  // \u96A3\u63A5\u30EA\u30B9\u30C8\u3092\u8FD4\u3059\n  vector<vector<Edge>>\
    \ adjacent_list(bool directed = false) const {\n    vector<vector<Edge>> g(n);\n\
    \    for (auto& [u, v, w, i] : es) {\n      g[u].emplace_back(u, v, w, i);\n \
    \     if (!directed) g[v].emplace_back(v, u, w, i);\n    }\n    return g;\n  }\n\
    \n  // \u96A3\u63A5\u884C\u5217\u3092\u8FD4\u3059\n  vector<vector<W>> adjacent_matrix(bool\
    \ directed = false) const {\n    vector<vector<W>> g(n, vector<W>(n, 0));\n  \
    \  for (auto& [u, v, w, _] : es) {\n      g[u][v] = w;\n      if (!directed) g[v][u]\
    \ = w;\n    }\n    return g;\n  }\n\n  // \u30B0\u30E9\u30D5\u3092\u96A3\u63A5\
    \u884C\u5217\u306E\u5F62\u5F0F\u3067\u51FA\u529B\n  void print_matrix(ostream&\
    \ os, bool directed = false) const {\n    auto g = adjacent_matrix(directed);\n\
    \    for (int i = 0; i < n; i++) {\n      for (int j = 0; j < n; j++) {\n    \
    \    os << g[i][j] << \" \\n\"[j == n - 1];\n      }\n    }\n  }\n\n  // \u30B0\
    \u30E9\u30D5\u306E\u8FBA\u60C5\u5831\u3092\u4E00\u822C\u7684\u306A\u5F62\u5F0F\
    \u3067\u51FA\u529B\n  void print_edge(ostream& os, bool origin_0 = false) const\
    \ {\n    for (auto& e : es) {\n      os << e.u + (origin_0 ? 0 : 1);\n      os\
    \ << \" \" << e.v + (origin_0 ? 0 : 1);\n      if (weighted) os << \" \" << e.w;\n\
    \      os << \"\\n\";\n    }\n  }\n\n  // \u30B0\u30E9\u30D5\u3092\u4E00\u822C\
    \u7684\u306A\u5F62\u5F0F\u3067\u51FA\u529B\n  void print(ostream& os, bool origin_0\
    \ = false) const {\n    os << n << \" \" << m << \"\\n\";\n    print_edge(os,\
    \ origin_0);\n  }\n\n  friend ostream& operator<<(ostream& os, const Graph& g)\
    \ {\n    g.print(os);\n    return os;\n  }\n};\n"
  dependsOn:
  - random_graph/random.hpp
  isVerificationFile: false
  path: random_graph/graph.hpp
  requiredBy:
  - random_graph/gen.hpp
  timestamp: '2021-08-11 08:31:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random_graph/graph.hpp
layout: document
redirect_from:
- /library/random_graph/graph.hpp
- /library/random_graph/graph.hpp.html
title: random_graph/graph.hpp
---
