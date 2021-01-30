---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse-table.hpp
    title: data-structure/sparse-table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-number-of-substrings.test.cpp
    title: verify/verify-yosupo-string/yosupo-number-of-substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-suffix-array.test.cpp
    title: verify/verify-yosupo-string/yosupo-suffix-array.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-zalgo-suffixarray.test.cpp
    title: verify/verify-yosupo-string/yosupo-zalgo-suffixarray.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc135/submissions/7574225
    - https://atcoder.jp/contests/abc141/submissions/7577295
    - https://judge.yosupo.jp/submission/240
    - https://judge.yosupo.jp/submission/241
    - https://onlinejudge.u-aizu.ac.jp/status/users/NyaanNyaan/submissions/1/ALDS1_14_D/judge/3874273/C++14
  bundledCode: "#line 2 \"string/suffix-array.hpp\"\n\n\n\n#line 2 \"data-structure/sparse-table.hpp\"\
    \n\ntemplate <typename T>\nstruct SparseTable {\n  vector<vector<T> > table;\n\
    \  vector<int> log_table;\n\n  inline T f(T a, T b) { return min(a, b); }\n\n\
    \  SparseTable(const vector<T> &v) {\n    int b = 0;\n    while ((1 << b) <= (int)v.size())\
    \ ++b;\n    table.assign(b, vector<T>(1 << b));\n    for (int i = 0; i < (int)v.size();\
    \ i++) {\n      table[0][i] = v[i];\n    }\n    for (int i = 1; i < b; i++) {\n\
    \      for (int j = 0; j + (1 << i) <= (1 << b); j++) {\n        table[i][j] =\
    \ f(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n    log_table.resize(v.size()\
    \ + 1);\n    for (int i = 2; i < (int)log_table.size(); i++) {\n      log_table[i]\
    \ = log_table[i >> 1] + 1;\n    }\n  }\n\n  // [l, r)\n  inline T query(int l,\
    \ int r) {\n    int b = log_table[r - l];\n    return f(table[b][l], table[b][r\
    \ - (1 << b)]);\n  }\n};\n#line 6 \"string/suffix-array.hpp\"\n\n// remind: SA\
    \ including empty string\n// verify https://judge.yosupo.jp/submission/240\nstruct\
    \ SuffixArray {\n  int _size;\n  vector<int> sa;\n  string &s;\n  SuffixArray(string\
    \ &str) : _size(str.size()), s(str) {\n    s.push_back(0);\n    sa.resize(s.size());\n\
    \    iota(begin(sa), end(sa), 0);\n    sort(begin(sa), end(sa),\n         [&](int\
    \ a, int b) { return s[a] == s[b] ? a > b : s[a] < s[b]; });\n    vector<int>\
    \ classes(s.size()), c(s.begin(), s.end()), cnt(s.size());\n    for (int len =\
    \ 1; len < (int)s.size(); len <<= 1) {\n      for (int i = 0; i < (int)s.size();\
    \ i++) {\n        if (i > 0 && c[sa[i - 1]] == c[sa[i]] &&\n            sa[i -\
    \ 1] + len < (int)s.size() &&\n            c[sa[i - 1] + len / 2] == c[sa[i] +\
    \ len / 2]) {\n          classes[sa[i]] = classes[sa[i - 1]];\n        } else\
    \ {\n          classes[sa[i]] = i;\n        }\n      }\n      iota(begin(cnt),\
    \ end(cnt), 0);\n      copy(begin(sa), end(sa), begin(c));\n      for (int i =\
    \ 0; i < (int)s.size(); i++) {\n        int s1 = c[i] - len;\n        if (s1 >=\
    \ 0) sa[cnt[classes[s1]]++] = s1;\n      }\n      classes.swap(c);\n    }\n  \
    \  s.pop_back();\n  }\n\n  void output() {\n    cout << \"SA\\tidx\\tstr\" <<\
    \ endl;\n    for (int i = 0; i < size(); i++) {\n      cout << i << \": \\t\"\
    \ << sa[i] << \" \\t\";\n      if (sa[i] != _size)\n        cout << s.substr(sa[i],\
    \ _size - sa[i]) << endl;\n      else\n        cout << \"$\" << endl;\n    }\n\
    \    cout << endl;\n  }\n\n  int size() const { return _size + 1; }\n  int operator[](int\
    \ k) const { return sa[k]; }\n};\n\nstruct LCPArray {\n  const SuffixArray &SA;\n\
    \  vector<int> LCP, rank;\n  LCPArray(const SuffixArray &sa) : SA(sa) {\n    LCP.resize(SA.size());\n\
    \    rank.resize(SA.size());\n    for (int i = 0; i < SA.size(); i++) {\n    \
    \  rank[SA[i]] = i;\n    }\n    LCP[0] = 0;\n\n    for (int i = 0, h = 0; i <\
    \ SA.size() - 1; i++) {\n      int j = SA[rank[i] - 1];\n      h ? h-- : h;\n\
    \      while ((i > j ? i : j) + h < SA.size() - 1 &&\n             SA.s[i + h]\
    \ == SA.s[j + h] && ++h)\n        ;\n      LCP[rank[i] - 1] = h;\n    }\n  }\n\
    \n  void output() {\n    cout << \"SA\\tidx\\tLCP\\tstr\" << endl;\n    for (int\
    \ i = 0; i < SA.size(); i++) {\n      cout << i << \"\\t\" << SA[i] << \" \\t\"\
    \ << LCP[i] << \"\\t\";\n      if (SA[i] == SA.size() - 1)\n        cout << \"\
    $\";\n      else\n        cout << SA.s.substr(SA[i], SA.size() - 1 - SA[i]);\n\
    \      cout << endl;\n    }\n  }\n};\n\n// verify\n// https://onlinejudge.u-aizu.ac.jp/status/users/NyaanNyaan/submissions/1/ALDS1_14_D/judge/3874273/C++14\n\
    // https://atcoder.jp/contests/abc135/submissions/7574225\n// https://judge.yosupo.jp/submission/241\n\
    // https://atcoder.jp/contests/abc141/submissions/7577295\nstruct StringSearch\
    \ {\n  string &s;\n  const SuffixArray &sa;\n  const LCPArray &lcp;\n  SparseTable<int>\
    \ sparse;\n  StringSearch(LCPArray &lcp)\n      : s(lcp.SA.s), sa(lcp.SA), lcp(lcp),\
    \ sparse(lcp.LCP) {}\n\n  pair<int, int> comp(const string &t, int len, int si,\
    \ int ti = 0) {\n    int sn = (int)s.size(), tn = (int)t.size();\n    si += len,\
    \ ti += len;\n    while (si < sn && ti < tn) {\n      if (s[si] != t[ti]) return\
    \ make_pair(s[si] < t[ti], ti);\n      si++, ti++;\n    }\n    return make_pair((si\
    \ >= sn && ti < tn), ti);\n  }\n\n  pair<int, int> find_range(int left, int med,\
    \ int right, int len) {\n    {\n      int ng = left - 1, ok = med;\n      while\
    \ (ng + 1 < ok) {\n        int cur = (ng + ok) / 2;\n        if (sparse.query(cur,\
    \ med) >= len)\n          ok = cur;\n        else\n          ng = cur;\n     \
    \ }\n      left = ok;\n    }\n    {\n      int ok = med, ng = right + 1;\n   \
    \   while (ok + 1 < ng) {\n        int cur = (ng + ok) / 2;\n        if (sparse.query(med,\
    \ cur) >= len)\n          ok = cur;\n        else\n          ng = cur;\n     \
    \ }\n      right = ok;\n    }\n    return make_pair(left, right);\n  }\n\n public:\n\
    \  // Longest Common Prefix between S[i , N) and S[j , N)\n  int ArbitaryLCP(int\
    \ i, int j) {\n    if (i == j) return (int)(s.size()) - i;\n    return sparse.query(min(lcp.rank[i],\
    \ lcp.rank[j]),\n                        max(lcp.rank[i], lcp.rank[j]));\n  }\n\
    \n  // String Search  O(|T| + log |S|)\n  // return : [l, r], l and r are indices\
    \ of Suffix Array\n  // if T doesn't exist, return (-1, -1)\n  pair<int, int>\
    \ find(string &t) {\n    int left = 1, right = sa.size() - 1, med = left;\n  \
    \  int leftlen = 0, rightlen = 0, tlen = t.size();\n    pair<int, int> ret;\n\
    \    while (left + 1 < right) {\n      med = (left + right) / 2;\n      int corres_len\
    \ = max(min(leftlen, sparse.query(left, med)),\n                           min(rightlen,\
    \ sparse.query(med, right)));\n      if (corres_len < max(leftlen, rightlen))\
    \ {\n        if (leftlen < rightlen)\n          left = med, leftlen = corres_len;\n\
    \        else\n          right = med, rightlen = corres_len;\n        continue;\n\
    \      }\n      ret = comp(t, corres_len, sa[med]);\n      if (ret.second == tlen)\
    \ return find_range(left, med, right, tlen);\n      if (ret.first == 0)\n    \
    \    right = med, rightlen = ret.second;\n      else\n        left = med, leftlen\
    \ = ret.second;\n    }\n    if (sa.size() <= 3) {\n      if (comp(t, 0, sa[left]).second\
    \ == tlen)\n        return find_range(left, left, right, tlen);\n      if (comp(t,\
    \ 0, sa[right]).second == tlen)\n        return find_range(left, right, right,\
    \ tlen);\n      return make_pair(-1, -1);\n    }\n    med = left + right - med;\n\
    \    ret = comp(t, min(leftlen, rightlen), sa[med]);\n    if (ret.second == tlen)\
    \ return find_range(left, med, right, tlen);\n    return make_pair(-1, -1);\n\
    \  }\n};\n// Usage:\n//  SuffixArray sa(S);\n//  LCPArray lcp(sa);\n//  StringSearch\
    \ search(lcp);\n"
  code: "#pragma once\n\n\n\n#include \"../data-structure/sparse-table.hpp\"\n\n//\
    \ remind: SA including empty string\n// verify https://judge.yosupo.jp/submission/240\n\
    struct SuffixArray {\n  int _size;\n  vector<int> sa;\n  string &s;\n  SuffixArray(string\
    \ &str) : _size(str.size()), s(str) {\n    s.push_back(0);\n    sa.resize(s.size());\n\
    \    iota(begin(sa), end(sa), 0);\n    sort(begin(sa), end(sa),\n         [&](int\
    \ a, int b) { return s[a] == s[b] ? a > b : s[a] < s[b]; });\n    vector<int>\
    \ classes(s.size()), c(s.begin(), s.end()), cnt(s.size());\n    for (int len =\
    \ 1; len < (int)s.size(); len <<= 1) {\n      for (int i = 0; i < (int)s.size();\
    \ i++) {\n        if (i > 0 && c[sa[i - 1]] == c[sa[i]] &&\n            sa[i -\
    \ 1] + len < (int)s.size() &&\n            c[sa[i - 1] + len / 2] == c[sa[i] +\
    \ len / 2]) {\n          classes[sa[i]] = classes[sa[i - 1]];\n        } else\
    \ {\n          classes[sa[i]] = i;\n        }\n      }\n      iota(begin(cnt),\
    \ end(cnt), 0);\n      copy(begin(sa), end(sa), begin(c));\n      for (int i =\
    \ 0; i < (int)s.size(); i++) {\n        int s1 = c[i] - len;\n        if (s1 >=\
    \ 0) sa[cnt[classes[s1]]++] = s1;\n      }\n      classes.swap(c);\n    }\n  \
    \  s.pop_back();\n  }\n\n  void output() {\n    cout << \"SA\\tidx\\tstr\" <<\
    \ endl;\n    for (int i = 0; i < size(); i++) {\n      cout << i << \": \\t\"\
    \ << sa[i] << \" \\t\";\n      if (sa[i] != _size)\n        cout << s.substr(sa[i],\
    \ _size - sa[i]) << endl;\n      else\n        cout << \"$\" << endl;\n    }\n\
    \    cout << endl;\n  }\n\n  int size() const { return _size + 1; }\n  int operator[](int\
    \ k) const { return sa[k]; }\n};\n\nstruct LCPArray {\n  const SuffixArray &SA;\n\
    \  vector<int> LCP, rank;\n  LCPArray(const SuffixArray &sa) : SA(sa) {\n    LCP.resize(SA.size());\n\
    \    rank.resize(SA.size());\n    for (int i = 0; i < SA.size(); i++) {\n    \
    \  rank[SA[i]] = i;\n    }\n    LCP[0] = 0;\n\n    for (int i = 0, h = 0; i <\
    \ SA.size() - 1; i++) {\n      int j = SA[rank[i] - 1];\n      h ? h-- : h;\n\
    \      while ((i > j ? i : j) + h < SA.size() - 1 &&\n             SA.s[i + h]\
    \ == SA.s[j + h] && ++h)\n        ;\n      LCP[rank[i] - 1] = h;\n    }\n  }\n\
    \n  void output() {\n    cout << \"SA\\tidx\\tLCP\\tstr\" << endl;\n    for (int\
    \ i = 0; i < SA.size(); i++) {\n      cout << i << \"\\t\" << SA[i] << \" \\t\"\
    \ << LCP[i] << \"\\t\";\n      if (SA[i] == SA.size() - 1)\n        cout << \"\
    $\";\n      else\n        cout << SA.s.substr(SA[i], SA.size() - 1 - SA[i]);\n\
    \      cout << endl;\n    }\n  }\n};\n\n// verify\n// https://onlinejudge.u-aizu.ac.jp/status/users/NyaanNyaan/submissions/1/ALDS1_14_D/judge/3874273/C++14\n\
    // https://atcoder.jp/contests/abc135/submissions/7574225\n// https://judge.yosupo.jp/submission/241\n\
    // https://atcoder.jp/contests/abc141/submissions/7577295\nstruct StringSearch\
    \ {\n  string &s;\n  const SuffixArray &sa;\n  const LCPArray &lcp;\n  SparseTable<int>\
    \ sparse;\n  StringSearch(LCPArray &lcp)\n      : s(lcp.SA.s), sa(lcp.SA), lcp(lcp),\
    \ sparse(lcp.LCP) {}\n\n  pair<int, int> comp(const string &t, int len, int si,\
    \ int ti = 0) {\n    int sn = (int)s.size(), tn = (int)t.size();\n    si += len,\
    \ ti += len;\n    while (si < sn && ti < tn) {\n      if (s[si] != t[ti]) return\
    \ make_pair(s[si] < t[ti], ti);\n      si++, ti++;\n    }\n    return make_pair((si\
    \ >= sn && ti < tn), ti);\n  }\n\n  pair<int, int> find_range(int left, int med,\
    \ int right, int len) {\n    {\n      int ng = left - 1, ok = med;\n      while\
    \ (ng + 1 < ok) {\n        int cur = (ng + ok) / 2;\n        if (sparse.query(cur,\
    \ med) >= len)\n          ok = cur;\n        else\n          ng = cur;\n     \
    \ }\n      left = ok;\n    }\n    {\n      int ok = med, ng = right + 1;\n   \
    \   while (ok + 1 < ng) {\n        int cur = (ng + ok) / 2;\n        if (sparse.query(med,\
    \ cur) >= len)\n          ok = cur;\n        else\n          ng = cur;\n     \
    \ }\n      right = ok;\n    }\n    return make_pair(left, right);\n  }\n\n public:\n\
    \  // Longest Common Prefix between S[i , N) and S[j , N)\n  int ArbitaryLCP(int\
    \ i, int j) {\n    if (i == j) return (int)(s.size()) - i;\n    return sparse.query(min(lcp.rank[i],\
    \ lcp.rank[j]),\n                        max(lcp.rank[i], lcp.rank[j]));\n  }\n\
    \n  // String Search  O(|T| + log |S|)\n  // return : [l, r], l and r are indices\
    \ of Suffix Array\n  // if T doesn't exist, return (-1, -1)\n  pair<int, int>\
    \ find(string &t) {\n    int left = 1, right = sa.size() - 1, med = left;\n  \
    \  int leftlen = 0, rightlen = 0, tlen = t.size();\n    pair<int, int> ret;\n\
    \    while (left + 1 < right) {\n      med = (left + right) / 2;\n      int corres_len\
    \ = max(min(leftlen, sparse.query(left, med)),\n                           min(rightlen,\
    \ sparse.query(med, right)));\n      if (corres_len < max(leftlen, rightlen))\
    \ {\n        if (leftlen < rightlen)\n          left = med, leftlen = corres_len;\n\
    \        else\n          right = med, rightlen = corres_len;\n        continue;\n\
    \      }\n      ret = comp(t, corres_len, sa[med]);\n      if (ret.second == tlen)\
    \ return find_range(left, med, right, tlen);\n      if (ret.first == 0)\n    \
    \    right = med, rightlen = ret.second;\n      else\n        left = med, leftlen\
    \ = ret.second;\n    }\n    if (sa.size() <= 3) {\n      if (comp(t, 0, sa[left]).second\
    \ == tlen)\n        return find_range(left, left, right, tlen);\n      if (comp(t,\
    \ 0, sa[right]).second == tlen)\n        return find_range(left, right, right,\
    \ tlen);\n      return make_pair(-1, -1);\n    }\n    med = left + right - med;\n\
    \    ret = comp(t, min(leftlen, rightlen), sa[med]);\n    if (ret.second == tlen)\
    \ return find_range(left, med, right, tlen);\n    return make_pair(-1, -1);\n\
    \  }\n};\n// Usage:\n//  SuffixArray sa(S);\n//  LCPArray lcp(sa);\n//  StringSearch\
    \ search(lcp);"
  dependsOn:
  - data-structure/sparse-table.hpp
  isVerificationFile: false
  path: string/suffix-array.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-string/yosupo-zalgo-suffixarray.test.cpp
  - verify/verify-yosupo-string/yosupo-number-of-substrings.test.cpp
  - verify/verify-yosupo-string/yosupo-suffix-array.test.cpp
documentation_of: string/suffix-array.hpp
layout: document
redirect_from:
- /library/string/suffix-array.hpp
- /library/string/suffix-array.hpp.html
title: string/suffix-array.hpp
---
