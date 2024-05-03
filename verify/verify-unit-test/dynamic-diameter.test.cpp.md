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
    path: internal/internal-seed.hpp
    title: internal/internal-seed.hpp
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: shortest-path/dijkstra.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
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
  - icon: ':heavy_check_mark:'
    path: tree/convert-tree.hpp
    title: "\u6839\u4ED8\u304D\u6728\u30FB\u9006\u8FBA\u304B\u3089\u306A\u308B\u6728\
      \u3078\u306E\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: tree/dynamic-diameter.hpp
    title: tree/dynamic-diameter.hpp
  - icon: ':heavy_check_mark:'
    path: tree/heavy-light-decomposition.hpp
    title: "Heavy Light Decomposition(\u91CD\u8EFD\u5206\u89E3)"
  - icon: ':heavy_check_mark:'
    path: tree/static-top-tree-vertex-based.hpp
    title: Static Top Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/dynamic-diameter.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#line 2 \"template/template.hpp\"\
    \nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cctype>\n#include\
    \ <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <cstdarg>\n#include\
    \ <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
    #include <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include\
    \ <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <streambuf>\n#include <string>\n#include <tuple>\n\
    #include <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <vector>\n\n// utility\n#line\
    \ 1 \"template/util.hpp\"\nnamespace Nyaan {\nusing ll = long long;\nusing i64\
    \ = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\nusing\
    \ u128 = __uint128_t;\n\ntemplate <typename T>\nusing V = vector<T>;\ntemplate\
    \ <typename T>\nusing VV = vector<vector<T>>;\nusing vi = vector<int>;\nusing\
    \ vl = vector<long long>;\nusing vd = V<double>;\nusing vs = V<string>;\nusing\
    \ vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\ntemplate\
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
    \ 4 \"verify/verify-unit-test/dynamic-diameter.test.cpp\"\n//\n#line 2 \"tree/dynamic-diameter.hpp\"\
    \n\n#line 9 \"tree/dynamic-diameter.hpp\"\nusing namespace std;\n\n#line 2 \"\
    graph/graph-template.hpp\"\n\ntemplate <typename T>\nstruct edge {\n  int src,\
    \ to;\n  T cost;\n\n  edge(int _to, T _cost) : src(-1), to(_to), cost(_cost) {}\n\
    \  edge(int _src, int _to, T _cost) : src(_src), to(_to), cost(_cost) {}\n\n \
    \ edge &operator=(const int &x) {\n    to = x;\n    return *this;\n  }\n\n  operator\
    \ int() const { return to; }\n};\ntemplate <typename T>\nusing Edges = vector<edge<T>>;\n\
    template <typename T>\nusing WeightedGraph = vector<Edges<T>>;\nusing UnweightedGraph\
    \ = vector<vector<int>>;\n\n// Input of (Unweighted) Graph\nUnweightedGraph graph(int\
    \ N, int M = -1, bool is_directed = false,\n                      bool is_1origin\
    \ = true) {\n  UnweightedGraph g(N);\n  if (M == -1) M = N - 1;\n  for (int _\
    \ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    if (is_1origin) x--,\
    \ y--;\n    g[x].push_back(y);\n    if (!is_directed) g[y].push_back(x);\n  }\n\
    \  return g;\n}\n\n// Input of Weighted Graph\ntemplate <typename T>\nWeightedGraph<T>\
    \ wgraph(int N, int M = -1, bool is_directed = false,\n                      \
    \  bool is_1origin = true) {\n  WeightedGraph<T> g(N);\n  if (M == -1) M = N -\
    \ 1;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n   \
    \ T c;\n    cin >> c;\n    if (is_1origin) x--, y--;\n    g[x].emplace_back(x,\
    \ y, c);\n    if (!is_directed) g[y].emplace_back(y, x, c);\n  }\n  return g;\n\
    }\n\n// Input of Edges\ntemplate <typename T>\nEdges<T> esgraph(int N, int M,\
    \ int is_weighted = true, bool is_1origin = true) {\n  Edges<T> es;\n  for (int\
    \ _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n\
    \      cin >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    es.emplace_back(x,\
    \ y, c);\n  }\n  return es;\n}\n\n// Input of Adjacency Matrix\ntemplate <typename\
    \ T>\nvector<vector<T>> adjgraph(int N, int M, T INF, int is_weighted = true,\n\
    \                           bool is_directed = false, bool is_1origin = true)\
    \ {\n  vector<vector<T>> d(N, vector<T>(N, INF));\n  for (int _ = 0; _ < M; _++)\
    \ {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n     \
    \ cin >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    d[x][y]\
    \ = c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/graph/graph-template.md\n\
    \ */\n#line 2 \"tree/static-top-tree-vertex-based.hpp\"\n\n#line 6 \"tree/static-top-tree-vertex-based.hpp\"\
    \nusing namespace std;\n\n#line 2 \"tree/convert-tree.hpp\"\n\n#line 4 \"tree/convert-tree.hpp\"\
    \n\ntemplate <typename T>\nstruct has_cost {\n private:\n  template <typename\
    \ U>\n  static auto confirm(U u) -> decltype(u.cost, std::true_type());\n  static\
    \ auto confirm(...) -> std::false_type;\n\n public:\n  enum : bool { value = decltype(confirm(std::declval<T>()))::value\
    \ };\n};\n\ntemplate <typename T>\nvector<vector<T>> inverse_tree(const vector<vector<T>>&\
    \ g) {\n  int N = (int)g.size();\n  vector<vector<T>> rg(N);\n  for (int i = 0;\
    \ i < N; i++) {\n    for (auto& e : g[i]) {\n      if constexpr (is_same<T, int>::value)\
    \ {\n        rg[e].push_back(i);\n      } else if constexpr (has_cost<T>::value)\
    \ {\n        rg[e].emplace_back(e.to, i, e.cost);\n      } else {\n        assert(0);\n\
    \      }\n    }\n  }\n  return rg;\n}\n\ntemplate <typename T>\nvector<vector<T>>\
    \ rooted_tree(const vector<vector<T>>& g, int root = 0) {\n  int N = (int)g.size();\n\
    \  vector<vector<T>> rg(N);\n  vector<char> v(N, false);\n  v[root] = true;\n\
    \  queue<int> que;\n  que.emplace(root);\n  while (!que.empty()) {\n    auto p\
    \ = que.front();\n    que.pop();\n    for (auto& e : g[p]) {\n      if (v[e] ==\
    \ false) {\n        v[e] = true;\n        que.push(e);\n        rg[p].push_back(e);\n\
    \      }\n    }\n  }\n  return rg;\n}\n\n/**\n * @brief \u6839\u4ED8\u304D\u6728\
    \u30FB\u9006\u8FBA\u304B\u3089\u306A\u308B\u6728\u3078\u306E\u5909\u63DB\n */\n\
    #line 2 \"tree/heavy-light-decomposition.hpp\"\n\n#line 4 \"tree/heavy-light-decomposition.hpp\"\
    \n\ntemplate <typename G>\nstruct HeavyLightDecomposition {\n private:\n  void\
    \ dfs_sz(int cur) {\n    size[cur] = 1;\n    for (auto& dst : g[cur]) {\n    \
    \  if (dst == par[cur]) {\n        if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))\n\
    \          swap(g[cur][0], g[cur][1]);\n        else\n          continue;\n  \
    \    }\n      depth[dst] = depth[cur] + 1;\n      par[dst] = cur;\n      dfs_sz(dst);\n\
    \      size[cur] += size[dst];\n      if (size[dst] > size[g[cur][0]]) {\n   \
    \     swap(dst, g[cur][0]);\n      }\n    }\n  }\n\n  void dfs_hld(int cur) {\n\
    \    down[cur] = id++;\n    for (auto dst : g[cur]) {\n      if (dst == par[cur])\
    \ continue;\n      nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));\n\
    \      dfs_hld(dst);\n    }\n    up[cur] = id;\n  }\n\n  // [u, v)\n  vector<pair<int,\
    \ int>> ascend(int u, int v) const {\n    vector<pair<int, int>> res;\n    while\
    \ (nxt[u] != nxt[v]) {\n      res.emplace_back(down[u], down[nxt[u]]);\n     \
    \ u = par[nxt[u]];\n    }\n    if (u != v) res.emplace_back(down[u], down[v] +\
    \ 1);\n    return res;\n  }\n\n  // (u, v]\n  vector<pair<int, int>> descend(int\
    \ u, int v) const {\n    if (u == v) return {};\n    if (nxt[u] == nxt[v]) return\
    \ {{down[u] + 1, down[v]}};\n    auto res = descend(u, par[nxt[v]]);\n    res.emplace_back(down[nxt[v]],\
    \ down[v]);\n    return res;\n  }\n\n public:\n  G& g;\n  int root, id;\n  vector<int>\
    \ size, depth, down, up, nxt, par;\n  HeavyLightDecomposition(G& _g, int _root\
    \ = 0)\n      : g(_g),\n        root(_root),\n        id(0),\n        size(g.size(),\
    \ 0),\n        depth(g.size(), 0),\n        down(g.size(), -1),\n        up(g.size(),\
    \ -1),\n        nxt(g.size(), root),\n        par(g.size(), root) {\n    dfs_sz(root);\n\
    \    dfs_hld(root);\n  }\n\n  pair<int, int> idx(int i) const { return make_pair(down[i],\
    \ up[i]); }\n\n  template <typename F>\n  void path_query(int u, int v, bool vertex,\
    \ const F& f) {\n    int l = lca(u, v);\n    for (auto&& [a, b] : ascend(u, l))\
    \ {\n      int s = a + 1, t = b;\n      s > t ? f(t, s) : f(s, t);\n    }\n  \
    \  if (vertex) f(down[l], down[l] + 1);\n    for (auto&& [a, b] : descend(l, v))\
    \ {\n      int s = a, t = b + 1;\n      s > t ? f(t, s) : f(s, t);\n    }\n  }\n\
    \n  template <typename F>\n  void path_noncommutative_query(int u, int v, bool\
    \ vertex, const F& f) {\n    int l = lca(u, v);\n    for (auto&& [a, b] : ascend(u,\
    \ l)) f(a + 1, b);\n    if (vertex) f(down[l], down[l] + 1);\n    for (auto&&\
    \ [a, b] : descend(l, v)) f(a, b + 1);\n  }\n\n  template <typename F>\n  void\
    \ subtree_query(int u, bool vertex, const F& f) {\n    f(down[u] + int(!vertex),\
    \ up[u]);\n  }\n\n  int lca(int a, int b) {\n    while (nxt[a] != nxt[b]) {\n\
    \      if (down[a] < down[b]) swap(a, b);\n      a = par[nxt[a]];\n    }\n   \
    \ return depth[a] < depth[b] ? a : b;\n  }\n\n  int dist(int a, int b) { return\
    \ depth[a] + depth[b] - depth[lca(a, b)] * 2; }\n};\n\n/**\n * @brief Heavy Light\
    \ Decomposition(\u91CD\u8EFD\u5206\u89E3)\n * @docs docs/tree/heavy-light-decomposition.md\n\
    \ */\n#line 10 \"tree/static-top-tree-vertex-based.hpp\"\n\nnamespace StaticTopTreeVertexBasedImpl\
    \ {\n\nenum Type { Vertex, Compress, Rake, Add_Edge, Add_Vertex };\n\ntemplate\
    \ <typename G>\nstruct StaticTopTreeVertexBased {\n  const HeavyLightDecomposition<G>&\
    \ hld;\n  vector<vector<int>> g;\n  int root;     // \u5143\u306E\u6728\u306E\
    \ root\n  int tt_root;  // top tree \u306E root\n  vector<int> P, L, R;\n  vector<Type>\
    \ T;\n\n  StaticTopTreeVertexBased(const HeavyLightDecomposition<G>& _hld) : hld(_hld)\
    \ {\n    root = hld.root;\n    g = rooted_tree(hld.g, root);\n    int n = g.size();\n\
    \    P.resize(n, -1), L.resize(n, -1), R.resize(n, -1);\n    T.resize(n, Type::Vertex);\n\
    \    build();\n  }\n\n private:\n  int add(int l, int r, Type t) {\n    if (t\
    \ == Type::Compress or t == Type::Rake) {\n      assert(l != -1 and r != -1);\n\
    \    }\n    if (t == Type::Add_Edge) {\n      assert(l != -1 and r == -1);\n \
    \   }\n    assert(t != Type::Vertex and t != Type::Add_Vertex);\n    int k = P.size();\n\
    \    P.push_back(-1), L.push_back(l), R.push_back(r), T.push_back(t);\n    if\
    \ (l != -1) P[l] = k;\n    if (r != -1) P[r] = k;\n    return k;\n  }\n  int add2(int\
    \ k, int l, int r, Type t) {\n    assert(k < (int)g.size());\n    assert(t ==\
    \ Type::Vertex or t == Type::Add_Vertex);\n    if (t == Type::Vertex) {\n    \
    \  assert(l == -1 and r == -1);\n    } else {\n      assert(l != -1 and r == -1);\n\
    \    }\n    P[k] = -1, L[k] = l, R[k] = r, T[k] = t;\n    if (l != -1) P[l] =\
    \ k;\n    if (r != -1) P[r] = k;\n    return k;\n  }\n  pair<int, int> merge(const\
    \ vector<pair<int, int>>& a, Type t) {\n    assert(!a.empty());\n    if (a.size()\
    \ == 1) return a[0];\n    int sum_s = 0;\n    for (auto& [_, s] : a) sum_s +=\
    \ s;\n    vector<pair<int, int>> b, c;\n    for (auto& [i, s] : a) {\n      (sum_s\
    \ > s ? b : c).emplace_back(i, s);\n      sum_s -= s * 2;\n    }\n    auto [i,\
    \ si] = merge(b, t);\n    auto [j, sj] = merge(c, t);\n    return {add(i, j, t),\
    \ si + sj};\n  }\n  pair<int, int> compress(int i) {\n    vector<pair<int, int>>\
    \ chs;\n    while (true) {\n      chs.push_back(add_vertex(i));\n      if (g[i].empty())\
    \ break;\n      i = g[i][0];\n    }\n    return merge(chs, Type::Compress);\n\
    \  }\n  pair<int, int> rake(int i) {\n    vector<pair<int, int>> chs;\n    for\
    \ (int j = 1; j < (int)g[i].size(); j++) chs.push_back(add_edge(g[i][j]));\n \
    \   if (chs.empty()) return {-1, 0};\n    return merge(chs, Type::Rake);\n  }\n\
    \  pair<int, int> add_edge(int i) {\n    auto [j, sj] = compress(i);\n    return\
    \ {add(j, -1, Type::Add_Edge), sj};\n  }\n  pair<int, int> add_vertex(int i) {\n\
    \    auto [j, sj] = rake(i);\n    return {add2(i, j, -1, j == -1 ? Type::Vertex\
    \ : Type::Add_Vertex), sj + 1};\n  }\n  void build() {\n    auto [i, n] = compress(root);\n\
    \    assert((int)g.size() == n);\n    tt_root = i;\n  }\n};\n\ntemplate <typename\
    \ G, typename Path, typename Point, typename Vertex,\n          typename Compress,\
    \ typename Rake, typename Add_edge,\n          typename Add_vertex>\nstruct DPonStaticTopTreeVertexBased\
    \ {\n  const StaticTopTreeVertexBased<G> tt;\n  vector<Path> path;\n  vector<Point>\
    \ point;\n  const Vertex vertex;\n  const Compress compress;\n  const Rake rake;\n\
    \  const Add_edge add_edge;\n  const Add_vertex add_vertex;\n\n  DPonStaticTopTreeVertexBased(const\
    \ HeavyLightDecomposition<G>& hld,\n                               const Vertex&\
    \ _vertex, const Compress& _compress,\n                               const Rake&\
    \ _rake, const Add_edge& _add_edge,\n                               const Add_vertex&\
    \ _add_vertex)\n      : tt(hld),\n        vertex(_vertex),\n        compress(_compress),\n\
    \        rake(_rake),\n        add_edge(_add_edge),\n        add_vertex(_add_vertex)\
    \ {\n    int n = tt.P.size();\n    path.resize(n), point.resize(n);\n    dfs(tt.tt_root);\n\
    \  }\n\n  Path get() { return path[tt.tt_root]; }\n  void update(int k) {\n  \
    \  while (k != -1) _update(k), k = tt.P[k];\n  }\n\n private:\n  void _update(int\
    \ k) {\n    if (tt.T[k] == Type::Vertex) {\n      path[k] = vertex(k);\n    }\
    \ else if (tt.T[k] == Type::Compress) {\n      path[k] = compress(path[tt.L[k]],\
    \ path[tt.R[k]]);\n    } else if (tt.T[k] == Type::Rake) {\n      point[k] = rake(point[tt.L[k]],\
    \ point[tt.R[k]]);\n    } else if (tt.T[k] == Type::Add_Edge) {\n      point[k]\
    \ = add_edge(path[tt.L[k]]);\n    } else {\n      path[k] = add_vertex(point[tt.L[k]],\
    \ k);\n    }\n  }\n\n  void dfs(int k) {\n    if (tt.L[k] != -1) dfs(tt.L[k]);\n\
    \    if (tt.R[k] != -1) dfs(tt.R[k]);\n    _update(k);\n  }\n};\n\n}  // namespace\
    \ StaticTopTreeVertexBasedImpl\n\nusing StaticTopTreeVertexBasedImpl::DPonStaticTopTreeVertexBased;\n\
    using StaticTopTreeVertexBasedImpl::StaticTopTreeVertexBased;\n\n/*\n\n  // template\n\
    \  using Path = ;\n  using Point = ;\n  auto vertex = [&](int i) -> Path {\n\n\
    \  };\n  auto compress = [&](const Path& p, const Path& c) -> Path {\n\n  };\n\
    \  auto rake = [&](const Point& a, const Point& b) -> Point {\n\n  };\n  auto\
    \ add_edge = [&](const Path& a) -> Point {\n\n  };\n  auto add_vertex = [&](const\
    \ Point& a, int i) -> Path {\n\n  };\n  HeavyLightDecomposition hld{g};\n  DPonStaticTopTreeVertexBased<vector<vector<int>>,\
    \ Path, Point,\n  decltype(vertex), decltype(compress), decltype(rake), decltype(add_edge),\n\
    \                    decltype(add_vertex)>\n      dp(hld, vertex, compress, rake,\
    \ add_edge, add_vertex);\n*/\n\n/**\n * @brief Static Top Tree\n */\n#line 13\
    \ \"tree/dynamic-diameter.hpp\"\n\nnamespace DynamicDiameterImpl {\n\ntemplate\
    \ <typename T>\nstruct HalfPath {\n  T d;\n  int u;\n  friend HalfPath max(const\
    \ HalfPath& lhs, const HalfPath& rhs) {\n    if (lhs.d != rhs.d) return lhs.d\
    \ > rhs.d ? lhs : rhs;\n    return lhs.u > rhs.u ? lhs : rhs;\n  }\n};\ntemplate\
    \ <typename T>\nstruct Path {\n  T d;\n  int u, v;\n  friend Path max(const Path&\
    \ lhs, const Path& rhs) {\n    if (lhs.d != rhs.d) return lhs.d > rhs.d ? lhs\
    \ : rhs;\n    if (lhs.u != rhs.u) return lhs.u > rhs.u ? lhs : rhs;\n    return\
    \ lhs.v > rhs.v ? lhs : rhs;\n  }\n};\ntemplate <typename T>\nstruct L {\n  Path<T>\
    \ dia;\n  HalfPath<T> d1, d2;\n};\ntemplate <typename T>\nstruct H {\n  Path<T>\
    \ dia;\n  HalfPath<T> pd, cd;\n  T p_to_c;\n  int p, c;\n};\n\ntemplate <typename\
    \ T>\nH<T> vertex(T x, int i) {\n  H<T> r;\n  r.dia = {x, i, i};\n  r.pd = r.cd\
    \ = {x, i};\n  r.p_to_c = x;\n  r.p = r.c = i;\n  return r;\n}\n\ntemplate <typename\
    \ T>\nH<T> compress(const H<T>& p, const H<T>& c) {\n  H<T> r;\n  r.dia = max(max(p.dia,\
    \ c.dia), {p.cd.d + c.pd.d, p.cd.u, c.pd.u});\n  r.pd = max(p.pd, {p.p_to_c +\
    \ c.pd.d, c.pd.u});\n  r.cd = max(c.cd, {c.p_to_c + p.cd.d, p.cd.u});\n  r.p_to_c\
    \ = p.p_to_c + c.p_to_c;\n  r.p = p.p, r.c = c.c;\n  return r;\n}\n\ntemplate\
    \ <typename T>\nL<T> rake(const L<T>& a, const L<T>& b) {\n  L<T> r;\n  r.dia\
    \ = max(a.dia, b.dia);\n  if (a.d1.d > b.d1.d) {\n    r.d1 = a.d1;\n    r.d2 =\
    \ max(a.d2, b.d1);\n  } else {\n    r.d1 = b.d1;\n    r.d2 = max(b.d2, a.d1);\n\
    \  }\n  return r;\n}\n\ntemplate <typename T>\nL<T> add_edge(const H<T>& a) {\n\
    \  L<T> r;\n  r.dia = a.dia;\n  r.d1 = a.pd;\n  r.d2 = {0, -1};\n  return r;\n\
    }\n\ntemplate <typename T>\nH<T> add_vertex(const L<T>& a, T x, int i) {\n  H<T>\
    \ r;\n  r.dia = max(a.dia, {a.d1.d + x + a.d2.d, a.d1.u, a.d2.u});\n  r.pd = r.cd\
    \ = {a.d1.d + x, a.d1.u};\n  r.p_to_c = x;\n  r.p = r.c = i;\n  return r;\n}\n\
    \ntemplate <typename T>\nstruct Aux_Tree {\n  int N, _buf;\n  const WeightedGraph<T>&\
    \ g;\n  vector<vector<int>> aux;\n  vector<T> w;\n  map<pair<int, int>, int> e_to_id;\n\
    \n  Aux_Tree(const WeightedGraph<T>& _g) : g(_g) {\n    N = g.size();\n    aux.resize(2\
    \ * N - 1);\n    w.resize(2 * N - 1);\n    _buf = N;\n    dfs(0, -1);\n    assert(_buf\
    \ == 2 * N - 1);\n  }\n\n  void dfs(int c, int p) {\n    for (auto& d : g[c])\
    \ {\n      if (d == p) continue;\n      int id = _buf++;\n      aux[id].push_back(c),\
    \ aux[c].push_back(id);\n      aux[id].push_back(d), aux[d].push_back(id);\n \
    \     w[id] = d.cost;\n      e_to_id[minmax<int>(c, d)] = id;\n      dfs(d, c);\n\
    \    }\n  }\n};\n\ntemplate <typename T>\nstruct DynamicDiameter {\n  const WeightedGraph<T>&\
    \ g;\n  int n;\n  Aux_Tree<T> aux;\n  HeavyLightDecomposition<vector<vector<int>>>\
    \ hld;\n  DPonStaticTopTreeVertexBased<\n      vector<vector<int>>, H<T>, L<T>,\
    \ function<H<T>(int)>,\n      function<H<T>(const H<T>&, const H<T>&)>,\n    \
    \  function<L<T>(const L<T>&, const L<T>&)>, function<L<T>(const H<T>&)>,\n  \
    \    function<H<T>(const L<T>&, int)>>\n      dp;\n\n  DynamicDiameter(const WeightedGraph<T>&\
    \ _g)\n      : g(_g),\n        n(g.size()),\n        aux(g),\n        hld(aux.aux),\n\
    \        dp(\n            hld, [&](int i) { return vertex(aux.w[i], i < n ? i\
    \ : -1); },\n            [&](const H<T>& p, const H<T>& c) { return compress(p,\
    \ c); },\n            [&](const L<T>& a, const L<T>& b) { return rake(a, b); },\n\
    \            [&](const H<T>& a) { return add_edge(a); },\n            [&](const\
    \ L<T>& a, int i) {\n              return add_vertex(a, aux.w[i], i < n ? i :\
    \ -1);\n            }) {}\n\n  pair<T, pair<int, int>> get() {\n    auto [d, u,\
    \ v] = dp.get().dia;\n    return make_pair(d, make_pair(u, v));\n  }\n\n  void\
    \ update(int u, int v, T x) {\n    assert(aux.e_to_id.count(minmax(u, v)));\n\
    \    int i = aux.e_to_id[minmax(u, v)];\n    aux.w[i] = x;\n    dp.update(i);\n\
    \  }\n};\n}  // namespace DynamicDiameterImpl\n\nusing DynamicDiameterImpl::DynamicDiameter;\n\
    #line 6 \"verify/verify-unit-test/dynamic-diameter.test.cpp\"\nusing namespace\
    \ Nyaan;\n//\n#line 2 \"graph/graph-utility.hpp\"\n\n#line 4 \"graph/graph-utility.hpp\"\
    \n\n// \u4E00\u822C\u306E\u30B0\u30E9\u30D5\u306Est\u304B\u3089\u306E\u8DDD\u96E2\
    \uFF01\uFF01\uFF01\uFF01\n// unvisited nodes : d = -1\nvector<int> Depth(const\
    \ UnweightedGraph &g, int start = 0) {\n  int n = g.size();\n  vector<int> ds(n,\
    \ -1);\n  ds[start] = 0;\n  queue<int> q;\n  q.push(start);\n  while (!q.empty())\
    \ {\n    int c = q.front();\n    q.pop();\n    int dc = ds[c];\n    for (auto\
    \ &d : g[c]) {\n      if (ds[d] == -1) {\n        ds[d] = dc + 1;\n        q.push(d);\n\
    \      }\n    }\n  }\n  return ds;\n}\n\n// Depth of Rooted Weighted Tree\n//\
    \ unvisited nodes : d = -1\ntemplate <typename T>\nvector<T> Depth(const WeightedGraph<T>\
    \ &g, int start = 0) {\n  vector<T> d(g.size(), -1);\n  auto dfs = [&](auto rec,\
    \ int cur, T val, int par = -1) -> void {\n    d[cur] = val;\n    for (auto &dst\
    \ : g[cur]) {\n      if (dst == par) continue;\n      rec(rec, dst, val + dst.cost,\
    \ cur);\n    }\n  };\n  dfs(dfs, start, 0);\n  return d;\n}\n\n// Diameter of\
    \ Tree\n// return value : { {u, v}, length }\npair<pair<int, int>, int> Diameter(const\
    \ UnweightedGraph &g) {\n  auto d = Depth(g, 0);\n  int u = max_element(begin(d),\
    \ end(d)) - begin(d);\n  d = Depth(g, u);\n  int v = max_element(begin(d), end(d))\
    \ - begin(d);\n  return make_pair(make_pair(u, v), d[v]);\n}\n\n// Diameter of\
    \ Weighted Tree\n// return value : { {u, v}, length }\ntemplate <typename T>\n\
    pair<pair<int, int>, T> Diameter(const WeightedGraph<T> &g) {\n  auto d = Depth(g,\
    \ 0);\n  int u = max_element(begin(d), end(d)) - begin(d);\n  d = Depth(g, u);\n\
    \  int v = max_element(begin(d), end(d)) - begin(d);\n  return make_pair(make_pair(u,\
    \ v), d[v]);\n}\n\n// nodes on the path u-v ( O(N) )\ntemplate <typename G>\n\
    vector<int> Path(G &g, int u, int v) {\n  vector<int> ret;\n  int end = 0;\n \
    \ auto dfs = [&](auto rec, int cur, int par = -1) -> void {\n    ret.push_back(cur);\n\
    \    if (cur == v) {\n      end = 1;\n      return;\n    }\n    for (int dst :\
    \ g[cur]) {\n      if (dst == par) continue;\n      rec(rec, dst, cur);\n    \
    \  if (end) return;\n    }\n    if (end) return;\n    ret.pop_back();\n  };\n\
    \  dfs(dfs, u);\n  return ret;\n}\n\n/**\n * @brief \u30B0\u30E9\u30D5\u30E6\u30FC\
    \u30C6\u30A3\u30EA\u30C6\u30A3\n * @docs docs/graph/graph-utility.md\n */\n#line\
    \ 9 \"verify/verify-unit-test/dynamic-diameter.test.cpp\"\n//\n#line 2 \"shortest-path/dijkstra.hpp\"\
    \n\n#line 4 \"shortest-path/dijkstra.hpp\"\n\n// unreachable -> -1\ntemplate <typename\
    \ T>\nvector<T> dijkstra(WeightedGraph<T> &g, int start = 0) {\n  using P = pair<T,\
    \ int>;\n  int N = (int)g.size();\n  vector<T> d(N, T(-1));\n  priority_queue<P,\
    \ vector<P>, greater<P> > Q;\n  d[start] = 0;\n  Q.emplace(0, start);\n  while\
    \ (!Q.empty()) {\n    P p = Q.top();\n    Q.pop();\n    int cur = p.second;\n\
    \    if (d[cur] < p.first) continue;\n    for (auto dst : g[cur]) {\n      if\
    \ (d[dst] == T(-1) || d[cur] + dst.cost < d[dst]) {\n        d[dst] = d[cur] +\
    \ dst.cost;\n        Q.emplace(d[dst], dst);\n      }\n    }\n  }\n  return d;\n\
    }\n\n/**\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n * @docs docs/shortest-path/dijkstra.md\n\
    \ */\n#line 11 \"verify/verify-unit-test/dynamic-diameter.test.cpp\"\n//\n#line\
    \ 2 \"misc/rng.hpp\"\n\n#line 2 \"internal/internal-seed.hpp\"\n\n#line 4 \"internal/internal-seed.hpp\"\
    \nusing namespace std;\n\nnamespace internal {\nunsigned long long non_deterministic_seed()\
    \ {\n  unsigned long long m =\n      chrono::duration_cast<chrono::nanoseconds>(\n\
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \  .count();\n  m ^= 9845834732710364265uLL;\n  m ^= m << 24, m ^= m >> 31, m\
    \ ^= m << 35;\n  return m;\n}\nunsigned long long deterministic_seed() { return\
    \ 88172645463325252UL; }\n\n// 64 bit \u306E seed \u5024\u3092\u751F\u6210 (\u624B\
    \u5143\u3067\u306F seed \u56FA\u5B9A)\n// \u9023\u7D9A\u3067\u547C\u3073\u51FA\
    \u3059\u3068\u540C\u3058\u5024\u304C\u4F55\u5EA6\u3082\u8FD4\u3063\u3066\u304F\
    \u308B\u306E\u3067\u6CE8\u610F\n// #define RANDOMIZED_SEED \u3059\u308B\u3068\u30B7\
    \u30FC\u30C9\u304C\u30E9\u30F3\u30C0\u30E0\u306B\u306A\u308B\nunsigned long long\
    \ seed() {\n#if defined(NyaanLocal) && !defined(RANDOMIZED_SEED)\n  return deterministic_seed();\n\
    #else\n  return non_deterministic_seed();\n#endif\n}\n\n}  // namespace internal\n\
    #line 4 \"misc/rng.hpp\"\n\nnamespace my_rand {\nusing i64 = long long;\nusing\
    \ u64 = unsigned long long;\n\n// [0, 2^64 - 1)\nu64 rng() {\n  static u64 _x\
    \ = internal::seed();\n  return _x ^= _x << 7, _x ^= _x >> 9;\n}\n\n// [l, r]\n\
    i64 rng(i64 l, i64 r) {\n  assert(l <= r);\n  return l + rng() % u64(r - l + 1);\n\
    }\n\n// [l, r)\ni64 randint(i64 l, i64 r) {\n  assert(l < r);\n  return l + rng()\
    \ % u64(r - l);\n}\n\n// choose n numbers from [l, r) without overlapping\nvector<i64>\
    \ randset(i64 l, i64 r, i64 n) {\n  assert(l <= r && n <= r - l);\n  unordered_set<i64>\
    \ s;\n  for (i64 i = n; i; --i) {\n    i64 m = randint(l, r + 1 - i);\n    if\
    \ (s.find(m) != s.end()) m = r - i;\n    s.insert(m);\n  }\n  vector<i64> ret;\n\
    \  for (auto& x : s) ret.push_back(x);\n  sort(begin(ret), end(ret));\n  return\
    \ ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() { return rng() * 5.42101086242752217004e-20;\
    \ }\n// [l, r)\ndouble rnd(double l, double r) {\n  assert(l < r);\n  return l\
    \ + rnd() * (r - l);\n}\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n\
    \  int n = v.size();\n  for (int i = 1; i < n; i++) swap(v[i], v[randint(0, i\
    \ + 1)]);\n}\n\n}  // namespace my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\n\
    using my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n#line 13 \"\
    verify/verify-unit-test/dynamic-diameter.test.cpp\"\n\nvoid test() {\n  ll wmax\
    \ = TEN(9);\n\n  rep1(N, 50) {\n    rep(_, 100) {\n      WeightedGraph<ll> g;\n\
    \      Edges<ll> es;\n      rep1(i, N - 1) {\n        int j = rng(0, i - 1);\n\
    \        es.emplace_back(j, i, rng(0, wmax));\n      }\n\n      auto gen = [&]()\
    \ {\n        g.clear();\n        g.resize(N);\n        each(e, es) {\n       \
    \   g[e.src].emplace_back(e.src, e.to, e.cost);\n          g[e.to].emplace_back(e.to,\
    \ e.src, e.cost);\n        }\n      };\n      gen();\n\n      auto DP = DynamicDiameter(g);\n\
    \n      rep(t, 100) {\n        // check\n        auto [d, uv] = DP.get();\n\n\
    \        ll d2 = -1;\n        {\n          int u = 0;\n          auto du = dijkstra(g,\
    \ u);\n          int v = max_element(all(du)) - begin(du);\n          auto dv\
    \ = dijkstra(g, v);\n          int w = max_element(all(dv)) - begin(dv);\n   \
    \       d2 = dv[w];\n        }\n        assert(uv.first != -1 and uv.second !=\
    \ -1);\n        assert(d == d2);\n        assert(d == dijkstra(g, uv.first)[uv.second]);\n\
    \n        if (N >= 2) {\n          // update\n          int e_num = rng(0, N -\
    \ 2);\n          int u = es[e_num].src, v = es[e_num].to;\n          ll x = rng(0,\
    \ wmax);\n\n          DP.update(u, v, x);\n          es[e_num].cost = x;\n   \
    \       gen();\n        }\n      }\n    }\n  }\n  trc2(\"OK\");\n}\n\nvoid q()\
    \ {\n  test();\n\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n}\n\
    \nvoid Nyaan::solve() {\n  int t = 1;\n  // in(t);\n  while (t--) q();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../tree/dynamic-diameter.hpp\"\
    \nusing namespace Nyaan;\n//\n#include \"../../graph/graph-utility.hpp\"\n//\n\
    #include \"../../shortest-path/dijkstra.hpp\"\n//\n#include \"../../misc/rng.hpp\"\
    \n\nvoid test() {\n  ll wmax = TEN(9);\n\n  rep1(N, 50) {\n    rep(_, 100) {\n\
    \      WeightedGraph<ll> g;\n      Edges<ll> es;\n      rep1(i, N - 1) {\n   \
    \     int j = rng(0, i - 1);\n        es.emplace_back(j, i, rng(0, wmax));\n \
    \     }\n\n      auto gen = [&]() {\n        g.clear();\n        g.resize(N);\n\
    \        each(e, es) {\n          g[e.src].emplace_back(e.src, e.to, e.cost);\n\
    \          g[e.to].emplace_back(e.to, e.src, e.cost);\n        }\n      };\n \
    \     gen();\n\n      auto DP = DynamicDiameter(g);\n\n      rep(t, 100) {\n \
    \       // check\n        auto [d, uv] = DP.get();\n\n        ll d2 = -1;\n  \
    \      {\n          int u = 0;\n          auto du = dijkstra(g, u);\n        \
    \  int v = max_element(all(du)) - begin(du);\n          auto dv = dijkstra(g,\
    \ v);\n          int w = max_element(all(dv)) - begin(dv);\n          d2 = dv[w];\n\
    \        }\n        assert(uv.first != -1 and uv.second != -1);\n        assert(d\
    \ == d2);\n        assert(d == dijkstra(g, uv.first)[uv.second]);\n\n        if\
    \ (N >= 2) {\n          // update\n          int e_num = rng(0, N - 2);\n    \
    \      int u = es[e_num].src, v = es[e_num].to;\n          ll x = rng(0, wmax);\n\
    \n          DP.update(u, v, x);\n          es[e_num].cost = x;\n          gen();\n\
    \        }\n      }\n    }\n  }\n  trc2(\"OK\");\n}\n\nvoid q() {\n  test();\n\
    \n  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n}\n\nvoid Nyaan::solve()\
    \ {\n  int t = 1;\n  // in(t);\n  while (t--) q();\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - tree/dynamic-diameter.hpp
  - graph/graph-template.hpp
  - tree/static-top-tree-vertex-based.hpp
  - tree/convert-tree.hpp
  - tree/heavy-light-decomposition.hpp
  - graph/graph-utility.hpp
  - shortest-path/dijkstra.hpp
  - misc/rng.hpp
  - internal/internal-seed.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/dynamic-diameter.test.cpp
  requiredBy: []
  timestamp: '2024-05-03 21:06:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/dynamic-diameter.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/dynamic-diameter.test.cpp
- /verify/verify/verify-unit-test/dynamic-diameter.test.cpp.html
title: verify/verify-unit-test/dynamic-diameter.test.cpp
---
