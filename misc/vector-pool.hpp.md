---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/vector-pool.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <class T>\nstruct VectorPool {\n  using ptr_t = int;\n\
    \  vector<T> pool;\n  vector<ptr_t> st;\n  int idx;\n  int cap;\n\n  VectorPool(int\
    \ s = 4) : pool(s), st(), idx(0), cap(s) { assert(s > 0); }\n\n  inline T& operator[](ptr_t\
    \ i) { return pool[i]; }\n\n  void reallocate() {\n    assert(st.size() == 0);\n\
    \    cap *= 2;\n    pool.resize(cap);\n  }\n\n  ptr_t alloc() {\n    if (idx !=\
    \ cap) return idx++;\n    if (st.empty()) reallocate();\n    ptr_t ret = st.back();\n\
    \    st.pop_back();\n    return ret;\n  }\n\n  template <typename... Args>\n \
    \ ptr_t my_new(Args... args) {\n    ptr_t ret = alloc();\n    pool[ret] = T(args...);\n\
    \    return ret;\n  }\n\n  void free(ptr_t i) { st.push_back(i); }\n\n  void clear()\
    \ {\n    idx = 0;\n    st.clear();\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T>\nstruct VectorPool {\n  using ptr_t = int;\n  vector<T> pool;\n  vector<ptr_t>\
    \ st;\n  int idx;\n  int cap;\n\n  VectorPool(int s = 4) : pool(s), st(), idx(0),\
    \ cap(s) { assert(s > 0); }\n\n  inline T& operator[](ptr_t i) { return pool[i];\
    \ }\n\n  void reallocate() {\n    assert(st.size() == 0);\n    cap *= 2;\n   \
    \ pool.resize(cap);\n  }\n\n  ptr_t alloc() {\n    if (idx != cap) return idx++;\n\
    \    if (st.empty()) reallocate();\n    ptr_t ret = st.back();\n    st.pop_back();\n\
    \    return ret;\n  }\n\n  template <typename... Args>\n  ptr_t my_new(Args...\
    \ args) {\n    ptr_t ret = alloc();\n    pool[ret] = T(args...);\n    return ret;\n\
    \  }\n\n  void free(ptr_t i) { st.push_back(i); }\n\n  void clear() {\n    idx\
    \ = 0;\n    st.clear();\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/vector-pool.hpp
  requiredBy: []
  timestamp: '2020-10-11 13:18:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/vector-pool.hpp
layout: document
redirect_from:
- /library/misc/vector-pool.hpp
- /library/misc/vector-pool.hpp.html
title: misc/vector-pool.hpp
---
