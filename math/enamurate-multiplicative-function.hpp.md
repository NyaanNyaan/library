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
  bundledCode: "#line 2 \"math/enamurate-multiplicative-function.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// f(n, p, c) : n = pow(p, c), f is multiplicative function\n\
    template <typename mint, typename F>\nvector<mint> enamurate_multiplicative_function(const\
    \ F& func, int n) {\n  assert(n < (1LL << 30));\n  vector<mint> f(n + 1, mint(0));\n\
    \  if (!p) {\n    f[0] = 1;\n    return std::move(f);\n  }\n  f[1] = 1;\n  vector<bool>\
    \ sieve(n + 1, false);\n  vector<int> ps;\n  for (int i = 2; i <= n; i++) {\n\
    \    if (!sieve[i]) {\n      f[i] = func(i, i, 1);\n      ps.push_back(i);\n \
    \   }\n    for (int j = 0; j < (int)ps.size() && i * ps[j] <= n; j++) {\n    \
    \  sieve[i * ps[j]] = 1;\n      if (i % ps[j] == 0) {\n        int c = 0, x =\
    \ i, y = 1;\n        while (x % ps[j] == 0) x /= ps[j], y *= ps[j], ++c;\n   \
    \     if (x == 1)\n          f[i * ps[j]] = func(i * ps[j], i, c + 1);\n     \
    \   else\n          f[i * ps[j]] = f[x] * f[y];\n        break;\n      } else\n\
    \        f[i * ps[j]] = f[i] * f[ps[j]];\n    }\n  }\n  return std::move(f);\n\
    }\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// f(n, p,\
    \ c) : n = pow(p, c), f is multiplicative function\ntemplate <typename mint, typename\
    \ F>\nvector<mint> enamurate_multiplicative_function(const F& func, int n) {\n\
    \  assert(n < (1LL << 30));\n  vector<mint> f(n + 1, mint(0));\n  if (!p) {\n\
    \    f[0] = 1;\n    return std::move(f);\n  }\n  f[1] = 1;\n  vector<bool> sieve(n\
    \ + 1, false);\n  vector<int> ps;\n  for (int i = 2; i <= n; i++) {\n    if (!sieve[i])\
    \ {\n      f[i] = func(i, i, 1);\n      ps.push_back(i);\n    }\n    for (int\
    \ j = 0; j < (int)ps.size() && i * ps[j] <= n; j++) {\n      sieve[i * ps[j]]\
    \ = 1;\n      if (i % ps[j] == 0) {\n        int c = 0, x = i, y = 1;\n      \
    \  while (x % ps[j] == 0) x /= ps[j], y *= ps[j], ++c;\n        if (x == 1)\n\
    \          f[i * ps[j]] = func(i * ps[j], i, c + 1);\n        else\n         \
    \ f[i * ps[j]] = f[x] * f[y];\n        break;\n      } else\n        f[i * ps[j]]\
    \ = f[i] * f[ps[j]];\n    }\n  }\n  return std::move(f);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/enamurate-multiplicative-function.hpp
  requiredBy: []
  timestamp: '2020-08-31 22:48:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/enamurate-multiplicative-function.hpp
layout: document
redirect_from:
- /library/math/enamurate-multiplicative-function.hpp
- /library/math/enamurate-multiplicative-function.hpp.html
title: math/enamurate-multiplicative-function.hpp
---
