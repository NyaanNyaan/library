---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: inner/inner-hash.hpp
    title: inner/inner-hash.hpp
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash-2d.hpp
    title: "\u4E8C\u6B21\u5143Rolling Hash"
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C
  bundledCode: "#line 1 \"verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp\"\n\
    #define PROBLEM \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C\"\
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
    \ 2 \"string/rolling-hash-2d.hpp\"\n\n\n\n#line 2 \"inner/inner-hash.hpp\"\n\n\
    namespace inner {\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    \ntemplate <int BASE_NUM>\nstruct Hash : array<u64, BASE_NUM> {\n  using array<u64,\
    \ BASE_NUM>::operator[];\n  static constexpr int n = BASE_NUM;\n\n  Hash() : array<u64,\
    \ BASE_NUM>() {}\n\n  static constexpr u64 md = (1ull << 61) - 1;\n\n  static\
    \ u64 cast(const int64_t &a) { return a < 0 ? a + md : a; }\n\n  static inline\
    \ constexpr u64 modmul(const u64 &a, const u64 &b) {\n    u128 ret = u128(a) *\
    \ b;\n    ret = (ret & md) + (ret >> 61);\n    return ret >= md ? ret - md : ret;\n\
    \  }\n  static inline constexpr u64 modfma(const u64 &a, const u64 &b, const u64\
    \ &c) {\n    u128 ret = u128(a) * b + c;\n    ret = (ret & md) + (ret >> 61);\n\
    \    return ret >= md ? ret - md : ret;\n  }\n  constexpr static Hash set(u64\
    \ a) {\n    Hash res;\n    for (int i = 0; i < n; i++) res[i] = a;\n    return\
    \ res;\n  }\n  Hash &operator+=(const Hash &r) {\n    for (int i = 0; i < n; i++)\n\
    \      if (((*this)[i] += r[i]) >= md) (*this)[i] -= md;\n    return *this;\n\
    \  }\n  Hash &operator+=(const u64 &r) {\n    for (int i = 0; i < n; i++)\n  \
    \    if (((*this)[i] += r) >= md) (*this)[i] -= md;\n    return *this;\n  }\n\
    \  Hash &operator-=(const Hash &r) {\n    for (int i = 0; i < n; i++)\n      if\
    \ (((*this)[i] += md - r[i]) >= md) (*this)[i] -= md;\n    return *this;\n  }\n\
    \  Hash &operator-=(const u64 &r) {\n    for (int i = 0; i < n; i++)\n      if\
    \ (((*this)[i] += md - r) >= md) (*this)[i] -= md;\n    return *this;\n  }\n \
    \ inline Hash &operator*=(const Hash &r) {\n    for (int i = 0; i < n; i++) (*this)[i]\
    \ = modmul((*this)[i], r[i]);\n    return *this;\n  }\n  Hash operator+(const\
    \ Hash &r) { return Hash(*this) += r; }\n  Hash operator+(const u64 &r) { return\
    \ Hash(*this) += r; }\n  Hash operator-(const Hash &r) { return Hash(*this) -=\
    \ r; }\n  Hash operator-(const u64 &r) { return Hash(*this) -= r; }\n  inline\
    \ Hash operator*(const Hash &r) { return Hash(*this) *= r; }\n  Hash operator-()\
    \ const {\n    Hash res;\n    for (int i = 0; i < n; i++) res[i] = (*this)[i]\
    \ == 0 ? 0 : md - (*this)[i];\n    return res;\n  }\n  friend Hash pfma(const\
    \ Hash &a, const Hash &b, const Hash &c) {\n    Hash res;\n    for (int i = 0;\
    \ i < n; i++) res[i] = modfma(a[i], b[i], c[i]);\n    return res;\n  }\n  friend\
    \ Hash pfma(const Hash &a, const Hash &b, const u64 &c) {\n    Hash res;\n   \
    \ for (int i = 0; i < n; i++) res[i] = modfma(a[i], b[i], c);\n    return res;\n\
    \  }\n\n  static Hash get_basis() {\n    constexpr u64 ds[] = {2, 3, 5, 7, 11,\
    \ 13, 31, 41, 61, 151, 331, 1321};\n    static auto rand_time =\n        chrono::duration_cast<chrono::nanoseconds>(\n\
    \            chrono::high_resolution_clock::now().time_since_epoch())\n      \
    \      .count();\n    static mt19937_64 rng(rand_time);\n\n    auto modpow = [&](u64\
    \ a, u64 b) {\n      u64 r = 1;\n      for (a %= md; b; a = modmul(a, a), b >>=\
    \ 1) r = modmul(r, a);\n      return r;\n    };\n    auto isPrimitive = [&](u64\
    \ x) {\n      for (auto &d : ds)\n        if (modpow(x, (md - 1) / d) <= 1) return\
    \ false;\n      return true;\n    };\n\n    Hash h;\n    for (int i = 0; i < n;\
    \ i++) {\n      while (isPrimitive(h[i] = rng() % (md - 1) + 1) == false)\n  \
    \      ;\n    }\n    return h;\n  }\n};\n\n}  // namespace inner\n#line 6 \"string/rolling-hash-2d.hpp\"\
    \n\ntemplate <typename Str, int BASE_NUM = 1>\nstruct RollingHash2D {\n  using\
    \ Hash = inner::Hash<BASE_NUM>;\n  using u64 = unsigned long long;\n  vector<Str>\
    \ data;\n  vector<vector<Hash>> hs;\n  vector<Hash> pw[2];\n  int h, w;\n  static\
    \ Hash basis[2];\n\n  RollingHash2D(const vector<Str> &S = vector<Str>()) { build(S);\
    \ }\n\n  void build(const vector<Str> &S) {\n    data = S;\n    h = S.size();\n\
    \    w = S[0].size();\n    pw[0].resize(h + 1);\n    pw[1].resize(w + 1);\n  \
    \  pw[0][0] = pw[1][0] = Hash::set(1);\n    for (int i = 1; i <= h; i++) pw[0][i]\
    \ = pw[0][i - 1] * basis[0];\n    for (int i = 1; i <= w; i++) pw[1][i] = pw[1][i\
    \ - 1] * basis[1];\n    hs.resize(h + 1, vector<Hash>(w + 1));\n    hs[0][0] =\
    \ Hash::set(0);\n    for (int i = 1; i <= h; i++) {\n      hs[i][0] = Hash::set(0);\n\
    \      for (int j = 1; j <= w; j++)\n        hs[i][j] = pfma(hs[i][j - 1], basis[1],\
    \ Hash::cast(S[i - 1][j - 1]));\n    }\n    for (int j = 1; j <= w; j++) {\n \
    \     hs[0][j] = Hash::set(0);\n      for (int i = 1; i <= h; i++)\n        hs[i][j]\
    \ = pfma(hs[i - 1][j], basis[0], hs[i][j]);\n    }\n  }\n\n  Hash get(int u, int\
    \ l, int d, int r) {\n    return hs[d][r] - hs[u][r] * pw[0][d - u] - hs[d][l]\
    \ * pw[1][r - l] +\n           hs[u][l] * pw[0][d - u] * pw[1][r - l];\n  }\n\n\
    \  static Hash get_hash(const vector<Str> &T) {\n    Hash ret = Hash::set(0);\n\
    \    for (int i = 0; i < (int)T.size(); i++) {\n      Hash h = Hash::set(0);\n\
    \      for(int j = 0; j < (int)T[0].size(); j++) \n        h = pfma(h, basis[1],\
    \ Hash::cast(T[i][j]));\n      ret = pfma(ret, basis[0], h);\n    }\n    return\
    \ ret;\n  }\n\n};\n\ntemplate <typename Str, int BASE_NUM>\ntypename RollingHash2D<Str,\
    \ BASE_NUM>::Hash RollingHash2D<Str, BASE_NUM>::basis[2] =\n    {inner::Hash<BASE_NUM>::get_basis(),\
    \ inner::Hash<BASE_NUM>::get_basis()};\nusing roriha2d = RollingHash2D<string,\
    \ 1>;\n\n/**\n * @brief \u4E8C\u6B21\u5143Rolling Hash\n * @docs docs/string/rolling-hash-2d.md\n\
    \ */\n#line 6 \"verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp\"\n\nusing\
    \ namespace Nyaan;\nvoid Nyaan::solve() {\n  ini(H, W);\n  vs S(H);\n  in(S);\n\
    \  roriha2d rori(S);\n\n  ini(h, w);\n  vs T(h);\n  in(T);\n\n  auto th = roriha2d::get_hash(T);\n\
    \  rep(i, H - h + 1) rep(j, W - w + 1) {\n    auto sh = rori.get(i, j, i + h,\
    \ j + w);\n    if (sh == th) out(i, j);\n  }\n}\n"
  code: "#define PROBLEM \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../string/rolling-hash-2d.hpp\"\
    \n\nusing namespace Nyaan;\nvoid Nyaan::solve() {\n  ini(H, W);\n  vs S(H);\n\
    \  in(S);\n  roriha2d rori(S);\n\n  ini(h, w);\n  vs T(h);\n  in(T);\n\n  auto\
    \ th = roriha2d::get_hash(T);\n  rep(i, H - h + 1) rep(j, W - w + 1) {\n    auto\
    \ sh = rori.get(i, j, i + h, j + w);\n    if (sh == th) out(i, j);\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - string/rolling-hash-2d.hpp
  - inner/inner-hash.hpp
  isVerificationFile: true
  path: verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp
- /verify/verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp.html
title: verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp
---
