---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':question:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/cooley-turkey-ntt.hpp
    title: ntt/cooley-turkey-ntt.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#line\
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
    \ { return mod; }\n};\n#line 2 \"ntt/cooley-turkey-ntt.hpp\"\n\n\n\nnamespace\
    \ FastFourierTransform {\nusing real = double;\n\nstruct C {\n  real x, y;\n\n\
    \  C() : x(0), y(0) {}\n\n  C(real x, real y) : x(x), y(y) {}\n\n  inline C operator+(const\
    \ C &c) const { return C(x + c.x, y + c.y); }\n\n  inline C operator-(const C\
    \ &c) const { return C(x - c.x, y - c.y); }\n\n  inline C operator*(const C &c)\
    \ const {\n    return C(x * c.x - y * c.y, x * c.y + y * c.x);\n  }\n\n  inline\
    \ C conj() const { return C(x, -y); }\n};\n\nconst real PI = acosl(-1);\nint base\
    \ = 1;\nvector<C> rts = {{0, 0}, {1, 0}};\nvector<int> rev = {0, 1};\n\nvoid ensure_base(int\
    \ nbase) {\n  if (nbase <= base) return;\n  rev.resize(1 << nbase);\n  rts.resize(1\
    \ << nbase);\n  for (int i = 0; i < (1 << nbase); i++) {\n    rev[i] = (rev[i\
    \ >> 1] >> 1) + ((i & 1) << (nbase - 1));\n  }\n  while (base < nbase) {\n   \
    \ real angle = PI * 2.0 / (1 << (base + 1));\n    for (int i = 1 << (base - 1);\
    \ i < (1 << base); i++) {\n      rts[i << 1] = rts[i];\n      real angle_i = angle\
    \ * (2 * i + 1 - (1 << base));\n      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\n\
    \    }\n    ++base;\n  }\n}\n\nvoid fft(vector<C> &a, int n) {\n  assert((n &\
    \ (n - 1)) == 0);\n  int zeros = __builtin_ctz(n);\n  ensure_base(zeros);\n  int\
    \ shift = base - zeros;\n  for (int i = 0; i < n; i++) {\n    if (i < (rev[i]\
    \ >> shift)) {\n      swap(a[i], a[rev[i] >> shift]);\n    }\n  }\n  for (int\
    \ k = 1; k < n; k <<= 1) {\n    for (int i = 0; i < n; i += 2 * k) {\n      for\
    \ (int j = 0; j < k; j++) {\n        C z = a[i + j + k] * rts[j + k];\n      \
    \  a[i + j + k] = a[i + j] - z;\n        a[i + j] = a[i + j] + z;\n      }\n \
    \   }\n  }\n}\n\ntemplate <typename mint>\nvector<mint> multiply(const vector<mint>\
    \ &a, const vector<mint> &b) {\n  int need = (int)a.size() + (int)b.size() - 1;\n\
    \  int nbase = 1;\n  while ((1 << nbase) < need) nbase++;\n  ensure_base(nbase);\n\
    \  int sz = 1 << nbase;\n  vector<C> fa(sz);\n  for (int i = 0; i < sz; i++) {\n\
    \    int x = (i < (int)a.size() ? a[i].get() : 0);\n    int y = (i < (int)b.size()\
    \ ? b[i].get() : 0);\n    fa[i] = C(x, y);\n  }\n  fft(fa, sz);\n  C r(0, -0.25\
    \ / (sz >> 1)), s(0, 1), t(0.5, 0);\n  for (int i = 0; i <= (sz >> 1); i++) {\n\
    \    int j = (sz - i) & (sz - 1);\n    C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj())\
    \ * r;\n    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;\n    fa[i] =\
    \ z;\n  }\n  for (int i = 0; i < (sz >> 1); i++) {\n    C A0 = (fa[i] + fa[i +\
    \ (sz >> 1)]) * t;\n    C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1)\
    \ + i];\n    fa[i] = A0 + A1 * s;\n  }\n  fft(fa, sz >> 1);\n  vector<mint> ret(need);\n\
    \  for (int i = 0; i < need; i++) {\n    ret[i] = llround(i & 1 ? fa[i >> 1].y\
    \ : fa[i >> 1].x);\n  }\n  return ret;\n}\n};  // namespace FastFourierTransform\n\
    \ntemplate <typename T>\nstruct ArbitraryModConvolution {\n  using real = FastFourierTransform::real;\n\
    \  using C = FastFourierTransform::C;\n\n  ArbitraryModConvolution() = default;\n\
    \n  static vector<T> multiply(const vector<T> &a, const vector<T> &b,\n      \
    \                      int need = -1) {\n    if (need == -1) need = a.size() +\
    \ b.size() - 1;\n    int nbase = 0;\n    while ((1 << nbase) < need) nbase++;\n\
    \    FastFourierTransform::ensure_base(nbase);\n    int sz = 1 << nbase;\n   \
    \ vector<C> fa(sz);\n    for (int i = 0; i < (int)a.size(); i++) {\n      fa[i]\
    \ = C(a[i].get() & ((1 << 15) - 1), a[i].get() >> 15);\n    }\n    fft(fa, sz);\n\
    \    vector<C> fb(sz);\n    if (a == b) {\n      fb = fa;\n    } else {\n    \
    \  for (int i = 0; i < (int)b.size(); i++) {\n        fb[i] = C(b[i].get() & ((1\
    \ << 15) - 1), b[i].get() >> 15);\n      }\n      fft(fb, sz);\n    }\n    real\
    \ ratio = 0.25 / sz;\n    C r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);\n\
    \    for (int i = 0; i <= (sz >> 1); i++) {\n      int j = (sz - i) & (sz - 1);\n\
    \      C a1 = (fa[i] + fa[j].conj());\n      C a2 = (fa[i] - fa[j].conj()) * r2;\n\
    \      C b1 = (fb[i] + fb[j].conj()) * r3;\n      C b2 = (fb[i] - fb[j].conj())\
    \ * r4;\n      if (i != j) {\n        C c1 = (fa[j] + fa[i].conj());\n       \
    \ C c2 = (fa[j] - fa[i].conj()) * r2;\n        C d1 = (fb[j] + fb[i].conj()) *\
    \ r3;\n        C d2 = (fb[j] - fb[i].conj()) * r4;\n        fa[i] = c1 * d1 +\
    \ c2 * d2 * r5;\n        fb[i] = c1 * d2 + c2 * d1;\n      }\n      fa[j] = a1\
    \ * b1 + a2 * b2 * r5;\n      fb[j] = a1 * b2 + a2 * b1;\n    }\n    fft(fa, sz);\n\
    \    fft(fb, sz);\n    vector<T> ret(need);\n    for (int i = 0; i < need; i++)\
    \ {\n      int64_t aa = llround(fa[i].x);\n      int64_t bb = llround(fb[i].x);\n\
    \      int64_t cc = llround(fa[i].y);\n      aa = T(aa).get(), bb = T(bb).get(),\
    \ cc = T(cc).get();\n      ret[i] = aa + (bb << 15) + (cc << 30);\n    }\n   \
    \ return ret;\n  }\n};\n\ntemplate <typename mint>\nstruct ArbitraryLengthNTT\
    \ {\n  using i64 = long long;\n\n  static int modpow(i64 a, i64 p, int m) {\n\
    \    i64 r = 1 % m;\n    for (a %= m; p; a = a * a % m, p >>= 1)\n      if (p\
    \ & 1) r = r * a % m;\n    return r;\n  }\n\n  static int factor(int n) {\n  \
    \  for (int i = 2; i * i <= n; i++)\n      if (n % i == 0) return i;\n    return\
    \ n;\n  }\n\n  static vector<int> divisor(int n) {\n    vector<int> ret;\n   \
    \ for (int i = 2; i * i <= n; i++) {\n      if (n % i == 0) {\n        ret.push_back(i);\n\
    \        ret.push_back(n / i);\n      }\n    }\n    ret.push_back(n);\n    sort(begin(ret),\
    \ end(ret));\n    ret.erase(unique(begin(ret), end(ret)), end(ret));\n    return\
    \ ret;\n  }\n\n  static int get_pr(int m) {\n    vector<int> st;\n    for (int\
    \ i = m - 1; i != 1; i /= st.back()) st.push_back(factor(i));\n    st.erase(unique(begin(st),\
    \ end(st)), end(st));\n    for (int pr = 1, flg = 1; pr < m; ++pr, flg = 1) {\n\
    \      for (auto &x : st)\n        if (modpow(pr, (m - 1) / x, m) == 1) flg =\
    \ 0;\n      if (flg) return pr;\n    }\n    exit(1);\n  }\n\n  struct LaderNTT\
    \ {\n    int p, pr;\n    vector<int> prs, iprs;\n    LaderNTT() {}\n    LaderNTT(int\
    \ p_) : p(p_), pr(get_pr(p_)), prs(p_ - 1), iprs(p_, -1) {\n      for (int i =\
    \ 0; i < p - 1; i++) prs[i] = i ? prs[i - 1] * pr % p : 1;\n      for (int i =\
    \ 0; i < p - 1; i++) iprs[prs[i]] = i;\n    }\n\n    void ntt(vector<mint> &a)\
    \ {\n      vector<mint> s(p - 1), t(p - 1);\n      for (int i = 0; i < p - 1;\
    \ i++) s[i] = a[prs[i]];\n      for (int i = 0, ldp = len / p; i < p - 1; i++)\n\
    \        t[i] = w[ldp * prs[i ? p - 1 - i : 0]];\n      vector<mint> u = ArbitraryModConvolution<mint>::multiply(s,\
    \ t);\n      s.resize(p);\n      fill(begin(s), end(s), a[0]);\n      for (int\
    \ i = 1; i < p; i++) s[0] += a[i];\n      for (int i = 0, y = 0; i < (int)u.size();\
    \ i++) {\n        s[prs[y]] += u[i];\n        if (--y < 0) y += p - 1;\n     \
    \ }\n      swap(a, s);\n    }\n  };\n\n  static int len;\n  static vector<mint>\
    \ w;\n  static vector<int> divisors;\n  static map<int, LaderNTT *> lader;\n\n\
    \  ArbitraryLengthNTT(int len_ = -1) {\n    int mod = mint::get_mod();\n    if\
    \ ((len = len_) == -1) len = mod - 1;\n    if (mod >= 3 && len <= 1) len = 2;\n\
    \    while ((mod - 1) % len != 0) ++len;\n    w.resize(len + 1);\n    mint pr\
    \ = mint(get_pr(mod)).pow((mod - 1) / len);\n    for (int i = 0; i <= len; i++)\
    \ w[i] = i ? w[i - 1] * pr : mint(1);\n    divisors = divisor(len);\n  }\n\n \
    \ static void dft(vector<mint> &a) {\n    int N = a.size();\n    if (N == 2) {\n\
    \      mint a01 = a[0] + a[1];\n      a[1] = a[0] - a[1];\n      a[0] = a01;\n\
    \      return;\n    }\n    int d = len / N;\n    vector<mint> b(N);\n    for (int\
    \ i = 0, dk = 0; i < N; i++, dk += d) {\n      for (int j = 0, k = 0; j < N; j++)\
    \ {\n        b[j] += a[i] * w[k];\n        if ((k += dk) >= len) k -= len;\n \
    \     }\n    }\n    swap(a, b);\n  }\n\n  static void ntt_base2(vector<mint> &a)\
    \ {\n    static vector<int> btr;\n    int N = a.size();\n    assert(N % 2 == 0);\n\
    \n    if (btr.size() != a.size()) {\n      btr.resize(N);\n      int b = __builtin_ctz(N);\n\
    \      assert(N == (1 << b));\n      for (int i = 0; i < N; i++) {\n        btr[i]\
    \ = (btr[i >> 1] >> 1) + ((i & 1) << (b - 1));\n      }\n    }\n\n    static vector<mint>\
    \ basis;\n    if (basis.size() < a.size()) {\n      basis.resize(N);\n      mint\
    \ b = w[len / N];\n      for (int i = N >> 1; i > 0; i >>= 1) {\n        mint\
    \ c = 1;\n        for (int j = 0; j < i; ++j) {\n          basis[i + j] = c;\n\
    \          c *= b;\n        }\n        b *= b;\n      }\n    }\n\n    for (int\
    \ i = 0; i < N; i++)\n      if (i < btr[i]) swap(a[i], a[btr[i]]);\n\n    for\
    \ (int k = 1; k < N; k <<= 1) {\n      for (int i = 0; i < N; i += 2 * k) {\n\
    \        for (int j = 0; j < k; j++) {\n          mint z = a[i + j + k] * basis[j\
    \ + k];\n          a[i + j + k] = a[i + j] - z;\n          a[i + j] = a[i + j]\
    \ + z;\n        }\n      }\n    }\n  }\n\n  static void pntt(vector<mint> &a)\
    \ {\n    int P = a.size();\n    if (P <= 64) {\n      dft(a);\n      return;\n\
    \    }\n    if (lader.find(P) == end(lader)) lader[P] = new LaderNTT(P);\n   \
    \ lader[P]->ntt(a);\n  }\n\n  static void ntt(vector<mint> &a) {\n    assert(len\
    \ % a.size() == 0);\n    int N = (int)a.size();\n    if(N <= 1) return;\n    if\
    \ (N <= 64) {\n      dft(a);\n      return;\n    }\n\n    int P = factor(N);\n\
    \    if (P == N) {\n      pntt(a);\n      return;\n    }\n    if (P == 2) {\n\
    \      P = 1 << __builtin_ctz(N);\n      if (N == P) {\n        ntt_base2(a);\n\
    \        return;\n      }\n    }\n\n    int Q = N / P;\n    vector<mint> s(Q),\
    \ t(N), u(P);\n    for (int p = 0, lN = len / N, d = 0; p < P; p++, d += lN) {\n\
    \      for (int q = 0, qP = 0; q < Q; q++, qP += P) s[q] = a[qP + p];\n      ntt(s);\n\
    \      for (int r = 0, n = 0, pQ = p * Q; r < Q; ++r, n += d) {\n        t[pQ\
    \ + r] = w[n] * s[r];\n      }\n    }\n    for (int r = 0; r < Q; r++) {\n   \
    \   for (int p = 0, pQ = 0; p < P; p++, pQ += Q) u[p] = t[pQ + r];\n      if (P\
    \ <= 64)\n        dft(u);\n      else if (P & 1)\n        pntt(u);\n      else\n\
    \        ntt_base2(u);\n      for (int s = 0, sQ = 0; s < P; s++, sQ += Q) a[sQ\
    \ + r] = u[s];\n    }\n  }\n\n  static void intt(vector<mint> &a) {\n    reverse(begin(a)\
    \ + 1, end(a));\n    ntt(a);\n    mint invn = mint(a.size()).inverse();\n    for\
    \ (auto &x : a) x *= invn;\n  }\n\n  static vector<mint> multiply(const vector<mint>\
    \ &a, const vector<mint> &b) {\n    int N = (int)a.size() + (int)b.size() - 1;\n\
    \    assert(N <= len);\n    vector<mint> s(a), t(b);\n    int l = *lower_bound(begin(divisors),\
    \ end(divisors), N);\n    s.resize(l, mint(0));\n    t.resize(l, mint(0));\n \
    \   ntt(s);\n    ntt(t);\n    for (int i = 0; i < l; i++) s[i] *= t[i];\n    intt(s);\n\
    \    s.resize(N);\n    return s;\n  }\n};\ntemplate <typename mint>\nint ArbitraryLengthNTT<mint>::len;\n\
    template <typename mint>\nvector<mint> ArbitraryLengthNTT<mint>::w;\ntemplate\
    \ <typename mint>\nvector<int> ArbitraryLengthNTT<mint>::divisors;\ntemplate <typename\
    \ mint>\nmap<int, typename ArbitraryLengthNTT<mint>::LaderNTT *>\n    ArbitraryLengthNTT<mint>::lader;\n\
    #line 7 \"verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve() {\n  using mint = LazyMontgomeryModInt<998244353>;\n\
    \  ArbitraryLengthNTT<mint> ntt(7 * 17 * (1 << 14));\n  int N, M;\n  rd(N, M);\n\
    \  V<mint> a(N), b(M);\n  for (int i = 0; i < N; i++) rd(a[i]);\n  for (int i\
    \ = 0; i < M; i++) rd(b[i]);\n  auto c = ntt.multiply(a, b);\n  for (int i = 0;\
    \ i < (int)N + M - 1; i++) {\n    wt(c[i].get(), (i == (int)N + M - 1 ? '\\n'\
    \ : ' '));\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ \"../../template/template.hpp\"\n#include \"../../misc/fastio.hpp\"\n#include\
    \ \"../../modint/montgomery-modint.hpp\"\n#include \"../../ntt/cooley-turkey-ntt.hpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve() {\n  using mint = LazyMontgomeryModInt<998244353>;\n\
    \  ArbitraryLengthNTT<mint> ntt(7 * 17 * (1 << 14));\n  int N, M;\n  rd(N, M);\n\
    \  V<mint> a(N), b(M);\n  for (int i = 0; i < N; i++) rd(a[i]);\n  for (int i\
    \ = 0; i < M; i++) rd(b[i]);\n  auto c = ntt.multiply(a, b);\n  for (int i = 0;\
    \ i < (int)N + M - 1; i++) {\n    wt(c[i].get(), (i == (int)N + M - 1 ? '\\n'\
    \ : ' '));\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - misc/fastio.hpp
  - modint/montgomery-modint.hpp
  - ntt/cooley-turkey-ntt.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
- /verify/verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp.html
title: verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
---
