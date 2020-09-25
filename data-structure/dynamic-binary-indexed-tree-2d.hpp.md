---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/hash-map-variable-length.hpp
    title: "Hash Map(\u53EF\u5909\u9577\u7248)"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum.test-bit2d.cpp
    title: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum.test-bit2d.cpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"data-structure/dynamic-binary-indexed-tree-2d.hpp\"\n#include\
    \ <bits/stdc++.h>\n#include <immintrin.h>\nusing namespace std;\n\n#line 3 \"\
    data-structure/hash-map-variable-length.hpp\"\nusing namespace std;\n\ntemplate\
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
    \ */\n#line 7 \"data-structure/dynamic-binary-indexed-tree-2d.hpp\"\n\ntemplate\
    \ <typename T>\nstruct DynamicBinaryIndexedTree2D {\n  using i32 = int32_t;\n\
    \  using u32 = uint32_t;\n  using u64 = uint64_t;\n  u32 N, M;\n  HashMap<u64,\
    \ T> dat;\n\n  DynamicBinaryIndexedTree2D() = default;\n  DynamicBinaryIndexedTree2D(u32\
    \ n, u32 m) : N(n + 1), M(m + 1) {\n    assert(N < (1LL << 30));\n    assert(M\
    \ < (1LL << 30));\n  }\n\n private:\n  inline u64 id(u32 n, u32 m) const { return\
    \ (u64(n) << 32) | u32(m); }\n\n  inline u64 get(u32 n, u32 m) const {\n    T*\
    \ p = dat.find(id(n, m));\n    return p ? *p : T();\n  }\n\n public:\n  __attribute__((target(\"\
    bmi\"))) void add(u32 n, u32 m, T k) {\n    for (++n, ++m; n <= N; n += _blsi_u32(n))\n\
    \      for (u32 j = m; j <= M; j += _blsi_u32(j)) dat[id(n, j)] += k;\n  }\n\n\
    \  __attribute__((target(\"bmi\"))) T sum(i32 n, i32 m) const {\n    if (n < 0\
    \ || m < 0) return T();\n    T ret = T();\n    for (u32 i = n; i > 0; i = _blsr_u32(i))\n\
    \      for (u32 j = m; j > 0; j = _blsr_u32(j)) ret += get(i, j);\n    return\
    \ ret;\n  }\n\n  T sum(i32 nl, i32 ml, i32 nr, i32 mr) const {\n    return sum(nr,\
    \ mr) - sum(nr, ml) - sum(nl, mr) + sum(nl, ml);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include <immintrin.h>\nusing namespace\
    \ std;\n\n#include \"hash-map-variable-length.hpp\"\n\ntemplate <typename T>\n\
    struct DynamicBinaryIndexedTree2D {\n  using i32 = int32_t;\n  using u32 = uint32_t;\n\
    \  using u64 = uint64_t;\n  u32 N, M;\n  HashMap<u64, T> dat;\n\n  DynamicBinaryIndexedTree2D()\
    \ = default;\n  DynamicBinaryIndexedTree2D(u32 n, u32 m) : N(n + 1), M(m + 1)\
    \ {\n    assert(N < (1LL << 30));\n    assert(M < (1LL << 30));\n  }\n\n private:\n\
    \  inline u64 id(u32 n, u32 m) const { return (u64(n) << 32) | u32(m); }\n\n \
    \ inline u64 get(u32 n, u32 m) const {\n    T* p = dat.find(id(n, m));\n    return\
    \ p ? *p : T();\n  }\n\n public:\n  __attribute__((target(\"bmi\"))) void add(u32\
    \ n, u32 m, T k) {\n    for (++n, ++m; n <= N; n += _blsi_u32(n))\n      for (u32\
    \ j = m; j <= M; j += _blsi_u32(j)) dat[id(n, j)] += k;\n  }\n\n  __attribute__((target(\"\
    bmi\"))) T sum(i32 n, i32 m) const {\n    if (n < 0 || m < 0) return T();\n  \
    \  T ret = T();\n    for (u32 i = n; i > 0; i = _blsr_u32(i))\n      for (u32\
    \ j = m; j > 0; j = _blsr_u32(j)) ret += get(i, j);\n    return ret;\n  }\n\n\
    \  T sum(i32 nl, i32 ml, i32 nr, i32 mr) const {\n    return sum(nr, mr) - sum(nr,\
    \ ml) - sum(nl, mr) + sum(nl, ml);\n  }\n};\n"
  dependsOn:
  - data-structure/hash-map-variable-length.hpp
  isVerificationFile: false
  path: data-structure/dynamic-binary-indexed-tree-2d.hpp
  requiredBy:
  - verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum.test-bit2d.cpp
  timestamp: '2020-09-25 21:13:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/dynamic-binary-indexed-tree-2d.hpp
layout: document
redirect_from:
- /library/data-structure/dynamic-binary-indexed-tree-2d.hpp
- /library/data-structure/dynamic-binary-indexed-tree-2d.hpp.html
title: data-structure/dynamic-binary-indexed-tree-2d.hpp
---
