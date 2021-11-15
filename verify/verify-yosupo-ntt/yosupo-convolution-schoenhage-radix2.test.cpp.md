---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/schoenhage-strassen-radix2.hpp
    title: "Sch\xF6nhage-Strassen Algorithm(radix-2)"
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#line 1 \"verify/verify-yosupo-ntt/yosupo-convolution-schoenhage-radix2.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
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
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line 4 \"verify/verify-yosupo-ntt/yosupo-convolution-schoenhage-radix2.test.cpp\"\
    \n//\nusing namespace Nyaan;\n\n#line 2 \"modint/montgomery-modint.hpp\"\n\n\n\
    \ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n\
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
    \ { return mod; }\n};\n#line 2 \"ntt/schoenhage-strassen-radix2.hpp\"\n\ntemplate\
    \ <typename T>\nstruct Schoenhage_Strassen_radix2 {\n  T* buf = nullptr;\n\n \
    \ void rot(T* dst, T* src, int s, int d) {\n    assert(0 <= d and d < 2 * s);\n\
    \    bool f = s <= d;\n    if (s <= d) d -= s;\n    int i = 0;\n    if (f) {\n\
    \      for (; i < s - d; i++) dst[i + d] = -src[i];\n      for (; i < s; i++)\
    \ dst[i + d - s] = src[i];\n    } else {\n      for (; i < s - d; i++) dst[i +\
    \ d] = src[i];\n      for (; i < s; i++) dst[i + d - s] = -src[i];\n    }\n  }\n\
    \n  void in_add(T* dst, T* src, int s) {\n    for (int i = 0; i < s; i++) dst[i]\
    \ += src[i];\n  }\n  void in_sub(T* dst, T* src, int s) {\n    for (int i = 0;\
    \ i < s; i++) dst[i] -= src[i];\n  }\n\n  void cp(T* dst, T* src, int s) { memcpy(dst,\
    \ src, s * sizeof(T)); }\n  void reset(T* dst, int s) { fill(dst, dst + s, T());\
    \ }\n\n  // R[x] / (1 + x^(2^m)) \u4E0A\u306E\u9577\u30552^L\u306EFFT\n  void\
    \ fft(T* a, int l, int m) {\n    if (l == 0) return;\n    int L = 1 << l, M =\
    \ 1 << m;\n    assert(M * 2 >= L);\n    assert(buf != nullptr);\n\n    vector<int>\
    \ dw(l - 1);\n    for (int i = 0; i < l - 1; i++) {\n      dw[i] = (1 << (l -\
    \ 2 - i)) + (1 << (l - 1 - i)) - (1 << (l - 1));\n      if (dw[i] < 0) dw[i] +=\
    \ L;\n      if (L == M) dw[i] *= 2;\n      if (2 * L == M) dw[i] *= 4;\n    }\n\
    \n    for (int d = L; d >>= 1;) {\n      int w = 0;\n      for (int s = 0, k =\
    \ 0;;) {\n        for (int i = s, j = s + d; i < s + d; ++i, ++j) {\n        \
    \  T *ai = a + i * M, *aj = a + j * M;\n          rot(buf, aj, M, w);\n      \
    \    cp(aj, ai, M);\n          in_add(ai, buf, M);\n          in_sub(aj, buf,\
    \ M);\n        }\n        if ((s += 2 * d) >= L) break;\n        w += dw[__builtin_ctz(++k)];\n\
    \        if (w >= 2 * M) w -= 2 * M;\n      }\n    }\n  }\n\n  // R[x] / (1 +\
    \ x^(2^m)) \u4E0A\u306E\u9577\u30552^L\u306EIFFT\n  void ifft(T* a, int l, int\
    \ m) {\n    if (l == 0) return;\n    int L = 1 << l, M = 1 << m;\n    assert(M\
    \ * 2 >= L);\n    assert(buf != nullptr);\n\n    vector<int> dw(l - 1);\n    for\
    \ (int i = 0; i < l - 1; i++) {\n      dw[i] = (1 << (l - 2 - i)) + (1 << (l -\
    \ 1 - i)) - (1 << (l - 1));\n      if (dw[i] < 0) dw[i] += L;\n      if (L ==\
    \ M) dw[i] *= 2;\n      if (2 * L == M) dw[i] *= 4;\n    }\n\n    for (int d =\
    \ 1; d < L; d *= 2) {\n      int w = 0;\n      for (int s = 0, k = 0;;) {\n  \
    \      for (int i = s, j = s + d; i < s + d; ++i, ++j) {\n          T *ai = a\
    \ + i * M, *aj = a + j * M;\n          cp(buf, ai, M);\n          in_add(ai, aj,\
    \ M);\n          in_sub(buf, aj, M);\n          rot(aj, buf, M, w);\n        }\n\
    \        if ((s += 2 * d) >= L) break;\n        w -= dw[__builtin_ctz(++k)];\n\
    \        if (w < 0) w += 2 * M;\n      }\n    }\n  }\n\n  // a <- ab / (x^(2^n)+1)\n\
    \  int naive_mul(T* a, T* b, int n) {\n    int N = 1 << n;\n    reset(buf, N);\n\
    \    for (int i = 0; i < N; i++) {\n      int j = 0;\n      for (; j < N - i;\
    \ j++) buf[i + j] += a[i] * b[j];\n      for (; j < N; j++) buf[i + j - N] -=\
    \ a[i] * b[j];\n    }\n    cp(a, buf, N);\n    return 0;\n  }\n\n  // a <- ab\
    \ / (x^(2^n)+1)\n  int inplace_mul(T* a, T* b, int n) {\n    if (n <= 5) {\n \
    \     naive_mul(a, b, n);\n      return 0;\n    }\n\n    int l = (n + 1) / 2;\n\
    \    int m = n / 2;\n    int L = 1 << l, M = 1 << m, N = 1 << n;\n    int cnt\
    \ = 0;\n\n    // R[x] (x^(2^(m+1))-1) R[y] (y^(2^l)-1)\n    vector<T> A(N * 2),\
    \ B(N * 2);\n    reset(buf + M, M);\n    for (int i = 0, s = 0, ds = 2 * M / L;\
    \ i < L; i++) {\n      // y -> x^{2m/r} y\n      cp(buf, a + i * M, M);\n    \
    \  rot(A.data() + i * M * 2, buf, 2 * M, s);\n      cp(buf, b + i * M, M);\n \
    \     rot(B.data() + i * M * 2, buf, 2 * M, s);\n      s += ds;\n      if (s >=\
    \ 4 * M) s -= 4 * M;\n    }\n\n    fft(A.data(), l, m + 1);\n    fft(B.data(),\
    \ l, m + 1);\n    for (int i = 0; i < L; i++) {\n      cnt = inplace_mul(A.data()\
    \ + i * M * 2, B.data() + i * M * 2, m + 1);\n    }\n    ifft(A.data(), l, m +\
    \ 1);\n\n    for (int i = 0, s = 0, ds = 2 * M / L; i < L; i++) {\n      // y\
    \ -> x^{-2m/r} y\n      cp(buf, A.data() + i * M * 2, 2 * M);\n      rot(A.data()\
    \ + i * M * 2, buf, 2 * M, s);\n      s -= ds;\n      if (s < 0) s += 4 * M;\n\
    \    }\n\n    for (int i = 0; i < L; i++) {\n      for (int j = 0; j < M; j++)\
    \ {\n        a[i * M + j] = A[i * M * 2 + j];\n        if (i == 0) {\n       \
    \   a[i * M + j] -= A[(L - 1) * M * 2 + M + j];\n        } else {\n          a[i\
    \ * M + j] += A[(i - 1) * M * 2 + M + j];\n        }\n      }\n    }\n    return\
    \ cnt + l;\n  }\n\n  // a <- ab / (x^(2^n)-1)\n  int inplace_mul2(T* a, T* b,\
    \ int n) {\n    if (n <= 5) {\n      naive_mul(a, b, n);\n      return 0;\n  \
    \  }\n\n    int l = (n + 1) / 2;\n    int m = n / 2;\n    int L = 1 << l, M =\
    \ 1 << m, N = 1 << n;\n    int cnt = 0;\n\n    // R[x] (x^(2^(m+1))-1) R[y] (y^(2^l)-1)\n\
    \    vector<T> A(N * 2), B(N * 2);\n    for (int i = 0; i < L; i++) {\n      cp(A.data()\
    \ + i * M * 2, a + i * M, M);\n      cp(B.data() + i * M * 2, b + i * M, M);\n\
    \    }\n    fft(A.data(), l, m + 1);\n    fft(B.data(), l, m + 1);\n    for (int\
    \ i = 0; i < L; i++) {\n      cnt = inplace_mul(A.data() + i * M * 2, B.data()\
    \ + i * M * 2, m + 1);\n    }\n    ifft(A.data(), l, m + 1);\n    for (int i =\
    \ 0; i < L; i++) {\n      for (int j = 0; j < M; j++) {\n        a[i * M + j]\
    \ = A[i * M * 2 + j];\n        a[i * M + j] += A[(i ? i - 1 : L - 1) * M * 2 +\
    \ M + j];\n      }\n    }\n    return cnt + l;\n  }\n\n  pair<vector<T>, int>\
    \ multiply(const vector<T>& a, const vector<T>& b) {\n    int L = a.size() + b.size()\
    \ - 1;\n    int M = 1, m = 0;\n    while (M < L) M *= 2, m++;\n    buf = new T[M];\n\
    \    vector<T> s(M), t(M);\n    for (int i = 0; i < (int)a.size(); i++) s[i] =\
    \ a[i];\n    for (int i = 0; i < (int)b.size(); i++) t[i] = b[i];\n    int cnt\
    \ = inplace_mul2(s.data(), t.data(), m);\n    vector<T> u(L);\n    for (int i\
    \ = 0; i < L; i++) u[i] = s[i];\n    delete[] buf;\n    return make_pair(u, cnt);\n\
    \  }\n};\n\n/**\n * @brief Sch\xF6nhage-Strassen Algorithm(radix-2)\n */\n#line\
    \ 9 \"verify/verify-yosupo-ntt/yosupo-convolution-schoenhage-radix2.test.cpp\"\
    \n\nusing mint = LazyMontgomeryModInt<1000000007>;\nusing vm = V<mint>;\nSchoenhage_Strassen_radix2<mint>\
    \ ss;\n\n/*\n#include \"misc/timer.hpp\"\n\nvoid calc() {\n  int N = TEN(5) *\
    \ 5;\n  vm a(N), b(N);\n  int e = 1;\n  each(x, a) x = e, ++e;\n  each(x, b) x\
    \ = e, ++e;\n\n  Timer timer;\n  auto c = ss.multiply(a, b);\n  cerr << c.first.size()\
    \ << \" \" << timer.elapsed() << endl;\n}\n\nvoid test() {\n  for (int n = 1,\
    \ m = 1; n < 100; n += 2, m += 2) {\n    vm a(n), b(m);\n    int e = 1;\n    each(x,\
    \ a) x = e, e += 1;\n    // each(x, b) x = e, e += 1;\n    b = a;\n\n    auto\
    \ [c, d] = ss.multiply(a, b);\n    mint inv = mint(1 << d).inverse();\n    each(x,\
    \ c) x *= inv;\n\n    vm C(n + m - 1);\n    rep(i, n) rep(j, m) C[i + j] += a[i]\
    \ * b[j];\n    assert(C == c);\n  }\n}\n*/\n\nvoid Nyaan::solve() {\n  // test();\n\
    \  // calc();\n\n  ini(N, M);\n  vm a(N), b(M);\n  in(a, b);\n\n  auto [c, d]\
    \ = ss.multiply(a, b);\n  mint inv = mint(1 << d).inverse();\n  each(x, c) x *=\
    \ inv;\n\n  out(c);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n//\n#include \"../../template/template.hpp\"\n//\nusing namespace Nyaan;\n\n\
    #include \"../../modint/montgomery-modint.hpp\"\n#include \"../../ntt/schoenhage-strassen-radix2.hpp\"\
    \n\nusing mint = LazyMontgomeryModInt<1000000007>;\nusing vm = V<mint>;\nSchoenhage_Strassen_radix2<mint>\
    \ ss;\n\n/*\n#include \"misc/timer.hpp\"\n\nvoid calc() {\n  int N = TEN(5) *\
    \ 5;\n  vm a(N), b(N);\n  int e = 1;\n  each(x, a) x = e, ++e;\n  each(x, b) x\
    \ = e, ++e;\n\n  Timer timer;\n  auto c = ss.multiply(a, b);\n  cerr << c.first.size()\
    \ << \" \" << timer.elapsed() << endl;\n}\n\nvoid test() {\n  for (int n = 1,\
    \ m = 1; n < 100; n += 2, m += 2) {\n    vm a(n), b(m);\n    int e = 1;\n    each(x,\
    \ a) x = e, e += 1;\n    // each(x, b) x = e, e += 1;\n    b = a;\n\n    auto\
    \ [c, d] = ss.multiply(a, b);\n    mint inv = mint(1 << d).inverse();\n    each(x,\
    \ c) x *= inv;\n\n    vm C(n + m - 1);\n    rep(i, n) rep(j, m) C[i + j] += a[i]\
    \ * b[j];\n    assert(C == c);\n  }\n}\n*/\n\nvoid Nyaan::solve() {\n  // test();\n\
    \  // calc();\n\n  ini(N, M);\n  vm a(N), b(M);\n  in(a, b);\n\n  auto [c, d]\
    \ = ss.multiply(a, b);\n  mint inv = mint(1 << d).inverse();\n  each(x, c) x *=\
    \ inv;\n\n  out(c);\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - modint/montgomery-modint.hpp
  - ntt/schoenhage-strassen-radix2.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ntt/yosupo-convolution-schoenhage-radix2.test.cpp
  requiredBy: []
  timestamp: '2021-06-12 11:33:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ntt/yosupo-convolution-schoenhage-radix2.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ntt/yosupo-convolution-schoenhage-radix2.test.cpp
- /verify/verify/verify-yosupo-ntt/yosupo-convolution-schoenhage-radix2.test.cpp.html
title: verify/verify-yosupo-ntt/yosupo-convolution-schoenhage-radix2.test.cpp
---
