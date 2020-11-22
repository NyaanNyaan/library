---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-hashmap-chain.test.cpp
    title: verify/verify-yosupo-ds/yosupo-hashmap-chain.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/hashmap_all.md
    document_title: "Hash Map(\u9023\u9396\u6CD5)"
    links: []
  bundledCode: "#line 2 \"hashmap/hashmap-chain.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename Key, typename Val, uint32_t N = 1 <<\
    \ 20,\n          Val DefaultValue = Val()>\nstruct HashMap {\n  using u32 = uint32_t;\n\
    \  using u64 = uint64_t;\n\n private:\n  struct Node {\n    Key key;\n    Val\
    \ val;\n    Node* nxt;\n    Node() = default;\n  };\n\n  u32 mask;\n  Node** table;\n\
    \  Node* pool;\n  int pid;\n  static constexpr u32 shift = 64 - __lg(N);\n\n \
    \ Node* my_new(const Key& key, const Val& val) {\n    pool[pid].key = key;\n \
    \   pool[pid].val = val;\n    pool[pid].nxt = nullptr;\n    return &(pool[pid++]);\n\
    \  }\n\n  static u64 rng() {\n    u64 m = chrono::duration_cast<chrono::nanoseconds>(\n\
    \                chrono::high_resolution_clock::now().time_since_epoch())\n  \
    \              .count();\n    m ^= m >> 16;\n    m ^= m << 32;\n    return m;\n\
    \  }\n\n public:\n  HashMap() : mask(N - 1), table(new Node*[N]()), pool(new Node[N]),\
    \ pid(0) {}\n\n  Val& operator[](const Key& key) {\n    static u64 r = rng();\n\
    \    u32 h = (u64(key) * r) >> shift;\n    Node** pp = &(table[h]);\n    while\
    \ (*pp != nullptr && (*pp)->key != key) pp = &((*pp)->nxt);\n    if (*pp == nullptr)\
    \ *pp = my_new(key, DefaultValue);\n    return (*pp)->val;\n  }\n};\n\n/**\n *\
    \ @brief Hash Map(\u9023\u9396\u6CD5)\n * @docs docs/data-structure/hashmap_all.md\n\
    \ */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename Key, typename Val, uint32_t N = 1 << 20,\n          Val DefaultValue\
    \ = Val()>\nstruct HashMap {\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\
    \n private:\n  struct Node {\n    Key key;\n    Val val;\n    Node* nxt;\n   \
    \ Node() = default;\n  };\n\n  u32 mask;\n  Node** table;\n  Node* pool;\n  int\
    \ pid;\n  static constexpr u32 shift = 64 - __lg(N);\n\n  Node* my_new(const Key&\
    \ key, const Val& val) {\n    pool[pid].key = key;\n    pool[pid].val = val;\n\
    \    pool[pid].nxt = nullptr;\n    return &(pool[pid++]);\n  }\n\n  static u64\
    \ rng() {\n    u64 m = chrono::duration_cast<chrono::nanoseconds>(\n         \
    \       chrono::high_resolution_clock::now().time_since_epoch())\n           \
    \     .count();\n    m ^= m >> 16;\n    m ^= m << 32;\n    return m;\n  }\n\n\
    \ public:\n  HashMap() : mask(N - 1), table(new Node*[N]()), pool(new Node[N]),\
    \ pid(0) {}\n\n  Val& operator[](const Key& key) {\n    static u64 r = rng();\n\
    \    u32 h = (u64(key) * r) >> shift;\n    Node** pp = &(table[h]);\n    while\
    \ (*pp != nullptr && (*pp)->key != key) pp = &((*pp)->nxt);\n    if (*pp == nullptr)\
    \ *pp = my_new(key, DefaultValue);\n    return (*pp)->val;\n  }\n};\n\n/**\n *\
    \ @brief Hash Map(\u9023\u9396\u6CD5)\n * @docs docs/data-structure/hashmap_all.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: hashmap/hashmap-chain.hpp
  requiredBy: []
  timestamp: '2020-11-22 18:12:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-hashmap-chain.test.cpp
documentation_of: hashmap/hashmap-chain.hpp
layout: document
redirect_from:
- /library/hashmap/hashmap-chain.hpp
- /library/hashmap/hashmap-chain.hpp.html
title: "Hash Map(\u9023\u9396\u6CD5)"
---
