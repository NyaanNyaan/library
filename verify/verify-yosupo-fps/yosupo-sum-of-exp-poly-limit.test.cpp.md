---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':question:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':question:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':question:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  - icon: ':heavy_check_mark:'
    path: fps/lagrange-interpolation-point.hpp
    title: fps/lagrange-interpolation-point.hpp
  - icon: ':heavy_check_mark:'
    path: fps/sum-of-exponential-times-poly.hpp
    title: $\sum_{i}a^i f(i)$
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
    links:
    - https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
  bundledCode: "#line 1 \"verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n\n#line 1 \"competitive-template.hpp\"\n#pragma region kyopro_template\n#define\
    \ Nyaan_template\n#include <immintrin.h>\n#include <bits/stdc++.h>\n#define pb\
    \ push_back\n#define eb emplace_back\n#define fi first\n#define se second\n#define\
    \ each(x, v) for (auto &x : v)\n#define all(v) (v).begin(), (v).end()\n#define\
    \ sz(v) ((int)(v).size())\n#define mem(a, val) memset(a, val, sizeof(a))\n#define\
    \ ini(...)   \\\n  int __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define inl(...)  \
    \       \\\n  long long __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define ins(...) \
    \     \\\n  string __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define inc(...)    \\\n\
    \  char __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define in2(s, t)                \
    \           \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i]);\
    \                         \\\n  }\n#define in3(s, t, u)                      \
    \  \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i], u[i]);\
    \                   \\\n  }\n#define in4(s, t, u, v)                     \\\n\
    \  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i], u[i], v[i]);\
    \             \\\n  }\n#define rep(i, N) for (long long i = 0; i < (long long)(N);\
    \ i++)\n#define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)\n\
    #define rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)\n#define repr1(i,\
    \ N) for (long long i = (N); (long long)(i) > 0; i--)\n#define reg(i, a, b) for\
    \ (long long i = (a); i < (b); i++)\n#define die(...)      \\\n  do {        \
    \        \\\n    out(__VA_ARGS__); \\\n    return;           \\\n  } while (0)\n\
    using namespace std;\nusing ll = long long;\ntemplate <class T>\nusing V = vector<T>;\n\
    using vi = vector<int>;\nusing vl = vector<long long>;\nusing vvi = vector<vector<int>>;\n\
    using vd = V<double>;\nusing vs = V<string>;\nusing vvl = vector<vector<long long>>;\n\
    using P = pair<long long, long long>;\nusing vp = vector<P>;\nusing pii = pair<int,\
    \ int>;\nusing vpi = vector<pair<int, int>>;\nconstexpr int inf = 1001001001;\n\
    constexpr long long infLL = (1LL << 61) - 1;\ntemplate <typename T, typename U>\n\
    inline bool amin(T &x, U y) {\n  return (y < x) ? (x = y, true) : false;\n}\n\
    template <typename T, typename U>\ninline bool amax(T &x, U y) {\n  return (x\
    \ < y) ? (x = y, true) : false;\n}\ntemplate <typename T, typename U>\nostream\
    \ &operator<<(ostream &os, const pair<T, U> &p) {\n  os << p.first << \" \" <<\
    \ p.second;\n  return os;\n}\ntemplate <typename T, typename U>\nistream &operator>>(istream\
    \ &is, pair<T, U> &p) {\n  is >> p.first >> p.second;\n  return is;\n}\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n  int\
    \ s = (int)v.size();\n  for (int i = 0; i < s; i++) os << (i ? \" \" : \"\") <<\
    \ v[i];\n  return os;\n}\ntemplate <typename T>\nistream &operator>>(istream &is,\
    \ vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return is;\n}\nvoid in() {}\n\
    template <typename T, class... U>\nvoid in(T &t, U &... u) {\n  cin >> t;\n  in(u...);\n\
    }\nvoid out() { cout << \"\\n\"; }\ntemplate <typename T, class... U>\nvoid out(const\
    \ T &t, const U &... u) {\n  cout << t;\n  if (sizeof...(u)) cout << \" \";\n\
    \  out(u...);\n}\n\n#ifdef NyaanDebug\n#define trc(...)                   \\\n\
    \  do {                             \\\n    cerr << #__VA_ARGS__ << \" = \"; \\\
    \n    dbg_out(__VA_ARGS__);          \\\n  } while (0)\n#define trca(v, N)   \
    \    \\\n  do {                   \\\n    cerr << #v << \" = \"; \\\n    array_out(v,\
    \ N);     \\\n  } while (0)\n#define trcc(v)                             \\\n\
    \  do {                                      \\\n    cerr << #v << \" = {\"; \
    \                  \\\n    each(x, v) { cerr << \" \" << x << \",\"; } \\\n  \
    \  cerr << \"}\" << endl;                    \\\n  } while (0)\ntemplate <typename\
    \ T>\nvoid _cout(const T &c) {\n  cerr << c;\n}\nvoid _cout(const int &c) {\n\
    \  if (c == 1001001001)\n    cerr << \"inf\";\n  else if (c == -1001001001)\n\
    \    cerr << \"-inf\";\n  else\n    cerr << c;\n}\nvoid _cout(const unsigned int\
    \ &c) {\n  if (c == 1001001001)\n    cerr << \"inf\";\n  else\n    cerr << c;\n\
    }\nvoid _cout(const long long &c) {\n  if (c == 1001001001 || c == (1LL << 61)\
    \ - 1)\n    cerr << \"inf\";\n  else if (c == -1001001001 || c == -((1LL << 61)\
    \ - 1))\n    cerr << \"-inf\";\n  else\n    cerr << c;\n}\nvoid _cout(const unsigned\
    \ long long &c) {\n  if (c == 1001001001 || c == (1LL << 61) - 1)\n    cerr <<\
    \ \"inf\";\n  else\n    cerr << c;\n}\ntemplate <typename T, typename U>\nvoid\
    \ _cout(const pair<T, U> &p) {\n  cerr << \"{ \";\n  _cout(p.fi);\n  cerr << \"\
    , \";\n  _cout(p.se);\n  cerr << \" } \";\n}\ntemplate <typename T>\nvoid _cout(const\
    \ vector<T> &v) {\n  int s = v.size();\n  cerr << \"{ \";\n  for (int i = 0; i\
    \ < s; i++) {\n    cerr << (i ? \", \" : \"\");\n    _cout(v[i]);\n  }\n  cerr\
    \ << \" } \";\n}\ntemplate <typename T>\nvoid _cout(const vector<vector<T>> &v)\
    \ {\n  cerr << \"[ \";\n  for (const auto &x : v) {\n    cerr << endl;\n    _cout(x);\n\
    \    cerr << \", \";\n  }\n  cerr << endl << \" ] \";\n}\nvoid dbg_out() { cerr\
    \ << endl; }\ntemplate <typename T, class... U>\nvoid dbg_out(const T &t, const\
    \ U &... u) {\n  _cout(t);\n  if (sizeof...(u)) cerr << \", \";\n  dbg_out(u...);\n\
    }\ntemplate <typename T>\nvoid array_out(const T &v, int s) {\n  cerr << \"{ \"\
    ;\n  for (int i = 0; i < s; i++) {\n    cerr << (i ? \", \" : \"\");\n    _cout(v[i]);\n\
    \  }\n  cerr << \" } \" << endl;\n}\ntemplate <typename T>\nvoid array_out(const\
    \ T &v, int H, int W) {\n  cerr << \"[ \";\n  for (int i = 0; i < H; i++) {\n\
    \    cerr << (i ? \", \" : \"\");\n    array_out(v[i], W);\n  }\n  cerr << \"\
    \ ] \" << endl;\n}\n#else\n#define trc(...)\n#define trca(...)\n#define trcc(...)\n\
    #endif\n\ninline int popcnt(unsigned long long a) { return __builtin_popcountll(a);\
    \ }\ninline int lsb(unsigned long long a) { return __builtin_ctzll(a); }\ninline\
    \ int msb(unsigned long long a) { return 63 - __builtin_clzll(a); }\ntemplate\
    \ <typename T>\ninline int getbit(T a, int i) {\n  return (a >> i) & 1;\n}\ntemplate\
    \ <typename T>\ninline void setbit(T &a, int i) {\n  a |= (1LL << i);\n}\ntemplate\
    \ <typename T>\ninline void delbit(T &a, int i) {\n  a &= ~(1LL << i);\n}\ntemplate\
    \ <typename T>\nint lb(const vector<T> &v, const T &a) {\n  return lower_bound(begin(v),\
    \ end(v), a) - begin(v);\n}\ntemplate <typename T>\nint ub(const vector<T> &v,\
    \ const T &a) {\n  return upper_bound(begin(v), end(v), a) - begin(v);\n}\ntemplate\
    \ <typename T>\nint btw(T a, T x, T b) {\n  return a <= x && x < b;\n}\ntemplate\
    \ <typename T, typename U>\nT ceil(T a, U b) {\n  return (a + b - 1) / b;\n}\n\
    constexpr long long TEN(int n) {\n  long long ret = 1, x = 10;\n  while (n) {\n\
    \    if (n & 1) ret *= x;\n    x *= x;\n    n >>= 1;\n  }\n  return ret;\n}\n\
    template <typename T>\nvector<T> mkrui(const vector<T> &v) {\n  vector<T> ret(v.size()\
    \ + 1);\n  for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];\n\
    \  return ret;\n};\ntemplate <typename T>\nvector<T> mkuni(const vector<T> &v)\
    \ {\n  vector<T> ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(),\
    \ ret.end()), ret.end());\n  return ret;\n}\ntemplate <typename F>\nvector<int>\
    \ mkord(int N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n\
    \  sort(begin(ord), end(ord), f);\n  return ord;\n}\ntemplate <typename T = int>\n\
    vector<T> mkiota(int N) {\n  vector<T> ret(N);\n  iota(begin(ret), end(ret), 0);\n\
    \  return ret;\n}\ntemplate <typename T>\nvector<int> mkinv(vector<T> &v) {\n\
    \  vector<int> inv(v.size());\n  for (int i = 0; i < (int)v.size(); i++) inv[v[i]]\
    \ = i;\n  return inv;\n}\n\nstruct IoSetupNya {\n  IoSetupNya() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(15);\n  \
    \  cerr << fixed << setprecision(7);\n  }\n} iosetupnya;\n\nvoid solve();\nint\
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"misc/fastio.hpp\"\nusing\
    \ namespace std;\n\nnamespace fastio {\nstatic constexpr int SZ = 1 << 17;\nchar\
    \ ibuf[SZ], obuf[SZ];\nint pil = 0, pir = 0, por = 0;\n\nstruct Pre {\n  char\
    \ num[40000];\n  constexpr Pre() : num() {\n    for (int i = 0; i < 10000; i++)\
    \ {\n      int n = i;\n      for (int j = 3; j >= 0; j--) {\n        num[i * 4\
    \ + j] = n % 10 + '0';\n        n /= 10;\n      }\n    }\n  }\n} constexpr pre;\n\
    \ninline void load() {\n  memcpy(ibuf, ibuf + pil, pir - pil);\n  pir = pir -\
    \ pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);\n  pil = 0;\n}\ninline\
    \ void flush() {\n  fwrite(obuf, 1, por, stdout);\n  por = 0;\n}\n\ninline void\
    \ rd(char& c) { c = ibuf[pil++]; }\ntemplate <typename T>\ninline void rd(T& x)\
    \ {\n  if (pil + 32 > pir) load();\n  char c;\n  do\n    c = ibuf[pil++];\n  while\
    \ (c < '-');\n  bool minus = 0;\n  if (c == '-') {\n    minus = 1;\n    c = ibuf[pil++];\n\
    \  }\n  x = 0;\n  while (c >= '0') {\n    x = x * 10 + (c & 15);\n    c = ibuf[pil++];\n\
    \  }\n  if (minus) x = -x;\n}\ninline void rd() {}\ntemplate <typename Head, typename...\
    \ Tail>\ninline void rd(Head& head, Tail&... tail) {\n  rd(head);\n  rd(tail...);\n\
    }\n\ninline void wt(char c) { obuf[por++] = c; }\ntemplate <typename T>\ninline\
    \ void wt(T x) {\n  if (por > SZ - 32) flush();\n  if (!x) {\n    obuf[por++]\
    \ = '0';\n    return;\n  }\n  if (x < 0) {\n    obuf[por++] = '-';\n    x = -x;\n\
    \  }\n  int i = 12;\n  char buf[16];\n  while (x >= 10000) {\n    memcpy(buf +\
    \ i, pre.num + (x % 10000) * 4, 4);\n    x /= 10000;\n    i -= 4;\n  }\n  if (x\
    \ < 100) {\n    if (x < 10) {\n      wt(char('0' + char(x)));\n    } else {\n\
    \      uint32_t q = (uint32_t(x) * 205) >> 11;\n      uint32_t r = uint32_t(x)\
    \ - q * 10;\n      obuf[por + 0] = '0' + q;\n      obuf[por + 1] = '0' + r;\n\
    \      por += 2;\n    }\n  } else {\n    if (x < 1000) {\n      memcpy(obuf +\
    \ por, pre.num + (x << 2) + 1, 3);\n      por += 3;\n    } else {\n      memcpy(obuf\
    \ + por, pre.num + (x << 2), 4);\n      por += 4;\n    }\n  }\n  memcpy(obuf +\
    \ por, buf + i + 4, 12 - i);\n  por += 12 - i;\n}\n\ninline void wt() {}\ntemplate\
    \ <typename Head, typename... Tail>\ninline void wt(Head head, Tail... tail) {\n\
    \  wt(head);\n  wt(tail...);\n}\ntemplate <typename T>\ninline void wtn(T x) {\n\
    \  wt(x, '\\n');\n}\n\nstruct Dummy {\n  Dummy() { atexit(flush); }\n} dummy;\n\
    \n}  // namespace fastio\nusing fastio::rd;\nusing fastio::wt;\nusing fastio::wtn;\n\
    #line 3 \"modint/montgomery-modint.hpp\"\nusing namespace std;\n\ntemplate <uint32_t\
    \ mod>\nstruct LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n\
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
    \ { return mod; }\n};\n#line 3 \"modulo/binomial.hpp\"\nusing namespace std;\n\
    \ntemplate <typename T>\nstruct Binomial {\n  vector<T> fac_, finv_, inv_;\n \
    \ Binomial(int MAX) : fac_(MAX + 10), finv_(MAX + 10), inv_(MAX + 10) {\n    MAX\
    \ += 9;\n    fac_[0] = finv_[0] = inv_[0] = 1;\n    for (int i = 1; i <= MAX;\
    \ i++) fac_[i] = fac_[i - 1] * i;\n    finv_[MAX] = fac_[MAX].inverse();\n   \
    \ for (int i = MAX - 1; i > 0; i--) finv_[i] = finv_[i + 1] * (i + 1);\n    for\
    \ (int i = 1; i <= MAX; i++) inv_[i] = finv_[i] * fac_[i - 1];\n  }\n\n  inline\
    \ T fac(int i) const { return fac_[i]; }\n  inline T finv(int i) const { return\
    \ finv_[i]; }\n  inline T inv(int i) const { return inv_[i]; }\n\n  T C(int n,\
    \ int r) const {\n    if (n < r || r < 0) return T(0);\n    return fac_[n] * finv_[n\
    \ - r] * finv_[r];\n  }\n\n  T C_naive(int n, int r) const {\n    if (n < r ||\
    \ r < 0) return T(0);\n    T ret = 1;\n    for (T i = 1; i <= r; i += T(1)) {\n\
    \      ret *= n--;\n      ret *= i.inverse();\n    }\n    return ret;\n  }\n\n\
    \  T P(int n, int r) const {\n    if (n < r || r < 0) return T(0);\n    return\
    \ fac_[n] * finv_[n - r];\n  }\n\n  T H(int n, int r) const {\n    if (n < 0 ||\
    \ r < 0) return (0);\n    return r == 0 ? 1 : C(n + r - 1, r);\n  }\n};\n#line\
    \ 3 \"fps/lagrange-interpolation-point.hpp\"\nusing namespace std;\n\n#line 6\
    \ \"fps/lagrange-interpolation-point.hpp\"\n\n// given  : y(x=0) , y(x=1) , ...\
    \ , y(k)\n// return : y(x)\ntemplate <typename mint>\nmint lagrange_interpolation(const\
    \ vector<mint>& y, long long x,\n                            const Binomial<mint>&\
    \ C) {\n  int N = (int)y.size() - 1;\n  if (x <= N) return y[x];\n  mint ret =\
    \ 0;\n  vector<mint> dp(N + 1, 1), pd(N + 1, 1);\n  mint a = x, one = 1;\n  for\
    \ (int i = 0; i < N; i++) dp[i + 1] = dp[i] * a, a -= one;\n  for (int i = N;\
    \ i > 0; i--) pd[i - 1] = pd[i] * a, a += one;\n  for (int i = 0; i <= N; i++)\
    \ {\n    mint tmp = y[i] * dp[i] * pd[i] * C.finv(i) * C.finv(N - i);\n    ret\
    \ += ((N - i) & 1) ? -tmp : tmp;\n  }\n  return ret;\n}\n#line 3 \"fps/sum-of-exponential-times-poly.hpp\"\
    \nusing namespace std;\n\n#line 6 \"fps/sum-of-exponential-times-poly.hpp\"\n\n\
    // given  : f(0)...f(k) (deg(f) = k), a, n\n// return : \\sum_{i=0...n-1} a^i\
    \ f(i)\ntemplate <typename mint>\nmint sum_of_exp(const vector<mint>& f, mint\
    \ a, long long n,\n                const Binomial<mint>& C) {\n  if (n == 0) return\
    \ mint(0);\n  if (a == mint(0)) return f[0];\n  if (a == mint(1)) {\n    vector<mint>\
    \ g(f.size() + 1, mint(0));\n    for (int i = 1; i < (int)g.size(); i++) g[i]\
    \ = g[i - 1] + f[i - 1];\n    return lagrange_interpolation(g, n, C);\n  }\n \
    \ int K = f.size() - 1;\n  vector<mint> g(f.size());\n  mint buf = 1;\n  for (int\
    \ i = 0; i < (int)g.size(); i++) g[i] = f[i] * buf, buf *= a;\n  for (int i =\
    \ 1; i < (int)g.size(); i++) g[i] += g[i - 1];\n  mint c = 0, buf2 = 1;\n  for\
    \ (int i = 0; i <= K; i++) c += C.C(K + 1, i) * buf2 * g[K - i], buf2 *= -a;\n\
    \  c /= (-a + 1).pow(K + 1);\n  mint buf3 = 1, ia = a.inverse();\n  for (int i\
    \ = 0; i < (int)g.size(); i++) g[i] = (g[i] - c) * buf3, buf3 *= ia;\n  mint tn\
    \ = lagrange_interpolation(g, n - 1, C);\n  return tn * a.pow(n - 1) + c;\n}\n\
    \n// given  : f(0)...f(k) (deg(f) = k), a\n// return : \\sum_{i=0...infty} a^i\
    \ f(i)\ntemplate <typename mint>\nmint sum_of_exp_limit(const vector<mint>& f,\
    \ mint a, const Binomial<mint>& C) {\n  if (a == mint(0)) return f[0];\n  int\
    \ K = f.size() - 1;\n  vector<mint> g(f.size());\n  mint buf = 1;\n  for (int\
    \ i = 0; i < (int)g.size(); i++) g[i] = f[i] * buf, buf *= a;\n  for (int i =\
    \ 1; i < (int)g.size(); i++) g[i] += g[i - 1];\n  mint c = 0, buf2 = 1;\n  for\
    \ (int i = 0; i <= K; i++) c += C.C(K + 1, i) * buf2 * g[K - i], buf2 *= -a;\n\
    \  c /= (-a + 1).pow(K + 1);\n  return c;\n}\n\n// given  : p, n\n// return :\
    \ (0^p, 1^p, ... , n^p)\ntemplate <typename mint>\nvector<mint> exp_enamurate(int\
    \ p, int n) {\n  vector<mint> f(n + 1, mint(0));\n  if (!p) {\n    f[0] = 1;\n\
    \    return std::move(f);\n  }\n  f[1] = 1;\n  vector<bool> sieve(n + 1, false);\n\
    \  vector<int> ps;\n  for (int i = 2; i <= n; i++) {\n    if (!sieve[i]) {\n \
    \     f[i] = mint(i).pow(p);\n      ps.push_back(i);\n    }\n    for (int j =\
    \ 0; j < (int)ps.size() && i * ps[j] <= n; j++) {\n      sieve[i * ps[j]] = 1;\n\
    \      f[i * ps[j]] = f[i] * f[ps[j]];\n      if (i % ps[j] == 0) break;\n   \
    \ }\n  }\n  return std::move(f);\n}\n\n// given  : d, r, n\n// return : \\sum_{i=0...n-1}\
    \ r^i i^d\ntemplate <typename mint>\nmint sum_of_exp2(int d, mint r, long long\
    \ n, const Binomial<mint>& C) {\n  vector<mint> f = exp_enamurate<mint>(d, d);\n\
    \  return sum_of_exp(f, r, n, C);\n}\n\n// given  : d, r\n// return : \\sum_{i=0...infty}\
    \ r^i i^d\ntemplate <typename mint>\nmint sum_of_exp_limit2(int d, mint r, const\
    \ Binomial<mint>& C) {\n  vector<mint> f = exp_enamurate<mint>(d, d);\n  return\
    \ sum_of_exp_limit(f, r, C);\n}\n\n/**\n * @brief $\\sum_{i}a^i f(i)$\n * @docs\
    \ docs/fps/sum-of-exponential-times-poly.md\n */\n#line 9 \"verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp\"\
    \n\nvoid solve() {\n  using mint = LazyMontgomeryModInt<998244353>;\n  Binomial<mint>\
    \ C(10001000);\n  long long r, d;\n  rd(r, d);\n  wtn(sum_of_exp_limit2<mint>(d,\
    \ r, C).get());\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n\n#include \"../../competitive-template.hpp\"\n#include \"../../misc/fastio.hpp\"\
    \n#include \"../../modint/montgomery-modint.hpp\"\n#include \"../../modulo/binomial.hpp\"\
    \n#include \"../../fps/lagrange-interpolation-point.hpp\"\n#include \"../../fps/sum-of-exponential-times-poly.hpp\"\
    \n\nvoid solve() {\n  using mint = LazyMontgomeryModInt<998244353>;\n  Binomial<mint>\
    \ C(10001000);\n  long long r, d;\n  rd(r, d);\n  wtn(sum_of_exp_limit2<mint>(d,\
    \ r, C).get());\n}"
  dependsOn:
  - competitive-template.hpp
  - misc/fastio.hpp
  - modint/montgomery-modint.hpp
  - modulo/binomial.hpp
  - fps/lagrange-interpolation-point.hpp
  - fps/sum-of-exponential-times-poly.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
  requiredBy: []
  timestamp: '2020-09-15 23:09:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
- /verify/verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp.html
title: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
---
