---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-treap.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-treap.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FDTreap"
    links: []
  bundledCode: "#line 2 \"rbst/treap.hpp\"\n\n\n\n#line 2 \"misc/rng.hpp\"\n\nnamespace\
    \ my_rand {\n\n// [0, 2^64 - 1)\nuint64_t rng() {\n  static uint64_t x_ =\n  \
    \    uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n                  \
    \ chrono::high_resolution_clock::now().time_since_epoch())\n                 \
    \  .count()) *\n      10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_\
    \ ^= x_ >> 9;\n}\n\n// [l, r)\nint64_t randint(int64_t l, int64_t r) {\n  assert(l\
    \ < r);\n  return l + rng() % (r - l);\n}\n\n// choose n numbers from [l, r) without\
    \ overlapping\nvector<int64_t> randset(int64_t l, int64_t r, int64_t n) {\n  assert(l\
    \ <= r && n <= r - l);\n  unordered_set<int64_t> s;\n  for (int64_t i = n; i;\
    \ --i) {\n    int64_t m = randint(l, r + 1 - i);\n    if (s.find(m) != s.end())\
    \ m = r - i;\n    s.insert(m);\n  }\n  vector<int64_t> ret;\n  for (auto& x :\
    \ s) ret.push_back(x);\n  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() {\n  union\
    \ raw_cast {\n    double t;\n    uint64_t u;\n  };\n  constexpr uint64_t p = uint64_t(1023\
    \ - 64) << 52;\n  return rng() * ((raw_cast*)(&p))->t;\n}\n\ntemplate <typename\
    \ T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n  for (int loop = 0;\
    \ loop < 2; loop++)\n    for (int i = 0; i < n; i++) swap(v[i], v[randint(0, n)]);\n\
    }\n\n}  // namespace my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\n\
    using my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n#line 6 \"\
    rbst/treap.hpp\"\n\ntemplate <typename Node>\nstruct TreapBase {\n  using Ptr\
    \ = Node *;\n  template <typename... Args>\n  inline Ptr my_new(Args... args)\
    \ {\n    return new Node(args...);\n  }\n  Ptr make_tree() { return nullptr; }\n\
    \n  // for avoiding memory leak, activate below\n  /*\n  using Ptr = shared_ptr<Node>;\n\
    \  template <typename... Args>\n  inline Ptr my_new(Args... args) {\n    return\
    \ make_shared<Node>(args...);\n  }\n  Ptr make_tree() {return Ptr();}\n  */\n\n\
    \  int size(Ptr t) const { return count(t); }\n\n  Ptr merge(Ptr l, Ptr r) {\n\
    \    if (!l || !r) return l ? l : r;\n    if (l->pr >= r->pr) {\n      push(l);\n\
    \      l->r = merge(l->r, r);\n      return update(l);\n    } else {\n      push(r);\n\
    \      r->l = merge(l, r->l);\n      return update(r);\n    }\n  }\n\n  pair<Ptr,\
    \ Ptr> split(Ptr t, int k) {\n    if (!t) return {nullptr, nullptr};\n    push(t);\n\
    \    if (k <= count(t->l)) {\n      auto s = split(t->l, k);\n      t->l = s.second;\n\
    \      return {s.first, update(t)};\n    } else {\n      auto s = split(t->r,\
    \ k - count(t->l) - 1);\n      t->r = s.first;\n      return {update(t), s.second};\n\
    \    }\n  }\n\n  Ptr build(const vector<decltype(Node::key)> &v) {\n    int n\
    \ = v.size();\n    vector<Ptr> ps;\n    ps.reserve(n);\n    for (int i = 0; i\
    \ < n; i++) ps.push_back(my_new(v[i]));\n    vector<int> p(n, -1), st;\n    for\
    \ (int i = 0; i < n; i++) {\n      int prv = -1;\n      while (!st.empty() &&\
    \ ps[i]->pr > ps[st.back()]->pr) {\n        prv = st.back();\n        st.pop_back();\n\
    \      }\n      if (prv != -1) p[prv] = i;\n      if (!st.empty()) p[i] = st.back();\n\
    \      st.push_back(i);\n    }\n    int root = -1;\n    for (int i = 0; i < n;\
    \ i++) {\n      if (p[i] != -1) {\n        if (i < p[i]) {\n          ps[p[i]]->l\
    \ = ps[i];\n        } else {\n          ps[p[i]]->r = ps[i];\n        }\n    \
    \  } else\n        root = i;\n    }\n    dfs(ps[root]);\n    return ps[root];\n\
    \  }\n\n  template <typename... Args>\n  void insert(Ptr &t, int k, const Args\
    \ &... args) {\n    auto x = split(t, k);\n    t = merge(merge(x.first, my_new(args...)),\
    \ x.second);\n  }\n\n  void erase(Ptr &t, int k) {\n    auto x = split(t, k);\n\
    \    t = merge(x.first, split(x.second, 1).second);\n  }\n\n protected:\n\n  void\
    \ dfs(Ptr r) {\n    if (r->l) dfs(r->l);\n    if (r->r) dfs(r->r);\n    update(r);\n\
    \  }\n  \n  inline int count(const Ptr t) const { return t ? t->cnt : 0; }\n\n\
    \  virtual void push(Ptr) {}\n\n  virtual Ptr update(Ptr) = 0;\n};\n\ntemplate\
    \ <typename T, typename E>\nstruct LazyReversibleTreapNode {\n  using Treap =\
    \ TreapBase<LazyReversibleTreapNode>;\n  typename Treap::Ptr l, r;\n  T key, sum;\n\
    \  E lazy;\n  int cnt;\n  uint32_t pr;\n  bool rev;\n\n  LazyReversibleTreapNode(const\
    \ T &t = T(), const E &e = E())\n      : l(),\n        r(),\n        key(t),\n\
    \        sum(t),\n        lazy(e),\n        cnt(1),\n        pr(my_rand::rng()),\n\
    \        rev(false) {}\n};\n\ntemplate <typename T, typename E, T (*f)(T, T),\
    \ T (*g)(T, E), E (*h)(E, E),\n          T (*ts)(T)>\nstruct LazyReversibleTreap\
    \ : TreapBase<LazyReversibleTreapNode<T, E>> {\n  using Node = LazyReversibleTreapNode<T,\
    \ E>;\n  using base = TreapBase<LazyReversibleTreapNode<T, E>>;\n  using base::merge;\n\
    \  using base::split;\n  using typename base::Ptr;\n\n  LazyReversibleTreap()\
    \ = default;\n\n  void toggle(Ptr t) {\n    swap(t->l, t->r);\n    t->sum = ts(t->sum);\n\
    \    t->rev ^= true;\n  }\n\n  T fold(Ptr &t, int a, int b) {\n    auto x = split(t,\
    \ a);\n    auto y = split(x.second, b - a);\n    auto ret = sum(y.first);\n  \
    \  t = merge(x.first, merge(y.first, y.second));\n    return ret;\n  }\n\n  void\
    \ reverse(Ptr &t, int a, int b) {\n    auto x = split(t, a);\n    auto y = split(x.second,\
    \ b - a);\n    toggle(y.first);\n    t = merge(x.first, merge(y.first, y.second));\n\
    \  }\n\n  void apply(Ptr &t, int a, int b, const E &e) {\n    auto x = split(t,\
    \ a);\n    auto y = split(x.second, b - a);\n    propagate(y.first, e);\n    t\
    \ = merge(x.first, merge(y.first, y.second));\n  }\n\n protected:\n  inline T\
    \ sum(const Ptr t) const { return t ? t->sum : T(); }\n\n  Ptr update(Ptr t) override\
    \ {\n    push(t);\n    t->cnt = 1;\n    t->sum = t->key;\n    if (t->l) t->cnt\
    \ += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n    if (t->r) t->cnt += t->r->cnt,\
    \ t->sum = f(t->sum, t->r->sum);\n    return t;\n  }\n\n  void push(Ptr t) override\
    \ {\n    if (t->rev) {\n      if (t->l) toggle(t->l);\n      if (t->r) toggle(t->r);\n\
    \      t->rev = false;\n    }\n    if (t->lazy != E()) {\n      if (t->l) propagate(t->l,\
    \ t->lazy);\n      if (t->r) propagate(t->r, t->lazy);\n      t->lazy = E();\n\
    \    }\n  }\n\n  void propagate(Ptr t, const E &x) {\n    t->lazy = h(t->lazy,\
    \ x);\n    t->key = g(t->key, x);\n    t->sum = g(t->sum, x);\n  }\n};\n\n/**\n\
    \ * @brief \u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FDTreap\n */\n"
  code: "#pragma once\n\n\n\n#include \"../misc/rng.hpp\"\n\ntemplate <typename Node>\n\
    struct TreapBase {\n  using Ptr = Node *;\n  template <typename... Args>\n  inline\
    \ Ptr my_new(Args... args) {\n    return new Node(args...);\n  }\n  Ptr make_tree()\
    \ { return nullptr; }\n\n  // for avoiding memory leak, activate below\n  /*\n\
    \  using Ptr = shared_ptr<Node>;\n  template <typename... Args>\n  inline Ptr\
    \ my_new(Args... args) {\n    return make_shared<Node>(args...);\n  }\n  Ptr make_tree()\
    \ {return Ptr();}\n  */\n\n  int size(Ptr t) const { return count(t); }\n\n  Ptr\
    \ merge(Ptr l, Ptr r) {\n    if (!l || !r) return l ? l : r;\n    if (l->pr >=\
    \ r->pr) {\n      push(l);\n      l->r = merge(l->r, r);\n      return update(l);\n\
    \    } else {\n      push(r);\n      r->l = merge(l, r->l);\n      return update(r);\n\
    \    }\n  }\n\n  pair<Ptr, Ptr> split(Ptr t, int k) {\n    if (!t) return {nullptr,\
    \ nullptr};\n    push(t);\n    if (k <= count(t->l)) {\n      auto s = split(t->l,\
    \ k);\n      t->l = s.second;\n      return {s.first, update(t)};\n    } else\
    \ {\n      auto s = split(t->r, k - count(t->l) - 1);\n      t->r = s.first;\n\
    \      return {update(t), s.second};\n    }\n  }\n\n  Ptr build(const vector<decltype(Node::key)>\
    \ &v) {\n    int n = v.size();\n    vector<Ptr> ps;\n    ps.reserve(n);\n    for\
    \ (int i = 0; i < n; i++) ps.push_back(my_new(v[i]));\n    vector<int> p(n, -1),\
    \ st;\n    for (int i = 0; i < n; i++) {\n      int prv = -1;\n      while (!st.empty()\
    \ && ps[i]->pr > ps[st.back()]->pr) {\n        prv = st.back();\n        st.pop_back();\n\
    \      }\n      if (prv != -1) p[prv] = i;\n      if (!st.empty()) p[i] = st.back();\n\
    \      st.push_back(i);\n    }\n    int root = -1;\n    for (int i = 0; i < n;\
    \ i++) {\n      if (p[i] != -1) {\n        if (i < p[i]) {\n          ps[p[i]]->l\
    \ = ps[i];\n        } else {\n          ps[p[i]]->r = ps[i];\n        }\n    \
    \  } else\n        root = i;\n    }\n    dfs(ps[root]);\n    return ps[root];\n\
    \  }\n\n  template <typename... Args>\n  void insert(Ptr &t, int k, const Args\
    \ &... args) {\n    auto x = split(t, k);\n    t = merge(merge(x.first, my_new(args...)),\
    \ x.second);\n  }\n\n  void erase(Ptr &t, int k) {\n    auto x = split(t, k);\n\
    \    t = merge(x.first, split(x.second, 1).second);\n  }\n\n protected:\n\n  void\
    \ dfs(Ptr r) {\n    if (r->l) dfs(r->l);\n    if (r->r) dfs(r->r);\n    update(r);\n\
    \  }\n  \n  inline int count(const Ptr t) const { return t ? t->cnt : 0; }\n\n\
    \  virtual void push(Ptr) {}\n\n  virtual Ptr update(Ptr) = 0;\n};\n\ntemplate\
    \ <typename T, typename E>\nstruct LazyReversibleTreapNode {\n  using Treap =\
    \ TreapBase<LazyReversibleTreapNode>;\n  typename Treap::Ptr l, r;\n  T key, sum;\n\
    \  E lazy;\n  int cnt;\n  uint32_t pr;\n  bool rev;\n\n  LazyReversibleTreapNode(const\
    \ T &t = T(), const E &e = E())\n      : l(),\n        r(),\n        key(t),\n\
    \        sum(t),\n        lazy(e),\n        cnt(1),\n        pr(my_rand::rng()),\n\
    \        rev(false) {}\n};\n\ntemplate <typename T, typename E, T (*f)(T, T),\
    \ T (*g)(T, E), E (*h)(E, E),\n          T (*ts)(T)>\nstruct LazyReversibleTreap\
    \ : TreapBase<LazyReversibleTreapNode<T, E>> {\n  using Node = LazyReversibleTreapNode<T,\
    \ E>;\n  using base = TreapBase<LazyReversibleTreapNode<T, E>>;\n  using base::merge;\n\
    \  using base::split;\n  using typename base::Ptr;\n\n  LazyReversibleTreap()\
    \ = default;\n\n  void toggle(Ptr t) {\n    swap(t->l, t->r);\n    t->sum = ts(t->sum);\n\
    \    t->rev ^= true;\n  }\n\n  T fold(Ptr &t, int a, int b) {\n    auto x = split(t,\
    \ a);\n    auto y = split(x.second, b - a);\n    auto ret = sum(y.first);\n  \
    \  t = merge(x.first, merge(y.first, y.second));\n    return ret;\n  }\n\n  void\
    \ reverse(Ptr &t, int a, int b) {\n    auto x = split(t, a);\n    auto y = split(x.second,\
    \ b - a);\n    toggle(y.first);\n    t = merge(x.first, merge(y.first, y.second));\n\
    \  }\n\n  void apply(Ptr &t, int a, int b, const E &e) {\n    auto x = split(t,\
    \ a);\n    auto y = split(x.second, b - a);\n    propagate(y.first, e);\n    t\
    \ = merge(x.first, merge(y.first, y.second));\n  }\n\n protected:\n  inline T\
    \ sum(const Ptr t) const { return t ? t->sum : T(); }\n\n  Ptr update(Ptr t) override\
    \ {\n    push(t);\n    t->cnt = 1;\n    t->sum = t->key;\n    if (t->l) t->cnt\
    \ += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n    if (t->r) t->cnt += t->r->cnt,\
    \ t->sum = f(t->sum, t->r->sum);\n    return t;\n  }\n\n  void push(Ptr t) override\
    \ {\n    if (t->rev) {\n      if (t->l) toggle(t->l);\n      if (t->r) toggle(t->r);\n\
    \      t->rev = false;\n    }\n    if (t->lazy != E()) {\n      if (t->l) propagate(t->l,\
    \ t->lazy);\n      if (t->r) propagate(t->r, t->lazy);\n      t->lazy = E();\n\
    \    }\n  }\n\n  void propagate(Ptr t, const E &x) {\n    t->lazy = h(t->lazy,\
    \ x);\n    t->key = g(t->key, x);\n    t->sum = g(t->sum, x);\n  }\n};\n\n/**\n\
    \ * @brief \u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FDTreap\n */\n"
  dependsOn:
  - misc/rng.hpp
  isVerificationFile: false
  path: rbst/treap.hpp
  requiredBy: []
  timestamp: '2020-12-08 00:23:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-treap.test.cpp
documentation_of: rbst/treap.hpp
layout: document
redirect_from:
- /library/rbst/treap.hpp
- /library/rbst/treap.hpp.html
title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FDTreap"
---
