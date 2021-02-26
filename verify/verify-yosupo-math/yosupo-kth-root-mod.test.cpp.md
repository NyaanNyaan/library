---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: inner/inner_math.hpp
    title: inner/inner_math.hpp
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: modint/arbitrary-prime-modint.hpp
    title: modint/arbitrary-prime-modint.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint-montgomery64.hpp
    title: modint/modint-montgomery64.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/mod-kth-root.hpp
    title: kth root(Tonelli-Shanks algorithm)
  - icon: ':heavy_check_mark:'
    path: prime/fast-factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)"
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_root_mod
    links:
    - https://judge.yosupo.jp/problem/kth_root_mod
  bundledCode: "#line 1 \"verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_mod\"\n\n#line 2\
    \ \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include\
    \ <cinttypes>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
    \ <csetjmp>\n#include <csignal>\n#include <cstdarg>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <ctime>\n#include <deque>\n#include <exception>\n#include <forward_list>\n#include\
    \ <fstream>\n#include <functional>\n#include <initializer_list>\n#include <iomanip>\n\
    #include <ios>\n#include <iosfwd>\n#include <iostream>\n#include <istream>\n#include\
    \ <iterator>\n#include <limits>\n#include <list>\n#include <locale>\n#include\
    \ <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n\
    #include <queue>\n#include <random>\n#include <ratio>\n#include <regex>\n#include\
    \ <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n#include\
    \ <streambuf>\n#include <string>\n#include <system_error>\n#include <tuple>\n\
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
    \ 2 \"modulo/mod-kth-root.hpp\"\n\n\n\n#line 2 \"inner/inner_math.hpp\"\n\nnamespace\
    \ inner {\n\nusing i32 = int32_t;\nusing u32 = uint32_t;\nusing i64 = int64_t;\n\
    using u64 = uint64_t;\n\ntemplate <typename T>\nT gcd(T a, T b) {\n  while (b)\
    \ swap(a %= b, b);\n  return a;\n}\n\ntemplate <typename T>\nT inv(T a, T p) {\n\
    \  T b = p, x = 1, y = 0;\n  while (a) {\n    T q = b / a;\n    swap(a, b %= a);\n\
    \    swap(x, y -= q * x);\n  }\n  assert(b == 1);\n  return y < 0 ? y + p : y;\n\
    }\n\ntemplate <typename T, typename U>\nT modpow(T a, U n, T p) {\n  T ret = 1\
    \ % p;\n  for (; n; n >>= 1, a = U(a) * a % p)\n    if (n & 1) ret = U(ret) *\
    \ a % p;\n  return ret;\n}\n\n}  // namespace inner\n#line 2 \"modint/arbitrary-prime-modint.hpp\"\
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
    \ montgomery64::mod, montgomery64::r, montgomery64::n2;\n#line 2 \"prime/fast-factorize.hpp\"\
    \n\n#line 2 \"misc/rng.hpp\"\n\nnamespace my_rand {\n\n// [0, 2^64 - 1)\nuint64_t\
    \ rng() {\n  static uint64_t x_ =\n      uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                   chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count()) *\n      10150724397891781847ULL;\n  x_ ^= x_ <<\
    \ 7;\n  return x_ ^= x_ >> 9;\n}\n\n// [l, r)\nint64_t randint(int64_t l, int64_t\
    \ r) {\n  assert(l < r);\n  return l + rng() % (r - l);\n}\n\n// choose n numbers\
    \ from [l, r) without overlapping\nvector<int64_t> randset(int64_t l, int64_t\
    \ r, int64_t n) {\n  assert(l <= r && n <= r - l);\n  unordered_set<int64_t> s;\n\
    \  for (int64_t i = n; i; --i) {\n    int64_t m = randint(l, r + 1 - i);\n   \
    \ if (s.find(m) != s.end()) m = r - i;\n    s.insert(m);\n  }\n  vector<int64_t>\
    \ ret;\n  for (auto& x : s) ret.push_back(x);\n  return ret;\n}\n\n// [0.0, 1.0)\n\
    double rnd() {\n  union raw_cast {\n    double t;\n    uint64_t u;\n  };\n  constexpr\
    \ uint64_t p = uint64_t(1023 - 64) << 52;\n  return rng() * ((raw_cast*)(&p))->t;\n\
    }\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n\
    \  for (int loop = 0; loop < 2; loop++)\n    for (int i = 0; i < n; i++) swap(v[i],\
    \ v[randint(0, n)]);\n}\n\n}  // namespace my_rand\n\nusing my_rand::randint;\n\
    using my_rand::randset;\nusing my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n\
    #line 7 \"prime/fast-factorize.hpp\"\n\nnamespace fast_factorize {\nusing u64\
    \ = uint64_t;\n\ntemplate <typename mint>\nbool miller_rabin(u64 n, vector<u64>\
    \ as) {\n  if (mint::get_mod() != n) mint::set_mod(n);\n  u64 d = n - 1;\n  while\
    \ (~d & 1) d >>= 1;\n  mint e{1}, rev{int64_t(n - 1)};\n  for (u64 a : as) {\n\
    \    if (n <= a) break;\n    u64 t = d;\n    mint y = mint(a).pow(t);\n    while\
    \ (t != n - 1 && y != e && y != rev) {\n      y *= y;\n      t *= 2;\n    }\n\
    \    if (y != rev && t % 2 == 0) return false;\n  }\n  return true;\n}\n\nbool\
    \ is_prime(u64 n) {\n  if (~n & 1) return n == 2;\n  if (n <= 1) return false;\n\
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
    \  exit(1);\n}\n\nvector<u64> inner_factorize(u64 n) {\n  if (n <= 1) return {};\n\
    \  u64 p;\n  if (n <= (1LL << 30))\n    p = pollard_rho<ArbitraryLazyMontgomeryModInt,\
    \ uint32_t>(n);\n  else\n    p = pollard_rho<montgomery64, uint64_t>(n);\n  if\
    \ (p == n) return {p};\n  auto l = inner_factorize(p);\n  auto r = inner_factorize(n\
    \ / p);\n  copy(begin(r), end(r), back_inserter(l));\n  return l;\n}\n\nvector<u64>\
    \ factorize(u64 n) {\n  auto ret = inner_factorize(n);\n  sort(begin(ret), end(ret));\n\
    \  return ret;\n}\n\nusing i64 = int64_t;\n\nmap<u64, i64> factor_count(u64 n)\
    \ {\n  map<u64, i64> mp;\n  for (auto &x : factorize(n)) mp[x]++;\n  return mp;\n\
    }\n\nvector<u64> divisors(u64 n) {\n  if (n == 0) return {};\n  vector<pair<u64,\
    \ i64>> v;\n  for (auto &p : factor_count(n)) v.push_back(p);\n  vector<u64> ret;\n\
    \  auto f = [&](auto rec, int i, u64 x) -> void {\n    if (i == (int)v.size())\
    \ {\n      ret.push_back(x);\n      return;\n    }\n    for (int j = v[i].second;;\
    \ --j) {\n      rec(rec, i + 1, x);\n      if (j == 0) break;\n      x *= v[i].first;\n\
    \    }\n  };\n  f(f, 0, 1);\n  sort(begin(ret), end(ret));\n  return ret;\n}\n\
    \n}  // namespace fast_factorize\n\nusing fast_factorize::divisors;\nusing fast_factorize::factor_count;\n\
    using fast_factorize::factorize;\nusing fast_factorize::is_prime;\n\n/**\n * @brief\
    \ \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)\n * @docs\
    \ docs/prime/fast-factorize.md\n */\n#line 9 \"modulo/mod-kth-root.hpp\"\n\nnamespace\
    \ kth_root_mod {\n\n// fast BS-GS\ntemplate <typename T>\nstruct Memo {\n  Memo(const\
    \ T &g, int s, int period)\n      : size(1 << __lg(min(s, period))),\n       \
    \ mask(size - 1),\n        period(period),\n        vs(size),\n        os(size\
    \ + 1) {\n    T x(1);\n    for (int i = 0; i < size; ++i, x *= g) os[x.get() &\
    \ mask]++;\n    for (int i = 1; i < size; ++i) os[i] += os[i - 1];\n    x = 1;\n\
    \    for (int i = 0; i < size; ++i, x *= g) vs[--os[x.get() & mask]] = {x, i};\n\
    \    gpow = x;\n    os[size] = size;\n  }\n  int find(T x) const {\n    for (int\
    \ t = 0; t < period; t += size, x *= gpow) {\n      for (int m = (x.get() & mask),\
    \ i = os[m]; i < os[m + 1]; ++i) {\n        if (x == vs[i].first) {\n        \
    \  int ret = vs[i].second - t;\n          return ret < 0 ? ret + period : ret;\n\
    \        }\n      }\n    }\n    assert(0);\n  }\n  T gpow;\n  int size, mask,\
    \ period;\n  vector<pair<T, int> > vs;\n  vector<int> os;\n};\n\nusing inner::gcd;\n\
    using inner::inv;\nusing inner::modpow;\ntemplate <typename INT, typename LINT,\
    \ typename mint>\nmint pe_root(INT c, INT pi, INT ei, INT p) {\n  if (mint::get_mod()\
    \ != decltype(mint::a)(p)) mint::set_mod(p);\n  INT s = p - 1, t = 0;\n  while\
    \ (s % pi == 0) s /= pi, ++t;\n  INT pe = 1;\n  for (INT _ = 0; _ < ei; ++_) pe\
    \ *= pi;\n\n  INT u = inv(pe - s % pe, pe);\n  mint mc = c, one = 1;\n  mint z\
    \ = mc.pow((s * u + 1) / pe);\n  mint zpe = mc.pow(s * u);\n  if (zpe == one)\
    \ return z;\n  assert(t > ei);\n  \n  mint vs;\n  {\n    INT ptm1 = 1;\n    for\
    \ (INT _ = 0; _ < t - 1; ++_) ptm1 *= pi;\n    for (mint v = 2;; v += one) {\n\
    \      vs = v.pow(s);\n      if (vs.pow(ptm1) != one) break;\n    }\n  }\n\n \
    \ mint vspe = vs.pow(pe);\n  INT vs_e = ei;\n  mint base = vspe;\n  for (INT _\
    \ = 0; _ < t - ei - 1; _++) base = base.pow(pi);\n  Memo<mint> memo(base, (INT)(sqrt(t\
    \ - ei) * sqrt(pi)) + 1, pi);\n\n  while (zpe != one) {\n    mint tmp = zpe;\n\
    \    INT td = 0;\n    while (tmp != 1) ++td, tmp = tmp.pow(pi);\n    INT e = t\
    \ - td;\n    while (vs_e != e) {\n      vs = vs.pow(pi);\n      vspe = vspe.pow(pi);\n\
    \      ++vs_e;\n    }\n\n    // BS-GS ... find (zpe * ( vspe ^ n ) ) ^( p_i ^\
    \ (td - 1) ) = 1\n    mint base_zpe = zpe.inverse();\n    for (INT _ = 0; _ <\
    \ td - 1; _++) base_zpe = base_zpe.pow(pi);\n    INT bsgs = memo.find(base_zpe);\n\
    \n    z *= vs.pow(bsgs);\n    zpe *= vspe.pow(bsgs);\n  }\n  return z;\n}\n\n\
    template <typename INT, typename LINT, typename mint>\nINT inner_kth_root(INT\
    \ a, INT k, INT p) {\n  a %= p;\n  if (k == 0) return a == 1 ? a : -1;\n  if (a\
    \ <= 1 || k <= 1) return a;\n  assert(p > 2);\n  if (mint::get_mod() != decltype(mint::a)(p))\
    \ mint::set_mod(p);\n  INT g = gcd(p - 1, k);\n  if (modpow<INT, LINT>(a, (p -\
    \ 1) / g, p) != 1) return -1;\n  a = mint(a).pow(inv(k / g, (p - 1) / g)).get();\n\
    \  unordered_map<INT, int> fac;\n  for (auto &f : factorize(g)) fac[f]++;\n  if\
    \ (mint::get_mod() != decltype(mint::a)(p)) mint::set_mod(p);\n  for (auto pp\
    \ : fac)\n    a = pe_root<INT, LINT, mint>(a, pp.first, pp.second, p).get();\n\
    \  return a;\n}\n\nint64_t kth_root(int64_t a, int64_t k, int64_t p) {\n  if (max({a,\
    \ k, p}) < (1LL << 30))\n    return inner_kth_root<int32_t, int64_t, ArbitraryLazyMontgomeryModInt>(a,\
    \ k,\n                                                                       \
    \    p);\n  else\n    return inner_kth_root<int64_t, __int128_t, montgomery64>(a,\
    \ k, p);\n}\n\n}  // namespace kth_root_mod\nusing kth_root_mod::kth_root;\n\n\
    /**\n * @brief kth root(Tonelli-Shanks algorithm)\n * @docs docs/modulo/mod-kth-root.md\n\
    \ */\n#line 5 \"verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp\"\n\nusing\
    \ namespace Nyaan; void Nyaan::solve() {\n  ini(T);\n  rep(_, T) {\n    inl(K,\
    \ Y, P);\n    out(kth_root(Y, K, P));\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_mod\"\n\n#include\
    \ \"../../template/template.hpp\"\n#include \"../../modulo/mod-kth-root.hpp\"\n\
    \nusing namespace Nyaan; void Nyaan::solve() {\n  ini(T);\n  rep(_, T) {\n   \
    \ inl(K, Y, P);\n    out(kth_root(Y, K, P));\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - modulo/mod-kth-root.hpp
  - inner/inner_math.hpp
  - modint/arbitrary-prime-modint.hpp
  - modint/modint-montgomery64.hpp
  - prime/fast-factorize.hpp
  - misc/rng.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
  requiredBy: []
  timestamp: '2020-12-08 00:23:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
- /verify/verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp.html
title: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
---
