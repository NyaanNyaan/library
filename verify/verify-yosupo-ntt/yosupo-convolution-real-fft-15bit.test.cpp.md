---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/complex-fft.hpp
    title: ntt/complex-fft.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#line 1 \"verify/verify-yosupo-ntt/yosupo-convolution-real-fft-15bit.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n//\n#line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n\
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
    \ 4 \"verify/verify-yosupo-ntt/yosupo-convolution-real-fft-15bit.test.cpp\"\n\
    //\n#line 2 \"misc/fastio.hpp\"\n\n#line 8 \"misc/fastio.hpp\"\n\nusing namespace\
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
    using fastio::skip_space;\nusing fastio::wt;\nusing fastio::wtn;\n#line 2 \"ntt/complex-fft.hpp\"\
    \n\nnamespace ArbitraryModConvolution {\n\ntemplate <typename T>\nstruct Cp {\n\
    \  T x, y;\n  constexpr Cp() : x(0), y(0) {}\n  constexpr Cp(T _x, T _y) : x(_x),\
    \ y(_y) {}\n  constexpr inline Cp operator+(const Cp& c) const {\n    return Cp(x\
    \ + c.x, y + c.y);\n  }\n  constexpr inline Cp operator-(const Cp& c) const {\n\
    \    return Cp(x - c.x, y - c.y);\n  }\n  constexpr inline Cp operator*(const\
    \ Cp& c) const {\n    return Cp(x * c.x - y * c.y, x * c.y + y * c.x);\n  }\n\
    \  constexpr inline Cp operator-() const { return Cp(-x, -y); }\n  constexpr inline\
    \ Cp conj() const { return Cp(x, -y); }\n  constexpr inline Cp rotl() const {\
    \ return Cp(-y, x); }\n  friend ostream& operator<<(ostream& os, const Cp& c)\
    \ {\n    os << \"(\" << c.x << \", \" << c.y << \")\" << endl;\n    return os;\n\
    \  }\n};\n\nusing C = Cp<double>;\nconst long double PI = acosl(-1);\n\nstruct\
    \ CooleyTukey {\n  static vector<C> w;\n\n  static void setw(int k) {\n    --k;\n\
    \    if ((int)w.size() >= (1 << k)) return;\n    w.resize(1 << k);\n    vector<Cp<long\
    \ double>> base(k);\n    const long double arg = PI / (1 << k);\n    for (int\
    \ i = 0, j = 1 << (k - 1); j; i++, j >>= 1) {\n      complex<long double> z =\
    \ exp(complex<long double>(1i) * (arg * j));\n      base[i] = Cp<long double>{z.real(),\
    \ z.imag()};\n    }\n    genw(0, k - 1, Cp<long double>{1, 0}, base);\n  }\n\n\
    \  static void genw(int i, int b, Cp<long double> z,\n                   const\
    \ vector<Cp<long double>>& base) {\n    if (b == -1) {\n      w[i].x = z.x, w[i].y\
    \ = z.y;\n    } else {\n      genw(i, b - 1, z, base);\n      genw(i | (1 << b),\
    \ b - 1, z * base[b], base);\n    }\n  }\n\n  static void fft(vector<C>& a, int\
    \ k) {\n    if (k <= 0) return;\n    if (k == 1) {\n      C a1 = a[1];\n     \
    \ a[1] = a[0] - a[1];\n      a[0] = a[0] + a1;\n      return;\n    }\n    if (k\
    \ & 1) {\n      int v = 1 << (k - 1);\n      for (int j = 0; j < v; ++j) {\n \
    \       C ajv = a[j + v];\n        a[j + v] = a[j] - ajv;\n        a[j] = a[j]\
    \ + ajv;\n      }\n    }\n    int u = 1 << (k & 1), v = 1 << (k - 2 - (k & 1));\n\
    \    while (v) {\n      {\n        int j0 = 0;\n        int j1 = v;\n        int\
    \ j2 = j1 + v;\n        int j3 = j2 + v;\n        int je = v;\n        for (;\
    \ j0 < je; ++j0, ++j1, ++j2, ++j3) {\n          C t0 = a[j0], t1 = a[j1], t2 =\
    \ a[j2], t3 = a[j3];\n          C t0p2 = t0 + t2, t1p3 = t1 + t3;\n          C\
    \ t0m2 = t0 - t2, t1m3 = (t1 - t3) * w[1];\n          a[j0] = t0p2 + t1p3, a[j1]\
    \ = t0p2 - t1p3;\n          a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;\n      \
    \  }\n      }\n      // jh >= 1\n      for (int jh = 1; jh < u; ++jh) {\n    \
    \    int j0 = jh * v * 4;\n        int j1 = j0 + v;\n        int j2 = j1 + v;\n\
    \        int j3 = j2 + v;\n        int je = j1;\n        C ww = w[jh];\n     \
    \   C xx = w[jh << 1];\n        C wx = ww * xx;\n        for (; j0 < je; ++j0,\
    \ ++j1, ++j2, ++j3) {\n          C t0 = a[j0], t1 = a[j1] * xx, t2 = a[j2] * ww,\
    \ t3 = a[j3] * wx;\n          C t0p2 = t0 + t2, t1p3 = t1 + t3;\n          C t0m2\
    \ = t0 - t2, t1m3 = (t1 - t3) * w[1];\n          a[j0] = t0p2 + t1p3, a[j1] =\
    \ t0p2 - t1p3;\n          a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;\n        }\n\
    \      }\n      u <<= 2, v >>= 2;\n    }\n  }\n\n  static void ifft(vector<C>&\
    \ a, int k) {\n    if ((int)a.size() <= 1) return;\n    if (k == 1) {\n      C\
    \ a1 = a[1];\n      a[1] = a[0] - a[1];\n      a[0] = a[0] + a1;\n      return;\n\
    \    }\n    int u = 1 << (k - 2);\n    int v = 1;\n    while (u) {\n      // jh\
    \ = 0\n      {\n        int j0 = 0;\n        int j1 = v;\n        int j2 = j1\
    \ + v;\n        int j3 = j2 + v;\n        for (; j0 < v; ++j0, ++j1, ++j2, ++j3)\
    \ {\n          C t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];\n          C\
    \ t0p1 = t0 + t1, t2p3 = t2 + t3;\n          C t0m1 = t0 - t1, t2m3 = (t2 - t3)\
    \ * w[1].conj();\n          a[j0] = t0p1 + t2p3, a[j2] = t0p1 - t2p3;\n      \
    \    a[j1] = t0m1 + t2m3, a[j3] = t0m1 - t2m3;\n        }\n      }\n      // jh\
    \ >= 1\n      for (int jh = 1; jh < u; ++jh) {\n        int j0 = (jh * v) << 2;\n\
    \        int j1 = j0 + v;\n        int j2 = j1 + v;\n        int j3 = j2 + v;\n\
    \        int je = j1;\n        C ww = w[jh].conj();\n        C xx = w[jh << 1].conj();\n\
    \        C yy = w[(jh << 1) + 1].conj();\n        for (; j0 < je; ++j0, ++j1,\
    \ ++j2, ++j3) {\n          C t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];\n\
    \          C t0p1 = t0 + t1, t2p3 = t2 + t3;\n          C t0m1 = (t0 - t1) * xx,\
    \ t2m3 = (t2 - t3) * yy;\n          a[j0] = t0p1 + t2p3, a[j2] = (t0p1 - t2p3)\
    \ * ww;\n          a[j1] = t0m1 + t2m3, a[j3] = (t0m1 - t2m3) * ww;\n        }\n\
    \      }\n      u >>= 2;\n      v <<= 2;\n    }\n    if (k & 1) {\n      u = 1\
    \ << (k - 1);\n      for (int j = 0; j < u; j++) {\n        C ajv = a[j] - a[j\
    \ + u];\n        a[j] = a[j] + a[j + u];\n        a[j + u] = ajv;\n      }\n \
    \   }\n  }\n\n  static void fft_real(vector<C>& AL, vector<C>& AH, int k) {\n\
    \    fft(AL, k);\n    AH[0] = C{AL[0].y * 2.0, 0};\n    AL[0] = C{AL[0].x * 2.0,\
    \ 0};\n    AH[1] = C{AL[1].y * 2.0, 0};\n    AL[1] = C{AL[1].x * 2.0, 0};\n  \
    \  for (int i = 2, y = 2; y < (1 << k); y <<= 1) {\n      for (; i < 2 * y; i\
    \ += 2) {\n        int j = i ^ (y - 1);\n        AH[i] = (AL[j].conj() - AL[i]).rotl();\n\
    \        AL[i] = (AL[j].conj() + AL[i]);\n        AH[j] = AH[i].conj();\n    \
    \    AL[j] = AL[i].conj();\n      }\n    }\n  }\n\n  // naive convolution for\
    \ int\n  template <typename T, enable_if_t<is_integral<T>::value, nullptr_t> =\
    \ nullptr>\n  static vector<long long> multiply(const vector<T>& s, const vector<T>&\
    \ t) {\n    int l = s.size() + t.size() - 1;\n    if (min(s.size(), t.size())\
    \ <= 40) {\n      vector<long long> u(l);\n      for (int i = 0; i < (int)s.size();\
    \ i++) {\n        for (int j = 0; j < (int)t.size(); j++) u[i + j] += 1LL * s[i]\
    \ * t[j];\n      }\n      return u;\n    }\n\n    int k = 2, M = 4;\n    while\
    \ (M < l) M <<= 1, ++k;\n    setw(k);\n    auto round = [](double x) -> long long\
    \ {\n      return (long long)(x + (x > 0 ? 0.5 : -0.5));\n    };\n\n    vector<C>\
    \ a(M);\n    for (int i = 0; i < (int)s.size(); i++) a[i].x = s[i];\n    for (int\
    \ i = 0; i < (int)t.size(); i++) a[i].y = t[i];\n    fft(a, k);\n\n    a[0].y\
    \ = 4.0 * a[0].x * a[0].y;\n    a[1].y = 4.0 * a[1].x * a[1].y;\n    a[0].x =\
    \ a[1].x = 0.0;\n    for (int i = 2; i < M; i += 2) {\n      int c = 1 << (31\
    \ - __builtin_clz(i));\n      int j = i ^ (c - 1);\n      a[i] = (a[i] + a[j].conj())\
    \ * (a[i] - a[j].conj());\n      a[j] = -a[i].conj();\n    }\n\n    vector<C>\
    \ b(M / 2);\n    for (int j = 0; j < M / 2; j++) {\n      C tmp1 = a[j * 2 + 0]\
    \ + a[j * 2 + 1];\n      C tmp2 = (a[j * 2 + 0] - a[j * 2 + 1]) * w[j].conj();\n\
    \      b[j] = tmp1 + tmp2.rotl();\n    }\n    ifft(b, k - 1);\n\n    vector<long\
    \ long> u(l);\n    for (int i = 0; i < l; i++) {\n      if (i & 1) {\n       \
    \ u[i] = round(-b[i >> 1].x / (4.0 * M));\n      } else {\n        u[i] = round(b[i\
    \ >> 1].y / (4.0 * M));\n      }\n    }\n    return u;\n  }\n\n  static vector<double>\
    \ multiply(const vector<double>& s,\n                                 const vector<double>&\
    \ t) {\n    int l = s.size() + t.size() - 1;\n    if (min(s.size(), t.size())\
    \ <= 40) {\n      vector<double> u(l);\n      for (int i = 0; i < (int)s.size();\
    \ i++) {\n        for (int j = 0; j < (int)t.size(); j++) u[i + j] += s[i] * t[j];\n\
    \      }\n      return u;\n    }\n\n    int k = 2, M = 4;\n    while (M < l) M\
    \ <<= 1, ++k;\n    setw(k);\n\n    vector<C> a(M);\n    for (int i = 0; i < (int)s.size();\
    \ i++) a[i].x = s[i];\n    for (int i = 0; i < (int)t.size(); i++) a[i].y = t[i];\n\
    \    fft(a, k);\n\n    a[0].y = 4.0 * a[0].x * a[0].y;\n    a[1].y = 4.0 * a[1].x\
    \ * a[1].y;\n    a[0].x = a[1].x = 0.0;\n    for (int i = 2; i < M; i += 2) {\n\
    \      int c = 1 << (31 - __builtin_clz(i));\n      int j = i ^ (c - 1);\n   \
    \   a[i] = (a[i] + a[j].conj()) * (a[i] - a[j].conj());\n      a[j] = -a[i].conj();\n\
    \    }\n\n    vector<C> b(M / 2);\n    for (int j = 0; j < M / 2; j++) {\n   \
    \   C tmp1 = a[j * 2 + 0] + a[j * 2 + 1];\n      C tmp2 = (a[j * 2 + 0] - a[j\
    \ * 2 + 1]) * w[j].conj();\n      b[j] = tmp1 + tmp2.rotl();\n    }\n    ifft(b,\
    \ k - 1);\n\n    vector<double> u(l);\n    for (int i = 0; i < l; i++) {\n   \
    \   if (i & 1) {\n        u[i] = -b[i >> 1].x / (4.0 * M);\n      } else {\n \
    \       u[i] = b[i >> 1].y / (4.0 * M);\n      }\n    }\n    return u;\n  }\n\n\
    \  template <unsigned int MOD>\n  static vector<int> multiply_15bit(const vector<int>&\
    \ a,\n                                    const vector<int>& b) {\n    using u64\
    \ = unsigned long long;\n    constexpr u64 B = 32000;\n    int l = a.size() +\
    \ b.size() - 1;\n    int k = 2, M = 4;\n    while (M < l) M <<= 1, ++k;\n    setw(k);\n\
    \    auto round = [](double x) -> u64 { return u64(x + 0.5); };\n\n    vector<C>\
    \ AL(M), AH(M), BL(M), BH(M);\n    for (int i = 0; i < (int)a.size(); i++) {\n\
    \      AL[i] = C{double(a[i] % B), double(a[i] / B)};\n    }\n    for (int i =\
    \ 0; i < (int)b.size(); i++) {\n      BL[i] = C{double(b[i] % B), double(b[i]\
    \ / B)};\n    }\n\n    fft_real(AL, AH, k);\n    fft_real(BL, BH, k);\n\n    for\
    \ (int i = 0; i < M; i++) {\n      C tmp = AL[i] * BL[i] + (AH[i] * BH[i]).rotl();\n\
    \      BH[i] = AL[i] * BH[i] + (AH[i] * BL[i]).rotl();\n      BL[i] = tmp;\n \
    \   }\n\n    ifft(BL, k);\n    ifft(BH, k);\n\n    vector<int> u(l);\n    double\
    \ im = 1.0 / (4.0 * M);\n    for (int i = 0; i < l; i++) {\n      BL[i].x *= im,\
    \ BL[i].y *= im;\n      BH[i].x *= im, BH[i].y *= im;\n      int x1 = u64(round(BL[i].x))\
    \ % MOD;\n      int x2 = u64(round(BH[i].x) + round(BH[i].y)) % MOD * B % MOD;\n\
    \      int x3 = u64(round(BL[i].y)) % MOD * (B * B % MOD) % MOD;\n      if ((x1\
    \ += x2) >= (int)MOD) x1 -= MOD;\n      if ((x1 += x3) >= (int)MOD) x1 -= MOD;\n\
    \      u[i] = x1;\n    }\n    return u;\n  }\n};\nvector<C> CooleyTukey::w;\n\n\
    }  // namespace ArbitraryModConvolution\n#line 7 \"verify/verify-yosupo-ntt/yosupo-convolution-real-fft-15bit.test.cpp\"\
    \n\nvoid Nyaan::solve() {\n  using namespace ArbitraryModConvolution;\n  int N,\
    \ M;\n  rd(N, M);\n  vector<int> a(N), b(M);\n  for (auto& x : a) rd(x);\n  for\
    \ (auto& x : b) rd(x);\n\n  auto c = CooleyTukey::multiply_15bit<1000000007>(a,\
    \ b);\n  for (int i = 0; i < N + M - 1; i++) {\n    wt(c[i], \" \\n\"[i == N +\
    \ M - 2]);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n//\n#include \"../../template/template.hpp\"\n//\n#include \"../../misc/fastio.hpp\"\
    \n#include \"../../ntt/complex-fft.hpp\"\n\nvoid Nyaan::solve() {\n  using namespace\
    \ ArbitraryModConvolution;\n  int N, M;\n  rd(N, M);\n  vector<int> a(N), b(M);\n\
    \  for (auto& x : a) rd(x);\n  for (auto& x : b) rd(x);\n\n  auto c = CooleyTukey::multiply_15bit<1000000007>(a,\
    \ b);\n  for (int i = 0; i < N + M - 1; i++) {\n    wt(c[i], \" \\n\"[i == N +\
    \ M - 2]);\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - misc/fastio.hpp
  - internal/internal-type-traits.hpp
  - ntt/complex-fft.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ntt/yosupo-convolution-real-fft-15bit.test.cpp
  requiredBy: []
  timestamp: '2023-05-21 20:49:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ntt/yosupo-convolution-real-fft-15bit.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ntt/yosupo-convolution-real-fft-15bit.test.cpp
- /verify/verify/verify-yosupo-ntt/yosupo-convolution-real-fft-15bit.test.cpp.html
title: verify/verify-yosupo-ntt/yosupo-convolution-real-fft-15bit.test.cpp
---
