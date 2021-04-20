---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: prime/factor-enumerate.hpp
    title: prime/factor-enumerate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/factorize.test.cpp
    title: verify/verify-unit-test/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/osak.test.cpp
    title: verify/verify-unit-test/osak.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"prime/osak.hpp\"\n\n#line 2 \"prime/factor-enumerate.hpp\"\
    \n\nvector<int> factor_enumerate(int N) {\n  vector<int> lp(N + 1, 0);\n  if (N\
    \ < 2) return lp;\n  vector<int> pr{2, 3};\n  for (int i = 2; i <= N; i += 2)\
    \ lp[i] = 2;\n  for (int i = 3; i <= N; i += 6) lp[i] = 3;\n  for (int i = 5,\
    \ d = 4; i <= N; i += d = 6 - d) {\n    if (lp[i] == 0) {\n      lp[i] = i;\n\
    \      pr.push_back(i);\n    }\n    for (int j = 2; j < (int)pr.size() && i *\
    \ pr[j] <= N; ++j) {\n      lp[i * pr[j]] = pr[j];\n      if (pr[j] == lp[i])\
    \ break;\n    }\n  }\n  return lp;\n}\n#line 4 \"prime/osak.hpp\"\n\ntemplate\
    \ <int MAX>\nvector<int> osak(int n) {\n  static vector<int> f = factor_enumerate(MAX);\n\
    \  vector<int> ret;\n  while (f[n]) ret.push_back(f[n]), n /= f[n];\n  return\
    \ ret;\n}\n\ntemplate <int MAX>\nvector<pair<int, int>> osak_table(int n) {\n\
    \  static vector<int> f = factor_enumerate(MAX);\n  vector<pair<int, int>> v;\n\
    \  for (; f[n]; n /= f[n]) {\n    if (v.empty() || v.back().first != f[n]) {\n\
    \      v.emplace_back(f[n], 1);\n    } else {\n      v.back().second++;\n    }\n\
    \  }\n  return v;\n}\n\ntemplate <int MAX>\nvector<int> osak_divisors(int n) {\n\
    \  if(n == 0) return {};\n  if(n == 1) return vector<int>(1, 1);\n  auto p = osak_table<MAX>(n);\n\
    \  vector<int> ds;\n\n  auto dfs = [&](auto r, int i, int c) {\n    if (i == (int)p.size())\
    \ {\n      ds.push_back(c);\n      return;\n    }\n    for (int j = 0; j <= p[i].second;\
    \ j++) {\n      r(r, i + 1, c);\n      c *= p[i].first;\n    }\n  };\n\n  dfs(dfs,\
    \ 0, 1);\n  sort(begin(ds), end(ds));\n  return ds;\n}\n"
  code: "#pragma once\n\n#include \"factor-enumerate.hpp\"\n\ntemplate <int MAX>\n\
    vector<int> osak(int n) {\n  static vector<int> f = factor_enumerate(MAX);\n \
    \ vector<int> ret;\n  while (f[n]) ret.push_back(f[n]), n /= f[n];\n  return ret;\n\
    }\n\ntemplate <int MAX>\nvector<pair<int, int>> osak_table(int n) {\n  static\
    \ vector<int> f = factor_enumerate(MAX);\n  vector<pair<int, int>> v;\n  for (;\
    \ f[n]; n /= f[n]) {\n    if (v.empty() || v.back().first != f[n]) {\n      v.emplace_back(f[n],\
    \ 1);\n    } else {\n      v.back().second++;\n    }\n  }\n  return v;\n}\n\n\
    template <int MAX>\nvector<int> osak_divisors(int n) {\n  if(n == 0) return {};\n\
    \  if(n == 1) return vector<int>(1, 1);\n  auto p = osak_table<MAX>(n);\n  vector<int>\
    \ ds;\n\n  auto dfs = [&](auto r, int i, int c) {\n    if (i == (int)p.size())\
    \ {\n      ds.push_back(c);\n      return;\n    }\n    for (int j = 0; j <= p[i].second;\
    \ j++) {\n      r(r, i + 1, c);\n      c *= p[i].first;\n    }\n  };\n\n  dfs(dfs,\
    \ 0, 1);\n  sort(begin(ds), end(ds));\n  return ds;\n}"
  dependsOn:
  - prime/factor-enumerate.hpp
  isVerificationFile: false
  path: prime/osak.hpp
  requiredBy: []
  timestamp: '2021-04-20 10:57:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/factorize.test.cpp
  - verify/verify-unit-test/osak.test.cpp
documentation_of: prime/osak.hpp
layout: document
redirect_from:
- /library/prime/osak.hpp
- /library/prime/osak.hpp.html
title: prime/osak.hpp
---
