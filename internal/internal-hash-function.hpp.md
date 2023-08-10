---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-seed.hpp
    title: internal/internal-seed.hpp
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: hashmap/hashmap-unerasable.hpp
    title: hashmap/hashmap-unerasable.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-1377.test.cpp
    title: verify/verify-aoj-other/aoj-1377.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/internal-type-traits.test.cpp
    title: verify/verify-unit-test/internal-type-traits.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-associative-array-unerasable-hashmap.test.cpp
    title: verify/verify-yosupo-ds/yosupo-associative-array-unerasable-hashmap.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30CF\u30C3\u30B7\u30E5\u95A2\u6570"
    links: []
  bundledCode: "#line 2 \"internal/internal-hash-function.hpp\"\n\n#include <cassert>\n\
    using namespace std;\n\n#line 2 \"internal/internal-seed.hpp\"\n\n#include <chrono>\n\
    using namespace std;\n\nnamespace internal {\nunsigned long long non_deterministic_seed()\
    \ {\n  unsigned long long m =\n      chrono::duration_cast<chrono::nanoseconds>(\n\
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \  .count();\n  m ^= 9845834732710364265uLL;\n  m ^= m << 24, m ^= m >> 31, m\
    \ ^= m << 35;\n  return m;\n}\nunsigned long long deterministic_seed() { return\
    \ 88172645463325252UL; }\n\n// 64 bit \u306E seed \u5024\u3092\u751F\u6210 (\u624B\
    \u5143\u3067\u306F seed \u56FA\u5B9A)\n// \u9023\u7D9A\u3067\u547C\u3073\u51FA\
    \u3059\u3068\u540C\u3058\u5024\u304C\u4F55\u5EA6\u3082\u8FD4\u3063\u3066\u304F\
    \u308B\u306E\u3067\u6CE8\u610F\n// #define RANDOMIZED_SEED \u3059\u308B\u3068\u30B7\
    \u30FC\u30C9\u304C\u30E9\u30F3\u30C0\u30E0\u306B\u306A\u308B\nunsigned long long\
    \ seed() {\n#if defined(NyaanLocal) && !defined(RANDOMIZED_SEED)\n  return deterministic_seed();\n\
    #else\n  return non_deterministic_seed();\n#endif\n}\n\n}  // namespace internal\n\
    #line 2 \"internal/internal-type-traits.hpp\"\n\n#include <type_traits>\nusing\
    \ namespace std;\n\nnamespace internal {\ntemplate <typename T>\nusing is_broadly_integral\
    \ =\n    typename conditional_t<is_integral_v<T> || is_same_v<T, __int128_t> ||\n\
    \                               is_same_v<T, __uint128_t>,\n                 \
    \          true_type, false_type>::type;\n\ntemplate <typename T>\nusing is_broadly_signed\
    \ =\n    typename conditional_t<is_signed_v<T> || is_same_v<T, __int128_t>,\n\
    \                           true_type, false_type>::type;\n\ntemplate <typename\
    \ T>\nusing is_broadly_unsigned =\n    typename conditional_t<is_unsigned_v<T>\
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
    \n}  // namespace internal\n#line 8 \"internal/internal-hash-function.hpp\"\n\n\
    namespace internal {\n// \u6574\u6570, \u6574\u6570\u5217\u3092 64 bit unsigned\
    \ int \u3078\u79FB\u3059\n\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    \nENABLE_HAS_TYPE(first_type);\nENABLE_HAS_TYPE(second_type);\nENABLE_HAS_TYPE(iterator);\n\
    \ntemplate <typename T>\nu64 hash_function(const T& x) {\n  static u64 r = seed();\n\
    \  constexpr u64 z1 = 11995408973635179863ULL;\n  if constexpr (is_broadly_integral_v<T>)\
    \ {\n    // Integral\n    return (u64(x) ^ r) * z1;\n  } else if constexpr (has_first_type_v<T>\
    \ && has_second_type_v<T>) {\n    // pair\n    constexpr u64 z2 = 10150724397891781847ULL;\n\
    \    return hash_function(x.first) + hash_function(x.second) * z2;\n  } else if\
    \ constexpr (has_iterator_v<T>) {\n    // Container\n    constexpr u64 mod = (1LL\
    \ << 61) - 1;\n    constexpr u64 base = 950699498548472943ULL;\n    u64 m = 0;\n\
    \    for (auto& z : x) {\n      u64 w;\n      if constexpr (is_broadly_integral_v<T>)\
    \ {\n        w = u64(z) ^ r;\n      } else {\n        w = hash_function(z);\n\
    \      }\n      u128 y = u128(m) * base + (w & mod);\n      m = (y & mod) + (y\
    \ >> 61);\n      if (m >= mod) m -= mod;\n    }\n    m ^= m << 24, m ^= m >> 31,\
    \ m ^= m << 35;\n    return m;\n  } else {\n    static_assert([]() { return false;\
    \ }());\n  }\n}\n\ntemplate <typename Key>\nstruct HashObject {\n  size_t operator()(const\
    \ Key& x) const { return hash_function(x); }\n};\n\n}  // namespace internal\n\
    \n/*\n@brief \u30CF\u30C3\u30B7\u30E5\u95A2\u6570\n*/\n"
  code: "#pragma once\n\n#include <cassert>\nusing namespace std;\n\n#include \"internal-seed.hpp\"\
    \n#include \"internal-type-traits.hpp\"\n\nnamespace internal {\n// \u6574\u6570\
    , \u6574\u6570\u5217\u3092 64 bit unsigned int \u3078\u79FB\u3059\n\nusing u64\
    \ = unsigned long long;\nusing u128 = __uint128_t;\n\nENABLE_HAS_TYPE(first_type);\n\
    ENABLE_HAS_TYPE(second_type);\nENABLE_HAS_TYPE(iterator);\n\ntemplate <typename\
    \ T>\nu64 hash_function(const T& x) {\n  static u64 r = seed();\n  constexpr u64\
    \ z1 = 11995408973635179863ULL;\n  if constexpr (is_broadly_integral_v<T>) {\n\
    \    // Integral\n    return (u64(x) ^ r) * z1;\n  } else if constexpr (has_first_type_v<T>\
    \ && has_second_type_v<T>) {\n    // pair\n    constexpr u64 z2 = 10150724397891781847ULL;\n\
    \    return hash_function(x.first) + hash_function(x.second) * z2;\n  } else if\
    \ constexpr (has_iterator_v<T>) {\n    // Container\n    constexpr u64 mod = (1LL\
    \ << 61) - 1;\n    constexpr u64 base = 950699498548472943ULL;\n    u64 m = 0;\n\
    \    for (auto& z : x) {\n      u64 w;\n      if constexpr (is_broadly_integral_v<T>)\
    \ {\n        w = u64(z) ^ r;\n      } else {\n        w = hash_function(z);\n\
    \      }\n      u128 y = u128(m) * base + (w & mod);\n      m = (y & mod) + (y\
    \ >> 61);\n      if (m >= mod) m -= mod;\n    }\n    m ^= m << 24, m ^= m >> 31,\
    \ m ^= m << 35;\n    return m;\n  } else {\n    static_assert([]() { return false;\
    \ }());\n  }\n}\n\ntemplate <typename Key>\nstruct HashObject {\n  size_t operator()(const\
    \ Key& x) const { return hash_function(x); }\n};\n\n}  // namespace internal\n\
    \n/*\n@brief \u30CF\u30C3\u30B7\u30E5\u95A2\u6570\n*/"
  dependsOn:
  - internal/internal-seed.hpp
  - internal/internal-type-traits.hpp
  isVerificationFile: false
  path: internal/internal-hash-function.hpp
  requiredBy:
  - hashmap/hashmap-unerasable.hpp
  timestamp: '2023-08-10 13:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-associative-array-unerasable-hashmap.test.cpp
  - verify/verify-aoj-other/aoj-1377.test.cpp
  - verify/verify-unit-test/internal-type-traits.test.cpp
documentation_of: internal/internal-hash-function.hpp
layout: document
redirect_from:
- /library/internal/internal-hash-function.hpp
- /library/internal/internal-hash-function.hpp.html
title: "\u30CF\u30C3\u30B7\u30E5\u95A2\u6570"
---
