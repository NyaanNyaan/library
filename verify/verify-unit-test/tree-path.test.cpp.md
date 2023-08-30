---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find.hpp
    title: Union Find(Disjoint Set Union)
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: internal/internal-seed.hpp
    title: internal/internal-seed.hpp
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
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
    path: tree/pruefer-code.hpp
    title: Pruefer Code
  - icon: ':heavy_check_mark:'
    path: tree/tree-query.hpp
    title: "\u6728\u306B\u5BFE\u3059\u308B\u4E00\u822C\u7684\u306A\u30AF\u30A8\u30EA"
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
  bundledCode: "#line 1 \"verify/verify-unit-test/tree-path.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"template/template.hpp\"\
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
    \ */\n#line 2 \"misc/rng.hpp\"\n\n#line 2 \"internal/internal-seed.hpp\"\n\n#line\
    \ 4 \"internal/internal-seed.hpp\"\nusing namespace std;\n\nnamespace internal\
    \ {\nunsigned long long non_deterministic_seed() {\n  unsigned long long m =\n\
    \      chrono::duration_cast<chrono::nanoseconds>(\n          chrono::high_resolution_clock::now().time_since_epoch())\n\
    \          .count();\n  m ^= 9845834732710364265uLL;\n  m ^= m << 24, m ^= m >>\
    \ 31, m ^= m << 35;\n  return m;\n}\nunsigned long long deterministic_seed() {\
    \ return 88172645463325252UL; }\n\n// 64 bit \u306E seed \u5024\u3092\u751F\u6210\
    \ (\u624B\u5143\u3067\u306F seed \u56FA\u5B9A)\n// \u9023\u7D9A\u3067\u547C\u3073\
    \u51FA\u3059\u3068\u540C\u3058\u5024\u304C\u4F55\u5EA6\u3082\u8FD4\u3063\u3066\
    \u304F\u308B\u306E\u3067\u6CE8\u610F\n// #define RANDOMIZED_SEED \u3059\u308B\u3068\
    \u30B7\u30FC\u30C9\u304C\u30E9\u30F3\u30C0\u30E0\u306B\u306A\u308B\nunsigned long\
    \ long seed() {\n#if defined(NyaanLocal) && !defined(RANDOMIZED_SEED)\n  return\
    \ deterministic_seed();\n#else\n  return non_deterministic_seed();\n#endif\n}\n\
    \n}  // namespace internal\n#line 4 \"misc/rng.hpp\"\n\nnamespace my_rand {\n\
    using i64 = long long;\nusing u64 = unsigned long long;\n\n// [0, 2^64 - 1)\n\
    u64 rng() {\n  static u64 _x = internal::seed();\n  return _x ^= _x << 7, _x ^=\
    \ _x >> 9;\n}\n\n// [l, r]\ni64 rng(i64 l, i64 r) {\n  assert(l <= r);\n  return\
    \ l + rng() % u64(r - l + 1);\n}\n\n// [l, r)\ni64 randint(i64 l, i64 r) {\n \
    \ assert(l < r);\n  return l + rng() % u64(r - l);\n}\n\n// choose n numbers from\
    \ [l, r) without overlapping\nvector<i64> randset(i64 l, i64 r, i64 n) {\n  assert(l\
    \ <= r && n <= r - l);\n  unordered_set<i64> s;\n  for (i64 i = n; i; --i) {\n\
    \    i64 m = randint(l, r + 1 - i);\n    if (s.find(m) != s.end()) m = r - i;\n\
    \    s.insert(m);\n  }\n  vector<i64> ret;\n  for (auto& x : s) ret.push_back(x);\n\
    \  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() { return rng() * 5.42101086242752217004e-20;\
    \ }\n// [l, r)\ndouble rnd(double l, double r) {\n  assert(l < r);\n  return l\
    \ + rnd() * (r - l);\n}\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n\
    \  int n = v.size();\n  for (int i = 1; i < n; i++) swap(v[i], v[randint(0, i\
    \ + 1)]);\n}\n\n}  // namespace my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\n\
    using my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n#line 2 \"\
    tree/convert-tree.hpp\"\n\n#line 2 \"graph/graph-template.hpp\"\n\ntemplate <typename\
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
    \ */\n#line 4 \"tree/convert-tree.hpp\"\n\ntemplate <typename T>\nstruct has_cost\
    \ {\n private:\n  template <typename U>\n  static auto confirm(U u) -> decltype(u.cost,\
    \ std::true_type());\n  static auto confirm(...) -> std::false_type;\n\n public:\n\
    \  enum : bool { value = decltype(confirm(std::declval<T>()))::value };\n};\n\n\
    template <typename T>\nvector<vector<T>> inverse_tree(const vector<vector<T>>&\
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
    #line 2 \"tree/pruefer-code.hpp\"\n\n#line 4 \"tree/pruefer-code.hpp\"\n\n// input:\
    \ [c \\in [0, n)] * (n-2), n>=3\nvector<vector<int>> pruefer_code(const vector<int>&\
    \ code) {\n  int n = code.size() + 2;\n  assert(n > 2);\n  vector<vector<int>>\
    \ g(n);\n  vector<int> deg(n, 1);\n  int e = 0;\n  for (auto& x : code) deg[x]++;\n\
    \  set<int> ps;\n  for (int j = 0; j < n; j++) {\n    if (deg[j] == 1) ps.insert(j);\n\
    \  }\n  for (auto& i : code) {\n    if (ps.empty()) break;\n    int j = *begin(ps);\n\
    \    ps.erase(j);\n    g[i].push_back(j);\n    g[j].push_back(i);\n    if (deg[i]\
    \ == 1) ps.erase(i);\n    deg[i]--, deg[j]--;\n    if (deg[i] == 1) ps.insert(i);\n\
    \    e++;\n  }\n  int u = -1, v = -1;\n  for (int i = 0; i < n; i++) {\n    if\
    \ (deg[i] == 1) (u == -1 ? u : v) = i;\n  }\n  assert(u != -1 and v != -1);\n\
    \  g[u].push_back(v);\n  g[v].push_back(u);\n  e++;\n  assert(e == n - 1);\n \
    \ return g;\n}\n\nvector<vector<int>> random_tree(int n) {\n  if (n <= 2) {\n\
    \    vector<vector<int>> g(n);\n    if (n == 2) {\n      g[0].push_back(1);\n\
    \      g[1].push_back(0);\n    }\n    return g;\n  }\n  vector<int> pruefer(n\
    \ - 2);\n  for (auto& x : pruefer) x = randint(0, n);\n  return pruefer_code(pruefer);\n\
    }\n\n/**\n * @brief Pruefer Code\n */\n#line 3 \"tree/tree-query.hpp\"\n\ntemplate\
    \ <typename G>\nstruct Tree {\n private:\n  G& g;\n  int root;\n  vector<array<int,\
    \ 24>> bl;\n  vector<int> dp;\n  void build() {\n    bl.resize(g.size());\n  \
    \  dp.resize(g.size());\n    for (auto& v : bl) fill(begin(v), end(v), -1);\n\
    \    dfs(root, -1, 0);\n  }\n\n  void dfs(int c, int p, int _dp) {\n    dp[c]\
    \ = _dp;\n    for (int i = p, x = 0; i != -1;) {\n      bl[c][x] = i;\n      i\
    \ = bl[i][x], x++;\n    }\n    for (auto& d : g[c]) {\n      if (d == p) continue;\n\
    \      dfs(d, c, _dp + 1);\n    }\n  }\n\n public:\n  Tree(G& _g, int _r = 0)\
    \ : g(_g), root(_r) { build(); }\n\n  int depth(int u) const { return dp[u]; }\n\
    \n  int par(int u) const { return u == root ? -1 : bl[u][0]; }\n\n  int kth_ancestor(int\
    \ u, int k) const {\n    if (dp[u] < k) return -1;\n    while (k) {\n      int\
    \ t = __builtin_ctz(k);\n      u = bl[u][t], k ^= 1 << t;\n    }\n    return u;\n\
    \  }\n\n  int nxt(int s, int t) const {\n    if (dp[s] >= dp[t]) return par(s);\n\
    \    int u = kth_ancestor(t, dp[t] - dp[s] - 1);\n    return bl[u][0] == s ? u\
    \ : bl[s][0];\n  }\n\n  vector<int> path(int s, int t) const {\n    vector<int>\
    \ pre, suf;\n    while (dp[s] > dp[t]) {\n      pre.push_back(s);\n      s = bl[s][0];\n\
    \    }\n    while (dp[s] < dp[t]) {\n      suf.push_back(t);\n      t = bl[t][0];\n\
    \    }\n    while (s != t) {\n      pre.push_back(s);\n      suf.push_back(t);\n\
    \      s = bl[s][0];\n      t = bl[t][0];\n    }\n    pre.push_back(s);\n    reverse(begin(suf),\
    \ end(suf));\n    copy(begin(suf), end(suf), back_inserter(pre));\n    return\
    \ pre;\n  }\n\n  int lca(int u, int v) {\n    if (dp[u] != dp[v]) {\n      if\
    \ (dp[u] > dp[v]) swap(u, v);\n      v = kth_ancestor(v, dp[v] - dp[u]);\n   \
    \ }\n    if (u == v) return u;\n    for (int i = __lg(dp[u]); i >= 0; --i) {\n\
    \      if (dp[u] < (1 << i)) continue;\n      if (bl[u][i] != bl[v][i]) u = bl[u][i],\
    \ v = bl[v][i];\n    }\n    return bl[u][0];\n  }\n\n  // u - v \u9593\u306E\u30D1\
    \u30B9\u4E0A\u306E\u9802\u70B9\u306E\u3046\u3061 u \u304B\u3089\u8DDD\u96E2 i\
    \ \u306E\u9802\u70B9\n  // (dist(u, v) < i \u306E\u3068\u304D -1)\n  int jump(int\
    \ u, int v, int i) {\n    int lc = lca(u, v);\n    int d1 = dp[u] - dp[lc];\n\
    \    if (i <= d1) return kth_ancestor(u, i);\n    int d = d1 + dp[v] - dp[lc];\n\
    \    if (i <= d) return kth_ancestor(v, d - i);\n    return -1;\n  }\n};\n\n/**\n\
    \ * @brief \u6728\u306B\u5BFE\u3059\u308B\u4E00\u822C\u7684\u306A\u30AF\u30A8\u30EA\
    \n * @docs docs/tree/tree-query.md\n */\n#line 10 \"verify/verify-unit-test/tree-path.test.cpp\"\
    \n\nusing namespace Nyaan;\n\ntemplate <typename G>\nbool is_tree(G& g, bool directed\
    \ = false) {\n  int n = g.size();\n  UnionFind uf(n);\n  rep(i, n) each(j, g[i])\
    \ {\n    if (!directed and i > j) continue;\n    if (!uf.unite(i, j)) return false;\n\
    \  }\n  return uf.size(0) == n;\n}\n\ntemplate <typename G>\nbool is_rooted_tree(G&\
    \ g, int root) {\n  int n = g.size();\n  vector<char> vis(n, false);\n  auto dfs\
    \ = [&](auto rc, int c) -> void {\n    vis[c] = true;\n    each(d, g[c]) {\n \
    \     assert(vis[d] == false);\n      rc(rc, d);\n    }\n  };\n  dfs(dfs, root);\n\
    \  int sm = 0;\n  each(b, vis) sm += !!b;\n  return sm == n;\n}\n\ntemplate <typename\
    \ G>\nbool is_inverse_tree(G& g, G& rg) {\n  set<pair<int, int>> s, t;\n  int\
    \ n = g.size();\n  for (int i = 0; i < n; i++) {\n    for (auto& j : g[i]) s.emplace(i,\
    \ int(j));\n    for (auto& j : rg[i]) t.emplace(j, int(i));\n  }\n  return s ==\
    \ t;\n}\n\nvoid test_tree_query(vvi& g, int root = 0) {\n  Tree<vvi> tree(g, root);\n\
    \  int N = sz(g);\n  rep(i, N) rep(j, N) {\n    vi p1 = tree.path(i, j);\n   \
    \ vi p2{int(i)};\n    for (int k = i; k != j;) {\n      p2.push_back(k = tree.nxt(k,\
    \ j));\n    }\n    assert(p1 == p2);\n    int l = i, ld = tree.depth(i);\n   \
    \ each(x, p1) if (amin(ld, tree.depth(x))) l = x;\n    assert(l == tree.lca(i,\
    \ j));\n  }\n}\n\nusing namespace Nyaan;\n\nvoid Nyaan::solve() {\n  // Random\
    \ Tree\n  for (int N : vi{2, 3, 4, 5, 10, 100}) {\n    vvi g = random_tree(N);\n\
    \    assert(is_tree(g) && \"random tree\");\n    test_tree_query(g);\n\n    int\
    \ root = randint(0, N);\n    vvi rg = rooted_tree(g, root);\n    assert(is_tree(rg,\
    \ true) && \"rooted tree\");\n    test_tree_query(rg, root);\n\n    vvi rh = inverse_tree(rg);\n\
    \    assert(is_inverse_tree(rg, rh) && \"inverse tree\");\n  }\n\n  for (int N\
    \ : vi{2, 3, 4, 5, 10, 100}) {\n    vvi _g = random_tree(N);\n    assert(is_tree(_g)\
    \ && \"random tree\");\n    WeightedGraph<ll> g(N);\n    rep(i, N) each(j, _g[i])\
    \ { g[i].emplace_back(i, j, rng() & 15); }\n\n    int root = randint(0, N);\n\
    \    auto rg = rooted_tree(g, root);\n    assert(is_tree(rg, true) && \"rooted\
    \ tree\");\n\n    auto rh = inverse_tree(rg);\n    assert(is_inverse_tree(rg,\
    \ rh) && \"inverse tree\");\n  }\n\n  // Line Tree\n  for (int N : vi{2, 3, 4,\
    \ 5, 10, 100}) {\n    vvi g(N);\n    rep1(i, N - 1) g[i - 1].push_back(i);\n \
    \   test_tree_query(g);\n  }\n\n  // Preufer Code\n  {\n    V<vvi> gs(125);\n\
    \    rep(i, 125) {\n      vi pr(3);\n      for (int j = i, k = 0; k < 3; j /=\
    \ 5, k++) {\n        pr[k] = j % 5;\n      }\n      gs[i] = pruefer_code(pr);\n\
    \      for (auto& es : gs[i]) sort(begin(es), end(es));\n    }\n    rep(i, 125)\
    \ assert(is_tree(gs[i]));\n    rep(i, 125) rep(j, i) assert(gs[i] != gs[j]);\n\
    \  }\n\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../template/template.hpp\"\n//\n#include \"../../data-structure/union-find.hpp\"\
    \n#include \"../../misc/rng.hpp\"\n#include \"../../tree/convert-tree.hpp\"\n\
    #include \"../../tree/pruefer-code.hpp\"\n#include \"../../tree/tree-query.hpp\"\
    \n\nusing namespace Nyaan;\n\ntemplate <typename G>\nbool is_tree(G& g, bool directed\
    \ = false) {\n  int n = g.size();\n  UnionFind uf(n);\n  rep(i, n) each(j, g[i])\
    \ {\n    if (!directed and i > j) continue;\n    if (!uf.unite(i, j)) return false;\n\
    \  }\n  return uf.size(0) == n;\n}\n\ntemplate <typename G>\nbool is_rooted_tree(G&\
    \ g, int root) {\n  int n = g.size();\n  vector<char> vis(n, false);\n  auto dfs\
    \ = [&](auto rc, int c) -> void {\n    vis[c] = true;\n    each(d, g[c]) {\n \
    \     assert(vis[d] == false);\n      rc(rc, d);\n    }\n  };\n  dfs(dfs, root);\n\
    \  int sm = 0;\n  each(b, vis) sm += !!b;\n  return sm == n;\n}\n\ntemplate <typename\
    \ G>\nbool is_inverse_tree(G& g, G& rg) {\n  set<pair<int, int>> s, t;\n  int\
    \ n = g.size();\n  for (int i = 0; i < n; i++) {\n    for (auto& j : g[i]) s.emplace(i,\
    \ int(j));\n    for (auto& j : rg[i]) t.emplace(j, int(i));\n  }\n  return s ==\
    \ t;\n}\n\nvoid test_tree_query(vvi& g, int root = 0) {\n  Tree<vvi> tree(g, root);\n\
    \  int N = sz(g);\n  rep(i, N) rep(j, N) {\n    vi p1 = tree.path(i, j);\n   \
    \ vi p2{int(i)};\n    for (int k = i; k != j;) {\n      p2.push_back(k = tree.nxt(k,\
    \ j));\n    }\n    assert(p1 == p2);\n    int l = i, ld = tree.depth(i);\n   \
    \ each(x, p1) if (amin(ld, tree.depth(x))) l = x;\n    assert(l == tree.lca(i,\
    \ j));\n  }\n}\n\nusing namespace Nyaan;\n\nvoid Nyaan::solve() {\n  // Random\
    \ Tree\n  for (int N : vi{2, 3, 4, 5, 10, 100}) {\n    vvi g = random_tree(N);\n\
    \    assert(is_tree(g) && \"random tree\");\n    test_tree_query(g);\n\n    int\
    \ root = randint(0, N);\n    vvi rg = rooted_tree(g, root);\n    assert(is_tree(rg,\
    \ true) && \"rooted tree\");\n    test_tree_query(rg, root);\n\n    vvi rh = inverse_tree(rg);\n\
    \    assert(is_inverse_tree(rg, rh) && \"inverse tree\");\n  }\n\n  for (int N\
    \ : vi{2, 3, 4, 5, 10, 100}) {\n    vvi _g = random_tree(N);\n    assert(is_tree(_g)\
    \ && \"random tree\");\n    WeightedGraph<ll> g(N);\n    rep(i, N) each(j, _g[i])\
    \ { g[i].emplace_back(i, j, rng() & 15); }\n\n    int root = randint(0, N);\n\
    \    auto rg = rooted_tree(g, root);\n    assert(is_tree(rg, true) && \"rooted\
    \ tree\");\n\n    auto rh = inverse_tree(rg);\n    assert(is_inverse_tree(rg,\
    \ rh) && \"inverse tree\");\n  }\n\n  // Line Tree\n  for (int N : vi{2, 3, 4,\
    \ 5, 10, 100}) {\n    vvi g(N);\n    rep1(i, N - 1) g[i - 1].push_back(i);\n \
    \   test_tree_query(g);\n  }\n\n  // Preufer Code\n  {\n    V<vvi> gs(125);\n\
    \    rep(i, 125) {\n      vi pr(3);\n      for (int j = i, k = 0; k < 3; j /=\
    \ 5, k++) {\n        pr[k] = j % 5;\n      }\n      gs[i] = pruefer_code(pr);\n\
    \      for (auto& es : gs[i]) sort(begin(es), end(es));\n    }\n    rep(i, 125)\
    \ assert(is_tree(gs[i]));\n    rep(i, 125) rep(j, i) assert(gs[i] != gs[j]);\n\
    \  }\n\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - data-structure/union-find.hpp
  - misc/rng.hpp
  - internal/internal-seed.hpp
  - tree/convert-tree.hpp
  - graph/graph-template.hpp
  - tree/pruefer-code.hpp
  - tree/tree-query.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/tree-path.test.cpp
  requiredBy: []
  timestamp: '2023-08-30 22:50:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/tree-path.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/tree-path.test.cpp
- /verify/verify/verify-unit-test/tree-path.test.cpp.html
title: verify/verify-unit-test/tree-path.test.cpp
---
