---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/w-ary-tree.hpp\"\n\nstruct FastSet {\n  using\
    \ u64 = uint64_t;\n  static constexpr u64 B = 64;\n  int n, lg;\n  vector<vector<u64>>\
    \ seg;\n  FastSet(int _n) : n(_n) {\n    do {\n      seg.push_back(vector<u64>((_n\
    \ + B - 1) / B));\n      _n = (_n + B - 1) / B;\n    } while (_n > 1);\n    lg\
    \ = int(seg.size());\n  }\n\n  inline int lsb(u64 x) { return __builtin_ctzll(x);\
    \ }\n  inline int msb(u64 x) { return 63 - __builtin_clzll(x); }\n  bool operator[](int\
    \ i) const { return (seg[0][i / B] >> (i % B) & 1) != 0; }\n  void set(int i)\
    \ {\n    for (int h = 0; h < lg; h++) {\n      bool b = seg[h][i / B] != 0;\n\
    \      seg[h][i / B] |= 1ULL << (i % B);\n      if (b) break;\n      i /= B;\n\
    \    }\n  }\n  void reset(int i) {\n    for (int h = 0; h < lg; h++) {\n     \
    \ seg[h][i / B] &= ~(1ULL << (i % B));\n      if (seg[h][i / B]) break;\n    \
    \  i /= B;\n    }\n  }\n\n  int find_next(int i) {\n    i++;\n    for (int h =\
    \ 0; h < lg; h++) {\n      if (i / B == seg[h].size()) break;\n      u64 d = seg[h][i\
    \ / B] >> (i % B);\n      if (!d) {\n        i = i / B + 1;\n        continue;\n\
    \      }\n      i += lsb(d);\n      for (int g = h - 1; g >= 0; g--) {\n     \
    \   i *= B;\n        i += lsb(seg[g][i / B]);\n      }\n      return i;\n    }\n\
    \    return -1;\n  }\n\n  int find_prev(int i) {\n    i--;\n    for (int h = 0;\
    \ h < lg; h++) {\n      if (i == -1) break;\n      u64 d = seg[h][i / B] << (63\
    \ - i % 64);\n      if (!d) {\n        i = i / B - 1;\n        continue;\n   \
    \   }\n      i += msb(d) - (B - 1);\n      for (int g = h - 1; g >= 0; g--) {\n\
    \        i *= B;\n        i += msb(seg[g][i / B]);\n      }\n      return i;\n\
    \    }\n    return -1;\n  }\n};\n"
  code: "#pragma once\n\nstruct FastSet {\n  using u64 = uint64_t;\n  static constexpr\
    \ u64 B = 64;\n  int n, lg;\n  vector<vector<u64>> seg;\n  FastSet(int _n) : n(_n)\
    \ {\n    do {\n      seg.push_back(vector<u64>((_n + B - 1) / B));\n      _n =\
    \ (_n + B - 1) / B;\n    } while (_n > 1);\n    lg = int(seg.size());\n  }\n\n\
    \  inline int lsb(u64 x) { return __builtin_ctzll(x); }\n  inline int msb(u64\
    \ x) { return 63 - __builtin_clzll(x); }\n  bool operator[](int i) const { return\
    \ (seg[0][i / B] >> (i % B) & 1) != 0; }\n  void set(int i) {\n    for (int h\
    \ = 0; h < lg; h++) {\n      bool b = seg[h][i / B] != 0;\n      seg[h][i / B]\
    \ |= 1ULL << (i % B);\n      if (b) break;\n      i /= B;\n    }\n  }\n  void\
    \ reset(int i) {\n    for (int h = 0; h < lg; h++) {\n      seg[h][i / B] &= ~(1ULL\
    \ << (i % B));\n      if (seg[h][i / B]) break;\n      i /= B;\n    }\n  }\n\n\
    \  int find_next(int i) {\n    i++;\n    for (int h = 0; h < lg; h++) {\n    \
    \  if (i / B == seg[h].size()) break;\n      u64 d = seg[h][i / B] >> (i % B);\n\
    \      if (!d) {\n        i = i / B + 1;\n        continue;\n      }\n      i\
    \ += lsb(d);\n      for (int g = h - 1; g >= 0; g--) {\n        i *= B;\n    \
    \    i += lsb(seg[g][i / B]);\n      }\n      return i;\n    }\n    return -1;\n\
    \  }\n\n  int find_prev(int i) {\n    i--;\n    for (int h = 0; h < lg; h++) {\n\
    \      if (i == -1) break;\n      u64 d = seg[h][i / B] << (63 - i % 64);\n  \
    \    if (!d) {\n        i = i / B - 1;\n        continue;\n      }\n      i +=\
    \ msb(d) - (B - 1);\n      for (int g = h - 1; g >= 0; g--) {\n        i *= B;\n\
    \        i += msb(seg[g][i / B]);\n      }\n      return i;\n    }\n    return\
    \ -1;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/w-ary-tree.hpp
  requiredBy: []
  timestamp: '2021-02-25 20:04:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/w-ary-tree.hpp
layout: document
redirect_from:
- /library/data-structure/w-ary-tree.hpp
- /library/data-structure/w-ary-tree.hpp.html
title: data-structure/w-ary-tree.hpp
---
