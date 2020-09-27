---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: dynamic-binary-indexed-tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../../competitive-template.hpp\"\n#include \"../../data-structure/hash-map-variable-length.hpp\"\
    \n#include \"../../data-structure-2d/dynamic-binary-indexed-tree-2d.hpp\"\n#include\
    \ \"../../misc/compress.hpp\"\n#include \"../../misc/fastio.hpp\"\n\nvoid solve()\
    \ {\n  int N, Q;\n  rd(N, Q);\n  vector<int> X(N), Y(N), W(N), c(Q), s(Q), t(Q),\
    \ u(Q), v(Q);\n  rep(i, N) rd(X[i], Y[i], W[i]);\n  rep(i, Q) {\n    rd(c[i],\
    \ s[i], t[i], u[i]);\n    if (c[i]) rd(v[i]);\n  }\n\n  vi xs{-1, inf}, ys{-1,\
    \ inf};\n  each(x, X) xs.push_back(x);\n  each(y, Y) ys.push_back(y);\n  rep(i,\
    \ Q) {\n    if (!c[i]) {\n      xs.push_back(s[i]);\n      ys.push_back(t[i]);\n\
    \    }\n  }\n\n  auto zipx = compress<int>(xs);\n  auto zipy = compress<int>(ys);\n\
    \n  DynamicFenwickTree2D<ll> seg(zipx.size(), zipy.size());\n  rep(i, N) seg.add(zipx.get(X[i]),\
    \ zipy.get(Y[i]), W[i]);\n\n  rep(i, Q) {\n    if (c[i]) {\n      int nl = zipx.get(s[i]);\n\
    \      int ml = zipy.get(t[i]);\n      int nr = zipx.get(u[i]);\n      int mr\
    \ = zipy.get(v[i]);\n      out(seg.sum(nl, ml, nr, mr));\n    } else\n      seg.add(zipx.get(s[i]),\
    \ zipy.get(t[i]), u[i]);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-bit2d.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-bit2d.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-bit2d.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-bit2d.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-bit2d.test.cpp
---
