---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/primitive-root-ll.hpp
    title: math/primitive-root-ll.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/mod-kth-root.hpp
    title: kth root(Tonelli-Shanks algorithm)
  - icon: ':heavy_check_mark:'
    path: modulo/mod-log.hpp
    title: modulo/mod-log.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/multivariate-circular-convolution.hpp
    title: "\u591A\u5909\u6570\u5DE1\u56DE\u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: ntt/ntt-64bit.hpp
    title: ntt/ntt-64bit.hpp
  - icon: ':heavy_check_mark:'
    path: prime/fast-factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)"
  - icon: ':heavy_check_mark:'
    path: prime/miller-rabin.hpp
    title: Miller-Rabin primality test
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/factorize.test.cpp
    title: verify/verify-unit-test/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/garner-bigint.test.cpp
    title: verify/verify-unit-test/garner-bigint.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/internal-math.test.cpp
    title: verify/verify-unit-test/internal-math.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/ntt-64bit.test.cpp
    title: verify/verify-unit-test/ntt-64bit.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/osak.test.cpp
    title: verify/verify-unit-test/osak.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/primality-test.test.cpp
    title: verify/verify-unit-test/primality-test.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/primitive-root.test.cpp
    title: verify/verify-unit-test/primitive-root.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-factorization.test.cpp
    title: verify/verify-yosupo-math/yosupo-factorization.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
    title: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
    title: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-primality-test-u64.test.cpp
    title: verify/verify-yosupo-math/yosupo-primality-test-u64.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-primality-test.test.cpp
    title: verify/verify-yosupo-math/yosupo-primality-test.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-primitive-root.test.cpp
    title: verify/verify-yosupo-math/yosupo-primitive-root.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0002.test.cpp
    title: verify/verify-yuki/yuki-0002.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0103.test.cpp
    title: verify/verify-yuki/yuki-0103.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"internal/internal-math.hpp\"\n\n#line 2 \"internal/internal-type-traits.hpp\"\
    \n\n#include <type_traits>\nusing namespace std;\n\nnamespace internal {\ntemplate\
    \ <typename T>\nusing is_broadly_integral =\n    typename conditional_t<is_integral_v<T>\
    \ || is_same_v<T, __int128_t> ||\n                               is_same_v<T,\
    \ __uint128_t>,\n                           true_type, false_type>::type;\n\n\
    template <typename T>\nusing is_broadly_signed =\n    typename conditional_t<is_signed_v<T>\
    \ || is_same_v<T, __int128_t>,\n                           true_type, false_type>::type;\n\
    \ntemplate <typename T>\nusing is_broadly_unsigned =\n    typename conditional_t<is_unsigned_v<T>\
    \ || is_same_v<T, __uint128_t>,\n                           true_type, false_type>::type;\n\
    \n#define ENABLE_VALUE(x) \\\n  template <typename T> \\\n  constexpr bool x##_v\
    \ = x<T>::value;\n\nENABLE_VALUE(is_broadly_integral);\nENABLE_VALUE(is_broadly_signed);\n\
    ENABLE_VALUE(is_broadly_unsigned);\n#undef ENABLE_VALUE\n\n#define ENABLE_HAS_TYPE(var)\
    \                                   \\\n  template <class, class = void>     \
    \                          \\\n  struct has_##var : false_type {};           \
    \                 \\\n  template <class T>                                   \
    \        \\\n  struct has_##var<T, void_t<typename T::var>> : true_type {}; \\\
    \n  template <class T>                                           \\\n  constexpr\
    \ auto has_##var##_v = has_##var<T>::value;\n\n#define ENABLE_HAS_VAR(var)   \
    \                                  \\\n  template <class, class = void>      \
    \                          \\\n  struct has_##var : false_type {};           \
    \                  \\\n  template <class T>                                  \
    \          \\\n  struct has_##var<T, void_t<decltype(T::var)>> : true_type {};\
    \ \\\n  template <class T>                                            \\\n  constexpr\
    \ auto has_##var##_v = has_##var<T>::value;\n\n}  // namespace internal\n#line\
    \ 4 \"internal/internal-math.hpp\"\n\nnamespace internal {\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\n// a mod p\ntemplate\
    \ <typename T>\nT safe_mod(T a, T p) {\n  a %= p;\n  if constexpr (is_broadly_signed_v<T>)\
    \ {\n    if (a < 0) a += p;\n  }\n  return a;\n}\n\n// \u8FD4\u308A\u5024\uFF1A\
    pair(g, x)\n// s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g\ntemplate <typename\
    \ T>\npair<T, T> inv_gcd(T a, T p) {\n  static_assert(is_broadly_signed_v<T>);\n\
    \  a = safe_mod(a, p);\n  if (a == 0) return {p, 0};\n  T b = p, x = 1, y = 0;\n\
    \  while (a != 0) {\n    T q = b / a;\n    swap(a, b %= a);\n    swap(x, y -=\
    \ q * x);\n  }\n  if (y < 0) y += p / b;\n  return {b, y};\n}\n\n// \u8FD4\u308A\
    \u5024 : a^{-1} mod p\n// gcd(a, p) != 1 \u304C\u5FC5\u8981\ntemplate <typename\
    \ T>\nT inv(T a, T p) {\n  static_assert(is_broadly_signed_v<T>);\n  a = safe_mod(a,\
    \ p);\n  T b = p, x = 1, y = 0;\n  while (a != 0) {\n    T q = b / a;\n    swap(a,\
    \ b %= a);\n    swap(x, y -= q * x);\n  }\n  assert(b == 1);\n  return y < 0 ?\
    \ y + p : y;\n}\n\n// T : \u5E95\u306E\u578B\n// U : T*T \u304C\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044 \u304B\u3064 \u6307\u6570\u306E\u578B\
    \ntemplate <typename T, typename U>\nT modpow(T a, U n, T p) {\n  a = safe_mod(a,\
    \ p);\n  T ret = 1 % p;\n  while (n != 0) {\n    if (n % 2 == 1) ret = U(ret)\
    \ * a % p;\n    a = U(a) * a % p;\n    n /= 2;\n  }\n  return ret;\n}\n\n// \u8FD4\
    \u308A\u5024 : pair(rem, mod)\n// \u89E3\u306A\u3057\u306E\u3068\u304D\u306F {0,\
    \ 0} \u3092\u8FD4\u3059\ntemplate <typename T>\npair<T, T> crt(const vector<T>&\
    \ r, const vector<T>& m) {\n  static_assert(is_broadly_signed_v<T>);\n  assert(r.size()\
    \ == m.size());\n  int n = int(r.size());\n  T r0 = 0, m0 = 1;\n  for (int i =\
    \ 0; i < n; i++) {\n    assert(1 <= m[i]);\n    T r1 = safe_mod(r[i], m[i]), m1\
    \ = m[i];\n    if (m0 < m1) swap(r0, r1), swap(m0, m1);\n    if (m0 % m1 == 0)\
    \ {\n      if (r0 % m1 != r1) return {0, 0};\n      continue;\n    }\n    auto\
    \ [g, im] = inv_gcd(m0, m1);\n    T u1 = m1 / g;\n    if ((r1 - r0) % g) return\
    \ {0, 0};\n    T x = (r1 - r0) / g % u1 * im % u1;\n    r0 += x * m0;\n    m0\
    \ *= u1;\n    if (r0 < 0) r0 += m0;\n  }\n  return {r0, m0};\n}\n\n}  // namespace\
    \ internal\n"
  code: "#pragma once\n\n#include \"internal-type-traits.hpp\"\n\nnamespace internal\
    \ {\n\n#include <cassert>\n#include <utility>\n#include <vector>\nusing namespace\
    \ std;\n\n// a mod p\ntemplate <typename T>\nT safe_mod(T a, T p) {\n  a %= p;\n\
    \  if constexpr (is_broadly_signed_v<T>) {\n    if (a < 0) a += p;\n  }\n  return\
    \ a;\n}\n\n// \u8FD4\u308A\u5024\uFF1Apair(g, x)\n// s.t. g = gcd(a, b), xa =\
    \ g (mod b), 0 <= x < b/g\ntemplate <typename T>\npair<T, T> inv_gcd(T a, T p)\
    \ {\n  static_assert(is_broadly_signed_v<T>);\n  a = safe_mod(a, p);\n  if (a\
    \ == 0) return {p, 0};\n  T b = p, x = 1, y = 0;\n  while (a != 0) {\n    T q\
    \ = b / a;\n    swap(a, b %= a);\n    swap(x, y -= q * x);\n  }\n  if (y < 0)\
    \ y += p / b;\n  return {b, y};\n}\n\n// \u8FD4\u308A\u5024 : a^{-1} mod p\n//\
    \ gcd(a, p) != 1 \u304C\u5FC5\u8981\ntemplate <typename T>\nT inv(T a, T p) {\n\
    \  static_assert(is_broadly_signed_v<T>);\n  a = safe_mod(a, p);\n  T b = p, x\
    \ = 1, y = 0;\n  while (a != 0) {\n    T q = b / a;\n    swap(a, b %= a);\n  \
    \  swap(x, y -= q * x);\n  }\n  assert(b == 1);\n  return y < 0 ? y + p : y;\n\
    }\n\n// T : \u5E95\u306E\u578B\n// U : T*T \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\
    \u30ED\u30FC\u3057\u306A\u3044 \u304B\u3064 \u6307\u6570\u306E\u578B\ntemplate\
    \ <typename T, typename U>\nT modpow(T a, U n, T p) {\n  a = safe_mod(a, p);\n\
    \  T ret = 1 % p;\n  while (n != 0) {\n    if (n % 2 == 1) ret = U(ret) * a %\
    \ p;\n    a = U(a) * a % p;\n    n /= 2;\n  }\n  return ret;\n}\n\n// \u8FD4\u308A\
    \u5024 : pair(rem, mod)\n// \u89E3\u306A\u3057\u306E\u3068\u304D\u306F {0, 0}\
    \ \u3092\u8FD4\u3059\ntemplate <typename T>\npair<T, T> crt(const vector<T>& r,\
    \ const vector<T>& m) {\n  static_assert(is_broadly_signed_v<T>);\n  assert(r.size()\
    \ == m.size());\n  int n = int(r.size());\n  T r0 = 0, m0 = 1;\n  for (int i =\
    \ 0; i < n; i++) {\n    assert(1 <= m[i]);\n    T r1 = safe_mod(r[i], m[i]), m1\
    \ = m[i];\n    if (m0 < m1) swap(r0, r1), swap(m0, m1);\n    if (m0 % m1 == 0)\
    \ {\n      if (r0 % m1 != r1) return {0, 0};\n      continue;\n    }\n    auto\
    \ [g, im] = inv_gcd(m0, m1);\n    T u1 = m1 / g;\n    if ((r1 - r0) % g) return\
    \ {0, 0};\n    T x = (r1 - r0) / g % u1 * im % u1;\n    r0 += x * m0;\n    m0\
    \ *= u1;\n    if (r0 < 0) r0 += m0;\n  }\n  return {r0, m0};\n}\n\n}  // namespace\
    \ internal\n"
  dependsOn:
  - internal/internal-type-traits.hpp
  isVerificationFile: false
  path: internal/internal-math.hpp
  requiredBy:
  - math/primitive-root-ll.hpp
  - ntt/multivariate-circular-convolution.hpp
  - ntt/ntt-64bit.hpp
  - prime/miller-rabin.hpp
  - prime/fast-factorize.hpp
  - modulo/mod-log.hpp
  - modulo/mod-kth-root.hpp
  timestamp: '2024-03-04 16:48:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-primitive-root.test.cpp
  - verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
  - verify/verify-yosupo-math/yosupo-primality-test-u64.test.cpp
  - verify/verify-yosupo-math/yosupo-mod-log.test.cpp
  - verify/verify-yosupo-math/yosupo-primality-test.test.cpp
  - verify/verify-yosupo-math/yosupo-factorization.test.cpp
  - verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
  - verify/verify-unit-test/factorize.test.cpp
  - verify/verify-unit-test/primitive-root.test.cpp
  - verify/verify-unit-test/osak.test.cpp
  - verify/verify-unit-test/garner-bigint.test.cpp
  - verify/verify-unit-test/internal-math.test.cpp
  - verify/verify-unit-test/primality-test.test.cpp
  - verify/verify-unit-test/ntt-64bit.test.cpp
  - verify/verify-yuki/yuki-0002.test.cpp
  - verify/verify-yuki/yuki-0103.test.cpp
documentation_of: internal/internal-math.hpp
layout: document
redirect_from:
- /library/internal/internal-math.hpp
- /library/internal/internal-math.hpp.html
title: internal/internal-math.hpp
---
