---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: inner/inner_math.hpp
    title: inner/inner_math.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
    title: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"modulo/mod-log.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 3 \"inner/inner_math.hpp\"\nusing namespace std;\n\nnamespace\
    \ inner {\n\nusing i32 = int32_t;\nusing u32 = uint32_t;\nusing i64 = int64_t;\n\
    using u64 = uint64_t;\n\ntemplate <typename T>\nT gcd(T a, T b) {\n  while (b)\
    \ swap(a %= b, b);\n  return a;\n}\n\ntemplate <typename T>\nT inv(T a, T p) {\n\
    \  T b = p, x = 1, y = 0;\n  while (a) {\n    T q = b / a;\n    swap(a, b %= a);\n\
    \    swap(x, y -= q * x);\n  }\n  assert(b == 1);\n  return y < 0 ? y + p : y;\n\
    }\n\ntemplate <typename T, typename U>\nT modpow(T a, U n, T p) {\n  T ret = 1\
    \ % p;\n  for (; n; n >>= 1, a = U(a) * a % p)\n    if (n & 1) ret = U(ret) *\
    \ a % p;\n  return ret;\n}\n\n}  // namespace inner\n#line 6 \"modulo/mod-log.hpp\"\
    \n\nint64_t mod_log(int64_t a, int64_t b, int64_t p) {\n  using namespace inner;\n\
    \  if ((a %= p) < 0) a += p;\n  if ((b %= p) < 0) b += p;\n  int64_t f, g, r =\
    \ 1 % p;\n  for (f = 0; (g = gcd(a, p)) > 1; ++f) {\n    if (b % g) return (r\
    \ == b) ? f : -1;\n    b /= g;\n    p /= g;\n    (r *= (a / g)) %= p;\n  }\n \
    \ if (p == 1) return f;\n  int64_t ir = inv(r, p);\n  (b *= ir) %= p;\n  int64_t\
    \ k = 0, ak = 1;\n  unordered_map<int64_t, int64_t> baby;\n  for (; k * k < p;\
    \ ++k) {\n    if (!baby.count(ak)) baby[ak] = k;\n    (ak *= a) %= p;\n  }\n \
    \ int64_t iak = inv(ak, p);\n  for (int64_t i = 0; i < k; ++i) {\n    if (baby.count(b))\
    \ return f + i * k + baby[b];\n    (b *= iak) %= p;\n  }\n  return -1;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../inner/inner_math.hpp\"\n\nint64_t mod_log(int64_t a, int64_t b, int64_t\
    \ p) {\n  using namespace inner;\n  if ((a %= p) < 0) a += p;\n  if ((b %= p)\
    \ < 0) b += p;\n  int64_t f, g, r = 1 % p;\n  for (f = 0; (g = gcd(a, p)) > 1;\
    \ ++f) {\n    if (b % g) return (r == b) ? f : -1;\n    b /= g;\n    p /= g;\n\
    \    (r *= (a / g)) %= p;\n  }\n  if (p == 1) return f;\n  int64_t ir = inv(r,\
    \ p);\n  (b *= ir) %= p;\n  int64_t k = 0, ak = 1;\n  unordered_map<int64_t, int64_t>\
    \ baby;\n  for (; k * k < p; ++k) {\n    if (!baby.count(ak)) baby[ak] = k;\n\
    \    (ak *= a) %= p;\n  }\n  int64_t iak = inv(ak, p);\n  for (int64_t i = 0;\
    \ i < k; ++i) {\n    if (baby.count(b)) return f + i * k + baby[b];\n    (b *=\
    \ iak) %= p;\n  }\n  return -1;\n}"
  dependsOn:
  - inner/inner_math.hpp
  isVerificationFile: false
  path: modulo/mod-log.hpp
  requiredBy: []
  timestamp: '2020-09-21 20:08:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-mod-log.test.cpp
documentation_of: modulo/mod-log.hpp
layout: document
redirect_from:
- /library/modulo/mod-log.hpp
- /library/modulo/mod-log.hpp.html
title: modulo/mod-log.hpp
---
