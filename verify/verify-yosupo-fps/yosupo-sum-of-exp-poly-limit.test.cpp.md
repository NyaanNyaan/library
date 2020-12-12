---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/lagrange-interpolation-point.hpp
    title: fps/lagrange-interpolation-point.hpp
  - icon: ':heavy_check_mark:'
    path: fps/sum-of-exponential-times-poly.hpp
    title: $\sum_{i}a^i f(i)$
  - icon: ':question:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
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
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
    links:
    - https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
  bundledCode: "#line 1 \"verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n\n#line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n\
    #include <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
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
    \ 2 \"misc/fastio.hpp\"\n\n\n\nnamespace fastio {\nstatic constexpr int SZ = 1\
    \ << 17;\nchar ibuf[SZ], obuf[SZ];\nint pil = 0, pir = 0, por = 0;\n\nstruct Pre\
    \ {\n  char num[40000];\n  constexpr Pre() : num() {\n    for (int i = 0; i <\
    \ 10000; i++) {\n      int n = i;\n      for (int j = 3; j >= 0; j--) {\n    \
    \    num[i * 4 + j] = n % 10 + '0';\n        n /= 10;\n      }\n    }\n  }\n}\
    \ constexpr pre;\n\ninline void load() {\n  memcpy(ibuf, ibuf + pil, pir - pil);\n\
    \  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);\n  pil\
    \ = 0;\n}\ninline void flush() {\n  fwrite(obuf, 1, por, stdout);\n  por = 0;\n\
    }\n\ninline void rd(char& c) { c = ibuf[pil++]; }\ntemplate <typename T>\ninline\
    \ void rd(T& x) {\n  if (pil + 32 > pir) load();\n  char c;\n  do\n    c = ibuf[pil++];\n\
    \  while (c < '-');\n  bool minus = 0;\n  if (c == '-') {\n    minus = 1;\n  \
    \  c = ibuf[pil++];\n  }\n  x = 0;\n  while (c >= '0') {\n    x = x * 10 + (c\
    \ & 15);\n    c = ibuf[pil++];\n  }\n  if (minus) x = -x;\n}\ninline void rd()\
    \ {}\ntemplate <typename Head, typename... Tail>\ninline void rd(Head& head, Tail&...\
    \ tail) {\n  rd(head);\n  rd(tail...);\n}\n\ninline void wt(char c) { obuf[por++]\
    \ = c; }\ntemplate <typename T>\ninline void wt(T x) {\n  if (por > SZ - 32) flush();\n\
    \  if (!x) {\n    obuf[por++] = '0';\n    return;\n  }\n  if (x < 0) {\n    obuf[por++]\
    \ = '-';\n    x = -x;\n  }\n  int i = 12;\n  char buf[16];\n  while (x >= 10000)\
    \ {\n    memcpy(buf + i, pre.num + (x % 10000) * 4, 4);\n    x /= 10000;\n   \
    \ i -= 4;\n  }\n  if (x < 100) {\n    if (x < 10) {\n      wt(char('0' + char(x)));\n\
    \    } else {\n      uint32_t q = (uint32_t(x) * 205) >> 11;\n      uint32_t r\
    \ = uint32_t(x) - q * 10;\n      obuf[por + 0] = '0' + q;\n      obuf[por + 1]\
    \ = '0' + r;\n      por += 2;\n    }\n  } else {\n    if (x < 1000) {\n      memcpy(obuf\
    \ + por, pre.num + (x << 2) + 1, 3);\n      por += 3;\n    } else {\n      memcpy(obuf\
    \ + por, pre.num + (x << 2), 4);\n      por += 4;\n    }\n  }\n  memcpy(obuf +\
    \ por, buf + i + 4, 12 - i);\n  por += 12 - i;\n}\n\ninline void wt() {}\ntemplate\
    \ <typename Head, typename... Tail>\ninline void wt(Head head, Tail... tail) {\n\
    \  wt(head);\n  wt(tail...);\n}\ntemplate <typename T>\ninline void wtn(T x) {\n\
    \  wt(x, '\\n');\n}\n\nstruct Dummy {\n  Dummy() { atexit(flush); }\n} dummy;\n\
    \n}  // namespace fastio\nusing fastio::rd;\nusing fastio::wt;\nusing fastio::wtn;\n\
    #line 2 \"modint/montgomery-modint.hpp\"\n\n\n\ntemplate <uint32_t mod>\nstruct\
    \ LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n  using i32 =\
    \ int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr\
    \ u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i < 4; ++i) ret *= 2\
    \ - mod * ret;\n    return ret;\n  }\n\n  static constexpr u32 r = get_r();\n\
    \  static constexpr u32 n2 = -u64(mod) % mod;\n  static_assert(r * mod == 1, \"\
    invalid, r * mod != 1\");\n  static_assert(mod < (1 << 30), \"invalid, mod >=\
    \ 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"invalid, mod % 2 == 0\");\n\n\
    \  u32 a;\n\n  constexpr LazyMontgomeryModInt() : a(0) {}\n  constexpr LazyMontgomeryModInt(const\
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
    \ }\n\n  constexpr mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n   \
    \ while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>=\
    \ 1;\n    }\n    return ret;\n  }\n  \n  constexpr mint inverse() const { return\
    \ pow(mod - 2); }\n\n  friend ostream &operator<<(ostream &os, const mint &b)\
    \ {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is,\
    \ mint &b) {\n    int64_t t;\n    is >> t;\n    b = LazyMontgomeryModInt<mod>(t);\n\
    \    return (is);\n  }\n  \n  constexpr u32 get() const {\n    u32 ret = reduce(a);\n\
    \    return ret >= mod ? ret - mod : ret;\n  }\n\n  static constexpr u32 get_mod()\
    \ { return mod; }\n};\n#line 2 \"modulo/binomial.hpp\"\n\n\n\ntemplate <typename\
    \ T>\nstruct Binomial {\n  vector<T> fac_, finv_, inv_;\n  Binomial(int MAX =\
    \ 0) : fac_(MAX + 10), finv_(MAX + 10), inv_(MAX + 10) {\n    assert(T::get_mod()\
    \ != 0);\n    MAX += 9;\n    fac_[0] = finv_[0] = inv_[0] = 1;\n    for (int i\
    \ = 1; i <= MAX; i++) fac_[i] = fac_[i - 1] * i;\n    finv_[MAX] = fac_[MAX].inverse();\n\
    \    for (int i = MAX - 1; i > 0; i--) finv_[i] = finv_[i + 1] * (i + 1);\n  \
    \  for (int i = 1; i <= MAX; i++) inv_[i] = finv_[i] * fac_[i - 1];\n  }\n\n \
    \ void extend() {\n    int n = fac_.size();\n    T fac = fac_.back() * n;\n  \
    \  T inv = (-inv_[T::get_mod() % n]) * (T::get_mod() / n);\n    T finv = finv_.back()\
    \ * inv;\n    fac_.push_back(fac);\n    finv_.push_back(finv);\n    inv_.push_back(inv);\n\
    \  }\n\n  T fac(int i) {\n    while (i >= (int)fac_.size()) extend();\n    return\
    \ fac_[i];\n  }\n\n  T finv(int i) {\n    while (i >= (int)finv_.size()) extend();\n\
    \    return finv_[i];\n  }\n\n  T inv(int i) {\n    while (i >= (int)inv_.size())\
    \ extend();\n    return inv_[i];\n  }\n\n  T C(int n, int r) {\n    if (n < r\
    \ || r < 0) return T(0);\n    return fac(n) * finv(n - r) * finv(r);\n  }\n\n\
    \  T C_naive(int n, int r) {\n    if (n < r || r < 0) return T(0);\n    T ret\
    \ = T(1);\n    r = min(r, n - r);\n    for (int i = 1; i <= r; ++i) ret *= inv(i)\
    \ * (n--);\n    return ret;\n  }\n\n  T P(int n, int r) {\n    if (n < r || r\
    \ < 0) return T(0);\n    return fac(n) * finv(n - r);\n  }\n\n  T H(int n, int\
    \ r) {\n    if (n < 0 || r < 0) return T(0);\n    return r == 0 ? 1 : C(n + r\
    \ - 1, r);\n  }\n};\n#line 2 \"fps/lagrange-interpolation-point.hpp\"\n\n#line\
    \ 4 \"fps/lagrange-interpolation-point.hpp\"\n\n// given  : y(x=0) , y(x=1) ,\
    \ ... , y(k)\n// return : y(x)\ntemplate <typename mint>\nmint lagrange_interpolation(const\
    \ vector<mint>& y, long long x,\n                            Binomial<mint>& C)\
    \ {\n  int N = (int)y.size() - 1;\n  if (x <= N) return y[x];\n  mint ret = 0;\n\
    \  vector<mint> dp(N + 1, 1), pd(N + 1, 1);\n  mint a = x, one = 1;\n  for (int\
    \ i = 0; i < N; i++) dp[i + 1] = dp[i] * a, a -= one;\n  for (int i = N; i > 0;\
    \ i--) pd[i - 1] = pd[i] * a, a += one;\n  for (int i = 0; i <= N; i++) {\n  \
    \  mint tmp = y[i] * dp[i] * pd[i] * C.finv(i) * C.finv(N - i);\n    ret += ((N\
    \ - i) & 1) ? -tmp : tmp;\n  }\n  return ret;\n}\n#line 2 \"fps/sum-of-exponential-times-poly.hpp\"\
    \n\n#line 4 \"fps/sum-of-exponential-times-poly.hpp\"\n\n// given  : f(0)...f(k)\
    \ (deg(f) = k), a, n\n// return : \\sum_{i=0...n-1} a^i f(i)\ntemplate <typename\
    \ mint>\nmint sum_of_exp(const vector<mint>& f, mint a, long long n,\n       \
    \         Binomial<mint>& C) {\n  if (n == 0) return mint(0);\n  if (a == mint(0))\
    \ return f[0];\n  if (a == mint(1)) {\n    vector<mint> g(f.size() + 1, mint(0));\n\
    \    for (int i = 1; i < (int)g.size(); i++) g[i] = g[i - 1] + f[i - 1];\n   \
    \ return lagrange_interpolation(g, n, C);\n  }\n  int K = f.size() - 1;\n  vector<mint>\
    \ g(f.size());\n  mint buf = 1;\n  for (int i = 0; i < (int)g.size(); i++) g[i]\
    \ = f[i] * buf, buf *= a;\n  for (int i = 1; i < (int)g.size(); i++) g[i] += g[i\
    \ - 1];\n  mint c = 0, buf2 = 1;\n  for (int i = 0; i <= K; i++) c += C.C(K +\
    \ 1, i) * buf2 * g[K - i], buf2 *= -a;\n  c /= (-a + 1).pow(K + 1);\n  mint buf3\
    \ = 1, ia = a.inverse();\n  for (int i = 0; i < (int)g.size(); i++) g[i] = (g[i]\
    \ - c) * buf3, buf3 *= ia;\n  mint tn = lagrange_interpolation(g, n - 1, C);\n\
    \  return tn * a.pow(n - 1) + c;\n}\n\n// given  : f(0)...f(k) (deg(f) = k), a\n\
    // return : \\sum_{i=0...infty} a^i f(i)\ntemplate <typename mint>\nmint sum_of_exp_limit(const\
    \ vector<mint>& f, mint a, Binomial<mint>& C) {\n  if (a == mint(0)) return f[0];\n\
    \  int K = f.size() - 1;\n  vector<mint> g(f.size());\n  mint buf = 1;\n  for\
    \ (int i = 0; i < (int)g.size(); i++) g[i] = f[i] * buf, buf *= a;\n  for (int\
    \ i = 1; i < (int)g.size(); i++) g[i] += g[i - 1];\n  mint c = 0, buf2 = 1;\n\
    \  for (int i = 0; i <= K; i++) c += C.C(K + 1, i) * buf2 * g[K - i], buf2 *=\
    \ -a;\n  c /= (-a + 1).pow(K + 1);\n  return c;\n}\n\n// given  : p, n\n// return\
    \ : (0^p, 1^p, ... , n^p)\ntemplate <typename mint>\nvector<mint> exp_enamurate(int\
    \ p, int n) {\n  vector<mint> f(n + 1, mint(0));\n  if (!p) {\n    f[0] = 1;\n\
    \    return std::move(f);\n  }\n  f[1] = 1;\n  vector<bool> sieve(n + 1, false);\n\
    \  vector<int> ps;\n  for (int i = 2; i <= n; i++) {\n    if (!sieve[i]) {\n \
    \     f[i] = mint(i).pow(p);\n      ps.push_back(i);\n    }\n    for (int j =\
    \ 0; j < (int)ps.size() && i * ps[j] <= n; j++) {\n      sieve[i * ps[j]] = 1;\n\
    \      f[i * ps[j]] = f[i] * f[ps[j]];\n      if (i % ps[j] == 0) break;\n   \
    \ }\n  }\n  return std::move(f);\n}\n\n// given  : d, r, n\n// return : \\sum_{i=0...n-1}\
    \ r^i i^d\ntemplate <typename mint>\nmint sum_of_exp2(int d, mint r, long long\
    \ n, Binomial<mint>& C) {\n  vector<mint> f = exp_enamurate<mint>(d, d);\n  return\
    \ sum_of_exp(f, r, n, C);\n}\n\n// given  : d, r\n// return : \\sum_{i=0...infty}\
    \ r^i i^d\ntemplate <typename mint>\nmint sum_of_exp_limit2(int d, mint r, Binomial<mint>&\
    \ C) {\n  vector<mint> f = exp_enamurate<mint>(d, d);\n  return sum_of_exp_limit(f,\
    \ r, C);\n}\n\n/**\n * @brief $\\sum_{i}a^i f(i)$\n * @docs docs/fps/sum-of-exponential-times-poly.md\n\
    \ */\n#line 9 \"verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve() {\n  using mint = LazyMontgomeryModInt<998244353>;\n\
    \  Binomial<mint> C(10001000);\n  long long r, d;\n  rd(r, d);\n  wtn(sum_of_exp_limit2<mint>(d,\
    \ r, C).get());\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../misc/fastio.hpp\"\
    \n#include \"../../modint/montgomery-modint.hpp\"\n#include \"../../modulo/binomial.hpp\"\
    \n#include \"../../fps/lagrange-interpolation-point.hpp\"\n#include \"../../fps/sum-of-exponential-times-poly.hpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve() {\n  using mint = LazyMontgomeryModInt<998244353>;\n\
    \  Binomial<mint> C(10001000);\n  long long r, d;\n  rd(r, d);\n  wtn(sum_of_exp_limit2<mint>(d,\
    \ r, C).get());\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - misc/fastio.hpp
  - modint/montgomery-modint.hpp
  - modulo/binomial.hpp
  - fps/lagrange-interpolation-point.hpp
  - fps/sum-of-exponential-times-poly.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
  requiredBy: []
  timestamp: '2020-12-05 08:16:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
- /verify/verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp.html
title: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
---
