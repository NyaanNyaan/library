---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-indexed-tree.hpp
    title: Binary Indexed Tree(Fenwick Tree)
  - icon: ':question:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/static-graph.hpp
    title: Static Graph
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: tree/dsu-on-tree.hpp
    title: DSU on Tree(Guni)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-dst-on-tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"data-structure/binary-indexed-tree.hpp\"\
    \nusing namespace std;\n\ntemplate <typename T>\nstruct BinaryIndexedTree {\n\
    \  int N;\n  vector<T> data;\n\n  BinaryIndexedTree() = default;\n\n  BinaryIndexedTree(int\
    \ size) { init(size); }\n\n  void init(int size) {\n    N = size + 2;\n    data.assign(N\
    \ + 1, 0);\n  }\n\n  // get sum of [0,k]\n  T sum(int k) const {\n    if (k <\
    \ 0) return 0;  // return 0 if k < 0\n    T ret = 0;\n    for (++k; k > 0; k -=\
    \ k & -k) ret += data[k];\n    return ret;\n  }\n\n  // getsum of [l,r]\n  inline\
    \ T sum(int l, int r) const { return sum(r) - sum(l - 1); }\n\n  // get value\
    \ of k\n  inline T operator[](int k) const { return sum(k) - sum(k - 1); }\n\n\
    \  // data[k] += x\n  void add(int k, T x) {\n    for (++k; k < N; k += k & -k)\
    \ data[k] += x;\n  }\n\n  // range add x to [l,r]\n  void imos(int l, int r, T\
    \ x) {\n    add(l, x);\n    add(r + 1, -x);\n  }\n\n  // minimize i s.t. sum(i)\
    \ >= w\n  int lower_bound(T w) {\n    if (w <= 0) return 0;\n    int x = 0;\n\
    \    for (int k = 1 << __lg(N); k; k >>= 1) {\n      if (x + k <= N - 1 && data[x\
    \ + k] < w) {\n        w -= data[x + k];\n        x += k;\n      }\n    }\n  \
    \  return x;\n  }\n\n  // minimize i s.t. sum(i) > w\n  int upper_bound(T w) {\n\
    \    if (w < 0) return 0;\n    int x = 0;\n    for (int k = 1 << __lg(N); k; k\
    \ >>= 1) {\n      if (x + k <= N - 1 && data[x + k] <= w) {\n        w -= data[x\
    \ + k];\n        x += k;\n      }\n    }\n    return x;\n  }\n};\n\n/**\n * @brief\
    \ Binary Indexed Tree(Fenwick Tree)\n * @docs docs/data-structure/binary-indexed-tree.md\n\
    \ */\n#line 3 \"graph/static-graph.hpp\"\nusing namespace std;\n\nnamespace StaticGraphImpl\
    \ {\n\ntemplate <typename T, bool Cond = is_void<T>::value>\nstruct E;\ntemplate\
    \ <typename T>\nstruct E<T, false> {\n  int to;\n  T cost;\n  E() {}\n  E(const\
    \ int& v, const T& c) : to(v), cost(c) {}\n  operator int() const { return to;\
    \ }\n};\ntemplate <typename T>\nstruct E<T, true> {\n  int to;\n  E() {}\n  E(const\
    \ int& v) : to(v) {}\n  operator int() const { return to; }\n};\n\ntemplate <typename\
    \ T = void>\nstruct StaticGraph {\n private:\n  template <typename It>\n  struct\
    \ Es {\n    It b, e;\n    It begin() const { return b; }\n    It end() const {\
    \ return e; }\n    int size() const { return int(e - b); }\n    auto&& operator[](int\
    \ i) const { return b[i]; }\n  };\n  \n  int N, M, ec;\n  vector<int> head;\n\
    \  vector<pair<int, E<T>>> buf;\n  vector<E<T>> es;\n\n  void build() {\n    partial_sum(begin(head),\
    \ end(head), begin(head));\n    es.resize(M);\n    for (auto&& [u, e] : buf) es[--head[u]]\
    \ = e;\n  }\n\n public:\n  StaticGraph(int _n, int _m) : N(_n), M(_m), ec(0),\
    \ head(N + 1, 0) {\n    buf.reserve(M);\n  }\n\n  template <typename... Args>\n\
    \  void add_edge(int u, Args&&... args) {\n#pragma GCC diagnostic ignored \"-Wnarrowing\"\
    \n    buf.emplace_back(u, E<T>{std::forward<Args>(args)...});\n#pragma GCC diagnostic\
    \ warning \"-Wnarrowing\"\n    ++head[u];\n    if ((int)buf.size() == M) build();\n\
    \  }\n\n  Es<typename vector<E<T>>::iterator> operator[](int u) {\n    return\
    \ {begin(es) + head[u], begin(es) + head[u + 1]};\n  }\n  const Es<typename vector<E<T>>::const_iterator>\
    \ operator[](int u) const {\n    return {begin(es) + head[u], begin(es) + head[u\
    \ + 1]};\n  }\n  int size() const { return N; }\n};\n\n}  // namespace StaticGraphImpl\n\
    \nusing StaticGraphImpl::StaticGraph;\n\n/**\n * @brief Static Graph\n * @docs\
    \ docs/graph/static-graph.md\n */\n#line 3 \"misc/fastio.hpp\"\nusing namespace\
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
    #line 3 \"tree/dsu-on-tree.hpp\"\nusing namespace std;\n\n#line 3 \"graph/graph-template.hpp\"\
    \nusing namespace std;\n\ntemplate <typename T>\nstruct edge {\n  int src, to;\n\
    \  T cost;\n\n  edge(int _to, T _cost) : src(-1), to(_to), cost(_cost) {}\n  edge(int\
    \ _src, int _to, T _cost) : src(_src), to(_to), cost(_cost) {}\n\n  edge &operator=(const\
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
    \ d;\n}\n#line 6 \"tree/dsu-on-tree.hpp\"\n\ntemplate <typename G>\nstruct DSUonTree\
    \ {\n private:\n  G &g;\n  int N;\n  vector<int> sub_sz, euler, down, up;\n  int\
    \ idx_;\n  int root;\n\n  int dfs1(int cur, int par = -1) {\n    sub_sz[cur] =\
    \ 1;\n    if ((int)g[cur].size() >= 2 and g[cur][0] == par) {\n      swap(g[cur][0],\
    \ g[cur][1]);\n    }\n    for (auto &dst : g[cur]) {\n      if (dst == par) continue;\n\
    \      sub_sz[cur] += dfs1(dst, cur);\n      if (sub_sz[dst] > sub_sz[g[cur][0]])\
    \ swap(dst, g[cur][0]);\n    }\n    return sub_sz[cur];\n  }\n\n  void dfs2(int\
    \ cur, int par = -1) {\n    euler[idx_] = cur;\n    down[cur] = idx_++;\n    for\
    \ (auto &dst : g[cur]) {\n      if (dst == par) continue;\n      dfs2(dst, cur);\n\
    \    }\n    up[cur] = idx_;\n  }\n\n public:\n  DSUonTree(G &_g,int _root = 0)\n\
    \      : g(_g),\n        N(_g.size()),\n        sub_sz(_g.size()),\n        euler(_g.size()),\n\
    \        down(_g.size()),\n        up(_g.size()),\n        idx_(0),\n        root(_root)\
    \ {\n    dfs1(root);\n    dfs2(root);\n  }\n\n  int idx(int u) const { return\
    \ down[u]; }\n\n  template <typename UPDATE, typename QUERY, typename CLEAR, typename\
    \ RESET>\n  void run(UPDATE &update, QUERY &query, CLEAR &clear, RESET &reset)\
    \ {\n    auto dsu = [&](auto rc, int cur, int par = -1, bool keep = true) -> void\
    \ {\n      // light edge -> run dfs and clear data\n      for (int i = 1; i <\
    \ (int)g[cur].size(); i++)\n        if (g[cur][i] != par) rc(rc, g[cur][i], cur,\
    \ false);\n\n      // heavy edge -> run dfs and reserve data\n      if (sub_sz[cur]\
    \ != 1) rc(rc, g[cur][0], cur, true);\n\n      // light edge -> reserve data\n\
    \      if (sub_sz[cur] != 1)\n        for (int i = up[g[cur][0]]; i < up[cur];\
    \ i++) update(euler[i]);\n\n      // current node -> reserve data\n      update(cur);\n\
    \n      // answer queries related to subtree of current node\n      query(cur);\n\
    \n      // if keep is false, clear all data\n      if (!keep) {\n        for (int\
    \ i = down[cur]; i < up[cur]; i++) clear(euler[i]);\n        reset();\n      }\n\
    \      return;\n    };\n    dsu(dsu, root);\n  }\n};\n\n/**\n * @brief DSU on\
    \ Tree(Guni)\n * @docs docs/tree/dsu-on-tree.md\n */\n#line 8 \"verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-dst-on-tree.test.cpp\"\
    \n\nvoid solve() {\n  int N, Q;\n  rd(N, Q);\n  vector<int> a(N);\n  rep(i, N)\
    \ rd(a[i]);\n\n  StaticGraph<void> g(N, N - 1);\n  rep1(i, N - 1) {\n    int p;\n\
    \    rd(p);\n    g.add_edge(p, i);\n  }\n\n  V<V<pair<int, int>>> upd(N);\n  V<V<int>>\
    \ que(N);\n\n  rep(i, N) upd[i].emplace_back(0, a[i]);\n  rep1(i, Q) {\n    int\
    \ c, u;\n    rd(c, u);\n    if (c == 0) {\n      int x;\n      rd(x);\n      upd[u].emplace_back(i,\
    \ x);\n    } else {\n      que[u].push_back(i);\n    }\n  }\n\n  BinaryIndexedTree<ll>\
    \ bit(Q + 1);\n  vl ans(Q + 1, infLL);\n\n  // reflect data of node i\n  auto\
    \ update = [&](int i) {\n    for (auto&& [j, x] : upd[i]) bit.add(j, x);\n  };\n\
    \  // answer queries of subtree i\n  auto query = [&](int i) {\n    for (auto&&\
    \ j : que[i]) ans[j] = bit.sum(j);\n  };\n  // below two function are called if\
    \ all data must be deleted\n  // delete data of node i (if necesarry)\n  auto\
    \ clear = [&](int i) {\n    for (auto&& [j, x] : upd[i]) bit.add(j, -x);\n  };\n\
    \  // delete data related to all (if necesarry)\n  auto reset = [&]() {\n\n  };\n\
    \n  DSUonTree<decltype(g)> dsu(g);\n  dsu.run(update, query, clear, reset);\n\
    \  each(x, ans) if (x != infLL) wtn(x);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../../competitive-template.hpp\"\n#include \"../../data-structure/binary-indexed-tree.hpp\"\
    \n#include \"../../graph/static-graph.hpp\"\n#include \"../../misc/fastio.hpp\"\
    \n#include \"../../tree/dsu-on-tree.hpp\"\n\nvoid solve() {\n  int N, Q;\n  rd(N,\
    \ Q);\n  vector<int> a(N);\n  rep(i, N) rd(a[i]);\n\n  StaticGraph<void> g(N,\
    \ N - 1);\n  rep1(i, N - 1) {\n    int p;\n    rd(p);\n    g.add_edge(p, i);\n\
    \  }\n\n  V<V<pair<int, int>>> upd(N);\n  V<V<int>> que(N);\n\n  rep(i, N) upd[i].emplace_back(0,\
    \ a[i]);\n  rep1(i, Q) {\n    int c, u;\n    rd(c, u);\n    if (c == 0) {\n  \
    \    int x;\n      rd(x);\n      upd[u].emplace_back(i, x);\n    } else {\n  \
    \    que[u].push_back(i);\n    }\n  }\n\n  BinaryIndexedTree<ll> bit(Q + 1);\n\
    \  vl ans(Q + 1, infLL);\n\n  // reflect data of node i\n  auto update = [&](int\
    \ i) {\n    for (auto&& [j, x] : upd[i]) bit.add(j, x);\n  };\n  // answer queries\
    \ of subtree i\n  auto query = [&](int i) {\n    for (auto&& j : que[i]) ans[j]\
    \ = bit.sum(j);\n  };\n  // below two function are called if all data must be\
    \ deleted\n  // delete data of node i (if necesarry)\n  auto clear = [&](int i)\
    \ {\n    for (auto&& [j, x] : upd[i]) bit.add(j, -x);\n  };\n  // delete data\
    \ related to all (if necesarry)\n  auto reset = [&]() {\n\n  };\n\n  DSUonTree<decltype(g)>\
    \ dsu(g);\n  dsu.run(update, query, clear, reset);\n  each(x, ans) if (x != infLL)\
    \ wtn(x);\n}\n"
  dependsOn:
  - competitive-template.hpp
  - data-structure/binary-indexed-tree.hpp
  - graph/static-graph.hpp
  - misc/fastio.hpp
  - tree/dsu-on-tree.hpp
  - graph/graph-template.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-dst-on-tree.test.cpp
  requiredBy: []
  timestamp: '2020-11-26 23:21:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-dst-on-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-dst-on-tree.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-dst-on-tree.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-dst-on-tree.test.cpp
---
