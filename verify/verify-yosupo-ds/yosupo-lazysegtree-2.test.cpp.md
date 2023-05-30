---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: segment-tree/lazy-segment-tree-utility.hpp
    title: "\u4F7F\u7528\u983B\u5EA6\u306E\u9AD8\u3044\u9045\u5EF6\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728"
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
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-lazysegtree-2.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n//\n\
    #line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n#include\
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
    \ 4 \"verify/verify-yosupo-ds/yosupo-lazysegtree-2.test.cpp\"\n//\n#line 2 \"\
    modint/montgomery-modint.hpp\"\n\ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt\
    \ {\n  using mint = LazyMontgomeryModInt;\n  using i32 = int32_t;\n  using u32\
    \ = uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr u32 get_r() {\n \
    \   u32 ret = mod;\n    for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n  \
    \  return ret;\n  }\n\n  static constexpr u32 r = get_r();\n  static constexpr\
    \ u32 n2 = -u64(mod) % mod;\n  static_assert(mod < (1 << 30), \"invalid, mod >=\
    \ 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"invalid, mod % 2 == 0\");\n  static_assert(r\
    \ * mod == 1, \"this code has bugs.\");\n\n  u32 a;\n\n  constexpr LazyMontgomeryModInt()\
    \ : a(0) {}\n  constexpr LazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b\
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
    \ { return mod; }\n};\n#line 2 \"segment-tree/lazy-segment-tree-utility.hpp\"\n\
    \ntemplate <typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),\n\
    \          T (*ti)(), E (*ei)()>\nstruct LazySegmentTreeBase {\n  int n, log,\
    \ s;\n  vector<T> val;\n  vector<E> laz;\n\n  explicit LazySegmentTreeBase() {}\n\
    \  explicit LazySegmentTreeBase(const vector<T>& vc) { init(vc); }\n\n  void init(const\
    \ vector<T>& vc) {\n    n = 1, log = 0, s = vc.size();\n    while (n < s) n <<=\
    \ 1, log++;\n    val.resize(2 * n, ti());\n    laz.resize(n, ei());\n    for (int\
    \ i = 0; i < s; ++i) val[i + n] = vc[i];\n    for (int i = n - 1; i; --i) _update(i);\n\
    \  }\n\n  void update(int l, int r, const E& x) {\n    if (l == r) return;\n \
    \   l += n, r += n;\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i)\
    \ << i) != l) _push(l >> i);\n      if (((r >> i) << i) != r) _push((r - 1) >>\
    \ i);\n    }\n    {\n      int l2 = l, r2 = r;\n      while (l < r) {\n      \
    \  if (l & 1) _apply(l++, x);\n        if (r & 1) _apply(--r, x);\n        l >>=\
    \ 1;\n        r >>= 1;\n      }\n      l = l2;\n      r = r2;\n    }\n    for\
    \ (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l) _update(l >> i);\n\
    \      if (((r >> i) << i) != r) _update((r - 1) >> i);\n    }\n  }\n\n  T query(int\
    \ l, int r) {\n    if (l == r) return ti();\n    l += n, r += n;\n    T L = ti(),\
    \ R = ti();\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) !=\
    \ l) _push(l >> i);\n      if (((r >> i) << i) != r) _push((r - 1) >> i);\n  \
    \  }\n    while (l < r) {\n      if (l & 1) L = f(L, val[l++]);\n      if (r &\
    \ 1) R = f(val[--r], R);\n      l >>= 1;\n      r >>= 1;\n    }\n    return f(L,\
    \ R);\n  }\n\n  void set_val(int k, const T& x) {\n    k += n;\n    for (int i\
    \ = log; i >= 1; i--) {\n      if (((k >> i) << i) != k || (((k + 1) >> i) <<\
    \ i) != (k + 1))\n        _push(k >> i);\n    }\n    val[k] = x;\n    for (int\
    \ i = 1; i <= log; i++) {\n      if (((k >> i) << i) != k || (((k + 1) >> i) <<\
    \ i) != (k + 1))\n        _update(k >> i);\n    }\n  }\n\n  void update_val(int\
    \ k, const E& x) {\n    k += n;\n    for (int i = log; i >= 1; i--) {\n      if\
    \ (((k >> i) << i) != k || (((k + 1) >> i) << i) != (k + 1))\n        _push(k\
    \ >> i);\n    }\n    val[k] = g(val[k], x);\n    for (int i = 1; i <= log; i++)\
    \ {\n      if (((k >> i) << i) != k || (((k + 1) >> i) << i) != (k + 1))\n   \
    \     _update(k >> i);\n    }\n  }\n\n  T get_val(int k) {\n    k += n;\n    for\
    \ (int i = log; i >= 1; i--) {\n      if (((k >> i) << i) != k || (((k + 1) >>\
    \ i) << i) != (k + 1))\n        _push(k >> i);\n    }\n    return val[k];\n  }\n\
    \n  template <class G>\n  int max_right(int l, G check) {\n    assert(0 <= l &&\
    \ l <= s);\n    assert(check(ei()));\n    if (l == n) return n;\n    l += n;\n\
    \    for (int i = log; i >= 1; i--) _push(l >> i);\n    T sm = ti();\n    do {\n\
    \      while (l % 2 == 0) l >>= 1;\n      if (!check(f(sm, val[l]))) {\n     \
    \   while (l < n) {\n          _push(l);\n          l = (2 * l);\n          if\
    \ (check(f(sm, val[l]))) {\n            sm = f(sm, val[l]);\n            l++;\n\
    \          }\n        }\n        return l - n;\n      }\n      sm = f(sm, val[l]);\n\
    \      l++;\n    } while ((l & -l) != l);\n    return s;\n  }\n\n  template <class\
    \ G>\n  int min_left(int r, G check) {\n    assert(0 <= r && r <= s);\n    assert(check(ei()));\n\
    \    if (r == 0) return 0;\n    r += n;\n    for (int i = log; i >= 1; i--) _push((r\
    \ - 1) >> i);\n    T sm = ti();\n    do {\n      r--;\n      while (r > 1 && (r\
    \ % 2)) r >>= 1;\n      if (!check(f(val[r], sm))) {\n        while (r < n) {\n\
    \          _push(r);\n          r = (2 * r + 1);\n          if (check(f(val[r],\
    \ sm))) {\n            sm = f(val[r], sm);\n            r--;\n          }\n  \
    \      }\n        return r + 1 - n;\n      }\n      sm = f(val[r], sm);\n    }\
    \ while ((r & -r) != r);\n    return 0;\n  }\n\n private:\n  void _push(int i)\
    \ {\n    if (laz[i] != ei()) {\n      val[2 * i + 0] = g(val[2 * i + 0], laz[i]);\n\
    \      val[2 * i + 1] = g(val[2 * i + 1], laz[i]);\n      if (2 * i < n) {\n \
    \       compose(laz[2 * i + 0], laz[i]);\n        compose(laz[2 * i + 1], laz[i]);\n\
    \      }\n      laz[i] = ei();\n    }\n  }\n  inline void _update(int i) { val[i]\
    \ = f(val[2 * i + 0], val[2 * i + 1]); }\n  inline void _apply(int i, const E&\
    \ x) {\n    if (x != ei()) {\n      val[i] = g(val[i], x);\n      if (i < n) compose(laz[i],\
    \ x);\n    }\n  }\n  inline void compose(E& a, const E& b) { a = a == ei() ? b\
    \ : h(a, b); }\n};\n\nnamespace SegmentTreeUtil {\n\ntemplate <typename T>\nstruct\
    \ Pair {\n  T first, second;\n  Pair() = default;\n  Pair(const T& f, const T&\
    \ s) : first(f), second(s) {}\n  operator T() const { return first; }\n  friend\
    \ ostream& operator<<(ostream& os, const Pair<T>& p) {\n    os << T(p.first);\n\
    \    return os;\n  }\n};\n\ntemplate <typename T>\nT Mx(T a, T b) {\n  return\
    \ max(a, b);\n}\ntemplate <typename T>\nT Mn(T a, T b) {\n  return min(a, b);\n\
    }\ntemplate <typename T>\nT Update(T, T b) {\n  return b;\n}\ntemplate <typename\
    \ T>\nT Add(T a, T b) {\n  return a + b;\n}\ntemplate <typename T>\nPair<T> Psum(Pair<T>\
    \ a, Pair<T> b) {\n  return Pair<T>(a.first + b.first, a.second + b.second);\n\
    }\ntemplate <typename T>\nPair<T> Padd(Pair<T> a, T b) {\n  return Pair<T>(a.first\
    \ + a.second * b, a.second);\n}\ntemplate <typename T>\nPair<T> PUpdate(Pair<T>\
    \ a, T b) {\n  return Pair<T>(a.second * b, a.second);\n}\ntemplate <typename\
    \ T>\nPair<T> Pid() {\n  return Pair<T>(0, 0);\n}\ntemplate <typename T>\nT Zero()\
    \ {\n  return T(0);\n}\ntemplate <typename T, T val>\nT Const() {\n  return val;\n\
    }\n\ntemplate <typename T, T MINF>\nstruct AddMax_LazySegmentTree\n    : LazySegmentTreeBase<T,\
    \ T, Mx<T>, Add<T>, Add<T>, Const<T, MINF>, Zero<T>> {\n  using base =\n     \
    \ LazySegmentTreeBase<T, T, Mx<T>, Add<T>, Add<T>, Const<T, MINF>, Zero<T>>;\n\
    \  AddMax_LazySegmentTree(const vector<T>& v) : base(v) {}\n};\n\ntemplate <typename\
    \ T, T INF>\nstruct AddMin_LazySegmentTree\n    : LazySegmentTreeBase<T, T, Mn<T>,\
    \ Add<T>, Add<T>, Const<T, INF>, Zero<T>> {\n  using base =\n      LazySegmentTreeBase<T,\
    \ T, Mn<T>, Add<T>, Add<T>, Const<T, INF>, Zero<T>>;\n  AddMin_LazySegmentTree(const\
    \ vector<T>& v) : base(v) {}\n};\n\ntemplate <typename T>\nstruct AddSum_LazySegmentTree\n\
    \    : LazySegmentTreeBase<Pair<T>, T, Psum<T>, Padd<T>, Add<T>, Pid<T>, Zero<T>>\
    \ {\n  using base =\n      LazySegmentTreeBase<Pair<T>, T, Psum<T>, Padd<T>, Add<T>,\
    \ Pid<T>, Zero<T>>;\n  AddSum_LazySegmentTree(const vector<T>& v) {\n    vector<Pair<T>>\
    \ w(v.size());\n    for (int i = 0; i < (int)v.size(); i++) w[i] = Pair<T>(v[i],\
    \ 1);\n    base::init(w);\n  }\n};\n\ntemplate <typename T, T MINF>\nstruct UpdateMax_LazySegmentTree\n\
    \    : LazySegmentTreeBase<T, T, Mx<T>, Update<T>, Update<T>, Const<T, MINF>,\n\
    \                      Const<T, MINF>> {\n  using base = LazySegmentTreeBase<T,\
    \ T, Mx<T>, Update<T>, Update<T>,\n                               Const<T, MINF>,\
    \ Const<T, MINF>>;\n  UpdateMax_LazySegmentTree(const vector<T>& v) : base(v)\
    \ {}\n};\n\ntemplate <typename T, T INF>\nstruct UpdateMin_LazySegmentTree\n \
    \   : LazySegmentTreeBase<T, T, Mn<T>, Update<T>, Update<T>, Const<T, INF>,\n\
    \                      Const<T, INF>> {\n  using base = LazySegmentTreeBase<T,\
    \ T, Mn<T>, Update<T>, Update<T>, Const<T, INF>,\n                           \
    \    Const<T, INF>>;\n  UpdateMin_LazySegmentTree(const vector<T>& v) : base(v)\
    \ {}\n};\n\ntemplate <typename T, T UNUSED_VALUE>\nstruct UpdateSum_LazySegmentTree\n\
    \    : LazySegmentTreeBase<Pair<T>, T, Psum<T>, PUpdate<T>, Update<T>, Pid<T>,\n\
    \                      Const<T, UNUSED_VALUE>> {\n  using base = LazySegmentTreeBase<Pair<T>,\
    \ T, Psum<T>, PUpdate<T>, Update<T>,\n                               Pid<T>, Const<T,\
    \ UNUSED_VALUE>>;\n  UpdateSum_LazySegmentTree(const vector<T>& v) {\n    vector<Pair<T>>\
    \ w(v.size());\n    for (int i = 0; i < (int)v.size(); i++) w[i] = Pair<T>(v[i],\
    \ 1);\n    base::init(w);\n  }\n};\n\n}  // namespace SegmentTreeUtil\nusing SegmentTreeUtil::AddMax_LazySegmentTree;\n\
    using SegmentTreeUtil::AddMin_LazySegmentTree;\nusing SegmentTreeUtil::AddSum_LazySegmentTree;\n\
    using SegmentTreeUtil::UpdateMax_LazySegmentTree;\nusing SegmentTreeUtil::UpdateMin_LazySegmentTree;\n\
    using SegmentTreeUtil::UpdateSum_LazySegmentTree;\n\n/**\n * @brief \u4F7F\u7528\
    \u983B\u5EA6\u306E\u9AD8\u3044\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n * @docs docs/segment-tree/lazy-segment-tree-utility.md\n */\n#line 7 \"verify/verify-yosupo-ds/yosupo-lazysegtree-2.test.cpp\"\
    \nusing mint = LazyMontgomeryModInt<998244353>;\n\nusing Pair = pair<mint, mint>;\n\
    Pair f(Pair a, Pair b) { return Pair{a.first + b.first, a.second + b.second};\
    \ };\nPair g(Pair a, Pair b) {\n  return Pair{a.first * b.first + a.second * b.second,\
    \ a.second};\n};\nPair h(Pair a, Pair b) {\n  return Pair{a.first * b.first, a.second\
    \ * b.first + b.second};\n};\nPair ti() { return {0, 0}; }\nPair ei() { return\
    \ {1, 0}; }\n\nusing namespace Nyaan;\nvoid Nyaan::solve() {\n  ini(N, Q);\n \
    \ V<Pair> a(N, {0, 1});\n  rep(i, N) in(a[i].first);\n  LazySegmentTreeBase<Pair,\
    \ Pair, f, g, h, ti, ei> seg(a);\n\n  rep(_, Q) {\n    ini(cmd);\n    if (!cmd)\
    \ {\n      inl(l, r, b, c);\n      seg.update(l, r, {b, c});\n    } else {\n \
    \     inl(l, r);\n      out(seg.query(l, r).first);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n//\n#include \"../../template/template.hpp\"\n//\n#include \"../../modint/montgomery-modint.hpp\"\
    \n#include \"../../segment-tree/lazy-segment-tree-utility.hpp\"\nusing mint =\
    \ LazyMontgomeryModInt<998244353>;\n\nusing Pair = pair<mint, mint>;\nPair f(Pair\
    \ a, Pair b) { return Pair{a.first + b.first, a.second + b.second}; };\nPair g(Pair\
    \ a, Pair b) {\n  return Pair{a.first * b.first + a.second * b.second, a.second};\n\
    };\nPair h(Pair a, Pair b) {\n  return Pair{a.first * b.first, a.second * b.first\
    \ + b.second};\n};\nPair ti() { return {0, 0}; }\nPair ei() { return {1, 0}; }\n\
    \nusing namespace Nyaan;\nvoid Nyaan::solve() {\n  ini(N, Q);\n  V<Pair> a(N,\
    \ {0, 1});\n  rep(i, N) in(a[i].first);\n  LazySegmentTreeBase<Pair, Pair, f,\
    \ g, h, ti, ei> seg(a);\n\n  rep(_, Q) {\n    ini(cmd);\n    if (!cmd) {\n   \
    \   inl(l, r, b, c);\n      seg.update(l, r, {b, c});\n    } else {\n      inl(l,\
    \ r);\n      out(seg.query(l, r).first);\n    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - modint/montgomery-modint.hpp
  - segment-tree/lazy-segment-tree-utility.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-lazysegtree-2.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 20:50:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-lazysegtree-2.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-lazysegtree-2.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-lazysegtree-2.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-lazysegtree-2.test.cpp
---
