---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-line-add-get-min.test.cpp
    title: verify/verify-yosupo-ds/yosupo-line-add-get-min.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp
    title: verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segment-tree/li-chao-tree.hpp\"\n\n\n\ntemplate <typename\
    \ T, T INF>\nstruct LiChaoTree {\n  struct Line {\n    T slope, intercept;\n \
    \   Line(T slope, T intercept) : slope(slope), intercept(intercept) {}\n    inline\
    \ T get(T x) const { return slope * x + intercept; }\n    inline bool over(const\
    \ Line &other, const T &x) const {\n      return get(x) < other.get(x);\n    }\n\
    \  };\n\n  // remind \u30BB\u30B0\u6728\u306F0-indexed\u306E\u5B9F\u88C5\n  vector<T>\
    \ xset;\n  vector<Line> seg;\n  int _size;\n\n  // \u5F15\u6570x\u306B\u306Fx\u5EA7\
    \u6A19\u306E\u96C6\u5408\u3092\u5165\u308C\u308B\n  LiChaoTree(const vector<T>\
    \ &x) : xset(x) {\n    sort(xset.begin(), xset.end());\n    xset.erase(unique(xset.begin(),\
    \ xset.end()), xset.end());\n    _size = 1;\n    while (_size < (int)xset.size())\
    \ _size <<= 1;\n    while ((int)xset.size() < _size) xset.push_back(xset.back()\
    \ + 1);\n    seg.assign(2 * _size, Line(0, INF));\n  }\n\n  // \u4EE5\u4E0A xset[max]\u4EE5\
    \u4E0B\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\n  int get_more_idx(T k)\
    \ {\n    return lower_bound(xset.begin(), xset.end(), k) - xset.begin();\n  }\n\
    \  // \u4EE5\u4E0B xset[0]\u4EE5\u4E0A\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\
    \u5B9A\n  int get_less_idx(T k) {\n    int ret = upper_bound(xset.begin(), xset.end(),\
    \ k) - xset.begin();\n    return max(0, ret - 1);\n  }\n\n  // \u5185\u90E8\u7528\
    \n  void inner_update(T a, T b, int left, int right, int seg_idx) {\n    Line\
    \ line(a, b);\n    while (1) {\n      int mid = (left + right) >> 1;\n      bool\
    \ l_over = line.over(seg[seg_idx], xset[left]);\n      bool r_over = line.over(seg[seg_idx],\
    \ xset[right - 1]);\n      if (l_over == r_over) {\n        if (l_over) swap(seg[seg_idx],\
    \ line);\n        return;\n      }\n      bool m_over = line.over(seg[seg_idx],\
    \ xset[mid]);\n      if (m_over) swap(seg[seg_idx], line);\n      if (l_over !=\
    \ m_over)\n        seg_idx = (seg_idx << 1), right = mid;\n      else\n      \
    \  seg_idx = (seg_idx << 1) | 1, left = mid;\n    }\n  }\n\n  // \u5185\u90E8\u7528\
    \n  void inner_update(T a, T b, int seg_idx) {\n    int left, right;\n    int\
    \ upper_bit = 31 - __builtin_clz(seg_idx);\n    left = (_size >> upper_bit) *\
    \ (seg_idx - (1 << upper_bit));\n    right = left + (_size >> upper_bit);\n  \
    \  inner_update(a, b, left, right, seg_idx);\n  }\n\n  // y = ax + b\u306A\u308B\
    \u76F4\u7DDA\u3092\u8FFD\u52A0\n  void update(T a, T b) { inner_update(a, b, 0,\
    \ _size, 1); }\n\n  // \u9589\u533A\u9593x in [left , right]\u306B\u7DDA\u5206\
    y = ax + b\u3092\u8FFD\u52A0\u3059\u308B\u30AF\u30A8\u30EA\n  void update_segment(T\
    \ a, T b, T low, T high) {\n    int left = get_more_idx(low) + _size;\n    int\
    \ right = get_less_idx(high) + _size + 1;\n    for (; left < right; left >>= 1,\
    \ right >>= 1) {\n      if (left & 1) inner_update(a, b, left++);\n      if (right\
    \ & 1) inner_update(a, b, --right);\n    }\n  }\n\n  T inner_query(int x, int\
    \ segidx) {\n    T ret = seg[segidx].get(x);\n    while (segidx > 1) {\n     \
    \ segidx = segidx >> 1;\n      ret = min(ret, seg[segidx].get(x));\n    }\n  \
    \  return ret;\n  }\n\n  // x = xset[k]\u306A\u308B\u70B9\u306B\u304A\u3051\u308B\
    \u6700\u5C0F\u5024\u30AF\u30A8\u30EA\n  T query_idx(int k) {\n    const T x =\
    \ xset[k];\n    k += _size;\n    return inner_query(x, k);\n  }\n\n  // x\u306B\
    \u304A\u3051\u308B\u6700\u5C0F\u30AF\u30A8\u30EA\n  T query(T x) { return query_idx(get_more_idx(x));\
    \ }\n};\n"
  code: "#pragma once\n\n\n\ntemplate <typename T, T INF>\nstruct LiChaoTree {\n \
    \ struct Line {\n    T slope, intercept;\n    Line(T slope, T intercept) : slope(slope),\
    \ intercept(intercept) {}\n    inline T get(T x) const { return slope * x + intercept;\
    \ }\n    inline bool over(const Line &other, const T &x) const {\n      return\
    \ get(x) < other.get(x);\n    }\n  };\n\n  // remind \u30BB\u30B0\u6728\u306F\
    0-indexed\u306E\u5B9F\u88C5\n  vector<T> xset;\n  vector<Line> seg;\n  int _size;\n\
    \n  // \u5F15\u6570x\u306B\u306Fx\u5EA7\u6A19\u306E\u96C6\u5408\u3092\u5165\u308C\
    \u308B\n  LiChaoTree(const vector<T> &x) : xset(x) {\n    sort(xset.begin(), xset.end());\n\
    \    xset.erase(unique(xset.begin(), xset.end()), xset.end());\n    _size = 1;\n\
    \    while (_size < (int)xset.size()) _size <<= 1;\n    while ((int)xset.size()\
    \ < _size) xset.push_back(xset.back() + 1);\n    seg.assign(2 * _size, Line(0,\
    \ INF));\n  }\n\n  // \u4EE5\u4E0A xset[max]\u4EE5\u4E0B\u3067\u3042\u308B\u3053\
    \u3068\u3092\u4EEE\u5B9A\n  int get_more_idx(T k) {\n    return lower_bound(xset.begin(),\
    \ xset.end(), k) - xset.begin();\n  }\n  // \u4EE5\u4E0B xset[0]\u4EE5\u4E0A\u3067\
    \u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\n  int get_less_idx(T k) {\n    int\
    \ ret = upper_bound(xset.begin(), xset.end(), k) - xset.begin();\n    return max(0,\
    \ ret - 1);\n  }\n\n  // \u5185\u90E8\u7528\n  void inner_update(T a, T b, int\
    \ left, int right, int seg_idx) {\n    Line line(a, b);\n    while (1) {\n   \
    \   int mid = (left + right) >> 1;\n      bool l_over = line.over(seg[seg_idx],\
    \ xset[left]);\n      bool r_over = line.over(seg[seg_idx], xset[right - 1]);\n\
    \      if (l_over == r_over) {\n        if (l_over) swap(seg[seg_idx], line);\n\
    \        return;\n      }\n      bool m_over = line.over(seg[seg_idx], xset[mid]);\n\
    \      if (m_over) swap(seg[seg_idx], line);\n      if (l_over != m_over)\n  \
    \      seg_idx = (seg_idx << 1), right = mid;\n      else\n        seg_idx = (seg_idx\
    \ << 1) | 1, left = mid;\n    }\n  }\n\n  // \u5185\u90E8\u7528\n  void inner_update(T\
    \ a, T b, int seg_idx) {\n    int left, right;\n    int upper_bit = 31 - __builtin_clz(seg_idx);\n\
    \    left = (_size >> upper_bit) * (seg_idx - (1 << upper_bit));\n    right =\
    \ left + (_size >> upper_bit);\n    inner_update(a, b, left, right, seg_idx);\n\
    \  }\n\n  // y = ax + b\u306A\u308B\u76F4\u7DDA\u3092\u8FFD\u52A0\n  void update(T\
    \ a, T b) { inner_update(a, b, 0, _size, 1); }\n\n  // \u9589\u533A\u9593x in\
    \ [left , right]\u306B\u7DDA\u5206y = ax + b\u3092\u8FFD\u52A0\u3059\u308B\u30AF\
    \u30A8\u30EA\n  void update_segment(T a, T b, T low, T high) {\n    int left =\
    \ get_more_idx(low) + _size;\n    int right = get_less_idx(high) + _size + 1;\n\
    \    for (; left < right; left >>= 1, right >>= 1) {\n      if (left & 1) inner_update(a,\
    \ b, left++);\n      if (right & 1) inner_update(a, b, --right);\n    }\n  }\n\
    \n  T inner_query(int x, int segidx) {\n    T ret = seg[segidx].get(x);\n    while\
    \ (segidx > 1) {\n      segidx = segidx >> 1;\n      ret = min(ret, seg[segidx].get(x));\n\
    \    }\n    return ret;\n  }\n\n  // x = xset[k]\u306A\u308B\u70B9\u306B\u304A\
    \u3051\u308B\u6700\u5C0F\u5024\u30AF\u30A8\u30EA\n  T query_idx(int k) {\n   \
    \ const T x = xset[k];\n    k += _size;\n    return inner_query(x, k);\n  }\n\n\
    \  // x\u306B\u304A\u3051\u308B\u6700\u5C0F\u30AF\u30A8\u30EA\n  T query(T x)\
    \ { return query_idx(get_more_idx(x)); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/li-chao-tree.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-line-add-get-min.test.cpp
  - verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp
documentation_of: segment-tree/li-chao-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/li-chao-tree.hpp
- /library/segment-tree/li-chao-tree.hpp.html
title: segment-tree/li-chao-tree.hpp
---
