---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/sparse-table.hpp
    title: data-structure/sparse-table.hpp
  - icon: ':x:'
    path: string/suffix-array.hpp
    title: string/suffix-array.hpp
  - icon: ':question:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':question:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':question:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"verify/verify-yosupo-string/yosupo-number-of-substrings.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\n\
    #line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n#include\
    \ <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <csetjmp>\n#include <csignal>\n#include <cstdarg>\n#include\
    \ <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <ctime>\n#include <deque>\n#include <exception>\n#include\
    \ <forward_list>\n#include <fstream>\n#include <functional>\n#include <initializer_list>\n\
    #include <iomanip>\n#include <ios>\n#include <iosfwd>\n#include <iostream>\n#include\
    \ <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n#include\
    \ <locale>\n#include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n\
    #include <ostream>\n#include <queue>\n#include <random>\n#include <ratio>\n#include\
    \ <regex>\n#include <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n\
    #include <streambuf>\n#include <string>\n#include <system_error>\n#include <tuple>\n\
    #include <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <valarray>\n#include <vector>\n\
    \n// utility\n#line 1 \"template/util.hpp\"\nnamespace Nyaan {\nusing ll = long\
    \ long;\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing i128 =\
    \ __int128_t;\nusing u128 = __uint128_t;\n\ntemplate <typename T>\nusing V = vector<T>;\n\
    template <typename T>\nusing VV = vector<vector<T>>;\nusing vi = vector<int>;\n\
    using vl = vector<long long>;\nusing vd = V<double>;\nusing vs = V<string>;\n\
    using vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\n\ntemplate\
    \ <typename T, typename U>\nstruct P : pair<T, U> {\n  template <typename... Args>\n\
    \  P(Args... args) : pair<T, U>(args...) {}\n\n  using pair<T, U>::first;\n  using\
    \ pair<T, U>::second;\n\n  T &x() { return first; }\n  const T &x() const { return\
    \ first; }\n  U &y() { return second; }\n  const U &y() const { return second;\
    \ }\n\n  P &operator+=(const P &r) {\n    first += r.first;\n    second += r.second;\n\
    \    return *this;\n  }\n  P &operator-=(const P &r) {\n    first -= r.first;\n\
    \    second -= r.second;\n    return *this;\n  }\n  P &operator*=(const P &r)\
    \ {\n    first *= r.first;\n    second *= r.second;\n    return *this;\n  }\n\
    \  P operator+(const P &r) const { return P(*this) += r; }\n  P operator-(const\
    \ P &r) const { return P(*this) -= r; }\n  P operator*(const P &r) const { return\
    \ P(*this) *= r; }\n};\n\nusing pl = P<ll, ll>;\nusing pi = P<int, int>;\nusing\
    \ vp = V<pl>;\n\nconstexpr int inf = 1001001001;\nconstexpr long long infLL =\
    \ 4004004004004004004LL;\n\ntemplate <typename T>\nint sz(const T &t) {\n  return\
    \ t.size();\n}\ntemplate <typename T, size_t N>\nvoid mem(T (&a)[N], int c) {\n\
    \  memset(a, c, sizeof(T) * N);\n}\n\ntemplate <typename T, typename U>\ninline\
    \ bool amin(T &x, U y) {\n  return (y < x) ? (x = y, true) : false;\n}\ntemplate\
    \ <typename T, typename U>\ninline bool amax(T &x, U y) {\n  return (x < y) ?\
    \ (x = y, true) : false;\n}\n\ntemplate <typename T>\nint lb(const vector<T> &v,\
    \ const T &a) {\n  return lower_bound(begin(v), end(v), a) - begin(v);\n}\ntemplate\
    \ <typename T>\nint ub(const vector<T> &v, const T &a) {\n  return upper_bound(begin(v),\
    \ end(v), a) - begin(v);\n}\n\nconstexpr long long TEN(int n) {\n  long long ret\
    \ = 1, x = 10;\n  for (; n; x *= x, n >>= 1) ret *= (n & 1 ? x : 1);\n  return\
    \ ret;\n}\n\ntemplate <typename T, typename U>\npair<T, U> mkp(const T &t, const\
    \ U &u) {\n  return make_pair(t, u);\n}\n\ntemplate <typename T>\nvector<T> mkrui(const\
    \ vector<T> &v, bool rev = false) {\n  vector<T> ret(v.size() + 1);\n  if (rev)\
    \ {\n    for (int i = int(v.size()) - 1; i >= 0; i--) ret[i] = v[i] + ret[i +\
    \ 1];\n  } else {\n    for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i]\
    \ + v[i];\n  }\n  return ret;\n};\n\ntemplate <typename T>\nvector<T> mkuni(const\
    \ vector<T> &v) {\n  vector<T> ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(),\
    \ ret.end()), ret.end());\n  return ret;\n}\n\ntemplate <typename F>\nvector<int>\
    \ mkord(int N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n\
    \  sort(begin(ord), end(ord), f);\n  return ord;\n}\n\ntemplate <typename T>\n\
    vector<T> reord(const vector<T> &v, const vector<T> &ord) {\n  int N = v.size();\n\
    \  vector<T> ret(N);\n  for (int i = 0; i < N; i++) ret[i] = v[ord[i]];\n  return\
    \ ret;\n};\n\ntemplate <typename T = int>\nvector<T> mkiota(int N) {\n  vector<T>\
    \ ret(N);\n  iota(begin(ret), end(ret), 0);\n  return ret;\n}\n\ntemplate <typename\
    \ T>\nvector<int> mkinv(vector<T> &v, int max_val = -1) {\n  if (max_val < (int)v.size())\
    \ max_val = v.size() - 1;\n  vector<int> inv(max_val + 1, -1);\n  for (int i =\
    \ 0; i < (int)v.size(); i++) inv[v[i]] = i;\n  return inv;\n}\n\n}  // namespace\
    \ Nyaan\n#line 70 \"template/template.hpp\"\n\n// bit operation\n#line 1 \"template/bitop.hpp\"\
    \nnamespace Nyaan {\n\n__attribute__((target(\"popcnt\"))) inline int popcnt(const\
    \ u64 &a) {\n  return _mm_popcnt_u64(a);\n}\n\n__attribute__((target(\"bmi\")))\
    \ inline int lsb(const u64 &a) {\n  return _tzcnt_u64(a);\n}\n__attribute__((target(\"\
    bmi\"))) inline int ctz(const u64 &a) {\n  return _tzcnt_u64(a);\n}\n\n__attribute__((target(\"\
    lzcnt\"))) inline int msb(const u64 &a) {\n  return 63 - _lzcnt_u64(a);\n}\n__attribute__((target(\"\
    lzcnt\"))) inline int clz64(const u64 &a) {\n  return _lzcnt_u64(a);\n}\n\ntemplate\
    \ <typename T>\ninline int gbit(const T &a, int i) {\n  return (a >> i) & 1;\n\
    }\ntemplate <typename T>\ninline void sbit(T &a, int i, bool b) {\n  a ^= (gbit(a,\
    \ i) == b ? 0 : (T(b) << i));\n}\n\nconstexpr long long PW(int n) { return 1LL\
    \ << n; }\n\nconstexpr long long MSK(int n) { return (1LL << n) - 1; }\n\n}  //\
    \ namespace Nyaan\n#line 73 \"template/template.hpp\"\n\n// inout\n#line 1 \"\
    template/inout.hpp\"\nnamespace Nyaan {\n\ntemplate <typename T, typename U>\n\
    ostream &operator<<(ostream &os, const pair<T, U> &p) {\n  os << p.first << \"\
    \ \" << p.second;\n  return os;\n}\ntemplate <typename T, typename U>\nistream\
    \ &operator>>(istream &is, pair<T, U> &p) {\n  is >> p.first >> p.second;\n  return\
    \ is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const vector<T>\
    \ &v) {\n  int s = (int)v.size();\n  for (int i = 0; i < s; i++) os << (i ? \"\
    \ \" : \"\") << v[i];\n  return os;\n}\ntemplate <typename T>\nistream &operator>>(istream\
    \ &is, vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return is;\n}\n\nvoid\
    \ in() {}\ntemplate <typename T, class... U>\nvoid in(T &t, U &... u) {\n  cin\
    \ >> t;\n  in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename\
    \ T, class... U, char sep = ' '>\nvoid out(const T &t, const U &... u) {\n  cout\
    \ << t;\n  if (sizeof...(u)) cout << sep;\n  out(u...);\n}\n\nvoid outr() {}\n\
    template <typename T, class... U, char sep = ' '>\nvoid outr(const T &t, const\
    \ U &... u) {\n  cout << t;\n  outr(u...);\n}\n\nstruct IoSetupNya {\n  IoSetupNya()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(15);\n    cerr << fixed << setprecision(7);\n  }\n} iosetupnya;\n\
    \n}  // namespace Nyaan\n#line 76 \"template/template.hpp\"\n\n// debug\n#line\
    \ 1 \"template/debug.hpp\"\nnamespace DebugImpl {\n\ntemplate <typename U, typename\
    \ = void>\nstruct is_specialize : false_type {};\ntemplate <typename U>\nstruct\
    \ is_specialize<\n    U, typename conditional<false, typename U::iterator, void>::type>\n\
    \    : true_type {};\ntemplate <typename U>\nstruct is_specialize<\n    U, typename\
    \ conditional<false, decltype(U::first), void>::type>\n    : true_type {};\ntemplate\
    \ <typename U>\nstruct is_specialize<U, enable_if_t<is_integral<U>::value, void>>\
    \ : true_type {\n};\n\nvoid dump(const char& t) { cerr << t; }\n\nvoid dump(const\
    \ string& t) { cerr << t; }\n\ntemplate <typename U,\n          enable_if_t<!is_specialize<U>::value,\
    \ nullptr_t> = nullptr>\nvoid dump(const U& t) {\n  cerr << t;\n}\n\ntemplate\
    \ <typename T>\nvoid dump(const T& t, enable_if_t<is_integral<T>::value>* = nullptr)\
    \ {\n  string res;\n  if (t == Nyaan::inf) res = \"inf\";\n  if (is_signed<T>::value)\n\
    \    if (t == -Nyaan::inf) res = \"-inf\";\n  if (sizeof(T) == 8) {\n    if (t\
    \ == Nyaan::infLL) res = \"inf\";\n    if (is_signed<T>::value)\n      if (t ==\
    \ -Nyaan::infLL) res = \"-inf\";\n  }\n  if (res.empty()) res = to_string(t);\n\
    \  cerr << res;\n}\n\ntemplate <typename T, typename U>\nvoid dump(const pair<T,\
    \ U>&);\ntemplate <typename T>\nvoid dump(const pair<T*, int>&);\n\ntemplate <typename\
    \ T>\nvoid dump(const T& t,\n          enable_if_t<!is_void<typename T::iterator>::value>*\
    \ = nullptr) {\n  cerr << \"[ \";\n  for (auto it = t.begin(); it != t.end();)\
    \ {\n    dump(*it);\n    cerr << (++it == t.end() ? \"\" : \", \");\n  }\n  cerr\
    \ << \" ]\";\n}\n\ntemplate <typename T, typename U>\nvoid dump(const pair<T,\
    \ U>& t) {\n  cerr << \"( \";\n  dump(t.first);\n  cerr << \", \";\n  dump(t.second);\n\
    \  cerr << \" )\";\n}\n\ntemplate <typename T>\nvoid dump(const pair<T*, int>&\
    \ t) {\n  cerr << \"[ \";\n  for (int i = 0; i < t.second; i++) {\n    dump(t.first[i]);\n\
    \    cerr << (i == t.second - 1 ? \"\" : \", \");\n  }\n  cerr << \" ]\";\n}\n\
    \nvoid trace() { cerr << endl; }\ntemplate <typename Head, typename... Tail>\n\
    void trace(Head&& head, Tail&&... tail) {\n  cerr << \" \";\n  dump(head);\n \
    \ if (sizeof...(tail) != 0) cerr << \",\";\n  trace(forward<Tail>(tail)...);\n\
    }\n\n}  // namespace DebugImpl\n\n#ifdef NyaanDebug\n#define trc(...)        \
    \                    \\\n  do {                                      \\\n    cerr\
    \ << \"## \" << #__VA_ARGS__ << \" = \"; \\\n    DebugImpl::trace(__VA_ARGS__);\
    \          \\\n  } while (0)\n#else\n#define trc(...)\n#endif\n#line 79 \"template/template.hpp\"\
    \n\n// macro\n#line 1 \"template/macro.hpp\"\n#define each(x, v) for (auto&& x\
    \ : v)\n#define each2(x, y, v) for (auto&& [x, y] : v)\n#define all(v) (v).begin(),\
    \ (v).end()\n#define rep(i, N) for (long long i = 0; i < (long long)(N); i++)\n\
    #define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)\n#define\
    \ rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)\n#define repr1(i,\
    \ N) for (long long i = (N); (long long)(i) > 0; i--)\n#define reg(i, a, b) for\
    \ (long long i = (a); i < (b); i++)\n#define regr(i, a, b) for (long long i =\
    \ (b)-1; i >= (a); i--)\n#define repc(i, a, cond) for (long long i = (a); (cond);\
    \ i++)\n#define enm(i, val, vec)                                  \\\n  for (long\
    \ long i = 0; i < (long long)(vec).size(); i++) \\\n    if (auto& val = vec[i];\
    \ false)                        \\\n      ;                                  \
    \                 \\\n    else\n\n#define ini(...)   \\\n  int __VA_ARGS__; \\\
    \n  in(__VA_ARGS__)\n#define inl(...)         \\\n  long long __VA_ARGS__; \\\n\
    \  in(__VA_ARGS__)\n#define ins(...)      \\\n  string __VA_ARGS__; \\\n  in(__VA_ARGS__)\n\
    #define inc(...)    \\\n  char __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define in2(s,\
    \ t)                           \\\n  for (int i = 0; i < (int)s.size(); i++) {\
    \ \\\n    in(s[i], t[i]);                         \\\n  }\n#define in3(s, t, u)\
    \                        \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n\
    \    in(s[i], t[i], u[i]);                   \\\n  }\n#define in4(s, t, u, v)\
    \                     \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n   \
    \ in(s[i], t[i], u[i], v[i]);             \\\n  }\n\n#define die(...)        \
    \     \\\n  do {                       \\\n    Nyaan::out(__VA_ARGS__); \\\n \
    \   return;                  \\\n  } while (0)\n#line 82 \"template/template.hpp\"\
    \n\nnamespace Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line\
    \ 2 \"string/suffix-array.hpp\"\n\n\n\n#line 2 \"data-structure/sparse-table.hpp\"\
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
    \ search(lcp);\n#line 5 \"verify/verify-yosupo-string/yosupo-number-of-substrings.test.cpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve() {\n  ins(S);\n  SuffixArray sa(S);\n\
    \  LCPArray lcp(sa);\n  ll ans = 1LL * sz(S) * (sz(S) + 1) / 2;\n  each(x,lcp.LCP)\
    \ ans -= x;\n  out(ans);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    \n#include \"../../template/template.hpp\"\n#include \"../../string/suffix-array.hpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve() {\n  ins(S);\n  SuffixArray sa(S);\n\
    \  LCPArray lcp(sa);\n  ll ans = 1LL * sz(S) * (sz(S) + 1) / 2;\n  each(x,lcp.LCP)\
    \ ans -= x;\n  out(ans);\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - string/suffix-array.hpp
  - data-structure/sparse-table.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-string/yosupo-number-of-substrings.test.cpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/verify-yosupo-string/yosupo-number-of-substrings.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-string/yosupo-number-of-substrings.test.cpp
- /verify/verify/verify-yosupo-string/yosupo-number-of-substrings.test.cpp.html
title: verify/verify-yosupo-string/yosupo-number-of-substrings.test.cpp
---
