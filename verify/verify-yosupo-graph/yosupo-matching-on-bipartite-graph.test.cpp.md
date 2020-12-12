---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: flow/flow-on-bipartite-graph.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u30D5\u30ED\u30FC"
  - icon: ':question:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':question:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':question:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':question:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \ g;\n};\n\n}  // namespace atcoder\n\nusing namespace atcoder;\n#line 2 \"template/template.hpp\"\
    \nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\n#line 8 \"\
    template/template.hpp\"\n#include <array>\n#include <bitset>\n#line 11 \"template/template.hpp\"\
    \n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n\
    #include <cinttypes>\n#include <climits>\n#include <cmath>\n#include <complex>\n\
    #include <csetjmp>\n#include <csignal>\n#include <cstdarg>\n#include <cstddef>\n\
    #include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n\
    #include <ctime>\n#include <deque>\n#include <exception>\n#include <forward_list>\n\
    #include <fstream>\n#include <functional>\n#include <initializer_list>\n#include\
    \ <iomanip>\n#include <ios>\n#include <iosfwd>\n#include <iostream>\n#include\
    \ <istream>\n#include <iterator>\n#line 41 \"template/template.hpp\"\n#include\
    \ <list>\n#include <locale>\n#include <map>\n#include <memory>\n#include <new>\n\
    #include <numeric>\n#include <ostream>\n#line 49 \"template/template.hpp\"\n#include\
    \ <random>\n#include <ratio>\n#include <regex>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <stdexcept>\n#include <streambuf>\n#include <string>\n\
    #include <system_error>\n#include <tuple>\n#include <type_traits>\n#include <typeinfo>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <valarray>\n#line 67 \"template/template.hpp\"\n\n// utility\n#line 1 \"template/util.hpp\"\
    \nnamespace Nyaan {\nusing ll = long long;\nusing i64 = long long;\nusing u64\
    \ = unsigned long long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    \ntemplate <typename T>\nusing V = vector<T>;\ntemplate <typename T>\nusing VV\
    \ = vector<vector<T>>;\nusing vi = vector<int>;\nusing vl = vector<long long>;\n\
    using vd = V<double>;\nusing vs = V<string>;\nusing vvi = vector<vector<int>>;\n\
    using vvl = vector<vector<long long>>;\n\ntemplate <typename T, typename U>\n\
    struct P : pair<T, U> {\n  template <typename... Args>\n  P(Args... args) : pair<T,\
    \ U>(args...) {}\n\n  using pair<T, U>::first;\n  using pair<T, U>::second;\n\n\
    \  T &x() { return first; }\n  const T &x() const { return first; }\n  U &y()\
    \ { return second; }\n  const U &y() const { return second; }\n\n  P &operator+=(const\
    \ P &r) {\n    first += r.first;\n    second += r.second;\n    return *this;\n\
    \  }\n  P &operator-=(const P &r) {\n    first -= r.first;\n    second -= r.second;\n\
    \    return *this;\n  }\n  P &operator*=(const P &r) {\n    first *= r.first;\n\
    \    second *= r.second;\n    return *this;\n  }\n  P operator+(const P &r) const\
    \ { return P(*this) += r; }\n  P operator-(const P &r) const { return P(*this)\
    \ -= r; }\n  P operator*(const P &r) const { return P(*this) *= r; }\n};\n\nusing\
    \ pl = P<ll, ll>;\nusing pi = P<int, int>;\nusing vp = V<pl>;\n\nconstexpr int\
    \ inf = 1001001001;\nconstexpr long long infLL = 4004004004004004004LL;\n\ntemplate\
    \ <typename T>\nint sz(const T &t) {\n  return t.size();\n}\ntemplate <typename\
    \ T, size_t N>\nvoid mem(T (&a)[N], int c) {\n  memset(a, c, sizeof(T) * N);\n\
    }\n\ntemplate <typename T, typename U>\ninline bool amin(T &x, U y) {\n  return\
    \ (y < x) ? (x = y, true) : false;\n}\ntemplate <typename T, typename U>\ninline\
    \ bool amax(T &x, U y) {\n  return (x < y) ? (x = y, true) : false;\n}\n\ntemplate\
    \ <typename T>\nint lb(const vector<T> &v, const T &a) {\n  return lower_bound(begin(v),\
    \ end(v), a) - begin(v);\n}\ntemplate <typename T>\nint ub(const vector<T> &v,\
    \ const T &a) {\n  return upper_bound(begin(v), end(v), a) - begin(v);\n}\n\n\
    constexpr long long TEN(int n) {\n  long long ret = 1, x = 10;\n  for (; n; x\
    \ *= x, n >>= 1) ret *= (n & 1 ? x : 1);\n  return ret;\n}\n\ntemplate <typename\
    \ T, typename U>\npair<T, U> mkp(const T &t, const U &u) {\n  return make_pair(t,\
    \ u);\n}\n\ntemplate <typename T>\nvector<T> mkrui(const vector<T> &v, bool rev\
    \ = false) {\n  vector<T> ret(v.size() + 1);\n  if (rev) {\n    for (int i = int(v.size())\
    \ - 1; i >= 0; i--) ret[i] = v[i] + ret[i + 1];\n  } else {\n    for (int i =\
    \ 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];\n  }\n  return ret;\n\
    };\n\ntemplate <typename T>\nvector<T> mkuni(const vector<T> &v) {\n  vector<T>\
    \ ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(), ret.end()),\
    \ ret.end());\n  return ret;\n}\n\ntemplate <typename F>\nvector<int> mkord(int\
    \ N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n  sort(begin(ord),\
    \ end(ord), f);\n  return ord;\n}\n\ntemplate <typename T>\nvector<T> reord(const\
    \ vector<T> &v, const vector<T> &ord) {\n  int N = v.size();\n  vector<T> ret(N);\n\
    \  for (int i = 0; i < N; i++) ret[i] = v[ord[i]];\n  return ret;\n};\n\ntemplate\
    \ <typename T = int>\nvector<T> mkiota(int N) {\n  vector<T> ret(N);\n  iota(begin(ret),\
    \ end(ret), 0);\n  return ret;\n}\n\ntemplate <typename T>\nvector<int> mkinv(vector<T>\
    \ &v, int max_val = -1) {\n  if (max_val < (int)v.size()) max_val = v.size() -\
    \ 1;\n  vector<int> inv(max_val + 1, -1);\n  for (int i = 0; i < (int)v.size();\
    \ i++) inv[v[i]] = i;\n  return inv;\n}\n\n}  // namespace Nyaan\n#line 70 \"\
    template/template.hpp\"\n\n// bit operation\n#line 1 \"template/bitop.hpp\"\n\
    namespace Nyaan {\n\n__attribute__((target(\"popcnt\"))) inline int popcnt(const\
    \ u64 &a) {\n  return _mm_popcnt_u64(a);\n}\n\n__attribute__((target(\"bmi\")))\
    \ inline int lsb(const u64 &a) {\n  return _tzcnt_u64(a);\n}\n__attribute__((target(\"\
    bmi\"))) inline int ctz(const u64 &a) {\n  return _tzcnt_u64(a);\n}\n\n__attribute__((target(\"\
    lzcnt\"))) inline int msb(const u64 &a) {\n  return 63 - _lzcnt_u64(a);\n}\n__attribute__((target(\"\
    lzcnt\"))) inline int clz64(const u64 &a) {\n  return _lzcnt_u64(a);\n}\n\ntemplate\
    \ <typename T>\ninline int gbit(const T &a, int i) {\n  return (a >> i) & 1;\n\
    }\ntemplate <typename T>\ninline void sbit(T &a, int i, bool b) {\n  a ^= (gbit(a,\
    \ i) == b ? 0 : (T(b) << i));\n}\n\nconstexpr long long PW(int n) { return 1LL\
    \ << n; }\n\nconstexpr long long MSK(int n) { return (1LL << n) - 1; }\n\n}  //\
    \ namespace Nyaan\n#line 73 \"template/template.hpp\"\n\n// inout\n#line 1 \"\
    template/inout.hpp\"\nnamespace Nyaan {\n\ntemplate <typename T, typename U>\n\
    ostream &operator<<(ostream &os, const pair<T, U> &p) {\n  os << p.first << \"\
    \ \" << p.second;\n  return os;\n}\ntemplate <typename T, typename U>\nistream\
    \ &operator>>(istream &is, pair<T, U> &p) {\n  is >> p.first >> p.second;\n  return\
    \ is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const vector<T>\
    \ &v) {\n  int s = (int)v.size();\n  for (int i = 0; i < s; i++) os << (i ? \"\
    \ \" : \"\") << v[i];\n  return os;\n}\ntemplate <typename T>\nistream &operator>>(istream\
    \ &is, vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return is;\n}\n\nvoid\
    \ in() {}\ntemplate <typename T, class... U>\nvoid in(T &t, U &... u) {\n  cin\
    \ >> t;\n  in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename\
    \ T, class... U, char sep = ' '>\nvoid out(const T &t, const U &... u) {\n  cout\
    \ << t;\n  if (sizeof...(u)) cout << sep;\n  out(u...);\n}\n\nvoid outr() {}\n\
    template <typename T, class... U, char sep = ' '>\nvoid outr(const T &t, const\
    \ U &... u) {\n  cout << t;\n  outr(u...);\n}\n\nstruct IoSetupNya {\n  IoSetupNya()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(15);\n    cerr << fixed << setprecision(7);\n  }\n} iosetupnya;\n\
    \n}  // namespace Nyaan\n#line 76 \"template/template.hpp\"\n\n// debug\n#line\
    \ 1 \"template/debug.hpp\"\nnamespace DebugImpl {\n\ntemplate <typename U, typename\
    \ = void>\nstruct is_specialize : false_type {};\ntemplate <typename U>\nstruct\
    \ is_specialize<\n    U, typename conditional<false, typename U::iterator, void>::type>\n\
    \    : true_type {};\ntemplate <typename U>\nstruct is_specialize<\n    U, typename\
    \ conditional<false, decltype(U::first), void>::type>\n    : true_type {};\ntemplate\
    \ <typename U>\nstruct is_specialize<U, enable_if_t<is_integral<U>::value, void>>\
    \ : true_type {\n};\n\nvoid dump(const char& t) { cerr << t; }\n\nvoid dump(const\
    \ string& t) { cerr << t; }\n\ntemplate <typename U,\n          enable_if_t<!is_specialize<U>::value,\
    \ nullptr_t> = nullptr>\nvoid dump(const U& t) {\n  cerr << t;\n}\n\ntemplate\
    \ <typename T>\nvoid dump(const T& t, enable_if_t<is_integral<T>::value>* = nullptr)\
    \ {\n  string res;\n  if (t == Nyaan::inf) res = \"inf\";\n  if (is_signed<T>::value)\n\
    \    if (t == -Nyaan::inf) res = \"-inf\";\n  if (sizeof(T) == 8) {\n    if (t\
    \ == Nyaan::infLL) res = \"inf\";\n    if (is_signed<T>::value)\n      if (t ==\
    \ -Nyaan::infLL) res = \"-inf\";\n  }\n  if (res.empty()) res = to_string(t);\n\
    \  cerr << res;\n}\n\ntemplate <typename T, typename U>\nvoid dump(const pair<T,\
    \ U>&);\ntemplate <typename T>\nvoid dump(const pair<T*, int>&);\n\ntemplate <typename\
    \ T>\nvoid dump(const T& t,\n          enable_if_t<!is_void<typename T::iterator>::value>*\
    \ = nullptr) {\n  cerr << \"[ \";\n  for (auto it = t.begin(); it != t.end();)\
    \ {\n    dump(*it);\n    cerr << (++it == t.end() ? \"\" : \", \");\n  }\n  cerr\
    \ << \" ]\";\n}\n\ntemplate <typename T, typename U>\nvoid dump(const pair<T,\
    \ U>& t) {\n  cerr << \"( \";\n  dump(t.first);\n  cerr << \", \";\n  dump(t.second);\n\
    \  cerr << \" )\";\n}\n\ntemplate <typename T>\nvoid dump(const pair<T*, int>&\
    \ t) {\n  cerr << \"[ \";\n  for (int i = 0; i < t.second; i++) {\n    dump(t.first[i]);\n\
    \    cerr << (i == t.second - 1 ? \"\" : \", \");\n  }\n  cerr << \" ]\";\n}\n\
    \nvoid trace() { cerr << endl; }\ntemplate <typename Head, typename... Tail>\n\
    void trace(Head&& head, Tail&&... tail) {\n  cerr << \" \";\n  dump(head);\n \
    \ if (sizeof...(tail) != 0) cerr << \",\";\n  trace(forward<Tail>(tail)...);\n\
    }\n\n}  // namespace DebugImpl\n\n#ifdef NyaanDebug\n#define trc(...)        \
    \                    \\\n  do {                                      \\\n    cerr\
    \ << \"## \" << #__VA_ARGS__ << \" = \"; \\\n    DebugImpl::trace(__VA_ARGS__);\
    \          \\\n  } while (0)\n#else\n#define trc(...)\n#endif\n#line 79 \"template/template.hpp\"\
    \n\n// macro\n#line 1 \"template/macro.hpp\"\n#define each(x, v) for (auto&& x\
    \ : v)\n#define each2(x, y, v) for (auto&& [x, y] : v)\n#define all(v) (v).begin(),\
    \ (v).end()\n#define rep(i, N) for (long long i = 0; i < (long long)(N); i++)\n\
    #define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)\n#define\
    \ rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)\n#define repr1(i,\
    \ N) for (long long i = (N); (long long)(i) > 0; i--)\n#define reg(i, a, b) for\
    \ (long long i = (a); i < (b); i++)\n#define regr(i, a, b) for (long long i =\
    \ (b)-1; i >= (a); i--)\n#define repc(i, a, cond) for (long long i = (a); (cond);\
    \ i++)\n#define enm(i, val, vec)                                  \\\n  for (long\
    \ long i = 0; i < (long long)(vec).size(); i++) \\\n    if (auto& val = vec[i];\
    \ false)                        \\\n      ;                                  \
    \                 \\\n    else\n\n#define ini(...)   \\\n  int __VA_ARGS__; \\\
    \n  in(__VA_ARGS__)\n#define inl(...)         \\\n  long long __VA_ARGS__; \\\n\
    \  in(__VA_ARGS__)\n#define ins(...)      \\\n  string __VA_ARGS__; \\\n  in(__VA_ARGS__)\n\
    #define inc(...)    \\\n  char __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define in2(s,\
    \ t)                           \\\n  for (int i = 0; i < (int)s.size(); i++) {\
    \ \\\n    in(s[i], t[i]);                         \\\n  }\n#define in3(s, t, u)\
    \                        \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n\
    \    in(s[i], t[i], u[i]);                   \\\n  }\n#define in4(s, t, u, v)\
    \                     \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n   \
    \ in(s[i], t[i], u[i], v[i]);             \\\n  }\n\n#define die(...)        \
    \     \\\n  do {                       \\\n    Nyaan::out(__VA_ARGS__); \\\n \
    \   return;                  \\\n  } while (0)\n#line 82 \"template/template.hpp\"\
    \n\nnamespace Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line\
    \ 2 \"flow/flow-on-bipartite-graph.hpp\"\n\n#line 4 \"flow/flow-on-bipartite-graph.hpp\"\
    \n\nnamespace BipartiteGraphImpl {\nusing namespace atcoder;\nstruct BipartiteGraph\
    \ : mf_graph<long long> {\n  int L, R, s, t;\n\n  explicit BipartiteGraph(int\
    \ N, int M)\n      : mf_graph<long long>(N + M + 2), L(N), R(M), s(N + M), t(N\
    \ + M + 1) {\n    for (int i = 0; i < L; i++) mf_graph<long long>::add_edge(s,\
    \ i, 1);\n    for (int i = 0; i < R; i++) mf_graph<long long>::add_edge(i + L,\
    \ t, 1);\n  }\n\n  int add_edge(int n, int m, long long cap = 1) override {\n\
    \    assert(0 <= n && n < L);\n    assert(0 <= m && m < R);\n    return mf_graph<long\
    \ long>::add_edge(n, m + L, cap);\n  }\n\n  long long flow() { return mf_graph<long\
    \ long>::flow(s, t); }\n\n  vector<pair<int, int>> MaximumMatching() {\n    auto\
    \ es = mf_graph<long long>::edges();\n    vector<pair<int, int>> ret;\n    for\
    \ (auto &e : es) {\n      if (e.flow > 0 && e.from != s && e.to != t) {\n    \
    \    ret.emplace_back(e.from, e.to - L);\n      }\n    }\n    return ret;\n  }\n\
    \n  // call after calclating flow !\n  pair<vector<int>, vector<int>> MinimumVertexCover()\
    \ {\n    auto colored = PreCalc();\n    vector<int> nl, nr;\n    for (int i =\
    \ 0; i < L; i++)\n      if (!colored[i]) nl.push_back(i);\n    for (int i = 0;\
    \ i < R; i++)\n      if (colored[i + L]) nr.push_back(i);\n    return make_pair(nl,\
    \ nr);\n  }\n\n  // call after calclating flow !\n  pair<vector<int>, vector<int>>\
    \ MaximumIndependentSet() {\n    auto colored = PreCalc();\n    vector<int> nl,\
    \ nr;\n    for (int i = 0; i < L; i++)\n      if (colored[i]) nl.push_back(i);\n\
    \    for (int i = 0; i < R; i++)\n      if (!colored[i + L]) nr.push_back(i);\n\
    \    return make_pair(nl, nr);\n  }\n\n private:\n  vector<bool> PreCalc() {\n\
    \    vector<vector<int>> ag(L + R);\n    vector<bool> used(L, false);\n    for\
    \ (auto &e : mf_graph<long long>::edges()) {\n      if (e.from == s || e.to ==\
    \ t) continue;\n      if (e.flow > 0) {\n        ag[e.to].push_back(e.from);\n\
    \        used[e.from] = true;\n      } else {\n        ag[e.from].push_back(e.to);\n\
    \      }\n    }\n    vector<bool> colored(L + R, false);\n    auto dfs = [&](auto\
    \ rc, int cur) -> void {\n      for (auto &d : ag[cur]) {\n        if (!colored[d])\
    \ colored[d] = true, rc(rc, d);\n      }\n    };\n    for (int i = 0; i < L; i++)\n\
    \      if (!used[i]) colored[i] = true, dfs(dfs, i);\n    return colored;\n  }\n\
    };\n\n}  // namespace BipartiteGraphImpl\n\nusing BipartiteGraphImpl::BipartiteGraph;\n\
    \n/**\n * @brief \u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u30D5\u30ED\u30FC\n * @docs\
    \ docs/flow/flow-on-bipartite-graph.md\n */\n#line 2 \"misc/fastio.hpp\"\n\n\n\
    \nnamespace fastio {\nstatic constexpr int SZ = 1 << 17;\nchar ibuf[SZ], obuf[SZ];\n\
    int pil = 0, pir = 0, por = 0;\n\nstruct Pre {\n  char num[40000];\n  constexpr\
    \ Pre() : num() {\n    for (int i = 0; i < 10000; i++) {\n      int n = i;\n \
    \     for (int j = 3; j >= 0; j--) {\n        num[i * 4 + j] = n % 10 + '0';\n\
    \        n /= 10;\n      }\n    }\n  }\n} constexpr pre;\n\ninline void load()\
    \ {\n  memcpy(ibuf, ibuf + pil, pir - pil);\n  pir = pir - pil + fread(ibuf +\
    \ pir - pil, 1, SZ - pir + pil, stdin);\n  pil = 0;\n}\ninline void flush() {\n\
    \  fwrite(obuf, 1, por, stdout);\n  por = 0;\n}\n\ninline void rd(char& c) { c\
    \ = ibuf[pil++]; }\ntemplate <typename T>\ninline void rd(T& x) {\n  if (pil +\
    \ 32 > pir) load();\n  char c;\n  do\n    c = ibuf[pil++];\n  while (c < '-');\n\
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
    #line 7 \"verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve() {\n  int L, R, M;\n  rd(L, R, M);\n\
    \  BipartiteGraph::Matching<int> graph(L, R);\n  rep(i, M) {\n    int u, v;\n\
    \    rd(u, v);\n    graph.add_edge(u, v);\n  }\n  wtn(graph.flow());\n  auto es\
    \ = graph.edges();\n  for (auto &e : es) {\n    wt(e.first, ' ', e.second, '\\\
    n');\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include \"../../atcoder/maxflow.hpp\"\n#include \"../../template/template.hpp\"\
    \n#include \"../../flow/flow-on-bipartite-graph.hpp\"\n#include \"../../misc/fastio.hpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve() {\n  int L, R, M;\n  rd(L, R, M);\n\
    \  BipartiteGraph::Matching<int> graph(L, R);\n  rep(i, M) {\n    int u, v;\n\
    \    rd(u, v);\n    graph.add_edge(u, v);\n  }\n  wtn(graph.flow());\n  auto es\
    \ = graph.edges();\n  for (auto &e : es) {\n    wt(e.first, ' ', e.second, '\\\
    n');\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - flow/flow-on-bipartite-graph.hpp
  - misc/fastio.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp
  requiredBy: []
  timestamp: '2020-12-13 00:57:06+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp
- /verify/verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp.html
title: verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp
---
