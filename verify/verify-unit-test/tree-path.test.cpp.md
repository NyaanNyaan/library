---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find.hpp
    title: Union Find(Disjoint Set Union)
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':question:'
    path: misc/rng.hpp
    title: misc/rng.hpp
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
  - icon: ':heavy_check_mark:'
    path: tree/convert-tree.hpp
    title: "\u6839\u4ED8\u304D\u6728\u30FB\u9006\u8FBA\u304B\u3089\u306A\u308B\u6728\
      \u3078\u306E\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: tree/pruefer-code.hpp
    title: Pruefer Code
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
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"template/template.hpp\"\
    \nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cctype>\n#include\
    \ <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <csetjmp>\n#include\
    \ <csignal>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <ctime>\n#include\
    \ <deque>\n#include <exception>\n#include <forward_list>\n#include <fstream>\n\
    #include <functional>\n#include <initializer_list>\n#include <iomanip>\n#include\
    \ <ios>\n#include <iosfwd>\n#include <iostream>\n#include <istream>\n#include\
    \ <iterator>\n#include <limits>\n#include <list>\n#include <locale>\n#include\
    \ <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n\
    #include <queue>\n#include <random>\n#include <ratio>\n#include <regex>\n#include\
    \ <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n#include\
    \ <streambuf>\n#include <string>\n#include <system_error>\n#include <tuple>\n\
    #include <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <valarray>\n#include <vector>\n\
    \n// utility\n#line 1 \"template/util.hpp\"\nnamespace Nyaan {\nusing ll = long\
    \ long;\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing i128 =\
    \ __int128_t;\nusing u128 = __uint128_t;\n\ntemplate <typename T>\nusing V = vector<T>;\n\
    template <typename T>\nusing VV = vector<vector<T>>;\nusing vi = vector<int>;\n\
    using vl = vector<long long>;\nusing vd = V<double>;\nusing vs = V<string>;\n\
    using vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\n\ntemplate\
    \ <typename T, typename U>\nstruct P : pair<T, U> {\n  template <typename... Args>\n\
    \  P(Args... args) : pair<T, U>(args...) {}\n\n  using pair<T, U>::first;\n  using\
    \ pair<T, U>::second;\n\n  T &x() { return first; }\n  const T &x() const { return\
    \ first; }\n  U &y() { return second; }\n  const U &y() const { return second;\
    \ }\n\n  P &operator+=(const P &r) {\n    first += r.first;\n    second += r.second;\n\
    \    return *this;\n  }\n  P &operator-=(const P &r) {\n    first -= r.first;\n\
    \    second -= r.second;\n    return *this;\n  }\n  P &operator*=(const P &r)\
    \ {\n    first *= r.first;\n    second *= r.second;\n    return *this;\n  }\n\
    \  P operator+(const P &r) const { return P(*this) += r; }\n  P operator-(const\
    \ P &r) const { return P(*this) -= r; }\n  P operator*(const P &r) const { return\
    \ P(*this) *= r; }\n};\n\nusing pl = P<ll, ll>;\nusing pi = P<int, int>;\nusing\
    \ vp = V<pl>;\n\nconstexpr int inf = 1001001001;\nconstexpr long long infLL =\
    \ 4004004004004004004LL;\n\ntemplate <typename T>\nint sz(const T &t) {\n  return\
    \ t.size();\n}\ntemplate <typename T, size_t N>\nvoid mem(T (&a)[N], int c) {\n\
    \  memset(a, c, sizeof(T) * N);\n}\n\ntemplate <typename T, typename U>\ninline\
    \ bool amin(T &x, U y) {\n  return (y < x) ? (x = y, true) : false;\n}\ntemplate\
    \ <typename T, typename U>\ninline bool amax(T &x, U y) {\n  return (x < y) ?\
    \ (x = y, true) : false;\n}\n\ntemplate <typename T>\nint lb(const vector<T> &v,\
    \ const T &a) {\n  return lower_bound(begin(v), end(v), a) - begin(v);\n}\ntemplate\
    \ <typename T>\nint ub(const vector<T> &v, const T &a) {\n  return upper_bound(begin(v),\
    \ end(v), a) - begin(v);\n}\n\nconstexpr long long TEN(int n) {\n  long long ret\
    \ = 1, x = 10;\n  for (; n; x *= x, n >>= 1) ret *= (n & 1 ? x : 1);\n  return\
    \ ret;\n}\n\ntemplate <typename T, typename U>\npair<T, U> mkp(const T &t, const\
    \ U &u) {\n  return make_pair(t, u);\n}\n\ntemplate <typename T>\nvector<T> mkrui(const\
    \ vector<T> &v, bool rev = false) {\n  vector<T> ret(v.size() + 1);\n  if (rev)\
    \ {\n    for (int i = int(v.size()) - 1; i >= 0; i--) ret[i] = v[i] + ret[i +\
    \ 1];\n  } else {\n    for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i]\
    \ + v[i];\n  }\n  return ret;\n};\n\ntemplate <typename T>\nvector<T> mkuni(const\
    \ vector<T> &v) {\n  vector<T> ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(),\
    \ ret.end()), ret.end());\n  return ret;\n}\n\ntemplate <typename F>\nvector<int>\
    \ mkord(int N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n\
    \  sort(begin(ord), end(ord), f);\n  return ord;\n}\n\ntemplate <typename T>\n\
    vector<T> reord(const vector<T> &v, const vector<T> &ord) {\n  int N = v.size();\n\
    \  vector<T> ret(N);\n  for (int i = 0; i < N; i++) ret[i] = v[ord[i]];\n  return\
    \ ret;\n};\n\ntemplate <typename T = int>\nvector<T> mkiota(int N) {\n  vector<T>\
    \ ret(N);\n  iota(begin(ret), end(ret), 0);\n  return ret;\n}\n\ntemplate <typename\
    \ T>\nvector<int> mkinv(vector<T> &v, int max_val = -1) {\n  if (max_val < (int)v.size())\
    \ max_val = v.size() - 1;\n  vector<int> inv(max_val + 1, -1);\n  for (int i =\
    \ 0; i < (int)v.size(); i++) inv[v[i]] = i;\n  return inv;\n}\n\n}  // namespace\
    \ Nyaan\n#line 70 \"template/template.hpp\"\n\n// bit operation\n#line 1 \"template/bitop.hpp\"\
    \nnamespace Nyaan {\n\n__attribute__((target(\"popcnt\"))) inline int popcnt(const\
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
    \ 4 \"verify/verify-unit-test/tree-path.test.cpp\"\n//\n#line 2 \"data-structure/union-find.hpp\"\
    \n\nstruct UnionFind {\n  vector<int> data;\n  UnionFind(int N) : data(N, -1)\
    \ {}\n\n  int find(int k) { return data[k] < 0 ? k : data[k] = find(data[k]);\
    \ }\n\n  int unite(int x, int y) {\n    if ((x = find(x)) == (y = find(y))) return\
    \ false;\n    if (data[x] > data[y]) swap(x, y);\n    data[x] += data[y];\n  \
    \  data[y] = x;\n    return true;\n  }\n\n  // f ... merge function\n  template<typename\
    \ F>\n  int unite(int x, int y,const F &f) {\n    if ((x = find(x)) == (y = find(y)))\
    \ return false;\n    if (data[x] > data[y]) swap(x, y);\n    data[x] += data[y];\n\
    \    data[y] = x;\n    f(x, y);\n    return true;\n  }\n\n  int size(int k) {\
    \ return -data[find(k)]; }\n\n  int same(int x, int y) { return find(x) == find(y);\
    \ }\n};\n\n/**\n * @brief Union Find(Disjoint Set Union)\n * @docs docs/data-structure/union-find.md\n\
    \ */\n#line 2 \"misc/rng.hpp\"\n\n\n\nnamespace my_rand {\n\n// [0, 2^64 - 1)\n\
    uint64_t rng() {\n  static uint64_t x_ =\n      uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
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
    \ uint64_t p = uint64_t(1023 - 64) << 52;\n  return rng() * ((raw_cast*)(&p))->t;\n\
    }\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n\
    \  for (int loop = 0; loop < 2; loop++)\n    for (int i = 0; i < n; i++) swap(v[i],\
    \ v[randint(0, n)]);\n}\n\n}  // namespace my_rand\n\nusing my_rand::randint;\n\
    using my_rand::randset;\nusing my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n\
    #line 2 \"tree/convert-tree.hpp\"\n\nvector<vector<int>> inverse_tree(const vector<vector<int>>&\
    \ g, int root = 0) {\n  int N = (int)g.size();\n  vector<vector<int>> rg(N);\n\
    \  vector<char> v(N);\n  for (int i = 0; i < N; i++)\n    for (auto& j : g[i])\
    \ {\n      rg[j].push_back(i);\n    }\n  return rg;\n}\n\nvector<vector<int>>\
    \ rooted_tree(const vector<vector<int>>& g, int root = 0) {\n  int N = (int)g.size();\n\
    \  vector<vector<int>> rg(N);\n  vector<bool> v(N, false);\n  v[root] = 1;\n \
    \ queue<int> que;\n  que.emplace(root);\n  while (!que.empty()) {\n    auto p\
    \ = que.front();\n    que.pop();\n    for (auto& e : g[p]) {\n      if (v[e] ==\
    \ false) {\n        v[e] = true;\n        que.push(e);\n        rg[p].push_back(e);\n\
    \      }\n    }\n  }\n  return rg;\n}\n\n/**\n * @brief \u6839\u4ED8\u304D\u6728\
    \u30FB\u9006\u8FBA\u304B\u3089\u306A\u308B\u6728\u3078\u306E\u5909\u63DB\n */\n\
    #line 2 \"tree/pruefer-code.hpp\"\n\n#line 4 \"tree/pruefer-code.hpp\"\n\n// input:\
    \ [c \\in [0, n)] * (n-2), n>=3\nvector<vector<int>> pruefer_code(const vector<int>&\
    \ code) {\n  int n = code.size() + 2;\n  assert(n > 2);\n  vector<vector<int>>\
    \ g(n);\n  vector<int> deg(n, 1);\n  int e = 0;\n  for (auto& x : code) deg[x]++;\n\
    \  for (auto& i : code) {\n    for (int j = 0; j < n; j++) {\n      if (deg[j]\
    \ == 1) {\n        g[i].push_back(j);\n        g[j].push_back(i);\n        deg[i]--,\
    \ deg[j]--;\n        e++;\n        break;\n      }\n    }\n  }\n  int u = -1,\
    \ v = -1;\n  for (int i = 0; i < n; i++) {\n    if (deg[i] == 1) (u == -1 ? u\
    \ : v) = i;\n  }\n  assert(u != -1 and v != -1);\n  g[u].push_back(v);\n  g[v].push_back(u);\n\
    \  e++;\n  assert(e == n - 1);\n  return g;\n}\n\nvector<vector<int>> random_tree(int\
    \ n) {\n  if (n <= 2) {\n    vector<vector<int>> g(n);\n    if (n == 2) {\n  \
    \    g[0].push_back(1);\n      g[1].push_back(0);\n    }\n    return g;\n  }\n\
    \  vector<int> pruefer(n - 2);\n  for (auto& x : pruefer) x = randint(0, n);\n\
    \  return pruefer_code(pruefer);\n}\n\n/**\n * @brief Pruefer Code\n */\n#line\
    \ 2 \"graph/graph-template.hpp\"\n\ntemplate <typename T>\nstruct edge {\n  int\
    \ src, to;\n  T cost;\n\n  edge(int _to, T _cost) : src(-1), to(_to), cost(_cost)\
    \ {}\n  edge(int _src, int _to, T _cost) : src(_src), to(_to), cost(_cost) {}\n\
    \n  edge &operator=(const int &x) {\n    to = x;\n    return *this;\n  }\n\n \
    \ operator int() const { return to; }\n};\ntemplate <typename T>\nusing Edges\
    \ = vector<edge<T>>;\ntemplate <typename T>\nusing WeightedGraph = vector<Edges<T>>;\n\
    using UnweightedGraph = vector<vector<int>>;\n\n// Input of (Unweighted) Graph\n\
    UnweightedGraph graph(int N, int M = -1, bool is_directed = false,\n         \
    \             bool is_1origin = true) {\n  UnweightedGraph g(N);\n  if (M == -1)\
    \ M = N - 1;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >>\
    \ y;\n    if (is_1origin) x--, y--;\n    g[x].push_back(y);\n    if (!is_directed)\
    \ g[y].push_back(x);\n  }\n  return g;\n}\n\n// Input of Weighted Graph\ntemplate\
    \ <typename T>\nWeightedGraph<T> wgraph(int N, int M = -1, bool is_directed =\
    \ false,\n                        bool is_1origin = true) {\n  WeightedGraph<T>\
    \ g(N);\n  if (M == -1) M = N - 1;\n  for (int _ = 0; _ < M; _++) {\n    int x,\
    \ y;\n    cin >> x >> y;\n    T c;\n    cin >> c;\n    if (is_1origin) x--, y--;\n\
    \    g[x].emplace_back(x, y, c);\n    if (!is_directed) g[y].emplace_back(y, x,\
    \ c);\n  }\n  return g;\n}\n\n// Input of Edges\ntemplate <typename T>\nEdges<T>\
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
    \ d;\n}\n#line 3 \"tree/tree-query.hpp\"\n\ntemplate <typename G>\nstruct Tree\
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
    \ */\n#line 10 \"verify/verify-unit-test/tree-path.test.cpp\"\n\nusing namespace\
    \ Nyaan;\n\nbool is_tree(vvi& g, bool directed = false) {\n  int n = g.size();\n\
    \  UnionFind uf(n);\n  rep(i, n) each(j, g[i]) {\n    if (!directed and i > j)\
    \ continue;\n    if (!uf.unite(i, j)) return false;\n  }\n  return uf.size(0)\
    \ == n;\n}\n\nbool is_rooted_tree(vvi& g, int root) {\n  int n = g.size();\n \
    \ vector<bool> vis(n, false);\n  auto dfs = [&](auto rc, int c) -> void {\n  \
    \  vis[c] = true;\n    each(d, g[c]) {\n      assert(vis[d] == false);\n     \
    \ rc(rc, d);\n    }\n  };\n  dfs(dfs, root);\n  int sm = 0;\n  each(b, vis) sm\
    \ += !!b;\n  return sm == n;\n}\n\nbool is_inverse_tree(vvi& g, vvi& rg) {\n \
    \ set<pair<int, int>> s, t;\n  int n = g.size();\n  for (int i = 0; i < n; i++)\
    \ {\n    for (int& j : g[i]) s.emplace(i, j);\n    for (int& j : rg[i]) t.emplace(j,\
    \ i);\n  }\n  return s == t;\n}\n\nvoid test_tree_query(vvi& g, int root = 0)\
    \ {\n  Tree<vvi> tree(g, root);\n  int N = sz(g);\n  rep(i, N) rep(j, N) {\n \
    \   vi p1 = tree.path(i, j);\n    vi p2{int(i)};\n    for (int k = i; k != j;)\
    \ {\n      p2.push_back(k = tree.nxt(k, j));\n    }\n    assert(p1 == p2);\n \
    \   int l = i, ld = tree.depth(i);\n    each(x, p1) if (amin(ld, tree.depth(x)))\
    \ l = x;\n    assert(l == tree.lca(i, j));\n  }\n}\n\nusing namespace Nyaan;\n\
    void Nyaan::solve() {\n  \n  // Random Tree\n  for (int N : vi{2, 3, 4, 5, 10,\
    \ 100}) {\n    vvi g = random_tree(N);\n    assert(is_tree(g) && \"random tree\"\
    );\n    test_tree_query(g);\n\n    int root = randint(0, N);\n    vvi rg = rooted_tree(g,\
    \ root);\n    assert(is_tree(rg, true) && \"rooted tree\");\n    test_tree_query(rg,\
    \ root);\n\n    vvi rh = inverse_tree(rg);\n    assert(is_inverse_tree(rg, rh)\
    \ && \"inverse tree\");\n  }\n\n  // Line Tree\n  for (int N : vi{2, 3, 4, 5,\
    \ 10, 100}) {\n    vvi g(N);\n    rep1(i, N - 1) g[i - 1].push_back(i);\n    test_tree_query(g);\n\
    \  }\n\n  // Preufer Code\n  {\n    V<vvi> gs(125);\n    rep(i, 125) {\n     \
    \ vi pr(3);\n      for (int j = i, k = 0; k < 3; j /= 5, k++) {\n        pr[k]\
    \ = j % 5;\n      }\n      gs[i] = pruefer_code(pr);\n      for (auto& es : gs[i])\
    \ sort(begin(es), end(es));\n    }\n    rep(i, 125) assert(is_tree(gs[i]));\n\
    \    rep(i, 125) rep(j, i) assert(gs[i] != gs[j]);\n  }\n\n  int a, b;\n  cin\
    \ >> a >> b;\n  cout << a + b << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../template/template.hpp\"\n//\n#include \"../../data-structure/union-find.hpp\"\
    \n#include \"../../misc/rng.hpp\"\n#include \"../../tree/convert-tree.hpp\"\n\
    #include \"../../tree/pruefer-code.hpp\"\n#include \"../../tree/tree-query.hpp\"\
    \n\nusing namespace Nyaan;\n\nbool is_tree(vvi& g, bool directed = false) {\n\
    \  int n = g.size();\n  UnionFind uf(n);\n  rep(i, n) each(j, g[i]) {\n    if\
    \ (!directed and i > j) continue;\n    if (!uf.unite(i, j)) return false;\n  }\n\
    \  return uf.size(0) == n;\n}\n\nbool is_rooted_tree(vvi& g, int root) {\n  int\
    \ n = g.size();\n  vector<bool> vis(n, false);\n  auto dfs = [&](auto rc, int\
    \ c) -> void {\n    vis[c] = true;\n    each(d, g[c]) {\n      assert(vis[d] ==\
    \ false);\n      rc(rc, d);\n    }\n  };\n  dfs(dfs, root);\n  int sm = 0;\n \
    \ each(b, vis) sm += !!b;\n  return sm == n;\n}\n\nbool is_inverse_tree(vvi& g,\
    \ vvi& rg) {\n  set<pair<int, int>> s, t;\n  int n = g.size();\n  for (int i =\
    \ 0; i < n; i++) {\n    for (int& j : g[i]) s.emplace(i, j);\n    for (int& j\
    \ : rg[i]) t.emplace(j, i);\n  }\n  return s == t;\n}\n\nvoid test_tree_query(vvi&\
    \ g, int root = 0) {\n  Tree<vvi> tree(g, root);\n  int N = sz(g);\n  rep(i, N)\
    \ rep(j, N) {\n    vi p1 = tree.path(i, j);\n    vi p2{int(i)};\n    for (int\
    \ k = i; k != j;) {\n      p2.push_back(k = tree.nxt(k, j));\n    }\n    assert(p1\
    \ == p2);\n    int l = i, ld = tree.depth(i);\n    each(x, p1) if (amin(ld, tree.depth(x)))\
    \ l = x;\n    assert(l == tree.lca(i, j));\n  }\n}\n\nusing namespace Nyaan;\n\
    void Nyaan::solve() {\n  \n  // Random Tree\n  for (int N : vi{2, 3, 4, 5, 10,\
    \ 100}) {\n    vvi g = random_tree(N);\n    assert(is_tree(g) && \"random tree\"\
    );\n    test_tree_query(g);\n\n    int root = randint(0, N);\n    vvi rg = rooted_tree(g,\
    \ root);\n    assert(is_tree(rg, true) && \"rooted tree\");\n    test_tree_query(rg,\
    \ root);\n\n    vvi rh = inverse_tree(rg);\n    assert(is_inverse_tree(rg, rh)\
    \ && \"inverse tree\");\n  }\n\n  // Line Tree\n  for (int N : vi{2, 3, 4, 5,\
    \ 10, 100}) {\n    vvi g(N);\n    rep1(i, N - 1) g[i - 1].push_back(i);\n    test_tree_query(g);\n\
    \  }\n\n  // Preufer Code\n  {\n    V<vvi> gs(125);\n    rep(i, 125) {\n     \
    \ vi pr(3);\n      for (int j = i, k = 0; k < 3; j /= 5, k++) {\n        pr[k]\
    \ = j % 5;\n      }\n      gs[i] = pruefer_code(pr);\n      for (auto& es : gs[i])\
    \ sort(begin(es), end(es));\n    }\n    rep(i, 125) assert(is_tree(gs[i]));\n\
    \    rep(i, 125) rep(j, i) assert(gs[i] != gs[j]);\n  }\n\n  int a, b;\n  cin\
    \ >> a >> b;\n  cout << a + b << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - data-structure/union-find.hpp
  - misc/rng.hpp
  - tree/convert-tree.hpp
  - tree/pruefer-code.hpp
  - tree/tree-query.hpp
  - graph/graph-template.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/tree-path.test.cpp
  requiredBy: []
  timestamp: '2020-12-05 20:52:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/tree-path.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/tree-path.test.cpp
- /verify/verify/verify-unit-test/tree-path.test.cpp.html
title: verify/verify-unit-test/tree-path.test.cpp
---
