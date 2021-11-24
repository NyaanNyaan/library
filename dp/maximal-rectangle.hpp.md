---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dpl/aoj-dpl-3-c.test.cpp
    title: verify/verify-aoj-dpl/aoj-dpl-3-c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/dp/maximal-rectangle.md
    document_title: "\u6700\u5927\u9577\u65B9\u5F62"
    links: []
  bundledCode: "#line 2 \"dp/maximal-rectangle.hpp\"\n\nlong long MaximalRectangle(vector<long\
    \ long> buf) {\n  int N = buf.size();\n  buf.push_back(0);\n  using P = pair<long\
    \ long, long long>;\n  stack<P> st;\n  long long mx = 0;\n  for (int i = 0; i\
    \ <= N; i++) {\n    P rect{buf[i], i};\n    if (st.empty() or st.top().first <\
    \ rect.first) {\n      st.push(rect);\n    } else {\n      int j = i;\n      while\
    \ (!st.empty() and st.top().first >= rect.first) {\n        P pre = st.top();\n\
    \        st.pop();\n        mx = max(mx, pre.first * (i - pre.second));\n    \
    \    j = pre.second;\n      }\n      rect.second = j;\n      st.push(rect);\n\
    \    }\n  }\n  return mx;\n}\n\n/**\n * @brief \u6700\u5927\u9577\u65B9\u5F62\n\
    \ * @docs docs/dp/maximal-rectangle.md\n */\n"
  code: "#pragma once\n\nlong long MaximalRectangle(vector<long long> buf) {\n  int\
    \ N = buf.size();\n  buf.push_back(0);\n  using P = pair<long long, long long>;\n\
    \  stack<P> st;\n  long long mx = 0;\n  for (int i = 0; i <= N; i++) {\n    P\
    \ rect{buf[i], i};\n    if (st.empty() or st.top().first < rect.first) {\n   \
    \   st.push(rect);\n    } else {\n      int j = i;\n      while (!st.empty() and\
    \ st.top().first >= rect.first) {\n        P pre = st.top();\n        st.pop();\n\
    \        mx = max(mx, pre.first * (i - pre.second));\n        j = pre.second;\n\
    \      }\n      rect.second = j;\n      st.push(rect);\n    }\n  }\n  return mx;\n\
    }\n\n/**\n * @brief \u6700\u5927\u9577\u65B9\u5F62\n * @docs docs/dp/maximal-rectangle.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/maximal-rectangle.hpp
  requiredBy: []
  timestamp: '2021-11-17 23:54:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-dpl/aoj-dpl-3-c.test.cpp
documentation_of: dp/maximal-rectangle.hpp
layout: document
redirect_from:
- /library/dp/maximal-rectangle.hpp
- /library/dp/maximal-rectangle.hpp.html
title: "\u6700\u5927\u9577\u65B9\u5F62"
---
## 最大長方形

### 概要

短く言うと、ヒストグラム中の長方形の最大面積を求める。

非負整数列$A$を入力とする。非負整数$l,r,h$ $(l \leq r \lt N)$が$h \leq A_i$ $(l \leq i \leq r)$ を満たすとき、$h(r-l+1)$の最大値を求める。

### 使い方

- `MaximalRectangle(buf)`: `buf`で非負整数列$A$を与える。求める最大値を返す。計算量$\mathrm{O}(\vert A \vert)$
