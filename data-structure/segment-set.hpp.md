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
    struct SegmentSet {\n  map<T, T> st;\n  SegmentSet() = default;\n\n  using const_iterator\
    \ = typename map<T, T>::const_iterator;\n  const_iterator begin() const { return\
    \ st.begin(); }\n  const_iterator end() const { return st.end(); }\n  const_iterator\
    \ find(T x) const {\n    auto it = st.upper_bound(x);\n    if (it == st.begin()\
    \ || (--it)->second <= x) return st.end();\n    return it;\n  }\n  const_iterator\
    \ lower_bound(T x) const {\n    auto it = st.lower_bound(x);\n    if (it == st.begin()\
    \ || prev(it)->second <= x) return it;\n    return prev(it);\n  }\n\n  void insert(T\
    \ l, T r) {\n    auto L = st.upper_bound(l), R = st.upper_bound(r);\n    if (L\
    \ != st.begin() && l <= prev(L)->second) --L;\n    if (L != R) {\n      l = min(l,\
    \ L->first);\n      r = max(r, prev(R)->second);\n      st.erase(L, R);\n    }\n\
    \    st[l] = r;\n  }\n\n  void erase(T l, T r) {\n    auto L = st.upper_bound(l),\
    \ R = st.upper_bound(r);\n    if (L != st.begin() && l <= prev(L)->second) --L;\n\
    \    if (L == R) return;\n    T nl = min(l, L->first), nr = max(r, prev(R)->second);\n\
    \    st.erase(L, R);\n    if (nl < l) st[nl] = l;\n    if (r < nr) st[r] = nr;\n\
    \  }\n\n  // x \u4EE5\u4E0A\u306E\u5024\u3092\u8FD4\u3059 \n  // \u5B58\u5728\u3057\
    \u306A\u3044\u5834\u5408\u306F numeric_limits<T>::max() \u3092\u8FD4\u3059\n \
    \ T next(T x) const {\n    auto it = this->lower_bound(x);\n    if (it == this->end())\
    \ return numeric_limits<T>::max();\n    return max<T>(x, it->first);\n  }\n\n\
    \  int size() { return st.size(); }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct SegmentSet {\n  map<T, T> st;\n\
    \  SegmentSet() = default;\n\n  using const_iterator = typename map<T, T>::const_iterator;\n\
    \  const_iterator begin() const { return st.begin(); }\n  const_iterator end()\
    \ const { return st.end(); }\n  const_iterator find(T x) const {\n    auto it\
    \ = st.upper_bound(x);\n    if (it == st.begin() || (--it)->second <= x) return\
    \ st.end();\n    return it;\n  }\n  const_iterator lower_bound(T x) const {\n\
    \    auto it = st.lower_bound(x);\n    if (it == st.begin() || prev(it)->second\
    \ <= x) return it;\n    return prev(it);\n  }\n\n  void insert(T l, T r) {\n \
    \   auto L = st.upper_bound(l), R = st.upper_bound(r);\n    if (L != st.begin()\
    \ && l <= prev(L)->second) --L;\n    if (L != R) {\n      l = min(l, L->first);\n\
    \      r = max(r, prev(R)->second);\n      st.erase(L, R);\n    }\n    st[l] =\
    \ r;\n  }\n\n  void erase(T l, T r) {\n    auto L = st.upper_bound(l), R = st.upper_bound(r);\n\
    \    if (L != st.begin() && l <= prev(L)->second) --L;\n    if (L == R) return;\n\
    \    T nl = min(l, L->first), nr = max(r, prev(R)->second);\n    st.erase(L, R);\n\
    \    if (nl < l) st[nl] = l;\n    if (r < nr) st[r] = nr;\n  }\n\n  // x \u4EE5\
    \u4E0A\u306E\u5024\u3092\u8FD4\u3059 \n  // \u5B58\u5728\u3057\u306A\u3044\u5834\
    \u5408\u306F numeric_limits<T>::max() \u3092\u8FD4\u3059\n  T next(T x) const\
    \ {\n    auto it = this->lower_bound(x);\n    if (it == this->end()) return numeric_limits<T>::max();\n\
    \    return max<T>(x, it->first);\n  }\n\n  int size() { return st.size(); }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-set.hpp
  requiredBy: []
  timestamp: '2021-09-05 13:40:06+09:00'
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
