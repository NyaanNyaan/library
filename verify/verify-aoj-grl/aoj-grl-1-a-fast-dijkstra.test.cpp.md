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
    path: graph/static-graph.hpp
    title: Static Graph
  - icon: ':heavy_check_mark:'
    path: shortest-path/dijkstra-fast.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u5B9A\u6570\u500D\u9AD8\u901F\
      \u5316)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp\"\
    \n#define PROBLEM \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"shortest-path/dijkstra-fast.hpp\"\
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
    \ docs/graph/static-graph.md\n */\n#line 7 \"shortest-path/dijkstra-fast.hpp\"\
    \n\ntemplate <typename T>\nvector<T> dijkstra(StaticGraph<T>& g, int start = 0)\
    \ {\n  vector<T> d(g.size(), T(-1));\n  RadixHeap<T, int> Q;\n  d[start] = 0;\n\
    \  Q.push(0, start);\n  while (!Q.empty()) {\n    auto p = Q.pop();\n    int u\
    \ = p.second;\n    if (d[u] < T(p.first)) continue;\n    T du = d[u];\n    for\
    \ (auto&& [v, c] : g[u]) {\n      if (d[v] == T(-1) || du + c < d[v]) {\n    \
    \    d[v] = du + c;\n        Q.push(d[v], v);\n      }\n    }\n  }\n  return d;\n\
    }\n\ntemplate <typename T>\nvector<pair<T, int>> dijkstra_restore(StaticGraph<T>&\
    \ g, int start = 0) {\n  vector<pair<T, int>> d(g.size(), {T(-1), -1});\n  RadixHeap<T,\
    \ int> Q;\n  d[start] = {0, -1};\n  Q.push(0, start);\n  while (!Q.empty()) {\n\
    \    auto p = Q.pop();\n    int u = p.second;\n    if (d[u].first < T(p.first))\
    \ continue;\n    T du = d[u].first;\n    for (auto&& [v, c] : g[u]) {\n      if\
    \ (d[v].first == T(-1) || du + c < d[v].first) {\n        d[v] = {du + c, u};\n\
    \        Q.push(du + c, v);\n      }\n    }\n  }\n  return d;\n}\n\n/*\n * @brief\
    \ \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u5B9A\u6570\u500D\u9AD8\u901F\u5316\
    )\n * @docs docs/shortest-path/dijkstra-fast.md\n **/\n#line 6 \"verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp\"\
    \n\nvoid solve() {\n  ini(N, E, S);\n  StaticGraph<int> g(N, E);\n  rep(i, E)\
    \ {\n    ini(s, t, d);\n    g.add_edge(s, t, d);\n  }\n  auto d = dijkstra(g,\
    \ S);\n  d.resize(N);\n  each(x, d) {\n    if (x == -1)\n      out(\"INF\");\n\
    \    else\n      out(x);\n  }\n}\n"
  code: "#define PROBLEM \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include \"../../competitive-template.hpp\"\n#include \"../../shortest-path/dijkstra-fast.hpp\"\
    \n\nvoid solve() {\n  ini(N, E, S);\n  StaticGraph<int> g(N, E);\n  rep(i, E)\
    \ {\n    ini(s, t, d);\n    g.add_edge(s, t, d);\n  }\n  auto d = dijkstra(g,\
    \ S);\n  d.resize(N);\n  each(x, d) {\n    if (x == -1)\n      out(\"INF\");\n\
    \    else\n      out(x);\n  }\n}\n"
  dependsOn:
  - competitive-template.hpp
  - shortest-path/dijkstra-fast.hpp
  - data-structure/radix-heap.hpp
  - graph/static-graph.hpp
  isVerificationFile: true
  path: verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp
  requiredBy: []
  timestamp: '2020-11-26 23:21:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp
- /verify/verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp.html
title: verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp
---
