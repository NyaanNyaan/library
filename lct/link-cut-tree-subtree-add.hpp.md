---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-tree-subtree-add-subtree-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-tree-subtree-add-subtree-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-subtree-sum-2.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-subtree-sum-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u90E8\u5206\u6728\u52A0\u7B97\u30AF\u30A8\u30EALink/Cut Tree"
    links: []
  bundledCode: "#line 2 \"lct/link-cut-tree-subtree-add.hpp\"\n\ntemplate <typename\
    \ T, T (*add)(T, T), T (*sub)(T, T), T (*mul)(T, long long)>\nstruct LinkCutForSubtreeNode\
    \ {\n  using Node = LinkCutForSubtreeNode;\n  using Ptr = LinkCutForSubtreeNode*;\n\
    \  Ptr l, r, p;\n  T key, sum, lazy, cancel, subsum;\n  int cnt, subcnt;\n  bool\
    \ rev;\n\n  LinkCutForSubtreeNode(const T& t = T())\n      : l(),\n        r(),\n\
    \        p(),\n        key(t),\n        sum(t),\n        lazy(T()),\n        cancel(T()),\n\
    \        subsum(T()),\n        cnt(1),\n        subcnt(0),\n        rev(false)\
    \ {}\n  void make_normal(Ptr other) {\n    subsum = add(subsum, other->sum);\n\
    \    subcnt += other->cnt;\n  }\n  void make_prefer(Ptr other) {\n    subsum =\
    \ sub(subsum, other->sum);\n    subcnt -= other->cnt;\n  }\n  void merge(Ptr n1,\
    \ Ptr n2) {\n    sum = add(add(n1 ? n1->sum : T(), key), add(subsum, n2 ? n2->sum\
    \ : T()));\n    cnt = 1 + (n1 ? n1->cnt : 0) + (n2 ? n2->cnt : 0) + subcnt;\n\
    \    if (n1) n1->cancel = lazy;\n    if (n2) n2->cancel = lazy;\n  }\n  void apply(const\
    \ T& add_val) {\n    key = add(key, add_val);\n    sum = add(sum, mul(add_val,\
    \ cnt));\n    lazy = add(lazy, add_val);\n    subsum = add(subsum, mul(add_val,\
    \ subcnt));\n  }\n  void fetch() {\n    if (!p) return;\n    apply(p->lazy - cancel);\n\
    \    cancel = p->lazy;\n  }\n};\n\ntemplate <typename T, T (*add)(T, T), T (*sub)(T,\
    \ T), T (*mul)(T, long long)>\nstruct LinkCutTreeSubtreeQuery {\n  using Node\
    \ = LinkCutForSubtreeNode<T, add, sub, mul>;\n  using Ptr = Node*;\n\n  void push_rev(Ptr\
    \ t) {\n    if (!t) return;\n    if (t->rev) {\n      if (t->l) toggle(t->l);\n\
    \      if (t->r) toggle(t->r);\n      t->rev = false;\n    }\n  }\n\n  void push(Ptr\
    \ t) {\n    if (!t) return;\n    if (t->rev) {\n      if (t->l) toggle(t->l);\n\
    \      if (t->r) toggle(t->r);\n      t->rev = false;\n    }\n    if (t->l) t->l->fetch();\n\
    \    if (t->r) t->r->fetch();\n  }\n\n  Ptr update(Ptr t) {\n    if (!t) return\
    \ t;\n    t->merge(t->l, t->r);\n    return t;\n  }\n\n  void splay(Ptr t) {\n\
    \    push(t);\n    while (!is_root(t)) {\n      Ptr q = t->p;\n      if (is_root(q))\
    \ {\n        push_rev(q), push_rev(t);\n        rot(t);\n      } else {\n    \
    \    Ptr r = q->p;\n        push_rev(r), push_rev(q), push_rev(t);\n        if\
    \ (pos(q) == pos(t))\n          rot(q), rot(t);\n        else\n          rot(t),\
    \ rot(t);\n      }\n    }\n  }\n\n  Ptr expose(Ptr t) {\n    Ptr rp = nullptr;\n\
    \    for (Ptr cur = t; cur; cur = cur->p) {\n      splay(cur), push(cur);\n  \
    \    if (cur->r) cur->make_normal(cur->r);\n      if (rp) rp->fetch(), cur->make_prefer(rp);\n\
    \      cur->r = rp;\n      rp = cur;\n    }\n    splay(t);\n    return rp;\n \
    \ }\n\n  void evert(Ptr t) {\n    expose(t);\n    toggle(t);\n    push(t);\n \
    \ }\n\n  void link(Ptr u, Ptr v) {\n    evert(u);\n    expose(v);\n    u->p =\
    \ v, v->r = u;\n    update(v);\n  }\n\n  void cut(Ptr u, Ptr v) {\n    evert(u);\n\
    \    expose(v);\n    v->l = u->p = nullptr;\n    update(v);\n  }\n\n  void toggle(Ptr\
    \ t) {\n    swap(t->l, t->r);\n    t->rev ^= true;\n  }\n\n  T get_key(Ptr t)\
    \ {\n    expose(t);\n    return t->key;\n  }\n\n  void set_key(Ptr t, const T&\
    \ key) {\n    expose(t);\n    t->key = key;\n    update(t);\n  }\n\n  void subtree_add(Ptr\
    \ t, const T& add_val) {\n    expose(t);\n    Ptr l = t->l;\n    if (l) t->l =\
    \ nullptr, update(t);\n    t->apply(add_val);\n    if (l) t->l = l, update(t);\n\
    \  }\n\n  T subtree_sum(Ptr t) {\n    expose(t);\n    return add(t->key, t->subsum);\n\
    \  }\n\n  Ptr get_root(Ptr x) {\n    expose(x);\n    while (x->l) this->push(x),\
    \ x = x->l;\n    return x;\n  }\n\n protected:\n  bool is_root(Ptr t) { return\
    \ !(t->p) || (t->p->l != t && t->p->r != t); }\n\n  inline int pos(Ptr t) {\n\
    \    if (t->p) {\n      if (t->p->l == t) return -1;\n      if (t->p->r == t)\
    \ return 1;\n    }\n    return 0;\n  }\n\n  void rot(Ptr t) {\n    Ptr x = t->p,\
    \ y = x->p;\n    push(x), push(t);\n    if (pos(t) == -1) {\n      if ((x->l =\
    \ t->r)) t->r->p = x;\n      t->r = x, x->p = t;\n    } else {\n      if ((x->r\
    \ = t->l)) t->l->p = x;\n      t->l = x, x->p = t;\n    }\n    T xc = x->cancel;\n\
    \    update(x), update(t);\n    t->cancel = xc;\n    if ((t->p = y)) {\n     \
    \ if (y->l == x) y->l = t;\n      if (y->r == x) y->r = t;\n    }\n  }\n};\n\n\
    /**\n * @brief \u90E8\u5206\u6728\u52A0\u7B97\u30AF\u30A8\u30EALink/Cut Tree\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <typename T, T (*add)(T, T), T (*sub)(T, T), T (*mul)(T,\
    \ long long)>\nstruct LinkCutForSubtreeNode {\n  using Node = LinkCutForSubtreeNode;\n\
    \  using Ptr = LinkCutForSubtreeNode*;\n  Ptr l, r, p;\n  T key, sum, lazy, cancel,\
    \ subsum;\n  int cnt, subcnt;\n  bool rev;\n\n  LinkCutForSubtreeNode(const T&\
    \ t = T())\n      : l(),\n        r(),\n        p(),\n        key(t),\n      \
    \  sum(t),\n        lazy(T()),\n        cancel(T()),\n        subsum(T()),\n \
    \       cnt(1),\n        subcnt(0),\n        rev(false) {}\n  void make_normal(Ptr\
    \ other) {\n    subsum = add(subsum, other->sum);\n    subcnt += other->cnt;\n\
    \  }\n  void make_prefer(Ptr other) {\n    subsum = sub(subsum, other->sum);\n\
    \    subcnt -= other->cnt;\n  }\n  void merge(Ptr n1, Ptr n2) {\n    sum = add(add(n1\
    \ ? n1->sum : T(), key), add(subsum, n2 ? n2->sum : T()));\n    cnt = 1 + (n1\
    \ ? n1->cnt : 0) + (n2 ? n2->cnt : 0) + subcnt;\n    if (n1) n1->cancel = lazy;\n\
    \    if (n2) n2->cancel = lazy;\n  }\n  void apply(const T& add_val) {\n    key\
    \ = add(key, add_val);\n    sum = add(sum, mul(add_val, cnt));\n    lazy = add(lazy,\
    \ add_val);\n    subsum = add(subsum, mul(add_val, subcnt));\n  }\n  void fetch()\
    \ {\n    if (!p) return;\n    apply(p->lazy - cancel);\n    cancel = p->lazy;\n\
    \  }\n};\n\ntemplate <typename T, T (*add)(T, T), T (*sub)(T, T), T (*mul)(T,\
    \ long long)>\nstruct LinkCutTreeSubtreeQuery {\n  using Node = LinkCutForSubtreeNode<T,\
    \ add, sub, mul>;\n  using Ptr = Node*;\n\n  void push_rev(Ptr t) {\n    if (!t)\
    \ return;\n    if (t->rev) {\n      if (t->l) toggle(t->l);\n      if (t->r) toggle(t->r);\n\
    \      t->rev = false;\n    }\n  }\n\n  void push(Ptr t) {\n    if (!t) return;\n\
    \    if (t->rev) {\n      if (t->l) toggle(t->l);\n      if (t->r) toggle(t->r);\n\
    \      t->rev = false;\n    }\n    if (t->l) t->l->fetch();\n    if (t->r) t->r->fetch();\n\
    \  }\n\n  Ptr update(Ptr t) {\n    if (!t) return t;\n    t->merge(t->l, t->r);\n\
    \    return t;\n  }\n\n  void splay(Ptr t) {\n    push(t);\n    while (!is_root(t))\
    \ {\n      Ptr q = t->p;\n      if (is_root(q)) {\n        push_rev(q), push_rev(t);\n\
    \        rot(t);\n      } else {\n        Ptr r = q->p;\n        push_rev(r),\
    \ push_rev(q), push_rev(t);\n        if (pos(q) == pos(t))\n          rot(q),\
    \ rot(t);\n        else\n          rot(t), rot(t);\n      }\n    }\n  }\n\n  Ptr\
    \ expose(Ptr t) {\n    Ptr rp = nullptr;\n    for (Ptr cur = t; cur; cur = cur->p)\
    \ {\n      splay(cur), push(cur);\n      if (cur->r) cur->make_normal(cur->r);\n\
    \      if (rp) rp->fetch(), cur->make_prefer(rp);\n      cur->r = rp;\n      rp\
    \ = cur;\n    }\n    splay(t);\n    return rp;\n  }\n\n  void evert(Ptr t) {\n\
    \    expose(t);\n    toggle(t);\n    push(t);\n  }\n\n  void link(Ptr u, Ptr v)\
    \ {\n    evert(u);\n    expose(v);\n    u->p = v, v->r = u;\n    update(v);\n\
    \  }\n\n  void cut(Ptr u, Ptr v) {\n    evert(u);\n    expose(v);\n    v->l =\
    \ u->p = nullptr;\n    update(v);\n  }\n\n  void toggle(Ptr t) {\n    swap(t->l,\
    \ t->r);\n    t->rev ^= true;\n  }\n\n  T get_key(Ptr t) {\n    expose(t);\n \
    \   return t->key;\n  }\n\n  void set_key(Ptr t, const T& key) {\n    expose(t);\n\
    \    t->key = key;\n    update(t);\n  }\n\n  void subtree_add(Ptr t, const T&\
    \ add_val) {\n    expose(t);\n    Ptr l = t->l;\n    if (l) t->l = nullptr, update(t);\n\
    \    t->apply(add_val);\n    if (l) t->l = l, update(t);\n  }\n\n  T subtree_sum(Ptr\
    \ t) {\n    expose(t);\n    return add(t->key, t->subsum);\n  }\n\n  Ptr get_root(Ptr\
    \ x) {\n    expose(x);\n    while (x->l) this->push(x), x = x->l;\n    return\
    \ x;\n  }\n\n protected:\n  bool is_root(Ptr t) { return !(t->p) || (t->p->l !=\
    \ t && t->p->r != t); }\n\n  inline int pos(Ptr t) {\n    if (t->p) {\n      if\
    \ (t->p->l == t) return -1;\n      if (t->p->r == t) return 1;\n    }\n    return\
    \ 0;\n  }\n\n  void rot(Ptr t) {\n    Ptr x = t->p, y = x->p;\n    push(x), push(t);\n\
    \    if (pos(t) == -1) {\n      if ((x->l = t->r)) t->r->p = x;\n      t->r =\
    \ x, x->p = t;\n    } else {\n      if ((x->r = t->l)) t->l->p = x;\n      t->l\
    \ = x, x->p = t;\n    }\n    T xc = x->cancel;\n    update(x), update(t);\n  \
    \  t->cancel = xc;\n    if ((t->p = y)) {\n      if (y->l == x) y->l = t;\n  \
    \    if (y->r == x) y->r = t;\n    }\n  }\n};\n\n/**\n * @brief \u90E8\u5206\u6728\
    \u52A0\u7B97\u30AF\u30A8\u30EALink/Cut Tree\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: lct/link-cut-tree-subtree-add.hpp
  requiredBy: []
  timestamp: '2021-01-31 21:16:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-dynamic-tree-subtree-add-subtree-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-subtree-sum-2.test.cpp
documentation_of: lct/link-cut-tree-subtree-add.hpp
layout: document
redirect_from:
- /library/lct/link-cut-tree-subtree-add.hpp
- /library/lct/link-cut-tree-subtree-add.hpp.html
title: "\u90E8\u5206\u6728\u52A0\u7B97\u30AF\u30A8\u30EALink/Cut Tree"
---
