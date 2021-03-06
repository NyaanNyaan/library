---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-ds/yosupo-predecessor-problem.test.cpp
    title: verify/verify-yosupo-ds/yosupo-predecessor-problem.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/w-ary-tree.hpp\"\n\nnamespace w_ary_tree_impl\
    \ {\nusing u64 = uint64_t;\nstatic constexpr unsigned int lgW = 6;\nstatic constexpr\
    \ unsigned int W = 1u << lgW;\nstatic constexpr int inf = 1 << 30;\ninline int\
    \ ctz(u64 n) { return n ? __builtin_ctzll(n) : -1; }\ninline int clz(u64 n) {\
    \ return n ? 63 - __builtin_clzll(n) : -1; }\n\ntemplate <int LOG, class D = void>\n\
    struct w_ary_tree_node {\n  u64 map;\n  int mn, mx;\n  static constexpr int shift\
    \ = (LOG - 1) * lgW;\n  array<w_ary_tree_node<LOG - 1>, W> chd;\n  inline int\
    \ mask(u64 key) const { return key & ((1 << shift) - 1); }\n\n  w_ary_tree_node()\
    \ : map(0), mn(inf), mx(-1) {}\n  void insert(int key) {\n    mn = std::min(mn,\
    \ key), mx = std::max(mx, key);\n    int pos = key >> shift;\n    map |= 1ULL\
    \ << pos;\n    chd[pos].insert(mask(key));\n  }\n  void erase(int key) {\n   \
    \ int pos = key >> shift;\n    chd[pos].erase(mask(key));\n    if (chd[pos].map\
    \ == 0) map &= ~(1ULL << pos);\n    if (mn == mx) {\n      mn = inf, mx = -1;\n\
    \    } else if (mn == key) {\n      int p = ctz(map);\n      mn = (p << shift)\
    \ + chd[p].min();\n    } else if (mx == key) {\n      int p = clz(map);\n    \
    \  mx = (p << shift) + chd[p].max();\n    }\n  }\n  bool contain(int key) const\
    \ {\n    int pos = key >> shift;\n    return chd[pos].contain(mask(key));\n  }\n\
    \  inline int min() const { return mn == inf ? -1 : mn; }\n  inline int max()\
    \ const { return mx; }\n  int find_next(int key) const {\n    if (key <= min())\
    \ return min();\n    int pos = key >> shift;\n    if (((map >> pos) & 1) && mask(key)\
    \ <= chd[pos].max()) {\n      return (pos << shift) + chd[pos].find_next(mask(key));\n\
    \    }\n    int nxt = ctz(map & ~((1ULL << (pos + 1)) - 1));\n    if (pos == 63\
    \ || nxt == -1) return -1;\n    return (nxt << shift) + chd[nxt].min();\n  }\n\
    \  int find_prev(int key) const {\n    if (max() < key) return max();\n    int\
    \ pos = key >> shift;\n    if (((map >> pos) & 1) && chd[pos].min() < mask(key))\
    \ {\n      return (pos << shift) + chd[pos].find_prev(mask(key));\n    }\n   \
    \ int nxt = clz(map & ((1ULL << pos) - 1ULL));\n    if (nxt == -1) return -1;\n\
    \    return (nxt << shift) + chd[nxt].max();\n  }\n};\n\ntemplate <int LOG>\n\
    struct w_ary_tree_node<LOG, typename std::enable_if<LOG == 1>::type> {\n  u64\
    \ map;\n  w_ary_tree_node() : map(0) {}\n  void insert(int key) { map |= 1ULL\
    \ << key; }\n  void erase(int key) { map &= ~(1ULL << key); }\n  bool contain(int\
    \ key) const { return (map >> key) & 1; }\n  int min() const { return ctz(map);\
    \ }\n  int max() const { return clz(map); }\n  int find_next(int key) const {\
    \ return ctz(map & ~((1ULL << key) - 1)); }\n  int find_prev(int key) const {\
    \ return clz(map & ((1ULL << key) - 1)); }\n};\n\n}  // namespace w_ary_tree_impl\n\
    \ntemplate <int LOG = 4>\nusing w_ary_tree = w_ary_tree_impl::w_ary_tree_node<LOG>;\n"
  code: "#pragma once\n\nnamespace w_ary_tree_impl {\nusing u64 = uint64_t;\nstatic\
    \ constexpr unsigned int lgW = 6;\nstatic constexpr unsigned int W = 1u << lgW;\n\
    static constexpr int inf = 1 << 30;\ninline int ctz(u64 n) { return n ? __builtin_ctzll(n)\
    \ : -1; }\ninline int clz(u64 n) { return n ? 63 - __builtin_clzll(n) : -1; }\n\
    \ntemplate <int LOG, class D = void>\nstruct w_ary_tree_node {\n  u64 map;\n \
    \ int mn, mx;\n  static constexpr int shift = (LOG - 1) * lgW;\n  array<w_ary_tree_node<LOG\
    \ - 1>, W> chd;\n  inline int mask(u64 key) const { return key & ((1 << shift)\
    \ - 1); }\n\n  w_ary_tree_node() : map(0), mn(inf), mx(-1) {}\n  void insert(int\
    \ key) {\n    mn = std::min(mn, key), mx = std::max(mx, key);\n    int pos = key\
    \ >> shift;\n    map |= 1ULL << pos;\n    chd[pos].insert(mask(key));\n  }\n \
    \ void erase(int key) {\n    int pos = key >> shift;\n    chd[pos].erase(mask(key));\n\
    \    if (chd[pos].map == 0) map &= ~(1ULL << pos);\n    if (mn == mx) {\n    \
    \  mn = inf, mx = -1;\n    } else if (mn == key) {\n      int p = ctz(map);\n\
    \      mn = (p << shift) + chd[p].min();\n    } else if (mx == key) {\n      int\
    \ p = clz(map);\n      mx = (p << shift) + chd[p].max();\n    }\n  }\n  bool contain(int\
    \ key) const {\n    int pos = key >> shift;\n    return chd[pos].contain(mask(key));\n\
    \  }\n  inline int min() const { return mn == inf ? -1 : mn; }\n  inline int max()\
    \ const { return mx; }\n  int find_next(int key) const {\n    if (key <= min())\
    \ return min();\n    int pos = key >> shift;\n    if (((map >> pos) & 1) && mask(key)\
    \ <= chd[pos].max()) {\n      return (pos << shift) + chd[pos].find_next(mask(key));\n\
    \    }\n    int nxt = ctz(map & ~((1ULL << (pos + 1)) - 1));\n    if (pos == 63\
    \ || nxt == -1) return -1;\n    return (nxt << shift) + chd[nxt].min();\n  }\n\
    \  int find_prev(int key) const {\n    if (max() < key) return max();\n    int\
    \ pos = key >> shift;\n    if (((map >> pos) & 1) && chd[pos].min() < mask(key))\
    \ {\n      return (pos << shift) + chd[pos].find_prev(mask(key));\n    }\n   \
    \ int nxt = clz(map & ((1ULL << pos) - 1ULL));\n    if (nxt == -1) return -1;\n\
    \    return (nxt << shift) + chd[nxt].max();\n  }\n};\n\ntemplate <int LOG>\n\
    struct w_ary_tree_node<LOG, typename std::enable_if<LOG == 1>::type> {\n  u64\
    \ map;\n  w_ary_tree_node() : map(0) {}\n  void insert(int key) { map |= 1ULL\
    \ << key; }\n  void erase(int key) { map &= ~(1ULL << key); }\n  bool contain(int\
    \ key) const { return (map >> key) & 1; }\n  int min() const { return ctz(map);\
    \ }\n  int max() const { return clz(map); }\n  int find_next(int key) const {\
    \ return ctz(map & ~((1ULL << key) - 1)); }\n  int find_prev(int key) const {\
    \ return clz(map & ((1ULL << key) - 1)); }\n};\n\n}  // namespace w_ary_tree_impl\n\
    \ntemplate <int LOG = 4>\nusing w_ary_tree = w_ary_tree_impl::w_ary_tree_node<LOG>;\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/w-ary-tree.hpp
  requiredBy: []
  timestamp: '2021-03-07 00:59:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-predecessor-problem.test.cpp
documentation_of: data-structure/w-ary-tree.hpp
layout: document
redirect_from:
- /library/data-structure/w-ary-tree.hpp
- /library/data-structure/w-ary-tree.hpp.html
title: data-structure/w-ary-tree.hpp
---
