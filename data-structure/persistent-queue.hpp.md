---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-persistent-queue.test.cpp
    title: verify/verify-yosupo-ds/yosupo-persistent-queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/persistent-queue.hpp\"\n\ntemplate <typename\
    \ T>\nstruct PersistentQueue {\n  struct Node {\n    int d;\n    T val;\n    vector<Node*>\
    \ par;\n    Node(int d_) : d(d_) {}\n    Node(int d_, const T& val_, Node* n)\
    \ : d(d_), val(val_), par({n}) {}\n  };\n\n  using P = pair<Node*, Node*>;\n \
    \ vector<P> roots;\n\n  PersistentQueue() {\n    Node* root = new Node(0);\n \
    \   roots.emplace_back(root, root);\n  }\n\n  int push(const T& val, int id =\
    \ -1) {\n    Node *s, *e;\n    tie(s, e) = id == -1 ? roots.back() : roots[id];\n\
    \    Node* ne = new Node(e->d + 1, val, e);\n    roots.emplace_back(s, ne);\n\
    \    for (int i = 0;; i++) {\n      if ((int)e->par.size() <= i) break;\n    \
    \  Node* nxt = e->par[i];\n      ne->par.push_back(e = nxt);\n    }\n    return\
    \ (int)roots.size() - 1;\n  }\n\n  pair<T, int> pop(int id = -1) {\n    Node *s,\
    \ *e;\n    tie(s, e) = id == -1 ? roots.back() : roots[id];\n    Node* ns = e;\n\
    \    for (int x = e->d - s->d - 1; x;) {\n      int d = __builtin_ctz(x);\n  \
    \    ns = ns->par[d];\n      x -= 1 << d;\n    }\n    roots.emplace_back(ns, e);\n\
    \    return make_pair(ns->val, (int)roots.size() - 1);\n  }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct PersistentQueue {\n  struct\
    \ Node {\n    int d;\n    T val;\n    vector<Node*> par;\n    Node(int d_) : d(d_)\
    \ {}\n    Node(int d_, const T& val_, Node* n) : d(d_), val(val_), par({n}) {}\n\
    \  };\n\n  using P = pair<Node*, Node*>;\n  vector<P> roots;\n\n  PersistentQueue()\
    \ {\n    Node* root = new Node(0);\n    roots.emplace_back(root, root);\n  }\n\
    \n  int push(const T& val, int id = -1) {\n    Node *s, *e;\n    tie(s, e) = id\
    \ == -1 ? roots.back() : roots[id];\n    Node* ne = new Node(e->d + 1, val, e);\n\
    \    roots.emplace_back(s, ne);\n    for (int i = 0;; i++) {\n      if ((int)e->par.size()\
    \ <= i) break;\n      Node* nxt = e->par[i];\n      ne->par.push_back(e = nxt);\n\
    \    }\n    return (int)roots.size() - 1;\n  }\n\n  pair<T, int> pop(int id =\
    \ -1) {\n    Node *s, *e;\n    tie(s, e) = id == -1 ? roots.back() : roots[id];\n\
    \    Node* ns = e;\n    for (int x = e->d - s->d - 1; x;) {\n      int d = __builtin_ctz(x);\n\
    \      ns = ns->par[d];\n      x -= 1 << d;\n    }\n    roots.emplace_back(ns,\
    \ e);\n    return make_pair(ns->val, (int)roots.size() - 1);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/persistent-queue.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-persistent-queue.test.cpp
documentation_of: data-structure/persistent-queue.hpp
layout: document
redirect_from:
- /library/data-structure/persistent-queue.hpp
- /library/data-structure/persistent-queue.hpp.html
title: data-structure/persistent-queue.hpp
---
