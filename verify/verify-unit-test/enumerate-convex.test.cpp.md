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
    path: math/enumerate-convex.hpp
    title: math/enumerate-convex.hpp
  - icon: ':heavy_check_mark:'
    path: math/gaussian-integer.hpp
    title: math/gaussian-integer.hpp
  - icon: ':heavy_check_mark:'
    path: math/isqrt.hpp
    title: math/isqrt.hpp
  - icon: ':heavy_check_mark:'
    path: math/stern-brocot-tree.hpp
    title: Stern-Brocot Tree
  - icon: ':heavy_check_mark:'
    path: math/two-square.hpp
    title: math/two-square.hpp
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: modint/arbitrary-montgomery-modint.hpp
    title: modint/arbitrary-montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: prime/fast-factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)"
  - icon: ':heavy_check_mark:'
    path: prime/miller-rabin.hpp
    title: Miller-Rabin primality test
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
  bundledCode: "#line 1 \"verify/verify-unit-test/enumerate-convex.test.cpp\"\n#define\
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
    \ 4 \"verify/verify-unit-test/enumerate-convex.test.cpp\"\n//\n#line 2 \"math/enumerate-convex.hpp\"\
    \n\n#line 6 \"math/enumerate-convex.hpp\"\nusing namespace std;\n\n#line 2 \"\
    math/stern-brocot-tree.hpp\"\n\n#line 6 \"math/stern-brocot-tree.hpp\"\nusing\
    \ namespace std;\n\n// x / y (x > 0, y > 0) \u3092\u7BA1\u7406\u3001\u30C7\u30D5\
    \u30A9\u30EB\u30C8\u3067 1 / 1\n// \u5165\u529B\u304C\u4E92\u3044\u306B\u7D20\u3067\
    \u306A\u3044\u5834\u5408\u306F gcd \u3092\u53D6\u3063\u3066\u683C\u7D0D\n// seq\
    \ : (1, 1) \u304B\u3089 (x, y) \u3078\u306E\u30D1\u30B9\u3002\u53F3\u306E\u5B50\
    \u304C\u6B63/\u5DE6\u306E\u5B50\u304C\u8CA0\ntemplate <typename Int>\nstruct SternBrocotTreeNode\
    \ {\n  using Node = SternBrocotTreeNode;\n\n  Int lx, ly, x, y, rx, ry;\n  vector<Int>\
    \ seq;\n\n  SternBrocotTreeNode() : lx(0), ly(1), x(1), y(1), rx(1), ry(0) {}\n\
    \n  SternBrocotTreeNode(Int X, Int Y) : SternBrocotTreeNode() {\n    assert(1\
    \ <= X && 1 <= Y);\n    Int g = gcd(X, Y);\n    X /= g, Y /= g;\n    while (min(X,\
    \ Y) > 0) {\n      if (X > Y) {\n        Int d = X / Y;\n        X -= d * Y;\n\
    \        go_right(d - (X == 0 ? 1 : 0));\n      } else {\n        Int d = Y /\
    \ X;\n        Y -= d * X;\n        go_left(d - (Y == 0 ? 1 : 0));\n      }\n \
    \   }\n  }\n  SternBrocotTreeNode(const pair<Int, Int> &xy)\n      : SternBrocotTreeNode(xy.first,\
    \ xy.second) {}\n  SternBrocotTreeNode(const vector<Int> &_seq) : SternBrocotTreeNode()\
    \ {\n    for (const Int &d : _seq) {\n      assert(d != 0);\n      if (d > 0)\
    \ go_right(d);\n      if (d < 0) go_left(d);\n    }\n    assert(seq == _seq);\n\
    \  }\n\n  // pair<Int, Int> \u578B\u3067\u5206\u6570\u3092 get\n  pair<Int, Int>\
    \ get() const { return make_pair(x, y); }\n  // \u533A\u9593\u306E\u4E0B\u9650\
    \n  pair<Int, Int> lower_bound() const { return make_pair(lx, ly); }\n  // \u533A\
    \u9593\u306E\u4E0A\u9650\n  pair<Int, Int> upper_bound() const { return make_pair(rx,\
    \ ry); }\n\n  // \u6839\u304B\u3089\u306E\u6DF1\u3055\n  Int depth() const {\n\
    \    Int res = 0;\n    for (auto &s : seq) res += abs(s);\n    return res;\n \
    \ }\n  // \u5DE6\u306E\u5B50\u306B d \u9032\u3080\n  void go_left(Int d = 1) {\n\
    \    if (d <= 0) return;\n    if (seq.empty() or seq.back() > 0) seq.push_back(0);\n\
    \    seq.back() -= d;\n    rx += lx * d, ry += ly * d;\n    x = rx + lx, y = ry\
    \ + ly;\n  }\n  // \u53F3\u306E\u5B50\u306B d \u9032\u3080\n  void go_right(Int\
    \ d = 1) {\n    if (d <= 0) return;\n    if (seq.empty() or seq.back() < 0) seq.push_back(0);\n\
    \    seq.back() += d;\n    lx += rx * d, ly += ry * d;\n    x = rx + lx, y = ry\
    \ + ly;\n  }\n  // \u89AA\u306E\u65B9\u5411\u306B d \u9032\u3080\n  // d \u9032\
    \u3081\u305F\u3089 true, \u9032\u3081\u306A\u304B\u3063\u305F\u3089 false \u3092\
    \u8FD4\u3059\n  bool go_parent(Int d = 1) {\n    if (d <= 0) return true;\n  \
    \  while (d != 0) {\n      if (seq.empty()) return false;\n      Int d2 = min(d,\
    \ abs(seq.back()));\n      if (seq.back() > 0) {\n        x -= rx * d2, y -= ry\
    \ * d2;\n        lx = x - rx, ly = y - ry;\n        seq.back() -= d2;\n      }\
    \ else {\n        x -= lx * d2, y -= ly * d2;\n        rx = x - lx, ry = y - ly;\n\
    \        seq.back() += d2;\n      }\n      d -= d2;\n      if (seq.back() == 0)\
    \ seq.pop_back();\n      if (d2 == Int{0}) break;\n    }\n    return true;\n \
    \ }\n  // SBT \u4E0A\u306E LCA\n  static Node lca(const Node &lhs, const Node\
    \ &rhs) {\n    Node n;\n    for (int i = 0; i < min<int>(lhs.seq.size(), rhs.seq.size());\
    \ i++) {\n      Int val1 = lhs.seq[i], val2 = rhs.seq[i];\n      if ((val1 < 0)\
    \ != (val2 < 0)) break;\n      if (val1 < 0) n.go_left(min(-val1, -val2));\n \
    \     if (val1 > 0) n.go_right(min(val1, val2));\n      if (val1 != val2) break;\n\
    \    }\n    return n;\n  }\n  friend ostream &operator<<(ostream &os, const Node\
    \ &rhs) {\n    os << \"\\n\";\n    os << \"L : ( \" << rhs.lx << \", \" << rhs.ly\
    \ << \" )\\n\";\n    os << \"M : ( \" << rhs.x << \", \" << rhs.y << \" )\\n\"\
    ;\n    os << \"R : ( \" << rhs.rx << \", \" << rhs.ry << \" )\\n\";\n    os <<\
    \ \"seq : {\";\n    for (auto &x : rhs.seq) os << x << \", \";\n    os << \"}\
    \ \\n\";\n    return os;\n  }\n  friend bool operator<(const Node &lhs, const\
    \ Node &rhs) {\n    return lhs.x * rhs.y < rhs.x * lhs.y;\n  }\n  friend bool\
    \ operator==(const Node &lhs, const Node &rhs) {\n    return lhs.x == rhs.x and\
    \ lhs.y == rhs.y;\n  }\n};\n\n/**\n *  @brief Stern-Brocot Tree\n */\n#line 9\
    \ \"math/enumerate-convex.hpp\"\n\n// \u4E0B\u5411\u304D\u51F8\u5305\u306E\u9802\
    \u70B9\u5217\u6319\n// (xl, yl) \u59CB\u70B9, x in [xl, xr]\n// inside(x, y) :\
    \ (x, y) \u304C\u51F8\u5305\u5185\u90E8\u304B\uFF1F\n// candicate(x, y, c, d)\
    \ : (x, y) \u304C\u51F8\u5305\u5916\u90E8\u306B\u3042\u308B\u3068\u3059\u308B\u3002\
    \n// \u51F8\u5305\u5185\u90E8\u306E\u70B9 (x + sc, y + sd) \u304C\u5B58\u5728\u3059\
    \u308C\u3070\u305D\u306E\u3088\u3046\u306A s \u3092\u8FD4\u3059\n// \u5B58\u5728\
    \u3057\u306A\u3051\u308C\u3070\u4EFB\u610F\u306E\u5024 (-1 \u3067\u3082\u3088\u3044\
    ) \u3092\u8FD4\u3059\ntemplate <typename Int>\nvector<pair<Int, Int>> enumerate_convex(\n\
    \    Int xl, Int yl, Int xr, const function<bool(Int, Int)>& inside,\n    const\
    \ function<Int(Int, Int, Int, Int)>& candicate) {\n  assert(xl <= xr);\n\n  //\
    \ inside \u304B\u3064 x <= xr\n  auto f = [&](Int x, Int y) { return x <= xr &&\
    \ inside(x, y); };\n\n  // (a, b) \u304B\u3089 (c, d) \u65B9\u5411\u306B\u9032\
    \u3081\u308B\u3060\u3051\u9032\u3080\n  auto go = [&](Int a, Int b, Int c, Int\
    \ d) -> Int {\n    assert(f(a, b));\n    Int r = 1, s = 0;\n    while (f(a + r\
    \ * c, b + r * d)) r *= 2;\n    while ((r /= 2) != 0) {\n      if (f(a + r * c,\
    \ b + r * d)) s += r, a += r * c, b += r * d;\n    }\n    return s;\n  };\n\n\
    \  // (a, b) \u304C out, (a + c * k, b + d * k) \u304C in \u3068\u3059\u308B\n\
    \  // out \u306E\u9593\u9032\u3081\u308B\u3060\u3051\u9032\u3080\n  auto go2 =\
    \ [&](Int a, Int b, Int c, Int d, Int k) {\n    assert(!inside(a, b) and inside(a\
    \ + c * k, b + d * k));\n    Int ok = 0, ng = k;\n    while (ok + 1 < ng) {\n\
    \      Int m = (ok + ng) / 2;\n      (inside(a + c * m, b + d * m) ? ng : ok)\
    \ = m;\n    }\n    return ok;\n  };\n\n  vector<pair<Int, Int>> ps;\n  Int x =\
    \ xl, y = yl;\n  assert(inside(x, y) and go(x, y, 0, -1) == 0);\n  ps.emplace_back(x,\
    \ y);\n  while (x < xr) {\n    Int a, b;\n    if (f(x + 1, y)) {\n      a = 1,\
    \ b = 0;\n    } else {\n      SternBrocotTreeNode<Int> sb;\n      while (true)\
    \ {\n        assert(f(x + sb.lx, y + sb.ly));\n        assert(!f(x + sb.rx, y\
    \ + sb.ry));\n        if (f(x + sb.lx + sb.rx, y + sb.ly + sb.ry)) {\n       \
    \   Int s = go(x + sb.lx, y + sb.ly, sb.rx, sb.ry);\n          assert(s > 0);\n\
    \          sb.go_right(s);\n        } else {\n          Int s = candicate(x +\
    \ sb.rx, y + sb.ry, sb.lx, sb.ly);\n          if (s <= 0 || !inside(x + sb.lx\
    \ * s + sb.rx, y + sb.ly * s + sb.ry)) {\n            a = sb.lx, b = sb.ly;\n\
    \            break;\n          } else {\n            Int t = go2(x + sb.rx, y\
    \ + sb.ry, sb.lx, sb.ly, s);\n            sb.go_left(t);\n          }\n      \
    \  }\n      }\n    }\n    Int s = go(x, y, a, b);\n    x += a * s, y += b * s;\n\
    \    ps.emplace_back(x, y);\n  }\n  return ps;\n}\n#line 2 \"math/isqrt.hpp\"\n\
    \n#line 4 \"math/isqrt.hpp\"\nusing namespace std;\n\n// floor(sqrt(n)) \u3092\
    \u8FD4\u3059 (\u305F\u3060\u3057 n \u304C\u8CA0\u306E\u5834\u5408\u306F 0 \u3092\
    \u8FD4\u3059)\nlong long isqrt(long long n) {\n  if (n <= 0) return 0;\n  long\
    \ long x = sqrt(n);\n  while ((x + 1) * (x + 1) <= n) x++;\n  while (x * x > n)\
    \ x--;\n  return x;\n}\n#line 2 \"math/two-square.hpp\"\n\n#line 2 \"internal/internal-math.hpp\"\
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
    \ internal\n#line 2 \"prime/fast-factorize.hpp\"\n\n#line 6 \"prime/fast-factorize.hpp\"\
    \nusing namespace std;\n\n#line 2 \"misc/rng.hpp\"\n\n#line 2 \"internal/internal-seed.hpp\"\
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
    \  sort(begin(ret), end(ret));\n  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd()\
    \ { return rng() * 5.42101086242752217004e-20; }\n// [l, r)\ndouble rnd(double\
    \ l, double r) {\n  assert(l < r);\n  return l + rnd() * (r - l);\n}\n\ntemplate\
    \ <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n  for (int\
    \ i = 1; i < n; i++) swap(v[i], v[randint(0, i + 1)]);\n}\n\n}  // namespace my_rand\n\
    \nusing my_rand::randint;\nusing my_rand::randset;\nusing my_rand::randshf;\n\
    using my_rand::rnd;\nusing my_rand::rng;\n#line 2 \"modint/arbitrary-montgomery-modint.hpp\"\
    \n\n#line 4 \"modint/arbitrary-montgomery-modint.hpp\"\nusing namespace std;\n\
    \ntemplate <typename Int, typename UInt, typename Long, typename ULong, int id>\n\
    struct ArbitraryLazyMontgomeryModIntBase {\n  using mint = ArbitraryLazyMontgomeryModIntBase;\n\
    \n  inline static UInt mod;\n  inline static UInt r;\n  inline static UInt n2;\n\
    \  static constexpr int bit_length = sizeof(UInt) * 8;\n\n  static UInt get_r()\
    \ {\n    UInt ret = mod;\n    while (mod * ret != 1) ret *= UInt(2) - mod * ret;\n\
    \    return ret;\n  }\n  static void set_mod(UInt m) {\n    assert(m < (UInt(1u)\
    \ << (bit_length - 2)));\n    assert((m & 1) == 1);\n    mod = m, n2 = -ULong(m)\
    \ % m, r = get_r();\n  }\n  UInt a;\n\n  ArbitraryLazyMontgomeryModIntBase() :\
    \ a(0) {}\n  ArbitraryLazyMontgomeryModIntBase(const Long &b)\n      : a(reduce(ULong(b\
    \ % mod + mod) * n2)){};\n\n  static UInt reduce(const ULong &b) {\n    return\
    \ (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;\n  }\n\n  mint &operator+=(const\
    \ mint &b) {\n    if (Int(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n\
    \  }\n  mint &operator-=(const mint &b) {\n    if (Int(a -= b.a) < 0) a += 2 *\
    \ mod;\n    return *this;\n  }\n  mint &operator*=(const mint &b) {\n    a = reduce(ULong(a)\
    \ * b.a);\n    return *this;\n  }\n  mint &operator/=(const mint &b) {\n    *this\
    \ *= b.inverse();\n    return *this;\n  }\n\n  mint operator+(const mint &b) const\
    \ { return mint(*this) += b; }\n  mint operator-(const mint &b) const { return\
    \ mint(*this) -= b; }\n  mint operator*(const mint &b) const { return mint(*this)\
    \ *= b; }\n  mint operator/(const mint &b) const { return mint(*this) /= b; }\n\
    \n  bool operator==(const mint &b) const {\n    return (a >= mod ? a - mod : a)\
    \ == (b.a >= mod ? b.a - mod : b.a);\n  }\n  bool operator!=(const mint &b) const\
    \ {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);\n\
    \  }\n  mint operator-() const { return mint(0) - mint(*this); }\n  mint operator+()\
    \ const { return mint(*this); }\n\n  mint pow(ULong n) const {\n    mint ret(1),\
    \ mul(*this);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *=\
    \ mul, n >>= 1;\n    }\n    return ret;\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const mint &b) {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream\
    \ &is, mint &b) {\n    Long t;\n    is >> t;\n    b = ArbitraryLazyMontgomeryModIntBase(t);\n\
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
    #line 2 \"math/gaussian-integer.hpp\"\n\n// x + yi\ntemplate <typename T>\nstruct\
    \ Gaussian_Integer {\n  T x, y;\n  using G = Gaussian_Integer;\n\n  Gaussian_Integer(T\
    \ _x = 0, T _y = 0) : x(_x), y(_y) {}\n  Gaussian_Integer(const pair<T, T>& p)\
    \ : x(p.fi), y(p.se) {}\n\n  T norm() const { return x * x + y * y; }\n  G conj()\
    \ const { return G{x, -y}; }\n\n  G operator+(const G& r) const { return G{x +\
    \ r.x, y + r.y}; }\n  G operator-(const G& r) const { return G{x - r.x, y - r.y};\
    \ }\n  G operator*(const G& r) const {\n    return G{x * r.x - y * r.y, x * r.y\
    \ + y * r.x};\n  }\n  G operator/(const G& r) const {\n    G g = G{*this} * r.conj();\n\
    \    T n = r.norm();\n    g.x += n / 2, g.y += n / 2;\n    return G{g.x / n -\
    \ (g.x % n < 0), g.y / n - (g.y % n < 0)};\n  }\n  G operator%(const G& r) const\
    \ { return G{*this} - G{*this} / r * r; }\n\n  G& operator+=(const G& r) { return\
    \ *this = G{*this} + r; }\n  G& operator-=(const G& r) { return *this = G{*this}\
    \ - r; }\n  G& operator*=(const G& r) { return *this = G{*this} * r; }\n  G& operator/=(const\
    \ G& r) { return *this = G{*this} / r; }\n  G& operator%=(const G& r) { return\
    \ *this = G{*this} % r; }\n  G operator-() const { return G{-x, -y}; }\n  G operator+()\
    \ const { return G{*this}; }\n  bool operator==(const G& g) const { return x ==\
    \ g.x && y == g.y; }\n  bool operator!=(const G& g) const { return x != g.x ||\
    \ y != g.y; }\n\n  G pow(__int128_t e) const {\n    G res{1}, a{*this};\n    while\
    \ (e) {\n      if (e & 1) res *= a;\n      a *= a, e >>= 1;\n    }\n    return\
    \ res;\n  }\n\n  friend G gcd(G a, G b) {\n    while (b != G{0, 0}) {\n      trc(a,\
    \ b, a / b, a % b);\n      swap(a %= b, b);\n    }\n    return a;\n  }\n  friend\
    \ ostream& operator<<(ostream& os, const G& rhs) {\n    return os << rhs.x <<\
    \ \" \" << rhs.y;\n  }\n};\n#line 6 \"math/two-square.hpp\"\n\n// \u89E3\u304C\
    \u5B58\u5728\u3057\u306A\u3044\u5834\u5408 (-1, -1) \u3092\u8FD4\u3059\nGaussian_Integer<__int128_t>\
    \ solve_norm_equation_prime(long long p) {\n  if (p % 4 == 3) return {-1, -1};\n\
    \  if (p == 2) return {1, 1};\n  long long x = 1;\n  while (true) {\n    x++;\n\
    \    long long z = internal::modpow<long long, __int128_t>(x, (p - 1) / 4, p);\n\
    \    if (__int128_t(z) * z % p == p - 1) {\n      x = z;\n      break;\n    }\n\
    \  }\n  long long y = 1, k = (__int128_t(x) * x + 1) / p;\n  while (k > 1) {\n\
    \    long long B = x % k, D = y % k;\n    if (B < 0) B += k;\n    if (D < 0) D\
    \ += k;\n    if (B * 2 > k) B -= k;\n    if (D * 2 > k) D -= k;\n    long long\
    \ nx = (__int128_t(x) * B + __int128_t(y) * D) / k;\n    long long ny = (__int128_t(x)\
    \ * D - __int128_t(y) * B) / k;\n    x = nx, y = ny;\n    k = (__int128_t(x) *\
    \ x + __int128_t(y) * y) / p;\n  }\n  return {x, y};\n}\n\n// p^e \u304C long\
    \ long \u306B\u53CE\u307E\u308B\nvector<Gaussian_Integer<__int128_t>> solve_norm_equation_prime_power(\n\
    \    long long p, long long e) {\n  using G = Gaussian_Integer<__int128_t>;\n\
    \  if (p % 4 == 3) {\n    if (e % 2 == 1) return {};\n    long long x = 1;\n \
    \   for (int i = 0; i < e / 2; i++) x *= p;\n    return {G{x}};\n  }\n  if (p\
    \ == 2) return {G{1, 1}.pow(e)};\n  G pi = solve_norm_equation_prime(p);\n  vector<G>\
    \ pows(e + 1);\n  pows[0] = 1;\n  for (int i = 1; i <= e; i++) pows[i] = pows[i\
    \ - 1] * pi;\n  vector<G> res(e + 1);\n  for (int i = 0; i <= e; i++) res[i] =\
    \ pows[i] * (pows[e - i].conj());\n  return res;\n}\n\n// 0 <= arg < 90 \u306E\
    \u7BC4\u56F2\u306E\u89E3\u306E\u307F\u8FD4\u3059\nvector<Gaussian_Integer<__int128_t>>\
    \ solve_norm_equation(long long N) {\n  using G = Gaussian_Integer<__int128_t>;\n\
    \  if (N < 0) return {};\n  if (N == 0) return {G{0}};\n  auto pes = factor_count(N);\n\
    \  for (auto& [p, e] : pes) {\n    if (p % 4 == 3 && e % 2 == 1) return {};\n\
    \  }\n  vector<G> res{G{1}};\n  for (auto& [p, e] : pes) {\n    vector<G> cur\
    \ = solve_norm_equation_prime_power(p, e);\n    vector<G> nxt;\n    for (auto&\
    \ g1 : res) {\n      for (auto& g2 : cur) nxt.push_back(g1 * g2);\n    }\n   \
    \ res = nxt;\n  }\n\n  for (auto& g : res) {\n    while (g.x <= 0 || g.y < 0)\
    \ g = G{-g.y, g.x};\n  }\n  return res;\n}\n\n// x,y \u4E21\u65B9\u975E\u8CA0\u306E\
    \u307F, \u8F9E\u66F8\u9806\u3067\u8FD4\u3059\nvector<pair<long long, long long>>\
    \ two_square(long long N) {\n  if (N < 0) return {};\n  if (N == 0) return {{0,\
    \ 0}};\n  vector<pair<long long, long long>> ans;\n  for (auto& g : solve_norm_equation(N))\
    \ {\n    ans.emplace_back(g.x, g.y);\n    if (g.y == 0) ans.emplace_back(g.y,\
    \ g.x);\n  }\n  sort(begin(ans), end(ans));\n  return ans;\n}\n#line 9 \"verify/verify-unit-test/enumerate-convex.test.cpp\"\
    \n//\nusing namespace Nyaan;\n\nvector<pair<long long, long long>> calc(ll N)\
    \ {\n  ll m = isqrt(N);\n  // (0, m) \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u534A\
    \u5F84 sqrt(N) \u306E\u5186\n  auto inside = [&](ll x, ll y) {\n    return y >=\
    \ m or x * x + (y - m) * (y - m) <= N;\n  };\n  auto candicate = [&](ll x, ll\
    \ y, ll c, ll d) {\n    // (x + sc)^2 + (y - m + sd)^2 <= N\n    ll A = c * c\
    \ + d * d;\n    ll B = 2 * c * x + 2 * d * (y - m);\n    // A s^2 + B s + const\
    \ <= 0\n    ll num = -B, den = 2 * A;\n    ll quo = num / den, rem = num % den;\n\
    \    if (rem < 0) quo--, rem += den;\n    if (2 * rem > den) quo++, rem -= den;\n\
    \    return quo;\n  };\n\n  auto ans = enumerate_convex<ll>(0, 0, m, inside, candicate);\n\
    \  vector<pair<long long, long long>> res;\n  each2(x, y, ans) if (x * x + (y\
    \ - m) * (y - m) == N) {\n    res.emplace_back(x, m - y);\n  }\n  sort(begin(res),\
    \ end(res));\n  return res;\n}\n\nvoid check(long long N) {\n  auto ac = two_square(N);\n\
    \  auto ad = calc(N);\n  assert(ac == ad);\n}\n\nvoid q() {\n  rep1(N, 1000) check(N);\n\
    \  rep(t, 100) check(rng(1001, TEN(9)));\n  check(TEN(18));\n\n  trc2(\"OK\");\n\
    \  inl(a, b);\n  out(a + b);\n}\n\nvoid Nyaan::solve() {\n  int t = 1;\n  // in(t);\n\
    \  while (t--) q();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../math/enumerate-convex.hpp\"\
    \n#include \"../../math/isqrt.hpp\"\n#include \"../../math/two-square.hpp\"\n\
    #include \"../../misc/rng.hpp\"\n//\nusing namespace Nyaan;\n\nvector<pair<long\
    \ long, long long>> calc(ll N) {\n  ll m = isqrt(N);\n  // (0, m) \u3092\u4E2D\
    \u5FC3\u3068\u3059\u308B\u534A\u5F84 sqrt(N) \u306E\u5186\n  auto inside = [&](ll\
    \ x, ll y) {\n    return y >= m or x * x + (y - m) * (y - m) <= N;\n  };\n  auto\
    \ candicate = [&](ll x, ll y, ll c, ll d) {\n    // (x + sc)^2 + (y - m + sd)^2\
    \ <= N\n    ll A = c * c + d * d;\n    ll B = 2 * c * x + 2 * d * (y - m);\n \
    \   // A s^2 + B s + const <= 0\n    ll num = -B, den = 2 * A;\n    ll quo = num\
    \ / den, rem = num % den;\n    if (rem < 0) quo--, rem += den;\n    if (2 * rem\
    \ > den) quo++, rem -= den;\n    return quo;\n  };\n\n  auto ans = enumerate_convex<ll>(0,\
    \ 0, m, inside, candicate);\n  vector<pair<long long, long long>> res;\n  each2(x,\
    \ y, ans) if (x * x + (y - m) * (y - m) == N) {\n    res.emplace_back(x, m - y);\n\
    \  }\n  sort(begin(res), end(res));\n  return res;\n}\n\nvoid check(long long\
    \ N) {\n  auto ac = two_square(N);\n  auto ad = calc(N);\n  assert(ac == ad);\n\
    }\n\nvoid q() {\n  rep1(N, 1000) check(N);\n  rep(t, 100) check(rng(1001, TEN(9)));\n\
    \  check(TEN(18));\n\n  trc2(\"OK\");\n  inl(a, b);\n  out(a + b);\n}\n\nvoid\
    \ Nyaan::solve() {\n  int t = 1;\n  // in(t);\n  while (t--) q();\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - math/enumerate-convex.hpp
  - math/stern-brocot-tree.hpp
  - math/isqrt.hpp
  - math/two-square.hpp
  - internal/internal-math.hpp
  - internal/internal-type-traits.hpp
  - prime/fast-factorize.hpp
  - misc/rng.hpp
  - internal/internal-seed.hpp
  - modint/arbitrary-montgomery-modint.hpp
  - prime/miller-rabin.hpp
  - math/gaussian-integer.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/enumerate-convex.test.cpp
  requiredBy: []
  timestamp: '2024-09-14 23:22:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/enumerate-convex.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/enumerate-convex.test.cpp
- /verify/verify/verify-unit-test/enumerate-convex.test.cpp.html
title: verify/verify-unit-test/enumerate-convex.test.cpp
---