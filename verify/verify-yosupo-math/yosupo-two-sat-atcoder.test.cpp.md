---
data:
  _extendedDependsOn:
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"verify/verify-yosupo-math/yosupo-two-sat-atcoder.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#line 1 \"atcoder/twosat.hpp\"\
    \n\n\n\n#include <cassert>\n#include <vector>\n\n#line 1 \"atcoder/internal_scc.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <utility>\n#line 7 \"atcoder/internal_scc.hpp\"\
    \n\n#line 1 \"atcoder/internal_csr.hpp\"\n\n\n\n#line 7 \"atcoder/internal_csr.hpp\"\
    \n\nnamespace atcoder {\nnamespace internal {\n\ntemplate <class E> struct csr\
    \ {\n    std::vector<int> start;\n    std::vector<E> elist;\n    csr(int n, const\
    \ std::vector<std::pair<int, E>>& edges)\n        : start(n + 1), elist(edges.size())\
    \ {\n        for (auto e : edges) {\n            start[e.first + 1]++;\n     \
    \   }\n        for (int i = 1; i <= n; i++) {\n            start[i] += start[i\
    \ - 1];\n        }\n        auto counter = start;\n        for (auto e : edges)\
    \ {\n            elist[counter[e.first]++] = e.second;\n        }\n    }\n};\n\
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 9 \"atcoder/internal_scc.hpp\"\
    \n\nnamespace atcoder {\nnamespace internal {\n\n// Reference:\n// R. Tarjan,\n\
    // Depth-First Search and Linear Graph Algorithms\nstruct scc_graph {\n  public:\n\
    \    scc_graph(int n) : _n(n) {}\n\n    int num_vertices() { return _n; }\n\n\
    \    void add_edge(int from, int to) { edges.push_back({from, {to}}); }\n\n  \
    \  // @return pair of (# of scc, scc id)\n    std::pair<int, std::vector<int>>\
    \ scc_ids() {\n        auto g = csr<edge>(_n, edges);\n        int now_ord = 0,\
    \ group_num = 0;\n        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);\n\
    \        visited.reserve(_n);\n        auto dfs = [&](auto self, int v) -> void\
    \ {\n            low[v] = ord[v] = now_ord++;\n            visited.push_back(v);\n\
    \            for (int i = g.start[v]; i < g.start[v + 1]; i++) {\n           \
    \     auto to = g.elist[i].to;\n                if (ord[to] == -1) {\n       \
    \             self(self, to);\n                    low[v] = std::min(low[v], low[to]);\n\
    \                } else {\n                    low[v] = std::min(low[v], ord[to]);\n\
    \                }\n            }\n            if (low[v] == ord[v]) {\n     \
    \           while (true) {\n                    int u = visited.back();\n    \
    \                visited.pop_back();\n                    ord[u] = _n;\n     \
    \               ids[u] = group_num;\n                    if (u == v) break;\n\
    \                }\n                group_num++;\n            }\n        };\n\
    \        for (int i = 0; i < _n; i++) {\n            if (ord[i] == -1) dfs(dfs,\
    \ i);\n        }\n        for (auto& x : ids) {\n            x = group_num - 1\
    \ - x;\n        }\n        return {group_num, ids};\n    }\n\n    std::vector<std::vector<int>>\
    \ scc() {\n        auto ids = scc_ids();\n        int group_num = ids.first;\n\
    \        std::vector<int> counts(group_num);\n        for (auto x : ids.second)\
    \ counts[x]++;\n        std::vector<std::vector<int>> groups(ids.first);\n   \
    \     for (int i = 0; i < group_num; i++) {\n            groups[i].reserve(counts[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            groups[ids.second[i]].push_back(i);\n\
    \        }\n        return groups;\n    }\n\n  private:\n    int _n;\n    struct\
    \ edge {\n        int to;\n    };\n    std::vector<std::pair<int, edge>> edges;\n\
    };\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 8 \"atcoder/twosat.hpp\"\
    \n\nnamespace atcoder {\n\n// Reference:\n// B. Aspvall, M. Plass, and R. Tarjan,\n\
    // A Linear-Time Algorithm for Testing the Truth of Certain Quantified Boolean\n\
    // Formulas\nstruct two_sat {\n  public:\n    two_sat() : _n(0), scc(0) {}\n \
    \   two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}\n\n    void add_clause(int\
    \ i, bool f, int j, bool g) {\n        assert(0 <= i && i < _n);\n        assert(0\
    \ <= j && j < _n);\n        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 :\
    \ 0));\n        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));\n    }\n\
    \    bool satisfiable() {\n        auto id = scc.scc_ids().second;\n        for\
    \ (int i = 0; i < _n; i++) {\n            if (id[2 * i] == id[2 * i + 1]) return\
    \ false;\n            _answer[i] = id[2 * i] < id[2 * i + 1];\n        }\n   \
    \     return true;\n    }\n    std::vector<bool> answer() { return _answer; }\n\
    \n  private:\n    int _n;\n    std::vector<bool> _answer;\n    internal::scc_graph\
    \ scc;\n};\n\n}  // namespace atcoder\n\n\n#line 2 \"template/template.hpp\"\n\
    using namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\n#line 8 \"template/template.hpp\"\
    \n#include <array>\n#include <bitset>\n#line 11 \"template/template.hpp\"\n#include\
    \ <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n\
    #include <climits>\n#include <cmath>\n#include <complex>\n#include <csetjmp>\n\
    #include <csignal>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n\
    #include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <ctime>\n\
    #include <deque>\n#include <exception>\n#include <forward_list>\n#include <fstream>\n\
    #include <functional>\n#include <initializer_list>\n#include <iomanip>\n#include\
    \ <ios>\n#include <iosfwd>\n#include <iostream>\n#include <istream>\n#include\
    \ <iterator>\n#include <limits>\n#include <list>\n#include <locale>\n#include\
    \ <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n\
    #include <queue>\n#include <random>\n#include <ratio>\n#include <regex>\n#include\
    \ <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n#include\
    \ <streambuf>\n#include <string>\n#include <system_error>\n#include <tuple>\n\
    #include <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#line 65 \"template/template.hpp\"\n#include <valarray>\n#line\
    \ 67 \"template/template.hpp\"\n\n// utility\n#line 1 \"template/util.hpp\"\n\
    namespace Nyaan {\nusing ll = long long;\nusing i64 = long long;\nusing u64 =\
    \ unsigned long long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\n\
    template <typename T>\nusing V = vector<T>;\ntemplate <typename T>\nusing VV =\
    \ vector<vector<T>>;\nusing vi = vector<int>;\nusing vl = vector<long long>;\n\
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
    \ 5 \"verify/verify-yosupo-math/yosupo-two-sat-atcoder.test.cpp\"\n\nusing namespace\
    \ Nyaan;\nvoid Nyaan::solve() {\n  ins(p, cnf);\n  ini(N, M);\n  atcoder::two_sat\
    \ sat(N);\n  rep(_, M) {\n    ini(a, b, c);\n    sat.add_clause(abs(a) - 1, a\
    \ > 0, abs(b) - 1, b > 0);\n  }\n  int flg = sat.satisfiable();\n  if (!flg) {\n\
    \    out(\"s UNSATISFIABLE\");\n    return;\n  }\n  auto ans = sat.answer();\n\
    \  out(\"s SATISFIABLE\");\n  cout << \"v \";\n  rep(i, N) cout << (ans[i] ? (i\
    \ + 1) : -(i + 1)) << \" \";\n  cout << \"0\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include \"\
    ../../atcoder/twosat.hpp\"\n#include \"../../template/template.hpp\"\n\nusing\
    \ namespace Nyaan;\nvoid Nyaan::solve() {\n  ins(p, cnf);\n  ini(N, M);\n  atcoder::two_sat\
    \ sat(N);\n  rep(_, M) {\n    ini(a, b, c);\n    sat.add_clause(abs(a) - 1, a\
    \ > 0, abs(b) - 1, b > 0);\n  }\n  int flg = sat.satisfiable();\n  if (!flg) {\n\
    \    out(\"s UNSATISFIABLE\");\n    return;\n  }\n  auto ans = sat.answer();\n\
    \  out(\"s SATISFIABLE\");\n  cout << \"v \";\n  rep(i, N) cout << (ans[i] ? (i\
    \ + 1) : -(i + 1)) << \" \";\n  cout << \"0\\n\";\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-math/yosupo-two-sat-atcoder.test.cpp
  requiredBy: []
  timestamp: '2020-12-21 18:22:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-math/yosupo-two-sat-atcoder.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-math/yosupo-two-sat-atcoder.test.cpp
- /verify/verify/verify-yosupo-math/yosupo-two-sat-atcoder.test.cpp.html
title: verify/verify-yosupo-math/yosupo-two-sat-atcoder.test.cpp
---
