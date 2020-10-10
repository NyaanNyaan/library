---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/square-root-decomposition.hpp
    title: "\u5E73\u65B9\u5206\u5272"
  - icon: ':question:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"data-structure/square-root-decomposition.hpp\"\
    \nusing namespace std;\n\ntemplate <typename MERGE, typename block, int B>\nstruct\
    \ SquareRootDecomposition {\n  int N;\n  vector<block> sq;\n  MERGE merge;\n \
    \ typename block::T UNIT;\n  SquareRootDecomposition(int N_, MERGE merge_, typename\
    \ block::T UNIT_)\n      : N(N_), sq(N / B + 1), merge(merge_), UNIT(UNIT_) {\n\
    \    for(int i = 0; i < (int)sq.size(); i++) sq[i].init(i);\n  }\n\n  void update(int\
    \ l, int r, typename block::S x) {\n    if (l / B == r / B) {\n      sq[l / B].update_part(l\
    \ % B, r % B, x);\n    } else {\n      sq[l / B].update_part(l % B, B, x);\n \
    \     for (int i = l / B + 1; i < r / B; i++) sq[i].update_all(x);\n      sq[r\
    \ / B].update_part(0, r % B, x);\n    }\n  }\n\n  typename block::T query(int\
    \ l, int r) {\n    if (l / B == r / B) return sq[l / B].query_part(l % B, r %\
    \ B);\n    typename block::T ret = UNIT;\n    ret = merge(ret, sq[l / B].query_part(l\
    \ % B, B));\n    for (int i = l / B + 1; i < r / B; i++) ret = merge(ret, sq[i].query_all());\n\
    \    ret = merge(ret, sq[r / B].query_part(0, r % B));\n    return ret;\n  }\n\
    };\n\n/**\n * @brief \u5E73\u65B9\u5206\u5272\n * @docs docs/data-structure/sqrt-dec.md\n\
    \ */\n#line 3 \"modint/montgomery-modint.hpp\"\nusing namespace std;\n\ntemplate\
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
    \ { return mod; }\n};\n#line 6 \"verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp\"\
    \n\nconstexpr int B = 300;\nusing mint = LazyMontgomeryModInt<998244353>;\nstruct\
    \ affine {\n  mint a, b;\n  affine() = default;\n  affine(mint a_, mint b_) :\
    \ a(a_), b(b_) {}\n};\naffine operator*(const  affine &l,const affine &r) {\n\
    \  return affine{r.a * l.a, r.a * l.b + r.b};\n};\n\nint N, Q;\nV<affine> a;\n\
    affine id = {1, 0};\n\nvoid solve() {\n  in(N, Q);\n  a.resize(N);\n  rep(i, N)\
    \ in(a[i].a, a[i].b);\n\n  struct block {\n    // S \u4F5C\u7528\u7D20\u306E\u578B\
    \ T \u8981\u7D20\u306E\u578B\n    using S = affine;\n    using T = affine;\n\n\
    \    int i;\n\n    block() {}\n\n    // i ... \u4F55\u500B\u76EE\u306E\u30D6\u30ED\
    \u30C3\u30AF\u304B\n    // i * B + j ... (j\u3092\u30D6\u30ED\u30C3\u30AF\u5185\
    \u306Eidx\u3068\u3057\u3066)\u5168\u4F53\u3067\u306Eidx\n    int idx(int j) const\
    \ { return i * B + j; }\n\n    affine fold;\n\n    // \u5909\u6570\u3068\u30D6\
    \u30ED\u30C3\u30AF\u306E\u521D\u671F\u5316\u3092\u5FD8\u308C\u306A\u3044\uFF01\
    \n    void init(int _) {\n      i = _;\n      build();\n    }\n\n    void build()\
    \ {\n      fold = {1, 0};\n      rep(j, B) if (idx(j) < N) fold = fold * a[idx(j)];\n\
    \    }\n\n    void update_all(S) { exit(1); }\n\n    void update_part(int l, int\
    \ r, S x) {\n      for (int j = l; j < r; j++) a[idx(j)] = x;\n      build();\n\
    \    }\n\n    T query_all() { return fold; }\n\n    T query_part(int l, int r)\
    \ {\n      affine ret = id;\n      for (int i = l; i < r; i++) ret = ret * a[idx(i)];\n\
    \      return ret;\n    }\n  };\n\n  auto merge = [](const affine &a,const affine\
    \ &b) { return a * b; };\n  SquareRootDecomposition<decltype(merge), block, B>\
    \ sqd(N, merge, id);\n\n  rep(_, Q) {\n    ini(cmd);\n    if (cmd == 0) {\n  \
    \    ini(p, c, d);\n      sqd.update(p, p + 1, {c, d});\n    } else {\n      ini(l,\
    \ r, x);\n      affine sm = sqd.query(l, r);\n      out(sm.a * x + sm.b);\n  \
    \  }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../../competitive-template.hpp\"\n#include \"../../data-structure/square-root-decomposition.hpp\"\
    \n#include \"../../modint/montgomery-modint.hpp\"\n\nconstexpr int B = 300;\n\
    using mint = LazyMontgomeryModInt<998244353>;\nstruct affine {\n  mint a, b;\n\
    \  affine() = default;\n  affine(mint a_, mint b_) : a(a_), b(b_) {}\n};\naffine\
    \ operator*(const  affine &l,const affine &r) {\n  return affine{r.a * l.a, r.a\
    \ * l.b + r.b};\n};\n\nint N, Q;\nV<affine> a;\naffine id = {1, 0};\n\nvoid solve()\
    \ {\n  in(N, Q);\n  a.resize(N);\n  rep(i, N) in(a[i].a, a[i].b);\n\n  struct\
    \ block {\n    // S \u4F5C\u7528\u7D20\u306E\u578B T \u8981\u7D20\u306E\u578B\n\
    \    using S = affine;\n    using T = affine;\n\n    int i;\n\n    block() {}\n\
    \n    // i ... \u4F55\u500B\u76EE\u306E\u30D6\u30ED\u30C3\u30AF\u304B\n    //\
    \ i * B + j ... (j\u3092\u30D6\u30ED\u30C3\u30AF\u5185\u306Eidx\u3068\u3057\u3066\
    )\u5168\u4F53\u3067\u306Eidx\n    int idx(int j) const { return i * B + j; }\n\
    \n    affine fold;\n\n    // \u5909\u6570\u3068\u30D6\u30ED\u30C3\u30AF\u306E\u521D\
    \u671F\u5316\u3092\u5FD8\u308C\u306A\u3044\uFF01\n    void init(int _) {\n   \
    \   i = _;\n      build();\n    }\n\n    void build() {\n      fold = {1, 0};\n\
    \      rep(j, B) if (idx(j) < N) fold = fold * a[idx(j)];\n    }\n\n    void update_all(S)\
    \ { exit(1); }\n\n    void update_part(int l, int r, S x) {\n      for (int j\
    \ = l; j < r; j++) a[idx(j)] = x;\n      build();\n    }\n\n    T query_all()\
    \ { return fold; }\n\n    T query_part(int l, int r) {\n      affine ret = id;\n\
    \      for (int i = l; i < r; i++) ret = ret * a[idx(i)];\n      return ret;\n\
    \    }\n  };\n\n  auto merge = [](const affine &a,const affine &b) { return a\
    \ * b; };\n  SquareRootDecomposition<decltype(merge), block, B> sqd(N, merge,\
    \ id);\n\n  rep(_, Q) {\n    ini(cmd);\n    if (cmd == 0) {\n      ini(p, c, d);\n\
    \      sqd.update(p, p + 1, {c, d});\n    } else {\n      ini(l, r, x);\n    \
    \  affine sm = sqd.query(l, r);\n      out(sm.a * x + sm.b);\n    }\n  }\n}"
  dependsOn:
  - competitive-template.hpp
  - data-structure/square-root-decomposition.hpp
  - modint/montgomery-modint.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp
  requiredBy: []
  timestamp: '2020-09-03 23:56:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp
---
