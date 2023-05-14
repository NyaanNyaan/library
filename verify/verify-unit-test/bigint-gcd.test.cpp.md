---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math-fast/gcd.hpp
    title: binary GCD
  - icon: ':heavy_check_mark:'
    path: math/bigint-gcd.hpp
    title: math/bigint-gcd.hpp
  - icon: ':heavy_check_mark:'
    path: math/bigint.hpp
    title: "\u591A\u500D\u9577\u6574\u6570"
  - icon: ':heavy_check_mark:'
    path: matrix/matrix.hpp
    title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: misc/timer.hpp
    title: misc/timer.hpp
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
  bundledCode: "#line 1 \"verify/verify-unit-test/bigint-gcd.test.cpp\"\n#define PROBLEM\
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
    \ 4 \"verify/verify-unit-test/bigint-gcd.test.cpp\"\n//\n#line 2 \"misc/rng.hpp\"\
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
    using my_rand::rnd;\nusing my_rand::rng;\n#line 2 \"misc/timer.hpp\"\n\n#line\
    \ 4 \"misc/timer.hpp\"\n\nstruct Timer {\n  chrono::high_resolution_clock::time_point\
    \ st;\n\n  Timer() { reset(); }\n\n  void reset() { st = chrono::high_resolution_clock::now();\
    \ }\n\n  chrono::milliseconds::rep elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n\
    \    return chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n\
    };\n#line 7 \"verify/verify-unit-test/bigint-gcd.test.cpp\"\n//\n#line 2 \"math/bigint-gcd.hpp\"\
    \n\n#line 4 \"math/bigint-gcd.hpp\"\nusing namespace std;\n\n#line 2 \"math-fast/gcd.hpp\"\
    \n\n#line 4 \"math-fast/gcd.hpp\"\nusing namespace std;\n\nnamespace BinaryGCDImpl\
    \ {\nusing u64 = unsigned long long;\nusing i8 = char;\n\nu64 binary_gcd(u64 a,\
    \ u64 b) {\n  if (a == 0 || b == 0) return a + b;\n  i8 n = __builtin_ctzll(a);\n\
    \  i8 m = __builtin_ctzll(b);\n  a >>= n;\n  b >>= m;\n  n = min(n, m);\n  while\
    \ (a != b) {\n    u64 d = a - b;\n    i8 s = __builtin_ctzll(d);\n    bool f =\
    \ a > b;\n    b = f ? b : a;\n    a = (f ? d : -d) >> s;\n  }\n  return a << n;\n\
    }\n\nusing u128 = __uint128_t;\n// a > 0\nint ctz128(u128 a) {\n  u64 lo = a &\
    \ u64(-1);\n  return lo ? __builtin_ctzll(lo) : 64 + __builtin_ctzll(a >> 64);\n\
    }\nu128 binary_gcd128(u128 a, u128 b) {\n  if (a == 0 || b == 0) return a + b;\n\
    \  i8 n = ctz128(a);\n  i8 m = ctz128(b);\n  a >>= n;\n  b >>= m;\n  n = min(n,\
    \ m);\n  while (a != b) {\n    u128 d = a - b;\n    i8 s = ctz128(d);\n    bool\
    \ f = a > b;\n    b = f ? b : a;\n    a = (f ? d : -d) >> s;\n  }\n  return a\
    \ << n;\n}\n\n}  // namespace BinaryGCDImpl\n\nlong long binary_gcd(long long\
    \ a, long long b) {\n  return BinaryGCDImpl::binary_gcd(abs(a), abs(b));\n}\n\
    __int128_t binary_gcd128(__int128_t a, __int128_t b) {\n  if (a < 0) a = -a;\n\
    \  if (b < 0) b = -b;\n  return BinaryGCDImpl::binary_gcd128(a, b);\n}\n\n/**\n\
    \ * @brief binary GCD\n */\n#line 2 \"math/bigint.hpp\"\n\n#line 10 \"math/bigint.hpp\"\
    \nusing namespace std;\n\n#line 2 \"ntt/arbitrary-ntt.hpp\"\n\n#line 2 \"modint/montgomery-modint.hpp\"\
    \n\n\n\ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt {\n  using mint =\
    \ LazyMontgomeryModInt;\n  using i32 = int32_t;\n  using u32 = uint32_t;\n  using\
    \ u64 = uint64_t;\n\n  static constexpr u32 get_r() {\n    u32 ret = mod;\n  \
    \  for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n\
    \  static constexpr u32 r = get_r();\n  static constexpr u32 n2 = -u64(mod) %\
    \ mod;\n  static_assert(r * mod == 1, \"invalid, r * mod != 1\");\n  static_assert(mod\
    \ < (1 << 30), \"invalid, mod >= 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"\
    invalid, mod % 2 == 0\");\n\n  u32 a;\n\n  constexpr LazyMontgomeryModInt() :\
    \ a(0) {}\n  constexpr LazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b\
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
    \ }\n\n  constexpr mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n   \
    \ while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>=\
    \ 1;\n    }\n    return ret;\n  }\n  \n  constexpr mint inverse() const { return\
    \ pow(mod - 2); }\n\n  friend ostream &operator<<(ostream &os, const mint &b)\
    \ {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is,\
    \ mint &b) {\n    int64_t t;\n    is >> t;\n    b = LazyMontgomeryModInt<mod>(t);\n\
    \    return (is);\n  }\n  \n  constexpr u32 get() const {\n    u32 ret = reduce(a);\n\
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
    \    setwy(k);\n    vector<mint> s(M), t(M);\n    for (int i = 0; i < (int)a.size();\
    \ ++i) s[i] = a[i];\n    for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i];\n\
    \    fft4(s, k);\n    fft4(t, k);\n    for (int i = 0; i < M; ++i) s[i] *= t[i];\n\
    \    ifft4(s, k);\n    s.resize(l);\n    mint invm = mint(M).inverse();\n    for\
    \ (int i = 0; i < l; ++i) s[i] *= invm;\n    return s;\n  }\n\n  void ntt_doubling(vector<mint>\
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
    \ * w2;\n  }\n  return ret;\n}\n}  // namespace ArbitraryNTT\n#line 13 \"math/bigint.hpp\"\
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
    \ dat(d) {}\n\n  template <typename I, enable_if_t<is_integral_v<I> ||\n     \
    \                               is_same_v<I, __int128_t>>* = nullptr>\n  MultiPrecisionInteger(I\
    \ x) : neg(false) {\n    if constexpr (is_signed_v<I> || is_same_v<I, __int128_t>)\
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
    \ I, enable_if_t<is_integral_v<I> ||\n                                    is_same_v<I,\
    \ __int128_t>>* = nullptr>\n  static vector<int> _integer_to_vec(I x) {\n    if\
    \ constexpr (is_signed_v<I> || is_same_v<I, __int128_t>) {\n      assert(x >=\
    \ 0);\n    }\n    vector<int> res;\n    while (x) res.push_back(x % D), x /= D;\n\
    \    return res;\n  }\n\n  static long long _to_ll(const vector<int>& a) {\n \
    \   long long res = 0;\n    for (int i = (int)a.size() - 1; i >= 0; i--) res =\
    \ res * D + a[i];\n    return res;\n  }\n\n  static __int128_t _to_i128(const\
    \ vector<int>& a) {\n    __int128_t res = 0;\n    for (int i = (int)a.size() -\
    \ 1; i >= 0; i--) res = res * D + a[i];\n    return res;\n  }\n\n  static void\
    \ _dump(const vector<int>& a, string s = \"\") {\n    if (!s.empty()) cerr <<\
    \ s << \" : \";\n    cerr << \"{ \";\n    for (int i = 0; i < (int)a.size(); i++)\
    \ cerr << a[i] << \", \";\n    cerr << \"}\" << endl;\n  }\n};\n\nusing bigint\
    \ = MultiPrecisionInteger;\n\n/**\n * @brief \u591A\u500D\u9577\u6574\u6570\n\
    \ */\n#line 8 \"math/bigint-gcd.hpp\"\n\nnamespace GCDforBigintImpl {\n\nbigint\
    \ bigint_pow(bigint a, long long k) {\n  bigint res{1};\n  while (k) {\n    if\
    \ (k & 1) res = res * a;\n    k >>= 1;\n    if (k) a = a * a;\n  }\n  return res;\n\
    }\n\n// a = 2^x 5^y \u306E\u5F62\u3067\u8868\u73FE\u3059\u308B\npair<int, int>\
    \ shrink(int a) {\n  assert(a > 0);\n  int x = __builtin_ctz(a);\n  a >>= x;\n\
    \  int y = a == 1        ? 0\n          : a == 5      ? 1\n          : a == 25\
    \     ? 2\n          : a == 125    ? 3\n          : a == 625    ? 4\n        \
    \  : a == 3125   ? 5\n          : a == 15625  ? 6\n          : a == 78125  ? 7\n\
    \          : a == 390625 ? 8\n                        : 9;\n  return {x, y};\n\
    }\n\npair<int, int> shrink(bigint& a) {\n  assert(a.neg == false);\n  if (a.dat.empty())\
    \ return {0, 0};\n  pair<int, int> res{0, 0};\n  while (true) {\n    int g = gcd(bigint::D,\
    \ a.dat[0]);\n    if (g == 1) break;\n    if (g != bigint::D) a *= bigint::D /\
    \ g;\n    a.dat.erase(begin(a.dat));\n    auto s = shrink(g);\n    res.first +=\
    \ s.first, res.second += s.second;\n  }\n  return res;\n}\n\ntemplate <bool FAST\
    \ = false>\nbigint gcd_d_ary(bigint a, bigint b) {\n  a.neg = b.neg = false;\n\
    \  if constexpr (FAST) {\n    if (max<int>(a.dat.size(), b.dat.size()) <= 4) {\n\
    \      return __int128_t(BinaryGCDImpl::binary_gcd128(a.to_i128(), b.to_i128()));\n\
    \    }\n  }\n  if (a.dat.empty()) return b;\n  if (b.dat.empty()) return a;\n\
    \  pair<int, int> s = shrink(a), t = shrink(b);\n  if (a < b) swap(a, b);\n  while\
    \ (true) {\n    if (b.dat.empty()) break;\n    if constexpr (FAST) {\n      if\
    \ ((int)a.dat.size() <= 4) break;\n    }\n    a = a - b;\n    if (!a.dat.empty())\
    \ {\n      while (true) {\n        int g = gcd<int>(a.dat[0], bigint::D);\n  \
    \      if (g == 1) break;\n        if (g != bigint::D) a *= bigint::D / g;\n \
    \       a.dat.erase(begin(a.dat));\n      }\n    }\n    if (a < b) swap(a, b);\n\
    \  }\n  assert(a >= b);\n  bigint g;\n  if constexpr (FAST) {\n    if (b.dat.empty())\
    \ {\n      g = a;\n    } else {\n      g = __int128_t(BinaryGCDImpl::binary_gcd128(a.to_i128(),\
    \ b.to_i128()));\n    }\n  } else {\n    g = a;\n  }\n  int e2 = min(s.first,\
    \ t.first);\n  int e5 = min(s.second, t.second);\n  if (e2) g *= bigint_pow(bigint{2},\
    \ e2);\n  if (e5) g *= bigint_pow(bigint{5}, e5);\n  return g;\n}\n}  // namespace\
    \ GCDforBigintImpl\n\nMultiPrecisionInteger gcd(const MultiPrecisionInteger& a,\n\
    \                          const MultiPrecisionInteger& b) {\n  return GCDforBigintImpl::gcd_d_ary<true>(a,\
    \ b);\n}\n#line 9 \"verify/verify-unit-test/bigint-gcd.test.cpp\"\n//\n#line 2\
    \ \"matrix/matrix.hpp\"\n\ntemplate <class T>\nstruct Matrix {\n  vector<vector<T>\
    \ > A;\n\n  Matrix() = default;\n  Matrix(int n, int m) : A(n, vector<T>(m, T()))\
    \ {}\n  Matrix(int n) : A(n, vector<T>(n, T())){};\n\n  int H() const { return\
    \ A.size(); }\n\n  int W() const { return A[0].size(); }\n\n  int size() const\
    \ { return A.size(); }\n\n  inline const vector<T> &operator[](int k) const {\
    \ return A[k]; }\n\n  inline vector<T> &operator[](int k) { return A[k]; }\n\n\
    \  static Matrix I(int n) {\n    Matrix mat(n);\n    for (int i = 0; i < n; i++)\
    \ mat[i][i] = 1;\n    return (mat);\n  }\n\n  Matrix &operator+=(const Matrix\
    \ &B) {\n    int n = H(), m = W();\n    assert(n == B.H() && m == B.W());\n  \
    \  for (int i = 0; i < n; i++)\n      for (int j = 0; j < m; j++) (*this)[i][j]\
    \ += B[i][j];\n    return (*this);\n  }\n\n  Matrix &operator-=(const Matrix &B)\
    \ {\n    int n = H(), m = W();\n    assert(n == B.H() && m == B.W());\n    for\
    \ (int i = 0; i < n; i++)\n      for (int j = 0; j < m; j++) (*this)[i][j] -=\
    \ B[i][j];\n    return (*this);\n  }\n\n  Matrix &operator*=(const Matrix &B)\
    \ {\n    int n = H(), m = B.W(), p = W();\n    assert(p == B.H());\n    vector<vector<T>\
    \ > C(n, vector<T>(m, T{}));\n    for (int i = 0; i < n; i++)\n      for (int\
    \ k = 0; k < p; k++)\n        for (int j = 0; j < m; j++) C[i][j] += (*this)[i][k]\
    \ * B[k][j];\n    A.swap(C);\n    return (*this);\n  }\n\n  Matrix &operator^=(long\
    \ long k) {\n    Matrix B = Matrix::I(H());\n    while (k > 0) {\n      if (k\
    \ & 1) B *= *this;\n      *this *= *this;\n      k >>= 1LL;\n    }\n    A.swap(B.A);\n\
    \    return (*this);\n  }\n\n  Matrix operator+(const Matrix &B) const { return\
    \ (Matrix(*this) += B); }\n\n  Matrix operator-(const Matrix &B) const { return\
    \ (Matrix(*this) -= B); }\n\n  Matrix operator*(const Matrix &B) const { return\
    \ (Matrix(*this) *= B); }\n\n  Matrix operator^(const long long k) const { return\
    \ (Matrix(*this) ^= k); }\n\n  bool operator==(const Matrix &B) const {\n    assert(H()\
    \ == B.H() && W() == B.W());\n    for (int i = 0; i < H(); i++)\n      for (int\
    \ j = 0; j < W(); j++)\n        if (A[i][j] != B[i][j]) return false;\n    return\
    \ true;\n  }\n\n  bool operator!=(const Matrix &B) const {\n    assert(H() ==\
    \ B.H() && W() == B.W());\n    for (int i = 0; i < H(); i++)\n      for (int j\
    \ = 0; j < W(); j++)\n        if (A[i][j] != B[i][j]) return true;\n    return\
    \ false;\n  }\n\n  friend ostream &operator<<(ostream &os, const Matrix &p) {\n\
    \    int n = p.H(), m = p.W();\n    for (int i = 0; i < n; i++) {\n      os <<\
    \ (i ? \"   \" : \"\") << \"[\";\n      for (int j = 0; j < m; j++) {\n      \
    \  os << p[i][j] << (j + 1 == m ? \"]\\n\" : \",\");\n      }\n    }\n    return\
    \ (os);\n  }\n\n  T determinant() const {\n    Matrix B(*this);\n    assert(H()\
    \ == W());\n    T ret = 1;\n    for (int i = 0; i < H(); i++) {\n      int idx\
    \ = -1;\n      for (int j = i; j < W(); j++) {\n        if (B[j][i] != 0) {\n\
    \          idx = j;\n          break;\n        }\n      }\n      if (idx == -1)\
    \ return 0;\n      if (i != idx) {\n        ret *= T(-1);\n        swap(B[i],\
    \ B[idx]);\n      }\n      ret *= B[i][i];\n      T inv = T(1) / B[i][i];\n  \
    \    for (int j = 0; j < W(); j++) {\n        B[i][j] *= inv;\n      }\n     \
    \ for (int j = i + 1; j < H(); j++) {\n        T a = B[j][i];\n        if (a ==\
    \ 0) continue;\n        for (int k = i; k < W(); k++) {\n          B[j][k] -=\
    \ B[i][k] * a;\n        }\n      }\n    }\n    return ret;\n  }\n};\n\n/**\n *\
    \ @brief \u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA\n */\n#line 12 \"verify/verify-unit-test/bigint-gcd.test.cpp\"\
    \n\nnamespace GCDforBigintImpl {\n\nusing Mat = Matrix<bigint>;\n\n// \u4E0B\u4F4D\
    \ d \u6841\u3092\u9664\u304F\nbigint suf(const bigint& n, int d) {\n  d = min(d,\
    \ (int)n.dat.size());\n  return bigint{false, vector<int>{begin(n.dat) + d, end(n.dat)}};\n\
    }\n\n// \u7E26\u30D9\u30AF\u30C8\u30EB (p00, p10) \u3092\u4F5C\u308B\nMat make_vec(const\
    \ bigint& p00, const bigint& p10) {\n  Mat m(2, 1);\n  m[0][0] = p00, m[1][0]\
    \ = p10;\n  return m;\n}\n\ntemplate <typename I>\nMat inner_naive(Mat& p) {\n\
    \  assert(p[0][0] >= p[1][0]);\n  assert((int)p[0][0].dat.size() <= 4);\n  I g\
    \ = 1;\n  // solve : ax + by = gcd(a, b)\n  // return : pair(x, y)\n  auto extgcd\
    \ = [&](auto rc, I a, I b) -> pair<I, I> {\n    if (b == 0) {\n      g = a;\n\
    \      return make_pair(1, 0);\n    }\n    I x, y;\n    tie(y, x) = rc(rc, b,\
    \ a % b);\n    y -= a / b * x;\n    return make_pair(x, y);\n  };\n  I a = p[0][0].to_i128(),\
    \ b = p[1][0].to_i128(), x, y;\n  tie(x, y) = extgcd(extgcd, a, b);\n  Mat m(2);\n\
    \  m[0][0] = x, m[0][1] = y;\n  m[1][0] = b / g, m[1][1] = -a / g;\n  return m;\n\
    }\n// p_0 >= p_1, 1 \u624B\u9032\u3081\u308B\nvoid inner_succ(Mat& m, Mat& p)\
    \ {\n  assert(p[0][0] >= p[1][0]);\n  if (p[1][0] == 0) return;\n  auto [quo,\
    \ rem] = divmod(p[0][0], p[1][0]);\n  m[0][0] -= m[1][0] * quo;\n  m[0][1] -=\
    \ m[1][1] * quo;\n  swap(m[0][0], m[1][0]), swap(m[0][1], m[1][1]);\n  p[0][0]\
    \ = p[1][0], p[1][0] = rem;\n}\nMat inner_half_gcd(Mat p) {\n  assert(p[0][0]\
    \ >= p[1][0]);\n  int n = p[0][0].dat.size(), m = p[1][0].dat.size();\n  if (n\
    \ <= 2) return inner_naive<long long>(p);\n  if (n <= 4) return inner_naive<__int128_t>(p);\n\
    \  int k = (n + 1) / 2;\n  if (m <= k) return Mat::I(2);\n  Mat m1 = inner_half_gcd(make_vec(suf(p[0][0],\
    \ k), suf(p[1][0], k)));\n  p = m1 * p;\n  for (int i = 0; i < 2; i++) {\n   \
    \ if (p[i][0] < 0) {\n      m1[i][0] = -m1[i][0], m1[i][1] = -m1[i][1], p[i][0]\
    \ = -p[i][0];\n    }\n  }\n  if (p[0][0] < p[1][0]) {\n    swap(m1[0][0], m1[1][0]),\
    \ swap(m1[0][1], m1[1][1]);\n    swap(p[0][0], p[1][0]);\n  }\n  if ((int)p[1][0].dat.size()\
    \ <= k) return m1;\n  for (int i = 0; i < 20; i++) inner_succ(m1, p);\n  if ((int)p[1][0].dat.size()\
    \ <= k) return m1;\n  int j = (k + 1) / 2;\n  Mat m2 = inner_half_gcd(make_vec(suf(p[0][0],\
    \ j), suf(p[1][0], j)));\n  return m2 * m1;\n}\n\n__int128_t gcd_naive_i128(__int128_t\
    \ a, __int128_t b) {\n  assert(a >= 0 and b >= 0);\n  while (b) swap(a %= b, b);\n\
    \  return a;\n}\nbigint gcd_naive(bigint a, bigint b) {\n  a = abs(a), b = abs(b);\n\
    \  if (a < b) swap(a, b);\n  while (b != bigint{}) {\n    if ((int)a.dat.size()\
    \ <= 4) {\n      return gcd_naive_i128(a.to_i128(), b.to_i128());\n    }\n   \
    \ swap(a %= b, b);\n  }\n  return a;\n}\n\nbigint gcd_half(bigint a, bigint b)\
    \ {\n  a = abs(a), b = abs(b);\n  if (a < b) swap(a, b);\n  Mat p = make_vec(a,\
    \ b);\n  while (p[1][0] != 0) {\n    Mat m1 = inner_half_gcd(p);\n    p = m1 *\
    \ p;\n    p[0][0].neg = p[1][0].neg = false;\n    if (p[0][0] < p[1][0]) swap(p[0][0],\
    \ p[1][0]);\n    inner_succ(m1, p);\n  }\n  return p[0][0];\n}\n\n}  // namespace\
    \ GCDforBigintImpl\n\nusing GCDforBigintImpl::gcd_d_ary;\nusing GCDforBigintImpl::gcd_half;\n\
    using GCDforBigintImpl::gcd_naive;\n\nusing namespace Nyaan;\n\nvoid q() {\n \
    \ {\n    bigint a =\n        \"1234567900000000000000000000000000000000000000000000000000000000000\"\
    s;\n    bigint b =\n        \"111111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\"\
    s;\n    bigint g = gcd_half(a, b);\n    trc(a, b, g);\n  }\n  auto gen = [&](int\
    \ d) {\n    string S(d, '0');\n    each(c, S) c += rng(0, 9);\n    while (sz(S)\
    \ and S[0] == '0') S.erase(begin(S));\n    if (S.empty()) return bigint{};\n \
    \   return bigint{S};\n  };\n\n#ifdef PROFILER\n  {\n    for (int d = 1; d <=\
    \ 256; d *= 2) {\n      V<bigint> as, bs;\n      int T = 1000;\n      rep(i, T)\
    \ {\n        as.push_back(gen(d));\n        bs.push_back(gen(d));\n      }\n\n\
    \      Timer timer;\n      bigint g1 = 0, g2 = 0;\n\n      timer.reset();\n  \
    \    rep(i, T) g2 += gcd_d_ary(as[i], bs[i]);\n      ll t2 = timer.elapsed();\n\
    \n      trc2(d, t2);\n    }\n    exit(0);\n  }\n#endif\n\n  auto check = [&](bigint\
    \ a, bigint b) -> void {\n    bigint g1 = gcd_half(a, b);\n    bigint g2 = gcd_naive(a,\
    \ b);\n    bigint g3 = gcd_d_ary<false>(a, b);\n    bigint g4 = gcd_d_ary<true>(a,\
    \ b);\n    if (g1 != g2 or g2 != g3 or g3 != g4) {\n      trc2(a, b);\n      trc2(g1);\n\
    \      trc2(g2);\n      trc2(g3);\n      trc2(g4);\n      trc2(divmod(g3, g4));\n\
    \      exit(1);\n    }\n    if (g1 == 0) return;\n    auto [aq, ar] = divmod(a,\
    \ g1);\n    auto [bq, br] = divmod(b, g1);\n    assert(ar == 0 and br == 0);\n\
    \    assert(gcd_half(aq, bq) == 1);\n    assert(gcd_naive(aq, bq) == 1);\n   \
    \ assert(gcd_d_ary<false>(aq, bq) == 1);\n    assert(gcd_d_ary<true>(aq, bq) ==\
    \ 1);\n  };\n\n  rep(s, 100) rep(t, 100) {\n    bigint a = s;\n    bigint b =\
    \ t;\n    check(a, b);\n    if (a != 0) check(-a, b);\n    if (b != 0) check(a,\
    \ -b);\n    if (a != 0 and b != 0) check(-a, -b);\n  }\n  rep(t, 500) {\n    bigint\
    \ a = gen(rng(1, 100));\n    bigint b = gen(rng(1, 100));\n    check(a, b);\n\
    \    if (a != 0) check(-a, b);\n    if (b != 0) check(a, -b);\n    if (a != 0\
    \ and b != 0) check(-a, -b);\n  }\n  rep(t, 500) {\n    bigint a = gen(rng(1,\
    \ 50));\n    bigint b = gen(rng(1, 50));\n    bigint c = gen(rng(1, 50));\n  \
    \  a *= c, b *= c;\n    check(a, b);\n    if (a != 0) check(-a, b);\n    if (b\
    \ != 0) check(a, -b);\n    if (a != 0 and b != 0) check(-a, -b);\n  }\n  reg(a,\
    \ 90, 110) reg(b, 90, 110) {\n    string s(a + 1, '0'), t(b + 1, '0');\n    s[0]\
    \ = t[0] = '1';\n    check(s, t);\n  }\n\n  cerr << \"OK\" << endl;\n\n  // \u5B9F\
    \u884C\u6642\u9593\u306E\u6BD4\u8F03\n  /**\n  for (int d = 1; d <= 256; d *=\
    \ 2) {\n    V<bigint> as, bs;\n    int T = 1000;\n    rep(i, T) {\n      as.push_back(gen(d));\n\
    \      bs.push_back(gen(d));\n    }\n\n    Timer timer;\n    bigint g1 = 0, g2\
    \ = 0, g3 = 0;\n\n    timer.reset();\n    rep(i, T) g1 += gcd_half(as[i], bs[i]);\n\
    \    ll t1 = timer.elapsed();\n\n    timer.reset();\n    rep(i, T) g2 += gcd_d_ary(as[i],\
    \ bs[i]);\n    ll t2 = timer.elapsed();\n\n    timer.reset();\n    rep(i, T) g3\
    \ += gcd_d_ary<true>(as[i], bs[i]);\n    ll t3 = timer.elapsed();\n\n    assert(g1\
    \ == g2 and g2 == g3);\n    trc2(d, t1, t2, t3);\n  }\n  //*/\n\n  {\n    int\
    \ a, b;\n    cin >> a >> b;\n    cout << a + b << \"\\n\";\n  }\n}\n\nvoid Nyaan::solve()\
    \ {\n  int t = 1;\n  // in(t);\n  while (t--) q();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../misc/rng.hpp\"\n#include\
    \ \"../../misc/timer.hpp\"\n//\n#include \"../../math/bigint-gcd.hpp\"\n//\n#include\
    \ \"../../math/bigint.hpp\"\n#include \"../../matrix/matrix.hpp\"\n\nnamespace\
    \ GCDforBigintImpl {\n\nusing Mat = Matrix<bigint>;\n\n// \u4E0B\u4F4D d \u6841\
    \u3092\u9664\u304F\nbigint suf(const bigint& n, int d) {\n  d = min(d, (int)n.dat.size());\n\
    \  return bigint{false, vector<int>{begin(n.dat) + d, end(n.dat)}};\n}\n\n// \u7E26\
    \u30D9\u30AF\u30C8\u30EB (p00, p10) \u3092\u4F5C\u308B\nMat make_vec(const bigint&\
    \ p00, const bigint& p10) {\n  Mat m(2, 1);\n  m[0][0] = p00, m[1][0] = p10;\n\
    \  return m;\n}\n\ntemplate <typename I>\nMat inner_naive(Mat& p) {\n  assert(p[0][0]\
    \ >= p[1][0]);\n  assert((int)p[0][0].dat.size() <= 4);\n  I g = 1;\n  // solve\
    \ : ax + by = gcd(a, b)\n  // return : pair(x, y)\n  auto extgcd = [&](auto rc,\
    \ I a, I b) -> pair<I, I> {\n    if (b == 0) {\n      g = a;\n      return make_pair(1,\
    \ 0);\n    }\n    I x, y;\n    tie(y, x) = rc(rc, b, a % b);\n    y -= a / b *\
    \ x;\n    return make_pair(x, y);\n  };\n  I a = p[0][0].to_i128(), b = p[1][0].to_i128(),\
    \ x, y;\n  tie(x, y) = extgcd(extgcd, a, b);\n  Mat m(2);\n  m[0][0] = x, m[0][1]\
    \ = y;\n  m[1][0] = b / g, m[1][1] = -a / g;\n  return m;\n}\n// p_0 >= p_1, 1\
    \ \u624B\u9032\u3081\u308B\nvoid inner_succ(Mat& m, Mat& p) {\n  assert(p[0][0]\
    \ >= p[1][0]);\n  if (p[1][0] == 0) return;\n  auto [quo, rem] = divmod(p[0][0],\
    \ p[1][0]);\n  m[0][0] -= m[1][0] * quo;\n  m[0][1] -= m[1][1] * quo;\n  swap(m[0][0],\
    \ m[1][0]), swap(m[0][1], m[1][1]);\n  p[0][0] = p[1][0], p[1][0] = rem;\n}\n\
    Mat inner_half_gcd(Mat p) {\n  assert(p[0][0] >= p[1][0]);\n  int n = p[0][0].dat.size(),\
    \ m = p[1][0].dat.size();\n  if (n <= 2) return inner_naive<long long>(p);\n \
    \ if (n <= 4) return inner_naive<__int128_t>(p);\n  int k = (n + 1) / 2;\n  if\
    \ (m <= k) return Mat::I(2);\n  Mat m1 = inner_half_gcd(make_vec(suf(p[0][0],\
    \ k), suf(p[1][0], k)));\n  p = m1 * p;\n  for (int i = 0; i < 2; i++) {\n   \
    \ if (p[i][0] < 0) {\n      m1[i][0] = -m1[i][0], m1[i][1] = -m1[i][1], p[i][0]\
    \ = -p[i][0];\n    }\n  }\n  if (p[0][0] < p[1][0]) {\n    swap(m1[0][0], m1[1][0]),\
    \ swap(m1[0][1], m1[1][1]);\n    swap(p[0][0], p[1][0]);\n  }\n  if ((int)p[1][0].dat.size()\
    \ <= k) return m1;\n  for (int i = 0; i < 20; i++) inner_succ(m1, p);\n  if ((int)p[1][0].dat.size()\
    \ <= k) return m1;\n  int j = (k + 1) / 2;\n  Mat m2 = inner_half_gcd(make_vec(suf(p[0][0],\
    \ j), suf(p[1][0], j)));\n  return m2 * m1;\n}\n\n__int128_t gcd_naive_i128(__int128_t\
    \ a, __int128_t b) {\n  assert(a >= 0 and b >= 0);\n  while (b) swap(a %= b, b);\n\
    \  return a;\n}\nbigint gcd_naive(bigint a, bigint b) {\n  a = abs(a), b = abs(b);\n\
    \  if (a < b) swap(a, b);\n  while (b != bigint{}) {\n    if ((int)a.dat.size()\
    \ <= 4) {\n      return gcd_naive_i128(a.to_i128(), b.to_i128());\n    }\n   \
    \ swap(a %= b, b);\n  }\n  return a;\n}\n\nbigint gcd_half(bigint a, bigint b)\
    \ {\n  a = abs(a), b = abs(b);\n  if (a < b) swap(a, b);\n  Mat p = make_vec(a,\
    \ b);\n  while (p[1][0] != 0) {\n    Mat m1 = inner_half_gcd(p);\n    p = m1 *\
    \ p;\n    p[0][0].neg = p[1][0].neg = false;\n    if (p[0][0] < p[1][0]) swap(p[0][0],\
    \ p[1][0]);\n    inner_succ(m1, p);\n  }\n  return p[0][0];\n}\n\n}  // namespace\
    \ GCDforBigintImpl\n\nusing GCDforBigintImpl::gcd_d_ary;\nusing GCDforBigintImpl::gcd_half;\n\
    using GCDforBigintImpl::gcd_naive;\n\nusing namespace Nyaan;\n\nvoid q() {\n \
    \ {\n    bigint a =\n        \"1234567900000000000000000000000000000000000000000000000000000000000\"\
    s;\n    bigint b =\n        \"111111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\"\
    s;\n    bigint g = gcd_half(a, b);\n    trc(a, b, g);\n  }\n  auto gen = [&](int\
    \ d) {\n    string S(d, '0');\n    each(c, S) c += rng(0, 9);\n    while (sz(S)\
    \ and S[0] == '0') S.erase(begin(S));\n    if (S.empty()) return bigint{};\n \
    \   return bigint{S};\n  };\n\n#ifdef PROFILER\n  {\n    for (int d = 1; d <=\
    \ 256; d *= 2) {\n      V<bigint> as, bs;\n      int T = 1000;\n      rep(i, T)\
    \ {\n        as.push_back(gen(d));\n        bs.push_back(gen(d));\n      }\n\n\
    \      Timer timer;\n      bigint g1 = 0, g2 = 0;\n\n      timer.reset();\n  \
    \    rep(i, T) g2 += gcd_d_ary(as[i], bs[i]);\n      ll t2 = timer.elapsed();\n\
    \n      trc2(d, t2);\n    }\n    exit(0);\n  }\n#endif\n\n  auto check = [&](bigint\
    \ a, bigint b) -> void {\n    bigint g1 = gcd_half(a, b);\n    bigint g2 = gcd_naive(a,\
    \ b);\n    bigint g3 = gcd_d_ary<false>(a, b);\n    bigint g4 = gcd_d_ary<true>(a,\
    \ b);\n    if (g1 != g2 or g2 != g3 or g3 != g4) {\n      trc2(a, b);\n      trc2(g1);\n\
    \      trc2(g2);\n      trc2(g3);\n      trc2(g4);\n      trc2(divmod(g3, g4));\n\
    \      exit(1);\n    }\n    if (g1 == 0) return;\n    auto [aq, ar] = divmod(a,\
    \ g1);\n    auto [bq, br] = divmod(b, g1);\n    assert(ar == 0 and br == 0);\n\
    \    assert(gcd_half(aq, bq) == 1);\n    assert(gcd_naive(aq, bq) == 1);\n   \
    \ assert(gcd_d_ary<false>(aq, bq) == 1);\n    assert(gcd_d_ary<true>(aq, bq) ==\
    \ 1);\n  };\n\n  rep(s, 100) rep(t, 100) {\n    bigint a = s;\n    bigint b =\
    \ t;\n    check(a, b);\n    if (a != 0) check(-a, b);\n    if (b != 0) check(a,\
    \ -b);\n    if (a != 0 and b != 0) check(-a, -b);\n  }\n  rep(t, 500) {\n    bigint\
    \ a = gen(rng(1, 100));\n    bigint b = gen(rng(1, 100));\n    check(a, b);\n\
    \    if (a != 0) check(-a, b);\n    if (b != 0) check(a, -b);\n    if (a != 0\
    \ and b != 0) check(-a, -b);\n  }\n  rep(t, 500) {\n    bigint a = gen(rng(1,\
    \ 50));\n    bigint b = gen(rng(1, 50));\n    bigint c = gen(rng(1, 50));\n  \
    \  a *= c, b *= c;\n    check(a, b);\n    if (a != 0) check(-a, b);\n    if (b\
    \ != 0) check(a, -b);\n    if (a != 0 and b != 0) check(-a, -b);\n  }\n  reg(a,\
    \ 90, 110) reg(b, 90, 110) {\n    string s(a + 1, '0'), t(b + 1, '0');\n    s[0]\
    \ = t[0] = '1';\n    check(s, t);\n  }\n\n  cerr << \"OK\" << endl;\n\n  // \u5B9F\
    \u884C\u6642\u9593\u306E\u6BD4\u8F03\n  /**\n  for (int d = 1; d <= 256; d *=\
    \ 2) {\n    V<bigint> as, bs;\n    int T = 1000;\n    rep(i, T) {\n      as.push_back(gen(d));\n\
    \      bs.push_back(gen(d));\n    }\n\n    Timer timer;\n    bigint g1 = 0, g2\
    \ = 0, g3 = 0;\n\n    timer.reset();\n    rep(i, T) g1 += gcd_half(as[i], bs[i]);\n\
    \    ll t1 = timer.elapsed();\n\n    timer.reset();\n    rep(i, T) g2 += gcd_d_ary(as[i],\
    \ bs[i]);\n    ll t2 = timer.elapsed();\n\n    timer.reset();\n    rep(i, T) g3\
    \ += gcd_d_ary<true>(as[i], bs[i]);\n    ll t3 = timer.elapsed();\n\n    assert(g1\
    \ == g2 and g2 == g3);\n    trc2(d, t1, t2, t3);\n  }\n  //*/\n\n  {\n    int\
    \ a, b;\n    cin >> a >> b;\n    cout << a + b << \"\\n\";\n  }\n}\n\nvoid Nyaan::solve()\
    \ {\n  int t = 1;\n  // in(t);\n  while (t--) q();\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - misc/rng.hpp
  - misc/timer.hpp
  - math/bigint-gcd.hpp
  - math-fast/gcd.hpp
  - math/bigint.hpp
  - ntt/arbitrary-ntt.hpp
  - modint/montgomery-modint.hpp
  - ntt/ntt.hpp
  - matrix/matrix.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/bigint-gcd.test.cpp
  requiredBy: []
  timestamp: '2023-04-15 00:09:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/bigint-gcd.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/bigint-gcd.test.cpp
- /verify/verify/verify-unit-test/bigint-gcd.test.cpp.html
title: verify/verify-unit-test/bigint-gcd.test.cpp
---