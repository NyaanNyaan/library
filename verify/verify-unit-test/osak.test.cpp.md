---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-math.hpp
    title: internal/internal-math.hpp
  - icon: ':heavy_check_mark:'
    path: internal/internal-seed.hpp
    title: internal/internal-seed.hpp
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: modint/arbitrary-montgomery-modint.hpp
    title: modint/arbitrary-montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: prime/factor-enumerate.hpp
    title: prime/factor-enumerate.hpp
  - icon: ':heavy_check_mark:'
    path: prime/fast-factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)"
  - icon: ':heavy_check_mark:'
    path: prime/miller-rabin.hpp
    title: Miller-Rabin primality test
  - icon: ':heavy_check_mark:'
    path: prime/osak.hpp
    title: prime/osak.hpp
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
  bundledCode: "#line 1 \"verify/verify-unit-test/osak.test.cpp\"\n#define PROBLEM\
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
    \ vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\ntemplate\
    \ <typename T>\nusing minpq = priority_queue<T, vector<T>, greater<T>>;\n\ntemplate\
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
    \ N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n  sort(begin(ord),\
    \ end(ord), f);\n  return ord;\n}\n\ntemplate <typename T>\nvector<int> mkinv(vector<T>\
    \ &v) {\n  int max_val = *max_element(begin(v), end(v));\n  vector<int> inv(max_val\
    \ + 1, -1);\n  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;\n  return\
    \ inv;\n}\n\nvector<int> mkiota(int n) {\n  vector<int> ret(n);\n  iota(begin(ret),\
    \ end(ret), 0);\n  return ret;\n}\n\ntemplate <typename T>\nT mkrev(const T &v)\
    \ {\n  T w{v};\n  reverse(begin(w), end(w));\n  return w;\n}\n\ntemplate <typename\
    \ T>\nbool nxp(vector<T> &v) {\n  return next_permutation(begin(v), end(v));\n\
    }\n\n// \u8FD4\u308A\u5024\u306E\u578B\u306F\u5165\u529B\u306E T \u306B\u4F9D\u5B58\
    \n// i \u8981\u7D20\u76EE : [0, a[i])\ntemplate <typename T>\nvector<vector<T>>\
    \ product(const vector<T> &a) {\n  vector<vector<T>> ret;\n  vector<T> v;\n  auto\
    \ dfs = [&](auto rc, int i) -> void {\n    if (i == (int)a.size()) {\n      ret.push_back(v);\n\
    \      return;\n    }\n    for (int j = 0; j < a[i]; j++) v.push_back(j), rc(rc,\
    \ i + 1), v.pop_back();\n  };\n  dfs(dfs, 0);\n  return ret;\n}\n\n// F : function(void(T&)),\
    \ mod \u3092\u53D6\u308B\u64CD\u4F5C\n// T : \u6574\u6570\u578B\u306E\u3068\u304D\
    \u306F\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306B\u6CE8\u610F\u3059\u308B\
    \ntemplate <typename T>\nT Power(T a, long long n, const T &I, const function<void(T\
    \ &)> &f) {\n  T res = I;\n  for (; n; f(a = a * a), n >>= 1) {\n    if (n & 1)\
    \ f(res = res * a);\n  }\n  return res;\n}\n// T : \u6574\u6570\u578B\u306E\u3068\
    \u304D\u306F\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306B\u6CE8\u610F\u3059\
    \u308B\ntemplate <typename T>\nT Power(T a, long long n, const T &I) {\n  return\
    \ Power(a, n, I, function<void(T &)>{[](T &) -> void {}});\n}\n\n}  // namespace\
    \ Nyaan\n#line 58 \"template/template.hpp\"\n\n// bit operation\n#line 1 \"template/bitop.hpp\"\
    \nnamespace Nyaan {\n__attribute__((target(\"popcnt\"))) inline int popcnt(const\
    \ u64 &a) {\n  return _mm_popcnt_u64(a);\n}\ninline int lsb(const u64 &a) { return\
    \ a ? __builtin_ctzll(a) : 64; }\ninline int ctz(const u64 &a) { return a ? __builtin_ctzll(a)\
    \ : 64; }\ninline int msb(const u64 &a) { return a ? 63 - __builtin_clzll(a) :\
    \ -1; }\ntemplate <typename T>\ninline int gbit(const T &a, int i) {\n  return\
    \ (a >> i) & 1;\n}\ntemplate <typename T>\ninline void sbit(T &a, int i, bool\
    \ b) {\n  if (gbit(a, i) != b) a ^= T(1) << i;\n}\nconstexpr long long PW(int\
    \ n) { return 1LL << n; }\nconstexpr long long MSK(int n) { return (1LL << n)\
    \ - 1; }\n}  // namespace Nyaan\n#line 61 \"template/template.hpp\"\n\n// inout\n\
    #line 1 \"template/inout.hpp\"\nnamespace Nyaan {\n\ntemplate <typename T, typename\
    \ U>\nostream &operator<<(ostream &os, const pair<T, U> &p) {\n  os << p.first\
    \ << \" \" << p.second;\n  return os;\n}\ntemplate <typename T, typename U>\n\
    istream &operator>>(istream &is, pair<T, U> &p) {\n  is >> p.first >> p.second;\n\
    \  return is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const\
    \ vector<T> &v) {\n  int s = (int)v.size();\n  for (int i = 0; i < s; i++) os\
    \ << (i ? \" \" : \"\") << v[i];\n  return os;\n}\ntemplate <typename T>\nistream\
    \ &operator>>(istream &is, vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return\
    \ is;\n}\n\nistream &operator>>(istream &is, __int128_t &x) {\n  string S;\n \
    \ is >> S;\n  x = 0;\n  int flag = 0;\n  for (auto &c : S) {\n    if (c == '-')\
    \ {\n      flag = true;\n      continue;\n    }\n    x *= 10;\n    x += c - '0';\n\
    \  }\n  if (flag) x = -x;\n  return is;\n}\n\nistream &operator>>(istream &is,\
    \ __uint128_t &x) {\n  string S;\n  is >> S;\n  x = 0;\n  for (auto &c : S) {\n\
    \    x *= 10;\n    x += c - '0';\n  }\n  return is;\n}\n\nostream &operator<<(ostream\
    \ &os, __int128_t x) {\n  if (x == 0) return os << 0;\n  if (x < 0) os << '-',\
    \ x = -x;\n  string S;\n  while (x) S.push_back('0' + x % 10), x /= 10;\n  reverse(begin(S),\
    \ end(S));\n  return os << S;\n}\nostream &operator<<(ostream &os, __uint128_t\
    \ x) {\n  if (x == 0) return os << 0;\n  string S;\n  while (x) S.push_back('0'\
    \ + x % 10), x /= 10;\n  reverse(begin(S), end(S));\n  return os << S;\n}\n\n\
    void in() {}\ntemplate <typename T, class... U>\nvoid in(T &t, U &...u) {\n  cin\
    \ >> t;\n  in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename\
    \ T, class... U, char sep = ' '>\nvoid out(const T &t, const U &...u) {\n  cout\
    \ << t;\n  if (sizeof...(u)) cout << sep;\n  out(u...);\n}\n\nstruct IoSetupNya\
    \ {\n  IoSetupNya() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(15);\n    cerr << fixed << setprecision(7);\n\
    \  }\n} iosetupnya;\n\n}  // namespace Nyaan\n#line 64 \"template/template.hpp\"\
    \n\n// debug\n#line 1 \"template/debug.hpp\"\nnamespace DebugImpl {\n\ntemplate\
    \ <typename U, typename = void>\nstruct is_specialize : false_type {};\ntemplate\
    \ <typename U>\nstruct is_specialize<\n    U, typename conditional<false, typename\
    \ U::iterator, void>::type>\n    : true_type {};\ntemplate <typename U>\nstruct\
    \ is_specialize<\n    U, typename conditional<false, decltype(U::first), void>::type>\n\
    \    : true_type {};\ntemplate <typename U>\nstruct is_specialize<U, enable_if_t<is_integral<U>::value,\
    \ void>> : true_type {\n};\n\nvoid dump(const char& t) { cerr << t; }\n\nvoid\
    \ dump(const string& t) { cerr << t; }\n\nvoid dump(const bool& t) { cerr << (t\
    \ ? \"true\" : \"false\"); }\n\nvoid dump(__int128_t t) {\n  if (t == 0) cerr\
    \ << 0;\n  if (t < 0) cerr << '-', t = -t;\n  string S;\n  while (t) S.push_back('0'\
    \ + t % 10), t /= 10;\n  reverse(begin(S), end(S));\n  cerr << S;\n}\n\nvoid dump(__uint128_t\
    \ t) {\n  if (t == 0) cerr << 0;\n  string S;\n  while (t) S.push_back('0' + t\
    \ % 10), t /= 10;\n  reverse(begin(S), end(S));\n  cerr << S;\n}\n\ntemplate <typename\
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
    \ 4 \"verify/verify-unit-test/osak.test.cpp\"\n//\n#line 2 \"prime/fast-factorize.hpp\"\
    \n\n#line 6 \"prime/fast-factorize.hpp\"\nusing namespace std;\n\n#line 2 \"internal/internal-math.hpp\"\
    \n\n#line 2 \"internal/internal-type-traits.hpp\"\n\n#line 4 \"internal/internal-type-traits.hpp\"\
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
    \                                   \\\n  template <class, class = void>     \
    \                          \\\n  struct has_##var : false_type {};           \
    \                 \\\n  template <class T>                                   \
    \        \\\n  struct has_##var<T, void_t<typename T::var>> : true_type {}; \\\
    \n  template <class T>                                           \\\n  constexpr\
    \ auto has_##var##_v = has_##var<T>::value;\n\n#define ENABLE_HAS_VAR(var)   \
    \                                  \\\n  template <class, class = void>      \
    \                          \\\n  struct has_##var : false_type {};           \
    \                  \\\n  template <class T>                                  \
    \          \\\n  struct has_##var<T, void_t<decltype(T::var)>> : true_type {};\
    \ \\\n  template <class T>                                            \\\n  constexpr\
    \ auto has_##var##_v = has_##var<T>::value;\n\n}  // namespace internal\n#line\
    \ 4 \"internal/internal-math.hpp\"\n\nnamespace internal {\n\n#line 10 \"internal/internal-math.hpp\"\
    \nusing namespace std;\n\n// a mod p\ntemplate <typename T>\nT safe_mod(T a, T\
    \ p) {\n  a %= p;\n  if constexpr (is_broadly_signed_v<T>) {\n    if (a < 0) a\
    \ += p;\n  }\n  return a;\n}\n\n// \u8FD4\u308A\u5024\uFF1Apair(g, x)\n// s.t.\
    \ g = gcd(a, b), xa = g (mod b), 0 <= x < b/g\ntemplate <typename T>\npair<T,\
    \ T> inv_gcd(T a, T p) {\n  static_assert(is_broadly_signed_v<T>);\n  a = safe_mod(a,\
    \ p);\n  if (a == 0) return {p, 0};\n  T b = p, x = 1, y = 0;\n  while (a != 0)\
    \ {\n    T q = b / a;\n    swap(a, b %= a);\n    swap(x, y -= q * x);\n  }\n \
    \ if (y < 0) y += p / b;\n  return {b, y};\n}\n\n// \u8FD4\u308A\u5024 : a^{-1}\
    \ mod p\n// gcd(a, p) != 1 \u304C\u5FC5\u8981\ntemplate <typename T>\nT inv(T\
    \ a, T p) {\n  static_assert(is_broadly_signed_v<T>);\n  a = safe_mod(a, p);\n\
    \  T b = p, x = 1, y = 0;\n  while (a != 0) {\n    T q = b / a;\n    swap(a, b\
    \ %= a);\n    swap(x, y -= q * x);\n  }\n  assert(b == 1);\n  return y < 0 ? y\
    \ + p : y;\n}\n\n// T : \u5E95\u306E\u578B\n// U : T*T \u304C\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044 \u304B\u3064 \u6307\u6570\u306E\u578B\
    \ntemplate <typename T, typename U>\nT modpow(T a, U n, T p) {\n  a = safe_mod(a,\
    \ p);\n  T ret = 1 % p;\n  while (n != 0) {\n    if (n % 2 == 1) ret = U(ret)\
    \ * a % p;\n    a = U(a) * a % p;\n    n /= 2;\n  }\n  return ret;\n}\n\n// \u8FD4\
    \u308A\u5024 : pair(rem, mod)\n// \u89E3\u306A\u3057\u306E\u3068\u304D\u306F {0,\
    \ 0} \u3092\u8FD4\u3059\ntemplate <typename T>\npair<T, T> crt(const vector<T>&\
    \ r, const vector<T>& m) {\n  static_assert(is_broadly_signed_v<T>);\n  assert(r.size()\
    \ == m.size());\n  int n = int(r.size());\n  T r0 = 0, m0 = 1;\n  for (int i =\
    \ 0; i < n; i++) {\n    assert(1 <= m[i]);\n    T r1 = safe_mod(r[i], m[i]), m1\
    \ = m[i];\n    if (m0 < m1) swap(r0, r1), swap(m0, m1);\n    if (m0 % m1 == 0)\
    \ {\n      if (r0 % m1 != r1) return {0, 0};\n      continue;\n    }\n    auto\
    \ [g, im] = inv_gcd(m0, m1);\n    T u1 = m1 / g;\n    if ((r1 - r0) % g) return\
    \ {0, 0};\n    T x = (r1 - r0) / g % u1 * im % u1;\n    r0 += x * m0;\n    m0\
    \ *= u1;\n    if (r0 < 0) r0 += m0;\n  }\n  return {r0, m0};\n}\n\n}  // namespace\
    \ internal\n#line 2 \"misc/rng.hpp\"\n\n#line 2 \"internal/internal-seed.hpp\"\
    \n\n#line 4 \"internal/internal-seed.hpp\"\nusing namespace std;\n\nnamespace\
    \ internal {\nunsigned long long non_deterministic_seed() {\n  unsigned long long\
    \ m =\n      chrono::duration_cast<chrono::nanoseconds>(\n          chrono::high_resolution_clock::now().time_since_epoch())\n\
    \          .count();\n  m ^= 9845834732710364265uLL;\n  m ^= m << 24, m ^= m >>\
    \ 31, m ^= m << 35;\n  return m;\n}\nunsigned long long deterministic_seed() {\
    \ return 88172645463325252UL; }\n\n// 64 bit \u306E seed \u5024\u3092\u751F\u6210\
    \ (\u624B\u5143\u3067\u306F seed \u56FA\u5B9A)\n// \u9023\u7D9A\u3067\u547C\u3073\
    \u51FA\u3059\u3068\u540C\u3058\u5024\u304C\u4F55\u5EA6\u3082\u8FD4\u3063\u3066\
    \u304F\u308B\u306E\u3067\u6CE8\u610F\n// #define RANDOMIZED_SEED \u3059\u308B\u3068\
    \u30B7\u30FC\u30C9\u304C\u30E9\u30F3\u30C0\u30E0\u306B\u306A\u308B\nunsigned long\
    \ long seed() {\n#if defined(NyaanLocal) && !defined(RANDOMIZED_SEED)\n  return\
    \ deterministic_seed();\n#else\n  return non_deterministic_seed();\n#endif\n}\n\
    \n}  // namespace internal\n#line 4 \"misc/rng.hpp\"\n\nnamespace my_rand {\n\
    using i64 = long long;\nusing u64 = unsigned long long;\n\n// [0, 2^64 - 1)\n\
    u64 rng() {\n  static u64 _x = internal::seed();\n  return _x ^= _x << 7, _x ^=\
    \ _x >> 9;\n}\n\n// [l, r]\ni64 rng(i64 l, i64 r) {\n  assert(l <= r);\n  return\
    \ l + rng() % u64(r - l + 1);\n}\n\n// [l, r)\ni64 randint(i64 l, i64 r) {\n \
    \ assert(l < r);\n  return l + rng() % u64(r - l);\n}\n\n// choose n numbers from\
    \ [l, r) without overlapping\nvector<i64> randset(i64 l, i64 r, i64 n) {\n  assert(l\
    \ <= r && n <= r - l);\n  unordered_set<i64> s;\n  for (i64 i = n; i; --i) {\n\
    \    i64 m = randint(l, r + 1 - i);\n    if (s.find(m) != s.end()) m = r - i;\n\
    \    s.insert(m);\n  }\n  vector<i64> ret;\n  for (auto& x : s) ret.push_back(x);\n\
    \  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() { return rng() * 5.42101086242752217004e-20;\
    \ }\n// [l, r)\ndouble rnd(double l, double r) {\n  assert(l < r);\n  return l\
    \ + rnd() * (r - l);\n}\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n\
    \  int n = v.size();\n  for (int i = 1; i < n; i++) swap(v[i], v[randint(0, i\
    \ + 1)]);\n}\n\n}  // namespace my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\n\
    using my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n#line 2 \"\
    modint/arbitrary-montgomery-modint.hpp\"\n\n#line 4 \"modint/arbitrary-montgomery-modint.hpp\"\
    \nusing namespace std;\n\ntemplate <typename Int, typename UInt, typename Long,\
    \ typename ULong, int id>\nstruct ArbitraryLazyMontgomeryModIntBase {\n  using\
    \ mint = ArbitraryLazyMontgomeryModIntBase;\n\n  inline static UInt mod;\n  inline\
    \ static UInt r;\n  inline static UInt n2;\n  static constexpr int bit_length\
    \ = sizeof(UInt) * 8;\n\n  static UInt get_r() {\n    UInt ret = mod;\n    while\
    \ (mod * ret != 1) ret *= UInt(2) - mod * ret;\n    return ret;\n  }\n  static\
    \ void set_mod(UInt m) {\n    assert(m < (UInt(1u) << (bit_length - 2)));\n  \
    \  assert((m & 1) == 1);\n    mod = m, n2 = -ULong(m) % m, r = get_r();\n  }\n\
    \  UInt a;\n\n  ArbitraryLazyMontgomeryModIntBase() : a(0) {}\n  ArbitraryLazyMontgomeryModIntBase(const\
    \ Long &b)\n      : a(reduce(ULong(b % mod + mod) * n2)){};\n\n  static UInt reduce(const\
    \ ULong &b) {\n    return (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;\n\
    \  }\n\n  mint &operator+=(const mint &b) {\n    if (Int(a += b.a - 2 * mod) <\
    \ 0) a += 2 * mod;\n    return *this;\n  }\n  mint &operator-=(const mint &b)\
    \ {\n    if (Int(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n  mint\
    \ &operator*=(const mint &b) {\n    a = reduce(ULong(a) * b.a);\n    return *this;\n\
    \  }\n  mint &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return\
    \ *this;\n  }\n\n  mint operator+(const mint &b) const { return mint(*this) +=\
    \ b; }\n  mint operator-(const mint &b) const { return mint(*this) -= b; }\n \
    \ mint operator*(const mint &b) const { return mint(*this) *= b; }\n  mint operator/(const\
    \ mint &b) const { return mint(*this) /= b; }\n\n  bool operator==(const mint\
    \ &b) const {\n    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod\
    \ : b.a);\n  }\n  bool operator!=(const mint &b) const {\n    return (a >= mod\
    \ ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);\n  }\n  mint operator-() const\
    \ { return mint(0) - mint(*this); }\n  mint operator+() const { return mint(*this);\
    \ }\n\n  mint pow(ULong n) const {\n    mint ret(1), mul(*this);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul, n >>= 1;\n    }\n  \
    \  return ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const mint &b)\
    \ {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is,\
    \ mint &b) {\n    Long t;\n    is >> t;\n    b = ArbitraryLazyMontgomeryModIntBase(t);\n\
    \    return (is);\n  }\n\n  mint inverse() const {\n    Int x = get(), y = get_mod(),\
    \ u = 1, v = 0;\n    while (y > 0) {\n      Int t = x / y;\n      swap(x -= t\
    \ * y, y);\n      swap(u -= t * v, v);\n    }\n    return mint{u};\n  }\n\n  UInt\
    \ get() const {\n    UInt ret = reduce(a);\n    return ret >= mod ? ret - mod\
    \ : ret;\n  }\n\n  static UInt get_mod() { return mod; }\n};\n\n// id \u306B\u9069\
    \u5F53\u306A\u4E71\u6570\u3092\u5272\u308A\u5F53\u3066\u3066\u4F7F\u3046\ntemplate\
    \ <int id>\nusing ArbitraryLazyMontgomeryModInt =\n    ArbitraryLazyMontgomeryModIntBase<int,\
    \ unsigned int, long long,\n                                      unsigned long\
    \ long, id>;\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt64bit =\n\
    \    ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long, __int128_t,\n\
    \                                      __uint128_t, id>;\n#line 2 \"prime/miller-rabin.hpp\"\
    \n\n#line 4 \"prime/miller-rabin.hpp\"\nusing namespace std;\n\n#line 8 \"prime/miller-rabin.hpp\"\
    \n\nnamespace fast_factorize {\n\ntemplate <typename T, typename U>\nbool miller_rabin(const\
    \ T& n, vector<T> ws) {\n  if (n <= 2) return n == 2;\n  if (n % 2 == 0) return\
    \ false;\n\n  T d = n - 1;\n  while (d % 2 == 0) d /= 2;\n  U e = 1, rev = n -\
    \ 1;\n  for (T w : ws) {\n    if (w % n == 0) continue;\n    T t = d;\n    U y\
    \ = internal::modpow<T, U>(w, t, n);\n    while (t != n - 1 && y != e && y !=\
    \ rev) y = y * y % n, t *= 2;\n    if (y != rev && t % 2 == 0) return false;\n\
    \  }\n  return true;\n}\n\nbool miller_rabin_u64(unsigned long long n) {\n  return\
    \ miller_rabin<unsigned long long, __uint128_t>(\n      n, {2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022});\n}\n\ntemplate <typename mint>\nbool miller_rabin(unsigned\
    \ long long n, vector<unsigned long long> ws) {\n  if (n <= 2) return n == 2;\n\
    \  if (n % 2 == 0) return false;\n\n  if (mint::get_mod() != n) mint::set_mod(n);\n\
    \  unsigned long long d = n - 1;\n  while (~d & 1) d >>= 1;\n  mint e = 1, rev\
    \ = n - 1;\n  for (unsigned long long w : ws) {\n    if (w % n == 0) continue;\n\
    \    unsigned long long t = d;\n    mint y = mint(w).pow(t);\n    while (t !=\
    \ n - 1 && y != e && y != rev) y *= y, t *= 2;\n    if (y != rev && t % 2 == 0)\
    \ return false;\n  }\n  return true;\n}\n\nbool is_prime(unsigned long long n)\
    \ {\n  using mint32 = ArbitraryLazyMontgomeryModInt<96229631>;\n  using mint64\
    \ = ArbitraryLazyMontgomeryModInt64bit<622196072>;\n\n  if (n <= 2) return n ==\
    \ 2;\n  if (n % 2 == 0) return false;\n  if (n < (1uLL << 30)) {\n    return miller_rabin<mint32>(n,\
    \ {2, 7, 61});\n  } else if (n < (1uLL << 62)) {\n    return miller_rabin<mint64>(\n\
    \        n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\n  } else {\n\
    \    return miller_rabin_u64(n);\n  }\n}\n\n}  // namespace fast_factorize\n\n\
    using fast_factorize::is_prime;\n\n/**\n * @brief Miller-Rabin primality test\n\
    \ */\n#line 12 \"prime/fast-factorize.hpp\"\n\nnamespace fast_factorize {\nusing\
    \ u64 = uint64_t;\n\ntemplate <typename mint, typename T>\nT pollard_rho(T n)\
    \ {\n  if (~n & 1) return 2;\n  if (is_prime(n)) return n;\n  if (mint::get_mod()\
    \ != n) mint::set_mod(n);\n  mint R, one = 1;\n  auto f = [&](mint x) { return\
    \ x * x + R; };\n  auto rnd_ = [&]() { return rng() % (n - 2) + 2; };\n  while\
    \ (1) {\n    mint x, y, ys, q = one;\n    R = rnd_(), y = rnd_();\n    T g = 1;\n\
    \    constexpr int m = 128;\n    for (int r = 1; g == 1; r <<= 1) {\n      x =\
    \ y;\n      for (int i = 0; i < r; ++i) y = f(y);\n      for (int k = 0; g ==\
    \ 1 && k < r; k += m) {\n        ys = y;\n        for (int i = 0; i < m && i <\
    \ r - k; ++i) q *= x - (y = f(y));\n        g = gcd(q.get(), n);\n      }\n  \
    \  }\n    if (g == n) do\n        g = gcd((x - (ys = f(ys))).get(), n);\n    \
    \  while (g == 1);\n    if (g != n) return g;\n  }\n  exit(1);\n}\n\nusing i64\
    \ = long long;\n\nvector<i64> inner_factorize(u64 n) {\n  using mint32 = ArbitraryLazyMontgomeryModInt<452288976>;\n\
    \  using mint64 = ArbitraryLazyMontgomeryModInt64bit<401243123>;\n\n  if (n <=\
    \ 1) return {};\n  u64 p;\n  if (n <= (1LL << 30)) {\n    p = pollard_rho<mint32,\
    \ uint32_t>(n);\n  } else if (n <= (1LL << 62)) {\n    p = pollard_rho<mint64,\
    \ uint64_t>(n);\n  } else {\n    exit(1);\n  }\n  if (p == n) return {i64(p)};\n\
    \  auto l = inner_factorize(p);\n  auto r = inner_factorize(n / p);\n  copy(begin(r),\
    \ end(r), back_inserter(l));\n  return l;\n}\n\nvector<i64> factorize(u64 n) {\n\
    \  auto ret = inner_factorize(n);\n  sort(begin(ret), end(ret));\n  return ret;\n\
    }\n\nmap<i64, i64> factor_count(u64 n) {\n  map<i64, i64> mp;\n  for (auto &x\
    \ : factorize(n)) mp[x]++;\n  return mp;\n}\n\nvector<i64> divisors(u64 n) {\n\
    \  if (n == 0) return {};\n  vector<pair<i64, i64>> v;\n  for (auto &p : factorize(n))\
    \ {\n    if (v.empty() || v.back().first != p) {\n      v.emplace_back(p, 1);\n\
    \    } else {\n      v.back().second++;\n    }\n  }\n  vector<i64> ret;\n  auto\
    \ f = [&](auto rc, int i, i64 x) -> void {\n    if (i == (int)v.size()) {\n  \
    \    ret.push_back(x);\n      return;\n    }\n    rc(rc, i + 1, x);\n    for (int\
    \ j = 0; j < v[i].second; j++) rc(rc, i + 1, x *= v[i].first);\n  };\n  f(f, 0,\
    \ 1);\n  sort(begin(ret), end(ret));\n  return ret;\n}\n\n}  // namespace fast_factorize\n\
    \nusing fast_factorize::divisors;\nusing fast_factorize::factor_count;\nusing\
    \ fast_factorize::factorize;\n\n/**\n * @brief \u9AD8\u901F\u7D20\u56E0\u6570\u5206\
    \u89E3(Miller Rabin/Pollard's Rho)\n * @docs docs/prime/fast-factorize.md\n */\n\
    #line 2 \"prime/osak.hpp\"\n\n#line 2 \"prime/factor-enumerate.hpp\"\n\nvector<int>\
    \ factor_enumerate(int N) {\n  vector<int> lp(N + 1, 0);\n  if (N < 2) return\
    \ lp;\n  vector<int> pr{2, 3};\n  for (int i = 2; i <= N; i += 2) lp[i] = 2;\n\
    \  for (int i = 3; i <= N; i += 6) lp[i] = 3;\n  for (int i = 5, d = 4; i <= N;\
    \ i += d = 6 - d) {\n    if (lp[i] == 0) {\n      lp[i] = i;\n      pr.push_back(i);\n\
    \    }\n    for (int j = 2; j < (int)pr.size() && i * pr[j] <= N; ++j) {\n   \
    \   lp[i * pr[j]] = pr[j];\n      if (pr[j] == lp[i]) break;\n    }\n  }\n  return\
    \ lp;\n}\n#line 4 \"prime/osak.hpp\"\n\ntemplate <int MAX>\nvector<int> osak(int\
    \ n) {\n  static vector<int> f = factor_enumerate(MAX);\n  vector<int> ret;\n\
    \  while (f[n]) ret.push_back(f[n]), n /= f[n];\n  return ret;\n}\n\ntemplate\
    \ <int MAX>\nvector<pair<int, int>> osak_table(int n) {\n  static vector<int>\
    \ f = factor_enumerate(MAX);\n  vector<pair<int, int>> v;\n  for (; f[n]; n /=\
    \ f[n]) {\n    if (v.empty() || v.back().first != f[n]) {\n      v.emplace_back(f[n],\
    \ 1);\n    } else {\n      v.back().second++;\n    }\n  }\n  return v;\n}\n\n\
    template <int MAX>\nvector<int> osak_divisors(int n) {\n  if(n == 0) return {};\n\
    \  if(n == 1) return vector<int>(1, 1);\n  auto p = osak_table<MAX>(n);\n  vector<int>\
    \ ds;\n\n  auto dfs = [&](auto r, int i, int c) {\n    if (i == (int)p.size())\
    \ {\n      ds.push_back(c);\n      return;\n    }\n    for (int j = 0; j <= p[i].second;\
    \ j++) {\n      r(r, i + 1, c);\n      c *= p[i].first;\n    }\n  };\n\n  dfs(dfs,\
    \ 0, 1);\n  sort(begin(ds), end(ds));\n  return ds;\n}\n#line 7 \"verify/verify-unit-test/osak.test.cpp\"\
    \n\nunsigned long long rng2() {\n  static unsigned long long x_ =\n      chrono::duration_cast<chrono::nanoseconds>(\n\
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \  .count();\n  x_ = x_ ^ (x_ << 7);\n  return x_ = x_ ^ (x_ >> 9);\n}\n\nconstexpr\
    \ int MX = 10000000;\n\nusing namespace Nyaan;\nvoid Nyaan::solve() {\n  auto\
    \ end = [](auto x, auto y) {\n    out(x);\n    out(y);\n    exit(1);\n  };\n \
    \ rep(i, 100000) {\n    auto f1 = osak<MX>(i);\n    auto f2 = factorize(i);\n\
    \    if (f1.size() != f2.size()) end(f1, f2);\n    rep(i, sz(f1)) if (f1[i] !=\
    \ (int)f2[i]) end(f1, f2);\n\n    auto d1 = osak_divisors<MX>(i);\n    auto d2\
    \ = divisors(i);\n    if (d1.size() != d2.size()) end(d1, d2);\n    rep(i, sz(d1))\
    \ if (d1[i] != (int)d2[i]) end(d1, d2);\n  }\n\n  rep(_, 200000) {\n    int i\
    \ = rng2() & ((1 << 23) - 1);\n    auto f1 = osak<MX>(i);\n    auto f2 = factorize(i);\n\
    \    if (f1.size() != f2.size()) end(f1, f2);\n    rep(i, sz(f1)) if (f1[i] !=\
    \ (int)f2[i]) end(f1, f2);\n\n    auto d1 = osak_divisors<MX>(i);\n    auto d2\
    \ = divisors(i);\n    if (d1.size() != d2.size()) end(d1, d2);\n    rep(i, sz(d1))\
    \ if (d1[i] != (int)d2[i]) end(d1, d2);\n  }\n\n  int a, b;\n  cin >> a >> b;\n\
    \  cout << (a + b) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../prime/fast-factorize.hpp\"\
    \n#include \"../../prime/osak.hpp\"\n\nunsigned long long rng2() {\n  static unsigned\
    \ long long x_ =\n      chrono::duration_cast<chrono::nanoseconds>(\n        \
    \  chrono::high_resolution_clock::now().time_since_epoch())\n          .count();\n\
    \  x_ = x_ ^ (x_ << 7);\n  return x_ = x_ ^ (x_ >> 9);\n}\n\nconstexpr int MX\
    \ = 10000000;\n\nusing namespace Nyaan;\nvoid Nyaan::solve() {\n  auto end = [](auto\
    \ x, auto y) {\n    out(x);\n    out(y);\n    exit(1);\n  };\n  rep(i, 100000)\
    \ {\n    auto f1 = osak<MX>(i);\n    auto f2 = factorize(i);\n    if (f1.size()\
    \ != f2.size()) end(f1, f2);\n    rep(i, sz(f1)) if (f1[i] != (int)f2[i]) end(f1,\
    \ f2);\n\n    auto d1 = osak_divisors<MX>(i);\n    auto d2 = divisors(i);\n  \
    \  if (d1.size() != d2.size()) end(d1, d2);\n    rep(i, sz(d1)) if (d1[i] != (int)d2[i])\
    \ end(d1, d2);\n  }\n\n  rep(_, 200000) {\n    int i = rng2() & ((1 << 23) - 1);\n\
    \    auto f1 = osak<MX>(i);\n    auto f2 = factorize(i);\n    if (f1.size() !=\
    \ f2.size()) end(f1, f2);\n    rep(i, sz(f1)) if (f1[i] != (int)f2[i]) end(f1,\
    \ f2);\n\n    auto d1 = osak_divisors<MX>(i);\n    auto d2 = divisors(i);\n  \
    \  if (d1.size() != d2.size()) end(d1, d2);\n    rep(i, sz(d1)) if (d1[i] != (int)d2[i])\
    \ end(d1, d2);\n  }\n\n  int a, b;\n  cin >> a >> b;\n  cout << (a + b) << '\\\
    n';\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - prime/fast-factorize.hpp
  - internal/internal-math.hpp
  - internal/internal-type-traits.hpp
  - misc/rng.hpp
  - internal/internal-seed.hpp
  - modint/arbitrary-montgomery-modint.hpp
  - prime/miller-rabin.hpp
  - prime/osak.hpp
  - prime/factor-enumerate.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/osak.test.cpp
  requiredBy: []
  timestamp: '2024-03-04 16:48:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/osak.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/osak.test.cpp
- /verify/verify/verify-unit-test/osak.test.cpp.html
title: verify/verify-unit-test/osak.test.cpp
---
