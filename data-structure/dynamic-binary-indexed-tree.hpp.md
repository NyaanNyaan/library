---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/hash-map-variable-length.hpp
    title: "Hash Map(\u53EF\u5909\u9577\u7248)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"data-structure/dynamic-binary-indexed-tree.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"data-structure/hash-map-variable-length.hpp\"\
    \nusing namespace std;\n\ntemplate <typename Key, typename Val>\nstruct HashMap\
    \ {\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n private:\n  u32 cap,\
    \ s;\n  Key* keys;\n  Val* vals;\n  vector<bool> flag;\n  const u64 r;\n  u32\
    \ shift;\n  Val DefaultValue;\n\n  static u64 rng() {\n    u64 m = chrono::duration_cast<chrono::nanoseconds>(\n\
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
    \ */\n#line 6 \"data-structure/dynamic-binary-indexed-tree.hpp\"\n\ntemplate <typename\
    \ idx_t, typename data_t>\nstruct DynamicFenwickTree {\n  idx_t N;\n  HashMap<idx_t,\
    \ data_t> data;\n  DynamicFenwickTree(idx_t size) { N = size += 3; }\n\n  void\
    \ add(idx_t k, data_t x) {\n    for (k++; k < N; k += k & -k) data[k] += x;\n\
    \  }\n\n  data_t sum(idx_t k) {\n    if (k < 0) return 0;\n    data_t ret = 0;\n\
    \    for (k++; k > 0; k -= k & -k) ret += data[k];\n    return ret;\n  }\n\n \
    \ data_t sum(idx_t a, idx_t b) { return sum(b) - sum(a - 1); }\n\n  data_t operator[](idx_t\
    \ k) { return sum(k) - sum(k - 1); }\n\n  idx_t lower_bound(data_t w) {\n    if\
    \ (w <= 0) return 0;\n    idx_t x = 0;\n    for (idx_t k = 1 << __lg(x); k > 0;\
    \ k /= 2) {\n      if (x + k <= N - 1 && data[x + k] < w) {\n        w -= data[x\
    \ + k];\n        x += k;\n      }\n    }\n    return x;\n  }\n\n  void merge(DynamicFenwickTree<idx_t,\
    \ data_t>& other) {\n    if (data.size() < other.data.size()) data.swap(other.data);\n\
    \    for (auto& x : other.data) data[x.fi] += x.se;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"data-structure/hash-map-variable-length.hpp\"\n\ntemplate <typename idx_t,\
    \ typename data_t>\nstruct DynamicFenwickTree {\n  idx_t N;\n  HashMap<idx_t,\
    \ data_t> data;\n  DynamicFenwickTree(idx_t size) { N = size += 3; }\n\n  void\
    \ add(idx_t k, data_t x) {\n    for (k++; k < N; k += k & -k) data[k] += x;\n\
    \  }\n\n  data_t sum(idx_t k) {\n    if (k < 0) return 0;\n    data_t ret = 0;\n\
    \    for (k++; k > 0; k -= k & -k) ret += data[k];\n    return ret;\n  }\n\n \
    \ data_t sum(idx_t a, idx_t b) { return sum(b) - sum(a - 1); }\n\n  data_t operator[](idx_t\
    \ k) { return sum(k) - sum(k - 1); }\n\n  idx_t lower_bound(data_t w) {\n    if\
    \ (w <= 0) return 0;\n    idx_t x = 0;\n    for (idx_t k = 1 << __lg(x); k > 0;\
    \ k /= 2) {\n      if (x + k <= N - 1 && data[x + k] < w) {\n        w -= data[x\
    \ + k];\n        x += k;\n      }\n    }\n    return x;\n  }\n\n  void merge(DynamicFenwickTree<idx_t,\
    \ data_t>& other) {\n    if (data.size() < other.data.size()) data.swap(other.data);\n\
    \    for (auto& x : other.data) data[x.fi] += x.se;\n  }\n};\n"
  dependsOn:
  - data-structure/hash-map-variable-length.hpp
  isVerificationFile: false
  path: data-structure/dynamic-binary-indexed-tree.hpp
  requiredBy: []
  timestamp: '2020-09-25 21:13:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/dynamic-binary-indexed-tree.hpp
layout: document
redirect_from:
- /library/data-structure/dynamic-binary-indexed-tree.hpp
- /library/data-structure/dynamic-binary-indexed-tree.hpp.html
title: data-structure/dynamic-binary-indexed-tree.hpp
---
