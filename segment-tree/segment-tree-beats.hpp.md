---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/segment-tree-beats.test.cpp
    title: verify/verify-unit-test/segment-tree-beats.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-segtree-beats.test.cpp
    title: verify/verify-yosupo-ds/yosupo-segtree-beats.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/segment-tree/segment-tree-beats.md
    document_title: Range Chmin Chmax Add Update Range Min Max Sum Segment Tree Beats
    links: []
  bundledCode: "#line 2 \"segment-tree/segment-tree-beats.hpp\"\n\nstruct AngelBeats\
    \ {\n  using i64 = long long;\n  static constexpr i64 INF = numeric_limits<i64>::max()\
    \ / 2.1;\n\n  struct alignas(32) Node {\n    i64 sum = 0, g1 = 0, l1 = 0;\n  \
    \  i64 g2 = -INF, gc = 1, l2 = INF, lc = 1, add = 0;\n  };\n\n  vector<Node> v;\n\
    \  i64 n, log;\n\n  AngelBeats() {}\n  AngelBeats(int _n) : AngelBeats(vector<i64>(_n))\
    \ {}\n  AngelBeats(const vector<i64>& vc) {\n    n = 1, log = 0;\n    while (n\
    \ < (int)vc.size()) n <<= 1, log++;\n    v.resize(2 * n);\n    for (i64 i = 0;\
    \ i < (int)vc.size(); ++i) {\n      v[i + n].sum = v[i + n].g1 = v[i + n].l1 =\
    \ vc[i];\n    }\n    for (i64 i = n - 1; i; --i) update(i);\n  }\n\n  void range_chmin(int\
    \ l, int r, i64 x) { inner_apply<1>(l, r, x); }\n  void range_chmax(int l, int\
    \ r, i64 x) { inner_apply<2>(l, r, x); }\n  void range_add(int l, int r, i64 x)\
    \ { inner_apply<3>(l, r, x); }\n  void range_update(int l, int r, i64 x) { inner_apply<4>(l,\
    \ r, x); }\n  i64 range_min(int l, int r) { return inner_fold<1>(l, r); }\n  i64\
    \ range_max(int l, int r) { return inner_fold<2>(l, r); }\n  i64 range_sum(int\
    \ l, int r) { return inner_fold<3>(l, r); }\n\n private:\n  void update(int k)\
    \ {\n    Node& p = v[k];\n    Node& l = v[k * 2 + 0];\n    Node& r = v[k * 2 +\
    \ 1];\n\n    p.sum = l.sum + r.sum;\n\n    if (l.g1 == r.g1) {\n      p.g1 = l.g1;\n\
    \      p.g2 = max(l.g2, r.g2);\n      p.gc = l.gc + r.gc;\n    } else {\n    \
    \  bool f = l.g1 > r.g1;\n      p.g1 = f ? l.g1 : r.g1;\n      p.gc = f ? l.gc\
    \ : r.gc;\n      p.g2 = max(f ? r.g1 : l.g1, f ? l.g2 : r.g2);\n    }\n\n    if\
    \ (l.l1 == r.l1) {\n      p.l1 = l.l1;\n      p.l2 = min(l.l2, r.l2);\n      p.lc\
    \ = l.lc + r.lc;\n    } else {\n      bool f = l.l1 < r.l1;\n      p.l1 = f ?\
    \ l.l1 : r.l1;\n      p.lc = f ? l.lc : r.lc;\n      p.l2 = min(f ? r.l1 : l.l1,\
    \ f ? l.l2 : r.l2);\n    }\n  }\n\n  void push_add(int k, i64 x) {\n    Node&\
    \ p = v[k];\n    p.sum += x << (log + __builtin_clz(k) - 31);\n    p.g1 += x;\n\
    \    p.l1 += x;\n    if (p.g2 != -INF) p.g2 += x;\n    if (p.l2 != INF) p.l2 +=\
    \ x;\n    p.add += x;\n  }\n  void push_min(int k, i64 x) {\n    Node& p = v[k];\n\
    \    p.sum += (x - p.g1) * p.gc;\n    if (p.l1 == p.g1) p.l1 = x;\n    if (p.l2\
    \ == p.g1) p.l2 = x;\n    p.g1 = x;\n  }\n  void push_max(int k, i64 x) {\n  \
    \  Node& p = v[k];\n    p.sum += (x - p.l1) * p.lc;\n    if (p.g1 == p.l1) p.g1\
    \ = x;\n    if (p.g2 == p.l1) p.g2 = x;\n    p.l1 = x;\n  }\n  void push(int k)\
    \ {\n    Node& p = v[k];\n    if (p.add != 0) {\n      push_add(k * 2 + 0, p.add);\n\
    \      push_add(k * 2 + 1, p.add);\n      p.add = 0;\n    }\n    if (p.g1 < v[k\
    \ * 2 + 0].g1) push_min(k * 2 + 0, p.g1);\n    if (p.l1 > v[k * 2 + 0].l1) push_max(k\
    \ * 2 + 0, p.l1);\n\n    if (p.g1 < v[k * 2 + 1].g1) push_min(k * 2 + 1, p.g1);\n\
    \    if (p.l1 > v[k * 2 + 1].l1) push_max(k * 2 + 1, p.l1);\n  }\n\n  void subtree_chmin(int\
    \ k, i64 x) {\n    if (v[k].g1 <= x) return;\n    if (v[k].g2 < x) {\n      push_min(k,\
    \ x);\n      return;\n    }\n    push(k);\n    subtree_chmin(k * 2 + 0, x);\n\
    \    subtree_chmin(k * 2 + 1, x);\n    update(k);\n  }\n\n  void subtree_chmax(int\
    \ k, i64 x) {\n    if (x <= v[k].l1) return;\n    if (x < v[k].l2) {\n      push_max(k,\
    \ x);\n      return;\n    }\n    push(k);\n    subtree_chmax(k * 2 + 0, x);\n\
    \    subtree_chmax(k * 2 + 1, x);\n    update(k);\n  }\n\n  template <int cmd>\n\
    \  inline void _apply(int k, i64 x) {\n    if constexpr (cmd == 1) subtree_chmin(k,\
    \ x);\n    if constexpr (cmd == 2) subtree_chmax(k, x);\n    if constexpr (cmd\
    \ == 3) push_add(k, x);\n    if constexpr (cmd == 4) subtree_chmin(k, x), subtree_chmax(k,\
    \ x);\n  }\n\n  template <int cmd>\n  void inner_apply(int l, int r, i64 x) {\n\
    \    if (l == r) return;\n    l += n, r += n;\n    for (int i = log; i >= 1; i--)\
    \ {\n      if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i)\
    \ != r) push((r - 1) >> i);\n    }\n    {\n      int l2 = l, r2 = r;\n      while\
    \ (l < r) {\n        if (l & 1) _apply<cmd>(l++, x);\n        if (r & 1) _apply<cmd>(--r,\
    \ x);\n        l >>= 1;\n        r >>= 1;\n      }\n      l = l2;\n      r = r2;\n\
    \    }\n    for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l)\
    \ update(l >> i);\n      if (((r >> i) << i) != r) update((r - 1) >> i);\n   \
    \ }\n  }\n\n  template <int cmd>\n  inline i64 e() {\n    if constexpr (cmd ==\
    \ 1) return INF;\n    if constexpr (cmd == 2) return -INF;\n    return 0;\n  }\n\
    \n  template <int cmd>\n  inline void op(i64& a, const Node& b) {\n    if constexpr\
    \ (cmd == 1) a = min(a, b.l1);\n    if constexpr (cmd == 2) a = max(a, b.g1);\n\
    \    if constexpr (cmd == 3) a += b.sum;\n  }\n\n  template <int cmd>\n  i64 inner_fold(int\
    \ l, int r) {\n    if (l == r) return e<cmd>();\n    l += n, r += n;\n    for\
    \ (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n\
    \      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    i64 lx = e<cmd>(),\
    \ rx = e<cmd>();\n    while (l < r) {\n      if (l & 1) op<cmd>(lx, v[l++]);\n\
    \      if (r & 1) op<cmd>(rx, v[--r]);\n      l >>= 1;\n      r >>= 1;\n    }\n\
    \    if constexpr (cmd == 1) lx = min(lx, rx);\n    if constexpr (cmd == 2) lx\
    \ = max(lx, rx);\n    if constexpr (cmd == 3) lx += rx;\n    return lx;\n  }\n\
    };\n\n/**\n * @brief Range Chmin Chmax Add Update Range Min Max Sum Segment Tree\
    \ Beats\n * @docs docs/segment-tree/segment-tree-beats.md\n */\n"
  code: "#pragma once\n\nstruct AngelBeats {\n  using i64 = long long;\n  static constexpr\
    \ i64 INF = numeric_limits<i64>::max() / 2.1;\n\n  struct alignas(32) Node {\n\
    \    i64 sum = 0, g1 = 0, l1 = 0;\n    i64 g2 = -INF, gc = 1, l2 = INF, lc = 1,\
    \ add = 0;\n  };\n\n  vector<Node> v;\n  i64 n, log;\n\n  AngelBeats() {}\n  AngelBeats(int\
    \ _n) : AngelBeats(vector<i64>(_n)) {}\n  AngelBeats(const vector<i64>& vc) {\n\
    \    n = 1, log = 0;\n    while (n < (int)vc.size()) n <<= 1, log++;\n    v.resize(2\
    \ * n);\n    for (i64 i = 0; i < (int)vc.size(); ++i) {\n      v[i + n].sum =\
    \ v[i + n].g1 = v[i + n].l1 = vc[i];\n    }\n    for (i64 i = n - 1; i; --i) update(i);\n\
    \  }\n\n  void range_chmin(int l, int r, i64 x) { inner_apply<1>(l, r, x); }\n\
    \  void range_chmax(int l, int r, i64 x) { inner_apply<2>(l, r, x); }\n  void\
    \ range_add(int l, int r, i64 x) { inner_apply<3>(l, r, x); }\n  void range_update(int\
    \ l, int r, i64 x) { inner_apply<4>(l, r, x); }\n  i64 range_min(int l, int r)\
    \ { return inner_fold<1>(l, r); }\n  i64 range_max(int l, int r) { return inner_fold<2>(l,\
    \ r); }\n  i64 range_sum(int l, int r) { return inner_fold<3>(l, r); }\n\n private:\n\
    \  void update(int k) {\n    Node& p = v[k];\n    Node& l = v[k * 2 + 0];\n  \
    \  Node& r = v[k * 2 + 1];\n\n    p.sum = l.sum + r.sum;\n\n    if (l.g1 == r.g1)\
    \ {\n      p.g1 = l.g1;\n      p.g2 = max(l.g2, r.g2);\n      p.gc = l.gc + r.gc;\n\
    \    } else {\n      bool f = l.g1 > r.g1;\n      p.g1 = f ? l.g1 : r.g1;\n  \
    \    p.gc = f ? l.gc : r.gc;\n      p.g2 = max(f ? r.g1 : l.g1, f ? l.g2 : r.g2);\n\
    \    }\n\n    if (l.l1 == r.l1) {\n      p.l1 = l.l1;\n      p.l2 = min(l.l2,\
    \ r.l2);\n      p.lc = l.lc + r.lc;\n    } else {\n      bool f = l.l1 < r.l1;\n\
    \      p.l1 = f ? l.l1 : r.l1;\n      p.lc = f ? l.lc : r.lc;\n      p.l2 = min(f\
    \ ? r.l1 : l.l1, f ? l.l2 : r.l2);\n    }\n  }\n\n  void push_add(int k, i64 x)\
    \ {\n    Node& p = v[k];\n    p.sum += x << (log + __builtin_clz(k) - 31);\n \
    \   p.g1 += x;\n    p.l1 += x;\n    if (p.g2 != -INF) p.g2 += x;\n    if (p.l2\
    \ != INF) p.l2 += x;\n    p.add += x;\n  }\n  void push_min(int k, i64 x) {\n\
    \    Node& p = v[k];\n    p.sum += (x - p.g1) * p.gc;\n    if (p.l1 == p.g1) p.l1\
    \ = x;\n    if (p.l2 == p.g1) p.l2 = x;\n    p.g1 = x;\n  }\n  void push_max(int\
    \ k, i64 x) {\n    Node& p = v[k];\n    p.sum += (x - p.l1) * p.lc;\n    if (p.g1\
    \ == p.l1) p.g1 = x;\n    if (p.g2 == p.l1) p.g2 = x;\n    p.l1 = x;\n  }\n  void\
    \ push(int k) {\n    Node& p = v[k];\n    if (p.add != 0) {\n      push_add(k\
    \ * 2 + 0, p.add);\n      push_add(k * 2 + 1, p.add);\n      p.add = 0;\n    }\n\
    \    if (p.g1 < v[k * 2 + 0].g1) push_min(k * 2 + 0, p.g1);\n    if (p.l1 > v[k\
    \ * 2 + 0].l1) push_max(k * 2 + 0, p.l1);\n\n    if (p.g1 < v[k * 2 + 1].g1) push_min(k\
    \ * 2 + 1, p.g1);\n    if (p.l1 > v[k * 2 + 1].l1) push_max(k * 2 + 1, p.l1);\n\
    \  }\n\n  void subtree_chmin(int k, i64 x) {\n    if (v[k].g1 <= x) return;\n\
    \    if (v[k].g2 < x) {\n      push_min(k, x);\n      return;\n    }\n    push(k);\n\
    \    subtree_chmin(k * 2 + 0, x);\n    subtree_chmin(k * 2 + 1, x);\n    update(k);\n\
    \  }\n\n  void subtree_chmax(int k, i64 x) {\n    if (x <= v[k].l1) return;\n\
    \    if (x < v[k].l2) {\n      push_max(k, x);\n      return;\n    }\n    push(k);\n\
    \    subtree_chmax(k * 2 + 0, x);\n    subtree_chmax(k * 2 + 1, x);\n    update(k);\n\
    \  }\n\n  template <int cmd>\n  inline void _apply(int k, i64 x) {\n    if constexpr\
    \ (cmd == 1) subtree_chmin(k, x);\n    if constexpr (cmd == 2) subtree_chmax(k,\
    \ x);\n    if constexpr (cmd == 3) push_add(k, x);\n    if constexpr (cmd == 4)\
    \ subtree_chmin(k, x), subtree_chmax(k, x);\n  }\n\n  template <int cmd>\n  void\
    \ inner_apply(int l, int r, i64 x) {\n    if (l == r) return;\n    l += n, r +=\
    \ n;\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l\
    \ >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    {\n\
    \      int l2 = l, r2 = r;\n      while (l < r) {\n        if (l & 1) _apply<cmd>(l++,\
    \ x);\n        if (r & 1) _apply<cmd>(--r, x);\n        l >>= 1;\n        r >>=\
    \ 1;\n      }\n      l = l2;\n      r = r2;\n    }\n    for (int i = 1; i <= log;\
    \ i++) {\n      if (((l >> i) << i) != l) update(l >> i);\n      if (((r >> i)\
    \ << i) != r) update((r - 1) >> i);\n    }\n  }\n\n  template <int cmd>\n  inline\
    \ i64 e() {\n    if constexpr (cmd == 1) return INF;\n    if constexpr (cmd ==\
    \ 2) return -INF;\n    return 0;\n  }\n\n  template <int cmd>\n  inline void op(i64&\
    \ a, const Node& b) {\n    if constexpr (cmd == 1) a = min(a, b.l1);\n    if constexpr\
    \ (cmd == 2) a = max(a, b.g1);\n    if constexpr (cmd == 3) a += b.sum;\n  }\n\
    \n  template <int cmd>\n  i64 inner_fold(int l, int r) {\n    if (l == r) return\
    \ e<cmd>();\n    l += n, r += n;\n    for (int i = log; i >= 1; i--) {\n     \
    \ if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n    }\n    i64 lx = e<cmd>(), rx = e<cmd>();\n    while (l < r)\
    \ {\n      if (l & 1) op<cmd>(lx, v[l++]);\n      if (r & 1) op<cmd>(rx, v[--r]);\n\
    \      l >>= 1;\n      r >>= 1;\n    }\n    if constexpr (cmd == 1) lx = min(lx,\
    \ rx);\n    if constexpr (cmd == 2) lx = max(lx, rx);\n    if constexpr (cmd ==\
    \ 3) lx += rx;\n    return lx;\n  }\n};\n\n/**\n * @brief Range Chmin Chmax Add\
    \ Update Range Min Max Sum Segment Tree Beats\n * @docs docs/segment-tree/segment-tree-beats.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/segment-tree-beats.hpp
  requiredBy: []
  timestamp: '2021-02-02 18:56:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/segment-tree-beats.test.cpp
  - verify/verify-yosupo-ds/yosupo-segtree-beats.test.cpp
documentation_of: segment-tree/segment-tree-beats.hpp
layout: document
redirect_from:
- /library/segment-tree/segment-tree-beats.hpp
- /library/segment-tree/segment-tree-beats.hpp.html
title: Range Chmin Chmax Add Update Range Min Max Sum Segment Tree Beats
---
## Range Chmin Chmax Add Update Range Min Max Sum Segment Tree Beats

Range (Chmin Chmax Add Update)クエリとRange (Min Max Sum)クエリに対応したSegment Tree Beatsのライブラリ。

#### 使い方

- `range_chmin(l, r, x)`: for each $i \in [l, r)$, $a_i \leftarrow \min(a_i,x)$
- `range_chmax(l, r, x)`: for each $i \in [l, r)$, $a_i \leftarrow \max(a_i,x)$
- `range_add(l, r, x)`: for each $i \in [l, r)$, $a_i \leftarrow a_i + x$
- `range_update(l, r, x)`: for each $i \in [l, r)$, $a_i \leftarrow x$
- `range_min(l, r)`: return $\min(a_l,\ldots,a_{r-1})$
- `range_max(l, r)`: return $\max(a_l,\ldots,a_{r-1})$
- `range_sum(l, r)`: return $\sum_{i=l}^{r-1}a_i$
