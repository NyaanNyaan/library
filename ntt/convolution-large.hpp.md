---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-large.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-large.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ntt/convolution-large.hpp\"\n\ntemplate <typename fps>\n\
    fps convolution_large(const fps &a, const fps &b) {\n  using mint = typename fps::value_type;\n\
    \  int len = 1LL << __builtin_ctz(mint::get_mod() - 1);\n  if (a.empty() || b.empty())\
    \ return fps{};\n  if ((int)a.size() + (int)b.size() - 1 <= len) return a * b;\n\
    \  vector<fps> as, bs;\n  for (int i = 0; i < (int)a.size(); i += len / 2) {\n\
    \    fps v{begin(a) + i, begin(a) + min<int>(i + len / 2, a.size())};\n    v.resize(len);\n\
    \    v.ntt();\n    as.push_back(v);\n  }\n  for (int i = 0; i < (int)b.size();\
    \ i += len / 2) {\n    fps v{begin(b) + i, begin(b) + min<int>(i + len / 2, b.size())};\n\
    \    v.resize(len);\n    v.ntt();\n    bs.push_back(v);\n  }\n  vector<fps> cs(as.size()\
    \ + bs.size() - 1, fps(len));\n  for (int i = 0; i < (int)as.size(); i++) {\n\
    \    for (int j = 0; j < (int)bs.size(); j++) {\n      for (int k = 0; k < len;\
    \ k++) cs[i + j][k] += as[i][k] * bs[j][k];\n    }\n  }\n  for (auto &v : cs)\
    \ v.intt();\n\n  fps c(a.size() + b.size() - 1);\n  for (int i = 0; i < (int)cs.size();\
    \ i++) {\n    int offset = len / 2 * i;\n    int je = min<int>(len, c.size() -\
    \ offset);\n    for (int j = 0; j < je; j++) c[j + offset] += cs[i][j];\n  }\n\
    \  return c;\n}\n"
  code: "#pragma once\n\ntemplate <typename fps>\nfps convolution_large(const fps\
    \ &a, const fps &b) {\n  using mint = typename fps::value_type;\n  int len = 1LL\
    \ << __builtin_ctz(mint::get_mod() - 1);\n  if (a.empty() || b.empty()) return\
    \ fps{};\n  if ((int)a.size() + (int)b.size() - 1 <= len) return a * b;\n  vector<fps>\
    \ as, bs;\n  for (int i = 0; i < (int)a.size(); i += len / 2) {\n    fps v{begin(a)\
    \ + i, begin(a) + min<int>(i + len / 2, a.size())};\n    v.resize(len);\n    v.ntt();\n\
    \    as.push_back(v);\n  }\n  for (int i = 0; i < (int)b.size(); i += len / 2)\
    \ {\n    fps v{begin(b) + i, begin(b) + min<int>(i + len / 2, b.size())};\n  \
    \  v.resize(len);\n    v.ntt();\n    bs.push_back(v);\n  }\n  vector<fps> cs(as.size()\
    \ + bs.size() - 1, fps(len));\n  for (int i = 0; i < (int)as.size(); i++) {\n\
    \    for (int j = 0; j < (int)bs.size(); j++) {\n      for (int k = 0; k < len;\
    \ k++) cs[i + j][k] += as[i][k] * bs[j][k];\n    }\n  }\n  for (auto &v : cs)\
    \ v.intt();\n\n  fps c(a.size() + b.size() - 1);\n  for (int i = 0; i < (int)cs.size();\
    \ i++) {\n    int offset = len / 2 * i;\n    int je = min<int>(len, c.size() -\
    \ offset);\n    for (int j = 0; j < je; j++) c[j + offset] += cs[i][j];\n  }\n\
    \  return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: ntt/convolution-large.hpp
  requiredBy: []
  timestamp: '2021-11-15 19:19:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-ntt/yosupo-convolution-large.test.cpp
documentation_of: ntt/convolution-large.hpp
layout: document
redirect_from:
- /library/ntt/convolution-large.hpp
- /library/ntt/convolution-large.hpp.html
title: ntt/convolution-large.hpp
---
