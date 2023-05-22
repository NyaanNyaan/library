---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/radix-heap.hpp
    title: Radix Heap
  - icon: ':heavy_check_mark:'
    path: graph/static-graph.hpp
    title: Static Graph
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: shortest-path/dijkstra-fast.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u5B9A\u6570\u500D\u9AD8\u901F\
      \u5316)"
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"verify/verify-yosupo-graph/yosupo-shortest-path-3.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#line 2 \"\
    template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include\
    \ <cinttypes>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
    \ <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <initializer_list>\n#include <iomanip>\n#include <ios>\n\
    #include <iostream>\n#include <istream>\n#include <iterator>\n#include <limits>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n\
    #include <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include\
    \ <sstream>\n#include <stack>\n#include <streambuf>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\n\n// utility\n\
    #line 1 \"template/util.hpp\"\nnamespace Nyaan {\nusing ll = long long;\nusing\
    \ i64 = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\ntemplate <typename T>\nusing V = vector<T>;\ntemplate\
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
    \ 2 \"misc/fastio.hpp\"\n\n#line 8 \"misc/fastio.hpp\"\n\nusing namespace std;\n\
    \n#line 2 \"internal/internal-type-traits.hpp\"\n\n#line 4 \"internal/internal-type-traits.hpp\"\
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
    \ = nullptr>\ninline void single_read(T& x) {\n  if (in_left + offset > in_right)\
    \ load();\n  skip_space();\n  char c = inbuf[in_left++];\n  [[maybe_unused]] bool\
    \ minus = false;\n  if constexpr (internal::is_broadly_signed_v<T>) {\n    if\
    \ (c == '-') minus = true, c = inbuf[in_left++];\n  }\n  x = 0;\n  while (c >=\
    \ '0') {\n    x = x * 10 + (c & 15);\n    c = inbuf[in_left++];\n  }\n  if constexpr\
    \ (internal::is_broadly_signed_v<T>) {\n    if (minus) x = -x;\n  }\n}\ninline\
    \ void rd() {}\ntemplate <typename Head, typename... Tail>\ninline void rd(Head&\
    \ head, Tail&... tail) {\n  single_read(head);\n  rd(tail...);\n}\n\ninline void\
    \ single_write(const char& c) {\n  if (out_right > SZ - offset) flush();\n  outbuf[out_right++]\
    \ = c;\n}\ninline void single_write(const bool& b) {\n  if (out_right > SZ - offset)\
    \ flush();\n  outbuf[out_right++] = b ? '1' : '0';\n}\ninline void single_write(const\
    \ string& S) {\n  int i = 0;\n  while (i != (int)S.size()) {\n    if (out_right\
    \ == SZ) flush();\n    int len = min((int)S.size() - i, SZ - out_right);\n   \
    \ memcpy(outbuf + out_right, S.data() + i, sizeof(char) * len);\n    i += len,\
    \ out_right += len;\n  }\n}\ntemplate <typename T,\n          enable_if_t<internal::is_broadly_integral_v<T>>*\
    \ = nullptr>\ninline void single_write(const T& _x) {\n  if (out_right > SZ -\
    \ offset) flush();\n  if (_x == 0) {\n    outbuf[out_right++] = '0';\n    return;\n\
    \  }\n  T x = _x;\n  if constexpr (internal::is_broadly_signed_v<T>) {\n    if\
    \ (x < 0) outbuf[out_right++] = '-', x = -x;\n  }\n  constexpr int buffer_size\
    \ = sizeof(T) * 10 / 4;\n  char buf[buffer_size];\n  int i = buffer_size;\n  while\
    \ (x >= 10000) {\n    i -= 4;\n    memcpy(buf + i, pre.num + (x % 10000) * 4,\
    \ 4);\n    x /= 10000;\n  }\n  if (x < 100) {\n    if (x < 10) {\n      outbuf[out_right]\
    \ = '0' + x;\n      ++out_right;\n    } else {\n      uint32_t q = (uint32_t(x)\
    \ * 205) >> 11;\n      uint32_t r = uint32_t(x) - q * 10;\n      outbuf[out_right]\
    \ = '0' + q;\n      outbuf[out_right + 1] = '0' + r;\n      out_right += 2;\n\
    \    }\n  } else {\n    if (x < 1000) {\n      memcpy(outbuf + out_right, pre.num\
    \ + (x << 2) + 1, 3);\n      out_right += 3;\n    } else {\n      memcpy(outbuf\
    \ + out_right, pre.num + (x << 2), 4);\n      out_right += 4;\n    }\n  }\n  memcpy(outbuf\
    \ + out_right, buf + i, buffer_size - i);\n  out_right += buffer_size - i;\n}\n\
    inline void wt() {}\ntemplate <typename Head, typename... Tail>\ninline void wt(const\
    \ Head& head, const Tail&... tail) {\n  single_write(head);\n  wt(forward<const\
    \ Tail>(tail)...);\n}\ntemplate <typename... Args>\ninline void wtn(const Args&...\
    \ x) {\n  wt(forward<const Args>(x)...);\n  wt('\\n');\n}\n\nstruct Dummy {\n\
    \  Dummy() { atexit(flush); }\n} dummy;\n\n}  // namespace fastio\nusing fastio::rd;\n\
    using fastio::skip_space;\nusing fastio::wt;\nusing fastio::wtn;\n#line 2 \"shortest-path/dijkstra-fast.hpp\"\
    \n\n#line 2 \"data-structure/radix-heap.hpp\"\n\ntemplate <typename Key, typename\
    \ Val>\nstruct RadixHeap {\n  using uint = typename make_unsigned<Key>::type;\n\
    \  static constexpr int bit = sizeof(Key) * 8;\n  array<vector<pair<uint, Val>\
    \ >, bit + 1> vs;\n  array<uint, bit + 1> ms;\n\n  int s;\n  uint last;\n\n  RadixHeap()\
    \ : s(0), last(0) { fill(begin(ms), end(ms), uint(-1)); }\n\n  bool empty() const\
    \ { return s == 0; }\n\n  int size() const { return s; }\n\n  __attribute__((target(\"\
    lzcnt\"))) inline uint64_t getbit(uint a) const {\n    return 64 - _lzcnt_u64(a);\n\
    \  }\n\n  void push(const uint &key, const Val &val) {\n    s++;\n    uint64_t\
    \ b = getbit(key ^ last);\n    vs[b].emplace_back(key, val);\n    ms[b] = min(key,\
    \ ms[b]);\n  }\n\n  pair<uint, Val> pop() {\n    if (ms[0] == uint(-1)) {\n  \
    \    int idx = 1;\n      while (ms[idx] == uint(-1)) idx++;\n      last = ms[idx];\n\
    \      for (auto &p : vs[idx]) {\n        uint64_t b = getbit(p.first ^ last);\n\
    \        vs[b].emplace_back(p);\n        ms[b] = min(p.first, ms[b]);\n      }\n\
    \      vs[idx].clear();\n      ms[idx] = uint(-1);\n    }\n    --s;\n    auto\
    \ res = vs[0].back();\n    vs[0].pop_back();\n    if (vs[0].empty()) ms[0] = uint(-1);\n\
    \    return res;\n  }\n};\n\n/**\n * @brief Radix Heap\n * @docs docs/data-structure/radix-heap.md\n\
    \ */\n#line 2 \"graph/static-graph.hpp\"\n\nnamespace StaticGraphImpl {\n\ntemplate\
    \ <typename T, bool Cond = is_void<T>::value>\nstruct E;\ntemplate <typename T>\n\
    struct E<T, false> {\n  int to;\n  T cost;\n  E() {}\n  E(const int& v, const\
    \ T& c) : to(v), cost(c) {}\n  operator int() const { return to; }\n};\ntemplate\
    \ <typename T>\nstruct E<T, true> {\n  int to;\n  E() {}\n  E(const int& v) :\
    \ to(v) {}\n  operator int() const { return to; }\n};\n\ntemplate <typename T\
    \ = void>\nstruct StaticGraph {\n private:\n  template <typename It>\n  struct\
    \ Es {\n    It b, e;\n    It begin() const { return b; }\n    It end() const {\
    \ return e; }\n    int size() const { return int(e - b); }\n    auto&& operator[](int\
    \ i) const { return b[i]; }\n  };\n  \n  int N, M, ec;\n  vector<int> head;\n\
    \  vector<pair<int, E<T>>> buf;\n  vector<E<T>> es;\n\n  void build() {\n    partial_sum(begin(head),\
    \ end(head), begin(head));\n    es.resize(M);\n    for (auto&& [u, e] : buf) es[--head[u]]\
    \ = e;\n  }\n\n public:\n  StaticGraph(int _n, int _m) : N(_n), M(_m), ec(0),\
    \ head(N + 1, 0) {\n    buf.reserve(M);\n  }\n\n  template <typename... Args>\n\
    \  void add_edge(int u, Args&&... args) {\n#pragma GCC diagnostic ignored \"-Wnarrowing\"\
    \n    buf.emplace_back(u, E<T>{std::forward<Args>(args)...});\n#pragma GCC diagnostic\
    \ warning \"-Wnarrowing\"\n    ++head[u];\n    if ((int)buf.size() == M) build();\n\
    \  }\n\n  Es<typename vector<E<T>>::iterator> operator[](int u) {\n    return\
    \ {begin(es) + head[u], begin(es) + head[u + 1]};\n  }\n  const Es<typename vector<E<T>>::const_iterator>\
    \ operator[](int u) const {\n    return {begin(es) + head[u], begin(es) + head[u\
    \ + 1]};\n  }\n  int size() const { return N; }\n};\n\n}  // namespace StaticGraphImpl\n\
    \nusing StaticGraphImpl::StaticGraph;\n\n/**\n * @brief Static Graph\n * @docs\
    \ docs/graph/static-graph.md\n */\n#line 5 \"shortest-path/dijkstra-fast.hpp\"\
    \n\ntemplate <typename T>\nvector<T> dijkstra(StaticGraph<T>& g, int start = 0)\
    \ {\n  vector<T> d(g.size(), T(-1));\n  RadixHeap<T, int> Q;\n  d[start] = 0;\n\
    \  Q.push(0, start);\n  while (!Q.empty()) {\n    auto p = Q.pop();\n    int u\
    \ = p.second;\n    if (d[u] < T(p.first)) continue;\n    T du = d[u];\n    for\
    \ (auto&& [v, c] : g[u]) {\n      if (d[v] == T(-1) || du + c < d[v]) {\n    \
    \    d[v] = du + c;\n        Q.push(d[v], v);\n      }\n    }\n  }\n  return d;\n\
    }\n\ntemplate <typename T>\nT dijkstra_point(StaticGraph<T>& g, int start, int\
    \ goal) {\n  vector<T> d(g.size(), T(-1));\n  RadixHeap<T, int> Q;\n  d[start]\
    \ = 0;\n  Q.push(0, start);\n  while (!Q.empty()) {\n    auto p = Q.pop();\n \
    \   int u = p.second;\n    if(u == goal) return d[u];\n    if (d[u] < T(p.first))\
    \ continue;\n    T du = d[u];\n    for (auto&& [v, c] : g[u]) {\n      if (d[v]\
    \ == T(-1) || du + c < d[v]) {\n        d[v] = du + c;\n        Q.push(d[v], v);\n\
    \      }\n    }\n  }\n  return -1;\n}\n\ntemplate <typename T>\nvector<pair<T,\
    \ int>> dijkstra_restore(StaticGraph<T>& g, int start = 0) {\n  vector<pair<T,\
    \ int>> d(g.size(), {T(-1), -1});\n  RadixHeap<T, int> Q;\n  d[start] = {0, -1};\n\
    \  Q.push(0, start);\n  while (!Q.empty()) {\n    auto p = Q.pop();\n    int u\
    \ = p.second;\n    if (d[u].first < T(p.first)) continue;\n    T du = d[u].first;\n\
    \    for (auto&& [v, c] : g[u]) {\n      if (d[v].first == T(-1) || du + c < d[v].first)\
    \ {\n        d[v] = {du + c, u};\n        Q.push(du + c, v);\n      }\n    }\n\
    \  }\n  return d;\n}\n\n/*\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\
    (\u5B9A\u6570\u500D\u9AD8\u901F\u5316)\n * @docs docs/shortest-path/dijkstra-fast.md\n\
    \ **/\n#line 5 \"verify/verify-yosupo-graph/yosupo-shortest-path-3.test.cpp\"\n\
    \nusing namespace Nyaan; void Nyaan::solve() {\n  int N, M, s, t;\n  rd(N, M,\
    \ s, t);\n\n  StaticGraph<ll> g(N, M);\n  rep(i, M) {\n    int a, b, c;\n    rd(a,\
    \ b, c);\n    g.add_edge(a, b, c);\n  }\n  auto d = dijkstra_restore(g, s);\n\
    \  if (d[t].first == -1) {\n    wtn(-1);\n    return;\n  }\n  vi ans;\n  for (int\
    \ r = t; r != s; r = d[r].second) ans.push_back(r);\n  ans.push_back(s);\n  wt(d[t].first,\
    \ ' ', sz(ans) - 1, '\\n');\n  repr(i, sz(ans) - 1) wt(ans[i + 1], ' ', ans[i],\
    \ '\\n');\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"../../template/template.hpp\"\n#include \"../../misc/fastio.hpp\"\n#include\
    \ \"../../shortest-path/dijkstra-fast.hpp\"\n\nusing namespace Nyaan; void Nyaan::solve()\
    \ {\n  int N, M, s, t;\n  rd(N, M, s, t);\n\n  StaticGraph<ll> g(N, M);\n  rep(i,\
    \ M) {\n    int a, b, c;\n    rd(a, b, c);\n    g.add_edge(a, b, c);\n  }\n  auto\
    \ d = dijkstra_restore(g, s);\n  if (d[t].first == -1) {\n    wtn(-1);\n    return;\n\
    \  }\n  vi ans;\n  for (int r = t; r != s; r = d[r].second) ans.push_back(r);\n\
    \  ans.push_back(s);\n  wt(d[t].first, ' ', sz(ans) - 1, '\\n');\n  repr(i, sz(ans)\
    \ - 1) wt(ans[i + 1], ' ', ans[i], '\\n');\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - misc/fastio.hpp
  - internal/internal-type-traits.hpp
  - shortest-path/dijkstra-fast.hpp
  - data-structure/radix-heap.hpp
  - graph/static-graph.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-graph/yosupo-shortest-path-3.test.cpp
  requiredBy: []
  timestamp: '2023-05-21 20:49:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-graph/yosupo-shortest-path-3.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-graph/yosupo-shortest-path-3.test.cpp
- /verify/verify/verify-yosupo-graph/yosupo-shortest-path-3.test.cpp.html
title: verify/verify-yosupo-graph/yosupo-shortest-path-3.test.cpp
---
