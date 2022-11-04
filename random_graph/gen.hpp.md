---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: random_graph/graph.hpp
    title: random_graph/graph.hpp
  - icon: ':warning:'
    path: random_graph/random.hpp
    title: random_graph/random.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ random_graph/random.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <array>\n#include <cassert>\n\
    #include <chrono>\n#include <cstdint>\n#include <functional>\n#include <iostream>\n\
    #include <numeric>\n#include <random>\n#include <set>\n#include <vector>\n\n#include\
    \ \"graph.hpp\"\n#include \"random.hpp\"\n\n// \u30B8\u30A7\u30CD\u30EC\u30FC\u30BF\
    \u672C\u4F53\nstruct UndirectedGraphGenerator {\n private:\n  // \u4E71\u6570\u751F\
    \u6210\u5668 (static\u30E1\u30F3\u30D0\u5909\u6570\u306E\u4EE3\u308F\u308A)\n\
    \  Random& _gen() {\n    static Random gen{};\n    return gen;\n  }\n  // [l,\
    \ r]\u4E0A\u306E\u4E00\u69D8\u4E71\u6570\u3092\u751F\u6210\n  long long random(long\
    \ long l, long long r) {\n    assert(l <= r && \"UndirectedGraphGenerator::random(l,\
    \ r)\");\n    return _gen().uniform(l, r);\n  }\n  // v\u3092\u30E9\u30F3\u30C0\
    \u30E0\u306B\u30B7\u30E3\u30C3\u30D5\u30EB\n  template <typename U>\n  void random_shuffle(vector<U>&\
    \ v) {\n    _gen().shuffle(begin(v), end(v));\n  }\n\n  W _w_min, _w_max;\n\n\
    \  // \u8FBA\u306E\u91CD\u307F\u3092\u8A2D\u5B9A\n  void set_weight(bool weighted,\
    \ W w_min, W w_max) {\n    _w_min = w_min, _w_max = w_max;\n    if (!weighted)\
    \ _w_min = _w_max = 1;\n  }\n\n  // \u8FBA\u3092\u8FFD\u52A0\n  void add_edge(Graph&\
    \ g, int i, int j) {\n    W w = _w_min == _w_max ? _w_min : random(_w_min, _w_max);\n\
    \    g.add_undirected_edge(i, j, w);\n  }\n\n  // \u4E71\u6570\u751F\u6210s\n\
    \  unsigned long long random_seed() const {\n    unsigned long long seed =\n \
    \       chrono::duration_cast<chrono::nanoseconds>(\n            chrono::high_resolution_clock::now().time_since_epoch())\n\
    \            .count();\n    return seed;\n  }\n\n public:\n  UndirectedGraphGenerator(unsigned\
    \ long long seed = 0) : _w_min(1), _w_max(1) {\n    if (seed == 0) seed = random_seed();\n\
    \    set_seed(seed);\n  }\n\n  // \u30B7\u30FC\u30C9\u3092\u8A2D\u5B9A\u3059\u308B\
    \n  void set_seed(unsigned long long seed) { _gen() = Random{seed ^ 1333uLL};\
    \ }\n\n  /**\n   * \u30E9\u30F3\u30C0\u30E0\u30B1\u30FC\u30B9\u751F\u6210\u7528\
    \u3002\n   *  \u6761\u4EF6\u3092\u6E80\u305F\u3059\u5168\u3066\u306E\u95A2\u6570\
    \u306E\u4E2D\u304B\u3089\u30E9\u30F3\u30C0\u30E0\u306B1\u3064\u3092\u9078\u3093\
    \u3067\u30B0\u30E9\u30D5\u3092\u751F\u6210\u3002\n   */\n  Graph test(int n, bool\
    \ is_tree = true, bool weighted = false, W w_min = 1,\n             W w_max =\
    \ 1) {\n    using F = Graph (UndirectedGraphGenerator::*)(int, bool, W, W);\n\
    \    vector<F> f{tree, path, star, perfect, simple, namori, simple_sparse};\n\
    \    int mx = is_tree ? 2 : 6;\n    return (this->*f[random(0, mx)])(n, weighted,\
    \ w_min, w_max);\n  }\n\n  // \u30E9\u30F3\u30C0\u30E0\u306A\u7121\u5411\u306E\
    \u6728\u3092\u51FA\u529B\n  Graph tree(int n, bool weighted = false, W w_min =\
    \ 1, W w_max = 1) {\n    set_weight(weighted, w_min, w_max);\n    Graph g(n, weighted);\n\
    \    if (n == 2) add_edge(g, 0, 1);\n    if (n <= 2) return g;\n    vector<int>\
    \ code(n - 2), deg(n, 1);\n    for (auto& i : code) i = random(0, n - 1), deg[i]++;\n\
    \    set<int> js;\n    for (int j = 0; j < n; j++) {\n      if (deg[j] == 1) js.insert(j);\n\
    \    }\n    for (auto& i : code) {\n      int j = *js.begin();\n      add_edge(g,\
    \ i, j);\n      js.erase(begin(js));\n      if (--deg[i] == 1) js.insert(i);\n\
    \      deg[j]--;\n    }\n    int u = *js.begin(), v = *next(js.begin());\n   \
    \ add_edge(g, u, v);\n    assert(g.edges_size() == n - 1);\n    return g;\n  }\n\
    \n  // \u30E9\u30F3\u30C0\u30E0\u306A\u7121\u5411\u306E\u30D1\u30B9\u30B0\u30E9\
    \u30D5\u3092\u51FA\u529B\n  Graph path(int n, bool weighted = false, W w_min =\
    \ 1, W w_max = 1) {\n    set_weight(weighted, w_min, w_max);\n    vector<int>\
    \ ord(n);\n    iota(begin(ord), end(ord), 0);\n    random_shuffle(ord);\n    Graph\
    \ g(n, weighted);\n    for (int i = 0; i < n - 1; i++) add_edge(g, ord[i], ord[i\
    \ + 1]);\n    return g;\n  }\n\n  // \u30E9\u30F3\u30C0\u30E0\u306A\u7121\u5411\
    \u306E\u30B9\u30BF\u30FC\u30B0\u30E9\u30D5\u3092\u51FA\u529B\n  Graph star(int\
    \ n, bool weighted = false, W w_min = 1, W w_max = 1) {\n    set_weight(weighted,\
    \ w_min, w_max);\n    vector<int> ord(n);\n    iota(begin(ord), end(ord), 0);\n\
    \    random_shuffle(ord);\n    Graph g(n, weighted);\n    for (int i = 1; i <\
    \ n; i++) add_edge(g, ord[0], ord[i]);\n    return g;\n  }\n\n  // \u5B8C\u5168\
    \u30B0\u30E9\u30D5\n  Graph perfect(int n, bool weighted = false, W w_min = 1,\
    \ W w_max = 1) {\n    set_weight(weighted, w_min, w_max);\n    Graph g(n, weighted);\n\
    \    for (int i = 0; i < n; i++) {\n      for (int j = i + 1; j < n; j++) add_edge(g,\
    \ i, j);\n    }\n    return g;\n  }\n\n  // \u5358\u7D14\u30B0\u30E9\u30D5\n \
    \ Graph simple(int n, bool weighted = false, W w_min = 1, W w_max = 1) {\n   \
    \ set_weight(weighted, w_min, w_max);\n    Graph g(n, weighted);\n    for (int\
    \ i = 0; i < n; i++) {\n      for (int j = i + 1; j < n; j++) {\n        if (random(0,\
    \ 1) == 1) add_edge(g, i, j);\n      }\n    }\n    return g;\n  }\n\n  // \u306A\
    \u3082\u308A\u30B0\u30E9\u30D5\n  Graph namori(int n, bool weighted = false, W\
    \ w_min = 1, W w_max = 1) {\n    set_weight(weighted, w_min, w_max);\n    Graph\
    \ g(n, weighted);\n    for (int i = 0; i < n; i++) {\n      if (i == 0) {\n  \
    \      add_edge(g, i, random(1, n - 1));\n      } else {\n        add_edge(g,\
    \ i, random(0, i - 1));\n      }\n    }\n    return g;\n  }\n\n  // \u758E\u306A\
    \u5358\u7D14\u30B0\u30E9\u30D5\n  Graph simple_sparse(int n, bool weighted = false,\
    \ W w_min = 1, W w_max = 1) {\n    set_weight(weighted, w_min, w_max);\n    if\
    \ (n == 0) return Graph{};\n    int m = random(0, n - 1);\n    set<pair<int, int>>\
    \ es;\n    while ((int)es.size() < m) {\n      int i = random(0, n - 1);\n   \
    \   int j = random(0, n - 1);\n      if (i >= j) continue;\n      es.emplace(i,\
    \ j);\n    }\n    Graph g(n, weighted);\n    for (auto& [i, j] : es) add_edge(g,\
    \ i, j);\n    return g;\n  }\n} undirected;\n"
  dependsOn:
  - random_graph/graph.hpp
  - random_graph/random.hpp
  isVerificationFile: false
  path: random_graph/gen.hpp
  requiredBy: []
  timestamp: '2021-08-11 08:31:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random_graph/gen.hpp
layout: document
redirect_from:
- /library/random_graph/gen.hpp
- /library/random_graph/gen.hpp.html
title: random_graph/gen.hpp
---
