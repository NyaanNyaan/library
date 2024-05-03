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
    path: math/bigint-gcd.hpp
    title: math/bigint-gcd.hpp
  - icon: ':heavy_check_mark:'
    path: math/bigint-rational.hpp
    title: math/bigint-rational.hpp
  - icon: ':heavy_check_mark:'
    path: math/bigint.hpp
    title: "\u591A\u500D\u9577\u6574\u6570"
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
  bundledCode: "#line 1 \"verify/verify-unit-test/bigrational.test.cpp\"\n#define\
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
    \ T>\nbool nxp(T &v) {\n  return next_permutation(begin(v), end(v));\n}\n\n//\
    \ \u8FD4\u308A\u5024\u306E\u578B\u306F\u5165\u529B\u306E T \u306B\u4F9D\u5B58\n\
    // i \u8981\u7D20\u76EE : [0, a[i])\ntemplate <typename T>\nvector<vector<T>>\
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
    \u308B\ntemplate <typename T>\nT Power(T a, long long n, const T &I = T{1}) {\n\
    \  return Power(a, n, I, function<void(T &)>{[](T &) -> void {}});\n}\n\ntemplate\
    \ <typename T>\nT Rev(const T &v) {\n  T res = v;\n  reverse(begin(res), end(res));\n\
    \  return res;\n}\n\ntemplate <typename T>\nvector<T> Transpose(const vector<T>\
    \ &v) {\n  using U = typename T::value_type;\n  if(v.empty()) return {};\n  int\
    \ H = v.size(), W = v[0].size();\n  vector res(W, T(H, U{}));\n  for (int i =\
    \ 0; i < H; i++) {\n    for (int j = 0; j < W; j++) {\n      res[j][i] = v[i][j];\n\
    \    }\n  }\n  return res;\n}\n\ntemplate <typename T>\nvector<T> Rotate(const\
    \ vector<T> &v, int clockwise = true) {\n  using U = typename T::value_type;\n\
    \  int H = v.size(), W = v[0].size();\n  vector res(W, T(H, U{}));\n  for (int\
    \ i = 0; i < H; i++) {\n    for (int j = 0; j < W; j++) {\n      if (clockwise)\
    \ {\n        res[W - 1 - j][i] = v[i][j];\n      } else {\n        res[j][H -\
    \ 1 - i] = v[i][j];\n      }\n    }\n  }\n  return res;\n}\n\n}  // namespace\
    \ Nyaan\n#line 58 \"template/template.hpp\"\n\n// bit operation\n#line 1 \"template/bitop.hpp\"\
    \nnamespace Nyaan {\n__attribute__((target(\"popcnt\"))) inline int popcnt(const\
    \ u64 &a) {\n  return __builtin_popcountll(a);\n}\ninline int lsb(const u64 &a)\
    \ { return a ? __builtin_ctzll(a) : 64; }\ninline int ctz(const u64 &a) { return\
    \ a ? __builtin_ctzll(a) : 64; }\ninline int msb(const u64 &a) { return a ? 63\
    \ - __builtin_clzll(a) : -1; }\ntemplate <typename T>\ninline int gbit(const T\
    \ &a, int i) {\n  return (a >> i) & 1;\n}\ntemplate <typename T>\ninline void\
    \ sbit(T &a, int i, bool b) {\n  if (gbit(a, i) != b) a ^= T(1) << i;\n}\nconstexpr\
    \ long long PW(int n) { return 1LL << n; }\nconstexpr long long MSK(int n) { return\
    \ (1LL << n) - 1; }\n}  // namespace Nyaan\n#line 61 \"template/template.hpp\"\
    \n\n// inout\n#line 1 \"template/inout.hpp\"\nnamespace Nyaan {\n\ntemplate <typename\
    \ T, typename U>\nostream &operator<<(ostream &os, const pair<T, U> &p) {\n  os\
    \ << p.first << \" \" << p.second;\n  return os;\n}\ntemplate <typename T, typename\
    \ U>\nistream &operator>>(istream &is, pair<T, U> &p) {\n  is >> p.first >> p.second;\n\
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
    \ \" \";\n  dump(head);\n  if (sizeof...(tail) != 0) cerr << \",\";\n  trace(std::forward<Tail>(tail)...);\n\
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
    \ 4 \"verify/verify-unit-test/bigrational.test.cpp\"\n//\n#line 2 \"math/rational-binomial.hpp\"\
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
    \  }\n};\n#line 8 \"verify/verify-unit-test/bigrational.test.cpp\"\n//\n#line\
    \ 2 \"math/bigint-rational.hpp\"\n\n#line 2 \"math/bigint-gcd.hpp\"\n\n#line 4\
    \ \"math/bigint-gcd.hpp\"\nusing namespace std;\n\n#line 2 \"math/bigint.hpp\"\
    \n\n#line 10 \"math/bigint.hpp\"\nusing namespace std;\n\n#line 2 \"ntt/arbitrary-ntt.hpp\"\
    \n\n#line 2 \"modint/montgomery-modint.hpp\"\n\ntemplate <uint32_t mod>\nstruct\
    \ LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n  using i32 =\
    \ int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr\
    \ u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i < 4; ++i) ret *= 2\
    \ - mod * ret;\n    return ret;\n  }\n\n  static constexpr u32 r = get_r();\n\
    \  static constexpr u32 n2 = -u64(mod) % mod;\n  static_assert(mod < (1 << 30),\
    \ \"invalid, mod >= 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"invalid, mod\
    \ % 2 == 0\");\n  static_assert(r * mod == 1, \"this code has bugs.\");\n\n  u32\
    \ a;\n\n  constexpr LazyMontgomeryModInt() : a(0) {}\n  constexpr LazyMontgomeryModInt(const\
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
    \    setwy(k);\n    vector<mint> s(M);\n    for (int i = 0; i < (int)a.size();\
    \ ++i) s[i] = a[i];\n    fft4(s, k);\n    if (a.size() == b.size() && a == b)\
    \ {\n      for (int i = 0; i < M; ++i) s[i] *= s[i];\n    } else {\n      vector<mint>\
    \ t(M);\n      for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i];\n      fft4(t,\
    \ k);\n      for (int i = 0; i < M; ++i) s[i] *= t[i];\n    }\n    ifft4(s, k);\n\
    \    s.resize(l);\n    mint invm = mint(M).inverse();\n    for (int i = 0; i <\
    \ l; ++i) s[i] *= invm;\n    return s;\n  }\n\n  void ntt_doubling(vector<mint>\
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
    \ * w2;\n  }\n  return ret;\n}\n}  // namespace ArbitraryNTT\n#line 14 \"math/bigint.hpp\"\
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
    \ dat(d) {}\n\n  template <typename I,\n            enable_if_t<internal::is_broadly_integral_v<I>>*\
    \ = nullptr>\n  MultiPrecisionInteger(I x) : neg(false) {\n    if constexpr (internal::is_broadly_signed_v<I>)\
    \ {\n      if (x < 0) neg = true, x = -x;\n    }\n    while (x) dat.push_back(x\
    \ % D), x /= D;\n  }\n\n  MultiPrecisionInteger(const string& S) : neg(false)\
    \ {\n    assert(!S.empty());\n    if (S.size() == 1u && S[0] == '0') return;\n\
    \    int l = 0;\n    if (S[0] == '-') ++l, neg = true;\n    for (int ie = S.size();\
    \ l < ie; ie -= logD) {\n      int is = max(l, ie - logD);\n      long long x\
    \ = 0;\n      for (int i = is; i < ie; i++) x = x * 10 + S[i] - '0';\n      dat.push_back(x);\n\
    \    }\n    while(!dat.empty() and dat.back() == 0) dat.pop_back();\n  }\n\n \
    \ friend M operator+(const M& lhs, const M& rhs) {\n    if (lhs.neg == rhs.neg)\
    \ return {lhs.neg, _add(lhs.dat, rhs.dat)};\n    if (_leq(lhs.dat, rhs.dat)) {\n\
    \      // |l| <= |r|\n      auto c = _sub(rhs.dat, lhs.dat);\n      bool n = _is_zero(c)\
    \ ? false : rhs.neg;\n      return {n, c};\n    }\n    auto c = _sub(lhs.dat,\
    \ rhs.dat);\n    bool n = _is_zero(c) ? false : lhs.neg;\n    return {n, c};\n\
    \  }\n  friend M operator-(const M& lhs, const M& rhs) { return lhs + (-rhs);\
    \ }\n\n  friend M operator*(const M& lhs, const M& rhs) {\n    auto c = _mul(lhs.dat,\
    \ rhs.dat);\n    bool n = _is_zero(c) ? false : (lhs.neg ^ rhs.neg);\n    return\
    \ {n, c};\n  }\n  friend pair<M, M> divmod(const M& lhs, const M& rhs) {\n   \
    \ auto dm = _divmod_newton(lhs.dat, rhs.dat);\n    bool dn = _is_zero(dm.first)\
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
    \ I,\n            enable_if_t<internal::is_broadly_integral_v<I>>* = nullptr>\n\
    \  static vector<int> _integer_to_vec(I x) {\n    if constexpr (internal::is_broadly_signed_v<I>)\
    \ {\n      assert(x >= 0);\n    }\n    vector<int> res;\n    while (x) res.push_back(x\
    \ % D), x /= D;\n    return res;\n  }\n\n  static long long _to_ll(const vector<int>&\
    \ a) {\n    long long res = 0;\n    for (int i = (int)a.size() - 1; i >= 0; i--)\
    \ res = res * D + a[i];\n    return res;\n  }\n\n  static __int128_t _to_i128(const\
    \ vector<int>& a) {\n    __int128_t res = 0;\n    for (int i = (int)a.size() -\
    \ 1; i >= 0; i--) res = res * D + a[i];\n    return res;\n  }\n\n  static void\
    \ _dump(const vector<int>& a, string s = \"\") {\n    if (!s.empty()) cerr <<\
    \ s << \" : \";\n    cerr << \"{ \";\n    for (int i = 0; i < (int)a.size(); i++)\
    \ cerr << a[i] << \", \";\n    cerr << \"}\" << endl;\n  }\n};\n\nusing bigint\
    \ = MultiPrecisionInteger;\n\n/**\n * @brief \u591A\u500D\u9577\u6574\u6570\n\
    \ */\n#line 8 \"math/bigint-gcd.hpp\"\n\nnamespace GCDforBigintImpl {\n\nbigint\
    \ bigint_pow(bigint a, long long k) {\n  if (k == 0) return 1;\n  bigint half\
    \ = bigint_pow(a, k / 2);\n  bigint res = half * half;\n  return k % 2 ? res *\
    \ a : res;\n}\n\n// a = 2^x 5^y \u306E\u5F62\u3067\u8868\u73FE\u3059\u308B\npair<int,\
    \ int> shrink(int a) {\n  assert(a > 0);\n  int x = __builtin_ctz(a);\n  a >>=\
    \ x;\n  int y = a == 1        ? 0\n          : a == 5      ? 1\n          : a\
    \ == 25     ? 2\n          : a == 125    ? 3\n          : a == 625    ? 4\n  \
    \        : a == 3125   ? 5\n          : a == 15625  ? 6\n          : a == 78125\
    \  ? 7\n          : a == 390625 ? 8\n                        : 9;\n  return {x,\
    \ y};\n}\n\npair<int, int> shrink(bigint& a) {\n  assert(a.neg == false);\n  if\
    \ (a.dat.empty()) return {0, 0};\n  pair<int, int> res{0, 0};\n  while (true)\
    \ {\n    int g = gcd(bigint::D, a.dat[0]);\n    if (g == 1) break;\n    if (g\
    \ != bigint::D) a *= bigint::D / g;\n    a.dat.erase(begin(a.dat));\n    auto\
    \ s = shrink(g);\n    res.first += s.first, res.second += s.second;\n  }\n  return\
    \ res;\n}\n\ntemplate <bool FAST = false>\nbigint gcd_d_ary(bigint a, bigint b)\
    \ {\n  a.neg = b.neg = false;\n  if constexpr (FAST) {\n    if (max<int>(a.dat.size(),\
    \ b.dat.size()) <= 4) {\n      return __int128_t(BinaryGCDImpl::binary_gcd128(a.to_i128(),\
    \ b.to_i128()));\n    }\n  }\n  if (a.dat.empty()) return b;\n  if (b.dat.empty())\
    \ return a;\n  pair<int, int> s = shrink(a), t = shrink(b);\n  if (a < b) swap(a,\
    \ b);\n  while (true) {\n    if (b.dat.empty()) break;\n    if constexpr (FAST)\
    \ {\n      if ((int)a.dat.size() <= 4) break;\n    }\n    a = a - b;\n    if (!a.dat.empty())\
    \ {\n      while ((a.dat[0] & 1) == 0) {\n        int m = a.dat[0] ? __builtin_ctz(a.dat[0])\
    \ : 32;\n        m = min(m, bigint::logD);\n        int mask = (1 << m) - 1, prod\
    \ = bigint::D >> m;\n        a.dat[0] >>= m;\n        for (int i = 1; i < (int)a.dat.size();\
    \ i++) {\n          a.dat[i - 1] += prod * (a.dat[i] & mask);\n          a.dat[i]\
    \ >>= m;\n        }\n        if (a.dat.back() == 0) a.dat.pop_back();\n      }\n\
    \    }\n    if (a < b) swap(a, b);\n  }\n  assert(a >= b);\n  bigint g;\n  if\
    \ constexpr (FAST) {\n    if (b.dat.empty()) {\n      g = a;\n    } else {\n \
    \     g = __int128_t(BinaryGCDImpl::binary_gcd128(a.to_i128(), b.to_i128()));\n\
    \    }\n  } else {\n    g = a;\n  }\n  int e2 = min(s.first, t.first);\n  int\
    \ e5 = min(s.second, t.second);\n  if (e2) g *= bigint_pow(bigint{2}, e2);\n \
    \ if (e5) g *= bigint_pow(bigint{5}, e5);\n  return g;\n}\n}  // namespace GCDforBigintImpl\n\
    \nMultiPrecisionInteger gcd(const MultiPrecisionInteger& a,\n                \
    \          const MultiPrecisionInteger& b) {\n  return GCDforBigintImpl::gcd_d_ary<true>(a,\
    \ b);\n}\n\nMultiPrecisionInteger lcm(const MultiPrecisionInteger& a,\n      \
    \                    const MultiPrecisionInteger& b) {\n  return a / gcd(a, b)\
    \ * b;\n}\n#line 5 \"math/bigint-rational.hpp\"\n\nusing BigRational = RationalBase<bigint,\
    \ bigint>;\n\ndouble to_double(const BigRational& r) {\n  pair<long double, int>\
    \ a = r.x.dfp();\n  pair<long double, int> b = r.y.dfp();\n  return a.first /\
    \ b.first * powl(10.0, a.second - b.second);\n}\n#line 10 \"verify/verify-unit-test/bigrational.test.cpp\"\
    \n//\n#line 2 \"modulo/binomial.hpp\"\n\n#line 6 \"modulo/binomial.hpp\"\nusing\
    \ namespace std;\n\n// \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306E MAX \u306B\
    \ \u300CC(n, r) \u3084 fac(n) \u3067\u30AF\u30A8\u30EA\u3092\u6295\u3052\u308B\
    \u6700\u5927\u306E n \u300D\n// \u3092\u5165\u308C\u308B\u3068\u500D\u901F\u304F\
    \u3089\u3044\u306B\u306A\u308B\n// mod \u3092\u8D85\u3048\u3066\u524D\u8A08\u7B97\
    \u3057\u3066 0 \u5272\u308A\u3092\u8E0F\u3080\u30D0\u30B0\u306F\u5BFE\u7B56\u6E08\
    \u307F\ntemplate <typename T>\nstruct Binomial {\n  vector<T> f, g, h;\n  Binomial(int\
    \ MAX = 0) {\n    assert(T::get_mod() != 0 && \"Binomial<mint>()\");\n    f.resize(1,\
    \ T{1});\n    g.resize(1, T{1});\n    h.resize(1, T{1});\n    if (MAX > 0) extend(MAX\
    \ + 1);\n  }\n\n  void extend(int m = -1) {\n    int n = f.size();\n    if (m\
    \ == -1) m = n * 2;\n    m = min<int>(m, T::get_mod());\n    if (n >= m) return;\n\
    \    f.resize(m);\n    g.resize(m);\n    h.resize(m);\n    for (int i = n; i <\
    \ m; i++) f[i] = f[i - 1] * T(i);\n    g[m - 1] = f[m - 1].inverse();\n    h[m\
    \ - 1] = g[m - 1] * f[m - 2];\n    for (int i = m - 2; i >= n; i--) {\n      g[i]\
    \ = g[i + 1] * T(i + 1);\n      h[i] = g[i] * f[i - 1];\n    }\n  }\n\n  T fac(int\
    \ i) {\n    if (i < 0) return T(0);\n    while (i >= (int)f.size()) extend();\n\
    \    return f[i];\n  }\n\n  T finv(int i) {\n    if (i < 0) return T(0);\n   \
    \ while (i >= (int)g.size()) extend();\n    return g[i];\n  }\n\n  T inv(int i)\
    \ {\n    if (i < 0) return -inv(-i);\n    while (i >= (int)h.size()) extend();\n\
    \    return h[i];\n  }\n\n  T C(int n, int r) {\n    if (n < 0 || n < r || r <\
    \ 0) return T(0);\n    return fac(n) * finv(n - r) * finv(r);\n  }\n\n  inline\
    \ T operator()(int n, int r) { return C(n, r); }\n\n  template <typename I>\n\
    \  T multinomial(const vector<I>& r) {\n    static_assert(is_integral<I>::value\
    \ == true);\n    int n = 0;\n    for (auto& x : r) {\n      if (x < 0) return\
    \ T(0);\n      n += x;\n    }\n    T res = fac(n);\n    for (auto& x : r) res\
    \ *= finv(x);\n    return res;\n  }\n\n  template <typename I>\n  T operator()(const\
    \ vector<I>& r) {\n    return multinomial(r);\n  }\n\n  T C_naive(int n, int r)\
    \ {\n    if (n < 0 || n < r || r < 0) return T(0);\n    T ret = T(1);\n    r =\
    \ min(r, n - r);\n    for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);\n  \
    \  return ret;\n  }\n\n  T P(int n, int r) {\n    if (n < 0 || n < r || r < 0)\
    \ return T(0);\n    return fac(n) * finv(n - r);\n  }\n\n  // [x^r] 1 / (1-x)^n\n\
    \  T H(int n, int r) {\n    if (n < 0 || r < 0) return T(0);\n    return r ==\
    \ 0 ? 1 : C(n + r - 1, r);\n  }\n};\n#line 13 \"verify/verify-unit-test/bigrational.test.cpp\"\
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
    using my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n#line 16 \"\
    verify/verify-unit-test/bigrational.test.cpp\"\n\nusing namespace Nyaan;\n\nvoid\
    \ Nyaan::solve() {\n  {\n    BigRational a{4, 3}, b{2, 3};\n    assert(a + b ==\
    \ 2);\n    assert(a - b == BigRational(2, 3));\n    assert(a * b == BigRational(8,\
    \ 9));\n    assert(a / b == 2);\n    assert(a.inverse() == BigRational(3, 4));\n\
    \    assert(a.pow(3) == BigRational(64, 27));\n\n    assert((a > b) == true);\n\
    \    assert((a >= b) == true);\n    assert((a < b) == false);\n    assert((a <=\
    \ b) == false);\n  }\n\n  {\n    Binomial_rational<BigRational> C;\n    assert(C.fac(3)\
    \ == 6);\n    assert(C.finv(3) == BigRational(1, 6));\n    assert(C(4, 2) == 6);\n\
    \    assert(C(vi{3, 2}) == 10);\n  }\n\n  {\n    using fps = FormalPowerSeries_rational<BigRational>;\n\
    \    {\n      fps f{1, 2, {3, 2}}, g{{1, 4}, 5};\n      fps h{{5, 4}, 7, {3, 2}};\n\
    \      assert(f + g == h);\n      h = fps{{3, 4}, -3, {3, 2}};\n      assert(f\
    \ - g == h);\n      assert(f * g % g == fps{});\n      assert(f * g % f == fps{});\n\
    \    }\n\n    {\n      fps e{1, 1, {1, 2}, {1, 6}, {1, 24}, {1, 120}};\n     \
    \ fps f = e.pow(TEN(10));\n      trc(f);\n      rep(i, sz(e)) { assert(e[i] *\
    \ BigRational{TEN(10)}.pow(i) == f[i]); }\n    }\n  }\n\n  // mint \u3068\u6319\
    \u52D5\u306E\u6BD4\u8F03\n  {\n    auto comp = [&](int i, int j, int k, int l)\
    \ {\n      rep(b, 16) {\n        int ii = (b >> 0) % 2 ? -i : +i;\n        int\
    \ jj = (b >> 1) % 2 ? -j : +j;\n        int kk = (b >> 2) % 2 ? -k : +k;\n   \
    \     int ll = (b >> 3) % 2 ? -l : +l;\n        BigRational x{ii, jj}, y{kk, ll};\n\
    \        mint X = mint{ii} / jj;\n        mint Y = mint{kk} / ll;\n        assert(X\
    \ + Y == (x + y).to_mint(998244353).to_ll());\n        assert(X - Y == (x - y).to_mint(998244353).to_ll());\n\
    \        assert(X * Y == (x * y).to_mint(998244353).to_ll());\n        if (Y !=\
    \ 0) {\n          assert(X / Y == (x / y).to_mint(998244353).to_ll());\n     \
    \   }\n      }\n    };\n    rep(i, 10) rep1(j, 10) rep(k, 10) rep1(l, 10) comp(i,\
    \ j, k, l);\n    rep(t, 1000) {\n      ll lower = t % 2 ? 1 : TEN(17);\n     \
    \ ll i = rng(lower, TEN(18));\n      ll j = rng(lower, TEN(18));\n      ll k =\
    \ rng(lower, TEN(18));\n      ll l = rng(lower, TEN(18));\n      comp(i, j, k,\
    \ l);\n    }\n  }\n\n  // binom, mint \u3068\u6319\u52D5\u306E\u6BD4\u8F03\n \
    \ {\n    Binomial_rational<BigRational> C1;\n    Binomial<mint> C2;\n    reg(i,\
    \ -15, 15) {\n      assert(C2.fac(i) == C1.fac(i).to_mint(998244353).to_ll());\n\
    \      assert(C2.finv(i) == C1.finv(i).to_mint(998244353).to_ll());\n      assert(C2.inv(i)\
    \ == C1.inv(i).to_mint(998244353).to_ll());\n      reg(j, -15, 15) assert(C2(i,\
    \ j) == C1(i, j).to_mint(998244353).to_ll());\n    }\n  }\n\n  cerr << \"OK\"\
    \ << endl;\n  {\n    int s, t;\n    cin >> s >> t;\n    cout << s + t << \"\\\
    n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../template/template.hpp\"\n//\n#include \"../../math/rational-binomial.hpp\"\
    \n#include \"../../math/rational-fps.hpp\"\n#include \"../../math/rational.hpp\"\
    \n//\n#include \"../../math/bigint-rational.hpp\"\n//\n#include \"../../modint/montgomery-modint.hpp\"\
    \n#include \"../../modulo/binomial.hpp\"\nusing mint = LazyMontgomeryModInt<998244353>;\n\
    //\n#include \"../../misc/rng.hpp\"\n\nusing namespace Nyaan;\n\nvoid Nyaan::solve()\
    \ {\n  {\n    BigRational a{4, 3}, b{2, 3};\n    assert(a + b == 2);\n    assert(a\
    \ - b == BigRational(2, 3));\n    assert(a * b == BigRational(8, 9));\n    assert(a\
    \ / b == 2);\n    assert(a.inverse() == BigRational(3, 4));\n    assert(a.pow(3)\
    \ == BigRational(64, 27));\n\n    assert((a > b) == true);\n    assert((a >= b)\
    \ == true);\n    assert((a < b) == false);\n    assert((a <= b) == false);\n \
    \ }\n\n  {\n    Binomial_rational<BigRational> C;\n    assert(C.fac(3) == 6);\n\
    \    assert(C.finv(3) == BigRational(1, 6));\n    assert(C(4, 2) == 6);\n    assert(C(vi{3,\
    \ 2}) == 10);\n  }\n\n  {\n    using fps = FormalPowerSeries_rational<BigRational>;\n\
    \    {\n      fps f{1, 2, {3, 2}}, g{{1, 4}, 5};\n      fps h{{5, 4}, 7, {3, 2}};\n\
    \      assert(f + g == h);\n      h = fps{{3, 4}, -3, {3, 2}};\n      assert(f\
    \ - g == h);\n      assert(f * g % g == fps{});\n      assert(f * g % f == fps{});\n\
    \    }\n\n    {\n      fps e{1, 1, {1, 2}, {1, 6}, {1, 24}, {1, 120}};\n     \
    \ fps f = e.pow(TEN(10));\n      trc(f);\n      rep(i, sz(e)) { assert(e[i] *\
    \ BigRational{TEN(10)}.pow(i) == f[i]); }\n    }\n  }\n\n  // mint \u3068\u6319\
    \u52D5\u306E\u6BD4\u8F03\n  {\n    auto comp = [&](int i, int j, int k, int l)\
    \ {\n      rep(b, 16) {\n        int ii = (b >> 0) % 2 ? -i : +i;\n        int\
    \ jj = (b >> 1) % 2 ? -j : +j;\n        int kk = (b >> 2) % 2 ? -k : +k;\n   \
    \     int ll = (b >> 3) % 2 ? -l : +l;\n        BigRational x{ii, jj}, y{kk, ll};\n\
    \        mint X = mint{ii} / jj;\n        mint Y = mint{kk} / ll;\n        assert(X\
    \ + Y == (x + y).to_mint(998244353).to_ll());\n        assert(X - Y == (x - y).to_mint(998244353).to_ll());\n\
    \        assert(X * Y == (x * y).to_mint(998244353).to_ll());\n        if (Y !=\
    \ 0) {\n          assert(X / Y == (x / y).to_mint(998244353).to_ll());\n     \
    \   }\n      }\n    };\n    rep(i, 10) rep1(j, 10) rep(k, 10) rep1(l, 10) comp(i,\
    \ j, k, l);\n    rep(t, 1000) {\n      ll lower = t % 2 ? 1 : TEN(17);\n     \
    \ ll i = rng(lower, TEN(18));\n      ll j = rng(lower, TEN(18));\n      ll k =\
    \ rng(lower, TEN(18));\n      ll l = rng(lower, TEN(18));\n      comp(i, j, k,\
    \ l);\n    }\n  }\n\n  // binom, mint \u3068\u6319\u52D5\u306E\u6BD4\u8F03\n \
    \ {\n    Binomial_rational<BigRational> C1;\n    Binomial<mint> C2;\n    reg(i,\
    \ -15, 15) {\n      assert(C2.fac(i) == C1.fac(i).to_mint(998244353).to_ll());\n\
    \      assert(C2.finv(i) == C1.finv(i).to_mint(998244353).to_ll());\n      assert(C2.inv(i)\
    \ == C1.inv(i).to_mint(998244353).to_ll());\n      reg(j, -15, 15) assert(C2(i,\
    \ j) == C1(i, j).to_mint(998244353).to_ll());\n    }\n  }\n\n  cerr << \"OK\"\
    \ << endl;\n  {\n    int s, t;\n    cin >> s >> t;\n    cout << s + t << \"\\\
    n\";\n  }\n}\n"
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
  - math/bigint-rational.hpp
  - math/bigint-gcd.hpp
  - math/bigint.hpp
  - ntt/arbitrary-ntt.hpp
  - modint/montgomery-modint.hpp
  - ntt/ntt.hpp
  - modulo/binomial.hpp
  - misc/rng.hpp
  - internal/internal-seed.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/bigrational.test.cpp
  requiredBy: []
  timestamp: '2024-05-03 23:21:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/bigrational.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/bigrational.test.cpp
- /verify/verify/verify-unit-test/bigrational.test.cpp.html
title: verify/verify-unit-test/bigrational.test.cpp
---
