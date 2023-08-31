---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-longest-increasing-sequence.test.cpp
    title: verify/verify-yosupo-math/yosupo-longest-increasing-sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/longest-increasing-sequence.hpp\"\n\n#include <algorithm>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\n// LIS \u306E index\
    \ \u3092\u8FD4\u3059\ntemplate <typename T>\nvector<int> longest_increasing_sequence(const\
    \ vector<T>& a) {\n  int N = a.size();\n  vector<pair<T, int>> dp;\n  vector<int>\
    \ p(N, -1);\n\n  for (int i = 0; i < N; i++) {\n    auto it = lower_bound(begin(dp),\
    \ end(dp), make_pair(a[i], -i));\n    if (it != begin(dp)) p[i] = -prev(it)->second;\n\
    \    if (it == end(dp)) {\n      dp.emplace_back(a[i], -i);\n    } else {\n  \
    \    *it = make_pair(a[i], -i);\n    }\n  }\n\n  vector<int> res;\n  for (int\
    \ i = -dp.back().second; i != -1; i = p[i]) res.push_back(i);\n  reverse(begin(res),\
    \ end(res));\n  return res;\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\n// LIS \u306E index \u3092\u8FD4\u3059\ntemplate <typename\
    \ T>\nvector<int> longest_increasing_sequence(const vector<T>& a) {\n  int N =\
    \ a.size();\n  vector<pair<T, int>> dp;\n  vector<int> p(N, -1);\n\n  for (int\
    \ i = 0; i < N; i++) {\n    auto it = lower_bound(begin(dp), end(dp), make_pair(a[i],\
    \ -i));\n    if (it != begin(dp)) p[i] = -prev(it)->second;\n    if (it == end(dp))\
    \ {\n      dp.emplace_back(a[i], -i);\n    } else {\n      *it = make_pair(a[i],\
    \ -i);\n    }\n  }\n\n  vector<int> res;\n  for (int i = -dp.back().second; i\
    \ != -1; i = p[i]) res.push_back(i);\n  reverse(begin(res), end(res));\n  return\
    \ res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/longest-increasing-sequence.hpp
  requiredBy: []
  timestamp: '2023-08-31 20:44:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-longest-increasing-sequence.test.cpp
documentation_of: dp/longest-increasing-sequence.hpp
layout: document
redirect_from:
- /library/dp/longest-increasing-sequence.hpp
- /library/dp/longest-increasing-sequence.hpp.html
title: dp/longest-increasing-sequence.hpp
---
