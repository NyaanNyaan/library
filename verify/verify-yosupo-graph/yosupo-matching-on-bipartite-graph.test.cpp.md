---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: flow/flow-on-bipartite-graph.hpp
    title: flow/flow-on-bipartite-graph.hpp
  - icon: ':question:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n#line\
    \ 2 \"atcoder/maxflow.hpp\"\n#include <algorithm>\n#include <cassert>\n#include\
    \ <limits>\n#include <queue>\n#include <vector>\n\n#line 3 \"atcoder/internal_queue.hpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\ntemplate <class T>\nstruct\
    \ simple_queue {\n  std::vector<T> payload;\n  int pos = 0;\n  void reserve(int\
    \ n) { payload.reserve(n); }\n  int size() const { return int(payload.size())\
    \ - pos; }\n  bool empty() const { return pos == int(payload.size()); }\n  void\
    \ push(const T& t) { payload.push_back(t); }\n  T& front() { return payload[pos];\
    \ }\n  void clear() {\n    payload.clear();\n    pos = 0;\n  }\n  void pop() {\
    \ pos++; }\n};\n\n}  // namespace internal\n\n}  // namespace atcoder\n#line 9\
    \ \"atcoder/maxflow.hpp\"\n\nnamespace atcoder {\n\ntemplate <class Cap>\nstruct\
    \ mf_graph {\n public:\n  mf_graph() : _n(0) {}\n  mf_graph(int n) : _n(n), g(n)\
    \ {}\n\n  virtual int add_edge(int from, int to, Cap cap) {\n    assert(0 <= from\
    \ && from < _n);\n    assert(0 <= to && to < _n);\n    assert(0 <= cap);\n   \
    \ int m = int(pos.size());\n    pos.push_back({from, int(g[from].size())});\n\
    \    g[from].push_back(_edge{to, int(g[to].size()), cap});\n    g[to].push_back(_edge{from,\
    \ int(g[from].size()) - 1, 0});\n    return m;\n  }\n\n  struct edge {\n    int\
    \ from, to;\n    Cap cap, flow;\n  };\n\n  edge get_edge(int i) {\n    int m =\
    \ int(pos.size());\n    assert(0 <= i && i < m);\n    auto _e = g[pos[i].first][pos[i].second];\n\
    \    auto _re = g[_e.to][_e.rev];\n    return edge{pos[i].first, _e.to, _e.cap\
    \ + _re.cap, _re.cap};\n  }\n\n  std::vector<edge> edges() {\n    int m = int(pos.size());\n\
    \    std::vector<edge> result;\n    for (int i = 0; i < m; i++) {\n      result.push_back(get_edge(i));\n\
    \    }\n    return result;\n  }\n\n  void change_edge(int i, Cap new_cap, Cap\
    \ new_flow) {\n    int m = int(pos.size());\n    assert(0 <= i && i < m);\n  \
    \  assert(0 <= new_flow && new_flow <= new_cap);\n    auto& _e = g[pos[i].first][pos[i].second];\n\
    \    auto& _re = g[_e.to][_e.rev];\n    _e.cap = new_cap - new_flow;\n    _re.cap\
    \ = new_flow;\n  }\n\n  Cap flow(int s, int t) { return flow(s, t, std::numeric_limits<Cap>::max());\
    \ }\n  Cap flow(int s, int t, Cap flow_limit) {\n    assert(0 <= s && s < _n);\n\
    \    assert(0 <= t && t < _n);\n\n    std::vector<int> level(_n), iter(_n);\n\
    \    internal::simple_queue<int> que;\n\n    auto bfs = [&]() {\n      std::fill(level.begin(),\
    \ level.end(), -1);\n      level[s] = 0;\n      que.clear();\n      que.push(s);\n\
    \      while (!que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \        for (auto &e : g[v]) {\n          if (e.cap == 0 || level[e.to] >= 0)\
    \ continue;\n          level[e.to] = level[v] + 1;\n          if (e.to == t) return;\n\
    \          que.push(e.to);\n        }\n      }\n    };\n    auto dfs = [&](auto\
    \ self, int v, Cap up) {\n      if (v == s) return up;\n      Cap res = 0;\n \
    \     int level_v = level[v];\n      for (int& i = iter[v]; i < int(g[v].size());\
    \ i++) {\n        _edge& e = g[v][i];\n        if (level_v <= level[e.to] || g[e.to][e.rev].cap\
    \ == 0) continue;\n        Cap d = self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));\n\
    \        if (d <= 0) continue;\n        g[v][i].cap += d;\n        g[e.to][e.rev].cap\
    \ -= d;\n        res += d;\n        if (res == up) break;\n      }\n      return\
    \ res;\n    };\n\n    Cap flow = 0;\n    while (flow < flow_limit) {\n      bfs();\n\
    \      if (level[t] == -1) break;\n      std::fill(iter.begin(), iter.end(), 0);\n\
    \      while (flow < flow_limit) {\n        Cap f = dfs(dfs, t, flow_limit - flow);\n\
    \        if (!f) break;\n        flow += f;\n      }\n    }\n    return flow;\n\
    \  }\n\n  std::vector<bool> min_cut(int s) {\n    std::vector<bool> visited(_n);\n\
    \    internal::simple_queue<int> que;\n    que.push(s);\n    while (!que.empty())\
    \ {\n      int p = que.front();\n      que.pop();\n      visited[p] = true;\n\
    \      for (auto e : g[p]) {\n        if (e.cap && !visited[e.to]) {\n       \
    \   visited[e.to] = true;\n          que.push(e.to);\n        }\n      }\n   \
    \ }\n    return visited;\n  }\n\n private:\n  int _n;\n  struct _edge {\n    int\
    \ to, rev;\n    Cap cap;\n  };\n  std::vector<std::pair<int, int>> pos;\n  std::vector<std::vector<_edge>>\
    \ g;\n};\n\n}  // namespace atcoder\n\nusing namespace atcoder;\n#line 1 \"competitive-template.hpp\"\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 4 \"flow/flow-on-bipartite-graph.hpp\"\
    \n\nnamespace BipartiteGraph {\nusing namespace atcoder;\ntemplate <typename Cap>\n\
    struct Matching : mf_graph<Cap> {\n  int L, R, s, t;\n\n  explicit Matching(int\
    \ N, int M)\n      : mf_graph<Cap>(N + M + 2), L(N), R(M), s(N + M), t(N + M +\
    \ 1) {\n    for (int i = 0; i < L; i++) mf_graph<Cap>::add_edge(s, i, 1);\n  \
    \  for (int i = 0; i < R; i++) mf_graph<Cap>::add_edge(i + L, t, 1);\n  }\n\n\
    \  int add_edge(int n, int m, int cap = 1) override {\n    assert(0 <= n && n\
    \ < L);\n    assert(0 <= m && m < R);\n    return mf_graph<Cap>::add_edge(n, m\
    \ + L, cap);\n  }\n\n  Cap flow() { return mf_graph<Cap>::flow(s, t); }\n\n  vector<pair<int,\
    \ int>> edges() {\n    auto es = mf_graph<Cap>::edges();\n    vector<pair<int,\
    \ int>> ret;\n    for (auto &e : es) {\n      if (e.flow > 0 && e.from != s &&\
    \ e.to != t) {\n        ret.emplace_back(e.from, e.to - L);\n      }\n    }\n\
    \    return ret;\n  }\n};\n\n}  // namespace BipartiteGraph\n#line 3 \"misc/fastio.hpp\"\
    \nusing namespace std;\n\nnamespace fastio {\nstatic constexpr int SZ = 1 << 17;\n\
    char ibuf[SZ], obuf[SZ];\nint pil = 0, pir = 0, por = 0;\n\nstruct Pre {\n  char\
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
    #line 7 \"verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp\"\
    \n\nvoid solve() {\n  int L, R, M;\n  rd(L, R, M);\n  BipartiteGraph::Matching<int>\
    \ graph(L, R);\n  rep(i, M) {\n    int u, v;\n    rd(u, v);\n    graph.add_edge(u,\
    \ v);\n  }\n  wtn(graph.flow());\n  auto es = graph.edges();\n  for (auto &e :\
    \ es) {\n    wt(e.first, ' ', e.second, '\\n');\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include \"../../atcoder/maxflow.hpp\"\n#include \"../../competitive-template.hpp\"\
    \n#include \"../../flow/flow-on-bipartite-graph.hpp\"\n#include \"../../misc/fastio.hpp\"\
    \n\nvoid solve() {\n  int L, R, M;\n  rd(L, R, M);\n  BipartiteGraph::Matching<int>\
    \ graph(L, R);\n  rep(i, M) {\n    int u, v;\n    rd(u, v);\n    graph.add_edge(u,\
    \ v);\n  }\n  wtn(graph.flow());\n  auto es = graph.edges();\n  for (auto &e :\
    \ es) {\n    wt(e.first, ' ', e.second, '\\n');\n  }\n}"
  dependsOn:
  - competitive-template.hpp
  - flow/flow-on-bipartite-graph.hpp
  - misc/fastio.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp
  requiredBy: []
  timestamp: '2020-09-15 23:09:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp
- /verify/verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp.html
title: verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp
---
