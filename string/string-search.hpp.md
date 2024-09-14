---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse-table.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/string-search.test.cpp
    title: verify/verify-unit-test/string-search.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2231.test.cpp
    title: verify/verify-yuki/yuki-2231.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/string-search.hpp\"\n\n#line 1 \"atcoder/string.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n#include\
    \ <string>\n#include <vector>\n\nnamespace atcoder {\n\nnamespace internal {\n\
    \nstd::vector<int> sa_naive(const std::vector<int>& s) {\n    int n = int(s.size());\n\
    \    std::vector<int> sa(n);\n    std::iota(sa.begin(), sa.end(), 0);\n    std::sort(sa.begin(),\
    \ sa.end(), [&](int l, int r) {\n        if (l == r) return false;\n        while\
    \ (l < n && r < n) {\n            if (s[l] != s[r]) return s[l] < s[r];\n    \
    \        l++;\n            r++;\n        }\n        return l == n;\n    });\n\
    \    return sa;\n}\n\nstd::vector<int> sa_doubling(const std::vector<int>& s)\
    \ {\n    int n = int(s.size());\n    std::vector<int> sa(n), rnk = s, tmp(n);\n\
    \    std::iota(sa.begin(), sa.end(), 0);\n    for (int k = 1; k < n; k *= 2) {\n\
    \        auto cmp = [&](int x, int y) {\n            if (rnk[x] != rnk[y]) return\
    \ rnk[x] < rnk[y];\n            int rx = x + k < n ? rnk[x + k] : -1;\n      \
    \      int ry = y + k < n ? rnk[y + k] : -1;\n            return rx < ry;\n  \
    \      };\n        std::sort(sa.begin(), sa.end(), cmp);\n        tmp[sa[0]] =\
    \ 0;\n        for (int i = 1; i < n; i++) {\n            tmp[sa[i]] = tmp[sa[i\
    \ - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);\n        }\n        std::swap(tmp,\
    \ rnk);\n    }\n    return sa;\n}\n\n// SA-IS, linear-time suffix array construction\n\
    // Reference:\n// G. Nong, S. Zhang, and W. H. Chan,\n// Two Efficient Algorithms\
    \ for Linear Time Suffix Array Construction\ntemplate <int THRESHOLD_NAIVE = 10,\
    \ int THRESHOLD_DOUBLING = 40>\nstd::vector<int> sa_is(const std::vector<int>&\
    \ s, int upper) {\n    int n = int(s.size());\n    if (n == 0) return {};\n  \
    \  if (n == 1) return {0};\n    if (n == 2) {\n        if (s[0] < s[1]) {\n  \
    \          return {0, 1};\n        } else {\n            return {1, 0};\n    \
    \    }\n    }\n    if (n < THRESHOLD_NAIVE) {\n        return sa_naive(s);\n \
    \   }\n    if (n < THRESHOLD_DOUBLING) {\n        return sa_doubling(s);\n   \
    \ }\n\n    std::vector<int> sa(n);\n    std::vector<bool> ls(n);\n    for (int\
    \ i = n - 2; i >= 0; i--) {\n        ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] :\
    \ (s[i] < s[i + 1]);\n    }\n    std::vector<int> sum_l(upper + 1), sum_s(upper\
    \ + 1);\n    for (int i = 0; i < n; i++) {\n        if (!ls[i]) {\n          \
    \  sum_s[s[i]]++;\n        } else {\n            sum_l[s[i] + 1]++;\n        }\n\
    \    }\n    for (int i = 0; i <= upper; i++) {\n        sum_s[i] += sum_l[i];\n\
    \        if (i < upper) sum_l[i + 1] += sum_s[i];\n    }\n\n    auto induce =\
    \ [&](const std::vector<int>& lms) {\n        std::fill(sa.begin(), sa.end(),\
    \ -1);\n        std::vector<int> buf(upper + 1);\n        std::copy(sum_s.begin(),\
    \ sum_s.end(), buf.begin());\n        for (auto d : lms) {\n            if (d\
    \ == n) continue;\n            sa[buf[s[d]]++] = d;\n        }\n        std::copy(sum_l.begin(),\
    \ sum_l.end(), buf.begin());\n        sa[buf[s[n - 1]]++] = n - 1;\n        for\
    \ (int i = 0; i < n; i++) {\n            int v = sa[i];\n            if (v >=\
    \ 1 && !ls[v - 1]) {\n                sa[buf[s[v - 1]]++] = v - 1;\n         \
    \   }\n        }\n        std::copy(sum_l.begin(), sum_l.end(), buf.begin());\n\
    \        for (int i = n - 1; i >= 0; i--) {\n            int v = sa[i];\n    \
    \        if (v >= 1 && ls[v - 1]) {\n                sa[--buf[s[v - 1] + 1]] =\
    \ v - 1;\n            }\n        }\n    };\n\n    std::vector<int> lms_map(n +\
    \ 1, -1);\n    int m = 0;\n    for (int i = 1; i < n; i++) {\n        if (!ls[i\
    \ - 1] && ls[i]) {\n            lms_map[i] = m++;\n        }\n    }\n    std::vector<int>\
    \ lms;\n    lms.reserve(m);\n    for (int i = 1; i < n; i++) {\n        if (!ls[i\
    \ - 1] && ls[i]) {\n            lms.push_back(i);\n        }\n    }\n\n    induce(lms);\n\
    \n    if (m) {\n        std::vector<int> sorted_lms;\n        sorted_lms.reserve(m);\n\
    \        for (int v : sa) {\n            if (lms_map[v] != -1) sorted_lms.push_back(v);\n\
    \        }\n        std::vector<int> rec_s(m);\n        int rec_upper = 0;\n \
    \       rec_s[lms_map[sorted_lms[0]]] = 0;\n        for (int i = 1; i < m; i++)\
    \ {\n            int l = sorted_lms[i - 1], r = sorted_lms[i];\n            int\
    \ end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;\n            int end_r\
    \ = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;\n            bool same = true;\n\
    \            if (end_l - l != end_r - r) {\n                same = false;\n  \
    \          } else {\n                while (l < end_l) {\n                   \
    \ if (s[l] != s[r]) {\n                        break;\n                    }\n\
    \                    l++;\n                    r++;\n                }\n     \
    \           if (l == n || s[l] != s[r]) same = false;\n            }\n       \
    \     if (!same) rec_upper++;\n            rec_s[lms_map[sorted_lms[i]]] = rec_upper;\n\
    \        }\n\n        auto rec_sa =\n            sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s,\
    \ rec_upper);\n\n        for (int i = 0; i < m; i++) {\n            sorted_lms[i]\
    \ = lms[rec_sa[i]];\n        }\n        induce(sorted_lms);\n    }\n    return\
    \ sa;\n}\n\n}  // namespace internal\n\nstd::vector<int> suffix_array(const std::vector<int>&\
    \ s, int upper) {\n    assert(0 <= upper);\n    for (int d : s) {\n        assert(0\
    \ <= d && d <= upper);\n    }\n    auto sa = internal::sa_is(s, upper);\n    return\
    \ sa;\n}\n\ntemplate <class T> std::vector<int> suffix_array(const std::vector<T>&\
    \ s) {\n    int n = int(s.size());\n    std::vector<int> idx(n);\n    iota(idx.begin(),\
    \ idx.end(), 0);\n    sort(idx.begin(), idx.end(), [&](int l, int r) { return\
    \ s[l] < s[r]; });\n    std::vector<int> s2(n);\n    int now = 0;\n    for (int\
    \ i = 0; i < n; i++) {\n        if (i && s[idx[i - 1]] != s[idx[i]]) now++;\n\
    \        s2[idx[i]] = now;\n    }\n    return internal::sa_is(s2, now);\n}\n\n\
    std::vector<int> suffix_array(const std::string& s) {\n    int n = int(s.size());\n\
    \    std::vector<int> s2(n);\n    for (int i = 0; i < n; i++) {\n        s2[i]\
    \ = s[i];\n    }\n    return internal::sa_is(s2, 255);\n}\n\n// Reference:\n//\
    \ T. Kasai, G. Lee, H. Arimura, S. Arikawa, and K. Park,\n// Linear-Time Longest-Common-Prefix\
    \ Computation in Suffix Arrays and Its\n// Applications\ntemplate <class T>\n\
    std::vector<int> lcp_array(const std::vector<T>& s,\n                        \
    \   const std::vector<int>& sa) {\n    int n = int(s.size());\n    assert(n >=\
    \ 1);\n    std::vector<int> rnk(n);\n    for (int i = 0; i < n; i++) {\n     \
    \   rnk[sa[i]] = i;\n    }\n    std::vector<int> lcp(n - 1);\n    int h = 0;\n\
    \    for (int i = 0; i < n; i++) {\n        if (h > 0) h--;\n        if (rnk[i]\
    \ == 0) continue;\n        int j = sa[rnk[i] - 1];\n        for (; j + h < n &&\
    \ i + h < n; h++) {\n            if (s[j + h] != s[i + h]) break;\n        }\n\
    \        lcp[rnk[i] - 1] = h;\n    }\n    return lcp;\n}\n\nstd::vector<int> lcp_array(const\
    \ std::string& s, const std::vector<int>& sa) {\n    int n = int(s.size());\n\
    \    std::vector<int> s2(n);\n    for (int i = 0; i < n; i++) {\n        s2[i]\
    \ = s[i];\n    }\n    return lcp_array(s2, sa);\n}\n\n// Reference:\n// D. Gusfield,\n\
    // Algorithms on Strings, Trees, and Sequences: Computer Science and\n// Computational\
    \ Biology\ntemplate <class T> std::vector<int> z_algorithm(const std::vector<T>&\
    \ s) {\n    int n = int(s.size());\n    if (n == 0) return {};\n    std::vector<int>\
    \ z(n);\n    z[0] = 0;\n    for (int i = 1, j = 0; i < n; i++) {\n        int&\
    \ k = z[i];\n        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);\n\
    \        while (i + k < n && s[k] == s[i + k]) k++;\n        if (j + z[j] < i\
    \ + z[i]) j = i;\n    }\n    z[0] = n;\n    return z;\n}\n\nstd::vector<int> z_algorithm(const\
    \ std::string& s) {\n    int n = int(s.size());\n    std::vector<int> s2(n);\n\
    \    for (int i = 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n    return z_algorithm(s2);\n\
    }\n\n}  // namespace atcoder\n\n\n#line 2 \"data-structure/sparse-table.hpp\"\n\
    \n#line 4 \"data-structure/sparse-table.hpp\"\n#include <limits>\n#line 6 \"data-structure/sparse-table.hpp\"\
    \nusing namespace std;\n\ntemplate <typename T>\nstruct SparseTable {\n  inline\
    \ static constexpr T INF = numeric_limits<T>::max() / 2;\n  int N;\n  vector<vector<T>\
    \ > table;\n  T f(T a, T b) { return min(a, b); }\n  SparseTable() {}\n  SparseTable(const\
    \ vector<T> &v) : N(v.size()) {\n    int b = 1;\n    while ((1 << b) <= N) ++b;\n\
    \    table.push_back(v);\n    for (int i = 1; i < b; i++) {\n      table.push_back(vector<T>(N,\
    \ INF));\n      for (int j = 0; j + (1 << i) <= N; j++) {\n        table[i][j]\
    \ = f(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n  }\n\
    \  // [l, r)\n  T query(int l, int r) {\n    assert(0 <= l and l <= r and r <=\
    \ N);\n    if (l == r) return INF;\n    int b = 31 - __builtin_clz(r - l);\n \
    \   return f(table[b][l], table[b][r - (1 << b)]);\n  }\n};\n\n/**\n * @brief\
    \ Sparse Table\n */\n#line 5 \"string/string-search.hpp\"\n\ntemplate <typename\
    \ Container>\nstruct StringSearch {\n  const Container& S;\n  int N;\n  vector<int>\
    \ sa, la, invsa;\n  SparseTable<int> sparse;\n\n  StringSearch(const Container&\
    \ _s) : S(_s), N(S.size()) {\n    sa = atcoder::suffix_array(S);\n    la = atcoder::lcp_array(S,\
    \ sa);\n    invsa.resize(N);\n    for (int i = 0; i < N; i++) invsa[sa[i]] = i;\n\
    \    sparse = SparseTable<int>{la};\n  }\n\n  // lcp(s[i, N), s[j, N))\n  int\
    \ lcp(int i, int j) {\n    assert(0 <= min(i, j) and max(i, j) < N);\n    if (i\
    \ == j) return N - i;\n    int x = min(invsa[i], invsa[j]);\n    int y = max(invsa[i],\
    \ invsa[j]);\n    return sparse.query(x, y);\n  }\n  // lcp(s[a, b), s[c, d))\n\
    \  int lcp(int a, int b, int c, int d) {\n    assert(0 <= a and a <= b and b <=\
    \ N);\n    assert(0 <= c and c <= d and d <= N);\n    int l = lcp(a, c);\n   \
    \ return min({l, b - a, d - c});\n  }\n  // lcp(s[a, b), s[c, d))\n  template\
    \ <typename Int>\n  int lcp(pair<Int, Int> p, pair<Int, Int> q) {\n    return\
    \ lcp(p.first, p.second, q.first, q.second);\n  }\n\n  // s[i, N) > s[j, N) :\
    \ 1\n  // s[i, N) = s[j, N) : 0\n  // s[i, N) < s[j, N) : -1\n  int strcmp(int\
    \ i, int j) {\n    assert(0 <= min(i, j) and max(i, j) < N);\n    if (i == j)\
    \ return 0;\n    return invsa[i] < invsa[j] ? -1 : 1;\n  }\n\n  // s[a, b) > s[c,\
    \ d) : 1\n  // s[a, b) = s[c, d) : 0\n  // s[a, b) < s[c, d) : -1\n  int strcmp(int\
    \ a, int b, int c, int d) {\n    int l = lcp(a, b, c, d);\n    return a + l ==\
    \ b            ? (c + l == d ? 0 : -1)\n           : c + l == d          ? 1\n\
    \           : S[a + l] < S[c + l] ? -1\n                                 : 1;\n\
    \  }\n  // s[a, b) > s[c, d) : 1\n  // s[a, b) = s[c, d) : 0\n  // s[a, b) < s[c,\
    \ d) : -1\n  template <typename Int>\n  int strcmp(pair<Int, Int> p, pair<Int,\
    \ Int> q) {\n    return strcmp(p.first, p.second, q.first, q.second);\n  }\n};\n"
  code: "#pragma once\n\n#include \"../atcoder/string.hpp\"\n#include \"../data-structure/sparse-table.hpp\"\
    \n\ntemplate <typename Container>\nstruct StringSearch {\n  const Container& S;\n\
    \  int N;\n  vector<int> sa, la, invsa;\n  SparseTable<int> sparse;\n\n  StringSearch(const\
    \ Container& _s) : S(_s), N(S.size()) {\n    sa = atcoder::suffix_array(S);\n\
    \    la = atcoder::lcp_array(S, sa);\n    invsa.resize(N);\n    for (int i = 0;\
    \ i < N; i++) invsa[sa[i]] = i;\n    sparse = SparseTable<int>{la};\n  }\n\n \
    \ // lcp(s[i, N), s[j, N))\n  int lcp(int i, int j) {\n    assert(0 <= min(i,\
    \ j) and max(i, j) < N);\n    if (i == j) return N - i;\n    int x = min(invsa[i],\
    \ invsa[j]);\n    int y = max(invsa[i], invsa[j]);\n    return sparse.query(x,\
    \ y);\n  }\n  // lcp(s[a, b), s[c, d))\n  int lcp(int a, int b, int c, int d)\
    \ {\n    assert(0 <= a and a <= b and b <= N);\n    assert(0 <= c and c <= d and\
    \ d <= N);\n    int l = lcp(a, c);\n    return min({l, b - a, d - c});\n  }\n\
    \  // lcp(s[a, b), s[c, d))\n  template <typename Int>\n  int lcp(pair<Int, Int>\
    \ p, pair<Int, Int> q) {\n    return lcp(p.first, p.second, q.first, q.second);\n\
    \  }\n\n  // s[i, N) > s[j, N) : 1\n  // s[i, N) = s[j, N) : 0\n  // s[i, N) <\
    \ s[j, N) : -1\n  int strcmp(int i, int j) {\n    assert(0 <= min(i, j) and max(i,\
    \ j) < N);\n    if (i == j) return 0;\n    return invsa[i] < invsa[j] ? -1 : 1;\n\
    \  }\n\n  // s[a, b) > s[c, d) : 1\n  // s[a, b) = s[c, d) : 0\n  // s[a, b) <\
    \ s[c, d) : -1\n  int strcmp(int a, int b, int c, int d) {\n    int l = lcp(a,\
    \ b, c, d);\n    return a + l == b            ? (c + l == d ? 0 : -1)\n      \
    \     : c + l == d          ? 1\n           : S[a + l] < S[c + l] ? -1\n     \
    \                            : 1;\n  }\n  // s[a, b) > s[c, d) : 1\n  // s[a,\
    \ b) = s[c, d) : 0\n  // s[a, b) < s[c, d) : -1\n  template <typename Int>\n \
    \ int strcmp(pair<Int, Int> p, pair<Int, Int> q) {\n    return strcmp(p.first,\
    \ p.second, q.first, q.second);\n  }\n};\n"
  dependsOn:
  - data-structure/sparse-table.hpp
  isVerificationFile: false
  path: string/string-search.hpp
  requiredBy: []
  timestamp: '2023-02-24 23:55:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/string-search.test.cpp
  - verify/verify-yuki/yuki-2231.test.cpp
documentation_of: string/string-search.hpp
layout: document
redirect_from:
- /library/string/string-search.hpp
- /library/string/string-search.hpp.html
title: string/string-search.hpp
---
