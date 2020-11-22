---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure-2d/abstract-range-tree.hpp
    title: "\u62BD\u8C61\u5316\u9818\u57DF\u6728"
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-indexed-tree.hpp
    title: Binary Indexed Tree(Fenwick Tree)
  - icon: ':heavy_check_mark:'
    path: misc/compress.hpp
    title: misc/compress.hpp
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-abstruct-range-tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"data-structure-2d/abstract-range-tree.hpp\"\
    \nusing namespace std;\n\n// DS ... data_structure_type\n// S ... size_type\n\
    // T ... value_type\ntemplate <typename DS, typename S, typename T>\nstruct RangeTree\
    \ {\n  using NEW = function<DS*(int)>;\n  using ADD = function<void(DS&, int,\
    \ T)>;\n  using SUM = function<T(DS&, int, int)>;\n  using MRG = function<T(T,\
    \ T)>;\n  using P = pair<S, S>;\n\n  S N, M;\n  const NEW ds_new;\n  const ADD\
    \ ds_add;\n  const SUM ds_sum;\n  const MRG t_merge;\n  const T ti;\n  vector<DS*>\
    \ ds;\n  vector<vector<S>> ys;\n  vector<P> ps;\n\n  RangeTree(const NEW& nw,\
    \ const ADD& ad, const SUM& sm, const MRG& mrg,\n            const T& ti_)\n \
    \     : ds_new(nw), ds_add(ad), ds_sum(sm), t_merge(mrg), ti(ti_) {}\n\n  void\
    \ add_point(S x, S y) { ps.push_back(make_pair(x, y)); }\n\n  void build() {\n\
    \    sort(begin(ps), end(ps));\n    ps.erase(unique(begin(ps), end(ps)), end(ps));\n\
    \    N = ps.size();\n    ds.resize(2 * N, nullptr);\n    ys.resize(2 * N);\n \
    \   for (int i = 0; i < N; ++i) {\n      ys[i + N].push_back(ps[i].second);\n\
    \      ds[i + N] = ds_new(1);\n    }\n    for (int i = N - 1; i > 0; --i) {\n\
    \      ys[i].resize(ys[i << 1].size() + ys[(i << 1) | 1].size());\n      merge(begin(ys[(i\
    \ << 1) | 0]), end(ys[(i << 1) | 0]),\n            begin(ys[(i << 1) | 1]), end(ys[(i\
    \ << 1) | 1]), begin(ys[i]));\n      ys[i].erase(unique(begin(ys[i]), end(ys[i])),\
    \ end(ys[i]));\n      ds[i] = ds_new(ys[i].size());\n    }\n  }\n\n  int id(S\
    \ x) const {\n    return lower_bound(\n               begin(ps), end(ps), make_pair(x,\
    \ S()),\n               [](const P& a, const P& b) { return a.first < b.first;\
    \ }) -\n           begin(ps);\n  }\n\n  int id(int i, S y) const {\n    return\
    \ lower_bound(begin(ys[i]), end(ys[i]), y) - begin(ys[i]);\n  }\n\n  void add(S\
    \ x, S y, T a) {\n    int i = lower_bound(begin(ps), end(ps), make_pair(x, y))\
    \ - begin(ps);\n    assert(ps[i] == make_pair(x, y));\n    for (i += N; i; i >>=\
    \ 1) ds_add(*ds[i], id(i, y), a);\n  }\n\n  T sum(S xl, S yl, S xr, S yr) {\n\
    \    T L = ti, R = ti;\n    int a = id(xl), b = id(xr);\n    for (a += N, b +=\
    \ N; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) L = t_merge(L, ds_sum(*ds[a],\
    \ id(a, yl), id(a, yr))), ++a;\n      if (b & 1) --b, R = t_merge(ds_sum(*ds[b],\
    \ id(b, yl), id(b, yr)), R);\n    }\n    return t_merge(L, R);\n  }\n};\n\n/*\n\
    \ * @brief \u62BD\u8C61\u5316\u9818\u57DF\u6728\n * @docs docs/data-structure-2d/ds-2d.md\n\
    \ */\n#line 3 \"data-structure/binary-indexed-tree.hpp\"\nusing namespace std;\n\
    \ntemplate <typename T>\nstruct BinaryIndexedTree {\n  int N;\n  vector<T> data;\n\
    \n  BinaryIndexedTree() = default;\n\n  BinaryIndexedTree(int size) { init(size);\
    \ }\n\n  void init(int size) {\n    N = size + 2;\n    data.assign(N + 1, 0);\n\
    \  }\n\n  // get sum of [0,k]\n  T sum(int k) const {\n    if (k < 0) return 0;\
    \  // return 0 if k < 0\n    T ret = 0;\n    for (++k; k > 0; k -= k & -k) ret\
    \ += data[k];\n    return ret;\n  }\n\n  // getsum of [l,r]\n  inline T sum(int\
    \ l, int r) const { return sum(r) - sum(l - 1); }\n\n  // get value of k\n  inline\
    \ T operator[](int k) const { return sum(k) - sum(k - 1); }\n\n  // data[k] +=\
    \ x\n  void add(int k, T x) {\n    for (++k; k < N; k += k & -k) data[k] += x;\n\
    \  }\n\n  // range add x to [l,r]\n  void imos(int l, int r, T x) {\n    add(l,\
    \ x);\n    add(r + 1, -x);\n  }\n\n  // minimize i s.t. sum(i) >= w\n  int lower_bound(T\
    \ w) {\n    if (w <= 0) return 0;\n    int x = 0;\n    for (int k = 1 << __lg(N);\
    \ k; k >>= 1) {\n      if (x + k <= N - 1 && data[x + k] < w) {\n        w -=\
    \ data[x + k];\n        x += k;\n      }\n    }\n    return x;\n  }\n\n  // minimize\
    \ i s.t. sum(i) > w\n  int upper_bound(T w) {\n    if (w < 0) return 0;\n    int\
    \ x = 0;\n    for (int k = 1 << __lg(N); k; k >>= 1) {\n      if (x + k <= N -\
    \ 1 && data[x + k] <= w) {\n        w -= data[x + k];\n        x += k;\n     \
    \ }\n    }\n    return x;\n  }\n};\n\n/**\n * @brief Binary Indexed Tree(Fenwick\
    \ Tree)\n * @docs docs/data-structure/binary-indexed-tree.md\n */\n#line 3 \"\
    misc/compress.hpp\"\nusing namespace std;\n\ntemplate<class T>\nstruct compress{\n\
    \  vector<T> xs;\n  compress(const vector<T>& v){\n    xs.reserve(v.size());\n\
    \    for(T x : v) xs.push_back(x);\n    sort(xs.begin(),xs.end());\n    xs.erase(unique(xs.begin(),xs.end())\
    \ , xs.end());\n  }\n\n  int get(const T& x){\n    return lower_bound(xs.begin(),xs.end(),x)\
    \ - xs.begin();\n  }\n  int size(){\n    return xs.size();\n  }\n  T& operator[](int\
    \ i){\n    return xs[i];\n  }\n};\n#line 3 \"misc/fastio.hpp\"\nusing namespace\
    \ std;\n\nnamespace fastio {\nstatic constexpr int SZ = 1 << 17;\nchar ibuf[SZ],\
    \ obuf[SZ];\nint pil = 0, pir = 0, por = 0;\n\nstruct Pre {\n  char num[40000];\n\
    \  constexpr Pre() : num() {\n    for (int i = 0; i < 10000; i++) {\n      int\
    \ n = i;\n      for (int j = 3; j >= 0; j--) {\n        num[i * 4 + j] = n % 10\
    \ + '0';\n        n /= 10;\n      }\n    }\n  }\n} constexpr pre;\n\ninline void\
    \ load() {\n  memcpy(ibuf, ibuf + pil, pir - pil);\n  pir = pir - pil + fread(ibuf\
    \ + pir - pil, 1, SZ - pir + pil, stdin);\n  pil = 0;\n}\ninline void flush()\
    \ {\n  fwrite(obuf, 1, por, stdout);\n  por = 0;\n}\n\ninline void rd(char& c)\
    \ { c = ibuf[pil++]; }\ntemplate <typename T>\ninline void rd(T& x) {\n  if (pil\
    \ + 32 > pir) load();\n  char c;\n  do\n    c = ibuf[pil++];\n  while (c < '-');\n\
    \  bool minus = 0;\n  if (c == '-') {\n    minus = 1;\n    c = ibuf[pil++];\n\
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
    #line 8 \"verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-abstruct-range-tree.test.cpp\"\
    \n\nvoid solve() {\n  using BIT = BinaryIndexedTree<ll>;\n  auto nw = [](int n)\
    \ { return new BIT(n); };\n  auto add = [](BIT& bit, int i, ll a) { bit.add(i,\
    \ a); };\n  auto sum = [](BIT& bit, int i, int j) {\n    return bit.sum(j - 1)\
    \ - bit.sum(i - 1);\n  };\n  auto mrg = [](ll a, ll b) { return a + b; };\n\n\
    \  RangeTree<BIT, int, ll> rtree(nw, add, sum, mrg, 0);\n\n  int N, Q;\n  rd(N,\
    \ Q);\n  vector<int> X(N), Y(N), W(N), c(Q), s(Q), t(Q), u(Q), v(Q);\n  rep(i,\
    \ N) {\n    rd(X[i], Y[i], W[i]);\n    rtree.add_point(X[i], Y[i]);\n  }\n  rep(i,\
    \ Q) {\n    rd(c[i], s[i], t[i], u[i]);\n    if (c[i])\n      rd(v[i]);\n    else\n\
    \      rtree.add_point(s[i], t[i]);\n  }\n\n  rtree.build();\n  rep(i, N) { rtree.add(X[i],\
    \ Y[i], W[i]); }\n  rep(i, Q) {\n    if (c[i]) {\n      out(rtree.sum(s[i], t[i],\
    \ u[i], v[i]));\n    } else\n      rtree.add(s[i], t[i], u[i]);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../../competitive-template.hpp\"\n#include \"../../data-structure-2d/abstract-range-tree.hpp\"\
    \n#include \"../../data-structure/binary-indexed-tree.hpp\"\n#include \"../../misc/compress.hpp\"\
    \n#include \"../../misc/fastio.hpp\"\n\nvoid solve() {\n  using BIT = BinaryIndexedTree<ll>;\n\
    \  auto nw = [](int n) { return new BIT(n); };\n  auto add = [](BIT& bit, int\
    \ i, ll a) { bit.add(i, a); };\n  auto sum = [](BIT& bit, int i, int j) {\n  \
    \  return bit.sum(j - 1) - bit.sum(i - 1);\n  };\n  auto mrg = [](ll a, ll b)\
    \ { return a + b; };\n\n  RangeTree<BIT, int, ll> rtree(nw, add, sum, mrg, 0);\n\
    \n  int N, Q;\n  rd(N, Q);\n  vector<int> X(N), Y(N), W(N), c(Q), s(Q), t(Q),\
    \ u(Q), v(Q);\n  rep(i, N) {\n    rd(X[i], Y[i], W[i]);\n    rtree.add_point(X[i],\
    \ Y[i]);\n  }\n  rep(i, Q) {\n    rd(c[i], s[i], t[i], u[i]);\n    if (c[i])\n\
    \      rd(v[i]);\n    else\n      rtree.add_point(s[i], t[i]);\n  }\n\n  rtree.build();\n\
    \  rep(i, N) { rtree.add(X[i], Y[i], W[i]); }\n  rep(i, Q) {\n    if (c[i]) {\n\
    \      out(rtree.sum(s[i], t[i], u[i], v[i]));\n    } else\n      rtree.add(s[i],\
    \ t[i], u[i]);\n  }\n}"
  dependsOn:
  - competitive-template.hpp
  - data-structure-2d/abstract-range-tree.hpp
  - data-structure/binary-indexed-tree.hpp
  - misc/compress.hpp
  - misc/fastio.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-abstruct-range-tree.test.cpp
  requiredBy: []
  timestamp: '2020-10-28 23:43:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-abstruct-range-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-abstruct-range-tree.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-abstruct-range-tree.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-abstruct-range-tree.test.cpp
---
