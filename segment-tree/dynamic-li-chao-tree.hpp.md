---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"segment-tree/dynamic-li-chao-tree.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename T, T INF>\nstruct DynamicLiChaoTree\
    \ {\n  struct Line {\n    T slope, intercept;\n    Line() : slope(0), intercept(INF)\
    \ {}\n    Line(T slope, T intercept) : slope(slope), intercept(intercept) {}\n\
    \    inline T get(T x) const { return slope * x + intercept; }\n    inline bool\
    \ over(const Line &other, const T &x) const {\n      return get(x) < other.get(x);\n\
    \    }\n  };\n\n  // remind \u30BB\u30B0\u6728\u306F1-indexed\u306E\u5B9F\u88C5\
    \n  T xmin, xmax, _size;\n  unordered_map<T, Line> seg;\n\n  // [l , r]\u306B\u304A\
    \u3051\u308BLi Chao Tree\n  DynamicLiChaoTree(T xmin, T xmax) : xmin(xmin), xmax(xmax)\
    \ {\n    _size = 1;\n    while (_size < xmax - xmin + 1) _size <<= 1;\n  }\n\n\
    \  // \u5185\u90E8\u7528\u306E\u95A2\u6570\n  void update(T a, T b, T left, T\
    \ right, T seg_idx) {\n    Line line(a, b);\n    while (1) {\n      T mid = (left\
    \ + right) >> 1;\n      bool l_over = line.over(seg[seg_idx], min(xmax, left +\
    \ xmin));\n      bool r_over = line.over(seg[seg_idx], min(xmax, right - 1 + xmin));\n\
    \      if (l_over == r_over) {\n        if (l_over) swap(seg[seg_idx], line);\n\
    \        return;\n      }\n      bool m_over = line.over(seg[seg_idx], min(xmax,\
    \ mid + xmin));\n      if (m_over) swap(seg[seg_idx], line);\n      if (l_over\
    \ != m_over)\n        seg_idx = (seg_idx << 1), right = mid;\n      else\n   \
    \     seg_idx = (seg_idx << 1) | 1, left = mid;\n    }\n  }\n  // \u5185\u90E8\
    \u7528\u306E\u95A2\u6570\n  void update(T a, T b, T seg_idx) {\n    T left, right;\n\
    \    T upper_bit = 63 - __builtin_clzll(seg_idx);\n    left = (_size >> upper_bit)\
    \ * (seg_idx - (1 << upper_bit));\n    right = left + (_size >> upper_bit);\n\
    \    update(a, b, left, right, seg_idx);\n  }\n  /*\n  void update(T a,T b,T left,T\
    \ right){\n    T lower_bit = (left | right) & (- (left | right) );\n    T seg_idx\
    \ = ( _size + left ) / lower_bit;\n    update(a , b , left , right , seg_idx);\n\
    \  }\n  */\n  // y = ax + b\u306A\u308B\u76F4\u7DDA\u3092\u8FFD\u52A0\n  void\
    \ update(T a, T b) { update(a, b, 0, _size, 1); }\n\n  // \u9589\u533A\u9593x\
    \ in [left , right]\u306B\u7DDA\u5206y = ax + b\u3092\u8FFD\u52A0\u3059\u308B\u30AF\
    \u30A8\u30EA\n  void update_line_segment(T a, T b, T left, T right) {\n    left\
    \ -= xmin - _size, right -= xmin - _size - 1;\n    for (; left < right; left >>=\
    \ 1, right >>= 1) {\n      if (left & 1) update(a, b, left++);\n      if (right\
    \ & 1) update(a, b, --right);\n    }\n  }\n\n  // x\u306B\u304A\u3051\u308B\u6700\
    \u5C0F\u5024\u30AF\u30A8\u30EA\n  T query(T x) {\n    T left = 0, right = _size,\
    \ seg_idx = 1, idx = x - xmin, ret = INF;\n    while (1) {\n      T cur = seg[seg_idx].get(x);\n\
    \      // \u7DDA\u5206\u8FFD\u52A0\u30AF\u30A8\u30EA\u304C\u306A\u3044\u5834\u5408\
    \u306F\u3053\u3053\u306E\u30B3\u30E1\u30F3\u30C8\u30A2\u30A6\u30C8\u3092\u5916\
    \u3057\u3066\u9AD8\u901F\u5316\u53EF\u80FD(1.5\u500D\u7A0B\u5EA6\uFF1F)\n    \
    \  // if(cur == INF) break;\n      ret = min(ret, cur);\n      if (left + 1 >=\
    \ right) break;\n      T mid = (left + right) >> 1;\n      if (idx < mid)\n  \
    \      seg_idx = (seg_idx << 1), right = mid;\n      else\n        seg_idx = (seg_idx\
    \ << 1) | 1, left = mid;\n    }\n    return ret;\n  }\n\n  void merge(DynamicLiChaoTree<T,\
    \ INF> &other) {\n    if (seg.size() < other.seg.size()) seg.swap(other.seg);\n\
    \    for (auto &x : other.seg) {\n      if (x.second.intercept == INF) continue;\n\
    \      update(x.second.slope, x.second.intercept, x.first);\n    }\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename T, T INF>\nstruct DynamicLiChaoTree {\n  struct Line {\n    T slope,\
    \ intercept;\n    Line() : slope(0), intercept(INF) {}\n    Line(T slope, T intercept)\
    \ : slope(slope), intercept(intercept) {}\n    inline T get(T x) const { return\
    \ slope * x + intercept; }\n    inline bool over(const Line &other, const T &x)\
    \ const {\n      return get(x) < other.get(x);\n    }\n  };\n\n  // remind \u30BB\
    \u30B0\u6728\u306F1-indexed\u306E\u5B9F\u88C5\n  T xmin, xmax, _size;\n  unordered_map<T,\
    \ Line> seg;\n\n  // [l , r]\u306B\u304A\u3051\u308BLi Chao Tree\n  DynamicLiChaoTree(T\
    \ xmin, T xmax) : xmin(xmin), xmax(xmax) {\n    _size = 1;\n    while (_size <\
    \ xmax - xmin + 1) _size <<= 1;\n  }\n\n  // \u5185\u90E8\u7528\u306E\u95A2\u6570\
    \n  void update(T a, T b, T left, T right, T seg_idx) {\n    Line line(a, b);\n\
    \    while (1) {\n      T mid = (left + right) >> 1;\n      bool l_over = line.over(seg[seg_idx],\
    \ min(xmax, left + xmin));\n      bool r_over = line.over(seg[seg_idx], min(xmax,\
    \ right - 1 + xmin));\n      if (l_over == r_over) {\n        if (l_over) swap(seg[seg_idx],\
    \ line);\n        return;\n      }\n      bool m_over = line.over(seg[seg_idx],\
    \ min(xmax, mid + xmin));\n      if (m_over) swap(seg[seg_idx], line);\n     \
    \ if (l_over != m_over)\n        seg_idx = (seg_idx << 1), right = mid;\n    \
    \  else\n        seg_idx = (seg_idx << 1) | 1, left = mid;\n    }\n  }\n  // \u5185\
    \u90E8\u7528\u306E\u95A2\u6570\n  void update(T a, T b, T seg_idx) {\n    T left,\
    \ right;\n    T upper_bit = 63 - __builtin_clzll(seg_idx);\n    left = (_size\
    \ >> upper_bit) * (seg_idx - (1 << upper_bit));\n    right = left + (_size >>\
    \ upper_bit);\n    update(a, b, left, right, seg_idx);\n  }\n  /*\n  void update(T\
    \ a,T b,T left,T right){\n    T lower_bit = (left | right) & (- (left | right)\
    \ );\n    T seg_idx = ( _size + left ) / lower_bit;\n    update(a , b , left ,\
    \ right , seg_idx);\n  }\n  */\n  // y = ax + b\u306A\u308B\u76F4\u7DDA\u3092\u8FFD\
    \u52A0\n  void update(T a, T b) { update(a, b, 0, _size, 1); }\n\n  // \u9589\u533A\
    \u9593x in [left , right]\u306B\u7DDA\u5206y = ax + b\u3092\u8FFD\u52A0\u3059\u308B\
    \u30AF\u30A8\u30EA\n  void update_line_segment(T a, T b, T left, T right) {\n\
    \    left -= xmin - _size, right -= xmin - _size - 1;\n    for (; left < right;\
    \ left >>= 1, right >>= 1) {\n      if (left & 1) update(a, b, left++);\n    \
    \  if (right & 1) update(a, b, --right);\n    }\n  }\n\n  // x\u306B\u304A\u3051\
    \u308B\u6700\u5C0F\u5024\u30AF\u30A8\u30EA\n  T query(T x) {\n    T left = 0,\
    \ right = _size, seg_idx = 1, idx = x - xmin, ret = INF;\n    while (1) {\n  \
    \    T cur = seg[seg_idx].get(x);\n      // \u7DDA\u5206\u8FFD\u52A0\u30AF\u30A8\
    \u30EA\u304C\u306A\u3044\u5834\u5408\u306F\u3053\u3053\u306E\u30B3\u30E1\u30F3\
    \u30C8\u30A2\u30A6\u30C8\u3092\u5916\u3057\u3066\u9AD8\u901F\u5316\u53EF\u80FD\
    (1.5\u500D\u7A0B\u5EA6\uFF1F)\n      // if(cur == INF) break;\n      ret = min(ret,\
    \ cur);\n      if (left + 1 >= right) break;\n      T mid = (left + right) >>\
    \ 1;\n      if (idx < mid)\n        seg_idx = (seg_idx << 1), right = mid;\n \
    \     else\n        seg_idx = (seg_idx << 1) | 1, left = mid;\n    }\n    return\
    \ ret;\n  }\n\n  void merge(DynamicLiChaoTree<T, INF> &other) {\n    if (seg.size()\
    \ < other.seg.size()) seg.swap(other.seg);\n    for (auto &x : other.seg) {\n\
    \      if (x.second.intercept == INF) continue;\n      update(x.second.slope,\
    \ x.second.intercept, x.first);\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/dynamic-li-chao-tree.hpp
  requiredBy: []
  timestamp: '2020-07-28 11:29:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment-tree/dynamic-li-chao-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/dynamic-li-chao-tree.hpp
- /library/segment-tree/dynamic-li-chao-tree.hpp.html
title: segment-tree/dynamic-li-chao-tree.hpp
---
