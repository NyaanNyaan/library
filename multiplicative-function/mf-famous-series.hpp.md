---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: multiplicative-function/enamurate-multiplicative-function.hpp
    title: multiplicative-function/enamurate-multiplicative-function.hpp
  - icon: ':heavy_check_mark:'
    path: prime/prime-enumerate.hpp
    title: prime/prime-enumerate.hpp
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/mf.test.cpp
    title: verify/verify-unit-test/mf.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/multiplicative-function/mf-famous-series.md
    document_title: "\u6709\u540D\u306A\u4E57\u6CD5\u7684\u95A2\u6570"
    links: []
  bundledCode: "#line 2 \"multiplicative-function/mf-famous-series.hpp\"\n\n#line\
    \ 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n#include\
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
    \ 2 \"multiplicative-function/enamurate-multiplicative-function.hpp\"\n\n#line\
    \ 2 \"prime/prime-enumerate.hpp\"\n\n// Prime Sieve {2, 3, 5, 7, 11, 13, 17, ...}\n\
    vector<int> prime_enumerate(int N) {\n  vector<bool> sieve(N / 3 + 1, 1);\n  for\
    \ (int p = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn; p += d = 6 - d, i++) {\n\
    \    if (!sieve[i]) continue;\n    for (int q = p * p / 3, r = d * p / 3 + (d\
    \ * p % 3 == 2), s = 2 * p,\n             qe = sieve.size();\n         q < qe;\
    \ q += r = s - r)\n      sieve[q] = 0;\n  }\n  vector<int> ret{2, 3};\n  for (int\
    \ p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)\n    if (sieve[i]) ret.push_back(p);\n\
    \  while (!ret.empty() && ret.back() > N) ret.pop_back();\n  return ret;\n}\n\
    #line 5 \"multiplicative-function/enamurate-multiplicative-function.hpp\"\n\n\
    // f(n, p, c) : n = pow(p, c), f is multiplicative function\n\ntemplate <typename\
    \ T, T (*f)(int, int, int)>\nstruct enamurate_multiplicative_function {\n  enamurate_multiplicative_function(int\
    \ _n)\n      : ps(prime_enumerate(_n)), a(_n + 1, T()), n(_n), p(ps.size()) {}\n\
    \n  vector<T> run() {\n    a[1] = 1;\n    dfs(-1, 1, 1);\n    return a;\n  }\n\
    \n private:\n  vector<int> ps;\n  vector<T> a;\n  int n, p;\n  void dfs(int i,\
    \ long long x, T y) {\n    a[x] = y;\n    if (y == T()) return;\n    for (int\
    \ j = i + 1; j < p; j++) {\n      long long nx = x * ps[j];\n      long long dx\
    \ = ps[j];\n      if (nx > n) break;\n      for (int c = 1; nx <= n; nx *= ps[j],\
    \ dx *= ps[j], ++c) {\n        dfs(j, nx, y * f(dx, ps[j], c));\n      }\n   \
    \ }\n  }\n};\n#line 5 \"multiplicative-function/mf-famous-series.hpp\"\n\nnamespace\
    \ multiplicative_function {\ntemplate <typename T>\nT moebius(int, int, int c)\
    \ {\n  return c == 0 ? 1 : c == 1 ? -1 : 0;\n}\ntemplate <typename T>\nT sigma0(int,\
    \ int, int c) {\n  return c + 1;\n}\ntemplate <typename T>\nT sigma1(int n, int\
    \ p, int) {\n  return (n - 1) / (p - 1) + n;\n}\ntemplate <typename T>\nT totient(int\
    \ n, int p, int) {\n  return n - n / p;\n}\n}  // namespace multiplicative_function\n\
    \ntemplate <typename T>\nstatic constexpr vector<T> mobius_function(int n) {\n\
    \  enamurate_multiplicative_function<T, multiplicative_function::moebius<T>> em(\n\
    \      n);\n  return em.run();\n}\n\ntemplate <typename T>\nstatic constexpr vector<T>\
    \ sigma0(int n) {\n  enamurate_multiplicative_function<T, multiplicative_function::sigma0<T>>\
    \ em(\n      n);\n  return em.run();\n}\n\ntemplate <typename T>\nstatic constexpr\
    \ vector<T> sigma1(int n) {\n  enamurate_multiplicative_function<T, multiplicative_function::sigma1<T>>\
    \ em(\n      n);\n  return em.run();\n}\n\ntemplate <typename T>\nstatic constexpr\
    \ vector<T> totient(int n) {\n  enamurate_multiplicative_function<T, multiplicative_function::totient<T>>\
    \ em(\n      n);\n  return em.run();\n}\n\n/**\n * @brief \u6709\u540D\u306A\u4E57\
    \u6CD5\u7684\u95A2\u6570\n * @docs docs/multiplicative-function/mf-famous-series.md\n\
    \ */\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n#include \"enamurate-multiplicative-function.hpp\"\
    \n\nnamespace multiplicative_function {\ntemplate <typename T>\nT moebius(int,\
    \ int, int c) {\n  return c == 0 ? 1 : c == 1 ? -1 : 0;\n}\ntemplate <typename\
    \ T>\nT sigma0(int, int, int c) {\n  return c + 1;\n}\ntemplate <typename T>\n\
    T sigma1(int n, int p, int) {\n  return (n - 1) / (p - 1) + n;\n}\ntemplate <typename\
    \ T>\nT totient(int n, int p, int) {\n  return n - n / p;\n}\n}  // namespace\
    \ multiplicative_function\n\ntemplate <typename T>\nstatic constexpr vector<T>\
    \ mobius_function(int n) {\n  enamurate_multiplicative_function<T, multiplicative_function::moebius<T>>\
    \ em(\n      n);\n  return em.run();\n}\n\ntemplate <typename T>\nstatic constexpr\
    \ vector<T> sigma0(int n) {\n  enamurate_multiplicative_function<T, multiplicative_function::sigma0<T>>\
    \ em(\n      n);\n  return em.run();\n}\n\ntemplate <typename T>\nstatic constexpr\
    \ vector<T> sigma1(int n) {\n  enamurate_multiplicative_function<T, multiplicative_function::sigma1<T>>\
    \ em(\n      n);\n  return em.run();\n}\n\ntemplate <typename T>\nstatic constexpr\
    \ vector<T> totient(int n) {\n  enamurate_multiplicative_function<T, multiplicative_function::totient<T>>\
    \ em(\n      n);\n  return em.run();\n}\n\n/**\n * @brief \u6709\u540D\u306A\u4E57\
    \u6CD5\u7684\u95A2\u6570\n * @docs docs/multiplicative-function/mf-famous-series.md\n\
    \ */\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - multiplicative-function/enamurate-multiplicative-function.hpp
  - prime/prime-enumerate.hpp
  isVerificationFile: false
  path: multiplicative-function/mf-famous-series.hpp
  requiredBy: []
  timestamp: '2020-12-08 16:55:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/mf.test.cpp
documentation_of: multiplicative-function/mf-famous-series.hpp
layout: document
redirect_from:
- /library/multiplicative-function/mf-famous-series.hpp
- /library/multiplicative-function/mf-famous-series.hpp.html
title: "\u6709\u540D\u306A\u4E57\u6CD5\u7684\u95A2\u6570"
---
## 有名な乗法的関数

来るべきDGF(ディリクレ母関数)の流行に備えて(本当に流行るのか？)、自分が理解していることをメモしておく…

#### 乗法的関数

$f(n)$が任意の$\gcd(a,b) = 1$である自然数$a,b$に対して$f(ab) = f(a)f(b)$となる時、$f(n)$は乗法的であると呼ぶ。特に任意の$a,b$について$f(ab)=f(a)f(b)$が成り立つ時は完全乗法的であると呼ぶ。

乗法的関数の重要な性質は以下のようなものが挙げられる。

- $f(n),g(n)$が乗法的である時、$h(n)=f(n)g(n)$も乗法的である。
- $f(n),g(n)$が乗法的である時、ディリクレの畳み込みで得られる関数$h(n)=\sum_{d\mid n}f(d)g\left(\frac{n}{d}\right)$も乗法的である。

また、乗法的関数に関するアルゴリズムは以下のものが知られている。

- $f(n)$が乗法的であり、かつ$f(p^k)$が$\mathrm{O}(1)$で求まるとき、
  - $f(n)$の計算が$\mathrm{O}(n^{\frac{1}{4}})$　(Pollard's Rho法 + 反転公式)
  - $f(n)$の初め$n$項の列挙が$\mathrm{O}(n)$　([実装](https://nyaannyaan.github.io/library/multiplicative-function/enamurate-multiplicative-function.hpp))
  - $f(n)$の初め$n$項のprefix sumが$\mathrm{O}(n^{\frac{2}{3}})$　([実装](https://nyaannyaan.github.io/library/multiplicative-function/enamurate-multiplicative-function.hpp))
  - $g(n)=\sum_{d\mid n}\mu\left(\frac{n}{d}\right)f(d)$の初め$n$項の列挙が$\mathrm{O}(n \log \log n)$　([実装](https://nyaannyaan.github.io/library/multiplicative-function/divisor-multiple-transform.hpp))

#### 有名な乗法的関数

- 定数関数　$\mathrm{I}(n)=c$
- 恒等写像　$\mathrm{Id}(n)=n$
- 指数関数　$\mathrm{Id}_a(n)=n^a$
- Unit Function $\epsilon(n)=[n = 1]$
- メビウス関数　$\sum_{d \mid n} \mu(p^k) =[k = 0]-[k = 1]$
- 約数関数 $\sigma_a(p^k) = \sum_{i=0}^k p^{ai}$
- トーシェント関数　$\sum_{d \mid n} \phi(p^k) = p^k - p^{k-1}$

このうち下の3つは次の畳み込みの関係が知られている。

- メビウス関数　$\sum_{d \mid n} \mu(n) = \epsilon(n)$
- 約数関数 $\sum_{d \mid n} d^a = \sigma_a(n)$
- トーシェント関数　$\sum_{d \mid n} \phi(d) = n$

#### メビウス関数　$\mu(n)$

メビウス関数に関する説明は[ここ](https://nyaannyaan.github.io/library/multiplicative-function/divisor-multiple-transform.hpp)に詳しく書いた。

競技プログラミングにおいてのメビウス関数の利用法は(雑に説明すると)包除原理の$(-1)^k$と似た使い方をすることが多い。実際に具体例を見てみる。

##### 例題1

- $N$の約数$n$に対して$g(n)=\sum_{d\mid n}f(d)$と$\mu(n)$がわかっているとする。この時$f(N)$を$\mathrm{O}(\sigma(N))$で計算せよ。

約数系包除を使えば$\mathrm{O}(\sigma(N)^2)$で解けるがより高速な解法を考えたい。
まずは反転公式を使わずに考察してみる。具体的な$N$についていくつか実験してみると、

$$f(16)=g(16)-g(8)$$

$$f(12)=g(12)-g(6)-g(4)+g(2)$$

$$f(30)=g(30)-g(15)-g(10)-g(6)+g(5)+g(3)+g(2)-g(1)$$

のようになり、これは包除原理+BIT全探索で解くことが出来る。([tsutajさんの非常にわかりやすい包除PDF](https://compro.tsutaj.com//archive/181015_incexc.pdf)に類題の詳しい説明がある。)

一方、反転公式を使うと、例えば$n=12$の時は

$$f(12) = \sum_{d \in \lbrace 1,2,3,4,6,12\rbrace}\mu\left(\frac{n}{d}\right)g(d)=g(12)-g(6)-g(4)+g(2)$$

となり包除原理によって得られる結果と一致する。

下位集合に対するゼータ変換が包除原理で解けることと、約数集合に対するゼータ変換がメビウス関数で解けることは同じような関係にある(？)と言える。

##### 例題2：[Cube-loving Numbers　(HackerRank)](https://www.hackerrank.com/contests/university-codesprint-5/challenges)

- $N$が与えられるので、「自然数$a>1,b\geq 1$を用いて$a^3\times b$と表せる$N$以下の自然数の個数」を$\mathrm{O}(\sqrt[3]{N})$で計算せよ。

$1\leq n\leq N$において自然数$a,b$を用いて$n=a^3\times b$と表せる$n$の個数$g(a)$は$g(a)=\lfloor\frac{N}{a^3}\rfloor$と容易に表せるので、この式をうまく利用して答えを求めたい。(直感的には、$g(n)$は一つの自然数を複数回カウントする関数なのでメビウス変換したいという気持ちになる。)

対象を重複なく数え上げるために、自然数$n$に一対一対応する$(a,b)$を決定したい。具体的には、「$n=A^3\times B$を満たす自然数の組$(A,B)$の中で最も$B$が小さい組」を$n$に対応する組$(a,b)$とおく。そして、$f(a)$を「$(a,\frac{n}{a^3})$と対応している$N$以下の自然数$n$の個数」とおく。

$f$と$g$の関係式を得るために、$g(a)$でカウントされている自然数$n$が$f$のどこでカウントされているかを考える。$n=a^3\times b$としたとき、$b$に一対一対応する整数の組を$(c,d)$とおくと、$n$に対応する組は$(ca,d)$であるから$f(ca)$で数え上げられていることが分かる。逆に$f(ca)$で数え上げられた$n$が$g(a)$で数えられていることも示せる。よって$f(a)$と$g(a)$の間には

$$g(a)=\sum_{a\mid m}f(m) \leftrightarrow f(a)=\sum_{a\mid m}\mu\left(\frac{m}{a}\right)g(m)$$

という倍数変換の関係式が成り立つことがわかる。また、求める答えは$M=\lfloor\sqrt[3]{N}\rfloor$と置いたとき$\sum_{a=2}^Mf(a)$である。
($M\lt a$のとき$f(a)=g(a)=0$である事実を利用している。)

よって倍数メビウス変換を用いれば$\mathrm{O}(M\log \log M)$で計算できることが示せたが、メビウス関数を用いることでさらなる高速化を図りたい。$\sum_{a=2}^Mf(a)$を$g(m)$の線形和に分解したときの$g(m)$の寄与を考察すると、

$$\sum_{a=2}^M f(a)=\sum_{2\leq a\leq M, a\mid m} \left( \mu\left(\frac{m}{a}\right)g(m)\right)$$

$$=\sum_{2\leq m\leq M} g(m)\left(\sum_{a\mid m,a\neq 1}\mu\left(\frac{m}{a}\right)\right)$$

$$=\sum_{2\leq m\leq M} g(m)(-\mu(m)+\sum_{a\mid m}\mu(a))=-\sum_{2\leq m\leq M} g(m)\mu(m)$$

と非常にきれいな式になる。$\mu(m)$および$g(m)$は線形で列挙できるため、求める答えも線形で列挙できる。以上よりこの問題を$\mathrm{O}(\sqrt[3]{N})$で解くことが出来た。
