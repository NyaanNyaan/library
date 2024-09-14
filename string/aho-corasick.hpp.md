---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/trie.hpp
    title: string/trie.hpp
  _extendedRequiredBy: []
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
  bundledCode: "#line 2 \"string/aho-corasick.hpp\"\n\n#line 2 \"string/trie.hpp\"\
    \n\ntemplate <size_t X = 26, char margin = 'a'>\nstruct Trie {\n  struct Node\
    \ {\n    array<int, X> nxt;\n    vector<int> idxs;\n    int idx;\n    char key;\n\
    \    Node(char c) : idx(-1), key(c) { fill(nxt.begin(), nxt.end(), -1); }\n  };\n\
    \n  vector<Node> st;\n\n  Trie(char c = '$') { st.emplace_back(c); }\n\n  inline\
    \ int &next(int i, int j) { return st[i].nxt[j]; }\n\n  void add(const string\
    \ &s, int x) {\n    int pos = 0;\n    for (int i = 0; i < (int)s.size(); i++)\
    \ {\n      int k = s[i] - margin;\n      if (~next(pos, k)) {\n        pos = next(pos,\
    \ k);\n        continue;\n      }\n      int npos = st.size();\n      next(pos,\
    \ k) = npos;\n      st.emplace_back(s[i]);\n      pos = npos;\n    }\n    st[pos].idx\
    \ = x;\n    st[pos].idxs.emplace_back(x);\n  }\n\n  int find(const string &s)\
    \ {\n    int pos = 0;\n    for (int i = 0; i < (int)s.size(); i++) {\n      int\
    \ k = s[i] - margin;\n      if (next(pos, k) < 0) return -1;\n      pos = next(pos,\
    \ k);\n    }\n    return pos;\n  }\n\n  int move(int pos, char c) {\n    assert(pos\
    \ < (int)st.size());\n    return pos < 0 ? -1 : next(pos, c - margin);\n  }\n\n\
    \  int size() const { return st.size(); }\n\n  int idx(int pos) { return pos <\
    \ 0 ? -1 : st[pos].idx; }\n\n  vector<int> idxs(int pos) { return pos < 0 ? vector<int>()\
    \ : st[pos].idxs; }\n};\n#line 4 \"string/aho-corasick.hpp\"\n\ntemplate <size_t\
    \ X = 26, char margin = 'a', bool heavy = false>\nstruct AhoCorasick : Trie<X\
    \ + 1, margin> {\n  using TRIE = Trie<X + 1, margin>;\n  using TRIE::next;\n \
    \ using TRIE::st;\n  using TRIE::TRIE;\n  vector<int> cnt;\n\n  void build() {\n\
    \    int n = st.size();\n    cnt.resize(n);\n    for (int i = 0; i < n; i++) {\n\
    \      if (heavy) sort(st[i].idxs.begin(), st[i].idxs.end());\n      cnt[i] =\
    \ st[i].idxs.size();\n    }\n\n    queue<int> que;\n    for (int i = 0; i < (int)X;\
    \ i++) {\n      if (~next(0, i)) {\n        next(next(0, i), X) = 0;\n       \
    \ que.emplace(next(0, i));\n      } else {\n        next(0, i) = 0;\n      }\n\
    \    }\n\n    while (!que.empty()) {\n      auto &x = st[que.front()];\n     \
    \ int fail = x.nxt[X];\n\n      cnt[que.front()] += cnt[fail];\n      que.pop();\n\
    \n      for (int i = 0; i < (int)X; i++) {\n        int &nx = x.nxt[i];\n    \
    \    if (nx < 0) {\n          nx = next(fail, i);\n          continue;\n     \
    \   }\n        que.emplace(nx);\n        next(nx, X) = next(fail, i);\n      \
    \  if (heavy) {\n          auto &idx = st[nx].idxs;\n          auto &idy = st[next(fail,\
    \ i)].idxs;\n          vector<int> idz;\n          set_union(idx.begin(), idx.end(),\
    \ idy.begin(), idy.end(),\n                    back_inserter(idz));\n        \
    \  idx = idz;\n        }\n      }\n    }\n  }\n\n  // heavy\n  // true  : \u5404\
    \u30D1\u30BF\u30FC\u30F3\u6587\u5B57\u5217\u306B\u5BFE\u3057\u3066\u30DE\u30C3\
    \u30C1\u3057\u305F\u56DE\u6570\u3092\u8A08\u7B97\n  // false : \u5168\u3066\u306E\
    \u30D1\u30BF\u30FC\u30F3\u6587\u5B57\u5217\u306B\u30DE\u30C3\u30C1\u3057\u305F\
    \u56DE\u6570\u306E\u7DCF\u548C\n  conditional_t<heavy, unordered_map<int, long\
    \ long>, long long> match(\n      string s) {\n    unordered_map<int, int> pos_cnt;\n\
    \    int pos = 0;\n    for (auto &c : s) {\n      pos = next(pos, c - margin);\n\
    \      pos_cnt[pos]++;\n    }\n    conditional_t<heavy, unordered_map<int, long\
    \ long>, long long> res{};\n    for (auto &[key, val] : pos_cnt) {\n      if constexpr\
    \ (heavy) {\n        for (auto &x : st[key].idxs) res[x] += val;\n      } else\
    \ {\n        res += 1LL * cnt[key] * val;\n      }\n    }\n    return res;\n \
    \ }\n\n  int count(int pos) { return cnt[pos]; }\n};\n"
  code: "#pragma once\n\n#include \"trie.hpp\"\n\ntemplate <size_t X = 26, char margin\
    \ = 'a', bool heavy = false>\nstruct AhoCorasick : Trie<X + 1, margin> {\n  using\
    \ TRIE = Trie<X + 1, margin>;\n  using TRIE::next;\n  using TRIE::st;\n  using\
    \ TRIE::TRIE;\n  vector<int> cnt;\n\n  void build() {\n    int n = st.size();\n\
    \    cnt.resize(n);\n    for (int i = 0; i < n; i++) {\n      if (heavy) sort(st[i].idxs.begin(),\
    \ st[i].idxs.end());\n      cnt[i] = st[i].idxs.size();\n    }\n\n    queue<int>\
    \ que;\n    for (int i = 0; i < (int)X; i++) {\n      if (~next(0, i)) {\n   \
    \     next(next(0, i), X) = 0;\n        que.emplace(next(0, i));\n      } else\
    \ {\n        next(0, i) = 0;\n      }\n    }\n\n    while (!que.empty()) {\n \
    \     auto &x = st[que.front()];\n      int fail = x.nxt[X];\n\n      cnt[que.front()]\
    \ += cnt[fail];\n      que.pop();\n\n      for (int i = 0; i < (int)X; i++) {\n\
    \        int &nx = x.nxt[i];\n        if (nx < 0) {\n          nx = next(fail,\
    \ i);\n          continue;\n        }\n        que.emplace(nx);\n        next(nx,\
    \ X) = next(fail, i);\n        if (heavy) {\n          auto &idx = st[nx].idxs;\n\
    \          auto &idy = st[next(fail, i)].idxs;\n          vector<int> idz;\n \
    \         set_union(idx.begin(), idx.end(), idy.begin(), idy.end(),\n        \
    \            back_inserter(idz));\n          idx = idz;\n        }\n      }\n\
    \    }\n  }\n\n  // heavy\n  // true  : \u5404\u30D1\u30BF\u30FC\u30F3\u6587\u5B57\
    \u5217\u306B\u5BFE\u3057\u3066\u30DE\u30C3\u30C1\u3057\u305F\u56DE\u6570\u3092\
    \u8A08\u7B97\n  // false : \u5168\u3066\u306E\u30D1\u30BF\u30FC\u30F3\u6587\u5B57\
    \u5217\u306B\u30DE\u30C3\u30C1\u3057\u305F\u56DE\u6570\u306E\u7DCF\u548C\n  conditional_t<heavy,\
    \ unordered_map<int, long long>, long long> match(\n      string s) {\n    unordered_map<int,\
    \ int> pos_cnt;\n    int pos = 0;\n    for (auto &c : s) {\n      pos = next(pos,\
    \ c - margin);\n      pos_cnt[pos]++;\n    }\n    conditional_t<heavy, unordered_map<int,\
    \ long long>, long long> res{};\n    for (auto &[key, val] : pos_cnt) {\n    \
    \  if constexpr (heavy) {\n        for (auto &x : st[key].idxs) res[x] += val;\n\
    \      } else {\n        res += 1LL * cnt[key] * val;\n      }\n    }\n    return\
    \ res;\n  }\n\n  int count(int pos) { return cnt[pos]; }\n};\n"
  dependsOn:
  - string/trie.hpp
  isVerificationFile: false
  path: string/aho-corasick.hpp
  requiredBy: []
  timestamp: '2024-08-07 23:00:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-0430-2.test.cpp
  - verify/verify-yuki/yuki-0430.test.cpp
  - verify/verify-yuki/yuki-1269.test.cpp
documentation_of: string/aho-corasick.hpp
layout: document
redirect_from:
- /library/string/aho-corasick.hpp
- /library/string/aho-corasick.hpp.html
title: string/aho-corasick.hpp
---
