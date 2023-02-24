---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/karatsuba.test.cpp
    title: verify/verify-unit-test/karatsuba.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-2-64-karatsuba.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-2-64-karatsuba.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ntt/karatsuba.hpp\"\n\nnamespace KaratsubaImpl {\n  \ntemplate\
    \ <typename T>\nvector<T> naive(const vector<T>& a, const vector<T>& b) {\n  if\
    \ (a.empty() and b.empty()) return {};\n  if (a.size() < b.size()) return naive(b,\
    \ a);\n  int s = a.size(), t = b.size();\n  vector<T> c(s + t - 1);\n  for (int\
    \ i = 0; i < s; i++) {\n    for (int j = 0; j < t; j++) c[i + j] += a[i] * b[j];\n\
    \  }\n  return c;\n}\n\ntemplate <typename T>\nvoid add(vector<T>& a, const vector<T>&\
    \ b) {\n  if (a.size() < b.size()) a.resize(b.size());\n  for (int i = 0; i <\
    \ (int)b.size(); i++) a[i] += b[i];\n}\ntemplate <typename T>\nvoid sub(vector<T>&\
    \ a, const vector<T>& b) {\n  if (a.size() < b.size()) a.resize(b.size());\n \
    \ for (int i = 0; i < (int)b.size(); i++) a[i] -= b[i];\n}\n\ntemplate <typename\
    \ T>\nvector<T> karatsuba(const vector<T>& a, const vector<T>& b) {\n  if (a.empty()\
    \ and b.empty()) return {};\n  if (a.size() < b.size()) return karatsuba(b, a);\n\
    \  if (a.size() < 32) return naive(a, b);\n  int d = a.size() / 2;\n  vector<T>\
    \ al{begin(a), begin(a) + d}, au{begin(a) + d, end(a)};\n  if ((int)b.size() <\
    \ d + 10) {\n    auto cl = karatsuba(al, b);\n    auto cu = karatsuba(au, b);\n\
    \    vector<T> c(a.size() + b.size() - 1);\n    for (int i = 0; i < (int)cl.size();\
    \ i++) c[i] = cl[i];\n    for (int i = 0; i < (int)cu.size(); i++) c[i + d] +=\
    \ cu[i];\n    return c;\n  }\n  vector<T> bl{begin(b), begin(b) + d}, bu{begin(b)\
    \ + d, end(b)};\n  vector<T> alu{al}, blu{bl};\n  add(alu, au), add(blu, bu);\n\
    \  auto cll = karatsuba(al, bl);\n  auto cuu = karatsuba(au, bu);\n  auto clu\
    \ = karatsuba(alu, blu);\n  sub(clu, cll), sub(clu, cuu);\n  vector<T> c(d);\n\
    \  copy(begin(clu), end(clu), back_inserter(c));\n  c.resize(a.size() + b.size()\
    \ - 1);\n  add(c, cll);\n  for (int i = 0; i < (int)cuu.size(); i++) c[i + 2 *\
    \ d] += cuu[i];\n  c.resize(a.size() + b.size() - 1);\n  return c;\n}\n\n}  //\
    \ namespace KaratsubaImpl\nusing KaratsubaImpl::karatsuba;\n"
  code: "#pragma once\n\nnamespace KaratsubaImpl {\n  \ntemplate <typename T>\nvector<T>\
    \ naive(const vector<T>& a, const vector<T>& b) {\n  if (a.empty() and b.empty())\
    \ return {};\n  if (a.size() < b.size()) return naive(b, a);\n  int s = a.size(),\
    \ t = b.size();\n  vector<T> c(s + t - 1);\n  for (int i = 0; i < s; i++) {\n\
    \    for (int j = 0; j < t; j++) c[i + j] += a[i] * b[j];\n  }\n  return c;\n\
    }\n\ntemplate <typename T>\nvoid add(vector<T>& a, const vector<T>& b) {\n  if\
    \ (a.size() < b.size()) a.resize(b.size());\n  for (int i = 0; i < (int)b.size();\
    \ i++) a[i] += b[i];\n}\ntemplate <typename T>\nvoid sub(vector<T>& a, const vector<T>&\
    \ b) {\n  if (a.size() < b.size()) a.resize(b.size());\n  for (int i = 0; i <\
    \ (int)b.size(); i++) a[i] -= b[i];\n}\n\ntemplate <typename T>\nvector<T> karatsuba(const\
    \ vector<T>& a, const vector<T>& b) {\n  if (a.empty() and b.empty()) return {};\n\
    \  if (a.size() < b.size()) return karatsuba(b, a);\n  if (a.size() < 32) return\
    \ naive(a, b);\n  int d = a.size() / 2;\n  vector<T> al{begin(a), begin(a) + d},\
    \ au{begin(a) + d, end(a)};\n  if ((int)b.size() < d + 10) {\n    auto cl = karatsuba(al,\
    \ b);\n    auto cu = karatsuba(au, b);\n    vector<T> c(a.size() + b.size() -\
    \ 1);\n    for (int i = 0; i < (int)cl.size(); i++) c[i] = cl[i];\n    for (int\
    \ i = 0; i < (int)cu.size(); i++) c[i + d] += cu[i];\n    return c;\n  }\n  vector<T>\
    \ bl{begin(b), begin(b) + d}, bu{begin(b) + d, end(b)};\n  vector<T> alu{al},\
    \ blu{bl};\n  add(alu, au), add(blu, bu);\n  auto cll = karatsuba(al, bl);\n \
    \ auto cuu = karatsuba(au, bu);\n  auto clu = karatsuba(alu, blu);\n  sub(clu,\
    \ cll), sub(clu, cuu);\n  vector<T> c(d);\n  copy(begin(clu), end(clu), back_inserter(c));\n\
    \  c.resize(a.size() + b.size() - 1);\n  add(c, cll);\n  for (int i = 0; i < (int)cuu.size();\
    \ i++) c[i + 2 * d] += cuu[i];\n  c.resize(a.size() + b.size() - 1);\n  return\
    \ c;\n}\n\n}  // namespace KaratsubaImpl\nusing KaratsubaImpl::karatsuba;\n"
  dependsOn: []
  isVerificationFile: false
  path: ntt/karatsuba.hpp
  requiredBy: []
  timestamp: '2021-12-21 23:55:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/karatsuba.test.cpp
  - verify/verify-yosupo-ntt/yosupo-convolution-2-64-karatsuba.test.cpp
documentation_of: ntt/karatsuba.hpp
layout: document
redirect_from:
- /library/ntt/karatsuba.hpp
- /library/ntt/karatsuba.hpp.html
title: ntt/karatsuba.hpp
---
