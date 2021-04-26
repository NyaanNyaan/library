---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
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
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line 4 \"verify/verify-unit-test/template.test.cpp\"\
    \n//\n#line 2 \"misc/rng.hpp\"\n\nnamespace my_rand {\n\n// [0, 2^64 - 1)\nuint64_t\
    \ rng() {\n  static uint64_t x_ =\n      uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
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
    #line 6 \"verify/verify-unit-test/template.test.cpp\"\n//\nusing namespace Nyaan;\n\
    \n// bitop.hpp\n\nvoid verify_bitop() {\n  // popcnt\n  assert(popcnt(7) == 3);\n\
    \  assert(popcnt(0) == 0);\n  assert(popcnt(1LL << 40) == 1);\n  rep(loop, 100)\
    \ {\n    u64 x = rng();\n    int pc = popcnt(x);\n    rep(i, 64) if ((x >> i)\
    \ & 1) pc--;\n    assert(pc == 0 && \"popcnt\");\n  }\n\n  // lsb\n  assert(lsb(0)\
    \ == 64);\n  assert(lsb(1) == 0);\n  assert(lsb(1LL << 40) == 40);\n  assert(lsb(100)\
    \ == 2);\n\n  // ctz\n  assert(ctz(0) == 64);\n  assert(ctz(1) == 0);\n  assert(ctz(1LL\
    \ << 40) == 40);\n  assert(ctz(100) == 2);\n\n  rep(loop, 100) {\n    u64 x =\
    \ rng();\n    int n = lsb(x);\n    assert(ctz(x) == n);\n    while (n--) {\n \
    \     assert((x & 1) == 0 && \"lsb\");\n      x >>= 1;\n    }\n    assert((x &\
    \ 1) == 1 && \"lsb\");\n  }\n\n  // msb\n  assert(msb(0) == -1);\n  assert(msb(1)\
    \ == 0);\n  assert(msb(1LL << 40) == 40);\n  assert(msb(100) == 6);\n\n  rep(loop,\
    \ 100) {\n    u64 x = rng();\n    int m = msb(x);\n    if (m != -1) {\n      assert(((x\
    \ >> m) & 1) == 1 && \"msb\");\n    }\n    for (int i = m + 1; i < 64; i++) {\n\
    \      assert(((x >> i) & 1) == 0 && \"msb\");\n    }\n  }\n\n  // gbit, sbit\n\
    \  // sbit\u306F\u73FE\u5728\u30D0\u30B0\u308A\u4E2D\n  assert(gbit(5, 0) == 1);\n\
    \  assert(gbit(5, 1) == 0);\n  assert(gbit(5, 2) == 1);\n  assert(gbit(1LL <<\
    \ 40, 40) == 1);\n\n  rep(loop, 100) {\n    u64 x = rng();\n    for (int i = 0;\
    \ i < 64; i++) {\n      u64 g = gbit(x, i);\n      assert(((x >> i) & 1) == g\
    \ && \"gbit\");\n      /*\n      sbit(x, i, 1);\n      assert(((x >> i) & 1) ==\
    \ 1u && \"sbit\");\n      sbit(x, i, 0);\n      assert(((x >> i) & 1) == 0u &&\
    \ \"sbit\");\n      sbit(x, i, g);\n      */\n    }\n  }\n\n  // PW,MSK\n  rep(i,\
    \ 63) {\n    assert(1LL << i == PW(i));\n    assert(1LL << i == MSK(i) + 1);\n\
    \  }\n}\n\nvoid verify_util() {\n  // P, mkp\n  {\n    pl x(3, 2);\n    pl y(2,\
    \ 3);\n    assert(x + y == pl(5, 5));\n    assert(x - y == pl(1, -1));\n    assert(x\
    \ * y == pl(6, 6));\n    x += y;\n    assert(x == pl(5, 5));\n    x -= y;\n  \
    \  assert(x == pl(3, 2));\n    x *= y;\n    assert(x == pl(6, 6));\n\n    // mkp\n\
    \    auto p0 = mkp(1, 1);\n    static_assert(is_same<decltype(p0), pair<int, int>>::value);\n\
    \    auto p1 = mkp(1LL, double(2.0));\n    static_assert(is_same<decltype(p1),\
    \ pair<long long, double>>::value);\n    assert(p0.first == 1 && p0.second ==\
    \ 1);\n    assert(p1.first == 1LL && p1.second == 2.0);\n  }\n\n  // amin, amax\n\
    \  {\n    int x = 5;\n    amin(x, 4);\n    assert(x == 4);\n    amax(x, 5);\n\
    \    assert(x == 5);\n  }\n\n  // sz, Max, Min, Sum, mkrui, lb, ub, mkuni\n  {\n\
    \    // sz, Max, Min, Sum\n    vector<int> v;\n    for (int i = 0; i < 100; i++)\
    \ {\n      assert(sz(v) == i);\n      v.push_back(randint(0, 10));\n      assert(Max(v)\
    \ == *max_element(all(v)));\n      assert(Min(v) == *min_element(all(v)));\n \
    \     assert(Sum(v) == accumulate(all(v), 0LL));\n    }\n\n    // mkrui\n    auto\
    \ rui = mkrui(v);\n    int buf = 0;\n    rep(i, sz(v)) {\n      buf += v[i];\n\
    \      assert(rui[i + 1] == buf);\n    }\n\n    // lb, ub\n    sort(all(v));\n\
    \    for (int i = 0; i < sz(v); i++) {\n      if (i != 0 and v[i - 1] == v[i])\
    \ continue;\n      int x = v[i];\n      assert(lb(v, x) == i);\n      assert(ub(v,\
    \ x - 1) == i);\n    }\n    for (int x = 0; x < 10; x++) {\n      int l = lb(v,\
    \ x);\n      int u = ub(v, x);\n      for (int i = 0; i < sz(v); i++) {\n    \
    \    assert((l <= i) == (x <= v[i]) && \"lb\");\n        assert((u <= i) == (x\
    \ < v[i]) && \"ub\");\n      }\n    }\n\n    // mkuni\n    set<int> s1, s2;\n\
    \    for (int i : v) s1.insert(i);\n    v = mkuni(v);\n    for (int i : v) s2.insert(i);\n\
    \    assert(s1 == s2);\n  }\n\n  // TEN\n  for (long long i = 0, x = 1; i <= 18;\
    \ i++, x *= 10) {\n    assert(TEN(i) == x);\n  }\n\n  // mkord, mkinv(100\u500B\
    , 1~1000)\n  {\n    vector<int> v;\n    rep(loop, 100) { v.push_back(loop); }\n\
    \    auto ord = mkord(sz(v), [&v](int i, int j) { return v[i] < v[j]; });\n  \
    \  rep(i, sz(ord) - 1) { assert(v[ord[i]] <= v[ord[i + 1]] && \"mkord\"); }\n\n\
    \    randshf(v);\n    auto inv = mkinv(v);\n    assert(inv.size() == 100 && \"\
    mkinv\");\n    set<int> st;\n    each(x, v) st.insert(x);\n    rep(i, sz(inv))\
    \ {\n      if (inv[i] == -1) {\n        assert(st.find(i) == st.end() && \"mkinv\"\
    );\n      } else {\n        assert(0 <= inv[i] && inv[i] < sz(v) && \"mkinv\"\
    );\n        assert(v[inv[i]] == i);\n      }\n    }\n  }\n\n  // mkord, mkinv(100\u500B\
    , 1~1000)\n  {\n    vector<int> v;\n    rep(loop, 100) { v.push_back(randint(0,\
    \ 1000)); }\n    auto ord = mkord(sz(v), [&v](int i, int j) { return v[i] < v[j];\
    \ });\n    rep(i, sz(ord) - 1) { assert(v[ord[i]] <= v[ord[i + 1]] && \"mkord\"\
    ); }\n\n    v = mkuni(v);\n    randshf(v);\n    auto inv = mkinv(v);\n    assert(sz(inv)\
    \ == Max(v) + 1 && \"mkinv\");\n    set<int> st;\n    each(x, v) st.insert(x);\n\
    \    rep(i, sz(inv)) {\n      if (inv[i] == -1) {\n        assert(st.find(i) ==\
    \ st.end() && \"mkinv\");\n      } else {\n        assert(0 <= inv[i] && inv[i]\
    \ < sz(v) && \"mkinv\");\n        assert(v[inv[i]] == i);\n      }\n    }\n  }\n\
    }\n\nvoid Nyaan::solve() {\n  verify_bitop();\n  verify_util();\n\n  int a, b;\n\
    \  cin >> a >> b;\n  cout << a + b << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../misc/rng.hpp\"\n//\nusing\
    \ namespace Nyaan;\n\n// bitop.hpp\n\nvoid verify_bitop() {\n  // popcnt\n  assert(popcnt(7)\
    \ == 3);\n  assert(popcnt(0) == 0);\n  assert(popcnt(1LL << 40) == 1);\n  rep(loop,\
    \ 100) {\n    u64 x = rng();\n    int pc = popcnt(x);\n    rep(i, 64) if ((x >>\
    \ i) & 1) pc--;\n    assert(pc == 0 && \"popcnt\");\n  }\n\n  // lsb\n  assert(lsb(0)\
    \ == 64);\n  assert(lsb(1) == 0);\n  assert(lsb(1LL << 40) == 40);\n  assert(lsb(100)\
    \ == 2);\n\n  // ctz\n  assert(ctz(0) == 64);\n  assert(ctz(1) == 0);\n  assert(ctz(1LL\
    \ << 40) == 40);\n  assert(ctz(100) == 2);\n\n  rep(loop, 100) {\n    u64 x =\
    \ rng();\n    int n = lsb(x);\n    assert(ctz(x) == n);\n    while (n--) {\n \
    \     assert((x & 1) == 0 && \"lsb\");\n      x >>= 1;\n    }\n    assert((x &\
    \ 1) == 1 && \"lsb\");\n  }\n\n  // msb\n  assert(msb(0) == -1);\n  assert(msb(1)\
    \ == 0);\n  assert(msb(1LL << 40) == 40);\n  assert(msb(100) == 6);\n\n  rep(loop,\
    \ 100) {\n    u64 x = rng();\n    int m = msb(x);\n    if (m != -1) {\n      assert(((x\
    \ >> m) & 1) == 1 && \"msb\");\n    }\n    for (int i = m + 1; i < 64; i++) {\n\
    \      assert(((x >> i) & 1) == 0 && \"msb\");\n    }\n  }\n\n  // gbit, sbit\n\
    \  // sbit\u306F\u73FE\u5728\u30D0\u30B0\u308A\u4E2D\n  assert(gbit(5, 0) == 1);\n\
    \  assert(gbit(5, 1) == 0);\n  assert(gbit(5, 2) == 1);\n  assert(gbit(1LL <<\
    \ 40, 40) == 1);\n\n  rep(loop, 100) {\n    u64 x = rng();\n    for (int i = 0;\
    \ i < 64; i++) {\n      u64 g = gbit(x, i);\n      assert(((x >> i) & 1) == g\
    \ && \"gbit\");\n      /*\n      sbit(x, i, 1);\n      assert(((x >> i) & 1) ==\
    \ 1u && \"sbit\");\n      sbit(x, i, 0);\n      assert(((x >> i) & 1) == 0u &&\
    \ \"sbit\");\n      sbit(x, i, g);\n      */\n    }\n  }\n\n  // PW,MSK\n  rep(i,\
    \ 63) {\n    assert(1LL << i == PW(i));\n    assert(1LL << i == MSK(i) + 1);\n\
    \  }\n}\n\nvoid verify_util() {\n  // P, mkp\n  {\n    pl x(3, 2);\n    pl y(2,\
    \ 3);\n    assert(x + y == pl(5, 5));\n    assert(x - y == pl(1, -1));\n    assert(x\
    \ * y == pl(6, 6));\n    x += y;\n    assert(x == pl(5, 5));\n    x -= y;\n  \
    \  assert(x == pl(3, 2));\n    x *= y;\n    assert(x == pl(6, 6));\n\n    // mkp\n\
    \    auto p0 = mkp(1, 1);\n    static_assert(is_same<decltype(p0), pair<int, int>>::value);\n\
    \    auto p1 = mkp(1LL, double(2.0));\n    static_assert(is_same<decltype(p1),\
    \ pair<long long, double>>::value);\n    assert(p0.first == 1 && p0.second ==\
    \ 1);\n    assert(p1.first == 1LL && p1.second == 2.0);\n  }\n\n  // amin, amax\n\
    \  {\n    int x = 5;\n    amin(x, 4);\n    assert(x == 4);\n    amax(x, 5);\n\
    \    assert(x == 5);\n  }\n\n  // sz, Max, Min, Sum, mkrui, lb, ub, mkuni\n  {\n\
    \    // sz, Max, Min, Sum\n    vector<int> v;\n    for (int i = 0; i < 100; i++)\
    \ {\n      assert(sz(v) == i);\n      v.push_back(randint(0, 10));\n      assert(Max(v)\
    \ == *max_element(all(v)));\n      assert(Min(v) == *min_element(all(v)));\n \
    \     assert(Sum(v) == accumulate(all(v), 0LL));\n    }\n\n    // mkrui\n    auto\
    \ rui = mkrui(v);\n    int buf = 0;\n    rep(i, sz(v)) {\n      buf += v[i];\n\
    \      assert(rui[i + 1] == buf);\n    }\n\n    // lb, ub\n    sort(all(v));\n\
    \    for (int i = 0; i < sz(v); i++) {\n      if (i != 0 and v[i - 1] == v[i])\
    \ continue;\n      int x = v[i];\n      assert(lb(v, x) == i);\n      assert(ub(v,\
    \ x - 1) == i);\n    }\n    for (int x = 0; x < 10; x++) {\n      int l = lb(v,\
    \ x);\n      int u = ub(v, x);\n      for (int i = 0; i < sz(v); i++) {\n    \
    \    assert((l <= i) == (x <= v[i]) && \"lb\");\n        assert((u <= i) == (x\
    \ < v[i]) && \"ub\");\n      }\n    }\n\n    // mkuni\n    set<int> s1, s2;\n\
    \    for (int i : v) s1.insert(i);\n    v = mkuni(v);\n    for (int i : v) s2.insert(i);\n\
    \    assert(s1 == s2);\n  }\n\n  // TEN\n  for (long long i = 0, x = 1; i <= 18;\
    \ i++, x *= 10) {\n    assert(TEN(i) == x);\n  }\n\n  // mkord, mkinv(100\u500B\
    , 1~1000)\n  {\n    vector<int> v;\n    rep(loop, 100) { v.push_back(loop); }\n\
    \    auto ord = mkord(sz(v), [&v](int i, int j) { return v[i] < v[j]; });\n  \
    \  rep(i, sz(ord) - 1) { assert(v[ord[i]] <= v[ord[i + 1]] && \"mkord\"); }\n\n\
    \    randshf(v);\n    auto inv = mkinv(v);\n    assert(inv.size() == 100 && \"\
    mkinv\");\n    set<int> st;\n    each(x, v) st.insert(x);\n    rep(i, sz(inv))\
    \ {\n      if (inv[i] == -1) {\n        assert(st.find(i) == st.end() && \"mkinv\"\
    );\n      } else {\n        assert(0 <= inv[i] && inv[i] < sz(v) && \"mkinv\"\
    );\n        assert(v[inv[i]] == i);\n      }\n    }\n  }\n\n  // mkord, mkinv(100\u500B\
    , 1~1000)\n  {\n    vector<int> v;\n    rep(loop, 100) { v.push_back(randint(0,\
    \ 1000)); }\n    auto ord = mkord(sz(v), [&v](int i, int j) { return v[i] < v[j];\
    \ });\n    rep(i, sz(ord) - 1) { assert(v[ord[i]] <= v[ord[i + 1]] && \"mkord\"\
    ); }\n\n    v = mkuni(v);\n    randshf(v);\n    auto inv = mkinv(v);\n    assert(sz(inv)\
    \ == Max(v) + 1 && \"mkinv\");\n    set<int> st;\n    each(x, v) st.insert(x);\n\
    \    rep(i, sz(inv)) {\n      if (inv[i] == -1) {\n        assert(st.find(i) ==\
    \ st.end() && \"mkinv\");\n      } else {\n        assert(0 <= inv[i] && inv[i]\
    \ < sz(v) && \"mkinv\");\n        assert(v[inv[i]] == i);\n      }\n    }\n  }\n\
    }\n\nvoid Nyaan::solve() {\n  verify_bitop();\n  verify_util();\n\n  int a, b;\n\
    \  cin >> a >> b;\n  cout << a + b << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - misc/rng.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/template.test.cpp
  requiredBy: []
  timestamp: '2021-04-27 01:21:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/template.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/template.test.cpp
- /verify/verify/verify-unit-test/template.test.cpp.html
title: verify/verify-unit-test/template.test.cpp
---
