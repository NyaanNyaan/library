---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: hashmap/hashmap-base.hpp
    title: "Hash Map(base)\u3000(\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7\u30FB\u57FA\
      \u5E95\u30AF\u30E9\u30B9)"
  - icon: ':heavy_check_mark:'
    path: hashmap/hashmap.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7(\u9023\u60F3\u914D\u5217)"
  - icon: ':heavy_check_mark:'
    path: internal/internal-math.hpp
    title: internal/internal-math.hpp
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/mod-log.hpp
    title: modulo/mod-log.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"verify/verify-yosupo-math/yosupo-mod-log.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n\n#line\
    \ 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n#include\
    \ <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <initializer_list>\n#include <iomanip>\n\
    #include <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n\
    #include <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <streambuf>\n#include\
    \ <string>\n#include <tuple>\n#include <type_traits>\n#include <typeinfo>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include <vector>\n\
    \n// utility\n#line 1 \"template/util.hpp\"\nnamespace Nyaan {\nusing ll = long\
    \ long;\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing i128 =\
    \ __int128_t;\nusing u128 = __uint128_t;\n\ntemplate <typename T>\nusing V = vector<T>;\n\
    template <typename T>\nusing VV = vector<vector<T>>;\nusing vi = vector<int>;\n\
    using vl = vector<long long>;\nusing vd = V<double>;\nusing vs = V<string>;\n\
    using vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\ntemplate\
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
    \ 2 \"misc/fastio.hpp\"\n\n#line 8 \"misc/fastio.hpp\"\n\nusing namespace std;\n\
    \n#line 2 \"internal/internal-type-traits.hpp\"\n\n#line 4 \"internal/internal-type-traits.hpp\"\
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
    \ 12 \"misc/fastio.hpp\"\n\nnamespace fastio {\nstatic constexpr int SZ = 1 <<\
    \ 17;\nstatic constexpr int offset = 64;\nchar inbuf[SZ], outbuf[SZ];\nint in_left\
    \ = 0, in_right = 0, out_right = 0;\n\nstruct Pre {\n  char num[40000];\n  constexpr\
    \ Pre() : num() {\n    for (int i = 0; i < 10000; i++) {\n      int n = i;\n \
    \     for (int j = 3; j >= 0; j--) {\n        num[i * 4 + j] = n % 10 + '0';\n\
    \        n /= 10;\n      }\n    }\n  }\n} constexpr pre;\n\nvoid load() {\n  int\
    \ len = in_right - in_left;\n  memmove(inbuf, inbuf + in_left, len);\n  in_right\
    \ = len + fread(inbuf + len, 1, SZ - len, stdin);\n  in_left = 0;\n}\nvoid flush()\
    \ {\n  fwrite(outbuf, 1, out_right, stdout);\n  out_right = 0;\n}\nvoid skip_space()\
    \ {\n  if (in_left + offset > in_right) load();\n  while (inbuf[in_left] <= '\
    \ ') in_left++;\n}\n\nvoid single_read(char& c) {\n  if (in_left + offset > in_right)\
    \ load();\n  skip_space();\n  c = inbuf[in_left++];\n}\nvoid single_read(string&\
    \ S) {\n  skip_space();\n  while (true) {\n    if (in_left == in_right) load();\n\
    \    int i = in_left;\n    for (; i != in_right; i++) {\n      if (inbuf[i] <=\
    \ ' ') break;\n    }\n    copy(inbuf + in_left, inbuf + i, back_inserter(S));\n\
    \    in_left = i;\n    if (i != in_right) break;\n  }\n}\ntemplate <typename T,\n\
    \          enable_if_t<internal::is_broadly_integral_v<T>>* = nullptr>\nvoid single_read(T&\
    \ x) {\n  if (in_left + offset > in_right) load();\n  skip_space();\n  char c\
    \ = inbuf[in_left++];\n  [[maybe_unused]] bool minus = false;\n  if constexpr\
    \ (internal::is_broadly_signed_v<T>) {\n    if (c == '-') minus = true, c = inbuf[in_left++];\n\
    \  }\n  x = 0;\n  while (c >= '0') {\n    x = x * 10 + (c & 15);\n    c = inbuf[in_left++];\n\
    \  }\n  if constexpr (internal::is_broadly_signed_v<T>) {\n    if (minus) x =\
    \ -x;\n  }\n}\nvoid rd() {}\ntemplate <typename Head, typename... Tail>\nvoid\
    \ rd(Head& head, Tail&... tail) {\n  single_read(head);\n  rd(tail...);\n}\n\n\
    void single_write(const char& c) {\n  if (out_right > SZ - offset) flush();\n\
    \  outbuf[out_right++] = c;\n}\nvoid single_write(const bool& b) {\n  if (out_right\
    \ > SZ - offset) flush();\n  outbuf[out_right++] = b ? '1' : '0';\n}\nvoid single_write(const\
    \ string& S) {\n  flush(), fwrite(S.data(), 1, S.size(), stdout);\n}\nvoid single_write(const\
    \ char* p) { flush(), fwrite(p, 1, strlen(p), stdout); }\ntemplate <typename T,\n\
    \          enable_if_t<internal::is_broadly_integral_v<T>>* = nullptr>\nvoid single_write(const\
    \ T& _x) {\n  if (out_right > SZ - offset) flush();\n  if (_x == 0) {\n    outbuf[out_right++]\
    \ = '0';\n    return;\n  }\n  T x = _x;\n  if constexpr (internal::is_broadly_signed_v<T>)\
    \ {\n    if (x < 0) outbuf[out_right++] = '-', x = -x;\n  }\n  constexpr int buffer_size\
    \ = sizeof(T) * 10 / 4;\n  char buf[buffer_size];\n  int i = buffer_size;\n  while\
    \ (x >= 10000) {\n    i -= 4;\n    memcpy(buf + i, pre.num + (x % 10000) * 4,\
    \ 4);\n    x /= 10000;\n  }\n  if (x < 100) {\n    if (x < 10) {\n      outbuf[out_right]\
    \ = '0' + x;\n      ++out_right;\n    } else {\n      uint32_t q = (uint32_t(x)\
    \ * 205) >> 11;\n      uint32_t r = uint32_t(x) - q * 10;\n      outbuf[out_right]\
    \ = '0' + q;\n      outbuf[out_right + 1] = '0' + r;\n      out_right += 2;\n\
    \    }\n  } else {\n    if (x < 1000) {\n      memcpy(outbuf + out_right, pre.num\
    \ + (x << 2) + 1, 3);\n      out_right += 3;\n    } else {\n      memcpy(outbuf\
    \ + out_right, pre.num + (x << 2), 4);\n      out_right += 4;\n    }\n  }\n  memcpy(outbuf\
    \ + out_right, buf + i, buffer_size - i);\n  out_right += buffer_size - i;\n}\n\
    void wt() {}\ntemplate <typename Head, typename... Tail>\nvoid wt(const Head&\
    \ head, const Tail&... tail) {\n  single_write(head);\n  wt(std::forward<const\
    \ Tail>(tail)...);\n}\ntemplate <typename... Args>\nvoid wtn(const Args&... x)\
    \ {\n  wt(std::forward<const Args>(x)...);\n  wt('\\n');\n}\n\nstruct Dummy {\n\
    \  Dummy() { atexit(flush); }\n} dummy;\n\n}  // namespace fastio\nusing fastio::rd;\n\
    using fastio::skip_space;\nusing fastio::wt;\nusing fastio::wtn;\n#line 2 \"modulo/mod-log.hpp\"\
    \n\n#line 2 \"hashmap/hashmap.hpp\"\n\n#line 2 \"hashmap/hashmap-base.hpp\"\n\n\
    #line 4 \"hashmap/hashmap-base.hpp\"\nusing namespace std;\n\nnamespace HashMapImpl\
    \ {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\ntemplate <typename Key, typename\
    \ Data>\nstruct HashMapBase;\n\ntemplate <typename Key, typename Data>\nstruct\
    \ itrB\n    : iterator<bidirectional_iterator_tag, Data, ptrdiff_t, Data*, Data&>\
    \ {\n  using base =\n      iterator<bidirectional_iterator_tag, Data, ptrdiff_t,\
    \ Data*, Data&>;\n  using ptr = typename base::pointer;\n  using ref = typename\
    \ base::reference;\n\n  u32 i;\n  HashMapBase<Key, Data>* p;\n\n  explicit constexpr\
    \ itrB() : i(0), p(nullptr) {}\n  explicit constexpr itrB(u32 _i, HashMapBase<Key,\
    \ Data>* _p) : i(_i), p(_p) {}\n  explicit constexpr itrB(u32 _i, const HashMapBase<Key,\
    \ Data>* _p)\n      : i(_i), p(const_cast<HashMapBase<Key, Data>*>(_p)) {}\n \
    \ friend void swap(itrB& l, itrB& r) { swap(l.i, r.i), swap(l.p, r.p); }\n  friend\
    \ bool operator==(const itrB& l, const itrB& r) { return l.i == r.i; }\n  friend\
    \ bool operator!=(const itrB& l, const itrB& r) { return l.i != r.i; }\n  const\
    \ ref operator*() const {\n    return const_cast<const HashMapBase<Key, Data>*>(p)->data[i];\n\
    \  }\n  ref operator*() { return p->data[i]; }\n  ptr operator->() const { return\
    \ &(p->data[i]); }\n\n  itrB& operator++() {\n    assert(i != p->cap && \"itr::operator++()\"\
    );\n    do {\n      i++;\n      if (i == p->cap) break;\n      if (p->occupied_flag[i]\
    \ && !p->deleted_flag[i]) break;\n    } while (true);\n    return (*this);\n \
    \ }\n  itrB operator++(int) {\n    itrB it(*this);\n    ++(*this);\n    return\
    \ it;\n  }\n  itrB& operator--() {\n    do {\n      i--;\n      if (p->occupied_flag[i]\
    \ && !p->deleted_flag[i]) break;\n      assert(i != 0 && \"itr::operator--()\"\
    );\n    } while (true);\n    return (*this);\n  }\n  itrB operator--(int) {\n\
    \    itrB it(*this);\n    --(*this);\n    return it;\n  }\n};\n\ntemplate <typename\
    \ Key, typename Data>\nstruct HashMapBase {\n  using u32 = uint32_t;\n  using\
    \ u64 = uint64_t;\n  using iterator = itrB<Key, Data>;\n  using itr = iterator;\n\
    \n protected:\n  template <typename K>\n  inline u64 randomized(const K& key)\
    \ const {\n    return u64(key) ^ r;\n  }\n\n  template <typename K,\n        \
    \    enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,\n            enable_if_t<is_integral<K>::value,\
    \ nullptr_t> = nullptr>\n  inline u32 inner_hash(const K& key) const {\n    return\
    \ (randomized(key) * 11995408973635179863ULL) >> shift;\n  }\n  template <\n \
    \     typename K, enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,\n\
    \      enable_if_t<is_integral<decltype(K::first)>::value, nullptr_t> = nullptr,\n\
    \      enable_if_t<is_integral<decltype(K::second)>::value, nullptr_t> = nullptr>\n\
    \  inline u32 inner_hash(const K& key) const {\n    u64 a = randomized(key.first),\
    \ b = randomized(key.second);\n    a *= 11995408973635179863ULL;\n    b *= 10150724397891781847ULL;\n\
    \    return (a + b) >> shift;\n  }\n  template <typename K,\n            enable_if_t<is_same<K,\
    \ Key>::value, nullptr_t> = nullptr,\n            enable_if_t<is_integral<typename\
    \ K::value_type>::value, nullptr_t> =\n                nullptr>\n  inline u32\
    \ inner_hash(const K& key) const {\n    static constexpr u64 mod = (1LL << 61)\
    \ - 1;\n    static constexpr u64 base = 950699498548472943ULL;\n    u64 res =\
    \ 0;\n    for (auto& elem : key) {\n      __uint128_t x = __uint128_t(res) * base\
    \ + (randomized(elem) & mod);\n      res = (x & mod) + (x >> 61);\n    }\n   \
    \ __uint128_t x = __uint128_t(res) * base;\n    res = (x & mod) + (x >> 61);\n\
    \    if (res >= mod) res -= mod;\n    return res >> (shift - 3);\n  }\n\n  template\
    \ <typename D = Data,\n            enable_if_t<is_same<D, Key>::value, nullptr_t>\
    \ = nullptr>\n  inline u32 hash(const D& dat) const {\n    return inner_hash(dat);\n\
    \  }\n  template <\n      typename D = Data,\n      enable_if_t<is_same<decltype(D::first),\
    \ Key>::value, nullptr_t> = nullptr>\n  inline u32 hash(const D& dat) const {\n\
    \    return inner_hash(dat.first);\n  }\n\n  template <typename D = Data,\n  \
    \          enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr>\n  inline\
    \ Key data_to_key(const D& dat) const {\n    return dat;\n  }\n  template <\n\
    \      typename D = Data,\n      enable_if_t<is_same<decltype(D::first), Key>::value,\
    \ nullptr_t> = nullptr>\n  inline Key data_to_key(const D& dat) const {\n    return\
    \ dat.first;\n  }\n\n  void reallocate(u32 ncap) {\n    vector<Data> ndata(ncap);\n\
    \    vector<bool> nf(ncap);\n    shift = 64 - __lg(ncap);\n    for (u32 i = 0;\
    \ i < cap; i++) {\n      if (occupied_flag[i] && !deleted_flag[i]) {\n       \
    \ u32 h = hash(data[i]);\n        while (nf[h]) h = (h + 1) & (ncap - 1);\n  \
    \      ndata[h] = move(data[i]);\n        nf[h] = true;\n      }\n    }\n    data.swap(ndata);\n\
    \    occupied_flag.swap(nf);\n    cap = ncap;\n    occupied = s;\n    deleted_flag.resize(cap);\n\
    \    fill(std::begin(deleted_flag), std::end(deleted_flag), false);\n  }\n\n \
    \ inline bool extend_rate(u32 x) const { return x * 2 >= cap; }\n\n  inline bool\
    \ shrink_rate(u32 x) const {\n    return HASHMAP_DEFAULT_SIZE < cap && x * 10\
    \ <= cap;\n  }\n\n  inline void extend() { reallocate(cap << 1); }\n\n  inline\
    \ void shrink() { reallocate(cap >> 1); }\n\n public:\n  u32 cap, s, occupied;\n\
    \  vector<Data> data;\n  vector<bool> occupied_flag, deleted_flag;\n  u32 shift;\n\
    \  static u64 r;\n  static constexpr uint32_t HASHMAP_DEFAULT_SIZE = 4;\n\n  explicit\
    \ HashMapBase()\n      : cap(HASHMAP_DEFAULT_SIZE),\n        s(0),\n        occupied(0),\n\
    \        data(cap),\n        occupied_flag(cap),\n        deleted_flag(cap),\n\
    \        shift(64 - __lg(cap)) {}\n\n  itr begin() const {\n    u32 h = 0;\n \
    \   while (h != cap) {\n      if (occupied_flag[h] && !deleted_flag[h]) break;\n\
    \      h++;\n    }\n    return itr(h, this);\n  }\n  itr end() const { return\
    \ itr(this->cap, this); }\n\n  friend itr begin(const HashMapBase& h) { return\
    \ h.begin(); }\n  friend itr end(const HashMapBase& h) { return h.end(); }\n\n\
    \  itr find(const Key& key) const {\n    u32 h = inner_hash(key);\n    while (true)\
    \ {\n      if (occupied_flag[h] == false) return this->end();\n      if (data_to_key(data[h])\
    \ == key) {\n        if (deleted_flag[h] == true) return this->end();\n      \
    \  return itr(h, this);\n      }\n      h = (h + 1) & (cap - 1);\n    }\n  }\n\
    \n  bool contain(const Key& key) const { return find(key) != this->end(); }\n\n\
    \  itr insert(const Data& d) {\n    u32 h = hash(d);\n    while (true) {\n   \
    \   if (occupied_flag[h] == false) {\n        if (extend_rate(occupied + 1)) {\n\
    \          extend();\n          h = hash(d);\n          continue;\n        }\n\
    \        data[h] = d;\n        occupied_flag[h] = true;\n        ++occupied, ++s;\n\
    \        return itr(h, this);\n      }\n      if (data_to_key(data[h]) == data_to_key(d))\
    \ {\n        if (deleted_flag[h] == true) {\n          data[h] = d;\n        \
    \  deleted_flag[h] = false;\n          ++s;\n        }\n        return itr(h,\
    \ this);\n      }\n      h = (h + 1) & (cap - 1);\n    }\n  }\n\n  // tips for\
    \ speed up :\n  // if return value is unnecessary, make argument_2 false.\n  itr\
    \ erase(itr it, bool get_next = true) {\n    if (it == this->end()) return this->end();\n\
    \    s--;\n    if (!get_next) {\n      this->deleted_flag[it.i] = true;\n    \
    \  if (shrink_rate(s)) shrink();\n      return this->end();\n    }\n    itr nxt\
    \ = it;\n    nxt++;\n    this->deleted_flag[it.i] = true;\n    if (shrink_rate(s))\
    \ {\n      Data d = data[nxt.i];\n      shrink();\n      it = find(data_to_key(d));\n\
    \    }\n    return nxt;\n  }\n\n  itr erase(const Key& key) { return erase(find(key));\
    \ }\n\n  int count(const Key& key) { return find(key) == end() ? 0 : 1; }\n\n\
    \  bool empty() const { return s == 0; }\n\n  int size() const { return s; }\n\
    \n  void clear() {\n    fill(std::begin(occupied_flag), std::end(occupied_flag),\
    \ false);\n    fill(std::begin(deleted_flag), std::end(deleted_flag), false);\n\
    \    s = occupied = 0;\n  }\n\n  void reserve(int n) {\n    if (n <= 0) return;\n\
    \    n = 1 << min(23, __lg(n) + 2);\n    if (cap < u32(n)) reallocate(n);\n  }\n\
    };\n\ntemplate <typename Key, typename Data>\nuint64_t HashMapBase<Key, Data>::r\
    \ =\n    chrono::duration_cast<chrono::nanoseconds>(\n        chrono::high_resolution_clock::now().time_since_epoch())\n\
    \        .count();\n\n}  // namespace HashMapImpl\n\n/**\n * @brief Hash Map(base)\u3000\
    (\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7\u30FB\u57FA\u5E95\u30AF\u30E9\u30B9\
    )\n */\n#line 4 \"hashmap/hashmap.hpp\"\n\ntemplate <typename Key, typename Val>\n\
    struct HashMap : HashMapImpl::HashMapBase<Key, pair<Key, Val>> {\n  using base\
    \ = typename HashMapImpl::HashMapBase<Key, pair<Key, Val>>;\n  using HashMapImpl::HashMapBase<Key,\
    \ pair<Key, Val>>::HashMapBase;\n  using Data = pair<Key, Val>;\n\n  Val& operator[](const\
    \ Key& k) {\n    typename base::u32 h = base::inner_hash(k);\n    while (true)\
    \ {\n      if (base::occupied_flag[h] == false) {\n        if (base::extend_rate(base::occupied\
    \ + 1)) {\n          base::extend();\n          h = base::hash(k);\n         \
    \ continue;\n        }\n        base::data[h].first = k;\n        base::data[h].second\
    \ = Val();\n        base::occupied_flag[h] = true;\n        ++base::occupied,\
    \ ++base::s;\n        return base::data[h].second;\n      }\n      if (base::data[h].first\
    \ == k) {\n        if (base::deleted_flag[h] == true) {\n          base::data[h].second\
    \ = Val();\n          base::deleted_flag[h] = false;\n          ++base::s;\n \
    \       }\n        return base::data[h].second;\n      }\n      h = (h + 1) &\
    \ (base::cap - 1);\n    }\n  }\n\n  typename base::itr emplace(const Key& key,\
    \ const Val& val) {\n    return base::insert(Data(key, val));\n  }\n};\n\n/*\n\
    \ * @brief \u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7(\u9023\u60F3\u914D\u5217\
    )\n * @docs docs/hashmap/hashmap.md\n **/\n#line 2 \"internal/internal-math.hpp\"\
    \n\n#line 4 \"internal/internal-math.hpp\"\n\nnamespace internal {\n\n#line 10\
    \ \"internal/internal-math.hpp\"\nusing namespace std;\n\n// a mod p\ntemplate\
    \ <typename T>\nT safe_mod(T a, T p) {\n  a %= p;\n  if constexpr (is_broadly_signed_v<T>)\
    \ {\n    if (a < 0) a += p;\n  }\n  return a;\n}\n\n// \u8FD4\u308A\u5024\uFF1A\
    pair(g, x)\n// s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g\ntemplate <typename\
    \ T>\npair<T, T> inv_gcd(T a, T p) {\n  static_assert(is_broadly_signed_v<T>);\n\
    \  a = safe_mod(a, p);\n  if (a == 0) return {p, 0};\n  T b = p, x = 1, y = 0;\n\
    \  while (a != 0) {\n    T q = b / a;\n    swap(a, b %= a);\n    swap(x, y -=\
    \ q * x);\n  }\n  if (y < 0) y += p / b;\n  return {b, y};\n}\n\n// \u8FD4\u308A\
    \u5024 : a^{-1} mod p\n// gcd(a, p) != 1 \u304C\u5FC5\u8981\ntemplate <typename\
    \ T>\nT inv(T a, T p) {\n  static_assert(is_broadly_signed_v<T>);\n  a = safe_mod(a,\
    \ p);\n  T b = p, x = 1, y = 0;\n  while (a != 0) {\n    T q = b / a;\n    swap(a,\
    \ b %= a);\n    swap(x, y -= q * x);\n  }\n  assert(b == 1);\n  return y < 0 ?\
    \ y + p : y;\n}\n\n// T : \u5E95\u306E\u578B\n// U : T*T \u304C\u30AA\u30FC\u30D0\
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
    \ internal\n#line 5 \"modulo/mod-log.hpp\"\n\nint64_t mod_log(int64_t a, int64_t\
    \ b, int64_t p) {\n  if ((a %= p) < 0) a += p;\n  if ((b %= p) < 0) b += p;\n\
    \  int64_t f, g, r = 1 % p;\n  for (f = 0; (g = gcd(a, p)) > 1; ++f) {\n    if\
    \ (b % g) return (r == b) ? f : -1;\n    b /= g;\n    p /= g;\n    (r *= (a /\
    \ g)) %= p;\n  }\n  if (p == 1) return f;\n  int64_t ir = internal::inv(r, p);\n\
    \  (b *= ir) %= p;\n  int64_t k = 0, ak = 1;\n  HashMap<int64_t, int64_t> baby;\n\
    \  for (; k * k < p; ++k) {\n    if(baby.find(ak) == baby.end()) baby[ak] = k;\n\
    \    (ak *= a) %= p;\n  }\n  int64_t iak = internal::inv(ak, p);\n  for (int64_t\
    \ i = 0; i < k; ++i) {\n    if (baby.find(b) != baby.end()) return f + i * k +\
    \ baby[b];\n    (b *= iak) %= p;\n  }\n  return -1;\n}\n#line 6 \"verify/verify-yosupo-math/yosupo-mod-log.test.cpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve() {\n  int T;\n  rd(T);\n  rep(_,\
    \ T) {\n    ll x, y, m;\n    rd(x, y, m);\n    wt(mod_log(x, y, m));\n    wt('\\\
    n');\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../misc/fastio.hpp\"\
    \n#include \"../../modulo/mod-log.hpp\"\n\nusing namespace Nyaan; void Nyaan::solve()\
    \ {\n  int T;\n  rd(T);\n  rep(_, T) {\n    ll x, y, m;\n    rd(x, y, m);\n  \
    \  wt(mod_log(x, y, m));\n    wt('\\n');\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - misc/fastio.hpp
  - internal/internal-type-traits.hpp
  - modulo/mod-log.hpp
  - hashmap/hashmap.hpp
  - hashmap/hashmap-base.hpp
  - internal/internal-math.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
  requiredBy: []
  timestamp: '2024-05-03 23:21:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-math/yosupo-mod-log.test.cpp
- /verify/verify/verify-yosupo-math/yosupo-mod-log.test.cpp.html
title: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
---
