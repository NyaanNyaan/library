---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/aho-corasick.hpp
    title: string/aho-corasick.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0430-2.test.cpp
    title: verify/verify-yuki/yuki-0430-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0430.test.cpp
    title: verify/verify-yuki/yuki-0430.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1269.test.cpp
    title: verify/verify-yuki/yuki-1269.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/trie.hpp\"\n\ntemplate <size_t X = 26, char margin\
    \ = 'a'>\nstruct Trie {\n  struct Node {\n    array<int, X> nxt;\n    vector<int>\
    \ idxs;\n    int idx;\n    char key;\n    Node(char c) : idx(-1), key(c) { fill(nxt.begin(),\
    \ nxt.end(), -1); }\n  };\n\n  vector<Node> st;\n\n  Trie(char c = '$') { st.emplace_back(c);\
    \ }\n\n  inline int &next(int i, int j) { return st[i].nxt[j]; }\n\n  void add(const\
    \ string &s, int x) {\n    int pos = 0;\n    for (int i = 0; i < (int)s.size();\
    \ i++) {\n      int k = s[i] - margin;\n      if (~next(pos, k)) {\n        pos\
    \ = next(pos, k);\n        continue;\n      }\n      int npos = st.size();\n \
    \     next(pos, k) = npos;\n      st.emplace_back(s[i]);\n      pos = npos;\n\
    \    }\n    st[pos].idx = x;\n    st[pos].idxs.emplace_back(x);\n  }\n\n  int\
    \ find(const string &s) {\n    int pos = 0;\n    for (int i = 0; i < (int)s.size();\
    \ i++) {\n      int k = s[i] - margin;\n      if (next(pos, k) < 0) return -1;\n\
    \      pos = next(pos, k);\n    }\n    return pos;\n  }\n\n  int move(int pos,\
    \ char c) {\n    assert(pos < (int)st.size());\n    return pos < 0 ? -1 : next(pos,\
    \ c - margin);\n  }\n\n  int size() const { return st.size(); }\n\n  int idx(int\
    \ pos) { return pos < 0 ? -1 : st[pos].idx; }\n\n  vector<int> idxs(int pos) {\
    \ return pos < 0 ? vector<int>() : st[pos].idxs; }\n};\n"
  code: "#pragma once\n\ntemplate <size_t X = 26, char margin = 'a'>\nstruct Trie\
    \ {\n  struct Node {\n    array<int, X> nxt;\n    vector<int> idxs;\n    int idx;\n\
    \    char key;\n    Node(char c) : idx(-1), key(c) { fill(nxt.begin(), nxt.end(),\
    \ -1); }\n  };\n\n  vector<Node> st;\n\n  Trie(char c = '$') { st.emplace_back(c);\
    \ }\n\n  inline int &next(int i, int j) { return st[i].nxt[j]; }\n\n  void add(const\
    \ string &s, int x) {\n    int pos = 0;\n    for (int i = 0; i < (int)s.size();\
    \ i++) {\n      int k = s[i] - margin;\n      if (~next(pos, k)) {\n        pos\
    \ = next(pos, k);\n        continue;\n      }\n      int npos = st.size();\n \
    \     next(pos, k) = npos;\n      st.emplace_back(s[i]);\n      pos = npos;\n\
    \    }\n    st[pos].idx = x;\n    st[pos].idxs.emplace_back(x);\n  }\n\n  int\
    \ find(const string &s) {\n    int pos = 0;\n    for (int i = 0; i < (int)s.size();\
    \ i++) {\n      int k = s[i] - margin;\n      if (next(pos, k) < 0) return -1;\n\
    \      pos = next(pos, k);\n    }\n    return pos;\n  }\n\n  int move(int pos,\
    \ char c) {\n    assert(pos < (int)st.size());\n    return pos < 0 ? -1 : next(pos,\
    \ c - margin);\n  }\n\n  int size() const { return st.size(); }\n\n  int idx(int\
    \ pos) { return pos < 0 ? -1 : st[pos].idx; }\n\n  vector<int> idxs(int pos) {\
    \ return pos < 0 ? vector<int>() : st[pos].idxs; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy:
  - string/aho-corasick.hpp
  timestamp: '2020-12-10 19:54:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-0430.test.cpp
  - verify/verify-yuki/yuki-0430-2.test.cpp
  - verify/verify-yuki/yuki-1269.test.cpp
documentation_of: string/trie.hpp
layout: document
redirect_from:
- /library/string/trie.hpp
- /library/string/trie.hpp.html
title: string/trie.hpp
---
