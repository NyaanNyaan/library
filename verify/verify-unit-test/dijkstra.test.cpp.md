---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/radix-heap.hpp
    title: Radix Heap
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/static-graph.hpp
    title: Static Graph
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: shortest-path/dijkstra-fast.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u5B9A\u6570\u500D\u9AD8\u901F\
      \u5316)"
  - icon: ':heavy_check_mark:'
    path: shortest-path/dijkstra-radix-heap.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(Radix Heap)"
  - icon: ':heavy_check_mark:'
    path: shortest-path/dijkstra.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/dijkstra.test.cpp\"\n#define PROBLEM\
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
    }\n\n}  // namespace my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\n\
    using my_rand::rnd;\nusing my_rand::rng;\n#line 3 \"shortest-path/dijkstra-fast.hpp\"\
    \nusing namespace std;\n\n#line 3 \"data-structure/radix-heap.hpp\"\nusing namespace\
    \ std;\n\ntemplate <typename Key, typename Val>\nstruct RadixHeap {\n  using uint\
    \ = typename make_unsigned<Key>::type;\n  static constexpr int bit = sizeof(Key)\
    \ * 8;\n  array<vector<pair<uint, Val> >, bit + 1> vs;\n  array<uint, bit + 1>\
    \ ms;\n\n  int s;\n  uint last;\n\n  RadixHeap() : s(0), last(0) { fill(begin(ms),\
    \ end(ms), uint(-1)); }\n\n  bool empty() const { return s == 0; }\n\n  int size()\
    \ const { return s; }\n\n  __attribute__((target(\"lzcnt\"))) inline uint64_t\
    \ getbit(uint a) const {\n    return 64 - _lzcnt_u64(a);\n  }\n\n  void push(const\
    \ uint &key, const Val &val) {\n    s++;\n    uint64_t b = getbit(key ^ last);\n\
    \    vs[b].emplace_back(key, val);\n    ms[b] = min(key, ms[b]);\n  }\n\n  pair<uint,\
    \ Val> pop() {\n    if (ms[0] == uint(-1)) {\n      int idx = 1;\n      while\
    \ (ms[idx] == uint(-1)) idx++;\n      last = ms[idx];\n      for (auto &p : vs[idx])\
    \ {\n        uint64_t b = getbit(p.first ^ last);\n        vs[b].emplace_back(p);\n\
    \        ms[b] = min(p.first, ms[b]);\n      }\n      vs[idx].clear();\n     \
    \ ms[idx] = uint(-1);\n    }\n    --s;\n    auto res = vs[0].back();\n    vs[0].pop_back();\n\
    \    if (vs[0].empty()) ms[0] = uint(-1);\n    return res;\n  }\n};\n\n/**\n *\
    \ @brief Radix Heap\n * @docs docs/data-structure/radix-heap.md\n */\n#line 3\
    \ \"graph/static-graph.hpp\"\nusing namespace std;\n\nnamespace StaticGraphImpl\
    \ {\n\ntemplate <typename T, bool Cond = is_void<T>::value>\nstruct E;\ntemplate\
    \ <typename T>\nstruct E<T, false> {\n  int to;\n  T cost;\n  E() {}\n  E(const\
    \ int& v, const T& c) : to(v), cost(c) {}\n  operator int() const { return to;\
    \ }\n};\ntemplate <typename T>\nstruct E<T, true> {\n  int to;\n  E() {}\n  E(const\
    \ int& v) : to(v) {}\n  operator int() const { return to; }\n};\n\ntemplate <typename\
    \ T = void>\nstruct StaticGraph {\n private:\n  template <typename It>\n  struct\
    \ Es {\n    It b, e;\n    It begin() const { return b; }\n    It end() const {\
    \ return e; }\n    int size() const { return int(e - b); }\n  };\n  int N, M,\
    \ ec;\n  vector<int> head;\n  vector<pair<int, E<T>>> buf;\n  vector<E<T>> es;\n\
    \n  void build() {\n    partial_sum(begin(head), end(head), begin(head));\n  \
    \  es.resize(M);\n    for (auto&& [u, e] : buf) es[--head[u]] = e;\n  }\n\n public:\n\
    \  StaticGraph(int _n, int _m) : N(_n), M(_m), ec(0), head(N + 1, 0) {\n    buf.reserve(M);\n\
    \  }\n\n  template <typename... Args>\n  void add_edge(int u, Args&&... args)\
    \ {\n#pragma GCC diagnostic ignored \"-Wnarrowing\"\n    buf.emplace_back(u, E<T>{std::forward<Args>(args)...});\n\
    #pragma GCC diagnostic warning \"-Wnarrowing\"\n    ++head[u];\n    if ((int)buf.size()\
    \ == M) build();\n  }\n\n  Es<typename vector<E<T>>::iterator> operator[](int\
    \ u) {\n    return {begin(es) + head[u], begin(es) + head[u + 1]};\n  }\n  const\
    \ Es<typename vector<E<T>>::const_iterator> operator[](int u) const {\n    return\
    \ {begin(es) + head[u], begin(es) + head[u + 1]};\n  }\n  int size() const { return\
    \ N; }\n};\n\n}  // namespace StaticGraphImpl\n\nusing StaticGraphImpl::StaticGraph;\n\
    \n/**\n * @brief Static Graph\n */\n#line 7 \"shortest-path/dijkstra-fast.hpp\"\
    \n\ntemplate <typename T>\nstruct DijkstraGraph {\n  StaticGraph<T> g;\n\n  DijkstraGraph(int\
    \ _n, int _m) : g(_n, _m) {}\n\n  void add_edge(int u, int v, T c) { g.add_edge(u,\
    \ v, c); }\n\n  vector<T> dijkstra(int start = 0) {\n    vector<T> d(g.size(),\
    \ T(-1));\n    RadixHeap<T, int> Q;\n    d[start] = 0;\n    Q.push(0, start);\n\
    \    while (!Q.empty()) {\n      auto p = Q.pop();\n      int u = p.second;\n\
    \      if (d[u] < T(p.first)) continue;\n      T du = d[u];\n      for (auto&&\
    \ [v, c] : g[u]) {\n        if (d[v] == T(-1) || du + c < d[v]) {\n          d[v]\
    \ = du + c;\n          Q.push(d[v], v);\n        }\n      }\n    }\n    return\
    \ d;\n  }\n};\n\n/*\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u5B9A\
    \u6570\u500D\u9AD8\u901F\u5316)\n * @docs docs/shortest-path/dijkstra-fast.md\n\
    \ **/\n#line 3 \"shortest-path/dijkstra-radix-heap.hpp\"\nusing namespace std;\n\
    \n#line 3 \"graph/graph-template.hpp\"\nusing namespace std;\n\ntemplate <typename\
    \ T>\nstruct edge {\n  int src, to;\n  T cost;\n\n  edge(int _to, T _cost) : src(-1),\
    \ to(_to), cost(_cost) {}\n  edge(int _src, int _to, T _cost) : src(_src), to(_to),\
    \ cost(_cost) {}\n\n  edge &operator=(const int &x) {\n    to = x;\n    return\
    \ *this;\n  }\n\n  operator int() const { return to; }\n};\ntemplate <typename\
    \ T>\nusing Edges = vector<edge<T>>;\ntemplate <typename T>\nusing WeightedGraph\
    \ = vector<Edges<T>>;\nusing UnweightedGraph = vector<vector<int>>;\n\n// Input\
    \ of (Unweighted) Graph\nUnweightedGraph graph(int N, int M = -1, bool is_directed\
    \ = false,\n                      bool is_1origin = true) {\n  UnweightedGraph\
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
    \ d;\n}\n#line 7 \"shortest-path/dijkstra-radix-heap.hpp\"\n\n// unreachable ->\
    \ -1\ntemplate <typename T>\nvector<T> dijkstra_radix_heap(WeightedGraph<T> &g,\
    \ int start = 0) {\n  int N = (int)g.size();\n  vector<T> d(N, T(-1));\n  RadixHeap<T,\
    \ int> Q;\n  d[start] = 0;\n  Q.push(0, start);\n  while (!Q.empty()) {\n    auto\
    \ p = Q.pop();\n    int cur = p.second;\n    if (d[cur] < T(p.first)) continue;\n\
    \    for (auto dst : g[cur]) {\n      if (d[dst] == T(-1) || d[cur] + dst.cost\
    \ < d[dst]) {\n        d[dst] = d[cur] + dst.cost;\n        Q.push(d[dst], dst);\n\
    \      }\n    }\n  }\n  return d;\n}\n\n/*\n * @brief \u30C0\u30A4\u30AF\u30B9\
    \u30C8\u30E9\u6CD5(Radix Heap)\n * @docs docs/shortest-path/dijkstra-radix-heap.md\n\
    **/\n#line 3 \"shortest-path/dijkstra.hpp\"\nusing namespace std;\n\n#line 6 \"\
    shortest-path/dijkstra.hpp\"\n\n// unreachable -> -1\ntemplate <typename T>\n\
    vector<T> dijkstra(WeightedGraph<T> &g, int start = 0) {\n  using P = pair<T,\
    \ int>;\n  int N = (int)g.size();\n  vector<T> d(N, T(-1));\n  priority_queue<P,\
    \ vector<P>, greater<P> > Q;\n  d[start] = 0;\n  Q.emplace(0, start);\n  while\
    \ (!Q.empty()) {\n    P p = Q.top();\n    Q.pop();\n    int cur = p.second;\n\
    \    if (d[cur] < p.first) continue;\n    for (auto dst : g[cur]) {\n      if\
    \ (d[dst] == T(-1) || d[cur] + dst.cost < d[dst]) {\n        d[dst] = d[cur] +\
    \ dst.cost;\n        Q.emplace(d[dst], dst);\n      }\n    }\n  }\n  return d;\n\
    }\n\n/*\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n * @docs docs/shortest-path/dijkstra.md\n\
    **/\n#line 8 \"verify/verify-unit-test/dijkstra.test.cpp\"\n\ntemplate <int N,\
    \ int M, int C>\nvoid test() {\n  static_assert(N >= 1);\n  vector<tuple<int,\
    \ int, ll>> es;\n\n  // connectivity\n  mt19937_64 mt(rng());\n  vi ord(N - 1);\n\
    \  iota(all(ord), 1);\n  shuffle(all(ord), mt);\n  ord.insert(begin(ord), 0);\n\
    \  rep(i, N - 1) {\n    int u = ord[i], v = ord[i + 1];\n    ll c = randint(0,\
    \ C + 1);\n    es.emplace_back(u, v, c);\n  }\n  rep(_, M - (N - 1)) {\n    int\
    \ u, v;\n    do {\n      u = randint(0, N), v = randint(0, N);\n    } while (u\
    \ == v);\n    ll c = randint(0, C + 1);\n    es.emplace_back(u, v, c);\n  }\n\n\
    \  shuffle(all(es), mt);\n  WeightedGraph<ll> g(N);\n  DijkstraGraph<ll> dg(N,\
    \ M);\n  if (es.size() > M) es.resize(M);\n\n  for (auto&& [u, v, c] : es) {\n\
    \    g[u].emplace_back(v, c);\n    dg.add_edge(u, v, c);\n  }\n\n  vl d1, d2,\
    \ d3;\n\n  d1 = dijkstra(g);\n  d2 = dijkstra_radix_heap(g);\n  d3 = dg.dijkstra();\n\
    \n  if (N <= 20) {\n    trc(d1);\n    trc(d2);\n    trc(d3);\n  }\n  assert(d1\
    \ == d2);\n  assert(d1 == d3);\n}\n\nvoid solve() {\n  test<1, 0, 100>();\n  test<2,\
    \ 0, 100>();\n  test<2, 1, 100>();\n  test<3, 0, 100>();\n  test<3, 1, 100>();\n\
    \  test<3, 2, 100>();\n  test<TEN(2), TEN(1), 100>();\n  test<TEN(2), TEN(2) -\
    \ 1, 100>();\n  test<TEN(2), TEN(2) * 2, 100>();\n  test<TEN(3), TEN(3) * 2, 100>();\n\
    \  test<TEN(4), TEN(4) * 2, 100>();\n  test<TEN(5), TEN(5) * 2, 100>();\n  test<TEN(6),\
    \ TEN(6) * 2, 100>();\n\n  int n, m;\n  cin >> n >> m;\n  cout << n + m << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../competitive-template.hpp\"\n#include \"../../misc/rng.hpp\"\n#include \"\
    ../../shortest-path/dijkstra-fast.hpp\"\n#include \"../../shortest-path/dijkstra-radix-heap.hpp\"\
    \n#include \"../../shortest-path/dijkstra.hpp\"\n\ntemplate <int N, int M, int\
    \ C>\nvoid test() {\n  static_assert(N >= 1);\n  vector<tuple<int, int, ll>> es;\n\
    \n  // connectivity\n  mt19937_64 mt(rng());\n  vi ord(N - 1);\n  iota(all(ord),\
    \ 1);\n  shuffle(all(ord), mt);\n  ord.insert(begin(ord), 0);\n  rep(i, N - 1)\
    \ {\n    int u = ord[i], v = ord[i + 1];\n    ll c = randint(0, C + 1);\n    es.emplace_back(u,\
    \ v, c);\n  }\n  rep(_, M - (N - 1)) {\n    int u, v;\n    do {\n      u = randint(0,\
    \ N), v = randint(0, N);\n    } while (u == v);\n    ll c = randint(0, C + 1);\n\
    \    es.emplace_back(u, v, c);\n  }\n\n  shuffle(all(es), mt);\n  WeightedGraph<ll>\
    \ g(N);\n  DijkstraGraph<ll> dg(N, M);\n  if (es.size() > M) es.resize(M);\n\n\
    \  for (auto&& [u, v, c] : es) {\n    g[u].emplace_back(v, c);\n    dg.add_edge(u,\
    \ v, c);\n  }\n\n  vl d1, d2, d3;\n\n  d1 = dijkstra(g);\n  d2 = dijkstra_radix_heap(g);\n\
    \  d3 = dg.dijkstra();\n\n  if (N <= 20) {\n    trc(d1);\n    trc(d2);\n    trc(d3);\n\
    \  }\n  assert(d1 == d2);\n  assert(d1 == d3);\n}\n\nvoid solve() {\n  test<1,\
    \ 0, 100>();\n  test<2, 0, 100>();\n  test<2, 1, 100>();\n  test<3, 0, 100>();\n\
    \  test<3, 1, 100>();\n  test<3, 2, 100>();\n  test<TEN(2), TEN(1), 100>();\n\
    \  test<TEN(2), TEN(2) - 1, 100>();\n  test<TEN(2), TEN(2) * 2, 100>();\n  test<TEN(3),\
    \ TEN(3) * 2, 100>();\n  test<TEN(4), TEN(4) * 2, 100>();\n  test<TEN(5), TEN(5)\
    \ * 2, 100>();\n  test<TEN(6), TEN(6) * 2, 100>();\n\n  int n, m;\n  cin >> n\
    \ >> m;\n  cout << n + m << endl;\n}"
  dependsOn:
  - competitive-template.hpp
  - misc/rng.hpp
  - shortest-path/dijkstra-fast.hpp
  - data-structure/radix-heap.hpp
  - graph/static-graph.hpp
  - shortest-path/dijkstra-radix-heap.hpp
  - graph/graph-template.hpp
  - shortest-path/dijkstra.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2020-11-26 16:49:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/dijkstra.test.cpp
- /verify/verify/verify-unit-test/dijkstra.test.cpp.html
title: verify/verify-unit-test/dijkstra.test.cpp
---
