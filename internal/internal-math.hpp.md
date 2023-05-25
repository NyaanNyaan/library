---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: modulo/mod-kth-root.hpp
    title: kth root(Tonelli-Shanks algorithm)
  - icon: ':heavy_check_mark:'
    path: modulo/mod-log.hpp
    title: modulo/mod-log.hpp
  - icon: ':heavy_check_mark:'
    path: prime/fast-factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/factorize.test.cpp
    title: verify/verify-unit-test/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/garner-bigint.test.cpp
    title: verify/verify-unit-test/garner-bigint.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/osak.test.cpp
    title: verify/verify-unit-test/osak.test.cpp
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
    \                                              \\\n  template <class, class =\
    \ void>                                         \\\n  struct has_##var : std::false_type\
    \ {};                                 \\\n  template <class T>               \
    \                                      \\\n  struct has_##var<T, std::void_t<typename\
    \ T::var>> : std::true_type {}; \\\n  template <class T>                     \
    \                                \\\n  constexpr auto has_##var##_v = has_##var<T>::value;\n\
    \n}  // namespace internal\n#line 4 \"internal/internal-math.hpp\"\n\nnamespace\
    \ internal {\n\n#include <cassert>\nusing namespace std;\n\n// a^{-1} mod p \u3092\
    \u8A08\u7B97\u3002gcd(a, p) != 1 \u304C\u5FC5\u8981\ntemplate <typename T>\nT\
    \ inv(T a, T p) {\n  a = a % p;\n  if constexpr (is_broadly_signed_v<T>) {\n \
    \   if (a < 0) a += p;\n  }\n  T b = p, x = 1, y = 0;\n  while (a) {\n    T q\
    \ = b / a;\n    swap(a, b %= a);\n    swap(x, y -= q * x);\n  }\n  assert(b ==\
    \ 1);\n  return y < 0 ? y + p : y;\n}\n\n// T : \u5024\u306E\u578B\n// U : T*T\
    \ \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u578B\ntemplate\
    \ <typename T, typename U>\nT modpow(T a, __int128_t n, T p) {\n  T ret = 1 %\
    \ p;\n  while (n) {\n    if (n & 1) ret = U(ret) * a % p;\n    a = U(a) * a %\
    \ p;\n    n >>= 1;\n  }\n  return ret;\n}\n\n}  // namespace internal\n"
  code: "#pragma once\n\n#include \"internal-type-traits.hpp\"\n\nnamespace internal\
    \ {\n\n#include <cassert>\nusing namespace std;\n\n// a^{-1} mod p \u3092\u8A08\
    \u7B97\u3002gcd(a, p) != 1 \u304C\u5FC5\u8981\ntemplate <typename T>\nT inv(T\
    \ a, T p) {\n  a = a % p;\n  if constexpr (is_broadly_signed_v<T>) {\n    if (a\
    \ < 0) a += p;\n  }\n  T b = p, x = 1, y = 0;\n  while (a) {\n    T q = b / a;\n\
    \    swap(a, b %= a);\n    swap(x, y -= q * x);\n  }\n  assert(b == 1);\n  return\
    \ y < 0 ? y + p : y;\n}\n\n// T : \u5024\u306E\u578B\n// U : T*T \u304C\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u578B\ntemplate <typename T,\
    \ typename U>\nT modpow(T a, __int128_t n, T p) {\n  T ret = 1 % p;\n  while (n)\
    \ {\n    if (n & 1) ret = U(ret) * a % p;\n    a = U(a) * a % p;\n    n >>= 1;\n\
    \  }\n  return ret;\n}\n\n}  // namespace internal\n"
  dependsOn:
  - internal/internal-type-traits.hpp
  isVerificationFile: false
  path: internal/internal-math.hpp
  requiredBy:
  - prime/fast-factorize.hpp
  - modulo/mod-kth-root.hpp
  - modulo/mod-log.hpp
  timestamp: '2023-05-21 20:49:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-0103.test.cpp
  - verify/verify-yuki/yuki-0002.test.cpp
  - verify/verify-yosupo-math/yosupo-mod-log.test.cpp
  - verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
  - verify/verify-yosupo-math/yosupo-factorization.test.cpp
  - verify/verify-unit-test/garner-bigint.test.cpp
  - verify/verify-unit-test/factorize.test.cpp
  - verify/verify-unit-test/primitive-root.test.cpp
  - verify/verify-unit-test/osak.test.cpp
documentation_of: internal/internal-math.hpp
layout: document
redirect_from:
- /library/internal/internal-math.hpp
- /library/internal/internal-math.hpp.html
title: internal/internal-math.hpp
---
