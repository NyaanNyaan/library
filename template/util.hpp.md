---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/debug.test.cpp
    title: verify/verify-unit-test/debug.test.cpp
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
  bundledCode: "#line 1 \"template/util.hpp\"\nnamespace Nyaan {\nusing ll = long\
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
    \ i++) inv[v[i]] = i;\n  return inv;\n}\n\n}  // namespace Nyaan\n"
  code: "namespace Nyaan {\nusing ll = long long;\nusing i64 = long long;\nusing u64\
    \ = unsigned long long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    \ntemplate <typename T>\nusing V = vector<T>;\ntemplate <typename T>\nusing VV\
    \ = vector<vector<T>>;\nusing vi = vector<int>;\nusing vl = vector<long long>;\n\
    using vd = V<double>;\nusing vs = V<string>;\nusing vvi = vector<vector<int>>;\n\
    using vvl = vector<vector<long long>>;\n\ntemplate <typename T, typename U>\n\
    struct P : pair<T, U> {\n  template <typename... Args>\n  P(Args... args) : pair<T,\
    \ U>(args...) {}\n\n  using pair<T, U>::first;\n  using pair<T, U>::second;\n\n\
    \  T &x() { return first; }\n  const T &x() const { return first; }\n  U &y()\
    \ { return second; }\n  const U &y() const { return second; }\n\n  P &operator+=(const\
    \ P &r) {\n    first += r.first;\n    second += r.second;\n    return *this;\n\
    \  }\n  P &operator-=(const P &r) {\n    first -= r.first;\n    second -= r.second;\n\
    \    return *this;\n  }\n  P &operator*=(const P &r) {\n    first *= r.first;\n\
    \    second *= r.second;\n    return *this;\n  }\n  P operator+(const P &r) const\
    \ { return P(*this) += r; }\n  P operator-(const P &r) const { return P(*this)\
    \ -= r; }\n  P operator*(const P &r) const { return P(*this) *= r; }\n};\n\nusing\
    \ pl = P<ll, ll>;\nusing pi = P<int, int>;\nusing vp = V<pl>;\n\nconstexpr int\
    \ inf = 1001001001;\nconstexpr long long infLL = 4004004004004004004LL;\n\ntemplate\
    \ <typename T>\nint sz(const T &t) {\n  return t.size();\n}\ntemplate <typename\
    \ T, size_t N>\nvoid mem(T (&a)[N], int c) {\n  memset(a, c, sizeof(T) * N);\n\
    }\n\ntemplate <typename T, typename U>\ninline bool amin(T &x, U y) {\n  return\
    \ (y < x) ? (x = y, true) : false;\n}\ntemplate <typename T, typename U>\ninline\
    \ bool amax(T &x, U y) {\n  return (x < y) ? (x = y, true) : false;\n}\n\ntemplate\
    \ <typename T>\nint lb(const vector<T> &v, const T &a) {\n  return lower_bound(begin(v),\
    \ end(v), a) - begin(v);\n}\ntemplate <typename T>\nint ub(const vector<T> &v,\
    \ const T &a) {\n  return upper_bound(begin(v), end(v), a) - begin(v);\n}\n\n\
    template <typename T>\nint btw(T a, T x, T b) {\n  return a <= x && x < b;\n}\n\
    \ntemplate <typename T, typename U>\nT ceil(T a, U b) {\n  return (a + b - 1)\
    \ / b;\n}\n\nconstexpr long long TEN(int n) {\n  long long ret = 1, x = 10;\n\
    \  for (; n; x *= x, n >>= 1) ret *= (n & 1 ? x : 1);\n  return ret;\n}\n\ntemplate\
    \ <typename T, typename U>\npair<T, U> mkp(const T &t, const U &u) {\n  return\
    \ make_pair(t, u);\n}\n\ntemplate <typename T>\nvector<T> mkrui(const vector<T>\
    \ &v, bool rev = false) {\n  vector<T> ret(v.size() + 1);\n  if (rev) {\n    for\
    \ (int i = int(v.size()) - 1; i >= 0; i--) ret[i] = v[i] + ret[i + 1];\n  } else\
    \ {\n    for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];\n\
    \  }\n  return ret;\n};\n\ntemplate <typename T>\nvector<T> mkuni(const vector<T>\
    \ &v) {\n  vector<T> ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(),\
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
    \ Nyaan\n"
  dependsOn: []
  isVerificationFile: false
  path: template/util.hpp
  requiredBy:
  - template/template.hpp
  timestamp: '2020-11-30 18:57:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/debug.test.cpp
  - verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  - verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
documentation_of: template/util.hpp
layout: document
redirect_from:
- /library/template/util.hpp
- /library/template/util.hpp.html
title: template/util.hpp
---
