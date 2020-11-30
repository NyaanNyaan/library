---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':question:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: tree/tree-query.hpp
    title: "\u6728\u306B\u5BFE\u3059\u308B\u4E00\u822C\u7684\u306A\u30AF\u30A8\u30EA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/tree-path.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"competitive-template.hpp\"\
    \n#pragma region kyopro_template\n#define Nyaan_template\n#include <immintrin.h>\n\
    #include <bits/stdc++.h>\n#define pb push_back\n#define eb emplace_back\n#define\
    \ fi first\n#define se second\n#define each(x, v) for (auto &x : v)\n#define all(v)\
    \ (v).begin(), (v).end()\n#define sz(v) ((int)(v).size())\n#define mem(a, val)\
    \ memset(a, val, sizeof(a))\n#define ini(...)   \\\n  int __VA_ARGS__; \\\n  in(__VA_ARGS__)\n\
    #define inl(...)         \\\n  long long __VA_ARGS__; \\\n  in(__VA_ARGS__)\n\
    #define ins(...)      \\\n  string __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define\
    \ inc(...)    \\\n  char __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define in2(s, t)\
    \                           \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\
    \n    in(s[i], t[i]);                         \\\n  }\n#define in3(s, t, u)  \
    \                      \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n  \
    \  in(s[i], t[i], u[i]);                   \\\n  }\n#define in4(s, t, u, v)  \
    \                   \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i],\
    \ t[i], u[i], v[i]);             \\\n  }\n#define rep(i, N) for (long long i =\
    \ 0; i < (long long)(N); i++)\n#define repr(i, N) for (long long i = (long long)(N)-1;\
    \ i >= 0; i--)\n#define rep1(i, N) for (long long i = 1; i <= (long long)(N);\
    \ i++)\n#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)\n\
    #define reg(i, a, b) for (long long i = (a); i < (b); i++)\n#define die(...) \
    \     \\\n  do {                \\\n    out(__VA_ARGS__); \\\n    return;    \
    \       \\\n  } while (0)\nusing namespace std;\nusing ll = long long;\ntemplate\
    \ <class T>\nusing V = vector<T>;\nusing vi = vector<int>;\nusing vl = vector<long\
    \ long>;\nusing vvi = vector<vector<int>>;\nusing vd = V<double>;\nusing vs =\
    \ V<string>;\nusing vvl = vector<vector<long long>>;\nusing P = pair<long long,\
    \ long long>;\nusing vp = vector<P>;\nusing pii = pair<int, int>;\nusing vpi =\
    \ vector<pair<int, int>>;\nconstexpr int inf = 1001001001;\nconstexpr long long\
    \ infLL = (1LL << 61) - 1;\ntemplate <typename T, typename U>\ninline bool amin(T\
    \ &x, U y) {\n  return (y < x) ? (x = y, true) : false;\n}\ntemplate <typename\
    \ T, typename U>\ninline bool amax(T &x, U y) {\n  return (x < y) ? (x = y, true)\
    \ : false;\n}\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n  os << p.first << \" \" << p.second;\n  return\
    \ os;\n}\ntemplate <typename T, typename U>\nistream &operator>>(istream &is,\
    \ pair<T, U> &p) {\n  is >> p.first >> p.second;\n  return is;\n}\ntemplate <typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n  int s = (int)v.size();\n\
    \  for (int i = 0; i < s; i++) os << (i ? \" \" : \"\") << v[i];\n  return os;\n\
    }\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T> &v) {\n \
    \ for (auto &x : v) is >> x;\n  return is;\n}\nvoid in() {}\ntemplate <typename\
    \ T, class... U>\nvoid in(T &t, U &... u) {\n  cin >> t;\n  in(u...);\n}\nvoid\
    \ out() { cout << \"\\n\"; }\ntemplate <typename T, class... U>\nvoid out(const\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"misc/rng.hpp\"\nusing namespace\
    \ std;\n\nnamespace my_rand {\n\n// [0, 2^64 - 1)\nuint64_t rng() {\n  static\
    \ uint64_t x_ =\n      uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                   chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count()) *\n      10150724397891781847ULL;\n  x_ ^= x_ <<\
    \ 7;\n  return x_ ^= x_ >> 9;\n}\n\n// [l, r)\nint64_t randint(int64_t l, int64_t\
    \ r) {\n  assert(l < r);\n  return l + rng() % (r - l);\n}\n\n// choose n numbers\
    \ from [l, r) without overlapping\nvector<int64_t> randset(int64_t l, int64_t\
    \ r, int64_t n) {\n  assert(l <= r && n <= r - l);\n  unordered_set<int64_t> s;\n\
    \  for (int64_t i = n; i; --i) {\n    int64_t m = randint(l, r + 1 - i);\n   \
    \ if (s.find(m) != s.end()) m = r - i;\n    s.insert(m);\n  }\n  vector<int64_t>\
    \ ret;\n  for (auto& x : s) ret.push_back(x);\n  return ret;\n}\n\n// [0.0, 1.0)\n\
    double rnd() {\n  union raw_cast {\n    double t;\n    uint64_t u;\n  };\n  constexpr\
    \ uint64_t p = uint64_t(1023 - 64) << 52;\n  return rnd() * ((raw_cast*)(&p))->t;\n\
    }\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n\
    \  for (int loop = 0; loop < 2; loop++)\n    for (int i = 0; i < n; i++) swap(v[i],\
    \ v[randint(0, n)]);\n}\n\n}  // namespace my_rand\n\nusing my_rand::randint;\n\
    using my_rand::randset;\nusing my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n\
    #line 3 \"tree/tree-query.hpp\"\nusing namespace std;\n\n#line 3 \"graph/graph-template.hpp\"\
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
    \ d;\n}\n#line 6 \"tree/tree-query.hpp\"\n\ntemplate <typename G>\nstruct Tree\
    \ {\n private:\n  G& g;\n  int root;\n  vector<vector<int>> bl;\n  vector<int>\
    \ dp;\n  void build() {\n    bl.resize(g.size());\n    dp.resize(g.size());\n\
    \    dfs(root, -1, 0);\n  }\n\n  void dfs(int c, int p, int _dp) {\n    dp[c]\
    \ = _dp;\n    for (int i = p, x = -1; i != -1;) {\n      bl[c].push_back(i);\n\
    \      i = ++x < (int)bl[i].size() ? bl[i][x] : -1;\n    }\n    for (auto& d :\
    \ g[c]) {\n      if (d == p) continue;\n      dfs(d, c, _dp + 1);\n    }\n  }\n\
    \n public:\n  Tree(G& _g, int _r = 0) : g(_g), root(_r) { build(); }\n\n  int\
    \ depth(int u) const { return dp[u]; }\n\n  int par(int u) const { return u ==\
    \ root ? -1 : bl[u][0]; }\n\n  int kth_ancestor(int u, int k) const {\n    if\
    \ (dp[u] < k) return -1;\n    for (int i = k ? __lg(k) : -1; i >= 0; --i) {\n\
    \      if ((k >> i) & 1) u = bl[u][i];\n    }\n    return u;\n  }\n\n  int nxt(int\
    \ s, int t) const {\n    if (dp[s] >= dp[t]) return par(s);\n    int u = kth_ancestor(t,\
    \ dp[t] - dp[s] - 1);\n    return bl[u][0] == s ? u : bl[s][0];\n  }\n\n  vector<int>\
    \ path(int s, int t) const {\n    vector<int> pre, suf;\n    while (dp[s] > dp[t])\
    \ {\n      pre.push_back(s);\n      s = bl[s][0];\n    }\n    while (dp[s] < dp[t])\
    \ {\n      suf.push_back(t);\n      t = bl[t][0];\n    }\n    while (s != t) {\n\
    \      pre.push_back(s);\n      suf.push_back(t);\n      s = bl[s][0];\n     \
    \ t = bl[t][0];\n    }\n    pre.push_back(s);\n    reverse(begin(suf), end(suf));\n\
    \    copy(begin(suf), end(suf), back_inserter(pre));\n    return pre;\n  }\n\n\
    \  int lca(int u, int v) {\n    if (dp[u] != dp[v]) {\n      if (dp[u] > dp[v])\
    \ swap(u, v);\n      v = kth_ancestor(v, dp[v] - dp[u]);\n    }\n    if (u ==\
    \ v) return u;\n    for (int i = __lg(dp[u]); i >= 0; --i) {\n      if (dp[u]\
    \ < (1 << i)) continue;\n      if (bl[u][i] != bl[v][i]) u = bl[u][i], v = bl[v][i];\n\
    \    }\n    return bl[u][0];\n  }\n};\n\n/**\n * @brief \u6728\u306B\u5BFE\u3059\
    \u308B\u4E00\u822C\u7684\u306A\u30AF\u30A8\u30EA\n * @docs docs/tree/tree-query.md\n\
    \ */\n#line 6 \"verify/verify-unit-test/tree-path.test.cpp\"\n\nvoid test(vvi&\
    \ g) {\n  cerr << g.size() << endl;\n  Tree<vvi> tree(g);\n  int N = sz(g);\n\
    \  rep(i, N) rep(j, N) {\n    vi p1 = tree.path(i, j);\n    vi p2{int(i)};\n \
    \   for (int k = i; k != j;) {\n      p2.push_back(k = tree.nxt(k, j));\n    }\n\
    \    assert(p1 == p2);\n    int l = i, ld = tree.depth(i);\n    each(x, p1) if\
    \ (amin(ld, tree.depth(x))) l = x;\n    assert(l == tree.lca(i, j));\n  }\n}\n\
    \nvoid solve() {\n  for (int N : vi{2, 3, 4, 5, 10, 100, 300}) {\n    vvi g(N);\n\
    \    rep1(i, N - 1) g[randint(0, i)].push_back(i);\n    test(g);\n  }\n\n  for\
    \ (int N : vi{2, 3, 4, 5, 10, 100, 200}) {\n    vvi g(N);\n    rep1(i, N - 1)\
    \ g[i - 1].push_back(i);\n    test(g);\n  }\n\n  int a, b;\n  cin >> a >> b;\n\
    \  cout << a + b << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../competitive-template.hpp\"\n#include \"../../misc/rng.hpp\"\n#include \"\
    ../../tree/tree-query.hpp\"\n\nvoid test(vvi& g) {\n  cerr << g.size() << endl;\n\
    \  Tree<vvi> tree(g);\n  int N = sz(g);\n  rep(i, N) rep(j, N) {\n    vi p1 =\
    \ tree.path(i, j);\n    vi p2{int(i)};\n    for (int k = i; k != j;) {\n     \
    \ p2.push_back(k = tree.nxt(k, j));\n    }\n    assert(p1 == p2);\n    int l =\
    \ i, ld = tree.depth(i);\n    each(x, p1) if (amin(ld, tree.depth(x))) l = x;\n\
    \    assert(l == tree.lca(i, j));\n  }\n}\n\nvoid solve() {\n  for (int N : vi{2,\
    \ 3, 4, 5, 10, 100, 300}) {\n    vvi g(N);\n    rep1(i, N - 1) g[randint(0, i)].push_back(i);\n\
    \    test(g);\n  }\n\n  for (int N : vi{2, 3, 4, 5, 10, 100, 200}) {\n    vvi\
    \ g(N);\n    rep1(i, N - 1) g[i - 1].push_back(i);\n    test(g);\n  }\n\n  int\
    \ a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n}\n"
  dependsOn:
  - competitive-template.hpp
  - misc/rng.hpp
  - tree/tree-query.hpp
  - graph/graph-template.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/tree-path.test.cpp
  requiredBy: []
  timestamp: '2020-11-30 18:57:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/tree-path.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/tree-path.test.cpp
- /verify/verify/verify-unit-test/tree-path.test.cpp.html
title: verify/verify-unit-test/tree-path.test.cpp
---
