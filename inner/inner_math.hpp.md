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
  bundledCode: "#line 2 \"inner/inner_math.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nnamespace inner {\n\nusing i32 = int32_t;\nusing u32 = uint32_t;\n\
    using i64 = int64_t;\nusing u64 = uint64_t;\n\ntemplate <typename T = i32>\nT\
    \ gcd(T a, T b) {\n  while (b) swap(a %= b, b);\n  return a;\n}\n\n__attribute__((target(\"\
    avx2\"), optimize(\"O3\"))) u64 gcd_fast(u64 x, u64 y) {\n  if (x == 0 || y ==\
    \ 0) return x + y;\n  u32 bx = __builtin_ctz(x);\n  u32 by = __builtin_ctz(y);\n\
    \  u32 k = min(bx, by);\n  x >>= bx, y >>= by;\n  while (x != 0)\n    if (x ==\
    \ y) return x << k;\n    else if (x > y)\n      x = (x - y) >> __builtin_ctz(x\
    \ - y);\n    else\n      y = (y - x) >> __builtin_ctz(y - x);\n  return y << k;\n\
    }\n\ntemplate <typename T = int32_t>\nT inv(T a, T p) {\n  T b = p, x = 1, y =\
    \ 0;\n  while (a) {\n    T q = b % a;\n    swap(a, b /= a);\n    swap(x, y -=\
    \ q * x);\n  }\n  assert(b == 1);\n  return y < 0 ? y + p : y;\n}\n\ntemplate\
    \ <typename T = int32_t, typename U = int64_t>\nT modpow(T a, U n, T p) {\n  T\
    \ ret = 1;\n  for (; n; n >>= 1, a = U(a) * a % p)\n    if (n & 1) ret = U(ret)\
    \ * a % p;\n  return ret;\n}\n\n}  // namespace inner\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nnamespace\
    \ inner {\n\nusing i32 = int32_t;\nusing u32 = uint32_t;\nusing i64 = int64_t;\n\
    using u64 = uint64_t;\n\ntemplate <typename T = i32>\nT gcd(T a, T b) {\n  while\
    \ (b) swap(a %= b, b);\n  return a;\n}\n\n__attribute__((target(\"avx2\"), optimize(\"\
    O3\"))) u64 gcd_fast(u64 x, u64 y) {\n  if (x == 0 || y == 0) return x + y;\n\
    \  u32 bx = __builtin_ctz(x);\n  u32 by = __builtin_ctz(y);\n  u32 k = min(bx,\
    \ by);\n  x >>= bx, y >>= by;\n  while (x != 0)\n    if (x == y) return x << k;\n\
    \    else if (x > y)\n      x = (x - y) >> __builtin_ctz(x - y);\n    else\n \
    \     y = (y - x) >> __builtin_ctz(y - x);\n  return y << k;\n}\n\ntemplate <typename\
    \ T = int32_t>\nT inv(T a, T p) {\n  T b = p, x = 1, y = 0;\n  while (a) {\n \
    \   T q = b % a;\n    swap(a, b /= a);\n    swap(x, y -= q * x);\n  }\n  assert(b\
    \ == 1);\n  return y < 0 ? y + p : y;\n}\n\ntemplate <typename T = int32_t, typename\
    \ U = int64_t>\nT modpow(T a, U n, T p) {\n  T ret = 1;\n  for (; n; n >>= 1,\
    \ a = U(a) * a % p)\n    if (n & 1) ret = U(ret) * a % p;\n  return ret;\n}\n\n\
    }  // namespace inner\n"
  dependsOn: []
  isVerificationFile: false
  path: inner/inner_math.hpp
  requiredBy: []
  timestamp: '2020-09-16 23:27:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: inner/inner_math.hpp
layout: document
redirect_from:
- /library/inner/inner_math.hpp
- /library/inner/inner_math.hpp.html
title: inner/inner_math.hpp
---
