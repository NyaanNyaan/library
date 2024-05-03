---
data:
  _extendedDependsOn:
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
  - icon: ':heavy_check_mark:'
    path: tree/dynamic-rerooting.hpp
    title: tree/dynamic-rerooting.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
    links:
    - https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
  bundledCode: "#line 1 \"verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root-2.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n//\n#line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n\
    #include <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
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
    \ 4 \"verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root-2.test.cpp\"\
    \n//\n#line 2 \"modint/montgomery-modint.hpp\"\n\ntemplate <uint32_t mod>\nstruct\
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
    \ { return mod; }\n};\n#line 6 \"verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root-2.test.cpp\"\
    \n//\n#line 2 \"tree/dynamic-rerooting.hpp\"\n\nnamespace DynamicRerootingImpl\
    \ {\ntemplate <typename Point, Point (*rake)(const Point &, const Point &)>\n\
    struct SplayTreeforDashedEdge {\n  struct Node {\n    Node *l, *r, *p;\n    Point\
    \ key, sum;\n\n    explicit Node(const Point &_key)\n        : l(nullptr), r(nullptr),\
    \ p(nullptr), key(_key), sum(_key) {}\n  };\n\n  SplayTreeforDashedEdge() {}\n\
    \n  using NP = Node *;\n\n  void rotr(NP t) {\n    NP x = t->p, y = x->p;\n  \
    \  if ((x->l = t->r)) t->r->p = x;\n    t->r = x, x->p = t;\n    update(x), update(t);\n\
    \    if ((t->p = y)) {\n      if (y->l == x) y->l = t;\n      if (y->r == x) y->r\
    \ = t;\n    }\n  }\n\n  void rotl(NP t) {\n    NP x = t->p, y = x->p;\n    if\
    \ ((x->r = t->l)) t->l->p = x;\n    t->l = x, x->p = t;\n    update(x), update(t);\n\
    \    if ((t->p = y)) {\n      if (y->l == x) y->l = t;\n      if (y->r == x) y->r\
    \ = t;\n    }\n  }\n\n  void update(NP t) {\n    t->sum = t->key;\n    if (t->l)\
    \ t->sum = rake(t->sum, t->l->sum);\n    if (t->r) t->sum = rake(t->sum, t->r->sum);\n\
    \  }\n\n  NP get_right(NP t) {\n    while (t->r) t = t->r;\n    return t;\n  }\n\
    \n  NP alloc(const Point &v) {\n    auto t = new Node(v);\n    update(t);\n  \
    \  return t;\n  }\n\n  void splay(NP t) {\n    while (t->p) {\n      NP q = t->p;\n\
    \      if (!q->p) {\n        if (q->l == t)\n          rotr(t);\n        else\n\
    \          rotl(t);\n      } else {\n        NP r = q->p;\n        if (r->l ==\
    \ q) {\n          if (q->l == t)\n            rotr(q), rotr(t);\n          else\n\
    \            rotl(t), rotr(t);\n        } else {\n          if (q->r == t)\n \
    \           rotl(q), rotl(t);\n          else\n            rotr(t), rotl(t);\n\
    \        }\n      }\n    }\n  }\n\n  NP insert(NP t, const Point &v) {\n    if\
    \ (not t) {\n      t = alloc(v);\n      return t;\n    } else {\n      NP cur\
    \ = get_right(t), z = alloc(v);\n      splay(cur);\n      z->p = cur;\n      cur->r\
    \ = z;\n      update(cur);\n      splay(z);\n      return z;\n    }\n  }\n\n \
    \ NP erase(NP t) {\n    splay(t);\n    NP x = t->l, y = t->r;\n    delete t;\n\
    \    if (not x) {\n      t = y;\n      if (t) t->p = nullptr;\n    } else if (not\
    \ y) {\n      t = x;\n      t->p = nullptr;\n    } else {\n      x->p = nullptr;\n\
    \      t = get_right(x);\n      splay(t);\n      t->r = y;\n      y->p = t;\n\
    \      update(t);\n    }\n    return t;\n  }\n};\n\ntemplate <typename Path, typename\
    \ Point, typename Info,\n          Path (*vertex)(const Info &),\n          Path\
    \ (*compress)(const Path &, const Path &),\n          Point (*rake)(const Point\
    \ &, const Point &),\n          Point (*add_edge)(const Path &),\n          Path\
    \ (*add_vertex)(const Point &, const Info &)>\nstruct TopTree {\n private:\n \
    \ struct Node {\n    Node *l, *r, *p;\n    Info info;\n    Path key, sum, mus;\n\
    \    typename SplayTreeforDashedEdge<Point, rake>::Node *light, *belong;\n   \
    \ bool rev;\n\n    bool is_root() const { return not p or (p->l != this and p->r\
    \ != this); }\n\n    explicit Node(const Info _info)\n        : l(nullptr),\n\
    \          r(nullptr),\n          p(nullptr),\n          info(_info),\n      \
    \    light(nullptr),\n          belong(nullptr),\n          rev(false) {}\n  };\n\
    \n public:\n  using NP = Node *;\n  SplayTreeforDashedEdge<Point, rake> splay_tree;\n\
    \n private:\n  void toggle(NP t) {\n    swap(t->l, t->r);\n    swap(t->sum, t->mus);\n\
    \    t->rev ^= true;\n  }\n\n  void rotr(NP t) {\n    NP x = t->p, y = x->p;\n\
    \    push(x), push(t);\n    if ((x->l = t->r)) t->r->p = x;\n    t->r = x, x->p\
    \ = t;\n    update(x), update(t);\n    if ((t->p = y)) {\n      if (y->l == x)\
    \ y->l = t;\n      if (y->r == x) y->r = t;\n    }\n  }\n\n  void rotl(NP t) {\n\
    \    NP x = t->p, y = x->p;\n    push(x), push(t);\n    if ((x->r = t->l)) t->l->p\
    \ = x;\n    t->l = x, x->p = t;\n    update(x), update(t);\n    if ((t->p = y))\
    \ {\n      if (y->l == x) y->l = t;\n      if (y->r == x) y->r = t;\n    }\n \
    \ }\n\n public:\n  TopTree() : splay_tree{} {}\n\n  void push(NP t) {\n    if\
    \ (t->rev) {\n      if (t->l) toggle(t->l);\n      if (t->r) toggle(t->r);\n \
    \     t->rev = false;\n    }\n  }\n\n  void push_rev(NP t) {\n    if (t->rev)\
    \ {\n      if (t->l) toggle(t->l);\n      if (t->r) toggle(t->r);\n      t->rev\
    \ = false;\n    }\n  }\n\n  void update(NP t) {\n    Path key = t->light ? add_vertex(t->light->sum,\
    \ t->info) : vertex(t->info);\n    Path sum = key, mus = key;\n    if (t->l) sum\
    \ = compress(t->l->sum, sum), mus = compress(mus, t->l->mus);\n    if (t->r) sum\
    \ = compress(sum, t->r->sum), mus = compress(t->r->mus, mus);\n    t->key = key,\
    \ t->sum = sum, t->mus = mus;\n  }\n\n  void splay(NP t) {\n    push(t);\n   \
    \ {\n      NP rot = t;\n      while (not rot->is_root()) rot = rot->p;\n     \
    \ t->belong = rot->belong;\n      if (t != rot) rot->belong = nullptr;\n    }\n\
    \    while (not t->is_root()) {\n      NP q = t->p;\n      if (q->is_root()) {\n\
    \        push_rev(q), push_rev(t);\n        if (q->l == t)\n          rotr(t);\n\
    \        else\n          rotl(t);\n      } else {\n        NP r = q->p;\n    \
    \    push_rev(r), push_rev(q), push_rev(t);\n        if (r->l == q) {\n      \
    \    if (q->l == t)\n            rotr(q), rotr(t);\n          else\n         \
    \   rotl(t), rotr(t);\n        } else {\n          if (q->r == t)\n          \
    \  rotl(q), rotl(t);\n          else\n            rotr(t), rotl(t);\n        }\n\
    \      }\n    }\n  }\n\n  NP expose(NP t) {\n    NP rp = nullptr;\n    for (NP\
    \ cur = t; cur; cur = cur->p) {\n      splay(cur);\n      if (cur->r) {\n    \
    \    cur->light = splay_tree.insert(cur->light, add_edge(cur->r->sum));\n    \
    \    cur->r->belong = cur->light;\n      }\n      cur->r = rp;\n      if (cur->r)\
    \ {\n        splay_tree.splay(cur->r->belong);\n        push(cur->r);\n      \
    \  cur->light = splay_tree.erase(cur->r->belong);\n      }\n      update(cur);\n\
    \      rp = cur;\n    }\n    splay(t);\n    return rp;\n  }\n\n  void link(NP\
    \ child, NP parent) {\n    expose(parent);\n    expose(child);\n    child->p =\
    \ parent;\n    parent->r = child;\n    update(parent);\n  }\n\n  void cut(NP child)\
    \ {\n    expose(child);\n    NP parent = child->l;\n    child->l = nullptr;\n\
    \    parent->p = nullptr;\n    update(child);\n  }\n\n  void evert(NP t) {\n \
    \   expose(t);\n    toggle(t);\n    push(t);\n  }\n\n  NP alloc(const Info &info)\
    \ {\n    NP t = new Node(info);\n    update(t);\n    return t;\n  }\n\n  bool\
    \ is_connected(NP u, NP v) {\n    expose(u), expose(v);\n    return u == v or\
    \ u->p;\n  }\n\n  NP lca(NP u, NP v) {\n    if (not is_connected(u, v)) return\
    \ nullptr;\n    expose(u);\n    return expose(v);\n  }\n\n  void set_key(NP t,\
    \ const Info &v) {\n    expose(t);\n    t->info = v;\n    update(t);\n  }\n\n\
    \  // u \u3092\u6839\u3068\u3059\u308B sum\n  Path query(NP u) {\n    evert(u);\n\
    \    return u->sum;\n  }\n\n  // root \u3092\u6839, u \u3092\u90E8\u5206\u6728\
    \u306E\u6839\u3068\u3059\u308B sum\n  Path query_subtree(NP root, NP u) {\n  \
    \  evert(root);\n    expose(u);\n    NP l = u->l;\n    u->l = nullptr;\n    update(u);\n\
    \    auto ret = u->sum;\n    u->l = l;\n    update(u);\n    return ret;\n  }\n\
    };\n\ntemplate <typename Path, typename Point, typename Info,\n          Path\
    \ (*vertex)(const Info &),\n          Path (*compress)(const Path &, const Path\
    \ &),\n          Point (*rake)(const Point &, const Point &),\n          Point\
    \ (*Add_edge)(const Path &),\n          Path (*add_vertex)(const Point &, const\
    \ Info &)>\nstruct DynamicRerooting {\n  int n;\n  TopTree<Path, Point, Info,\
    \ vertex, compress, rake, Add_edge, add_vertex> tt;\n  using NP = typename decltype(tt)::NP;\n\
    \  vector<NP> vs;\n\n  DynamicRerooting(int _n, const vector<Info> &info) : n(_n),\
    \ vs(n) {\n    for (int i = 0; i < n; i++) vs[i] = tt.alloc(info[i]);\n  }\n \
    \ // u-v \u9593\u306B\u8FBA\u3092\u8FFD\u52A0\n  void add_edge(int u, int v) {\n\
    \    tt.evert(vs[u]);\n    tt.link(vs[u], vs[v]);\n  }\n  // u-v \u9593\u306E\u8FBA\
    \u3092\u524A\u9664\n  void del_edge(int u, int v) {\n    tt.evert(vs[u]);\n  \
    \  tt.cut(vs[v]);\n  }\n  // \u9802\u70B9 u \u306E\u60C5\u5831\u3092\u53D6\u5F97\
    \n  Info get_info(int u) { return vs[u]->info; }\n  // \u9802\u70B9 u \u306E\u60C5\
    \u5831\u3092\u8A2D\u5B9A\n  void set_info(int u, const Info &info) { tt.set_key(vs[u],\
    \ info); }\n  // \u9802\u70B9 u \u3092\u6839\u3068\u3059\u308B\u30AF\u30A8\u30EA\
    \n  Path query(int u) { return tt.query(vs[u]); }\n  // \u9802\u70B9 root \u3092\
    \u6839, \u9802\u70B9 u \u3092\u90E8\u5206\u6728\u306E\u6839\u3068\u3059\u308B\u30AF\
    \u30A8\u30EA\n  Path query_subtree(int root, int u) {\n    return tt.query_subtree(vs[root],\
    \ vs[u]);\n  }\n};\n\n}  // namespace DynamicRerootingImpl\n\nusing DynamicRerootingImpl::DynamicRerooting;\n\
    using DynamicRerootingImpl::TopTree;\n\n/*\nstruct Path {\n\n};\nstruct Point\
    \ {\n\n};\nstruct Info {\n\n};\nPath vertex(const Info &i) {\n\n}\nPath compress(const\
    \ Path &p, const Path &c) {\n\n}\nPoint rake(const Point &a, const Point &b) {\n\
    \n}\nPoint add_edge(const Path &a) {\n\n}\nPath add_vertex(const Point &a, const\
    \ Info &i) {\n\n}\n\nusing DR = DynamicRerooting<Path, Point, Info, vertex, compress,\
    \ rake, add_edge,\n                            add_vertex>;\n*/\n#line 8 \"verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root-2.test.cpp\"\
    \n//\nusing mint = LazyMontgomeryModInt<998244353>;\n\nstruct Path {\n  mint a,\
    \ b, s, x;\n};\nstruct Point {\n  mint s, x;\n};\nstruct Info {\n  bool vertex;\n\
    \  mint x, y;\n};\nPath vertex(const Info &i) {\n  if (i.vertex) return {1, 0,\
    \ i.x, 1};\n  return {i.x, i.y, 0, 0};\n}\nPath compress(const Path &p, const\
    \ Path &c) {\n  return {p.a * c.a, p.a * c.b + p.b, p.s + p.a * c.s + p.b * c.x,\
    \ p.x + c.x};\n}\nPoint rake(const Point &a, const Point &b) { return {a.s + b.s,\
    \ a.x + b.x}; }\nPoint add_edge(const Path &a) { return {a.s, a.x}; }\nPath add_vertex(const\
    \ Point &a, const Info &i) {\n  if (i.vertex) return {1, 0, a.s + i.x, a.x + 1};\n\
    \  return {i.x, i.y, a.s * i.x + a.x * i.y, a.x};\n}\n\nusing DR = DynamicRerooting<Path,\
    \ Point, Info, vertex, compress, rake, add_edge,\n                           \
    \ add_vertex>;\n\nusing namespace Nyaan;\n\nvoid Nyaan::solve() {\n  int N, Q;\n\
    \  in(N, Q);\n  vector<int> A(N);\n  for (auto &x : A) in(x);\n  vector<int> U(N\
    \ - 1), V(N - 1), B(N - 1), C(N - 1);\n  for (int i = 0; i < N - 1; i++) in(U[i],\
    \ V[i], B[i], C[i]);\n\n  vector<Info> info(2 * N - 1);\n  for (int i = 0; i <\
    \ N; i++) info[i] = {true, A[i], 0};\n  for (int i = 0; i < N - 1; i++) info[N\
    \ + i] = {false, B[i], C[i]};\n\n  DR dr{2 * N - 1, info};\n  for (int i = 0;\
    \ i < N - 1; i++) {\n    dr.add_edge(N + i, U[i]), dr.add_edge(N + i, V[i]);\n\
    \  }\n\n  while (Q--) {\n    int cmd, i, x;\n    in(cmd, i, x);\n    if (cmd ==\
    \ 0) {\n      dr.set_info(i, {true, x, 0});\n    } else {\n      int y;\n    \
    \  in(y);\n      dr.set_info(N + i, {false, x, y});\n    }\n    out(dr.query(0).s.get());\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n//\n#include \"../../template/template.hpp\"\n//\n#include \"../../modint/montgomery-modint.hpp\"\
    \n//\n#include \"../../tree/dynamic-rerooting.hpp\"\n//\nusing mint = LazyMontgomeryModInt<998244353>;\n\
    \nstruct Path {\n  mint a, b, s, x;\n};\nstruct Point {\n  mint s, x;\n};\nstruct\
    \ Info {\n  bool vertex;\n  mint x, y;\n};\nPath vertex(const Info &i) {\n  if\
    \ (i.vertex) return {1, 0, i.x, 1};\n  return {i.x, i.y, 0, 0};\n}\nPath compress(const\
    \ Path &p, const Path &c) {\n  return {p.a * c.a, p.a * c.b + p.b, p.s + p.a *\
    \ c.s + p.b * c.x, p.x + c.x};\n}\nPoint rake(const Point &a, const Point &b)\
    \ { return {a.s + b.s, a.x + b.x}; }\nPoint add_edge(const Path &a) { return {a.s,\
    \ a.x}; }\nPath add_vertex(const Point &a, const Info &i) {\n  if (i.vertex) return\
    \ {1, 0, a.s + i.x, a.x + 1};\n  return {i.x, i.y, a.s * i.x + a.x * i.y, a.x};\n\
    }\n\nusing DR = DynamicRerooting<Path, Point, Info, vertex, compress, rake, add_edge,\n\
    \                            add_vertex>;\n\nusing namespace Nyaan;\n\nvoid Nyaan::solve()\
    \ {\n  int N, Q;\n  in(N, Q);\n  vector<int> A(N);\n  for (auto &x : A) in(x);\n\
    \  vector<int> U(N - 1), V(N - 1), B(N - 1), C(N - 1);\n  for (int i = 0; i <\
    \ N - 1; i++) in(U[i], V[i], B[i], C[i]);\n\n  vector<Info> info(2 * N - 1);\n\
    \  for (int i = 0; i < N; i++) info[i] = {true, A[i], 0};\n  for (int i = 0; i\
    \ < N - 1; i++) info[N + i] = {false, B[i], C[i]};\n\n  DR dr{2 * N - 1, info};\n\
    \  for (int i = 0; i < N - 1; i++) {\n    dr.add_edge(N + i, U[i]), dr.add_edge(N\
    \ + i, V[i]);\n  }\n\n  while (Q--) {\n    int cmd, i, x;\n    in(cmd, i, x);\n\
    \    if (cmd == 0) {\n      dr.set_info(i, {true, x, 0});\n    } else {\n    \
    \  int y;\n      in(y);\n      dr.set_info(N + i, {false, x, y});\n    }\n   \
    \ out(dr.query(0).s.get());\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - modint/montgomery-modint.hpp
  - tree/dynamic-rerooting.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root-2.test.cpp
  requiredBy: []
  timestamp: '2024-05-03 23:21:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root-2.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root-2.test.cpp
- /verify/verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root-2.test.cpp.html
title: verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root-2.test.cpp
---
