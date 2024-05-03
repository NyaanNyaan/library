---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-indexed-tree.hpp
    title: Binary Indexed Tree(Fenwick Tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-static-rectangle-add-rectangle-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-static-rectangle-add-rectangle-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://hitonanode.github.io/cplib-cpp/data_structure/rectangle_add_rectangle_sum.hpp
  bundledCode: "#line 2 \"data-structure-2d/rectangle-add-rectangle-sum.hpp\"\n\n\
    #include <vector>\nusing namespace std;\n\n#line 2 \"data-structure/binary-indexed-tree.hpp\"\
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
    \ Tree)\n * @docs docs/data-structure/binary-indexed-tree.md\n */\n#line 7 \"\
    data-structure-2d/rectangle-add-rectangle-sum.hpp\"\n\n// https://hitonanode.github.io/cplib-cpp/data_structure/rectangle_add_rectangle_sum.hpp\n\
    template <class I, class T>\nclass RectangleAddRectangleSum {\n  struct AddQuery\
    \ {\n    I xl, xr, yl, yr;\n    T val;\n  };\n  struct SumQuery {\n    I xl, xr,\
    \ yl, yr;\n  };\n  vector<AddQuery> add_queries;\n  vector<SumQuery> sum_queries;\n\
    \n public:\n  RectangleAddRectangleSum() = default;\n\n  void add_rectangle(I\
    \ xl, I xr, I yl, I yr, T val) {\n    add_queries.push_back(AddQuery{xl, xr, yl,\
    \ yr, val});\n  }\n  void add_query(I xl, I xr, I yl, I yr) {\n    sum_queries.push_back(SumQuery{xl,\
    \ xr, yl, yr});\n  }\n\n  vector<T> solve() const {\n    vector<I> ys;\n    for\
    \ (const auto &a : add_queries) {\n      ys.push_back(a.yl);\n      ys.push_back(a.yr);\n\
    \    }\n    sort(ys.begin(), ys.end());\n    ys.erase(unique(ys.begin(), ys.end()),\
    \ ys.end());\n\n    const int Y = ys.size();\n\n    vector<tuple<I, int, int>>\
    \ ops;\n    for (int q = 0; q < int(sum_queries.size()); ++q) {\n      ops.emplace_back(sum_queries[q].xl,\
    \ 0, q);\n      ops.emplace_back(sum_queries[q].xr, 1, q);\n    }\n    for (int\
    \ q = 0; q < int(add_queries.size()); ++q) {\n      ops.emplace_back(add_queries[q].xl,\
    \ 2, q);\n      ops.emplace_back(add_queries[q].xr, 3, q);\n    }\n    sort(ops.begin(),\
    \ ops.end());\n\n    BinaryIndexedTree<T> b00(Y), b01(Y), b10(Y), b11(Y);\n  \
    \  vector<T> ret(sum_queries.size());\n    for (auto o : ops) {\n      int qtype\
    \ = get<1>(o), q = get<2>(o);\n      if (qtype >= 2) {\n        const AddQuery\
    \ &query = add_queries.at(q);\n        int i = lower_bound(ys.begin(), ys.end(),\
    \ query.yl) - ys.begin();\n        int j = lower_bound(ys.begin(), ys.end(), query.yr)\
    \ - ys.begin();\n        T x = get<0>(o);\n        T yi = query.yl, yj = query.yr;\n\
    \        if (qtype & 1) swap(i, j), swap(yi, yj);\n\n        b00.add(i, x * yi\
    \ * query.val);\n        b01.add(i, -x * query.val);\n        b10.add(i, -yi *\
    \ query.val);\n        b11.add(i, query.val);\n        b00.add(j, -x * yj * query.val);\n\
    \        b01.add(j, x * query.val);\n        b10.add(j, yj * query.val);\n   \
    \     b11.add(j, -query.val);\n      } else {\n        const SumQuery &query =\
    \ sum_queries.at(q);\n        int i = lower_bound(ys.begin(), ys.end(), query.yl)\
    \ - ys.begin();\n        int j = lower_bound(ys.begin(), ys.end(), query.yr) -\
    \ ys.begin();\n        T x = get<0>(o);\n        T yi = query.yl, yj = query.yr;\n\
    \        if (qtype & 1) swap(i, j), swap(yi, yj);\n\n        i--, j--;\n     \
    \   ret[q] +=\n            b00.sum(i) + b01.sum(i) * yi + b10.sum(i) * x + b11.sum(i)\
    \ * x * yi;\n        ret[q] -=\n            b00.sum(j) + b01.sum(j) * yj + b10.sum(j)\
    \ * x + b11.sum(j) * x * yj;\n      }\n    }\n    return ret;\n  }\n};\n"
  code: "#pragma once\n\n#include <vector>\nusing namespace std;\n\n#include \"../data-structure/binary-indexed-tree.hpp\"\
    \n\n// https://hitonanode.github.io/cplib-cpp/data_structure/rectangle_add_rectangle_sum.hpp\n\
    template <class I, class T>\nclass RectangleAddRectangleSum {\n  struct AddQuery\
    \ {\n    I xl, xr, yl, yr;\n    T val;\n  };\n  struct SumQuery {\n    I xl, xr,\
    \ yl, yr;\n  };\n  vector<AddQuery> add_queries;\n  vector<SumQuery> sum_queries;\n\
    \n public:\n  RectangleAddRectangleSum() = default;\n\n  void add_rectangle(I\
    \ xl, I xr, I yl, I yr, T val) {\n    add_queries.push_back(AddQuery{xl, xr, yl,\
    \ yr, val});\n  }\n  void add_query(I xl, I xr, I yl, I yr) {\n    sum_queries.push_back(SumQuery{xl,\
    \ xr, yl, yr});\n  }\n\n  vector<T> solve() const {\n    vector<I> ys;\n    for\
    \ (const auto &a : add_queries) {\n      ys.push_back(a.yl);\n      ys.push_back(a.yr);\n\
    \    }\n    sort(ys.begin(), ys.end());\n    ys.erase(unique(ys.begin(), ys.end()),\
    \ ys.end());\n\n    const int Y = ys.size();\n\n    vector<tuple<I, int, int>>\
    \ ops;\n    for (int q = 0; q < int(sum_queries.size()); ++q) {\n      ops.emplace_back(sum_queries[q].xl,\
    \ 0, q);\n      ops.emplace_back(sum_queries[q].xr, 1, q);\n    }\n    for (int\
    \ q = 0; q < int(add_queries.size()); ++q) {\n      ops.emplace_back(add_queries[q].xl,\
    \ 2, q);\n      ops.emplace_back(add_queries[q].xr, 3, q);\n    }\n    sort(ops.begin(),\
    \ ops.end());\n\n    BinaryIndexedTree<T> b00(Y), b01(Y), b10(Y), b11(Y);\n  \
    \  vector<T> ret(sum_queries.size());\n    for (auto o : ops) {\n      int qtype\
    \ = get<1>(o), q = get<2>(o);\n      if (qtype >= 2) {\n        const AddQuery\
    \ &query = add_queries.at(q);\n        int i = lower_bound(ys.begin(), ys.end(),\
    \ query.yl) - ys.begin();\n        int j = lower_bound(ys.begin(), ys.end(), query.yr)\
    \ - ys.begin();\n        T x = get<0>(o);\n        T yi = query.yl, yj = query.yr;\n\
    \        if (qtype & 1) swap(i, j), swap(yi, yj);\n\n        b00.add(i, x * yi\
    \ * query.val);\n        b01.add(i, -x * query.val);\n        b10.add(i, -yi *\
    \ query.val);\n        b11.add(i, query.val);\n        b00.add(j, -x * yj * query.val);\n\
    \        b01.add(j, x * query.val);\n        b10.add(j, yj * query.val);\n   \
    \     b11.add(j, -query.val);\n      } else {\n        const SumQuery &query =\
    \ sum_queries.at(q);\n        int i = lower_bound(ys.begin(), ys.end(), query.yl)\
    \ - ys.begin();\n        int j = lower_bound(ys.begin(), ys.end(), query.yr) -\
    \ ys.begin();\n        T x = get<0>(o);\n        T yi = query.yl, yj = query.yr;\n\
    \        if (qtype & 1) swap(i, j), swap(yi, yj);\n\n        i--, j--;\n     \
    \   ret[q] +=\n            b00.sum(i) + b01.sum(i) * yi + b10.sum(i) * x + b11.sum(i)\
    \ * x * yi;\n        ret[q] -=\n            b00.sum(j) + b01.sum(j) * yj + b10.sum(j)\
    \ * x + b11.sum(j) * x * yj;\n      }\n    }\n    return ret;\n  }\n};\n"
  dependsOn:
  - data-structure/binary-indexed-tree.hpp
  isVerificationFile: false
  path: data-structure-2d/rectangle-add-rectangle-sum.hpp
  requiredBy: []
  timestamp: '2024-05-03 21:06:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-static-rectangle-add-rectangle-sum.test.cpp
documentation_of: data-structure-2d/rectangle-add-rectangle-sum.hpp
layout: document
redirect_from:
- /library/data-structure-2d/rectangle-add-rectangle-sum.hpp
- /library/data-structure-2d/rectangle-add-rectangle-sum.hpp.html
title: data-structure-2d/rectangle-add-rectangle-sum.hpp
---
