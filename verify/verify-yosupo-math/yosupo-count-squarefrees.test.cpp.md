---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/enumerate-quotient.hpp
    title: "\u5546\u306E\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: math/isqrt.hpp
    title: math/isqrt.hpp
  - icon: ':heavy_check_mark:'
    path: multiplicative-function/count-square-free.hpp
    title: "\u7121\u5E73\u65B9\u6570\u306E\u6570\u3048\u4E0A\u3052"
  - icon: ':heavy_check_mark:'
    path: multiplicative-function/enamurate-multiplicative-function.hpp
    title: "\u4E57\u6CD5\u7684\u95A2\u6570\u306E\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: multiplicative-function/mf-famous-series.hpp
    title: "\u6709\u540D\u306A\u4E57\u6CD5\u7684\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: prime/prime-enumerate.hpp
    title: prime/prime-enumerate.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/counting_squarefrees
    links:
    - https://judge.yosupo.jp/problem/counting_squarefrees
  bundledCode: "#line 1 \"verify/verify-yosupo-math/yosupo-count-squarefrees.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/counting_squarefrees\"\n//\n\
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
    \ 4 \"verify/verify-yosupo-math/yosupo-count-squarefrees.test.cpp\"\n//\n#line\
    \ 2 \"multiplicative-function/count-square-free.hpp\"\n\n#line 5 \"multiplicative-function/count-square-free.hpp\"\
    \nusing namespace std;\n\n#line 2 \"math/enumerate-quotient.hpp\"\n\n#line 2 \"\
    math/isqrt.hpp\"\n\n#line 4 \"math/isqrt.hpp\"\nusing namespace std;\n\n// floor(sqrt(n))\
    \ \u3092\u8FD4\u3059 (\u305F\u3060\u3057 n \u304C\u8CA0\u306E\u5834\u5408\u306F\
    \ 0 \u3092\u8FD4\u3059)\nlong long isqrt(long long n) {\n  if (n <= 0) return\
    \ 0;\n  long long x = sqrt(n);\n  while ((x + 1) * (x + 1) <= n) x++;\n  while\
    \ (x * x > n) x--;\n  return x;\n}\n#line 4 \"math/enumerate-quotient.hpp\"\n\n\
    namespace EnumerateQuotientImpl {\nlong long fast_div(long long a, long long b)\
    \ { return 1.0 * a / b; };\nlong long slow_div(long long a, long long b) { return\
    \ a / b; };\n}  // namespace EnumerateQuotientImpl\n\n// { (q, l, r) : forall\
    \ x in (l,r], floor(N/x) = q }\n// \u3092\u5F15\u6570\u306B\u53D6\u308B\u95A2\u6570\
    f(q, l, r)\u3092\u6E21\u3059\u3002\u7BC4\u56F2\u304C\u5DE6\u306B\u534A\u958B\u306A\
    \u306E\u306B\u6CE8\u610F\n// \u5546\u306F\u5C0F\u3055\u3044\u65B9\u304B\u3089\u8D70\
    \u67FB\u3059\u308B\ntemplate <typename T, typename F>\nvoid enumerate_quotient(T\
    \ N, const F& f) {\n  T sq = isqrt(N);\n\n#define FUNC(d)                    \
    \   \\\n  T upper = N, quo = 0;               \\\n  while (upper > sq) {     \
    \           \\\n    T thres = d(N, (++quo + 1));      \\\n    f(quo, thres, upper);\
    \             \\\n    upper = thres;                    \\\n  }              \
    \                     \\\n  while (upper > 0) {                 \\\n    f(d(N,\
    \ upper), upper - 1, upper); \\\n    upper--;                          \\\n  }\n\
    \n  if (N <= 1e12) {\n    FUNC(EnumerateQuotientImpl::fast_div);\n  } else {\n\
    \    FUNC(EnumerateQuotientImpl::slow_div);\n  }\n#undef FUNC\n}\n\n/**\n *  @brief\
    \ \u5546\u306E\u5217\u6319\n */\n#line 2 \"multiplicative-function/mf-famous-series.hpp\"\
    \n\n#line 2 \"multiplicative-function/enamurate-multiplicative-function.hpp\"\n\
    \n#line 2 \"prime/prime-enumerate.hpp\"\n\n// Prime Sieve {2, 3, 5, 7, 11, 13,\
    \ 17, ...}\nvector<int> prime_enumerate(int N) {\n  vector<bool> sieve(N / 3 +\
    \ 1, 1);\n  for (int p = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn; p += d = 6\
    \ - d, i++) {\n    if (!sieve[i]) continue;\n    for (int q = p * p / 3, r = d\
    \ * p / 3 + (d * p % 3 == 2), s = 2 * p,\n             qe = sieve.size();\n  \
    \       q < qe; q += r = s - r)\n      sieve[q] = 0;\n  }\n  vector<int> ret{2,\
    \ 3};\n  for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)\n    if (sieve[i])\
    \ ret.push_back(p);\n  while (!ret.empty() && ret.back() > N) ret.pop_back();\n\
    \  return ret;\n}\n#line 5 \"multiplicative-function/enamurate-multiplicative-function.hpp\"\
    \n\n// f(n, p, c) : n = pow(p, c), f is multiplicative function\n\ntemplate <typename\
    \ T, T (*f)(int, int, int)>\nstruct enamurate_multiplicative_function {\n  enamurate_multiplicative_function(int\
    \ _n)\n      : ps(prime_enumerate(_n)), a(_n + 1, T()), n(_n), p(ps.size()) {}\n\
    \n  vector<T> run() {\n    a[1] = 1;\n    dfs(-1, 1, 1);\n    return a;\n  }\n\
    \n private:\n  vector<int> ps;\n  vector<T> a;\n  int n, p;\n  void dfs(int i,\
    \ long long x, T y) {\n    a[x] = y;\n    if (y == T()) return;\n    for (int\
    \ j = i + 1; j < p; j++) {\n      long long nx = x * ps[j];\n      long long dx\
    \ = ps[j];\n      if (nx > n) break;\n      for (int c = 1; nx <= n; nx *= ps[j],\
    \ dx *= ps[j], ++c) {\n        dfs(j, nx, y * f(dx, ps[j], c));\n      }\n   \
    \ }\n  }\n};\n\n/**\n * @brief \u4E57\u6CD5\u7684\u95A2\u6570\u306E\u5217\u6319\
    \n */\n#line 5 \"multiplicative-function/mf-famous-series.hpp\"\n\nnamespace multiplicative_function\
    \ {\ntemplate <typename T>\nT moebius(int, int, int c) {\n  return c == 0 ? 1\
    \ : c == 1 ? -1 : 0;\n}\ntemplate <typename T>\nT sigma0(int, int, int c) {\n\
    \  return c + 1;\n}\ntemplate <typename T>\nT sigma1(int n, int p, int) {\n  return\
    \ (n - 1) / (p - 1) + n;\n}\ntemplate <typename T>\nT totient(int n, int p, int)\
    \ {\n  return n - n / p;\n}\n}  // namespace multiplicative_function\n\ntemplate\
    \ <typename T>\nstatic constexpr vector<T> mobius_function(int n) {\n  enamurate_multiplicative_function<T,\
    \ multiplicative_function::moebius<T>> em(\n      n);\n  return em.run();\n}\n\
    \ntemplate <typename T>\nstatic constexpr vector<T> sigma0(int n) {\n  enamurate_multiplicative_function<T,\
    \ multiplicative_function::sigma0<T>> em(\n      n);\n  return em.run();\n}\n\n\
    template <typename T>\nstatic constexpr vector<T> sigma1(int n) {\n  enamurate_multiplicative_function<T,\
    \ multiplicative_function::sigma1<T>> em(\n      n);\n  return em.run();\n}\n\n\
    template <typename T>\nstatic constexpr vector<T> totient(int n) {\n  enamurate_multiplicative_function<T,\
    \ multiplicative_function::totient<T>> em(\n      n);\n  return em.run();\n}\n\
    \n/**\n * @brief \u6709\u540D\u306A\u4E57\u6CD5\u7684\u95A2\u6570\n * @docs docs/multiplicative-function/mf-famous-series.md\n\
    \ */\n#line 10 \"multiplicative-function/count-square-free.hpp\"\n\nlong long\
    \ count_square_free(long long N) {\n  long long B = pow(N, 0.4);\n\n  auto pre\
    \ = mobius_function<int>(B + 1);\n  for (int i = 1; i <= B; i++) pre[i] += pre[i\
    \ - 1];\n  unordered_map<long long, long long> dp;\n  auto mu = [&](auto rc, long\
    \ long n) -> long long {\n    if (n <= B) return pre[n];\n    if (dp.count(n))\
    \ return dp[n];\n    long long cur = 1;\n    enumerate_quotient(n, [&](long long\
    \ q, long long l, long long r) {\n      if (q != n) cur -= rc(rc, q) * (r - l);\n\
    \    });\n    return dp[n] = cur;\n  };\n\n  long long ans = 0;\n  long long upper\
    \ = isqrt(N);\n  for (long long i = 1; upper > B; i++) {\n    long long nxt =\
    \ isqrt(N / (i + 1));\n    ans += i * (mu(mu, upper) - mu(mu, nxt));\n    upper\
    \ = nxt;\n  }\n  while (upper > 0) {\n    ans += (pre[upper] - pre[upper - 1])\
    \ * (N / (upper * upper));\n    upper--;\n  }\n  return ans;\n}\n\n/**\n * @brief\
    \ \u7121\u5E73\u65B9\u6570\u306E\u6570\u3048\u4E0A\u3052\n */\n#line 6 \"verify/verify-yosupo-math/yosupo-count-squarefrees.test.cpp\"\
    \nusing namespace Nyaan;\n\nvoid q() {\n  inl(N);\n  out(count_square_free(N));\n\
    }\n\nvoid Nyaan::solve() {\n  int t = 1;\n  // in(t);\n  while (t--) q();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_squarefrees\"\n\
    //\n#include \"../../template/template.hpp\"\n//\n#include \"../../multiplicative-function/count-square-free.hpp\"\
    \nusing namespace Nyaan;\n\nvoid q() {\n  inl(N);\n  out(count_square_free(N));\n\
    }\n\nvoid Nyaan::solve() {\n  int t = 1;\n  // in(t);\n  while (t--) q();\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - multiplicative-function/count-square-free.hpp
  - math/enumerate-quotient.hpp
  - math/isqrt.hpp
  - multiplicative-function/mf-famous-series.hpp
  - multiplicative-function/enamurate-multiplicative-function.hpp
  - prime/prime-enumerate.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-math/yosupo-count-squarefrees.test.cpp
  requiredBy: []
  timestamp: '2024-03-04 16:48:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-math/yosupo-count-squarefrees.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-math/yosupo-count-squarefrees.test.cpp
- /verify/verify/verify-yosupo-math/yosupo-count-squarefrees.test.cpp.html
title: verify/verify-yosupo-math/yosupo-count-squarefrees.test.cpp
---
