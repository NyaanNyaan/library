---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  - icon: ':heavy_check_mark:'
    path: lct/lazy-reversible-bbst-base.hpp
    title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\
      \u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)"
  - icon: ':heavy_check_mark:'
    path: lct/link-cut-base.hpp
    title: Link/Cut Tree(base)
  - icon: ':heavy_check_mark:'
    path: lct/link-cut-tree-lazy.hpp
    title: "\u9045\u5EF6\u4F1D\u642CLink/Cut Tree"
  - icon: ':heavy_check_mark:'
    path: lct/splay-base.hpp
    title: Splay Tree(base)
  - icon: ':heavy_check_mark:'
    path: lct/splay-lazy-reversible.hpp
    title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FDSplay Tree"
  - icon: ':heavy_check_mark:'
    path: math/affine-transformation.hpp
    title: "\u30A2\u30D5\u30A3\u30F3\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n#include\
    \ <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
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
    \ 4 \"verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp\"\
    \n//\nusing namespace Nyaan;\n\n#line 2 \"modint/montgomery-modint.hpp\"\n\ntemplate\
    \ <uint32_t mod>\nstruct LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n\
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
    \ { return mod; }\n};\n#line 8 \"verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp\"\
    \nusing mint = LazyMontgomeryModInt<998244353>;\nusing vm = vector<mint>;\n#line\
    \ 2 \"math/affine-transformation.hpp\"\n\ntemplate <typename mint>\nstruct Affine\
    \ {\n  mint a, b;\n  constexpr Affine() : a(1), b(0) {}\n  constexpr Affine(mint\
    \ _a, mint _b) : a(_a), b(_b) {}\n  mint operator()(mint x) { return a * x + b;\
    \ }\n  // R(L(x))\n  friend Affine operator*(const Affine& l, const Affine& r)\
    \ {\n    return Affine(l.a * r.a, l.b * r.a + r.b);\n  }\n  bool operator==(const\
    \ Affine& r) const { return a == r.a && b == r.b; }\n  bool operator!=(const Affine&\
    \ r) const { return a != r.a || b != r.b; }\n  friend ostream& operator<<(ostream&\
    \ os, const Affine& r) {\n    os << \"( \" << r.a << \", \" << r.b << \" )\";\n\
    \    return os;\n  }\n};\n\n/**\n * @brief \u30A2\u30D5\u30A3\u30F3\u5909\u63DB\
    \n */\n#line 2 \"misc/fastio.hpp\"\n\n#line 8 \"misc/fastio.hpp\"\n\nusing namespace\
    \ std;\n\n#line 2 \"internal/internal-type-traits.hpp\"\n\n#line 4 \"internal/internal-type-traits.hpp\"\
    \nusing namespace std;\n\nnamespace internal {\ntemplate <typename T>\nusing is_broadly_integral\
    \ =\n    typename conditional_t<is_integral_v<T> || is_same_v<T, __int128_t> ||\n\
    \                               is_same_v<T, __uint128_t>,\n                 \
    \          true_type, false_type>::type;\n\ntemplate <typename T>\nusing is_broadly_signed\
    \ =\n    typename conditional_t<is_signed_v<T> || is_same_v<T, __int128_t>,\n\
    \                           true_type, false_type>::type;\n\ntemplate <typename\
    \ T>\nusing is_broadly_unsigned =\n    typename conditional_t<is_unsigned_v<T>\
    \ || is_same_v<T, __uint128_t>,\n                           true_type, false_type>::type;\n\
    \n#define ENABLE_VALUE(x) \\\n  template <typename T> \\\n  constexpr bool x##_v\
    \ = x<T>::value;\n\nENABLE_VALUE(is_broadly_integral);\nENABLE_VALUE(is_broadly_signed);\n\
    ENABLE_VALUE(is_broadly_unsigned);\n#undef ENABLE_VALUE\n\n#define ENABLE_HAS_TYPE(var)\
    \                                              \\\n  template <class, class =\
    \ void>                                         \\\n  struct has_##var : std::false_type\
    \ {};                                 \\\n  template <class T>               \
    \                                      \\\n  struct has_##var<T, std::void_t<typename\
    \ T::var>> : std::true_type {}; \\\n  template <class T>                     \
    \                                \\\n  constexpr auto has_##var##_v = has_##var<T>::value;\n\
    \n}  // namespace internal\n#line 12 \"misc/fastio.hpp\"\n\nnamespace fastio {\n\
    static constexpr int SZ = 1 << 17;\nstatic constexpr int offset = 64;\nchar inbuf[SZ],\
    \ outbuf[SZ];\nint in_left = 0, in_right = 0, out_right = 0;\n\nstruct Pre {\n\
    \  char num[40000];\n  constexpr Pre() : num() {\n    for (int i = 0; i < 10000;\
    \ i++) {\n      int n = i;\n      for (int j = 3; j >= 0; j--) {\n        num[i\
    \ * 4 + j] = n % 10 + '0';\n        n /= 10;\n      }\n    }\n  }\n} constexpr\
    \ pre;\n\nvoid load() {\n  int len = in_right - in_left;\n  memmove(inbuf, inbuf\
    \ + in_left, len);\n  in_right = len + fread(inbuf + len, 1, SZ - len, stdin);\n\
    \  in_left = 0;\n}\nvoid flush() {\n  fwrite(outbuf, 1, out_right, stdout);\n\
    \  out_right = 0;\n}\nvoid skip_space() {\n  if (in_left + offset > in_right)\
    \ load();\n  while (inbuf[in_left] <= ' ') in_left++;\n}\n\nvoid single_read(char&\
    \ c) {\n  if (in_left + offset > in_right) load();\n  skip_space();\n  c = inbuf[in_left++];\n\
    }\nvoid single_read(string& S) {\n  skip_space();\n  while (true) {\n    if (in_left\
    \ == in_right) load();\n    int i = in_left;\n    for (; i != in_right; i++) {\n\
    \      if (inbuf[i] <= ' ') break;\n    }\n    copy(inbuf + in_left, inbuf + i,\
    \ back_inserter(S));\n    in_left = i;\n    if (i != in_right) break;\n  }\n}\n\
    template <typename T,\n          enable_if_t<internal::is_broadly_integral_v<T>>*\
    \ = nullptr>\nvoid single_read(T& x) {\n  if (in_left + offset > in_right) load();\n\
    \  skip_space();\n  char c = inbuf[in_left++];\n  [[maybe_unused]] bool minus\
    \ = false;\n  if constexpr (internal::is_broadly_signed_v<T>) {\n    if (c ==\
    \ '-') minus = true, c = inbuf[in_left++];\n  }\n  x = 0;\n  while (c >= '0')\
    \ {\n    x = x * 10 + (c & 15);\n    c = inbuf[in_left++];\n  }\n  if constexpr\
    \ (internal::is_broadly_signed_v<T>) {\n    if (minus) x = -x;\n  }\n}\nvoid rd()\
    \ {}\ntemplate <typename Head, typename... Tail>\nvoid rd(Head& head, Tail&...\
    \ tail) {\n  single_read(head);\n  rd(tail...);\n}\n\nvoid single_write(const\
    \ char& c) {\n  if (out_right > SZ - offset) flush();\n  outbuf[out_right++] =\
    \ c;\n}\nvoid single_write(const bool& b) {\n  if (out_right > SZ - offset) flush();\n\
    \  outbuf[out_right++] = b ? '1' : '0';\n}\nvoid single_write(const string& S)\
    \ {\n  int i = 0;\n  while (i != (int)S.size()) {\n    if (out_right == SZ) flush();\n\
    \    int len = min((int)S.size() - i, SZ - out_right);\n    memcpy(outbuf + out_right,\
    \ S.data() + i, sizeof(char) * len);\n    i += len, out_right += len;\n  }\n}\n\
    void single_write(const char* p) {\n  int i = 0, N = strlen(p);\n  while (i !=\
    \ N) {\n    if (out_right == SZ) flush();\n    int len = min(N - i, SZ - out_right);\n\
    \    memcpy(outbuf + out_right, p + i, sizeof(char) * len);\n    i += len, out_right\
    \ += len;\n  }\n}\ntemplate <typename T,\n          enable_if_t<internal::is_broadly_integral_v<T>>*\
    \ = nullptr>\nvoid single_write(const T& _x) {\n  if (out_right > SZ - offset)\
    \ flush();\n  if (_x == 0) {\n    outbuf[out_right++] = '0';\n    return;\n  }\n\
    \  T x = _x;\n  if constexpr (internal::is_broadly_signed_v<T>) {\n    if (x <\
    \ 0) outbuf[out_right++] = '-', x = -x;\n  }\n  constexpr int buffer_size = sizeof(T)\
    \ * 10 / 4;\n  char buf[buffer_size];\n  int i = buffer_size;\n  while (x >= 10000)\
    \ {\n    i -= 4;\n    memcpy(buf + i, pre.num + (x % 10000) * 4, 4);\n    x /=\
    \ 10000;\n  }\n  if (x < 100) {\n    if (x < 10) {\n      outbuf[out_right] =\
    \ '0' + x;\n      ++out_right;\n    } else {\n      uint32_t q = (uint32_t(x)\
    \ * 205) >> 11;\n      uint32_t r = uint32_t(x) - q * 10;\n      outbuf[out_right]\
    \ = '0' + q;\n      outbuf[out_right + 1] = '0' + r;\n      out_right += 2;\n\
    \    }\n  } else {\n    if (x < 1000) {\n      memcpy(outbuf + out_right, pre.num\
    \ + (x << 2) + 1, 3);\n      out_right += 3;\n    } else {\n      memcpy(outbuf\
    \ + out_right, pre.num + (x << 2), 4);\n      out_right += 4;\n    }\n  }\n  memcpy(outbuf\
    \ + out_right, buf + i, buffer_size - i);\n  out_right += buffer_size - i;\n}\n\
    void wt() {}\ntemplate <typename Head, typename... Tail>\nvoid wt(const Head&\
    \ head, const Tail&... tail) {\n  single_write(head);\n  wt(forward<const Tail>(tail)...);\n\
    }\ntemplate <typename... Args>\nvoid wtn(const Args&... x) {\n  wt(forward<const\
    \ Args>(x)...);\n  wt('\\n');\n}\n\nstruct Dummy {\n  Dummy() { atexit(flush);\
    \ }\n} dummy;\n\n}  // namespace fastio\nusing fastio::rd;\nusing fastio::skip_space;\n\
    using fastio::wt;\nusing fastio::wtn;\n#line 12 \"verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp\"\
    \n//\n#line 2 \"lct/link-cut-tree-lazy.hpp\"\n\n#line 2 \"lct/splay-lazy-reversible.hpp\"\
    \n\n#line 2 \"lct/lazy-reversible-bbst-base.hpp\"\n\ntemplate <typename Tree,\
    \ typename Node, typename T, typename E, T (*f)(T, T),\n          T (*g)(T, E),\
    \ E (*h)(E, E), T (*ts)(T)>\nstruct LazyReversibleBBST : Tree {\n  using Tree::merge;\n\
    \  using Tree::split;\n  using typename Tree::Ptr;\n\n  LazyReversibleBBST() =\
    \ default;\n\n  void toggle(Ptr t) {\n    swap(t->l, t->r);\n    t->sum = ts(t->sum);\n\
    \    t->rev ^= true;\n  }\n\n  T fold(Ptr &t, int a, int b) {\n    auto x = split(t,\
    \ a);\n    auto y = split(x.second, b - a);\n    auto ret = sum(y.first);\n  \
    \  t = merge(x.first, merge(y.first, y.second));\n    return ret;\n  }\n\n  void\
    \ reverse(Ptr &t, int a, int b) {\n    auto x = split(t, a);\n    auto y = split(x.second,\
    \ b - a);\n    toggle(y.first);\n    t = merge(x.first, merge(y.first, y.second));\n\
    \  }\n\n  void apply(Ptr &t, int a, int b, const E &e) {\n    auto x = split(t,\
    \ a);\n    auto y = split(x.second, b - a);\n    propagate(y.first, e);\n    t\
    \ = merge(x.first, merge(y.first, y.second));\n  }\n\n protected:\n  inline T\
    \ sum(const Ptr t) { return t ? t->sum : T(); }\n\n  Ptr update(Ptr t) override\
    \ {\n    if (!t) return t;\n    t->cnt = 1;\n    t->sum = t->key;\n    if (t->l)\
    \ t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n    if (t->r) t->cnt +=\
    \ t->r->cnt, t->sum = f(t->sum, t->r->sum);\n    return t;\n  }\n\n  void push(Ptr\
    \ t) override {\n    if (!t) return;\n    if (t->rev) {\n      if (t->l) toggle(t->l);\n\
    \      if (t->r) toggle(t->r);\n      t->rev = false;\n    }\n    if (t->lazy\
    \ != E()) {\n      if (t->l) propagate(t->l, t->lazy);\n      if (t->r) propagate(t->r,\
    \ t->lazy);\n      t->lazy = E();\n    }\n  }\n\n  void propagate(Ptr t, const\
    \ E &x) {\n    t->lazy = h(t->lazy, x);\n    t->key = g(t->key, x);\n    t->sum\
    \ = g(t->sum, x);\n  }\n};\n\n/**\n * @brief \u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\
    \u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)\n */\n\
    #line 2 \"lct/splay-base.hpp\"\n\ntemplate <typename Node>\nstruct SplayTreeBase\
    \ {\n  using Ptr = Node *;\n  template <typename... Args>\n  Ptr my_new(const\
    \ Args &... args) {\n    return new Node(args...);\n  }\n  void my_del(Ptr p)\
    \ { delete p; }\n\n  bool is_root(Ptr t) { return !(t->p) || (t->p->l != t &&\
    \ t->p->r != t); }\n\n  int size(Ptr t) const { return count(t); }\n\n  virtual\
    \ void splay(Ptr t) {\n    push(t);\n    while (!is_root(t)) {\n      Ptr q =\
    \ t->p;\n      if (is_root(q)) {\n        push(q), push(t);\n        rot(t);\n\
    \      } else {\n        Ptr r = q->p;\n        push(r), push(q), push(t);\n \
    \       if (pos(q) == pos(t))\n          rot(q), rot(t);\n        else\n     \
    \     rot(t), rot(t);\n      }\n    }\n  }\n\n  Ptr get_left(Ptr t) {\n    while\
    \ (t->l) push(t), t = t->l;\n    return t;\n  }\n\n  Ptr get_right(Ptr t) {\n\
    \    while (t->r) push(t), t = t->r;\n    return t;\n  }\n\n  pair<Ptr, Ptr> split(Ptr\
    \ t, int k) {\n    if (!t) return {nullptr, nullptr};\n    if (k == 0) return\
    \ {nullptr, t};\n    if (k == count(t)) return {t, nullptr};\n    push(t);\n \
    \   if (k <= count(t->l)) {\n      auto x = split(t->l, k);\n      t->l = x.second;\n\
    \      t->p = nullptr;\n      if (x.second) x.second->p = t;\n      return {x.first,\
    \ update(t)};\n    } else {\n      auto x = split(t->r, k - count(t->l) - 1);\n\
    \      t->r = x.first;\n      t->p = nullptr;\n      if (x.first) x.first->p =\
    \ t;\n      return {update(t), x.second};\n    }\n  }\n\n  Ptr merge(Ptr l, Ptr\
    \ r) {\n    if (!l && !r) return nullptr;\n    if (!l) return splay(r), r;\n \
    \   if (!r) return splay(l), l;\n    splay(l), splay(r);\n    l = get_right(l);\n\
    \    splay(l);\n    l->r = r;\n    r->p = l;\n    update(l);\n    return l;\n\
    \  }\n\n  using Key = decltype(Node::key);\n  Ptr build(const vector<Key> &v)\
    \ { return build(0, v.size(), v); }\n  Ptr build(int l, int r, const vector<Key>\
    \ &v) {\n    if (l + 1 >= r) return my_new(v[l]);\n    return merge(build(l, (l\
    \ + r) >> 1, v), build((l + r) >> 1, r, v));\n  }\n\n  template <typename... Args>\n\
    \  void insert(Ptr &t, int k, const Args &... args) {\n    splay(t);\n    auto\
    \ x = split(t, k);\n    t = merge(merge(x.first, my_new(args...)), x.second);\n\
    \  }\n\n  void erase(Ptr &t, int k) {\n    splay(t);\n    auto x = split(t, k);\n\
    \    auto y = split(x.second, 1);\n    my_del(y.first);\n    t = merge(x.first,\
    \ y.second);\n  }\n\n  virtual Ptr update(Ptr t) = 0;\n\n protected:\n  inline\
    \ int count(Ptr t) const { return t ? t->cnt : 0; }\n\n  virtual void push(Ptr\
    \ t) = 0;\n\n  Ptr build(const vector<Ptr> &v) { return build(0, v.size(), v);\
    \ }\n\n  Ptr build(int l, int r, const vector<Ptr> &v) {\n    if (l + 1 >= r)\
    \ return v[l];\n    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1,\
    \ r, v));\n  }\n\n  inline int pos(Ptr t) {\n    if (t->p) {\n      if (t->p->l\
    \ == t) return -1;\n      if (t->p->r == t) return 1;\n    }\n    return 0;\n\
    \  }\n\n  virtual void rot(Ptr t) {\n    Ptr x = t->p, y = x->p;\n    if (pos(t)\
    \ == -1) {\n      if ((x->l = t->r)) t->r->p = x;\n      t->r = x, x->p = t;\n\
    \    } else {\n      if ((x->r = t->l)) t->l->p = x;\n      t->l = x, x->p = t;\n\
    \    }\n    update(x), update(t);\n    if ((t->p = y)) {\n      if (y->l == x)\
    \ y->l = t;\n      if (y->r == x) y->r = t;\n    }\n  }\n};\n\n/**\n * @brief\
    \ Splay Tree(base)\n */\n#line 5 \"lct/splay-lazy-reversible.hpp\"\n\ntemplate\
    \ <typename T, typename E>\nstruct LazyReversibleSplayTreeNode {\n  using Ptr\
    \ = LazyReversibleSplayTreeNode *;\n  Ptr l, r, p;\n  T key, sum;\n  E lazy;\n\
    \  int cnt;\n  bool rev;\n\n  LazyReversibleSplayTreeNode(const T &t = T(), const\
    \ E &e = E())\n      : l(), r(), p(), key(t), sum(t), lazy(e), cnt(1), rev(false)\
    \ {}\n};\n\ntemplate <typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E,\
    \ E),\n          T (*ts)(T)>\nstruct LazyReversibleSplayTree\n    : LazyReversibleBBST<SplayTreeBase<LazyReversibleSplayTreeNode<T,\
    \ E>>,\n                         LazyReversibleSplayTreeNode<T, E>, T, E, f, g,\
    \ h, ts> {\n  using Node = LazyReversibleSplayTreeNode<T, E>;\n};\n\n/**\n * @brief\
    \ \u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FDSplay Tree\n */\n#line 4 \"\
    lct/link-cut-tree-lazy.hpp\"\n\n//\n#line 2 \"lct/link-cut-base.hpp\"\n\ntemplate\
    \ <typename Splay>\nstruct LinkCutBase : Splay {\n  using Node = typename Splay::Node;\n\
    \  using Ptr = Node*;\n\n  virtual Ptr expose(Ptr t) {\n    Ptr rp = nullptr;\n\
    \    for (Ptr cur = t; cur; cur = cur->p) {\n      this->splay(cur);\n      cur->r\
    \ = rp;\n      this->update(cur);\n      rp = cur;\n    }\n    this->splay(t);\n\
    \    return rp;\n  }\n\n  virtual void link(Ptr u, Ptr v) {\n    evert(u);\n \
    \   expose(v);\n    u->p = v;\n  }\n\n  void cut(Ptr u, Ptr v) {\n    evert(u);\n\
    \    expose(v);\n    assert(u->p == v);\n    v->l = u->p = nullptr;\n    this->update(v);\n\
    \  }\n\n  void evert(Ptr t) {\n    expose(t);\n    this->toggle(t);\n    this->push(t);\n\
    \  }\n\n  Ptr lca(Ptr u, Ptr v) {\n    if (get_root(u) != get_root(v)) return\
    \ nullptr;\n    expose(u);\n    return expose(v);\n  }\n\n  Ptr get_kth(Ptr x,\
    \ int k) {\n    expose(x);\n    while (x) {\n      this->push(x);\n      if (x->r\
    \ && x->r->sz > k) {\n        x = x->r;\n      } else {\n        if (x->r) k -=\
    \ x->r->sz;\n        if (k == 0) return x;\n        k -= 1;\n        x = x->l;\n\
    \      }\n    }\n    return nullptr;\n  }\n\n  Ptr get_root(Ptr x) {\n    expose(x);\n\
    \    while (x->l) this->push(x), x = x->l;\n    return x;\n  }\n\n  Ptr get_parent(Ptr\
    \ x) {\n    expose(x);\n    Ptr p = x->l;\n    if(p == nullptr) return nullptr;\n\
    \    while (true) {\n      this->push(p);\n      if (p->r == nullptr) return p;\n\
    \      p = p->r;\n    }\n    exit(1);\n  }\n\n  virtual void set_key(Ptr t, const\
    \ decltype(Node::key)& key) {\n    this->splay(t);\n    t->key = key;\n    this->update(t);\n\
    \  }\n\n  virtual decltype(Node::key) get_key(Ptr t) { return t->key; }\n\n  decltype(Node::key)\
    \ fold(Ptr u, Ptr v) {\n    evert(u);\n    expose(v);\n    return v->sum;\n  }\n\
    };\n\n/**\n * @brief Link/Cut Tree(base)\n * @docs docs/lct/link-cut-tree.md\n\
    \ */\n#line 7 \"lct/link-cut-tree-lazy.hpp\"\n\ntemplate <typename T, typename\
    \ E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),\n          T (*ts)(T)>\nstruct\
    \ LazyLinkCutTree\n    : LinkCutBase<LazyReversibleSplayTree<T, E, f, g, h, ts>>\
    \ {\n  using base = LinkCutBase<LazyReversibleSplayTree<T, E, f, g, h, ts>>;\n\
    \  using Ptr = typename base::Ptr;\n\n  void set_key(Ptr t, const T& key) override\
    \ {\n    this->evert(t);\n    t->key = key;\n    this->update(t);\n  }\n\n  T\
    \ get_key(Ptr t) override {\n    this->evert(t);\n    return t->key;\n  }\n\n\
    \  void apply(Ptr u, Ptr v, const E& e) {\n    this->evert(u);\n    this->expose(v);\n\
    \    this->propagate(v, e);\n  }\n};\n\n/**\n * @brief \u9045\u5EF6\u4F1D\u642C\
    Link/Cut Tree\n */\n#line 14 \"verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp\"\
    \n//\n\nusing T = pair<mint, mint>;\nusing E = Affine<mint>;\nT f(T a, T b) {\
    \ return T(a.first + b.first, a.second + b.second); }\nT g(T a, E b) { return\
    \ T(a.first * b.a + a.second * b.b, a.second); }\nE h(E a, E b) { return a * b;\
    \ };\nT ts(T a) { return a; }\n\nusing namespace Nyaan;\nvoid Nyaan::solve() {\n\
    \  int N, Q;\n  rd(N, Q);\n\n  using LCT = LazyLinkCutTree<T, E, f, g, h, ts>;\n\
    \  LCT lct;\n\n  vector<LCT::Ptr> vs(N);\n  rep(i, N) {\n    int a;\n    rd(a);\n\
    \    vs[i] = lct.my_new(T(a, 1));\n  }\n\n  for (int i = 1; i < N; i++) lct.link(vs[i\
    \ - 1], vs[i]);\n\n  while (Q--) {\n    int cmd;\n    rd(cmd);\n    if (cmd ==\
    \ 0) {\n      int l, r, b, c;\n      rd(l, r, b, c);\n      lct.apply(vs[l], vs[r\
    \ - 1], E(b, c));\n    } else {\n      int l, r;\n      rd(l, r);\n      T fold\
    \ = lct.fold(vs[l], vs[r - 1]);\n      wtn(fold.first.get());\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../../template/template.hpp\"\n//\nusing namespace Nyaan;\n\n#include\
    \ \"../../modint/montgomery-modint.hpp\"\nusing mint = LazyMontgomeryModInt<998244353>;\n\
    using vm = vector<mint>;\n#include \"../../math/affine-transformation.hpp\"\n\
    #include \"../../misc/fastio.hpp\"\n//\n#include \"../../lct/link-cut-tree-lazy.hpp\"\
    \n//\n\nusing T = pair<mint, mint>;\nusing E = Affine<mint>;\nT f(T a, T b) {\
    \ return T(a.first + b.first, a.second + b.second); }\nT g(T a, E b) { return\
    \ T(a.first * b.a + a.second * b.b, a.second); }\nE h(E a, E b) { return a * b;\
    \ };\nT ts(T a) { return a; }\n\nusing namespace Nyaan;\nvoid Nyaan::solve() {\n\
    \  int N, Q;\n  rd(N, Q);\n\n  using LCT = LazyLinkCutTree<T, E, f, g, h, ts>;\n\
    \  LCT lct;\n\n  vector<LCT::Ptr> vs(N);\n  rep(i, N) {\n    int a;\n    rd(a);\n\
    \    vs[i] = lct.my_new(T(a, 1));\n  }\n\n  for (int i = 1; i < N; i++) lct.link(vs[i\
    \ - 1], vs[i]);\n\n  while (Q--) {\n    int cmd;\n    rd(cmd);\n    if (cmd ==\
    \ 0) {\n      int l, r, b, c;\n      rd(l, r, b, c);\n      lct.apply(vs[l], vs[r\
    \ - 1], E(b, c));\n    } else {\n      int l, r;\n      rd(l, r);\n      T fold\
    \ = lct.fold(vs[l], vs[r - 1]);\n      wtn(fold.first.get());\n    }\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - modint/montgomery-modint.hpp
  - math/affine-transformation.hpp
  - misc/fastio.hpp
  - internal/internal-type-traits.hpp
  - lct/link-cut-tree-lazy.hpp
  - lct/splay-lazy-reversible.hpp
  - lct/lazy-reversible-bbst-base.hpp
  - lct/splay-base.hpp
  - lct/link-cut-base.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 20:50:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp
---
