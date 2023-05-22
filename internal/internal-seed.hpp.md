---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: hashmap/hashmap-unerasable.hpp
    title: hashmap/hashmap-unerasable.hpp
  - icon: ':heavy_check_mark:'
    path: internal/internal-hash-function.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u95A2\u6570"
  _extendedVerifiedWith:
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
  bundledCode: "#line 2 \"internal/internal-seed.hpp\"\n\n#include <chrono>\nusing\
    \ namespace std;\n\nnamespace internal {\nunsigned long long non_deterministic_seed()\
    \ {\n  unsigned long long m =\n      chrono::duration_cast<chrono::nanoseconds>(\n\
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \  .count();\n  m ^= 9845834732710364265uLL;\n  m ^= m << 24, m ^= m >> 31, m\
    \ ^= m << 35;\n  return m;\n}\nunsigned long long deterministic_seed() { return\
    \ 88172645463325252UL; }\n\n// 64 bit \u306E seed \u5024\u3092\u751F\u6210 (\u624B\
    \u5143\u3067\u306F seed \u56FA\u5B9A)\n// \u9023\u7D9A\u3067\u547C\u3073\u51FA\
    \u3059\u3068\u540C\u3058\u5024\u304C\u4F55\u5EA6\u3082\u8FD4\u3063\u3066\u304F\
    \u308B\u306E\u3067\u6CE8\u610F\nunsigned long long seed() {\n#if defined(NyaanLocal)\
    \ && !defined(NON_DETERMINISTIC_SEED)\n  return deterministic_seed();\n#else\n\
    \  return non_deterministic_seed();\n#endif\n}\n\n}  // namespace internal\n"
  code: "#pragma once\n\n#include <chrono>\nusing namespace std;\n\nnamespace internal\
    \ {\nunsigned long long non_deterministic_seed() {\n  unsigned long long m =\n\
    \      chrono::duration_cast<chrono::nanoseconds>(\n          chrono::high_resolution_clock::now().time_since_epoch())\n\
    \          .count();\n  m ^= 9845834732710364265uLL;\n  m ^= m << 24, m ^= m >>\
    \ 31, m ^= m << 35;\n  return m;\n}\nunsigned long long deterministic_seed() {\
    \ return 88172645463325252UL; }\n\n// 64 bit \u306E seed \u5024\u3092\u751F\u6210\
    \ (\u624B\u5143\u3067\u306F seed \u56FA\u5B9A)\n// \u9023\u7D9A\u3067\u547C\u3073\
    \u51FA\u3059\u3068\u540C\u3058\u5024\u304C\u4F55\u5EA6\u3082\u8FD4\u3063\u3066\
    \u304F\u308B\u306E\u3067\u6CE8\u610F\nunsigned long long seed() {\n#if defined(NyaanLocal)\
    \ && !defined(NON_DETERMINISTIC_SEED)\n  return deterministic_seed();\n#else\n\
    \  return non_deterministic_seed();\n#endif\n}\n\n}  // namespace internal\n"
  dependsOn: []
  isVerificationFile: false
  path: internal/internal-seed.hpp
  requiredBy:
  - hashmap/hashmap-unerasable.hpp
  - internal/internal-hash-function.hpp
  timestamp: '2023-05-21 18:39:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/internal-type-traits.test.cpp
  - verify/verify-yosupo-ds/yosupo-associative-array-unerasable-hashmap.test.cpp
documentation_of: internal/internal-seed.hpp
layout: document
redirect_from:
- /library/internal/internal-seed.hpp
- /library/internal/internal-seed.hpp.html
title: internal/internal-seed.hpp
---
