---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: misc/vector-pool.hpp
    title: misc/vector-pool.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/orderedmap/rbst-ordered-map.md
    document_title: "OrderedMap(\u9806\u5E8F\u4ED8\u304D\u9023\u60F3\u914D\u5217)"
    links: []
  bundledCode: "#line 2 \"orderedmap/rbst-ordered-map.hpp\"\n\n\n\n#line 2 \"misc/vector-pool.hpp\"\
    \n\n\n\ntemplate <typename T,typename ptr_t = int>\nstruct VectorPool {\n  vector<T>\
    \ pool;\n  vector<ptr_t> st;\n  int idx;\n  int cap;\n\n  // pool[0] is missing\
    \ number (assuming nil)\n  VectorPool(int s = 4) : pool(s), st(), idx(1), cap(s)\
    \ { assert(s > 0); }\n\n  inline T& operator[](ptr_t i) { return pool[int(i)];\
    \ }\n\n  void reallocate() {\n    assert(idx == cap && st.size() == 0);\n    cap\
    \ *= 2;\n    pool.resize(cap, T());\n  }\n\n  ptr_t alloc() {\n    if (idx !=\
    \ cap) return ptr_t(idx++);\n    if (st.empty()) {\n      reallocate();\n    \
    \  return ptr_t(idx++);\n    }\n    ptr_t ret = st.back();\n    st.pop_back();\n\
    \    return ret;\n  }\n\n  template <typename... Args>\n  ptr_t my_new(Args...\
    \ args) {\n    ptr_t ret = alloc();\n    pool[int(ret)] = T(args...);\n    return\
    \ ret;\n  }\n\n  void free(ptr_t i) { st.push_back(i); }\n\n  void clear() {\n\
    \    idx = 1;\n    st.clear();\n  }\n};\n#line 6 \"orderedmap/rbst-ordered-map.hpp\"\
    \n\ntemplate <typename Key, typename Val>\nstruct OrderedMap {\n private:\n  uint64_t\
    \ rng() {\n    static uint64_t x_ = 88172645463325252ULL;\n    x_ = x_ ^ (x_ <<\
    \ 7);\n    x_ = x_ ^ (x_ >> 9);\n    return x_ & 0xFFFFFFFFull;\n  }\n\n  struct\
    \ NodePtr;\n  struct Node {\n    NodePtr l, r;\n    Key key;\n    Val val, sum;\n\
    \    int cnt;\n    Node() {}\n    Node(const Key &k, const Val &v)\n        :\
    \ l(0), r(0), key(k), val(v), sum(v), cnt(1) {}\n  };\n\n  struct NodePtr {\n\
    \    int n;\n    explicit constexpr NodePtr() {}\n    explicit constexpr NodePtr(int\
    \ _n) : n(_n) {}\n    constexpr bool operator==(const NodePtr &r) { return n ==\
    \ r.n; }\n    constexpr bool operator!=(const NodePtr &r) { return n != r.n; }\n\
    \    explicit constexpr operator int() { return n; }\n    explicit constexpr operator\
    \ bool() { return n != 0; }\n    constexpr bool operator!() { return n == 0; }\n\
    \    Node *operator->() { return &(pool.pool[n]); }\n    pair<const Key &, Val\
    \ &> operator*() {\n      assert(n != 0 and \"pair<const Key &, Val &> NodePtr::operator*()\"\
    );\n      return make_pair(pool.pool[n].key, pool.pool[n].val);\n    }\n    static\
    \ constexpr NodePtr nil() { return NodePtr(0); }\n  };\n\n  using F = function<Val(Val,\
    \ Val)>;\n\n  static VectorPool<Node, NodePtr> pool;\n  static F f;\n  static\
    \ Val I;\n  static bool fold_flag, lazy_flag;\n  NodePtr root;\n\n  NodePtr my_new(const\
    \ Key &k, const Val &v) {\n    NodePtr ret = pool.my_new(k, v);\n    assert(bool(ret)\
    \ && \"NodePtr my_new(const Key &k, const Val &v)\");\n    return ret;\n  }\n\n\
    \  void my_delete(NodePtr t) {\n    assert(bool(t) && \"void my_delete(NodePtr\
    \ t)\");\n    pool.free(t);\n  }\n\n  // inner_update (*t)\n  inline NodePtr inner_update(NodePtr\
    \ t) {\n    t->cnt = t->l->cnt + t->r->cnt + 1;\n    if (fold_flag) {\n      t->sum\
    \ = f(f(t->l->sum, t->val), t->r->sum);\n    }\n    return t;\n  }\n\n  // assign\
    \ (*this)[x] = y, and update parent nodes\n  void thrust(NodePtr p, const Key\
    \ &x, const Val &y) {\n    if (!p) return;\n    if (p->key == x) {\n      p->val\
    \ = y;\n      inner_update(p);\n      return;\n    }\n    NodePtr nxt = p->key\
    \ < x ? p->r : p->l;\n    thrust(nxt, x, y);\n    inner_update(p);\n  }\n\n  //\
    \ merge (*l, *r)\n  NodePtr merge(NodePtr l, NodePtr r) {\n    if (!l || !r) return\
    \ bool(l) ? l : r;\n    if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n\
    \      l->r = merge(l->r, r);\n      return inner_update(l);\n    } else {\n \
    \     r->l = merge(l, r->l);\n      return inner_update(r);\n    }\n  }\n\n  //\
    \ split (*t) to [-inf, x), [x, inf)\n  pair<NodePtr, NodePtr> split(NodePtr t,\
    \ const Key &x) {\n    if (!t) return {NodePtr::nil(), NodePtr::nil()};\n    if\
    \ (x <= t->key) {\n      auto s = split(t->l, x);\n      t->l = s.second;\n  \
    \    return {s.first, inner_update(t)};\n    } else {\n      auto s = split(t->r,\
    \ x);\n      t->r = s.first;\n      return {inner_update(t), s.second};\n    }\n\
    \  }\n\n  // split (*t) to [-inf, x], (x, inf)\n  pair<NodePtr, NodePtr> split_upper(NodePtr\
    \ t, const Key &x) {\n    if (!t) return {NodePtr::nil(), NodePtr::nil()};\n \
    \   if (x < t->key) {\n      auto s = split(t->l, x);\n      t->l = s.second;\n\
    \      return {s.first, inner_update(t)};\n    } else {\n      auto s = split(t->r,\
    \ x);\n      t->r = s.first;\n      return {inner_update(t), s.second};\n    }\n\
    \  }\n\n  // find t : t->key == x\n  NodePtr find_ptr(const Key &x) const {\n\
    \    NodePtr p = root;\n    while (bool(p)) {\n      if (x == p->key) return p;\n\
    \      p = x < p->key ? p->l : p->r;\n    }\n    return NodePtr::nil();\n  }\n\
    \n  // find t : t->key is minimum among (ptr n: n->key >= x)\n  static NodePtr\
    \ lower_ptr(NodePtr p, const Key &x) {\n    if (!p) return NodePtr::nil();\n \
    \   if (pool[p].val == x) return p;\n    if (pool[p].val < x) return lower_ptr(pool[p].r,\
    \ x);\n    NodePtr q = lower_ptr(pool[p].l, x);\n    return q ? q : p;\n  }\n\n\
    \  // find t : t->key is minimum among (ptr n: n->key > x)\n  static NodePtr upper_ptr(NodePtr\
    \ p, const Key &x) {\n    if (!p) return NodePtr::nil();\n    if (pool[p].val\
    \ <= x) return upper_ptr(pool[p].r, x);\n    NodePtr q = upper_ptr(pool[p].l,\
    \ x);\n    return q ? q : p;\n  }\n\n  NodePtr build(int l, int r, const vector<Val>\
    \ &v) {\n    if (l == r) return NodePtr::nil();\n    if (l + 1 == r) return my_new(l,\
    \ v[l]);\n    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));\n\
    \  }\n\n public:\n  OrderedMap() : root(NodePtr::nil()) {}\n\n  void build(const\
    \ vector<Val> &v) { root = build(0, v.size(), v); }\n\n  static void set_monoid(const\
    \ F &_f, const Val &I_) {\n    f = _f;\n    I = I_;\n    NodePtr root = NodePtr::nil();\n\
    \    root->val = root->sum = I_;\n    fold_flag = true;\n  }\n\n  static VectorPool<Node,\
    \ NodePtr> init_pool() {\n    VectorPool<Node, NodePtr> pool;\n    NodePtr root\
    \ = NodePtr::nil();\n    root->l = root->r = root;\n    root->cnt = 0;\n    root->key\
    \ = Key();\n    root->val = root->sum = Val();\n    return pool;\n  }\n\n  //\
    \ access (*this)[x]\n  Val &operator[](const Key &x) {\n    NodePtr p = find_ptr(x);\n\
    \    if (p) return p->val;\n    NodePtr l, r;\n    tie(l, r) = split(root, x);\n\
    \    NodePtr n = my_new(x, Val());\n    root = merge(merge(l, n), r);\n    return\
    \ n->val;\n  }\n\n  // get (*this)[x]\n  Val get(const Key &x) const {\n    NodePtr\
    \ p = root;\n    while (p) {\n      if (x == p->key) return p->val;\n      p =\
    \ x < p->key ? p->l : p->r;\n    }\n    return Val();\n  }\n\n  // get node, of\
    \ which key is minimum\n  NodePtr first_ptr() const {\n    NodePtr p = root;\n\
    \    while (!pool[p].l) p = pool[p].l;\n    return p;\n  }\n\n  // get node, of\
    \ which key is maximum\n  NodePtr last_ptr() const {\n    NodePtr p = root;\n\
    \    while (!pool[p].r) p = pool[p].r;\n    return p;\n  }\n\n  // enumerate all\
    \ key in order of increasing\n  vector<pair<const Key &, Val &>> enumerate() const\
    \ {\n    vector<pair<const Key &, Val &>> ret;\n    auto dfs = [&](auto rec, NodePtr\
    \ p) -> void {\n      if (pool[p].l) rec(rec, pool[p].l);\n      if (p) ret.emplace_back(pool[p].key,\
    \ pool[p].val);\n      if (pool[p].r) rec(rec, pool[p].r);\n      return;\n  \
    \  };\n    dfs(dfs, root);\n    return ret;\n  }\n\n  // (*this)[x] = y\n  void\
    \ insert(const Key &x, const Val &y) {\n    NodePtr p = find_ptr(x);\n    if (p)\
    \ {\n      thrust(root, x, y);\n      return;\n    }\n    NodePtr l, r;\n    tie(l,\
    \ r) = split(root, x);\n    root = merge(merge(l, my_new(x, y)), r);\n  }\n\n\
    \  void apply(const Key &x, const Val &y) {\n    assert(fold_flag = true);\n \
    \   NodePtr p = find_ptr(x);\n    if (p) {\n      thrust(root, x, f(p->val, y));\n\
    \      return;\n    }\n    NodePtr l, r;\n    tie(l, r) = split(root, x);\n  \
    \  root = merge(merge(l, my_new(x, y)), r);\n  }\n\n  // erase (*this)[x]\n  void\
    \ erase(const Key &x) {\n    NodePtr p = find_ptr(x);\n    if (!p) return;\n \
    \   NodePtr l, r;\n    tie(l, r) = split(root, x);\n    root = merge(l, split_upper(r,\
    \ x).second);\n    my_delete(p);\n  }\n\n  // count the number of node: n.key\
    \ < x\n  int lower_bound(const Key &x) const {\n    NodePtr p = root;\n    int\
    \ ret = 0;\n    while (p) {\n      if (x <= pool[p].val) {\n        p = pool[p].l;\n\
    \      } else {\n        ret += pool[pool[p].l].cnt + 1;\n        p = pool[p].r;\n\
    \      }\n    }\n    return ret;\n  }\n\n  // count the number of node: n.key\
    \ <= x\n  int upper_bound(const Key &x) const {\n    NodePtr p = root;\n    int\
    \ ret = 0;\n    while (p) {\n      if (x < pool[p].val) {\n        p = pool[p].l;\n\
    \      } else {\n        ret += pool[pool[p].l].cnt + 1;\n        p = pool[p].r;\n\
    \      }\n    }\n    return ret;\n  }\n\n  // (0-indexed) kth smallest number\n\
    \  NodePtr kth_element(int n) {\n    if (root->cnt <= n) return NodePtr::nil();\n\
    \    NodePtr p = root;\n    while (bool(p)) {\n      int sl = p->l->cnt;\n   \
    \   if (sl + 1 == n) return p;\n      if (sl < n) {\n        n -= sl + 1;\n  \
    \      p = p->r;\n      } else {\n        p = p->l;\n      }\n    }\n  }\n\n private:\n\
    \  // fold [l, inf]\n  Val fold_left(NodePtr p, const Key &l) {\n    Val ret =\
    \ I;\n    while (bool(p)) {\n      if (p->key == l) {\n        ret = f(f(p->val,\
    \ p->r->sum), ret);\n        break;\n      } else if (p->key < l) {\n        p\
    \ = p->r;\n      } else {\n        ret = f(f(p->val, p->r->sum), ret);\n     \
    \   p = p->l;\n      }\n    }\n    return ret;\n  }\n\n  // fold [inf, r)\n  Val\
    \ fold_right(NodePtr p, const Key &r) {\n    Val ret = I;\n    while (bool(p))\
    \ {\n      if (p->key == r) {\n        ret = f(ret, p->l->sum);\n        break;\n\
    \      } else if (p->key < r) {\n        ret = f(ret, f(p->l->sum, p->val));\n\
    \        p = p->r;\n      } else {\n        p = p->l;\n      }\n    }\n    return\
    \ ret;\n  }\n\n public:\n  // calculate f([n : l <= n.key < r])\n  Val fold(const\
    \ Key &l, const Key &r) {\n    NodePtr p = root;\n    while (bool(p)) {\n    \
    \  if (p->key < l) {\n        p = p->r;\n      } else if (r <= p->key) {\n   \
    \     p = p->l;\n      } else\n        break;\n    }\n    return f(f(fold_left(p->l,\
    \ l), p->val), fold_right(p->r, r));\n  }\n\n  // count containing nodes\n  int\
    \ size() const { return root->cnt; }\n};\n\ntemplate <typename Key, typename Val>\n\
    VectorPool<typename OrderedMap<Key, Val>::Node,\n           typename OrderedMap<Key,\
    \ Val>::NodePtr>\n    OrderedMap<Key, Val>::pool = OrderedMap<Key, Val>::init_pool();\n\
    template <typename Key, typename Val>\nfunction<Val(Val, Val)> OrderedMap<Key,\
    \ Val>::f = +[](Val, Val) {\n  return Val();\n};\ntemplate <typename Key, typename\
    \ Val>\nVal OrderedMap<Key, Val>::I = Val();\n\ntemplate <typename Key, typename\
    \ Val>\nbool OrderedMap<Key, Val>::fold_flag = false;\n\ntemplate <typename Key,\
    \ typename Val>\nbool OrderedMap<Key, Val>::lazy_flag = false;\n\n/**\n *  @brief\
    \ OrderedMap(\u9806\u5E8F\u4ED8\u304D\u9023\u60F3\u914D\u5217)\n *  @docs docs/orderedmap/rbst-ordered-map.md\n\
    \ */ \n"
  code: "#pragma once\n\n\n\n#include \"../misc/vector-pool.hpp\"\n\ntemplate <typename\
    \ Key, typename Val>\nstruct OrderedMap {\n private:\n  uint64_t rng() {\n   \
    \ static uint64_t x_ = 88172645463325252ULL;\n    x_ = x_ ^ (x_ << 7);\n    x_\
    \ = x_ ^ (x_ >> 9);\n    return x_ & 0xFFFFFFFFull;\n  }\n\n  struct NodePtr;\n\
    \  struct Node {\n    NodePtr l, r;\n    Key key;\n    Val val, sum;\n    int\
    \ cnt;\n    Node() {}\n    Node(const Key &k, const Val &v)\n        : l(0), r(0),\
    \ key(k), val(v), sum(v), cnt(1) {}\n  };\n\n  struct NodePtr {\n    int n;\n\
    \    explicit constexpr NodePtr() {}\n    explicit constexpr NodePtr(int _n) :\
    \ n(_n) {}\n    constexpr bool operator==(const NodePtr &r) { return n == r.n;\
    \ }\n    constexpr bool operator!=(const NodePtr &r) { return n != r.n; }\n  \
    \  explicit constexpr operator int() { return n; }\n    explicit constexpr operator\
    \ bool() { return n != 0; }\n    constexpr bool operator!() { return n == 0; }\n\
    \    Node *operator->() { return &(pool.pool[n]); }\n    pair<const Key &, Val\
    \ &> operator*() {\n      assert(n != 0 and \"pair<const Key &, Val &> NodePtr::operator*()\"\
    );\n      return make_pair(pool.pool[n].key, pool.pool[n].val);\n    }\n    static\
    \ constexpr NodePtr nil() { return NodePtr(0); }\n  };\n\n  using F = function<Val(Val,\
    \ Val)>;\n\n  static VectorPool<Node, NodePtr> pool;\n  static F f;\n  static\
    \ Val I;\n  static bool fold_flag, lazy_flag;\n  NodePtr root;\n\n  NodePtr my_new(const\
    \ Key &k, const Val &v) {\n    NodePtr ret = pool.my_new(k, v);\n    assert(bool(ret)\
    \ && \"NodePtr my_new(const Key &k, const Val &v)\");\n    return ret;\n  }\n\n\
    \  void my_delete(NodePtr t) {\n    assert(bool(t) && \"void my_delete(NodePtr\
    \ t)\");\n    pool.free(t);\n  }\n\n  // inner_update (*t)\n  inline NodePtr inner_update(NodePtr\
    \ t) {\n    t->cnt = t->l->cnt + t->r->cnt + 1;\n    if (fold_flag) {\n      t->sum\
    \ = f(f(t->l->sum, t->val), t->r->sum);\n    }\n    return t;\n  }\n\n  // assign\
    \ (*this)[x] = y, and update parent nodes\n  void thrust(NodePtr p, const Key\
    \ &x, const Val &y) {\n    if (!p) return;\n    if (p->key == x) {\n      p->val\
    \ = y;\n      inner_update(p);\n      return;\n    }\n    NodePtr nxt = p->key\
    \ < x ? p->r : p->l;\n    thrust(nxt, x, y);\n    inner_update(p);\n  }\n\n  //\
    \ merge (*l, *r)\n  NodePtr merge(NodePtr l, NodePtr r) {\n    if (!l || !r) return\
    \ bool(l) ? l : r;\n    if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n\
    \      l->r = merge(l->r, r);\n      return inner_update(l);\n    } else {\n \
    \     r->l = merge(l, r->l);\n      return inner_update(r);\n    }\n  }\n\n  //\
    \ split (*t) to [-inf, x), [x, inf)\n  pair<NodePtr, NodePtr> split(NodePtr t,\
    \ const Key &x) {\n    if (!t) return {NodePtr::nil(), NodePtr::nil()};\n    if\
    \ (x <= t->key) {\n      auto s = split(t->l, x);\n      t->l = s.second;\n  \
    \    return {s.first, inner_update(t)};\n    } else {\n      auto s = split(t->r,\
    \ x);\n      t->r = s.first;\n      return {inner_update(t), s.second};\n    }\n\
    \  }\n\n  // split (*t) to [-inf, x], (x, inf)\n  pair<NodePtr, NodePtr> split_upper(NodePtr\
    \ t, const Key &x) {\n    if (!t) return {NodePtr::nil(), NodePtr::nil()};\n \
    \   if (x < t->key) {\n      auto s = split(t->l, x);\n      t->l = s.second;\n\
    \      return {s.first, inner_update(t)};\n    } else {\n      auto s = split(t->r,\
    \ x);\n      t->r = s.first;\n      return {inner_update(t), s.second};\n    }\n\
    \  }\n\n  // find t : t->key == x\n  NodePtr find_ptr(const Key &x) const {\n\
    \    NodePtr p = root;\n    while (bool(p)) {\n      if (x == p->key) return p;\n\
    \      p = x < p->key ? p->l : p->r;\n    }\n    return NodePtr::nil();\n  }\n\
    \n  // find t : t->key is minimum among (ptr n: n->key >= x)\n  static NodePtr\
    \ lower_ptr(NodePtr p, const Key &x) {\n    if (!p) return NodePtr::nil();\n \
    \   if (pool[p].val == x) return p;\n    if (pool[p].val < x) return lower_ptr(pool[p].r,\
    \ x);\n    NodePtr q = lower_ptr(pool[p].l, x);\n    return q ? q : p;\n  }\n\n\
    \  // find t : t->key is minimum among (ptr n: n->key > x)\n  static NodePtr upper_ptr(NodePtr\
    \ p, const Key &x) {\n    if (!p) return NodePtr::nil();\n    if (pool[p].val\
    \ <= x) return upper_ptr(pool[p].r, x);\n    NodePtr q = upper_ptr(pool[p].l,\
    \ x);\n    return q ? q : p;\n  }\n\n  NodePtr build(int l, int r, const vector<Val>\
    \ &v) {\n    if (l == r) return NodePtr::nil();\n    if (l + 1 == r) return my_new(l,\
    \ v[l]);\n    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));\n\
    \  }\n\n public:\n  OrderedMap() : root(NodePtr::nil()) {}\n\n  void build(const\
    \ vector<Val> &v) { root = build(0, v.size(), v); }\n\n  static void set_monoid(const\
    \ F &_f, const Val &I_) {\n    f = _f;\n    I = I_;\n    NodePtr root = NodePtr::nil();\n\
    \    root->val = root->sum = I_;\n    fold_flag = true;\n  }\n\n  static VectorPool<Node,\
    \ NodePtr> init_pool() {\n    VectorPool<Node, NodePtr> pool;\n    NodePtr root\
    \ = NodePtr::nil();\n    root->l = root->r = root;\n    root->cnt = 0;\n    root->key\
    \ = Key();\n    root->val = root->sum = Val();\n    return pool;\n  }\n\n  //\
    \ access (*this)[x]\n  Val &operator[](const Key &x) {\n    NodePtr p = find_ptr(x);\n\
    \    if (p) return p->val;\n    NodePtr l, r;\n    tie(l, r) = split(root, x);\n\
    \    NodePtr n = my_new(x, Val());\n    root = merge(merge(l, n), r);\n    return\
    \ n->val;\n  }\n\n  // get (*this)[x]\n  Val get(const Key &x) const {\n    NodePtr\
    \ p = root;\n    while (p) {\n      if (x == p->key) return p->val;\n      p =\
    \ x < p->key ? p->l : p->r;\n    }\n    return Val();\n  }\n\n  // get node, of\
    \ which key is minimum\n  NodePtr first_ptr() const {\n    NodePtr p = root;\n\
    \    while (!pool[p].l) p = pool[p].l;\n    return p;\n  }\n\n  // get node, of\
    \ which key is maximum\n  NodePtr last_ptr() const {\n    NodePtr p = root;\n\
    \    while (!pool[p].r) p = pool[p].r;\n    return p;\n  }\n\n  // enumerate all\
    \ key in order of increasing\n  vector<pair<const Key &, Val &>> enumerate() const\
    \ {\n    vector<pair<const Key &, Val &>> ret;\n    auto dfs = [&](auto rec, NodePtr\
    \ p) -> void {\n      if (pool[p].l) rec(rec, pool[p].l);\n      if (p) ret.emplace_back(pool[p].key,\
    \ pool[p].val);\n      if (pool[p].r) rec(rec, pool[p].r);\n      return;\n  \
    \  };\n    dfs(dfs, root);\n    return ret;\n  }\n\n  // (*this)[x] = y\n  void\
    \ insert(const Key &x, const Val &y) {\n    NodePtr p = find_ptr(x);\n    if (p)\
    \ {\n      thrust(root, x, y);\n      return;\n    }\n    NodePtr l, r;\n    tie(l,\
    \ r) = split(root, x);\n    root = merge(merge(l, my_new(x, y)), r);\n  }\n\n\
    \  void apply(const Key &x, const Val &y) {\n    assert(fold_flag = true);\n \
    \   NodePtr p = find_ptr(x);\n    if (p) {\n      thrust(root, x, f(p->val, y));\n\
    \      return;\n    }\n    NodePtr l, r;\n    tie(l, r) = split(root, x);\n  \
    \  root = merge(merge(l, my_new(x, y)), r);\n  }\n\n  // erase (*this)[x]\n  void\
    \ erase(const Key &x) {\n    NodePtr p = find_ptr(x);\n    if (!p) return;\n \
    \   NodePtr l, r;\n    tie(l, r) = split(root, x);\n    root = merge(l, split_upper(r,\
    \ x).second);\n    my_delete(p);\n  }\n\n  // count the number of node: n.key\
    \ < x\n  int lower_bound(const Key &x) const {\n    NodePtr p = root;\n    int\
    \ ret = 0;\n    while (p) {\n      if (x <= pool[p].val) {\n        p = pool[p].l;\n\
    \      } else {\n        ret += pool[pool[p].l].cnt + 1;\n        p = pool[p].r;\n\
    \      }\n    }\n    return ret;\n  }\n\n  // count the number of node: n.key\
    \ <= x\n  int upper_bound(const Key &x) const {\n    NodePtr p = root;\n    int\
    \ ret = 0;\n    while (p) {\n      if (x < pool[p].val) {\n        p = pool[p].l;\n\
    \      } else {\n        ret += pool[pool[p].l].cnt + 1;\n        p = pool[p].r;\n\
    \      }\n    }\n    return ret;\n  }\n\n  // (0-indexed) kth smallest number\n\
    \  NodePtr kth_element(int n) {\n    if (root->cnt <= n) return NodePtr::nil();\n\
    \    NodePtr p = root;\n    while (bool(p)) {\n      int sl = p->l->cnt;\n   \
    \   if (sl + 1 == n) return p;\n      if (sl < n) {\n        n -= sl + 1;\n  \
    \      p = p->r;\n      } else {\n        p = p->l;\n      }\n    }\n  }\n\n private:\n\
    \  // fold [l, inf]\n  Val fold_left(NodePtr p, const Key &l) {\n    Val ret =\
    \ I;\n    while (bool(p)) {\n      if (p->key == l) {\n        ret = f(f(p->val,\
    \ p->r->sum), ret);\n        break;\n      } else if (p->key < l) {\n        p\
    \ = p->r;\n      } else {\n        ret = f(f(p->val, p->r->sum), ret);\n     \
    \   p = p->l;\n      }\n    }\n    return ret;\n  }\n\n  // fold [inf, r)\n  Val\
    \ fold_right(NodePtr p, const Key &r) {\n    Val ret = I;\n    while (bool(p))\
    \ {\n      if (p->key == r) {\n        ret = f(ret, p->l->sum);\n        break;\n\
    \      } else if (p->key < r) {\n        ret = f(ret, f(p->l->sum, p->val));\n\
    \        p = p->r;\n      } else {\n        p = p->l;\n      }\n    }\n    return\
    \ ret;\n  }\n\n public:\n  // calculate f([n : l <= n.key < r])\n  Val fold(const\
    \ Key &l, const Key &r) {\n    NodePtr p = root;\n    while (bool(p)) {\n    \
    \  if (p->key < l) {\n        p = p->r;\n      } else if (r <= p->key) {\n   \
    \     p = p->l;\n      } else\n        break;\n    }\n    return f(f(fold_left(p->l,\
    \ l), p->val), fold_right(p->r, r));\n  }\n\n  // count containing nodes\n  int\
    \ size() const { return root->cnt; }\n};\n\ntemplate <typename Key, typename Val>\n\
    VectorPool<typename OrderedMap<Key, Val>::Node,\n           typename OrderedMap<Key,\
    \ Val>::NodePtr>\n    OrderedMap<Key, Val>::pool = OrderedMap<Key, Val>::init_pool();\n\
    template <typename Key, typename Val>\nfunction<Val(Val, Val)> OrderedMap<Key,\
    \ Val>::f = +[](Val, Val) {\n  return Val();\n};\ntemplate <typename Key, typename\
    \ Val>\nVal OrderedMap<Key, Val>::I = Val();\n\ntemplate <typename Key, typename\
    \ Val>\nbool OrderedMap<Key, Val>::fold_flag = false;\n\ntemplate <typename Key,\
    \ typename Val>\nbool OrderedMap<Key, Val>::lazy_flag = false;\n\n/**\n *  @brief\
    \ OrderedMap(\u9806\u5E8F\u4ED8\u304D\u9023\u60F3\u914D\u5217)\n *  @docs docs/orderedmap/rbst-ordered-map.md\n\
    \ */ \n"
  dependsOn:
  - misc/vector-pool.hpp
  isVerificationFile: false
  path: orderedmap/rbst-ordered-map.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: orderedmap/rbst-ordered-map.hpp
layout: document
redirect_from:
- /library/orderedmap/rbst-ordered-map.hpp
- /library/orderedmap/rbst-ordered-map.hpp.html
title: "OrderedMap(\u9806\u5E8F\u4ED8\u304D\u9023\u60F3\u914D\u5217)"
---
## OrderedMap(順序付き連想配列)

順序付き連想配列をRandomized Binary Search Tree(merge-splitベース)を内部実装として実装したもの。計算量は言及がない限り$\mathrm{O}(\log N)$。

#### 使い方

内部ではノードへのポインタを`NodePtr`型で管理しており、一部の関数は`NodePtr`型が返り値となる。`NodePtr p`に対して`*p`で`pair(const key&, val&)`を取得することが出来る。(インクリメント等は実装しておらず参照にしか使えない。)また、`NodePtr::nil()`は`nullptr`と同様の意味を持っており、`bool(NodePtr) = false`を返す設計となっている。

- 初期化
  - `OrderedMap<Key, Val>()`:　初期化する。`Key`はキーの型、`Val`は値の型。
  - `build(const vector<Val>& v)`:　`(i, v[i])`を初期値として構築する。計算量$\mathrm{O}(N)$
  - `set_monoid(const F &f, const Val &I)`: `I`を単位元とする`f` : `Val` $\times$`Val`$\rightarrow$`Val`を載せる。
- 挿入・削除
  - `insert(const Key& x, const Val& y)`: キーが`x`であるノードの値に`y`を代入する。
  - `apply(const Key &x, const Val &y)`: キーが`k`であるノードの値を`f(*this[k], y)`に更新する。
  - `erase(const Key &x)`:　キーが`k`であるノードを削除する。
- 参照・検索
  - `[](const Key& k)`:　キーが`k`であるノードの値への参照を返す(代入も可能)。存在しない場合は新たに初期化したノードを追加して参照する。
  - `get(const Key& k) const`: キーが`k`であるノードのポインタを返す。存在しない場合は`nil`を返す。
  - `first_ptr() const`: キーが最も小さいノードのポインタを返す。存在しない場合は`nil`を返す。
  - `last_ptr() const`: キーが最も小さいノードのポインタを返す。存在しない場合は`nil`を返す。
- それ以外の機能
  - `enumerate() const`: 要素を昇順に列挙した`vector`を返す。計算量$\mathrm{O}(N)$
  - `lower_bound(const Key &x)`:　キーが`x`より小さいノードの個数を数える。
  - `lower_bound(const Key &x)`:　キーが`x`より大きいノードの個数を数える。
  - `kth_element(int n)`:　キーが`n`番目(0-indexed)に小さいノードのポインタを返す。存在しない場合は`nil`を返す。
  - `fold(const Key &l, const Key &r)`:　`[l, r)`番目のノードにモノイド`f`を作用させた時の値の和を返す。
  - `size() const`:　要素数を返す。計算量$\mathrm{O}(1)$
