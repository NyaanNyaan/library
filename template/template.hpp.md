---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':question:'
    path: template/debug.hpp
    title: "\u30C7\u30D0\u30C3\u30B0\u7528\u30C0\u30F3\u30D7\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
    title: verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
    title: verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n\
    #include <immintrin.h>\n\n// bits\n#include <bits/stdc++.h>\n\n// utility\n#line\
    \ 1 \"template/util.hpp\"\nnamespace Nyaan {\nusing ll = long long;\nusing i64\
    \ = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\nusing\
    \ u128 = __uint128_t;\n\ntemplate <typename T>\nusing V = vector<T>;\ntemplate\
    \ <typename T>\nusing VV = vector<vector<T>>;\nusing vi = vector<int>;\nusing\
    \ vl = vector<long long>;\nusing vd = V<double>;\nusing vs = V<string>;\nusing\
    \ vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\n\ntemplate\
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
    \ end(v), a) - begin(v);\n}\n\ntemplate <typename T>\nint btw(T a, T x, T b) {\n\
    \  return a <= x && x < b;\n}\n\ntemplate <typename T, typename U>\nT ceil(T a,\
    \ U b) {\n  return (a + b - 1) / b;\n}\n\nconstexpr long long TEN(int n) {\n \
    \ long long ret = 1, x = 10;\n  for (; n; x *= x, n >>= 1) ret *= (n & 1 ? x :\
    \ 1);\n  return ret;\n}\n\ntemplate <typename T, typename U>\npair<T, U> mkp(const\
    \ T &t, const U &u) {\n  return make_pair(t, u);\n}\n\ntemplate <typename T>\n\
    vector<T> mkrui(const vector<T> &v, bool rev = false) {\n  vector<T> ret(v.size()\
    \ + 1);\n  if (rev) {\n    for (int i = int(v.size()) - 1; i >= 0; i--) ret[i]\
    \ = v[i] + ret[i + 1];\n  } else {\n    for (int i = 0; i < int(v.size()); i++)\
    \ ret[i + 1] = ret[i] + v[i];\n  }\n  return ret;\n};\n\ntemplate <typename T>\n\
    vector<T> mkuni(const vector<T> &v) {\n  vector<T> ret(v);\n  sort(ret.begin(),\
    \ ret.end());\n  ret.erase(unique(ret.begin(), ret.end()), ret.end());\n  return\
    \ ret;\n}\n\ntemplate <typename F>\nvector<int> mkord(int N, F f) {\n  vector<int>\
    \ ord(N);\n  iota(begin(ord), end(ord), 0);\n  sort(begin(ord), end(ord), f);\n\
    \  return ord;\n}\n\ntemplate <typename T>\nvector<T> reord(const vector<T> &v,\
    \ const vector<T> &ord) {\n  int N = v.size();\n  vector<T> ret(N);\n  for (int\
    \ i = 0; i < N; i++) ret[i] = v[ord[i]];\n  return ret;\n};\n\ntemplate <typename\
    \ T = int>\nvector<T> mkiota(int N) {\n  vector<T> ret(N);\n  iota(begin(ret),\
    \ end(ret), 0);\n  return ret;\n}\n\ntemplate <typename T>\nvector<int> mkinv(vector<T>\
    \ &v, int max_val = -1) {\n  if (max_val < (int)v.size()) max_val = v.size() -\
    \ 1;\n  vector<int> inv(max_val + 1, -1);\n  for (int i = 0; i < (int)v.size();\
    \ i++) inv[v[i]] = i;\n  return inv;\n}\n\n}  // namespace Nyaan\n#line 12 \"\
    template/template.hpp\"\n\n// bit operation\n#line 1 \"template/bitop.hpp\"\n\
    namespace Nyaan {\n\n__attribute__((target(\"popcnt\"))) inline int popcnt(const\
    \ u64 &a) {\n  return _mm_popcnt_u64(a);\n}\n\n__attribute__((target(\"bmi\")))\
    \ inline int botbit(const u64 &a) {\n  return _tzcnt_u64(a);\n}\n__attribute__((target(\"\
    bmi\"))) inline int ctz(const u64 &a) {\n  return _tzcnt_u64(a);\n}\n\n__attribute__((target(\"\
    lzcnt\"))) inline int topbit(const u64 &a) {\n  return 63 - _lzcnt_u64(a);\n}\n\
    __attribute__((target(\"lzcnt\"))) inline int clz64(const u64 &a) {\n  return\
    \ _lzcnt_u64(a);\n}\n\ntemplate <typename T>\ninline int gbit(const T &a, int\
    \ i) {\n  return (a >> i) & 1;\n}\ntemplate <typename T>\ninline void sbit(T &a,\
    \ int i, bool b) {\n  a ^= (gbit(a, i) == b ? 0 : (T(b) << i));\n}\n\nconstexpr\
    \ long long PW(int n) { return 1LL << n; }\n\nconstexpr long long MSK(int n) {\
    \ return (1LL << n) - 1; }\n\n}  // namespace Nyaan\n#line 15 \"template/template.hpp\"\
    \n\n// inout\n#line 1 \"template/inout.hpp\"\nnamespace Nyaan {\n\ntemplate <typename\
    \ T, typename U>\nostream &operator<<(ostream &os, const pair<T, U> &p) {\n  os\
    \ << p.first << \" \" << p.second;\n  return os;\n}\ntemplate <typename T, typename\
    \ U>\nistream &operator>>(istream &is, pair<T, U> &p) {\n  is >> p.first >> p.second;\n\
    \  return is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const\
    \ vector<T> &v) {\n  int s = (int)v.size();\n  for (int i = 0; i < s; i++) os\
    \ << (i ? \" \" : \"\") << v[i];\n  return os;\n}\ntemplate <typename T>\nistream\
    \ &operator>>(istream &is, vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return\
    \ is;\n}\n\nvoid in() {}\ntemplate <typename T, class... U>\nvoid in(T &t, U &...\
    \ u) {\n  cin >> t;\n  in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\ntemplate\
    \ <typename T, class... U, char sep = ' '>\nvoid out(const T &t, const U &...\
    \ u) {\n  cout << t;\n  if (sizeof...(u)) cout << sep;\n  out(u...);\n}\n\nvoid\
    \ outr() {}\ntemplate <typename T, class... U, char sep = ' '>\nvoid outr(const\
    \ T &t, const U &... u) {\n  cout << t;\n  outr(u...);\n}\n\nstruct IoSetupNya\
    \ {\n  IoSetupNya() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(15);\n    cerr << fixed << setprecision(7);\n\
    \  }\n} iosetupnya;\n\n}  // namespace Nyaan\n#line 18 \"template/template.hpp\"\
    \n\n// debug\n#line 1 \"template/debug.hpp\"\nnamespace DebugImpl {\n\nvoid dump(const\
    \ char& t) { cerr << t; }\n\nvoid dump(const string& t) { cerr << t; }\n\ntemplate\
    \ <typename T>\nvoid dump(const T& t, enable_if_t<is_integral<T>::value>* = nullptr)\
    \ {\n  string res;\n  if (t == Nyaan::inf) res = \"inf\";\n  if (is_signed<T>::value)\n\
    \    if (t == -Nyaan::inf) res = \"-inf\";\n  if (sizeof(T) == 8) {\n    if (t\
    \ == Nyaan::infLL) res = \"inf\";\n    if (is_signed<T>::value)\n      if (t ==\
    \ -Nyaan::infLL) res = \"-inf\";\n  }\n  if (res.empty()) res = to_string(t);\n\
    \  cerr << res;\n}\n\ntemplate <typename T, typename U>\nvoid dump(const pair<T,\
    \ U>&);\ntemplate <typename T>\nvoid dump(const pair<T*, int>&);\n\ntemplate <typename\
    \ T>\nvoid dump(const T& t,\n          enable_if_t<!is_void<typename T::iterator>::value>*\
    \ = nullptr) {\n  cerr << \"[ \";\n  for (auto it = t.begin(); it != t.end();)\
    \ {\n    dump(*it);\n    cerr << (++it == t.end() ? \" ]\" : \", \");\n  }\n}\n\
    \ntemplate <typename T, typename U>\nvoid dump(const pair<T, U>& t) {\n  cerr\
    \ << \"( \";\n  dump(t.first);\n  cerr << \", \";\n  dump(t.second);\n  cerr <<\
    \ \" )\";\n}\n\ntemplate <typename T>\nvoid dump(const pair<T*, int>& t) {\n \
    \ cerr << \"[ \";\n  for (int i = 0; i < t.second; i++) {\n    dump(t.first[i]);\n\
    \    cerr << (i == t.second - 1 ? \" ]\" : \", \");\n  }\n}\n\nvoid trace() {\
    \ cerr << endl; }\ntemplate <typename Head, typename... Tail>\nvoid trace(Head&&\
    \ head, Tail&&... tail) {\n  cerr << \" \";\n  dump(head);\n  if (sizeof...(tail)\
    \ != 0) cerr << \",\";\n  trace(forward<Tail>(tail)...);\n}\n\n}  // namespace\
    \ DebugImpl\n\nusing DebugImpl::trace;\n\n#ifdef NyaanDebug\n#define trc(...)\
    \                            \\\n  do {                                      \\\
    \n    cerr << \"## \" << #__VA_ARGS__ << \" = \"; \\\n    DebugImpl::trace(__VA_ARGS__);\
    \          \\\n  } while (0)\n#else\n#define trc(...)\n#endif\n\n/**\n * @brief\
    \ \u30C7\u30D0\u30C3\u30B0\u7528\u30C0\u30F3\u30D7\u95A2\u6570\n */\n#line 21\
    \ \"template/template.hpp\"\n\n// macro\n#line 2 \"template/macro.hpp\"\n\n#define\
    \ each(x, v) for (auto&& x : v)\n#define all(v) (v).begin(), (v).end()\n#define\
    \ rep(i, N) for (long long i = 0; i < (long long)(N); i++)\n#define repr(i, N)\
    \ for (long long i = (long long)(N)-1; i >= 0; i--)\n#define rep1(i, N) for (long\
    \ long i = 1; i <= (long long)(N); i++)\n#define repr1(i, N) for (long long i\
    \ = (N); (long long)(i) > 0; i--)\n#define reg(i, a, b) for (long long i = (a);\
    \ i < (b); i++)\n#define regr(i, a, b) for (long long i = (b)-1; i >= (a); i--)\n\
    #define repc(i, a, cond) for (long long i = (a); (cond); i++)\n\n#define die(...)\
    \      \\\n  do {                \\\n    Nyaan::out(__VA_ARGS__); \\\n    return;\
    \           \\\n  } while (0)\n#line 24 \"template/template.hpp\"\n\nnamespace\
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n"
  code: '#pragma once

    using namespace std;


    // intrinstic

    #include <immintrin.h>


    // bits

    #include <bits/stdc++.h>


    // utility

    #include "util.hpp"


    // bit operation

    #include "bitop.hpp"


    // inout

    #include "inout.hpp"


    // debug

    #include "debug.hpp"


    // macro

    #include "macro.hpp"


    namespace Nyaan {

    void solve();

    }

    int main() { Nyaan::solve(); }

    '
  dependsOn:
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  isVerificationFile: false
  path: template/template.hpp
  requiredBy: []
  timestamp: '2020-11-30 18:57:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  - verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
