---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lct/link-cut-tree-lazy.hpp
    title: "\u9045\u5EF6\u4F1D\u642CLink/Cut Tree"
  - icon: ':heavy_check_mark:'
    path: lct/link-cut-tree-subtree.hpp
    title: "\u90E8\u5206\u6728\u30AF\u30A8\u30EALink/Cut Tree"
  - icon: ':heavy_check_mark:'
    path: lct/link-cut-tree.hpp
    title: Link/Cut Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-path-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-subtree-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-subtree-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Link Cut Tree(base)
    links: []
  bundledCode: "#line 2 \"lct/link-cut-base.hpp\"\n\ntemplate <typename Splay>\nstruct\
    \ LinkCutBase : Splay {\n  using Node = typename Splay::Node;\n  using Ptr = Node*;\n\
    \n  virtual Ptr expose(Ptr t) {\n    Ptr rp = nullptr;\n    for (Ptr cur = t;\
    \ cur; cur = cur->p) {\n      this->splay(cur);\n      cur->r = rp;\n      this->update(cur);\n\
    \      rp = cur;\n    }\n    this->splay(t);\n    return rp;\n  }\n\n  virtual\
    \ void link(Ptr u, Ptr v) {\n    evert(u);\n    expose(v);\n    u->p = v;\n  }\n\
    \n  void cut(Ptr u, Ptr v) {\n    evert(u);\n    expose(v);\n    v->l = u->p =\
    \ nullptr;\n    this->update(v);\n  }\n\n  void evert(Ptr t) {\n    expose(t);\n\
    \    this->toggle(t);\n    this->push(t);\n  }\n\n  Ptr lca(Ptr u, Ptr v) {\n\
    \    if (get_root(u) != get_root(v)) return nullptr;\n    expose(u);\n    return\
    \ expose(v);\n  }\n\n  Ptr get_kth(Ptr x, int k) {\n    expose(x);\n    while\
    \ (x) {\n      this->push(x);\n      if (x->r && x->r->sz > k) {\n        x =\
    \ x->r;\n      } else {\n        if (x->r) k -= x->r->sz;\n        if (k == 0)\
    \ return x;\n        k -= 1;\n        x = x->l;\n      }\n    }\n    return nullptr;\n\
    \  }\n\n  Ptr get_root(Ptr x) {\n    expose(x);\n    while (x->l) this->push(x),\
    \ x = x->l;\n    return x;\n  }\n\n  virtual void set_key(Ptr t, const decltype(Node::key)&\
    \ key) {\n    this->splay(t);\n    t->key = key;\n    this->update(t);\n  }\n\n\
    \  decltype(Node::key) get_key(Ptr t) { return t->key; }\n\n  decltype(Node::key)\
    \ fold(Ptr u, Ptr v) {\n    evert(u);\n    expose(v);\n    return v->sum;\n  }\n\
    };\n\n/**\n * @brief Link Cut Tree(base)\n */\n"
  code: "#pragma once\n\ntemplate <typename Splay>\nstruct LinkCutBase : Splay {\n\
    \  using Node = typename Splay::Node;\n  using Ptr = Node*;\n\n  virtual Ptr expose(Ptr\
    \ t) {\n    Ptr rp = nullptr;\n    for (Ptr cur = t; cur; cur = cur->p) {\n  \
    \    this->splay(cur);\n      cur->r = rp;\n      this->update(cur);\n      rp\
    \ = cur;\n    }\n    this->splay(t);\n    return rp;\n  }\n\n  virtual void link(Ptr\
    \ u, Ptr v) {\n    evert(u);\n    expose(v);\n    u->p = v;\n  }\n\n  void cut(Ptr\
    \ u, Ptr v) {\n    evert(u);\n    expose(v);\n    v->l = u->p = nullptr;\n   \
    \ this->update(v);\n  }\n\n  void evert(Ptr t) {\n    expose(t);\n    this->toggle(t);\n\
    \    this->push(t);\n  }\n\n  Ptr lca(Ptr u, Ptr v) {\n    if (get_root(u) !=\
    \ get_root(v)) return nullptr;\n    expose(u);\n    return expose(v);\n  }\n\n\
    \  Ptr get_kth(Ptr x, int k) {\n    expose(x);\n    while (x) {\n      this->push(x);\n\
    \      if (x->r && x->r->sz > k) {\n        x = x->r;\n      } else {\n      \
    \  if (x->r) k -= x->r->sz;\n        if (k == 0) return x;\n        k -= 1;\n\
    \        x = x->l;\n      }\n    }\n    return nullptr;\n  }\n\n  Ptr get_root(Ptr\
    \ x) {\n    expose(x);\n    while (x->l) this->push(x), x = x->l;\n    return\
    \ x;\n  }\n\n  virtual void set_key(Ptr t, const decltype(Node::key)& key) {\n\
    \    this->splay(t);\n    t->key = key;\n    this->update(t);\n  }\n\n  decltype(Node::key)\
    \ get_key(Ptr t) { return t->key; }\n\n  decltype(Node::key) fold(Ptr u, Ptr v)\
    \ {\n    evert(u);\n    expose(v);\n    return v->sum;\n  }\n};\n\n/**\n * @brief\
    \ Link Cut Tree(base)\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: lct/link-cut-base.hpp
  requiredBy:
  - lct/link-cut-tree.hpp
  - lct/link-cut-tree-subtree.hpp
  - lct/link-cut-tree-lazy.hpp
  timestamp: '2020-12-18 14:55:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-path-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-subtree-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp
documentation_of: lct/link-cut-base.hpp
layout: document
redirect_from:
- /library/lct/link-cut-base.hpp
- /library/lct/link-cut-base.hpp.html
title: Link Cut Tree(base)
---
