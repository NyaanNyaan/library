---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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
    path: tree/convert-tree.hpp
    title: "\u6839\u4ED8\u304D\u6728\u30FB\u9006\u8FBA\u304B\u3089\u306A\u308B\u6728\
      \u3078\u306E\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: tree/heavy-light-decomposition.hpp
    title: "Heavy Light Decomposition(\u91CD\u8EFD\u5206\u89E3)"
  - icon: ':heavy_check_mark:'
    path: tree/static-top-tree-vertex-based.hpp
    title: Static Top Tree
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
  bundledCode: "#line 1 \"verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root.test.cpp\"\
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
    \ 4 \"verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root.test.cpp\"\
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
    \ { return mod; }\n};\n#line 6 \"verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root.test.cpp\"\
    \n//\n#line 2 \"tree/static-top-tree-vertex-based.hpp\"\n\n#line 6 \"tree/static-top-tree-vertex-based.hpp\"\
    \nusing namespace std;\n\n#line 2 \"tree/convert-tree.hpp\"\n\n#line 2 \"graph/graph-template.hpp\"\
    \n\ntemplate <typename T>\nstruct edge {\n  int src, to;\n  T cost;\n\n  edge(int\
    \ _to, T _cost) : src(-1), to(_to), cost(_cost) {}\n  edge(int _src, int _to,\
    \ T _cost) : src(_src), to(_to), cost(_cost) {}\n\n  edge &operator=(const int\
    \ &x) {\n    to = x;\n    return *this;\n  }\n\n  operator int() const { return\
    \ to; }\n};\ntemplate <typename T>\nusing Edges = vector<edge<T>>;\ntemplate <typename\
    \ T>\nusing WeightedGraph = vector<Edges<T>>;\nusing UnweightedGraph = vector<vector<int>>;\n\
    \n// Input of (Unweighted) Graph\nUnweightedGraph graph(int N, int M = -1, bool\
    \ is_directed = false,\n                      bool is_1origin = true) {\n  UnweightedGraph\
    \ g(N);\n  if (M == -1) M = N - 1;\n  for (int _ = 0; _ < M; _++) {\n    int x,\
    \ y;\n    cin >> x >> y;\n    if (is_1origin) x--, y--;\n    g[x].push_back(y);\n\
    \    if (!is_directed) g[y].push_back(x);\n  }\n  return g;\n}\n\n// Input of\
    \ Weighted Graph\ntemplate <typename T>\nWeightedGraph<T> wgraph(int N, int M\
    \ = -1, bool is_directed = false,\n                        bool is_1origin = true)\
    \ {\n  WeightedGraph<T> g(N);\n  if (M == -1) M = N - 1;\n  for (int _ = 0; _\
    \ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    cin >> c;\n  \
    \  if (is_1origin) x--, y--;\n    g[x].emplace_back(x, y, c);\n    if (!is_directed)\
    \ g[y].emplace_back(y, x, c);\n  }\n  return g;\n}\n\n// Input of Edges\ntemplate\
    \ <typename T>\nEdges<T> esgraph([[maybe_unused]] int N, int M, int is_weighted\
    \ = true,\n                 bool is_1origin = true) {\n  Edges<T> es;\n  for (int\
    \ _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n\
    \      cin >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    es.emplace_back(x,\
    \ y, c);\n  }\n  return es;\n}\n\n// Input of Adjacency Matrix\ntemplate <typename\
    \ T>\nvector<vector<T>> adjgraph(int N, int M, T INF, int is_weighted = true,\n\
    \                           bool is_directed = false, bool is_1origin = true)\
    \ {\n  vector<vector<T>> d(N, vector<T>(N, INF));\n  for (int _ = 0; _ < M; _++)\
    \ {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n     \
    \ cin >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    d[x][y]\
    \ = c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/graph/graph-template.md\n\
    \ */\n#line 4 \"tree/convert-tree.hpp\"\n\ntemplate <typename T>\nstruct has_cost\
    \ {\n private:\n  template <typename U>\n  static auto confirm(U u) -> decltype(u.cost,\
    \ std::true_type());\n  static auto confirm(...) -> std::false_type;\n\n public:\n\
    \  enum : bool { value = decltype(confirm(std::declval<T>()))::value };\n};\n\n\
    template <typename T>\nvector<vector<T>> inverse_tree(const vector<vector<T>>&\
    \ g) {\n  int N = (int)g.size();\n  vector<vector<T>> rg(N);\n  for (int i = 0;\
    \ i < N; i++) {\n    for (auto& e : g[i]) {\n      if constexpr (is_same<T, int>::value)\
    \ {\n        rg[e].push_back(i);\n      } else if constexpr (has_cost<T>::value)\
    \ {\n        rg[e].emplace_back(e.to, i, e.cost);\n      } else {\n        assert(0);\n\
    \      }\n    }\n  }\n  return rg;\n}\n\ntemplate <typename T>\nvector<vector<T>>\
    \ rooted_tree(const vector<vector<T>>& g, int root = 0) {\n  int N = (int)g.size();\n\
    \  vector<vector<T>> rg(N);\n  vector<char> v(N, false);\n  v[root] = true;\n\
    \  queue<int> que;\n  que.emplace(root);\n  while (!que.empty()) {\n    auto p\
    \ = que.front();\n    que.pop();\n    for (auto& e : g[p]) {\n      if (v[e] ==\
    \ false) {\n        v[e] = true;\n        que.push(e);\n        rg[p].push_back(e);\n\
    \      }\n    }\n  }\n  return rg;\n}\n\n/**\n * @brief \u6839\u4ED8\u304D\u6728\
    \u30FB\u9006\u8FBA\u304B\u3089\u306A\u308B\u6728\u3078\u306E\u5909\u63DB\n */\n\
    #line 2 \"tree/heavy-light-decomposition.hpp\"\n\n#line 4 \"tree/heavy-light-decomposition.hpp\"\
    \n\ntemplate <typename G>\nstruct HeavyLightDecomposition {\n private:\n  void\
    \ dfs_sz(int cur) {\n    size[cur] = 1;\n    for (auto& dst : g[cur]) {\n    \
    \  if (dst == par[cur]) {\n        if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))\n\
    \          swap(g[cur][0], g[cur][1]);\n        else\n          continue;\n  \
    \    }\n      depth[dst] = depth[cur] + 1;\n      par[dst] = cur;\n      dfs_sz(dst);\n\
    \      size[cur] += size[dst];\n      if (size[dst] > size[g[cur][0]]) {\n   \
    \     swap(dst, g[cur][0]);\n      }\n    }\n  }\n\n  void dfs_hld(int cur) {\n\
    \    down[cur] = id++;\n    for (auto dst : g[cur]) {\n      if (dst == par[cur])\
    \ continue;\n      nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));\n\
    \      dfs_hld(dst);\n    }\n    up[cur] = id;\n  }\n\n  // [u, v)\n  vector<pair<int,\
    \ int>> ascend(int u, int v) const {\n    vector<pair<int, int>> res;\n    while\
    \ (nxt[u] != nxt[v]) {\n      res.emplace_back(down[u], down[nxt[u]]);\n     \
    \ u = par[nxt[u]];\n    }\n    if (u != v) res.emplace_back(down[u], down[v] +\
    \ 1);\n    return res;\n  }\n\n  // (u, v]\n  vector<pair<int, int>> descend(int\
    \ u, int v) const {\n    if (u == v) return {};\n    if (nxt[u] == nxt[v]) return\
    \ {{down[u] + 1, down[v]}};\n    auto res = descend(u, par[nxt[v]]);\n    res.emplace_back(down[nxt[v]],\
    \ down[v]);\n    return res;\n  }\n\n public:\n  G& g;\n  int root, id;\n  vector<int>\
    \ size, depth, down, up, nxt, par;\n  HeavyLightDecomposition(G& _g, int _root\
    \ = 0)\n      : g(_g),\n        root(_root),\n        id(0),\n        size(g.size(),\
    \ 0),\n        depth(g.size(), 0),\n        down(g.size(), -1),\n        up(g.size(),\
    \ -1),\n        nxt(g.size(), root),\n        par(g.size(), root) {\n    dfs_sz(root);\n\
    \    dfs_hld(root);\n  }\n\n  pair<int, int> idx(int i) const { return make_pair(down[i],\
    \ up[i]); }\n\n  template <typename F>\n  void path_query(int u, int v, bool vertex,\
    \ const F& f) {\n    int l = lca(u, v);\n    for (auto&& [a, b] : ascend(u, l))\
    \ {\n      int s = a + 1, t = b;\n      s > t ? f(t, s) : f(s, t);\n    }\n  \
    \  if (vertex) f(down[l], down[l] + 1);\n    for (auto&& [a, b] : descend(l, v))\
    \ {\n      int s = a, t = b + 1;\n      s > t ? f(t, s) : f(s, t);\n    }\n  }\n\
    \n  template <typename F>\n  void path_noncommutative_query(int u, int v, bool\
    \ vertex, const F& f) {\n    int l = lca(u, v);\n    for (auto&& [a, b] : ascend(u,\
    \ l)) f(a + 1, b);\n    if (vertex) f(down[l], down[l] + 1);\n    for (auto&&\
    \ [a, b] : descend(l, v)) f(a, b + 1);\n  }\n\n  template <typename F>\n  void\
    \ subtree_query(int u, bool vertex, const F& f) {\n    f(down[u] + int(!vertex),\
    \ up[u]);\n  }\n\n  int lca(int a, int b) {\n    while (nxt[a] != nxt[b]) {\n\
    \      if (down[a] < down[b]) swap(a, b);\n      a = par[nxt[a]];\n    }\n   \
    \ return depth[a] < depth[b] ? a : b;\n  }\n\n  int dist(int a, int b) { return\
    \ depth[a] + depth[b] - depth[lca(a, b)] * 2; }\n};\n\n/**\n * @brief Heavy Light\
    \ Decomposition(\u91CD\u8EFD\u5206\u89E3)\n * @docs docs/tree/heavy-light-decomposition.md\n\
    \ */\n#line 10 \"tree/static-top-tree-vertex-based.hpp\"\n\nnamespace StaticTopTreeVertexBasedImpl\
    \ {\n\nenum Type { Vertex, Compress, Rake, Add_Edge, Add_Vertex };\n\ntemplate\
    \ <typename G>\nstruct StaticTopTreeVertexBased {\n  const HeavyLightDecomposition<G>&\
    \ hld;\n  vector<vector<int>> g;\n  int root;     // \u5143\u306E\u6728\u306E\
    \ root\n  int tt_root;  // top tree \u306E root\n  vector<int> P, L, R;\n  vector<Type>\
    \ T;\n\n  StaticTopTreeVertexBased(const HeavyLightDecomposition<G>& _hld) : hld(_hld)\
    \ {\n    root = hld.root;\n    g = rooted_tree(hld.g, root);\n    int n = g.size();\n\
    \    P.resize(n, -1), L.resize(n, -1), R.resize(n, -1);\n    T.resize(n, Type::Vertex);\n\
    \    build();\n  }\n\n private:\n  int add(int l, int r, Type t) {\n    if (t\
    \ == Type::Compress or t == Type::Rake) {\n      assert(l != -1 and r != -1);\n\
    \    }\n    if (t == Type::Add_Edge) {\n      assert(l != -1 and r == -1);\n \
    \   }\n    assert(t != Type::Vertex and t != Type::Add_Vertex);\n    int k = P.size();\n\
    \    P.push_back(-1), L.push_back(l), R.push_back(r), T.push_back(t);\n    if\
    \ (l != -1) P[l] = k;\n    if (r != -1) P[r] = k;\n    return k;\n  }\n  int add2(int\
    \ k, int l, int r, Type t) {\n    assert(k < (int)g.size());\n    assert(t ==\
    \ Type::Vertex or t == Type::Add_Vertex);\n    if (t == Type::Vertex) {\n    \
    \  assert(l == -1 and r == -1);\n    } else {\n      assert(l != -1 and r == -1);\n\
    \    }\n    P[k] = -1, L[k] = l, R[k] = r, T[k] = t;\n    if (l != -1) P[l] =\
    \ k;\n    if (r != -1) P[r] = k;\n    return k;\n  }\n  pair<int, int> merge(const\
    \ vector<pair<int, int>>& a, Type t) {\n    assert(!a.empty());\n    if (a.size()\
    \ == 1) return a[0];\n    int sum_s = 0;\n    for (auto& [_, s] : a) sum_s +=\
    \ s;\n    vector<pair<int, int>> b, c;\n    for (auto& [i, s] : a) {\n      (sum_s\
    \ > s ? b : c).emplace_back(i, s);\n      sum_s -= s * 2;\n    }\n    auto [i,\
    \ si] = merge(b, t);\n    auto [j, sj] = merge(c, t);\n    return {add(i, j, t),\
    \ si + sj};\n  }\n  pair<int, int> compress(int i) {\n    vector<pair<int, int>>\
    \ chs;\n    while (true) {\n      chs.push_back(add_vertex(i));\n      if (g[i].empty())\
    \ break;\n      i = g[i][0];\n    }\n    return merge(chs, Type::Compress);\n\
    \  }\n  pair<int, int> rake(int i) {\n    vector<pair<int, int>> chs;\n    for\
    \ (int j = 1; j < (int)g[i].size(); j++) chs.push_back(add_edge(g[i][j]));\n \
    \   if (chs.empty()) return {-1, 0};\n    return merge(chs, Type::Rake);\n  }\n\
    \  pair<int, int> add_edge(int i) {\n    auto [j, sj] = compress(i);\n    return\
    \ {add(j, -1, Type::Add_Edge), sj};\n  }\n  pair<int, int> add_vertex(int i) {\n\
    \    auto [j, sj] = rake(i);\n    return {add2(i, j, -1, j == -1 ? Type::Vertex\
    \ : Type::Add_Vertex), sj + 1};\n  }\n  void build() {\n    auto [i, n] = compress(root);\n\
    \    assert((int)g.size() == n);\n    tt_root = i;\n  }\n};\n\ntemplate <typename\
    \ G, typename Path, typename Point, typename Vertex,\n          typename Compress,\
    \ typename Rake, typename Add_edge,\n          typename Add_vertex>\nstruct DPonStaticTopTreeVertexBased\
    \ {\n  const StaticTopTreeVertexBased<G> tt;\n  vector<Path> path;\n  vector<Point>\
    \ point;\n  const Vertex vertex;\n  const Compress compress;\n  const Rake rake;\n\
    \  const Add_edge add_edge;\n  const Add_vertex add_vertex;\n\n  DPonStaticTopTreeVertexBased(const\
    \ HeavyLightDecomposition<G>& hld,\n                               const Vertex&\
    \ _vertex, const Compress& _compress,\n                               const Rake&\
    \ _rake, const Add_edge& _add_edge,\n                               const Add_vertex&\
    \ _add_vertex)\n      : tt(hld),\n        vertex(_vertex),\n        compress(_compress),\n\
    \        rake(_rake),\n        add_edge(_add_edge),\n        add_vertex(_add_vertex)\
    \ {\n    int n = tt.P.size();\n    path.resize(n), point.resize(n);\n    dfs(tt.tt_root);\n\
    \  }\n\n  Path get() { return path[tt.tt_root]; }\n  void update(int k) {\n  \
    \  while (k != -1) _update(k), k = tt.P[k];\n  }\n\n private:\n  void _update(int\
    \ k) {\n    if (tt.T[k] == Type::Vertex) {\n      path[k] = vertex(k);\n    }\
    \ else if (tt.T[k] == Type::Compress) {\n      path[k] = compress(path[tt.L[k]],\
    \ path[tt.R[k]]);\n    } else if (tt.T[k] == Type::Rake) {\n      point[k] = rake(point[tt.L[k]],\
    \ point[tt.R[k]]);\n    } else if (tt.T[k] == Type::Add_Edge) {\n      point[k]\
    \ = add_edge(path[tt.L[k]]);\n    } else {\n      path[k] = add_vertex(point[tt.L[k]],\
    \ k);\n    }\n  }\n\n  void dfs(int k) {\n    if (tt.L[k] != -1) dfs(tt.L[k]);\n\
    \    if (tt.R[k] != -1) dfs(tt.R[k]);\n    _update(k);\n  }\n};\n\n}  // namespace\
    \ StaticTopTreeVertexBasedImpl\n\nusing StaticTopTreeVertexBasedImpl::DPonStaticTopTreeVertexBased;\n\
    using StaticTopTreeVertexBasedImpl::StaticTopTreeVertexBased;\n\n/*\n\n  // template\n\
    \  using Path = ;\n  using Point = ;\n  auto vertex = [&](int i) -> Path {\n\n\
    \  };\n  auto compress = [&](const Path& p, const Path& c) -> Path {\n\n  };\n\
    \  auto rake = [&](const Point& a, const Point& b) -> Point {\n\n  };\n  auto\
    \ add_edge = [&](const Path& a) -> Point {\n\n  };\n  auto add_vertex = [&](const\
    \ Point& a, int i) -> Path {\n\n  };\n  HeavyLightDecomposition hld{g};\n  DPonStaticTopTreeVertexBased<vector<vector<int>>,\
    \ Path, Point,\n  decltype(vertex), decltype(compress), decltype(rake), decltype(add_edge),\n\
    \                    decltype(add_vertex)>\n      dp(hld, vertex, compress, rake,\
    \ add_edge, add_vertex);\n*/\n\n/**\n * @brief Static Top Tree\n */\n#line 8 \"\
    verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root.test.cpp\"\
    \n//\nusing mint = LazyMontgomeryModInt<998244353>;\n\nstruct Path {\n  mint a,\
    \ b, s, x;\n};\nstruct Point {\n  mint s, x;\n};\nvector<mint> calc(int N, int\
    \ Q, vector<int> A, vector<int> U, vector<int> V,\n                  vector<int>\
    \ B, vector<int> C, vector<int> cmd, vector<int> I,\n                  vector<int>\
    \ X, vector<int> Y) {\n  vector<vector<int>> g(2 * N - 1);\n  rep(e, N - 1) {\n\
    \    g[N + e].push_back(U[e]), g[U[e]].push_back(N + e);\n    g[N + e].push_back(V[e]),\
    \ g[V[e]].push_back(N + e);\n  }\n  auto vertex = [&](int i) -> Path {\n    if\
    \ (i < N) return {1, 0, A[i], 1};\n    int e = i - N;\n    return {B[e], C[e],\
    \ 0, 0};\n  };\n  auto compress = [&](const Path& p, const Path& c) -> Path {\n\
    \    return {p.a * c.a, p.a * c.b + p.b, p.s + p.a * c.s + p.b * c.x, p.x + c.x};\n\
    \  };\n  auto rake = [&](const Point& a, const Point& b) -> Point {\n    return\
    \ {a.s + b.s, a.x + b.x};\n  };\n  auto add_edge = [&](const Path& a) -> Point\
    \ { return {a.s, a.x}; };\n  auto add_vertex = [&](const Point& a, int i) -> Path\
    \ {\n    if (i < N) return {1, 0, a.s + A[i], a.x + 1};\n    int e = i - N;\n\
    \    return {B[e], C[e], a.s * B[e] + a.x * C[e], a.x};\n  };\n\n  HeavyLightDecomposition\
    \ hld{g};\n  DPonStaticTopTreeVertexBased<\n      vector<vector<int>>, Path, Point,\
    \ decltype(vertex), decltype(compress),\n      decltype(rake), decltype(add_edge),\
    \ decltype(add_vertex)>\n      dp(hld, vertex, compress, rake, add_edge, add_vertex);\n\
    \n  vector<mint> ans(Q);\n  rep(q, Q) {\n    if (cmd[q] == 0) {\n      A[I[q]]\
    \ = X[q];\n      dp.update(I[q]);\n    } else {\n      B[I[q]] = X[q], C[I[q]]\
    \ = Y[q];\n      dp.update(N + I[q]);\n    }\n    ans[q] = dp.get().s;\n  }\n\
    \  return ans;\n}\n\nvoid Nyaan::solve() {\n  int N, Q;\n  in(N, Q);\n  vector<int>\
    \ A(N);\n  for (auto& x : A) in(x);\n  vector<int> U(N - 1), V(N - 1), B(N - 1),\
    \ C(N - 1);\n  rep(i, N - 1) in(U[i], V[i], B[i], C[i]);\n  vector<int> cmd(Q),\
    \ I(Q), X(Q), Y(Q, -1);\n  rep(i, Q) {\n    in(cmd[i], I[i], X[i]);\n    if (cmd[i]\
    \ == 1) in(Y[i]);\n  }\n  auto ac = calc(N, Q, A, U, V, B, C, cmd, I, X, Y);\n\
    \  for (auto& x : ac) out(x.get());\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n//\n#include \"../../template/template.hpp\"\n//\n#include \"../../modint/montgomery-modint.hpp\"\
    \n//\n#include \"../../tree/static-top-tree-vertex-based.hpp\"\n//\nusing mint\
    \ = LazyMontgomeryModInt<998244353>;\n\nstruct Path {\n  mint a, b, s, x;\n};\n\
    struct Point {\n  mint s, x;\n};\nvector<mint> calc(int N, int Q, vector<int>\
    \ A, vector<int> U, vector<int> V,\n                  vector<int> B, vector<int>\
    \ C, vector<int> cmd, vector<int> I,\n                  vector<int> X, vector<int>\
    \ Y) {\n  vector<vector<int>> g(2 * N - 1);\n  rep(e, N - 1) {\n    g[N + e].push_back(U[e]),\
    \ g[U[e]].push_back(N + e);\n    g[N + e].push_back(V[e]), g[V[e]].push_back(N\
    \ + e);\n  }\n  auto vertex = [&](int i) -> Path {\n    if (i < N) return {1,\
    \ 0, A[i], 1};\n    int e = i - N;\n    return {B[e], C[e], 0, 0};\n  };\n  auto\
    \ compress = [&](const Path& p, const Path& c) -> Path {\n    return {p.a * c.a,\
    \ p.a * c.b + p.b, p.s + p.a * c.s + p.b * c.x, p.x + c.x};\n  };\n  auto rake\
    \ = [&](const Point& a, const Point& b) -> Point {\n    return {a.s + b.s, a.x\
    \ + b.x};\n  };\n  auto add_edge = [&](const Path& a) -> Point { return {a.s,\
    \ a.x}; };\n  auto add_vertex = [&](const Point& a, int i) -> Path {\n    if (i\
    \ < N) return {1, 0, a.s + A[i], a.x + 1};\n    int e = i - N;\n    return {B[e],\
    \ C[e], a.s * B[e] + a.x * C[e], a.x};\n  };\n\n  HeavyLightDecomposition hld{g};\n\
    \  DPonStaticTopTreeVertexBased<\n      vector<vector<int>>, Path, Point, decltype(vertex),\
    \ decltype(compress),\n      decltype(rake), decltype(add_edge), decltype(add_vertex)>\n\
    \      dp(hld, vertex, compress, rake, add_edge, add_vertex);\n\n  vector<mint>\
    \ ans(Q);\n  rep(q, Q) {\n    if (cmd[q] == 0) {\n      A[I[q]] = X[q];\n    \
    \  dp.update(I[q]);\n    } else {\n      B[I[q]] = X[q], C[I[q]] = Y[q];\n   \
    \   dp.update(N + I[q]);\n    }\n    ans[q] = dp.get().s;\n  }\n  return ans;\n\
    }\n\nvoid Nyaan::solve() {\n  int N, Q;\n  in(N, Q);\n  vector<int> A(N);\n  for\
    \ (auto& x : A) in(x);\n  vector<int> U(N - 1), V(N - 1), B(N - 1), C(N - 1);\n\
    \  rep(i, N - 1) in(U[i], V[i], B[i], C[i]);\n  vector<int> cmd(Q), I(Q), X(Q),\
    \ Y(Q, -1);\n  rep(i, Q) {\n    in(cmd[i], I[i], X[i]);\n    if (cmd[i] == 1)\
    \ in(Y[i]);\n  }\n  auto ac = calc(N, Q, A, U, V, B, C, cmd, I, X, Y);\n  for\
    \ (auto& x : ac) out(x.get());\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - modint/montgomery-modint.hpp
  - tree/static-top-tree-vertex-based.hpp
  - tree/convert-tree.hpp
  - graph/graph-template.hpp
  - tree/heavy-light-decomposition.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root.test.cpp
  requiredBy: []
  timestamp: '2024-05-03 23:21:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root.test.cpp
- /verify/verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root.test.cpp.html
title: verify/verify-yosupo-graph/yosupo-point-set-tree-path-composite-sum-fixed-root.test.cpp
---
