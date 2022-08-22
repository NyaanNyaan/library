---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/garner.hpp
    title: Garner's algorithm
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':question:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':question:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':question:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
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
  bundledCode: "#line 1 \"verify/verify-unit-test/garner.test.cpp\"\n#define PROBLEM\
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
    \ vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\n\ntemplate\
    \ <typename T, typename U>\nstruct P : pair<T, U> {\n  template <typename... Args>\n\
    \  P(Args... args) : pair<T, U>(args...) {}\n\n  using pair<T, U>::first;\n  using\
    \ pair<T, U>::second;\n\n  T &x() { return first; }\n  const T &x() const { return\
    \ first; }\n  U &y() { return second; }\n  const U &y() const { return second;\
    \ }\n\n  P &operator+=(const P &r) {\n    first += r.first;\n    second += r.second;\n\
    \    return *this;\n  }\n  P &operator-=(const P &r) {\n    first -= r.first;\n\
    \    second -= r.second;\n    return *this;\n  }\n  P &operator*=(const P &r)\
    \ {\n    first *= r.first;\n    second *= r.second;\n    return *this;\n  }\n\
    \  P operator+(const P &r) const { return P(*this) += r; }\n  P operator-(const\
    \ P &r) const { return P(*this) -= r; }\n  P operator*(const P &r) const { return\
    \ P(*this) *= r; }\n};\n\nusing pl = P<ll, ll>;\nusing pi = P<int, int>;\nusing\
    \ vp = V<pl>;\n\nconstexpr int inf = 1001001001;\nconstexpr long long infLL =\
    \ 4004004004004004004LL;\n\ntemplate <typename T>\nint sz(const T &t) {\n  return\
    \ t.size();\n}\n\ntemplate <typename T, typename U>\ninline bool amin(T &x, U\
    \ y) {\n  return (y < x) ? (x = y, true) : false;\n}\ntemplate <typename T, typename\
    \ U>\ninline bool amax(T &x, U y) {\n  return (x < y) ? (x = y, true) : false;\n\
    }\n\ntemplate <typename T>\ninline T Max(const vector<T> &v) {\n  return *max_element(begin(v),\
    \ end(v));\n}\ntemplate <typename T>\ninline T Min(const vector<T> &v) {\n  return\
    \ *min_element(begin(v), end(v));\n}\ntemplate <typename T>\ninline long long\
    \ Sum(const vector<T> &v) {\n  return accumulate(begin(v), end(v), 0LL);\n}\n\n\
    template <typename T>\nint lb(const vector<T> &v, const T &a) {\n  return lower_bound(begin(v),\
    \ end(v), a) - begin(v);\n}\ntemplate <typename T>\nint ub(const vector<T> &v,\
    \ const T &a) {\n  return upper_bound(begin(v), end(v), a) - begin(v);\n}\n\n\
    constexpr long long TEN(int n) {\n  long long ret = 1, x = 10;\n  for (; n; x\
    \ *= x, n >>= 1) ret *= (n & 1 ? x : 1);\n  return ret;\n}\n\ntemplate <typename\
    \ T, typename U>\npair<T, U> mkp(const T &t, const U &u) {\n  return make_pair(t,\
    \ u);\n}\n\ntemplate <typename T>\nvector<T> mkrui(const vector<T> &v, bool rev\
    \ = false) {\n  vector<T> ret(v.size() + 1);\n  if (rev) {\n    for (int i = int(v.size())\
    \ - 1; i >= 0; i--) ret[i] = v[i] + ret[i + 1];\n  } else {\n    for (int i =\
    \ 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];\n  }\n  return ret;\n\
    };\n\ntemplate <typename T>\nvector<T> mkuni(const vector<T> &v) {\n  vector<T>\
    \ ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(), ret.end()),\
    \ ret.end());\n  return ret;\n}\n\ntemplate <typename F>\nvector<int> mkord(int\
    \ N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n  sort(begin(ord),\
    \ end(ord), f);\n  return ord;\n}\n\ntemplate <typename T>\nvector<int> mkinv(vector<T>\
    \ &v) {\n  int max_val = *max_element(begin(v), end(v));\n  vector<int> inv(max_val\
    \ + 1, -1);\n  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;\n  return\
    \ inv;\n}\n\n}  // namespace Nyaan\n#line 58 \"template/template.hpp\"\n\n// bit\
    \ operation\n#line 1 \"template/bitop.hpp\"\nnamespace Nyaan {\n__attribute__((target(\"\
    popcnt\"))) inline int popcnt(const u64 &a) {\n  return _mm_popcnt_u64(a);\n}\n\
    inline int lsb(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }\ninline int\
    \ ctz(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }\ninline int msb(const\
    \ u64 &a) { return a ? 63 - __builtin_clzll(a) : -1; }\ntemplate <typename T>\n\
    inline int gbit(const T &a, int i) {\n  return (a >> i) & 1;\n}\ntemplate <typename\
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
    \ for (auto &x : v) is >> x;\n  return is;\n}\n\nvoid in() {}\ntemplate <typename\
    \ T, class... U>\nvoid in(T &t, U &... u) {\n  cin >> t;\n  in(u...);\n}\n\nvoid\
    \ out() { cout << \"\\n\"; }\ntemplate <typename T, class... U, char sep = ' '>\n\
    void out(const T &t, const U &... u) {\n  cout << t;\n  if (sizeof...(u)) cout\
    \ << sep;\n  out(u...);\n}\n\nvoid outr() {}\ntemplate <typename T, class... U,\
    \ char sep = ' '>\nvoid outr(const T &t, const U &... u) {\n  cout << t;\n  outr(u...);\n\
    }\n\nstruct IoSetupNya {\n  IoSetupNya() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
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
    \ ? \"true\" : \"false\"); }\n\ntemplate <typename U,\n          enable_if_t<!is_specialize<U>::value,\
    \ nullptr_t> = nullptr>\nvoid dump(const U& t) {\n  cerr << t;\n}\n\ntemplate\
    \ <typename T>\nvoid dump(const T& t, enable_if_t<is_integral<T>::value>* = nullptr)\
    \ {\n  string res;\n  if (t == Nyaan::inf) res = \"inf\";\n  if constexpr (is_signed<T>::value)\
    \ {\n    if (t == -Nyaan::inf) res = \"-inf\";\n  }\n  if constexpr (sizeof(T)\
    \ == 8) {\n    if (t == Nyaan::infLL) res = \"inf\";\n    if constexpr (is_signed<T>::value)\
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
    \          \\\n  } while (0)\n#else\n#define trc(...) (void(0))\n#endif\n#line\
    \ 67 \"template/template.hpp\"\n\n// macro\n#line 1 \"template/macro.hpp\"\n#define\
    \ each(x, v) for (auto&& x : v)\n#define each2(x, y, v) for (auto&& [x, y] : v)\n\
    #define all(v) (v).begin(), (v).end()\n#define rep(i, N) for (long long i = 0;\
    \ i < (long long)(N); i++)\n#define repr(i, N) for (long long i = (long long)(N)-1;\
    \ i >= 0; i--)\n#define rep1(i, N) for (long long i = 1; i <= (long long)(N);\
    \ i++)\n#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)\n\
    #define reg(i, a, b) for (long long i = (a); i < (b); i++)\n#define regr(i, a,\
    \ b) for (long long i = (b)-1; i >= (a); i--)\n#define fi first\n#define se second\n\
    #define ini(...)   \\\n  int __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define inl(...)\
    \         \\\n  long long __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define ins(...)\
    \      \\\n  string __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define in2(s, t)    \
    \                       \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n \
    \   in(s[i], t[i]);                         \\\n  }\n#define in3(s, t, u)    \
    \                    \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i],\
    \ t[i], u[i]);                   \\\n  }\n#define in4(s, t, u, v)            \
    \         \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i],\
    \ u[i], v[i]);             \\\n  }\n#define die(...)             \\\n  do {  \
    \                     \\\n    Nyaan::out(__VA_ARGS__); \\\n    return;       \
    \           \\\n  } while (0)\n#line 70 \"template/template.hpp\"\n\nnamespace\
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line 4 \"verify/verify-unit-test/garner.test.cpp\"\
    \n//\n#line 1 \"atcoder/math.hpp\"\n\n\n\n#line 8 \"atcoder/math.hpp\"\n\n#line\
    \ 1 \"atcoder/internal_math.hpp\"\n\n\n\n#line 5 \"atcoder/internal_math.hpp\"\
    \n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\n// @param m `1 <= m`\n// @return x mod m\nconstexpr long long\
    \ safe_mod(long long x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n\
    \    return x;\n}\n\n// Fast modular multiplication by barrett reduction\n// Reference:\
    \ https://en.wikipedia.org/wiki/Barrett_reduction\n// NOTE: reconsider after Ice\
    \ Lake\nstruct barrett {\n    unsigned int _m;\n    unsigned long long im;\n\n\
    \    // @param m `1 <= m < 2^31`\n    barrett(unsigned int m) : _m(m), im((unsigned\
    \ long long)(-1) / m + 1) {}\n\n    // @return m\n    unsigned int umod() const\
    \ { return _m; }\n\n    // @param a `0 <= a < m`\n    // @param b `0 <= b < m`\n\
    \    // @return `a * b % m`\n    unsigned int mul(unsigned int a, unsigned int\
    \ b) const {\n        // [1] m = 1\n        // a = b = im = 0, so okay\n\n   \
    \     // [2] m >= 2\n        // im = ceil(2^64 / m)\n        // -> im * m = 2^64\
    \ + r (0 <= r < m)\n        // let z = a*b = c*m + d (0 <= c, d < m)\n       \
    \ // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r + d*im\n     \
    \   // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64 + m * (m + 1) <\
    \ 2^64 * 2\n        // ((ab * im) >> 64) == c or c + 1\n        unsigned long\
    \ long z = a;\n        z *= b;\n#ifdef _MSC_VER\n        unsigned long long x;\n\
    \        _umul128(z, im, &x);\n#else\n        unsigned long long x =\n       \
    \     (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n#endif\n     \
    \   unsigned int v = (unsigned int)(z - x * _m);\n        if (_m <= v) v += _m;\n\
    \        return v;\n    }\n};\n\n// @param n `0 <= n`\n// @param m `1 <= m`\n\
    // @return `(x ** n) % m`\nconstexpr long long pow_mod_constexpr(long long x,\
    \ long long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m = (unsigned\
    \ int)(m);\n    unsigned long long r = 1;\n    unsigned long long y = safe_mod(x,\
    \ m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n        y = (y *\
    \ y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n// Reference:\n// M.\
    \ Forisek and J. Jancina,\n// Fast Primality Testing for Integers That Fit into\
    \ a Machine Word\n// @param n `0 <= n`\nconstexpr bool is_prime_constexpr(int\
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
    \ atcoder\n\n\n#line 10 \"atcoder/math.hpp\"\n\nnamespace atcoder {\n\nlong long\
    \ pow_mod(long long x, long long n, int m) {\n    assert(0 <= n && 1 <= m);\n\
    \    if (m == 1) return 0;\n    internal::barrett bt((unsigned int)(m));\n   \
    \ unsigned int r = 1, y = (unsigned int)(internal::safe_mod(x, m));\n    while\
    \ (n) {\n        if (n & 1) r = bt.mul(r, y);\n        y = bt.mul(y, y);\n   \
    \     n >>= 1;\n    }\n    return r;\n}\n\nlong long inv_mod(long long x, long\
    \ long m) {\n    assert(1 <= m);\n    auto z = internal::inv_gcd(x, m);\n    assert(z.first\
    \ == 1);\n    return z.second;\n}\n\n// (rem, mod)\nstd::pair<long long, long\
    \ long> crt(const std::vector<long long>& r,\n                               \
    \     const std::vector<long long>& m) {\n    assert(r.size() == m.size());\n\
    \    int n = int(r.size());\n    // Contracts: 0 <= r0 < m0\n    long long r0\
    \ = 0, m0 = 1;\n    for (int i = 0; i < n; i++) {\n        assert(1 <= m[i]);\n\
    \        long long r1 = internal::safe_mod(r[i], m[i]), m1 = m[i];\n        if\
    \ (m0 < m1) {\n            std::swap(r0, r1);\n            std::swap(m0, m1);\n\
    \        }\n        if (m0 % m1 == 0) {\n            if (r0 % m1 != r1) return\
    \ {0, 0};\n            continue;\n        }\n        // assume: m0 > m1, lcm(m0,\
    \ m1) >= 2 * max(m0, m1)\n\n        // (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0,\
    \ m1));\n        // r2 % m0 = r0\n        // r2 % m1 = r1\n        // -> (r0 +\
    \ x*m0) % m1 = r1\n        // -> x*u0*g % (u1*g) = (r1 - r0) (u0*g = m0, u1*g\
    \ = m1)\n        // -> x = (r1 - r0) / g * inv(u0) (mod u1)\n\n        // im =\
    \ inv(u0) (mod u1) (0 <= im < u1)\n        long long g, im;\n        std::tie(g,\
    \ im) = internal::inv_gcd(m0, m1);\n\n        long long u1 = (m1 / g);\n     \
    \   // |r1 - r0| < (m0 + m1) <= lcm(m0, m1)\n        if ((r1 - r0) % g) return\
    \ {0, 0};\n\n        // u1 * u1 <= m1 * m1 / g / g <= m0 * m1 / g = lcm(m0, m1)\n\
    \        long long x = (r1 - r0) / g % u1 * im % u1;\n\n        // |r0| + |m0\
    \ * x|\n        // < m0 + m0 * (u1 - 1)\n        // = m0 + m0 * m1 / g - m0\n\
    \        // = lcm(m0, m1)\n        r0 += x * m0;\n        m0 *= u1;  // -> lcm(m0,\
    \ m1)\n        if (r0 < 0) r0 += m0;\n    }\n    return {r0, m0};\n}\n\nlong long\
    \ floor_sum(long long n, long long m, long long a, long long b) {\n    long long\
    \ ans = 0;\n    if (a >= m) {\n        ans += (n - 1) * n * (a / m) / 2;\n   \
    \     a %= m;\n    }\n    if (b >= m) {\n        ans += n * (b / m);\n       \
    \ b %= m;\n    }\n\n    long long y_max = (a * n + b) / m, x_max = (y_max * m\
    \ - b);\n    if (y_max == 0) return ans;\n    ans += (n - (x_max + a - 1) / a)\
    \ * y_max;\n    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);\n    return\
    \ ans;\n}\n\n}  // namespace atcoder\n\n\n#line 2 \"math/garner.hpp\"\n\n// input\
    \  : a, M (0 < a < M)\n// output : pair(g, x) s.t. g = gcd(a, M), xa = g (mod\
    \ M), 0 <= x < b/g\ntemplate <typename uint>\npair<uint, uint> gcd_inv(uint a,\
    \ uint M) {\n  assert(M != 0 && 0 < a);\n  a %= M;\n  uint b = M, s = 1, t = 0;\n\
    \  while (true) {\n    if (a == 0) return {b, t + M};\n    t -= b / a * s;\n \
    \   b %= a;\n    if (b == 0) return {a, s};\n    s -= a / b * t;\n    a %= b;\n\
    \  }\n}\n\n// \u5165\u529B : 0 <= rem[i] < mod[i], 1 <= mod[i]\n// \u5B58\u5728\
    \u3059\u308B\u3068\u304D   : return {rem, mod}\n// \u5B58\u5728\u3057\u306A\u3044\
    \u3068\u304D : return {0, 0}\ntemplate <typename T, typename U>\npair<unsigned\
    \ long long, unsigned long long> garner(const vector<T>& rem,\n              \
    \                                      const vector<U>& mod) {\n  assert(rem.size()\
    \ == mod.size());\n  using u64 = unsigned long long;\n  u64 r0 = 0, m0 = 1;\n\
    \  for (int i = 0; i < (int)rem.size(); i++) {\n    assert(1 <= mod[i]);\n   \
    \ assert(0 <= rem[i] && rem[i] < mod[i]);\n    u64 m1 = mod[i], r1 = rem[i] %\
    \ m1;\n    if (m0 < m1) swap(r0, r1), swap(m0, m1);\n    if (m0 % m1 == 0) {\n\
    \      if (r0 % m1 != r1) return {0, 0};\n      continue;\n    }\n    u64 g, im;\n\
    \    tie(g, im) = gcd_inv(m0, m1);\n    u64 y = r0 < r1 ? r1 - r0 : r0 - r1;\n\
    \    if (y % g != 0) return {0, 0};\n    u64 u1 = m1 / g;\n    y = y / g % u1;\n\
    \    if (r0 > r1 && y != 0) y = u1 - y;\n    u64 x = y * im % u1;\n    r0 += x\
    \ * m0;\n    m0 *= u1;\n  }\n  return {r0, m0};\n}\n\n/**\n * @brief Garner's\
    \ algorithm\n */\n#line 2 \"misc/rng.hpp\"\n\nnamespace my_rand {\nusing i64 =\
    \ long long;\nusing u64 = unsigned long long;\n\n// [0, 2^64 - 1)\nu64 rng() {\n\
    \  static u64 _x =\n      u64(chrono::duration_cast<chrono::nanoseconds>(\n  \
    \            chrono::high_resolution_clock::now().time_since_epoch())\n      \
    \        .count()) *\n      10150724397891781847ULL;\n  _x ^= _x << 7;\n  return\
    \ _x ^= _x >> 9;\n}\n\n// [l, r]\ni64 rng(i64 l, i64 r) {\n  assert(l <= r);\n\
    \  return l + rng() % (r - l + 1);\n}\n\n// [l, r)\ni64 randint(i64 l, i64 r)\
    \ {\n  assert(l < r);\n  return l + rng() % (r - l);\n}\n\n// choose n numbers\
    \ from [l, r) without overlapping\nvector<i64> randset(i64 l, i64 r, i64 n) {\n\
    \  assert(l <= r && n <= r - l);\n  unordered_set<i64> s;\n  for (i64 i = n; i;\
    \ --i) {\n    i64 m = randint(l, r + 1 - i);\n    if (s.find(m) != s.end()) m\
    \ = r - i;\n    s.insert(m);\n  }\n  vector<i64> ret;\n  for (auto& x : s) ret.push_back(x);\n\
    \  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() { return rng() * 5.42101086242752217004e-20;\
    \ }\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n\
    \  for (int i = 1; i < n; i++) swap(v[i], v[randint(0, i + 1)]);\n}\n\n}  // namespace\
    \ my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\nusing my_rand::randshf;\n\
    using my_rand::rnd;\nusing my_rand::rng;\n#line 8 \"verify/verify-unit-test/garner.test.cpp\"\
    \n\nusing namespace Nyaan;\n\nvoid Nyaan::solve() {\n  {\n    V<u64> m{3, 5, 17,\
    \ 257, 65537}, r;\n    each(x, m) r.push_back(x - 1);\n    auto [R, M] = garner(r,\
    \ m);\n    assert(R + 1 == M && M == unsigned(-1));\n  }\n  {\n    V<u64> m{3,\
    \ 5, 17, 257, 65537, 641, 6700417}, r;\n    each(x, m) r.push_back(x - 1);\n \
    \   auto [R, M] = garner(r, m);\n    assert(R + 1 == M && M == u64(-1));\n  }\n\
    \  {\n    V<u64> base{3, 5, 17, 257, 65537, 641, 6700417};\n    vl bs(128);\n\
    \    iota(all(bs), 0);\n    rep(t, 10000) {\n      V<u64> m, r;\n      u64 x =\
    \ rng();\n      randshf(bs);\n      u64 th = rng();\n      u64 l = 1;\n      each(b,\
    \ bs) {\n        if (b == 0 or rng() > th) continue;\n        u64 md = 1;\n  \
    \      rep(j, 7) if (gbit(b, j)) md *= base[j];\n        m.push_back(md);\n  \
    \      r.push_back(x % md);\n        l = lcm(l, md);\n      }\n      if (m.empty())\
    \ continue;\n      auto [R, M] = garner(r, m);\n      assert(M != 0 && u64(-1)\
    \ % M == 0);\n      assert(R == x % M && M == l);\n    }\n  }\n  rep(t, 30030)\
    \ {\n    vl m{2, 3, 5, 7, 11, 13}, r;\n    each(x, m) r.push_back(t % x);\n  \
    \  auto [R, M] = garner(r, m);\n    assert(int(R) == t and M == 30030);\n  }\n\
    \  rep(t, 10000) {\n    vl r, m;\n    ll x = randint(1, 2 * TEN(17));\n    reg(y,\
    \ 2, 42) {\n      r.push_back(x % y);\n      m.push_back(y);\n    }\n    auto\
    \ [r0, m0] = atcoder::crt(r, m);\n    auto [r1, m1] = garner(r, m);\n    assert(r0\
    \ == i64(r1));\n    assert(r0 == x);\n    assert(m0 == i64(m1));\n  }\n  rep(t,\
    \ 100000) {\n    vl r, m;\n    rep(i, 3) {\n      ll x = randint(1 << 20, 1 <<\
    \ 21);\n      ll y = randint(0, x);\n      r.push_back(y);\n      m.push_back(x);\n\
    \    }\n    auto [r0, m0] = atcoder::crt(r, m);\n    auto [r1, m1] = garner(r,\
    \ m);\n    assert(r0 == i64(r1));\n    assert(m0 == i64(m1));\n  }\n  {\n    int\
    \ a, b;\n    cin >> a >> b;\n    cout << a + b << endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../atcoder/math.hpp\"\n#include\
    \ \"../../math/garner.hpp\"\n#include \"../../misc/rng.hpp\"\n\nusing namespace\
    \ Nyaan;\n\nvoid Nyaan::solve() {\n  {\n    V<u64> m{3, 5, 17, 257, 65537}, r;\n\
    \    each(x, m) r.push_back(x - 1);\n    auto [R, M] = garner(r, m);\n    assert(R\
    \ + 1 == M && M == unsigned(-1));\n  }\n  {\n    V<u64> m{3, 5, 17, 257, 65537,\
    \ 641, 6700417}, r;\n    each(x, m) r.push_back(x - 1);\n    auto [R, M] = garner(r,\
    \ m);\n    assert(R + 1 == M && M == u64(-1));\n  }\n  {\n    V<u64> base{3, 5,\
    \ 17, 257, 65537, 641, 6700417};\n    vl bs(128);\n    iota(all(bs), 0);\n   \
    \ rep(t, 10000) {\n      V<u64> m, r;\n      u64 x = rng();\n      randshf(bs);\n\
    \      u64 th = rng();\n      u64 l = 1;\n      each(b, bs) {\n        if (b ==\
    \ 0 or rng() > th) continue;\n        u64 md = 1;\n        rep(j, 7) if (gbit(b,\
    \ j)) md *= base[j];\n        m.push_back(md);\n        r.push_back(x % md);\n\
    \        l = lcm(l, md);\n      }\n      if (m.empty()) continue;\n      auto\
    \ [R, M] = garner(r, m);\n      assert(M != 0 && u64(-1) % M == 0);\n      assert(R\
    \ == x % M && M == l);\n    }\n  }\n  rep(t, 30030) {\n    vl m{2, 3, 5, 7, 11,\
    \ 13}, r;\n    each(x, m) r.push_back(t % x);\n    auto [R, M] = garner(r, m);\n\
    \    assert(int(R) == t and M == 30030);\n  }\n  rep(t, 10000) {\n    vl r, m;\n\
    \    ll x = randint(1, 2 * TEN(17));\n    reg(y, 2, 42) {\n      r.push_back(x\
    \ % y);\n      m.push_back(y);\n    }\n    auto [r0, m0] = atcoder::crt(r, m);\n\
    \    auto [r1, m1] = garner(r, m);\n    assert(r0 == i64(r1));\n    assert(r0\
    \ == x);\n    assert(m0 == i64(m1));\n  }\n  rep(t, 100000) {\n    vl r, m;\n\
    \    rep(i, 3) {\n      ll x = randint(1 << 20, 1 << 21);\n      ll y = randint(0,\
    \ x);\n      r.push_back(y);\n      m.push_back(x);\n    }\n    auto [r0, m0]\
    \ = atcoder::crt(r, m);\n    auto [r1, m1] = garner(r, m);\n    assert(r0 == i64(r1));\n\
    \    assert(m0 == i64(m1));\n  }\n  {\n    int a, b;\n    cin >> a >> b;\n   \
    \ cout << a + b << endl;\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - math/garner.hpp
  - misc/rng.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/garner.test.cpp
  requiredBy: []
  timestamp: '2022-08-22 19:46:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/garner.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/garner.test.cpp
- /verify/verify/verify-unit-test/garner.test.cpp.html
title: verify/verify-unit-test/garner.test.cpp
---
