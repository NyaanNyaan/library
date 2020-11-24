---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph-utility.hpp
    title: graph/graph-utility.hpp
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':question:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: segment-tree/segment-tree.hpp
    title: segment-tree/segment-tree.hpp
  - icon: ':heavy_check_mark:'
    path: tree/heavy-light-decomposition.hpp
    title: tree/heavy-light-decomposition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"graph/graph-utility.hpp\"\
    \nusing namespace std;\n\n#line 3 \"graph/graph-template.hpp\"\nusing namespace\
    \ std;\n\ntemplate <typename T>\nstruct edge {\n  int src, to;\n  T cost;\n\n\
    \  edge(int _to, T _cost) : src(-1), to(_to), cost(_cost) {}\n  edge(int _src,\
    \ int _to, T _cost) : src(_src), to(_to), cost(_cost) {}\n\n  edge &operator=(const\
    \ int &x) {\n    to = x;\n    return *this;\n  }\n\n  operator int() const { return\
    \ to; }\n};\ntemplate <typename T>\nusing Edges = vector<edge<T>>;\ntemplate <typename\
    \ T>\nusing WeightedGraph = vector<Edges<T>>;\nusing UnweightedGraph = vector<vector<int>>;\n\
    \n// Input of (Unweighted) Graph\nUnweightedGraph graph(int N, int M = -1, bool\
    \ is_directed = false,\n                      bool is_1origin = true) {\n  UnweightedGraph\
    \ g(N);\n  if (M == -1) M = N - 1;\n  for (int _ = 0; _ < M; _++) {\n    int x,\
    \ y;\n    cin >> x >> y;\n    if (is_1origin) x--, y--;\n    g[x].push_back(y);\n\
    \    if (!is_directed) g[y].push_back(x);\n  }\n  return g;\n}\n\n// Input of\
    \ Weighted Graph\ntemplate <typename T>\nWeightedGraph<T> wgraph(int N, int M\
    \ = -1, bool is_directed = false,\n                        bool is_1origin = true)\
    \ {\n  WeightedGraph<T> g(N);\n  if (M == -1) M = N - 1;\n  for (int _ = 0; _\
    \ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    cin >> c;\n  \
    \  if (is_1origin) x--, y--;\n    g[x].eb(x, y, c);\n    if (!is_directed) g[y].eb(y,\
    \ x, c);\n  }\n  return g;\n}\n\n// Input of Edges\ntemplate <typename T>\nEdges<T>\
    \ esgraph(int N, int M, int is_weighted = true, bool is_1origin = true) {\n  Edges<T>\
    \ es;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n  \
    \  T c;\n    if (is_weighted)\n      cin >> c;\n    else\n      c = 1;\n    if\
    \ (is_1origin) x--, y--;\n    es.emplace_back(x, y, c);\n  }\n  return es;\n}\n\
    \n// Input of Adjacency Matrix\ntemplate <typename T>\nvector<vector<T>> adjgraph(int\
    \ N, int M, T INF, int is_weighted = true,\n                           bool is_directed\
    \ = false, bool is_1origin = true) {\n  vector<vector<T>> d(N, vector<T>(N, INF));\n\
    \  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n\
    \    if (is_weighted)\n      cin >> c;\n    else\n      c = 1;\n    if (is_1origin)\
    \ x--, y--;\n    d[x][y] = c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return\
    \ d;\n}\n#line 6 \"graph/graph-utility.hpp\"\n\n// Depth of Rooted Tree\n// unvisited\
    \ nodes : d = -1\nvector<int> Depth(const UnweightedGraph &g, int start = 0) {\n\
    \  vector<int> d(g.size(), -1);\n  auto dfs = [&](auto rec, int cur, int par =\
    \ -1) -> void {\n    d[cur] = par == -1 ? 0 : d[par] + 1;\n    for (auto &dst\
    \ : g[cur]) {\n      if (dst == par) continue;\n      rec(rec, dst, cur);\n  \
    \  }\n  };\n  dfs(dfs, start);\n  return d;\n}\n\n// Depth of Rooted Weighted\
    \ Tree\n// unvisited nodes : d = -1\ntemplate <typename T>\nvector<T> Depth(const\
    \ WeightedGraph<T> &g, int start = 0) {\n  vector<T> d(g.size(), -1);\n  auto\
    \ dfs = [&](auto rec, int cur, T val, int par = -1) -> void {\n    d[cur] = val;\n\
    \    for (auto &dst : g[cur]) {\n      if (dst == par) continue;\n      rec(rec,\
    \ dst, val + dst.cost, cur);\n    }\n  };\n  dfs(dfs, start, 0);\n  return d;\n\
    }\n\n// Diameter of Tree\n// return value : { {u, v}, length }\npair<pair<int,\
    \ int>, int> Diameter(const UnweightedGraph &g) {\n  auto d = Depth(g, 0);\n \
    \ int u = max_element(begin(d), end(d)) - begin(d);\n  d = Depth(g, u);\n  int\
    \ v = max_element(begin(d), end(d)) - begin(d);\n  return make_pair(make_pair(u,\
    \ v), d[v]);\n}\n\n// Diameter of Weighted Tree\n// return value : { {u, v}, length\
    \ }\ntemplate <typename T>\npair<pair<int, int>, T> Diameter(const WeightedGraph<T>\
    \ &g) {\n  auto d = Depth(g, 0);\n  int u = max_element(begin(d), end(d)) - begin(d);\n\
    \  d = Depth(g, u);\n  int v = max_element(begin(d), end(d)) - begin(d);\n  return\
    \ make_pair(make_pair(u, v), d[v]);\n}\n\n// nodes on the path u-v ( O(N) )\n\
    template <typename G>\nvector<int> Path(G &g, int u, int v) {\n  vi ret;\n  int\
    \ end = 0;\n  auto dfs = [&](auto rec, int cur, int par = -1) -> void {\n    ret.push_back(cur);\n\
    \    if (cur == v) {\n      end = 1;\n      return;\n    }\n    for (int dst :\
    \ g[cur]) {\n      if (dst == par) continue;\n      rec(rec, dst, cur);\n    \
    \  if (end) return;\n    }\n    if (end) return;\n    ret.pop_back();\n  };\n\
    \  dfs(dfs, u);\n  return ret;\n}\n#line 3 \"misc/fastio.hpp\"\nusing namespace\
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
    \ { return mod; }\n};\n#line 3 \"segment-tree/segment-tree.hpp\"\nusing namespace\
    \ std;\n\ntemplate <typename T, typename F>\nstruct SegmentTree {\n  int size;\n\
    \  vector<T> seg;\n  const F f;\n  const T I;\n\n  SegmentTree(F f_, const T &I_)\
    \ : size(0), f(f_), I(I_) {}\n\n  SegmentTree(int N, F f_, const T &I_) : f(f_),\
    \ I(I_) { init(N); }\n\n  SegmentTree(const vector<T> &v, F f, T I) : f(f), I(I)\
    \ {\n    init(v.size());\n    for (int i = 0; i < (int)v.size(); i++) {\n    \
    \  seg[i + size] = v[i];\n    }\n    build();\n  }\n\n  void init(int N) {\n \
    \   size = 1;\n    while (size < N) size <<= 1;\n    seg.assign(2 * size, I);\n\
    \  }\n\n  void set(int k, T x) { seg[k + size] = x; }\n\n  void build() {\n  \
    \  for (int k = size - 1; k > 0; k--) {\n      seg[k] = f(seg[2 * k], seg[2 *\
    \ k + 1]);\n    }\n  }\n\n  void update(int k, T x) {\n    k += size;\n    seg[k]\
    \ = x;\n    while (k >>= 1) {\n      seg[k] = f(seg[2 * k], seg[2 * k + 1]);\n\
    \    }\n  }\n\n  void add(int k, T x) {\n    k += size;\n    seg[k] += x;\n  \
    \  while (k >>= 1) {\n      seg[k] = f(seg[2 * k], seg[2 * k + 1]);\n    }\n \
    \ }\n\n  // query to [a, b)\n  T query(int a, int b) {\n    T L = I, R = I;\n\
    \    for (a += size, b += size; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) L\
    \ = f(L, seg[a++]);\n      if (b & 1) R = f(seg[--b], R);\n    }\n    return f(L,\
    \ R);\n  }\n\n  T &operator[](const int &k) { return seg[k + size]; }\n\n  template\
    \ <typename C>\n  int find_subtree(int a, const C &check, T &M, bool type) {\n\
    \    while (a < size) {\n      T nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2\
    \ * a + type]);\n      if (check(nxt))\n        a = 2 * a + type;\n      else\n\
    \        M = nxt, a = 2 * a + 1 - type;\n    }\n    return a - size;\n  }\n\n\
    \  template <typename C>\n  int find_first(int a, const C &check) {\n    T L =\
    \ I;\n    if (a <= 0) {\n      if (check(f(L, seg[1]))) return find_subtree(1,\
    \ check, L, false);\n      return -1;\n    }\n    int b = size;\n    for (a +=\
    \ size, b += size; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) {\n        T nxt\
    \ = f(L, seg[a]);\n        if (check(nxt)) return find_subtree(a, check, L, false);\n\
    \        L = nxt;\n        ++a;\n      }\n    }\n    return -1;\n  }\n\n  template\
    \ <typename C>\n  int find_last(int b, const C &check) {\n    T R = I;\n    if\
    \ (b >= size) {\n      if (check(f(seg[1], R))) return find_subtree(1, check,\
    \ R, true);\n      return -1;\n    }\n    int a = size;\n    for (b += size; a\
    \ < b; a >>= 1, b >>= 1) {\n      if (b & 1) {\n        T nxt = f(seg[--b], R);\n\
    \        if (check(nxt)) return find_subtree(b, check, R, true);\n        R =\
    \ nxt;\n      }\n    }\n    return -1;\n  }\n};\n#line 3 \"tree/heavy-light-decomposition.hpp\"\
    \nusing namespace std;\n\n#line 6 \"tree/heavy-light-decomposition.hpp\"\n\ntemplate\
    \ <typename G>\nstruct HeavyLightDecomposition {\n  G& g;\n  int idx;\n  vector<int>\
    \ size, depth, in, out, nxt, par;\n  HeavyLightDecomposition(G& g, int root =\
    \ 0)\n      : g(g),\n        idx(0),\n        size(g.size(), 0),\n        depth(g.size(),\
    \ 0),\n        in(g.size(), -1),\n        out(g.size(), -1),\n        nxt(g.size(),\
    \ root),\n        par(g.size(), root) {\n    dfs_sz(root);\n    dfs_hld(root);\n\
    \  }\n\n  void build(int root) {\n    dfs_sz(root);\n    dfs_hld(root);\n  }\n\
    \n  void dfs_sz(int cur) {\n    size[cur] = 1;\n    for (auto& dst : g[cur]) {\n\
    \      if (dst == par[cur]) {\n        if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))\n\
    \          swap(g[cur][0], g[cur][1]);\n        else\n          continue;\n  \
    \    }\n      depth[dst] = depth[cur] + 1;\n      par[dst] = cur;\n      dfs_sz(dst);\n\
    \      size[cur] += size[dst];\n      if (size[dst] > size[g[cur][0]]) {\n   \
    \     swap(dst, g[cur][0]);\n      }\n    }\n  }\n\n  void dfs_hld(int cur) {\n\
    \    in[cur] = idx++;\n    for (auto dst : g[cur]) {\n      if (dst == par[cur])\
    \ continue;\n      nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));\n\
    \      dfs_hld(dst);\n    }\n    out[cur] = idx;\n  }\n\n  template <typename\
    \ F>\n  void edge_query(int u, int v, const F& f) {\n    while (1) {\n      if\
    \ (in[u] > in[v]) swap(u, v);\n      if (nxt[u] != nxt[v]) {\n        f(in[nxt[v]],\
    \ in[v] + 1);\n        v = par[nxt[v]];\n      } else {\n        if (u != v) f(in[u]\
    \ + 1, in[v] + 1);\n        break;\n      }\n    }\n  }\n\n  // TODO : verify\n\
    \  template <typename F>\n  void uncommutable_edge_query(int u, int v, const F&\
    \ f) {\n    while (1) {\n      if (nxt[u] != nxt[v]) {\n        if (in[u] > in[v])\
    \ {\n          f(in[u] + 1, in[nxt[u]], true);\n          u = par[nxt[u]];\n \
    \       } else {\n          f(in[nxt[v]], in[v] + 1, false);\n          v = par[nxt[v]];\n\
    \        }\n      } else {\n        if (in[u] != in[v]) {\n          if (in[u]\
    \ > in[v])\n            f(in[u] + 1, in[v] + 1, true);\n          else\n     \
    \       f(in[u] + 1, in[v] + 1, true);\n        }\n        break;\n      }\n \
    \   }\n  }\n\n  template <typename F>\n  void node_query(int u, int v, const F&\
    \ f) {\n    while (1) {\n      if (in[u] > in[v]) swap(u, v);\n      if (nxt[u]\
    \ != nxt[v]) {\n        f(in[nxt[v]], in[v] + 1);\n        v = par[nxt[v]];\n\
    \      } else {\n        f(in[u], in[v] + 1);\n        break;\n      }\n    }\n\
    \  }\n\n  template <typename F>\n  void uncommutable_node_query(int u, int v,\
    \ const F& f) {\n    while (1) {\n      if (nxt[u] != nxt[v]) {\n        if (in[u]\
    \ > in[v]) {\n          f(in[u] + 1, in[nxt[u]], true);\n          u = par[nxt[u]];\n\
    \        } else {\n          f(in[nxt[v]], in[v] + 1, false);\n          v = par[nxt[v]];\n\
    \        }\n      } else {\n        if (in[u] > in[v])\n          f(in[u] + 1,\
    \ in[v], true);\n        else\n          f(in[u], in[v] + 1, true);\n        break;\n\
    \      }\n    }\n  }\n\n  template <typename F>\n  void sub_edge_query(int u,\
    \ const F& f) {\n    f(in[u] + 1, out[u]);\n  }\n\n  template <typename F>\n \
    \ void sub_node_query(int u, const F& f) {\n    f(in[u], out[u]);\n  }\n\n  int\
    \ lca(int a, int b) {\n    while (nxt[a] != nxt[b]) {\n      if (in[a] < in[b])\
    \ swap(a, b);\n      a = par[nxt[a]];\n    }\n    return depth[a] < depth[b] ?\
    \ a : b;\n  }\n};\n#line 9 \"verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp\"\
    \n\nvoid solve() {\n  using mint = LazyMontgomeryModInt<998244353>;\n  int N,\
    \ Q;\n  rd(N);\n  rd(Q);\n  V<mint> a(N), b(N);\n  for (int i = 0; i < N; i++)\
    \ {\n    int buf;\n    rd(buf);\n    a[i] = buf;\n    rd(buf);\n    b[i] = buf;\n\
    \  }\n  vvi g(N);\n  rep(_, N - 1) {\n    int u, v;\n    rd(u);\n    rd(v);\n\
    \    g[u].pb(v);\n    g[v].pb(u);\n  }\n  HeavyLightDecomposition<vvi> hld(g);\n\
    \n  using P = pair<mint, mint>;\n  auto mul = [](P a, P b) {\n    return P{a.first\
    \ * b.first, a.second * b.first + b.second};\n  };\n  auto fl = [&mul](P a, P\
    \ b) { return mul(a, b); };\n  auto fr = [&mul](P a, P b) { return mul(b, a);\
    \ };\n  SegmentTree<P, decltype(fl)> segl(N, fl, P{1, 0});\n  SegmentTree<P, decltype(fr)>\
    \ segr(N, fr, P{1, 0});\n  rep(i, N) {\n    segl.set(hld.in[i], P{a[i], b[i]});\n\
    \    segr.set(hld.in[i], P{a[i], b[i]});\n  }\n  segl.build();\n  segr.build();\n\
    \n  rep(_, Q) {\n    int cmd, x, y, z;\n    rd(cmd);\n    rd(x);\n    rd(y);\n\
    \    rd(z);\n    if (!cmd) {\n      segl.update(hld.in[x], P{y, z});\n      segr.update(hld.in[x],\
    \ P{y, z});\n    } else {\n      P L{1, 0}, R{1, 0};\n      auto f = [&](int u,\
    \ int v, int le) {\n        if (le) {\n          if (u < v)\n            L = mul(L,\
    \ segl.query(u, v));\n          else\n            L = mul(L, segr.query(v, u));\n\
    \        } else {\n          if (u < v)\n            R = mul(segl.query(u, v),\
    \ R);\n          else\n            R = mul(segr.query(v, u), R);\n        }\n\
    \      };\n      hld.uncommutable_node_query(x, y, f);\n      P res = mul(L, R);\n\
    \      wt((res.first * z + res.second).get());\n      wt('\\n');\n    }\n  }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"../../competitive-template.hpp\"\n#include \"../../graph/graph-utility.hpp\"\
    \n#include \"../../misc/fastio.hpp\"\n#include \"../../modint/montgomery-modint.hpp\"\
    \n#include \"../../segment-tree/segment-tree.hpp\"\n#include \"../../tree/heavy-light-decomposition.hpp\"\
    \n\nvoid solve() {\n  using mint = LazyMontgomeryModInt<998244353>;\n  int N,\
    \ Q;\n  rd(N);\n  rd(Q);\n  V<mint> a(N), b(N);\n  for (int i = 0; i < N; i++)\
    \ {\n    int buf;\n    rd(buf);\n    a[i] = buf;\n    rd(buf);\n    b[i] = buf;\n\
    \  }\n  vvi g(N);\n  rep(_, N - 1) {\n    int u, v;\n    rd(u);\n    rd(v);\n\
    \    g[u].pb(v);\n    g[v].pb(u);\n  }\n  HeavyLightDecomposition<vvi> hld(g);\n\
    \n  using P = pair<mint, mint>;\n  auto mul = [](P a, P b) {\n    return P{a.first\
    \ * b.first, a.second * b.first + b.second};\n  };\n  auto fl = [&mul](P a, P\
    \ b) { return mul(a, b); };\n  auto fr = [&mul](P a, P b) { return mul(b, a);\
    \ };\n  SegmentTree<P, decltype(fl)> segl(N, fl, P{1, 0});\n  SegmentTree<P, decltype(fr)>\
    \ segr(N, fr, P{1, 0});\n  rep(i, N) {\n    segl.set(hld.in[i], P{a[i], b[i]});\n\
    \    segr.set(hld.in[i], P{a[i], b[i]});\n  }\n  segl.build();\n  segr.build();\n\
    \n  rep(_, Q) {\n    int cmd, x, y, z;\n    rd(cmd);\n    rd(x);\n    rd(y);\n\
    \    rd(z);\n    if (!cmd) {\n      segl.update(hld.in[x], P{y, z});\n      segr.update(hld.in[x],\
    \ P{y, z});\n    } else {\n      P L{1, 0}, R{1, 0};\n      auto f = [&](int u,\
    \ int v, int le) {\n        if (le) {\n          if (u < v)\n            L = mul(L,\
    \ segl.query(u, v));\n          else\n            L = mul(L, segr.query(v, u));\n\
    \        } else {\n          if (u < v)\n            R = mul(segl.query(u, v),\
    \ R);\n          else\n            R = mul(segr.query(v, u), R);\n        }\n\
    \      };\n      hld.uncommutable_node_query(x, y, f);\n      P res = mul(L, R);\n\
    \      wt((res.first * z + res.second).get());\n      wt('\\n');\n    }\n  }\n\
    }"
  dependsOn:
  - competitive-template.hpp
  - graph/graph-utility.hpp
  - graph/graph-template.hpp
  - misc/fastio.hpp
  - modint/montgomery-modint.hpp
  - segment-tree/segment-tree.hpp
  - tree/heavy-light-decomposition.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
  requiredBy: []
  timestamp: '2020-11-24 16:37:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
---
