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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/complex-fft.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#line 2 \"template/template.hpp\"\
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
    \ 4 \"verify/verify-unit-test/complex-fft.test.cpp\"\n//\n#line 2 \"misc/rng.hpp\"\
    \n\n#line 2 \"internal/internal-seed.hpp\"\n\n#line 4 \"internal/internal-seed.hpp\"\
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
    \  for (auto& x : s) ret.push_back(x);\n  return ret;\n}\n\n// [0.0, 1.0)\ndouble\
    \ rnd() { return rng() * 5.42101086242752217004e-20; }\n// [l, r)\ndouble rnd(double\
    \ l, double r) {\n  assert(l < r);\n  return l + rnd() * (r - l);\n}\n\ntemplate\
    \ <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n  for (int\
    \ i = 1; i < n; i++) swap(v[i], v[randint(0, i + 1)]);\n}\n\n}  // namespace my_rand\n\
    \nusing my_rand::randint;\nusing my_rand::randset;\nusing my_rand::randshf;\n\
    using my_rand::rnd;\nusing my_rand::rng;\n#line 2 \"ntt/complex-fft.hpp\"\n\n\
    namespace ArbitraryModConvolution {\n\ntemplate <typename T>\nstruct Cp {\n  T\
    \ x, y;\n  constexpr Cp() : x(0), y(0) {}\n  constexpr Cp(T _x, T _y) : x(_x),\
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
    \  template <unsigned int MOD = -1u>\n  static conditional_t<MOD == -1u, vector<__uint128_t>,\
    \ vector<int>>\n  multiply_15bit(const vector<int>& a, const vector<int>& b) {\n\
    \    using u64 = unsigned long long;\n    constexpr u64 B = 32000;\n    int l\
    \ = a.size() + b.size() - 1;\n    int k = 2, M = 4;\n    while (M < l) M <<= 1,\
    \ ++k;\n    setw(k);\n    auto round = [](double x) -> u64 { return u64(x + 0.5);\
    \ };\n\n    vector<C> AL(M), AH(M), BL(M), BH(M);\n    for (int i = 0; i < (int)a.size();\
    \ i++) {\n      AL[i] = C{double(a[i] % B), double(a[i] / B)};\n    }\n    for\
    \ (int i = 0; i < (int)b.size(); i++) {\n      BL[i] = C{double(b[i] % B), double(b[i]\
    \ / B)};\n    }\n\n    fft_real(AL, AH, k);\n    fft_real(BL, BH, k);\n\n    for\
    \ (int i = 0; i < M; i++) {\n      C tmp = AL[i] * BL[i] + (AH[i] * BH[i]).rotl();\n\
    \      BH[i] = AL[i] * BH[i] + (AH[i] * BL[i]).rotl();\n      BL[i] = tmp;\n \
    \   }\n\n    ifft(BL, k);\n    ifft(BH, k);\n\n    using return_type =\n     \
    \   conditional_t<MOD + 1u == 0u, vector<__uint128_t>, vector<int>>;\n\n    return_type\
    \ u(l);\n    double im = 1.0 / (4.0 * M);\n    for (int i = 0; i < l; i++) {\n\
    \      BL[i].x *= im, BL[i].y *= im;\n      BH[i].x *= im, BH[i].y *= im;\n  \
    \    u64 s1 = round(BL[i].x);\n      u64 s2 = round(BH[i].x) + round(BH[i].y);\n\
    \      u64 s3 = round(BL[i].y);\n\n      if constexpr (MOD == -1u) {\n       \
    \ u[i] += __uint128_t(s1);\n        u[i] += __uint128_t(s2) * B;\n        u[i]\
    \ += __uint128_t(s3) * B * B;\n      } else {\n        u[i] += s1 % MOD;\n   \
    \     u[i] += s2 % MOD * B % MOD;\n        if (u[i] >= MOD) u[i] -= MOD;\n   \
    \     u[i] += s3 % MOD * (B * B % MOD) % MOD;\n        if (u[i] >= MOD) u[i] -=\
    \ MOD;\n      }\n    }\n    return u;\n  }\n};\nvector<C> CooleyTukey::w;\n\n\
    }  // namespace ArbitraryModConvolution\n#line 7 \"verify/verify-unit-test/complex-fft.test.cpp\"\
    \n\nusing namespace Nyaan;\n\nvl naive(vi a, vi b) {\n  int n = sz(a), m = sz(b);\n\
    \  vl c(n + m - 1);\n  rep(i, n) rep(j, m) { c[i + j] += 1LL * a[i] * b[j]; }\n\
    \  return c;\n}\n\nvi naive_mod(vi a, vi b, int mod) {\n  int n = sz(a), m = sz(b);\n\
    \  vi c(n + m - 1);\n  rep(i, n) rep(j, m) {\n    ll x = c[i + j] + 1LL * a[i]\
    \ * b[j];\n    c[i + j] = x % mod;\n  }\n  return c;\n}\n\nvoid is_same_negative(vi\
    \ a, vi b) {\n  auto c1 = ArbitraryModConvolution::CooleyTukey::multiply(a, b);\n\
    \  auto c2 = naive(a, b);\n  if (c1 != c2) {\n    out(sz(a), sz(b));\n    rep(i,\
    \ sz(c1)) {\n      if (c1[i] != c2[i]) out(i, c1[i], c2[i]);\n    }\n    exit(1);\n\
    \  }\n}\n\nvoid is_same_mod(vi a, vi b) {\n  auto c1 =\n      ArbitraryModConvolution::CooleyTukey::multiply_15bit<TEN(9)\
    \ + 7>(a, b);\n  auto c2 = naive_mod(a, b, TEN(9) + 7);\n  if (c1 != c2) {\n \
    \   out(a);\n    out(b);\n    out(c1);\n    out(c2);\n    exit(1);\n  }\n}\n\n\
    void test() {\n  // negative\n  rep(loop, 100) {\n    vi a(randint(1, TEN(3)));\n\
    \    vi b(randint(1, TEN(3)));\n    each(x, a) x = randint(-TEN(5), TEN(5));\n\
    \    each(x, b) x = randint(-TEN(5), TEN(5));\n    is_same_negative(a, b);\n \
    \ }\n  // mod\n  rep(loop, 100) {\n    vi a(randint(1, 100));\n    vi b(randint(1,\
    \ 100));\n    each(x, a) x = randint(0, TEN(9) + 7);\n    each(x, b) x = randint(0,\
    \ TEN(9) + 7);\n    is_same_mod(a, b);\n  }\n}\n\nvoid Nyaan::solve() {\n  test();\n\
    \n  int a, b;\n  cin >> a >> b;\n  cout << (a + b) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../misc/rng.hpp\"\n#include\
    \ \"../../ntt/complex-fft.hpp\"\n\nusing namespace Nyaan;\n\nvl naive(vi a, vi\
    \ b) {\n  int n = sz(a), m = sz(b);\n  vl c(n + m - 1);\n  rep(i, n) rep(j, m)\
    \ { c[i + j] += 1LL * a[i] * b[j]; }\n  return c;\n}\n\nvi naive_mod(vi a, vi\
    \ b, int mod) {\n  int n = sz(a), m = sz(b);\n  vi c(n + m - 1);\n  rep(i, n)\
    \ rep(j, m) {\n    ll x = c[i + j] + 1LL * a[i] * b[j];\n    c[i + j] = x % mod;\n\
    \  }\n  return c;\n}\n\nvoid is_same_negative(vi a, vi b) {\n  auto c1 = ArbitraryModConvolution::CooleyTukey::multiply(a,\
    \ b);\n  auto c2 = naive(a, b);\n  if (c1 != c2) {\n    out(sz(a), sz(b));\n \
    \   rep(i, sz(c1)) {\n      if (c1[i] != c2[i]) out(i, c1[i], c2[i]);\n    }\n\
    \    exit(1);\n  }\n}\n\nvoid is_same_mod(vi a, vi b) {\n  auto c1 =\n      ArbitraryModConvolution::CooleyTukey::multiply_15bit<TEN(9)\
    \ + 7>(a, b);\n  auto c2 = naive_mod(a, b, TEN(9) + 7);\n  if (c1 != c2) {\n \
    \   out(a);\n    out(b);\n    out(c1);\n    out(c2);\n    exit(1);\n  }\n}\n\n\
    void test() {\n  // negative\n  rep(loop, 100) {\n    vi a(randint(1, TEN(3)));\n\
    \    vi b(randint(1, TEN(3)));\n    each(x, a) x = randint(-TEN(5), TEN(5));\n\
    \    each(x, b) x = randint(-TEN(5), TEN(5));\n    is_same_negative(a, b);\n \
    \ }\n  // mod\n  rep(loop, 100) {\n    vi a(randint(1, 100));\n    vi b(randint(1,\
    \ 100));\n    each(x, a) x = randint(0, TEN(9) + 7);\n    each(x, b) x = randint(0,\
    \ TEN(9) + 7);\n    is_same_mod(a, b);\n  }\n}\n\nvoid Nyaan::solve() {\n  test();\n\
    \n  int a, b;\n  cin >> a >> b;\n  cout << (a + b) << endl;\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - misc/rng.hpp
  - internal/internal-seed.hpp
  - ntt/complex-fft.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/complex-fft.test.cpp
  requiredBy: []
  timestamp: '2023-08-10 14:06:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/complex-fft.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/complex-fft.test.cpp
- /verify/verify/verify-unit-test/complex-fft.test.cpp.html
title: verify/verify-unit-test/complex-fft.test.cpp
---