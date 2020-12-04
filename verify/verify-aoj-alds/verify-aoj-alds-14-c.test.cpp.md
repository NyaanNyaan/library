---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: inner/inner-hash.hpp
    title: inner/inner-hash.hpp
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash-2d.hpp
    title: "\u4E8C\u6B21\u5143Rolling Hash"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C
  bundledCode: "#line 1 \"verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp\"\n\
    #define PROBLEM \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C\"\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"string/rolling-hash-2d.hpp\"\
    \nusing namespace std;\n\n#line 3 \"inner/inner-hash.hpp\"\nusing namespace std;\n\
    \nnamespace inner {\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    \ntemplate <int BASE_NUM>\nstruct Hash : array<u64, BASE_NUM> {\n  using array<u64,\
    \ BASE_NUM>::operator[];\n  static constexpr int n = BASE_NUM;\n\n  Hash() : array<u64,\
    \ BASE_NUM>() {}\n\n  static constexpr u64 md = (1ull << 61) - 1;\n\n  static\
    \ u64 cast(const int64_t &a) { return a < 0 ? a + md : a; }\n\n  static inline\
    \ constexpr u64 modmul(const u64 &a, const u64 &b) {\n    u128 ret = u128(a) *\
    \ b;\n    ret = (ret & md) + (ret >> 61);\n    return ret >= md ? ret - md : ret;\n\
    \  }\n  static inline constexpr u64 modfma(const u64 &a, const u64 &b, const u64\
    \ &c) {\n    u128 ret = u128(a) * b + c;\n    ret = (ret & md) + (ret >> 61);\n\
    \    return ret >= md ? ret - md : ret;\n  }\n  constexpr static Hash set(u64\
    \ a) {\n    Hash res;\n    for (int i = 0; i < n; i++) res[i] = a;\n    return\
    \ res;\n  }\n  Hash &operator+=(const Hash &r) {\n    for (int i = 0; i < n; i++)\n\
    \      if (((*this)[i] += r[i]) >= md) (*this)[i] -= md;\n    return *this;\n\
    \  }\n  Hash &operator+=(const u64 &r) {\n    for (int i = 0; i < n; i++)\n  \
    \    if (((*this)[i] += r) >= md) (*this)[i] -= md;\n    return *this;\n  }\n\
    \  Hash &operator-=(const Hash &r) {\n    for (int i = 0; i < n; i++)\n      if\
    \ (((*this)[i] += md - r[i]) >= md) (*this)[i] -= md;\n    return *this;\n  }\n\
    \  Hash &operator-=(const u64 &r) {\n    for (int i = 0; i < n; i++)\n      if\
    \ (((*this)[i] += md - r) >= md) (*this)[i] -= md;\n    return *this;\n  }\n \
    \ inline Hash &operator*=(const Hash &r) {\n    for (int i = 0; i < n; i++) (*this)[i]\
    \ = modmul((*this)[i], r[i]);\n    return *this;\n  }\n  Hash operator+(const\
    \ Hash &r) { return Hash(*this) += r; }\n  Hash operator+(const u64 &r) { return\
    \ Hash(*this) += r; }\n  Hash operator-(const Hash &r) { return Hash(*this) -=\
    \ r; }\n  Hash operator-(const u64 &r) { return Hash(*this) -= r; }\n  inline\
    \ Hash operator*(const Hash &r) { return Hash(*this) *= r; }\n  Hash operator-()\
    \ const {\n    Hash res;\n    for (int i = 0; i < n; i++) res[i] = (*this)[i]\
    \ == 0 ? 0 : md - (*this)[i];\n    return res;\n  }\n  friend Hash pfma(const\
    \ Hash &a, const Hash &b, const Hash &c) {\n    Hash res;\n    for (int i = 0;\
    \ i < n; i++) res[i] = modfma(a[i], b[i], c[i]);\n    return res;\n  }\n  friend\
    \ Hash pfma(const Hash &a, const Hash &b, const u64 &c) {\n    Hash res;\n   \
    \ for (int i = 0; i < n; i++) res[i] = modfma(a[i], b[i], c);\n    return res;\n\
    \  }\n\n  static Hash get_basis() {\n    constexpr u64 ds[] = {2, 3, 5, 7, 11,\
    \ 13, 31, 41, 61, 151, 331, 1321};\n    static auto rand_time =\n        chrono::duration_cast<chrono::nanoseconds>(\n\
    \            chrono::high_resolution_clock::now().time_since_epoch())\n      \
    \      .count();\n    static mt19937_64 rng(rand_time);\n\n    auto modpow = [&](u64\
    \ a, u64 b) {\n      u64 r = 1;\n      for (a %= md; b; a = modmul(a, a), b >>=\
    \ 1) r = modmul(r, a);\n      return r;\n    };\n    auto isPrimitive = [&](u64\
    \ x) {\n      for (auto &d : ds)\n        if (modpow(x, (md - 1) / d) <= 1) return\
    \ false;\n      return true;\n    };\n\n    Hash h;\n    for (int i = 0; i < n;\
    \ i++) {\n      while (isPrimitive(h[i] = rng() % (md - 1) + 1) == false)\n  \
    \      ;\n    }\n    return h;\n  }\n};\n\n}  // namespace inner\n#line 6 \"string/rolling-hash-2d.hpp\"\
    \n\ntemplate <typename Str, int BASE_NUM = 1>\nstruct RollingHash2D {\n  using\
    \ Hash = inner::Hash<BASE_NUM>;\n  using u64 = unsigned long long;\n  vector<Str>\
    \ data;\n  vector<vector<Hash>> hs;\n  vector<Hash> pw[2];\n  int h, w;\n  static\
    \ Hash basis[2];\n\n  RollingHash2D(const vector<Str> &S = vector<Str>()) { build(S);\
    \ }\n\n  void build(const vector<Str> &S) {\n    data = S;\n    h = S.size();\n\
    \    w = S[0].size();\n    pw[0].resize(h + 1);\n    pw[1].resize(w + 1);\n  \
    \  pw[0][0] = pw[1][0] = Hash::set(1);\n    for (int i = 1; i <= h; i++) pw[0][i]\
    \ = pw[0][i - 1] * basis[0];\n    for (int i = 1; i <= w; i++) pw[1][i] = pw[1][i\
    \ - 1] * basis[1];\n    hs.resize(h + 1, vector<Hash>(w + 1));\n    hs[0][0] =\
    \ Hash::set(0);\n    for (int i = 1; i <= h; i++) {\n      hs[i][0] = Hash::set(0);\n\
    \      for (int j = 1; j <= w; j++)\n        hs[i][j] = pfma(hs[i][j - 1], basis[1],\
    \ Hash::cast(S[i - 1][j - 1]));\n    }\n    for (int j = 1; j <= w; j++) {\n \
    \     hs[0][j] = Hash::set(0);\n      for (int i = 1; i <= h; i++)\n        hs[i][j]\
    \ = pfma(hs[i - 1][j], basis[0], hs[i][j]);\n    }\n  }\n\n  Hash get(int u, int\
    \ l, int d, int r) {\n    return hs[d][r] - hs[u][r] * pw[0][d - u] - hs[d][l]\
    \ * pw[1][r - l] +\n           hs[u][l] * pw[0][d - u] * pw[1][r - l];\n  }\n\n\
    \  static Hash get_hash(const vector<Str> &T) {\n    Hash ret = Hash::set(0);\n\
    \    for (int i = 0; i < (int)T.size(); i++) {\n      Hash h = Hash::set(0);\n\
    \      for(int j = 0; j < (int)T[0].size(); j++) \n        h = pfma(h, basis[1],\
    \ Hash::cast(T[i][j]));\n      ret = pfma(ret, basis[0], h);\n    }\n    return\
    \ ret;\n  }\n\n};\n\ntemplate <typename Str, int BASE_NUM>\ntypename RollingHash2D<Str,\
    \ BASE_NUM>::Hash RollingHash2D<Str, BASE_NUM>::basis[2] =\n    {inner::Hash<BASE_NUM>::get_basis(),\
    \ inner::Hash<BASE_NUM>::get_basis()};\nusing roriha2d = RollingHash2D<string,\
    \ 1>;\n\n/**\n * @brief \u4E8C\u6B21\u5143Rolling Hash\n * @docs docs/string/rolling-hash-2d.md\n\
    \ */\n#line 6 \"verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp\"\n\nvoid\
    \ solve() {\n  ini(H, W);\n  vs S(H);\n  in(S);\n  roriha2d rori(S);\n\n  ini(h,\
    \ w);\n  vs T(h);\n  in(T);\n\n  auto th = roriha2d::get_hash(T);\n  rep(i, H\
    \ - h + 1) rep(j, W - w + 1) {\n    auto sh = rori.get(i, j, i + h, j + w);\n\
    \    if (sh == th) out(i, j);\n  }\n}\n"
  code: "#define PROBLEM \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C\"\
    \n\n#include \"../../competitive-template.hpp\"\n#include \"../../string/rolling-hash-2d.hpp\"\
    \n\nvoid solve() {\n  ini(H, W);\n  vs S(H);\n  in(S);\n  roriha2d rori(S);\n\n\
    \  ini(h, w);\n  vs T(h);\n  in(T);\n\n  auto th = roriha2d::get_hash(T);\n  rep(i,\
    \ H - h + 1) rep(j, W - w + 1) {\n    auto sh = rori.get(i, j, i + h, j + w);\n\
    \    if (sh == th) out(i, j);\n  }\n}\n"
  dependsOn:
  - competitive-template.hpp
  - string/rolling-hash-2d.hpp
  - inner/inner-hash.hpp
  isVerificationFile: true
  path: verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp
  requiredBy: []
  timestamp: '2020-12-04 23:12:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp
- /verify/verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp.html
title: verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp
---
