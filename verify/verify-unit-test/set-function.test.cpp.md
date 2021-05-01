---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: set-function/and-convolution.hpp
    title: AND Convoluion
  - icon: ':heavy_check_mark:'
    path: set-function/or-convolution.hpp
    title: OR Convoluion
  - icon: ':heavy_check_mark:'
    path: set-function/walsh-hadamard-transform.hpp
    title: Walsh Hadamard Transform
  - icon: ':heavy_check_mark:'
    path: set-function/xor-convolution.hpp
    title: XOR Convoluion
  - icon: ':heavy_check_mark:'
    path: set-function/zeta-mobius-transform.hpp
    title: Zeta Transform / Moebius Transform
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/set-function.test.cpp\"\n#define\
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
    \ vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\n\ntemplate\
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
    \ t.size();\n}\n\ntemplate <typename T, typename U>\ninline bool amin(T &x, U\
    \ y) {\n  return (y < x) ? (x = y, true) : false;\n}\ntemplate <typename T, typename\
    \ U>\ninline bool amax(T &x, U y) {\n  return (x < y) ? (x = y, true) : false;\n\
    }\n\ntemplate <typename T>\ninline T Max(const vector<T> &v) {\n  return *max_element(begin(v),\
    \ end(v));\n}\ntemplate <typename T>\ninline T Min(const vector<T> &v) {\n  return\
    \ *min_element(begin(v), end(v));\n}\ntemplate <typename T>\ninline long long\
    \ Sum(const vector<T> &v) {\n  return accumulate(begin(v), end(v), 0LL);\n}\n\n\
    template <typename T>\nint lb(const vector<T> &v, const T &a) {\n  return lower_bound(begin(v),\
    \ end(v), a) - begin(v);\n}\ntemplate <typename T>\nint ub(const vector<T> &v,\
    \ const T &a) {\n  return upper_bound(begin(v), end(v), a) - begin(v);\n}\n\n\
    constexpr long long TEN(int n) {\n  long long ret = 1, x = 10;\n  for (; n; x\
    \ *= x, n >>= 1) ret *= (n & 1 ? x : 1);\n  return ret;\n}\n\ntemplate <typename\
    \ T, typename U>\npair<T, U> mkp(const T &t, const U &u) {\n  return make_pair(t,\
    \ u);\n}\n\ntemplate <typename T>\nvector<T> mkrui(const vector<T> &v, bool rev\
    \ = false) {\n  vector<T> ret(v.size() + 1);\n  if (rev) {\n    for (int i = int(v.size())\
    \ - 1; i >= 0; i--) ret[i] = v[i] + ret[i + 1];\n  } else {\n    for (int i =\
    \ 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];\n  }\n  return ret;\n\
    };\n\ntemplate <typename T>\nvector<T> mkuni(const vector<T> &v) {\n  vector<T>\
    \ ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(), ret.end()),\
    \ ret.end());\n  return ret;\n}\n\ntemplate <typename F>\nvector<int> mkord(int\
    \ N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n  sort(begin(ord),\
    \ end(ord), f);\n  return ord;\n}\n\ntemplate <typename T>\nvector<int> mkinv(vector<T>\
    \ &v) {\n  int max_val = *max_element(begin(v), end(v));\n  vector<int> inv(max_val\
    \ + 1, -1);\n  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;\n  return\
    \ inv;\n}\n\n}  // namespace Nyaan\n#line 58 \"template/template.hpp\"\n\n// bit\
    \ operation\n#line 1 \"template/bitop.hpp\"\nnamespace Nyaan {\n__attribute__((target(\"\
    popcnt\"))) inline int popcnt(const u64 &a) {\n  return _mm_popcnt_u64(a);\n}\n\
    inline int lsb(const u64 &a) {\n  return a ? __builtin_ctzll(a) : 64;\n}\ninline\
    \ int ctz(const u64 &a) {\n  return a ? __builtin_ctzll(a) : 64;\n}\ninline int\
    \ msb(const u64 &a) {\n  return a ? 63 - __builtin_clzll(a) : -1;\n}\ntemplate\
    \ <typename T>\ninline int gbit(const T &a, int i) {\n  return (a >> i) & 1;\n\
    }\ntemplate <typename T>\ninline void sbit(T &a, int i, bool b) {\n  a ^= (gbit(a,\
    \ i) == b ? 0 : (T(b) << i));\n}\nconstexpr long long PW(int n) { return 1LL <<\
    \ n; }\nconstexpr long long MSK(int n) { return (1LL << n) - 1; }\n}  // namespace\
    \ Nyaan\n#line 61 \"template/template.hpp\"\n\n// inout\n#line 1 \"template/inout.hpp\"\
    \nnamespace Nyaan {\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n  os << p.first << \" \" << p.second;\n  return\
    \ os;\n}\ntemplate <typename T, typename U>\nistream &operator>>(istream &is,\
    \ pair<T, U> &p) {\n  is >> p.first >> p.second;\n  return is;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n  int\
    \ s = (int)v.size();\n  for (int i = 0; i < s; i++) os << (i ? \" \" : \"\") <<\
    \ v[i];\n  return os;\n}\ntemplate <typename T>\nistream &operator>>(istream &is,\
    \ vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return is;\n}\n\nvoid in()\
    \ {}\ntemplate <typename T, class... U>\nvoid in(T &t, U &... u) {\n  cin >> t;\n\
    \  in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename T, class...\
    \ U, char sep = ' '>\nvoid out(const T &t, const U &... u) {\n  cout << t;\n \
    \ if (sizeof...(u)) cout << sep;\n  out(u...);\n}\n\nvoid outr() {}\ntemplate\
    \ <typename T, class... U, char sep = ' '>\nvoid outr(const T &t, const U &...\
    \ u) {\n  cout << t;\n  outr(u...);\n}\n\nstruct IoSetupNya {\n  IoSetupNya()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(15);\n    cerr << fixed << setprecision(7);\n  }\n} iosetupnya;\n\
    \n}  // namespace Nyaan\n#line 64 \"template/template.hpp\"\n\n// debug\n#line\
    \ 1 \"template/debug.hpp\"\nnamespace DebugImpl {\n\ntemplate <typename U, typename\
    \ = void>\nstruct is_specialize : false_type {};\ntemplate <typename U>\nstruct\
    \ is_specialize<\n    U, typename conditional<false, typename U::iterator, void>::type>\n\
    \    : true_type {};\ntemplate <typename U>\nstruct is_specialize<\n    U, typename\
    \ conditional<false, decltype(U::first), void>::type>\n    : true_type {};\ntemplate\
    \ <typename U>\nstruct is_specialize<U, enable_if_t<is_integral<U>::value, void>>\
    \ : true_type {\n};\n\nvoid dump(const char& t) { cerr << t; }\n\nvoid dump(const\
    \ string& t) { cerr << t; }\n\nvoid dump(const bool& t) { cerr << (t ? \"true\"\
    \ : \"false\"); }\n\ntemplate <typename U,\n          enable_if_t<!is_specialize<U>::value,\
    \ nullptr_t> = nullptr>\nvoid dump(const U& t) {\n  cerr << t;\n}\n\ntemplate\
    \ <typename T>\nvoid dump(const T& t, enable_if_t<is_integral<T>::value>* = nullptr)\
    \ {\n  string res;\n  if (t == Nyaan::inf) res = \"inf\";\n  if constexpr (is_signed<T>::value)\
    \ {\n    if (t == -Nyaan::inf) res = \"-inf\";\n  }\n  if constexpr (sizeof(T)\
    \ == 8) {\n    if (t == Nyaan::infLL) res = \"inf\";\n    if constexpr (is_signed<T>::value)\
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
    \          \\\n  } while (0)\n#else\n#define trc(...) (void(0))\n#endif\n#line\
    \ 67 \"template/template.hpp\"\n\n// macro\n#line 1 \"template/macro.hpp\"\n#define\
    \ each(x, v) for (auto&& x : v)\n#define each2(x, y, v) for (auto&& [x, y] : v)\n\
    #define all(v) (v).begin(), (v).end()\n#define rep(i, N) for (long long i = 0;\
    \ i < (long long)(N); i++)\n#define repr(i, N) for (long long i = (long long)(N)-1;\
    \ i >= 0; i--)\n#define rep1(i, N) for (long long i = 1; i <= (long long)(N);\
    \ i++)\n#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)\n\
    #define reg(i, a, b) for (long long i = (a); i < (b); i++)\n#define regr(i, a,\
    \ b) for (long long i = (b)-1; i >= (a); i--)\n#define fi first\n#define se second\n\
    #define ini(...)   \\\n  int __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define inl(...)\
    \         \\\n  long long __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define ins(...)\
    \      \\\n  string __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define in2(s, t)    \
    \                       \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n \
    \   in(s[i], t[i]);                         \\\n  }\n#define in3(s, t, u)    \
    \                    \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i],\
    \ t[i], u[i]);                   \\\n  }\n#define in4(s, t, u, v)            \
    \         \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i],\
    \ u[i], v[i]);             \\\n  }\n#define die(...)             \\\n  do {  \
    \                     \\\n    Nyaan::out(__VA_ARGS__); \\\n    return;       \
    \           \\\n  } while (0)\n#line 70 \"template/template.hpp\"\n\nnamespace\
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line 4 \"verify/verify-unit-test/set-function.test.cpp\"\
    \n\nusing namespace Nyaan;\n\n#line 2 \"misc/rng.hpp\"\n\nnamespace my_rand {\n\
    \n// [0, 2^64 - 1)\nuint64_t rng() {\n  static uint64_t x_ =\n      uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
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
    \ { return mod; }\n};\n#line 2 \"set-function/and-convolution.hpp\"\n\n#line 2\
    \ \"set-function/zeta-mobius-transform.hpp\"\n\ntemplate <typename T>\nvoid superset_zeta_transform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j] += f[j | i];\n      }\n    }\n  }\n}\n\ntemplate <typename T>\n\
    void superset_mobius_transform(vector<T>& f) {\n  int n = f.size();\n  assert((n\
    \ & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0;\
    \ j < n; j++) {\n      if ((j & i) == 0) {\n        f[j] -= f[j | i];\n      }\n\
    \    }\n  }\n}\n\ntemplate <typename T>\nvoid subset_zeta_transform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j | i] += f[j];\n      }\n    }\n  }\n}\n\ntemplate <typename T>\n\
    void subset_mobius_transform(vector<T>& f) {\n  int n = f.size();\n  assert((n\
    \ & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0;\
    \ j < n; j++) {\n      if ((j & i) == 0) {\n        f[j | i] -= f[j];\n      }\n\
    \    }\n  }\n}\n\n/**\n * @brief Zeta Transform / Moebius Transform\n */\n#line\
    \ 5 \"set-function/and-convolution.hpp\"\n\ntemplate <typename T>\nvector<T> and_convolution(vector<T>\
    \ a, vector<T> b) {\n  superset_zeta_transform(a);\n  superset_zeta_transform(b);\n\
    \  for (int i = 0; i < (int)a.size(); i++) a[i] *= b[i];\n  superset_mobius_transform(a);\n\
    \  return a;\n}\n\n/**\n * @brief AND Convoluion\n */\n#line 2 \"set-function/or-convolution.hpp\"\
    \n\n#line 5 \"set-function/or-convolution.hpp\"\n\ntemplate <typename T>\nvector<T>\
    \ or_convolution(vector<T> a, vector<T> b) {\n  subset_zeta_transform(a);\n  subset_zeta_transform(b);\n\
    \  for (int i = 0; i < (int)a.size(); i++) a[i] *= b[i];\n  subset_mobius_transform(a);\n\
    \  return a;\n}\n\n/**\n * @brief OR Convoluion\n */\n#line 2 \"set-function/xor-convolution.hpp\"\
    \n\n#line 2 \"set-function/walsh-hadamard-transform.hpp\"\n\ntemplate <typename\
    \ T>\nvoid walsh_hadamard_transform(vector<T>& f, bool inverse = false) {\n  int\
    \ n = f.size();\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0; j <\
    \ n; j++) {\n      if ((j & i) == 0) {\n        T x = f[j], y = f[j | i];\n  \
    \      f[j] = x + y, f[j | i] = x - y;\n      }\n    }\n  }\n  if (inverse) {\n\
    \    if constexpr (is_integral<T>::value) {\n      for (auto& x : f) x /= n;\n\
    \    } else {\n      T invn = T(1) / T(f.size());\n      for (auto& x : f) x *=\
    \ invn;\n    }\n  }\n}\n\n/**\n * @brief Walsh Hadamard Transform\n */\n#line\
    \ 5 \"set-function/xor-convolution.hpp\"\n\ntemplate <typename T>\nvector<T> xor_convolution(vector<T>\
    \ a, vector<T> b) {\n  walsh_hadamard_transform(a);\n  walsh_hadamard_transform(b);\n\
    \  for (int i = 0; i < (int)a.size(); i++) a[i] *= b[i];\n  walsh_hadamard_transform(a,\
    \ true);\n  return a;\n}\n\n/**\n * @brief XOR Convoluion\n */\n#line 12 \"verify/verify-unit-test/set-function.test.cpp\"\
    \nusing mint = LazyMontgomeryModInt<998244353>;\n\ntemplate <typename T>\nvoid\
    \ test(int n) {\n  assert((n & (n - 1)) == 0);\n  vector<T> a(n), b(n), c(n);\n\
    \n  rep(i, n) {\n    a[i] = rng() & 0xFFFF;\n    b[i] = rng() & 0xFFFF;\n  }\n\
    \n  {\n    auto d = a;\n    subset_zeta_transform(d);\n    subset_mobius_transform(d);\n\
    \    assert(a == d && \"subset\");\n  }\n\n  {\n    auto d = a;\n    superset_zeta_transform(d);\n\
    \    superset_mobius_transform(d);\n    assert(a == d && \"superset\");\n  }\n\
    \n  {\n    auto d = a;\n    walsh_hadamard_transform(d);\n    walsh_hadamard_transform(d,\
    \ true);\n    assert(a == d && \"hadamard\");\n  }\n\n  // and convolution\n \
    \ {\n    auto d = and_convolution(a, b);\n    fill(all(c), 0);\n    rep(i, n)\
    \ rep(j, n) c[i & j] += a[i] * b[j];\n    assert(c == d && \"and\");\n  }\n\n\
    \  // or convolution\n  {\n    auto d = or_convolution(a, b);\n    fill(all(c),\
    \ 0);\n    rep(i, n) rep(j, n) c[i | j] += a[i] * b[j];\n    assert(c == d &&\
    \ \"or\");\n  }\n\n  // xor convolution\n  {\n    auto d = xor_convolution(a,\
    \ b);\n    fill(all(c), 0);\n    rep(i, n) rep(j, n) c[i ^ j] += a[i] * b[j];\n\
    \    assert(c == d && \"xor\");\n  }\n}\n\nvoid Nyaan::solve() {\n  for (int i\
    \ = 1; i <= 1024; i *= 2) {\n    test<ll>(i);\n    test<mint>(i);\n  }\n  cerr\
    \ << \"ok\" << endl;\n\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../template/template.hpp\"\n\nusing namespace Nyaan;\n\n#include \"../../misc/rng.hpp\"\
    \n#include \"../../modint/montgomery-modint.hpp\"\n#include \"../../set-function/and-convolution.hpp\"\
    \n#include \"../../set-function/or-convolution.hpp\"\n#include \"../../set-function/xor-convolution.hpp\"\
    \nusing mint = LazyMontgomeryModInt<998244353>;\n\ntemplate <typename T>\nvoid\
    \ test(int n) {\n  assert((n & (n - 1)) == 0);\n  vector<T> a(n), b(n), c(n);\n\
    \n  rep(i, n) {\n    a[i] = rng() & 0xFFFF;\n    b[i] = rng() & 0xFFFF;\n  }\n\
    \n  {\n    auto d = a;\n    subset_zeta_transform(d);\n    subset_mobius_transform(d);\n\
    \    assert(a == d && \"subset\");\n  }\n\n  {\n    auto d = a;\n    superset_zeta_transform(d);\n\
    \    superset_mobius_transform(d);\n    assert(a == d && \"superset\");\n  }\n\
    \n  {\n    auto d = a;\n    walsh_hadamard_transform(d);\n    walsh_hadamard_transform(d,\
    \ true);\n    assert(a == d && \"hadamard\");\n  }\n\n  // and convolution\n \
    \ {\n    auto d = and_convolution(a, b);\n    fill(all(c), 0);\n    rep(i, n)\
    \ rep(j, n) c[i & j] += a[i] * b[j];\n    assert(c == d && \"and\");\n  }\n\n\
    \  // or convolution\n  {\n    auto d = or_convolution(a, b);\n    fill(all(c),\
    \ 0);\n    rep(i, n) rep(j, n) c[i | j] += a[i] * b[j];\n    assert(c == d &&\
    \ \"or\");\n  }\n\n  // xor convolution\n  {\n    auto d = xor_convolution(a,\
    \ b);\n    fill(all(c), 0);\n    rep(i, n) rep(j, n) c[i ^ j] += a[i] * b[j];\n\
    \    assert(c == d && \"xor\");\n  }\n}\n\nvoid Nyaan::solve() {\n  for (int i\
    \ = 1; i <= 1024; i *= 2) {\n    test<ll>(i);\n    test<mint>(i);\n  }\n  cerr\
    \ << \"ok\" << endl;\n\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - misc/rng.hpp
  - modint/montgomery-modint.hpp
  - set-function/and-convolution.hpp
  - set-function/zeta-mobius-transform.hpp
  - set-function/or-convolution.hpp
  - set-function/xor-convolution.hpp
  - set-function/walsh-hadamard-transform.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/set-function.test.cpp
  requiredBy: []
  timestamp: '2021-04-26 17:20:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/set-function.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/set-function.test.cpp
- /verify/verify/verify-unit-test/set-function.test.cpp.html
title: verify/verify-unit-test/set-function.test.cpp
---
