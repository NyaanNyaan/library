---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  - icon: ':heavy_check_mark:'
    path: math-fast/gcd.hpp
    title: binary GCD
  - icon: ':heavy_check_mark:'
    path: math/rational.hpp
    title: math/rational.hpp
  - icon: ':heavy_check_mark:'
    path: math/stern-brocot-tree-binary-search.hpp
    title: math/stern-brocot-tree-binary-search.hpp
  - icon: ':heavy_check_mark:'
    path: math/stern-brocot-tree.hpp
    title: Stern-Brocot Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/stern_brocot_tree
    links:
    - https://judge.yosupo.jp/problem/stern_brocot_tree
  bundledCode: "#line 1 \"verify/verify-yosupo-math/yosupo-stern-brocot-tree-2.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\n//\n\
    #line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n#include\
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
    \ 4 \"verify/verify-yosupo-math/yosupo-stern-brocot-tree-2.test.cpp\"\n//\n#line\
    \ 2 \"math/rational.hpp\"\n\n#line 6 \"math/rational.hpp\"\nusing namespace std;\n\
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
    \ long, __int128_t>;\n#line 2 \"math/stern-brocot-tree-binary-search.hpp\"\n\n\
    #line 5 \"math/stern-brocot-tree-binary-search.hpp\"\nusing namespace std;\n\n\
    #line 2 \"math/stern-brocot-tree.hpp\"\n\n#line 6 \"math/stern-brocot-tree.hpp\"\
    \nusing namespace std;\n\n// x / y (x > 0, y > 0) \u3092\u7BA1\u7406\u3001\u30C7\
    \u30D5\u30A9\u30EB\u30C8\u3067 1 / 1\n// \u5165\u529B\u304C\u4E92\u3044\u306B\u7D20\
    \u3067\u306A\u3044\u5834\u5408\u306F gcd \u3092\u53D6\u3063\u3066\u683C\u7D0D\n\
    // seq : (1, 1) \u304B\u3089 (x, y) \u3078\u306E\u30D1\u30B9\u3002\u53F3\u306E\
    \u5B50\u304C\u6B63/\u5DE6\u306E\u5B50\u304C\u8CA0\ntemplate <typename Int>\nstruct\
    \ SternBrocotTreeNode {\n  using Node = SternBrocotTreeNode;\n\n  Int lx, ly,\
    \ x, y, rx, ry;\n  vector<Int> seq;\n\n  SternBrocotTreeNode() : lx(0), ly(1),\
    \ x(1), y(1), rx(1), ry(0) {}\n\n  SternBrocotTreeNode(Int X, Int Y) : SternBrocotTreeNode()\
    \ {\n    assert(1 <= X && 1 <= Y);\n    Int g = gcd(X, Y);\n    X /= g, Y /= g;\n\
    \    while (min(X, Y) > 0) {\n      if (X > Y) {\n        Int d = X / Y;\n   \
    \     X -= d * Y;\n        go_right(d - (X == 0 ? 1 : 0));\n      } else {\n \
    \       Int d = Y / X;\n        Y -= d * X;\n        go_left(d - (Y == 0 ? 1 :\
    \ 0));\n      }\n    }\n  }\n  SternBrocotTreeNode(const pair<Int, Int> &xy)\n\
    \      : SternBrocotTreeNode(xy.first, xy.second) {}\n  SternBrocotTreeNode(const\
    \ vector<Int> &_seq) : SternBrocotTreeNode() {\n    for (const Int &d : _seq)\
    \ {\n      assert(d != 0);\n      if (d > 0) go_right(d);\n      if (d < 0) go_left(d);\n\
    \    }\n    assert(seq == _seq);\n  }\n\n  // pair<Int, Int> \u578B\u3067\u5206\
    \u6570\u3092 get\n  pair<Int, Int> get() const { return make_pair(x, y); }\n \
    \ // \u533A\u9593\u306E\u4E0B\u9650\n  pair<Int, Int> lower_bound() const { return\
    \ make_pair(lx, ly); }\n  // \u533A\u9593\u306E\u4E0A\u9650\n  pair<Int, Int>\
    \ upper_bound() const { return make_pair(rx, ry); }\n\n  // \u6839\u304B\u3089\
    \u306E\u6DF1\u3055\n  Int depth() const {\n    Int res = 0;\n    for (auto &s\
    \ : seq) res += abs(s);\n    return res;\n  }\n  // \u5DE6\u306E\u5B50\u306B d\
    \ \u9032\u3080\n  void go_left(Int d = 1) {\n    if (d <= 0) return;\n    if (seq.empty()\
    \ or seq.back() > 0) seq.push_back(0);\n    seq.back() -= d;\n    rx += lx * d,\
    \ ry += ly * d;\n    x = rx + lx, y = ry + ly;\n  }\n  // \u53F3\u306E\u5B50\u306B\
    \ d \u9032\u3080\n  void go_right(Int d = 1) {\n    if (d <= 0) return;\n    if\
    \ (seq.empty() or seq.back() < 0) seq.push_back(0);\n    seq.back() += d;\n  \
    \  lx += rx * d, ly += ry * d;\n    x = rx + lx, y = ry + ly;\n  }\n  // \u89AA\
    \u306E\u65B9\u5411\u306B d \u9032\u3080\n  // d \u9032\u3081\u305F\u3089 true,\
    \ \u9032\u3081\u306A\u304B\u3063\u305F\u3089 false \u3092\u8FD4\u3059\n  bool\
    \ go_parent(Int d = 1) {\n    if (d <= 0) return true;\n    while (d != 0) {\n\
    \      if (seq.empty()) return false;\n      Int d2 = min(d, abs(seq.back()));\n\
    \      if (seq.back() > 0) {\n        x -= rx * d2, y -= ry * d2;\n        lx\
    \ = x - rx, ly = y - ry;\n        seq.back() -= d2;\n      } else {\n        x\
    \ -= lx * d2, y -= ly * d2;\n        rx = x - lx, ry = y - ly;\n        seq.back()\
    \ += d2;\n      }\n      d -= d2;\n      if (seq.back() == 0) seq.pop_back();\n\
    \      if (d2 == Int{0}) break;\n    }\n    return true;\n  }\n  // SBT \u4E0A\
    \u306E LCA\n  static Node lca(const Node &lhs, const Node &rhs) {\n    Node n;\n\
    \    for (int i = 0; i < min<int>(lhs.seq.size(), rhs.seq.size()); i++) {\n  \
    \    Int val1 = lhs.seq[i], val2 = rhs.seq[i];\n      if ((val1 < 0) != (val2\
    \ < 0)) break;\n      if (val1 < 0) n.go_left(min(-val1, -val2));\n      if (val1\
    \ > 0) n.go_right(min(val1, val2));\n      if (val1 != val2) break;\n    }\n \
    \   return n;\n  }\n  friend ostream &operator<<(ostream &os, const Node &rhs)\
    \ {\n    os << \"\\n\";\n    os << \"L : ( \" << rhs.lx << \", \" << rhs.ly <<\
    \ \" )\\n\";\n    os << \"M : ( \" << rhs.x << \", \" << rhs.y << \" )\\n\";\n\
    \    os << \"R : ( \" << rhs.rx << \", \" << rhs.ry << \" )\\n\";\n    os << \"\
    seq : {\";\n    for (auto &x : rhs.seq) os << x << \", \";\n    os << \"} \\n\"\
    ;\n    return os;\n  }\n  friend bool operator<(const Node &lhs, const Node &rhs)\
    \ {\n    return lhs.x * rhs.y < rhs.x * lhs.y;\n  }\n  friend bool operator==(const\
    \ Node &lhs, const Node &rhs) {\n    return lhs.x == rhs.x and lhs.y == rhs.y;\n\
    \  }\n};\n\n/**\n *  @brief Stern-Brocot Tree\n */\n#line 8 \"math/stern-brocot-tree-binary-search.hpp\"\
    \n\n// \u5206\u5B50\u3068\u5206\u6BCD\u304C INF \u4EE5\u4E0B\u3067\u3042\u308B\
    \u975E\u8CA0\u306E\u65E2\u7D04\u5206\u6570\u306E\u3046\u3061\u6B21\u306E\u3082\
    \u306E\u3092\u8FD4\u3059\n// first : f(x) \u304C false \u3067\u3042\u308B\u6700\
    \u5927\u306E\u65E2\u7D04\u5206\u6570 x\n// second : f(x) \u304C true \u3067\u3042\
    \u308B\u6700\u5C0F\u306E\u65E2\u7D04\u5206\u6570 x\n// \u305F\u3060\u3057\n//\
    \ - f(0) = true \u306E\u5834\u5408\u306F (0/1, 0/1) \u3092\u8FD4\u3059\n// - true\
    \ \u306B\u306A\u308B\u5206\u6570\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\
    \u306F (?, 1/0) \u3092\u8FD4\u3059\n// - INF = 0 \u306E\u5834\u5408\u306F (0/1,\
    \ 1/0) \u3092\u8FD4\u3059\ntemplate <typename I>\npair<pair<I, I>, pair<I, I>>\
    \ binary_search_on_stern_brocot_tree(\n    function<bool(pair<I, I>)> f, const\
    \ I &INF) {\n  // INF >= 0\n  assert(0 <= INF);\n  SternBrocotTreeNode<I> m;\n\
    \  if (INF == 0) return {m.lower_bound(), m.upper_bound()};\n\n  // INF \u6761\
    \u4EF6\u3092\u8D85\u3048\u308B or f(m) = return_value \u3067\u3042\u308B\n  auto\
    \ over = [&](bool return_value) {\n    return max(m.x, m.y) > INF or f(m.get())\
    \ == return_value;\n  };\n\n  if (f(make_pair(0, 1))) return {m.lower_bound(),\
    \ m.lower_bound()};\n  int go_left = over(true);\n  for (; true; go_left ^= 1)\
    \ {\n    if (go_left) {\n      // f(M) = true -> (L, M] \u306B\u7B54\u3048\u304C\
    \u3042\u308B\n      // (f(L * b + M) = false) or (INF \u8D85\u3048) \u306B\u306A\
    \u308B b \u306E\u6700\u5C0F\u306F\uFF1F\n      I a = 1;\n      for (; true; a\
    \ *= 2) {\n        m.go_left(a);\n        if (over(false)) {\n          m.go_parent(a);\n\
    \          break;\n        }\n      }\n      for (a /= 2; a != 0; a /= 2) {\n\
    \        m.go_left(a);\n        if (over(false)) m.go_parent(a);\n      }\n  \
    \    m.go_left(1);\n      if (max(m.get().first, m.get().second) > INF)\n    \
    \    return {m.lower_bound(), m.upper_bound()};\n    } else {\n      // f(M) =\
    \ false -> (M, R] \u306B\u7B54\u3048\u304C\u3042\u308B\n      // (f(M + R * b)\
    \ = true) or (INF \u8D85\u3048) \u306B\u306A\u308B b \u306E\u6700\u5C0F\u306F\uFF1F\
    \n      I a = 1;\n      for (; true; a *= 2) {\n        m.go_right(a);\n     \
    \   if (over(true)) {\n          m.go_parent(a);\n          break;\n        }\n\
    \      }\n      for (a /= 2; a != 0; a /= 2) {\n        m.go_right(a);\n     \
    \   if (over(true)) m.go_parent(a);\n      }\n      m.go_right(1);\n      if (max(m.get().first,\
    \ m.get().second) > INF)\n        return {m.lower_bound(), m.upper_bound()};\n\
    \    }\n  }\n}\n#line 8 \"verify/verify-yosupo-math/yosupo-stern-brocot-tree-2.test.cpp\"\
    \nusing namespace Nyaan;\n\nusing SBT = SternBrocotTreeNode<ll>;\n\nvoid Nyaan::solve()\
    \ {\n  int T;\n  cin >> T;\n  while (T--) {\n    ins(cmd);\n    if (cmd == \"\
    DECODE_PATH\") {\n      ini(n);\n      SBT f;\n      rep(_, n) {\n        char\
    \ c;\n        in(c);\n        inl(x);\n        if (c == 'R') f.go_right(x);\n\
    \        if (c == 'L') f.go_left(x);\n      }\n      out(f.x, f.y);\n    } else\
    \ if (cmd == \"ENCODE_PATH\") {\n      inl(x, y);\n      SBT f{x, y};\n      cout\
    \ << f.seq.size() << \" \";\n      each(s, f.seq) {\n        cout << (s > 0 ?\
    \ 'R' : 'L') << \" \";\n        cout << abs(s) << \" \";\n      }\n      cout\
    \ << \"\\n\";\n    } else if (cmd == \"LCA\") {\n      inl(x1, y1, x2, y2);\n\
    \      SBT f{x1, y1}, g{x2, y2};\n      SBT h = SBT::lca(f, g);\n      out(h.x,\
    \ h.y);\n    } else if (cmd == \"ANCESTOR\") {\n      inl(k, x, y);\n      SBT\
    \ f{x, y};\n\n      ll l = f.depth() - k;\n      if (l < 0) {\n        out(-1);\n\
    \      } else {\n        bool b = f.go_parent(l);\n        assert(b == true);\n\
    \        out(f.x, f.y);\n      }\n    } else {\n      inl(x, y);\n      auto p\
    \ = binary_search_on_stern_brocot_tree<ll>(\n          [&](pair<ll, ll> f) {\n\
    \            return Rational{x, y} <= Rational{f};\n          },\n          max(x,\
    \ y) - 1);\n      out(p.fi.fi, p.fi.se, p.se.fi, p.se.se);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\n//\n\
    #include \"../../template/template.hpp\"\n//\n#include \"../../math/rational.hpp\"\
    \n#include \"../../math/stern-brocot-tree-binary-search.hpp\"\n#include \"../../math/stern-brocot-tree.hpp\"\
    \nusing namespace Nyaan;\n\nusing SBT = SternBrocotTreeNode<ll>;\n\nvoid Nyaan::solve()\
    \ {\n  int T;\n  cin >> T;\n  while (T--) {\n    ins(cmd);\n    if (cmd == \"\
    DECODE_PATH\") {\n      ini(n);\n      SBT f;\n      rep(_, n) {\n        char\
    \ c;\n        in(c);\n        inl(x);\n        if (c == 'R') f.go_right(x);\n\
    \        if (c == 'L') f.go_left(x);\n      }\n      out(f.x, f.y);\n    } else\
    \ if (cmd == \"ENCODE_PATH\") {\n      inl(x, y);\n      SBT f{x, y};\n      cout\
    \ << f.seq.size() << \" \";\n      each(s, f.seq) {\n        cout << (s > 0 ?\
    \ 'R' : 'L') << \" \";\n        cout << abs(s) << \" \";\n      }\n      cout\
    \ << \"\\n\";\n    } else if (cmd == \"LCA\") {\n      inl(x1, y1, x2, y2);\n\
    \      SBT f{x1, y1}, g{x2, y2};\n      SBT h = SBT::lca(f, g);\n      out(h.x,\
    \ h.y);\n    } else if (cmd == \"ANCESTOR\") {\n      inl(k, x, y);\n      SBT\
    \ f{x, y};\n\n      ll l = f.depth() - k;\n      if (l < 0) {\n        out(-1);\n\
    \      } else {\n        bool b = f.go_parent(l);\n        assert(b == true);\n\
    \        out(f.x, f.y);\n      }\n    } else {\n      inl(x, y);\n      auto p\
    \ = binary_search_on_stern_brocot_tree<ll>(\n          [&](pair<ll, ll> f) {\n\
    \            return Rational{x, y} <= Rational{f};\n          },\n          max(x,\
    \ y) - 1);\n      out(p.fi.fi, p.fi.se, p.se.fi, p.se.se);\n    }\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - math/rational.hpp
  - internal/internal-type-traits.hpp
  - math-fast/gcd.hpp
  - math/stern-brocot-tree-binary-search.hpp
  - math/stern-brocot-tree.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-math/yosupo-stern-brocot-tree-2.test.cpp
  requiredBy: []
  timestamp: '2023-12-18 23:52:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-math/yosupo-stern-brocot-tree-2.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-math/yosupo-stern-brocot-tree-2.test.cpp
- /verify/verify/verify-yosupo-math/yosupo-stern-brocot-tree-2.test.cpp.html
title: verify/verify-yosupo-math/yosupo-stern-brocot-tree-2.test.cpp
---
