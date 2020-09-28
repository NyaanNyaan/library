---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-hash-map-chain.test.cpp
    title: verify/verify-yosupo-ds/yosupo-hash-map-chain.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/hash-map.md
    document_title: "Hash Map(\u9023\u9396\u6CD5)"
    links: []
  bundledCode: "#line 2 \"data-structure/hash-map-chain.hpp\"\n#include <bits/stdc++.h>\n\
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
    \ @brief Hash Map(\u9023\u9396\u6CD5)\n * @docs docs/data-structure/hash-map.md\n\
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
    \ @brief Hash Map(\u9023\u9396\u6CD5)\n * @docs docs/data-structure/hash-map.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/hash-map-chain.hpp
  requiredBy: []
  timestamp: '2020-09-21 14:00:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-hash-map-chain.test.cpp
documentation_of: data-structure/hash-map-chain.hpp
layout: document
redirect_from:
- /library/data-structure/hash-map-chain.hpp
- /library/data-structure/hash-map-chain.hpp.html
title: "Hash Map(\u9023\u9396\u6CD5)"
---
## Hash Map

ハッシュマップとは、$\mathrm{O}(1)$で一点更新・一点取得を行うことのできるデータ構造である。

#### 概要

ハッシュマップとは、ハッシュをkeyとして値を管理することで、keyの値の範囲によらず一点取得・更新が$\mathrm{O}(1)$で行えるデータ構造を実現したものである。

同様のデータ構造にC++の`unordered_map`があるが、`unordered_map`はハッシュ衝突の脆弱性があり、CodeForcesのようなHackの存在するコンテストで無造作に使用するのは危険である。([参考](https://kimiyuki.net/blog/2017/03/08/unordered-map-hash-collision/))

このライブラリでは最低限の機能を持ったHash Mapを実装している。実装には大きく分けて連鎖法と開番地法があるが、開番地法の方がメモリの消費が少なく定数倍もよい。yosupo judgeの提出は以下の通りで、入出力の時間も考慮すると開番地法は`unordered_map`のおよそ4倍程度の速さで動作しているとわかる。

- [自作Hash Map(開番地法)](https://judge.yosupo.jp/submission/23703) 100ms
- [自作Hash Map(連鎖法)](https://judge.yosupo.jp/submission/23726)　146ms
- [ハッシュ衝突の対策をしたunordered_map](https://judge.yosupo.jp/submission/23582) 263ms
- (入出力にかかる時間は最大50ms程度と考えられる。)
