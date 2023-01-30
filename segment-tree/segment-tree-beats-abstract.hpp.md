---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0879.test.cpp
    title: verify/verify-yuki/yuki-0879.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0880.test.cpp
    title: verify/verify-yuki/yuki-0880.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/segment-tree/segment-tree-beats-abstract.md
    document_title: "\u62BD\u8C61\u5316Segment Tree Beats!"
    links: []
  bundledCode: "#line 2 \"segment-tree/segment-tree-beats-abstract.hpp\"\n\ntemplate\
    \ <typename Node>\nstruct Beats {\n  int n, log;\n  vector<Node> v;\n\n  template\
    \ <typename T>\n  Beats(vector<T>& vc) {\n    n = 1, log = 0;\n    while (n <\
    \ (int)vc.size()) n <<= 1, log++;\n    v.resize(2 * n);\n    for (int i = 0; i\
    \ < (int)vc.size(); ++i) v[i + n] = Node(vc[i]);\n    for (int i = n - 1; i; --i)\
    \ _update(i);\n  }\n\n  template <typename T>\n  void apply(int l, int r, T x)\
    \ {\n    if (l == r) return;\n    l += n, r += n;\n    for (int i = log; i >=\
    \ 1; i--) {\n      if (((l >> i) << i) != l) _push(l >> i);\n      if (((r >>\
    \ i) << i) != r) _push((r - 1) >> i);\n    }\n    {\n      int l2 = l, r2 = r;\n\
    \      while (l < r) {\n        if (l & 1) _apply(l++, x);\n        if (r & 1)\
    \ _apply(--r, x);\n        l >>= 1;\n        r >>= 1;\n      }\n      l = l2;\n\
    \      r = r2;\n    }\n    for (int i = 1; i <= log; i++) {\n      if (((l >>\
    \ i) << i) != l) _update(l >> i);\n      if (((r >> i) << i) != r) _update((r\
    \ - 1) >> i);\n    }\n  }\n\n  template <typename F>\n  void query(int l, int\
    \ r, const F& f) {\n    if (l == r) return;\n    l += n, r += n;\n    for (int\
    \ i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) _push(l >> i);\n  \
    \    if (((r >> i) << i) != r) _push((r - 1) >> i);\n    }\n    while (l < r)\
    \ {\n      if (l & 1) f(v[l++]);\n      if (r & 1) f(v[--r]);\n      l >>= 1;\n\
    \      r >>= 1;\n    }\n  }\n\n private:\n  void _push(int i) { v[i].push(v[2\
    \ * i + 0], v[2 * i + 1]); }\n  void _update(int i) { v[i].update(v[2 * i + 0],\
    \ v[2 * i + 1]); }\n  template <typename T>\n  void _apply(int i, T x) {\n   \
    \ bool res = v[i].apply(x);\n    if (i < n && res == false) {\n      _push(i);\n\
    \      _apply(i * 2 + 0, x);\n      _apply(i * 2 + 1, x);\n      _update(i);\n\
    \    }\n  }\n};\n\n/**\n * @brief \u62BD\u8C61\u5316Segment Tree Beats!\n * @docs\
    \ docs/segment-tree/segment-tree-beats-abstract.md\n */\n"
  code: "#pragma once\n\ntemplate <typename Node>\nstruct Beats {\n  int n, log;\n\
    \  vector<Node> v;\n\n  template <typename T>\n  Beats(vector<T>& vc) {\n    n\
    \ = 1, log = 0;\n    while (n < (int)vc.size()) n <<= 1, log++;\n    v.resize(2\
    \ * n);\n    for (int i = 0; i < (int)vc.size(); ++i) v[i + n] = Node(vc[i]);\n\
    \    for (int i = n - 1; i; --i) _update(i);\n  }\n\n  template <typename T>\n\
    \  void apply(int l, int r, T x) {\n    if (l == r) return;\n    l += n, r +=\
    \ n;\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) _push(l\
    \ >> i);\n      if (((r >> i) << i) != r) _push((r - 1) >> i);\n    }\n    {\n\
    \      int l2 = l, r2 = r;\n      while (l < r) {\n        if (l & 1) _apply(l++,\
    \ x);\n        if (r & 1) _apply(--r, x);\n        l >>= 1;\n        r >>= 1;\n\
    \      }\n      l = l2;\n      r = r2;\n    }\n    for (int i = 1; i <= log; i++)\
    \ {\n      if (((l >> i) << i) != l) _update(l >> i);\n      if (((r >> i) <<\
    \ i) != r) _update((r - 1) >> i);\n    }\n  }\n\n  template <typename F>\n  void\
    \ query(int l, int r, const F& f) {\n    if (l == r) return;\n    l += n, r +=\
    \ n;\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) _push(l\
    \ >> i);\n      if (((r >> i) << i) != r) _push((r - 1) >> i);\n    }\n    while\
    \ (l < r) {\n      if (l & 1) f(v[l++]);\n      if (r & 1) f(v[--r]);\n      l\
    \ >>= 1;\n      r >>= 1;\n    }\n  }\n\n private:\n  void _push(int i) { v[i].push(v[2\
    \ * i + 0], v[2 * i + 1]); }\n  void _update(int i) { v[i].update(v[2 * i + 0],\
    \ v[2 * i + 1]); }\n  template <typename T>\n  void _apply(int i, T x) {\n   \
    \ bool res = v[i].apply(x);\n    if (i < n && res == false) {\n      _push(i);\n\
    \      _apply(i * 2 + 0, x);\n      _apply(i * 2 + 1, x);\n      _update(i);\n\
    \    }\n  }\n};\n\n/**\n * @brief \u62BD\u8C61\u5316Segment Tree Beats!\n * @docs\
    \ docs/segment-tree/segment-tree-beats-abstract.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/segment-tree-beats-abstract.hpp
  requiredBy: []
  timestamp: '2021-02-10 23:32:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-0880.test.cpp
  - verify/verify-yuki/yuki-0879.test.cpp
documentation_of: segment-tree/segment-tree-beats-abstract.hpp
layout: document
redirect_from:
- /library/segment-tree/segment-tree-beats-abstract.hpp
- /library/segment-tree/segment-tree-beats-abstract.hpp.html
title: "\u62BD\u8C61\u5316Segment Tree Beats!"
---
## 抽象化Segment Tree Beats

Segment Tree Beatsの抽象化ライブラリ。

#### 使い方

次の関数を備えた構造体`Node`を載せて使用する。

- `Node()`:　デフォルトコンストラクタ。
- `Node(T)`: コンストラクタ。
- `void update(Node& l, Node& r)`: 子の情報を元に更新する関数。
- `void push(Node& l, Node& r)`:　子に親の情報を遅延して伝える関数。
- `bool apply(U x)`:　作用素を作用させて、更新に成功したら`true`、失敗したら`false`を返す関数。

`Beats`構造体の持つ関数は以下の通り。

- `Beats(vector<T> &v)`:　`Node`構造体を初期化できる型`T`の列を初期値として初期化する。
- `apply(int l, int r, U x)`: `U`を区間$[l, r)$に作用させる。
- `query(int l, int r, const F& f)`: 各区間に対して`f(Node &n)`を行う関数。クエリの取得に利用する。
