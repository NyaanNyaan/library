---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-seed.hpp
    title: internal/internal-seed.hpp
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  - icon: ':heavy_check_mark:'
    path: math-fast/gcd.hpp
    title: binary GCD
  - icon: ':heavy_check_mark:'
    path: math/rational-binomial.hpp
    title: math/rational-binomial.hpp
  - icon: ':heavy_check_mark:'
    path: math/rational-fps.hpp
    title: math/rational-fps.hpp
  - icon: ':heavy_check_mark:'
    path: math/rational.hpp
    title: math/rational.hpp
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
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
  bundledCode: "#line 1 \"verify/verify-unit-test/rational-number.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"template/template.hpp\"\
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
    \ 4 \"verify/verify-unit-test/rational-number.test.cpp\"\n//\n#line 2 \"math/rational-binomial.hpp\"\
    \n\n#line 2 \"math/rational.hpp\"\n\n#line 6 \"math/rational.hpp\"\nusing namespace\
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
    \ 2 \"math-fast/gcd.hpp\"\n\n#line 4 \"math-fast/gcd.hpp\"\nusing namespace std;\n\
    \nnamespace BinaryGCDImpl {\nusing u64 = unsigned long long;\nusing i8 = char;\n\
    \nu64 binary_gcd(u64 a, u64 b) {\n  if (a == 0 || b == 0) return a + b;\n  i8\
    \ n = __builtin_ctzll(a);\n  i8 m = __builtin_ctzll(b);\n  a >>= n;\n  b >>= m;\n\
    \  n = min(n, m);\n  while (a != b) {\n    u64 d = a - b;\n    i8 s = __builtin_ctzll(d);\n\
    \    bool f = a > b;\n    b = f ? b : a;\n    a = (f ? d : -d) >> s;\n  }\n  return\
    \ a << n;\n}\n\nusing u128 = __uint128_t;\n// a > 0\nint ctz128(u128 a) {\n  u64\
    \ lo = a & u64(-1);\n  return lo ? __builtin_ctzll(lo) : 64 + __builtin_ctzll(a\
    \ >> 64);\n}\nu128 binary_gcd128(u128 a, u128 b) {\n  if (a == 0 || b == 0) return\
    \ a + b;\n  i8 n = ctz128(a);\n  i8 m = ctz128(b);\n  a >>= n;\n  b >>= m;\n \
    \ n = min(n, m);\n  while (a != b) {\n    u128 d = a - b;\n    i8 s = ctz128(d);\n\
    \    bool f = a > b;\n    b = f ? b : a;\n    a = (f ? d : -d) >> s;\n  }\n  return\
    \ a << n;\n}\n\n}  // namespace BinaryGCDImpl\n\nlong long binary_gcd(long long\
    \ a, long long b) {\n  return BinaryGCDImpl::binary_gcd(abs(a), abs(b));\n}\n\
    __int128_t binary_gcd128(__int128_t a, __int128_t b) {\n  if (a < 0) a = -a;\n\
    \  if (b < 0) b = -b;\n  return BinaryGCDImpl::binary_gcd128(a, b);\n}\n\n/**\n\
    \ * @brief binary GCD\n */\n#line 10 \"math/rational.hpp\"\n\n// T : \u5024, U\
    \ : \u6BD4\u8F03\u7528\ntemplate <typename T, typename U>\nstruct RationalBase\
    \ {\n  using R = RationalBase;\n  using Key = T;\n  T x, y;\n  RationalBase()\
    \ : x(0), y(1) {}\n  template <typename T1>\n  RationalBase(const T1& _x) : RationalBase<T,\
    \ U>(_x, T1{1}) {}\n  template <typename T1, typename T2>\n  RationalBase(const\
    \ pair<T1, T2>& _p)\n      : RationalBase<T, U>(_p.first, _p.second) {}\n  template\
    \ <typename T1, typename T2>\n  RationalBase(const T1& _x, const T2& _y) : x(_x),\
    \ y(_y) {\n    assert(y != 0);\n    if (y == -1) x = -x, y = -y;\n    if (y !=\
    \ 1) {\n      T g;\n      if constexpr (internal::is_broadly_integral_v<T>) {\n\
    \        if constexpr (sizeof(T) == 16) {\n          g = binary_gcd128(x, y);\n\
    \        } else {\n          g = binary_gcd(x, y);\n        }\n      } else {\n\
    \        g = gcd(x, y);\n      }\n      if (g != 0) x /= g, y /= g;\n      if\
    \ (y < 0) x = -x, y = -y;\n    }\n  }\n  // y = 0 \u306E\u4EE3\u5165\u3082\u8A8D\
    \u3081\u308B\n  static R raw(T _x, T _y) {\n    R r;\n    r.x = _x, r.y = _y;\n\
    \    return r;\n  }\n  friend R operator+(const R& l, const R& r) {\n    if (l.y\
    \ == r.y) return R{l.x + r.x, l.y};\n    return R{l.x * r.y + l.y * r.x, l.y *\
    \ r.y};\n  }\n  friend R operator-(const R& l, const R& r) {\n    if (l.y == r.y)\
    \ return R{l.x - r.x, l.y};\n    return R{l.x * r.y - l.y * r.x, l.y * r.y};\n\
    \  }\n  friend R operator*(const R& l, const R& r) { return R{l.x * r.x, l.y *\
    \ r.y}; }\n  friend R operator/(const R& l, const R& r) { return R{l.x * r.y,\
    \ l.y * r.x}; }\n  R& operator+=(const R& r) { return (*this) = (*this) + r; }\n\
    \  R& operator-=(const R& r) { return (*this) = (*this) - r; }\n  R& operator*=(const\
    \ R& r) { return (*this) = (*this) * r; }\n  R& operator/=(const R& r) { return\
    \ (*this) = (*this) / r; }\n  R operator-() const { return raw(-x, y); }\n  R\
    \ inverse() const {\n    assert(x != 0);\n    R r = raw(y, x);\n    if (r.y <\
    \ 0) r.x = -r.x, r.y = -r.y;\n    return r;\n  }\n  R pow(long long p) const {\n\
    \    R res{1}, base{*this};\n    while (p) {\n      if (p & 1) res *= base;\n\
    \      base *= base;\n      p >>= 1;\n    }\n    return res;\n  }\n  friend bool\
    \ operator==(const R& l, const R& r) {\n    return l.x == r.x && l.y == r.y;\n\
    \  };\n  friend bool operator!=(const R& l, const R& r) {\n    return l.x != r.x\
    \ || l.y != r.y;\n  };\n  friend bool operator<(const R& l, const R& r) {\n  \
    \  return U{l.x} * r.y < U{l.y} * r.x;\n  };\n  friend bool operator<=(const R&\
    \ l, const R& r) { return l < r || l == r; }\n  friend bool operator>(const R&\
    \ l, const R& r) {\n    return U{l.x} * r.y > U{l.y} * r.x;\n  };\n  friend bool\
    \ operator>=(const R& l, const R& r) { return l > r || l == r; }\n  friend ostream&\
    \ operator<<(ostream& os, const R& r) {\n    os << r.x;\n    if (r.x != 0 && r.y\
    \ != 1) os << \"/\" << r.y;\n    return os;\n  }\n\n  // T \u306B\u30AD\u30E3\u30B9\
    \u30C8\u3055\u308C\u308B\u306E\u3067 T \u304C bigint \u306E\u5834\u5408\u306F\
    \ to_ll \u3082\u8981\u308B\n  T to_mint(T mod) const {\n    assert(mod != 0);\n\
    \    T a = y, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n\
    \      swap(a -= t * b, b);\n      swap(u -= t * v, v);\n    }\n    return U((u\
    \ % mod + mod) % mod) * x % mod;\n  }\n};\n\nusing Rational = RationalBase<long\
    \ long, __int128_t>;\n#line 4 \"math/rational-binomial.hpp\"\n\ntemplate <typename\
    \ R = Rational>\nstruct Binomial_rational {\n  vector<R> fc;\n  Binomial_rational(int\
    \ = 0) { fc.emplace_back(1); }\n  void extend() {\n    int n = fc.size();\n  \
    \  R nxt = fc.back() * n;\n    fc.push_back(nxt);\n  }\n  R fac(int n) {\n   \
    \ if (n < 0) return 0;\n    while ((int)fc.size() <= n) extend();\n    return\
    \ fc[n];\n  }\n  R finv(int n) {\n    if (n < 0) return 0;\n    return fac(n).inverse();\n\
    \  }\n  R inv(int n) {\n    if (n < 0) return -inv(-n);\n    return R{1, max(n,\
    \ 1)};\n  }\n  R C(int n, int r) {\n    if (n < 0 or r < 0 or n < r) return R{0};\n\
    \    return fac(n) * finv(n - r) * finv(r);\n  }\n  R operator()(int n, int r)\
    \ { return C(n, r); }\n  template <typename I>\n  R multinomial(const vector<I>&\
    \ r) {\n    static_assert(is_integral<I>::value == true);\n    int n = 0;\n  \
    \  for (auto& x : r) {\n      if (x < 0) return R{0};\n      n += x;\n    }\n\
    \    R res = fac(n);\n    for (auto& x : r) res *= finv(x);\n    return res;\n\
    \  }\n\n  template <typename I>\n  R operator()(const vector<I>& r) {\n    return\
    \ multinomial(r);\n  }\n  \n  R P(int n, int r) {\n    if (n < 0 || n < r || r\
    \ < 0) return R(0);\n    return fac(n) * finv(n - r);\n  }\n  // [x^r] 1 / (1-x)^n\n\
    \  R H(int n, int r) {\n    if (n < 0 || r < 0) return R(0);\n    return r ==\
    \ 0 ? 1 : C(n + r - 1, r);\n  }\n};\n#line 2 \"math/rational-fps.hpp\"\n\n#line\
    \ 5 \"math/rational-fps.hpp\"\n\ntemplate <typename R = Rational>\nstruct FormalPowerSeries_rational\
    \ : vector<R> {\n  using vector<R>::vector;\n  using fps = FormalPowerSeries_rational;\n\
    \n  fps &operator+=(const fps &r) {\n    if (r.size() > this->size()) this->resize(r.size());\n\
    \    for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
    \  }\n\n  fps &operator+=(const R &r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] += r;\n    return *this;\n  }\n\n  fps &operator-=(const fps &r)\
    \ {\n    if (r.size() > this->size()) this->resize(r.size());\n    for (int i\
    \ = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n    return *this;\n  }\n\n\
    \  fps &operator-=(const R &r) {\n    if (this->empty()) this->resize(1);\n  \
    \  (*this)[0] -= r;\n    return *this;\n  }\n\n  fps &operator*=(const fps &r)\
    \ {\n    int n = this->size() + r.size() - 1;\n    fps f(n);\n    for (int i =\
    \ 0; i < (int)this->size(); i++) {\n      for (int j = 0; j < (int)r.size(); j++)\
    \ {\n        f[i + j] += (*this)[i] * r[j];\n      }\n    }\n    return *this\
    \ = f;\n  }\n\n  fps &operator*=(const R &v) {\n    for (int k = 0; k < (int)this->size();\
    \ k++) (*this)[k] *= v;\n    return *this;\n  }\n\n  fps &operator/=(const fps\
    \ &r) {\n    if (this->size() < r.size()) {\n      this->clear();\n      return\
    \ *this;\n    }\n    int n = this->size() - r.size() + 1;\n    fps f(*this), g(r);\n\
    \    g.shrink();\n    R coeff = g.back().inverse();\n    for (auto &x : g) x *=\
    \ coeff;\n    int deg = (int)f.size() - (int)g.size() + 1;\n    int gs = g.size();\n\
    \    fps quo(deg);\n    for (int i = deg - 1; i >= 0; i--) {\n      quo[i] = f[i\
    \ + gs - 1];\n      for (int j = 0; j < gs; j++) f[i + j] -= quo[i] * g[j];\n\
    \    }\n    *this = quo * coeff;\n    this->resize(n, R(0));\n    return *this;\n\
    \  }\n\n  fps &operator%=(const fps &r) {\n    *this -= *this / r * r;\n    shrink();\n\
    \    return *this;\n  }\n\n  fps operator+(const fps &r) const { return fps(*this)\
    \ += r; }\n  fps operator+(const R &v) const { return fps(*this) += v; }\n  fps\
    \ operator-(const fps &r) const { return fps(*this) -= r; }\n  fps operator-(const\
    \ R &v) const { return fps(*this) -= v; }\n  fps operator*(const fps &r) const\
    \ { return fps(*this) *= r; }\n  fps operator*(const R &v) const { return fps(*this)\
    \ *= v; }\n  fps operator/(const fps &r) const { return fps(*this) /= r; }\n \
    \ fps operator%(const fps &r) const { return fps(*this) %= r; }\n  fps operator-()\
    \ const {\n    fps ret(this->size());\n    for (int i = 0; i < (int)this->size();\
    \ i++) ret[i] = -(*this)[i];\n    return ret;\n  }\n\n  void shrink() {\n    while\
    \ (this->size() && this->back() == R(0)) this->pop_back();\n  }\n\n  fps rev()\
    \ const {\n    fps ret(*this);\n    reverse(begin(ret), end(ret));\n    return\
    \ ret;\n  }\n\n  fps dot(fps r) const {\n    fps ret(min(this->size(), r.size()));\n\
    \    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i] * r[i];\n \
    \   return ret;\n  }\n\n  // \u524D sz \u9805\u3092\u53D6\u3063\u3066\u304F\u308B\
    \u3002sz \u306B\u8DB3\u308A\u306A\u3044\u9805\u306F 0 \u57CB\u3081\u3059\u308B\
    \n  fps pre(int sz) const {\n    fps ret(begin(*this), begin(*this) + min((int)this->size(),\
    \ sz));\n    if ((int)ret.size() < sz) ret.resize(sz);\n    return ret;\n  }\n\
    \n  fps operator>>(int sz) const {\n    if ((int)this->size() <= sz) return {};\n\
    \    fps ret(*this);\n    ret.erase(ret.begin(), ret.begin() + sz);\n    return\
    \ ret;\n  }\n\n  fps operator<<(int sz) const {\n    fps ret(*this);\n    ret.insert(ret.begin(),\
    \ sz, R(0));\n    return ret;\n  }\n\n  fps diff() const {\n    const int n =\
    \ (int)this->size();\n    fps ret(max(0, n - 1));\n    R one(1), coeff(1);\n \
    \   for (int i = 1; i < n; i++) {\n      ret[i - 1] = (*this)[i] * coeff;\n  \
    \    coeff += one;\n    }\n    return ret;\n  }\n\n  fps integral() const {\n\
    \    const int n = (int)this->size();\n    fps ret(n + 1);\n    for (int i = 0;\
    \ i < n; i++) ret[i + 1] = (*this)[i] / (i + 1);\n    return ret;\n  }\n\n  R\
    \ eval(R x) const {\n    R r = 0, w = 1;\n    for (auto &v : *this) r += w * v,\
    \ w *= x;\n    return r;\n  }\n\n  fps inv(int deg = -1) const {\n    assert((*this)[0]\
    \ != R(0));\n    if (deg == -1) deg = (*this).size();\n    fps ret{R(1) / (*this)[0]};\n\
    \    for (int i = 1; i < deg; i <<= 1) {\n      ret = (ret + ret - ret * ret *\
    \ (*this).pre(i << 1)).pre(i << 1);\n    }\n    return ret.pre(deg);\n  }\n  fps\
    \ log(int deg = -1) const {\n    assert(!(*this).empty() && (*this)[0] == R(1));\n\
    \    if (deg == -1) deg = (int)this->size();\n    return (this->diff() * this->inv(deg)).pre(deg\
    \ - 1).integral();\n  }\n  fps exp(int deg = -1) const {\n    assert((*this).size()\
    \ == 0 || (*this)[0] == R(0));\n    if (deg == -1) deg = (int)this->size();\n\
    \    fps ret{R(1)};\n    for (int i = 1; i < deg; i <<= 1) {\n      ret = (ret\
    \ * (pre(i << 1) + R(1) - ret.log(i << 1))).pre(i << 1);\n    }\n    return ret.pre(deg);\n\
    \  }\n  fps pow(int64_t k, int deg = -1) const {\n    const int n = (int)this->size();\n\
    \    if (deg == -1) deg = n;\n    if (k == 0) {\n      fps ret(deg);\n      if\
    \ (deg) ret[0] = 1;\n      return ret;\n    }\n    for (int i = 0; i < n; i++)\
    \ {\n      if ((*this)[i] != R(0)) {\n        R rev = R(1) / (*this)[i];\n   \
    \     fps ret = (((*this * rev) >> i).log(deg) * k).exp(deg);\n        ret *=\
    \ (*this)[i].pow(k);\n        ret = (ret << (i * k)).pre(deg);\n        if ((int)ret.size()\
    \ < deg) ret.resize(deg, R(0));\n        return ret;\n      }\n      if (__int128_t(i\
    \ + 1) * k >= deg) return fps(deg, R(0));\n    }\n    return fps(deg, R(0));\n\
    \  }\n};\n#line 8 \"verify/verify-unit-test/rational-number.test.cpp\"\n//\n#line\
    \ 2 \"modint/montgomery-modint.hpp\"\n\ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt\
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
    \ { return mod; }\n};\n#line 2 \"modulo/binomial.hpp\"\n\n#line 6 \"modulo/binomial.hpp\"\
    \nusing namespace std;\n\n// \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306E\
    \ MAX \u306B \u300CC(n, r) \u3084 fac(n) \u3067\u30AF\u30A8\u30EA\u3092\u6295\u3052\
    \u308B\u6700\u5927\u306E n \u300D\n// \u3092\u5165\u308C\u308B\u3068\u500D\u901F\
    \u304F\u3089\u3044\u306B\u306A\u308B\n// mod \u3092\u8D85\u3048\u3066\u524D\u8A08\
    \u7B97\u3057\u3066 0 \u5272\u308A\u3092\u8E0F\u3080\u30D0\u30B0\u306F\u5BFE\u7B56\
    \u6E08\u307F\ntemplate <typename T>\nstruct Binomial {\n  vector<T> f, g, h;\n\
    \  Binomial(int MAX = 0) {\n    assert(T::get_mod() != 0 && \"Binomial<mint>()\"\
    );\n    f.resize(1, T{1});\n    g.resize(1, T{1});\n    h.resize(1, T{1});\n \
    \   if (MAX > 0) extend(MAX + 1);\n  }\n\n  void extend(int m = -1) {\n    int\
    \ n = f.size();\n    if (m == -1) m = n * 2;\n    m = min<int>(m, T::get_mod());\n\
    \    if (n >= m) return;\n    f.resize(m);\n    g.resize(m);\n    h.resize(m);\n\
    \    for (int i = n; i < m; i++) f[i] = f[i - 1] * T(i);\n    g[m - 1] = f[m -\
    \ 1].inverse();\n    h[m - 1] = g[m - 1] * f[m - 2];\n    for (int i = m - 2;\
    \ i >= n; i--) {\n      g[i] = g[i + 1] * T(i + 1);\n      h[i] = g[i] * f[i -\
    \ 1];\n    }\n  }\n\n  T fac(int i) {\n    if (i < 0) return T(0);\n    while\
    \ (i >= (int)f.size()) extend();\n    return f[i];\n  }\n\n  T finv(int i) {\n\
    \    if (i < 0) return T(0);\n    while (i >= (int)g.size()) extend();\n    return\
    \ g[i];\n  }\n\n  T inv(int i) {\n    if (i < 0) return -inv(-i);\n    while (i\
    \ >= (int)h.size()) extend();\n    return h[i];\n  }\n\n  T C(int n, int r) {\n\
    \    if (n < 0 || n < r || r < 0) return T(0);\n    return fac(n) * finv(n - r)\
    \ * finv(r);\n  }\n\n  inline T operator()(int n, int r) { return C(n, r); }\n\
    \n  template <typename I>\n  T multinomial(const vector<I>& r) {\n    static_assert(is_integral<I>::value\
    \ == true);\n    int n = 0;\n    for (auto& x : r) {\n      if (x < 0) return\
    \ T(0);\n      n += x;\n    }\n    T res = fac(n);\n    for (auto& x : r) res\
    \ *= finv(x);\n    return res;\n  }\n\n  template <typename I>\n  T operator()(const\
    \ vector<I>& r) {\n    return multinomial(r);\n  }\n\n  T C_naive(int n, int r)\
    \ {\n    if (n < 0 || n < r || r < 0) return T(0);\n    T ret = T(1);\n    r =\
    \ min(r, n - r);\n    for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);\n  \
    \  return ret;\n  }\n\n  T P(int n, int r) {\n    if (n < 0 || n < r || r < 0)\
    \ return T(0);\n    return fac(n) * finv(n - r);\n  }\n\n  // [x^r] 1 / (1-x)^n\n\
    \  T H(int n, int r) {\n    if (n < 0 || r < 0) return T(0);\n    return r ==\
    \ 0 ? 1 : C(n + r - 1, r);\n  }\n};\n#line 11 \"verify/verify-unit-test/rational-number.test.cpp\"\
    \nusing mint = LazyMontgomeryModInt<998244353>;\n//\n#line 2 \"misc/rng.hpp\"\n\
    \n#line 2 \"internal/internal-seed.hpp\"\n\n#line 4 \"internal/internal-seed.hpp\"\
    \nusing namespace std;\n\nnamespace internal {\nunsigned long long non_deterministic_seed()\
    \ {\n  unsigned long long m =\n      chrono::duration_cast<chrono::nanoseconds>(\n\
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \  .count();\n  m ^= 9845834732710364265uLL;\n  m ^= m << 24, m ^= m >> 31, m\
    \ ^= m << 35;\n  return m;\n}\nunsigned long long deterministic_seed() { return\
    \ 88172645463325252UL; }\n\n// 64 bit \u306E seed \u5024\u3092\u751F\u6210 (\u624B\
    \u5143\u3067\u306F seed \u56FA\u5B9A)\n// \u9023\u7D9A\u3067\u547C\u3073\u51FA\
    \u3059\u3068\u540C\u3058\u5024\u304C\u4F55\u5EA6\u3082\u8FD4\u3063\u3066\u304F\
    \u308B\u306E\u3067\u6CE8\u610F\n// #define RANDOMIZED_SEED \u3059\u308B\u3068\u30B7\
    \u30FC\u30C9\u304C\u30E9\u30F3\u30C0\u30E0\u306B\u306A\u308B\nunsigned long long\
    \ seed() {\n#if defined(NyaanLocal) && !defined(RANDOMIZED_SEED)\n  return deterministic_seed();\n\
    #else\n  return non_deterministic_seed();\n#endif\n}\n\n}  // namespace internal\n\
    #line 4 \"misc/rng.hpp\"\n\nnamespace my_rand {\nusing i64 = long long;\nusing\
    \ u64 = unsigned long long;\n\n// [0, 2^64 - 1)\nu64 rng() {\n  static u64 _x\
    \ = internal::seed();\n  return _x ^= _x << 7, _x ^= _x >> 9;\n}\n\n// [l, r]\n\
    i64 rng(i64 l, i64 r) {\n  assert(l <= r);\n  return l + rng() % u64(r - l + 1);\n\
    }\n\n// [l, r)\ni64 randint(i64 l, i64 r) {\n  assert(l < r);\n  return l + rng()\
    \ % u64(r - l);\n}\n\n// choose n numbers from [l, r) without overlapping\nvector<i64>\
    \ randset(i64 l, i64 r, i64 n) {\n  assert(l <= r && n <= r - l);\n  unordered_set<i64>\
    \ s;\n  for (i64 i = n; i; --i) {\n    i64 m = randint(l, r + 1 - i);\n    if\
    \ (s.find(m) != s.end()) m = r - i;\n    s.insert(m);\n  }\n  vector<i64> ret;\n\
    \  for (auto& x : s) ret.push_back(x);\n  sort(begin(ret), end(ret));\n  return\
    \ ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() { return rng() * 5.42101086242752217004e-20;\
    \ }\n// [l, r)\ndouble rnd(double l, double r) {\n  assert(l < r);\n  return l\
    \ + rnd() * (r - l);\n}\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n\
    \  int n = v.size();\n  for (int i = 1; i < n; i++) swap(v[i], v[randint(0, i\
    \ + 1)]);\n}\n\n}  // namespace my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\n\
    using my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n#line 14 \"\
    verify/verify-unit-test/rational-number.test.cpp\"\n\nusing namespace Nyaan;\n\
    \nvoid Nyaan::solve() {\n  {\n    Rational a{4, 3}, b{2, 3};\n    assert(a + b\
    \ == 2);\n    assert(a - b == Rational(2, 3));\n    assert(a * b == Rational(8,\
    \ 9));\n    assert(a / b == 2);\n    assert(a.inverse() == Rational(3, 4));\n\
    \    assert(a.pow(3) == Rational(64, 27));\n\n    assert((a > b) == true);\n \
    \   assert((a >= b) == true);\n    assert((a < b) == false);\n    assert((a <=\
    \ b) == false);\n  }\n\n  {\n    Binomial_rational<Rational> C;\n    assert(C.fac(3)\
    \ == 6);\n    assert(C.finv(3) == Rational(1, 6));\n    assert(C(4, 2) == 6);\n\
    \    assert(C(vi{3, 2}) == 10);\n  }\n\n  {\n    using fps = FormalPowerSeries_rational<Rational>;\n\
    \n    {\n      fps f{1, 2, {3, 2}}, g{{1, 4}, 5};\n      fps h{{5, 4}, 7, {3,\
    \ 2}};\n      assert(f + g == h);\n      h = fps{{3, 4}, -3, {3, 2}};\n      assert(f\
    \ - g == h);\n      assert(f * g % g == fps{});\n      assert(f * g % f == fps{});\n\
    \    }\n\n    {\n      fps e{1, 1, {1, 2}, {1, 6}, {1, 24}, {1, 120}};\n     \
    \ fps f = e.pow(10);\n      trc(f);\n      rep(i, sz(e)) { assert(e[i] * Rational{10}.pow(i)\
    \ == f[i]); }\n    }\n  }\n\n  // mint \u3068\u6319\u52D5\u306E\u6BD4\u8F03\n\
    \  {\n    auto comp = [&](int i, int j, int k, int l) {\n      rep(b, 16) {\n\
    \        int ii = (b >> 0) % 2 ? -i : +i;\n        int jj = (b >> 1) % 2 ? -j\
    \ : +j;\n        int kk = (b >> 2) % 2 ? -k : +k;\n        int ll = (b >> 3) %\
    \ 2 ? -l : +l;\n        Rational x{ii, jj}, y{kk, ll};\n        mint X = mint{ii}\
    \ / jj;\n        mint Y = mint{kk} / ll;\n        assert(X + Y == (x + y).to_mint(998244353));\n\
    \        assert(X - Y == (x - y).to_mint(998244353));\n        assert(X * Y ==\
    \ (x * y).to_mint(998244353));\n        if (Y != 0) {\n          assert(X / Y\
    \ == (x / y).to_mint(998244353));\n        }\n      }\n    };\n    rep(i, 20)\
    \ rep1(j, 20) rep(k, 20) rep1(l, 20) comp(i, j, k, l);\n    rep(t, 10000) {\n\
    \      int lower = t % 2 ? 1 : 32000;\n      ll i = rng(lower, 35000);\n     \
    \ ll j = rng(lower, 35000);\n      ll k = rng(lower, 35000);\n      ll l = rng(lower,\
    \ 35000);\n      comp(i, j, k, l);\n    }\n  }\n\n  // binom, mint \u3068\u6319\
    \u52D5\u306E\u6BD4\u8F03\n  {\n    Binomial_rational<Rational> C1;\n    Binomial<mint>\
    \ C2;\n    reg(i, -15, 15) {\n      assert(C2.fac(i) == C1.fac(i).to_mint(998244353));\n\
    \      assert(C2.finv(i) == C1.finv(i).to_mint(998244353));\n      assert(C2.inv(i)\
    \ == C1.inv(i).to_mint(998244353));\n      reg(j, -15, 15) {\n        assert(C2(i,\
    \ j) == C1(i, j).to_mint(998244353));\n        assert(C2.P(i, j) == C1.P(i, j).to_mint(998244353));\n\
    \        if (i + j < 20) assert(C2.H(i, j) == C1.H(i, j).to_mint(998244353));\n\
    \      }\n    }\n  }\n\n  cerr << \"OK\" << endl;\n  {\n    int s, t;\n    cin\
    \ >> s >> t;\n    cout << s + t << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../template/template.hpp\"\n//\n#include \"../../math/rational-binomial.hpp\"\
    \n#include \"../../math/rational-fps.hpp\"\n#include \"../../math/rational.hpp\"\
    \n//\n#include \"../../modint/montgomery-modint.hpp\"\n#include \"../../modulo/binomial.hpp\"\
    \nusing mint = LazyMontgomeryModInt<998244353>;\n//\n#include \"../../misc/rng.hpp\"\
    \n\nusing namespace Nyaan;\n\nvoid Nyaan::solve() {\n  {\n    Rational a{4, 3},\
    \ b{2, 3};\n    assert(a + b == 2);\n    assert(a - b == Rational(2, 3));\n  \
    \  assert(a * b == Rational(8, 9));\n    assert(a / b == 2);\n    assert(a.inverse()\
    \ == Rational(3, 4));\n    assert(a.pow(3) == Rational(64, 27));\n\n    assert((a\
    \ > b) == true);\n    assert((a >= b) == true);\n    assert((a < b) == false);\n\
    \    assert((a <= b) == false);\n  }\n\n  {\n    Binomial_rational<Rational> C;\n\
    \    assert(C.fac(3) == 6);\n    assert(C.finv(3) == Rational(1, 6));\n    assert(C(4,\
    \ 2) == 6);\n    assert(C(vi{3, 2}) == 10);\n  }\n\n  {\n    using fps = FormalPowerSeries_rational<Rational>;\n\
    \n    {\n      fps f{1, 2, {3, 2}}, g{{1, 4}, 5};\n      fps h{{5, 4}, 7, {3,\
    \ 2}};\n      assert(f + g == h);\n      h = fps{{3, 4}, -3, {3, 2}};\n      assert(f\
    \ - g == h);\n      assert(f * g % g == fps{});\n      assert(f * g % f == fps{});\n\
    \    }\n\n    {\n      fps e{1, 1, {1, 2}, {1, 6}, {1, 24}, {1, 120}};\n     \
    \ fps f = e.pow(10);\n      trc(f);\n      rep(i, sz(e)) { assert(e[i] * Rational{10}.pow(i)\
    \ == f[i]); }\n    }\n  }\n\n  // mint \u3068\u6319\u52D5\u306E\u6BD4\u8F03\n\
    \  {\n    auto comp = [&](int i, int j, int k, int l) {\n      rep(b, 16) {\n\
    \        int ii = (b >> 0) % 2 ? -i : +i;\n        int jj = (b >> 1) % 2 ? -j\
    \ : +j;\n        int kk = (b >> 2) % 2 ? -k : +k;\n        int ll = (b >> 3) %\
    \ 2 ? -l : +l;\n        Rational x{ii, jj}, y{kk, ll};\n        mint X = mint{ii}\
    \ / jj;\n        mint Y = mint{kk} / ll;\n        assert(X + Y == (x + y).to_mint(998244353));\n\
    \        assert(X - Y == (x - y).to_mint(998244353));\n        assert(X * Y ==\
    \ (x * y).to_mint(998244353));\n        if (Y != 0) {\n          assert(X / Y\
    \ == (x / y).to_mint(998244353));\n        }\n      }\n    };\n    rep(i, 20)\
    \ rep1(j, 20) rep(k, 20) rep1(l, 20) comp(i, j, k, l);\n    rep(t, 10000) {\n\
    \      int lower = t % 2 ? 1 : 32000;\n      ll i = rng(lower, 35000);\n     \
    \ ll j = rng(lower, 35000);\n      ll k = rng(lower, 35000);\n      ll l = rng(lower,\
    \ 35000);\n      comp(i, j, k, l);\n    }\n  }\n\n  // binom, mint \u3068\u6319\
    \u52D5\u306E\u6BD4\u8F03\n  {\n    Binomial_rational<Rational> C1;\n    Binomial<mint>\
    \ C2;\n    reg(i, -15, 15) {\n      assert(C2.fac(i) == C1.fac(i).to_mint(998244353));\n\
    \      assert(C2.finv(i) == C1.finv(i).to_mint(998244353));\n      assert(C2.inv(i)\
    \ == C1.inv(i).to_mint(998244353));\n      reg(j, -15, 15) {\n        assert(C2(i,\
    \ j) == C1(i, j).to_mint(998244353));\n        assert(C2.P(i, j) == C1.P(i, j).to_mint(998244353));\n\
    \        if (i + j < 20) assert(C2.H(i, j) == C1.H(i, j).to_mint(998244353));\n\
    \      }\n    }\n  }\n\n  cerr << \"OK\" << endl;\n  {\n    int s, t;\n    cin\
    \ >> s >> t;\n    cout << s + t << \"\\n\";\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - math/rational-binomial.hpp
  - math/rational.hpp
  - internal/internal-type-traits.hpp
  - math-fast/gcd.hpp
  - math/rational-fps.hpp
  - modint/montgomery-modint.hpp
  - modulo/binomial.hpp
  - misc/rng.hpp
  - internal/internal-seed.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/rational-number.test.cpp
  requiredBy: []
  timestamp: '2024-04-28 09:13:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/rational-number.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/rational-number.test.cpp
- /verify/verify/verify-unit-test/rational-number.test.cpp.html
title: verify/verify-unit-test/rational-number.test.cpp
---