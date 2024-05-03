---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/rollback-union-find.hpp
    title: "Rollback\u3064\u304DUnion Find"
  - icon: ':heavy_check_mark:'
    path: graph/offline-dynamic-connectivity.hpp
    title: graph/offline-dynamic-connectivity.hpp
  - icon: ':heavy_check_mark:'
    path: hashmap/hashmap-base.hpp
    title: "Hash Map(base)\u3000(\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7\u30FB\u57FA\
      \u5E95\u30AF\u30E9\u30B9)"
  - icon: ':heavy_check_mark:'
    path: hashmap/hashmap.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7(\u9023\u60F3\u914D\u5217)"
  - icon: ':heavy_check_mark:'
    path: lct/link-cut-base.hpp
    title: Link/Cut Tree(base)
  - icon: ':heavy_check_mark:'
    path: lct/link-cut-tree-subtree.hpp
    title: "\u90E8\u5206\u6728\u30AF\u30A8\u30EALink/Cut Tree"
  - icon: ':heavy_check_mark:'
    path: lct/reversible-bbst-base.hpp
    title: "\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\
      \u30E9\u30B9)"
  - icon: ':heavy_check_mark:'
    path: lct/splay-base.hpp
    title: Splay Tree(base)
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-offline-dynamic-connectivity.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n\n#line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n\
    #include <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
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
    \ T>\nbool nxp(T &v) {\n  return next_permutation(begin(v), end(v));\n}\n\n//\
    \ \u8FD4\u308A\u5024\u306E\u578B\u306F\u5165\u529B\u306E T \u306B\u4F9D\u5B58\n\
    // i \u8981\u7D20\u76EE : [0, a[i])\ntemplate <typename T>\nvector<vector<T>>\
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
    \u308B\ntemplate <typename T>\nT Power(T a, long long n, const T &I = T{1}) {\n\
    \  return Power(a, n, I, function<void(T &)>{[](T &) -> void {}});\n}\n\ntemplate\
    \ <typename T>\nT Rev(const T &v) {\n  T res = v;\n  reverse(begin(res), end(res));\n\
    \  return res;\n}\n\ntemplate <typename T>\nvector<T> Transpose(const vector<T>\
    \ &v) {\n  using U = typename T::value_type;\n  if(v.empty()) return {};\n  int\
    \ H = v.size(), W = v[0].size();\n  vector res(W, T(H, U{}));\n  for (int i =\
    \ 0; i < H; i++) {\n    for (int j = 0; j < W; j++) {\n      res[j][i] = v[i][j];\n\
    \    }\n  }\n  return res;\n}\n\ntemplate <typename T>\nvector<T> Rotate(const\
    \ vector<T> &v, int clockwise = true) {\n  using U = typename T::value_type;\n\
    \  int H = v.size(), W = v[0].size();\n  vector res(W, T(H, U{}));\n  for (int\
    \ i = 0; i < H; i++) {\n    for (int j = 0; j < W; j++) {\n      if (clockwise)\
    \ {\n        res[W - 1 - j][i] = v[i][j];\n      } else {\n        res[j][H -\
    \ 1 - i] = v[i][j];\n      }\n    }\n  }\n  return res;\n}\n\n}  // namespace\
    \ Nyaan\n#line 58 \"template/template.hpp\"\n\n// bit operation\n#line 1 \"template/bitop.hpp\"\
    \nnamespace Nyaan {\n__attribute__((target(\"popcnt\"))) inline int popcnt(const\
    \ u64 &a) {\n  return __builtin_popcountll(a);\n}\ninline int lsb(const u64 &a)\
    \ { return a ? __builtin_ctzll(a) : 64; }\ninline int ctz(const u64 &a) { return\
    \ a ? __builtin_ctzll(a) : 64; }\ninline int msb(const u64 &a) { return a ? 63\
    \ - __builtin_clzll(a) : -1; }\ntemplate <typename T>\ninline int gbit(const T\
    \ &a, int i) {\n  return (a >> i) & 1;\n}\ntemplate <typename T>\ninline void\
    \ sbit(T &a, int i, bool b) {\n  if (gbit(a, i) != b) a ^= T(1) << i;\n}\nconstexpr\
    \ long long PW(int n) { return 1LL << n; }\nconstexpr long long MSK(int n) { return\
    \ (1LL << n) - 1; }\n}  // namespace Nyaan\n#line 61 \"template/template.hpp\"\
    \n\n// inout\n#line 1 \"template/inout.hpp\"\nnamespace Nyaan {\n\ntemplate <typename\
    \ T, typename U>\nostream &operator<<(ostream &os, const pair<T, U> &p) {\n  os\
    \ << p.first << \" \" << p.second;\n  return os;\n}\ntemplate <typename T, typename\
    \ U>\nistream &operator>>(istream &is, pair<T, U> &p) {\n  is >> p.first >> p.second;\n\
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
    \ \" \";\n  dump(head);\n  if (sizeof...(tail) != 0) cerr << \",\";\n  trace(std::forward<Tail>(tail)...);\n\
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
    \ 5 \"verify/verify-yosupo-ds/yosupo-offline-dynamic-connectivity.test.cpp\"\n\
    //\n#line 2 \"graph/offline-dynamic-connectivity.hpp\"\n\n#line 2 \"data-structure/rollback-union-find.hpp\"\
    \n\nstruct RollbackUnionFind {\n  vector<int> data;\n  stack<pair<int, int> >\
    \ history;\n  int inner_snap;\n\n  RollbackUnionFind(int sz) : inner_snap(0) {\
    \ data.assign(sz, -1); }\n\n  bool unite(int x, int y) {\n    x = find(x), y =\
    \ find(y);\n    history.emplace(x, data[x]);\n    history.emplace(y, data[y]);\n\
    \    if (x == y) return false;\n    if (data[x] > data[y]) swap(x, y);\n    data[x]\
    \ += data[y];\n    data[y] = x;\n    return true;\n  }\n\n  int find(int k) {\n\
    \    if (data[k] < 0) return k;\n    return find(data[k]);\n  }\n\n  int same(int\
    \ x, int y) { return find(x) == find(y); }\n\n  int size(int k) { return (-data[find(k)]);\
    \ }\n\n  void undo() {\n    data[history.top().first] = history.top().second;\n\
    \    history.pop();\n    data[history.top().first] = history.top().second;\n \
    \   history.pop();\n  }\n\n  void snapshot() { inner_snap = int(history.size()\
    \ >> 1); }\n\n  int get_state() { return int(history.size() >> 1); }\n\n  void\
    \ rollback(int state = -1) {\n    if (state == -1) state = inner_snap;\n    state\
    \ <<= 1;\n    assert(state <= (int)history.size());\n    while (state < (int)history.size())\
    \ undo();\n  }\n};\n\n/**\n * @brief Rollback\u3064\u304DUnion Find\n * @docs\
    \ docs/data-structure/rollback-union-find.md\n */\n#line 2 \"hashmap/hashmap.hpp\"\
    \n\n#line 2 \"hashmap/hashmap-base.hpp\"\n\n#line 4 \"hashmap/hashmap-base.hpp\"\
    \nusing namespace std;\n\nnamespace HashMapImpl {\nusing u32 = uint32_t;\nusing\
    \ u64 = uint64_t;\n\ntemplate <typename Key, typename Data>\nstruct HashMapBase;\n\
    \ntemplate <typename Key, typename Data>\nstruct itrB\n    : iterator<bidirectional_iterator_tag,\
    \ Data, ptrdiff_t, Data*, Data&> {\n  using base =\n      iterator<bidirectional_iterator_tag,\
    \ Data, ptrdiff_t, Data*, Data&>;\n  using ptr = typename base::pointer;\n  using\
    \ ref = typename base::reference;\n\n  u32 i;\n  HashMapBase<Key, Data>* p;\n\n\
    \  explicit constexpr itrB() : i(0), p(nullptr) {}\n  explicit constexpr itrB(u32\
    \ _i, HashMapBase<Key, Data>* _p) : i(_i), p(_p) {}\n  explicit constexpr itrB(u32\
    \ _i, const HashMapBase<Key, Data>* _p)\n      : i(_i), p(const_cast<HashMapBase<Key,\
    \ Data>*>(_p)) {}\n  friend void swap(itrB& l, itrB& r) { swap(l.i, r.i), swap(l.p,\
    \ r.p); }\n  friend bool operator==(const itrB& l, const itrB& r) { return l.i\
    \ == r.i; }\n  friend bool operator!=(const itrB& l, const itrB& r) { return l.i\
    \ != r.i; }\n  const ref operator*() const {\n    return const_cast<const HashMapBase<Key,\
    \ Data>*>(p)->data[i];\n  }\n  ref operator*() { return p->data[i]; }\n  ptr operator->()\
    \ const { return &(p->data[i]); }\n\n  itrB& operator++() {\n    assert(i != p->cap\
    \ && \"itr::operator++()\");\n    do {\n      i++;\n      if (i == p->cap) break;\n\
    \      if (p->occupied_flag[i] && !p->deleted_flag[i]) break;\n    } while (true);\n\
    \    return (*this);\n  }\n  itrB operator++(int) {\n    itrB it(*this);\n   \
    \ ++(*this);\n    return it;\n  }\n  itrB& operator--() {\n    do {\n      i--;\n\
    \      if (p->occupied_flag[i] && !p->deleted_flag[i]) break;\n      assert(i\
    \ != 0 && \"itr::operator--()\");\n    } while (true);\n    return (*this);\n\
    \  }\n  itrB operator--(int) {\n    itrB it(*this);\n    --(*this);\n    return\
    \ it;\n  }\n};\n\ntemplate <typename Key, typename Data>\nstruct HashMapBase {\n\
    \  using u32 = uint32_t;\n  using u64 = uint64_t;\n  using iterator = itrB<Key,\
    \ Data>;\n  using itr = iterator;\n\n protected:\n  template <typename K>\n  inline\
    \ u64 randomized(const K& key) const {\n    return u64(key) ^ r;\n  }\n\n  template\
    \ <typename K,\n            enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,\n\
    \            enable_if_t<is_integral<K>::value, nullptr_t> = nullptr>\n  inline\
    \ u32 inner_hash(const K& key) const {\n    return (randomized(key) * 11995408973635179863ULL)\
    \ >> shift;\n  }\n  template <\n      typename K, enable_if_t<is_same<K, Key>::value,\
    \ nullptr_t> = nullptr,\n      enable_if_t<is_integral<decltype(K::first)>::value,\
    \ nullptr_t> = nullptr,\n      enable_if_t<is_integral<decltype(K::second)>::value,\
    \ nullptr_t> = nullptr>\n  inline u32 inner_hash(const K& key) const {\n    u64\
    \ a = randomized(key.first), b = randomized(key.second);\n    a *= 11995408973635179863ULL;\n\
    \    b *= 10150724397891781847ULL;\n    return (a + b) >> shift;\n  }\n  template\
    \ <typename K,\n            enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,\n\
    \            enable_if_t<is_integral<typename K::value_type>::value, nullptr_t>\
    \ =\n                nullptr>\n  inline u32 inner_hash(const K& key) const {\n\
    \    static constexpr u64 mod = (1LL << 61) - 1;\n    static constexpr u64 base\
    \ = 950699498548472943ULL;\n    u64 res = 0;\n    for (auto& elem : key) {\n \
    \     __uint128_t x = __uint128_t(res) * base + (randomized(elem) & mod);\n  \
    \    res = (x & mod) + (x >> 61);\n    }\n    __uint128_t x = __uint128_t(res)\
    \ * base;\n    res = (x & mod) + (x >> 61);\n    if (res >= mod) res -= mod;\n\
    \    return res >> (shift - 3);\n  }\n\n  template <typename D = Data,\n     \
    \       enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr>\n  inline u32\
    \ hash(const D& dat) const {\n    return inner_hash(dat);\n  }\n  template <\n\
    \      typename D = Data,\n      enable_if_t<is_same<decltype(D::first), Key>::value,\
    \ nullptr_t> = nullptr>\n  inline u32 hash(const D& dat) const {\n    return inner_hash(dat.first);\n\
    \  }\n\n  template <typename D = Data,\n            enable_if_t<is_same<D, Key>::value,\
    \ nullptr_t> = nullptr>\n  inline Key data_to_key(const D& dat) const {\n    return\
    \ dat;\n  }\n  template <\n      typename D = Data,\n      enable_if_t<is_same<decltype(D::first),\
    \ Key>::value, nullptr_t> = nullptr>\n  inline Key data_to_key(const D& dat) const\
    \ {\n    return dat.first;\n  }\n\n  void reallocate(u32 ncap) {\n    vector<Data>\
    \ ndata(ncap);\n    vector<bool> nf(ncap);\n    shift = 64 - __lg(ncap);\n   \
    \ for (u32 i = 0; i < cap; i++) {\n      if (occupied_flag[i] && !deleted_flag[i])\
    \ {\n        u32 h = hash(data[i]);\n        while (nf[h]) h = (h + 1) & (ncap\
    \ - 1);\n        ndata[h] = move(data[i]);\n        nf[h] = true;\n      }\n \
    \   }\n    data.swap(ndata);\n    occupied_flag.swap(nf);\n    cap = ncap;\n \
    \   occupied = s;\n    deleted_flag.resize(cap);\n    fill(std::begin(deleted_flag),\
    \ std::end(deleted_flag), false);\n  }\n\n  inline bool extend_rate(u32 x) const\
    \ { return x * 2 >= cap; }\n\n  inline bool shrink_rate(u32 x) const {\n    return\
    \ HASHMAP_DEFAULT_SIZE < cap && x * 10 <= cap;\n  }\n\n  inline void extend()\
    \ { reallocate(cap << 1); }\n\n  inline void shrink() { reallocate(cap >> 1);\
    \ }\n\n public:\n  u32 cap, s, occupied;\n  vector<Data> data;\n  vector<bool>\
    \ occupied_flag, deleted_flag;\n  u32 shift;\n  static u64 r;\n  static constexpr\
    \ uint32_t HASHMAP_DEFAULT_SIZE = 4;\n\n  explicit HashMapBase()\n      : cap(HASHMAP_DEFAULT_SIZE),\n\
    \        s(0),\n        occupied(0),\n        data(cap),\n        occupied_flag(cap),\n\
    \        deleted_flag(cap),\n        shift(64 - __lg(cap)) {}\n\n  itr begin()\
    \ const {\n    u32 h = 0;\n    while (h != cap) {\n      if (occupied_flag[h]\
    \ && !deleted_flag[h]) break;\n      h++;\n    }\n    return itr(h, this);\n \
    \ }\n  itr end() const { return itr(this->cap, this); }\n\n  friend itr begin(const\
    \ HashMapBase& h) { return h.begin(); }\n  friend itr end(const HashMapBase& h)\
    \ { return h.end(); }\n\n  itr find(const Key& key) const {\n    u32 h = inner_hash(key);\n\
    \    while (true) {\n      if (occupied_flag[h] == false) return this->end();\n\
    \      if (data_to_key(data[h]) == key) {\n        if (deleted_flag[h] == true)\
    \ return this->end();\n        return itr(h, this);\n      }\n      h = (h + 1)\
    \ & (cap - 1);\n    }\n  }\n\n  bool contain(const Key& key) const { return find(key)\
    \ != this->end(); }\n\n  itr insert(const Data& d) {\n    u32 h = hash(d);\n \
    \   while (true) {\n      if (occupied_flag[h] == false) {\n        if (extend_rate(occupied\
    \ + 1)) {\n          extend();\n          h = hash(d);\n          continue;\n\
    \        }\n        data[h] = d;\n        occupied_flag[h] = true;\n        ++occupied,\
    \ ++s;\n        return itr(h, this);\n      }\n      if (data_to_key(data[h])\
    \ == data_to_key(d)) {\n        if (deleted_flag[h] == true) {\n          data[h]\
    \ = d;\n          deleted_flag[h] = false;\n          ++s;\n        }\n      \
    \  return itr(h, this);\n      }\n      h = (h + 1) & (cap - 1);\n    }\n  }\n\
    \n  // tips for speed up :\n  // if return value is unnecessary, make argument_2\
    \ false.\n  itr erase(itr it, bool get_next = true) {\n    if (it == this->end())\
    \ return this->end();\n    s--;\n    if (!get_next) {\n      this->deleted_flag[it.i]\
    \ = true;\n      if (shrink_rate(s)) shrink();\n      return this->end();\n  \
    \  }\n    itr nxt = it;\n    nxt++;\n    this->deleted_flag[it.i] = true;\n  \
    \  if (shrink_rate(s)) {\n      Data d = data[nxt.i];\n      shrink();\n     \
    \ it = find(data_to_key(d));\n    }\n    return nxt;\n  }\n\n  itr erase(const\
    \ Key& key) { return erase(find(key)); }\n\n  int count(const Key& key) { return\
    \ find(key) == end() ? 0 : 1; }\n\n  bool empty() const { return s == 0; }\n\n\
    \  int size() const { return s; }\n\n  void clear() {\n    fill(std::begin(occupied_flag),\
    \ std::end(occupied_flag), false);\n    fill(std::begin(deleted_flag), std::end(deleted_flag),\
    \ false);\n    s = occupied = 0;\n  }\n\n  void reserve(int n) {\n    if (n <=\
    \ 0) return;\n    n = 1 << min(23, __lg(n) + 2);\n    if (cap < u32(n)) reallocate(n);\n\
    \  }\n};\n\ntemplate <typename Key, typename Data>\nuint64_t HashMapBase<Key,\
    \ Data>::r =\n    chrono::duration_cast<chrono::nanoseconds>(\n        chrono::high_resolution_clock::now().time_since_epoch())\n\
    \        .count();\n\n}  // namespace HashMapImpl\n\n/**\n * @brief Hash Map(base)\u3000\
    (\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7\u30FB\u57FA\u5E95\u30AF\u30E9\u30B9\
    )\n */\n#line 4 \"hashmap/hashmap.hpp\"\n\ntemplate <typename Key, typename Val>\n\
    struct HashMap : HashMapImpl::HashMapBase<Key, pair<Key, Val>> {\n  using base\
    \ = typename HashMapImpl::HashMapBase<Key, pair<Key, Val>>;\n  using HashMapImpl::HashMapBase<Key,\
    \ pair<Key, Val>>::HashMapBase;\n  using Data = pair<Key, Val>;\n\n  Val& operator[](const\
    \ Key& k) {\n    typename base::u32 h = base::inner_hash(k);\n    while (true)\
    \ {\n      if (base::occupied_flag[h] == false) {\n        if (base::extend_rate(base::occupied\
    \ + 1)) {\n          base::extend();\n          h = base::hash(k);\n         \
    \ continue;\n        }\n        base::data[h].first = k;\n        base::data[h].second\
    \ = Val();\n        base::occupied_flag[h] = true;\n        ++base::occupied,\
    \ ++base::s;\n        return base::data[h].second;\n      }\n      if (base::data[h].first\
    \ == k) {\n        if (base::deleted_flag[h] == true) {\n          base::data[h].second\
    \ = Val();\n          base::deleted_flag[h] = false;\n          ++base::s;\n \
    \       }\n        return base::data[h].second;\n      }\n      h = (h + 1) &\
    \ (base::cap - 1);\n    }\n  }\n\n  typename base::itr emplace(const Key& key,\
    \ const Val& val) {\n    return base::insert(Data(key, val));\n  }\n};\n\n/*\n\
    \ * @brief \u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7(\u9023\u60F3\u914D\u5217\
    )\n * @docs docs/hashmap/hashmap.md\n **/\n#line 5 \"graph/offline-dynamic-connectivity.hpp\"\
    \n\nstruct OffLineDynamicConnectivity {\n  int N, Q, segsz;\n  RollbackUnionFind\
    \ uf;\n  vector<vector<pair<int, int>>> seg, qadd, qdel;\n  HashMap<pair<int,\
    \ int>, pair<int, int>> cnt;\n\n  OffLineDynamicConnectivity(int n, int q)\n \
    \     : N(n), Q(q), uf(n), qadd(q), qdel(q) {\n    segsz = 1;\n    while (segsz\
    \ < Q) segsz *= 2;\n    seg.resize(segsz * 2);\n  }\n\n  void add_edge(int t,\
    \ int u, int v) { qadd[t].emplace_back(u, v); }\n  void del_edge(int t, int u,\
    \ int v) { qdel[t].emplace_back(u, v); }\n\n  void build() {\n    for (int i =\
    \ 0; i < Q; i++) {\n      for (auto& e : qadd[i]) {\n        auto& dat = cnt[e];\n\
    \        if (dat.second++ == 0) dat.first = i;\n      }\n      for (auto& e :\
    \ qdel[i]) {\n        auto& dat = cnt[e];\n        if (--dat.second == 0) segment(e,\
    \ dat.first, i);\n      }\n    }\n    for (auto& [e, dat] : cnt) {\n      if (dat.second\
    \ != 0) segment(e, dat.first, Q);\n    }\n  }\n\n  template <typename ADD, typename\
    \ DEL, typename QUERY>\n  void dfs(const ADD& add, const DEL& del, const QUERY&\
    \ query, int id, int l,\n           int r) {\n    if (Q <= l) return;\n    int\
    \ state = uf.get_state();\n    vector<pair<int, int>> es;\n    for (auto& [u,\
    \ v] : seg[id]) {\n      if (!uf.same(u, v)) {\n        uf.unite(u, v);\n    \
    \    add(u, v);\n        es.emplace_back(u, v);\n      }\n    }\n    if (l + 1\
    \ == r) {\n      query(l);\n    } else {\n      dfs(add, del, query, id * 2 +\
    \ 0, l, (l + r) >> 1);\n      dfs(add, del, query, id * 2 + 1, (l + r) >> 1, r);\n\
    \    }\n    for (auto& [u, v] : es) del(u, v);\n    uf.rollback(state);\n  }\n\
    \n  template <typename ADD, typename DEL, typename QUERY>\n  void run(const ADD&\
    \ add, const DEL& del, const QUERY& query) {\n    dfs(add, del, query, 1, 0, segsz);\n\
    \  }\n\n private:\n  void segment(pair<int, int>& e, int l, int r) {\n    int\
    \ L = l + segsz;\n    int R = r + segsz;\n    while (L < R) {\n      if (L & 1)\
    \ seg[L++].push_back(e);\n      if (R & 1) seg[--R].push_back(e);\n      L >>=\
    \ 1, R >>= 1;\n    }\n  }\n};\n#line 2 \"lct/link-cut-tree-subtree.hpp\"\n\n#line\
    \ 2 \"lct/reversible-bbst-base.hpp\"\n\ntemplate <typename Tree, typename Node,\
    \ typename T, T (*f)(T, T), T (*ts)(T)>\nstruct ReversibleBBST : Tree {\n  using\
    \ Tree::merge;\n  using Tree::split;\n  using typename Tree::Ptr;\n\n  ReversibleBBST()\
    \ = default;\n\n  virtual void toggle(Ptr t) {\n    if(!t) return;\n    swap(t->l,\
    \ t->r);\n    t->sum = ts(t->sum);\n    t->rev ^= true;\n  }\n\n  T fold(Ptr &t,\
    \ int a, int b) {\n    auto x = split(t, a);\n    auto y = split(x.second, b -\
    \ a);\n    auto ret = sum(y.first);\n    t = merge(x.first, merge(y.first, y.second));\n\
    \    return ret;\n  }\n\n  void reverse(Ptr &t, int a, int b) {\n    auto x =\
    \ split(t, a);\n    auto y = split(x.second, b - a);\n    toggle(y.first);\n \
    \   t = merge(x.first, merge(y.first, y.second));\n  }\n\n  Ptr update(Ptr t)\
    \ override {\n    if (!t) return t;\n    t->cnt = 1;\n    t->sum = t->key;\n \
    \   if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n    if (t->r)\
    \ t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);\n    return t;\n  }\n\n\
    \ protected:\n  inline T sum(const Ptr t) { return t ? t->sum : T(); }\n\n  void\
    \ push(Ptr t) override {\n    if (!t) return;\n    if (t->rev) {\n      if (t->l)\
    \ toggle(t->l);\n      if (t->r) toggle(t->r);\n      t->rev = false;\n    }\n\
    \  }\n};\n\n/**\n * @brief \u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728\
    (\u57FA\u5E95\u30AF\u30E9\u30B9)\n */\n#line 2 \"lct/splay-base.hpp\"\n\ntemplate\
    \ <typename Node>\nstruct SplayTreeBase {\n  using Ptr = Node *;\n  template <typename...\
    \ Args>\n  Ptr my_new(const Args &...args) {\n    return new Node(args...);\n\
    \  }\n  void my_del(Ptr p) { delete p; }\n\n  bool is_root(Ptr t) { return !(t->p)\
    \ || (t->p->l != t && t->p->r != t); }\n\n  int size(Ptr t) const { return count(t);\
    \ }\n\n  virtual void splay(Ptr t) {\n    if (!t) return;\n    push(t);\n    while\
    \ (!is_root(t)) {\n      Ptr q = t->p;\n      if (is_root(q)) {\n        push(q),\
    \ push(t);\n        rot(t);\n      } else {\n        Ptr r = q->p;\n        push(r),\
    \ push(q), push(t);\n        if (pos(q) == pos(t))\n          rot(q), rot(t);\n\
    \        else\n          rot(t), rot(t);\n      }\n    }\n  }\n\n  Ptr get_left(Ptr\
    \ t) {\n    while (t->l) push(t), t = t->l;\n    return t;\n  }\n\n  Ptr get_right(Ptr\
    \ t) {\n    while (t->r) push(t), t = t->r;\n    return t;\n  }\n\n  pair<Ptr,\
    \ Ptr> split(Ptr t, int k) {\n    if (!t) return {nullptr, nullptr};\n    if (k\
    \ == 0) return {nullptr, t};\n    if (k == count(t)) return {t, nullptr};\n  \
    \  push(t);\n    if (k <= count(t->l)) {\n      auto x = split(t->l, k);\n   \
    \   t->l = x.second;\n      t->p = nullptr;\n      if (x.second) x.second->p =\
    \ t;\n      return {x.first, update(t)};\n    } else {\n      auto x = split(t->r,\
    \ k - count(t->l) - 1);\n      t->r = x.first;\n      t->p = nullptr;\n      if\
    \ (x.first) x.first->p = t;\n      return {update(t), x.second};\n    }\n  }\n\
    \n  Ptr merge(Ptr l, Ptr r) {\n    if (!l && !r) return nullptr;\n    if (!l)\
    \ return splay(r), r;\n    if (!r) return splay(l), l;\n    splay(l), splay(r);\n\
    \    l = get_right(l);\n    splay(l);\n    l->r = r;\n    r->p = l;\n    update(l);\n\
    \    return l;\n  }\n\n  using Key = decltype(Node::key);\n  Ptr build(const vector<Key>\
    \ &v) { return build(0, v.size(), v); }\n  Ptr build(int l, int r, const vector<Key>\
    \ &v) {\n    if (l == r) return nullptr;\n    if (l + 1 == r) return my_new(v[l]);\n\
    \    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));\n  }\n\
    \n  template <typename... Args>\n  void insert(Ptr &t, int k, const Args &...args)\
    \ {\n    splay(t);\n    auto x = split(t, k);\n    t = merge(merge(x.first, my_new(args...)),\
    \ x.second);\n  }\n\n  void erase(Ptr &t, int k) {\n    splay(t);\n    auto x\
    \ = split(t, k);\n    auto y = split(x.second, 1);\n    my_del(y.first);\n   \
    \ t = merge(x.first, y.second);\n  }\n\n  virtual Ptr update(Ptr t) = 0;\n\n protected:\n\
    \  inline int count(Ptr t) const { return t ? t->cnt : 0; }\n\n  virtual void\
    \ push(Ptr t) = 0;\n\n  Ptr build(const vector<Ptr> &v) { return build(0, v.size(),\
    \ v); }\n\n  Ptr build(int l, int r, const vector<Ptr> &v) {\n    if (l + 1 >=\
    \ r) return v[l];\n    return merge(build(l, (l + r) >> 1, v), build((l + r) >>\
    \ 1, r, v));\n  }\n\n  inline int pos(Ptr t) {\n    if (t->p) {\n      if (t->p->l\
    \ == t) return -1;\n      if (t->p->r == t) return 1;\n    }\n    return 0;\n\
    \  }\n\n  virtual void rot(Ptr t) {\n    Ptr x = t->p, y = x->p;\n    if (pos(t)\
    \ == -1) {\n      if ((x->l = t->r)) t->r->p = x;\n      t->r = x, x->p = t;\n\
    \    } else {\n      if ((x->r = t->l)) t->l->p = x;\n      t->l = x, x->p = t;\n\
    \    }\n    update(x), update(t);\n    if ((t->p = y)) {\n      if (y->l == x)\
    \ y->l = t;\n      if (y->r == x) y->r = t;\n    }\n  }\n};\n\n/**\n * @brief\
    \ Splay Tree(base)\n */\n#line 5 \"lct/link-cut-tree-subtree.hpp\"\n\ntemplate\
    \ <typename T, T (*f)(T, T), T (*finv)(T, T)>\nstruct LinkCutForSubtreeNode {\n\
    \  using Node = LinkCutForSubtreeNode;\n  using Ptr = LinkCutForSubtreeNode*;\n\
    \  Ptr l, r, p;\n  T key, sum, sub;\n  int cnt;\n  bool rev;\n\n  LinkCutForSubtreeNode(const\
    \ T& t = T())\n      : l(), r(), p(), key(t), sum(t), sub(T()), cnt(1), rev(false)\
    \ {}\n  void add(Node* other) { sub = f(sub, other->sum); }\n  void erase(Node*\
    \ other) { sub = finv(sub, other->sum); }\n  void merge(Node* n1, Node* n2) {\n\
    \    sum = f(f(n1 ? n1->sum : T(), key), f(sub, n2 ? n2->sum : T()));\n  }\n};\n\
    \ntemplate <typename T, T (*f)(T, T), T (*finv)(T, T)>\nstruct SplayTreeForLCSubtree\n\
    \    : ReversibleBBST<SplayTreeBase<LinkCutForSubtreeNode<T, f, finv>>,\n    \
    \                 LinkCutForSubtreeNode<T, f, finv>, T, nullptr, nullptr> {\n\
    \  using Node = LinkCutForSubtreeNode<T, f, finv>;\n};\n//\n#line 2 \"lct/link-cut-base.hpp\"\
    \n\ntemplate <typename Splay>\nstruct LinkCutBase : Splay {\n  using Node = typename\
    \ Splay::Node;\n  using Ptr = Node*;\n\n  virtual Ptr expose(Ptr t) {\n    Ptr\
    \ rp = nullptr;\n    for (Ptr cur = t; cur; cur = cur->p) {\n      this->splay(cur);\n\
    \      cur->r = rp;\n      this->update(cur);\n      rp = cur;\n    }\n    this->splay(t);\n\
    \    return rp;\n  }\n\n  virtual void link(Ptr u, Ptr v) {\n    evert(u);\n \
    \   expose(v);\n    u->p = v;\n  }\n\n  void cut(Ptr u, Ptr v) {\n    evert(u);\n\
    \    expose(v);\n    assert(u->p == v);\n    v->l = u->p = nullptr;\n    this->update(v);\n\
    \  }\n\n  void evert(Ptr t) {\n    expose(t);\n    this->toggle(t);\n    this->push(t);\n\
    \  }\n\n  Ptr lca(Ptr u, Ptr v) {\n    if (get_root(u) != get_root(v)) return\
    \ nullptr;\n    expose(u);\n    return expose(v);\n  }\n\n  Ptr get_kth(Ptr x,\
    \ int k) {\n    expose(x);\n    while (x) {\n      this->push(x);\n      if (x->r\
    \ && x->r->sz > k) {\n        x = x->r;\n      } else {\n        if (x->r) k -=\
    \ x->r->sz;\n        if (k == 0) return x;\n        k -= 1;\n        x = x->l;\n\
    \      }\n    }\n    return nullptr;\n  }\n\n  Ptr get_root(Ptr x) {\n    expose(x);\n\
    \    while (x->l) this->push(x), x = x->l;\n    return x;\n  }\n\n  Ptr get_parent(Ptr\
    \ x) {\n    expose(x);\n    Ptr p = x->l;\n    if(p == nullptr) return nullptr;\n\
    \    while (true) {\n      this->push(p);\n      if (p->r == nullptr) return p;\n\
    \      p = p->r;\n    }\n    exit(1);\n  }\n\n  virtual void set_key(Ptr t, const\
    \ decltype(Node::key)& key) {\n    this->splay(t);\n    t->key = key;\n    this->update(t);\n\
    \  }\n\n  virtual decltype(Node::key) get_key(Ptr t) { return t->key; }\n\n  decltype(Node::key)\
    \ fold(Ptr u, Ptr v) {\n    evert(u);\n    expose(v);\n    return v->sum;\n  }\n\
    };\n\n/**\n * @brief Link/Cut Tree(base)\n * @docs docs/lct/link-cut-tree.md\n\
    \ */\n#line 32 \"lct/link-cut-tree-subtree.hpp\"\n\ntemplate <typename T, T (*f)(T,\
    \ T), T (*finv)(T, T)>\nstruct LinkCutTreeSubtreeQuery\n    : LinkCutBase<SplayTreeForLCSubtree<T,\
    \ f, finv>> {\n  using base = LinkCutBase<SplayTreeForLCSubtree<T, f, finv>>;\n\
    \  using Node = typename base::Node;\n  using Ptr = typename base::Ptr;\n\n  Ptr\
    \ expose(Ptr t) override {\n    Ptr rp = nullptr;\n    for (Ptr cur = t; cur;\
    \ cur = cur->p) {\n      this->splay(cur);\n      if (cur->r) cur->add(cur->r);\n\
    \      cur->r = rp;\n      if (cur->r) cur->erase(cur->r);\n      this->update(cur);\n\
    \      rp = cur;\n    }\n    this->splay(t);\n    return rp;\n  }\n\n  void link(Ptr\
    \ u, Ptr v) override {\n    this->evert(u);\n    this->expose(v);\n    u->p =\
    \ v;\n    v->add(u);\n  }\n\n  void toggle(Ptr t) override {\n    if(!t) return;\n\
    \    swap(t->l, t->r);\n    t->rev ^= true;\n  }\n\n  Ptr update(Ptr t) override\
    \ {\n    if (!t) return t;\n    t->cnt = 1 + this->count(t->l) + this->count(t->r);\n\
    \    t->merge(t->l, t->r);\n    return t;\n  }\n\n  void set_key(Ptr t, const\
    \ T& key) override {\n    this->expose(t);\n    t->key = key;\n    this->update(t);\n\
    \  }\n\n  T subtree(Ptr t) {\n    this->expose(t);\n    return f(t->key, t->sub);\n\
    \  }\n};\n\n/**\n * @brief \u90E8\u5206\u6728\u30AF\u30A8\u30EALink/Cut Tree\n\
    \ */\n#line 8 \"verify/verify-yosupo-ds/yosupo-offline-dynamic-connectivity.test.cpp\"\
    \n\nusing namespace Nyaan;\n\nll add(ll a, ll b) { return a + b; }\nll sub(ll\
    \ a, ll b) { return a - b; }\n\nvoid Nyaan::solve() {\n  ini(N, Q);\n  vl a(N);\n\
    \  in(a);\n  vl cmd(Q), X(Q), Y(Q);\n  rep(i, Q) {\n    in(cmd[i], X[i]);\n  \
    \  if (cmd[i] != 3) in(Y[i]);\n    if (cmd[i] < 2 and X[i] > Y[i]) swap(X[i],\
    \ Y[i]);\n  }\n\n  using LCT = LinkCutTreeSubtreeQuery<ll, add, sub>;\n  LCT lct;\n\
    \  vector<LCT::Node*> vs(N);\n  rep(i, N) vs[i] = new LCT::Node(a[i]);\n\n  OffLineDynamicConnectivity\
    \ dc(N, Q);\n  rep(i, Q) {\n    if (cmd[i] == 0) dc.add_edge(i, X[i], Y[i]);\n\
    \    if (cmd[i] == 1) dc.del_edge(i, X[i], Y[i]);\n  }\n  dc.build();\n  vl ans;\n\
    \  auto add = [&](int u, int v) { lct.link(vs[u], vs[v]); };\n  auto del = [&](int\
    \ u, int v) { lct.cut(vs[u], vs[v]); };\n  auto query = [&](int i) {\n    if (cmd[i]\
    \ == 2) {\n      ll k = lct.get_key(vs[X[i]]);\n      lct.set_key(vs[X[i]], k\
    \ + Y[i]);\n    } else if (cmd[i] == 3) {\n      lct.evert(vs[X[i]]);\n      ans.emplace_back(lct.subtree(vs[X[i]]));\n\
    \    }\n  };\n\n  dc.run(add, del, query);\n  each(x, ans) out(x);\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n\n#include \"../../template/template.hpp\"\n//\n#include \"../../graph/offline-dynamic-connectivity.hpp\"\
    \n#include \"../../lct/link-cut-tree-subtree.hpp\"\n\nusing namespace Nyaan;\n\
    \nll add(ll a, ll b) { return a + b; }\nll sub(ll a, ll b) { return a - b; }\n\
    \nvoid Nyaan::solve() {\n  ini(N, Q);\n  vl a(N);\n  in(a);\n  vl cmd(Q), X(Q),\
    \ Y(Q);\n  rep(i, Q) {\n    in(cmd[i], X[i]);\n    if (cmd[i] != 3) in(Y[i]);\n\
    \    if (cmd[i] < 2 and X[i] > Y[i]) swap(X[i], Y[i]);\n  }\n\n  using LCT = LinkCutTreeSubtreeQuery<ll,\
    \ add, sub>;\n  LCT lct;\n  vector<LCT::Node*> vs(N);\n  rep(i, N) vs[i] = new\
    \ LCT::Node(a[i]);\n\n  OffLineDynamicConnectivity dc(N, Q);\n  rep(i, Q) {\n\
    \    if (cmd[i] == 0) dc.add_edge(i, X[i], Y[i]);\n    if (cmd[i] == 1) dc.del_edge(i,\
    \ X[i], Y[i]);\n  }\n  dc.build();\n  vl ans;\n  auto add = [&](int u, int v)\
    \ { lct.link(vs[u], vs[v]); };\n  auto del = [&](int u, int v) { lct.cut(vs[u],\
    \ vs[v]); };\n  auto query = [&](int i) {\n    if (cmd[i] == 2) {\n      ll k\
    \ = lct.get_key(vs[X[i]]);\n      lct.set_key(vs[X[i]], k + Y[i]);\n    } else\
    \ if (cmd[i] == 3) {\n      lct.evert(vs[X[i]]);\n      ans.emplace_back(lct.subtree(vs[X[i]]));\n\
    \    }\n  };\n\n  dc.run(add, del, query);\n  each(x, ans) out(x);\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - graph/offline-dynamic-connectivity.hpp
  - data-structure/rollback-union-find.hpp
  - hashmap/hashmap.hpp
  - hashmap/hashmap-base.hpp
  - lct/link-cut-tree-subtree.hpp
  - lct/reversible-bbst-base.hpp
  - lct/splay-base.hpp
  - lct/link-cut-base.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-offline-dynamic-connectivity.test.cpp
  requiredBy: []
  timestamp: '2024-05-03 23:21:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-offline-dynamic-connectivity.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-offline-dynamic-connectivity.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-offline-dynamic-connectivity.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-offline-dynamic-connectivity.test.cpp
---
