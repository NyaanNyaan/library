---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: fps/berlekamp-massey.hpp
    title: fps/berlekamp-massey.hpp
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: fps/kitamasa.hpp
    title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u306E\u9AD8\u901F\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/find_linear_recurrence
    links:
    - https://judge.yosupo.jp/problem/find_linear_recurrence
  bundledCode: "#line 1 \"verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\n\
    \n#line 1 \"competitive-template.hpp\"\n#pragma region kyopro_template\n#define\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"modint/montgomery-modint.hpp\"\
    \nusing namespace std;\n\ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt\
    \ {\n  using mint = LazyMontgomeryModInt;\n  using i32 = int32_t;\n  using u32\
    \ = uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr u32 get_r() {\n \
    \   u32 ret = mod;\n    for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n  \
    \  return ret;\n  }\n\n  static constexpr u32 r = get_r();\n  static constexpr\
    \ u32 n2 = -u64(mod) % mod;\n  static_assert(r * mod == 1, \"invalid, r * mod\
    \ != 1\");\n  static_assert(mod < (1 << 30), \"invalid, mod >= 2 ^ 30\");\n  static_assert((mod\
    \ & 1) == 1, \"invalid, mod % 2 == 0\");\n\n  u32 a;\n\n  constexpr LazyMontgomeryModInt()\
    \ : a(0) {}\n  constexpr LazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b\
    \ % mod + mod) * n2)){};\n\n  static constexpr u32 reduce(const u64 &b) {\n  \
    \  return (b + u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  constexpr mint &operator+=(const\
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
    \ { return mod; }\n};\n#line 3 \"fps/berlekamp-massey.hpp\"\nusing namespace std;\n\
    \ntemplate <typename mint>\nvector<mint> BerlekampMassey(const vector<mint> &s)\
    \ {\n  const int N = (int)s.size();\n  vector<mint> b, c;\n  b.reserve(N + 1);\n\
    \  c.reserve(N + 1);\n  b.push_back(mint(1));\n  c.push_back(mint(1));\n  mint\
    \ y = mint(1);\n  for (int ed = 1; ed <= N; ed++) {\n    int l = int(c.size()),\
    \ m = int(b.size());\n    mint x = 0;\n    for (int i = 0; i < l; i++) x += c[i]\
    \ * s[ed - l + i];\n    b.emplace_back(mint(0));\n    m++;\n    if (x == mint(0))\
    \ continue;\n    mint freq = x / y;\n    if (l < m) {\n      auto tmp = c;\n \
    \     c.insert(begin(c), m - l, mint(0));\n      for (int i = 0; i < m; i++) c[m\
    \ - 1 - i] -= freq * b[m - 1 - i];\n      b = tmp;\n      y = x;\n    } else {\n\
    \      for (int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];\n    }\n\
    \  }\n  reverse(begin(c), end(c));\n  return c;\n}\n\n#line 3 \"fps/kitamasa.hpp\"\
    \nusing namespace std;\n\n#line 3 \"fps/formal-power-series.hpp\"\nusing namespace\
    \ std;\n\ntemplate <typename mint>\nstruct FormalPowerSeries : vector<mint> {\n\
    \  using vector<mint>::vector;\n  using FPS = FormalPowerSeries;\n\n  FPS &operator+=(const\
    \ FPS &r) {\n    if (r.size() > this->size()) this->resize(r.size());\n    for\
    \ (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
    \  }\n\n  FPS &operator+=(const mint &r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] += r;\n    return *this;\n  }\n\n  FPS &operator-=(const FPS &r)\
    \ {\n    if (r.size() > this->size()) this->resize(r.size());\n    for (int i\
    \ = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n    return *this;\n  }\n\n\
    \  FPS &operator-=(const mint &r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] -= r;\n    return *this;\n  }\n\n  FPS &operator*=(const mint\
    \ &v) {\n    for (int k = 0; k < (int)this->size(); k++) (*this)[k] *= v;\n  \
    \  return *this;\n  }\n\n  FPS &operator/=(const FPS &r) {\n    if (this->size()\
    \ < r.size()) {\n      this->clear();\n      return *this;\n    }\n    int n =\
    \ this->size() - r.size() + 1;\n    if ((int)r.size() <= 64) {\n      FPS f(*this),\
    \ g(r);\n      g.shrink();\n      mint coeff = g.back().inverse();\n      for\
    \ (auto &x : g) x *= coeff;\n      int deg = (int)f.size() - (int)g.size() + 1;\n\
    \      int gs = g.size();\n      FPS quo(deg);\n      for (int i = deg - 1; i\
    \ >= 0; i--) {\n        quo[i] = f[i + gs - 1];\n        for (int j = 0; j < gs;\
    \ j++) f[i + j] -= quo[i] * g[j];\n      }\n      *this = quo * coeff;\n     \
    \ this->resize(n, mint(0));\n      return *this;\n    }\n    return *this = ((*this).rev().pre(n)\
    \ * r.rev().inv(n)).pre(n).rev();\n  }\n\n  FPS &operator%=(const FPS &r) {\n\
    \    *this -= *this / r * r;\n    shrink();\n    return *this;\n  }\n\n  FPS operator+(const\
    \ FPS &r) const { return FPS(*this) += r; }\n  FPS operator+(const mint &v) const\
    \ { return FPS(*this) += v; }\n  FPS operator-(const FPS &r) const { return FPS(*this)\
    \ -= r; }\n  FPS operator-(const mint &v) const { return FPS(*this) -= v; }\n\
    \  FPS operator*(const FPS &r) const { return FPS(*this) *= r; }\n  FPS operator*(const\
    \ mint &v) const { return FPS(*this) *= v; }\n  FPS operator/(const FPS &r) const\
    \ { return FPS(*this) /= r; }\n  FPS operator%(const FPS &r) const { return FPS(*this)\
    \ %= r; }\n  FPS operator-() const {\n    FPS ret(this->size());\n    for (int\
    \ i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];\n    return ret;\n\
    \  }\n\n  void shrink() {\n    while (this->size() && this->back() == mint(0))\
    \ this->pop_back();\n  }\n\n  FPS rev() const {\n    FPS ret(*this);\n    reverse(begin(ret),\
    \ end(ret));\n    return ret;\n  }\n\n  FPS dot(FPS r) const {\n    FPS ret(min(this->size(),\
    \ r.size()));\n    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i]\
    \ * r[i];\n    return ret;\n  }\n\n  FPS pre(int sz) const {\n    return FPS(begin(*this),\
    \ begin(*this) + min((int)this->size(), sz));\n  }\n\n  FPS operator>>(int sz)\
    \ const {\n    if ((int)this->size() <= sz) return {};\n    FPS ret(*this);\n\
    \    ret.erase(ret.begin(), ret.begin() + sz);\n    return ret;\n  }\n\n  FPS\
    \ operator<<(int sz) const {\n    FPS ret(*this);\n    ret.insert(ret.begin(),\
    \ sz, mint(0));\n    return ret;\n  }\n\n  FPS diff() const {\n    const int n\
    \ = (int)this->size();\n    FPS ret(max(0, n - 1));\n    mint one(1), coeff(1);\n\
    \    for (int i = 1; i < n; i++) {\n      ret[i - 1] = (*this)[i] * coeff;\n \
    \     coeff += one;\n    }\n    return ret;\n  }\n\n  FPS integral() const {\n\
    \    const int n = (int)this->size();\n    FPS ret(n + 1);\n    ret[0] = mint(0);\n\
    \    if (n > 0) ret[1] = mint(1);\n    auto mod = mint::get_mod();\n    for (int\
    \ i = 2; i <= n; i++) ret[i] = (-ret[mod % i]) * (mod / i);\n    for (int i =\
    \ 0; i < n; i++) ret[i + 1] *= (*this)[i];\n    return ret;\n  }\n\n  mint eval(mint\
    \ x) const {\n    mint r = 0, w = 1;\n    for (auto &v : *this) r += w * v, w\
    \ *= x;\n    return r;\n  }\n\n  FPS log(int deg = -1) const {\n    assert((*this)[0]\
    \ == mint(1));\n    if (deg == -1) deg = (int)this->size();\n    return (this->diff()\
    \ * this->inv(deg)).pre(deg - 1).integral();\n  }\n\n  FPS pow(int64_t k, int\
    \ deg = -1) const {\n    const int n = (int)this->size();\n    if (deg == -1)\
    \ deg = n;\n    for (int i = 0; i < n; i++) {\n      if ((*this)[i] != mint(0))\
    \ {\n        if (i * k > deg) return FPS(deg, mint(0));\n        mint rev = mint(1)\
    \ / (*this)[i];\n        FPS ret = (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));\n\
    \        ret = (ret << (i * k)).pre(deg);\n        if ((int)ret.size() < deg)\
    \ ret.resize(deg, mint(0));\n        return ret;\n      }\n    }\n    return FPS(deg,\
    \ mint(0));\n  }\n\n  static void *ntt_ptr;\n  static void set_fft();\n  FPS &operator*=(const\
    \ FPS &r);\n  void ntt();\n  void intt();\n  void ntt_doubling();\n  static int\
    \ ntt_pr();\n  FPS inv(int deg = -1) const;\n  FPS exp(int deg = -1) const;\n\
    };\ntemplate <typename mint>\nvoid *FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\
    \n/**\n * @brief \u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\
    \u30A4\u30D6\u30E9\u30EA\n * @docs docs/fps/formal-power-series.md\n */\n#line\
    \ 6 \"fps/kitamasa.hpp\"\n\ntemplate <typename mint>\nmint LinearRecursionFormula(long\
    \ long k, FormalPowerSeries<mint> Q,\n                            FormalPowerSeries<mint>\
    \ P) {\n  Q.shrink();\n  mint ret = 0;\n  if (P.size() >= Q.size()) {\n    auto\
    \ R = P / Q;\n    P -= R * Q;\n    P.shrink();\n    if (k < (int)R.size()) ret\
    \ += R[k];\n  }\n  if ((int)P.size() == 0) return ret;\n\n  FormalPowerSeries<mint>::set_fft();\n\
    \  if (FormalPowerSeries<mint>::ntt_ptr == nullptr) {\n    P.resize((int)Q.size()\
    \ - 1);\n    while (k) {\n      auto Q2 = Q;\n      for (int i = 1; i < (int)Q2.size();\
    \ i += 2) Q2[i] = -Q2[i];\n      auto S = P * Q2;\n      auto T = Q * Q2;\n  \
    \    if (k & 1) {\n        for (int i = 1; i < (int)S.size(); i += 2) P[i >> 1]\
    \ = S[i];\n        for (int i = 0; i < (int)T.size(); i += 2) Q[i >> 1] = T[i];\n\
    \      } else {\n        for (int i = 0; i < (int)S.size(); i += 2) P[i >> 1]\
    \ = S[i];\n        for (int i = 0; i < (int)T.size(); i += 2) Q[i >> 1] = T[i];\n\
    \      }\n      k >>= 1;\n    }\n    return ret + P[0];\n  } else {\n    int N\
    \ = 1;\n    while (N < (int)Q.size()) N <<= 1;\n\n    P.resize(2 * N);\n    Q.resize(2\
    \ * N);\n    P.ntt();\n    Q.ntt();\n    vector<mint> S(2 * N), T(2 * N);\n\n\
    \    vector<int> btr(N);\n    for (int i = 0, logn = __builtin_ctz(N); i < (1\
    \ << logn); i++) {\n      btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (logn - 1));\n\
    \    }\n    mint dw = mint(FormalPowerSeries<mint>::ntt_pr())\n              \
    \    .inverse()\n                  .pow((mint::get_mod() - 1) / (2 * N));\n\n\
    \    while (k) {\n      mint inv2 = mint(2).inverse();\n\n      // even degree\
    \ of Q(x)Q(-x)\n      T.resize(N);\n      for (int i = 0; i < N; i++) T[i] = Q[(i\
    \ << 1) | 0] * Q[(i << 1) | 1];\n\n      S.resize(N);\n      if (k & 1) {\n  \
    \      // odd degree of P(x)Q(-x)\n        for (auto &i : btr) {\n          S[i]\
    \ = (P[(i << 1) | 0] * Q[(i << 1) | 1] -\n                  P[(i << 1) | 1] *\
    \ Q[(i << 1) | 0]) *\n                 inv2;\n          inv2 *= dw;\n        }\n\
    \      } else {\n        // even degree of P(x)Q(-x)\n        for (int i = 0;\
    \ i < N; i++) {\n          S[i] = (P[(i << 1) | 0] * Q[(i << 1) | 1] +\n     \
    \             P[(i << 1) | 1] * Q[(i << 1) | 0]) *\n                 inv2;\n \
    \       }\n      }\n      swap(P, S);\n      swap(Q, T);\n      k >>= 1;\n   \
    \   if (k < N) break;\n      P.ntt_doubling();\n      Q.ntt_doubling();\n    }\n\
    \    P.intt();\n    Q.intt();\n    return ret + (P * (Q.inv()))[k];\n  }\n}\n\n\
    template <typename mint>\nmint kitamasa(long long N, FormalPowerSeries<mint> Q,\n\
    \              FormalPowerSeries<mint> a) {\n  int k = Q.size() - 1;\n  assert((int)a.size()\
    \ == k);\n  auto P = a * Q;\n  P.resize(Q.size() - 1);\n  return LinearRecursionFormula<mint>(N,\
    \ Q, P);\n}\n\n/**\n * @brief \u7DDA\u5F62\u6F38\u5316\u5F0F\u306E\u9AD8\u901F\
    \u8A08\u7B97\n * @docs docs/fps/kitamasa.md\n */\n#line 37 \"fps/berlekamp-massey.hpp\"\
    \ntemplate <typename mint>\nmint nth_term(int n, const vector<mint> &s) {\n  vector<mint>\
    \ Q = BerlekampMassey<mint>(s);\n  \n  return kitamasa(n, BerlekampMassey<mint>(s),\
    \ s);\n}\n#line 3 \"misc/fastio.hpp\"\nusing namespace std;\n\nnamespace fastio\
    \ {\nstatic constexpr int SZ = 1 << 17;\nchar ibuf[SZ], obuf[SZ];\nint pil = 0,\
    \ pir = 0, por = 0;\n\nstruct Pre {\n  char num[40000];\n  constexpr Pre() : num()\
    \ {\n    for (int i = 0; i < 10000; i++) {\n      int n = i;\n      for (int j\
    \ = 3; j >= 0; j--) {\n        num[i * 4 + j] = n % 10 + '0';\n        n /= 10;\n\
    \      }\n    }\n  }\n} constexpr pre;\n\ninline void load() {\n  memcpy(ibuf,\
    \ ibuf + pil, pir - pil);\n  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ -\
    \ pir + pil, stdin);\n  pil = 0;\n}\ninline void flush() {\n  fwrite(obuf, 1,\
    \ por, stdout);\n  por = 0;\n}\n\ninline void rd(char& c) { c = ibuf[pil++]; }\n\
    template <typename T>\ninline void rd(T& x) {\n  if (pil + 32 > pir) load();\n\
    \  char c;\n  do\n    c = ibuf[pil++];\n  while (c < '-');\n  bool minus = 0;\n\
    \  if (c == '-') {\n    minus = 1;\n    c = ibuf[pil++];\n  }\n  x = 0;\n  while\
    \ (c >= '0') {\n    x = x * 10 + (c & 15);\n    c = ibuf[pil++];\n  }\n  if (minus)\
    \ x = -x;\n}\ninline void rd() {}\ntemplate <typename Head, typename... Tail>\n\
    inline void rd(Head& head, Tail&... tail) {\n  rd(head);\n  rd(tail...);\n}\n\n\
    inline void wt(char c) { obuf[por++] = c; }\ntemplate <typename T>\ninline void\
    \ wt(T x) {\n  if (por > SZ - 32) flush();\n  if (!x) {\n    obuf[por++] = '0';\n\
    \    return;\n  }\n  if (x < 0) {\n    obuf[por++] = '-';\n    x = -x;\n  }\n\
    \  int i = 12;\n  char buf[16];\n  while (x >= 10000) {\n    memcpy(buf + i, pre.num\
    \ + (x % 10000) * 4, 4);\n    x /= 10000;\n    i -= 4;\n  }\n  if (x < 100) {\n\
    \    if (x < 10) {\n      wt(char('0' + char(x)));\n    } else {\n      uint32_t\
    \ q = (uint32_t(x) * 205) >> 11;\n      uint32_t r = uint32_t(x) - q * 10;\n \
    \     obuf[por + 0] = '0' + q;\n      obuf[por + 1] = '0' + r;\n      por += 2;\n\
    \    }\n  } else {\n    if (x < 1000) {\n      memcpy(obuf + por, pre.num + (x\
    \ << 2) + 1, 3);\n      por += 3;\n    } else {\n      memcpy(obuf + por, pre.num\
    \ + (x << 2), 4);\n      por += 4;\n    }\n  }\n  memcpy(obuf + por, buf + i +\
    \ 4, 12 - i);\n  por += 12 - i;\n}\n\ninline void wt() {}\ntemplate <typename\
    \ Head, typename... Tail>\ninline void wt(Head head, Tail... tail) {\n  wt(head);\n\
    \  wt(tail...);\n}\ntemplate <typename T>\ninline void wtn(T x) {\n  wt(x, '\\\
    n');\n}\n\nstruct Dummy {\n  Dummy() { atexit(flush); }\n} dummy;\n\n}  // namespace\
    \ fastio\nusing fastio::rd;\nusing fastio::wt;\nusing fastio::wtn;\n#line 7 \"\
    verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp\"\n\nvoid solve() {\n\
    \  using mint = LazyMontgomeryModInt<998244353>;\n  int N;\n  rd(N);\n  V<mint>\
    \ a(N);\n  for (int i = 0; i < N; i++) {\n    int n;\n    rd(n);\n    a[i] = n;\n\
    \  }\n  auto b = BerlekampMassey<mint>(a);\n  wtn(b.size() - 1);\n  for (int i\
    \ = 1; i < (int)b.size(); i++) {\n    if (i != 1) wt(' ');\n    wt((-b[i]).get());\n\
    \  }\n  wt('\\n');\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \n\n#include \"../../competitive-template.hpp\"\n#include \"../../modint/montgomery-modint.hpp\"\
    \n#include \"../../fps/berlekamp-massey.hpp\"\n#include \"misc/fastio.hpp\"\n\n\
    void solve() {\n  using mint = LazyMontgomeryModInt<998244353>;\n  int N;\n  rd(N);\n\
    \  V<mint> a(N);\n  for (int i = 0; i < N; i++) {\n    int n;\n    rd(n);\n  \
    \  a[i] = n;\n  }\n  auto b = BerlekampMassey<mint>(a);\n  wtn(b.size() - 1);\n\
    \  for (int i = 1; i < (int)b.size(); i++) {\n    if (i != 1) wt(' ');\n    wt((-b[i]).get());\n\
    \  }\n  wt('\\n');\n}\n"
  dependsOn:
  - competitive-template.hpp
  - modint/montgomery-modint.hpp
  - fps/berlekamp-massey.hpp
  - fps/kitamasa.hpp
  - fps/formal-power-series.hpp
  - misc/fastio.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp
  requiredBy: []
  timestamp: '2020-11-22 18:43:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp
- /verify/verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp.html
title: verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp
---
