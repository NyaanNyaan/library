---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/constexpr-primitive-root.hpp
    title: math/constexpr-primitive-root.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-on-z-pz.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-on-z-pz.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ntt/multiplicative-convolution-mod-p.hpp\"\n\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n\n#line 2 \"math/constexpr-primitive-root.hpp\"\
    \n\nconstexpr unsigned int constexpr_primitive_root(unsigned int mod) {\n  using\
    \ u32 = unsigned int;\n  using u64 = unsigned long long;\n  if(mod == 2) return\
    \ 1;\n  u64 m = mod - 1, ds[32] = {}, idx = 0;\n  for (u64 i = 2; i * i <= m;\
    \ ++i) {\n    if (m % i == 0) {\n      ds[idx++] = i;\n      while (m % i == 0)\
    \ m /= i;\n    }\n  }\n  if (m != 1) ds[idx++] = m;\n  for (u32 _pr = 2, flg =\
    \ true;; _pr++, flg = true) {\n    for (u32 i = 0; i < idx && flg; ++i) {\n  \
    \    u64 a = _pr, b = (mod - 1) / ds[i], r = 1;\n      for (; b; a = a * a % mod,\
    \ b >>= 1)\n        if (b & 1) r = r * a % mod;\n      if (r == 1) flg = false;\n\
    \    }\n    if (flg == true) return _pr;\n  }\n}\n\n#line 8 \"ntt/multiplicative-convolution-mod-p.hpp\"\
    \n\ntemplate <typename fps>\nfps multiplicative_convolution_mod_p(const fps& a,\
    \ const fps& b, int p) {\n  assert((int)a.size() == p);\n  assert((int)b.size()\
    \ == p);\n  using mint = typename fps::value_type;\n  int r = constexpr_primitive_root(p);\n\
    \  vector<int> exp(p - 1), log(p);\n  exp[0] = 1;\n  for (int i = 1; i < p - 1;\
    \ i++) exp[i] = 1LL * exp[i - 1] * r % p;\n  for (int i = 0; i < p - 1; i++) log[exp[i]]\
    \ = i;\n  fps s(p - 1), t(p - 1);\n  for (int i = 0; i < p - 1; i++) s[i] = a[exp[i]],\
    \ t[i] = b[exp[i]];\n  fps u = s * t;\n  for (int i = p - 1; i < (int)u.size();\
    \ i++) u[i % (p - 1)] += u[i];\n  fps c(p);\n  for (int i = 1; i < p; i++) c[i]\
    \ = u[log[i]];\n\n  mint sa = accumulate(begin(a), end(a), mint{});\n  mint sb\
    \ = accumulate(begin(b), end(b), mint{});\n  c[0] = sa * b[0] + sb * a[0] - a[0]\
    \ * b[0];\n  return c;\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \n#include \"../math/constexpr-primitive-root.hpp\"\n\ntemplate <typename fps>\n\
    fps multiplicative_convolution_mod_p(const fps& a, const fps& b, int p) {\n  assert((int)a.size()\
    \ == p);\n  assert((int)b.size() == p);\n  using mint = typename fps::value_type;\n\
    \  int r = constexpr_primitive_root(p);\n  vector<int> exp(p - 1), log(p);\n \
    \ exp[0] = 1;\n  for (int i = 1; i < p - 1; i++) exp[i] = 1LL * exp[i - 1] * r\
    \ % p;\n  for (int i = 0; i < p - 1; i++) log[exp[i]] = i;\n  fps s(p - 1), t(p\
    \ - 1);\n  for (int i = 0; i < p - 1; i++) s[i] = a[exp[i]], t[i] = b[exp[i]];\n\
    \  fps u = s * t;\n  for (int i = p - 1; i < (int)u.size(); i++) u[i % (p - 1)]\
    \ += u[i];\n  fps c(p);\n  for (int i = 1; i < p; i++) c[i] = u[log[i]];\n\n \
    \ mint sa = accumulate(begin(a), end(a), mint{});\n  mint sb = accumulate(begin(b),\
    \ end(b), mint{});\n  c[0] = sa * b[0] + sb * a[0] - a[0] * b[0];\n  return c;\n\
    }\n"
  dependsOn:
  - math/constexpr-primitive-root.hpp
  isVerificationFile: false
  path: ntt/multiplicative-convolution-mod-p.hpp
  requiredBy: []
  timestamp: '2024-05-03 21:06:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ntt/yosupo-convolution-on-z-pz.test.cpp
documentation_of: ntt/multiplicative-convolution-mod-p.hpp
layout: document
redirect_from:
- /library/ntt/multiplicative-convolution-mod-p.hpp
- /library/ntt/multiplicative-convolution-mod-p.hpp.html
title: ntt/multiplicative-convolution-mod-p.hpp
---
