---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/garner.hpp
    title: Garner's algorithm
  - icon: ':heavy_check_mark:'
    path: math/nimber.hpp
    title: Nim Product
  - icon: ':question:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/nim_product_64
    links:
    - https://judge.yosupo.jp/problem/nim_product_64
  bundledCode: "#line 1 \"verify/verify-yosupo-math/yosupo-nim-product.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/nim_product_64\"\n\n#line 2\
    \ \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include\
    \ <cinttypes>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
    \ <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <initializer_list>\n#include <iomanip>\n#include <ios>\n\
    #include <iostream>\n#include <istream>\n#include <iterator>\n#include <limits>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n\
    #include <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include\
    \ <sstream>\n#include <stack>\n#include <streambuf>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\n\n// utility\n\
    #line 1 \"template/util.hpp\"\nnamespace Nyaan {\nusing ll = long long;\nusing\
    \ i64 = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\ntemplate <typename T>\nusing V = vector<T>;\ntemplate\
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
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line 4 \"verify/verify-yosupo-math/yosupo-nim-product.test.cpp\"\
    \n//\n#line 2 \"math/nimber.hpp\"\n\n#line 2 \"math/garner.hpp\"\n\n// input \
    \ : a, M (0 < a < M)\n// output : pair(g, x) s.t. g = gcd(a, M), xa = g (mod M),\
    \ 0 <= x < b/g\ntemplate <typename uint>\npair<uint, uint> gcd_inv(uint a, uint\
    \ M) {\n  assert(M != 0 && 0 < a);\n  a %= M;\n  uint b = M, s = 1, t = 0;\n \
    \ while (true) {\n    if (a == 0) return {b, t + M};\n    t -= b / a * s;\n  \
    \  b %= a;\n    if (b == 0) return {a, s};\n    s -= a / b * t;\n    a %= b;\n\
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
    \ algorithm\n */\n#line 4 \"math/nimber.hpp\"\n\nnamespace NimberImpl {\nusing\
    \ u16 = uint16_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\nstruct calc8\
    \ {\n  u16 dp[1 << 8][1 << 8];\n  constexpr calc8() : dp() {\n    dp[0][0] = dp[0][1]\
    \ = dp[1][0] = 0;\n    dp[1][1] = 1;\n    for (int e = 1; e <= 3; e++) {\n   \
    \   int p = 1 << e, q = p >> 1;\n      u16 ep = 1u << p, eq = 1u << q;\n     \
    \ for (u16 i = 0; i < ep; i++) {\n        for (u16 j = i; j < ep; j++) {\n   \
    \       if (i < eq && j < eq) continue;\n          if (min(i, j) <= 1u) {\n  \
    \          dp[i][j] = dp[j][i] = i * j;\n            continue;\n          }\n\
    \          u16 iu = i >> q, il = i & (eq - 1);\n          u16 ju = j >> q, jl\
    \ = j & (eq - 1);\n          u16 u = dp[iu][ju], l = dp[il][jl];\n          u16\
    \ ul = dp[iu ^ il][ju ^ jl];\n          u16 uq = dp[u][eq >> 1];\n          dp[i][j]\
    \ = ((ul ^ l) << q) ^ uq ^ l;\n          dp[j][i] = dp[i][j];\n        }\n   \
    \   }\n    }\n  }\n} constexpr c8;\n\nstruct calc16 {\n  static constexpr u16\
    \ proot = 10279;\n  static constexpr u32 ppoly = 92191;\n  static constexpr int\
    \ order = 65535;\n\n  u16 base[16], exp[(1 << 18) + 100];\n  int log[1 << 16];\n\
    \n private:\n  constexpr u16 d(u32 x) { return (x << 1) ^ (x < 32768u ? 0 : ppoly);\
    \ }\n\n  constexpr u16 naive(u16 i, u16 j) {\n    if (min(i, j) <= 1u) return\
    \ i * j;\n    u16 q = 8, eq = 1u << 8;\n    u16 iu = i >> q, il = i & (eq - 1);\n\
    \    u16 ju = j >> q, jl = j & (eq - 1);\n    u16 u = c8.dp[iu][ju];\n    u16\
    \ l = c8.dp[il][jl];\n    u16 ul = c8.dp[iu ^ il][ju ^ jl];\n    u16 uq = c8.dp[u][eq\
    \ >> 1];\n    return ((ul ^ l) << q) ^ uq ^ l;\n  }\n\n public:\n  constexpr calc16()\
    \ : base(), exp(), log() {\n    base[0] = 1;\n    for (int i = 1; i < 16; i++)\
    \ base[i] = naive(base[i - 1], proot);\n    exp[0] = 1;\n    for (int i = 1; i\
    \ < order; i++) exp[i] = d(exp[i - 1]);\n    u16* pre = exp + order + 1;\n   \
    \ pre[0] = 0;\n    for (int b = 0; b < 16; b++) {\n      int is = 1 << b, ie =\
    \ is << 1;\n      for (int i = is; i < ie; i++) pre[i] = pre[i - is] ^ base[b];\n\
    \    }\n    for (int i = 0; i < order; i++) exp[i] = pre[exp[i]], log[exp[i]]\
    \ = i;\n\n    int ie = 2 * order + 30;\n    for (int i = order; i < ie; i++) exp[i]\
    \ = exp[i - order];\n    for (unsigned int i = ie; i < sizeof(exp) / sizeof(u16);\
    \ i++) exp[i] = 0;\n    log[0] = ie + 1;\n  }\n\n  constexpr u16 prod(u16 i, u16\
    \ j) const { return exp[log[i] + log[j]]; }\n\n  // exp[3] = 2^{15} = 32768\n\
    \  constexpr u16 Hprod(u16 i, u16 j) const { return exp[log[i] + log[j] + 3];\
    \ }\n  constexpr u16 H(u16 i) const { return exp[log[i] + 3]; }\n  constexpr u16\
    \ H2(u16 i) const { return exp[log[i] + 6]; }\n} constexpr c16;\n\nu16 product16(u16\
    \ i, u16 j) { return c16.prod(i, j); }\n\nconstexpr u32 product32(u32 i, u32 j)\
    \ {\n  u16 iu = i >> 16, il = i & 65535;\n  u16 ju = j >> 16, jl = j & 65535;\n\
    \  u16 l = c16.prod(il, jl);\n  u16 ul = c16.prod(iu ^ il, ju ^ jl);\n  u16 uq\
    \ = c16.Hprod(iu, ju);\n  return (u32(ul ^ l) << 16) ^ uq ^ l;\n}\n\n// (+ : xor,\
    \ x : nim product, * : integer product)\n// i x j\n// = (iu x ju + il x ju + iu\
    \ x ji) * 2^{16}\n// + (iu x ju x 2^{15}) + il x jl\n// (assign ju = 2^{15}, jl\
    \ = 0)\n// = ((iu + il) x 2^{15}) * 2^{16} + (iu x 2^{15} x 2^{15})\nconstexpr\
    \ u32 H(u32 i) {\n  u16 iu = i >> 16;\n  u16 il = i & 65535;\n  return (u32(c16.H(iu\
    \ ^ il)) << 16) ^ c16.H2(iu);\n}\n\nconstexpr u64 product64(u64 i, u64 j) {\n\
    \  u32 iu = i >> 32, il = i & u32(-1);\n  u32 ju = j >> 32, jl = j & u32(-1);\n\
    \  u32 l = product32(il, jl);\n  u32 ul = product32(iu ^ il, ju ^ jl);\n  u32\
    \ uq = H(product32(iu, ju));\n  return (u64(ul ^ l) << 32) ^ uq ^ l;\n}\n}  //\
    \ namespace NimberImpl\n\ntemplate <typename uint, uint (*prod)(uint, uint)>\n\
    struct NimberBase {\n  using N = NimberBase;\n  uint x;\n  NimberBase() : x(0)\
    \ {}\n  NimberBase(uint _x) : x(_x) {}\n  static N id0() { return {}; }\n  static\
    \ N id1() { return {1}; }\n\n  N& operator+=(const N& p) {\n    x ^= p.x;\n  \
    \  return *this;\n  }\n  N& operator-=(const N& p) {\n    x ^= p.x;\n    return\
    \ *this;\n  }\n  N& operator*=(const N& p) {\n    x = prod(x, p.x);\n    return\
    \ *this;\n  }\n  N operator+(const N& p) const { return x ^ p.x; }\n  N operator-(const\
    \ N& p) const { return x ^ p.x; }\n  N operator*(const N& p) const { return prod(x,\
    \ p.x); }\n  bool operator==(const N& p) const { return x == p.x; }\n  bool operator!=(const\
    \ N& p) const { return x != p.x; }\n  N pow(uint64_t n) const {\n    N a = *this,\
    \ r = 1;\n    for (; n; a *= a, n >>= 1)\n      if (n & 1) r *= a;\n    return\
    \ r;\n  }\n  friend ostream& operator<<(ostream& os, const N& p) { return os <<\
    \ p.x; }\n\n  // calculate log_a (b)\n  uint discrete_logarithm(N y) const {\n\
    \    assert(x != 0 && y != 0);\n    vector<uint> rem, mod;\n    for (uint p :\
    \ {3, 5, 17, 257, 641, 65537, 6700417}) {\n      if (uint(-1) % p) continue;\n\
    \      uint q = uint(-1) / p;\n      uint STEP = 1;\n      while (4 * STEP * STEP\
    \ < p) STEP *= 2;\n      // a^m = z \u3092\u6E80\u305F\u3059 1 \u4EE5\u4E0A\u306E\
    \u6574\u6570 m \u3092\u8FD4\u3059\n      auto inside = [&](N a, N z) -> uint {\n\
    \        unordered_map<uint, int> mp;\n        N big = 1, now = 1;  // x^m\n \
    \       for (int i = 0; i < int(STEP); i++) {\n          mp[z.x] = i, z *= a,\
    \ big *= a;\n        }\n        for (int step = 0; step < int(p + 10); step +=\
    \ STEP) {\n          now *= big;\n          if (mp.find(now.x) != mp.end()) return\
    \ (step + STEP) - mp[now.x];\n        }\n        return uint(-1);\n      };\n\
    \      N xq = (*this).pow(q), yq = y.pow(q);\n      if (xq == 1 and yq == 1) continue;\n\
    \      if (xq == 1 and yq != 1) return uint(-1);\n      uint res = inside(xq,\
    \ yq);\n      if (res == uint(-1)) return uint(-1);\n      rem.push_back(res %\
    \ p);\n      mod.push_back(p);\n    }\n    return garner(rem, mod).first;\n  }\n\
    \n  uint is_primitive_root() const {\n    if (x == 0) return false;\n    for (uint\
    \ p : {3, 5, 17, 257, 641, 65537, 6700417}) {\n      if (uint(-1) % p != 0) continue;\n\
    \      if ((*this).pow(uint(-1) / p) == 1) return false;\n    }\n    return true;\n\
    \  }\n};\n\nusing Nimber16 = NimberBase<uint16_t, NimberImpl::product16>;\nusing\
    \ Nimber32 = NimberBase<uint32_t, NimberImpl::product32>;\nusing Nimber64 = NimberBase<uint64_t,\
    \ NimberImpl::product64>;\nusing Nimber = Nimber64;\n\n/**\n * @brief Nim Product\n\
    \ * @docs docs/math/nimber.md\n */\n#line 2 \"misc/fastio.hpp\"\n\n#line 6 \"\
    misc/fastio.hpp\"\n\nusing namespace std;\n\nnamespace fastio {\nstatic constexpr\
    \ int SZ = 1 << 17;\nchar inbuf[SZ], outbuf[SZ];\nint in_left = 0, in_right =\
    \ 0, out_right = 0;\n\nstruct Pre {\n  char num[40000];\n  constexpr Pre() : num()\
    \ {\n    for (int i = 0; i < 10000; i++) {\n      int n = i;\n      for (int j\
    \ = 3; j >= 0; j--) {\n        num[i * 4 + j] = n % 10 + '0';\n        n /= 10;\n\
    \      }\n    }\n  }\n} constexpr pre;\n\ninline void load() {\n  int len = in_right\
    \ - in_left;\n  memmove(inbuf, inbuf + in_left, len);\n  in_right = len + fread(inbuf\
    \ + len, 1, SZ - len, stdin);\n  in_left = 0;\n}\n\ninline void flush() {\n  fwrite(outbuf,\
    \ 1, out_right, stdout);\n  out_right = 0;\n}\n\ninline void skip_space() {\n\
    \  if (in_left + 32 > in_right) load();\n  while (inbuf[in_left] <= ' ') in_left++;\n\
    }\n\ninline void rd(char& c) {\n  if (in_left + 32 > in_right) load();\n  c =\
    \ inbuf[in_left++];\n}\ntemplate <typename T>\ninline void rd(T& x) {\n  if (in_left\
    \ + 32 > in_right) load();\n  char c;\n  do c = inbuf[in_left++];\n  while (c\
    \ < '-');\n  [[maybe_unused]] bool minus = false;\n  if constexpr (is_signed<T>::value\
    \ == true) {\n    if (c == '-') minus = true, c = inbuf[in_left++];\n  }\n  x\
    \ = 0;\n  while (c >= '0') {\n    x = x * 10 + (c & 15);\n    c = inbuf[in_left++];\n\
    \  }\n  if constexpr (is_signed<T>::value == true) {\n    if (minus) x = -x;\n\
    \  }\n}\ninline void rd() {}\ntemplate <typename Head, typename... Tail>\ninline\
    \ void rd(Head& head, Tail&... tail) {\n  rd(head);\n  rd(tail...);\n}\n\ninline\
    \ void wt(char c) {\n  if (out_right > SZ - 32) flush();\n  outbuf[out_right++]\
    \ = c;\n}\ninline void wt(bool b) {\n  if (out_right > SZ - 32) flush();\n  outbuf[out_right++]\
    \ = b ? '1' : '0';\n}\ninline void wt(const string &s) {\n  if (out_right + s.size()\
    \ > SZ - 32) flush();\n  memcpy(outbuf + out_right, s.data(), sizeof(char) * s.size());\n\
    \  out_right += s.size();\n}\ntemplate <typename T>\ninline void wt(T x) {\n \
    \ if (out_right > SZ - 32) flush();\n  if (!x) {\n    outbuf[out_right++] = '0';\n\
    \    return;\n  }\n  if constexpr (is_signed<T>::value == true) {\n    if (x <\
    \ 0) outbuf[out_right++] = '-', x = -x;\n  }\n  int i = 12;\n  char buf[16];\n\
    \  while (x >= 10000) {\n    memcpy(buf + i, pre.num + (x % 10000) * 4, 4);\n\
    \    x /= 10000;\n    i -= 4;\n  }\n  if (x < 100) {\n    if (x < 10) {\n    \
    \  outbuf[out_right] = '0' + x;\n      ++out_right;\n    } else {\n      uint32_t\
    \ q = (uint32_t(x) * 205) >> 11;\n      uint32_t r = uint32_t(x) - q * 10;\n \
    \     outbuf[out_right] = '0' + q;\n      outbuf[out_right + 1] = '0' + r;\n \
    \     out_right += 2;\n    }\n  } else {\n    if (x < 1000) {\n      memcpy(outbuf\
    \ + out_right, pre.num + (x << 2) + 1, 3);\n      out_right += 3;\n    } else\
    \ {\n      memcpy(outbuf + out_right, pre.num + (x << 2), 4);\n      out_right\
    \ += 4;\n    }\n  }\n  memcpy(outbuf + out_right, buf + i + 4, 12 - i);\n  out_right\
    \ += 12 - i;\n}\ninline void wt() {}\ntemplate <typename Head, typename... Tail>\n\
    inline void wt(Head&& head, Tail&&... tail) {\n  wt(head);\n  wt(forward<Tail>(tail)...);\n\
    }\ntemplate <typename... Args>\ninline void wtn(Args&&... x) {\n  wt(forward<Args>(x)...);\n\
    \  wt('\\n');\n}\n\nstruct Dummy {\n  Dummy() { atexit(flush); }\n} dummy;\n\n\
    }  // namespace fastio\nusing fastio::rd;\nusing fastio::skip_space;\nusing fastio::wt;\n\
    using fastio::wtn;\n#line 7 \"verify/verify-yosupo-math/yosupo-nim-product.test.cpp\"\
    \n\nusing namespace Nyaan;\nvoid Nyaan::solve() {\n  int T;\n  rd(T);\n  rep(i,\
    \ T) {\n    uint64_t a, b;\n    rd(a, b);\n    wtn(NimberImpl::product64(a, b));\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/nim_product_64\"\n\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../math/nimber.hpp\"\n#include\
    \ \"../../misc/fastio.hpp\"\n\nusing namespace Nyaan;\nvoid Nyaan::solve() {\n\
    \  int T;\n  rd(T);\n  rep(i, T) {\n    uint64_t a, b;\n    rd(a, b);\n    wtn(NimberImpl::product64(a,\
    \ b));\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - math/nimber.hpp
  - math/garner.hpp
  - misc/fastio.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-math/yosupo-nim-product.test.cpp
  requiredBy: []
  timestamp: '2021-12-23 23:20:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-math/yosupo-nim-product.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-math/yosupo-nim-product.test.cpp
- /verify/verify/verify-yosupo-math/yosupo-nim-product.test.cpp.html
title: verify/verify-yosupo-math/yosupo-nim-product.test.cpp
---
