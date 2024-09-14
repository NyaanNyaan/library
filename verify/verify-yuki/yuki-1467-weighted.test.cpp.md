---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/slope-trick-weighted.hpp
    title: Weighted Slope Trick
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  - icon: ':heavy_check_mark:'
    path: segment-tree/rbst-segment-tree.hpp
    title: RBST-based Dynamic Lazy Segment Tree
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
    PROBLEM: https://yukicoder.me/problems/no/1467
    links:
    - https://atcoder.jp/contests/abc127/tasks/abc127_f
    - https://atcoder.jp/contests/abc275/tasks/abc275_h
    - https://atcoder.jp/contests/arc070/tasks/arc070_c
    - https://atcoder.jp/contests/dwango2016-prelims/tasks/dwango2016qual_e
    - https://atcoder.jp/contests/utpc2012/tasks/utpc2012_12
    - https://yukicoder.me/problems/no/1467
  bundledCode: "#line 1 \"verify/verify-yuki/yuki-1467-weighted.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1467\"\n//\n#line 2 \"template/template.hpp\"\
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
    \ 4 \"verify/verify-yuki/yuki-1467-weighted.test.cpp\"\n//\n#line 2 \"data-structure/slope-trick-weighted.hpp\"\
    \n\n#line 6 \"data-structure/slope-trick-weighted.hpp\"\nusing namespace std;\n\
    \n#line 2 \"segment-tree/rbst-segment-tree.hpp\"\n\n#line 2 \"internal/internal-type-traits.hpp\"\
    \n\n#line 4 \"internal/internal-type-traits.hpp\"\nusing namespace std;\n\nnamespace\
    \ internal {\ntemplate <typename T>\nusing is_broadly_integral =\n    typename\
    \ conditional_t<is_integral_v<T> || is_same_v<T, __int128_t> ||\n            \
    \                   is_same_v<T, __uint128_t>,\n                           true_type,\
    \ false_type>::type;\n\ntemplate <typename T>\nusing is_broadly_signed =\n   \
    \ typename conditional_t<is_signed_v<T> || is_same_v<T, __int128_t>,\n       \
    \                    true_type, false_type>::type;\n\ntemplate <typename T>\n\
    using is_broadly_unsigned =\n    typename conditional_t<is_unsigned_v<T> || is_same_v<T,\
    \ __uint128_t>,\n                           true_type, false_type>::type;\n\n\
    #define ENABLE_VALUE(x) \\\n  template <typename T> \\\n  constexpr bool x##_v\
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
    \ 4 \"segment-tree/rbst-segment-tree.hpp\"\n\nENABLE_HAS_VAR(lazy);\nENABLE_HAS_VAR(shift);\n\
    \ntemplate <typename Node, typename I, typename T, typename E, T (*f)(T, T),\n\
    \          T (*g)(T, E), E (*h)(E, E), T (*ti)(), E (*ei)()>\nstruct RBSTSegmentTreeBase\
    \ {\n protected:\n  using Ptr = Node *;\n  template <typename... Args>\n  static\
    \ Ptr _my_new(Args... args) {\n    return new Node(args...);\n  }\n  static void\
    \ _my_del(Ptr t) { delete t; }\n\n  static int _count(const Ptr t) { return t\
    \ ? t->cnt : 0; }\n\n  static T _sum(const Ptr &t) { return t ? t->sum : ti();\
    \ }\n\n  static uint64_t _rng() {\n    static uint64_t x_ = 88172645463325252ULL;\n\
    \    return x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;\n  }\n\n  static\
    \ Ptr _merge(Ptr l, Ptr r) {\n    if (!l || !r) return l ? l : r;\n    if (int((_rng()\
    \ * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n      _push(l);\n      l->r = _merge(l->r,\
    \ r);\n      return _update(l);\n    } else {\n      _push(r);\n      r->l = _merge(l,\
    \ r->l);\n      return _update(r);\n    }\n  }\n\n  static Ptr _build(int l, int\
    \ r, const vector<pair<I, T>> &dat) {\n    if (l == r) return nullptr;\n    if\
    \ (l + 1 == r) return _my_new(dat[l].first, dat[l].second);\n    int m = (l +\
    \ r) / 2;\n    return _merge(_build(l, m, dat), _build(m, r, dat));\n  };\n\n\
    \  static void _push([[maybe_unused]] Ptr t) {\n    if constexpr (has_lazy_v<Node>)\
    \ {\n      if (!t) return;\n      if (t->lazy != ei()) {\n        if (t->l) _propagate(t->l,\
    \ t->lazy);\n        if (t->r) _propagate(t->r, t->lazy);\n        t->lazy = ei();\n\
    \      }\n    }\n    if constexpr (has_shift_v<Node>) {\n      if (!t) return;\n\
    \      if (t->shift != I{}) {\n        if (t->l) _shift(t->l, t->shift);\n   \
    \     if (t->r) _shift(t->r, t->shift);\n        t->shift = I{};\n      }\n  \
    \  }\n  }\n  static void _propagate([[maybe_unused]] Ptr t, [[maybe_unused]] const\
    \ E &x) {\n    if constexpr (has_lazy_v<Node>) {\n      if (!t) return;\n    \
    \  t->lazy = h(t->lazy, x);\n      t->val = g(t->val, x);\n      t->sum = g(t->sum,\
    \ x);\n    }\n  }\n  static void _shift([[maybe_unused]] Ptr t, [[maybe_unused]]\
    \ const I &sh) {\n    if constexpr (has_shift_v<Node>) {\n      if (!t) return;\n\
    \      t->key += sh, t->shift += sh;\n    }\n  }\n\n  static Ptr _update(Ptr t)\
    \ {\n    if (!t) return t;\n    t->cnt = 1;\n    t->sum = t->val;\n    if (t->l)\
    \ t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n    if (t->r) t->cnt +=\
    \ t->r->cnt, t->sum = f(t->sum, t->r->sum);\n    return t;\n  }\n\n  // key \u304C\
    \ k \u3067\u3042\u308B\u30CE\u30FC\u30C9\u3092\u63A2\u3059, \u306A\u3051\u308C\
    \u3070 nullptr\n  static Ptr _find(Ptr t, I k) {\n    while (t) {\n      _push(t);\n\
    \      if (k == t->key) return t;\n      t = k < t->key ? t->l : t->r;\n    }\n\
    \    return nullptr;\n  }\n\n  static void _erase(Ptr &t, I k) {\n    if (!t)\
    \ return;\n    _push(t);\n    if (k == t->key) {\n      Ptr tl = t->l, tr = t->r;\n\
    \      _my_del(t);\n      t = _merge(tl, tr);\n    } else if (k < t->key) {\n\
    \      _erase(t->l, k);\n      _update(t);\n    } else {\n      _erase(t->r, k);\n\
    \      _update(t);\n    }\n  }\n\n  // [k \u672A\u6E80, k \u4EE5\u4E0A]\n  static\
    \ pair<Ptr, Ptr> _split_by_key(Ptr t, I k) {\n    if (!t) return {nullptr, nullptr};\n\
    \    _push(t);\n    if (k == t->key) {\n      Ptr tl = t->l;\n      t->l = nullptr;\n\
    \      return {tl, _update(t)};\n    } else if (k < t->key) {\n      auto s =\
    \ _split_by_key(t->l, k);\n      t->l = s.second;\n      return {s.first, _update(t)};\n\
    \    } else {\n      auto s = _split_by_key(t->r, k);\n      t->r = s.first;\n\
    \      return {_update(t), s.second};\n    }\n  }\n\n  // [k \u672A\u6E80, k,\
    \ k \u8D85\u904E]\n  static array<Ptr, 3> _split_by_key3(Ptr t, I k) {\n    if\
    \ (!t) return {{nullptr, nullptr, nullptr}};\n    _push(t);\n    if (k == t->key)\
    \ {\n      Ptr tl = t->l, tr = t->r;\n      t->l = t->r = nullptr;\n      return\
    \ {{tl, _update(t), tr}};\n    } else if (k < t->key) {\n      auto s = _split_by_key3(t->l,\
    \ k);\n      t->l = s[2];\n      return {{s[0], s[1], _update(t)}};\n    } else\
    \ {\n      auto s = _split_by_key3(t->r, k);\n      t->r = s[0];\n      return\
    \ {{_update(t), s[1], s[2]}};\n    }\n  }\n\n  // (-inf, i] \u306E prod \u306B\
    \u3064\u3044\u3066 check(prod) \u306E (true / false) \u3067\u5207\u308B\n  template\
    \ <typename C>\n  static pair<Ptr, Ptr> _split_max_right(Ptr t, const C &check,\
    \ T prod = ti()) {\n    assert(check(prod));\n    if (!t) return {nullptr, nullptr};\n\
    \    _push(t);\n    T p1 = f(prod, _sum(t->l));\n    if (check(p1)) {\n      prod\
    \ = p1;\n    } else {\n      auto s = _split_max_right(t->l, check, prod);\n \
    \     t->l = s.second;\n      return {s.first, _update(t)};\n    }\n    prod =\
    \ f(prod, t->val);\n    if (!check(prod)) {\n      Ptr tl = t->l;\n      t->l\
    \ = nullptr;\n      return {tl, _update(t)};\n    }\n    p1 = f(prod, _sum(t->r));\n\
    \    if (check(p1)) {\n      return {t, nullptr};\n    } else {\n      auto s\
    \ = _split_max_right(t->r, check, prod);\n      t->r = s.first;\n      return\
    \ {_update(t), s.second};\n    }\n  }\n\n  // [i, inf) \u306E prod \u306B\u3064\
    \u3044\u3066 check(prod) \u306E (false / true) \u3067\u5207\u308B\n  template\
    \ <typename C>\n  static pair<Ptr, Ptr> _split_min_left(Ptr t, const C &check,\
    \ T prod = ti()) {\n    assert(check(prod));\n    if (!t) return {nullptr, nullptr};\n\
    \    _push(t);\n    T p1 = f(_sum(t->r), prod);\n    if (check(p1)) {\n      prod\
    \ = p1;\n    } else {\n      auto s = _split_min_left(t->r, check, prod);\n  \
    \    t->r = s.first;\n      return {_update(t), s.second};\n    }\n    prod =\
    \ f(t->val, prod);\n    if (!check(prod)) {\n      Ptr tr = t->r;\n      t->r\
    \ = nullptr;\n      return {_update(t), tr};\n    }\n    p1 = f(_sum(t->l), prod);\n\
    \    if (check(p1)) {\n      return {nullptr, t};\n    } else {\n      auto s\
    \ = _split_min_left(t->l, check, prod);\n      t->l = s.second;\n      return\
    \ {s.first, _update(t)};\n    }\n  }\n\n  // [l, inf) \u3067\u3042\u308B\u5730\
    \u70B9\u306B apply\n  static void _apply_left(Ptr t, I l, const E &e) {\n    if\
    \ (!t) return;\n    _push(t);\n    if (t->key < l) {\n      _apply_left(t->r,\
    \ l, e);\n    } else if (t->key == l) {\n      t->val = g(t->val, e);\n      _propagate(t->r,\
    \ e);\n    } else {\n      _apply_left(t->l, l, e);\n      t->val = g(t->val,\
    \ e);\n      _propagate(t->r, e);\n    }\n    _update(t);\n  }\n\n  // [-inf,\
    \ r) \u3067\u3042\u308B\u5730\u70B9\u306B apply\n  static void _apply_right(Ptr\
    \ t, I r, const E &e) {\n    if (!t) return;\n    _push(t);\n    if (t->key <\
    \ r) {\n      _propagate(t->l, e);\n      t->val = g(t->val, e);\n      _apply_right(t->r,\
    \ r, e);\n    } else if (t->key == r) {\n      _propagate(t->l, e);\n    } else\
    \ {\n      _apply_right(t->l, r, e);\n    }\n    _update(t);\n  }\n\n  // [l,\
    \ r) \u306B apply\n  static void _apply(Ptr t, I l, I r, const E &e) {\n    if\
    \ (!t) return;\n    _push(t);\n    if (t->key < l) {\n      _apply(t->r, l, r,\
    \ e);\n    } else if (t->key == l) {\n      t->val = g(t->val, e);\n      _apply_right(t->r,\
    \ r, e);\n    } else if (t->key < r) {\n      _apply_left(t->l, l, e);\n     \
    \ t->val = g(t->val, e);\n      _apply_right(t->r, r, e);\n    } else if (t->key\
    \ == r) {\n      _apply_left(t->l, l, e);\n    } else {\n      _apply(t->l, l,\
    \ r, e);\n    }\n    _update(t);\n  }\n\n  // l \u4EE5\u4E0A\n  static T _fold_left(Ptr\
    \ t, I l) {\n    if (!t) return ti();\n    _push(t);\n    if (t->key < l) {\n\
    \      return _fold_left(t->r, l);\n    } else if (t->key == l) {\n      return\
    \ f(t->val, _fold_left(t->r, l));\n    } else {\n      T tl = _fold_left(t->l,\
    \ l);\n      return f(f(tl, t->val), _sum(t->r));\n    }\n  }\n\n  // r \u672A\
    \u6E80\n  static T _fold_right(Ptr t, I r) {\n    if (!t) return ti();\n    _push(t);\n\
    \    if (t->key < r) {\n      T tr = _fold_right(t->r, r);\n      return f(f(_sum(t->l),\
    \ t->val), tr);\n    } else if (t->key == r) {\n      return _sum(t->l);\n   \
    \ } else {\n      return _fold_right(t->l, r);\n    }\n  }\n\n  static T _fold(Ptr\
    \ t, I l, I r) {\n    if (!t) return ti();\n    _push(t);\n    if (t->key < l)\
    \ {\n      return _fold(t->r, l, r);\n    } else if (t->key == l) {\n      return\
    \ f(t->val, _fold_right(t->r, r));\n    } else if (t->key < r) {\n      T tl =\
    \ _fold_left(t->l, l);\n      T tr = _fold_right(t->r, r);\n      return f(f(tl,\
    \ t->val), tr);\n    } else if (t->key == r) {\n      return _fold_left(t->l,\
    \ l);\n    } else {\n      return _fold(t->l, l, r);\n    }\n  }\n\n  // t \u3092\
    \u6839\u3068\u3059\u308B\u6728\u306E\u4E0A\u3067\u6700\u5C0F\u306E key \u306F\uFF1F\
    \ (t \u304C\u7A7A\u306E\u5834\u5408\u306F failed)\n  static pair<I, T> _get_min_keyval(Ptr\
    \ t, const I &failed) {\n    if (!t) return {failed, ti()};\n    while (t->l)\
    \ _push(t), t = t->l;\n    return {t->key, t->val};\n  }\n\n  // t \u3092\u6839\
    \u3068\u3059\u308B\u6728\u306E\u4E0A\u3067\u6700\u5C0F\u306E key \u306F\uFF1F\
    \ (t \u304C\u7A7A\u306E\u5834\u5408\u306F failed)\n  static pair<I, T> _get_max_keyval(Ptr\
    \ t, const I &failed) {\n    if (!t) return {failed, ti()};\n    while (t->r)\
    \ _push(t), t = t->r;\n    return {t->key, t->val};\n  }\n\n  // t \u3092\u6839\
    \u3068\u3059\u308B\u6728\u306E\u3046\u3061\u3001[0, i \u306E\u533A\u9593 fold\
    \ \u304C true \u306B\u306A\u308B\u6700\u5927\u306E i \u306F\u4F55\u304B\uFF1F\n\
    \  // exclusive \u304B\u3064 (\u7A7A \u307E\u305F\u306F[0,\u53F3]\u304C\u771F\u306E\
    \u5834\u5408) \u306E\u5834\u5408\u306F failed(inf)\n  // inclusive \u304B\u3064\
    \ (\u7A7A \u307E\u305F\u306F[0,0] \u304C\u507D\u306E\u5834\u5408) \u306E\u5834\
    \u5408\u306F failed\n  template <typename C, bool exclusive>\n  static I _max_right(Ptr\
    \ t, C check, const I &failed) {\n    if (!t) return failed;\n    _push(t);\n\
    \    Ptr now = t;\n    T prod_now = ti();\n    [[maybe_unused]] I prev = failed;\n\
    \    while (true) {\n      if (now->l != nullptr) {\n        _push(now->l);\n\
    \        auto pl = f(prod_now, now->l->sum);\n        if (check(pl)) {\n     \
    \     prod_now = pl;\n        } else {\n          now = now->l;\n          continue;\n\
    \        }\n      }\n      auto pl = f(prod_now, now->val);\n      if (!check(pl))\
    \ {\n        if constexpr (exclusive) {\n          return now->key;\n        }\
    \ else {\n          return now->l ? _get_max_keyval(now->l, failed).first : prev;\n\
    \        }\n      }\n      prod_now = pl;\n      if (now->r == nullptr) {\n  \
    \      if constexpr (exclusive) {\n          return failed;\n        } else {\n\
    \          return now->key;\n        }\n      }\n      _push(now->r);\n      if\
    \ constexpr (!exclusive) prev = now->key;\n      now = now->r;\n    }\n  }\n\n\
    \  // t \u3092\u6839\u3068\u3059\u308B\u6728\u306E\u3046\u3061\u3001i, inf) \u306E\
    \u533A\u9593 fold \u304C true \u306B\u306A\u308B\u6700\u5C0F\u306E i \u306F\u4F55\
    \u304B\uFF1F\n  // inclusive \u304B\u3064 (\u7A7A \u307E\u305F\u306F \u5B58\u5728\
    \u3057\u306A\u3044) \u5834\u5408\u306F failed\n  // exlucisve \u304B\u3064 (\u7A7A\
    \ \u307E\u305F\u306F [\u5DE6, inf) \u304C\u771F) \u306E\u5834\u5408\u306F failed\n\
    \  template <typename C, bool inclusive>\n  static I _min_left(Ptr t, C check,\
    \ const I &failed) {\n    if (!t) return failed;\n    _push(t);\n    Ptr now =\
    \ t;\n    T prod_now = ti();\n    [[maybe_unused]] I prev = failed;\n    while\
    \ (true) {\n      if (now->r != nullptr) {\n        _push(now->r);\n        auto\
    \ pr = f(now->r->sum, prod_now);\n        if (check(pr)) {\n          prod_now\
    \ = pr;\n        } else {\n          now = now->r;\n          continue;\n    \
    \    }\n      }\n      auto pr = f(now->val, prod_now);\n      if (!check(pr))\
    \ {\n        if constexpr (inclusive) {\n          return now->r ? _get_min_keyval(now->r,\
    \ failed).first : prev;\n        } else {\n          return now->key;\n      \
    \  }\n      }\n      prod_now = pr;\n      if (now->l == nullptr) {\n        if\
    \ constexpr (inclusive) {\n          return now->key;\n        } else {\n    \
    \      return failed;\n        }\n      }\n      _push(now->l);\n      if constexpr\
    \ (inclusive) prev = now->key;\n      now = now->l;\n    }\n  }\n\n  static void\
    \ _clear(Ptr t) {\n    if (!t) return;\n    if (t->l) _clear(t->l);\n    if (t->r)\
    \ _clear(t->r);\n    _my_del(t);\n  }\n\n  static Ptr _deepcopy(Ptr t) {\n   \
    \ if (!t) return nullptr;\n    Ptr u = _my_new(*t);\n    if (u->l) u->l = _deepcopy(u->l);\n\
    \    if (u->r) u->r = _deepcopy(u->r);\n    return u;\n  }\n\n  static void _dump(Ptr\
    \ t) {\n    if (!t) return;\n    _push(t);\n    _dump(t->l);\n    cerr << \"##\
    \ key = \" << t->key << \",\";\n    cerr << \"\\tval = \" << t->val << \", \"\
    ;\n    cerr << \"\\tsum = \" << t->sum << \", \";\n    cerr << \"\\tchild = \"\
    ;\n    cerr << \"( \";\n    if (t->l) cerr << t->l->key;\n    if (!t->l) cerr\
    \ << \"nil\";\n    cerr << \", \";\n    if (t->r) cerr << t->r->key;\n    if (!t->r)\
    \ cerr << \"nil\";\n    cerr << \" )\" << endl;\n    _dump(t->r);\n  }\n\n  static\
    \ void _make_array(Ptr t, vector<pair<I, T>> &v) {\n    if (!t) return;\n    _push(t);\n\
    \    if (t->l) _make_array(t->l, v);\n    v.emplace_back(t->key, t->val);\n  \
    \  if (t->r) _make_array(t->r, v);\n  }\n\n public:\n  Ptr root;\n\n  RBSTSegmentTreeBase()\
    \ : root(nullptr) {}\n  RBSTSegmentTreeBase(Ptr t) : root(t) {}\n  RBSTSegmentTreeBase(const\
    \ vector<T> xs, const vector<I> &vals = {}) {\n    if (!vals.empty()) assert(xs.size()\
    \ == vals.size());\n    int n = xs.size();\n    vector<pair<I, T>> dat(n);\n \
    \   for (int i = 0; i < n; i++) dat[i] = {vals.empty() ? i : vals[i], xs[i]};\n\
    \    root = _build(0, n, dat);\n  }\n  RBSTSegmentTreeBase(RBSTSegmentTreeBase\
    \ &&rhs) noexcept { root = rhs.root; }\n  RBSTSegmentTreeBase(const RBSTSegmentTreeBase\
    \ &rhs) { root = rhs.root; }\n  ~RBSTSegmentTreeBase() = default;\n\n  using RBST\
    \ = RBSTSegmentTreeBase;\n  RBST &operator=(RBST &&rhs) noexcept {\n    root =\
    \ rhs.root;\n    return *this;\n  }\n  RBST &operator=(const RBST &rhs) {\n  \
    \  root = rhs.root;\n    return *this;\n  }\n  RBST deepcopy() { return _deepcopy(root);\
    \ }\n\n  friend void swap(RBST &lhs, RBST &rhs) { swap(lhs.root, rhs.root); }\n\
    \  void swap(RBST &rhs) { swap(root, rhs.root); }\n\n  // destructive ordered\
    \ _merge (max(lhs) < min(rhs))\n  friend RBST ordered_merge(RBST &lhs, RBST &rhs)\
    \ {\n    assert(lhs.get_max_key() < rhs.get_min_key());\n    return RBST{_merge(lhs.root,\
    \ rhs.root)};\n  }\n\n  // 1 \u70B9 \u5024\u306E\u66F8\u304D\u63DB\u3048\n  void\
    \ set_val(I i, T x) {\n    auto s = _split_by_key3(root, i);\n    if (s[1] ==\
    \ nullptr) {\n      s[1] = _my_new(i, x);\n    } else {\n      s[1]->val = x;\n\
    \    }\n    root = _merge(_merge(s[0], _update(s[1])), s[2]);\n  }\n\n  // \u3059\
    \u3067\u306B\u8981\u7D20\u304C\u5B58\u5728\u3059\u308B\u3068\u304D\u306B\u5024\
    \u3092 set \u3059\u308B\u3002\u304A\u305D\u3089\u304F\u5C11\u3057\u65E9\u3044\n\
    \  void set_val_fast(I i, T x) {\n    static vector<Ptr> ps;\n    ps.clear();\n\
    \    Ptr t = root;\n    while (t) {\n      _push(t);\n      ps.push_back(t);\n\
    \      if (i == t->key) break;\n      t = i < t->key ? t->l : t->r;\n    }\n \
    \   if (!t) {\n      set_val(i, x);\n      return;\n    }\n    t->val = x;\n \
    \   for (int j = ps.size() - 1; j >= 0; j--) _update(ps[j]);\n  }\n\n  // 1 \u70B9\
    \u53D6\u5F97\n  T get_val(I i) {\n    Ptr p = _find(root, i);\n    return p ?\
    \ p->val : ti();\n  }\n  bool exist(I i) {\n    Ptr p = _find(root, i);\n    return\
    \ p != nullptr;\n  }\n\n  // 1 \u70B9 \u5024\u306E\u66F8\u304D\u63DB\u3048\n \
    \ // func \u306E\u8FD4\u308A\u5024\u306F void !!!!!!(\u53C2\u7167\u3055\u308C\u305F\
    \u5024\u3092\u76F4\u63A5\u66F4\u65B0\u3059\u308B)\n  void apply_val(I i, const\
    \ function<void(T &)> &func) {\n    auto s = _split_by_key3(root, i);\n    if\
    \ (s[1] == nullptr) s[1] = _my_new(i);\n    func(s[1]->val);\n    root = _merge(_merge(s[0],\
    \ _update(s[1])), s[2]);\n  }\n  // 1 \u70B9 \u5024\u306E\u66F8\u304D\u63DB\u3048\
    \ \u5024\u304C\u65E2\u306B\u5B58\u5728\u3059\u308B\u3068\u304D\u306B\u65E9\u3044\
    \n  // func \u306E\u8FD4\u308A\u5024\u306F void !!!!!!(\u53C2\u7167\u3055\u308C\
    \u305F\u5024\u3092\u76F4\u63A5\u66F4\u65B0\u3059\u308B)\n  void apply_val_fast(I\
    \ i, const function<void(T &)> &func) {\n    static vector<Ptr> ps;\n    ps.clear();\n\
    \    Ptr t = root;\n    while (t) {\n      _push(t);\n      ps.push_back(t);\n\
    \      if (i == t->key) break;\n      t = i < t->key ? t->l : t->r;\n    }\n \
    \   if (!t) {\n      apply_val(i, func);\n      return;\n    }\n    func(t->val);\n\
    \    for (int j = ps.size() - 1; j >= 0; j--) _update(ps[j]);\n  }\n\n  // \u9802\
    \u70B9\u306E\u524A\u9664\n  virtual void erase(I i) { _erase(root, i); }\n\n \
    \ // \u7BC4\u56F2\u4F5C\u7528\n  void apply(I l, I r, const E &e) {\n    if (l\
    \ >= r) return;\n    _apply(root, l, r, e);\n  }\n  void apply_all(const E &e)\
    \ { _propagate(root, e); }\n\n  // \u7BC4\u56F2\u53D6\u5F97\n  T fold(I l, I r)\
    \ {\n    if (l >= r) return ti();\n    return _fold(root, l, r);\n  }\n  T fold_all()\
    \ { return _sum(root); }\n\n  void shift(const I &sh) { _shift(root, sh); }\n\n\
    \  // key \u6700\u5C0F\u3092\u53D6\u5F97\n  I get_min_key(I failed = {}) { return\
    \ _get_min_keyval(root, failed).first; }\n  // key \u6700\u5927\u3092\u53D6\u5F97\
    \n  I get_max_key(I failed = {}) { return _get_max_keyval(root, failed).first;\
    \ }\n  // (key, val) \u6700\u5C0F\u3092\u53D6\u5F97\n  pair<I, T> get_min_keyval(I\
    \ failed = {}) {\n    return _get_min_keyval(root, failed);\n  }\n  // (key, val)\
    \ \u6700\u5927\u3092\u53D6\u5F97\n  pair<I, T> get_max_keyval(I failed = {}) {\n\
    \    return _get_max_keyval(root, failed);\n  }\n  // (key, val) \u6700\u5C0F\u3092\
    \ pop\n  pair<I, T> pop_min_keyval(I failed = {}) {\n    assert(root != nullptr);\n\
    \    auto kv = _get_min_keyval(root, failed);\n    erase(kv.first);\n    return\
    \ kv;\n  }\n  // (key, val) \u6700\u5927\u3092\u53D6\u5F97\n  pair<I, T> pop_max_keyval(I\
    \ failed = {}) {\n    assert(root != nullptr);\n    auto kv = _get_max_keyval(root,\
    \ failed);\n    erase(kv.first);\n    return kv;\n  }\n\n  // n \u672A\u6E80\u306E\
    \ i \u306E\u3046\u3061\u3001[i, n) \u306E\u533A\u9593 fold \u304C true \u306B\u306A\
    \u308B\u6700\u5C0F\u306E i \u306F\u4F55\u304B\uFF1F\n  // (\u5B58\u5728\u3057\u306A\
    \u3044\u5834\u5408\u306F failed \u3092\u8FD4\u3059)\n  template <typename C>\n\
    \  I min_left(I n, C check, I failed) {\n    assert(check(ti()) == true);\n  \
    \  auto [x, y] = _split_by_key(root, n);\n    I res = _min_left<C, true>(x, check,\
    \ failed);\n    root = _merge(x, y);\n    return res;\n  }\n\n  // n \u672A\u6E80\
    \u306E i \u306E\u3046\u3061\u3001(i, n) \u306E\u533A\u9593 fold \u304C true \u306B\
    \u306A\u308B\u6700\u5C0F\u306E i \u306F\u4F55\u304B\uFF1F\n  // (\u7A7A\u3060\u3063\
    \u305F\u308A (\u5DE6\u7AEF, n) \u304C \u771F\u306E\u5834\u5408\u306F minus_infty\
    \ \u3092\u8FD4\u3059)\n  template <typename C>\n  I min_left_exclusive(I n, C\
    \ check, I minus_infty) {\n    assert(check(ti()) == true);\n    auto [x, y] =\
    \ _split_by_key(root, n);\n    I res = _min_left<C, false>(x, check, minus_infty);\n\
    \    root = _merge(x, y);\n    return res;\n  }\n\n  // n \u4EE5\u4E0A\u306E i\
    \ \u306E\u3046\u3061\u3001[n, i) \u306E\u533A\u9593 fold \u304C true \u306B\u306A\
    \u308B\u6700\u5927\u306E i \u306F\u4F55\u304B\uFF1F\n  // (\u7A7A\u3060\u3063\u305F\
    \u308A [n, \u53F3\u7AEF] \u304C true \u306E\u5834\u5408\u306F infty \u3092\u8FD4\
    \u3059)\n  template <typename C>\n  I max_right(I n, C check, I infty) {\n   \
    \ assert(check(ti()) == true);\n    auto [x, y] = _split_by_key(root, n);\n  \
    \  I res = _max_right<C, true>(y, check, infty);\n    root = _merge(x, y);\n \
    \   return res;\n  }\n\n  // n \u4EE5\u4E0A\u306E i \u306E\u3046\u3061\u3001[n,\
    \ i] \u306E\u533A\u9593 fold \u304C true \u306B\u306A\u308B\u6700\u5927\u306E\
    \ i \u306F\u4F55\u304B\uFF1F\n  // (\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\
    \u306F failed \u3092\u8FD4\u3059)\n  template <typename C>\n  I max_right_inclusive(I\
    \ n, C check, I failed) {\n    assert(check(ti()) == true);\n    auto [x, y] =\
    \ _split_by_key(root, n);\n    I res = _max_right<C, false>(y, check, failed);\n\
    \    root = _merge(x, y);\n    return res;\n  }\n\n  // (key \u672A\u6E80, key\
    \ \u4EE5\u4E0A) \u3067\u5206\u5272\n  // \u547C\u3073\u51FA\u3057\u5F8C\u306E\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\u306F\u7A7A\u306E\u30BB\u30B0\u6728\u306B\u306A\
    \u308B\n  pair<RBST, RBST> split_by_key(const I &key) {\n    auto [x, y] = _split_by_key(root,\
    \ key);\n    root = nullptr;\n    return make_pair(RBST{x}, RBST{y});\n  }\n \
    \ // [i, inf) \u306E\u533A\u9593\u7A4D\u304C (false, true) \u306B\u306A\u308B\u5883\
    \u754C\u3067\u5206\u5272\n  // \u547C\u3073\u51FA\u3057\u5F8C\u306E\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u306F\u7A7A\u306E\u30BB\u30B0\u6728\u306B\u306A\u308B\
    \n  template <typename C>\n  pair<RBST, RBST> split_min_left(const C &check) {\n\
    \    assert(check(ti()) == true);\n    auto [x, y] = _split_min_left(root, check);\n\
    \    root = nullptr;\n    return make_pair(RBST{x}, RBST{y});\n  }\n  // (-inf,\
    \ i] \u306E\u533A\u9593\u7A4D\u304C (true, false) \u306B\u306A\u308B\u5883\u754C\
    \u3067\u5206\u5272\n  // \u547C\u3073\u51FA\u3057\u5F8C\u306E\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u306F\u7A7A\u306E\u30BB\u30B0\u6728\u306B\u306A\u308B\n  template\
    \ <typename C>\n  pair<RBST, RBST> split_max_right(const C &check) {\n    assert(check(ti())\
    \ == true);\n    auto [x, y] = _split_max_right(root, check);\n    root = nullptr;\n\
    \    return make_pair(RBST{x}, RBST{y});\n  }\n\n  void clear() { _clear(root),\
    \ root = nullptr; }\n  int size() { return _count(root); }\n  bool empty() { return\
    \ !root; }\n  void dump() {\n    cerr << \"***** dump start *****\" << endl;\n\
    \    _dump(root);\n    cerr << \"****** dump end ******\" << endl;\n  }\n\n  //\
    \ \u5217\u3092\u914D\u5217\u306B\u5909\u63DB\u3057\u3066\u8FD4\u3059\n  vector<pair<I,\
    \ T>> make_array() {\n    vector<pair<I, T>> res;\n    _make_array(root, res);\n\
    \    return res;\n  }\n};\n\nnamespace RBSTSegmentTreeImpl {\nbool _ei() { return\
    \ false; }\n\ntemplate <typename I, typename T, typename E, T (*f)(T, T), T (*g)(T,\
    \ E),\n          E (*h)(E, E), T (*ti)(), E (*ei)()>\nstruct ShiftableLazySegNode\
    \ {\n  ShiftableLazySegNode *l, *r;\n  I key, shift;\n  T val, sum;\n  E lazy;\n\
    \  int cnt;\n  ShiftableLazySegNode(const I &i, const T &t = ti())\n      : l(),\
    \ r(), key(i), shift(I{}), val(t), sum(t), lazy(ei()), cnt(1) {}\n};\ntemplate\
    \ <typename I, typename T, typename E, T (*f)(T, T), T (*g)(T, E),\n         \
    \ E (*h)(E, E), T (*ti)(), E (*ei)()>\nusing RBSTShiftableLazySegmentTree =\n\
    \    RBSTSegmentTreeBase<ShiftableLazySegNode<I, T, E, f, g, h, ti, ei>, I, T,\
    \ E,\n                        f, g, h, ti, ei>;\n\ntemplate <typename I, typename\
    \ T, typename E, T (*f)(T, T), T (*g)(T, E),\n          E (*h)(E, E), T (*ti)(),\
    \ E (*ei)()>\nstruct LazySegNode {\n  LazySegNode *l, *r;\n  I key;\n  T val,\
    \ sum;\n  E lazy;\n  int cnt;\n  LazySegNode(const I &i, const T &t = ti())\n\
    \      : l(), r(), key(i), val(t), sum(t), lazy(ei()), cnt(1) {}\n};\ntemplate\
    \ <typename I, typename T, typename E, T (*f)(T, T), T (*g)(T, E),\n         \
    \ E (*h)(E, E), T (*ti)(), E (*ei)()>\nusing RBSTLazySegmentTree =\n    RBSTSegmentTreeBase<LazySegNode<I,\
    \ T, E, f, g, h, ti, ei>, I, T, E, f, g, h,\n                        ti, ei>;\n\
    \ntemplate <typename I, typename T, T (*f)(T, T), T (*ti)()>\nstruct SegNode {\n\
    \  SegNode *l, *r;\n  I key;\n  T val, sum;\n  int cnt;\n  SegNode(const I &i,\
    \ const T &t = ti())\n      : l(), r(), key(i), val(t), sum(t), cnt(1) {}\n};\n\
    template <typename I, typename T, T (*f)(T, T), T (*ti)()>\nusing RBSTSegmentTree\
    \ = RBSTSegmentTreeBase<SegNode<I, T, f, ti>, I, T, bool, f,\n               \
    \                             nullptr, nullptr, ti, _ei>;\n\n}  // namespace RBSTSegmentTreeImpl\n\
    \nusing RBSTSegmentTreeImpl::RBSTLazySegmentTree;\nusing RBSTSegmentTreeImpl::RBSTSegmentTree;\n\
    using RBSTSegmentTreeImpl::RBSTShiftableLazySegmentTree;\n\n/**\n * @brief RBST-based\
    \ Dynamic Lazy Segment Tree\n */\n#line 9 \"data-structure/slope-trick-weighted.hpp\"\
    \n\nnamespace SlopeTrickImpl {\n\ntemplate <typename Int>\nusing T = pair<Int,\
    \ Int>;\ntemplate <typename Int>\nusing E = Int;\ntemplate <typename Int>\nT<Int>\
    \ f(T<Int> a, T<Int> b) {\n  return {a.first + b.first, a.second + b.second};\n\
    }\ntemplate <typename Int>\nT<Int> g(T<Int> a, E<Int> b) {\n  return {a.first,\
    \ a.second + a.first * b};\n}\ntemplate <typename Int>\nE<Int> h(E<Int> a, E<Int>\
    \ b) {\n  return a + b;\n}\ntemplate <typename Int>\nT<Int> ti() {\n  return {};\n\
    }\ntemplate <typename Int>\nE<Int> ei() {\n  return {};\n}\ntemplate <typename\
    \ Int>\nusing SegTree = RBSTShiftableLazySegmentTree<Int, T<Int>, E<Int>, f<Int>,\n\
    \                                             g<Int>, h<Int>, ti<Int>, ei<Int>>;\n\
    }  // namespace SlopeTrickImpl\n\ntemplate <typename I>\nstruct WeightedSlopeTrick\
    \ {\n  static constexpr I inf = (I{1} << (sizeof(I) * 8 - 2)) - 1;\n  using Seg\
    \ = typename SlopeTrickImpl::SegTree<I>;\n  using T = SlopeTrickImpl::T<I>;\n\
    \  using E = SlopeTrickImpl::E<I>;\n\n  // x : \u5EA7\u6A19, c : \u50BE\u304D\u306E\
    \u5909\u5316\u91CF\n  struct P {\n    I x, c;\n    P(I _x, I _c) : x(_x), c(_c)\
    \ {}\n  };\n\n private:\n  Seg L, R;\n  I min_y;\n\n  // seg[x] += c\n  void _apply(Seg&\
    \ seg, I x, I c) {\n    if (c == 0) return;\n    seg.apply_val_fast(x, [&](T&\
    \ t) {\n      t.first += c;\n      t.second += x * c;\n    });\n  }\n  void _push_L(I\
    \ x, I c = 1) { _apply(L, x, c); }\n  void _push_R(I x, I c = 1) { _apply(R, x,\
    \ c); }\n  P _get_L() {\n    assert(!L.empty());\n    auto kv = L.get_max_keyval();\n\
    \    return P{kv.first, kv.second.first};\n  }\n  P _get_R() {\n    assert(!R.empty());\n\
    \    auto kv = R.get_min_keyval();\n    return P{kv.first, kv.second.first};\n\
    \  }\n  P _getpop_L() {\n    assert(!L.empty());\n    auto kv = L.pop_max_keyval();\n\
    \    return P{kv.first, kv.second.first};\n  }\n  P _getpop_R() {\n    assert(!R.empty());\n\
    \    auto kv = R.pop_min_keyval();\n    return P{kv.first, kv.second.first};\n\
    \  }\n  pair<Seg, Seg> _split_L(I c) {\n    assert(L.fold_all().first >= c);\n\
    \    pair<Seg, Seg> res =\n        L.split_min_left([&](const T& t) { return t.first\
    \ <= c; });\n    c -= res.second.fold_all().first;\n    if (c != 0) {\n      I\
    \ k = res.first.get_max_key();\n      _apply(res.first, k, -c);\n      _apply(res.second,\
    \ k, c);\n    }\n    return res;\n  }\n  pair<Seg, Seg> _split_R(I c) {\n    assert(R.fold_all().first\
    \ >= c);\n    pair<Seg, Seg> res =\n        R.split_max_right([&](const T& t)\
    \ { return t.first <= c; });\n    c -= res.first.fold_all().first;\n    if (c\
    \ != 0) {\n      I k = res.second.get_min_key();\n      _apply(res.first, k, c);\n\
    \      _apply(res.second, k, -c);\n    }\n    return res;\n  }\n  // destructive\
    \ merge\n  Seg _unite(Seg& lhs, Seg& rhs) {\n    if (lhs.empty()) return rhs;\n\
    \    if (rhs.empty()) return lhs;\n    assert(lhs.get_max_key() <= rhs.get_min_key()\
    \ && \"WeightSlopTrick::_unite\");\n    if (lhs.get_max_key() == rhs.get_min_key())\
    \ {\n      auto [x, p] = lhs.pop_max_keyval();\n      _apply(rhs, x, p.first);\n\
    \    }\n    if (lhs.empty()) return rhs;\n    if (rhs.empty()) return lhs;\n \
    \   return ordered_merge(lhs, rhs);\n  }\n\n public:\n  WeightedSlopeTrick() :\
    \ min_y(0) {}\n\n  void debug() {\n    auto LL = L.make_array(), RR = R.make_array();\n\
    \    cerr << \"L : \";\n    for (auto& [k, v] : LL) cerr << \"( \" << k << \"\
    , \" << v.first << \" ), \";\n    cerr << endl << \"R : \";\n    for (auto& [k,\
    \ v] : RR) cerr << \"( \" << k << \", \" << v.first << \" ), \";\n    cerr <<\
    \ endl << \"min : ( \";\n    cerr << get_min().first << \", \" << get_min().second\
    \ << \" )\" << endl;\n  }\n\n  // return {x, y} s.t. {argmin, min}\n  pair<I,\
    \ I> get_min() {\n    I x = L.empty() ? R.empty() ? 0 : _get_R().x : _get_L().x;\n\
    \    return {x, min_y};\n  }\n\n  void shift_L(I a) { L.shift(a), L.apply_all(a);\
    \ }\n  void shift_R(I a) { R.shift(a), R.apply_all(a); }\n  // f(x) <- f(x - a)\n\
    \  void shift_x(I a) { shift_L(a), shift_R(a); }\n  // f(x) <- f(x) + a\n  void\
    \ shift_y(I a) { min_y += a; }\n\n  // add (x-a)_+   _____/\n  void add_xma(I\
    \ a, I c = 1) {\n    _apply(L, a, c);\n    auto [L1, L2] = _split_L(c);\n    auto\
    \ [c_sum, ac_sum] = L2.fold(a, inf);\n    min_y += ac_sum - c_sum * a;\n    auto\
    \ c2 = L2.get_val(a);\n    L2.erase(a);\n    R = _unite(L2, R);\n    _apply(R,\
    \ a, c2.first);\n    L = L1;\n  }\n\n  // add (a-x)_+   \\_____\n  void add_amx(I\
    \ a, I c = 1) {\n    _apply(R, a, c);\n    auto [R1, R2] = _split_R(c);\n    auto\
    \ [c_sum, ac_sum] = R1.fold(-inf, a);\n    min_y += c_sum * a - ac_sum;\n    auto\
    \ c2 = R1.get_val(a);\n    R1.erase(a);\n    L = _unite(L, R1);\n    _apply(L,\
    \ a, c2.first);\n    R = R2;\n  }\n\n  // add |x-a|     \\____/\n  void add_abs_xma(I\
    \ a, I c = 1) {\n    add_xma(a, c);\n    add_amx(a, c);\n  }\n\n  //  chmin right\
    \ side \\_/ -> \\__\n  void chmin_right() { R.clear(); }\n  //  chmin left side\
    \  \\_/ -> __/\n  void chmin_left() { L.clear(); }\n\n  // destructive merge\n\
    \  void merge(WeightedSlopeTrick& r) {\n    if (L.size() + R.size() < r.L.size()\
    \ + r.R.size()) swap(*this, r);\n    for (auto& [x, t] : r.L.make_array()) add_amx(x,\
    \ t.first);\n    for (auto& [x, t] : r.R.make_array()) add_xma(x, t.first);\n\
    \    shift_y(r.min_y);\n  }\n\n  I eval(I x) {\n    I res = min_y;\n    if (!L.empty()\
    \ && _get_L().x > x) {\n      auto [L1, L2] = L.split_by_key(x);\n      auto [c_sum,\
    \ xc_sum] = L2.fold_all();\n      res += xc_sum - c_sum * x;\n      L = _unite(L1,\
    \ L2);\n    }\n    if (!R.empty() && _get_R().x < x) {\n      auto [R1, R2] =\
    \ R.split_by_key(x);\n      auto [c_sum, xc_sum] = R1.fold_all();\n      res +=\
    \ c_sum * x - xc_sum;\n      R = _unite(R1, R2);\n    }\n    return res;\n  }\n\
    \n  void clear() { L.clear(), R.clear(), min_y = 0; }\n};\n\nusing SlopeTrick\
    \ = WeightedSlopeTrick<__int128_t>;\n\n/**\n * @brief Weighted Slope Trick\n */\n\
    #line 6 \"verify/verify-yuki/yuki-1467-weighted.test.cpp\"\n\nusing namespace\
    \ Nyaan;\n\n/*\n\n// https://atcoder.jp/contests/abc127/tasks/abc127_f\nvoid ABC127F()\
    \ {\n  ini(Q);\n  SlopeTrick st;\n  rep(i, Q) {\n    ini(c);\n    if (c == 1)\
    \ {\n      inl(a, b);\n      st.add_abs_xma(a);\n      st.shift_y(b);\n    } else\
    \ {\n      out(st.get_min());\n    }\n  }\n}\n\n// https://atcoder.jp/contests/dwango2016-prelims/tasks/dwango2016qual_e\n\
    void dwacon2016qual_E() {\n  ini(N, L);\n  vvi ls(TEN(5) + 10);\n  rep(i, N) {\n\
    \    ini(t, l);\n    ls[t].push_back(l);\n  }\n  SlopeTrick st;\n  rep(i, sz(ls))\
    \ {\n    if (ls.empty()) continue;\n    st.chmin_right();\n    each(x, ls[i])\
    \ st.add_abs_xma(x);\n  }\n  out(st.get_min().second);\n}\n\n// https://atcoder.jp/contests/utpc2012/tasks/utpc2012_12\n\
    void utpc2012_L() {\n  ini(N, C0);\n  vl C(N);\n  C[0] = C0;\n  vvi g(N);\n  rep1(i,\
    \ N - 1) {\n    ini(p, c);\n    --p;\n    g[p].push_back(i);\n    C[i] = c;\n\
    \  }\n  auto dfs = [&](auto rc, int c) -> SlopeTrick {\n    SlopeTrick st;\n \
    \   each(d, g[c]) {\n      SlopeTrick stc = rc(rc, d);\n      stc.shift_x(1);\n\
    \      st.merge(stc);\n    }\n    st.add_abs_xma(C[c]);\n    st.chmin_right();\n\
    \    return move(st);\n  };\n  out(dfs(dfs, 0).get_min().second);\n}\n\n// https://atcoder.jp/contests/arc070/tasks/arc070_c\n\
    void ARC070C() {\n  inl(N);\n  vl a(N), b(N);\n  in2(a, b);\n  SlopeTrick st;\n\
    \  rep(i, N) {\n    if (i) {\n      st.shift_L(a[i] - b[i]);\n      st.shift_R(b[i\
    \ - 1] - a[i - 1]);\n    }\n    st.add_abs_xma(a[i]);\n  }\n  out(st.get_min().second);\n\
    }\n\n#include \"../../segment-tree/segment-tree.hpp\"\n\n// https://atcoder.jp/contests/abc275/tasks/abc275_h\n\
    void ABC275Ex() {\n  inl(N);\n  vl A(N), B(N);\n  in(A, B);\n  vp init(N);\n \
    \ rep(i, N) init[i] = {B[i], i};\n  SegmentTree seg(\n      init, [](pl a, pl\
    \ b) { return max(a, b); }, pl{-infLL, -1});\n  i128 ans = 0;\n  auto dfs = [&](auto\
    \ rc, int l, int r) -> SlopeTrick {\n    if (l == r) return {};\n    auto [v,\
    \ m] = seg.query(l, r);\n    SlopeTrick L = rc(rc, l, m + 0);\n    SlopeTrick\
    \ R = rc(rc, m + 1, r);\n    L.merge(R);\n    L.add_amx(A[m], infLL);\n    L.add_xma(0,\
    \ v);\n    L.chmin_left();\n    L.add_amx(inf, v);\n    ans += -ll(inf) * v;\n\
    \    return L;\n  };\n  auto f0 = dfs(dfs, 0, N);\n  out(ans + f0.eval(0));\n\
    }\n\nvoid ABC217H() {\n  inl(N);\n  SlopeTrick st;\n  st.add_abs_xma(0, 1e6);\n\
    \  ll last = 0;\n  rep(i, N) {\n    inl(t, d, x);\n    st.shift_L(-(t - last));\n\
    \    st.shift_R(t - last);\n    last = t;\n    if (d == 0) {\n      st.add_amx(x);\n\
    \    } else {\n      st.add_xma(x);\n    }\n  }\n  out(st.get_min().second);\n\
    }\n\n*/\n\n// https://yukicoder.me/problems/no/1467\nvoid yuki1467() {\n  ini(M,\
    \ N);\n  vl A(M), B(N);\n  in(A, B);\n  vl zip{A};\n  each(x, B) zip.push_back(x);\n\
    \  zip = mkuni(zip);\n  vl as(sz(zip)), bs(sz(zip));\n  each(x, A) as[lb(zip,\
    \ x)]++;\n  each(x, B) bs[lb(zip, x)]++;\n  rep1(k, M) {\n    SlopeTrick st;\n\
    \    st.add_amx(0, TEN(10));\n    rep(i, sz(zip)) {\n      st.shift_x(as[i] -\
    \ bs[i] * k);\n      st.chmin_right();\n      if (i != sz(zip) - 1) {\n      \
    \  st.add_abs_xma(0, zip[i + 1] - zip[i]);\n      } else {\n        st.add_xma(0,\
    \ 1e10);\n      }\n    }\n    out(ll(st.get_min().second));\n    st.clear();\n\
    \  }\n}\n\nvoid Nyaan::solve() {\n  // ABC127F();\n  // dwacon2016qual_E();\n\
    \  // utpc2012_L();\n  // ARC070C();\n  yuki1467();\n  // ABC275Ex();\n  // ABC217H();\n\
    }\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1467\"\n//\n#include \"\
    ../../template/template.hpp\"\n//\n#include \"../../data-structure/slope-trick-weighted.hpp\"\
    \n\nusing namespace Nyaan;\n\n/*\n\n// https://atcoder.jp/contests/abc127/tasks/abc127_f\n\
    void ABC127F() {\n  ini(Q);\n  SlopeTrick st;\n  rep(i, Q) {\n    ini(c);\n  \
    \  if (c == 1) {\n      inl(a, b);\n      st.add_abs_xma(a);\n      st.shift_y(b);\n\
    \    } else {\n      out(st.get_min());\n    }\n  }\n}\n\n// https://atcoder.jp/contests/dwango2016-prelims/tasks/dwango2016qual_e\n\
    void dwacon2016qual_E() {\n  ini(N, L);\n  vvi ls(TEN(5) + 10);\n  rep(i, N) {\n\
    \    ini(t, l);\n    ls[t].push_back(l);\n  }\n  SlopeTrick st;\n  rep(i, sz(ls))\
    \ {\n    if (ls.empty()) continue;\n    st.chmin_right();\n    each(x, ls[i])\
    \ st.add_abs_xma(x);\n  }\n  out(st.get_min().second);\n}\n\n// https://atcoder.jp/contests/utpc2012/tasks/utpc2012_12\n\
    void utpc2012_L() {\n  ini(N, C0);\n  vl C(N);\n  C[0] = C0;\n  vvi g(N);\n  rep1(i,\
    \ N - 1) {\n    ini(p, c);\n    --p;\n    g[p].push_back(i);\n    C[i] = c;\n\
    \  }\n  auto dfs = [&](auto rc, int c) -> SlopeTrick {\n    SlopeTrick st;\n \
    \   each(d, g[c]) {\n      SlopeTrick stc = rc(rc, d);\n      stc.shift_x(1);\n\
    \      st.merge(stc);\n    }\n    st.add_abs_xma(C[c]);\n    st.chmin_right();\n\
    \    return move(st);\n  };\n  out(dfs(dfs, 0).get_min().second);\n}\n\n// https://atcoder.jp/contests/arc070/tasks/arc070_c\n\
    void ARC070C() {\n  inl(N);\n  vl a(N), b(N);\n  in2(a, b);\n  SlopeTrick st;\n\
    \  rep(i, N) {\n    if (i) {\n      st.shift_L(a[i] - b[i]);\n      st.shift_R(b[i\
    \ - 1] - a[i - 1]);\n    }\n    st.add_abs_xma(a[i]);\n  }\n  out(st.get_min().second);\n\
    }\n\n#include \"../../segment-tree/segment-tree.hpp\"\n\n// https://atcoder.jp/contests/abc275/tasks/abc275_h\n\
    void ABC275Ex() {\n  inl(N);\n  vl A(N), B(N);\n  in(A, B);\n  vp init(N);\n \
    \ rep(i, N) init[i] = {B[i], i};\n  SegmentTree seg(\n      init, [](pl a, pl\
    \ b) { return max(a, b); }, pl{-infLL, -1});\n  i128 ans = 0;\n  auto dfs = [&](auto\
    \ rc, int l, int r) -> SlopeTrick {\n    if (l == r) return {};\n    auto [v,\
    \ m] = seg.query(l, r);\n    SlopeTrick L = rc(rc, l, m + 0);\n    SlopeTrick\
    \ R = rc(rc, m + 1, r);\n    L.merge(R);\n    L.add_amx(A[m], infLL);\n    L.add_xma(0,\
    \ v);\n    L.chmin_left();\n    L.add_amx(inf, v);\n    ans += -ll(inf) * v;\n\
    \    return L;\n  };\n  auto f0 = dfs(dfs, 0, N);\n  out(ans + f0.eval(0));\n\
    }\n\nvoid ABC217H() {\n  inl(N);\n  SlopeTrick st;\n  st.add_abs_xma(0, 1e6);\n\
    \  ll last = 0;\n  rep(i, N) {\n    inl(t, d, x);\n    st.shift_L(-(t - last));\n\
    \    st.shift_R(t - last);\n    last = t;\n    if (d == 0) {\n      st.add_amx(x);\n\
    \    } else {\n      st.add_xma(x);\n    }\n  }\n  out(st.get_min().second);\n\
    }\n\n*/\n\n// https://yukicoder.me/problems/no/1467\nvoid yuki1467() {\n  ini(M,\
    \ N);\n  vl A(M), B(N);\n  in(A, B);\n  vl zip{A};\n  each(x, B) zip.push_back(x);\n\
    \  zip = mkuni(zip);\n  vl as(sz(zip)), bs(sz(zip));\n  each(x, A) as[lb(zip,\
    \ x)]++;\n  each(x, B) bs[lb(zip, x)]++;\n  rep1(k, M) {\n    SlopeTrick st;\n\
    \    st.add_amx(0, TEN(10));\n    rep(i, sz(zip)) {\n      st.shift_x(as[i] -\
    \ bs[i] * k);\n      st.chmin_right();\n      if (i != sz(zip) - 1) {\n      \
    \  st.add_abs_xma(0, zip[i + 1] - zip[i]);\n      } else {\n        st.add_xma(0,\
    \ 1e10);\n      }\n    }\n    out(ll(st.get_min().second));\n    st.clear();\n\
    \  }\n}\n\nvoid Nyaan::solve() {\n  // ABC127F();\n  // dwacon2016qual_E();\n\
    \  // utpc2012_L();\n  // ARC070C();\n  yuki1467();\n  // ABC275Ex();\n  // ABC217H();\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - data-structure/slope-trick-weighted.hpp
  - segment-tree/rbst-segment-tree.hpp
  - internal/internal-type-traits.hpp
  isVerificationFile: true
  path: verify/verify-yuki/yuki-1467-weighted.test.cpp
  requiredBy: []
  timestamp: '2024-09-14 20:40:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yuki/yuki-1467-weighted.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yuki/yuki-1467-weighted.test.cpp
- /verify/verify/verify-yuki/yuki-1467-weighted.test.cpp.html
title: verify/verify-yuki/yuki-1467-weighted.test.cpp
---