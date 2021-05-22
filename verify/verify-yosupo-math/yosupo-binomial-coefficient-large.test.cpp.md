---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: modint/barrett-reduction.hpp
    title: modint/barrett-reduction.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/arbitrary-mod-binomial-large.hpp
    title: modulo/arbitrary-mod-binomial-large.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient
  bundledCode: "#line 1 \"verify/verify-yosupo-math/yosupo-binomial-coefficient-large.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient\"\n//\n\
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
    using vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\n\ntemplate\
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
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line 4 \"verify/verify-yosupo-math/yosupo-binomial-coefficient-large.test.cpp\"\
    \n//\n#line 2 \"modulo/arbitrary-mod-binomial-large.hpp\"\n\n#line 1 \"atcoder/math.hpp\"\
    \n\n\n\n#line 8 \"atcoder/math.hpp\"\n\n#line 1 \"atcoder/internal_math.hpp\"\n\
    \n\n\n#line 5 \"atcoder/internal_math.hpp\"\n\n#ifdef _MSC_VER\n#include <intrin.h>\n\
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
    \ ans;\n}\n\n}  // namespace atcoder\n\n\n#line 2 \"modint/barrett-reduction.hpp\"\
    \n\n#line 4 \"modint/barrett-reduction.hpp\"\nusing namespace std;\n\nstruct Barrett\
    \ {\n  using u32 = unsigned int;\n  using i64 = long long;\n  using u64 = unsigned\
    \ long long;\n  u32 m;\n  u64 im;\n  Barrett() : m(), im() {}\n  Barrett(int n)\
    \ : m(n), im(u64(-1) / m + 1) {}\n  constexpr inline i64 quo(u64 n) {\n    u64\
    \ x = u64((__uint128_t(n) * im) >> 64);\n    u32 r = n - x * m;\n    return m\
    \ <= r ? x - 1 : x;\n  }\n  constexpr inline i64 rem(u64 n) {\n    u64 x = u64((__uint128_t(n)\
    \ * im) >> 64);\n    u32 r = n - x * m;\n    return m <= r ? r + m : r;\n  }\n\
    \  constexpr inline pair<i64, int> quorem(u64 n) {\n    u64 x = u64((__uint128_t(n)\
    \ * im) >> 64);\n    u32 r = n - x * m;\n    if (m <= r) return {x - 1, r + m};\n\
    \    return {x, r};\n  }\n  constexpr inline i64 pow(u64 n, i64 p) {\n    u32\
    \ a = rem(n), r = 1;\n    while (p) {\n      if (p & 1) r = rem(u64(r) * a);\n\
    \      a = rem(u64(a) * a);\n      p >>= 1;\n    }\n    return r;\n  }\n};\n#line\
    \ 5 \"modulo/arbitrary-mod-binomial-large.hpp\"\n\n#define PRIME_POWER_BINOMIAL_M_MAX\
    \ ((1LL << 30) - 1)\n#define PRIME_POWER_BINOMIAL_N_MAX 20000000\n\nstruct simd_prime_binomial\
    \ {\n  using u32 = unsigned int;\n  using i64 = long long;\n  using u64 = unsigned\
    \ long long;\n  using m256 = __m256i;\n\n  u32 get_r(u32 _mod) {\n    u32 ret\
    \ = _mod;\n    for (int i = 0; i < 4; ++i) ret *= 2 - _mod * ret;\n    return\
    \ ret;\n  }\n  inline u32 reduce(const u64& b) {\n    return (b + u64(u32(b) *\
    \ u32(-r)) * mod) >> 32;\n  }\n  inline u32 mul(const u32& a, const u32& b) {\
    \ return reduce(u64(a) * b); }\n  inline u32 add(const u32& a, const u32& b) {\n\
    \    u32 c = a + b - 2 * mod;\n    if (c > 2 * mod) c += 2 * mod;\n    return\
    \ c;\n  }\n  inline u32 cast(const i64& b) { return reduce(u64(b % mod + mod)\
    \ * n2); }\n  inline u32 raw_cast(const u64& b) { return reduce(b * n2); }\n \
    \ u64 get(const u32& b) {\n    u32 a = reduce(b);\n    return a >= mod ? a - mod\
    \ : a;\n  }\n  u32 inv(u32 b) {\n    u32 e = mod - 2, a = raw_cast(1);\n    while\
    \ (e) {\n      if (e & 1) a = mul(a, b);\n      b = mul(b, b);\n      e >>= 1;\n\
    \    }\n    return a;\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"O3\"\
    , \"unroll-loops\"))) inline m256\n  simd_mulhi(const m256& a, const m256& b)\
    \ {\n    m256 a13 = _mm256_shuffle_epi32(a, 0xF5);\n    m256 b13 = _mm256_shuffle_epi32(b,\
    \ 0xF5);\n    m256 prod02 = _mm256_mul_epu32(a, b);\n    m256 prod13 = _mm256_mul_epu32(a13,\
    \ b13);\n    m256 unpalo = _mm256_unpacklo_epi32(prod02, prod13);\n    m256 unpahi\
    \ = _mm256_unpackhi_epi32(prod02, prod13);\n    m256 prod = _mm256_unpackhi_epi64(unpalo,\
    \ unpahi);\n    return prod;\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"\
    O3\", \"unroll-loops\"))) inline m256\n  simd_sub(const m256& a, const m256& b)\
    \ {\n    m256 ret = _mm256_sub_epi32(a, b);\n    m256 cmp = _mm256_cmpgt_epi32(M0,\
    \ ret);\n    m256 add = _mm256_and_si256(cmp, M2);\n    return _mm256_add_epi32(add,\
    \ ret);\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"\
    ))) inline m256\n  simd_mul(const m256& A, const m256& B) {\n    m256 a13 = _mm256_shuffle_epi32(A,\
    \ 0xF5);\n    m256 b13 = _mm256_shuffle_epi32(B, 0xF5);\n    m256 prod02 = _mm256_mul_epu32(A,\
    \ B);\n    m256 prod13 = _mm256_mul_epu32(a13, b13);\n    m256 unpalo = _mm256_unpacklo_epi32(prod02,\
    \ prod13);\n    m256 unpahi = _mm256_unpackhi_epi32(prod02, prod13);\n    m256\
    \ prodlo = _mm256_unpacklo_epi64(unpalo, unpahi);\n    m256 prodhi = _mm256_unpackhi_epi64(unpalo,\
    \ unpahi);\n    m256 hiplm1 = _mm256_add_epi32(prodhi, M1);\n    m256 lomulr =\
    \ _mm256_mullo_epi32(prodlo, R);\n    m256 lomulrmulm1 = simd_mulhi(lomulr, M1);\n\
    \    return _mm256_sub_epi32(hiplm1, lomulrmulm1);\n  }\n\n  __attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) inline void\n  transpose8_ps(__m256&\
    \ row0, __m256& row1, __m256& row2, __m256& row3,\n                __m256& row4,\
    \ __m256& row5, __m256& row6, __m256& row7) {\n    __m256 __t0, __t1, __t2, __t3,\
    \ __t4, __t5, __t6, __t7;\n    __m256 __tt0, __tt1, __tt2, __tt3, __tt4, __tt5,\
    \ __tt6, __tt7;\n    __t0 = _mm256_unpacklo_ps(row0, row1);\n    __t1 = _mm256_unpackhi_ps(row0,\
    \ row1);\n    __t2 = _mm256_unpacklo_ps(row2, row3);\n    __t3 = _mm256_unpackhi_ps(row2,\
    \ row3);\n    __t4 = _mm256_unpacklo_ps(row4, row5);\n    __t5 = _mm256_unpackhi_ps(row4,\
    \ row5);\n    __t6 = _mm256_unpacklo_ps(row6, row7);\n    __t7 = _mm256_unpackhi_ps(row6,\
    \ row7);\n    __tt0 = _mm256_shuffle_ps(__t0, __t2, _MM_SHUFFLE(1, 0, 1, 0));\n\
    \    __tt1 = _mm256_shuffle_ps(__t0, __t2, _MM_SHUFFLE(3, 2, 3, 2));\n    __tt2\
    \ = _mm256_shuffle_ps(__t1, __t3, _MM_SHUFFLE(1, 0, 1, 0));\n    __tt3 = _mm256_shuffle_ps(__t1,\
    \ __t3, _MM_SHUFFLE(3, 2, 3, 2));\n    __tt4 = _mm256_shuffle_ps(__t4, __t6, _MM_SHUFFLE(1,\
    \ 0, 1, 0));\n    __tt5 = _mm256_shuffle_ps(__t4, __t6, _MM_SHUFFLE(3, 2, 3, 2));\n\
    \    __tt6 = _mm256_shuffle_ps(__t5, __t7, _MM_SHUFFLE(1, 0, 1, 0));\n    __tt7\
    \ = _mm256_shuffle_ps(__t5, __t7, _MM_SHUFFLE(3, 2, 3, 2));\n    row0 = _mm256_permute2f128_ps(__tt0,\
    \ __tt4, 0x20);\n    row1 = _mm256_permute2f128_ps(__tt1, __tt5, 0x20);\n    row2\
    \ = _mm256_permute2f128_ps(__tt2, __tt6, 0x20);\n    row3 = _mm256_permute2f128_ps(__tt3,\
    \ __tt7, 0x20);\n    row4 = _mm256_permute2f128_ps(__tt0, __tt4, 0x31);\n    row5\
    \ = _mm256_permute2f128_ps(__tt1, __tt5, 0x31);\n    row6 = _mm256_permute2f128_ps(__tt2,\
    \ __tt6, 0x31);\n    row7 = _mm256_permute2f128_ps(__tt3, __tt7, 0x31);\n  }\n\
    \n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"))) void\n\
    \  precalc() {\n    __attribute__((aligned(32))) u32 b1[32];\n    __attribute__((aligned(32)))\
    \ __m256 b2[8];\n    int max = ((mod / 2) / v + 12) / 8 * 8;\n    f.resize(max\
    \ + 1, raw_cast(1));\n    for (int i = 0; i < 32; i++) b1[i] = raw_cast(i + 1);\n\
    \    m256 A0 = _mm256_set1_epi32(b1[0]);\n    m256 A1 = _mm256_set1_epi32(b1[0]);\n\
    \    m256 A2 = _mm256_set1_epi32(b1[0]);\n    m256 A3 = _mm256_set1_epi32(b1[0]);\n\
    \    m256 B0 = _mm256_load_si256((m256*)(b1 + 0));\n    m256 B1 = _mm256_load_si256((m256*)(b1\
    \ + 8));\n    m256 B2 = _mm256_load_si256((m256*)(b1 + 16));\n    m256 B3 = _mm256_load_si256((m256*)(b1\
    \ + 24));\n    m256 DI = _mm256_set1_epi32(mod * 2 - b1[31]);\n    for (int i\
    \ = 1; i < (int)f.size(); i += 8) {\n      for (int j = 0; j < 8; j++) {\n   \
    \     for (u32 loop = 0; loop < v / 32; loop++) {\n          A0 = simd_mul(A0,\
    \ B0), A1 = simd_mul(A1, B1);\n          A2 = simd_mul(A2, B2), A3 = simd_mul(A3,\
    \ B3);\n          B0 = simd_sub(B0, DI), B1 = simd_sub(B1, DI);\n          B2\
    \ = simd_sub(B2, DI), B3 = simd_sub(B3, DI);\n        }\n        m256 C0 = simd_mul(A0,\
    \ A1);\n        m256 C1 = simd_mul(A2, A3);\n        m256 C2 = simd_mul(C0, C1);\n\
    \        _mm256_store_si256((m256*)(b2 + j), C2);\n      }\n      transpose8_ps(b2[0],\
    \ b2[1], b2[2], b2[3], b2[4], b2[5], b2[6], b2[7]);\n      m256 D0 = simd_mul(m256(b2[0]),\
    \ m256(b2[1]));\n      m256 D1 = simd_mul(m256(b2[2]), m256(b2[3]));\n      m256\
    \ D2 = simd_mul(m256(b2[4]), m256(b2[5]));\n      m256 D3 = simd_mul(m256(b2[6]),\
    \ m256(b2[7]));\n      m256 D4 = simd_mul(D0, D1);\n      m256 D5 = simd_mul(D2,\
    \ D3);\n      m256 D6 = simd_mul(D4, D5);\n      _mm256_storeu_si256((m256*)(f.data()\
    \ + i), D6);\n    }\n  }\n\n  u32 mod, r, n2;\n  Barrett bm;\n  m256 R, M0, M1,\
    \ M2;\n  static constexpr u32 v = 128;\n  static_assert(v % 32 == 0);\n  vector<u32>\
    \ f;\n\n  simd_prime_binomial() = default;\n\n  __attribute__((target(\"avx2\"\
    ), optimize(\"O3\", \"unroll-loops\")))\n  simd_prime_binomial(u32 _mod)\n   \
    \   : mod(_mod) {\n    assert(2 < mod && mod < (1u << 30));\n    assert(mod %\
    \ 2 != 0);\n    r = get_r(mod);\n    n2 = -u64(mod) % mod;\n    bm = Barrett(mod);\n\
    \    R = _mm256_set1_epi32(r);\n    M0 = _mm256_set1_epi32(0);\n    M1 = _mm256_set1_epi32(mod);\n\
    \    M2 = _mm256_set1_epi32(mod * 2);\n    precalc();\n  }\n\n  u32 raw_fac(u64\
    \ n) {\n    assert(n < mod);\n    if (n * 2 > mod + 2) {\n      u64 x = raw_fac(mod\
    \ - 1 - n);\n      if (n % 2 == 0) x = mod * 2 - x;\n      return inv(x);\n  \
    \  }\n    u32 a = f[n / v], i = n / v * v + 1;\n    u32 j = raw_cast(i), o = raw_cast(1);\n\
    \    while (i++ <= n) {\n      a = mul(a, j), j = add(j, o);\n    }\n    return\
    \ a;\n  }\n\n  inline u32 fac(u64 n) {\n    if (n >= mod) return 0;\n    return\
    \ get(raw_fac(n));\n  }\n\n  u32 C(long long n, long long m) {\n    if (n < 0\
    \ or m < 0 or n < m) return 0;\n    u32 num = raw_cast(1), denom = raw_cast(1);\n\
    \    while (n) {\n      long long n0, m0;\n      tie(n, n0) = bm.quorem(n);\n\
    \      tie(m, m0) = bm.quorem(m);\n      if (n0 < m0) return 0;\n      num = mul(num,\
    \ raw_fac(n0));\n      denom = mul(denom, raw_fac(n0 - m0));\n      denom = mul(denom,\
    \ raw_fac(m0));\n    }\n    return get(mul(num, inv(denom)));\n  }\n};\n\nstruct\
    \ prime_power_binomial {\n  int p, q, M;\n  vector<int> fac, ifac, inv;\n  int\
    \ delta;\n  Barrett bm, bp;\n\n  prime_power_binomial() = default;\n\n  prime_power_binomial(int\
    \ _p, int _q) : p(_p), q(_q) {\n    assert(1 < p && p <= PRIME_POWER_BINOMIAL_M_MAX);\n\
    \    assert(_q > 0);\n    long long m = 1;\n    while (_q--) {\n      m *= p;\n\
    \      assert(m <= PRIME_POWER_BINOMIAL_M_MAX);\n    }\n    M = m;\n    bm = Barrett(M),\
    \ bp = Barrett(p);\n    enumerate();\n    delta = (p == 2 && q >= 3) ? 1 : M -\
    \ 1;\n  }\n\n  void enumerate() {\n    int MX = min<int>(M, PRIME_POWER_BINOMIAL_N_MAX\
    \ + 10);\n    fac.resize(MX);\n    ifac.resize(MX);\n    inv.resize(MX);\n   \
    \ fac[0] = ifac[0] = inv[0] = 1;\n    fac[1] = ifac[1] = inv[1] = 1;\n    for\
    \ (int i = 2; i < MX; i++) {\n      if (i % p == 0) {\n        fac[i] = fac[i\
    \ - 1];\n        fac[i + 1] = bm.rem(1LL * fac[i - 1] * (i + 1));\n        i++;\n\
    \      } else {\n        fac[i] = bm.rem(1LL * fac[i - 1] * i);\n      }\n   \
    \ }\n    ifac[MX - 1] = bm.pow(fac[MX - 1], M / p * (p - 1) - 1);\n    for (int\
    \ i = MX - 2; i > 1; --i) {\n      if (i % p == 0) {\n        ifac[i] = bm.rem(1LL\
    \ * ifac[i + 1] * (i + 1));\n        ifac[i - 1] = ifac[i];\n        i--;\n  \
    \    } else {\n        ifac[i] = bm.rem(1LL * ifac[i + 1] * (i + 1));\n      }\n\
    \    }\n  }\n\n  long long Lucas(long long n, long long m) {\n    int res = 1;\n\
    \    while (n) {\n      int n0, m0;\n      tie(n, n0) = bp.quorem(n);\n      tie(m,\
    \ m0) = bp.quorem(m);\n      if (n0 < m0) return 0;\n      res = bm.rem(1LL *\
    \ res * fac[n0]);\n      int buf = bm.rem(1LL * ifac[n0 - m0] * ifac[m0]);\n \
    \     res = bm.rem(1LL * res * buf);\n    }\n    return res;\n  }\n\n  long long\
    \ C(long long n, long long m) {\n    if (n < m || n < 0 || m < 0) return 0;\n\
    \    if (q == 1) return Lucas(n, m);\n    long long r = n - m;\n    int e0 = 0,\
    \ eq = 0, i = 0;\n    int res = 1;\n    while (n) {\n      res = bm.rem(1LL *\
    \ res * fac[bm.rem(n)]);\n      res = bm.rem(1LL * res * ifac[bm.rem(m)]);\n \
    \     res = bm.rem(1LL * res * ifac[bm.rem(r)]);\n      n = bp.quo(n);\n     \
    \ m = bp.quo(m);\n      r = bp.quo(r);\n      int eps = n - m - r;\n      e0 +=\
    \ eps;\n      if (e0 >= q) return 0;\n      if (++i >= q) eq += eps;\n    }\n\
    \    if (eq & 1) res = bm.rem(1LL * res * delta);\n    res = bm.rem(1LL * res\
    \ * bm.pow(p, e0));\n    return res;\n  }\n};\n\n// constraints:\n// M <= 1e9\
    \ and max(N) <= 1e18\nstruct arbitrary_mod_binomial {\n  int mod;\n  vector<int>\
    \ M1, M2;\n  vector<prime_power_binomial> cs1;\n  vector<simd_prime_binomial>\
    \ cs2;\n\n  void push_cs(int i, int j, int k) {\n    if (i < PRIME_POWER_BINOMIAL_N_MAX\
    \ || j != 1) {\n      cs1.emplace_back(i, j);\n      M1.push_back(k);\n    } else\
    \ {\n      assert(j == 1);\n      cs2.emplace_back(i);\n      M2.push_back(k);\n\
    \    }\n  }\n\n  arbitrary_mod_binomial(long long md) : mod(md) {\n    assert(1\
    \ <= md);\n    assert(md <= PRIME_POWER_BINOMIAL_M_MAX);\n    for (int i = 2;\
    \ i * i <= md; i++) {\n      if (md % i == 0) {\n        int j = 0, k = 1;\n \
    \       while (md % i == 0) md /= i, j++, k *= i;\n        push_cs(i, j, k);\n\
    \      }\n    }\n    if (md != 1) push_cs(md, 1, md);\n    assert(M1.size() ==\
    \ cs1.size());\n    assert(M2.size() == cs2.size());\n  }\n\n  long long C(long\
    \ long n, long long m) {\n    if (mod == 1) return 0;\n    vector<long long> rem,\
    \ d;\n    for (int i = 0; i < (int)cs1.size(); i++) {\n      rem.push_back(cs1[i].C(n,\
    \ m));\n      d.push_back(M1[i]);\n    }\n    for (int i = 0; i < (int)cs2.size();\
    \ i++) {\n      rem.push_back(cs2[i].C(n, m));\n      d.push_back(M2[i]);\n  \
    \  }\n    return atcoder::crt(rem, d).first;\n  }\n};\n\n#undef PRIME_POWER_BINOMIAL_M_MAX\n\
    #undef PRIME_POWER_BINOMIAL_N_MAX\n#line 6 \"verify/verify-yosupo-math/yosupo-binomial-coefficient-large.test.cpp\"\
    \n//\n#line 2 \"misc/fastio.hpp\"\n\n#line 6 \"misc/fastio.hpp\"\n\nusing namespace\
    \ std;\n\nnamespace fastio {\nstatic constexpr int SZ = 1 << 17;\nchar inbuf[SZ],\
    \ outbuf[SZ];\nint in_left = 0, in_right = 0, out_right = 0;\n\nstruct Pre {\n\
    \  char num[40000];\n  constexpr Pre() : num() {\n    for (int i = 0; i < 10000;\
    \ i++) {\n      int n = i;\n      for (int j = 3; j >= 0; j--) {\n        num[i\
    \ * 4 + j] = n % 10 + '0';\n        n /= 10;\n      }\n    }\n  }\n} constexpr\
    \ pre;\n\ninline void load() {\n  int len = in_right - in_left;\n  memmove(inbuf,\
    \ inbuf + in_left, len);\n  in_right = len + fread(inbuf + len, 1, SZ - len, stdin);\n\
    \  in_left = 0;\n}\n\ninline void flush() {\n  fwrite(outbuf, 1, out_right, stdout);\n\
    \  out_right = 0;\n}\n\ninline void skip_space() {\n  if (in_left + 32 > in_right)\
    \ load();\n  while (inbuf[in_left] <= ' ') in_left++;\n}\n\ninline void rd(char&\
    \ c) {\n  if (in_left + 32 > in_right) load();\n  c = inbuf[in_left++];\n}\ntemplate\
    \ <typename T>\ninline void rd(T& x) {\n  if (in_left + 32 > in_right) load();\n\
    \  char c;\n  do c = inbuf[in_left++];\n  while (c < '-');\n  [[maybe_unused]]\
    \ bool minus = false;\n  if constexpr (is_signed<T>::value == true) {\n    if\
    \ (c == '-') minus = true, c = inbuf[in_left++];\n  }\n  x = 0;\n  while (c >=\
    \ '0') {\n    x = x * 10 + (c & 15);\n    c = inbuf[in_left++];\n  }\n  if constexpr\
    \ (is_signed<T>::value == true) {\n    if (minus) x = -x;\n  }\n}\ninline void\
    \ rd() {}\ntemplate <typename Head, typename... Tail>\ninline void rd(Head& head,\
    \ Tail&... tail) {\n  rd(head);\n  rd(tail...);\n}\n\ninline void wt(char c) {\n\
    \  if (out_right > SZ - 32) flush();\n  outbuf[out_right++] = c;\n}\ninline void\
    \ wt(bool b) {\n  if (out_right > SZ - 32) flush();\n  outbuf[out_right++] = b\
    \ ? '1' : '0';\n}\ntemplate <typename T>\ninline void wt(T x) {\n  if (out_right\
    \ > SZ - 32) flush();\n  if (!x) {\n    outbuf[out_right++] = '0';\n    return;\n\
    \  }\n  if constexpr (is_signed<T>::value == true) {\n    if (x < 0) outbuf[out_right++]\
    \ = '-', x = -x;\n  }\n  int i = 12;\n  char buf[16];\n  while (x >= 10000) {\n\
    \    memcpy(buf + i, pre.num + (x % 10000) * 4, 4);\n    x /= 10000;\n    i -=\
    \ 4;\n  }\n  if (x < 100) {\n    if (x < 10) {\n      outbuf[out_right] = '0'\
    \ + x;\n      ++out_right;\n    } else {\n      uint32_t q = (uint32_t(x) * 205)\
    \ >> 11;\n      uint32_t r = uint32_t(x) - q * 10;\n      outbuf[out_right] =\
    \ '0' + q;\n      outbuf[out_right + 1] = '0' + r;\n      out_right += 2;\n  \
    \  }\n  } else {\n    if (x < 1000) {\n      memcpy(outbuf + out_right, pre.num\
    \ + (x << 2) + 1, 3);\n      out_right += 3;\n    } else {\n      memcpy(outbuf\
    \ + out_right, pre.num + (x << 2), 4);\n      out_right += 4;\n    }\n  }\n  memcpy(outbuf\
    \ + out_right, buf + i + 4, 12 - i);\n  out_right += 12 - i;\n}\ninline void wt()\
    \ {}\ntemplate <typename Head, typename... Tail>\ninline void wt(Head&& head,\
    \ Tail&&... tail) {\n  wt(head);\n  wt(forward<Tail>(tail)...);\n}\ntemplate <typename...\
    \ Args>\ninline void wtn(Args&&... x) {\n  wt(forward<Args>(x)...);\n  wt('\\\
    n');\n}\n\nstruct Dummy {\n  Dummy() { atexit(flush); }\n} dummy;\n\n}  // namespace\
    \ fastio\nusing fastio::rd;\nusing fastio::skip_space;\nusing fastio::wt;\nusing\
    \ fastio::wtn;\n#line 8 \"verify/verify-yosupo-math/yosupo-binomial-coefficient-large.test.cpp\"\
    \n\nusing namespace Nyaan;\n\nvoid Nyaan::solve() {\n  int T, m;\n  rd(T, m);\n\
    \  arbitrary_mod_binomial C(m);\n  while (T--) {\n    unsigned long long n, k;\n\
    \    rd(n, k);\n    auto ans = C.C(n, k);\n    wtn(ans);\n  }\n}\n\n/*\n#include\
    \ \"misc/rng.hpp\"\n#include \"misc/timer.hpp\"\nusing mint = LazyMontgomeryModInt<998244353>;\n\
    void verify() {\n  Timer timer;\n  simd_prime_binomial C(998244353);\n  cerr <<\
    \ \"time:\" << timer.elapsed() << endl;\n  mint f = 1, a = 1, one = 1;\n  for\
    \ (int i = 1; i < 998244353; i++) {\n    f *= a;\n    a += one;\n    if (rng()\
    \ % (1u << 16) == 0) {\n      mint f2 = C.fac(i);\n      if (f != f2) exit(1);\n\
    \    }\n  }\n  out(\"OK\");\n  cout.flush();\n  exit(0);\n}\n*/\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient\"\n\
    //\n#include \"../../template/template.hpp\"\n//\n#include \"../../modulo/arbitrary-mod-binomial-large.hpp\"\
    \n//\n#include \"../../misc/fastio.hpp\"\n\nusing namespace Nyaan;\n\nvoid Nyaan::solve()\
    \ {\n  int T, m;\n  rd(T, m);\n  arbitrary_mod_binomial C(m);\n  while (T--) {\n\
    \    unsigned long long n, k;\n    rd(n, k);\n    auto ans = C.C(n, k);\n    wtn(ans);\n\
    \  }\n}\n\n/*\n#include \"misc/rng.hpp\"\n#include \"misc/timer.hpp\"\nusing mint\
    \ = LazyMontgomeryModInt<998244353>;\nvoid verify() {\n  Timer timer;\n  simd_prime_binomial\
    \ C(998244353);\n  cerr << \"time:\" << timer.elapsed() << endl;\n  mint f = 1,\
    \ a = 1, one = 1;\n  for (int i = 1; i < 998244353; i++) {\n    f *= a;\n    a\
    \ += one;\n    if (rng() % (1u << 16) == 0) {\n      mint f2 = C.fac(i);\n   \
    \   if (f != f2) exit(1);\n    }\n  }\n  out(\"OK\");\n  cout.flush();\n  exit(0);\n\
    }\n*/\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - modulo/arbitrary-mod-binomial-large.hpp
  - modint/barrett-reduction.hpp
  - misc/fastio.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-math/yosupo-binomial-coefficient-large.test.cpp
  requiredBy: []
  timestamp: '2021-05-15 20:18:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-math/yosupo-binomial-coefficient-large.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-math/yosupo-binomial-coefficient-large.test.cpp
- /verify/verify/verify-yosupo-math/yosupo-binomial-coefficient-large.test.cpp.html
title: verify/verify-yosupo-math/yosupo-binomial-coefficient-large.test.cpp
---
