---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lct/link-cut-base.hpp
    title: Link/Cut Tree(base)
  - icon: ':heavy_check_mark:'
    path: lct/reversible-bbst-base.hpp
    title: "\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\
      \u30E9\u30B9)"
  - icon: ':heavy_check_mark:'
    path: lct/splay-base.hpp
    title: Splay Tree(base)
  - icon: ':heavy_check_mark:'
    path: lct/splay-reversible.hpp
    title: "\u53CD\u8EE2\u53EF\u80FDSplay Tree"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-path-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/lct/link-cut-tree.md
    document_title: Link/Cut Tree
    links: []
  bundledCode: "#line 2 \"lct/link-cut-tree.hpp\"\n\n#line 2 \"lct/splay-reversible.hpp\"\
    \n\n#line 2 \"lct/reversible-bbst-base.hpp\"\n\ntemplate <typename Tree, typename\
    \ Node, typename T, T (*f)(T, T), T (*ts)(T)>\nstruct ReversibleBBST : Tree {\n\
    \  using Tree::merge;\n  using Tree::split;\n  using typename Tree::Ptr;\n\n \
    \ ReversibleBBST() = default;\n\n  virtual void toggle(Ptr t) {\n    swap(t->l,\
    \ t->r);\n    t->sum = ts(t->sum);\n    t->rev ^= true;\n  }\n\n  T fold(Ptr &t,\
    \ int a, int b) {\n    auto x = split(t, a);\n    auto y = split(x.second, b -\
    \ a);\n    auto ret = sum(y.first);\n    t = merge(x.first, merge(y.first, y.second));\n\
    \    return ret;\n  }\n\n  void reverse(Ptr &t, int a, int b) {\n    auto x =\
    \ split(t, a);\n    auto y = split(x.second, b - a);\n    toggle(y.first);\n \
    \   t = merge(x.first, merge(y.first, y.second));\n  }\n\n  Ptr update(Ptr t)\
    \ override {\n    if (!t) return t;\n    t->cnt = 1;\n    t->sum = t->key;\n \
    \   if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n    if (t->r)\
    \ t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);\n    return t;\n  }\n\n\
    \ protected:\n  inline T sum(const Ptr t) { return t ? t->sum : T(); }\n\n  void\
    \ push(Ptr t) override {\n    if (!t) return;\n    if (t->rev) {\n      if (t->l)\
    \ toggle(t->l);\n      if (t->r) toggle(t->r);\n      t->rev = false;\n    }\n\
    \  }\n};\n\n/**\n * @brief \u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728\
    (\u57FA\u5E95\u30AF\u30E9\u30B9)\n */\n#line 2 \"lct/splay-base.hpp\"\n\ntemplate\
    \ <typename Node>\nstruct SplayTreeBase {\n  using Ptr = Node *;\n  template <typename...\
    \ Args>\n  Ptr my_new(const Args &... args) {\n    return new Node(args...);\n\
    \  }\n  void my_del(Ptr p) { delete p; }\n\n  bool is_root(Ptr t) { return !(t->p)\
    \ || (t->p->l != t && t->p->r != t); }\n\n  int size(Ptr t) const { return count(t);\
    \ }\n\n  virtual void splay(Ptr t) {\n    push(t);\n    while (!is_root(t)) {\n\
    \      Ptr q = t->p;\n      if (is_root(q)) {\n        push(q), push(t);\n   \
    \     rot(t);\n      } else {\n        Ptr r = q->p;\n        push(r), push(q),\
    \ push(t);\n        if (pos(q) == pos(t))\n          rot(q), rot(t);\n       \
    \ else\n          rot(t), rot(t);\n      }\n    }\n  }\n\n  Ptr get_left(Ptr t)\
    \ {\n    while (t->l) push(t), t = t->l;\n    return t;\n  }\n\n  Ptr get_right(Ptr\
    \ t) {\n    while (t->r) push(t), t = t->r;\n    return t;\n  }\n\n  pair<Ptr,\
    \ Ptr> split(Ptr t, int k) {\n    if (!t) return {nullptr, nullptr};\n    if (k\
    \ == 0) return {nullptr, t};\n    if (k == count(t)) return {t, nullptr};\n  \
    \  push(t);\n    if (k <= count(t->l)) {\n      auto x = split(t->l, k);\n   \
    \   t->l = x.second;\n      t->p = nullptr;\n      if (x.second) x.second->p =\
    \ t;\n      return {x.first, update(t)};\n    } else {\n      auto x = split(t->r,\
    \ k - count(t->l) - 1);\n      t->r = x.first;\n      t->p = nullptr;\n      if\
    \ (x.first) x.first->p = t;\n      return {update(t), x.second};\n    }\n  }\n\
    \n  Ptr merge(Ptr l, Ptr r) {\n    if (!l && !r) return nullptr;\n    if (!l)\
    \ return splay(r), r;\n    if (!r) return splay(l), l;\n    splay(l), splay(r);\n\
    \    l = get_right(l);\n    splay(l);\n    l->r = r;\n    r->p = l;\n    update(l);\n\
    \    return l;\n  }\n\n  using Key = decltype(Node::key);\n  Ptr build(const vector<Key>\
    \ &v) { return build(0, v.size(), v); }\n  Ptr build(int l, int r, const vector<Key>\
    \ &v) {\n    if (l + 1 >= r) return my_new(v[l]);\n    return merge(build(l, (l\
    \ + r) >> 1, v), build((l + r) >> 1, r, v));\n  }\n\n  template <typename... Args>\n\
    \  void insert(Ptr &t, int k, const Args &... args) {\n    splay(t);\n    auto\
    \ x = split(t, k);\n    t = merge(merge(x.first, my_new(args...)), x.second);\n\
    \  }\n\n  void erase(Ptr &t, int k) {\n    splay(t);\n    auto x = split(t, k);\n\
    \    auto y = split(x.second, 1);\n    my_del(y.first);\n    t = merge(x.first,\
    \ y.second);\n  }\n\n  virtual Ptr update(Ptr t) = 0;\n\n protected:\n  inline\
    \ int count(Ptr t) const { return t ? t->cnt : 0; }\n\n  virtual void push(Ptr\
    \ t) = 0;\n\n  Ptr build(const vector<Ptr> &v) { return build(0, v.size(), v);\
    \ }\n\n  Ptr build(int l, int r, const vector<Ptr> &v) {\n    if (l + 1 >= r)\
    \ return v[l];\n    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1,\
    \ r, v));\n  }\n\n  inline int pos(Ptr t) {\n    if (t->p) {\n      if (t->p->l\
    \ == t) return -1;\n      if (t->p->r == t) return 1;\n    }\n    return 0;\n\
    \  }\n\n  virtual void rot(Ptr t) {\n    Ptr x = t->p, y = x->p;\n    if (pos(t)\
    \ == -1) {\n      if ((x->l = t->r)) t->r->p = x;\n      t->r = x, x->p = t;\n\
    \    } else {\n      if ((x->r = t->l)) t->l->p = x;\n      t->l = x, x->p = t;\n\
    \    }\n    update(x), update(t);\n    if ((t->p = y)) {\n      if (y->l == x)\
    \ y->l = t;\n      if (y->r == x) y->r = t;\n    }\n  }\n};\n\n/**\n * @brief\
    \ Splay Tree(base)\n */\n#line 5 \"lct/splay-reversible.hpp\"\n\ntemplate <typename\
    \ T>\nstruct ReversibleSplayTreeNode {\n  using Ptr = ReversibleSplayTreeNode\
    \ *;\n  Ptr l, r, p;\n  T key, sum;\n  int cnt;\n  bool rev;\n\n  ReversibleSplayTreeNode(const\
    \ T &t = T())\n      : l(), r(), p(), key(t), sum(t), cnt(1), rev(false) {}\n\
    };\n\ntemplate <typename T, T (*f)(T, T), T (*ts)(T)>\nstruct ReversibleSplayTree\n\
    \    : ReversibleBBST<SplayTreeBase<ReversibleSplayTreeNode<T>>,\n           \
    \          ReversibleSplayTreeNode<T>, T, f, ts> {\n  using Node = ReversibleSplayTreeNode<T>;\n\
    };\n\n/**\n * @brief \u53CD\u8EE2\u53EF\u80FDSplay Tree\n */\n#line 4 \"lct/link-cut-tree.hpp\"\
    \n\n//\n#line 2 \"lct/link-cut-base.hpp\"\n\ntemplate <typename Splay>\nstruct\
    \ LinkCutBase : Splay {\n  using Node = typename Splay::Node;\n  using Ptr = Node*;\n\
    \n  virtual Ptr expose(Ptr t) {\n    Ptr rp = nullptr;\n    for (Ptr cur = t;\
    \ cur; cur = cur->p) {\n      this->splay(cur);\n      cur->r = rp;\n      this->update(cur);\n\
    \      rp = cur;\n    }\n    this->splay(t);\n    return rp;\n  }\n\n  virtual\
    \ void link(Ptr u, Ptr v) {\n    evert(u);\n    expose(v);\n    u->p = v;\n  }\n\
    \n  void cut(Ptr u, Ptr v) {\n    evert(u);\n    expose(v);\n    assert(u->p ==\
    \ v);\n    v->l = u->p = nullptr;\n    this->update(v);\n  }\n\n  void evert(Ptr\
    \ t) {\n    expose(t);\n    this->toggle(t);\n    this->push(t);\n  }\n\n  Ptr\
    \ lca(Ptr u, Ptr v) {\n    if (get_root(u) != get_root(v)) return nullptr;\n \
    \   expose(u);\n    return expose(v);\n  }\n\n  Ptr get_kth(Ptr x, int k) {\n\
    \    expose(x);\n    while (x) {\n      this->push(x);\n      if (x->r && x->r->sz\
    \ > k) {\n        x = x->r;\n      } else {\n        if (x->r) k -= x->r->sz;\n\
    \        if (k == 0) return x;\n        k -= 1;\n        x = x->l;\n      }\n\
    \    }\n    return nullptr;\n  }\n\n  Ptr get_root(Ptr x) {\n    expose(x);\n\
    \    while (x->l) this->push(x), x = x->l;\n    return x;\n  }\n\n  Ptr get_parent(Ptr\
    \ x) {\n    expose(x);\n    Ptr p = x->l;\n    if(p == nullptr) return nullptr;\n\
    \    while (true) {\n      this->push(p);\n      if (p->r == nullptr) return p;\n\
    \      p = p->r;\n    }\n    exit(1);\n  }\n\n  virtual void set_key(Ptr t, const\
    \ decltype(Node::key)& key) {\n    this->splay(t);\n    t->key = key;\n    this->update(t);\n\
    \  }\n\n  virtual decltype(Node::key) get_key(Ptr t) { return t->key; }\n\n  decltype(Node::key)\
    \ fold(Ptr u, Ptr v) {\n    evert(u);\n    expose(v);\n    return v->sum;\n  }\n\
    };\n\n/**\n * @brief Link/Cut Tree(base)\n * @docs docs/lct/link-cut-tree.md\n\
    \ */\n#line 7 \"lct/link-cut-tree.hpp\"\n\ntemplate <typename T, T (*f)(T, T),\
    \ T (*ts)(T)>\nstruct LinkCutTree : LinkCutBase<ReversibleSplayTree<T, f, ts>>\
    \ {};\n\n/**\n * @brief Link/Cut Tree\n * @docs docs/lct/link-cut-tree.md\n */\n"
  code: "#pragma once\n\n#include \"splay-reversible.hpp\"\n\n//\n#include \"link-cut-base.hpp\"\
    \n\ntemplate <typename T, T (*f)(T, T), T (*ts)(T)>\nstruct LinkCutTree : LinkCutBase<ReversibleSplayTree<T,\
    \ f, ts>> {};\n\n/**\n * @brief Link/Cut Tree\n * @docs docs/lct/link-cut-tree.md\n\
    \ */\n"
  dependsOn:
  - lct/splay-reversible.hpp
  - lct/reversible-bbst-base.hpp
  - lct/splay-base.hpp
  - lct/link-cut-base.hpp
  isVerificationFile: false
  path: lct/link-cut-tree.hpp
  requiredBy: []
  timestamp: '2021-04-26 00:32:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-path-sum.test.cpp
documentation_of: lct/link-cut-tree.hpp
layout: document
redirect_from:
- /library/lct/link-cut-tree.hpp
- /library/lct/link-cut-tree.hpp.html
title: Link/Cut Tree
---
## Link/Cut Tree

木の回転・辺の削除・辺の追加などを$\mathrm{O}(\log n)$で行うライブラリ。

### 概要

忘れないうちに簡潔にまとめる。

#### 情報の持ち方

参考：[うしさんの非常に分かりやすい資料](https://ei1333.hateblo.jp/entry/2018/05/29/011140)

- (反転可能Splay Treeの実装は前提知識とする)

- Link Cut Treeの内部では木を根付き木として管理している

- 重軽分解のようにPreferred EdgeとNormal Edgeの二つに塗り分けられていて、一つの頂点から子に生えるPreferred Edgeは高々1つ

- Preferred Edgeからなるパス、Preferred Pathの内部の点は深さを比較関数としたSplay Treeに載せられている

  - Preferred Pathは内部の実装では双方向にリンクしている。つまり、uの左の頂点がvの場合`u->l == v && v->p == u`が成り立つ

- Preferred Pathの最も根に近い頂点を`v`と置くと、`v`が木全体の根でないとき`v`の親`u`へのパス(Normal Path)が存在する。このパスは、**`v`の所属する平衡二分木の根**から`u`に向けて(根の方向に)生えているとみなす
  - Normal Pathは片方向にリンクしている。つまり、`(vの所属するSplay Treeの根)->p == u`であるが`u`は`v`に関する情報を持たない

#### `expose`

- 以上に説明した方法で木を管理したとき、内部でのポインタ操作によってPreferred EdgeとNormal Edgeを入れ替えることが出来る

  - `splay(u), u->r = nullptr`　$\leftrightarrow$ `u`から子に生えるPreferred EdgeをNormal Edgeに替える
  - `v`から`u`にNormal Edgeが生えているとき、`splay(u), u->r = v` $\leftrightarrow$ `u`から子に生えるPreferred EdgeをNormal Edgeに替える

- 上の二つを組み合わせると、Link Cut Treeの核である`expose(x)`：根から`x`までのパスをPreferred Edgeからなるパスにする関数を実装できる

```
Ptr expose(Ptr t) {
  Ptr rp = nullptr;
  for(Ptr cur = t; cur; ) {
    splay(cur); 
    // Preferred Edgeをxの所属する辺につなぎかえる
    cur->r = rp; 
    // curの子に関する情報を更新する
    update(cur);
    // 次の親に渡すポインタをメモする
    rp = cur; 
    // 次のPreferred Edgeに移動
    cur = cur->p;
  }
  splay(t);
  return rp;
}
```

#### その他の関数

- `expose`を利用すれば`link/cut`をはじめとした様々な関数を実装できる

- `evert(u)`: 頂点`u`を木全体の根とする
  - `expose(u)`した後に`toggle(u)`するだけ
    - Preferred Edgeの最も根から遠い頂点に対して`splay(u), toggle(u)`をするとsplay Treeの順序関係が反転するため`u`がPreferred Edgeの根側になる

- `link(u, v)`: 頂点`u`と頂点`v`をつなぐ(`u, v`は連結成分でないことを仮定)
  - `u`の親を`v`にすることを考える
  - `evert(u)`することで`u`を木全体の根とする
    - `expose(u)`でも内部的には`u->p = nullptr`になるが、実際の木は`u`の親が存在するため破綻する
  - `expose(v)`する
  - `u->p = v`として`u`と`v`をNormal Edgeでつなぐ
    - `evert(u)`または`expose(u)`した頂点は親が`nullptr`になっていることを利用
  - 疑問点: linkするだけなら`expose(v)`いらなくない？`evert(u), u->p = v`でいい気がする
    - [Gifted Infantの実装](http://yosupo06.github.io/Algorithm/src/datastructure/linkcuttree.hpp)は`evert(u), expose(v)`している
    - [kimiyukiさんの提出](https://judge.yosupo.jp/submission/4151)だと`expose(v)`の行に`// for the time complexity`と書いてある
    - [Library Checkerのfastest](https://judge.yosupo.jp/submission/31941)だと`expose(v)`していない
    - 以上をまとめると「あっても無くても良さそう？計算量解析に踏み入らないと理由はわからなそう？」という結論に
    - パス加算クエリや部分木クエリに対応するときは`expose(v)`は必要そう(根方向からの伝播を反映させる必要があるため)

- `cut(u, v)`：頂点`u`,`v`を切り離す
  - `evert(u), expose(v)`する
  - この時`v->l == u`になっている
  - `v->l = u->p = nullptr`とすれば辺が切れる

- 実装の際は評価更新用の関数`update()`と評価伝播用の関数`push()`を適切に入れる必要がある
  - 子の辺を張り変える**前**は`push()`で伝播させる
  - 子の辺を張り変えた**後**は`update()`で新しい子の情報を更新する

#### 使い方

- `expose(u)`：根から`u`までのパスをPreferred Edgeからなるパスにする
- `evert(u)`: 頂点`u`を木全体の根とする
- `link(u, v)`: 頂点`u`と頂点`v`をつなぐ(`u, v`は連結成分でないことを仮定)
- `cut(u, v)`：頂点`u`,`v`を切り離す
- `get_root(u)`：`u`の所属する木の根を返す
- `set_key(u, key)`：頂点`u`の`key`を書き換える
- `get_key(u, key)`：頂点`u`の`key`の値を得る
- `fold(u, v)` : `u, v`間のパスの`key`の和を得る
