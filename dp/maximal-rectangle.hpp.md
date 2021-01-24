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
    links: []
  bundledCode: "#line 2 \"dp/maximal-rectangle.hpp\"\n\nlong long MaximalRectangle(vector<long\
    \ long> buf) {\n  int N = buf.size();\n  buf.push_back(0);\n  using P = pair<long\
    \ long, long long>;\n  stack<P> st;\n  long long mx = 0;\n  for (int i = 0; i\
    \ <= N; i++) {\n    P rect{buf[i], i};\n    if (st.empty() or st.top().first <\
    \ rect.first) {\n      st.push(rect);\n    } else {\n      int j = i;\n      while\
    \ (!st.empty() and st.top().first >= rect.first) {\n        P pre = st.top();\n\
    \        st.pop();\n        mx = max(mx, pre.first * (i - pre.second));\n    \
    \    j = pre.second;\n      }\n      rect.second = j;\n      st.push(rect);\n\
    \    }\n  }\n  return mx;\n}\n"
  code: "#pragma once\n\nlong long MaximalRectangle(vector<long long> buf) {\n  int\
    \ N = buf.size();\n  buf.push_back(0);\n  using P = pair<long long, long long>;\n\
    \  stack<P> st;\n  long long mx = 0;\n  for (int i = 0; i <= N; i++) {\n    P\
    \ rect{buf[i], i};\n    if (st.empty() or st.top().first < rect.first) {\n   \
    \   st.push(rect);\n    } else {\n      int j = i;\n      while (!st.empty() and\
    \ st.top().first >= rect.first) {\n        P pre = st.top();\n        st.pop();\n\
    \        mx = max(mx, pre.first * (i - pre.second));\n        j = pre.second;\n\
    \      }\n      rect.second = j;\n      st.push(rect);\n    }\n  }\n  return mx;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/maximal-rectangle.hpp
  requiredBy: []
  timestamp: '2021-01-24 13:07:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-dpl/aoj-dpl-3-c.test.cpp
documentation_of: dp/maximal-rectangle.hpp
layout: document
redirect_from:
- /library/dp/maximal-rectangle.hpp
- /library/dp/maximal-rectangle.hpp.html
title: dp/maximal-rectangle.hpp
---
