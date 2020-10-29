---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse-table.hpp
    title: data-structure/sparse-table.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix-array.hpp
    title: string/suffix-array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"verify/verify-yosupo-other/yosupo-number-of-substrings.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\n\
    #line 1 \"competitive-template.hpp\"\n#pragma region kyopro_template\n#define\
    \ Nyaan_template\n#include <immintrin.h>\n#include <bits/stdc++.h>\n#define pb\
    \ push_back\n#define eb emplace_back\n#define fi first\n#define se second\n#define\
    \ each(x, v) for (auto &x : v)\n#define all(v) (v).begin(), (v).end()\n#define\
    \ sz(v) ((int)(v).size())\n#define mem(a, val) memset(a, val, sizeof(a))\n#define\
    \ ini(...)   \\\n  int __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define inl(...)  \
    \       \\\n  long long __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define ins(...) \
    \     \\\n  string __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define inc(...)    \\\n\
    \  char __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define in2(s, t)                \
    \           \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i]);\
    \                         \\\n  }\n#define in3(s, t, u)                      \
    \  \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i], u[i]);\
    \                   \\\n  }\n#define in4(s, t, u, v)                     \\\n\
    \  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i], u[i], v[i]);\
    \             \\\n  }\n#define rep(i, N) for (long long i = 0; i < (long long)(N);\
    \ i++)\n#define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)\n\
    #define rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)\n#define repr1(i,\
    \ N) for (long long i = (N); (long long)(i) > 0; i--)\n#define reg(i, a, b) for\
    \ (long long i = (a); i < (b); i++)\n#define die(...)      \\\n  do {        \
    \        \\\n    out(__VA_ARGS__); \\\n    return;           \\\n  } while (0)\n\
    using namespace std;\nusing ll = long long;\ntemplate <class T>\nusing V = vector<T>;\n\
    using vi = vector<int>;\nusing vl = vector<long long>;\nusing vvi = vector<vector<int>>;\n\
    using vd = V<double>;\nusing vs = V<string>;\nusing vvl = vector<vector<long long>>;\n\
    using P = pair<long long, long long>;\nusing vp = vector<P>;\nusing pii = pair<int,\
    \ int>;\nusing vpi = vector<pair<int, int>>;\nconstexpr int inf = 1001001001;\n\
    constexpr long long infLL = (1LL << 61) - 1;\ntemplate <typename T, typename U>\n\
    inline bool amin(T &x, U y) {\n  return (y < x) ? (x = y, true) : false;\n}\n\
    template <typename T, typename U>\ninline bool amax(T &x, U y) {\n  return (x\
    \ < y) ? (x = y, true) : false;\n}\ntemplate <typename T, typename U>\nostream\
    \ &operator<<(ostream &os, const pair<T, U> &p) {\n  os << p.first << \" \" <<\
    \ p.second;\n  return os;\n}\ntemplate <typename T, typename U>\nistream &operator>>(istream\
    \ &is, pair<T, U> &p) {\n  is >> p.first >> p.second;\n  return is;\n}\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n  int\
    \ s = (int)v.size();\n  for (int i = 0; i < s; i++) os << (i ? \" \" : \"\") <<\
    \ v[i];\n  return os;\n}\ntemplate <typename T>\nistream &operator>>(istream &is,\
    \ vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return is;\n}\nvoid in() {}\n\
    template <typename T, class... U>\nvoid in(T &t, U &... u) {\n  cin >> t;\n  in(u...);\n\
    }\nvoid out() { cout << \"\\n\"; }\ntemplate <typename T, class... U>\nvoid out(const\
    \ T &t, const U &... u) {\n  cout << t;\n  if (sizeof...(u)) cout << \" \";\n\
    \  out(u...);\n}\n\n#ifdef NyaanDebug\n#define trc(...)                   \\\n\
    \  do {                             \\\n    cerr << #__VA_ARGS__ << \" = \"; \\\
    \n    dbg_out(__VA_ARGS__);          \\\n  } while (0)\n#define trca(v, N)   \
    \    \\\n  do {                   \\\n    cerr << #v << \" = \"; \\\n    array_out(v,\
    \ N);     \\\n  } while (0)\n#define trcc(v)                             \\\n\
    \  do {                                      \\\n    cerr << #v << \" = {\"; \
    \                  \\\n    each(x, v) { cerr << \" \" << x << \",\"; } \\\n  \
    \  cerr << \"}\" << endl;                    \\\n  } while (0)\ntemplate <typename\
    \ T>\nvoid _cout(const T &c) {\n  cerr << c;\n}\nvoid _cout(const int &c) {\n\
    \  if (c == 1001001001)\n    cerr << \"inf\";\n  else if (c == -1001001001)\n\
    \    cerr << \"-inf\";\n  else\n    cerr << c;\n}\nvoid _cout(const unsigned int\
    \ &c) {\n  if (c == 1001001001)\n    cerr << \"inf\";\n  else\n    cerr << c;\n\
    }\nvoid _cout(const long long &c) {\n  if (c == 1001001001 || c == (1LL << 61)\
    \ - 1)\n    cerr << \"inf\";\n  else if (c == -1001001001 || c == -((1LL << 61)\
    \ - 1))\n    cerr << \"-inf\";\n  else\n    cerr << c;\n}\nvoid _cout(const unsigned\
    \ long long &c) {\n  if (c == 1001001001 || c == (1LL << 61) - 1)\n    cerr <<\
    \ \"inf\";\n  else\n    cerr << c;\n}\ntemplate <typename T, typename U>\nvoid\
    \ _cout(const pair<T, U> &p) {\n  cerr << \"{ \";\n  _cout(p.fi);\n  cerr << \"\
    , \";\n  _cout(p.se);\n  cerr << \" } \";\n}\ntemplate <typename T>\nvoid _cout(const\
    \ vector<T> &v) {\n  int s = v.size();\n  cerr << \"{ \";\n  for (int i = 0; i\
    \ < s; i++) {\n    cerr << (i ? \", \" : \"\");\n    _cout(v[i]);\n  }\n  cerr\
    \ << \" } \";\n}\ntemplate <typename T>\nvoid _cout(const vector<vector<T>> &v)\
    \ {\n  cerr << \"[ \";\n  for (const auto &x : v) {\n    cerr << endl;\n    _cout(x);\n\
    \    cerr << \", \";\n  }\n  cerr << endl << \" ] \";\n}\nvoid dbg_out() { cerr\
    \ << endl; }\ntemplate <typename T, class... U>\nvoid dbg_out(const T &t, const\
    \ U &... u) {\n  _cout(t);\n  if (sizeof...(u)) cerr << \", \";\n  dbg_out(u...);\n\
    }\ntemplate <typename T>\nvoid array_out(const T &v, int s) {\n  cerr << \"{ \"\
    ;\n  for (int i = 0; i < s; i++) {\n    cerr << (i ? \", \" : \"\");\n    _cout(v[i]);\n\
    \  }\n  cerr << \" } \" << endl;\n}\ntemplate <typename T>\nvoid array_out(const\
    \ T &v, int H, int W) {\n  cerr << \"[ \";\n  for (int i = 0; i < H; i++) {\n\
    \    cerr << (i ? \", \" : \"\");\n    array_out(v[i], W);\n  }\n  cerr << \"\
    \ ] \" << endl;\n}\n#else\n#define trc(...)\n#define trca(...)\n#define trcc(...)\n\
    #endif\n\ninline int popcnt(unsigned long long a) { return __builtin_popcountll(a);\
    \ }\ninline int lsb(unsigned long long a) { return __builtin_ctzll(a); }\ninline\
    \ int msb(unsigned long long a) { return 63 - __builtin_clzll(a); }\ntemplate\
    \ <typename T>\ninline int getbit(T a, int i) {\n  return (a >> i) & 1;\n}\ntemplate\
    \ <typename T>\ninline void setbit(T &a, int i) {\n  a |= (1LL << i);\n}\ntemplate\
    \ <typename T>\ninline void delbit(T &a, int i) {\n  a &= ~(1LL << i);\n}\ntemplate\
    \ <typename T>\nint lb(const vector<T> &v, const T &a) {\n  return lower_bound(begin(v),\
    \ end(v), a) - begin(v);\n}\ntemplate <typename T>\nint ub(const vector<T> &v,\
    \ const T &a) {\n  return upper_bound(begin(v), end(v), a) - begin(v);\n}\ntemplate\
    \ <typename T>\nint btw(T a, T x, T b) {\n  return a <= x && x < b;\n}\ntemplate\
    \ <typename T, typename U>\nT ceil(T a, U b) {\n  return (a + b - 1) / b;\n}\n\
    constexpr long long TEN(int n) {\n  long long ret = 1, x = 10;\n  while (n) {\n\
    \    if (n & 1) ret *= x;\n    x *= x;\n    n >>= 1;\n  }\n  return ret;\n}\n\
    template <typename T>\nvector<T> mkrui(const vector<T> &v) {\n  vector<T> ret(v.size()\
    \ + 1);\n  for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];\n\
    \  return ret;\n};\ntemplate <typename T>\nvector<T> mkuni(const vector<T> &v)\
    \ {\n  vector<T> ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(),\
    \ ret.end()), ret.end());\n  return ret;\n}\ntemplate <typename F>\nvector<int>\
    \ mkord(int N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n\
    \  sort(begin(ord), end(ord), f);\n  return ord;\n}\ntemplate <typename T = int>\n\
    vector<T> mkiota(int N) {\n  vector<T> ret(N);\n  iota(begin(ret), end(ret), 0);\n\
    \  return ret;\n}\ntemplate <typename T>\nvector<int> mkinv(vector<T> &v) {\n\
    \  vector<int> inv(v.size());\n  for (int i = 0; i < (int)v.size(); i++) inv[v[i]]\
    \ = i;\n  return inv;\n}\n\nstruct IoSetupNya {\n  IoSetupNya() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(15);\n  \
    \  cerr << fixed << setprecision(7);\n  }\n} iosetupnya;\n\nvoid solve();\nint\
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"string/suffix-array.hpp\"\
    \nusing namespace std;\n\n#line 3 \"data-structure/sparse-table.hpp\"\nusing namespace\
    \ std;\n\ntemplate <typename T>\nstruct SparseTable {\n  vector<vector<T> > table;\n\
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
    \ search(lcp);\n#line 5 \"verify/verify-yosupo-other/yosupo-number-of-substrings.test.cpp\"\
    \n\nvoid solve() {\n  ins(S);\n  SuffixArray sa(S);\n  LCPArray lcp(sa);\n  ll\
    \ ans = 1LL * sz(S) * (sz(S) + 1) / 2;\n  each(x,lcp.LCP) ans -= x;\n  out(ans);\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    \n#include \"../../competitive-template.hpp\"\n#include \"../../string/suffix-array.hpp\"\
    \n\nvoid solve() {\n  ins(S);\n  SuffixArray sa(S);\n  LCPArray lcp(sa);\n  ll\
    \ ans = 1LL * sz(S) * (sz(S) + 1) / 2;\n  each(x,lcp.LCP) ans -= x;\n  out(ans);\n\
    }"
  dependsOn:
  - competitive-template.hpp
  - string/suffix-array.hpp
  - data-structure/sparse-table.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-other/yosupo-number-of-substrings.test.cpp
  requiredBy: []
  timestamp: '2020-08-09 23:27:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-other/yosupo-number-of-substrings.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-other/yosupo-number-of-substrings.test.cpp
- /verify/verify/verify-yosupo-other/yosupo-number-of-substrings.test.cpp.html
title: verify/verify-yosupo-other/yosupo-number-of-substrings.test.cpp
---
