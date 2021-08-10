---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/segment-set.test.cpp
    title: verify/verify-unit-test/segment-set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segment-set.hpp\"\n\ntemplate <typename T>\n\
    struct SegmentSet {\n  map<T, T> st;\n  SegmentSet() = default;\n\n  using iterator\
    \ = typename map<T, T>::iterator;\n  using const_iterator = typename map<T, T>::const_iterator;\n\
    \  const_iterator begin() const { return st.begin(); }\n  const_iterator end()\
    \ const { return st.end(); }\n  const_iterator find(T x) const {\n    auto it\
    \ = st.upper_bound(x);\n    if (it == st.begin() || (--it)->second <= x) return\
    \ st.end();\n    return it;\n  }\n\n  void insert(T l, T r) {\n    auto L = st.upper_bound(l),\
    \ R = st.upper_bound(r);\n    if (L != st.begin() && l <= prev(L)->second) --L;\n\
    \    if (L != R) {\n      l = min(l, L->first);\n      r = max(r, prev(R)->second);\n\
    \      st.erase(L, R);\n    }\n    st[l] = r;\n  }\n\n  void erase(T l, T r) {\n\
    \    auto L = st.upper_bound(l), R = st.upper_bound(r);\n    if (L != st.begin()\
    \ && l <= prev(L)->second) --L;\n    if (L == R) return;\n    T nl = min(l, L->first),\
    \ nr = max(r, prev(R)->second);\n    st.erase(L, R);\n    if (nl < l) st[nl] =\
    \ l;\n    if (r < nr) st[r] = nr;\n  }\n\n  int size() { return st.size(); }\n\
    };\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct SegmentSet {\n  map<T, T> st;\n\
    \  SegmentSet() = default;\n\n  using iterator = typename map<T, T>::iterator;\n\
    \  using const_iterator = typename map<T, T>::const_iterator;\n  const_iterator\
    \ begin() const { return st.begin(); }\n  const_iterator end() const { return\
    \ st.end(); }\n  const_iterator find(T x) const {\n    auto it = st.upper_bound(x);\n\
    \    if (it == st.begin() || (--it)->second <= x) return st.end();\n    return\
    \ it;\n  }\n\n  void insert(T l, T r) {\n    auto L = st.upper_bound(l), R = st.upper_bound(r);\n\
    \    if (L != st.begin() && l <= prev(L)->second) --L;\n    if (L != R) {\n  \
    \    l = min(l, L->first);\n      r = max(r, prev(R)->second);\n      st.erase(L,\
    \ R);\n    }\n    st[l] = r;\n  }\n\n  void erase(T l, T r) {\n    auto L = st.upper_bound(l),\
    \ R = st.upper_bound(r);\n    if (L != st.begin() && l <= prev(L)->second) --L;\n\
    \    if (L == R) return;\n    T nl = min(l, L->first), nr = max(r, prev(R)->second);\n\
    \    st.erase(L, R);\n    if (nl < l) st[nl] = l;\n    if (r < nr) st[r] = nr;\n\
    \  }\n\n  int size() { return st.size(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-set.hpp
  requiredBy: []
  timestamp: '2021-08-10 23:14:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/segment-set.test.cpp
documentation_of: data-structure/segment-set.hpp
layout: document
redirect_from:
- /library/data-structure/segment-set.hpp
- /library/data-structure/segment-set.hpp.html
title: data-structure/segment-set.hpp
---
