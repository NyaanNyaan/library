---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: binary-search-tree/randomized-binary-search-tree.hpp
    title: binary-search-tree/randomized-binary-search-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"binary-search-tree/randomized-binary-search-tree.hpp\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <typename T, typename\
    \ F>\nstruct RandomizedBinarySearchTree {\n  uint64_t rng() {\n    static uint64_t\
    \ x_ = 88172645463325252ULL;\n    x_ = x_ ^ (x_ << 7);\n    x_ = x_ ^ (x_ >> 9);\n\
    \    return x_ & 0xFFFFFFFFull;\n  }\n\n  struct Node {\n    Node *l, *r;\n  \
    \  T key, sum;\n    int cnt;\n\n    Node() {}\n\n    Node(const T &k) : l(nullptr),\
    \ r(nullptr), key(k), sum(k), cnt(1) {}\n  };\n\n  vector<Node> pool;\n  int ptr;\n\
    \  const F f;\n  const T I;\n\n  RandomizedBinarySearchTree(const F &f_, const\
    \ T &I_, int pool_size = 2000000)\n      : pool(pool_size), ptr(0), f(f_), I(I_)\
    \ {}\n\n  Node *my_new(const T &k) { return &(pool[ptr++] = Node(k)); }\n\n  inline\
    \ int count(const Node *t){ return t ? t->cnt : 0; }\n\n  inline T sum(const Node\
    \ *t) { return t ? t->sum : I; }\n\n  Node *update(Node *t) {\n    t->cnt = count(t->l)\
    \ + count(t->r) + 1;\n    t->sum = f(f(sum(t->l), t->key), sum(t->r));\n    return\
    \ t;\n  }\n\n  Node *merge(Node *l, Node *r) {\n    if (!l || !r) return l ? l\
    \ : r;\n    if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n      l->r\
    \ = merge(l->r, r);\n      return update(l);\n    } else {\n      r->l = merge(l,\
    \ r->l);\n      return update(r);\n    }\n  }\n\n  pair<Node *, Node *> split(Node\
    \ *t, int k) {\n    if (!t) return {nullptr, nullptr};\n    if (k <= count(t->l))\
    \ {\n      auto s = split(t->l, k);\n      t->l = s.second;\n      return {s.first,\
    \ update(t)};\n    } else {\n      auto s = split(t->r, k - count(t->l) - 1);\n\
    \      t->r = s.first;\n      return {update(t), s.second};\n    }\n  }\n\n  Node\
    \ *build(int l, int r, const vector<T> &v) {\n    if (l + 1 >= r) return my_new(v[l]);\n\
    \    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));\n  }\n\
    \n  Node *build(const vector<T> &v) {\n    ptr = 0;\n    return build(0, (int)v.size(),\
    \ v);\n  }\n\n  void insert(Node *&t, int k, const T &v) {\n    auto x = split(t,\
    \ k);\n    t = merge(merge(x.first, my_new(v)), x.second);\n  }\n\n  void erase(Node\
    \ *&t, int k) {\n    auto x = split(t, k);\n    t = merge(x.first, split(x.second,\
    \ 1).second);\n  }\n\n  T query(Node *&t, int a, int b) {\n    auto x = split(t,\
    \ a);\n    auto y = split(x.second, b - a);\n    auto ret = sum(y.first);\n  \
    \  t = merge(x.first, merge(y.first, y.second));\n    return ret;\n  }\n\n  int\
    \ size(Node *t) { return count(t); }\n\n  Node *make() { return nullptr; }\n};\n\
    #line 3 \"binary-search-tree/rbst-ordered-set.hpp\"\n\ntemplate <typename T, int\
    \ S = 2000000, bool MULTI = false>\nstruct OrderedSet {\n  using F = function<T(T,\
    \ T)>;\n  using RBST = RandomizedBinarySearchTree<T, F>;\n  using Node = typename\
    \ RBST::Node;\n\n  static RBST* rbst;\n  Node* t;\n\n  OrderedSet() {\n    if\
    \ (!rbst) rbst = new RBST([](T, T) { return T(); }, T(), S);\n    t = rbst->make();\n\
    \  }\n\n  T kth_element(int k) {\n    Node* p = t;\n    int l;\n    while (k !=\
    \ (l = rbst->count(p->l))) {\n      if (k < l) {\n        p = p->l;\n      } else\
    \ {\n        p = p->r;\n        k -= l + 1;\n      }\n    }\n    return p->key;\n\
    \  }\n\n  void insert(const T& x) {\n    int l = lower_bound(x);\n    int r =\
    \ upper_bound(x);\n    if (!MULTI and l != r) return;\n    rbst->insert(t, l,\
    \ x);\n  }\n\n  void erase(const T& x) {\n    int l = lower_bound(x);\n    int\
    \ r = upper_bound(x);\n    if (l == r) return;\n    rbst->erase(t, l);\n  }\n\n\
    \  int count(const T& x) { return upper_bound(t, x) - lower_bound(t, x); }\n\n\
    \  int size() { return rbst->count(t); }\n\n  int lower_bound(const T& x) {\n\
    \    Node* p = t;\n    int ret = 0;\n    while (p) {\n      if (x <= p->key) {\n\
    \        p = p->l;\n      } else {\n        ret += rbst->count(p->l) + 1;\n  \
    \      p = p->r;\n      }\n    }\n    return ret;\n  }\n\n  int upper_bound(const\
    \ T& x) {\n    Node* p = t;\n    int ret = 0;\n    while (p) {\n      if (x <\
    \ p->key) {\n        p = p->l;\n      } else {\n        ret += rbst->count(p->l)\
    \ + 1;\n        p = p->r;\n      }\n    }\n    return ret;\n  }\n\n  vector<string>\
    \ dump() {\n    int width = 128;\n    string emp(width, ' ');\n    string data;\n\
    \    data += string(\"  DUMP ... size : \") + to_string(rbst->size(t));\n\n  \
    \  vector<string> ret(width, emp);\n    ret[0] = data;\n\n    int max_dep = 0;\n\
    \    dump(ret, t, 1, width / 2, width / 4, 0, &max_dep);\n    while (ret.size()\
    \ and ret.back() == emp) ret.pop_back();\n    ret[0] += string(\" depth : \")\
    \ + to_string(max_dep);\n    return ret;\n  }\n\n  void dump(vector<string>& s,\
    \ const Node* t, int i, int j, int off,\n            int cdep = 0, int* mdep =\
    \ nullptr) {\n    if (!t) return;\n    *mdep = max(cdep, *mdep);\n\n    string\
    \ n = to_string(t->key);\n    copy(begin(n), end(n), begin(s[i]) + j);\n\n   \
    \ if (t->l) {\n      s[i + 1][j - off / 2] = 'L';\n      dump(s, t->l, i + 2,\
    \ j - off, off / 2, cdep + 1, mdep);\n    }\n    if (t->r) {\n      s[i + 1][j\
    \ + off / 2] = 'R';\n      dump(s, t->r, i + 2, j + off, off / 2, cdep + 1, mdep);\n\
    \    }\n  }\n};\ntemplate <typename T, int S, bool MULTI>\ntypename OrderedSet<T,\
    \ S, MULTI>::RBST* OrderedSet<T, S, MULTI>::rbst = nullptr;\n"
  code: "#pragma once\n#include \"./randomized-binary-search-tree.hpp\"\n\ntemplate\
    \ <typename T, int S = 2000000, bool MULTI = false>\nstruct OrderedSet {\n  using\
    \ F = function<T(T, T)>;\n  using RBST = RandomizedBinarySearchTree<T, F>;\n \
    \ using Node = typename RBST::Node;\n\n  static RBST* rbst;\n  Node* t;\n\n  OrderedSet()\
    \ {\n    if (!rbst) rbst = new RBST([](T, T) { return T(); }, T(), S);\n    t\
    \ = rbst->make();\n  }\n\n  T kth_element(int k) {\n    Node* p = t;\n    int\
    \ l;\n    while (k != (l = rbst->count(p->l))) {\n      if (k < l) {\n       \
    \ p = p->l;\n      } else {\n        p = p->r;\n        k -= l + 1;\n      }\n\
    \    }\n    return p->key;\n  }\n\n  void insert(const T& x) {\n    int l = lower_bound(x);\n\
    \    int r = upper_bound(x);\n    if (!MULTI and l != r) return;\n    rbst->insert(t,\
    \ l, x);\n  }\n\n  void erase(const T& x) {\n    int l = lower_bound(x);\n   \
    \ int r = upper_bound(x);\n    if (l == r) return;\n    rbst->erase(t, l);\n \
    \ }\n\n  int count(const T& x) { return upper_bound(t, x) - lower_bound(t, x);\
    \ }\n\n  int size() { return rbst->count(t); }\n\n  int lower_bound(const T& x)\
    \ {\n    Node* p = t;\n    int ret = 0;\n    while (p) {\n      if (x <= p->key)\
    \ {\n        p = p->l;\n      } else {\n        ret += rbst->count(p->l) + 1;\n\
    \        p = p->r;\n      }\n    }\n    return ret;\n  }\n\n  int upper_bound(const\
    \ T& x) {\n    Node* p = t;\n    int ret = 0;\n    while (p) {\n      if (x <\
    \ p->key) {\n        p = p->l;\n      } else {\n        ret += rbst->count(p->l)\
    \ + 1;\n        p = p->r;\n      }\n    }\n    return ret;\n  }\n\n  vector<string>\
    \ dump() {\n    int width = 128;\n    string emp(width, ' ');\n    string data;\n\
    \    data += string(\"  DUMP ... size : \") + to_string(rbst->size(t));\n\n  \
    \  vector<string> ret(width, emp);\n    ret[0] = data;\n\n    int max_dep = 0;\n\
    \    dump(ret, t, 1, width / 2, width / 4, 0, &max_dep);\n    while (ret.size()\
    \ and ret.back() == emp) ret.pop_back();\n    ret[0] += string(\" depth : \")\
    \ + to_string(max_dep);\n    return ret;\n  }\n\n  void dump(vector<string>& s,\
    \ const Node* t, int i, int j, int off,\n            int cdep = 0, int* mdep =\
    \ nullptr) {\n    if (!t) return;\n    *mdep = max(cdep, *mdep);\n\n    string\
    \ n = to_string(t->key);\n    copy(begin(n), end(n), begin(s[i]) + j);\n\n   \
    \ if (t->l) {\n      s[i + 1][j - off / 2] = 'L';\n      dump(s, t->l, i + 2,\
    \ j - off, off / 2, cdep + 1, mdep);\n    }\n    if (t->r) {\n      s[i + 1][j\
    \ + off / 2] = 'R';\n      dump(s, t->r, i + 2, j + off, off / 2, cdep + 1, mdep);\n\
    \    }\n  }\n};\ntemplate <typename T, int S, bool MULTI>\ntypename OrderedSet<T,\
    \ S, MULTI>::RBST* OrderedSet<T, S, MULTI>::rbst = nullptr;\n"
  dependsOn:
  - binary-search-tree/randomized-binary-search-tree.hpp
  isVerificationFile: false
  path: binary-search-tree/rbst-ordered-set.hpp
  requiredBy: []
  timestamp: '2020-10-08 01:49:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: binary-search-tree/rbst-ordered-set.hpp
layout: document
redirect_from:
- /library/binary-search-tree/rbst-ordered-set.hpp
- /library/binary-search-tree/rbst-ordered-set.hpp.html
title: binary-search-tree/rbst-ordered-set.hpp
---
