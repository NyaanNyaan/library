---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-seed.hpp
    title: internal/internal-seed.hpp
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: modint
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
  bundledCode: "#line 1 \"verify/verify-unit-test/modint.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#line 2 \"template/template.hpp\"\
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
    \ 4 \"verify/verify-unit-test/modint.test.cpp\"\n//\n#line 1 \"atcoder/internal_math.hpp\"\
    \n\n\n\n#line 5 \"atcoder/internal_math.hpp\"\n\n#ifdef _MSC_VER\n#include <intrin.h>\n\
    #endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n// @param m `1 <= m`\n\
    // @return x mod m\nconstexpr long long safe_mod(long long x, long long m) {\n\
    \    x %= m;\n    if (x < 0) x += m;\n    return x;\n}\n\n// Fast modular multiplication\
    \ by barrett reduction\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n\
    // NOTE: reconsider after Ice Lake\nstruct barrett {\n    unsigned int _m;\n \
    \   unsigned long long im;\n\n    // @param m `1 <= m < 2^31`\n    barrett(unsigned\
    \ int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}\n\n    // @return m\n\
    \    unsigned int umod() const { return _m; }\n\n    // @param a `0 <= a < m`\n\
    \    // @param b `0 <= b < m`\n    // @return `a * b % m`\n    unsigned int mul(unsigned\
    \ int a, unsigned int b) const {\n        // [1] m = 1\n        // a = b = im\
    \ = 0, so okay\n\n        // [2] m >= 2\n        // im = ceil(2^64 / m)\n    \
    \    // -> im * m = 2^64 + r (0 <= r < m)\n        // let z = a*b = c*m + d (0\
    \ <= c, d < m)\n        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64\
    \ + c*r + d*im\n        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64\
    \ + m * (m + 1) < 2^64 * 2\n        // ((ab * im) >> 64) == c or c + 1\n     \
    \   unsigned long long z = a;\n        z *= b;\n#ifdef _MSC_VER\n        unsigned\
    \ long long x;\n        _umul128(z, im, &x);\n#else\n        unsigned long long\
    \ x =\n            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n\
    #endif\n        unsigned int v = (unsigned int)(z - x * _m);\n        if (_m <=\
    \ v) v += _m;\n        return v;\n    }\n};\n\n// @param n `0 <= n`\n// @param\
    \ m `1 <= m`\n// @return `(x ** n) % m`\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m\
    \ = (unsigned int)(m);\n    unsigned long long r = 1;\n    unsigned long long\
    \ y = safe_mod(x, m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n\
    \        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n// Reference:\n\
    // M. Forisek and J. Jancina,\n// Fast Primality Testing for Integers That Fit\
    \ into a Machine Word\n// @param n `0 <= n`\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for\
    \ (long long a : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    template <int n> constexpr bool is_prime = is_prime_constexpr(n);\n\n// @param\
    \ b `1 <= b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x\
    \ < b/g\nconstexpr std::pair<long long, long long> inv_gcd(long long a, long long\
    \ b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\n    // Contracts:\n\
    \    // [1] s - m0 * a = 0 (mod b)\n    // [2] t - m1 * a = 0 (mod b)\n    //\
    \ [3] s * |m1| + t * |m0| <= b\n    long long s = b, t = a;\n    long long m0\
    \ = 0, m1 = 1;\n\n    while (t) {\n        long long u = s / t;\n        s -=\
    \ t * u;\n        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b\n\n        // [3]:\n\
    \        // (s - t * u) * |m1| + t * |m0 - m1 * u|\n        // <= s * |m1| - t\
    \ * u * |m1| + t * (|m0| + |m1| * u)\n        // = s * |m1| + t * |m0| <= b\n\n\
    \        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    // by [3]: |m0| <= b/g\n    //\
    \ by g != b: |m0| < b/g\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\
    \n// Compile time primitive root\n// @param m must be prime\n// @return primitive\
    \ root (and minimum in now)\nconstexpr int primitive_root_constexpr(int m) {\n\
    \    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n}  // namespace internal\n\n}  // namespace\
    \ atcoder\n\n\n#line 2 \"misc/rng.hpp\"\n\n#line 2 \"internal/internal-seed.hpp\"\
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
    using my_rand::rnd;\nusing my_rand::rng;\n#line 7 \"verify/verify-unit-test/modint.test.cpp\"\
    \n//\n#line 2 \"modint/modint.hpp\"\n\ntemplate <int mod>\nstruct ModInt {\n \
    \ int x;\n\n  ModInt() : x(0) {}\n\n  ModInt(int64_t y) : x(y >= 0 ? y % mod :\
    \ (mod - (-y) % mod) % mod) {}\n\n  ModInt &operator+=(const ModInt &p) {\n  \
    \  if ((x += p.x) >= mod) x -= mod;\n    return *this;\n  }\n\n  ModInt &operator-=(const\
    \ ModInt &p) {\n    if ((x += mod - p.x) >= mod) x -= mod;\n    return *this;\n\
    \  }\n\n  ModInt &operator*=(const ModInt &p) {\n    x = (int)(1LL * x * p.x %\
    \ mod);\n    return *this;\n  }\n\n  ModInt &operator/=(const ModInt &p) {\n \
    \   *this *= p.inverse();\n    return *this;\n  }\n\n  ModInt operator-() const\
    \ { return ModInt(-x); }\n  ModInt operator+() const { return ModInt(*this); }\n\
    \n  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }\n\n\
    \  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }\n\n\
    \  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }\n\n\
    \  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }\n\n\
    \  bool operator==(const ModInt &p) const { return x == p.x; }\n\n  bool operator!=(const\
    \ ModInt &p) const { return x != p.x; }\n\n  ModInt inverse() const {\n    int\
    \ a = x, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n  \
    \    swap(a -= t * b, b);\n      swap(u -= t * v, v);\n    }\n    return ModInt(u);\n\
    \  }\n\n  ModInt pow(int64_t n) const {\n    ModInt ret(1), mul(x);\n    while\
    \ (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n\
    \    }\n    return ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const\
    \ ModInt &p) { return os << p.x; }\n\n  friend istream &operator>>(istream &is,\
    \ ModInt &a) {\n    int64_t t;\n    is >> t;\n    a = ModInt<mod>(t);\n    return\
    \ (is);\n  }\n\n  int get() const { return x; }\n\n  static constexpr int get_mod()\
    \ { return mod; }\n};\n\n/**\n * @brief modint\n */\n#line 2 \"modint/montgomery-modint.hpp\"\
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
    \ { return mod; }\n};\n#line 10 \"verify/verify-unit-test/modint.test.cpp\"\n\
    using namespace Nyaan;\n\ntemplate <typename mint>\nvoid test(int testcases) {\n\
    \  int mod = mint::get_mod();\n  assert(0 < mod and mod <= (1 << 30) - 1);\n\n\
    \  rep(t, testcases) {\n    int a = randint(0, mod);\n    if (rng() % 10 == 0)\
    \ a = (mod - 1) % mod;\n    if (rng() % 10 == 0) a = 0;\n    mint A = a;\n   \
    \ assert(int(A.get()) == a);\n\n    int b = randint(0, mod);\n    if (rng() %\
    \ 10 == 0) b = (mod - 1) % mod;\n    if (rng() % 10 == 0) b = 0;\n    mint B =\
    \ b;\n    assert(int(B.get()) == b);\n\n    int c = (a + b) % mod;\n    mint C\
    \ = A + B;\n    assert(int(C.get()) == c);\n\n    int d = (a + mod - b) % mod;\n\
    \    mint D = A - B;\n    assert(int(D.get()) == d);\n\n    int e = (1LL * a *\
    \ b) % mod;\n    mint E = A * B;\n    assert(int(E.get()) == e);\n\n    // \u9006\
    \u5143 : f * g = 1\n    int f, g = -1;\n    do {\n      f = randint(0, mod);\n\
    \      auto [gc, invf] = atcoder::internal::inv_gcd(f, mod);\n      g = invf;\n\
    \    } while (1LL * f * g % mod != 1LL % mod);\n    mint F = f;\n    mint G =\
    \ F.inverse();\n    assert(int(F.get()) == f);\n    assert(int(G.get()) == g);\n\
    \    assert(F * G == 1);\n\n    int h = 1LL * e * g % mod;\n    mint H = E / F;\n\
    \    assert(int(H.get()) == h);\n\n    int i = randint(0, mod);\n    if (rng()\
    \ % 10 == 0) i = (mod - 1) % mod;\n    if (rng() % 10 == 0) i = 0;\n    long long\
    \ ex = randint(0, TEN(18));\n    if (rng() % 10 == 0) ex = randint(0, 2);\n  \
    \  int j = 1 % mod;\n    {\n      int i2 = i;\n      long long e2 = ex;\n    \
    \  while (e2) {\n        if (e2 & 1) j = 1LL * j * i2 % mod;\n        i2 = 1LL\
    \ * i2 * i2 % mod;\n        e2 >>= 1;\n      }\n    }\n    mint I = i;\n    mint\
    \ J = I.pow(ex);\n    assert(int(I.get()) == i);\n    assert(int(J.get()) == j);\n\
    \n    // \u5358\u9805 +, -\n    int k = (mod - a) % mod;\n    mint K = -A;\n \
    \   assert(int(K.get()) == k);\n    assert(A == +A);\n  }\n}\n\ntemplate <int\
    \ mod>\nvoid test_wrapper(int testcases = 10000) {\n  if (mod <= 0) return;\n\
    \  static_assert(mod < (1LL << 30));\n  test<ModInt<mod>>(testcases);\n  if constexpr\
    \ (mod % 2 == 1) {\n    test<LazyMontgomeryModInt<mod>>(testcases);\n  }\n}\n\n\
    void Nyaan::solve() {\n  constexpr int mod_max = (1LL << 30) - 1;\n\n  test_wrapper<998244353>(1e6);\n\
    \  test_wrapper<1000000007>(1e6);\n  test_wrapper<mod_max - 10000>();\n\n  test_wrapper<1>();\n\
    \  test_wrapper<2>();\n  test_wrapper<3>();\n  test_wrapper<4>();\n  test_wrapper<5>();\n\
    \  test_wrapper<6>();\n  test_wrapper<7>();\n  test_wrapper<8>();\n  test_wrapper<9>();\n\
    \  test_wrapper<10>();\n  test_wrapper<11>();\n  test_wrapper<101>();\n  test_wrapper<1001>();\n\
    \  test_wrapper<10001>();\n  test_wrapper<100001>();\n  test_wrapper<1000001>();\n\
    \  test_wrapper<10000001>();\n  test_wrapper<100000001>();\n\n  test_wrapper<454763204>();\n\
    \  test_wrapper<302343120>();\n  test_wrapper<666121844>();\n  test_wrapper<180227696>();\n\
    \  test_wrapper<666012019>();\n  test_wrapper<557418622>();\n  test_wrapper<728776078>();\n\
    \  test_wrapper<447813621>();\n  test_wrapper<750511963>();\n  test_wrapper<726530008>();\n\
    \n  cerr << \"OK\" << endl;\n\n  int a, b;\n  cin >> a >> b;\n  cout << a + b\
    \ << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../atcoder/internal_math.hpp\"\
    \n#include \"../../misc/rng.hpp\"\n//\n#include \"../../modint/modint.hpp\"\n\
    #include \"../../modint/montgomery-modint.hpp\"\nusing namespace Nyaan;\n\ntemplate\
    \ <typename mint>\nvoid test(int testcases) {\n  int mod = mint::get_mod();\n\
    \  assert(0 < mod and mod <= (1 << 30) - 1);\n\n  rep(t, testcases) {\n    int\
    \ a = randint(0, mod);\n    if (rng() % 10 == 0) a = (mod - 1) % mod;\n    if\
    \ (rng() % 10 == 0) a = 0;\n    mint A = a;\n    assert(int(A.get()) == a);\n\n\
    \    int b = randint(0, mod);\n    if (rng() % 10 == 0) b = (mod - 1) % mod;\n\
    \    if (rng() % 10 == 0) b = 0;\n    mint B = b;\n    assert(int(B.get()) ==\
    \ b);\n\n    int c = (a + b) % mod;\n    mint C = A + B;\n    assert(int(C.get())\
    \ == c);\n\n    int d = (a + mod - b) % mod;\n    mint D = A - B;\n    assert(int(D.get())\
    \ == d);\n\n    int e = (1LL * a * b) % mod;\n    mint E = A * B;\n    assert(int(E.get())\
    \ == e);\n\n    // \u9006\u5143 : f * g = 1\n    int f, g = -1;\n    do {\n  \
    \    f = randint(0, mod);\n      auto [gc, invf] = atcoder::internal::inv_gcd(f,\
    \ mod);\n      g = invf;\n    } while (1LL * f * g % mod != 1LL % mod);\n    mint\
    \ F = f;\n    mint G = F.inverse();\n    assert(int(F.get()) == f);\n    assert(int(G.get())\
    \ == g);\n    assert(F * G == 1);\n\n    int h = 1LL * e * g % mod;\n    mint\
    \ H = E / F;\n    assert(int(H.get()) == h);\n\n    int i = randint(0, mod);\n\
    \    if (rng() % 10 == 0) i = (mod - 1) % mod;\n    if (rng() % 10 == 0) i = 0;\n\
    \    long long ex = randint(0, TEN(18));\n    if (rng() % 10 == 0) ex = randint(0,\
    \ 2);\n    int j = 1 % mod;\n    {\n      int i2 = i;\n      long long e2 = ex;\n\
    \      while (e2) {\n        if (e2 & 1) j = 1LL * j * i2 % mod;\n        i2 =\
    \ 1LL * i2 * i2 % mod;\n        e2 >>= 1;\n      }\n    }\n    mint I = i;\n \
    \   mint J = I.pow(ex);\n    assert(int(I.get()) == i);\n    assert(int(J.get())\
    \ == j);\n\n    // \u5358\u9805 +, -\n    int k = (mod - a) % mod;\n    mint K\
    \ = -A;\n    assert(int(K.get()) == k);\n    assert(A == +A);\n  }\n}\n\ntemplate\
    \ <int mod>\nvoid test_wrapper(int testcases = 10000) {\n  if (mod <= 0) return;\n\
    \  static_assert(mod < (1LL << 30));\n  test<ModInt<mod>>(testcases);\n  if constexpr\
    \ (mod % 2 == 1) {\n    test<LazyMontgomeryModInt<mod>>(testcases);\n  }\n}\n\n\
    void Nyaan::solve() {\n  constexpr int mod_max = (1LL << 30) - 1;\n\n  test_wrapper<998244353>(1e6);\n\
    \  test_wrapper<1000000007>(1e6);\n  test_wrapper<mod_max - 10000>();\n\n  test_wrapper<1>();\n\
    \  test_wrapper<2>();\n  test_wrapper<3>();\n  test_wrapper<4>();\n  test_wrapper<5>();\n\
    \  test_wrapper<6>();\n  test_wrapper<7>();\n  test_wrapper<8>();\n  test_wrapper<9>();\n\
    \  test_wrapper<10>();\n  test_wrapper<11>();\n  test_wrapper<101>();\n  test_wrapper<1001>();\n\
    \  test_wrapper<10001>();\n  test_wrapper<100001>();\n  test_wrapper<1000001>();\n\
    \  test_wrapper<10000001>();\n  test_wrapper<100000001>();\n\n  test_wrapper<454763204>();\n\
    \  test_wrapper<302343120>();\n  test_wrapper<666121844>();\n  test_wrapper<180227696>();\n\
    \  test_wrapper<666012019>();\n  test_wrapper<557418622>();\n  test_wrapper<728776078>();\n\
    \  test_wrapper<447813621>();\n  test_wrapper<750511963>();\n  test_wrapper<726530008>();\n\
    \n  cerr << \"OK\" << endl;\n\n  int a, b;\n  cin >> a >> b;\n  cout << a + b\
    \ << \"\\n\";\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - misc/rng.hpp
  - internal/internal-seed.hpp
  - modint/modint.hpp
  - modint/montgomery-modint.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/modint.test.cpp
  requiredBy: []
  timestamp: '2024-04-28 09:13:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/modint.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/modint.test.cpp
- /verify/verify/verify-unit-test/modint.test.cpp.html
title: verify/verify-unit-test/modint.test.cpp
---
