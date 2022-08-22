---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/binary-indexed-tree.hpp
    title: Binary Indexed Tree(Fenwick Tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/inversion-counting.hpp\"\n\n#line 2 \"data-structure/binary-indexed-tree.hpp\"\
    \n\ntemplate <typename T>\nstruct BinaryIndexedTree {\n  int N;\n  vector<T> data;\n\
    \n  BinaryIndexedTree() = default;\n\n  BinaryIndexedTree(int size) { init(size);\
    \ }\n\n  void init(int size) {\n    N = size + 2;\n    data.assign(N + 1, {});\n\
    \  }\n\n  // get sum of [0,k]\n  T sum(int k) const {\n    if (k < 0) return T{};\
    \  // return 0 if k < 0\n    T ret{};\n    for (++k; k > 0; k -= k & -k) ret +=\
    \ data[k];\n    return ret;\n  }\n\n  // getsum of [l,r]\n  inline T sum(int l,\
    \ int r) const { return sum(r) - sum(l - 1); }\n\n  // get value of k\n  inline\
    \ T operator[](int k) const { return sum(k) - sum(k - 1); }\n\n  // data[k] +=\
    \ x\n  void add(int k, T x) {\n    for (++k; k < N; k += k & -k) data[k] += x;\n\
    \  }\n\n  // range add x to [l,r]\n  void imos(int l, int r, T x) {\n    add(l,\
    \ x);\n    add(r + 1, -x);\n  }\n\n  // minimize i s.t. sum(i) >= w\n  int lower_bound(T\
    \ w) {\n    if (w <= 0) return 0;\n    int x = 0;\n    for (int k = 1 << __lg(N);\
    \ k; k >>= 1) {\n      if (x + k <= N - 1 && data[x + k] < w) {\n        w -=\
    \ data[x + k];\n        x += k;\n      }\n    }\n    return x;\n  }\n\n  // minimize\
    \ i s.t. sum(i) > w\n  int upper_bound(T w) {\n    if (w < 0) return 0;\n    int\
    \ x = 0;\n    for (int k = 1 << __lg(N); k; k >>= 1) {\n      if (x + k <= N -\
    \ 1 && data[x + k] <= w) {\n        w -= data[x + k];\n        x += k;\n     \
    \ }\n    }\n    return x;\n  }\n};\n\n/**\n * @brief Binary Indexed Tree(Fenwick\
    \ Tree)\n * @docs docs/data-structure/binary-indexed-tree.md\n */\n#line 4 \"\
    dp/inversion-counting.hpp\"\n\n// \u8EE2\u5012\u6570\ntemplate <typename T>\n\
    long long inversion_counting(const vector<T>& v) {\n  vector<T> xs{v};\n  sort(begin(xs),\
    \ end(xs));\n  xs.erase(unique(begin(xs), end(xs)), end(xs));\n  int s = xs.size();\n\
    \  BinaryIndexedTree<long long> bit(s + 1);\n  long long ans = 0;\n  for (auto&\
    \ x : v) {\n    int i = lower_bound(begin(xs), end(xs), x) - begin(xs);\n    if\
    \ (i + 1 != s) ans += bit.sum(i + 1, s - 1);\n    bit.add(i, 1);\n  }\n  return\
    \ ans;\n}\n\n// \u96A3\u63A5 swap \u306B\u3088\u3063\u3066 v \u3092 w \u306B\u5909\
    \u3048\u308B\u306E\u306B\u304B\u304B\u308B\u624B\u6570 (\u4E0D\u53EF\u80FD : -1)\n\
    template <typename T>\nlong long swap_distance(const vector<T>& v, const vector<T>&\
    \ w) {\n  if (v.size() != w.size()) return -1;\n  int N = v.size();\n  vector<pair<T,\
    \ int>> vv(N), ww(N);\n  for (int i = 0; i < N; i++) {\n    vv[i] = make_pair(v[i],\
    \ i);\n    ww[i] = make_pair(w[i], i);\n  }\n  sort(begin(vv), end(vv));\n  sort(begin(ww),\
    \ end(ww));\n  for (int i = 0; i < N; i++) {\n    if (vv[i].first != ww[i].first)\
    \ return -1;\n  }\n  vector<int> order(N);\n  for (int i = 0; i < N; i++) {\n\
    \    order[vv[i].second] = ww[i].second;\n  }\n  return inversion_counting(order);\n\
    }\n"
  code: "#pragma once\n\n#include \"../data-structure/binary-indexed-tree.hpp\"\n\n\
    // \u8EE2\u5012\u6570\ntemplate <typename T>\nlong long inversion_counting(const\
    \ vector<T>& v) {\n  vector<T> xs{v};\n  sort(begin(xs), end(xs));\n  xs.erase(unique(begin(xs),\
    \ end(xs)), end(xs));\n  int s = xs.size();\n  BinaryIndexedTree<long long> bit(s\
    \ + 1);\n  long long ans = 0;\n  for (auto& x : v) {\n    int i = lower_bound(begin(xs),\
    \ end(xs), x) - begin(xs);\n    if (i + 1 != s) ans += bit.sum(i + 1, s - 1);\n\
    \    bit.add(i, 1);\n  }\n  return ans;\n}\n\n// \u96A3\u63A5 swap \u306B\u3088\
    \u3063\u3066 v \u3092 w \u306B\u5909\u3048\u308B\u306E\u306B\u304B\u304B\u308B\
    \u624B\u6570 (\u4E0D\u53EF\u80FD : -1)\ntemplate <typename T>\nlong long swap_distance(const\
    \ vector<T>& v, const vector<T>& w) {\n  if (v.size() != w.size()) return -1;\n\
    \  int N = v.size();\n  vector<pair<T, int>> vv(N), ww(N);\n  for (int i = 0;\
    \ i < N; i++) {\n    vv[i] = make_pair(v[i], i);\n    ww[i] = make_pair(w[i],\
    \ i);\n  }\n  sort(begin(vv), end(vv));\n  sort(begin(ww), end(ww));\n  for (int\
    \ i = 0; i < N; i++) {\n    if (vv[i].first != ww[i].first) return -1;\n  }\n\
    \  vector<int> order(N);\n  for (int i = 0; i < N; i++) {\n    order[vv[i].second]\
    \ = ww[i].second;\n  }\n  return inversion_counting(order);\n}\n"
  dependsOn:
  - data-structure/binary-indexed-tree.hpp
  isVerificationFile: false
  path: dp/inversion-counting.hpp
  requiredBy: []
  timestamp: '2022-08-22 19:46:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/inversion-counting.hpp
layout: document
redirect_from:
- /library/dp/inversion-counting.hpp
- /library/dp/inversion-counting.hpp.html
title: dp/inversion-counting.hpp
---
