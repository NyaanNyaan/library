---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  - icon: ':heavy_check_mark:'
    path: math/bigint.hpp
    title: "\u591A\u500D\u9577\u6574\u6570"
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
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
  bundledCode: "#line 1 \"verify/verify-unit-test/bigint.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#line 2 \"template/template.hpp\"\
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
    \ 4 \"verify/verify-unit-test/bigint.test.cpp\"\n//\n#line 2 \"math/bigint.hpp\"\
    \n\n#line 10 \"math/bigint.hpp\"\nusing namespace std;\n\n#line 2 \"internal/internal-type-traits.hpp\"\
    \n\n#line 4 \"internal/internal-type-traits.hpp\"\nusing namespace std;\n\nnamespace\
    \ internal {\ntemplate <typename T>\nusing is_broadly_integral =\n    typename\
    \ conditional_t<is_integral_v<T> || is_same_v<T, __int128_t> ||\n            \
    \                   is_same_v<T, __uint128_t>,\n                           true_type,\
    \ false_type>::type;\n\ntemplate <typename T>\nusing is_broadly_signed =\n   \
    \ typename conditional_t<is_signed_v<T> || is_same_v<T, __int128_t>,\n       \
    \                    true_type, false_type>::type;\n\ntemplate <typename T>\n\
    using is_broadly_unsigned =\n    typename conditional_t<is_unsigned_v<T> || is_same_v<T,\
    \ __uint128_t>,\n                           true_type, false_type>::type;\n\n\
    #define ENABLE_VALUE(x) \\\n  template <typename T> \\\n  constexpr bool x##_v\
    \ = x<T>::value;\n\nENABLE_VALUE(is_broadly_integral);\nENABLE_VALUE(is_broadly_signed);\n\
    ENABLE_VALUE(is_broadly_unsigned);\n#undef ENABLE_VALUE\n\n#define ENABLE_HAS_TYPE(var)\
    \                                              \\\n  template <class, class =\
    \ void>                                         \\\n  struct has_##var : std::false_type\
    \ {};                                 \\\n  template <class T>               \
    \                                      \\\n  struct has_##var<T, std::void_t<typename\
    \ T::var>> : std::true_type {}; \\\n  template <class T>                     \
    \                                \\\n  constexpr auto has_##var##_v = has_##var<T>::value;\n\
    \n}  // namespace internal\n#line 2 \"ntt/arbitrary-ntt.hpp\"\n\n#line 2 \"modint/montgomery-modint.hpp\"\
    \n\ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n\
    \  using i32 = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n\
    \  static constexpr u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i <\
    \ 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n  static constexpr u32\
    \ r = get_r();\n  static constexpr u32 n2 = -u64(mod) % mod;\n  static_assert(mod\
    \ < (1 << 30), \"invalid, mod >= 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"\
    invalid, mod % 2 == 0\");\n  static_assert(r * mod == 1, \"this code has bugs.\"\
    );\n\n  u32 a;\n\n  constexpr LazyMontgomeryModInt() : a(0) {}\n  constexpr LazyMontgomeryModInt(const\
    \ int64_t &b)\n      : a(reduce(u64(b % mod + mod) * n2)){};\n\n  static constexpr\
    \ u32 reduce(const u64 &b) {\n    return (b + u64(u32(b) * u32(-r)) * mod) >>\
    \ 32;\n  }\n\n  constexpr mint &operator+=(const mint &b) {\n    if (i32(a +=\
    \ b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  constexpr mint\
    \ &operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2 * mod;\n   \
    \ return *this;\n  }\n\n  constexpr mint &operator*=(const mint &b) {\n    a =\
    \ reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  constexpr mint &operator/=(const\
    \ mint &b) {\n    *this *= b.inverse();\n    return *this;\n  }\n\n  constexpr\
    \ mint operator+(const mint &b) const { return mint(*this) += b; }\n  constexpr\
    \ mint operator-(const mint &b) const { return mint(*this) -= b; }\n  constexpr\
    \ mint operator*(const mint &b) const { return mint(*this) *= b; }\n  constexpr\
    \ mint operator/(const mint &b) const { return mint(*this) /= b; }\n  constexpr\
    \ bool operator==(const mint &b) const {\n    return (a >= mod ? a - mod : a)\
    \ == (b.a >= mod ? b.a - mod : b.a);\n  }\n  constexpr bool operator!=(const mint\
    \ &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod\
    \ : b.a);\n  }\n  constexpr mint operator-() const { return mint() - mint(*this);\
    \ }\n  constexpr mint operator+() const { return mint(*this); }\n\n  constexpr\
    \ mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n    while (n > 0) {\n\
    \      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n\n  constexpr mint inverse() const {\n    int x = get(), y = mod,\
    \ u = 1, v = 0, t = 0, tmp = 0;\n    while (y > 0) {\n      t = x / y;\n     \
    \ x -= t * y, u -= t * v;\n      tmp = x, x = y, y = tmp;\n      tmp = u, u =\
    \ v, v = tmp;\n    }\n    return mint{u};\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const mint &b) {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream\
    \ &is, mint &b) {\n    int64_t t;\n    is >> t;\n    b = LazyMontgomeryModInt<mod>(t);\n\
    \    return (is);\n  }\n\n  constexpr u32 get() const {\n    u32 ret = reduce(a);\n\
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
    \    setwy(k);\n    vector<mint> s(M);\n    for (int i = 0; i < (int)a.size();\
    \ ++i) s[i] = a[i];\n    fft4(s, k);\n    if (a.size() == b.size() && a == b)\
    \ {\n      for (int i = 0; i < M; ++i) s[i] *= s[i];\n    } else {\n      vector<mint>\
    \ t(M);\n      for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i];\n      fft4(t,\
    \ k);\n      for (int i = 0; i < M; ++i) s[i] *= t[i];\n    }\n    ifft4(s, k);\n\
    \    s.resize(l);\n    mint invm = mint(M).inverse();\n    for (int i = 0; i <\
    \ l; ++i) s[i] *= invm;\n    return s;\n  }\n\n  void ntt_doubling(vector<mint>\
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
    \ * w2;\n  }\n  return ret;\n}\n}  // namespace ArbitraryNTT\n#line 14 \"math/bigint.hpp\"\
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
    \ dat(d) {}\n\n  template <typename I,\n            enable_if_t<internal::is_broadly_integral_v<I>>*\
    \ = nullptr>\n  MultiPrecisionInteger(I x) : neg(false) {\n    if constexpr (internal::is_broadly_signed_v<I>)\
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
    \ I,\n            enable_if_t<internal::is_broadly_integral_v<I>>* = nullptr>\n\
    \  static vector<int> _integer_to_vec(I x) {\n    if constexpr (internal::is_broadly_signed_v<I>)\
    \ {\n      assert(x >= 0);\n    }\n    vector<int> res;\n    while (x) res.push_back(x\
    \ % D), x /= D;\n    return res;\n  }\n\n  static long long _to_ll(const vector<int>&\
    \ a) {\n    long long res = 0;\n    for (int i = (int)a.size() - 1; i >= 0; i--)\
    \ res = res * D + a[i];\n    return res;\n  }\n\n  static __int128_t _to_i128(const\
    \ vector<int>& a) {\n    __int128_t res = 0;\n    for (int i = (int)a.size() -\
    \ 1; i >= 0; i--) res = res * D + a[i];\n    return res;\n  }\n\n  static void\
    \ _dump(const vector<int>& a, string s = \"\") {\n    if (!s.empty()) cerr <<\
    \ s << \" : \";\n    cerr << \"{ \";\n    for (int i = 0; i < (int)a.size(); i++)\
    \ cerr << a[i] << \", \";\n    cerr << \"}\" << endl;\n  }\n};\n\nusing bigint\
    \ = MultiPrecisionInteger;\n\n/**\n * @brief \u591A\u500D\u9577\u6574\u6570\n\
    \ */\n#line 6 \"verify/verify-unit-test/bigint.test.cpp\"\n//\n#line 2 \"misc/rng.hpp\"\
    \n\nnamespace my_rand {\nusing i64 = long long;\nusing u64 = unsigned long long;\n\
    \n// [0, 2^64 - 1)\nu64 rng() {\n  static u64 _x =\n      u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \              chrono::high_resolution_clock::now().time_since_epoch())\n    \
    \          .count()) *\n      10150724397891781847ULL;\n  _x ^= _x << 7;\n  return\
    \ _x ^= _x >> 9;\n}\n\n// [l, r]\ni64 rng(i64 l, i64 r) {\n  assert(l <= r);\n\
    \  return l + rng() % (r - l + 1);\n}\n\n// [l, r)\ni64 randint(i64 l, i64 r)\
    \ {\n  assert(l < r);\n  return l + rng() % (r - l);\n}\n\n// choose n numbers\
    \ from [l, r) without overlapping\nvector<i64> randset(i64 l, i64 r, i64 n) {\n\
    \  assert(l <= r && n <= r - l);\n  unordered_set<i64> s;\n  for (i64 i = n; i;\
    \ --i) {\n    i64 m = randint(l, r + 1 - i);\n    if (s.find(m) != s.end()) m\
    \ = r - i;\n    s.insert(m);\n  }\n  vector<i64> ret;\n  for (auto& x : s) ret.push_back(x);\n\
    \  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() { return rng() * 5.42101086242752217004e-20;\
    \ }\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n\
    \  for (int i = 1; i < n; i++) swap(v[i], v[randint(0, i + 1)]);\n}\n\n}  // namespace\
    \ my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\nusing my_rand::randshf;\n\
    using my_rand::rnd;\nusing my_rand::rng;\n#line 8 \"verify/verify-unit-test/bigint.test.cpp\"\
    \n\nvoid MultiPrecisionInteger::_test_private_function(const M& A, const M& B)\
    \ {\n  const vector<int>& a = A.dat;\n  const vector<int>& b = B.dat;\n  {\n \
    \   auto m1 = _mul_naive(a, b);\n    auto m2 = _mul_fft(a, b);\n    assert(m1\
    \ == m2 && \"_mul_test\");\n  }\n}\n\n//\n\nusing namespace Nyaan;\n\nusing ll\
    \ = long long;\nusing i128 = __int128_t;\n\nvoid test() {\n  auto i128_to_string\
    \ = [](i128 x) -> string {\n    if (x == 0) return \"0\";\n    string S;\n   \
    \ bool neg = false;\n    if (x < 0) neg = true, x = -x;\n    while (x) S.push_back('0'\
    \ + x % 10), x /= 10;\n    if (neg) S.push_back('-');\n    reverse(begin(S), end(S));\n\
    \    return S;\n  };\n  // [0, 10^i)\n  auto rng128 = [&](int i = 37) {\n    assert(0\
    \ <= i and i <= 37);\n    i128 res = 0;\n    rep(_, i) res = res * 10 + rng(0,\
    \ 9);\n    return res;\n  };\n  auto TEN128 = [&](int i = 37) {\n    assert(0\
    \ <= i and i <= 37);\n    i128 res = 1;\n    rep(_, i) res *= 10;\n    return\
    \ res;\n  };\n\n  rep(t, 10000) {\n    int loga = rng(1, 37);\n    int logb =\
    \ rng(1, 37);\n    i128 a = rng128(loga);\n    i128 b = rng128(logb);\n    if\
    \ (rng() % 50 == 0) a = 0;\n    if (rng() % 50 == 0) b = 0;\n    if (rng() % 50\
    \ == 0) a = TEN128(loga);\n    if (rng() % 50 == 0) a = TEN128(loga) - 1;\n  \
    \  if (rng() % 50 == 0) b = TEN128(logb);\n    if (rng() % 50 == 0) b = TEN128(logb)\
    \ - 1;\n    if (rng() % 50 == 0) a = b + TEN128(loga);\n    if (rng() % 50 ==\
    \ 0) a = b + TEN128(loga) - 1;\n    if (rng() & 1) a = -a;\n    if (rng() & 1)\
    \ b = -b;\n    bigint A{a};\n    bigint B{b};\n\n    assert(a == A and A == a);\n\
    \    assert(!(a != A) and !(A != a));\n    assert(!(a < A) and !(A < a));\n  \
    \  assert(a <= A and A <= a);\n    assert(!(a > A) and !(A > a));\n    assert(a\
    \ >= A and A >= a);\n\n    assert((a < b) == (A < B));\n    assert((a > b) ==\
    \ (A > B));\n    assert((a <= b) == (A <= B));\n    assert((a >= b) == (A >= B));\n\
    \    assert((a == b) == (A == B));\n    assert((a != b) == (A != B));\n\n    assert(+A\
    \ == +a and -A == -a);\n    assert(+B == +b and -B == -b);\n    assert(abs(A)\
    \ == (a >= 0 ? a : -a));\n    assert(abs(B) == (b >= 0 ? b : -b));\n    assert(A.is_zero()\
    \ == (a == 0));\n    assert(B.is_zero() == (b == 0));\n\n    if (LONG_LONG_MIN\
    \ <= a and a <= LONG_LONG_MAX) {\n      assert(A.to_ll() == a);\n    }\n    if\
    \ (LONG_LONG_MIN <= b and b <= LONG_LONG_MAX) {\n      assert(B.to_ll() == b);\n\
    \    }\n    assert(A.to_i128() == a);\n    assert(B.to_i128() == b);\n\n    bigint\
    \ C{i128_to_string(a)};\n    bigint D{i128_to_string(b)};\n    if (A != C or B\
    \ != D) {\n      trc(a, b, A, B, C, D);\n    }\n    assert(A == C and B == D);\n\
    \    if (A.to_string() != i128_to_string(a)) {\n      trc(A);\n      trc(a);\n\
    \    }\n    assert(A.to_string() == i128_to_string(a));\n    assert(B.to_string()\
    \ == i128_to_string(b));\n\n    assert(a + b == A + B);\n    assert(a + b == B\
    \ + A);\n    assert(A + B == B + A);\n    assert(a - b == A - B);\n    assert(b\
    \ - a == B - A);\n\n    bigint E{A};\n    E += B;\n    assert(E == a + b);\n \
    \   E = B;\n    E += A;\n    assert(E == a + b);\n    E = A;\n    E -= B;\n  \
    \  assert(E == a - b);\n    E = B;\n    E -= A;\n    assert(E == b - a);\n  }\n\
    \n  // *\n  rep(t, 1000) {\n    ll a = randint(-TEN(18), TEN(18));\n    ll b =\
    \ randint(-TEN(18), TEN(18));\n    if (rng() % 100 == 0) a = 0;\n    if (rng()\
    \ % 100 == 0) b = 0;\n    if (rng() % 10 == 0) a = b + rng() % 11;\n    bigint\
    \ A{a}, B{b};\n\n    i128 p = i128(a) * b;\n    auto S = i128_to_string(p);\n\
    \    auto C = A * B;\n    auto D = B * A;\n\n    assert(C == D);\n    assert(C.to_string()\
    \ == S);\n    assert(D.to_string() == S);\n    assert(C == p and p == C);\n  \
    \  assert(D == p and p == D);\n    assert(C.to_i128() == p);\n    assert(D.to_i128()\
    \ == p);\n  }\n\n  // _mul_naive, _mul_fft\n  rep(t, 1000) {\n    vector<int>\
    \ a, b;\n    a.resize(rng(0, 20));\n    b.resize(rng(0, 20));\n    for (auto&\
    \ x : a) x = rng(0, TEN(9) - 1);\n    for (auto& x : b) x = rng(0, TEN(9) - 1);\n\
    \    while (!a.empty() and a.back() == 0) a.pop_back();\n    while (!b.empty()\
    \ and b.back() == 0) b.pop_back();\n    bigint::_test_private_function({false,\
    \ a}, {false, b});\n  }\n\n  // dfp\n  {\n    cerr << fixed << setprecision(21);\n\
    \    auto test_dfp = [&](string S, long double acc = 1e-18) {\n      bigint A{S};\n\
    \      auto [a, b] = A.dfp();\n      // trc(a, b, A.to_ld());\n      if (a ==\
    \ 0) {\n        assert(b == 0 and S == \"0\");\n        return;\n      }\n   \
    \   assert(1.0 <= abs(a) and abs(a) < 10.0);\n      if (S[0] == '-') {\n     \
    \   assert(b + 2 == (int)S.size());\n      } else {\n        assert(b + 1 == (int)S.size());\n\
    \      }\n      long double t1 = A.to_ld();\n      long double t2 = strtold(S.c_str(),\
    \ 0);\n      long double d = abs(t1 - t2);\n      assert(d / t2 < acc);\n    };\n\
    \    test_dfp(\"998244353\");\n    test_dfp(\"1000000000000000000\");\n    test_dfp(\"\
    123456789012345678901234567890\");\n    for (int i = -111; i <= 111; i++) {\n\
    \      test_dfp(to_string(i));\n    }\n    rep(t, 1000) {\n      long long x =\
    \ rng(-TEN(18), TEN(18));\n      test_dfp(to_string(x));\n    }\n    for (int\
    \ k = 20; k <= 60; k++) {\n      test_dfp(\"1\" + string(k, '0'));\n      test_dfp(string(k,\
    \ '9'));\n    }\n    rep(t, 1000) {\n      string s;\n      int b = rng(1, 100);\n\
    \      rep(i, 100) s.push_back(rng('0' + (i == 0), '9'));\n      if (rng() % 2)\
    \ s.insert(begin(s), '-');\n      test_dfp(s, 1e-17);\n    }\n  }\n\n  // to_ld\n\
    \  rep(t, 1000) {\n    long long x = rng(-TEN(16), TEN(16));\n    bigint A{x};\n\
    \    ll y = llround(A.to_ld());\n    assert(x == y);\n  }\n\n  // _tens\n  {\n\
    \    bigint _m;\n    /*\n    unsigned long long x = 1;\n    for (int i = 0; i\
    \ < 20; i++) {\n      assert(x == _m.tens.ten_ull(i));\n      assert(_m.tens.digit(x)\
    \ == i + 1);\n      assert(_m.tens.digit(x - 1) == (x == 1 ? 1 : i));\n      x\
    \ *= 10;\n    }\n    assert(_m.tens.digit(0) == 1);\n    assert(_m.tens.digit(1)\
    \ == 1);\n    */\n    for (int i = -_m.tens.offset; i <= _m.tens.offset; i++)\
    \ {\n      long double t1 = _m.tens.ten_ld(i);\n      long double t2 = powl(10,\
    \ i);\n      long double d = abs(t1 - t2);\n      // trc(i, t1, t2, d / t1);\n\
    \      // i < 0 -> \u6841\u843D\u3061\u304C\u767A\u751F\u3059\u308B\u305F\u3081\
    \u5C11\u3057\u9762\u5012\n      if (i <= 0) assert(d / t1 < 1e-17);\n      if\
    \ (i >= 0) assert(d / t2 < 1e-19);\n    }\n  }\n\n  {\n    auto validate_divmod\
    \ = [&](bigint a, bigint b) {\n      auto [q, r] = divmod(a, b);\n\n      i128\
    \ a2 = a.to_i128();\n      i128 b2 = b.to_i128();\n      i128 q2 = a2 / b2, r2\
    \ = a2 % b2;\n      assert(a == a2 and b == b2 and q == q2 and r == r2);\n\n \
    \     assert(q * b + r == a);\n      assert(0 <= abs(r) and abs(r) < abs(b));\n\
    \      if (a >= 0 and b > 0) {\n        assert(q >= 0 and r >= 0);\n      }\n\
    \      if (a >= 0 and b < 0) {\n        assert(q <= 0 and r >= 0);\n      }\n\
    \      if (a < 0 and b > 0) {\n        assert(q <= 0 and r <= 0);\n      }\n \
    \     if (a < 0 and b < 0) {\n        assert(q >= 0 and r <= 0);\n      }\n  \
    \  };\n    auto wrapper = [&](bigint a, bigint b) {\n      validate_divmod(+a,\
    \ +b);\n      validate_divmod(+a, -b);\n      validate_divmod(-a, +b);\n     \
    \ validate_divmod(-a, -b);\n    };\n\n    rep(t, 1000) {\n      i128 a = 0;\n\
    \      if (t < 37) {\n        a = TEN128(t);\n      } else if (t < 74) {\n   \
    \     a = TEN128(t - 37) - 1;\n      } else if (t < 100) {\n        a = t - 87;\n\
    \      } else {\n        a = rng();\n        a = (a << 63) + rng();\n      }\n\
    \      bigint A = a;\n      for (int i = 1; i <= 18; i++) {\n        wrapper(A,\
    \ i);\n        wrapper(A, TEN(i) - 1);\n      }\n      rep(_, 10) wrapper(A, rng(1,\
    \ TEN(9)));\n      rep(_, 10) wrapper(A, rng(1, TEN(18)));\n      rep(_, 10) wrapper(A,\
    \ rng128(27));\n    }\n  }\n\n  // divmod\n  {\n    auto validate_divmod2 = [&](bigint\
    \ a, bigint b) {\n      auto [q, r] = divmod(a, b);\n\n      bigint a2 = bigint(a.to_string());\n\
    \      bigint b2 = bigint(b.to_string());\n      bigint q2 = bigint(q.to_string());\n\
    \      bigint r2 = bigint(r.to_string());\n      assert(a == a2 and b == b2 and\
    \ q == q2 and r == r2);\n\n      assert(q * b + r == a);\n      assert(0 <= abs(r)\
    \ and abs(r) < abs(b));\n      if (a >= 0 and b > 0) {\n        assert(q >= 0\
    \ and r >= 0);\n      }\n      if (a >= 0 and b < 0) {\n        assert(q <= 0\
    \ and r >= 0);\n      }\n      if (a < 0 and b > 0) {\n        assert(q <= 0 and\
    \ r <= 0);\n      }\n      if (a < 0 and b < 0) {\n        assert(q >= 0 and r\
    \ <= 0);\n      }\n    };\n    auto wrapper = [&](bigint a, bigint b) {\n    \
    \  validate_divmod2(+a, +b);\n      validate_divmod2(+a, -b);\n      validate_divmod2(-a,\
    \ +b);\n      validate_divmod2(-a, -b);\n    };\n\n    rep(t, 1000) {\n      vector<int>\
    \ a, b;\n      a.resize(rng(0, 20));\n      b.resize(rng(0, 20));\n      for (auto&\
    \ x : a) x = rng(0, TEN(9) - 1);\n      for (auto& x : b) x = rng(0, TEN(9) -\
    \ 1);\n      while (!a.empty() and a.back() == 0) a.pop_back();\n      while (!b.empty()\
    \ and b.back() == 0) b.pop_back();\n      bigint A{false, a}, B{false, b};\n \
    \     if (!A.is_zero()) wrapper(B, A);\n      if (!B.is_zero()) wrapper(A, B);\n\
    \    }\n  }\n  cerr << \"OK\" << endl;\n}\n\nvoid Nyaan::solve() {\n  test();\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../math/bigint.hpp\"\n//\n\
    #include \"../../misc/rng.hpp\"\n\nvoid MultiPrecisionInteger::_test_private_function(const\
    \ M& A, const M& B) {\n  const vector<int>& a = A.dat;\n  const vector<int>& b\
    \ = B.dat;\n  {\n    auto m1 = _mul_naive(a, b);\n    auto m2 = _mul_fft(a, b);\n\
    \    assert(m1 == m2 && \"_mul_test\");\n  }\n}\n\n//\n\nusing namespace Nyaan;\n\
    \nusing ll = long long;\nusing i128 = __int128_t;\n\nvoid test() {\n  auto i128_to_string\
    \ = [](i128 x) -> string {\n    if (x == 0) return \"0\";\n    string S;\n   \
    \ bool neg = false;\n    if (x < 0) neg = true, x = -x;\n    while (x) S.push_back('0'\
    \ + x % 10), x /= 10;\n    if (neg) S.push_back('-');\n    reverse(begin(S), end(S));\n\
    \    return S;\n  };\n  // [0, 10^i)\n  auto rng128 = [&](int i = 37) {\n    assert(0\
    \ <= i and i <= 37);\n    i128 res = 0;\n    rep(_, i) res = res * 10 + rng(0,\
    \ 9);\n    return res;\n  };\n  auto TEN128 = [&](int i = 37) {\n    assert(0\
    \ <= i and i <= 37);\n    i128 res = 1;\n    rep(_, i) res *= 10;\n    return\
    \ res;\n  };\n\n  rep(t, 10000) {\n    int loga = rng(1, 37);\n    int logb =\
    \ rng(1, 37);\n    i128 a = rng128(loga);\n    i128 b = rng128(logb);\n    if\
    \ (rng() % 50 == 0) a = 0;\n    if (rng() % 50 == 0) b = 0;\n    if (rng() % 50\
    \ == 0) a = TEN128(loga);\n    if (rng() % 50 == 0) a = TEN128(loga) - 1;\n  \
    \  if (rng() % 50 == 0) b = TEN128(logb);\n    if (rng() % 50 == 0) b = TEN128(logb)\
    \ - 1;\n    if (rng() % 50 == 0) a = b + TEN128(loga);\n    if (rng() % 50 ==\
    \ 0) a = b + TEN128(loga) - 1;\n    if (rng() & 1) a = -a;\n    if (rng() & 1)\
    \ b = -b;\n    bigint A{a};\n    bigint B{b};\n\n    assert(a == A and A == a);\n\
    \    assert(!(a != A) and !(A != a));\n    assert(!(a < A) and !(A < a));\n  \
    \  assert(a <= A and A <= a);\n    assert(!(a > A) and !(A > a));\n    assert(a\
    \ >= A and A >= a);\n\n    assert((a < b) == (A < B));\n    assert((a > b) ==\
    \ (A > B));\n    assert((a <= b) == (A <= B));\n    assert((a >= b) == (A >= B));\n\
    \    assert((a == b) == (A == B));\n    assert((a != b) == (A != B));\n\n    assert(+A\
    \ == +a and -A == -a);\n    assert(+B == +b and -B == -b);\n    assert(abs(A)\
    \ == (a >= 0 ? a : -a));\n    assert(abs(B) == (b >= 0 ? b : -b));\n    assert(A.is_zero()\
    \ == (a == 0));\n    assert(B.is_zero() == (b == 0));\n\n    if (LONG_LONG_MIN\
    \ <= a and a <= LONG_LONG_MAX) {\n      assert(A.to_ll() == a);\n    }\n    if\
    \ (LONG_LONG_MIN <= b and b <= LONG_LONG_MAX) {\n      assert(B.to_ll() == b);\n\
    \    }\n    assert(A.to_i128() == a);\n    assert(B.to_i128() == b);\n\n    bigint\
    \ C{i128_to_string(a)};\n    bigint D{i128_to_string(b)};\n    if (A != C or B\
    \ != D) {\n      trc(a, b, A, B, C, D);\n    }\n    assert(A == C and B == D);\n\
    \    if (A.to_string() != i128_to_string(a)) {\n      trc(A);\n      trc(a);\n\
    \    }\n    assert(A.to_string() == i128_to_string(a));\n    assert(B.to_string()\
    \ == i128_to_string(b));\n\n    assert(a + b == A + B);\n    assert(a + b == B\
    \ + A);\n    assert(A + B == B + A);\n    assert(a - b == A - B);\n    assert(b\
    \ - a == B - A);\n\n    bigint E{A};\n    E += B;\n    assert(E == a + b);\n \
    \   E = B;\n    E += A;\n    assert(E == a + b);\n    E = A;\n    E -= B;\n  \
    \  assert(E == a - b);\n    E = B;\n    E -= A;\n    assert(E == b - a);\n  }\n\
    \n  // *\n  rep(t, 1000) {\n    ll a = randint(-TEN(18), TEN(18));\n    ll b =\
    \ randint(-TEN(18), TEN(18));\n    if (rng() % 100 == 0) a = 0;\n    if (rng()\
    \ % 100 == 0) b = 0;\n    if (rng() % 10 == 0) a = b + rng() % 11;\n    bigint\
    \ A{a}, B{b};\n\n    i128 p = i128(a) * b;\n    auto S = i128_to_string(p);\n\
    \    auto C = A * B;\n    auto D = B * A;\n\n    assert(C == D);\n    assert(C.to_string()\
    \ == S);\n    assert(D.to_string() == S);\n    assert(C == p and p == C);\n  \
    \  assert(D == p and p == D);\n    assert(C.to_i128() == p);\n    assert(D.to_i128()\
    \ == p);\n  }\n\n  // _mul_naive, _mul_fft\n  rep(t, 1000) {\n    vector<int>\
    \ a, b;\n    a.resize(rng(0, 20));\n    b.resize(rng(0, 20));\n    for (auto&\
    \ x : a) x = rng(0, TEN(9) - 1);\n    for (auto& x : b) x = rng(0, TEN(9) - 1);\n\
    \    while (!a.empty() and a.back() == 0) a.pop_back();\n    while (!b.empty()\
    \ and b.back() == 0) b.pop_back();\n    bigint::_test_private_function({false,\
    \ a}, {false, b});\n  }\n\n  // dfp\n  {\n    cerr << fixed << setprecision(21);\n\
    \    auto test_dfp = [&](string S, long double acc = 1e-18) {\n      bigint A{S};\n\
    \      auto [a, b] = A.dfp();\n      // trc(a, b, A.to_ld());\n      if (a ==\
    \ 0) {\n        assert(b == 0 and S == \"0\");\n        return;\n      }\n   \
    \   assert(1.0 <= abs(a) and abs(a) < 10.0);\n      if (S[0] == '-') {\n     \
    \   assert(b + 2 == (int)S.size());\n      } else {\n        assert(b + 1 == (int)S.size());\n\
    \      }\n      long double t1 = A.to_ld();\n      long double t2 = strtold(S.c_str(),\
    \ 0);\n      long double d = abs(t1 - t2);\n      assert(d / t2 < acc);\n    };\n\
    \    test_dfp(\"998244353\");\n    test_dfp(\"1000000000000000000\");\n    test_dfp(\"\
    123456789012345678901234567890\");\n    for (int i = -111; i <= 111; i++) {\n\
    \      test_dfp(to_string(i));\n    }\n    rep(t, 1000) {\n      long long x =\
    \ rng(-TEN(18), TEN(18));\n      test_dfp(to_string(x));\n    }\n    for (int\
    \ k = 20; k <= 60; k++) {\n      test_dfp(\"1\" + string(k, '0'));\n      test_dfp(string(k,\
    \ '9'));\n    }\n    rep(t, 1000) {\n      string s;\n      int b = rng(1, 100);\n\
    \      rep(i, 100) s.push_back(rng('0' + (i == 0), '9'));\n      if (rng() % 2)\
    \ s.insert(begin(s), '-');\n      test_dfp(s, 1e-17);\n    }\n  }\n\n  // to_ld\n\
    \  rep(t, 1000) {\n    long long x = rng(-TEN(16), TEN(16));\n    bigint A{x};\n\
    \    ll y = llround(A.to_ld());\n    assert(x == y);\n  }\n\n  // _tens\n  {\n\
    \    bigint _m;\n    /*\n    unsigned long long x = 1;\n    for (int i = 0; i\
    \ < 20; i++) {\n      assert(x == _m.tens.ten_ull(i));\n      assert(_m.tens.digit(x)\
    \ == i + 1);\n      assert(_m.tens.digit(x - 1) == (x == 1 ? 1 : i));\n      x\
    \ *= 10;\n    }\n    assert(_m.tens.digit(0) == 1);\n    assert(_m.tens.digit(1)\
    \ == 1);\n    */\n    for (int i = -_m.tens.offset; i <= _m.tens.offset; i++)\
    \ {\n      long double t1 = _m.tens.ten_ld(i);\n      long double t2 = powl(10,\
    \ i);\n      long double d = abs(t1 - t2);\n      // trc(i, t1, t2, d / t1);\n\
    \      // i < 0 -> \u6841\u843D\u3061\u304C\u767A\u751F\u3059\u308B\u305F\u3081\
    \u5C11\u3057\u9762\u5012\n      if (i <= 0) assert(d / t1 < 1e-17);\n      if\
    \ (i >= 0) assert(d / t2 < 1e-19);\n    }\n  }\n\n  {\n    auto validate_divmod\
    \ = [&](bigint a, bigint b) {\n      auto [q, r] = divmod(a, b);\n\n      i128\
    \ a2 = a.to_i128();\n      i128 b2 = b.to_i128();\n      i128 q2 = a2 / b2, r2\
    \ = a2 % b2;\n      assert(a == a2 and b == b2 and q == q2 and r == r2);\n\n \
    \     assert(q * b + r == a);\n      assert(0 <= abs(r) and abs(r) < abs(b));\n\
    \      if (a >= 0 and b > 0) {\n        assert(q >= 0 and r >= 0);\n      }\n\
    \      if (a >= 0 and b < 0) {\n        assert(q <= 0 and r >= 0);\n      }\n\
    \      if (a < 0 and b > 0) {\n        assert(q <= 0 and r <= 0);\n      }\n \
    \     if (a < 0 and b < 0) {\n        assert(q >= 0 and r <= 0);\n      }\n  \
    \  };\n    auto wrapper = [&](bigint a, bigint b) {\n      validate_divmod(+a,\
    \ +b);\n      validate_divmod(+a, -b);\n      validate_divmod(-a, +b);\n     \
    \ validate_divmod(-a, -b);\n    };\n\n    rep(t, 1000) {\n      i128 a = 0;\n\
    \      if (t < 37) {\n        a = TEN128(t);\n      } else if (t < 74) {\n   \
    \     a = TEN128(t - 37) - 1;\n      } else if (t < 100) {\n        a = t - 87;\n\
    \      } else {\n        a = rng();\n        a = (a << 63) + rng();\n      }\n\
    \      bigint A = a;\n      for (int i = 1; i <= 18; i++) {\n        wrapper(A,\
    \ i);\n        wrapper(A, TEN(i) - 1);\n      }\n      rep(_, 10) wrapper(A, rng(1,\
    \ TEN(9)));\n      rep(_, 10) wrapper(A, rng(1, TEN(18)));\n      rep(_, 10) wrapper(A,\
    \ rng128(27));\n    }\n  }\n\n  // divmod\n  {\n    auto validate_divmod2 = [&](bigint\
    \ a, bigint b) {\n      auto [q, r] = divmod(a, b);\n\n      bigint a2 = bigint(a.to_string());\n\
    \      bigint b2 = bigint(b.to_string());\n      bigint q2 = bigint(q.to_string());\n\
    \      bigint r2 = bigint(r.to_string());\n      assert(a == a2 and b == b2 and\
    \ q == q2 and r == r2);\n\n      assert(q * b + r == a);\n      assert(0 <= abs(r)\
    \ and abs(r) < abs(b));\n      if (a >= 0 and b > 0) {\n        assert(q >= 0\
    \ and r >= 0);\n      }\n      if (a >= 0 and b < 0) {\n        assert(q <= 0\
    \ and r >= 0);\n      }\n      if (a < 0 and b > 0) {\n        assert(q <= 0 and\
    \ r <= 0);\n      }\n      if (a < 0 and b < 0) {\n        assert(q >= 0 and r\
    \ <= 0);\n      }\n    };\n    auto wrapper = [&](bigint a, bigint b) {\n    \
    \  validate_divmod2(+a, +b);\n      validate_divmod2(+a, -b);\n      validate_divmod2(-a,\
    \ +b);\n      validate_divmod2(-a, -b);\n    };\n\n    rep(t, 1000) {\n      vector<int>\
    \ a, b;\n      a.resize(rng(0, 20));\n      b.resize(rng(0, 20));\n      for (auto&\
    \ x : a) x = rng(0, TEN(9) - 1);\n      for (auto& x : b) x = rng(0, TEN(9) -\
    \ 1);\n      while (!a.empty() and a.back() == 0) a.pop_back();\n      while (!b.empty()\
    \ and b.back() == 0) b.pop_back();\n      bigint A{false, a}, B{false, b};\n \
    \     if (!A.is_zero()) wrapper(B, A);\n      if (!B.is_zero()) wrapper(A, B);\n\
    \    }\n  }\n  cerr << \"OK\" << endl;\n}\n\nvoid Nyaan::solve() {\n  test();\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - math/bigint.hpp
  - internal/internal-type-traits.hpp
  - ntt/arbitrary-ntt.hpp
  - modint/montgomery-modint.hpp
  - ntt/ntt.hpp
  - misc/rng.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/bigint.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 20:50:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/bigint.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/bigint.test.cpp
- /verify/verify/verify-unit-test/bigint.test.cpp.html
title: verify/verify-unit-test/bigint.test.cpp
---
