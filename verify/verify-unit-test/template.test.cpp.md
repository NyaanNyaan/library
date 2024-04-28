---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-seed.hpp
    title: internal/internal-seed.hpp
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
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
  bundledCode: "#line 1 \"verify/verify-unit-test/template.test.cpp\"\n#define PROBLEM\
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
    \ 4 \"verify/verify-unit-test/template.test.cpp\"\n//\n#line 2 \"modint/montgomery-modint.hpp\"\
    \n\ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n\
    \  using i32 = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n\
    \  static constexpr u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i <\
    \ 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n  static constexpr u32\
    \ r = get_r();\n  static constexpr u32 n2 = -u64(mod) % mod;\n  static_assert(mod\
    \ < (1 << 30), \"invalid, mod >= 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"\
    invalid, mod % 2 == 0\");\n  static_assert(r * mod == 1, \"this code has bugs.\"\
    );\n\n  u32 a;\n\n  constexpr LazyMontgomeryModInt() : a(0) {}\n  constexpr LazyMontgomeryModInt(const\
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
    \ { return mod; }\n};\n#line 6 \"verify/verify-unit-test/template.test.cpp\"\n\
    //\n#line 2 \"misc/rng.hpp\"\n\n#line 2 \"internal/internal-seed.hpp\"\n\n#line\
    \ 4 \"internal/internal-seed.hpp\"\nusing namespace std;\n\nnamespace internal\
    \ {\nunsigned long long non_deterministic_seed() {\n  unsigned long long m =\n\
    \      chrono::duration_cast<chrono::nanoseconds>(\n          chrono::high_resolution_clock::now().time_since_epoch())\n\
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
    \  sort(begin(ret), end(ret));\n  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd()\
    \ { return rng() * 5.42101086242752217004e-20; }\n// [l, r)\ndouble rnd(double\
    \ l, double r) {\n  assert(l < r);\n  return l + rnd() * (r - l);\n}\n\ntemplate\
    \ <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n  for (int\
    \ i = 1; i < n; i++) swap(v[i], v[randint(0, i + 1)]);\n}\n\n}  // namespace my_rand\n\
    \nusing my_rand::randint;\nusing my_rand::randset;\nusing my_rand::randshf;\n\
    using my_rand::rnd;\nusing my_rand::rng;\n#line 8 \"verify/verify-unit-test/template.test.cpp\"\
    \n//\nusing namespace Nyaan;\n\n// bitop.hpp\n\nvoid verify_bitop() {\n  // popcnt\n\
    \  assert(popcnt(7) == 3);\n  assert(popcnt(0) == 0);\n  assert(popcnt(1LL <<\
    \ 40) == 1);\n  rep(loop, 100) {\n    u64 x = rng();\n    int pc = popcnt(x);\n\
    \    rep(i, 64) if ((x >> i) & 1) pc--;\n    assert(pc == 0 && \"popcnt\");\n\
    \  }\n\n  // lsb\n  assert(lsb(0) == 64);\n  assert(lsb(1) == 0);\n  assert(lsb(1LL\
    \ << 40) == 40);\n  assert(lsb(100) == 2);\n\n  // ctz\n  assert(ctz(0) == 64);\n\
    \  assert(ctz(1) == 0);\n  assert(ctz(1LL << 40) == 40);\n  assert(ctz(100) ==\
    \ 2);\n\n  rep(loop, 100) {\n    u64 x = rng();\n    int n = lsb(x);\n    assert(ctz(x)\
    \ == n);\n    while (n--) {\n      assert((x & 1) == 0 && \"lsb\");\n      x >>=\
    \ 1;\n    }\n    assert((x & 1) == 1 && \"lsb\");\n  }\n\n  // msb\n  assert(msb(0)\
    \ == -1);\n  assert(msb(1) == 0);\n  assert(msb(1LL << 40) == 40);\n  assert(msb(100)\
    \ == 6);\n\n  rep(loop, 100) {\n    u64 x = rng();\n    int m = msb(x);\n    if\
    \ (m != -1) {\n      assert(((x >> m) & 1) == 1 && \"msb\");\n    }\n    for (int\
    \ i = m + 1; i < 64; i++) {\n      assert(((x >> i) & 1) == 0 && \"msb\");\n \
    \   }\n  }\n\n  // gbit, sbit\n  // sbit\u306F\u73FE\u5728\u30D0\u30B0\u308A\u4E2D\
    \n  assert(gbit(5, 0) == 1);\n  assert(gbit(5, 1) == 0);\n  assert(gbit(5, 2)\
    \ == 1);\n  assert(gbit(1LL << 40, 40) == 1);\n\n  rep(loop, 100) {\n    u64 x\
    \ = rng();\n    for (int i = 0; i < 64; i++) {\n      u64 g = gbit(x, i);\n  \
    \    assert(((x >> i) & 1) == g && \"gbit\");\n      sbit(x, i, 1);\n      assert(((x\
    \ >> i) & 1) == 1u && \"sbit\");\n      sbit(x, i, 0);\n      assert(((x >> i)\
    \ & 1) == 0u && \"sbit\");\n      sbit(x, i, g);\n      assert(((x >> i) & 1)\
    \ == g && \"sbit\");\n    }\n  }\n\n  // PW,MSK\n  rep(i, 63) {\n    assert(1LL\
    \ << i == PW(i));\n    assert(1LL << i == MSK(i) + 1);\n  }\n}\n\nvoid verify_util()\
    \ {\n  // P, mkp\n  {\n    pl x(3, 2);\n    pl y(2, 3);\n    assert(x + y == pl(5,\
    \ 5));\n    assert(x - y == pl(1, -1));\n    assert(x * y == pl(6, 6));\n    x\
    \ += y;\n    assert(x == pl(5, 5));\n    x -= y;\n    assert(x == pl(3, 2));\n\
    \    x *= y;\n    assert(x == pl(6, 6));\n    x *= -3;\n    assert(x == pl(-18,\
    \ -18));\n\n    // mkp\n    auto p0 = mkp(1, 1);\n    static_assert(is_same<decltype(p0),\
    \ pair<int, int>>::value);\n    auto p1 = mkp(1LL, double(2.0));\n    static_assert(is_same<decltype(p1),\
    \ pair<long long, double>>::value);\n    assert(p0.first == 1 && p0.second ==\
    \ 1);\n    assert(p1.first == 1LL && p1.second == 2.0);\n  }\n\n  // P, modint\n\
    \  {\n    using mint = LazyMontgomeryModInt<998244353>;\n    using pm = P<mint,\
    \ mint>;\n    pm x(3, 2);\n    pm y(2, 3);\n    assert(x + y == pm(5, 5));\n \
    \   assert(x - y == pm(1, -1));\n    assert(x * y == pm(6, 6));\n    x += y;\n\
    \    assert(x == pm(5, 5));\n    x -= y;\n    assert(x == pm(3, 2));\n    x *=\
    \ y;\n    assert(x == pm(6, 6));\n    x *= -3;\n    assert(x == pm(-18, -18));\n\
    \    x *= mint{-3}.inverse();\n    assert(x == pm(6, 6));\n  }\n\n  // amin, amax\n\
    \  {\n    int x = 5;\n    amin(x, 4);\n    assert(x == 4);\n    amax(x, 5);\n\
    \    assert(x == 5);\n  }\n\n  // sz, Max, Min, Sum, mkrui, lb, ub, mkuni\n  {\n\
    \    // sz, Max, Min, Sum\n    vector<int> v;\n    for (int i = 0; i < 100; i++)\
    \ {\n      assert(sz(v) == i);\n      v.push_back(randint(0, 10));\n      assert(Max(v)\
    \ == *max_element(all(v)));\n      assert(Min(v) == *min_element(all(v)));\n \
    \     assert(Sum(v) == accumulate(all(v), 0LL));\n    }\n\n    // mkrui\n    auto\
    \ rui = mkrui(v);\n    int buf = 0;\n    assert(rui[0] == 0);\n    rep(i, sz(v))\
    \ {\n      buf += v[i];\n      assert(rui[i + 1] == buf);\n    }\n    rui = mkrui(v,\
    \ true);\n    buf = 0;\n    assert(rui.back() == 0);\n    repr(i, sz(v)) {\n \
    \     buf += v[i];\n      assert(rui[i] == buf);\n    }\n\n    // lb, ub\n   \
    \ sort(all(v));\n    for (int i = 0; i < sz(v); i++) {\n      if (i != 0 and v[i\
    \ - 1] == v[i]) continue;\n      int x = v[i];\n      assert(lb(v, x) == i);\n\
    \      assert(ub(v, x - 1) == i);\n    }\n    for (int x = 0; x < 10; x++) {\n\
    \      int l = lb(v, x);\n      int u = ub(v, x);\n      for (int i = 0; i < sz(v);\
    \ i++) {\n        assert((l <= i) == (x <= v[i]) && \"lb\");\n        assert((u\
    \ <= i) == (x < v[i]) && \"ub\");\n      }\n    }\n\n    // mkuni\n    set<int>\
    \ s1, s2;\n    for (int i : v) s1.insert(i);\n    v = mkuni(v);\n    for (int\
    \ i : v) s2.insert(i);\n    assert(s1 == s2);\n  }\n\n  // TEN\n  for (long long\
    \ i = 0, x = 1; i <= 18; i++, x *= 10) {\n    assert(TEN(i) == x);\n  }\n\n  //\
    \ mkord, mkinv(100\u500B, 1~1000)\n  {\n    vector<int> v;\n    rep(loop, 100)\
    \ { v.push_back(loop); }\n    auto ord = mkord(sz(v), [&v](int i, int j) { return\
    \ v[i] < v[j]; });\n    rep(i, sz(ord) - 1) { assert(v[ord[i]] <= v[ord[i + 1]]\
    \ && \"mkord\"); }\n\n    randshf(v);\n    auto inv = mkinv(v);\n    assert(inv.size()\
    \ == 100 && \"mkinv\");\n    set<int> st;\n    each(x, v) st.insert(x);\n    rep(i,\
    \ sz(inv)) {\n      if (inv[i] == -1) {\n        assert(st.find(i) == st.end()\
    \ && \"mkinv\");\n      } else {\n        assert(0 <= inv[i] && inv[i] < sz(v)\
    \ && \"mkinv\");\n        assert(v[inv[i]] == i && \"mkinv\");\n      }\n    }\n\
    \  }\n\n  // mkord, mkinv(100\u500B, 1~1000)\n  {\n    vector<int> v;\n    rep(loop,\
    \ 100) { v.push_back(randint(0, 1000)); }\n    auto ord = mkord(sz(v), [&v](int\
    \ i, int j) { return v[i] < v[j]; });\n    rep(i, sz(ord) - 1) { assert(v[ord[i]]\
    \ <= v[ord[i + 1]] && \"mkord\"); }\n\n    v = mkuni(v);\n    randshf(v);\n  \
    \  auto inv = mkinv(v);\n    assert(sz(inv) == Max(v) + 1 && \"mkinv\");\n   \
    \ set<int> st;\n    each(x, v) st.insert(x);\n    rep(i, sz(inv)) {\n      if\
    \ (inv[i] == -1) {\n        assert(st.find(i) == st.end() && \"mkinv\");\n   \
    \   } else {\n        assert(0 <= inv[i] && inv[i] < sz(v) && \"mkinv\");\n  \
    \      assert(v[inv[i]] == i);\n      }\n    }\n  }\n\n  // mkiota\n  {\n    for\
    \ (int n = 0; n < 100; n++) {\n      auto v = mkiota(n);\n      rep(i, n) assert(v[i]\
    \ == i && \"mkiota\");\n    }\n  }\n\n  // mkrev\n  {\n    for (int n = 0; n <\
    \ 100; n++) {\n      vi v(n);\n      each(x, v) x = randint(0, TEN(9));\n    \
    \  vi w{v};\n      reverse(all(w));\n      assert(mkrev(v) == w && \"mkrev\");\n\
    \    }\n\n    for (int n = 0; n < 100; n++) {\n      string s;\n      rep(t, n)\
    \ s.push_back(rng() % 26 + 'a');\n      string t{s};\n      reverse(all(t));\n\
    \      assert(mkrev(s) == t && \"mkrev\");\n    }\n  }\n\n  // nxp\n  {\n    for\
    \ (int n = 0; n <= 6; n++) {\n      vvi v, w;\n      vi o = mkiota(n);\n     \
    \ do {\n        v.push_back(o);\n      } while (nxp(o));\n      o = mkiota(n);\n\
    \      do {\n        w.push_back(o);\n      } while (next_permutation(all(o)));\n\
    \      assert(v == w && \"nxp\");\n    }\n  }\n\n  // product\n  {\n    auto v\
    \ = product(vector{2LL, 3LL});\n    assert(sz(v) == 6);\n    rep(i, sz(v)) {\n\
    \      assert(sz(v[i]) == 2);\n      assert(v[i][0] == i / 3);\n      assert(v[i][1]\
    \ == i % 3);\n    }\n  }\n\n  // Power\n  {\n    using mint = LazyMontgomeryModInt<998244353>;\n\
    \    for (ll x = 1; x <= 100; x++) {\n      i128 y = 1;\n      for (ll e = 0;\
    \ e <= 64; e++) {\n        ll z1 = Power<ll>(x, e, 1);\n        ll z2 = Power<ll>(x,\
    \ e, 1, [](ll& a) { a %= 998244353; });\n        mint z3 = Power<mint>(x, e, 1);\n\
    \        assert(z1 == y);\n        assert(z2 == y % 998244353);\n        assert(z3.get()\
    \ == z2);\n        y *= x;\n        if (y >= 8 * TEN(18)) break;\n      }\n  \
    \  }\n  }\n}\n\nvoid Nyaan::solve() {\n  verify_bitop();\n  verify_util();\n\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../modint/montgomery-modint.hpp\"\
    \n//\n#include \"../../misc/rng.hpp\"\n//\nusing namespace Nyaan;\n\n// bitop.hpp\n\
    \nvoid verify_bitop() {\n  // popcnt\n  assert(popcnt(7) == 3);\n  assert(popcnt(0)\
    \ == 0);\n  assert(popcnt(1LL << 40) == 1);\n  rep(loop, 100) {\n    u64 x = rng();\n\
    \    int pc = popcnt(x);\n    rep(i, 64) if ((x >> i) & 1) pc--;\n    assert(pc\
    \ == 0 && \"popcnt\");\n  }\n\n  // lsb\n  assert(lsb(0) == 64);\n  assert(lsb(1)\
    \ == 0);\n  assert(lsb(1LL << 40) == 40);\n  assert(lsb(100) == 2);\n\n  // ctz\n\
    \  assert(ctz(0) == 64);\n  assert(ctz(1) == 0);\n  assert(ctz(1LL << 40) == 40);\n\
    \  assert(ctz(100) == 2);\n\n  rep(loop, 100) {\n    u64 x = rng();\n    int n\
    \ = lsb(x);\n    assert(ctz(x) == n);\n    while (n--) {\n      assert((x & 1)\
    \ == 0 && \"lsb\");\n      x >>= 1;\n    }\n    assert((x & 1) == 1 && \"lsb\"\
    );\n  }\n\n  // msb\n  assert(msb(0) == -1);\n  assert(msb(1) == 0);\n  assert(msb(1LL\
    \ << 40) == 40);\n  assert(msb(100) == 6);\n\n  rep(loop, 100) {\n    u64 x =\
    \ rng();\n    int m = msb(x);\n    if (m != -1) {\n      assert(((x >> m) & 1)\
    \ == 1 && \"msb\");\n    }\n    for (int i = m + 1; i < 64; i++) {\n      assert(((x\
    \ >> i) & 1) == 0 && \"msb\");\n    }\n  }\n\n  // gbit, sbit\n  // sbit\u306F\
    \u73FE\u5728\u30D0\u30B0\u308A\u4E2D\n  assert(gbit(5, 0) == 1);\n  assert(gbit(5,\
    \ 1) == 0);\n  assert(gbit(5, 2) == 1);\n  assert(gbit(1LL << 40, 40) == 1);\n\
    \n  rep(loop, 100) {\n    u64 x = rng();\n    for (int i = 0; i < 64; i++) {\n\
    \      u64 g = gbit(x, i);\n      assert(((x >> i) & 1) == g && \"gbit\");\n \
    \     sbit(x, i, 1);\n      assert(((x >> i) & 1) == 1u && \"sbit\");\n      sbit(x,\
    \ i, 0);\n      assert(((x >> i) & 1) == 0u && \"sbit\");\n      sbit(x, i, g);\n\
    \      assert(((x >> i) & 1) == g && \"sbit\");\n    }\n  }\n\n  // PW,MSK\n \
    \ rep(i, 63) {\n    assert(1LL << i == PW(i));\n    assert(1LL << i == MSK(i)\
    \ + 1);\n  }\n}\n\nvoid verify_util() {\n  // P, mkp\n  {\n    pl x(3, 2);\n \
    \   pl y(2, 3);\n    assert(x + y == pl(5, 5));\n    assert(x - y == pl(1, -1));\n\
    \    assert(x * y == pl(6, 6));\n    x += y;\n    assert(x == pl(5, 5));\n   \
    \ x -= y;\n    assert(x == pl(3, 2));\n    x *= y;\n    assert(x == pl(6, 6));\n\
    \    x *= -3;\n    assert(x == pl(-18, -18));\n\n    // mkp\n    auto p0 = mkp(1,\
    \ 1);\n    static_assert(is_same<decltype(p0), pair<int, int>>::value);\n    auto\
    \ p1 = mkp(1LL, double(2.0));\n    static_assert(is_same<decltype(p1), pair<long\
    \ long, double>>::value);\n    assert(p0.first == 1 && p0.second == 1);\n    assert(p1.first\
    \ == 1LL && p1.second == 2.0);\n  }\n\n  // P, modint\n  {\n    using mint = LazyMontgomeryModInt<998244353>;\n\
    \    using pm = P<mint, mint>;\n    pm x(3, 2);\n    pm y(2, 3);\n    assert(x\
    \ + y == pm(5, 5));\n    assert(x - y == pm(1, -1));\n    assert(x * y == pm(6,\
    \ 6));\n    x += y;\n    assert(x == pm(5, 5));\n    x -= y;\n    assert(x ==\
    \ pm(3, 2));\n    x *= y;\n    assert(x == pm(6, 6));\n    x *= -3;\n    assert(x\
    \ == pm(-18, -18));\n    x *= mint{-3}.inverse();\n    assert(x == pm(6, 6));\n\
    \  }\n\n  // amin, amax\n  {\n    int x = 5;\n    amin(x, 4);\n    assert(x ==\
    \ 4);\n    amax(x, 5);\n    assert(x == 5);\n  }\n\n  // sz, Max, Min, Sum, mkrui,\
    \ lb, ub, mkuni\n  {\n    // sz, Max, Min, Sum\n    vector<int> v;\n    for (int\
    \ i = 0; i < 100; i++) {\n      assert(sz(v) == i);\n      v.push_back(randint(0,\
    \ 10));\n      assert(Max(v) == *max_element(all(v)));\n      assert(Min(v) ==\
    \ *min_element(all(v)));\n      assert(Sum(v) == accumulate(all(v), 0LL));\n \
    \   }\n\n    // mkrui\n    auto rui = mkrui(v);\n    int buf = 0;\n    assert(rui[0]\
    \ == 0);\n    rep(i, sz(v)) {\n      buf += v[i];\n      assert(rui[i + 1] ==\
    \ buf);\n    }\n    rui = mkrui(v, true);\n    buf = 0;\n    assert(rui.back()\
    \ == 0);\n    repr(i, sz(v)) {\n      buf += v[i];\n      assert(rui[i] == buf);\n\
    \    }\n\n    // lb, ub\n    sort(all(v));\n    for (int i = 0; i < sz(v); i++)\
    \ {\n      if (i != 0 and v[i - 1] == v[i]) continue;\n      int x = v[i];\n \
    \     assert(lb(v, x) == i);\n      assert(ub(v, x - 1) == i);\n    }\n    for\
    \ (int x = 0; x < 10; x++) {\n      int l = lb(v, x);\n      int u = ub(v, x);\n\
    \      for (int i = 0; i < sz(v); i++) {\n        assert((l <= i) == (x <= v[i])\
    \ && \"lb\");\n        assert((u <= i) == (x < v[i]) && \"ub\");\n      }\n  \
    \  }\n\n    // mkuni\n    set<int> s1, s2;\n    for (int i : v) s1.insert(i);\n\
    \    v = mkuni(v);\n    for (int i : v) s2.insert(i);\n    assert(s1 == s2);\n\
    \  }\n\n  // TEN\n  for (long long i = 0, x = 1; i <= 18; i++, x *= 10) {\n  \
    \  assert(TEN(i) == x);\n  }\n\n  // mkord, mkinv(100\u500B, 1~1000)\n  {\n  \
    \  vector<int> v;\n    rep(loop, 100) { v.push_back(loop); }\n    auto ord = mkord(sz(v),\
    \ [&v](int i, int j) { return v[i] < v[j]; });\n    rep(i, sz(ord) - 1) { assert(v[ord[i]]\
    \ <= v[ord[i + 1]] && \"mkord\"); }\n\n    randshf(v);\n    auto inv = mkinv(v);\n\
    \    assert(inv.size() == 100 && \"mkinv\");\n    set<int> st;\n    each(x, v)\
    \ st.insert(x);\n    rep(i, sz(inv)) {\n      if (inv[i] == -1) {\n        assert(st.find(i)\
    \ == st.end() && \"mkinv\");\n      } else {\n        assert(0 <= inv[i] && inv[i]\
    \ < sz(v) && \"mkinv\");\n        assert(v[inv[i]] == i && \"mkinv\");\n     \
    \ }\n    }\n  }\n\n  // mkord, mkinv(100\u500B, 1~1000)\n  {\n    vector<int>\
    \ v;\n    rep(loop, 100) { v.push_back(randint(0, 1000)); }\n    auto ord = mkord(sz(v),\
    \ [&v](int i, int j) { return v[i] < v[j]; });\n    rep(i, sz(ord) - 1) { assert(v[ord[i]]\
    \ <= v[ord[i + 1]] && \"mkord\"); }\n\n    v = mkuni(v);\n    randshf(v);\n  \
    \  auto inv = mkinv(v);\n    assert(sz(inv) == Max(v) + 1 && \"mkinv\");\n   \
    \ set<int> st;\n    each(x, v) st.insert(x);\n    rep(i, sz(inv)) {\n      if\
    \ (inv[i] == -1) {\n        assert(st.find(i) == st.end() && \"mkinv\");\n   \
    \   } else {\n        assert(0 <= inv[i] && inv[i] < sz(v) && \"mkinv\");\n  \
    \      assert(v[inv[i]] == i);\n      }\n    }\n  }\n\n  // mkiota\n  {\n    for\
    \ (int n = 0; n < 100; n++) {\n      auto v = mkiota(n);\n      rep(i, n) assert(v[i]\
    \ == i && \"mkiota\");\n    }\n  }\n\n  // mkrev\n  {\n    for (int n = 0; n <\
    \ 100; n++) {\n      vi v(n);\n      each(x, v) x = randint(0, TEN(9));\n    \
    \  vi w{v};\n      reverse(all(w));\n      assert(mkrev(v) == w && \"mkrev\");\n\
    \    }\n\n    for (int n = 0; n < 100; n++) {\n      string s;\n      rep(t, n)\
    \ s.push_back(rng() % 26 + 'a');\n      string t{s};\n      reverse(all(t));\n\
    \      assert(mkrev(s) == t && \"mkrev\");\n    }\n  }\n\n  // nxp\n  {\n    for\
    \ (int n = 0; n <= 6; n++) {\n      vvi v, w;\n      vi o = mkiota(n);\n     \
    \ do {\n        v.push_back(o);\n      } while (nxp(o));\n      o = mkiota(n);\n\
    \      do {\n        w.push_back(o);\n      } while (next_permutation(all(o)));\n\
    \      assert(v == w && \"nxp\");\n    }\n  }\n\n  // product\n  {\n    auto v\
    \ = product(vector{2LL, 3LL});\n    assert(sz(v) == 6);\n    rep(i, sz(v)) {\n\
    \      assert(sz(v[i]) == 2);\n      assert(v[i][0] == i / 3);\n      assert(v[i][1]\
    \ == i % 3);\n    }\n  }\n\n  // Power\n  {\n    using mint = LazyMontgomeryModInt<998244353>;\n\
    \    for (ll x = 1; x <= 100; x++) {\n      i128 y = 1;\n      for (ll e = 0;\
    \ e <= 64; e++) {\n        ll z1 = Power<ll>(x, e, 1);\n        ll z2 = Power<ll>(x,\
    \ e, 1, [](ll& a) { a %= 998244353; });\n        mint z3 = Power<mint>(x, e, 1);\n\
    \        assert(z1 == y);\n        assert(z2 == y % 998244353);\n        assert(z3.get()\
    \ == z2);\n        y *= x;\n        if (y >= 8 * TEN(18)) break;\n      }\n  \
    \  }\n  }\n}\n\nvoid Nyaan::solve() {\n  verify_bitop();\n  verify_util();\n\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - modint/montgomery-modint.hpp
  - misc/rng.hpp
  - internal/internal-seed.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/template.test.cpp
  requiredBy: []
  timestamp: '2024-04-28 09:13:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/template.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/template.test.cpp
- /verify/verify/verify-unit-test/template.test.cpp.html
title: verify/verify-unit-test/template.test.cpp
---
