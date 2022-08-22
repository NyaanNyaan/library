---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/timer.hpp
    title: misc/timer.hpp
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
  - icon: ':heavy_check_mark:'
    path: trial/fast-gcd.hpp
    title: "\u9AD8\u901FGCD"
  - icon: ':heavy_check_mark:'
    path: trial/fast-inv.hpp
    title: "\u9AD8\u901Fmodulo\u9006\u5143"
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
  bundledCode: "#line 1 \"verify/verify-unit-test/fast-inv-gcd.test.cpp\"\n#define\
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
    inline int lsb(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }\ninline int\
    \ ctz(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }\ninline int msb(const\
    \ u64 &a) { return a ? 63 - __builtin_clzll(a) : -1; }\ntemplate <typename T>\n\
    inline int gbit(const T &a, int i) {\n  return (a >> i) & 1;\n}\ntemplate <typename\
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
    \ for (auto &x : v) is >> x;\n  return is;\n}\n\nvoid in() {}\ntemplate <typename\
    \ T, class... U>\nvoid in(T &t, U &... u) {\n  cin >> t;\n  in(u...);\n}\n\nvoid\
    \ out() { cout << \"\\n\"; }\ntemplate <typename T, class... U, char sep = ' '>\n\
    void out(const T &t, const U &... u) {\n  cout << t;\n  if (sizeof...(u)) cout\
    \ << sep;\n  out(u...);\n}\n\nvoid outr() {}\ntemplate <typename T, class... U,\
    \ char sep = ' '>\nvoid outr(const T &t, const U &... u) {\n  cout << t;\n  outr(u...);\n\
    }\n\nstruct IoSetupNya {\n  IoSetupNya() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
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
    \ ? \"true\" : \"false\"); }\n\ntemplate <typename U,\n          enable_if_t<!is_specialize<U>::value,\
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
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line 2 \"trial/fast-inv.hpp\"\
    \n\n\n\n#line 2 \"misc/timer.hpp\"\n\n#line 4 \"misc/timer.hpp\"\n\nstruct Timer\
    \ {\n  chrono::high_resolution_clock::time_point st;\n\n  Timer() { reset(); }\n\
    \n  void reset() { st = chrono::high_resolution_clock::now(); }\n\n  chrono::milliseconds::rep\
    \ elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n    return\
    \ chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n};\n#line\
    \ 6 \"trial/fast-inv.hpp\"\n\nnamespace fast_inv {\nusing u64 = uint64_t;\nusing\
    \ u32 = uint32_t;\nusing i32 = int32_t;\nconstexpr u32 MOD = 998244353;\n\nstruct\
    \ Pre {\n  u32 a[64];\n  constexpr Pre() : a() {\n    static_assert(MOD & 1);\n\
    \    a[0] = 1;\n    for (int i = 1; i < 64; i++) a[i] = u64(a[i - 1]) * ((MOD\
    \ + 1) >> 1) % MOD;\n  }\n} constexpr pre;\n\n__attribute__((target(\"bmi\")))\
    \ u32 bgcd_inv(u32 a) {\n  u32 b = MOD, s = 1, t = 0;\n  int n = __builtin_ctz(a);\n\
    \  a >>= n;\n  if (__builtin_expect(a < 1 << 20, false)) {\n    if (a == 1) return\
    \ pre.a[n];\n    t = -(b / a);\n    b %= a;\n    int m = __builtin_ctz(b);\n \
    \   b >>= m;\n    s = 1u << m;\n    n += m;\n  }\n  while (a != b) {\n    int\
    \ m = __builtin_ctz(a - b);\n    n += m;\n    if (a > b) {\n      a -= b;\n  \
    \    s -= t;\n      a >>= m;\n      t <<= m;\n    } else {\n      b -= a;\n  \
    \    t -= s;\n      b >>= m;\n      s <<= m;\n    }\n  }\n  return u64(s) * pre.a[n]\
    \ % MOD;\n}\n\n}  // namespace fast_inv\n\nnamespace fast_inv {\n\n__attribute__((optimize(\"\
    unroll-loops\"))) u32 pow_inv(u32 a) {\n  u32 ret = 1;\n  for (u32 p = MOD - 2;\
    \ p; a = u64(a) * a % MOD, p >>= 1)\n    if (p & 1) ret = u64(ret) * a % MOD;\n\
    \  return ret;\n}\n\nu32 egcd_inv(u32 a) {\n  u32 b = MOD, s = 1, t = 0;\n  while\
    \ (true) {\n    if (a == 1) return s;\n    t -= b / a * s;\n    b %= a;\n    if\
    \ (b == 1) return t + MOD;\n    s -= a / b * t;\n    a %= b;\n  }\n}\n\nu32 reduce(const\
    \ u64 &b) { return (b + u64(u32(b) * 998244351u) * MOD) >> 32; }\n\nu32 mul(const\
    \ u32 &a, const u32 &b) { return reduce(u64(a) * b); }\n\n__attribute__((optimize(\"\
    unroll-loops\"))) u32 montgomery_pow_inv(u32 a) {\n  u32 ret = 301989884u;\n \
    \ for (u32 p = MOD - 2; p; a = mul(a, a), p >>= 1)\n    if (p & 1) ret = mul(ret,\
    \ a);\n  return reduce(reduce(ret));\n}\n\nu64 x_;\nvoid rng_init() { x_ = 88172645463325252ULL;\
    \ }\nu64 rng() { return x_ = x_ ^ (x_ << 7), x_ = x_ ^ (x_ >> 9); }\n\nvoid test_inner(u32\
    \ (*f)(u32)) {\n  auto test = [](u32 (*f)(u32), int n, u32 upper, string s) {\n\
    \    assert((upper & (upper - 1)) == 0);\n    --upper;\n\n    // set timer\n \
    \   Timer timer;\n    timer.reset();\n\n    // calculation\n    u64 res = 0;\n\
    \    while (n--) {\n      u32 a;\n      do {\n        a = rng() & upper;\n   \
    \     a = a >= MOD ? a - MOD : a;\n      } while (a == 0);\n      res += f(a);\n\
    \    }\n\n    // output results\n    cerr << s << \" \" << res << \" \" << timer.elapsed()\
    \ << endl;\n  };\n\n  rng_init();\n  test(f, 1e5, 1 << 10, \"small\");\n  test(f,\
    \ 1e5, 1 << 20, \"medium\");\n  test(f, 1e5, 1 << 30, \"large\");\n}\n\nvoid unit_test()\
    \ {\n  using F = u32 (*)(u32);\n\n  vector<u32> testcase;\n  for (u32 i = 1; i\
    \ <= 100000; ++i) testcase.emplace_back(i);\n  rng_init();\n  for (u32 loop =\
    \ 100000; --loop;) {\n    u32 r = rng() % MOD;\n    if (r != 0) testcase.emplace_back(r);\n\
    \  }\n  vector<F> functions = {pow_inv, egcd_inv, montgomery_pow_inv, bgcd_inv};\n\
    \n  for (auto t : testcase) {\n    unordered_set<u32> s;\n    for (auto &f : functions)\
    \ {\n      s.insert(f(t));\n    }\n    if (s.size() != 1u) {\n      cerr << \"\
    verify failed.\" << endl;\n      cerr << \"case : \" << t << endl;\n      cerr\
    \ << \"output : \";\n      for (auto &f : functions) cerr << f(t) << \", \";\n\
    \      cerr << endl;\n      exit(1);\n    }\n  }\n  cerr << \"verify passed.\"\
    \ << endl;\n\n  // pow-inv\n  cerr << \"pow-inv\" << endl;\n  test_inner(pow_inv);\n\
    \n  // extgcd-inv\n  cerr << \"extgcd-inv\" << endl;\n  test_inner(egcd_inv);\n\
    \n  // montgomery-inv\n  cerr << \"montgomery-inv\" << endl;\n  test_inner(montgomery_pow_inv);\n\
    \n  // binary-gcd-inv\n  cerr << \"binary-gcd-inv\" << endl;\n  test_inner(bgcd_inv);\n\
    }\n\n}  // namespace fast_inv\n\n/**\n * @brief \u9AD8\u901Fmodulo\u9006\u5143\
    \n * @docs docs/trial/fast-inv.md\n */\n#line 2 \"trial/fast-gcd.hpp\"\n\n\n\n\
    #line 6 \"trial/fast-gcd.hpp\"\n\nnamespace fast_gcd {\nusing u64 = uint64_t;\n\
    using u32 = uint32_t;\n\n__attribute__((target(\"bmi\"))) u64 binary_gcd(u64 a,\
    \ u64 b) {\n  if (a == 0 || b == 0) return a + b;\n  int n = __builtin_ctzll(a);\n\
    \  int m = __builtin_ctzll(b);\n  a >>= n;\n  b >>= m;\n  while (a != b) {\n \
    \   int m = __builtin_ctzll(a - b);\n    bool f = a > b;\n    u64 c = f ? a :\
    \ b;\n    b = f ? b : a;\n    a = (c - b) >> m;\n  }\n  return a << min(n, m);\n\
    }\n}  // namespace fast_gcd\n\nnamespace fast_gcd {\n\nuint64_t naive_gcd(uint64_t\
    \ a, uint64_t b) {\n  while (b) swap(a %= b, b);\n  return a;\n}\n\nu64 x_;\n\
    void rng_init() { x_ = 88172645463325252ULL; }\nu64 rng() { return x_ = x_ ^ (x_\
    \ << 7), x_ = x_ ^ (x_ >> 9); }\n\nvoid test_inner(u64 (*f)(u64, u64)) {\n  auto\
    \ test = [&](u64 (*f)(u64, u64), int n, u64 upper, string s) {\n    assert((upper\
    \ & (upper - 1)) == 0);\n    --upper;\n\n    // set timer\n    Timer timer;\n\
    \    timer.reset();\n\n    // calculation\n    u64 res = 0;\n    while (n--) {\n\
    \      u64 a = rng() & upper;\n      u64 b = rng() & upper;\n      res += f(a,\
    \ b);\n    }\n\n    // output results\n    cerr << s << \" \" << res << \" \"\
    \ << timer.elapsed() << endl;\n  };\n\n  rng_init();\n  test(f, 1e5, 1LL << 16,\
    \ \"small\");\n  test(f, 1e5, 1LL << 32, \"medium\");\n  test(f, 1e5, 0, \"large\"\
    );\n}\n\nvoid unit_test() {\n  using P = pair<u64, u64>;\n  using F = u64 (*)(u64,\
    \ u64);\n\n  vector<P> testcase{P(2, 4),\n                     P(100000, 10000),\n\
    \                     P(998244353, 1000000007),\n                     P(1LL <<\
    \ 40, 1LL << 60),\n                     P((1LL << 61) - 1, 11111111111111111),\n\
    \                     P((1LL << 60) + 1, (1LL << 59) + 1),\n                 \
    \    P(1LL << 63, 1LL << 63),\n                     P(1LL << 63, 1LL << 62),\n\
    \                     P(3LL << 61, 9LL << 60)};\n  for (u64 i = 1000; i--;)\n\
    \    for (u64 j = 1000; j--;) testcase.emplace_back(i, j);\n  rng_init();\n  for\
    \ (u64 n = 10000; n--;) {\n    u64 i = rng(), j = rng();\n    testcase.emplace_back(i,\
    \ j);\n  }\n\n  vector<F> functions{\n      std::__gcd<uint64_t>,\n      naive_gcd,\n\
    \      binary_gcd,\n  };\n\n  for (auto p : testcase) {\n    unordered_set<u64>\
    \ s;\n    for (auto &f : functions) {\n      s.insert(f(p.first, p.second));\n\
    \    }\n    if (s.size() != 1u) {\n      cerr << \"verify failed.\" << endl;\n\
    \      cerr << \"case : \" << p.first << \" \" << p.second << endl;\n      cerr\
    \ << \"output : \";\n      for (auto &f : functions) cerr << f(p.first, p.second)\
    \ << \", \";\n      cerr << endl;\n      exit(1);\n    }\n  }\n  cerr << \"verify\
    \ passed.\" << endl;\n\n  // std::__gcd\n  cerr << \"std::__gcd\" << endl;\n \
    \ test_inner(std::__gcd<uint64_t>);\n\n  // naive-gcd\n  cerr << \"naive-gcd\"\
    \ << endl;\n  test_inner(naive_gcd);\n\n  // binary-gcd\n  cerr << \"binary-gcd\"\
    \ << endl;\n  test_inner(binary_gcd);\n}\n\n}  // namespace fast_gcd\n\n/**\n\
    \ * @brief \u9AD8\u901FGCD\n * @docs docs/trial/fast-gcd.md\n */\n#line 6 \"verify/verify-unit-test/fast-inv-gcd.test.cpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve(){\n  fast_inv::unit_test();\n  fast_gcd::unit_test();\n\
    \n  int a,b;\n  cin >> a >> b;\n  cout << (a + b) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../template/template.hpp\"\n#include \"../../trial/fast-inv.hpp\"\n#include\
    \ \"../../trial/fast-gcd.hpp\"\n\nusing namespace Nyaan; void Nyaan::solve(){\n\
    \  fast_inv::unit_test();\n  fast_gcd::unit_test();\n\n  int a,b;\n  cin >> a\
    \ >> b;\n  cout << (a + b) << endl;\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - trial/fast-inv.hpp
  - misc/timer.hpp
  - trial/fast-gcd.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/fast-inv-gcd.test.cpp
  requiredBy: []
  timestamp: '2021-11-14 23:34:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/fast-inv-gcd.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/fast-inv-gcd.test.cpp
- /verify/verify/verify-unit-test/fast-inv-gcd.test.cpp.html
title: verify/verify-unit-test/fast-inv-gcd.test.cpp
---
