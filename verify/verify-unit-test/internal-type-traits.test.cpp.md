---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: hashmap/hashmap-unerasable.hpp
    title: hashmap/hashmap-unerasable.hpp
  - icon: ':heavy_check_mark:'
    path: internal/internal-hash-function.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u95A2\u6570"
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
  bundledCode: "#line 1 \"verify/verify-unit-test/internal-type-traits.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#line 2 \"template/template.hpp\"\
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
    \ 4 \"verify/verify-unit-test/internal-type-traits.test.cpp\"\n//\n#line 2 \"\
    misc/rng.hpp\"\n\n#line 2 \"internal/internal-seed.hpp\"\n\n#line 4 \"internal/internal-seed.hpp\"\
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
    using my_rand::rnd;\nusing my_rand::rng;\n#line 6 \"verify/verify-unit-test/internal-type-traits.test.cpp\"\
    \n//\n#line 2 \"hashmap/hashmap-unerasable.hpp\"\n\n#line 7 \"hashmap/hashmap-unerasable.hpp\"\
    \nusing namespace std;\n\n#line 2 \"internal/internal-hash-function.hpp\"\n\n\
    #line 4 \"internal/internal-hash-function.hpp\"\nusing namespace std;\n\n#line\
    \ 2 \"internal/internal-type-traits.hpp\"\n\n#line 4 \"internal/internal-type-traits.hpp\"\
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
    \n}  // namespace internal\n#line 8 \"internal/internal-hash-function.hpp\"\n\n\
    namespace internal {\n// \u6574\u6570, \u6574\u6570\u5217\u3092 64 bit unsigned\
    \ int \u3078\u79FB\u3059\n\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    \nENABLE_HAS_TYPE(first_type);\nENABLE_HAS_TYPE(second_type);\nENABLE_HAS_TYPE(iterator);\n\
    \ntemplate <typename T>\nu64 hash_function(const T& x) {\n  static u64 r = seed();\n\
    \  constexpr u64 z1 = 11995408973635179863ULL;\n  if constexpr (is_broadly_integral_v<T>)\
    \ {\n    // Integral\n    return (u64(x) ^ r) * z1;\n  } else if constexpr (has_first_type_v<T>\
    \ && has_second_type_v<T>) {\n    // pair\n    constexpr u64 z2 = 10150724397891781847ULL;\n\
    \    return hash_function(x.first) + hash_function(x.second) * z2;\n  } else if\
    \ constexpr (has_iterator_v<T>) {\n    // Container\n    constexpr u64 mod = (1LL\
    \ << 61) - 1;\n    constexpr u64 base = 950699498548472943ULL;\n    u64 m = 0;\n\
    \    for (auto& z : x) {\n      u64 w;\n      if constexpr (is_broadly_integral_v<T>)\
    \ {\n        w = u64(z) ^ r;\n      } else {\n        w = hash_function(z);\n\
    \      }\n      u128 y = u128(m) * base + (w & mod);\n      m = (y & mod) + (y\
    \ >> 61);\n      if (m >= mod) m -= mod;\n    }\n    m ^= m << 24, m ^= m >> 31,\
    \ m ^= m << 35;\n    return m;\n  } else {\n    static_assert([]() { return false;\
    \ }());\n  }\n}\n\ntemplate <typename Key>\nstruct HashObject {\n  size_t operator()(const\
    \ Key& x) const { return hash_function(x); }\n};\n\n}  // namespace internal\n\
    \n/*\n@brief \u30CF\u30C3\u30B7\u30E5\u95A2\u6570\n*/\n#line 10 \"hashmap/hashmap-unerasable.hpp\"\
    \n\n// \u524A\u9664\u4E0D\u53EF\u80FD\u306A hashmap\n//\n// \u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\u5F15\u6570\n// fixed_size : \u3053\u308C\u3092 true \u306B\
    \u3059\u308B\u3059\u308B\u3068\u30D0\u30B1\u30C3\u30C8\u30B5\u30A4\u30BA\u304C\
    \u56FA\u5B9A\u306B\u306A\u308B\n// get_hash : \u30CF\u30C3\u30B7\u30E5\u95A2\u6570\
    \u306E\u6307\u5B9A\n// \u5F15\u6570\n// _default_value : val \u306E\u521D\u671F\
    \u5024, \u3053\u306E\u5024\u3067\u521D\u671F\u5316\n// _default_size :\n// \u30D0\
    \u30B1\u30C3\u30C8\u30B5\u30A4\u30BA, max(4, _default_size) \u4EE5\u4E0A\u306E\
    \ 2 \u3079\u304D\u3067\u521D\u671F\u5316\n// \u305F\u3060\u3057 fixed_size \u304C\
    \ true \u306E\u6642\u306B\u3057\u304B\u30B5\u30A4\u30BA\u3092\u5909\u66F4\u3067\
    \u304D\u306A\u3044\n\ntemplate <typename Key, typename Val, bool fixed_size =\
    \ false,\n          unsigned long long (*get_hash)(const Key&) =\n           \
    \   internal::hash_function<Key>>\nstruct UnerasableHashMap {\n  int N, occupied_num,\
    \ shift;\n  vector<Key> keys;\n  vector<Val> vals;\n  vector<char> flag;\n\n \
    \ Val default_value;\n  int default_size;\n\n  // \u30B5\u30A4\u30BA\u3092 n \u306B\
    \u5909\u66F4\u3059\u308B\n  void init(int n, bool reset = false) {\n    assert(n\
    \ >= 4 && (n & (n - 1)) == 0);\n    if constexpr (fixed_size) {\n      assert(reset\
    \ == true);\n      n = N;\n    }\n    if (reset == true) {\n      N = n, occupied_num\
    \ = 0, shift = 64 - __builtin_ctz(n);\n      keys.resize(n);\n      vals.resize(n);\n\
    \      flag.resize(n);\n      fill(begin(vals), end(vals), default_value);\n \
    \     fill(begin(flag), end(flag), 0);\n    } else {\n      N = n, shift = 64\
    \ - __builtin_ctz(n);\n      vector<Key> keys2(n);\n      vector<Val> vals2(n,\
    \ default_value);\n      vector<char> flag2(n);\n      swap(keys, keys2), swap(vals,\
    \ vals2), swap(flag, flag2);\n      for (int i = 0; i < (int)flag2.size(); i++)\
    \ {\n        if (flag2[i]) {\n          int j = hint(keys2[i]);\n          keys[j]\
    \ = keys2[i], vals[j] = vals2[i], flag[j] = 1;\n        }\n      }\n    }\n  }\n\
    \n  UnerasableHashMap(const Val& _default_value = Val{}, int _default_size = 4)\n\
    \      : occupied_num(0), default_value(_default_value) {\n    if (fixed_size\
    \ == false) _default_size = 4;\n    N = 4;\n    while (N < _default_size) N *=\
    \ 2;\n    default_size = N;\n    init(N, true);\n  }\n\n  int hint(const Key&\
    \ k) {\n    int hash = get_hash(k) >> shift;\n    while (flag[hash] && keys[hash]\
    \ != k) hash = (hash + 1) & (N - 1);\n    return hash;\n  }\n\n  // key \u304C\
    \ i \u3067\u3042\u308B\u8981\u7D20\u3078\u306E\u53C2\u7167\u3092\u8FD4\u3059\n\
    \  Val& operator[](const Key& k) {\n    int i = hint(k);\n    if (!flag[i]) {\n\
    \      if constexpr (fixed_size == false) {\n        if (occupied_num * 2 >= N)\
    \ {\n          init(2 * N), i = hint(k);\n        }\n      }\n      keys[i] =\
    \ k, flag[i] = 1, occupied_num++;\n    }\n    return vals[i];\n  }\n\n  Val get(const\
    \ Key& k) {\n    int i = hint(k);\n    return flag[i] ? vals[i] : default_value;\n\
    \  }\n\n  // \u8D70\u67FB, f \u306B\u95A2\u6570 f(key, val) \u3092\u5165\u308C\
    \u308B\n  template <typename F>\n  void enumerate(const F f) {\n    for (int i\
    \ = 0; i < (int)flag.size(); i++) {\n      if (flag[i]) f(keys[i], vals[i]);\n\
    \    }\n  }\n\n  int count(const Key& k) { return flag[hint(k)]; }\n  bool contain(const\
    \ Key& k) { return flag[hint(k)]; }\n  int size() const { return occupied_num;\
    \ }\n  void reset() { init(default_size, true); }\n  void clear() { init(default_size,\
    \ true); }\n};\n#line 10 \"verify/verify-unit-test/internal-type-traits.test.cpp\"\
    \nusing namespace Nyaan;\n\ntemplate <typename T, bool low>\nT gen() {\n  if constexpr\
    \ (internal::is_broadly_integral_v<T>) {\n    if (low) return rng(0, 5);\n   \
    \ if constexpr (sizeof(T) == 16) {\n      return T(rng(0, TEN(18))) * TEN(18)\
    \ + rng(0, TEN(18));\n    } else {\n      return rng(0, numeric_limits<T>::max()\
    \ / 2);\n    }\n  } else if constexpr (internal::has_first_type_v<T> &&\n    \
    \                   internal::has_second_type_v<T>) {\n    return T{gen<decltype(T::first),\
    \ low>(), gen<decltype(T::second), low>()};\n  } else {\n    static_assert(internal::has_iterator_v<T>);\n\
    \    T t;\n    int n = rng(0, 10);\n    rep(_, n) t.push_back(gen<typename T::value_type,\
    \ low>());\n    return t;\n  }\n}\n\ntemplate <typename T, bool low>\nvoid test()\
    \ {\n  map<T, int> mp1;\n  UnerasableHashMap<T, int> mp2(-1);\n  assert(mp2.get(T{})\
    \ == -1);\n\n  rep(t, 3000) {\n    int cmd = rng(0, 1);\n    if (cmd == 0) {\n\
    \      T x = gen<T, low>();\n      mp1[x] = mp2[x] = t;\n    } else {\n      T\
    \ x = gen<T, low>();\n      int u = mp2.get(x);\n      int v = mp1.count(x) ?\
    \ mp1[x] : -1;\n      assert(u == v);\n    }\n    assert(sz(mp1) == sz(mp2));\n\
    \  }\n}\n\ntemplate <typename T>\nvoid test2() {\n  test<T, true>(), test<T, false>();\n\
    }\n\nvoid q() {\n  test2<char>();\n  test2<unsigned char>();\n  test2<short>();\n\
    \  test2<unsigned short>();\n  test2<int>();\n  test2<unsigned int>();\n  test2<long\
    \ long>();\n  test2<unsigned long long>();\n  test2<__int128_t>();\n  test2<__uint128_t>();\n\
    \n  test2<vector<int>>();\n\n  test2<pair<int, int>>();\n  test2<pair<__int128_t,\
    \ __int128_t>>();\n\n  test2<vvi>();\n  test2<VV<vvi>>();\n  test2<V<pl>>();\n\
    \  test2<pair<VV<pl>, V<pl>>>();\n  cerr << \"OK\" << endl;\n\n  int a, b;\n \
    \ cin >> a >> b;\n  cout << a + b << endl;\n}\n\nvoid Nyaan::solve() {\n  int\
    \ t = 1;\n  // in(t);\n  while (t--) q();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../misc/rng.hpp\"\n//\n#include\
    \ \"../../hashmap/hashmap-unerasable.hpp\"\n#include \"../../internal/internal-hash-function.hpp\"\
    \n#include \"../../internal/internal-type-traits.hpp\"\nusing namespace Nyaan;\n\
    \ntemplate <typename T, bool low>\nT gen() {\n  if constexpr (internal::is_broadly_integral_v<T>)\
    \ {\n    if (low) return rng(0, 5);\n    if constexpr (sizeof(T) == 16) {\n  \
    \    return T(rng(0, TEN(18))) * TEN(18) + rng(0, TEN(18));\n    } else {\n  \
    \    return rng(0, numeric_limits<T>::max() / 2);\n    }\n  } else if constexpr\
    \ (internal::has_first_type_v<T> &&\n                       internal::has_second_type_v<T>)\
    \ {\n    return T{gen<decltype(T::first), low>(), gen<decltype(T::second), low>()};\n\
    \  } else {\n    static_assert(internal::has_iterator_v<T>);\n    T t;\n    int\
    \ n = rng(0, 10);\n    rep(_, n) t.push_back(gen<typename T::value_type, low>());\n\
    \    return t;\n  }\n}\n\ntemplate <typename T, bool low>\nvoid test() {\n  map<T,\
    \ int> mp1;\n  UnerasableHashMap<T, int> mp2(-1);\n  assert(mp2.get(T{}) == -1);\n\
    \n  rep(t, 3000) {\n    int cmd = rng(0, 1);\n    if (cmd == 0) {\n      T x =\
    \ gen<T, low>();\n      mp1[x] = mp2[x] = t;\n    } else {\n      T x = gen<T,\
    \ low>();\n      int u = mp2.get(x);\n      int v = mp1.count(x) ? mp1[x] : -1;\n\
    \      assert(u == v);\n    }\n    assert(sz(mp1) == sz(mp2));\n  }\n}\n\ntemplate\
    \ <typename T>\nvoid test2() {\n  test<T, true>(), test<T, false>();\n}\n\nvoid\
    \ q() {\n  test2<char>();\n  test2<unsigned char>();\n  test2<short>();\n  test2<unsigned\
    \ short>();\n  test2<int>();\n  test2<unsigned int>();\n  test2<long long>();\n\
    \  test2<unsigned long long>();\n  test2<__int128_t>();\n  test2<__uint128_t>();\n\
    \n  test2<vector<int>>();\n\n  test2<pair<int, int>>();\n  test2<pair<__int128_t,\
    \ __int128_t>>();\n\n  test2<vvi>();\n  test2<VV<vvi>>();\n  test2<V<pl>>();\n\
    \  test2<pair<VV<pl>, V<pl>>>();\n  cerr << \"OK\" << endl;\n\n  int a, b;\n \
    \ cin >> a >> b;\n  cout << a + b << endl;\n}\n\nvoid Nyaan::solve() {\n  int\
    \ t = 1;\n  // in(t);\n  while (t--) q();\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - misc/rng.hpp
  - internal/internal-seed.hpp
  - hashmap/hashmap-unerasable.hpp
  - internal/internal-hash-function.hpp
  - internal/internal-type-traits.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/internal-type-traits.test.cpp
  requiredBy: []
  timestamp: '2023-08-27 10:14:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/internal-type-traits.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/internal-type-traits.test.cpp
- /verify/verify/verify-unit-test/internal-type-traits.test.cpp.html
title: verify/verify-unit-test/internal-type-traits.test.cpp
---
