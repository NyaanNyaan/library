---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-hash-function.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: internal/internal-seed.hpp
    title: internal/internal-seed.hpp
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  _extendedRequiredBy: []
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
    links: []
  bundledCode: "#line 2 \"hashmap/hashmap-unerasable.hpp\"\n\n#include <cassert>\n\
    #include <chrono>\n#include <vector>\nusing namespace std;\n\n#line 2 \"internal/internal-hash-function.hpp\"\
    \n\n#line 4 \"internal/internal-hash-function.hpp\"\nusing namespace std;\n\n\
    #line 2 \"internal/internal-seed.hpp\"\n\n#line 4 \"internal/internal-seed.hpp\"\
    \nusing namespace std;\n\nnamespace internal {\nunsigned long long non_deterministic_seed()\
    \ {\n  unsigned long long m =\n      chrono::duration_cast<chrono::nanoseconds>(\n\
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \  .count();\n  m ^= 9845834732710364265uLL;\n  m ^= m << 24, m ^= m >> 31, m\
    \ ^= m << 35;\n  return m;\n}\nunsigned long long deterministic_seed() { return\
    \ 88172645463325252UL; }\n\n// 64 bit \u306E seed \u5024\u3092\u751F\u6210 (\u624B\
    \u5143\u3067\u306F seed \u56FA\u5B9A)\n// \u9023\u7D9A\u3067\u547C\u3073\u51FA\
    \u3059\u3068\u540C\u3058\u5024\u304C\u4F55\u5EA6\u3082\u8FD4\u3063\u3066\u304F\
    \u308B\u306E\u3067\u6CE8\u610F\nunsigned long long seed() {\n#if defined(NyaanLocal)\
    \ && !defined(NON_DETERMINISTIC_SEED)\n  return deterministic_seed();\n#else\n\
    \  return non_deterministic_seed();\n#endif\n}\n\n}  // namespace internal\n#line\
    \ 2 \"internal/internal-type-traits.hpp\"\n\n#include <type_traits>\nusing namespace\
    \ std;\n\nnamespace internal {\ntemplate <typename T>\nusing is_broadly_integral\
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
    \n/*\n@brief \u30CF\u30C3\u30B7\u30E5\u95A2\u6570\n*/\n#line 9 \"hashmap/hashmap-unerasable.hpp\"\
    \n\n// \u524A\u9664\u4E0D\u53EF\u80FD\u306A hashmap\n//\n// \u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\u5F15\u6570\n// Key : Int, string, vector \u8FBA\u308A\u306F\
    \u4F55\u3067\u3082 (\u5C0F\u6570\u7CFB\u306F\u7121\u7406)\n// Val : \u4F55\u3067\
    \u3082\n// init_size : \u521D\u671F\u30D0\u30B1\u30C3\u30C8\u30B5\u30A4\u30BA\n\
    // fixed_size : \u3053\u308C\u3092 true \u306B\u3059\u308B\u3059\u308B\u3068\u30D0\
    \u30B1\u30C3\u30C8\u30B5\u30A4\u30BA\u304C\u56FA\u5B9A\u306B\u306A\u308B\n// \u5F15\
    \u6570\n// _default_value : Val \u306E\u521D\u671F\u5024, \u3053\u306E\u5024\u3067\
    \u521D\u671F\u5316\u3055\u308C\u308B\ntemplate <typename Key, typename Val, int\
    \ init_size = 4,\n          bool fixed_size = false>\nstruct UnerasableHashMap\
    \ {\n  static_assert(init_size >= 1 && (init_size & (init_size - 1)) == 0);\n\n\
    \ private:\n  int N, occupied_num;\n  vector<Key> keys;\n  vector<Val> vals;\n\
    \  vector<char> flag;\n  int shift;\n  Val default_value;\n\n  // 64 bit \u306E\
    \ hash \u3092\u8FD4\u3059\n  static unsigned long long get_hash(const Key& x)\
    \ {\n    return internal::hash_function(x);\n  }\n\n  // \u30B5\u30A4\u30BA\u3092\
    \ n \u306B\u62E1\u5F35\u3059\u308B\n  void init(int n = init_size, bool reset\
    \ = false) {\n    vector<Key> keys2(n);\n    vector<Val> vals2(n, default_value);\n\
    \    vector<char> flag2(n);\n    int shift2 = 64 - __builtin_ctz(n);\n    swap(N,\
    \ n), swap(keys, keys2);\n    swap(vals, vals2), swap(flag, flag2), swap(shift,\
    \ shift2);\n    if (reset == false) {\n      for (int i = 0; i < (int)flag2.size();\
    \ i++) {\n        if (flag2[i]) {\n          int j = hint(keys2[i]);\n       \
    \   keys[j] = keys2[i];\n          vals[j] = vals2[i];\n          flag[j] = 1;\n\
    \        }\n      }\n    }\n  }\n\n  int hint(const Key& k) {\n    int hash =\
    \ get_hash(k) >> shift;\n    while (flag[hash] && keys[hash] != k) hash = (hash\
    \ + 1) & (N - 1);\n    return hash;\n  }\n\n public:\n  UnerasableHashMap(const\
    \ Val& _default_value = Val{})\n      : occupied_num(0), default_value(_default_value)\
    \ {\n    init(init_size, true);\n  }\n\n  // key \u304C i \u3067\u3042\u308B\u8981\
    \u7D20\u3078\u306E\u53C2\u7167\u3092\u8FD4\u3059\n  Val& operator[](const Key&\
    \ k) {\n    int i = hint(k);\n    if (!flag[i]) {\n      if constexpr (fixed_size\
    \ == false) {\n        if (occupied_num * 2 >= N) {\n          init(2 * N), i\
    \ = hint(k);\n        }\n      }\n      keys[i] = k, flag[i] = 1, occupied_num++;\n\
    \    }\n    return vals[i];\n  }\n\n  Val get(const Key& k) {\n    int i = hint(k);\n\
    \    return flag[i] ? vals[i] : default_value;\n  }\n\n  // \u8D70\u67FB, f \u306B\
    \u95A2\u6570 f(key, val) \u3092\u5165\u308C\u308B\n  template <typename F>\n \
    \ void enumerate(const F f) {\n    for (int i = 0; i < (int)flag.size(); i++)\
    \ {\n      if (flag[i]) f(keys[i], vals[i]);\n    }\n  }\n\n  int count(const\
    \ Key& k) { return flag[hint(k)]; }\n  bool contain(const Key& k) { return flag[hint(k)];\
    \ }\n  int size() const { return occupied_num; }\n  void reset() { init(init_size,\
    \ true); }\n  void clear() { init(init_size, true); }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <chrono>\n#include <vector>\n\
    using namespace std;\n\n#include \"../internal/internal-hash-function.hpp\"\n\n\
    // \u524A\u9664\u4E0D\u53EF\u80FD\u306A hashmap\n//\n// \u30C6\u30F3\u30D7\u30EC\
    \u30FC\u30C8\u5F15\u6570\n// Key : Int, string, vector \u8FBA\u308A\u306F\u4F55\
    \u3067\u3082 (\u5C0F\u6570\u7CFB\u306F\u7121\u7406)\n// Val : \u4F55\u3067\u3082\
    \n// init_size : \u521D\u671F\u30D0\u30B1\u30C3\u30C8\u30B5\u30A4\u30BA\n// fixed_size\
    \ : \u3053\u308C\u3092 true \u306B\u3059\u308B\u3059\u308B\u3068\u30D0\u30B1\u30C3\
    \u30C8\u30B5\u30A4\u30BA\u304C\u56FA\u5B9A\u306B\u306A\u308B\n// \u5F15\u6570\n\
    // _default_value : Val \u306E\u521D\u671F\u5024, \u3053\u306E\u5024\u3067\u521D\
    \u671F\u5316\u3055\u308C\u308B\ntemplate <typename Key, typename Val, int init_size\
    \ = 4,\n          bool fixed_size = false>\nstruct UnerasableHashMap {\n  static_assert(init_size\
    \ >= 1 && (init_size & (init_size - 1)) == 0);\n\n private:\n  int N, occupied_num;\n\
    \  vector<Key> keys;\n  vector<Val> vals;\n  vector<char> flag;\n  int shift;\n\
    \  Val default_value;\n\n  // 64 bit \u306E hash \u3092\u8FD4\u3059\n  static\
    \ unsigned long long get_hash(const Key& x) {\n    return internal::hash_function(x);\n\
    \  }\n\n  // \u30B5\u30A4\u30BA\u3092 n \u306B\u62E1\u5F35\u3059\u308B\n  void\
    \ init(int n = init_size, bool reset = false) {\n    vector<Key> keys2(n);\n \
    \   vector<Val> vals2(n, default_value);\n    vector<char> flag2(n);\n    int\
    \ shift2 = 64 - __builtin_ctz(n);\n    swap(N, n), swap(keys, keys2);\n    swap(vals,\
    \ vals2), swap(flag, flag2), swap(shift, shift2);\n    if (reset == false) {\n\
    \      for (int i = 0; i < (int)flag2.size(); i++) {\n        if (flag2[i]) {\n\
    \          int j = hint(keys2[i]);\n          keys[j] = keys2[i];\n          vals[j]\
    \ = vals2[i];\n          flag[j] = 1;\n        }\n      }\n    }\n  }\n\n  int\
    \ hint(const Key& k) {\n    int hash = get_hash(k) >> shift;\n    while (flag[hash]\
    \ && keys[hash] != k) hash = (hash + 1) & (N - 1);\n    return hash;\n  }\n\n\
    \ public:\n  UnerasableHashMap(const Val& _default_value = Val{})\n      : occupied_num(0),\
    \ default_value(_default_value) {\n    init(init_size, true);\n  }\n\n  // key\
    \ \u304C i \u3067\u3042\u308B\u8981\u7D20\u3078\u306E\u53C2\u7167\u3092\u8FD4\u3059\
    \n  Val& operator[](const Key& k) {\n    int i = hint(k);\n    if (!flag[i]) {\n\
    \      if constexpr (fixed_size == false) {\n        if (occupied_num * 2 >= N)\
    \ {\n          init(2 * N), i = hint(k);\n        }\n      }\n      keys[i] =\
    \ k, flag[i] = 1, occupied_num++;\n    }\n    return vals[i];\n  }\n\n  Val get(const\
    \ Key& k) {\n    int i = hint(k);\n    return flag[i] ? vals[i] : default_value;\n\
    \  }\n\n  // \u8D70\u67FB, f \u306B\u95A2\u6570 f(key, val) \u3092\u5165\u308C\
    \u308B\n  template <typename F>\n  void enumerate(const F f) {\n    for (int i\
    \ = 0; i < (int)flag.size(); i++) {\n      if (flag[i]) f(keys[i], vals[i]);\n\
    \    }\n  }\n\n  int count(const Key& k) { return flag[hint(k)]; }\n  bool contain(const\
    \ Key& k) { return flag[hint(k)]; }\n  int size() const { return occupied_num;\
    \ }\n  void reset() { init(init_size, true); }\n  void clear() { init(init_size,\
    \ true); }\n};\n"
  dependsOn:
  - internal/internal-hash-function.hpp
  - internal/internal-seed.hpp
  - internal/internal-type-traits.hpp
  isVerificationFile: false
  path: hashmap/hashmap-unerasable.hpp
  requiredBy: []
  timestamp: '2023-05-27 23:17:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/internal-type-traits.test.cpp
  - verify/verify-yosupo-ds/yosupo-associative-array-unerasable-hashmap.test.cpp
  - verify/verify-aoj-other/aoj-1377.test.cpp
documentation_of: hashmap/hashmap-unerasable.hpp
layout: document
redirect_from:
- /library/hashmap/hashmap-unerasable.hpp
- /library/hashmap/hashmap-unerasable.hpp.html
title: hashmap/hashmap-unerasable.hpp
---
