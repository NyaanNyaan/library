---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-hashmap-open-address.test.cpp
    title: verify/verify-yosupo-ds/yosupo-hashmap-open-address.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/hashmap_all.md
    document_title: "Hash Map(\u958B\u756A\u5730\u6CD5)"
    links: []
  bundledCode: "#line 2 \"hashmap/hashmap-open-address.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename Key, typename Val, uint32_t N = 1 <<\
    \ 20,\n          Val DefaultValue = Val()>\nstruct HashMap {\n  using u32 = uint32_t;\n\
    \  using u64 = uint64_t;\n\n private:\n  Key* keys;\n  Val* vals;\n  bitset<N>\
    \ flag;\n  static constexpr u32 shift = 64 - __lg(N);\n\n  static u64 rng() {\n\
    \    u64 m = chrono::duration_cast<chrono::nanoseconds>(\n                chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                .count();\n    m ^= m >> 16;\n    m ^= m << 32;\n    return m;\n\
    \  }\n\n public:\n  HashMap() : keys(new Key[N]), vals(new Val[N]) {\n    static_assert((N\
    \ & (N - 1)) == 0 && N > 0);\n  }\n\n  Val& operator[](const Key& i) {\n    static\
    \ u64 r = rng();\n    u32 hash = (u64(i) * r) >> shift;\n    while (true) {\n\
    \      if (!flag[hash]) {\n        keys[hash] = i;\n        flag[hash] = 1;\n\
    \        return vals[hash] = DefaultValue;\n      }\n      if (keys[hash] == i)\
    \ return vals[hash];\n      hash = (hash + 1) & (N - 1);\n    }\n  }\n};\n\n/**\n\
    \ * @brief Hash Map(\u958B\u756A\u5730\u6CD5)\n * @docs docs/data-structure/hashmap_all.md\n\
    \ */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename Key, typename Val, uint32_t N = 1 << 20,\n          Val DefaultValue\
    \ = Val()>\nstruct HashMap {\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\
    \n private:\n  Key* keys;\n  Val* vals;\n  bitset<N> flag;\n  static constexpr\
    \ u32 shift = 64 - __lg(N);\n\n  static u64 rng() {\n    u64 m = chrono::duration_cast<chrono::nanoseconds>(\n\
    \                chrono::high_resolution_clock::now().time_since_epoch())\n  \
    \              .count();\n    m ^= m >> 16;\n    m ^= m << 32;\n    return m;\n\
    \  }\n\n public:\n  HashMap() : keys(new Key[N]), vals(new Val[N]) {\n    static_assert((N\
    \ & (N - 1)) == 0 && N > 0);\n  }\n\n  Val& operator[](const Key& i) {\n    static\
    \ u64 r = rng();\n    u32 hash = (u64(i) * r) >> shift;\n    while (true) {\n\
    \      if (!flag[hash]) {\n        keys[hash] = i;\n        flag[hash] = 1;\n\
    \        return vals[hash] = DefaultValue;\n      }\n      if (keys[hash] == i)\
    \ return vals[hash];\n      hash = (hash + 1) & (N - 1);\n    }\n  }\n};\n\n/**\n\
    \ * @brief Hash Map(\u958B\u756A\u5730\u6CD5)\n * @docs docs/data-structure/hashmap_all.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: hashmap/hashmap-open-address.hpp
  requiredBy: []
  timestamp: '2020-11-22 18:12:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-hashmap-open-address.test.cpp
documentation_of: hashmap/hashmap-open-address.hpp
layout: document
redirect_from:
- /library/hashmap/hashmap-open-address.hpp
- /library/hashmap/hashmap-open-address.hpp.html
title: "Hash Map(\u958B\u756A\u5730\u6CD5)"
---
