---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/graph-utility.hpp
    title: "\u30B0\u30E9\u30D5\u30E6\u30FC\u30C6\u30A3\u30EA\u30C6\u30A3"
  - icon: ':heavy_check_mark:'
    path: shortest-path/dijkstra-abstruct.hpp
    title: shortest-path/dijkstra-abstruct.hpp
  - icon: ':heavy_check_mark:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':heavy_check_mark:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':heavy_check_mark:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"verify/verify-yosupo-graph/yosupo-shortest-path-dijkstra-abstruct.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n//\n#line\
    \ 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n#include\
    \ <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <initializer_list>\n#include <iomanip>\n\
    #include <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n\
    #include <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <streambuf>\n#include\
    \ <string>\n#include <tuple>\n#include <type_traits>\n#include <typeinfo>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include <vector>\n\
    \n// utility\n#line 1 \"template/util.hpp\"\nnamespace Nyaan {\nusing ll = long\
    \ long;\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing i128 =\
    \ __int128_t;\nusing u128 = __uint128_t;\n\ntemplate <typename T>\nusing V = vector<T>;\n\
    template <typename T>\nusing VV = vector<vector<T>>;\nusing vi = vector<int>;\n\
    using vl = vector<long long>;\nusing vd = V<double>;\nusing vs = V<string>;\n\
    using vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\ntemplate\
    \ <typename T>\nusing minpq = priority_queue<T, vector<T>, greater<T>>;\n\ntemplate\
    \ <typename T, typename U>\nstruct P : pair<T, U> {\n  template <typename... Args>\n\
    \  P(Args... args) : pair<T, U>(args...) {}\n\n  using pair<T, U>::first;\n  using\
    \ pair<T, U>::second;\n\n  P &operator+=(const P &r) {\n    first += r.first;\n\
    \    second += r.second;\n    return *this;\n  }\n  P &operator-=(const P &r)\
    \ {\n    first -= r.first;\n    second -= r.second;\n    return *this;\n  }\n\
    \  P &operator*=(const P &r) {\n    first *= r.first;\n    second *= r.second;\n\
    \    return *this;\n  }\n  template <typename S>\n  P &operator*=(const S &r)\
    \ {\n    first *= r, second *= r;\n    return *this;\n  }\n  P operator+(const\
    \ P &r) const { return P(*this) += r; }\n  P operator-(const P &r) const { return\
    \ P(*this) -= r; }\n  P operator*(const P &r) const { return P(*this) *= r; }\n\
    \  template <typename S>\n  P operator*(const S &r) const {\n    return P(*this)\
    \ *= r;\n  }\n  P operator-() const { return P{-first, -second}; }\n};\n\nusing\
    \ pl = P<ll, ll>;\nusing pi = P<int, int>;\nusing vp = V<pl>;\n\nconstexpr int\
    \ inf = 1001001001;\nconstexpr long long infLL = 4004004004004004004LL;\n\ntemplate\
    \ <typename T>\nint sz(const T &t) {\n  return t.size();\n}\n\ntemplate <typename\
    \ T, typename U>\ninline bool amin(T &x, U y) {\n  return (y < x) ? (x = y, true)\
    \ : false;\n}\ntemplate <typename T, typename U>\ninline bool amax(T &x, U y)\
    \ {\n  return (x < y) ? (x = y, true) : false;\n}\n\ntemplate <typename T>\ninline\
    \ T Max(const vector<T> &v) {\n  return *max_element(begin(v), end(v));\n}\ntemplate\
    \ <typename T>\ninline T Min(const vector<T> &v) {\n  return *min_element(begin(v),\
    \ end(v));\n}\ntemplate <typename T>\ninline long long Sum(const vector<T> &v)\
    \ {\n  return accumulate(begin(v), end(v), 0LL);\n}\n\ntemplate <typename T>\n\
    int lb(const vector<T> &v, const T &a) {\n  return lower_bound(begin(v), end(v),\
    \ a) - begin(v);\n}\ntemplate <typename T>\nint ub(const vector<T> &v, const T\
    \ &a) {\n  return upper_bound(begin(v), end(v), a) - begin(v);\n}\n\nconstexpr\
    \ long long TEN(int n) {\n  long long ret = 1, x = 10;\n  for (; n; x *= x, n\
    \ >>= 1) ret *= (n & 1 ? x : 1);\n  return ret;\n}\n\ntemplate <typename T, typename\
    \ U>\npair<T, U> mkp(const T &t, const U &u) {\n  return make_pair(t, u);\n}\n\
    \ntemplate <typename T>\nvector<T> mkrui(const vector<T> &v, bool rev = false)\
    \ {\n  vector<T> ret(v.size() + 1);\n  if (rev) {\n    for (int i = int(v.size())\
    \ - 1; i >= 0; i--) ret[i] = v[i] + ret[i + 1];\n  } else {\n    for (int i =\
    \ 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];\n  }\n  return ret;\n\
    };\n\ntemplate <typename T>\nvector<T> mkuni(const vector<T> &v) {\n  vector<T>\
    \ ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(), ret.end()),\
    \ ret.end());\n  return ret;\n}\n\ntemplate <typename F>\nvector<int> mkord(int\
    \ N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n  sort(begin(ord),\
    \ end(ord), f);\n  return ord;\n}\n\ntemplate <typename T>\nvector<int> mkinv(vector<T>\
    \ &v) {\n  int max_val = *max_element(begin(v), end(v));\n  vector<int> inv(max_val\
    \ + 1, -1);\n  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;\n  return\
    \ inv;\n}\n\nvector<int> mkiota(int n) {\n  vector<int> ret(n);\n  iota(begin(ret),\
    \ end(ret), 0);\n  return ret;\n}\n\ntemplate <typename T>\nT mkrev(const T &v)\
    \ {\n  T w{v};\n  reverse(begin(w), end(w));\n  return w;\n}\n\ntemplate <typename\
    \ T>\nbool nxp(vector<T> &v) {\n  return next_permutation(begin(v), end(v));\n\
    }\n\n// \u8FD4\u308A\u5024\u306E\u578B\u306F\u5165\u529B\u306E T \u306B\u4F9D\u5B58\
    \n// i \u8981\u7D20\u76EE : [0, a[i])\ntemplate <typename T>\nvector<vector<T>>\
    \ product(const vector<T> &a) {\n  vector<vector<T>> ret;\n  vector<T> v;\n  auto\
    \ dfs = [&](auto rc, int i) -> void {\n    if (i == (int)a.size()) {\n      ret.push_back(v);\n\
    \      return;\n    }\n    for (int j = 0; j < a[i]; j++) v.push_back(j), rc(rc,\
    \ i + 1), v.pop_back();\n  };\n  dfs(dfs, 0);\n  return ret;\n}\n\n// F : function(void(T&)),\
    \ mod \u3092\u53D6\u308B\u64CD\u4F5C\n// T : \u6574\u6570\u578B\u306E\u3068\u304D\
    \u306F\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306B\u6CE8\u610F\u3059\u308B\
    \ntemplate <typename T>\nT Power(T a, long long n, const T &I, const function<void(T\
    \ &)> &f) {\n  T res = I;\n  for (; n; f(a = a * a), n >>= 1) {\n    if (n & 1)\
    \ f(res = res * a);\n  }\n  return res;\n}\n// T : \u6574\u6570\u578B\u306E\u3068\
    \u304D\u306F\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306B\u6CE8\u610F\u3059\
    \u308B\ntemplate <typename T>\nT Power(T a, long long n, const T &I) {\n  return\
    \ Power(a, n, I, function<void(T &)>{[](T &) -> void {}});\n}\n\n}  // namespace\
    \ Nyaan\n#line 58 \"template/template.hpp\"\n\n// bit operation\n#line 1 \"template/bitop.hpp\"\
    \nnamespace Nyaan {\n__attribute__((target(\"popcnt\"))) inline int popcnt(const\
    \ u64 &a) {\n  return _mm_popcnt_u64(a);\n}\ninline int lsb(const u64 &a) { return\
    \ a ? __builtin_ctzll(a) : 64; }\ninline int ctz(const u64 &a) { return a ? __builtin_ctzll(a)\
    \ : 64; }\ninline int msb(const u64 &a) { return a ? 63 - __builtin_clzll(a) :\
    \ -1; }\ntemplate <typename T>\ninline int gbit(const T &a, int i) {\n  return\
    \ (a >> i) & 1;\n}\ntemplate <typename T>\ninline void sbit(T &a, int i, bool\
    \ b) {\n  if (gbit(a, i) != b) a ^= T(1) << i;\n}\nconstexpr long long PW(int\
    \ n) { return 1LL << n; }\nconstexpr long long MSK(int n) { return (1LL << n)\
    \ - 1; }\n}  // namespace Nyaan\n#line 61 \"template/template.hpp\"\n\n// inout\n\
    #line 1 \"template/inout.hpp\"\nnamespace Nyaan {\n\ntemplate <typename T, typename\
    \ U>\nostream &operator<<(ostream &os, const pair<T, U> &p) {\n  os << p.first\
    \ << \" \" << p.second;\n  return os;\n}\ntemplate <typename T, typename U>\n\
    istream &operator>>(istream &is, pair<T, U> &p) {\n  is >> p.first >> p.second;\n\
    \  return is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const\
    \ vector<T> &v) {\n  int s = (int)v.size();\n  for (int i = 0; i < s; i++) os\
    \ << (i ? \" \" : \"\") << v[i];\n  return os;\n}\ntemplate <typename T>\nistream\
    \ &operator>>(istream &is, vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return\
    \ is;\n}\n\nistream &operator>>(istream &is, __int128_t &x) {\n  string S;\n \
    \ is >> S;\n  x = 0;\n  int flag = 0;\n  for (auto &c : S) {\n    if (c == '-')\
    \ {\n      flag = true;\n      continue;\n    }\n    x *= 10;\n    x += c - '0';\n\
    \  }\n  if (flag) x = -x;\n  return is;\n}\n\nistream &operator>>(istream &is,\
    \ __uint128_t &x) {\n  string S;\n  is >> S;\n  x = 0;\n  for (auto &c : S) {\n\
    \    x *= 10;\n    x += c - '0';\n  }\n  return is;\n}\n\nostream &operator<<(ostream\
    \ &os, __int128_t x) {\n  if (x == 0) return os << 0;\n  if (x < 0) os << '-',\
    \ x = -x;\n  string S;\n  while (x) S.push_back('0' + x % 10), x /= 10;\n  reverse(begin(S),\
    \ end(S));\n  return os << S;\n}\nostream &operator<<(ostream &os, __uint128_t\
    \ x) {\n  if (x == 0) return os << 0;\n  string S;\n  while (x) S.push_back('0'\
    \ + x % 10), x /= 10;\n  reverse(begin(S), end(S));\n  return os << S;\n}\n\n\
    void in() {}\ntemplate <typename T, class... U>\nvoid in(T &t, U &...u) {\n  cin\
    \ >> t;\n  in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename\
    \ T, class... U, char sep = ' '>\nvoid out(const T &t, const U &...u) {\n  cout\
    \ << t;\n  if (sizeof...(u)) cout << sep;\n  out(u...);\n}\n\nstruct IoSetupNya\
    \ {\n  IoSetupNya() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(15);\n    cerr << fixed << setprecision(7);\n\
    \  }\n} iosetupnya;\n\n}  // namespace Nyaan\n#line 64 \"template/template.hpp\"\
    \n\n// debug\n#line 1 \"template/debug.hpp\"\nnamespace DebugImpl {\n\ntemplate\
    \ <typename U, typename = void>\nstruct is_specialize : false_type {};\ntemplate\
    \ <typename U>\nstruct is_specialize<\n    U, typename conditional<false, typename\
    \ U::iterator, void>::type>\n    : true_type {};\ntemplate <typename U>\nstruct\
    \ is_specialize<\n    U, typename conditional<false, decltype(U::first), void>::type>\n\
    \    : true_type {};\ntemplate <typename U>\nstruct is_specialize<U, enable_if_t<is_integral<U>::value,\
    \ void>> : true_type {\n};\n\nvoid dump(const char& t) { cerr << t; }\n\nvoid\
    \ dump(const string& t) { cerr << t; }\n\nvoid dump(const bool& t) { cerr << (t\
    \ ? \"true\" : \"false\"); }\n\nvoid dump(__int128_t t) {\n  if (t == 0) cerr\
    \ << 0;\n  if (t < 0) cerr << '-', t = -t;\n  string S;\n  while (t) S.push_back('0'\
    \ + t % 10), t /= 10;\n  reverse(begin(S), end(S));\n  cerr << S;\n}\n\nvoid dump(__uint128_t\
    \ t) {\n  if (t == 0) cerr << 0;\n  string S;\n  while (t) S.push_back('0' + t\
    \ % 10), t /= 10;\n  reverse(begin(S), end(S));\n  cerr << S;\n}\n\ntemplate <typename\
    \ U,\n          enable_if_t<!is_specialize<U>::value, nullptr_t> = nullptr>\n\
    void dump(const U& t) {\n  cerr << t;\n}\n\ntemplate <typename T>\nvoid dump(const\
    \ T& t, enable_if_t<is_integral<T>::value>* = nullptr) {\n  string res;\n  if\
    \ (t == Nyaan::inf) res = \"inf\";\n  if constexpr (is_signed<T>::value) {\n \
    \   if (t == -Nyaan::inf) res = \"-inf\";\n  }\n  if constexpr (sizeof(T) == 8)\
    \ {\n    if (t == Nyaan::infLL) res = \"inf\";\n    if constexpr (is_signed<T>::value)\
    \ {\n      if (t == -Nyaan::infLL) res = \"-inf\";\n    }\n  }\n  if (res.empty())\
    \ res = to_string(t);\n  cerr << res;\n}\n\ntemplate <typename T, typename U>\n\
    void dump(const pair<T, U>&);\ntemplate <typename T>\nvoid dump(const pair<T*,\
    \ int>&);\n\ntemplate <typename T>\nvoid dump(const T& t,\n          enable_if_t<!is_void<typename\
    \ T::iterator>::value>* = nullptr) {\n  cerr << \"[ \";\n  for (auto it = t.begin();\
    \ it != t.end();) {\n    dump(*it);\n    cerr << (++it == t.end() ? \"\" : \"\
    , \");\n  }\n  cerr << \" ]\";\n}\n\ntemplate <typename T, typename U>\nvoid dump(const\
    \ pair<T, U>& t) {\n  cerr << \"( \";\n  dump(t.first);\n  cerr << \", \";\n \
    \ dump(t.second);\n  cerr << \" )\";\n}\n\ntemplate <typename T>\nvoid dump(const\
    \ pair<T*, int>& t) {\n  cerr << \"[ \";\n  for (int i = 0; i < t.second; i++)\
    \ {\n    dump(t.first[i]);\n    cerr << (i == t.second - 1 ? \"\" : \", \");\n\
    \  }\n  cerr << \" ]\";\n}\n\nvoid trace() { cerr << endl; }\ntemplate <typename\
    \ Head, typename... Tail>\nvoid trace(Head&& head, Tail&&... tail) {\n  cerr <<\
    \ \" \";\n  dump(head);\n  if (sizeof...(tail) != 0) cerr << \",\";\n  trace(forward<Tail>(tail)...);\n\
    }\n\n}  // namespace DebugImpl\n\n#ifdef NyaanDebug\n#define trc(...)        \
    \                    \\\n  do {                                      \\\n    cerr\
    \ << \"## \" << #__VA_ARGS__ << \" = \"; \\\n    DebugImpl::trace(__VA_ARGS__);\
    \          \\\n  } while (0)\n#else\n#define trc(...) (void(0))\n#endif\n\n#ifdef\
    \ NyaanLocal\n#define trc2(...)                           \\\n  do {         \
    \                             \\\n    cerr << \"## \" << #__VA_ARGS__ << \" =\
    \ \"; \\\n    DebugImpl::trace(__VA_ARGS__);          \\\n  } while (0)\n#else\n\
    #define trc2(...) (void(0))\n#endif\n#line 67 \"template/template.hpp\"\n\n//\
    \ macro\n#line 1 \"template/macro.hpp\"\n#define each(x, v) for (auto&& x : v)\n\
    #define each2(x, y, v) for (auto&& [x, y] : v)\n#define all(v) (v).begin(), (v).end()\n\
    #define rep(i, N) for (long long i = 0; i < (long long)(N); i++)\n#define repr(i,\
    \ N) for (long long i = (long long)(N)-1; i >= 0; i--)\n#define rep1(i, N) for\
    \ (long long i = 1; i <= (long long)(N); i++)\n#define repr1(i, N) for (long long\
    \ i = (N); (long long)(i) > 0; i--)\n#define reg(i, a, b) for (long long i = (a);\
    \ i < (b); i++)\n#define regr(i, a, b) for (long long i = (b)-1; i >= (a); i--)\n\
    #define fi first\n#define se second\n#define ini(...)   \\\n  int __VA_ARGS__;\
    \ \\\n  in(__VA_ARGS__)\n#define inl(...)         \\\n  long long __VA_ARGS__;\
    \ \\\n  in(__VA_ARGS__)\n#define ins(...)      \\\n  string __VA_ARGS__; \\\n\
    \  in(__VA_ARGS__)\n#define in2(s, t)                           \\\n  for (int\
    \ i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i]);                   \
    \      \\\n  }\n#define in3(s, t, u)                        \\\n  for (int i =\
    \ 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i], u[i]);                 \
    \  \\\n  }\n#define in4(s, t, u, v)                     \\\n  for (int i = 0;\
    \ i < (int)s.size(); i++) { \\\n    in(s[i], t[i], u[i], v[i]);             \\\
    \n  }\n#define die(...)             \\\n  do {                       \\\n    Nyaan::out(__VA_ARGS__);\
    \ \\\n    return;                  \\\n  } while (0)\n#line 70 \"template/template.hpp\"\
    \n\nnamespace Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line\
    \ 4 \"verify/verify-yosupo-graph/yosupo-shortest-path-dijkstra-abstruct.test.cpp\"\
    \n//\n#line 2 \"graph/graph-utility.hpp\"\n\n#line 2 \"graph/graph-template.hpp\"\
    \n\ntemplate <typename T>\nstruct edge {\n  int src, to;\n  T cost;\n\n  edge(int\
    \ _to, T _cost) : src(-1), to(_to), cost(_cost) {}\n  edge(int _src, int _to,\
    \ T _cost) : src(_src), to(_to), cost(_cost) {}\n\n  edge &operator=(const int\
    \ &x) {\n    to = x;\n    return *this;\n  }\n\n  operator int() const { return\
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
    \  if (is_1origin) x--, y--;\n    g[x].emplace_back(x, y, c);\n    if (!is_directed)\
    \ g[y].emplace_back(y, x, c);\n  }\n  return g;\n}\n\n// Input of Edges\ntemplate\
    \ <typename T>\nEdges<T> esgraph(int N, int M, int is_weighted = true, bool is_1origin\
    \ = true) {\n  Edges<T> es;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n\
    \    cin >> x >> y;\n    T c;\n    if (is_weighted)\n      cin >> c;\n    else\n\
    \      c = 1;\n    if (is_1origin) x--, y--;\n    es.emplace_back(x, y, c);\n\
    \  }\n  return es;\n}\n\n// Input of Adjacency Matrix\ntemplate <typename T>\n\
    vector<vector<T>> adjgraph(int N, int M, T INF, int is_weighted = true,\n    \
    \                       bool is_directed = false, bool is_1origin = true) {\n\
    \  vector<vector<T>> d(N, vector<T>(N, INF));\n  for (int _ = 0; _ < M; _++) {\n\
    \    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n      cin\
    \ >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    d[x][y] =\
    \ c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/graph/graph-template.md\n\
    \ */\n#line 4 \"graph/graph-utility.hpp\"\n\n// \u4E00\u822C\u306E\u30B0\u30E9\
    \u30D5\u306Est\u304B\u3089\u306E\u8DDD\u96E2\uFF01\uFF01\uFF01\uFF01\n// unvisited\
    \ nodes : d = -1\nvector<int> Depth(const UnweightedGraph &g, int start = 0) {\n\
    \  int n = g.size();\n  vector<int> ds(n, -1);\n  ds[start] = 0;\n  queue<int>\
    \ q;\n  q.push(start);\n  while (!q.empty()) {\n    int c = q.front();\n    q.pop();\n\
    \    int dc = ds[c];\n    for (auto &d : g[c]) {\n      if (ds[d] == -1) {\n \
    \       ds[d] = dc + 1;\n        q.push(d);\n      }\n    }\n  }\n  return ds;\n\
    }\n\n// Depth of Rooted Weighted Tree\n// unvisited nodes : d = -1\ntemplate <typename\
    \ T>\nvector<T> Depth(const WeightedGraph<T> &g, int start = 0) {\n  vector<T>\
    \ d(g.size(), -1);\n  auto dfs = [&](auto rec, int cur, T val, int par = -1) ->\
    \ void {\n    d[cur] = val;\n    for (auto &dst : g[cur]) {\n      if (dst ==\
    \ par) continue;\n      rec(rec, dst, val + dst.cost, cur);\n    }\n  };\n  dfs(dfs,\
    \ start, 0);\n  return d;\n}\n\n// Diameter of Tree\n// return value : { {u, v},\
    \ length }\npair<pair<int, int>, int> Diameter(const UnweightedGraph &g) {\n \
    \ auto d = Depth(g, 0);\n  int u = max_element(begin(d), end(d)) - begin(d);\n\
    \  d = Depth(g, u);\n  int v = max_element(begin(d), end(d)) - begin(d);\n  return\
    \ make_pair(make_pair(u, v), d[v]);\n}\n\n// Diameter of Weighted Tree\n// return\
    \ value : { {u, v}, length }\ntemplate <typename T>\npair<pair<int, int>, T> Diameter(const\
    \ WeightedGraph<T> &g) {\n  auto d = Depth(g, 0);\n  int u = max_element(begin(d),\
    \ end(d)) - begin(d);\n  d = Depth(g, u);\n  int v = max_element(begin(d), end(d))\
    \ - begin(d);\n  return make_pair(make_pair(u, v), d[v]);\n}\n\n// nodes on the\
    \ path u-v ( O(N) )\ntemplate <typename G>\nvector<int> Path(G &g, int u, int\
    \ v) {\n  vector<int> ret;\n  int end = 0;\n  auto dfs = [&](auto rec, int cur,\
    \ int par = -1) -> void {\n    ret.push_back(cur);\n    if (cur == v) {\n    \
    \  end = 1;\n      return;\n    }\n    for (int dst : g[cur]) {\n      if (dst\
    \ == par) continue;\n      rec(rec, dst, cur);\n      if (end) return;\n    }\n\
    \    if (end) return;\n    ret.pop_back();\n  };\n  dfs(dfs, u);\n  return ret;\n\
    }\n\n/**\n * @brief \u30B0\u30E9\u30D5\u30E6\u30FC\u30C6\u30A3\u30EA\u30C6\u30A3\
    \n * @docs docs/graph/graph-utility.md\n */\n#line 6 \"verify/verify-yosupo-graph/yosupo-shortest-path-dijkstra-abstruct.test.cpp\"\
    \n//\n#line 2 \"shortest-path/dijkstra-abstruct.hpp\"\n\n#line 8 \"shortest-path/dijkstra-abstruct.hpp\"\
    \nusing namespace std;\n\n// start : \u59CB\u70B9\n// goal  : \u5230\u9054\u3057\
    \u305F\u7D42\u70B9 (goal \u304C\u7121\u3044/\u7740\u304B\u306A\u3044\u5834\u5408\
    \ Index{})\n// dist  : start - goal \u9593\u306E\u8DDD\u96E2\n// reachable : goal\
    \ \u306B\u7740\u3044\u305F\u304B\uFF1F\u3092\u610F\u5473\u3059\u308B bool\n//\
    \ path  : start \u304B\u3089 goal \u3078\u306E\u30D1\u30B9 (reachable = false\
    \ \u306E\u5834\u5408\u306F\u7A7A)\n// mp    : mp[\u9802\u70B9] = (\u6700\u77ED\
    \u8DDD\u96E2, 1 \u3064\u524D\u306E\u9802\u70B9) \u3092\u7BA1\u7406\u3059\u308B\
    \ map\ntemplate <typename Index, typename Cost>\nstruct DijkstraResult {\n  Index\
    \ start, goal;\n  Cost dist;\n  bool reachable;\n  map<Index, pair<Cost, Index>>\
    \ mp;\n  vector<Index> path;\n\n  DijkstraResult(const Index& s, const Index&\
    \ g, Cost d, bool r,\n                 const map<Index, pair<Cost, Index>>& m)\n\
    \      : start(s), goal(g), dist(d), reachable(r), mp(m) {\n    if (reachable)\
    \ {\n      for (Index c = g; c != s; c = mp[c].second) path.push_back(c);\n  \
    \    path.push_back(s);\n      reverse(begin(path), end(path));\n    }\n  }\n\
    };\n\n// \u5F15\u6570 f \u306F (\u9802\u70B9 v, s-v \u9593\u306E\u8DDD\u96E2,\
    \ \u95A2\u6570 g) \u3092\u5F15\u6570\u306B\u53D6\u308B\n// f \u306E\u5185\u90E8\
    \u3067 g(\u6B21\u306E\u9802\u70B9 w, s-w \u9593\u306E\u8DDD\u96E2) \u3092\u547C\
    \u3073\u51FA\u3057\u3066\u4F7F\u3046\n//\n// \u8FD4\u308A\u5024\u306F DijkstraResult<Index,\
    \ Cost> \u3092\u8FD4\u3059\n//\n// goal \u306F lambda \u5F0F or \u5024 \u3092\u6E21\
    \u305B\u308B, goal \u304C\u8907\u6570\u3042\u308B\u5834\u5408\u306B\u5BFE\u5FDC\
    \u3057\u3066\u3044\u308B\n// (\u59CB\u70B9\u304C\u8907\u6570\u3042\u308B\u5834\
    \u5408\u306F\u8D85\u9802\u70B9\u3092\u4F7F\u3046\u3053\u3068\u306B\u3059\u308B\
    )\ntemplate <typename Index, typename Cost, bool has_goal = true>\nDijkstraResult<Index,\
    \ Cost> dijkstra_abstruct(\n    const function<void(Index, Cost, function<void(Index,\
    \ Cost)>)>& f,\n    const Index& start, const function<bool(Index)>& is_goal)\
    \ {\n  using P = pair<Cost, Index>;\n\n  map<Index, P> d;\n  priority_queue<P,\
    \ vector<P>, greater<P>> Q;\n  d[start] = P(0, Index{});\n  Q.emplace(0, start);\n\
    \n  while (!Q.empty()) {\n    auto [u, t] = Q.top();\n    Q.pop();\n    if (d[t].first\
    \ != u) continue;\n    if constexpr (has_goal) {\n      if (is_goal(t)) return\
    \ {start, t, u, true, d};\n    }\n    auto add = [&](Index nt, Cost nu) {\n  \
    \    if (d.count(nt) == 0 or nu < d[nt].first) {\n        d[nt] = P(nu, t);\n\
    \        Q.emplace(nu, nt);\n      }\n    };\n    f(t, u, add);\n  }\n  return\
    \ {start, Index{}, Cost{}, false, d};\n}\n\n// \u5F15\u6570 f \u306F (\u9802\u70B9\
    \ v, s-v \u9593\u306E\u8DDD\u96E2, \u95A2\u6570 g) \u3092\u5F15\u6570\u306B\u53D6\
    \u308B\n// f \u306E\u5185\u90E8\u3067 g(\u6B21\u306E\u9802\u70B9 w, s-w \u9593\
    \u306E\u8DDD\u96E2) \u3092\u547C\u3073\u51FA\u3057\u3066\u4F7F\u3046\n//\n// \u8FD4\
    \u308A\u5024\u306F DijkstraResult<Index, Cost> \u3092\u8FD4\u3059\n//\n// goal\
    \ \u306F lambda \u5F0F or \u5024 \u3092\u6E21\u305B\u308B, goal \u304C\u8907\u6570\
    \u3042\u308B\u5834\u5408\u306B\u5BFE\u5FDC\u3057\u3066\u3044\u308B\n// (\u59CB\
    \u70B9\u304C\u8907\u6570\u3042\u308B\u5834\u5408\u306F\u8D85\u9802\u70B9\u3092\
    \u4F7F\u3046\u3053\u3068\u306B\u3059\u308B)\ntemplate <typename Index, typename\
    \ Cost, bool has_goal = true>\nDijkstraResult<Index, Cost> dijkstra_abstruct(\n\
    \    const function<void(Index, Cost, function<void(Index, Cost)>)>& f,\n    const\
    \ Index& start, const Index& goal = Index{}) {\n  const function<bool(Index)>\
    \ is_goal = [&goal](Index i) -> bool {\n    return i == goal;\n  };\n  return\
    \ dijkstra_abstruct<Index, Cost, has_goal>(f, start, is_goal);\n}\n#line 8 \"\
    verify/verify-yosupo-graph/yosupo-shortest-path-dijkstra-abstruct.test.cpp\"\n\
    using namespace Nyaan;\n\nvoid q() {\n  inl(N, M, S, T);\n  auto g = wgraph<ll>(N,\
    \ M, true, false);\n\n  auto res = dijkstra_abstruct<int, ll>(\n      [&](int\
    \ c, ll cd, auto add) { each(e, g[c]) add(e.to, cd + e.cost); }, S,\n      T);\n\
    \  if (!res.reachable) die(-1);\n  out(res.dist, sz(res.path) - 1);\n  rep(i,\
    \ sz(res.path) - 1) out(res.path[i], res.path[i + 1]);\n}\n\nvoid Nyaan::solve()\
    \ {\n  int t = 1;\n  // in(t);\n  while (t--) q();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../graph/graph-utility.hpp\"\
    \n//\n#include \"../../shortest-path/dijkstra-abstruct.hpp\"\nusing namespace\
    \ Nyaan;\n\nvoid q() {\n  inl(N, M, S, T);\n  auto g = wgraph<ll>(N, M, true,\
    \ false);\n\n  auto res = dijkstra_abstruct<int, ll>(\n      [&](int c, ll cd,\
    \ auto add) { each(e, g[c]) add(e.to, cd + e.cost); }, S,\n      T);\n  if (!res.reachable)\
    \ die(-1);\n  out(res.dist, sz(res.path) - 1);\n  rep(i, sz(res.path) - 1) out(res.path[i],\
    \ res.path[i + 1]);\n}\n\nvoid Nyaan::solve() {\n  int t = 1;\n  // in(t);\n \
    \ while (t--) q();\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - graph/graph-utility.hpp
  - graph/graph-template.hpp
  - shortest-path/dijkstra-abstruct.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-graph/yosupo-shortest-path-dijkstra-abstruct.test.cpp
  requiredBy: []
  timestamp: '2023-08-10 13:25:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-graph/yosupo-shortest-path-dijkstra-abstruct.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-graph/yosupo-shortest-path-dijkstra-abstruct.test.cpp
- /verify/verify/verify-yosupo-graph/yosupo-shortest-path-dijkstra-abstruct.test.cpp.html
title: verify/verify-yosupo-graph/yosupo-shortest-path-dijkstra-abstruct.test.cpp
---
