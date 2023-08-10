---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  - icon: ':heavy_check_mark:'
    path: math/primitive-root.hpp
    title: "\u539F\u59CB\u6839"
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/arbitrary-ntt.hpp
    title: ntt/arbitrary-ntt.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/cooley-tukey-ntt.hpp
    title: Cooley-Tukey FFT Algorithm
  - icon: ':heavy_check_mark:'
    path: ntt/ntt.hpp
    title: ntt/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/rader-ntt.hpp
    title: Rader's FFT Algorithm
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#line\
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
    \ 4 \"verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp\"\
    \n//\n#line 2 \"misc/fastio.hpp\"\n\n#line 8 \"misc/fastio.hpp\"\n\nusing namespace\
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
    \                                              \\\n  template <class, class =\
    \ void>                                         \\\n  struct has_##var : std::false_type\
    \ {};                                 \\\n  template <class T>               \
    \                                      \\\n  struct has_##var<T, std::void_t<typename\
    \ T::var>> : std::true_type {}; \\\n  template <class T>                     \
    \                                \\\n  constexpr auto has_##var##_v = has_##var<T>::value;\n\
    \n}  // namespace internal\n#line 12 \"misc/fastio.hpp\"\n\nnamespace fastio {\n\
    static constexpr int SZ = 1 << 17;\nstatic constexpr int offset = 64;\nchar inbuf[SZ],\
    \ outbuf[SZ];\nint in_left = 0, in_right = 0, out_right = 0;\n\nstruct Pre {\n\
    \  char num[40000];\n  constexpr Pre() : num() {\n    for (int i = 0; i < 10000;\
    \ i++) {\n      int n = i;\n      for (int j = 3; j >= 0; j--) {\n        num[i\
    \ * 4 + j] = n % 10 + '0';\n        n /= 10;\n      }\n    }\n  }\n} constexpr\
    \ pre;\n\nvoid load() {\n  int len = in_right - in_left;\n  memmove(inbuf, inbuf\
    \ + in_left, len);\n  in_right = len + fread(inbuf + len, 1, SZ - len, stdin);\n\
    \  in_left = 0;\n}\nvoid flush() {\n  fwrite(outbuf, 1, out_right, stdout);\n\
    \  out_right = 0;\n}\nvoid skip_space() {\n  if (in_left + offset > in_right)\
    \ load();\n  while (inbuf[in_left] <= ' ') in_left++;\n}\n\nvoid single_read(char&\
    \ c) {\n  if (in_left + offset > in_right) load();\n  skip_space();\n  c = inbuf[in_left++];\n\
    }\nvoid single_read(string& S) {\n  skip_space();\n  while (true) {\n    if (in_left\
    \ == in_right) load();\n    int i = in_left;\n    for (; i != in_right; i++) {\n\
    \      if (inbuf[i] <= ' ') break;\n    }\n    copy(inbuf + in_left, inbuf + i,\
    \ back_inserter(S));\n    in_left = i;\n    if (i != in_right) break;\n  }\n}\n\
    template <typename T,\n          enable_if_t<internal::is_broadly_integral_v<T>>*\
    \ = nullptr>\nvoid single_read(T& x) {\n  if (in_left + offset > in_right) load();\n\
    \  skip_space();\n  char c = inbuf[in_left++];\n  [[maybe_unused]] bool minus\
    \ = false;\n  if constexpr (internal::is_broadly_signed_v<T>) {\n    if (c ==\
    \ '-') minus = true, c = inbuf[in_left++];\n  }\n  x = 0;\n  while (c >= '0')\
    \ {\n    x = x * 10 + (c & 15);\n    c = inbuf[in_left++];\n  }\n  if constexpr\
    \ (internal::is_broadly_signed_v<T>) {\n    if (minus) x = -x;\n  }\n}\nvoid rd()\
    \ {}\ntemplate <typename Head, typename... Tail>\nvoid rd(Head& head, Tail&...\
    \ tail) {\n  single_read(head);\n  rd(tail...);\n}\n\nvoid single_write(const\
    \ char& c) {\n  if (out_right > SZ - offset) flush();\n  outbuf[out_right++] =\
    \ c;\n}\nvoid single_write(const bool& b) {\n  if (out_right > SZ - offset) flush();\n\
    \  outbuf[out_right++] = b ? '1' : '0';\n}\nvoid single_write(const string& S)\
    \ {\n  flush(), fwrite(S.data(), 1, S.size(), stdout);\n}\nvoid single_write(const\
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
    \ head, const Tail&... tail) {\n  single_write(head);\n  wt(forward<const Tail>(tail)...);\n\
    }\ntemplate <typename... Args>\nvoid wtn(const Args&... x) {\n  wt(forward<const\
    \ Args>(x)...);\n  wt('\\n');\n}\n\nstruct Dummy {\n  Dummy() { atexit(flush);\
    \ }\n} dummy;\n\n}  // namespace fastio\nusing fastio::rd;\nusing fastio::skip_space;\n\
    using fastio::wt;\nusing fastio::wtn;\n#line 2 \"modint/montgomery-modint.hpp\"\
    \n\ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n\
    \  using i32 = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n\
    \  static constexpr u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i <\
    \ 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n  static constexpr u32\
    \ r = get_r();\n  static constexpr u32 n2 = -u64(mod) % mod;\n  static_assert(mod\
    \ < (1 << 30), \"invalid, mod >= 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"\
    invalid, mod % 2 == 0\");\n  static_assert(r * mod == 1, \"this code has bugs.\"\
    );\n\n  u32 a;\n\n  constexpr LazyMontgomeryModInt() : a(0) {}\n  constexpr LazyMontgomeryModInt(const\
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
    \ { return mod; }\n};\n#line 2 \"ntt/cooley-tukey-ntt.hpp\"\n\n#line 2 \"ntt/rader-ntt.hpp\"\
    \n\n#line 2 \"math/primitive-root.hpp\"\n\nconstexpr uint32_t PrimitiveRoot(uint32_t\
    \ mod) {\n  using u64 = uint64_t;\n  if (mod == 2) return 1;\n  u64 ds[32] = {};\n\
    \  int idx = 0;\n  u64 m = mod - 1;\n  for (u64 i = 2; i * i <= m; ++i) {\n  \
    \  if (m % i == 0) {\n      ds[idx++] = i;\n      while (m % i == 0) m /= i;\n\
    \    }\n  }\n  if (m != 1) ds[idx++] = m;\n\n  uint32_t pr = 2;\n  while (1) {\n\
    \    int flg = 1;\n    for (int i = 0; i < idx; ++i) {\n      u64 a = pr, b =\
    \ (mod - 1) / ds[i], r = 1;\n      while (b) {\n        if (b & 1) r = r * a %\
    \ mod;\n        a = a * a % mod;\n        b >>= 1;\n      }\n      if (r == 1)\
    \ {\n        flg = 0;\n        break;\n      }\n    }\n    if (flg == 1) break;\n\
    \    ++pr;\n  }\n  return pr;\n}\n\n/**\n * @brief \u539F\u59CB\u6839\n */\n#line\
    \ 2 \"ntt/arbitrary-ntt.hpp\"\n\n#line 2 \"ntt/ntt.hpp\"\n\ntemplate <typename\
    \ mint>\nstruct NTT {\n  static constexpr uint32_t get_pr() {\n    uint32_t _mod\
    \ = mint::get_mod();\n    using u64 = uint64_t;\n    u64 ds[32] = {};\n    int\
    \ idx = 0;\n    u64 m = _mod - 1;\n    for (u64 i = 2; i * i <= m; ++i) {\n  \
    \    if (m % i == 0) {\n        ds[idx++] = i;\n        while (m % i == 0) m /=\
    \ i;\n      }\n    }\n    if (m != 1) ds[idx++] = m;\n\n    uint32_t _pr = 2;\n\
    \    while (1) {\n      int flg = 1;\n      for (int i = 0; i < idx; ++i) {\n\
    \        u64 a = _pr, b = (_mod - 1) / ds[i], r = 1;\n        while (b) {\n  \
    \        if (b & 1) r = r * a % _mod;\n          a = a * a % _mod;\n         \
    \ b >>= 1;\n        }\n        if (r == 1) {\n          flg = 0;\n          break;\n\
    \        }\n      }\n      if (flg == 1) break;\n      ++_pr;\n    }\n    return\
    \ _pr;\n  };\n\n  static constexpr uint32_t mod = mint::get_mod();\n  static constexpr\
    \ uint32_t pr = get_pr();\n  static constexpr int level = __builtin_ctzll(mod\
    \ - 1);\n  mint dw[level], dy[level];\n\n  void setwy(int k) {\n    mint w[level],\
    \ y[level];\n    w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));\n    y[k - 1]\
    \ = w[k - 1].inverse();\n    for (int i = k - 2; i > 0; --i)\n      w[i] = w[i\
    \ + 1] * w[i + 1], y[i] = y[i + 1] * y[i + 1];\n    dw[1] = w[1], dy[1] = y[1],\
    \ dw[2] = w[2], dy[2] = y[2];\n    for (int i = 3; i < k; ++i) {\n      dw[i]\
    \ = dw[i - 1] * y[i - 2] * w[i];\n      dy[i] = dy[i - 1] * w[i - 2] * y[i];\n\
    \    }\n  }\n\n  NTT() { setwy(level); }\n\n  void fft4(vector<mint> &a, int k)\
    \ {\n    if ((int)a.size() <= 1) return;\n    if (k == 1) {\n      mint a1 = a[1];\n\
    \      a[1] = a[0] - a[1];\n      a[0] = a[0] + a1;\n      return;\n    }\n  \
    \  if (k & 1) {\n      int v = 1 << (k - 1);\n      for (int j = 0; j < v; ++j)\
    \ {\n        mint ajv = a[j + v];\n        a[j + v] = a[j] - ajv;\n        a[j]\
    \ += ajv;\n      }\n    }\n    int u = 1 << (2 + (k & 1));\n    int v = 1 << (k\
    \ - 2 - (k & 1));\n    mint one = mint(1);\n    mint imag = dw[1];\n    while\
    \ (v) {\n      // jh = 0\n      {\n        int j0 = 0;\n        int j1 = v;\n\
    \        int j2 = j1 + v;\n        int j3 = j2 + v;\n        for (; j0 < v; ++j0,\
    \ ++j1, ++j2, ++j3) {\n          mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 =\
    \ a[j3];\n          mint t0p2 = t0 + t2, t1p3 = t1 + t3;\n          mint t0m2\
    \ = t0 - t2, t1m3 = (t1 - t3) * imag;\n          a[j0] = t0p2 + t1p3, a[j1] =\
    \ t0p2 - t1p3;\n          a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;\n        }\n\
    \      }\n      // jh >= 1\n      mint ww = one, xx = one * dw[2], wx = one;\n\
    \      for (int jh = 4; jh < u;) {\n        ww = xx * xx, wx = ww * xx;\n    \
    \    int j0 = jh * v;\n        int je = j0 + v;\n        int j2 = je + v;\n  \
    \      for (; j0 < je; ++j0, ++j2) {\n          mint t0 = a[j0], t1 = a[j0 + v]\
    \ * xx, t2 = a[j2] * ww,\n               t3 = a[j2 + v] * wx;\n          mint\
    \ t0p2 = t0 + t2, t1p3 = t1 + t3;\n          mint t0m2 = t0 - t2, t1m3 = (t1 -\
    \ t3) * imag;\n          a[j0] = t0p2 + t1p3, a[j0 + v] = t0p2 - t1p3;\n     \
    \     a[j2] = t0m2 + t1m3, a[j2 + v] = t0m2 - t1m3;\n        }\n        xx *=\
    \ dw[__builtin_ctzll((jh += 4))];\n      }\n      u <<= 2;\n      v >>= 2;\n \
    \   }\n  }\n\n  void ifft4(vector<mint> &a, int k) {\n    if ((int)a.size() <=\
    \ 1) return;\n    if (k == 1) {\n      mint a1 = a[1];\n      a[1] = a[0] - a[1];\n\
    \      a[0] = a[0] + a1;\n      return;\n    }\n    int u = 1 << (k - 2);\n  \
    \  int v = 1;\n    mint one = mint(1);\n    mint imag = dy[1];\n    while (u)\
    \ {\n      // jh = 0\n      {\n        int j0 = 0;\n        int j1 = v;\n    \
    \    int j2 = v + v;\n        int j3 = j2 + v;\n        for (; j0 < v; ++j0, ++j1,\
    \ ++j2, ++j3) {\n          mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];\n\
    \          mint t0p1 = t0 + t1, t2p3 = t2 + t3;\n          mint t0m1 = t0 - t1,\
    \ t2m3 = (t2 - t3) * imag;\n          a[j0] = t0p1 + t2p3, a[j2] = t0p1 - t2p3;\n\
    \          a[j1] = t0m1 + t2m3, a[j3] = t0m1 - t2m3;\n        }\n      }\n   \
    \   // jh >= 1\n      mint ww = one, xx = one * dy[2], yy = one;\n      u <<=\
    \ 2;\n      for (int jh = 4; jh < u;) {\n        ww = xx * xx, yy = xx * imag;\n\
    \        int j0 = jh * v;\n        int je = j0 + v;\n        int j2 = je + v;\n\
    \        for (; j0 < je; ++j0, ++j2) {\n          mint t0 = a[j0], t1 = a[j0 +\
    \ v], t2 = a[j2], t3 = a[j2 + v];\n          mint t0p1 = t0 + t1, t2p3 = t2 +\
    \ t3;\n          mint t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;\n        \
    \  a[j0] = t0p1 + t2p3, a[j2] = (t0p1 - t2p3) * ww;\n          a[j0 + v] = t0m1\
    \ + t2m3, a[j2 + v] = (t0m1 - t2m3) * ww;\n        }\n        xx *= dy[__builtin_ctzll(jh\
    \ += 4)];\n      }\n      u >>= 4;\n      v <<= 2;\n    }\n    if (k & 1) {\n\
    \      u = 1 << (k - 1);\n      for (int j = 0; j < u; ++j) {\n        mint ajv\
    \ = a[j] - a[j + u];\n        a[j] += a[j + u];\n        a[j + u] = ajv;\n   \
    \   }\n    }\n  }\n\n  void ntt(vector<mint> &a) {\n    if ((int)a.size() <= 1)\
    \ return;\n    fft4(a, __builtin_ctz(a.size()));\n  }\n\n  void intt(vector<mint>\
    \ &a) {\n    if ((int)a.size() <= 1) return;\n    ifft4(a, __builtin_ctz(a.size()));\n\
    \    mint iv = mint(a.size()).inverse();\n    for (auto &x : a) x *= iv;\n  }\n\
    \n  vector<mint> multiply(const vector<mint> &a, const vector<mint> &b) {\n  \
    \  int l = a.size() + b.size() - 1;\n    if (min<int>(a.size(), b.size()) <= 40)\
    \ {\n      vector<mint> s(l);\n      for (int i = 0; i < (int)a.size(); ++i)\n\
    \        for (int j = 0; j < (int)b.size(); ++j) s[i + j] += a[i] * b[j];\n  \
    \    return s;\n    }\n    int k = 2, M = 4;\n    while (M < l) M <<= 1, ++k;\n\
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
    \ * w2;\n  }\n  return ret;\n}\n}  // namespace ArbitraryNTT\n#line 5 \"ntt/rader-ntt.hpp\"\
    \n\ntemplate <typename mint>\nstruct RaderNTT {\n  int p, pr, len;\n  const vector<mint>&\
    \ w;\n  vector<int> prs, iprs;\n  RaderNTT() {}\n  RaderNTT(int _p, int _len,\
    \ const vector<mint>& _w)\n      : p(_p), pr(PrimitiveRoot(p)), len(_len), w(_w)\
    \ {\n    prs.resize(p - 1);\n    iprs.resize(p, -1);\n    for (int i = 0; i <\
    \ p - 1; i++) prs[i] = i ? prs[i - 1] * pr % p : 1;\n    for (int i = 0; i < p\
    \ - 1; i++) iprs[prs[i]] = i;\n  }\n\n  void ntt(vector<mint>& a) {\n    vector<mint>\
    \ s(p - 1), t(p - 1);\n    for (int i = 0; i < p - 1; i++) s[i] = a[prs[i]];\n\
    \    for (int i = 0, ldp = len / p; i < p - 1; i++)\n      t[i] = w[ldp * prs[i\
    \ ? p - 1 - i : 0]];\n    vector<mint> u = ArbitraryNTT::multiply(s, t);\n   \
    \ s.resize(p);\n    fill(begin(s), end(s), a[0]);\n    for (int i = 1; i < p;\
    \ i++) s[0] += a[i];\n    for (int i = 0, y = 0; i < (int)u.size(); i++) {\n \
    \     s[prs[y]] += u[i];\n      if (--y < 0) y += p - 1;\n    }\n    swap(a, s);\n\
    \  }\n};\n\n/**\n * @brief Rader's FFT Algorithm\n */\n#line 4 \"ntt/cooley-tukey-ntt.hpp\"\
    \n\ntemplate <typename mint>\nstruct ArbitraryLengthNTT {\n  using i64 = long\
    \ long;\n\n  int factor(int n) {\n    for (int i = 2; i * i <= n; i++)\n     \
    \ if (n % i == 0) return i;\n    return n;\n  }\n\n  vector<int> divisor(int n)\
    \ {\n    vector<int> ret;\n    for (int i = 2; i * i <= n; i++) {\n      if (n\
    \ % i == 0) {\n        ret.push_back(i);\n        ret.push_back(n / i);\n    \
    \  }\n    }\n    ret.push_back(n);\n    sort(begin(ret), end(ret));\n    ret.erase(unique(begin(ret),\
    \ end(ret)), end(ret));\n    return ret;\n  }\n\n  int len;\n  vector<mint> w;\n\
    \  vector<int> divisors;\n  map<int, RaderNTT<mint> *> rader;\n\n  ArbitraryLengthNTT(int\
    \ len_ = -1) { set_len(len_); }\n\n  void set_len(int len_ = -1) {\n    int mod\
    \ = mint::get_mod();\n    if ((len = len_) == -1) len = mod - 1;\n    if (mod\
    \ >= 3 && len <= 1) len = 2;\n    while ((mod - 1) % len != 0) ++len;\n    mint\
    \ pr = mint(PrimitiveRoot(mod)).pow((mod - 1) / len);\n    w.resize(len + 1);\n\
    \    for (int i = 0; i <= len; i++) w[i] = i ? w[i - 1] * pr : mint(1);\n    divisors\
    \ = divisor(len);\n  }\n\n  void dft(vector<mint> &a) {\n    int N = a.size();\n\
    \    if (N == 2) {\n      mint a01 = a[0] + a[1];\n      a[1] = a[0] - a[1];\n\
    \      a[0] = a01;\n      return;\n    }\n    int d = len / N;\n    vector<mint>\
    \ b(N);\n    for (int i = 0, dk = 0; i < N; i++, dk += d) {\n      for (int j\
    \ = 0, k = 0; j < N; j++) {\n        b[j] += a[i] * w[k];\n        if ((k += dk)\
    \ >= len) k -= len;\n      }\n    }\n    swap(a, b);\n  }\n\n  void ntt_base2(vector<mint>\
    \ &a) {\n    static vector<int> btr;\n    int N = a.size();\n    assert(N % 2\
    \ == 0);\n    if (btr.size() != a.size()) {\n      btr.resize(N);\n      int b\
    \ = __builtin_ctz(N);\n      assert(N == (1 << b));\n      for (int i = 0; i <\
    \ N; i++) {\n        btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (b - 1));\n   \
    \   }\n    }\n    static vector<mint> basis;\n    if (basis.size() < a.size())\
    \ {\n      basis.resize(N);\n      mint b = w[len / N];\n      for (int i = N\
    \ >> 1; i > 0; i >>= 1) {\n        mint c = 1;\n        for (int j = 0; j < i;\
    \ ++j) {\n          basis[i + j] = c;\n          c *= b;\n        }\n        b\
    \ *= b;\n      }\n    }\n    for (int i = 0; i < N; i++)\n      if (i < btr[i])\
    \ swap(a[i], a[btr[i]]);\n    for (int k = 1; k < N; k <<= 1) {\n      for (int\
    \ i = 0; i < N; i += 2 * k) {\n        for (int j = 0; j < k; j++) {\n       \
    \   mint z = a[i + j + k] * basis[j + k];\n          a[i + j + k] = a[i + j] -\
    \ z;\n          a[i + j] = a[i + j] + z;\n        }\n      }\n    }\n  }\n\n \
    \ void pntt(vector<mint> &a) {\n    int P = a.size();\n    if (P <= 64) {\n  \
    \    dft(a);\n      return;\n    }\n    if (rader.find(P) == end(rader)) rader[P]\
    \ = new RaderNTT<mint>(P, len, w);\n    rader[P]->ntt(a);\n  }\n\n  void ntt(vector<mint>\
    \ &a) {\n    assert(len % a.size() == 0);\n    int N = (int)a.size();\n    if\
    \ (N <= 1) return;\n    if (N <= 64) {\n      dft(a);\n      return;\n    }\n\n\
    \    int P = factor(N);\n    if (P == N) {\n      pntt(a);\n      return;\n  \
    \  }\n    if (P == 2) {\n      P = 1 << __builtin_ctz(N);\n      if (N == P) {\n\
    \        ntt_base2(a);\n        return;\n      }\n    }\n\n    int Q = N / P;\n\
    \    vector<mint> t(N), u(P);\n    {\n      vector<mint> s(Q);\n      for (int\
    \ p = 0, lN = len / N, d = 0; p < P; p++, d += lN) {\n        for (int q = 0,\
    \ qP = 0; q < Q; q++, qP += P) s[q] = a[qP + p];\n        ntt(s);\n        for\
    \ (int r = 0, n = 0, pQ = p * Q; r < Q; ++r, n += d) {\n          t[pQ + r] =\
    \ w[n] * s[r];\n        }\n      }\n    }\n    for (int r = 0; r < Q; r++) {\n\
    \      for (int p = 0, pQ = 0; p < P; p++, pQ += Q) u[p] = t[pQ + r];\n      if\
    \ (P <= 64)\n        dft(u);\n      else if (P & 1)\n        pntt(u);\n      else\n\
    \        ntt_base2(u);\n      for (int s = 0, sQ = 0; s < P; s++, sQ += Q) a[sQ\
    \ + r] = u[s];\n    }\n  }\n\n  void intt(vector<mint> &a) {\n    reverse(begin(a)\
    \ + 1, end(a));\n    ntt(a);\n    mint invn = mint(a.size()).inverse();\n    for\
    \ (auto &x : a) x *= invn;\n  }\n\n  vector<mint> multiply(const vector<mint>\
    \ &a, const vector<mint> &b) {\n    int N = (int)a.size() + (int)b.size() - 1;\n\
    \    assert(N <= len);\n    vector<mint> s(a), t(b);\n    int l = *lower_bound(begin(divisors),\
    \ end(divisors), N);\n    s.resize(l, mint(0));\n    t.resize(l, mint(0));\n \
    \   ntt(s);\n    ntt(t);\n    for (int i = 0; i < l; i++) s[i] *= t[i];\n    intt(s);\n\
    \    s.resize(N);\n    return s;\n  }\n};\n\n/**\n * @brief Cooley-Tukey FFT Algorithm\n\
    \ */\n#line 8 \"verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp\"\
    \n\nusing namespace Nyaan;\nvoid Nyaan::solve() {\n  using mint = LazyMontgomeryModInt<998244353>;\n\
    \  ArbitraryLengthNTT<mint> ntt(7 * 17 * (1 << 14));\n  int N, M, x;\n  rd(N,\
    \ M);\n  V<mint> a(N), b(M);\n  for (int i = 0; i < N; i++) rd(x), a[i] = x;\n\
    \  for (int i = 0; i < M; i++) rd(x), b[i] = x;\n  auto c = ntt.multiply(a, b);\n\
    \  for (int i = 0; i < (int)N + M - 1; i++) {\n    wt(c[i].get(), (i == (int)N\
    \ + M - 1 ? '\\n' : ' '));\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../misc/fastio.hpp\"\n#include\
    \ \"../../modint/montgomery-modint.hpp\"\n#include \"../../ntt/cooley-tukey-ntt.hpp\"\
    \n\nusing namespace Nyaan;\nvoid Nyaan::solve() {\n  using mint = LazyMontgomeryModInt<998244353>;\n\
    \  ArbitraryLengthNTT<mint> ntt(7 * 17 * (1 << 14));\n  int N, M, x;\n  rd(N,\
    \ M);\n  V<mint> a(N), b(M);\n  for (int i = 0; i < N; i++) rd(x), a[i] = x;\n\
    \  for (int i = 0; i < M; i++) rd(x), b[i] = x;\n  auto c = ntt.multiply(a, b);\n\
    \  for (int i = 0; i < (int)N + M - 1; i++) {\n    wt(c[i].get(), (i == (int)N\
    \ + M - 1 ? '\\n' : ' '));\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - misc/fastio.hpp
  - internal/internal-type-traits.hpp
  - modint/montgomery-modint.hpp
  - ntt/cooley-tukey-ntt.hpp
  - ntt/rader-ntt.hpp
  - math/primitive-root.hpp
  - ntt/arbitrary-ntt.hpp
  - ntt/ntt.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
  requiredBy: []
  timestamp: '2023-08-10 14:25:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
- /verify/verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp.html
title: verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
---
