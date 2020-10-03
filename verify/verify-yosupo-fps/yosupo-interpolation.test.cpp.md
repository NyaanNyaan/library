---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: fps/multipoint-evaluation.hpp
    title: fps/multipoint-evaluation.hpp
  - icon: ':heavy_check_mark:'
    path: fps/ntt-friendly-fps.hpp
    title: "NTT mod\u7528FPS\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: fps/polynomial-interpolation.hpp
    title: fps/polynomial-interpolation.hpp
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: modint/simd-montgomery.hpp
    title: modint/simd-montgomery.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/ntt-avx2.hpp
    title: ntt/ntt-avx2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/polynomial_interpolation
    links:
    - https://judge.yosupo.jp/problem/polynomial_interpolation
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ fps/polynomial-interpolation.hpp: line 2: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/polynomial_interpolation\"\
    \n\n#include \"../../competitive-template.hpp\"\n#include \"../../fps/multipoint-evaluation.hpp\"\
    \n#include \"../../fps/ntt-friendly-fps.hpp\"\n#include \"../../modint/montgomery-modint.hpp\"\
    \n#include \"../../fps/polynomial-interpolation.hpp\"\n\nvoid solve() {\n  using\
    \ mint = LazyMontgomeryModInt<998244353>;\n  using fps = FormalPowerSeries<mint>;\n\
    \  int N;\n  cin >> N;\n  fps xs(N), ys(N);\n  cin >> xs >> ys;\n  cout << PolynomialInterpolation<mint>(xs,\
    \ ys) << endl;\n}"
  dependsOn:
  - competitive-template.hpp
  - fps/multipoint-evaluation.hpp
  - fps/formal-power-series.hpp
  - fps/ntt-friendly-fps.hpp
  - ntt/ntt-avx2.hpp
  - modint/simd-montgomery.hpp
  - modint/montgomery-modint.hpp
  - fps/polynomial-interpolation.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-fps/yosupo-interpolation.test.cpp
  requiredBy: []
  timestamp: '2020-09-07 01:48:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-fps/yosupo-interpolation.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-fps/yosupo-interpolation.test.cpp
- /verify/verify/verify-yosupo-fps/yosupo-interpolation.test.cpp.html
title: verify/verify-yosupo-fps/yosupo-interpolation.test.cpp
---
