---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-5-a-dynamic-rerooting.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-5-a-dynamic-rerooting.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root-2.test.cpp
    title: verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum.test.cpp
    title: verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0768.test.cpp
    title: verify/verify-yuki/yuki-0768.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1787.test.cpp
    title: verify/verify-yuki/yuki-1787.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1976.test.cpp
    title: verify/verify-yuki/yuki-1976.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2360.test.cpp
    title: verify/verify-yuki/yuki-2360.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2677.test.cpp
    title: verify/verify-yuki/yuki-2677.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/dynamic-rerooting.hpp\"\n\nnamespace DynamicRerootingImpl\
    \ {\ntemplate <typename Point, Point (*rake)(const Point &, const Point &)>\n\
    struct SplayTreeforDashedEdge {\n  struct Node {\n    Node *l, *r, *p;\n    Point\
    \ key, sum;\n\n    explicit Node(const Point &_key)\n        : l(nullptr), r(nullptr),\
    \ p(nullptr), key(_key), sum(_key) {}\n  };\n\n  SplayTreeforDashedEdge() {}\n\
    \n  using NP = Node *;\n\n  void rotr(NP t) {\n    NP x = t->p, y = x->p;\n  \
    \  if ((x->l = t->r)) t->r->p = x;\n    t->r = x, x->p = t;\n    update(x), update(t);\n\
    \    if ((t->p = y)) {\n      if (y->l == x) y->l = t;\n      if (y->r == x) y->r\
    \ = t;\n    }\n  }\n\n  void rotl(NP t) {\n    NP x = t->p, y = x->p;\n    if\
    \ ((x->r = t->l)) t->l->p = x;\n    t->l = x, x->p = t;\n    update(x), update(t);\n\
    \    if ((t->p = y)) {\n      if (y->l == x) y->l = t;\n      if (y->r == x) y->r\
    \ = t;\n    }\n  }\n\n  void update(NP t) {\n    t->sum = t->key;\n    if (t->l)\
    \ t->sum = rake(t->sum, t->l->sum);\n    if (t->r) t->sum = rake(t->sum, t->r->sum);\n\
    \  }\n\n  NP get_right(NP t) {\n    while (t->r) t = t->r;\n    return t;\n  }\n\
    \n  NP alloc(const Point &v) {\n    auto t = new Node(v);\n    update(t);\n  \
    \  return t;\n  }\n\n  void splay(NP t) {\n    while (t->p) {\n      NP q = t->p;\n\
    \      if (!q->p) {\n        if (q->l == t)\n          rotr(t);\n        else\n\
    \          rotl(t);\n      } else {\n        NP r = q->p;\n        if (r->l ==\
    \ q) {\n          if (q->l == t)\n            rotr(q), rotr(t);\n          else\n\
    \            rotl(t), rotr(t);\n        } else {\n          if (q->r == t)\n \
    \           rotl(q), rotl(t);\n          else\n            rotr(t), rotl(t);\n\
    \        }\n      }\n    }\n  }\n\n  NP insert(NP t, const Point &v) {\n    if\
    \ (not t) {\n      t = alloc(v);\n      return t;\n    } else {\n      NP cur\
    \ = get_right(t), z = alloc(v);\n      splay(cur);\n      z->p = cur;\n      cur->r\
    \ = z;\n      update(cur);\n      splay(z);\n      return z;\n    }\n  }\n\n \
    \ NP erase(NP t) {\n    splay(t);\n    NP x = t->l, y = t->r;\n    delete t;\n\
    \    if (not x) {\n      t = y;\n      if (t) t->p = nullptr;\n    } else if (not\
    \ y) {\n      t = x;\n      t->p = nullptr;\n    } else {\n      x->p = nullptr;\n\
    \      t = get_right(x);\n      splay(t);\n      t->r = y;\n      y->p = t;\n\
    \      update(t);\n    }\n    return t;\n  }\n};\n\ntemplate <typename Path, typename\
    \ Point, typename Info,\n          Path (*vertex)(const Info &),\n          Path\
    \ (*compress)(const Path &, const Path &),\n          Point (*rake)(const Point\
    \ &, const Point &),\n          Point (*add_edge)(const Path &),\n          Path\
    \ (*add_vertex)(const Point &, const Info &)>\nstruct TopTree {\n private:\n \
    \ struct Node {\n    Node *l, *r, *p;\n    Info info;\n    Path key, sum, mus;\n\
    \    typename SplayTreeforDashedEdge<Point, rake>::Node *light, *belong;\n   \
    \ bool rev;\n\n    bool is_root() const { return not p or (p->l != this and p->r\
    \ != this); }\n\n    explicit Node(const Info _info)\n        : l(nullptr),\n\
    \          r(nullptr),\n          p(nullptr),\n          info(_info),\n      \
    \    light(nullptr),\n          belong(nullptr),\n          rev(false) {}\n  };\n\
    \n public:\n  using NP = Node *;\n  SplayTreeforDashedEdge<Point, rake> splay_tree;\n\
    \n private:\n  void toggle(NP t) {\n    swap(t->l, t->r);\n    swap(t->sum, t->mus);\n\
    \    t->rev ^= true;\n  }\n\n  void rotr(NP t) {\n    NP x = t->p, y = x->p;\n\
    \    push(x), push(t);\n    if ((x->l = t->r)) t->r->p = x;\n    t->r = x, x->p\
    \ = t;\n    update(x), update(t);\n    if ((t->p = y)) {\n      if (y->l == x)\
    \ y->l = t;\n      if (y->r == x) y->r = t;\n    }\n  }\n\n  void rotl(NP t) {\n\
    \    NP x = t->p, y = x->p;\n    push(x), push(t);\n    if ((x->r = t->l)) t->l->p\
    \ = x;\n    t->l = x, x->p = t;\n    update(x), update(t);\n    if ((t->p = y))\
    \ {\n      if (y->l == x) y->l = t;\n      if (y->r == x) y->r = t;\n    }\n \
    \ }\n\n public:\n  TopTree() : splay_tree{} {}\n\n  void push(NP t) {\n    if\
    \ (t->rev) {\n      if (t->l) toggle(t->l);\n      if (t->r) toggle(t->r);\n \
    \     t->rev = false;\n    }\n  }\n\n  void push_rev(NP t) {\n    if (t->rev)\
    \ {\n      if (t->l) toggle(t->l);\n      if (t->r) toggle(t->r);\n      t->rev\
    \ = false;\n    }\n  }\n\n  void update(NP t) {\n    Path key = t->light ? add_vertex(t->light->sum,\
    \ t->info) : vertex(t->info);\n    Path sum = key, mus = key;\n    if (t->l) sum\
    \ = compress(t->l->sum, sum), mus = compress(mus, t->l->mus);\n    if (t->r) sum\
    \ = compress(sum, t->r->sum), mus = compress(t->r->mus, mus);\n    t->key = key,\
    \ t->sum = sum, t->mus = mus;\n  }\n\n  void splay(NP t) {\n    push(t);\n   \
    \ {\n      NP rot = t;\n      while (not rot->is_root()) rot = rot->p;\n     \
    \ t->belong = rot->belong;\n      if (t != rot) rot->belong = nullptr;\n    }\n\
    \    while (not t->is_root()) {\n      NP q = t->p;\n      if (q->is_root()) {\n\
    \        push_rev(q), push_rev(t);\n        if (q->l == t)\n          rotr(t);\n\
    \        else\n          rotl(t);\n      } else {\n        NP r = q->p;\n    \
    \    push_rev(r), push_rev(q), push_rev(t);\n        if (r->l == q) {\n      \
    \    if (q->l == t)\n            rotr(q), rotr(t);\n          else\n         \
    \   rotl(t), rotr(t);\n        } else {\n          if (q->r == t)\n          \
    \  rotl(q), rotl(t);\n          else\n            rotr(t), rotl(t);\n        }\n\
    \      }\n    }\n  }\n\n  NP expose(NP t) {\n    NP rp = nullptr;\n    for (NP\
    \ cur = t; cur; cur = cur->p) {\n      splay(cur);\n      if (cur->r) {\n    \
    \    cur->light = splay_tree.insert(cur->light, add_edge(cur->r->sum));\n    \
    \    cur->r->belong = cur->light;\n      }\n      cur->r = rp;\n      if (cur->r)\
    \ {\n        splay_tree.splay(cur->r->belong);\n        push(cur->r);\n      \
    \  cur->light = splay_tree.erase(cur->r->belong);\n      }\n      update(cur);\n\
    \      rp = cur;\n    }\n    splay(t);\n    return rp;\n  }\n\n  void link(NP\
    \ child, NP parent) {\n    expose(parent);\n    expose(child);\n    child->p =\
    \ parent;\n    parent->r = child;\n    update(parent);\n  }\n\n  void cut(NP child)\
    \ {\n    expose(child);\n    NP parent = child->l;\n    child->l = nullptr;\n\
    \    parent->p = nullptr;\n    update(child);\n  }\n\n  void evert(NP t) {\n \
    \   expose(t);\n    toggle(t);\n    push(t);\n  }\n\n  NP alloc(const Info &info)\
    \ {\n    NP t = new Node(info);\n    update(t);\n    return t;\n  }\n\n  bool\
    \ is_connected(NP u, NP v) {\n    expose(u), expose(v);\n    return u == v or\
    \ u->p;\n  }\n\n  NP lca(NP u, NP v) {\n    if (not is_connected(u, v)) return\
    \ nullptr;\n    expose(u);\n    return expose(v);\n  }\n\n  void set_key(NP t,\
    \ const Info &v) {\n    expose(t);\n    t->info = v;\n    update(t);\n  }\n\n\
    \  // u \u3092\u6839\u3068\u3059\u308B sum\n  Path query(NP u) {\n    evert(u);\n\
    \    return u->sum;\n  }\n\n  // root \u3092\u6839, u \u3092\u90E8\u5206\u6728\
    \u306E\u6839\u3068\u3059\u308B sum\n  Path query_subtree(NP root, NP u) {\n  \
    \  evert(root);\n    expose(u);\n    NP l = u->l;\n    u->l = nullptr;\n    update(u);\n\
    \    auto ret = u->sum;\n    u->l = l;\n    update(u);\n    return ret;\n  }\n\
    };\n\ntemplate <typename Path, typename Point, typename Info,\n          Path\
    \ (*vertex)(const Info &),\n          Path (*compress)(const Path &, const Path\
    \ &),\n          Point (*rake)(const Point &, const Point &),\n          Point\
    \ (*Add_edge)(const Path &),\n          Path (*add_vertex)(const Point &, const\
    \ Info &)>\nstruct DynamicRerooting {\n  int n;\n  TopTree<Path, Point, Info,\
    \ vertex, compress, rake, Add_edge, add_vertex> tt;\n  using NP = typename decltype(tt)::NP;\n\
    \  vector<NP> vs;\n\n  DynamicRerooting(int _n, const vector<Info> &info) : n(_n),\
    \ vs(n) {\n    for (int i = 0; i < n; i++) vs[i] = tt.alloc(info[i]);\n  }\n \
    \ // u-v \u9593\u306B\u8FBA\u3092\u8FFD\u52A0\n  void add_edge(int u, int v) {\n\
    \    tt.evert(vs[u]);\n    tt.link(vs[u], vs[v]);\n  }\n  // u-v \u9593\u306E\u8FBA\
    \u3092\u524A\u9664\n  void del_edge(int u, int v) {\n    tt.evert(vs[u]);\n  \
    \  tt.cut(vs[v]);\n  }\n  // \u9802\u70B9 u \u306E\u60C5\u5831\u3092\u53D6\u5F97\
    \n  Info get_info(int u) { return vs[u]->info; }\n  // \u9802\u70B9 u \u306E\u60C5\
    \u5831\u3092\u8A2D\u5B9A\n  void set_info(int u, const Info &info) { tt.set_key(vs[u],\
    \ info); }\n  // \u9802\u70B9 u \u3092\u6839\u3068\u3059\u308B\u30AF\u30A8\u30EA\
    \n  Path query(int u) { return tt.query(vs[u]); }\n  // \u9802\u70B9 root \u3092\
    \u6839, \u9802\u70B9 u \u3092\u90E8\u5206\u6728\u306E\u6839\u3068\u3059\u308B\u30AF\
    \u30A8\u30EA\n  Path query_subtree(int root, int u) {\n    return tt.query_subtree(vs[root],\
    \ vs[u]);\n  }\n};\n\n}  // namespace DynamicRerootingImpl\n\nusing DynamicRerootingImpl::DynamicRerooting;\n\
    using DynamicRerootingImpl::TopTree;\n\n/*\nstruct Path {\n\n};\nstruct Point\
    \ {\n\n};\nstruct Info {\n\n};\nPath vertex(const Info &i) {\n\n}\nPath compress(const\
    \ Path &p, const Path &c) {\n\n}\nPoint rake(const Point &a, const Point &b) {\n\
    \n}\nPoint add_edge(const Path &a) {\n\n}\nPath add_vertex(const Point &a, const\
    \ Info &i) {\n\n}\n\nusing DR = DynamicRerooting<Path, Point, Info, vertex, compress,\
    \ rake, add_edge,\n                            add_vertex>;\n*/\n"
  code: "#pragma once\n\nnamespace DynamicRerootingImpl {\ntemplate <typename Point,\
    \ Point (*rake)(const Point &, const Point &)>\nstruct SplayTreeforDashedEdge\
    \ {\n  struct Node {\n    Node *l, *r, *p;\n    Point key, sum;\n\n    explicit\
    \ Node(const Point &_key)\n        : l(nullptr), r(nullptr), p(nullptr), key(_key),\
    \ sum(_key) {}\n  };\n\n  SplayTreeforDashedEdge() {}\n\n  using NP = Node *;\n\
    \n  void rotr(NP t) {\n    NP x = t->p, y = x->p;\n    if ((x->l = t->r)) t->r->p\
    \ = x;\n    t->r = x, x->p = t;\n    update(x), update(t);\n    if ((t->p = y))\
    \ {\n      if (y->l == x) y->l = t;\n      if (y->r == x) y->r = t;\n    }\n \
    \ }\n\n  void rotl(NP t) {\n    NP x = t->p, y = x->p;\n    if ((x->r = t->l))\
    \ t->l->p = x;\n    t->l = x, x->p = t;\n    update(x), update(t);\n    if ((t->p\
    \ = y)) {\n      if (y->l == x) y->l = t;\n      if (y->r == x) y->r = t;\n  \
    \  }\n  }\n\n  void update(NP t) {\n    t->sum = t->key;\n    if (t->l) t->sum\
    \ = rake(t->sum, t->l->sum);\n    if (t->r) t->sum = rake(t->sum, t->r->sum);\n\
    \  }\n\n  NP get_right(NP t) {\n    while (t->r) t = t->r;\n    return t;\n  }\n\
    \n  NP alloc(const Point &v) {\n    auto t = new Node(v);\n    update(t);\n  \
    \  return t;\n  }\n\n  void splay(NP t) {\n    while (t->p) {\n      NP q = t->p;\n\
    \      if (!q->p) {\n        if (q->l == t)\n          rotr(t);\n        else\n\
    \          rotl(t);\n      } else {\n        NP r = q->p;\n        if (r->l ==\
    \ q) {\n          if (q->l == t)\n            rotr(q), rotr(t);\n          else\n\
    \            rotl(t), rotr(t);\n        } else {\n          if (q->r == t)\n \
    \           rotl(q), rotl(t);\n          else\n            rotr(t), rotl(t);\n\
    \        }\n      }\n    }\n  }\n\n  NP insert(NP t, const Point &v) {\n    if\
    \ (not t) {\n      t = alloc(v);\n      return t;\n    } else {\n      NP cur\
    \ = get_right(t), z = alloc(v);\n      splay(cur);\n      z->p = cur;\n      cur->r\
    \ = z;\n      update(cur);\n      splay(z);\n      return z;\n    }\n  }\n\n \
    \ NP erase(NP t) {\n    splay(t);\n    NP x = t->l, y = t->r;\n    delete t;\n\
    \    if (not x) {\n      t = y;\n      if (t) t->p = nullptr;\n    } else if (not\
    \ y) {\n      t = x;\n      t->p = nullptr;\n    } else {\n      x->p = nullptr;\n\
    \      t = get_right(x);\n      splay(t);\n      t->r = y;\n      y->p = t;\n\
    \      update(t);\n    }\n    return t;\n  }\n};\n\ntemplate <typename Path, typename\
    \ Point, typename Info,\n          Path (*vertex)(const Info &),\n          Path\
    \ (*compress)(const Path &, const Path &),\n          Point (*rake)(const Point\
    \ &, const Point &),\n          Point (*add_edge)(const Path &),\n          Path\
    \ (*add_vertex)(const Point &, const Info &)>\nstruct TopTree {\n private:\n \
    \ struct Node {\n    Node *l, *r, *p;\n    Info info;\n    Path key, sum, mus;\n\
    \    typename SplayTreeforDashedEdge<Point, rake>::Node *light, *belong;\n   \
    \ bool rev;\n\n    bool is_root() const { return not p or (p->l != this and p->r\
    \ != this); }\n\n    explicit Node(const Info _info)\n        : l(nullptr),\n\
    \          r(nullptr),\n          p(nullptr),\n          info(_info),\n      \
    \    light(nullptr),\n          belong(nullptr),\n          rev(false) {}\n  };\n\
    \n public:\n  using NP = Node *;\n  SplayTreeforDashedEdge<Point, rake> splay_tree;\n\
    \n private:\n  void toggle(NP t) {\n    swap(t->l, t->r);\n    swap(t->sum, t->mus);\n\
    \    t->rev ^= true;\n  }\n\n  void rotr(NP t) {\n    NP x = t->p, y = x->p;\n\
    \    push(x), push(t);\n    if ((x->l = t->r)) t->r->p = x;\n    t->r = x, x->p\
    \ = t;\n    update(x), update(t);\n    if ((t->p = y)) {\n      if (y->l == x)\
    \ y->l = t;\n      if (y->r == x) y->r = t;\n    }\n  }\n\n  void rotl(NP t) {\n\
    \    NP x = t->p, y = x->p;\n    push(x), push(t);\n    if ((x->r = t->l)) t->l->p\
    \ = x;\n    t->l = x, x->p = t;\n    update(x), update(t);\n    if ((t->p = y))\
    \ {\n      if (y->l == x) y->l = t;\n      if (y->r == x) y->r = t;\n    }\n \
    \ }\n\n public:\n  TopTree() : splay_tree{} {}\n\n  void push(NP t) {\n    if\
    \ (t->rev) {\n      if (t->l) toggle(t->l);\n      if (t->r) toggle(t->r);\n \
    \     t->rev = false;\n    }\n  }\n\n  void push_rev(NP t) {\n    if (t->rev)\
    \ {\n      if (t->l) toggle(t->l);\n      if (t->r) toggle(t->r);\n      t->rev\
    \ = false;\n    }\n  }\n\n  void update(NP t) {\n    Path key = t->light ? add_vertex(t->light->sum,\
    \ t->info) : vertex(t->info);\n    Path sum = key, mus = key;\n    if (t->l) sum\
    \ = compress(t->l->sum, sum), mus = compress(mus, t->l->mus);\n    if (t->r) sum\
    \ = compress(sum, t->r->sum), mus = compress(t->r->mus, mus);\n    t->key = key,\
    \ t->sum = sum, t->mus = mus;\n  }\n\n  void splay(NP t) {\n    push(t);\n   \
    \ {\n      NP rot = t;\n      while (not rot->is_root()) rot = rot->p;\n     \
    \ t->belong = rot->belong;\n      if (t != rot) rot->belong = nullptr;\n    }\n\
    \    while (not t->is_root()) {\n      NP q = t->p;\n      if (q->is_root()) {\n\
    \        push_rev(q), push_rev(t);\n        if (q->l == t)\n          rotr(t);\n\
    \        else\n          rotl(t);\n      } else {\n        NP r = q->p;\n    \
    \    push_rev(r), push_rev(q), push_rev(t);\n        if (r->l == q) {\n      \
    \    if (q->l == t)\n            rotr(q), rotr(t);\n          else\n         \
    \   rotl(t), rotr(t);\n        } else {\n          if (q->r == t)\n          \
    \  rotl(q), rotl(t);\n          else\n            rotr(t), rotl(t);\n        }\n\
    \      }\n    }\n  }\n\n  NP expose(NP t) {\n    NP rp = nullptr;\n    for (NP\
    \ cur = t; cur; cur = cur->p) {\n      splay(cur);\n      if (cur->r) {\n    \
    \    cur->light = splay_tree.insert(cur->light, add_edge(cur->r->sum));\n    \
    \    cur->r->belong = cur->light;\n      }\n      cur->r = rp;\n      if (cur->r)\
    \ {\n        splay_tree.splay(cur->r->belong);\n        push(cur->r);\n      \
    \  cur->light = splay_tree.erase(cur->r->belong);\n      }\n      update(cur);\n\
    \      rp = cur;\n    }\n    splay(t);\n    return rp;\n  }\n\n  void link(NP\
    \ child, NP parent) {\n    expose(parent);\n    expose(child);\n    child->p =\
    \ parent;\n    parent->r = child;\n    update(parent);\n  }\n\n  void cut(NP child)\
    \ {\n    expose(child);\n    NP parent = child->l;\n    child->l = nullptr;\n\
    \    parent->p = nullptr;\n    update(child);\n  }\n\n  void evert(NP t) {\n \
    \   expose(t);\n    toggle(t);\n    push(t);\n  }\n\n  NP alloc(const Info &info)\
    \ {\n    NP t = new Node(info);\n    update(t);\n    return t;\n  }\n\n  bool\
    \ is_connected(NP u, NP v) {\n    expose(u), expose(v);\n    return u == v or\
    \ u->p;\n  }\n\n  NP lca(NP u, NP v) {\n    if (not is_connected(u, v)) return\
    \ nullptr;\n    expose(u);\n    return expose(v);\n  }\n\n  void set_key(NP t,\
    \ const Info &v) {\n    expose(t);\n    t->info = v;\n    update(t);\n  }\n\n\
    \  // u \u3092\u6839\u3068\u3059\u308B sum\n  Path query(NP u) {\n    evert(u);\n\
    \    return u->sum;\n  }\n\n  // root \u3092\u6839, u \u3092\u90E8\u5206\u6728\
    \u306E\u6839\u3068\u3059\u308B sum\n  Path query_subtree(NP root, NP u) {\n  \
    \  evert(root);\n    expose(u);\n    NP l = u->l;\n    u->l = nullptr;\n    update(u);\n\
    \    auto ret = u->sum;\n    u->l = l;\n    update(u);\n    return ret;\n  }\n\
    };\n\ntemplate <typename Path, typename Point, typename Info,\n          Path\
    \ (*vertex)(const Info &),\n          Path (*compress)(const Path &, const Path\
    \ &),\n          Point (*rake)(const Point &, const Point &),\n          Point\
    \ (*Add_edge)(const Path &),\n          Path (*add_vertex)(const Point &, const\
    \ Info &)>\nstruct DynamicRerooting {\n  int n;\n  TopTree<Path, Point, Info,\
    \ vertex, compress, rake, Add_edge, add_vertex> tt;\n  using NP = typename decltype(tt)::NP;\n\
    \  vector<NP> vs;\n\n  DynamicRerooting(int _n, const vector<Info> &info) : n(_n),\
    \ vs(n) {\n    for (int i = 0; i < n; i++) vs[i] = tt.alloc(info[i]);\n  }\n \
    \ // u-v \u9593\u306B\u8FBA\u3092\u8FFD\u52A0\n  void add_edge(int u, int v) {\n\
    \    tt.evert(vs[u]);\n    tt.link(vs[u], vs[v]);\n  }\n  // u-v \u9593\u306E\u8FBA\
    \u3092\u524A\u9664\n  void del_edge(int u, int v) {\n    tt.evert(vs[u]);\n  \
    \  tt.cut(vs[v]);\n  }\n  // \u9802\u70B9 u \u306E\u60C5\u5831\u3092\u53D6\u5F97\
    \n  Info get_info(int u) { return vs[u]->info; }\n  // \u9802\u70B9 u \u306E\u60C5\
    \u5831\u3092\u8A2D\u5B9A\n  void set_info(int u, const Info &info) { tt.set_key(vs[u],\
    \ info); }\n  // \u9802\u70B9 u \u3092\u6839\u3068\u3059\u308B\u30AF\u30A8\u30EA\
    \n  Path query(int u) { return tt.query(vs[u]); }\n  // \u9802\u70B9 root \u3092\
    \u6839, \u9802\u70B9 u \u3092\u90E8\u5206\u6728\u306E\u6839\u3068\u3059\u308B\u30AF\
    \u30A8\u30EA\n  Path query_subtree(int root, int u) {\n    return tt.query_subtree(vs[root],\
    \ vs[u]);\n  }\n};\n\n}  // namespace DynamicRerootingImpl\n\nusing DynamicRerootingImpl::DynamicRerooting;\n\
    using DynamicRerootingImpl::TopTree;\n\n/*\nstruct Path {\n\n};\nstruct Point\
    \ {\n\n};\nstruct Info {\n\n};\nPath vertex(const Info &i) {\n\n}\nPath compress(const\
    \ Path &p, const Path &c) {\n\n}\nPoint rake(const Point &a, const Point &b) {\n\
    \n}\nPoint add_edge(const Path &a) {\n\n}\nPath add_vertex(const Point &a, const\
    \ Info &i) {\n\n}\n\nusing DR = DynamicRerooting<Path, Point, Info, vertex, compress,\
    \ rake, add_edge,\n                            add_vertex>;\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/dynamic-rerooting.hpp
  requiredBy: []
  timestamp: '2024-04-28 09:13:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root-2.test.cpp
  - verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum.test.cpp
  - verify/verify-yuki/yuki-2677.test.cpp
  - verify/verify-yuki/yuki-1976.test.cpp
  - verify/verify-yuki/yuki-0768.test.cpp
  - verify/verify-yuki/yuki-1787.test.cpp
  - verify/verify-yuki/yuki-2360.test.cpp
  - verify/verify-aoj-grl/aoj-grl-5-a-dynamic-rerooting.test.cpp
documentation_of: tree/dynamic-rerooting.hpp
layout: document
redirect_from:
- /library/tree/dynamic-rerooting.hpp
- /library/tree/dynamic-rerooting.hpp.html
title: tree/dynamic-rerooting.hpp
---
