---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1460.test.cpp
    title: verify/verify-yuki/yuki-1460.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/semiring-linear-recursive.hpp\"\n\ntemplate <typename\
    \ rig>\nstruct LinearRecursive {\n  vector<rig> C;\n  int N;\n  LinearRecursive(const\
    \ vector<rig>& c) : C(c), N(c.size()) {}\n\n  rig kth_term(vector<rig> a, long\
    \ long k) {\n    assert(a.size() == C.size());\n    if (k < (int)a.size()) return\
    \ a[k];\n    auto coeff = get_coeff(k);\n    rig res = rig::id0();\n    for (int\
    \ i = 0; i < N; i++) res += a[i] * coeff[N - 1 - i];\n    return res;\n  }\n\n\
    \  vector<rig> get_coeff(long long k) {\n    if (k == 0) {\n      vector<rig>\
    \ b(N, rig::id0());\n      b.back() = rig::id1();\n      return b;\n    }\n  \
    \  auto half = get_coeff(k / 2);\n    doubling(half);\n    if (k & 1) increment(half);\n\
    \    return half;\n  }\n\n  void increment(vector<rig>& b) {\n    vector<rig>\
    \ v{begin(b) + 1, end(b)};\n    v.push_back(rig::id0());\n    for (int i = 0;\
    \ i < N; i++) v[i] += b[0] * C[i];\n    b.swap(v);\n  }\n\n  void doubling(vector<rig>&\
    \ b) {\n    vector<rig> v(N, rig::id0()), bb{b};\n    for (int i = 0; i < N; i++)\
    \ {\n      for (int j = 0; j < N; j++) {\n        v[j] += bb[j] * b[N - 1 - i];\n\
    \      }\n      increment(bb);\n    }\n    swap(b, v);\n  }\n};\n"
  code: "#pragma once\n\ntemplate <typename rig>\nstruct LinearRecursive {\n  vector<rig>\
    \ C;\n  int N;\n  LinearRecursive(const vector<rig>& c) : C(c), N(c.size()) {}\n\
    \n  rig kth_term(vector<rig> a, long long k) {\n    assert(a.size() == C.size());\n\
    \    if (k < (int)a.size()) return a[k];\n    auto coeff = get_coeff(k);\n   \
    \ rig res = rig::id0();\n    for (int i = 0; i < N; i++) res += a[i] * coeff[N\
    \ - 1 - i];\n    return res;\n  }\n\n  vector<rig> get_coeff(long long k) {\n\
    \    if (k == 0) {\n      vector<rig> b(N, rig::id0());\n      b.back() = rig::id1();\n\
    \      return b;\n    }\n    auto half = get_coeff(k / 2);\n    doubling(half);\n\
    \    if (k & 1) increment(half);\n    return half;\n  }\n\n  void increment(vector<rig>&\
    \ b) {\n    vector<rig> v{begin(b) + 1, end(b)};\n    v.push_back(rig::id0());\n\
    \    for (int i = 0; i < N; i++) v[i] += b[0] * C[i];\n    b.swap(v);\n  }\n\n\
    \  void doubling(vector<rig>& b) {\n    vector<rig> v(N, rig::id0()), bb{b};\n\
    \    for (int i = 0; i < N; i++) {\n      for (int j = 0; j < N; j++) {\n    \
    \    v[j] += bb[j] * b[N - 1 - i];\n      }\n      increment(bb);\n    }\n   \
    \ swap(b, v);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/semiring-linear-recursive.hpp
  requiredBy: []
  timestamp: '2021-07-11 22:59:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1460.test.cpp
documentation_of: math/semiring-linear-recursive.hpp
layout: document
redirect_from:
- /library/math/semiring-linear-recursive.hpp
- /library/math/semiring-linear-recursive.hpp.html
title: math/semiring-linear-recursive.hpp
---
