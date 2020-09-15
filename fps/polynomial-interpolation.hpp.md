---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: fps/multipoint-evaluation.hpp
    title: fps/multipoint-evaluation.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-interpolation.test.cpp
    title: verify/verify-yosupo-fps/yosupo-interpolation.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ fps/polynomial-interpolation.hpp: line 2: #pragma once found in a non-first\
    \ line\n"
  code: "\n#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"./formal-power-series.hpp\"\n#include \"./multipoint-evaluation.hpp\"\n\n\
    template <class mint>\nFormalPowerSeries<mint> PolynomialInterpolation(const vector<mint>\
    \ &xs,\n                                                const vector<mint> &ys)\
    \ {\n  using fps = FormalPowerSeries<mint>;\n  assert(xs.size() == ys.size());\n\
    \  ProductTree<mint> ptree(xs);\n  fps w = ptree.buf[1].diff();\n  vector<mint>\
    \ vs = InnerMultipointEvaluation<mint>(w, xs, ptree);\n  auto rec = [&](auto self,\
    \ int idx) -> fps {\n    if (idx >= ptree.N) {\n      if (idx - ptree.N < (int)xs.size())\n\
    \        return {ys[idx - ptree.N] / vs[idx - ptree.N]};\n      else\n       \
    \ return {mint(1)};\n    }\n    if (ptree.buf[idx << 1 | 0].empty())\n      return\
    \ {};\n    else if (ptree.buf[idx << 1 | 1].empty())\n      return self(self,\
    \ idx << 1 | 0);\n    return self(self, idx << 1 | 0) * ptree.buf[idx << 1 | 1]\
    \ +\n           self(self, idx << 1 | 1) * ptree.buf[idx << 1 | 0];\n  };\n  return\
    \ rec(rec, 1);\n}\n"
  dependsOn:
  - fps/formal-power-series.hpp
  - fps/multipoint-evaluation.hpp
  isVerificationFile: false
  path: fps/polynomial-interpolation.hpp
  requiredBy: []
  timestamp: '2020-08-31 22:48:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-interpolation.test.cpp
documentation_of: fps/polynomial-interpolation.hpp
layout: document
redirect_from:
- /library/fps/polynomial-interpolation.hpp
- /library/fps/polynomial-interpolation.hpp.html
title: fps/polynomial-interpolation.hpp
---
