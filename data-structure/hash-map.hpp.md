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
    _deprecated_at_docs: docs/data-structure/hash-map.md
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
    \ docs/data-structure/hash-map.md\n */\n"
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
    \ docs/data-structure/hash-map.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/hash-map.hpp
  requiredBy: []
  timestamp: '2020-09-20 20:56:25+09:00'
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
## Hash Map

ハッシュマップとは、$\mathrm{O}(1)$で一点更新・一点取得を行うことのできるデータ構造である。

#### 概要

ハッシュマップとは、ハッシュをkeyとして値を管理することで、keyの値の範囲によらず一点取得・更新が\mathrm{O}(1)で行えるデータ構造を実現したものである。

同様のデータ構造にC++の`unordered_map`があるが、`unordered_map`はハッシュ衝突の脆弱性があり、CodeForcesのようなHackの存在するコンテストで無造作に使用するのは危険である。([参考](https://kimiyuki.net/blog/2017/03/08/unordered-map-hash-collision/))

このライブラリでは最低限の機能を持ったHash Mapを実装している。実装には大きく分けて連鎖法と開番地法があり、開番地法の方が定数倍がよいらしいが、簡単のため連鎖法で実装している。そのため定数倍はあまりよくないが、それでも`unordered_map`より2倍程度の速さで動作する。

- [自作のHash Map](https://judge.yosupo.jp/submission/23579)　141ms
- [ハッシュ衝突の対策をしたunordered_map](https://judge.yosupo.jp/submission/23582) 263ms
- (入出力にかかる時間はともに最大50ms程度と考えられる。)
