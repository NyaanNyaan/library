---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/dynamic-binary-indexed-tree.hpp
    title: data-structure/dynamic-binary-indexed-tree.hpp
  - icon: ':warning:'
    path: data-structure/dynamic-binary-indexed-tree-2d.hpp
    title: data-structure/dynamic-binary-indexed-tree-2d.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/mod-log.hpp
    title: modulo/mod-log.hpp
  - icon: ':heavy_check_mark:'
    path: segment-tree/dynamic-li-chao-tree.hpp
    title: segment-tree/dynamic-li-chao-tree.hpp
  - icon: ':warning:'
    path: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum.test-bit2d.cpp
    title: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum.test-bit2d.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-hash-map-variable-length.test.cpp
    title: verify/verify-yosupo-ds/yosupo-hash-map-variable-length.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-li-chao-tree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-li-chao-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
    title: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/data-structure/hash-map.md
    document_title: "Hash Map(\u53EF\u5909\u9577\u7248)"
    links: []
  bundledCode: "#line 2 \"data-structure/hash-map-variable-length.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\ntemplate <typename Key, typename Val>\n\
    struct HashMap {\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n private:\n\
    \  u32 cap, s;\n  Key* keys;\n  Val* vals;\n  vector<bool> flag;\n  const u64\
    \ r;\n  u32 shift;\n  Val DefaultValue;\n\n  static u64 rng() {\n    u64 m = chrono::duration_cast<chrono::nanoseconds>(\n\
    \                chrono::high_resolution_clock::now().time_since_epoch())\n  \
    \              .count();\n    m ^= m >> 16;\n    m ^= m << 32;\n    return m;\n\
    \  }\n\n  void reallocate() {\n    cap <<= 1;\n    Key* k = new Key[cap];\n  \
    \  Val* v = new Val[cap];\n    vector<bool> f(cap);\n    u32 sh = shift - 1;\n\
    \    for (int i = 0; i < (int)flag.size(); i++) {\n      if (flag[i]) {\n    \
    \    u32 hash = (u64(keys[i]) * r) >> sh;\n        while (f[hash]) hash = (hash\
    \ + 1) & (cap - 1);\n        k[hash] = keys[i];\n        v[hash] = vals[i];\n\
    \        f[hash] = 1;\n      }\n    }\n    delete (keys);\n    delete (vals);\n\
    \    keys = k;\n    vals = v;\n    flag.swap(f);\n    --shift;\n  }\n\n public:\n\
    \  HashMap()\n      : cap(8),\n        s(0),\n        keys(new Key[cap]),\n  \
    \      vals(new Val[cap]),\n        flag(cap),\n        r(rng()),\n        shift(64\
    \ - __lg(cap)),\n        DefaultValue(Val()) {}\n\n  ~HashMap() {\n    delete\
    \ (keys);\n    delete (vals);\n  }\n\n  Val& operator[](const Key& i) {\n    u32\
    \ hash = (u64(i) * r) >> shift;\n    while (true) {\n      if (!flag[hash]) {\n\
    \        if (s + s / 4 >= cap) {\n          reallocate();\n          return (*this)[i];\n\
    \        }\n        keys[hash] = i;\n        flag[hash] = 1;\n        ++s;\n \
    \       return vals[hash] = DefaultValue;\n      }\n      if (keys[hash] == i)\
    \ return vals[hash];\n      hash = (hash + 1) & (cap - 1);\n    }\n  }\n\n  //\
    \ exist -> return pointer of Val\n  // not exist -> return nullptr\n  Val* find(const\
    \ Key& i) const {\n    u32 hash = (u64(i) * r) >> shift;\n    while (true) {\n\
    \      if (!flag[hash]) return nullptr;\n      if (keys[hash] == i) return &(vals[hash]);\n\
    \      hash = (hash + 1) & (cap - 1);\n    }\n  }\n\n  // return vector< pair<const\
    \ Key&, val& > >\n  vector<pair<const Key&, Val&>> enumerate() const {\n    vector<pair<const\
    \ Key&, Val&>> ret;\n    for (u32 i = 0; i < cap; ++i)\n      if (flag[i]) ret.emplace_back(keys[i],\
    \ vals[i]);\n    return ret;\n  }\n\n  int size() const { return s; }\n\n  //\
    \ set default_value\n  void set_default(const Val& val) { DefaultValue = val;\
    \ }\n};\n\n/**\n * @brief Hash Map(\u53EF\u5909\u9577\u7248)\n * @docs docs/data-structure/hash-map.md\n\
    \ */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename Key, typename Val>\nstruct HashMap {\n  using u32 = uint32_t;\n  using\
    \ u64 = uint64_t;\n\n private:\n  u32 cap, s;\n  Key* keys;\n  Val* vals;\n  vector<bool>\
    \ flag;\n  const u64 r;\n  u32 shift;\n  Val DefaultValue;\n\n  static u64 rng()\
    \ {\n    u64 m = chrono::duration_cast<chrono::nanoseconds>(\n               \
    \ chrono::high_resolution_clock::now().time_since_epoch())\n                .count();\n\
    \    m ^= m >> 16;\n    m ^= m << 32;\n    return m;\n  }\n\n  void reallocate()\
    \ {\n    cap <<= 1;\n    Key* k = new Key[cap];\n    Val* v = new Val[cap];\n\
    \    vector<bool> f(cap);\n    u32 sh = shift - 1;\n    for (int i = 0; i < (int)flag.size();\
    \ i++) {\n      if (flag[i]) {\n        u32 hash = (u64(keys[i]) * r) >> sh;\n\
    \        while (f[hash]) hash = (hash + 1) & (cap - 1);\n        k[hash] = keys[i];\n\
    \        v[hash] = vals[i];\n        f[hash] = 1;\n      }\n    }\n    delete\
    \ (keys);\n    delete (vals);\n    keys = k;\n    vals = v;\n    flag.swap(f);\n\
    \    --shift;\n  }\n\n public:\n  HashMap()\n      : cap(8),\n        s(0),\n\
    \        keys(new Key[cap]),\n        vals(new Val[cap]),\n        flag(cap),\n\
    \        r(rng()),\n        shift(64 - __lg(cap)),\n        DefaultValue(Val())\
    \ {}\n\n  ~HashMap() {\n    delete (keys);\n    delete (vals);\n  }\n\n  Val&\
    \ operator[](const Key& i) {\n    u32 hash = (u64(i) * r) >> shift;\n    while\
    \ (true) {\n      if (!flag[hash]) {\n        if (s + s / 4 >= cap) {\n      \
    \    reallocate();\n          return (*this)[i];\n        }\n        keys[hash]\
    \ = i;\n        flag[hash] = 1;\n        ++s;\n        return vals[hash] = DefaultValue;\n\
    \      }\n      if (keys[hash] == i) return vals[hash];\n      hash = (hash +\
    \ 1) & (cap - 1);\n    }\n  }\n\n  // exist -> return pointer of Val\n  // not\
    \ exist -> return nullptr\n  Val* find(const Key& i) const {\n    u32 hash = (u64(i)\
    \ * r) >> shift;\n    while (true) {\n      if (!flag[hash]) return nullptr;\n\
    \      if (keys[hash] == i) return &(vals[hash]);\n      hash = (hash + 1) & (cap\
    \ - 1);\n    }\n  }\n\n  // return vector< pair<const Key&, val& > >\n  vector<pair<const\
    \ Key&, Val&>> enumerate() const {\n    vector<pair<const Key&, Val&>> ret;\n\
    \    for (u32 i = 0; i < cap; ++i)\n      if (flag[i]) ret.emplace_back(keys[i],\
    \ vals[i]);\n    return ret;\n  }\n\n  int size() const { return s; }\n\n  //\
    \ set default_value\n  void set_default(const Val& val) { DefaultValue = val;\
    \ }\n};\n\n/**\n * @brief Hash Map(\u53EF\u5909\u9577\u7248)\n * @docs docs/data-structure/hash-map.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/hash-map-variable-length.hpp
  requiredBy:
  - data-structure/dynamic-binary-indexed-tree.hpp
  - data-structure/dynamic-binary-indexed-tree-2d.hpp
  - modulo/mod-log.hpp
  - segment-tree/dynamic-li-chao-tree.hpp
  - verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum.test-bit2d.cpp
  timestamp: '2020-09-25 21:13:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-hash-map-variable-length.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-li-chao-tree.test.cpp
  - verify/verify-yosupo-math/yosupo-mod-log.test.cpp
documentation_of: data-structure/hash-map-variable-length.hpp
layout: document
redirect_from:
- /library/data-structure/hash-map-variable-length.hpp
- /library/data-structure/hash-map-variable-length.hpp.html
title: "Hash Map(\u53EF\u5909\u9577\u7248)"
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
