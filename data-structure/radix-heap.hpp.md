---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: shortest-path/dijkstra-fast.hpp
    title: shortest-path/dijkstra-fast.hpp
  - icon: ':warning:'
    path: shortest-path/dijkstra-radix-heap.hpp
    title: shortest-path/dijkstra-radix-heap.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-unit-test/radix-heap.test.cpp
    title: verify/verify-unit-test/radix-heap.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/radix-heap.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename Key, typename Val>\nstruct RadixHeap\
    \ {\n  using uint = typename make_unsigned<Key>::type;\n  static constexpr int\
    \ bit = sizeof(Key) * 8;\n  array<vector<pair<uint, Val> >, bit + 1> vs;\n  array<uint,\
    \ bit + 1> ms;\n\n  int s;\n  uint last;\n\n  RadixHeap() : s(0), last(0) { fill(begin(ms),\
    \ end(ms), uint(-1)); }\n\n  bool empty() const { return s == 0; }\n\n  int size()\
    \ const { return s; }\n\n  __attribute__((target(\"lzcnt\"))) inline uint64_t\
    \ getbit(uint a) const {\n    return 64 - _lzcnt_u64(a);\n  }\n\n  void push(const\
    \ uint &key, const Val &val) {\n    s++;\n    uint64_t b = getbit(key ^ last);\n\
    \    vs[b].emplace_back(key, val);\n    ms[b] = min(key, ms[b]);\n  }\n\n  pair<uint,\
    \ Val> pop() {\n    if (ms[0] == uint(-1)) {\n      int idx = 1;\n      while\
    \ (ms[idx] == uint(-1)) idx++;\n      last = ms[idx];\n      for (auto &p : vs[idx])\
    \ {\n        uint64_t b = getbit(p.first ^ last);\n        vs[b].emplace_back(p);\n\
    \        ms[b] = min(p.first, ms[b]);\n      }\n      vs[idx].clear();\n     \
    \ ms[idx] = uint(-1);\n    }\n    --s;\n    auto res = vs[0].back();\n    vs[0].pop_back();\n\
    \    if (vs[0].empty()) ms[0] = uint(-1);\n    return res;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename Key, typename Val>\nstruct RadixHeap {\n  using uint = typename make_unsigned<Key>::type;\n\
    \  static constexpr int bit = sizeof(Key) * 8;\n  array<vector<pair<uint, Val>\
    \ >, bit + 1> vs;\n  array<uint, bit + 1> ms;\n\n  int s;\n  uint last;\n\n  RadixHeap()\
    \ : s(0), last(0) { fill(begin(ms), end(ms), uint(-1)); }\n\n  bool empty() const\
    \ { return s == 0; }\n\n  int size() const { return s; }\n\n  __attribute__((target(\"\
    lzcnt\"))) inline uint64_t getbit(uint a) const {\n    return 64 - _lzcnt_u64(a);\n\
    \  }\n\n  void push(const uint &key, const Val &val) {\n    s++;\n    uint64_t\
    \ b = getbit(key ^ last);\n    vs[b].emplace_back(key, val);\n    ms[b] = min(key,\
    \ ms[b]);\n  }\n\n  pair<uint, Val> pop() {\n    if (ms[0] == uint(-1)) {\n  \
    \    int idx = 1;\n      while (ms[idx] == uint(-1)) idx++;\n      last = ms[idx];\n\
    \      for (auto &p : vs[idx]) {\n        uint64_t b = getbit(p.first ^ last);\n\
    \        vs[b].emplace_back(p);\n        ms[b] = min(p.first, ms[b]);\n      }\n\
    \      vs[idx].clear();\n      ms[idx] = uint(-1);\n    }\n    --s;\n    auto\
    \ res = vs[0].back();\n    vs[0].pop_back();\n    if (vs[0].empty()) ms[0] = uint(-1);\n\
    \    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/radix-heap.hpp
  requiredBy:
  - shortest-path/dijkstra-fast.hpp
  - shortest-path/dijkstra-radix-heap.hpp
  timestamp: '2020-11-24 21:21:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-unit-test/radix-heap.test.cpp
documentation_of: data-structure/radix-heap.hpp
layout: document
redirect_from:
- /library/data-structure/radix-heap.hpp
- /library/data-structure/radix-heap.hpp.html
title: data-structure/radix-heap.hpp
---
