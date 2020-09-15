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
  bundledCode: "#line 1 \"math/prime-counting-faster.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nnamespace PrimeCounting {\nusing i64 = long long;\nstatic\
    \ inline i64 my_div(i64 n, i64 p) { return double(n) / p; };\n\n__attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) i64\nprime_counting(i64 N) {\n \
    \ i64 N2 = sqrt(N);\n  i64 NdN2 = my_div(N, N2);\n\n  vector<i64> hl(NdN2);\n\
    \  for (int i = 1; i < NdN2; i++) hl[i] = my_div(N, i) - 1;\n\n  vector<int> hs(N2\
    \ + 1);\n  iota(begin(hs), end(hs), -1);\n\n  for (int x = 2, pi = 0; x <= N2;\
    \ ++x) {\n    if (hs[x] == hs[x - 1]) continue;\n    i64 x2 = i64(x) * x;\n  \
    \  i64 imax = min<i64>(NdN2, my_div(N, x2) + 1);\n    i64 ix = x;\n    for (i64\
    \ i = 1; i < imax; ++i) {\n      hl[i] -= (ix < NdN2 ? hl[ix] : hs[my_div(N, ix)])\
    \ - pi;\n      ix += x;\n    }\n    for (int n = N2; n >= x2; n--) {\n      hs[n]\
    \ -= hs[my_div(n, x)] - pi;\n    }\n    ++pi;\n  }\n  return hl[1];\n}\n\n}  //\
    \ namespace PrimeCounting\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nnamespace PrimeCounting\
    \ {\nusing i64 = long long;\nstatic inline i64 my_div(i64 n, i64 p) { return double(n)\
    \ / p; };\n\n__attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"\
    ))) i64\nprime_counting(i64 N) {\n  i64 N2 = sqrt(N);\n  i64 NdN2 = my_div(N,\
    \ N2);\n\n  vector<i64> hl(NdN2);\n  for (int i = 1; i < NdN2; i++) hl[i] = my_div(N,\
    \ i) - 1;\n\n  vector<int> hs(N2 + 1);\n  iota(begin(hs), end(hs), -1);\n\n  for\
    \ (int x = 2, pi = 0; x <= N2; ++x) {\n    if (hs[x] == hs[x - 1]) continue;\n\
    \    i64 x2 = i64(x) * x;\n    i64 imax = min<i64>(NdN2, my_div(N, x2) + 1);\n\
    \    i64 ix = x;\n    for (i64 i = 1; i < imax; ++i) {\n      hl[i] -= (ix < NdN2\
    \ ? hl[ix] : hs[my_div(N, ix)]) - pi;\n      ix += x;\n    }\n    for (int n =\
    \ N2; n >= x2; n--) {\n      hs[n] -= hs[my_div(n, x)] - pi;\n    }\n    ++pi;\n\
    \  }\n  return hl[1];\n}\n\n}  // namespace PrimeCounting"
  dependsOn: []
  isVerificationFile: false
  path: math/prime-counting-faster.hpp
  requiredBy: []
  timestamp: '2020-08-19 23:44:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime-counting-faster.hpp
layout: document
redirect_from:
- /library/math/prime-counting-faster.hpp
- /library/math/prime-counting-faster.hpp.html
title: math/prime-counting-faster.hpp
---
