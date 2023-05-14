---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: inner/inner_math.hpp
    title: inner/inner_math.hpp
  - icon: ':heavy_check_mark:'
    path: math/bigint-garner.hpp
    title: Garner's algorithm for bigint
  - icon: ':heavy_check_mark:'
    path: math/bigint.hpp
    title: "\u591A\u500D\u9577\u6574\u6570"
  - icon: ':heavy_check_mark:'
    path: misc/all.hpp
    title: misc/all.hpp
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: misc/timer.hpp
    title: misc/timer.hpp
  - icon: ':heavy_check_mark:'
    path: modint/arbitrary-modint.hpp
    title: modint/arbitrary-modint.hpp
  - icon: ':heavy_check_mark:'
    path: modint/arbitrary-prime-modint.hpp
    title: modint/arbitrary-prime-modint.hpp
  - icon: ':heavy_check_mark:'
    path: modint/barrett-reduction.hpp
    title: modint/barrett-reduction.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint-montgomery64.hpp
    title: modint/modint-montgomery64.hpp
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/arbitrary-ntt.hpp
    title: ntt/arbitrary-ntt.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/ntt.hpp
    title: ntt/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: prime/fast-factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)"
  - icon: ':heavy_check_mark:'
    path: prime/prime-enumerate.hpp
    title: prime/prime-enumerate.hpp
  - icon: ':heavy_check_mark:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':heavy_check_mark:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':heavy_check_mark:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/garner-bigint.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#line 2 \"template/template.hpp\"\
    \nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cctype>\n#include\
    \ <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <cstdarg>\n#include\
    \ <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
    #include <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include\
    \ <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <streambuf>\n#include <string>\n#include <tuple>\n\
    #include <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <vector>\n\n// utility\n#line\
    \ 1 \"template/util.hpp\"\nnamespace Nyaan {\nusing ll = long long;\nusing i64\
    \ = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\nusing\
    \ u128 = __uint128_t;\n\ntemplate <typename T>\nusing V = vector<T>;\ntemplate\
    \ <typename T>\nusing VV = vector<vector<T>>;\nusing vi = vector<int>;\nusing\
    \ vl = vector<long long>;\nusing vd = V<double>;\nusing vs = V<string>;\nusing\
    \ vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\n\ntemplate\
    \ <typename T, typename U>\nstruct P : pair<T, U> {\n  template <typename... Args>\n\
    \  P(Args... args) : pair<T, U>(args...) {}\n\n  using pair<T, U>::first;\n  using\
    \ pair<T, U>::second;\n\n  P &operator+=(const P &r) {\n    first += r.first;\n\
    \    second += r.second;\n    return *this;\n  }\n  P &operator-=(const P &r)\
    \ {\n    first -= r.first;\n    second -= r.second;\n    return *this;\n  }\n\
    \  P &operator*=(const P &r) {\n    first *= r.first;\n    second *= r.second;\n\
    \    return *this;\n  }\n  template <typename S>\n  P &operator*=(const S &r)\
    \ {\n    first *= r, second *= r;\n    return *this;\n  }\n  P operator+(const\
    \ P &r) const { return P(*this) += r; }\n  P operator-(const P &r) const { return\
    \ P(*this) -= r; }\n  P operator*(const P &r) const { return P(*this) *= r; }\n\
    \  template <typename S>\n  P operator*(const S &r) const {\n    return P(*this)\
    \ *= r;\n  }\n  P operator-() const { return P{-first, -second}; }\n};\n\nusing\
    \ pl = P<ll, ll>;\nusing pi = P<int, int>;\nusing vp = V<pl>;\n\nconstexpr int\
    \ inf = 1001001001;\nconstexpr long long infLL = 4004004004004004004LL;\n\ntemplate\
    \ <typename T>\nint sz(const T &t) {\n  return t.size();\n}\n\ntemplate <typename\
    \ T, typename U>\ninline bool amin(T &x, U y) {\n  return (y < x) ? (x = y, true)\
    \ : false;\n}\ntemplate <typename T, typename U>\ninline bool amax(T &x, U y)\
    \ {\n  return (x < y) ? (x = y, true) : false;\n}\n\ntemplate <typename T>\ninline\
    \ T Max(const vector<T> &v) {\n  return *max_element(begin(v), end(v));\n}\ntemplate\
    \ <typename T>\ninline T Min(const vector<T> &v) {\n  return *min_element(begin(v),\
    \ end(v));\n}\ntemplate <typename T>\ninline long long Sum(const vector<T> &v)\
    \ {\n  return accumulate(begin(v), end(v), 0LL);\n}\n\ntemplate <typename T>\n\
    int lb(const vector<T> &v, const T &a) {\n  return lower_bound(begin(v), end(v),\
    \ a) - begin(v);\n}\ntemplate <typename T>\nint ub(const vector<T> &v, const T\
    \ &a) {\n  return upper_bound(begin(v), end(v), a) - begin(v);\n}\n\nconstexpr\
    \ long long TEN(int n) {\n  long long ret = 1, x = 10;\n  for (; n; x *= x, n\
    \ >>= 1) ret *= (n & 1 ? x : 1);\n  return ret;\n}\n\ntemplate <typename T, typename\
    \ U>\npair<T, U> mkp(const T &t, const U &u) {\n  return make_pair(t, u);\n}\n\
    \ntemplate <typename T>\nvector<T> mkrui(const vector<T> &v, bool rev = false)\
    \ {\n  vector<T> ret(v.size() + 1);\n  if (rev) {\n    for (int i = int(v.size())\
    \ - 1; i >= 0; i--) ret[i] = v[i] + ret[i + 1];\n  } else {\n    for (int i =\
    \ 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];\n  }\n  return ret;\n\
    };\n\ntemplate <typename T>\nvector<T> mkuni(const vector<T> &v) {\n  vector<T>\
    \ ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(), ret.end()),\
    \ ret.end());\n  return ret;\n}\n\ntemplate <typename F>\nvector<int> mkord(int\
    \ N,F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n  sort(begin(ord),\
    \ end(ord), f);\n  return ord;\n}\n\ntemplate <typename T>\nvector<int> mkinv(vector<T>\
    \ &v) {\n  int max_val = *max_element(begin(v), end(v));\n  vector<int> inv(max_val\
    \ + 1, -1);\n  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;\n  return\
    \ inv;\n}\n\nvector<int> mkiota(int n) {\n  vector<int> ret(n);\n  iota(begin(ret),\
    \ end(ret), 0);\n  return ret;\n}\n\ntemplate <typename T>\nT mkrev(const T &v)\
    \ {\n  T w{v};\n  reverse(begin(w), end(w));\n  return w;\n}\n\ntemplate <typename\
    \ T>\nbool nxp(vector<T> &v) {\n  return next_permutation(begin(v), end(v));\n\
    }\n\ntemplate <typename T>\nusing minpq = priority_queue<T, vector<T>, greater<T>>;\n\
    \n}  // namespace Nyaan\n#line 58 \"template/template.hpp\"\n\n// bit operation\n\
    #line 1 \"template/bitop.hpp\"\nnamespace Nyaan {\n__attribute__((target(\"popcnt\"\
    ))) inline int popcnt(const u64 &a) {\n  return _mm_popcnt_u64(a);\n}\ninline\
    \ int lsb(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }\ninline int ctz(const\
    \ u64 &a) { return a ? __builtin_ctzll(a) : 64; }\ninline int msb(const u64 &a)\
    \ { return a ? 63 - __builtin_clzll(a) : -1; }\ntemplate <typename T>\ninline\
    \ int gbit(const T &a, int i) {\n  return (a >> i) & 1;\n}\ntemplate <typename\
    \ T>\ninline void sbit(T &a, int i, bool b) {\n  if (gbit(a, i) != b) a ^= T(1)\
    \ << i;\n}\nconstexpr long long PW(int n) { return 1LL << n; }\nconstexpr long\
    \ long MSK(int n) { return (1LL << n) - 1; }\n}  // namespace Nyaan\n#line 61\
    \ \"template/template.hpp\"\n\n// inout\n#line 1 \"template/inout.hpp\"\nnamespace\
    \ Nyaan {\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream &os,\
    \ const pair<T, U> &p) {\n  os << p.first << \" \" << p.second;\n  return os;\n\
    }\ntemplate <typename T, typename U>\nistream &operator>>(istream &is, pair<T,\
    \ U> &p) {\n  is >> p.first >> p.second;\n  return is;\n}\n\ntemplate <typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n  int s = (int)v.size();\n\
    \  for (int i = 0; i < s; i++) os << (i ? \" \" : \"\") << v[i];\n  return os;\n\
    }\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T> &v) {\n \
    \ for (auto &x : v) is >> x;\n  return is;\n}\n\nistream &operator>>(istream &is,\
    \ __int128_t &x) {\n  string S;\n  is >> S;\n  x = 0;\n  int flag = 0;\n  for\
    \ (auto &c : S) {\n    if (c == '-') {\n      flag = true;\n      continue;\n\
    \    }\n    x *= 10;\n    x += c - '0';\n  }\n  if (flag) x = -x;\n  return is;\n\
    }\n\nistream &operator>>(istream &is, __uint128_t &x) {\n  string S;\n  is >>\
    \ S;\n  x = 0;\n  for (auto &c : S) {\n    x *= 10;\n    x += c - '0';\n  }\n\
    \  return is;\n}\n\nostream &operator<<(ostream &os, __int128_t x) {\n  if (x\
    \ == 0) return os << 0;\n  if (x < 0) os << '-', x = -x;\n  string S;\n  while\
    \ (x) S.push_back('0' + x % 10), x /= 10;\n  reverse(begin(S), end(S));\n  return\
    \ os << S;\n}\nostream &operator<<(ostream &os, __uint128_t x) {\n  if (x == 0)\
    \ return os << 0;\n  string S;\n  while (x) S.push_back('0' + x % 10), x /= 10;\n\
    \  reverse(begin(S), end(S));\n  return os << S;\n}\n\nvoid in() {}\ntemplate\
    \ <typename T, class... U>\nvoid in(T &t, U &...u) {\n  cin >> t;\n  in(u...);\n\
    }\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename T, class... U, char sep\
    \ = ' '>\nvoid out(const T &t, const U &...u) {\n  cout << t;\n  if (sizeof...(u))\
    \ cout << sep;\n  out(u...);\n}\n\nstruct IoSetupNya {\n  IoSetupNya() {\n   \
    \ cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(15);\n\
    \    cerr << fixed << setprecision(7);\n  }\n} iosetupnya;\n\n}  // namespace\
    \ Nyaan\n#line 64 \"template/template.hpp\"\n\n// debug\n#line 1 \"template/debug.hpp\"\
    \nnamespace DebugImpl {\n\ntemplate <typename U, typename = void>\nstruct is_specialize\
    \ : false_type {};\ntemplate <typename U>\nstruct is_specialize<\n    U, typename\
    \ conditional<false, typename U::iterator, void>::type>\n    : true_type {};\n\
    template <typename U>\nstruct is_specialize<\n    U, typename conditional<false,\
    \ decltype(U::first), void>::type>\n    : true_type {};\ntemplate <typename U>\n\
    struct is_specialize<U, enable_if_t<is_integral<U>::value, void>> : true_type\
    \ {\n};\n\nvoid dump(const char& t) { cerr << t; }\n\nvoid dump(const string&\
    \ t) { cerr << t; }\n\nvoid dump(const bool& t) { cerr << (t ? \"true\" : \"false\"\
    ); }\n\nvoid dump(__int128_t t) {\n  if (t == 0) cerr << 0;\n  if (t < 0) cerr\
    \ << '-', t = -t;\n  string S;\n  while (t) S.push_back('0' + t % 10), t /= 10;\n\
    \  reverse(begin(S), end(S));\n  cerr << S;\n}\n\nvoid dump(__uint128_t t) {\n\
    \  if (t == 0) cerr << 0;\n  string S;\n  while (t) S.push_back('0' + t % 10),\
    \ t /= 10;\n  reverse(begin(S), end(S));\n  cerr << S;\n}\n\ntemplate <typename\
    \ U,\n          enable_if_t<!is_specialize<U>::value, nullptr_t> = nullptr>\n\
    void dump(const U& t) {\n  cerr << t;\n}\n\ntemplate <typename T>\nvoid dump(const\
    \ T& t, enable_if_t<is_integral<T>::value>* = nullptr) {\n  string res;\n  if\
    \ (t == Nyaan::inf) res = \"inf\";\n  if constexpr (is_signed<T>::value) {\n \
    \   if (t == -Nyaan::inf) res = \"-inf\";\n  }\n  if constexpr (sizeof(T) == 8)\
    \ {\n    if (t == Nyaan::infLL) res = \"inf\";\n    if constexpr (is_signed<T>::value)\
    \ {\n      if (t == -Nyaan::infLL) res = \"-inf\";\n    }\n  }\n  if (res.empty())\
    \ res = to_string(t);\n  cerr << res;\n}\n\ntemplate <typename T, typename U>\n\
    void dump(const pair<T, U>&);\ntemplate <typename T>\nvoid dump(const pair<T*,\
    \ int>&);\n\ntemplate <typename T>\nvoid dump(const T& t,\n          enable_if_t<!is_void<typename\
    \ T::iterator>::value>* = nullptr) {\n  cerr << \"[ \";\n  for (auto it = t.begin();\
    \ it != t.end();) {\n    dump(*it);\n    cerr << (++it == t.end() ? \"\" : \"\
    , \");\n  }\n  cerr << \" ]\";\n}\n\ntemplate <typename T, typename U>\nvoid dump(const\
    \ pair<T, U>& t) {\n  cerr << \"( \";\n  dump(t.first);\n  cerr << \", \";\n \
    \ dump(t.second);\n  cerr << \" )\";\n}\n\ntemplate <typename T>\nvoid dump(const\
    \ pair<T*, int>& t) {\n  cerr << \"[ \";\n  for (int i = 0; i < t.second; i++)\
    \ {\n    dump(t.first[i]);\n    cerr << (i == t.second - 1 ? \"\" : \", \");\n\
    \  }\n  cerr << \" ]\";\n}\n\nvoid trace() { cerr << endl; }\ntemplate <typename\
    \ Head, typename... Tail>\nvoid trace(Head&& head, Tail&&... tail) {\n  cerr <<\
    \ \" \";\n  dump(head);\n  if (sizeof...(tail) != 0) cerr << \",\";\n  trace(forward<Tail>(tail)...);\n\
    }\n\n}  // namespace DebugImpl\n\n#ifdef NyaanDebug\n#define trc(...)        \
    \                    \\\n  do {                                      \\\n    cerr\
    \ << \"## \" << #__VA_ARGS__ << \" = \"; \\\n    DebugImpl::trace(__VA_ARGS__);\
    \          \\\n  } while (0)\n#else\n#define trc(...) (void(0))\n#endif\n\n#ifdef\
    \ NyaanLocal\n#define trc2(...)                           \\\n  do {         \
    \                             \\\n    cerr << \"## \" << #__VA_ARGS__ << \" =\
    \ \"; \\\n    DebugImpl::trace(__VA_ARGS__);          \\\n  } while (0)\n#else\n\
    #define trc2(...) (void(0))\n#endif\n#line 67 \"template/template.hpp\"\n\n//\
    \ macro\n#line 1 \"template/macro.hpp\"\n#define each(x, v) for (auto&& x : v)\n\
    #define each2(x, y, v) for (auto&& [x, y] : v)\n#define all(v) (v).begin(), (v).end()\n\
    #define rep(i, N) for (long long i = 0; i < (long long)(N); i++)\n#define repr(i,\
    \ N) for (long long i = (long long)(N)-1; i >= 0; i--)\n#define rep1(i, N) for\
    \ (long long i = 1; i <= (long long)(N); i++)\n#define repr1(i, N) for (long long\
    \ i = (N); (long long)(i) > 0; i--)\n#define reg(i, a, b) for (long long i = (a);\
    \ i < (b); i++)\n#define regr(i, a, b) for (long long i = (b)-1; i >= (a); i--)\n\
    #define fi first\n#define se second\n#define ini(...)   \\\n  int __VA_ARGS__;\
    \ \\\n  in(__VA_ARGS__)\n#define inl(...)         \\\n  long long __VA_ARGS__;\
    \ \\\n  in(__VA_ARGS__)\n#define ins(...)      \\\n  string __VA_ARGS__; \\\n\
    \  in(__VA_ARGS__)\n#define in2(s, t)                           \\\n  for (int\
    \ i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i]);                   \
    \      \\\n  }\n#define in3(s, t, u)                        \\\n  for (int i =\
    \ 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i], u[i]);                 \
    \  \\\n  }\n#define in4(s, t, u, v)                     \\\n  for (int i = 0;\
    \ i < (int)s.size(); i++) { \\\n    in(s[i], t[i], u[i], v[i]);             \\\
    \n  }\n#define die(...)             \\\n  do {                       \\\n    Nyaan::out(__VA_ARGS__);\
    \ \\\n    return;                  \\\n  } while (0)\n#line 70 \"template/template.hpp\"\
    \n\nnamespace Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line\
    \ 4 \"verify/verify-unit-test/garner-bigint.test.cpp\"\n//\n#line 1 \"math/bigint-garner.hpp\"\
    \n\n#line 2 \"math/bigint.hpp\"\n\n#line 10 \"math/bigint.hpp\"\nusing namespace\
    \ std;\n\n#line 2 \"ntt/arbitrary-ntt.hpp\"\n\n#line 2 \"modint/montgomery-modint.hpp\"\
    \n\n\n\ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt {\n  using mint =\
    \ LazyMontgomeryModInt;\n  using i32 = int32_t;\n  using u32 = uint32_t;\n  using\
    \ u64 = uint64_t;\n\n  static constexpr u32 get_r() {\n    u32 ret = mod;\n  \
    \  for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n\
    \  static constexpr u32 r = get_r();\n  static constexpr u32 n2 = -u64(mod) %\
    \ mod;\n  static_assert(r * mod == 1, \"invalid, r * mod != 1\");\n  static_assert(mod\
    \ < (1 << 30), \"invalid, mod >= 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"\
    invalid, mod % 2 == 0\");\n\n  u32 a;\n\n  constexpr LazyMontgomeryModInt() :\
    \ a(0) {}\n  constexpr LazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b\
    \ % mod + mod) * n2)){};\n\n  static constexpr u32 reduce(const u64 &b) {\n  \
    \  return (b + u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  constexpr mint &operator+=(const\
    \ mint &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n\
    \  }\n\n  constexpr mint &operator-=(const mint &b) {\n    if (i32(a -= b.a) <\
    \ 0) a += 2 * mod;\n    return *this;\n  }\n\n  constexpr mint &operator*=(const\
    \ mint &b) {\n    a = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  constexpr\
    \ mint &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return *this;\n\
    \  }\n\n  constexpr mint operator+(const mint &b) const { return mint(*this) +=\
    \ b; }\n  constexpr mint operator-(const mint &b) const { return mint(*this) -=\
    \ b; }\n  constexpr mint operator*(const mint &b) const { return mint(*this) *=\
    \ b; }\n  constexpr mint operator/(const mint &b) const { return mint(*this) /=\
    \ b; }\n  constexpr bool operator==(const mint &b) const {\n    return (a >= mod\
    \ ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n  constexpr bool operator!=(const\
    \ mint &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a -\
    \ mod : b.a);\n  }\n  constexpr mint operator-() const { return mint() - mint(*this);\
    \ }\n\n  constexpr mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n   \
    \ while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>=\
    \ 1;\n    }\n    return ret;\n  }\n  \n  constexpr mint inverse() const { return\
    \ pow(mod - 2); }\n\n  friend ostream &operator<<(ostream &os, const mint &b)\
    \ {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is,\
    \ mint &b) {\n    int64_t t;\n    is >> t;\n    b = LazyMontgomeryModInt<mod>(t);\n\
    \    return (is);\n  }\n  \n  constexpr u32 get() const {\n    u32 ret = reduce(a);\n\
    \    return ret >= mod ? ret - mod : ret;\n  }\n\n  static constexpr u32 get_mod()\
    \ { return mod; }\n};\n#line 2 \"ntt/ntt.hpp\"\n\ntemplate <typename mint>\nstruct\
    \ NTT {\n  static constexpr uint32_t get_pr() {\n    uint32_t _mod = mint::get_mod();\n\
    \    using u64 = uint64_t;\n    u64 ds[32] = {};\n    int idx = 0;\n    u64 m\
    \ = _mod - 1;\n    for (u64 i = 2; i * i <= m; ++i) {\n      if (m % i == 0) {\n\
    \        ds[idx++] = i;\n        while (m % i == 0) m /= i;\n      }\n    }\n\
    \    if (m != 1) ds[idx++] = m;\n\n    uint32_t _pr = 2;\n    while (1) {\n  \
    \    int flg = 1;\n      for (int i = 0; i < idx; ++i) {\n        u64 a = _pr,\
    \ b = (_mod - 1) / ds[i], r = 1;\n        while (b) {\n          if (b & 1) r\
    \ = r * a % _mod;\n          a = a * a % _mod;\n          b >>= 1;\n        }\n\
    \        if (r == 1) {\n          flg = 0;\n          break;\n        }\n    \
    \  }\n      if (flg == 1) break;\n      ++_pr;\n    }\n    return _pr;\n  };\n\
    \n  static constexpr uint32_t mod = mint::get_mod();\n  static constexpr uint32_t\
    \ pr = get_pr();\n  static constexpr int level = __builtin_ctzll(mod - 1);\n \
    \ mint dw[level], dy[level];\n\n  void setwy(int k) {\n    mint w[level], y[level];\n\
    \    w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));\n    y[k - 1] = w[k - 1].inverse();\n\
    \    for (int i = k - 2; i > 0; --i)\n      w[i] = w[i + 1] * w[i + 1], y[i] =\
    \ y[i + 1] * y[i + 1];\n    dw[1] = w[1], dy[1] = y[1], dw[2] = w[2], dy[2] =\
    \ y[2];\n    for (int i = 3; i < k; ++i) {\n      dw[i] = dw[i - 1] * y[i - 2]\
    \ * w[i];\n      dy[i] = dy[i - 1] * w[i - 2] * y[i];\n    }\n  }\n\n  NTT() {\
    \ setwy(level); }\n\n  void fft4(vector<mint> &a, int k) {\n    if ((int)a.size()\
    \ <= 1) return;\n    if (k == 1) {\n      mint a1 = a[1];\n      a[1] = a[0] -\
    \ a[1];\n      a[0] = a[0] + a1;\n      return;\n    }\n    if (k & 1) {\n   \
    \   int v = 1 << (k - 1);\n      for (int j = 0; j < v; ++j) {\n        mint ajv\
    \ = a[j + v];\n        a[j + v] = a[j] - ajv;\n        a[j] += ajv;\n      }\n\
    \    }\n    int u = 1 << (2 + (k & 1));\n    int v = 1 << (k - 2 - (k & 1));\n\
    \    mint one = mint(1);\n    mint imag = dw[1];\n    while (v) {\n      // jh\
    \ = 0\n      {\n        int j0 = 0;\n        int j1 = v;\n        int j2 = j1\
    \ + v;\n        int j3 = j2 + v;\n        for (; j0 < v; ++j0, ++j1, ++j2, ++j3)\
    \ {\n          mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];\n        \
    \  mint t0p2 = t0 + t2, t1p3 = t1 + t3;\n          mint t0m2 = t0 - t2, t1m3 =\
    \ (t1 - t3) * imag;\n          a[j0] = t0p2 + t1p3, a[j1] = t0p2 - t1p3;\n   \
    \       a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;\n        }\n      }\n      //\
    \ jh >= 1\n      mint ww = one, xx = one * dw[2], wx = one;\n      for (int jh\
    \ = 4; jh < u;) {\n        ww = xx * xx, wx = ww * xx;\n        int j0 = jh *\
    \ v;\n        int je = j0 + v;\n        int j2 = je + v;\n        for (; j0 <\
    \ je; ++j0, ++j2) {\n          mint t0 = a[j0], t1 = a[j0 + v] * xx, t2 = a[j2]\
    \ * ww,\n               t3 = a[j2 + v] * wx;\n          mint t0p2 = t0 + t2, t1p3\
    \ = t1 + t3;\n          mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;\n      \
    \    a[j0] = t0p2 + t1p3, a[j0 + v] = t0p2 - t1p3;\n          a[j2] = t0m2 + t1m3,\
    \ a[j2 + v] = t0m2 - t1m3;\n        }\n        xx *= dw[__builtin_ctzll((jh +=\
    \ 4))];\n      }\n      u <<= 2;\n      v >>= 2;\n    }\n  }\n\n  void ifft4(vector<mint>\
    \ &a, int k) {\n    if ((int)a.size() <= 1) return;\n    if (k == 1) {\n     \
    \ mint a1 = a[1];\n      a[1] = a[0] - a[1];\n      a[0] = a[0] + a1;\n      return;\n\
    \    }\n    int u = 1 << (k - 2);\n    int v = 1;\n    mint one = mint(1);\n \
    \   mint imag = dy[1];\n    while (u) {\n      // jh = 0\n      {\n        int\
    \ j0 = 0;\n        int j1 = v;\n        int j2 = v + v;\n        int j3 = j2 +\
    \ v;\n        for (; j0 < v; ++j0, ++j1, ++j2, ++j3) {\n          mint t0 = a[j0],\
    \ t1 = a[j1], t2 = a[j2], t3 = a[j3];\n          mint t0p1 = t0 + t1, t2p3 = t2\
    \ + t3;\n          mint t0m1 = t0 - t1, t2m3 = (t2 - t3) * imag;\n          a[j0]\
    \ = t0p1 + t2p3, a[j2] = t0p1 - t2p3;\n          a[j1] = t0m1 + t2m3, a[j3] =\
    \ t0m1 - t2m3;\n        }\n      }\n      // jh >= 1\n      mint ww = one, xx\
    \ = one * dy[2], yy = one;\n      u <<= 2;\n      for (int jh = 4; jh < u;) {\n\
    \        ww = xx * xx, yy = xx * imag;\n        int j0 = jh * v;\n        int\
    \ je = j0 + v;\n        int j2 = je + v;\n        for (; j0 < je; ++j0, ++j2)\
    \ {\n          mint t0 = a[j0], t1 = a[j0 + v], t2 = a[j2], t3 = a[j2 + v];\n\
    \          mint t0p1 = t0 + t1, t2p3 = t2 + t3;\n          mint t0m1 = (t0 - t1)\
    \ * xx, t2m3 = (t2 - t3) * yy;\n          a[j0] = t0p1 + t2p3, a[j2] = (t0p1 -\
    \ t2p3) * ww;\n          a[j0 + v] = t0m1 + t2m3, a[j2 + v] = (t0m1 - t2m3) *\
    \ ww;\n        }\n        xx *= dy[__builtin_ctzll(jh += 4)];\n      }\n     \
    \ u >>= 4;\n      v <<= 2;\n    }\n    if (k & 1) {\n      u = 1 << (k - 1);\n\
    \      for (int j = 0; j < u; ++j) {\n        mint ajv = a[j] - a[j + u];\n  \
    \      a[j] += a[j + u];\n        a[j + u] = ajv;\n      }\n    }\n  }\n\n  void\
    \ ntt(vector<mint> &a) {\n    if ((int)a.size() <= 1) return;\n    fft4(a, __builtin_ctz(a.size()));\n\
    \  }\n\n  void intt(vector<mint> &a) {\n    if ((int)a.size() <= 1) return;\n\
    \    ifft4(a, __builtin_ctz(a.size()));\n    mint iv = mint(a.size()).inverse();\n\
    \    for (auto &x : a) x *= iv;\n  }\n\n  vector<mint> multiply(const vector<mint>\
    \ &a, const vector<mint> &b) {\n    int l = a.size() + b.size() - 1;\n    if (min<int>(a.size(),\
    \ b.size()) <= 40) {\n      vector<mint> s(l);\n      for (int i = 0; i < (int)a.size();\
    \ ++i)\n        for (int j = 0; j < (int)b.size(); ++j) s[i + j] += a[i] * b[j];\n\
    \      return s;\n    }\n    int k = 2, M = 4;\n    while (M < l) M <<= 1, ++k;\n\
    \    setwy(k);\n    vector<mint> s(M), t(M);\n    for (int i = 0; i < (int)a.size();\
    \ ++i) s[i] = a[i];\n    for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i];\n\
    \    fft4(s, k);\n    fft4(t, k);\n    for (int i = 0; i < M; ++i) s[i] *= t[i];\n\
    \    ifft4(s, k);\n    s.resize(l);\n    mint invm = mint(M).inverse();\n    for\
    \ (int i = 0; i < l; ++i) s[i] *= invm;\n    return s;\n  }\n\n  void ntt_doubling(vector<mint>\
    \ &a) {\n    int M = (int)a.size();\n    auto b = a;\n    intt(b);\n    mint r\
    \ = 1, zeta = mint(pr).pow((mint::get_mod() - 1) / (M << 1));\n    for (int i\
    \ = 0; i < M; i++) b[i] *= r, r *= zeta;\n    ntt(b);\n    copy(begin(b), end(b),\
    \ back_inserter(a));\n  }\n};\n#line 5 \"ntt/arbitrary-ntt.hpp\"\n\nnamespace\
    \ ArbitraryNTT {\nusing i64 = int64_t;\nusing u128 = __uint128_t;\nconstexpr int32_t\
    \ m0 = 167772161;\nconstexpr int32_t m1 = 469762049;\nconstexpr int32_t m2 = 754974721;\n\
    using mint0 = LazyMontgomeryModInt<m0>;\nusing mint1 = LazyMontgomeryModInt<m1>;\n\
    using mint2 = LazyMontgomeryModInt<m2>;\nconstexpr int r01 = mint1(m0).inverse().get();\n\
    constexpr int r02 = mint2(m0).inverse().get();\nconstexpr int r12 = mint2(m1).inverse().get();\n\
    constexpr int r02r12 = i64(r02) * r12 % m2;\nconstexpr i64 w1 = m0;\nconstexpr\
    \ i64 w2 = i64(m0) * m1;\n\ntemplate <typename T, typename submint>\nvector<submint>\
    \ mul(const vector<T> &a, const vector<T> &b) {\n  static NTT<submint> ntt;\n\
    \  vector<submint> s(a.size()), t(b.size());\n  for (int i = 0; i < (int)a.size();\
    \ ++i) s[i] = i64(a[i] % submint::get_mod());\n  for (int i = 0; i < (int)b.size();\
    \ ++i) t[i] = i64(b[i] % submint::get_mod());\n  return ntt.multiply(s, t);\n\
    }\n\ntemplate <typename T>\nvector<int> multiply(const vector<T> &s, const vector<T>\
    \ &t, int mod) {\n  auto d0 = mul<T, mint0>(s, t);\n  auto d1 = mul<T, mint1>(s,\
    \ t);\n  auto d2 = mul<T, mint2>(s, t);\n  int n = d0.size();\n  vector<int> ret(n);\n\
    \  const int W1 = w1 % mod;\n  const int W2 = w2 % mod;\n  for (int i = 0; i <\
    \ n; i++) {\n    int n1 = d1[i].get(), n2 = d2[i].get(), a = d0[i].get();\n  \
    \  int b = i64(n1 + m1 - a) * r01 % m1;\n    int c = (i64(n2 + m2 - a) * r02r12\
    \ + i64(m2 - b) * r12) % m2;\n    ret[i] = (i64(a) + i64(b) * W1 + i64(c) * W2)\
    \ % mod;\n  }\n  return ret;\n}\n\ntemplate <typename mint>\nvector<mint> multiply(const\
    \ vector<mint> &a, const vector<mint> &b) {\n  if (a.size() == 0 && b.size() ==\
    \ 0) return {};\n  if (min<int>(a.size(), b.size()) < 128) {\n    vector<mint>\
    \ ret(a.size() + b.size() - 1);\n    for (int i = 0; i < (int)a.size(); ++i)\n\
    \      for (int j = 0; j < (int)b.size(); ++j) ret[i + j] += a[i] * b[j];\n  \
    \  return ret;\n  }\n  vector<int> s(a.size()), t(b.size());\n  for (int i = 0;\
    \ i < (int)a.size(); ++i) s[i] = a[i].get();\n  for (int i = 0; i < (int)b.size();\
    \ ++i) t[i] = b[i].get();\n  vector<int> u = multiply<int>(s, t, mint::get_mod());\n\
    \  vector<mint> ret(u.size());\n  for (int i = 0; i < (int)u.size(); ++i) ret[i]\
    \ = mint(u[i]);\n  return ret;\n}\n\ntemplate <typename T>\nvector<u128> multiply_u128(const\
    \ vector<T> &s, const vector<T> &t) {\n  if (s.size() == 0 && t.size() == 0) return\
    \ {};\n  if (min<int>(s.size(), t.size()) < 128) {\n    vector<u128> ret(s.size()\
    \ + t.size() - 1);\n    for (int i = 0; i < (int)s.size(); ++i)\n      for (int\
    \ j = 0; j < (int)t.size(); ++j) ret[i + j] += i64(s[i]) * t[j];\n    return ret;\n\
    \  }\n  auto d0 = mul<T, mint0>(s, t);\n  auto d1 = mul<T, mint1>(s, t);\n  auto\
    \ d2 = mul<T, mint2>(s, t);\n  int n = d0.size();\n  vector<u128> ret(n);\n  for\
    \ (int i = 0; i < n; i++) {\n    i64 n1 = d1[i].get(), n2 = d2[i].get();\n   \
    \ i64 a = d0[i].get();\n    i64 b = (n1 + m1 - a) * r01 % m1;\n    i64 c = ((n2\
    \ + m2 - a) * r02r12 + (m2 - b) * r12) % m2;\n    ret[i] = a + b * w1 + u128(c)\
    \ * w2;\n  }\n  return ret;\n}\n}  // namespace ArbitraryNTT\n#line 13 \"math/bigint.hpp\"\
    \n\nnamespace MultiPrecisionIntegerImpl {\nstruct TENS {\n  static constexpr int\
    \ offset = 30;\n  constexpr TENS() : _tend() {\n    _tend[offset] = 1;\n    for\
    \ (int i = 1; i <= offset; i++) {\n      _tend[offset + i] = _tend[offset + i\
    \ - 1] * 10.0;\n      _tend[offset - i] = 1.0 / _tend[offset + i];\n    }\n  }\n\
    \  long double ten_ld(int n) const {\n    assert(-offset <= n and n <= offset);\n\
    \    return _tend[n + offset];\n  }\n\n private:\n  long double _tend[offset *\
    \ 2 + 1];\n};\n}  // namespace MultiPrecisionIntegerImpl\n\n// 0 \u306F neg=false,\
    \ dat={} \u3068\u3057\u3066\u6271\u3046\nstruct MultiPrecisionInteger {\n  using\
    \ M = MultiPrecisionInteger;\n  inline constexpr static MultiPrecisionIntegerImpl::TENS\
    \ tens = {};\n\n  static constexpr int D = 1000000000;\n  static constexpr int\
    \ logD = 9;\n  bool neg;\n  vector<int> dat;\n\n  MultiPrecisionInteger() : neg(false),\
    \ dat() {}\n\n  MultiPrecisionInteger(bool n, const vector<int>& d) : neg(n),\
    \ dat(d) {}\n\n  template <typename I, enable_if_t<is_integral_v<I> ||\n     \
    \                               is_same_v<I, __int128_t>>* = nullptr>\n  MultiPrecisionInteger(I\
    \ x) : neg(false) {\n    if constexpr (is_signed_v<I> || is_same_v<I, __int128_t>)\
    \ {\n      if (x < 0) neg = true, x = -x;\n    }\n    while (x) dat.push_back(x\
    \ % D), x /= D;\n  }\n\n  MultiPrecisionInteger(const string& S) : neg(false)\
    \ {\n    assert(!S.empty());\n    if (S.size() == 1u && S[0] == '0') return;\n\
    \    int l = 0;\n    if (S[0] == '-') ++l, neg = true;\n    for (int ie = S.size();\
    \ l < ie; ie -= logD) {\n      int is = max(l, ie - logD);\n      long long x\
    \ = 0;\n      for (int i = is; i < ie; i++) x = x * 10 + S[i] - '0';\n      dat.push_back(x);\n\
    \    }\n  }\n\n  friend M operator+(const M& lhs, const M& rhs) {\n    if (lhs.neg\
    \ == rhs.neg) return {lhs.neg, _add(lhs.dat, rhs.dat)};\n    if (_leq(lhs.dat,\
    \ rhs.dat)) {\n      // |l| <= |r|\n      auto c = _sub(rhs.dat, lhs.dat);\n \
    \     bool n = _is_zero(c) ? false : rhs.neg;\n      return {n, c};\n    }\n \
    \   auto c = _sub(lhs.dat, rhs.dat);\n    bool n = _is_zero(c) ? false : lhs.neg;\n\
    \    return {n, c};\n  }\n  friend M operator-(const M& lhs, const M& rhs) { return\
    \ lhs + (-rhs); }\n\n  friend M operator*(const M& lhs, const M& rhs) {\n    auto\
    \ c = _mul(lhs.dat, rhs.dat);\n    bool n = _is_zero(c) ? false : (lhs.neg ^ rhs.neg);\n\
    \    return {n, c};\n  }\n  friend pair<M, M> divmod(const M& lhs, const M& rhs)\
    \ {\n    auto dm = _divmod_newton(lhs.dat, rhs.dat);\n    bool dn = _is_zero(dm.first)\
    \ ? false : lhs.neg != rhs.neg;\n    bool mn = _is_zero(dm.second) ? false : lhs.neg;\n\
    \    return {M{dn, dm.first}, M{mn, dm.second}};\n  }\n  friend M operator/(const\
    \ M& lhs, const M& rhs) {\n    return divmod(lhs, rhs).first;\n  }\n  friend M\
    \ operator%(const M& lhs, const M& rhs) {\n    return divmod(lhs, rhs).second;\n\
    \  }\n\n  M& operator+=(const M& rhs) { return (*this) = (*this) + rhs; }\n  M&\
    \ operator-=(const M& rhs) { return (*this) = (*this) - rhs; }\n  M& operator*=(const\
    \ M& rhs) { return (*this) = (*this) * rhs; }\n  M& operator/=(const M& rhs) {\
    \ return (*this) = (*this) / rhs; }\n  M& operator%=(const M& rhs) { return (*this)\
    \ = (*this) % rhs; }\n\n  M operator-() const {\n    if (is_zero()) return *this;\n\
    \    return {!neg, dat};\n  }\n  M operator+() const { return *this; }\n  friend\
    \ M abs(const M& m) { return {false, m.dat}; }\n  bool is_zero() const { return\
    \ _is_zero(dat); }\n\n  friend bool operator==(const M& lhs, const M& rhs) {\n\
    \    return lhs.neg == rhs.neg && lhs.dat == rhs.dat;\n  }\n  friend bool operator!=(const\
    \ M& lhs, const M& rhs) {\n    return lhs.neg != rhs.neg || lhs.dat != rhs.dat;\n\
    \  }\n  friend bool operator<(const M& lhs, const M& rhs) {\n    if (lhs == rhs)\
    \ return false;\n    return _neq_lt(lhs, rhs);\n  }\n  friend bool operator<=(const\
    \ M& lhs, const M& rhs) {\n    if (lhs == rhs) return true;\n    return _neq_lt(lhs,\
    \ rhs);\n  }\n  friend bool operator>(const M& lhs, const M& rhs) {\n    if (lhs\
    \ == rhs) return false;\n    return _neq_lt(rhs, lhs);\n  }\n  friend bool operator>=(const\
    \ M& lhs, const M& rhs) {\n    if (lhs == rhs) return true;\n    return _neq_lt(rhs,\
    \ lhs);\n  }\n\n  // a * 10^b (1 <= |a| < 10) \u306E\u5F62\u3067\u6E21\u3059\n\
    \  // \u76F8\u5BFE\u8AA4\u5DEE\uFF1A10^{-16} ~ 10^{-19} \u7A0B\u5EA6 (\u51E6\u7406\
    \u7CFB\u4F9D\u5B58)\n  pair<long double, int> dfp() const {\n    if (is_zero())\
    \ return {0, 0};\n    int l = max<int>(0, _size() - 3);\n    int b = logD * l;\n\
    \    string prefix{};\n    for (int i = _size() - 1; i >= l; i--) {\n      prefix\
    \ += _itos(dat[i], i != _size() - 1);\n    }\n    b += prefix.size() - 1;\n  \
    \  long double a = 0;\n    for (auto& c : prefix) a = a * 10.0 + (c - '0');\n\
    \    a *= tens.ten_ld(-((int)prefix.size()) + 1);\n    a = clamp<long double>(a,\
    \ 1.0, nextafterl(10.0, 1.0));\n    if (neg) a = -a;\n    return {a, b};\n  }\n\
    \  string to_string() const {\n    if (is_zero()) return \"0\";\n    string res;\n\
    \    if (neg) res.push_back('-');\n    for (int i = _size() - 1; i >= 0; i--)\
    \ {\n      res += _itos(dat[i], i != _size() - 1);\n    }\n    return res;\n \
    \ }\n  long double to_ld() const {\n    auto [a, b] = dfp();\n    if (-tens.offset\
    \ <= b and b <= tens.offset) {\n      return a * tens.ten_ld(b);\n    }\n    return\
    \ a * powl(10, b);\n  }\n  long long to_ll() const {\n    long long res = _to_ll(dat);\n\
    \    return neg ? -res : res;\n  }\n  __int128_t to_i128() const {\n    __int128_t\
    \ res = _to_i128(dat);\n    return neg ? -res : res;\n  }\n\n  friend istream&\
    \ operator>>(istream& is, M& m) {\n    string s;\n    is >> s;\n    m = M{s};\n\
    \    return is;\n  }\n\n  friend ostream& operator<<(ostream& os, const M& m)\
    \ {\n    return os << m.to_string();\n  }\n\n  // \u5185\u90E8\u306E\u95A2\u6570\
    \u3092\u30C6\u30B9\u30C8\n  static void _test_private_function(const M&, const\
    \ M&);\n\n private:\n  // size\n  int _size() const { return dat.size(); }\n \
    \ // a == b\n  static bool _eq(const vector<int>& a, const vector<int>& b) { return\
    \ a == b; }\n  // a < b\n  static bool _lt(const vector<int>& a, const vector<int>&\
    \ b) {\n    if (a.size() != b.size()) return a.size() < b.size();\n    for (int\
    \ i = a.size() - 1; i >= 0; i--) {\n      if (a[i] != b[i]) return a[i] < b[i];\n\
    \    }\n    return false;\n  }\n  // a <= b\n  static bool _leq(const vector<int>&\
    \ a, const vector<int>& b) {\n    return _eq(a, b) || _lt(a, b);\n  }\n  // a\
    \ < b (s.t. a != b)\n  static bool _neq_lt(const M& lhs, const M& rhs) {\n   \
    \ assert(lhs != rhs);\n    if (lhs.neg != rhs.neg) return lhs.neg;\n    bool f\
    \ = _lt(lhs.dat, rhs.dat);\n    if (f) return !lhs.neg;\n    return lhs.neg;\n\
    \  }\n  // a == 0\n  static bool _is_zero(const vector<int>& a) { return a.empty();\
    \ }\n  // a == 1\n  static bool _is_one(const vector<int>& a) {\n    return (int)a.size()\
    \ == 1 && a[0] == 1;\n  }\n  // \u672B\u5C3E 0 \u3092\u524A\u9664\n  static void\
    \ _shrink(vector<int>& a) {\n    while (a.size() && a.back() == 0) a.pop_back();\n\
    \  }\n  // \u672B\u5C3E 0 \u3092\u524A\u9664\n  void _shrink() {\n    while (_size()\
    \ && dat.back() == 0) dat.pop_back();\n  }\n  // a + b\n  static vector<int> _add(const\
    \ vector<int>& a, const vector<int>& b) {\n    vector<int> c(max(a.size(), b.size())\
    \ + 1);\n    for (int i = 0; i < (int)a.size(); i++) c[i] += a[i];\n    for (int\
    \ i = 0; i < (int)b.size(); i++) c[i] += b[i];\n    for (int i = 0; i < (int)c.size()\
    \ - 1; i++) {\n      if (c[i] >= D) c[i] -= D, c[i + 1]++;\n    }\n    _shrink(c);\n\
    \    return c;\n  }\n  // a - b\n  static vector<int> _sub(const vector<int>&\
    \ a, const vector<int>& b) {\n    assert(_leq(b, a));\n    vector<int> c{a};\n\
    \    int borrow = 0;\n    for (int i = 0; i < (int)a.size(); i++) {\n      if\
    \ (i < (int)b.size()) borrow += b[i];\n      c[i] -= borrow;\n      borrow = 0;\n\
    \      if (c[i] < 0) c[i] += D, borrow = 1;\n    }\n    assert(borrow == 0);\n\
    \    _shrink(c);\n    return c;\n  }\n  // a * b (fft)\n  static vector<int> _mul_fft(const\
    \ vector<int>& a, const vector<int>& b) {\n    if (a.empty() || b.empty()) return\
    \ {};\n    auto m = ArbitraryNTT::multiply_u128(a, b);\n    vector<int> c;\n \
    \   c.reserve(m.size() + 3);\n    __uint128_t x = 0;\n    for (int i = 0;; i++)\
    \ {\n      if (i >= (int)m.size() && x == 0) break;\n      if (i < (int)m.size())\
    \ x += m[i];\n      c.push_back(x % D);\n      x /= D;\n    }\n    _shrink(c);\n\
    \    return c;\n  }\n  // a * b (naive)\n  static vector<int> _mul_naive(const\
    \ vector<int>& a, const vector<int>& b) {\n    if (a.empty() || b.empty()) return\
    \ {};\n    vector<long long> prod(a.size() + b.size() - 1 + 1);\n    for (int\
    \ i = 0; i < (int)a.size(); i++) {\n      for (int j = 0; j < (int)b.size(); j++)\
    \ {\n        long long p = 1LL * a[i] * b[j];\n        prod[i + j] += p;\n   \
    \     if (prod[i + j] >= (4LL * D * D)) {\n          prod[i + j] -= 4LL * D *\
    \ D;\n          prod[i + j + 1] += 4LL * D;\n        }\n      }\n    }\n    vector<int>\
    \ c(prod.size() + 1);\n    long long x = 0;\n    int i = 0;\n    for (; i < (int)prod.size();\
    \ i++) x += prod[i], c[i] = x % D, x /= D;\n    while (x) c[i] = x % D, x /= D,\
    \ i++;\n    _shrink(c);\n    return c;\n  }\n  // a * b\n  static vector<int>\
    \ _mul(const vector<int>& a, const vector<int>& b) {\n    if (_is_zero(a) || _is_zero(b))\
    \ return {};\n    if (_is_one(a)) return b;\n    if (_is_one(b)) return a;\n \
    \   if (min<int>(a.size(), b.size()) <= 128) {\n      return a.size() < b.size()\
    \ ? _mul_naive(b, a) : _mul_naive(a, b);\n    }\n    return _mul_fft(a, b);\n\
    \  }\n  // 0 <= A < 1e18, 1 <= B < 1e9\n  static pair<vector<int>, vector<int>>\
    \ _divmod_li(const vector<int>& a,\n                                         \
    \          const vector<int>& b) {\n    assert(0 <= (int)a.size() && (int)a.size()\
    \ <= 2);\n    assert((int)b.size() == 1);\n    long long va = _to_ll(a);\n   \
    \ int vb = b[0];\n    return {_integer_to_vec(va / vb), _integer_to_vec(va % vb)};\n\
    \  }\n  // 0 <= A < 1e18, 1 <= B < 1e18\n  static pair<vector<int>, vector<int>>\
    \ _divmod_ll(const vector<int>& a,\n                                         \
    \          const vector<int>& b) {\n    assert(0 <= (int)a.size() && (int)a.size()\
    \ <= 2);\n    assert(1 <= (int)b.size() && (int)b.size() <= 2);\n    long long\
    \ va = _to_ll(a), vb = _to_ll(b);\n    return {_integer_to_vec(va / vb), _integer_to_vec(va\
    \ % vb)};\n  }\n  // 1 <= B < 1e9\n  static pair<vector<int>, vector<int>> _divmod_1e9(const\
    \ vector<int>& a,\n                                                    const vector<int>&\
    \ b) {\n    assert((int)b.size() == 1);\n    if (b[0] == 1) return {a, {}};\n\
    \    if ((int)a.size() <= 2) return _divmod_li(a, b);\n    vector<int> quo(a.size());\n\
    \    long long d = 0;\n    int b0 = b[0];\n    for (int i = a.size() - 1; i >=\
    \ 0; i--) {\n      d = d * D + a[i];\n      assert(d < 1LL * D * b0);\n      int\
    \ q = d / b0, r = d % b0;\n      quo[i] = q, d = r;\n    }\n    _shrink(quo);\n\
    \    return {quo, d ? vector<int>{int(d)} : vector<int>{}};\n  }\n  // 0 <= A,\
    \ 1 <= B\n  static pair<vector<int>, vector<int>> _divmod_naive(const vector<int>&\
    \ a,\n                                                      const vector<int>&\
    \ b) {\n    if (_is_zero(b)) {\n      cerr << \"Divide by Zero Exception\" <<\
    \ endl;\n      exit(1);\n    }\n    assert(1 <= (int)b.size());\n    if ((int)b.size()\
    \ == 1) return _divmod_1e9(a, b);\n    if (max<int>(a.size(), b.size()) <= 2)\
    \ return _divmod_ll(a, b);\n    if (_lt(a, b)) return {{}, a};\n    // B >= 1e9,\
    \ A >= B\n    int norm = D / (b.back() + 1);\n    vector<int> x = _mul(a, {norm});\n\
    \    vector<int> y = _mul(b, {norm});\n    int yb = y.back();\n    vector<int>\
    \ quo(x.size() - y.size() + 1);\n    vector<int> rem(x.end() - y.size(), x.end());\n\
    \    for (int i = quo.size() - 1; i >= 0; i--) {\n      if (rem.size() < y.size())\
    \ {\n        // do nothing\n      } else if (rem.size() == y.size()) {\n     \
    \   if (_leq(y, rem)) {\n          quo[i] = 1, rem = _sub(rem, y);\n        }\n\
    \      } else {\n        assert(y.size() + 1 == rem.size());\n        long long\
    \ rb = 1LL * rem[rem.size() - 1] * D + rem[rem.size() - 2];\n        int q = rb\
    \ / yb;\n        vector<int> yq = _mul(y, {q});\n        // \u771F\u306E\u5546\
    \u306F q-2 \u4EE5\u4E0A q+1 \u4EE5\u4E0B\u3060\u304C\u81EA\u4FE1\u304C\u7121\u3044\
    \u306E\u3067\u5FF5\u306E\u305F\u3081 while \u3092\u56DE\u3059\n        while (_lt(rem,\
    \ yq)) q--, yq = _sub(yq, y);\n        rem = _sub(rem, yq);\n        while (_leq(y,\
    \ rem)) q++, rem = _sub(rem, y);\n        quo[i] = q;\n      }\n      if (i) rem.insert(begin(rem),\
    \ x[i - 1]);\n    }\n    _shrink(quo), _shrink(rem);\n    auto [q2, r2] = _divmod_1e9(rem,\
    \ {norm});\n    assert(_is_zero(r2));\n    return {quo, q2};\n  }\n\n  // 0 <=\
    \ A, 1 <= B\n  static pair<vector<int>, vector<int>> _divmod_dc(const vector<int>&\
    \ a,\n                                                   const vector<int>& b);\n\
    \n  // 1 / a \u3092 \u7D76\u5BFE\u8AA4\u5DEE B^{-deg} \u3067\u6C42\u3081\u308B\
    \n  static vector<int> _calc_inv(const vector<int>& a, int deg) {\n    assert(!a.empty()\
    \ && D / 2 <= a.back() and a.back() < D);\n    int k = deg, c = a.size();\n  \
    \  while (k > 64) k = (k + 1) / 2;\n    vector<int> z(c + k + 1);\n    z.back()\
    \ = 1;\n    z = _divmod_naive(z, a).first;\n    while (k < deg) {\n      vector<int>\
    \ s = _mul(z, z);\n      s.insert(begin(s), 0);\n      int d = min(c, 2 * k +\
    \ 1);\n      vector<int> t{end(a) - d, end(a)}, u = _mul(s, t);\n      u.erase(begin(u),\
    \ begin(u) + d);\n      vector<int> w(k + 1), w2 = _add(z, z);\n      copy(begin(w2),\
    \ end(w2), back_inserter(w));\n      z = _sub(w, u);\n      z.erase(begin(z));\n\
    \      k *= 2;\n    }\n    z.erase(begin(z), begin(z) + k - deg);\n    return\
    \ z;\n  }\n\n  static pair<vector<int>, vector<int>> _divmod_newton(const vector<int>&\
    \ a,\n                                                       const vector<int>&\
    \ b) {\n    if (_is_zero(b)) {\n      cerr << \"Divide by Zero Exception\" <<\
    \ endl;\n      exit(1);\n    }\n    if ((int)b.size() <= 64) return _divmod_naive(a,\
    \ b);\n    if ((int)a.size() - (int)b.size() <= 64) return _divmod_naive(a, b);\n\
    \    int norm = D / (b.back() + 1);\n    vector<int> x = _mul(a, {norm});\n  \
    \  vector<int> y = _mul(b, {norm});\n    int s = x.size(), t = y.size();\n   \
    \ int deg = s - t + 2;\n    vector<int> z = _calc_inv(y, deg);\n    vector<int>\
    \ q = _mul(x, z);\n    q.erase(begin(q), begin(q) + t + deg);\n    vector<int>\
    \ yq = _mul(y, {q});\n    while (_lt(x, yq)) q = _sub(q, {1}), yq = _sub(yq, y);\n\
    \    vector<int> r = _sub(x, yq);\n    while (_leq(y, r)) q = _add(q, {1}), r\
    \ = _sub(r, y);\n    _shrink(q), _shrink(r);\n    auto [q2, r2] = _divmod_1e9(r,\
    \ {norm});\n    assert(_is_zero(r2));\n    return {q, q2};\n  }\n\n  // int ->\
    \ string\n  // \u5148\u982D\u304B\u3069\u3046\u304B\u306B\u5FDC\u3058\u3066 zero\
    \ padding \u3059\u308B\u304B\u3092\u6C7A\u3081\u308B\n  static string _itos(int\
    \ x, bool zero_padding) {\n    assert(0 <= x && x < D);\n    string res;\n   \
    \ for (int i = 0; i < logD; i++) {\n      res.push_back('0' + x % 10), x /= 10;\n\
    \    }\n    if (!zero_padding) {\n      while (res.size() && res.back() == '0')\
    \ res.pop_back();\n      assert(!res.empty());\n    }\n    reverse(begin(res),\
    \ end(res));\n    return res;\n  }\n\n  // convert ll to vec\n  template <typename\
    \ I, enable_if_t<is_integral_v<I> ||\n                                    is_same_v<I,\
    \ __int128_t>>* = nullptr>\n  static vector<int> _integer_to_vec(I x) {\n    if\
    \ constexpr (is_signed_v<I> || is_same_v<I, __int128_t>) {\n      assert(x >=\
    \ 0);\n    }\n    vector<int> res;\n    while (x) res.push_back(x % D), x /= D;\n\
    \    return res;\n  }\n\n  static long long _to_ll(const vector<int>& a) {\n \
    \   long long res = 0;\n    for (int i = (int)a.size() - 1; i >= 0; i--) res =\
    \ res * D + a[i];\n    return res;\n  }\n\n  static __int128_t _to_i128(const\
    \ vector<int>& a) {\n    __int128_t res = 0;\n    for (int i = (int)a.size() -\
    \ 1; i >= 0; i--) res = res * D + a[i];\n    return res;\n  }\n\n  static void\
    \ _dump(const vector<int>& a, string s = \"\") {\n    if (!s.empty()) cerr <<\
    \ s << \" : \";\n    cerr << \"{ \";\n    for (int i = 0; i < (int)a.size(); i++)\
    \ cerr << a[i] << \", \";\n    cerr << \"}\" << endl;\n  }\n};\n\nusing bigint\
    \ = MultiPrecisionInteger;\n\n/**\n * @brief \u591A\u500D\u9577\u6574\u6570\n\
    \ */\n#line 3 \"math/bigint-garner.hpp\"\n\nnamespace GarnerImpl {\n\ntemplate\
    \ <typename T,\n          enable_if_t<is_integral_v<T> || is_same_v<T, __int128_t>>*\
    \ = nullptr>\nT inv_mod(T a, T m) {\n  assert(0 <= a);\n  if (a >= m) a %= m;\n\
    \  T b = m, s = 1, t = 0;\n  while (true) {\n    if (a == 1) return s;\n    t\
    \ -= b / a * s;\n    b %= a;\n    if (b == 1) return t + m;\n    s -= a / b *\
    \ t;\n    a %= b;\n  }\n}\n\npair<bigint, bigint> garner_dc(const vector<int>&\
    \ r, const vector<int>& m) {\n  int N = m.size();\n  if (N == 0) return {0, 1};\n\
    \  int B = 1;\n  while (B < N) B *= 2;\n  vector<bigint> tree(2 * B);\n  for (int\
    \ i = 0; i < B; i++) tree[B + i] = i < (int)m.size() ? m[i] : 1;\n  for (int i\
    \ = B - 1; i; i--) tree[i] = tree[i * 2 + 0] * tree[i * 2 + 1];\n  auto calc =\
    \ [&](auto&& rc, int ti, bigint X, bigint Y, int L,\n                  int R)\
    \ -> bigint {\n    if (N <= L) return 0;\n    X %= tree[ti], Y %= tree[ti];\n\
    \    if (L + 1 == R) {\n      int xl = X.to_ll(), yl = Y.to_ll();\n      int t\
    \ = (1LL * (r[L] - xl) * inv_mod(yl, m[L])) % m[L];\n      return t < 0 ? t +\
    \ m[L] : t;\n    }\n    auto& prod = tree[ti * 2 + 0];\n    int M = (L + R) /\
    \ 2;\n    auto xl = rc(rc, ti * 2 + 0, X, Y, L, M);\n    auto xr = rc(rc, ti *\
    \ 2 + 1, X + xl * Y, Y * prod, M, R);\n    return xl + xr * prod;\n  };\n  bigint\
    \ ans = calc(calc, 1, 0, 1, 0, B);\n  return {ans, tree[1]};\n}\n\npair<bigint,\
    \ bigint> garner_naive(const vector<int>& r, const vector<int>& m) {\n  int N\
    \ = r.size();\n  if (N == 0) return {0, 1};\n  vector<int> y(N), x(N), t(N);\n\
    \  for (int i = 0; i < N; i++) y[i] = 1 % m[i];\n  for (int i = 0; i < N; ++i)\
    \ {\n    t[i] = (1LL * (r[i] - x[i]) * inv_mod(y[i], m[i])) % m[i];\n    if (t[i]\
    \ < 0) t[i] += m[i];\n    for (int j = i + 1; j < N; j++) {\n      x[j] = (x[j]\
    \ + 1LL * y[j] * t[i]) % m[j];\n      y[j] = 1LL * y[j] * m[i] % m[j];\n    }\n\
    \  }\n  bigint ans = 0, mod = 1;\n  for (int i = N - 1; i >= 0; --i) ans = ans\
    \ * m[i] + t[i], mod *= m[i];\n  return {ans, mod};\n}\n\n// 1 <= m[i] <= 2 *\
    \ 10^9\n// m \u304C\u4E92\u3044\u306B\u7D20\u3067\u306A\u3044\u5834\u5408\uFF1A\
    \u672A\u5B9A\u7FA9\npair<bigint, bigint> garner_bigint(const vector<int>& r, const\
    \ vector<int>& m) {\n  assert(r.size() == m.size());\n  if ((int)m.size() <= 3000)\
    \ return garner_naive(r, m);\n  return garner_dc(r, m);\n}\n// 1 <= m[i] <= 2\
    \ * 10^9\n// m \u304C\u4E92\u3044\u306B\u7D20\u3067\u306A\u3044\u5834\u5408\uFF1A\
    \u672A\u5B9A\u7FA9\npair<bigint, bigint> crt_bigint(const vector<int>& r, const\
    \ vector<int>& m) {\n  return garner_bigint(r, m);\n}\n}  // namespace GarnerImpl\n\
    \nusing GarnerImpl::crt_bigint;\nusing GarnerImpl::garner_bigint;\n\n/**\n * @brief\
    \ Garner's algorithm for bigint\n */\n#line 6 \"verify/verify-unit-test/garner-bigint.test.cpp\"\
    \n//\n#line 2 \"modint/arbitrary-modint.hpp\"\n\n#line 2 \"modint/barrett-reduction.hpp\"\
    \n\n#line 4 \"modint/barrett-reduction.hpp\"\nusing namespace std;\n\nstruct Barrett\
    \ {\n  using u32 = unsigned int;\n  using i64 = long long;\n  using u64 = unsigned\
    \ long long;\n  u32 m;\n  u64 im;\n  Barrett() : m(), im() {}\n  Barrett(int n)\
    \ : m(n), im(u64(-1) / m + 1) {}\n  constexpr inline i64 quo(u64 n) {\n    u64\
    \ x = u64((__uint128_t(n) * im) >> 64);\n    u32 r = n - x * m;\n    return m\
    \ <= r ? x - 1 : x;\n  }\n  constexpr inline i64 rem(u64 n) {\n    u64 x = u64((__uint128_t(n)\
    \ * im) >> 64);\n    u32 r = n - x * m;\n    return m <= r ? r + m : r;\n  }\n\
    \  constexpr inline pair<i64, int> quorem(u64 n) {\n    u64 x = u64((__uint128_t(n)\
    \ * im) >> 64);\n    u32 r = n - x * m;\n    if (m <= r) return {x - 1, r + m};\n\
    \    return {x, r};\n  }\n  constexpr inline i64 pow(u64 n, i64 p) {\n    u32\
    \ a = rem(n), r = m == 1 ? 0 : 1;\n    while (p) {\n      if (p & 1) r = rem(u64(r)\
    \ * a);\n      a = rem(u64(a) * a);\n      p >>= 1;\n    }\n    return r;\n  }\n\
    };\n#line 4 \"modint/arbitrary-modint.hpp\"\n\nstruct ArbitraryModInt {\n  int\
    \ x;\n\n  ArbitraryModInt() : x(0) {}\n\n  ArbitraryModInt(int64_t y) {\n    int\
    \ z = y % get_mod();\n    if (z < 0) z += get_mod();\n    x = z;\n  }\n\n  ArbitraryModInt\
    \ &operator+=(const ArbitraryModInt &p) {\n    if ((x += p.x) >= get_mod()) x\
    \ -= get_mod();\n    return *this;\n  }\n\n  ArbitraryModInt &operator-=(const\
    \ ArbitraryModInt &p) {\n    if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();\n\
    \    return *this;\n  }\n\n  ArbitraryModInt &operator*=(const ArbitraryModInt\
    \ &p) {\n    x = rem((unsigned long long)x * p.x);\n    return *this;\n  }\n\n\
    \  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {\n    *this *= p.inverse();\n\
    \    return *this;\n  }\n\n  ArbitraryModInt operator-() const { return ArbitraryModInt(-x);\
    \ }\n\n  ArbitraryModInt operator+(const ArbitraryModInt &p) const {\n    return\
    \ ArbitraryModInt(*this) += p;\n  }\n\n  ArbitraryModInt operator-(const ArbitraryModInt\
    \ &p) const {\n    return ArbitraryModInt(*this) -= p;\n  }\n\n  ArbitraryModInt\
    \ operator*(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ *= p;\n  }\n\n  ArbitraryModInt operator/(const ArbitraryModInt &p) const {\n\
    \    return ArbitraryModInt(*this) /= p;\n  }\n\n  bool operator==(const ArbitraryModInt\
    \ &p) const { return x == p.x; }\n\n  bool operator!=(const ArbitraryModInt &p)\
    \ const { return x != p.x; }\n\n  ArbitraryModInt inverse() const {\n    int a\
    \ = x, b = get_mod(), u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n\
    \      swap(a -= t * b, b);\n      swap(u -= t * v, v);\n    }\n    return ArbitraryModInt(u);\n\
    \  }\n\n  ArbitraryModInt pow(int64_t n) const {\n    ArbitraryModInt ret(1),\
    \ mul(x);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n\
    \      n >>= 1;\n    }\n    return ret;\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const ArbitraryModInt &p) {\n    return os << p.x;\n  }\n\n  friend istream\
    \ &operator>>(istream &is, ArbitraryModInt &a) {\n    int64_t t;\n    is >> t;\n\
    \    a = ArbitraryModInt(t);\n    return (is);\n  }\n\n  int get() const { return\
    \ x; }\n\n  inline unsigned int rem(unsigned long long p) { return barrett().rem(p);\
    \ }\n\n  static inline Barrett &barrett() {\n    static Barrett b;\n    return\
    \ b;\n  }\n\n  static inline int &get_mod() {\n    static int mod = 0;\n    return\
    \ mod;\n  }\n\n  static void set_mod(int md) {\n    assert(0 < md && md <= (1LL\
    \ << 30) - 1);\n    get_mod() = md;\n    barrett() = Barrett(md);\n  }\n};\n#line\
    \ 8 \"verify/verify-unit-test/garner-bigint.test.cpp\"\n//\n#line 2 \"prime/fast-factorize.hpp\"\
    \n\n#line 2 \"inner/inner_math.hpp\"\n\nnamespace inner {\n\nusing i32 = int32_t;\n\
    using u32 = uint32_t;\nusing i64 = int64_t;\nusing u64 = uint64_t;\n\ntemplate\
    \ <typename T>\nT gcd(T a, T b) {\n  while (b) swap(a %= b, b);\n  return a;\n\
    }\n\ntemplate <typename T>\nT inv(T a, T p) {\n  T b = p, x = 1, y = 0;\n  while\
    \ (a) {\n    T q = b / a;\n    swap(a, b %= a);\n    swap(x, y -= q * x);\n  }\n\
    \  assert(b == 1);\n  return y < 0 ? y + p : y;\n}\n\ntemplate <typename T, typename\
    \ U>\nT modpow(T a, U n, T p) {\n  T ret = 1 % p;\n  for (; n; n >>= 1, a = U(a)\
    \ * a % p)\n    if (n & 1) ret = U(ret) * a % p;\n  return ret;\n}\n\n}  // namespace\
    \ inner\n#line 2 \"misc/rng.hpp\"\n\nnamespace my_rand {\nusing i64 = long long;\n\
    using u64 = unsigned long long;\n\n// [0, 2^64 - 1)\nu64 rng() {\n  static u64\
    \ _x =\n      u64(chrono::duration_cast<chrono::nanoseconds>(\n              chrono::high_resolution_clock::now().time_since_epoch())\n\
    \              .count()) *\n      10150724397891781847ULL;\n  _x ^= _x << 7;\n\
    \  return _x ^= _x >> 9;\n}\n\n// [l, r]\ni64 rng(i64 l, i64 r) {\n  assert(l\
    \ <= r);\n  return l + rng() % (r - l + 1);\n}\n\n// [l, r)\ni64 randint(i64 l,\
    \ i64 r) {\n  assert(l < r);\n  return l + rng() % (r - l);\n}\n\n// choose n\
    \ numbers from [l, r) without overlapping\nvector<i64> randset(i64 l, i64 r, i64\
    \ n) {\n  assert(l <= r && n <= r - l);\n  unordered_set<i64> s;\n  for (i64 i\
    \ = n; i; --i) {\n    i64 m = randint(l, r + 1 - i);\n    if (s.find(m) != s.end())\
    \ m = r - i;\n    s.insert(m);\n  }\n  vector<i64> ret;\n  for (auto& x : s) ret.push_back(x);\n\
    \  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() { return rng() * 5.42101086242752217004e-20;\
    \ }\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n\
    \  for (int i = 1; i < n; i++) swap(v[i], v[randint(0, i + 1)]);\n}\n\n}  // namespace\
    \ my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\nusing my_rand::randshf;\n\
    using my_rand::rnd;\nusing my_rand::rng;\n#line 2 \"modint/arbitrary-prime-modint.hpp\"\
    \n\n\n\nstruct ArbitraryLazyMontgomeryModInt {\n  using mint = ArbitraryLazyMontgomeryModInt;\n\
    \  using i32 = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n\
    \  static u32 mod;\n  static u32 r;\n  static u32 n2;\n\n  static u32 get_r()\
    \ {\n    u32 ret = mod;\n    for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n\
    \    return ret;\n  }\n\n  static void set_mod(u32 m) {\n    assert(m < (1 <<\
    \ 30));\n    assert((m & 1) == 1);\n    mod = m;\n    n2 = -u64(m) % m;\n    r\
    \ = get_r();\n    assert(r * mod == 1);\n  }\n\n  u32 a;\n\n  ArbitraryLazyMontgomeryModInt()\
    \ : a(0) {}\n  ArbitraryLazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b\
    \ % mod + mod) * n2)){};\n\n  static u32 reduce(const u64 &b) {\n    return (b\
    \ + u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  mint &operator+=(const mint\
    \ &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n\
    \  }\n\n  mint &operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2\
    \ * mod;\n    return *this;\n  }\n\n  mint &operator*=(const mint &b) {\n    a\
    \ = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  mint &operator/=(const\
    \ mint &b) {\n    *this *= b.inverse();\n    return *this;\n  }\n\n  mint operator+(const\
    \ mint &b) const { return mint(*this) += b; }\n  mint operator-(const mint &b)\
    \ const { return mint(*this) -= b; }\n  mint operator*(const mint &b) const {\
    \ return mint(*this) *= b; }\n  mint operator/(const mint &b) const { return mint(*this)\
    \ /= b; }\n  bool operator==(const mint &b) const {\n    return (a >= mod ? a\
    \ - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n  bool operator!=(const\
    \ mint &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a -\
    \ mod : b.a);\n  }\n  mint operator-() const { return mint() - mint(*this); }\n\
    \n  mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n    while (n > 0) {\n\
    \      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const mint &b) {\n  \
    \  return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is, mint\
    \ &b) {\n    int64_t t;\n    is >> t;\n    b = ArbitraryLazyMontgomeryModInt(t);\n\
    \    return (is);\n  }\n\n  mint inverse() const { return pow(mod - 2); }\n\n\
    \  u32 get() const {\n    u32 ret = reduce(a);\n    return ret >= mod ? ret -\
    \ mod : ret;\n  }\n\n  static u32 get_mod() { return mod; }\n};\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::mod;\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::r;\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::n2;\n#line 2 \"modint/modint-montgomery64.hpp\"\
    \n\n\n\nstruct montgomery64 {\n  using mint = montgomery64;\n  using i64 = int64_t;\n\
    \  using u64 = uint64_t;\n  using u128 = __uint128_t;\n\n  static u64 mod;\n \
    \ static u64 r;\n  static u64 n2;\n\n  static u64 get_r() {\n    u64 ret = mod;\n\
    \    for (i64 i = 0; i < 5; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\
    \n  static void set_mod(u64 m) {\n    assert(m < (1LL << 62));\n    assert((m\
    \ & 1) == 1);\n    mod = m;\n    n2 = -u128(m) % m;\n    r = get_r();\n    assert(r\
    \ * mod == 1);\n  }\n\n  u64 a;\n\n  montgomery64() : a(0) {}\n  montgomery64(const\
    \ int64_t &b) : a(reduce((u128(b) + mod) * n2)){};\n\n  static u64 reduce(const\
    \ u128 &b) {\n    return (b + u128(u64(b) * u64(-r)) * mod) >> 64;\n  }\n\n  mint\
    \ &operator+=(const mint &b) {\n    if (i64(a += b.a - 2 * mod) < 0) a += 2 *\
    \ mod;\n    return *this;\n  }\n\n  mint &operator-=(const mint &b) {\n    if\
    \ (i64(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint &operator*=(const\
    \ mint &b) {\n    a = reduce(u128(a) * b.a);\n    return *this;\n  }\n\n  mint\
    \ &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return *this;\n\
    \  }\n\n  mint operator+(const mint &b) const { return mint(*this) += b; }\n \
    \ mint operator-(const mint &b) const { return mint(*this) -= b; }\n  mint operator*(const\
    \ mint &b) const { return mint(*this) *= b; }\n  mint operator/(const mint &b)\
    \ const { return mint(*this) /= b; }\n  bool operator==(const mint &b) const {\n\
    \    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n\
    \  bool operator!=(const mint &b) const {\n    return (a >= mod ? a - mod : a)\
    \ != (b.a >= mod ? b.a - mod : b.a);\n  }\n  mint operator-() const { return mint()\
    \ - mint(*this); }\n\n  mint pow(u128 n) const {\n    mint ret(1), mul(*this);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const mint &b) {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream\
    \ &is, mint &b) {\n    int64_t t;\n    is >> t;\n    b = montgomery64(t);\n  \
    \  return (is);\n  }\n\n  mint inverse() const { return pow(mod - 2); }\n\n  u64\
    \ get() const {\n    u64 ret = reduce(a);\n    return ret >= mod ? ret - mod :\
    \ ret;\n  }\n\n  static u64 get_mod() { return mod; }\n};\ntypename montgomery64::u64\
    \ montgomery64::mod, montgomery64::r, montgomery64::n2;\n#line 7 \"prime/fast-factorize.hpp\"\
    \n\nnamespace fast_factorize {\nusing u64 = uint64_t;\n\ntemplate <typename mint>\n\
    bool miller_rabin(u64 n, vector<u64> as) {\n  if (mint::get_mod() != n) mint::set_mod(n);\n\
    \  u64 d = n - 1;\n  while (~d & 1) d >>= 1;\n  mint e{1}, rev{int64_t(n - 1)};\n\
    \  for (u64 a : as) {\n    if (n <= a) break;\n    u64 t = d;\n    mint y = mint(a).pow(t);\n\
    \    while (t != n - 1 && y != e && y != rev) {\n      y *= y;\n      t *= 2;\n\
    \    }\n    if (y != rev && t % 2 == 0) return false;\n  }\n  return true;\n}\n\
    \nbool is_prime(u64 n) {\n  if (~n & 1) return n == 2;\n  if (n <= 1) return false;\n\
    \  if (n < (1LL << 30))\n    return miller_rabin<ArbitraryLazyMontgomeryModInt>(n,\
    \ {2, 7, 61});\n  else\n    return miller_rabin<montgomery64>(\n        n, {2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022});\n}\n\ntemplate <typename mint,\
    \ typename T>\nT pollard_rho(T n) {\n  if (~n & 1) return 2;\n  if (is_prime(n))\
    \ return n;\n  if (mint::get_mod() != n) mint::set_mod(n);\n  mint R, one = 1;\n\
    \  auto f = [&](mint x) { return x * x + R; };\n  auto rnd_ = [&]() { return rng()\
    \ % (n - 2) + 2; };\n  while (1) {\n    mint x, y, ys, q = one;\n    R = rnd_(),\
    \ y = rnd_();\n    T g = 1;\n    constexpr int m = 128;\n    for (int r = 1; g\
    \ == 1; r <<= 1) {\n      x = y;\n      for (int i = 0; i < r; ++i) y = f(y);\n\
    \      for (int k = 0; g == 1 && k < r; k += m) {\n        ys = y;\n        for\
    \ (int i = 0; i < m && i < r - k; ++i) q *= x - (y = f(y));\n        g = inner::gcd<T>(q.get(),\
    \ n);\n      }\n    }\n    if (g == n) do\n        g = inner::gcd<T>((x - (ys\
    \ = f(ys))).get(), n);\n      while (g == 1);\n    if (g != n) return g;\n  }\n\
    \  exit(1);\n}\n\nusing i64 = long long;\n\nvector<i64> inner_factorize(u64 n)\
    \ {\n  if (n <= 1) return {};\n  u64 p;\n  if (n <= (1LL << 30))\n    p = pollard_rho<ArbitraryLazyMontgomeryModInt,\
    \ uint32_t>(n);\n  else\n    p = pollard_rho<montgomery64, uint64_t>(n);\n  if\
    \ (p == n) return {i64(p)};\n  auto l = inner_factorize(p);\n  auto r = inner_factorize(n\
    \ / p);\n  copy(begin(r), end(r), back_inserter(l));\n  return l;\n}\n\nvector<i64>\
    \ factorize(u64 n) {\n  auto ret = inner_factorize(n);\n  sort(begin(ret), end(ret));\n\
    \  return ret;\n}\n\nmap<i64, i64> factor_count(u64 n) {\n  map<i64, i64> mp;\n\
    \  for (auto &x : factorize(n)) mp[x]++;\n  return mp;\n}\n\nvector<i64> divisors(u64\
    \ n) {\n  if (n == 0) return {};\n  vector<pair<i64, i64>> v;\n  for (auto &p\
    \ : factorize(n)) {\n    if (v.empty() || v.back().first != p) {\n      v.emplace_back(p,\
    \ 1);\n    } else {\n      v.back().second++;\n    }\n  }\n  vector<i64> ret;\n\
    \  auto f = [&](auto rc, int i, i64 x) -> void {\n    if (i == (int)v.size())\
    \ {\n      ret.push_back(x);\n      return;\n    }\n    for (int j = v[i].second;;\
    \ --j) {\n      rc(rc, i + 1, x);\n      if (j == 0) break;\n      x *= v[i].first;\n\
    \    }\n  };\n  f(f, 0, 1);\n  sort(begin(ret), end(ret));\n  return ret;\n}\n\
    \n}  // namespace fast_factorize\n\nusing fast_factorize::divisors;\nusing fast_factorize::factor_count;\n\
    using fast_factorize::factorize;\nusing fast_factorize::is_prime;\n\n/**\n * @brief\
    \ \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)\n * @docs\
    \ docs/prime/fast-factorize.md\n */\n#line 2 \"prime/prime-enumerate.hpp\"\n\n\
    // Prime Sieve {2, 3, 5, 7, 11, 13, 17, ...}\nvector<int> prime_enumerate(int\
    \ N) {\n  vector<bool> sieve(N / 3 + 1, 1);\n  for (int p = 5, d = 4, i = 1, sqn\
    \ = sqrt(N); p <= sqn; p += d = 6 - d, i++) {\n    if (!sieve[i]) continue;\n\
    \    for (int q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p,\n  \
    \           qe = sieve.size();\n         q < qe; q += r = s - r)\n      sieve[q]\
    \ = 0;\n  }\n  vector<int> ret{2, 3};\n  for (int p = 5, d = 4, i = 1; p <= N;\
    \ p += d = 6 - d, i++)\n    if (sieve[i]) ret.push_back(p);\n  while (!ret.empty()\
    \ && ret.back() > N) ret.pop_back();\n  return ret;\n}\n#line 11 \"verify/verify-unit-test/garner-bigint.test.cpp\"\
    \n//\n#line 2 \"misc/fastio.hpp\"\n\n#line 6 \"misc/fastio.hpp\"\n\nusing namespace\
    \ std;\n\nnamespace fastio {\nstatic constexpr int SZ = 1 << 17;\nchar inbuf[SZ],\
    \ outbuf[SZ];\nint in_left = 0, in_right = 0, out_right = 0;\n\nstruct Pre {\n\
    \  char num[40000];\n  constexpr Pre() : num() {\n    for (int i = 0; i < 10000;\
    \ i++) {\n      int n = i;\n      for (int j = 3; j >= 0; j--) {\n        num[i\
    \ * 4 + j] = n % 10 + '0';\n        n /= 10;\n      }\n    }\n  }\n} constexpr\
    \ pre;\n\ninline void load() {\n  int len = in_right - in_left;\n  memmove(inbuf,\
    \ inbuf + in_left, len);\n  in_right = len + fread(inbuf + len, 1, SZ - len, stdin);\n\
    \  in_left = 0;\n}\n\ninline void flush() {\n  fwrite(outbuf, 1, out_right, stdout);\n\
    \  out_right = 0;\n}\n\ninline void skip_space() {\n  if (in_left + 32 > in_right)\
    \ load();\n  while (inbuf[in_left] <= ' ') in_left++;\n}\n\ninline void rd(char&\
    \ c) {\n  if (in_left + 32 > in_right) load();\n  c = inbuf[in_left++];\n}\ntemplate\
    \ <typename T>\ninline void rd(T& x) {\n  if (in_left + 32 > in_right) load();\n\
    \  char c;\n  do c = inbuf[in_left++];\n  while (c < '-');\n  [[maybe_unused]]\
    \ bool minus = false;\n  if constexpr (is_signed<T>::value == true) {\n    if\
    \ (c == '-') minus = true, c = inbuf[in_left++];\n  }\n  x = 0;\n  while (c >=\
    \ '0') {\n    x = x * 10 + (c & 15);\n    c = inbuf[in_left++];\n  }\n  if constexpr\
    \ (is_signed<T>::value == true) {\n    if (minus) x = -x;\n  }\n}\ninline void\
    \ rd() {}\ntemplate <typename Head, typename... Tail>\ninline void rd(Head& head,\
    \ Tail&... tail) {\n  rd(head);\n  rd(tail...);\n}\n\ninline void wt(char c) {\n\
    \  if (out_right > SZ - 32) flush();\n  outbuf[out_right++] = c;\n}\ninline void\
    \ wt(bool b) {\n  if (out_right > SZ - 32) flush();\n  outbuf[out_right++] = b\
    \ ? '1' : '0';\n}\ninline void wt(const string &s) {\n  if (out_right + s.size()\
    \ > SZ - 32) flush();\n  memcpy(outbuf + out_right, s.data(), sizeof(char) * s.size());\n\
    \  out_right += s.size();\n}\ntemplate <typename T>\ninline void wt(T x) {\n \
    \ if (out_right > SZ - 32) flush();\n  if (!x) {\n    outbuf[out_right++] = '0';\n\
    \    return;\n  }\n  if constexpr (is_signed<T>::value == true) {\n    if (x <\
    \ 0) outbuf[out_right++] = '-', x = -x;\n  }\n  int i = 12;\n  char buf[16];\n\
    \  while (x >= 10000) {\n    memcpy(buf + i, pre.num + (x % 10000) * 4, 4);\n\
    \    x /= 10000;\n    i -= 4;\n  }\n  if (x < 100) {\n    if (x < 10) {\n    \
    \  outbuf[out_right] = '0' + x;\n      ++out_right;\n    } else {\n      uint32_t\
    \ q = (uint32_t(x) * 205) >> 11;\n      uint32_t r = uint32_t(x) - q * 10;\n \
    \     outbuf[out_right] = '0' + q;\n      outbuf[out_right + 1] = '0' + r;\n \
    \     out_right += 2;\n    }\n  } else {\n    if (x < 1000) {\n      memcpy(outbuf\
    \ + out_right, pre.num + (x << 2) + 1, 3);\n      out_right += 3;\n    } else\
    \ {\n      memcpy(outbuf + out_right, pre.num + (x << 2), 4);\n      out_right\
    \ += 4;\n    }\n  }\n  memcpy(outbuf + out_right, buf + i + 4, 12 - i);\n  out_right\
    \ += 12 - i;\n}\ninline void wt() {}\ntemplate <typename Head, typename... Tail>\n\
    inline void wt(Head&& head, Tail&&... tail) {\n  wt(head);\n  wt(forward<Tail>(tail)...);\n\
    }\ntemplate <typename... Args>\ninline void wtn(Args&&... x) {\n  wt(forward<Args>(x)...);\n\
    \  wt('\\n');\n}\n\nstruct Dummy {\n  Dummy() { atexit(flush); }\n} dummy;\n\n\
    }  // namespace fastio\nusing fastio::rd;\nusing fastio::skip_space;\nusing fastio::wt;\n\
    using fastio::wtn;\n#line 2 \"misc/timer.hpp\"\n\n#line 4 \"misc/timer.hpp\"\n\
    \nstruct Timer {\n  chrono::high_resolution_clock::time_point st;\n\n  Timer()\
    \ { reset(); }\n\n  void reset() { st = chrono::high_resolution_clock::now();\
    \ }\n\n  chrono::milliseconds::rep elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n\
    \    return chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n\
    };\n#line 13 \"verify/verify-unit-test/garner-bigint.test.cpp\"\n\nusing namespace\
    \ Nyaan;\nusing mint = ArbitraryModInt;\n\n// n^e\nbigint pow1(ll n, int e) {\n\
    \  assert(1 <= n);\n  if (e == 0) return 1;\n  bigint half = pow1(n, e / 2);\n\
    \  bigint res = half * half;\n  if (e & 1) res *= n;\n  return res;\n}\nbigint\
    \ pow2(ll n, int e) {\n  assert(1 <= n);\n  int pnum = int(log10(n) * double(e)\
    \ / 8.8) + 2;\n  vector<int> ps, as;\n  for (int p = 1000000007; sz(ps) < pnum;\
    \ p += 2) {\n    if (is_prime(p)) ps.push_back(p);\n  }\n  for (auto& p : ps)\
    \ {\n    mint::set_mod(p);\n    as.push_back(mint{n}.pow(e).get());\n  }\n  auto\
    \ ans1 = GarnerImpl::garner_naive(as, ps).first;\n  auto ans2 = GarnerImpl::garner_dc(as,\
    \ ps).first;\n  assert(ans1 == ans2);\n  return ans1;\n}\n\nvoid Nyaan::solve()\
    \ {\n  {\n    auto ps = prime_enumerate(1000);\n    for (int n = 1; n <= sz(ps);\
    \ n++) {\n      vector<int> rem, mod;\n      for (int i = 0; i < n; i++) {\n \
    \       rem.push_back(rng(0, ps[i] - 1));\n        mod.push_back(ps[i]);\n   \
    \   }\n      trc(rem, mod);\n      auto ans1 = GarnerImpl::garner_naive(rem, mod);\n\
    \      trc(ans1);\n      auto ans2 = GarnerImpl::garner_dc(rem, mod);\n      trc(ans2);\n\
    \      if (ans1 != ans2) exit(1);\n    }\n  }\n  rep1(n, 100) rep(e, 100) {\n\
    \    bigint ans1 = pow1(n, e);\n    bigint ans2 = pow2(n, e);\n    if (ans1 !=\
    \ ans2) {\n      trc(n, e, ans1, ans2);\n    }\n    assert(ans1 == ans2);\n  }\n\
    \n  /**\n  {\n    int nmax = 1 << 15;\n    vector<int> ps;\n    for (int p = TEN(9);\
    \ sz(ps) < nmax; p--) {\n      if (is_prime(p)) ps.push_back(p);\n    }\n    for\
    \ (int n = 1; n <= nmax; n *= 2) {\n      vector<int> rem, mod;\n      for (int\
    \ i = 0; i < n; i++) {\n        rem.push_back(rng(0, ps[i] - 1));\n        mod.push_back(ps[i]);\n\
    \      }\n      trc(rem, mod);\n      Timer timer;\n\n      timer.reset();\n \
    \     auto ans1 = GarnerImpl::garner_naive(rem, mod);\n      int t1 = timer.elapsed();\n\
    \n      timer.reset();\n      auto ans2 = GarnerImpl::garner_dc(rem, mod);\n \
    \     int t2 = timer.elapsed();\n\n      if (ans1 != ans2) exit(1);\n      cerr\
    \ << \"n : \" << n << \", \";\n      cerr << \"naive : \" << t1 << \" ms , \"\
    ;\n      cerr << \"dc : \" << t2 << \" ms\" << endl;\n    }\n  }\n  //*/\n  cerr\
    \ << \"OK\" << endl;\n\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../math/bigint-garner.hpp\"\
    \n//\n#include \"../../modint/arbitrary-modint.hpp\"\n//\n#include \"../../prime/fast-factorize.hpp\"\
    \n#include \"../../prime/prime-enumerate.hpp\"\n//\n#include \"../../misc/all.hpp\"\
    \n\nusing namespace Nyaan;\nusing mint = ArbitraryModInt;\n\n// n^e\nbigint pow1(ll\
    \ n, int e) {\n  assert(1 <= n);\n  if (e == 0) return 1;\n  bigint half = pow1(n,\
    \ e / 2);\n  bigint res = half * half;\n  if (e & 1) res *= n;\n  return res;\n\
    }\nbigint pow2(ll n, int e) {\n  assert(1 <= n);\n  int pnum = int(log10(n) *\
    \ double(e) / 8.8) + 2;\n  vector<int> ps, as;\n  for (int p = 1000000007; sz(ps)\
    \ < pnum; p += 2) {\n    if (is_prime(p)) ps.push_back(p);\n  }\n  for (auto&\
    \ p : ps) {\n    mint::set_mod(p);\n    as.push_back(mint{n}.pow(e).get());\n\
    \  }\n  auto ans1 = GarnerImpl::garner_naive(as, ps).first;\n  auto ans2 = GarnerImpl::garner_dc(as,\
    \ ps).first;\n  assert(ans1 == ans2);\n  return ans1;\n}\n\nvoid Nyaan::solve()\
    \ {\n  {\n    auto ps = prime_enumerate(1000);\n    for (int n = 1; n <= sz(ps);\
    \ n++) {\n      vector<int> rem, mod;\n      for (int i = 0; i < n; i++) {\n \
    \       rem.push_back(rng(0, ps[i] - 1));\n        mod.push_back(ps[i]);\n   \
    \   }\n      trc(rem, mod);\n      auto ans1 = GarnerImpl::garner_naive(rem, mod);\n\
    \      trc(ans1);\n      auto ans2 = GarnerImpl::garner_dc(rem, mod);\n      trc(ans2);\n\
    \      if (ans1 != ans2) exit(1);\n    }\n  }\n  rep1(n, 100) rep(e, 100) {\n\
    \    bigint ans1 = pow1(n, e);\n    bigint ans2 = pow2(n, e);\n    if (ans1 !=\
    \ ans2) {\n      trc(n, e, ans1, ans2);\n    }\n    assert(ans1 == ans2);\n  }\n\
    \n  /**\n  {\n    int nmax = 1 << 15;\n    vector<int> ps;\n    for (int p = TEN(9);\
    \ sz(ps) < nmax; p--) {\n      if (is_prime(p)) ps.push_back(p);\n    }\n    for\
    \ (int n = 1; n <= nmax; n *= 2) {\n      vector<int> rem, mod;\n      for (int\
    \ i = 0; i < n; i++) {\n        rem.push_back(rng(0, ps[i] - 1));\n        mod.push_back(ps[i]);\n\
    \      }\n      trc(rem, mod);\n      Timer timer;\n\n      timer.reset();\n \
    \     auto ans1 = GarnerImpl::garner_naive(rem, mod);\n      int t1 = timer.elapsed();\n\
    \n      timer.reset();\n      auto ans2 = GarnerImpl::garner_dc(rem, mod);\n \
    \     int t2 = timer.elapsed();\n\n      if (ans1 != ans2) exit(1);\n      cerr\
    \ << \"n : \" << n << \", \";\n      cerr << \"naive : \" << t1 << \" ms , \"\
    ;\n      cerr << \"dc : \" << t2 << \" ms\" << endl;\n    }\n  }\n  //*/\n  cerr\
    \ << \"OK\" << endl;\n\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - math/bigint-garner.hpp
  - math/bigint.hpp
  - ntt/arbitrary-ntt.hpp
  - modint/montgomery-modint.hpp
  - ntt/ntt.hpp
  - modint/arbitrary-modint.hpp
  - modint/barrett-reduction.hpp
  - prime/fast-factorize.hpp
  - inner/inner_math.hpp
  - misc/rng.hpp
  - modint/arbitrary-prime-modint.hpp
  - modint/modint-montgomery64.hpp
  - prime/prime-enumerate.hpp
  - misc/all.hpp
  - misc/fastio.hpp
  - misc/timer.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/garner-bigint.test.cpp
  requiredBy: []
  timestamp: '2023-04-15 00:09:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/garner-bigint.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/garner-bigint.test.cpp
- /verify/verify/verify-unit-test/garner-bigint.test.cpp.html
title: verify/verify-unit-test/garner-bigint.test.cpp
---