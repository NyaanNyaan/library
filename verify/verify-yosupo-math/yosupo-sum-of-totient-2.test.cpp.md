---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  - icon: ':heavy_check_mark:'
    path: multiplicative-function/sum-of-multiplicative-function.hpp
    title: "\u4E57\u6CD5\u7684\u95A2\u6570\u306Eprefix sum"
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_totient_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_totient_function
  bundledCode: "#line 1 \"verify/verify-yosupo-math/yosupo-sum-of-totient-2.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\n\
    //\n#line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n\
    #include <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <initializer_list>\n#include <iomanip>\n\
    #include <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n\
    #include <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <streambuf>\n#include\
    \ <string>\n#include <tuple>\n#include <type_traits>\n#include <typeinfo>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include <vector>\n\
    \n// utility\n#line 1 \"template/util.hpp\"\nnamespace Nyaan {\nusing ll = long\
    \ long;\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing i128 =\
    \ __int128_t;\nusing u128 = __uint128_t;\n\ntemplate <typename T>\nusing V = vector<T>;\n\
    template <typename T>\nusing VV = vector<vector<T>>;\nusing vi = vector<int>;\n\
    using vl = vector<long long>;\nusing vd = V<double>;\nusing vs = V<string>;\n\
    using vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\n\ntemplate\
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
    \ 4 \"verify/verify-yosupo-math/yosupo-sum-of-totient-2.test.cpp\"\n//\nusing\
    \ namespace Nyaan;\n\n#line 2 \"modint/montgomery-modint.hpp\"\n\n\n\ntemplate\
    \ <uint32_t mod>\nstruct LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n\
    \  using i32 = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n\
    \  static constexpr u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i <\
    \ 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n  static constexpr u32\
    \ r = get_r();\n  static constexpr u32 n2 = -u64(mod) % mod;\n  static_assert(r\
    \ * mod == 1, \"invalid, r * mod != 1\");\n  static_assert(mod < (1 << 30), \"\
    invalid, mod >= 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"invalid, mod % 2\
    \ == 0\");\n\n  u32 a;\n\n  constexpr LazyMontgomeryModInt() : a(0) {}\n  constexpr\
    \ LazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b % mod + mod)\
    \ * n2)){};\n\n  static constexpr u32 reduce(const u64 &b) {\n    return (b +\
    \ u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  constexpr mint &operator+=(const\
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
    \ { return mod; }\n};\n#line 2 \"modulo/binomial.hpp\"\n\ntemplate <typename T>\n\
    struct Binomial {\n  vector<T> f, g, h;\n  Binomial(int MAX = 0) {\n    assert(T::get_mod()\
    \ != 0 && \"Binomial<mint>()\");\n    f.resize(1, T{1});\n    g.resize(1, T{1});\n\
    \    h.resize(1, T{1});\n    while (MAX >= (int)f.size()) extend();\n  }\n\n \
    \ void extend() {\n    int n = f.size();\n    int m = n * 2;\n    f.resize(m);\n\
    \    g.resize(m);\n    h.resize(m);\n    for (int i = n; i < m; i++) f[i] = f[i\
    \ - 1] * T(i);\n    g[m - 1] = f[m - 1].inverse();\n    h[m - 1] = g[m - 1] *\
    \ f[m - 2];\n    for (int i = m - 2; i >= n; i--) {\n      g[i] = g[i + 1] * T(i\
    \ + 1);\n      h[i] = g[i] * f[i - 1];\n    }\n  }\n\n  T fac(int i) {\n    if\
    \ (i < 0) return T(0);\n    while (i >= (int)f.size()) extend();\n    return f[i];\n\
    \  }\n\n  T finv(int i) {\n    if (i < 0) return T(0);\n    while (i >= (int)g.size())\
    \ extend();\n    return g[i];\n  }\n\n  T inv(int i) {\n    if (i < 0) return\
    \ -inv(-i);\n    while (i >= (int)h.size()) extend();\n    return h[i];\n  }\n\
    \n  T C(int n, int r) {\n    if (n < 0 || n < r || r < 0) return T(0);\n    return\
    \ fac(n) * finv(n - r) * finv(r);\n  }\n\n  inline T operator()(int n, int r)\
    \ { return C(n, r); }\n\n  template <typename I>\n  T multinomial(const vector<I>&\
    \ r) {\n    static_assert(is_integral<I>::value == true);\n    int n = 0;\n  \
    \  for (auto& x : r) {\n      if (x < 0) return T(0);\n      n += x;\n    }\n\
    \    T res = fac(n);\n    for (auto& x : r) res *= finv(x);\n    return res;\n\
    \  }\n\n  template <typename I>\n  T operator()(const vector<I>& r) {\n    return\
    \ multinomial(r);\n  }\n\n  T C_naive(int n, int r) {\n    if (n < 0 || n < r\
    \ || r < 0) return T(0);\n    T ret = T(1);\n    r = min(r, n - r);\n    for (int\
    \ i = 1; i <= r; ++i) ret *= inv(i) * (n--);\n    return ret;\n  }\n\n  T P(int\
    \ n, int r) {\n    if (n < 0 || n < r || r < 0) return T(0);\n    return fac(n)\
    \ * finv(n - r);\n  }\n\n  T H(int n, int r) {\n    if (n < 0 || r < 0) return\
    \ T(0);\n    return r == 0 ? 1 : C(n + r - 1, r);\n  }\n};\n#line 2 \"multiplicative-function/sum-of-multiplicative-function.hpp\"\
    \n\n#line 2 \"prime/prime-enumerate.hpp\"\n\n// Prime Sieve {2, 3, 5, 7, 11, 13,\
    \ 17, ...}\nvector<int> prime_enumerate(int N) {\n  vector<bool> sieve(N / 3 +\
    \ 1, 1);\n  for (int p = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn; p += d = 6\
    \ - d, i++) {\n    if (!sieve[i]) continue;\n    for (int q = p * p / 3, r = d\
    \ * p / 3 + (d * p % 3 == 2), s = 2 * p,\n             qe = sieve.size();\n  \
    \       q < qe; q += r = s - r)\n      sieve[q] = 0;\n  }\n  vector<int> ret{2,\
    \ 3};\n  for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)\n    if (sieve[i])\
    \ ret.push_back(p);\n  while (!ret.empty() && ret.back() > N) ret.pop_back();\n\
    \  return ret;\n}\n#line 4 \"multiplicative-function/sum-of-multiplicative-function.hpp\"\
    \n\n// f(p, c) : f(p^c) \u306E\u5024\u3092\u8FD4\u3059\ntemplate <typename T,\
    \ T (*f)(long long, long long)>\nstruct mf_prefix_sum {\n  using i64 = long long;\n\
    \n  i64 M, sq, s;\n  vector<int> p;\n  int ps;\n  vector<T> buf;\n  T ans;\n\n\
    \  mf_prefix_sum(i64 m) : M(m) {\n    assert(m < (1LL << 42));\n    sq = sqrt(M);\n\
    \    while (sq * sq > M) sq--;\n    while ((sq + 1) * (sq + 1) <= M) sq++;\n\n\
    \    if (M != 0) {\n      i64 hls = md(M, sq);\n      if (hls != 1 && md(M, hls\
    \ - 1) == sq) hls--;\n      s = hls + sq;\n\n      p = prime_enumerate(sq);\n\
    \      ps = p.size();\n      ans = T{};\n    }\n  }\n\n  // \u7D20\u6570\u306E\
    \u500B\u6570\u95A2\u6570\u306B\u95A2\u3059\u308B\u30C6\u30FC\u30D6\u30EB\n  vector<T>\
    \ pi_table() {\n    if (M == 0) return {};\n    i64 hls = md(M, sq);\n    if (hls\
    \ != 1 && md(M, hls - 1) == sq) hls--;\n\n    vector<i64> hl(hls);\n    for (int\
    \ i = 1; i < hls; i++) hl[i] = md(M, i) - 1;\n\n    vector<int> hs(sq + 1);\n\
    \    iota(begin(hs), end(hs), -1);\n\n    int pi = 0;\n    for (auto& x : p) {\n\
    \      i64 x2 = i64(x) * x;\n      i64 imax = min<i64>(hls, md(M, x2) + 1);\n\
    \      for (i64 i = 1, ix = x; i < imax; ++i, ix += x) {\n        hl[i] -= (ix\
    \ < hls ? hl[ix] : hs[md(M, ix)]) - pi;\n      }\n      for (int n = sq; n >=\
    \ x2; n--) hs[n] -= hs[md(n, x)] - pi;\n      pi++;\n    }\n\n    vector<T> res;\n\
    \    res.reserve(2 * sq + 10);\n    for (auto& x : hl) res.push_back(x);\n   \
    \ for (int i = hs.size(); --i;) res.push_back(hs[i]);\n    assert((int)res.size()\
    \ == s);\n    return res;\n  }\n\n  // \u7D20\u6570\u306E prefix sum \u306B\u95A2\
    \u3059\u308B\u30C6\u30FC\u30D6\u30EB\n  vector<T> prime_sum_table() {\n    if\
    \ (M == 0) return {};\n    i64 hls = md(M, sq);\n    if (hls != 1 && md(M, hls\
    \ - 1) == sq) hls--;\n\n    vector<T> h(s);\n    T inv2 = T{2}.inverse();\n  \
    \  for (int i = 1; i < hls; i++) {\n      T x = md(M, i);\n      h[i] = x * (x\
    \ + 1) * inv2 - 1;\n    }\n    for (int i = 1; i <= sq; i++) {\n      T x = i;\n\
    \      h[s - i] = x * (x + 1) / 2 - 1;\n    }\n\n    for (auto& x : p) {\n   \
    \   T xt = x;\n      T pi = h[s - x + 1];\n      i64 x2 = i64(x) * x;\n      i64\
    \ imax = min<i64>(hls, md(M, x2) + 1);\n      i64 ix = x;\n      for (i64 i =\
    \ 1; i < imax; ++i, ix += x) {\n        h[i] -= ((ix < hls ? h[ix] : h[s - md(M,\
    \ ix)]) - pi) * xt;\n      }\n      for (int n = sq; n >= x2; n--) {\n       \
    \ h[s - n] -= (h[s - md(n, x)] - pi) * xt;\n      }\n    }\n\n    assert((int)h.size()\
    \ == s);\n    return h;\n  }\n\n  void dfs(int i, int c, i64 prod, T cur) {\n\
    \    ans += cur * f(p[i], c + 1);\n    i64 lim = md(M, prod);\n    if (lim >=\
    \ 1LL * p[i] * p[i]) dfs(i, c + 1, p[i] * prod, cur);\n    cur *= f(p[i], c);\n\
    \    ans += cur * (buf[idx(lim)] - buf[idx(p[i])]);\n    int j = i + 1;\n    //\
    \ M < 2**42 -> p_j < 2**21 -> (p_j)^3 < 2**63\n    for (; j < ps && 1LL * p[j]\
    \ * p[j] * p[j] <= lim; j++) {\n      dfs(j, 1, prod * p[j], cur);\n    }\n  \
    \  for (; j < ps && 1LL * p[j] * p[j] <= lim; j++) {\n      T sm = f(p[j], 2);\n\
    \      int id1 = idx(md(lim, p[j])), id2 = idx(p[j]);\n      sm += f(p[j], 1)\
    \ * (buf[id1] - buf[id2]);\n      ans += cur * sm;\n    }\n  }\n\n  // fprime\
    \ \u7834\u58CA\u7684\n  T run(vector<T>& fprime) {\n    if (M == 0) return {};\n\
    \    set_buf(fprime);\n    assert((int)buf.size() == s);\n    ans = buf[idx(M)]\
    \ + 1;\n    for (int i = 0; i < ps; i++) dfs(i, 1, p[i], 1);\n    return ans;\n\
    \  }\n\n  i64 md(i64 n, i64 d) { return double(n) / d; }\n  i64 idx(i64 n) { return\
    \ n <= sq ? s - n : md(M, n); }\n  void set_buf(vector<T>& _buf) { swap(buf, _buf);\
    \ }\n};\n\n/**\n * @brief \u4E57\u6CD5\u7684\u95A2\u6570\u306Eprefix sum\n * @docs\
    \ docs/multiplicative-function/sum-of-multiplicative-function.md\n */\n#line 10\
    \ \"verify/verify-yosupo-math/yosupo-sum-of-totient-2.test.cpp\"\n//\nusing namespace\
    \ Nyaan;\nusing mint = LazyMontgomeryModInt<998244353>;\n// using mint = LazyMontgomeryModInt<1000000007>;\n\
    using vm = vector<mint>;\nusing vvm = vector<vm>;\nBinomial<mint> C;\n\nmint f(ll\
    \ p, ll c) {\n  ll res = 1;\n  while (--c) res = res * p;\n  return res * (p -\
    \ 1);\n}\n\nvoid Nyaan::solve() {\n  inl(N);\n  mf_prefix_sum<mint, f> mf(N);\n\
    \  auto h1 = mf.prime_sum_table();\n  auto h0 = mf.pi_table();\n  rep(i, sz(h1))\
    \ h1[i] -= h0[i];\n  out(mf.run(h1));\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n//\n#include \"../../template/template.hpp\"\n//\nusing namespace Nyaan;\n\n\
    #include \"../../modint/montgomery-modint.hpp\"\n#include \"../../modulo/binomial.hpp\"\
    \n#include \"../../multiplicative-function/sum-of-multiplicative-function.hpp\"\
    \n//\nusing namespace Nyaan;\nusing mint = LazyMontgomeryModInt<998244353>;\n\
    // using mint = LazyMontgomeryModInt<1000000007>;\nusing vm = vector<mint>;\n\
    using vvm = vector<vm>;\nBinomial<mint> C;\n\nmint f(ll p, ll c) {\n  ll res =\
    \ 1;\n  while (--c) res = res * p;\n  return res * (p - 1);\n}\n\nvoid Nyaan::solve()\
    \ {\n  inl(N);\n  mf_prefix_sum<mint, f> mf(N);\n  auto h1 = mf.prime_sum_table();\n\
    \  auto h0 = mf.pi_table();\n  rep(i, sz(h1)) h1[i] -= h0[i];\n  out(mf.run(h1));\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - modint/montgomery-modint.hpp
  - modulo/binomial.hpp
  - multiplicative-function/sum-of-multiplicative-function.hpp
  - prime/prime-enumerate.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-math/yosupo-sum-of-totient-2.test.cpp
  requiredBy: []
  timestamp: '2023-03-23 17:00:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-math/yosupo-sum-of-totient-2.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-math/yosupo-sum-of-totient-2.test.cpp
- /verify/verify/verify-yosupo-math/yosupo-sum-of-totient-2.test.cpp.html
title: verify/verify-yosupo-math/yosupo-sum-of-totient-2.test.cpp
---
