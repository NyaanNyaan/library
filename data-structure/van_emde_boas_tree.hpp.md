---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-ds/yosupo-predecessor-problem-vEB-tree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-predecessor-problem-vEB-tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/van_emde_boas_tree.hpp\"\n\nnamespace vEB_tree_impl\
    \ {\nusing u64 = uint64_t;\nstatic constexpr unsigned int lgW = 6;\nstatic constexpr\
    \ unsigned int W = 1u << lgW;\nstatic constexpr int inf = 1 << 30;\ninline int\
    \ ctz(u64 n) { return n ? __builtin_ctzll(n) : -1; }\ninline int clz(u64 n) {\
    \ return n ? 63 - __builtin_clzll(n) : -1; }\n\ntemplate <int LOG, class D = void>\n\
    struct vEB_tree_node {\n  using Chd = vEB_tree_node<(LOG >> 1)>;\n\n  Chd map;\n\
    \  int mn, mx;\n  static constexpr int shift = (LOG >> 1) * lgW;\n  array<Chd,\
    \ 1 << shift> chd;\n\n  inline int mask(u64 key) const { return key & ((1 << shift)\
    \ - 1); }\n\n  constexpr vEB_tree_node() : mn(inf), mx(-1) {}\n\n  void insert(int\
    \ key) {\n    mn = std::min(mn, key), mx = std::max(mx, key);\n    int pos = key\
    \ >> shift;\n    if (chd[pos].empty()) map.insert(pos);\n    chd[pos].insert(mask(key));\n\
    \  }\n\n  void erase(int key) {\n    int pos = key >> shift;\n    chd[pos].erase(mask(key));\n\
    \    if (chd[pos].empty()) map.erase(pos);\n    if (mn == mx) {\n      mn = inf,\
    \ mx = -1;\n    } else if (mn == key) {\n      int p = map.min();\n      mn =\
    \ (p << shift) + chd[p].min();\n    } else if (mx == key) {\n      int p = map.max();\n\
    \      mx = (p << shift) + chd[p].max();\n    }\n  }\n\n  bool contain(int key)\
    \ const {\n    int pos = key >> shift;\n    return chd[pos].contain(mask(key));\n\
    \  }\n\n  inline bool empty() const { return mx == -1; }\n  inline int min() const\
    \ { return mn == inf ? -1 : mn; }\n  inline int max() const { return mx; }\n\n\
    \  int find_next(int key) const {\n    if (key <= min()) return min();\n    if\
    \ (max() < key) return -1;\n    int pos = key >> shift;\n    if (map.contain(pos)\
    \ && mask(key) <= chd[pos].max()) {\n      return (pos << shift) + chd[pos].find_next(mask(key));\n\
    \    }\n    int nxt = map.find_next(pos + 1);\n    if (nxt == -1) return -1;\n\
    \    return (nxt << shift) + chd[nxt].min();\n  }\n\n  int find_prev(int key)\
    \ const {\n    if (max() < key) return max();\n    if (key <= min()) return -1;\n\
    \    int pos = key >> shift;\n    if (map.contain(pos) && chd[pos].min() < mask(key))\
    \ {\n      return (pos << shift) + chd[pos].find_prev(mask(key));\n    }\n   \
    \ int nxt = map.find_prev(pos);\n    if (nxt == -1) return -1;\n    return (nxt\
    \ << shift) + chd[nxt].max();\n  }\n};\n\ntemplate <int LOG>\nstruct vEB_tree_node<LOG,\
    \ typename std::enable_if<LOG == 1>::type> {\n  u64 map;\n  vEB_tree_node() :\
    \ map(0) {}\n  inline void insert(int key) { map |= 1ULL << key; }\n  inline void\
    \ erase(int key) { map &= ~(1ULL << key); }\n  inline bool contain(int key) const\
    \ { return (map >> key) & 1; }\n  inline bool empty() const { return map == 0;\
    \ }\n  inline int min() const { return ctz(map); }\n  inline int max() const {\
    \ return clz(map); }\n  int find_next(int key) const { return ctz(map & ~((1ULL\
    \ << key) - 1)); }\n  int find_prev(int key) const { return clz(map & ((1ULL <<\
    \ key) - 1)); }\n};\n\n}  // namespace vEB_tree_impl\n\nusing van_Emde_Boas_tree\
    \ = vEB_tree_impl::vEB_tree_node<4>;\n"
  code: "#pragma once\n\nnamespace vEB_tree_impl {\nusing u64 = uint64_t;\nstatic\
    \ constexpr unsigned int lgW = 6;\nstatic constexpr unsigned int W = 1u << lgW;\n\
    static constexpr int inf = 1 << 30;\ninline int ctz(u64 n) { return n ? __builtin_ctzll(n)\
    \ : -1; }\ninline int clz(u64 n) { return n ? 63 - __builtin_clzll(n) : -1; }\n\
    \ntemplate <int LOG, class D = void>\nstruct vEB_tree_node {\n  using Chd = vEB_tree_node<(LOG\
    \ >> 1)>;\n\n  Chd map;\n  int mn, mx;\n  static constexpr int shift = (LOG >>\
    \ 1) * lgW;\n  array<Chd, 1 << shift> chd;\n\n  inline int mask(u64 key) const\
    \ { return key & ((1 << shift) - 1); }\n\n  constexpr vEB_tree_node() : mn(inf),\
    \ mx(-1) {}\n\n  void insert(int key) {\n    mn = std::min(mn, key), mx = std::max(mx,\
    \ key);\n    int pos = key >> shift;\n    if (chd[pos].empty()) map.insert(pos);\n\
    \    chd[pos].insert(mask(key));\n  }\n\n  void erase(int key) {\n    int pos\
    \ = key >> shift;\n    chd[pos].erase(mask(key));\n    if (chd[pos].empty()) map.erase(pos);\n\
    \    if (mn == mx) {\n      mn = inf, mx = -1;\n    } else if (mn == key) {\n\
    \      int p = map.min();\n      mn = (p << shift) + chd[p].min();\n    } else\
    \ if (mx == key) {\n      int p = map.max();\n      mx = (p << shift) + chd[p].max();\n\
    \    }\n  }\n\n  bool contain(int key) const {\n    int pos = key >> shift;\n\
    \    return chd[pos].contain(mask(key));\n  }\n\n  inline bool empty() const {\
    \ return mx == -1; }\n  inline int min() const { return mn == inf ? -1 : mn; }\n\
    \  inline int max() const { return mx; }\n\n  int find_next(int key) const {\n\
    \    if (key <= min()) return min();\n    if (max() < key) return -1;\n    int\
    \ pos = key >> shift;\n    if (map.contain(pos) && mask(key) <= chd[pos].max())\
    \ {\n      return (pos << shift) + chd[pos].find_next(mask(key));\n    }\n   \
    \ int nxt = map.find_next(pos + 1);\n    if (nxt == -1) return -1;\n    return\
    \ (nxt << shift) + chd[nxt].min();\n  }\n\n  int find_prev(int key) const {\n\
    \    if (max() < key) return max();\n    if (key <= min()) return -1;\n    int\
    \ pos = key >> shift;\n    if (map.contain(pos) && chd[pos].min() < mask(key))\
    \ {\n      return (pos << shift) + chd[pos].find_prev(mask(key));\n    }\n   \
    \ int nxt = map.find_prev(pos);\n    if (nxt == -1) return -1;\n    return (nxt\
    \ << shift) + chd[nxt].max();\n  }\n};\n\ntemplate <int LOG>\nstruct vEB_tree_node<LOG,\
    \ typename std::enable_if<LOG == 1>::type> {\n  u64 map;\n  vEB_tree_node() :\
    \ map(0) {}\n  inline void insert(int key) { map |= 1ULL << key; }\n  inline void\
    \ erase(int key) { map &= ~(1ULL << key); }\n  inline bool contain(int key) const\
    \ { return (map >> key) & 1; }\n  inline bool empty() const { return map == 0;\
    \ }\n  inline int min() const { return ctz(map); }\n  inline int max() const {\
    \ return clz(map); }\n  int find_next(int key) const { return ctz(map & ~((1ULL\
    \ << key) - 1)); }\n  int find_prev(int key) const { return clz(map & ((1ULL <<\
    \ key) - 1)); }\n};\n\n}  // namespace vEB_tree_impl\n\nusing van_Emde_Boas_tree\
    \ = vEB_tree_impl::vEB_tree_node<4>;\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/van_emde_boas_tree.hpp
  requiredBy: []
  timestamp: '2021-03-08 15:21:05+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-predecessor-problem-vEB-tree.test.cpp
documentation_of: data-structure/van_emde_boas_tree.hpp
layout: document
redirect_from:
- /library/data-structure/van_emde_boas_tree.hpp
- /library/data-structure/van_emde_boas_tree.hpp.html
title: data-structure/van_emde_boas_tree.hpp
---
