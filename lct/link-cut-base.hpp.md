---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Link Cut Tree
    links: []
  bundledCode: "#line 2 \"lct/link-cut-base.hpp\"\n\ntemplate <typename Splay>\nstruct\
    \ LinkCutTree : Splay {\n  using Node = typename Splay::Node;\n  using Ptr = Node*;\n\
    \n  Ptr expose(Ptr t) {\n    Ptr rp = nullptr;\n    for (Ptr cur = t; cur; cur\
    \ = cur->p) {\n      this->splay(cur);\n      cur->r = rp;\n      this->update(cur);\n\
    \      rp = cur;\n    }\n    this->splay(t);\n    return rp;\n  }\n\n  void link(Ptr\
    \ u, Ptr v) {\n    evert(u);\n    expose(v);\n    u->p = v;\n  }\n\n  void cut(Ptr\
    \ u, Ptr v) {\n    evert(u);\n    expose(v);\n    assert(v->l == u);\n    v->l\
    \ = u->p = nullptr;\n    this->update(v);\n  }\n\n  void evert(Ptr t) {\n    expose(t);\n\
    \    this->toggle(t);\n    this->push(t);\n  }\n\n  Ptr lca(Ptr u, Ptr v) {\n\
    \    if (get_root(u) != get_root(v)) return nullptr;\n    expose(u);\n    return\
    \ expose(v);\n  }\n\n  Ptr get_kth(Ptr x, int k) {\n    expose(x);\n    while\
    \ (x) {\n      this->push(x);\n      if (x->r && x->r->sz > k) {\n        x =\
    \ x->r;\n      } else {\n        if (x->r) k -= x->r->sz;\n        if (k == 0)\
    \ return x;\n        k -= 1;\n        x = x->l;\n      }\n    }\n    return nullptr;\n\
    \  }\n\n  Ptr get_root(Ptr x) {\n    expose(x);\n    while (x->l) this->push(x),\
    \ x = x->l;\n    return x;\n  }\n\n  void vertex_set(Ptr t, const decltype(Node::key)&\
    \ key) {\n    this->splay(t);\n    t->key = key;\n    this->update(t);\n  }\n\n\
    \  decltype(Node::key) fold(Ptr u, Ptr v) {\n    evert(u);\n    expose(v);\n \
    \   return v->sum;\n  }\n};\n\n/**\n * @brief Link Cut Tree\n */\n"
  code: "#pragma once\n\ntemplate <typename Splay>\nstruct LinkCutTree : Splay {\n\
    \  using Node = typename Splay::Node;\n  using Ptr = Node*;\n\n  Ptr expose(Ptr\
    \ t) {\n    Ptr rp = nullptr;\n    for (Ptr cur = t; cur; cur = cur->p) {\n  \
    \    this->splay(cur);\n      cur->r = rp;\n      this->update(cur);\n      rp\
    \ = cur;\n    }\n    this->splay(t);\n    return rp;\n  }\n\n  void link(Ptr u,\
    \ Ptr v) {\n    evert(u);\n    expose(v);\n    u->p = v;\n  }\n\n  void cut(Ptr\
    \ u, Ptr v) {\n    evert(u);\n    expose(v);\n    assert(v->l == u);\n    v->l\
    \ = u->p = nullptr;\n    this->update(v);\n  }\n\n  void evert(Ptr t) {\n    expose(t);\n\
    \    this->toggle(t);\n    this->push(t);\n  }\n\n  Ptr lca(Ptr u, Ptr v) {\n\
    \    if (get_root(u) != get_root(v)) return nullptr;\n    expose(u);\n    return\
    \ expose(v);\n  }\n\n  Ptr get_kth(Ptr x, int k) {\n    expose(x);\n    while\
    \ (x) {\n      this->push(x);\n      if (x->r && x->r->sz > k) {\n        x =\
    \ x->r;\n      } else {\n        if (x->r) k -= x->r->sz;\n        if (k == 0)\
    \ return x;\n        k -= 1;\n        x = x->l;\n      }\n    }\n    return nullptr;\n\
    \  }\n\n  Ptr get_root(Ptr x) {\n    expose(x);\n    while (x->l) this->push(x),\
    \ x = x->l;\n    return x;\n  }\n\n  void vertex_set(Ptr t, const decltype(Node::key)&\
    \ key) {\n    this->splay(t);\n    t->key = key;\n    this->update(t);\n  }\n\n\
    \  decltype(Node::key) fold(Ptr u, Ptr v) {\n    evert(u);\n    expose(v);\n \
    \   return v->sum;\n  }\n};\n\n/**\n * @brief Link Cut Tree\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: lct/link-cut-base.hpp
  requiredBy: []
  timestamp: '2020-12-17 14:25:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
documentation_of: lct/link-cut-base.hpp
layout: document
redirect_from:
- /library/lct/link-cut-base.hpp
- /library/lct/link-cut-base.hpp.html
title: Link Cut Tree
---
