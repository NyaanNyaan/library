---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/fast-inv.test.cpp
    title: verify/verify-unit-test/fast-inv.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math-fast/inv.hpp\"\n\n#include <cassert>\nusing namespace\
    \ std;\n\n// \u5F15\u6570\u304C [0, mod) \u306E\u7BC4\u56F2\u5185, \u304B\u3064\
    \u9006\u5143\u304C\u5B58\u5728\u3059\u308B\u3068\u304D\u306B\u6B63\u3057\u304F\
    \u52D5\u304F\ntemplate <int MOD>\nstruct fast_modinv {\n  using u32 = unsigned\
    \ int;\n  using u64 = unsigned long long;\n\n  static constexpr int mod = MOD;\n\
    \  static_assert(mod % 2 == 1 && mod < (1LL << 30));\n  static constexpr int B\
    \ = 2048;\n  static constexpr bool prime = []() -> bool {\n    if (MOD == 1) return\
    \ false;\n    for (int p = 3; p * p <= MOD; p += 2) {\n      if (MOD % p == 0)\
    \ return false;\n    }\n    return true;\n  }();\n\n  u32 ipow2[64], pre[B / 2];\n\
    \  constexpr fast_modinv() : ipow2(), pre() {\n    ipow2[0] = 1 % mod;\n    for\
    \ (int i = 1; i < 64; i++) {\n      ipow2[i] = u64(ipow2[i - 1]) * ((mod + 1)\
    \ / 2) % mod;\n    }\n    pre[0] = 1 % mod;\n    for (int i = 3; i < B; i += 2)\
    \ {\n      pre[i >> 1] = [i]() -> int {\n        int x = i, y = mod, u = 1, v\
    \ = 0, t = 0, tmp = 0;\n        while (y > 0) {\n          t = x / y;\n      \
    \    x -= t * y, u -= t * v;\n          tmp = x, x = y, y = tmp;\n          tmp\
    \ = u, u = v, v = tmp;\n        }\n        return u < 0 ? u + mod : u;\n     \
    \ }();\n    }\n  }\n\n  constexpr u32 inv(u32 a) const {\n    if constexpr (mod\
    \ == 1) {\n      return 0;\n    }\n    u32 b = mod, s = 1, t = 0;\n    int n =\
    \ __builtin_ctz(a);\n    a >>= n;\n    while (a - b != 0) {\n      if constexpr\
    \ (prime) {\n        if (a < B) break;\n      }\n      int m = __builtin_ctz(a\
    \ - b);\n      bool f = a > b;\n      n += m;\n      a = f ? (a - b) >> m : a;\n\
    \      b = f ? b : -(a - b) >> m;\n      u32 u = f ? s - t : s << m;\n      t\
    \ = f ? t << m : -(s - t);\n      s = u;\n    }\n    return u64(s) * pre[a >>\
    \ 1] % mod * ipow2[n] % mod;\n  }\n  constexpr u32 operator()(u32 a) const { return\
    \ inv(a); }\n};\n"
  code: "#pragma once\n\n#include <cassert>\nusing namespace std;\n\n// \u5F15\u6570\
    \u304C [0, mod) \u306E\u7BC4\u56F2\u5185, \u304B\u3064\u9006\u5143\u304C\u5B58\
    \u5728\u3059\u308B\u3068\u304D\u306B\u6B63\u3057\u304F\u52D5\u304F\ntemplate <int\
    \ MOD>\nstruct fast_modinv {\n  using u32 = unsigned int;\n  using u64 = unsigned\
    \ long long;\n\n  static constexpr int mod = MOD;\n  static_assert(mod % 2 ==\
    \ 1 && mod < (1LL << 30));\n  static constexpr int B = 2048;\n  static constexpr\
    \ bool prime = []() -> bool {\n    if (MOD == 1) return false;\n    for (int p\
    \ = 3; p * p <= MOD; p += 2) {\n      if (MOD % p == 0) return false;\n    }\n\
    \    return true;\n  }();\n\n  u32 ipow2[64], pre[B / 2];\n  constexpr fast_modinv()\
    \ : ipow2(), pre() {\n    ipow2[0] = 1 % mod;\n    for (int i = 1; i < 64; i++)\
    \ {\n      ipow2[i] = u64(ipow2[i - 1]) * ((mod + 1) / 2) % mod;\n    }\n    pre[0]\
    \ = 1 % mod;\n    for (int i = 3; i < B; i += 2) {\n      pre[i >> 1] = [i]()\
    \ -> int {\n        int x = i, y = mod, u = 1, v = 0, t = 0, tmp = 0;\n      \
    \  while (y > 0) {\n          t = x / y;\n          x -= t * y, u -= t * v;\n\
    \          tmp = x, x = y, y = tmp;\n          tmp = u, u = v, v = tmp;\n    \
    \    }\n        return u < 0 ? u + mod : u;\n      }();\n    }\n  }\n\n  constexpr\
    \ u32 inv(u32 a) const {\n    if constexpr (mod == 1) {\n      return 0;\n   \
    \ }\n    u32 b = mod, s = 1, t = 0;\n    int n = __builtin_ctz(a);\n    a >>=\
    \ n;\n    while (a - b != 0) {\n      if constexpr (prime) {\n        if (a <\
    \ B) break;\n      }\n      int m = __builtin_ctz(a - b);\n      bool f = a >\
    \ b;\n      n += m;\n      a = f ? (a - b) >> m : a;\n      b = f ? b : -(a -\
    \ b) >> m;\n      u32 u = f ? s - t : s << m;\n      t = f ? t << m : -(s - t);\n\
    \      s = u;\n    }\n    return u64(s) * pre[a >> 1] % mod * ipow2[n] % mod;\n\
    \  }\n  constexpr u32 operator()(u32 a) const { return inv(a); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math-fast/inv.hpp
  requiredBy: []
  timestamp: '2023-08-10 13:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/fast-inv.test.cpp
documentation_of: math-fast/inv.hpp
layout: document
redirect_from:
- /library/math-fast/inv.hpp
- /library/math-fast/inv.hpp.html
title: math-fast/inv.hpp
---
