---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/process-of-merging-tree.hpp\"\n\n// \u30DE\u30FC\u30B8\
    \u904E\u7A0B\u3092\u8868\u3059\u6728\n// es \u306E\u6607\u9806\u306B\u6728\u3092\
    \u30DE\u30FC\u30B8\u3057\u3066\u3044\u304F\u3002(es \u306B\u306F\u30DE\u30FC\u30B8\
    \u306B\u4F7F\u308F\u306A\u3044\u8FBA\u304C\u5165\u3063\u3066\u3044\u3066\u3088\
    \u3044)\n//\n// \u8FD4\u308A\u5024 : (graph, \u88DC\u52A9\u7684\u306A\u9802\u70B9\
    \u306B\u5BFE\u5FDC\u3059\u308B\u8FBA\u306E\u91CD\u307F, root)\ntemplate <typename\
    \ T>\ntuple<WeightedGraph<T>, vector<T>, int> process_of_merging_tree(\n    const\
    \ Edges<T>& es) {\n  int n = 1;\n  for (auto& e : es) n = max(n, max(e.src, e.to)\
    \ + 1);\n \n  WeightedGraph<T> g(n * 2 - 1);\n  vector<T> nodes(n - 1);\n \n \
    \ UnionFind uf(n);\n  vector<int> roots(n);\n  iota(begin(roots), end(roots),\
    \ 0);\n  int aux = n;\n \n  for (auto& e : es) {\n    int u = e.src, v = e.to;\n\
    \    if (uf.same(u, v)) continue;\n    T w = e.cost;\n    auto f = [&](int x,\
    \ int y) {\n      g[aux].emplace_back(aux, roots[x], w);\n      g[aux].emplace_back(aux,\
    \ roots[y], w);\n      roots[x] = roots[y] = aux;\n    };\n    uf.unite(u, v,\
    \ f);\n    nodes[aux - n] = w;\n    aux++;\n  }\n  assert(aux == 2 * n - 1);\n\
    \ \n  return {g, nodes, 2 * n - 2};\n}\n"
  code: "#pragma once\n\n// \u30DE\u30FC\u30B8\u904E\u7A0B\u3092\u8868\u3059\u6728\
    \n// es \u306E\u6607\u9806\u306B\u6728\u3092\u30DE\u30FC\u30B8\u3057\u3066\u3044\
    \u304F\u3002(es \u306B\u306F\u30DE\u30FC\u30B8\u306B\u4F7F\u308F\u306A\u3044\u8FBA\
    \u304C\u5165\u3063\u3066\u3044\u3066\u3088\u3044)\n//\n// \u8FD4\u308A\u5024 :\
    \ (graph, \u88DC\u52A9\u7684\u306A\u9802\u70B9\u306B\u5BFE\u5FDC\u3059\u308B\u8FBA\
    \u306E\u91CD\u307F, root)\ntemplate <typename T>\ntuple<WeightedGraph<T>, vector<T>,\
    \ int> process_of_merging_tree(\n    const Edges<T>& es) {\n  int n = 1;\n  for\
    \ (auto& e : es) n = max(n, max(e.src, e.to) + 1);\n \n  WeightedGraph<T> g(n\
    \ * 2 - 1);\n  vector<T> nodes(n - 1);\n \n  UnionFind uf(n);\n  vector<int> roots(n);\n\
    \  iota(begin(roots), end(roots), 0);\n  int aux = n;\n \n  for (auto& e : es)\
    \ {\n    int u = e.src, v = e.to;\n    if (uf.same(u, v)) continue;\n    T w =\
    \ e.cost;\n    auto f = [&](int x, int y) {\n      g[aux].emplace_back(aux, roots[x],\
    \ w);\n      g[aux].emplace_back(aux, roots[y], w);\n      roots[x] = roots[y]\
    \ = aux;\n    };\n    uf.unite(u, v, f);\n    nodes[aux - n] = w;\n    aux++;\n\
    \  }\n  assert(aux == 2 * n - 1);\n \n  return {g, nodes, 2 * n - 2};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/process-of-merging-tree.hpp
  requiredBy: []
  timestamp: '2022-08-22 19:46:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/process-of-merging-tree.hpp
layout: document
redirect_from:
- /library/tree/process-of-merging-tree.hpp
- /library/tree/process-of-merging-tree.hpp.html
title: tree/process-of-merging-tree.hpp
---
