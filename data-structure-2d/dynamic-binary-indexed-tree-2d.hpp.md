---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: dynamic-binary-indexed-tree.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"dynamic-binary-indexed-tree.hpp\"\n\ntemplate <typename T>\nstruct DynamicFenwickTree2D\
    \ {\n  using BIT = DynamicFenwickTree<int, T>;\n  int N, M;\n  vector<BIT*> bit;\n\
    \  DynamicFenwickTree2D() = default;\n  DynamicFenwickTree2D(int n, int m) : N(n\
    \ + 1), M(m) {\n    for (int _ = 0; _ < N; ++_) bit.push_back(new BIT(M));\n \
    \ }\n  \n  void add(int i, int j, const T& x) {\n    for (++i; i < N; i += i &\
    \ -i) (*bit[i]).add(j, x);\n  }\n\n  // i = [0, n), j = [0, m)\n  T sum(int n,\
    \ int m) const {\n    if (n < 0 || m < 0) return T();\n    T ret = T();\n    for\
    \ (; n; n -= n & -n) ret += (*bit[n]).sum(m);\n    return ret;\n  }\n\n  // i\
    \ = [nl, nr), j = [ml, mr)\n  T sum(int nl, int ml, int nr, int mr) const {\n\
    \    T ret = T();\n    while (nl != nr) {\n      if (nl < nr) {\n        ret +=\
    \ (*bit[nr]).sum(ml, mr);\n        nr -= nr & -nr;\n      } else {\n        ret\
    \ -= (*bit[nl]).sum(ml, mr);\n        nl -= nl & -nl;\n      }\n    }\n    return\
    \ ret;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure-2d/dynamic-binary-indexed-tree-2d.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure-2d/dynamic-binary-indexed-tree-2d.hpp
layout: document
redirect_from:
- /library/data-structure-2d/dynamic-binary-indexed-tree-2d.hpp
- /library/data-structure-2d/dynamic-binary-indexed-tree-2d.hpp.html
title: data-structure-2d/dynamic-binary-indexed-tree-2d.hpp
---
