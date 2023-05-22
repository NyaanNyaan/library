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
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  - icon: ':heavy_check_mark:'
    path: multiplicative-function/enumerate-sum-of-multiplicative-function.hpp
    title: "\u4E57\u6CD5\u7684\u95A2\u6570\u306Eprefix sum \u306E\u5217\u6319"
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_totient_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_totient_function
  bundledCode: "#line 1 \"verify/verify-yosupo-math/yosupo-sum-of-totient-3.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\n\
    //\n#line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n\
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
    using vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\n\ntemplate\
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
    \ N,F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n  sort(begin(ord),\
    \ end(ord), f);\n  return ord;\n}\n\ntemplate <typename T>\nvector<int> mkinv(vector<T>\
    \ &v) {\n  int max_val = *max_element(begin(v), end(v));\n  vector<int> inv(max_val\
    \ + 1, -1);\n  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;\n  return\
    \ inv;\n}\n\nvector<int> mkiota(int n) {\n  vector<int> ret(n);\n  iota(begin(ret),\
    \ end(ret), 0);\n  return ret;\n}\n\ntemplate <typename T>\nT mkrev(const T &v)\
    \ {\n  T w{v};\n  reverse(begin(w), end(w));\n  return w;\n}\n\ntemplate <typename\
    \ T>\nbool nxp(vector<T> &v) {\n  return next_permutation(begin(v), end(v));\n\
    }\n\ntemplate <typename T>\nusing minpq = priority_queue<T, vector<T>, greater<T>>;\n\
    \n}  // namespace Nyaan\n#line 58 \"template/template.hpp\"\n\n// bit operation\n\
    #line 1 \"template/bitop.hpp\"\nnamespace Nyaan {\n__attribute__((target(\"popcnt\"\
    ))) inline int popcnt(const u64 &a) {\n  return _mm_popcnt_u64(a);\n}\ninline\
    \ int lsb(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }\ninline int ctz(const\
    \ u64 &a) { return a ? __builtin_ctzll(a) : 64; }\ninline int msb(const u64 &a)\
    \ { return a ? 63 - __builtin_clzll(a) : -1; }\ntemplate <typename T>\ninline\
    \ int gbit(const T &a, int i) {\n  return (a >> i) & 1;\n}\ntemplate <typename\
    \ T>\ninline void sbit(T &a, int i, bool b) {\n  if (gbit(a, i) != b) a ^= T(1)\
    \ << i;\n}\nconstexpr long long PW(int n) { return 1LL << n; }\nconstexpr long\
    \ long MSK(int n) { return (1LL << n) - 1; }\n}  // namespace Nyaan\n#line 61\
    \ \"template/template.hpp\"\n\n// inout\n#line 1 \"template/inout.hpp\"\nnamespace\
    \ Nyaan {\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream &os,\
    \ const pair<T, U> &p) {\n  os << p.first << \" \" << p.second;\n  return os;\n\
    }\ntemplate <typename T, typename U>\nistream &operator>>(istream &is, pair<T,\
    \ U> &p) {\n  is >> p.first >> p.second;\n  return is;\n}\n\ntemplate <typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n  int s = (int)v.size();\n\
    \  for (int i = 0; i < s; i++) os << (i ? \" \" : \"\") << v[i];\n  return os;\n\
    }\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T> &v) {\n \
    \ for (auto &x : v) is >> x;\n  return is;\n}\n\nistream &operator>>(istream &is,\
    \ __int128_t &x) {\n  string S;\n  is >> S;\n  x = 0;\n  int flag = 0;\n  for\
    \ (auto &c : S) {\n    if (c == '-') {\n      flag = true;\n      continue;\n\
    \    }\n    x *= 10;\n    x += c - '0';\n  }\n  if (flag) x = -x;\n  return is;\n\
    }\n\nistream &operator>>(istream &is, __uint128_t &x) {\n  string S;\n  is >>\
    \ S;\n  x = 0;\n  for (auto &c : S) {\n    x *= 10;\n    x += c - '0';\n  }\n\
    \  return is;\n}\n\nostream &operator<<(ostream &os, __int128_t x) {\n  if (x\
    \ == 0) return os << 0;\n  if (x < 0) os << '-', x = -x;\n  string S;\n  while\
    \ (x) S.push_back('0' + x % 10), x /= 10;\n  reverse(begin(S), end(S));\n  return\
    \ os << S;\n}\nostream &operator<<(ostream &os, __uint128_t x) {\n  if (x == 0)\
    \ return os << 0;\n  string S;\n  while (x) S.push_back('0' + x % 10), x /= 10;\n\
    \  reverse(begin(S), end(S));\n  return os << S;\n}\n\nvoid in() {}\ntemplate\
    \ <typename T, class... U>\nvoid in(T &t, U &...u) {\n  cin >> t;\n  in(u...);\n\
    }\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename T, class... U, char sep\
    \ = ' '>\nvoid out(const T &t, const U &...u) {\n  cout << t;\n  if (sizeof...(u))\
    \ cout << sep;\n  out(u...);\n}\n\nstruct IoSetupNya {\n  IoSetupNya() {\n   \
    \ cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(15);\n\
    \    cerr << fixed << setprecision(7);\n  }\n} iosetupnya;\n\n}  // namespace\
    \ Nyaan\n#line 64 \"template/template.hpp\"\n\n// debug\n#line 1 \"template/debug.hpp\"\
    \nnamespace DebugImpl {\n\ntemplate <typename U, typename = void>\nstruct is_specialize\
    \ : false_type {};\ntemplate <typename U>\nstruct is_specialize<\n    U, typename\
    \ conditional<false, typename U::iterator, void>::type>\n    : true_type {};\n\
    template <typename U>\nstruct is_specialize<\n    U, typename conditional<false,\
    \ decltype(U::first), void>::type>\n    : true_type {};\ntemplate <typename U>\n\
    struct is_specialize<U, enable_if_t<is_integral<U>::value, void>> : true_type\
    \ {\n};\n\nvoid dump(const char& t) { cerr << t; }\n\nvoid dump(const string&\
    \ t) { cerr << t; }\n\nvoid dump(const bool& t) { cerr << (t ? \"true\" : \"false\"\
    ); }\n\nvoid dump(__int128_t t) {\n  if (t == 0) cerr << 0;\n  if (t < 0) cerr\
    \ << '-', t = -t;\n  string S;\n  while (t) S.push_back('0' + t % 10), t /= 10;\n\
    \  reverse(begin(S), end(S));\n  cerr << S;\n}\n\nvoid dump(__uint128_t t) {\n\
    \  if (t == 0) cerr << 0;\n  string S;\n  while (t) S.push_back('0' + t % 10),\
    \ t /= 10;\n  reverse(begin(S), end(S));\n  cerr << S;\n}\n\ntemplate <typename\
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
    \ 4 \"verify/verify-yosupo-math/yosupo-sum-of-totient-3.test.cpp\"\n//\n#line\
    \ 2 \"multiplicative-function/enumerate-sum-of-multiplicative-function.hpp\"\n\
    \n#line 5 \"multiplicative-function/enumerate-sum-of-multiplicative-function.hpp\"\
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
    \ \u5546\u306E\u5217\u6319\n */\n#line 9 \"multiplicative-function/enumerate-sum-of-multiplicative-function.hpp\"\
    \n/**\n * S(f, n) = f(1) + f(2) + ... + f(n) \u3068\u3059\u308B\n * f \u3068 g\
    \ \u306E\u30C7\u30A3\u30EA\u30AF\u30EC\u7A4D\u3092 h \u3068\u3059\u308B\n * S(h,\
    \ n) \u3068 S(g, n) \u304C\u9AD8\u901F\u306B\u8A08\u7B97\u3067\u304D\u308B, \u304B\
    \u3064 g(1) = 1 \u306E\u3068\u304D\n * S(f, N/i) \u3092 O(N^{3/4}) \u3067\u5217\
    \u6319\u3067\u304D\u308B\n *\n * \u3046\u307E\u304F\u3084\u308B\u3068 O~(N^{2/3})\
    \ \u306B\u843D\u3061\u305F\u308A g(1) != 1 \u306B\u5BFE\u5FDC\u3067\u304D\u308B\
    \n * https://codeforces.com/blog/entry/54150\n */\ntemplate <typename T, typename\
    \ SG, typename SH>\nstruct enumerate_mf_prefix_sum {\n  long long N, sq;\n  const\
    \ SG sg;\n  const SH sh;\n  vector<T> small, large;\n  T& ref(long long x) {\n\
    \    if (x <= sq) {\n      return small[x];\n    } else if (N <= 1000000000000LL)\
    \ {\n      return large[1.0 * N / x];\n    } else {\n      return large[N / x];\n\
    \    }\n  }\n  enumerate_mf_prefix_sum(long long _n, SG _sg, SH _sh)\n      :\
    \ N(_n), sq(isqrt(N)), sg(_sg), sh(_sh) {\n    small.resize(sq + 1);\n    large.resize(sq\
    \ + 1);\n    enumerate_quotient(N, [&](long long n, long long, long long) {\n\
    \      T& cur = (ref(n) = sh(n));\n      enumerate_quotient(n, [&](long long q,\
    \ long long l, long long r) {\n        if (q != n) cur -= ref(q) * (sg(r) - sg(l));\n\
    \      });\n    });\n  }\n  T get(long long n) { return ref(n); }\n  T operator()(long\
    \ long n) { return get(n); }\n};\n\n/**\n * @brief \u4E57\u6CD5\u7684\u95A2\u6570\
    \u306Eprefix sum \u306E\u5217\u6319\n */\n#line 6 \"verify/verify-yosupo-math/yosupo-sum-of-totient-3.test.cpp\"\
    \nusing namespace Nyaan;\n\n#line 2 \"modint/montgomery-modint.hpp\"\n\n\n\ntemplate\
    \ <uint32_t mod>\nstruct LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n\
    \  using i32 = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n\
    \  static constexpr u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i <\
    \ 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n  static constexpr u32\
    \ r = get_r();\n  static constexpr u32 n2 = -u64(mod) % mod;\n  static_assert(r\
    \ * mod == 1, \"invalid, r * mod != 1\");\n  static_assert(mod < (1 << 30), \"\
    invalid, mod >= 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"invalid, mod % 2\
    \ == 0\");\n\n  u32 a;\n\n  constexpr LazyMontgomeryModInt() : a(0) {}\n  constexpr\
    \ LazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b % mod + mod)\
    \ * n2)){};\n\n  static constexpr u32 reduce(const u64 &b) {\n    return (b +\
    \ u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  constexpr mint &operator+=(const\
    \ mint &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n\
    \  }\n\n  constexpr mint &operator-=(const mint &b) {\n    if (i32(a -= b.a) <\
    \ 0) a += 2 * mod;\n    return *this;\n  }\n\n  constexpr mint &operator*=(const\
    \ mint &b) {\n    a = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  constexpr\
    \ mint &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return *this;\n\
    \  }\n\n  constexpr mint operator+(const mint &b) const { return mint(*this) +=\
    \ b; }\n  constexpr mint operator-(const mint &b) const { return mint(*this) -=\
    \ b; }\n  constexpr mint operator*(const mint &b) const { return mint(*this) *=\
    \ b; }\n  constexpr mint operator/(const mint &b) const { return mint(*this) /=\
    \ b; }\n  constexpr bool operator==(const mint &b) const {\n    return (a >= mod\
    \ ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n  constexpr bool operator!=(const\
    \ mint &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a -\
    \ mod : b.a);\n  }\n  constexpr mint operator-() const { return mint() - mint(*this);\
    \ }\n\n  constexpr mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n   \
    \ while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>=\
    \ 1;\n    }\n    return ret;\n  }\n  \n  constexpr mint inverse() const { return\
    \ pow(mod - 2); }\n\n  friend ostream &operator<<(ostream &os, const mint &b)\
    \ {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is,\
    \ mint &b) {\n    int64_t t;\n    is >> t;\n    b = LazyMontgomeryModInt<mod>(t);\n\
    \    return (is);\n  }\n  \n  constexpr u32 get() const {\n    u32 ret = reduce(a);\n\
    \    return ret >= mod ? ret - mod : ret;\n  }\n\n  static constexpr u32 get_mod()\
    \ { return mod; }\n};\n#line 2 \"modulo/binomial.hpp\"\n\n#line 6 \"modulo/binomial.hpp\"\
    \nusing namespace std;\n\n// \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306E\
    \ MAX \u306B \u300CC(n, r) \u3084 fac(n) \u3067\u30AF\u30A8\u30EA\u3092\u6295\u3052\
    \u308B\u6700\u5927\u306E n \u300D\n// \u3092\u5165\u308C\u308B\u3068\u500D\u901F\
    \u304F\u3089\u3044\u306B\u306A\u308B\n// mod \u3092\u8D85\u3048\u3066\u524D\u8A08\
    \u7B97\u3057\u3066 0 \u5272\u308A\u3092\u8E0F\u3080\u30D0\u30B0\u306F\u5BFE\u7B56\
    \u6E08\u307F\ntemplate <typename T>\nstruct Binomial {\n  vector<T> f, g, h;\n\
    \  Binomial(int MAX = 0) {\n    assert(T::get_mod() != 0 && \"Binomial<mint>()\"\
    );\n    f.resize(1, T{1});\n    g.resize(1, T{1});\n    h.resize(1, T{1});\n \
    \   if (MAX > 0) extend(MAX + 1);\n  }\n\n  void extend(int m = -1) {\n    int\
    \ n = f.size();\n    if (m == -1) m = n * 2;\n    m = min<int>(m, T::get_mod());\n\
    \    if (n >= m) return;\n    f.resize(m);\n    g.resize(m);\n    h.resize(m);\n\
    \    for (int i = n; i < m; i++) f[i] = f[i - 1] * T(i);\n    g[m - 1] = f[m -\
    \ 1].inverse();\n    h[m - 1] = g[m - 1] * f[m - 2];\n    for (int i = m - 2;\
    \ i >= n; i--) {\n      g[i] = g[i + 1] * T(i + 1);\n      h[i] = g[i] * f[i -\
    \ 1];\n    }\n  }\n\n  T fac(int i) {\n    if (i < 0) return T(0);\n    while\
    \ (i >= (int)f.size()) extend();\n    return f[i];\n  }\n\n  T finv(int i) {\n\
    \    if (i < 0) return T(0);\n    while (i >= (int)g.size()) extend();\n    return\
    \ g[i];\n  }\n\n  T inv(int i) {\n    if (i < 0) return -inv(-i);\n    while (i\
    \ >= (int)h.size()) extend();\n    return h[i];\n  }\n\n  T C(int n, int r) {\n\
    \    if (n < 0 || n < r || r < 0) return T(0);\n    return fac(n) * finv(n - r)\
    \ * finv(r);\n  }\n\n  inline T operator()(int n, int r) { return C(n, r); }\n\
    \n  template <typename I>\n  T multinomial(const vector<I>& r) {\n    static_assert(is_integral<I>::value\
    \ == true);\n    int n = 0;\n    for (auto& x : r) {\n      if (x < 0) return\
    \ T(0);\n      n += x;\n    }\n    T res = fac(n);\n    for (auto& x : r) res\
    \ *= finv(x);\n    return res;\n  }\n\n  template <typename I>\n  T operator()(const\
    \ vector<I>& r) {\n    return multinomial(r);\n  }\n\n  T C_naive(int n, int r)\
    \ {\n    if (n < 0 || n < r || r < 0) return T(0);\n    T ret = T(1);\n    r =\
    \ min(r, n - r);\n    for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);\n  \
    \  return ret;\n  }\n\n  T P(int n, int r) {\n    if (n < 0 || n < r || r < 0)\
    \ return T(0);\n    return fac(n) * finv(n - r);\n  }\n\n  // [x^r] 1 / (1-x)^n\n\
    \  T H(int n, int r) {\n    if (n < 0 || r < 0) return T(0);\n    return r ==\
    \ 0 ? 1 : C(n + r - 1, r);\n  }\n};\n#line 10 \"verify/verify-yosupo-math/yosupo-sum-of-totient-3.test.cpp\"\
    \n//\nusing namespace Nyaan;\nusing mint = LazyMontgomeryModInt<998244353>;\n\
    // using mint = LazyMontgomeryModInt<1000000007>;\nusing vm = vector<mint>;\n\
    using vvm = vector<vm>;\nBinomial<mint> C;\n\nvoid q() {\n  inl(N);\n  auto sg\
    \ = [&](ll x) -> mint { return x; };\n  auto sh = [&](ll x) -> mint { return mint{x}\
    \ * (x + 1) * C.inv(2); };\n  enumerate_mf_prefix_sum<mint, decltype(sg), decltype(sh)>\
    \ sf(N, sg, sh);\n  out(sf(N));\n}\n\nvoid Nyaan::solve() {\n  int t = 1;\n  //\
    \ in(t);\n  while (t--) q();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n//\n#include \"../../template/template.hpp\"\n//\n#include \"../../multiplicative-function/enumerate-sum-of-multiplicative-function.hpp\"\
    \nusing namespace Nyaan;\n\n#include \"../../modint/montgomery-modint.hpp\"\n\
    #include \"../../modulo/binomial.hpp\"\n//\nusing namespace Nyaan;\nusing mint\
    \ = LazyMontgomeryModInt<998244353>;\n// using mint = LazyMontgomeryModInt<1000000007>;\n\
    using vm = vector<mint>;\nusing vvm = vector<vm>;\nBinomial<mint> C;\n\nvoid q()\
    \ {\n  inl(N);\n  auto sg = [&](ll x) -> mint { return x; };\n  auto sh = [&](ll\
    \ x) -> mint { return mint{x} * (x + 1) * C.inv(2); };\n  enumerate_mf_prefix_sum<mint,\
    \ decltype(sg), decltype(sh)> sf(N, sg, sh);\n  out(sf(N));\n}\n\nvoid Nyaan::solve()\
    \ {\n  int t = 1;\n  // in(t);\n  while (t--) q();\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - multiplicative-function/enumerate-sum-of-multiplicative-function.hpp
  - math/enumerate-quotient.hpp
  - math/isqrt.hpp
  - modint/montgomery-modint.hpp
  - modulo/binomial.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-math/yosupo-sum-of-totient-3.test.cpp
  requiredBy: []
  timestamp: '2023-05-22 22:29:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-math/yosupo-sum-of-totient-3.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-math/yosupo-sum-of-totient-3.test.cpp
- /verify/verify/verify-yosupo-math/yosupo-sum-of-totient-3.test.cpp.html
title: verify/verify-yosupo-math/yosupo-sum-of-totient-3.test.cpp
---
