---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-hash-map.test.cpp
    title: verify/verify-yosupo-ds/yosupo-hash-map.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: data-structure/hash-map.md
    document_title: Hash Map
    links: []
  bundledCode: "#line 2 \"data-structure/hash-map.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename Key, typename Val, uint32_t N = 1 <<\
    \ 20>\nstruct HashMap {\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n\
    \ private:\n  struct Node {\n    Key key;\n    Val val;\n    Node* nxt;\n    Node()\
    \ = default;\n  };\n\n  u32 mask;\n  Node** table;\n  Node* pool;\n  int pid;\n\
    \n  Node* my_new(const Key& key, const Val& val) {\n    pool[pid].key = key;\n\
    \    pool[pid].val = val;\n    pool[pid].nxt = nullptr;\n    return &(pool[pid++]);\n\
    \  }\n\n  u32 hash(u64 x) {\n    static const u64 m =\n        chrono::duration_cast<chrono::nanoseconds>(\n\
    \            chrono::high_resolution_clock::now().time_since_epoch())\n      \
    \      .count();\n    x ^= x >> 23;\n    x ^= m;\n    x ^= x >> 47;\n    return\
    \ (x - (x >> 32)) & mask;\n  }\n\n public:\n  HashMap() : mask(N - 1), table(new\
    \ Node*[N]()), pool(new Node[N]), pid(0) {}\n\n  Val& operator[](const Key& key)\
    \ {\n    u32 h = hash(key);\n    Node** pp = &(table[h]);\n    while (*pp != nullptr\
    \ && (*pp)->key != key) pp = &((*pp)->nxt);\n    if (*pp == nullptr) *pp = my_new(key,\
    \ Val(0));\n    return (*pp)->val;\n  }\n};\n\n/**\n * @brief Hash Map\n * @docs\
    \ data-structure/hash-map.md\n */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename Key, typename Val, uint32_t N = 1 << 20>\nstruct HashMap {\n  using\
    \ u32 = uint32_t;\n  using u64 = uint64_t;\n\n private:\n  struct Node {\n   \
    \ Key key;\n    Val val;\n    Node* nxt;\n    Node() = default;\n  };\n\n  u32\
    \ mask;\n  Node** table;\n  Node* pool;\n  int pid;\n\n  Node* my_new(const Key&\
    \ key, const Val& val) {\n    pool[pid].key = key;\n    pool[pid].val = val;\n\
    \    pool[pid].nxt = nullptr;\n    return &(pool[pid++]);\n  }\n\n  u32 hash(u64\
    \ x) {\n    static const u64 m =\n        chrono::duration_cast<chrono::nanoseconds>(\n\
    \            chrono::high_resolution_clock::now().time_since_epoch())\n      \
    \      .count();\n    x ^= x >> 23;\n    x ^= m;\n    x ^= x >> 47;\n    return\
    \ (x - (x >> 32)) & mask;\n  }\n\n public:\n  HashMap() : mask(N - 1), table(new\
    \ Node*[N]()), pool(new Node[N]), pid(0) {}\n\n  Val& operator[](const Key& key)\
    \ {\n    u32 h = hash(key);\n    Node** pp = &(table[h]);\n    while (*pp != nullptr\
    \ && (*pp)->key != key) pp = &((*pp)->nxt);\n    if (*pp == nullptr) *pp = my_new(key,\
    \ Val(0));\n    return (*pp)->val;\n  }\n};\n\n/**\n * @brief Hash Map\n * @docs\
    \ data-structure/hash-map.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/hash-map.hpp
  requiredBy: []
  timestamp: '2020-09-20 20:42:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-hash-map.test.cpp
documentation_of: data-structure/hash-map.hpp
layout: document
redirect_from:
- /library/data-structure/hash-map.hpp
- /library/data-structure/hash-map.hpp.html
title: Hash Map
---
