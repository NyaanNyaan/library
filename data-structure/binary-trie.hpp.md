---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-binary-trie.test.cpp
    title: verify/verify-yosupo-ds/yosupo-binary-trie.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/data-structure/binary-trie.md
    document_title: Binary Trie
    links: []
  bundledCode: "#line 2 \"data-structure/binary-trie.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename T, int MAX_LOG, int NODES = 16777216>\n\
    struct BinaryTrie {\n  using Container = vector<int>;\n  struct Node {\n    Node\
    \ *nxt[2];\n    int exist;\n    Container accept;\n    Node() {}\n  };\n\n  Node\
    \ *pool;\n  int pid;\n  T lazy;\n  Node *nil;\n  Node *root;\n\n  BinaryTrie()\
    \ : pid(0), lazy(T(0)), nil(nullptr) {\n    pool = new Node[NODES];\n    nil =\
    \ my_new();\n    nil->nxt[0] = nil->nxt[1] = root = nil;\n  }\n\n  Node *my_new(int\
    \ exist_ = 0, int id = -1) {\n    pool[pid].nxt[0] = pool[pid].nxt[1] = nil;\n\
    \    pool[pid].exist = exist_;\n    if (id != -1) pool[pid].accept.push_back(id);\n\
    \    return &(pool[pid++]);\n  }\n\n  Node *merge(Node *l, Node *r) {\n    pool[pid].nxt[0]\
    \ = l;\n    pool[pid].nxt[1] = r;\n    pool[pid].exist = l->exist + r->exist;\n\
    \    return &(pool[pid++]);\n  }\n\n private:\n  Node *add_(const T &x, int id,\
    \ Node *n, int bit_idx) {\n    if (bit_idx == -1) {\n      if (n == nil) return\
    \ my_new(1, id);\n      n->exist++;\n      n->accept.push_back(id);\n      return\
    \ n;\n    } else {\n      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))\n\
    \        return merge(add_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);\n     \
    \ else\n        return merge(n->nxt[0], add_(x, id, n->nxt[1], bit_idx - 1));\n\
    \    }\n  }\n\n public:\n  void add(const T &x, int id = -1) { root = add_(x,\
    \ id, root, MAX_LOG); }\n\n private:\n  Node *del_(const T &x, int id, Node *n,\
    \ int bit_idx) {\n    if (bit_idx == -1) {\n      n->exist--;\n      return n;\n\
    \    } else {\n      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))\n  \
    \      return merge(del_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);\n      else\n\
    \        return merge(n->nxt[0], del_(x, id, n->nxt[1], bit_idx - 1));\n    }\n\
    \  }\n\n public:\n  void del(const T &x, int id = -1) { root = del_(x, id, root,\
    \ MAX_LOG); }\n\n private:\n  pair<int, Container &> find_(const T &x, Node *n,\
    \ int bit_idx) {\n    if (bit_idx == -1)\n      return pair<int, Container &>(n->exist,\
    \ n->accept);\n    else {\n      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx)\
    \ & 1))\n        return find_(x, n->nxt[0], bit_idx - 1);\n      else\n      \
    \  return find_(x, n->nxt[1], bit_idx - 1);\n    }\n  }\n\n public:\n  pair<int,\
    \ Container &> find(const T &x) { return find_(x, root, MAX_LOG); }\n\n private:\n\
    \  pair<T, Container &> max_element_(Node *n, int bit_idx) {\n    if (bit_idx\
    \ == -1) return pair<T, Container &>(0, n->accept);\n    if (n->nxt[~(lazy >>\
    \ bit_idx) & 1]->exist) {\n      auto ret = max_element_(n->nxt[~(lazy >> bit_idx)\
    \ & 1], bit_idx - 1);\n      ret.first |= T(1) << bit_idx;\n      return ret;\n\
    \    } else {\n      return max_element_(n->nxt[(lazy >> bit_idx) & 1], bit_idx\
    \ - 1);\n    }\n  }\n\n public:\n  pair<T, Container &> max_element() { return\
    \ max_element_(root, MAX_LOG); }\n\n private:\n  pair<T, Container &> min_element_(Node\
    \ *n, int bit_idx) {\n    if (bit_idx == -1) return pair<T, Container &>(0, n->accept);\n\
    \    if (n->nxt[(lazy >> bit_idx) & 1]->exist) {\n      return min_element_(n->nxt[(lazy\
    \ >> bit_idx) & 1], bit_idx - 1);\n    } else {\n      auto ret = min_element_(n->nxt[~(lazy\
    \ >> bit_idx) & 1], bit_idx - 1);\n      ret.first |= T(1) << bit_idx;\n     \
    \ return ret;\n    }\n  }\n\n public:\n  pair<T, Container &> min_element() {\
    \ return min_element_(root, MAX_LOG); }\n\n private:\n  pair<T, Container &> get_kth_(Node\
    \ *n, int64_t k, int bit_idx) {\n    if (bit_idx == -1) return pair<T, Container\
    \ &>(0, n->accept);\n    int ex0 = n->nxt[(lazy >> bit_idx) & 1]->exist;\n   \
    \ if (ex0 < k) {\n      auto ret = get_kth_(n->nxt[~(lazy >> bit_idx) & 1], k\
    \ - ex0, bit_idx - 1);\n      ret.first |= T(1) << bit_idx;\n      return ret;\n\
    \    } else {\n      return get_kth_(n->nxt[(lazy >> bit_idx) & 1], k, bit_idx\
    \ - 1);\n    }\n  }\n\n public:\n  pair<T, Container &> get_kth(int64_t k) { return\
    \ get_kth_(root, k, MAX_LOG); }\n\n  void operate_xor(T x) { lazy ^= x; }\n};\n\
    \n/**\n * @brief Binary Trie\n * @docs docs/data-structure/binary-trie.md\n */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename T, int MAX_LOG, int NODES = 16777216>\nstruct BinaryTrie {\n  using\
    \ Container = vector<int>;\n  struct Node {\n    Node *nxt[2];\n    int exist;\n\
    \    Container accept;\n    Node() {}\n  };\n\n  Node *pool;\n  int pid;\n  T\
    \ lazy;\n  Node *nil;\n  Node *root;\n\n  BinaryTrie() : pid(0), lazy(T(0)), nil(nullptr)\
    \ {\n    pool = new Node[NODES];\n    nil = my_new();\n    nil->nxt[0] = nil->nxt[1]\
    \ = root = nil;\n  }\n\n  Node *my_new(int exist_ = 0, int id = -1) {\n    pool[pid].nxt[0]\
    \ = pool[pid].nxt[1] = nil;\n    pool[pid].exist = exist_;\n    if (id != -1)\
    \ pool[pid].accept.push_back(id);\n    return &(pool[pid++]);\n  }\n\n  Node *merge(Node\
    \ *l, Node *r) {\n    pool[pid].nxt[0] = l;\n    pool[pid].nxt[1] = r;\n    pool[pid].exist\
    \ = l->exist + r->exist;\n    return &(pool[pid++]);\n  }\n\n private:\n  Node\
    \ *add_(const T &x, int id, Node *n, int bit_idx) {\n    if (bit_idx == -1) {\n\
    \      if (n == nil) return my_new(1, id);\n      n->exist++;\n      n->accept.push_back(id);\n\
    \      return n;\n    } else {\n      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx)\
    \ & 1))\n        return merge(add_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);\n\
    \      else\n        return merge(n->nxt[0], add_(x, id, n->nxt[1], bit_idx -\
    \ 1));\n    }\n  }\n\n public:\n  void add(const T &x, int id = -1) { root = add_(x,\
    \ id, root, MAX_LOG); }\n\n private:\n  Node *del_(const T &x, int id, Node *n,\
    \ int bit_idx) {\n    if (bit_idx == -1) {\n      n->exist--;\n      return n;\n\
    \    } else {\n      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))\n  \
    \      return merge(del_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);\n      else\n\
    \        return merge(n->nxt[0], del_(x, id, n->nxt[1], bit_idx - 1));\n    }\n\
    \  }\n\n public:\n  void del(const T &x, int id = -1) { root = del_(x, id, root,\
    \ MAX_LOG); }\n\n private:\n  pair<int, Container &> find_(const T &x, Node *n,\
    \ int bit_idx) {\n    if (bit_idx == -1)\n      return pair<int, Container &>(n->exist,\
    \ n->accept);\n    else {\n      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx)\
    \ & 1))\n        return find_(x, n->nxt[0], bit_idx - 1);\n      else\n      \
    \  return find_(x, n->nxt[1], bit_idx - 1);\n    }\n  }\n\n public:\n  pair<int,\
    \ Container &> find(const T &x) { return find_(x, root, MAX_LOG); }\n\n private:\n\
    \  pair<T, Container &> max_element_(Node *n, int bit_idx) {\n    if (bit_idx\
    \ == -1) return pair<T, Container &>(0, n->accept);\n    if (n->nxt[~(lazy >>\
    \ bit_idx) & 1]->exist) {\n      auto ret = max_element_(n->nxt[~(lazy >> bit_idx)\
    \ & 1], bit_idx - 1);\n      ret.first |= T(1) << bit_idx;\n      return ret;\n\
    \    } else {\n      return max_element_(n->nxt[(lazy >> bit_idx) & 1], bit_idx\
    \ - 1);\n    }\n  }\n\n public:\n  pair<T, Container &> max_element() { return\
    \ max_element_(root, MAX_LOG); }\n\n private:\n  pair<T, Container &> min_element_(Node\
    \ *n, int bit_idx) {\n    if (bit_idx == -1) return pair<T, Container &>(0, n->accept);\n\
    \    if (n->nxt[(lazy >> bit_idx) & 1]->exist) {\n      return min_element_(n->nxt[(lazy\
    \ >> bit_idx) & 1], bit_idx - 1);\n    } else {\n      auto ret = min_element_(n->nxt[~(lazy\
    \ >> bit_idx) & 1], bit_idx - 1);\n      ret.first |= T(1) << bit_idx;\n     \
    \ return ret;\n    }\n  }\n\n public:\n  pair<T, Container &> min_element() {\
    \ return min_element_(root, MAX_LOG); }\n\n private:\n  pair<T, Container &> get_kth_(Node\
    \ *n, int64_t k, int bit_idx) {\n    if (bit_idx == -1) return pair<T, Container\
    \ &>(0, n->accept);\n    int ex0 = n->nxt[(lazy >> bit_idx) & 1]->exist;\n   \
    \ if (ex0 < k) {\n      auto ret = get_kth_(n->nxt[~(lazy >> bit_idx) & 1], k\
    \ - ex0, bit_idx - 1);\n      ret.first |= T(1) << bit_idx;\n      return ret;\n\
    \    } else {\n      return get_kth_(n->nxt[(lazy >> bit_idx) & 1], k, bit_idx\
    \ - 1);\n    }\n  }\n\n public:\n  pair<T, Container &> get_kth(int64_t k) { return\
    \ get_kth_(root, k, MAX_LOG); }\n\n  void operate_xor(T x) { lazy ^= x; }\n};\n\
    \n/**\n * @brief Binary Trie\n * @docs docs/data-structure/binary-trie.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary-trie.hpp
  requiredBy: []
  timestamp: '2020-08-18 23:32:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-binary-trie.test.cpp
documentation_of: data-structure/binary-trie.hpp
layout: document
redirect_from:
- /library/data-structure/binary-trie.hpp
- /library/data-structure/binary-trie.hpp.html
title: Binary Trie
---
## Binary Trie

トライ木の辺に対応する文字を0/1に限定することで非負整数を管理できるようにしたデータ構造。

挿入される値の最大値のビット長さを$w$としたとき、値の挿入・削除・検索などを$\mathrm{O}(w)$で行える。また、全体にXORを掛ける操作が$\mathrm{O}(1)$で出来るのが大きな特徴である。

永続化しやすいようにポインタ木で実装してある(が、永続化はしていない。)

#### 使い方
整数のインデックスが必要な場合は引数`id`にインデックスを入れるとよい。
- `add(x, id)`: xを追加する
- `del(x, id)`: xを削除する
- `find(x)` : xが存在するか調べる。返り値はpair(個数,インデックスの集合)
- `max_element()/min_element()` : 最大値/最小値を返す。返り値はpair(最大値/最小値,インデックスの集合)
- `get_kth()` : k番目の値を返す。返り値はpair(値,インデックスの集合)
- `operate_xor(x)` : 集合全体にxorを作用させる。
