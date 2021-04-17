---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':question:'
    path: segment-tree/lazy-segment-tree-utility.hpp
    title: "\u4F7F\u7528\u983B\u5EA6\u306E\u9AD8\u3044\u9045\u5EF6\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728"
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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/lazyseg-setval.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#line 2 \"template/template.hpp\"\
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
    \ 4 \"verify/verify-unit-test/lazyseg-setval.test.cpp\"\n//\n#line 2 \"misc/rng.hpp\"\
    \n\nnamespace my_rand {\n\n// [0, 2^64 - 1)\nuint64_t rng() {\n  static uint64_t\
    \ x_ =\n      uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n         \
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \           .count()) *\n      10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return\
    \ x_ ^= x_ >> 9;\n}\n\n// [l, r)\nint64_t randint(int64_t l, int64_t r) {\n  assert(l\
    \ < r);\n  return l + rng() % (r - l);\n}\n\n// choose n numbers from [l, r) without\
    \ overlapping\nvector<int64_t> randset(int64_t l, int64_t r, int64_t n) {\n  assert(l\
    \ <= r && n <= r - l);\n  unordered_set<int64_t> s;\n  for (int64_t i = n; i;\
    \ --i) {\n    int64_t m = randint(l, r + 1 - i);\n    if (s.find(m) != s.end())\
    \ m = r - i;\n    s.insert(m);\n  }\n  vector<int64_t> ret;\n  for (auto& x :\
    \ s) ret.push_back(x);\n  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() {\n  union\
    \ raw_cast {\n    double t;\n    uint64_t u;\n  };\n  constexpr uint64_t p = uint64_t(1023\
    \ - 64) << 52;\n  return rng() * ((raw_cast*)(&p))->t;\n}\n\ntemplate <typename\
    \ T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n  for (int loop = 0;\
    \ loop < 2; loop++)\n    for (int i = 0; i < n; i++) swap(v[i], v[randint(0, n)]);\n\
    }\n\n}  // namespace my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\n\
    using my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n#line 2 \"\
    segment-tree/lazy-segment-tree-utility.hpp\"\n\ntemplate <typename T, typename\
    \ E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),\n          T (*ti)(), E (*ei)()>\n\
    struct LazySegmentTree {\n  int n, log;\n  vector<T> val;\n  vector<E> laz;\n\n\
    \  explicit LazySegmentTree() {}\n  explicit LazySegmentTree(const vector<T>&\
    \ vc) { init(vc); }\n\n  void init(const vector<T>& vc) {\n    n = 1, log = 0;\n\
    \    while (n < (int)vc.size()) n <<= 1, log++;\n    val.resize(2 * n, ti());\n\
    \    laz.resize(n, ei());\n    for (int i = 0; i < (int)vc.size(); ++i) val[i\
    \ + n] = vc[i];\n    for (int i = n - 1; i; --i) _update(i);\n  }\n\n  void update(int\
    \ l, int r, const E& x) {\n    if (l == r) return;\n    l += n, r += n;\n    for\
    \ (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) _push(l >> i);\n\
    \      if (((r >> i) << i) != r) _push((r - 1) >> i);\n    }\n    {\n      int\
    \ l2 = l, r2 = r;\n      while (l < r) {\n        if (l & 1) _apply(l++, x);\n\
    \        if (r & 1) _apply(--r, x);\n        l >>= 1;\n        r >>= 1;\n    \
    \  }\n      l = l2;\n      r = r2;\n    }\n    for (int i = 1; i <= log; i++)\
    \ {\n      if (((l >> i) << i) != l) _update(l >> i);\n      if (((r >> i) <<\
    \ i) != r) _update((r - 1) >> i);\n    }\n  }\n\n  T query(int l, int r) {\n \
    \   if (l == r) return ti();\n    l += n, r += n;\n    T L = ti(), R = ti();\n\
    \    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) _push(l\
    \ >> i);\n      if (((r >> i) << i) != r) _push((r - 1) >> i);\n    }\n    while\
    \ (l < r) {\n      if (l & 1) L = f(L, val[l++]);\n      if (r & 1) R = f(val[--r],\
    \ R);\n      l >>= 1;\n      r >>= 1;\n    }\n    return f(L, R);\n  }\n\n  void\
    \ set_val(int k, const T& x) {\n    k += n;\n    for (int i = log; i >= 1; i--)\
    \ {\n      if (((k >> i) << i) != k || (((k + 1) >> i) << i) != (k + 1))\n   \
    \     _push(k >> i);\n    }\n    val[k] = x;\n    for (int i = 1; i <= log; i++)\
    \ {\n      if (((k >> i) << i) != k || (((k + 1) >> i) << i) != (k + 1))\n   \
    \     _update(k >> i);\n    }\n  }\n\n  void update_val(int k, const E& x) {\n\
    \    k += n;\n    for (int i = log; i >= 1; i--) {\n      if (((k >> i) << i)\
    \ != k || (((k + 1) >> i) << i) != (k + 1))\n        _push(k >> i);\n    }\n \
    \   val[k] = g(val[k], x);\n    for (int i = 1; i <= log; i++) {\n      if (((k\
    \ >> i) << i) != k || (((k + 1) >> i) << i) != (k + 1))\n        _update(k >>\
    \ i);\n    }\n  }\n\n  T get_val(int k) {\n    k += n;\n    for (int i = log;\
    \ i >= 1; i--) {\n      if (((k >> i) << i) != k || (((k + 1) >> i) << i) != (k\
    \ + 1))\n        _push(k >> i);\n    }\n    return val[k];\n  }\n\n private:\n\
    \  void _push(int i) {\n    if (laz[i] != ei()) {\n      val[2 * i + 0] = g(val[2\
    \ * i + 0], laz[i]);\n      val[2 * i + 1] = g(val[2 * i + 1], laz[i]);\n    \
    \  if (2 * i < n) {\n        compose(laz[2 * i + 0], laz[i]);\n        compose(laz[2\
    \ * i + 1], laz[i]);\n      }\n      laz[i] = ei();\n    }\n  }\n  inline void\
    \ _update(int i) { val[i] = f(val[2 * i + 0], val[2 * i + 1]); }\n  inline void\
    \ _apply(int i, const E& x) {\n    if (x != ei()) {\n      val[i] = g(val[i],\
    \ x);\n      if (i < n) compose(laz[i], x);\n    }\n  }\n  inline void compose(E&\
    \ a, const E& b) { a = a == ei() ? b : h(a, b); }\n};\n\nnamespace SegmentTreeUtil\
    \ {\n\ntemplate <typename T>\nstruct Pair {\n  T first, second;\n  Pair() = default;\n\
    \  Pair(const T& f, const T& s) : first(f), second(s) {}\n  operator T() const\
    \ { return first; }\n  friend ostream& operator<<(ostream& os, const Pair<T>&\
    \ p) {\n    os << T(p.first);\n    return os;\n  }\n};\n\ntemplate <typename T>\n\
    T Max(T a, T b) {\n  return max(a, b);\n}\ntemplate <typename T>\nT Min(T a, T\
    \ b) {\n  return min(a, b);\n}\ntemplate <typename T>\nT Update(T, T b) {\n  return\
    \ b;\n}\ntemplate <typename T>\nT Add(T a, T b) {\n  return a + b;\n}\ntemplate\
    \ <typename T>\nPair<T> Psum(Pair<T> a, Pair<T> b) {\n  return Pair<T>(a.first\
    \ + b.first, a.second + b.second);\n}\ntemplate <typename T>\nPair<T> Padd(Pair<T>\
    \ a, T b) {\n  return Pair<T>(a.first + a.second * b, a.second);\n}\ntemplate\
    \ <typename T>\nPair<T> PUpdate(Pair<T> a, T b) {\n  return Pair<T>(a.second *\
    \ b, a.second);\n}\ntemplate <typename T>\nPair<T> Pid() {\n  return Pair<T>(0,\
    \ 0);\n}\ntemplate <typename T>\nT Zero() {\n  return T(0);\n}\ntemplate <typename\
    \ T, T val>\nT Const() {\n  return val;\n}\n\ntemplate <typename T, T MINF>\n\
    struct AddMax_LazySegmentTree\n    : LazySegmentTree<T, T, Max<T>, Add<T>, Add<T>,\
    \ Const<T, MINF>, Zero<T>> {\n  using base =\n      LazySegmentTree<T, T, Max<T>,\
    \ Add<T>, Add<T>, Const<T, MINF>, Zero<T>>;\n  AddMax_LazySegmentTree(const vector<T>&\
    \ v) : base(v) {}\n};\n\ntemplate <typename T, T INF>\nstruct AddMin_LazySegmentTree\n\
    \    : LazySegmentTree<T, T, Min<T>, Add<T>, Add<T>, Const<T, INF>, Zero<T>> {\n\
    \  using base =\n      LazySegmentTree<T, T, Min<T>, Add<T>, Add<T>, Const<T,\
    \ INF>, Zero<T>>;\n  AddMin_LazySegmentTree(const vector<T>& v) : base(v) {}\n\
    };\n\ntemplate <typename T>\nstruct AddSum_LazySegmentTree\n    : LazySegmentTree<Pair<T>,\
    \ T, Psum<T>, Padd<T>, Add<T>, Pid<T>, Zero<T>> {\n  using base =\n      LazySegmentTree<Pair<T>,\
    \ T, Psum<T>, Padd<T>, Add<T>, Pid<T>, Zero<T>>;\n  AddSum_LazySegmentTree(const\
    \ vector<T>& v) {\n    vector<Pair<T>> w(v.size());\n    for (int i = 0; i < (int)v.size();\
    \ i++) w[i] = Pair<T>(v[i], 1);\n    base::init(w);\n  }\n};\n\ntemplate <typename\
    \ T, T MINF>\nstruct UpdateMax_LazySegmentTree\n    : LazySegmentTree<T, T, Max<T>,\
    \ Update<T>, Update<T>, Const<T, MINF>,\n                      Const<T, MINF>>\
    \ {\n  using base = LazySegmentTree<T, T, Max<T>, Update<T>, Update<T>,\n    \
    \                           Const<T, MINF>, Const<T, MINF>>;\n  UpdateMax_LazySegmentTree(const\
    \ vector<T>& v) : base(v) {}\n};\n\ntemplate <typename T, T INF>\nstruct UpdateMin_LazySegmentTree\n\
    \    : LazySegmentTree<T, T, Min<T>, Update<T>, Update<T>, Const<T, INF>,\n  \
    \                    Const<T, INF>> {\n  using base = LazySegmentTree<T, T, Min<T>,\
    \ Update<T>, Update<T>,\n                               Const<T, INF>, Const<T,\
    \ INF>>;\n  UpdateMin_LazySegmentTree(const vector<T>& v) : base(v) {}\n};\n\n\
    template <typename T, T UNUSED_VALUE>\nstruct UpdateSum_LazySegmentTree\n    :\
    \ LazySegmentTree<Pair<T>, T, Psum<T>, PUpdate<T>, Update<T>, Pid<T>,\n      \
    \                Const<T, UNUSED_VALUE>> {\n  using base = LazySegmentTree<Pair<T>,\
    \ T, Psum<T>, PUpdate<T>, Update<T>,\n                               Pid<T>, Const<T,\
    \ UNUSED_VALUE>>;\n  UpdateSum_LazySegmentTree(const vector<T>& v) {\n    vector<Pair<T>>\
    \ w(v.size());\n    for (int i = 0; i < (int)v.size(); i++) w[i] = Pair<T>(v[i],\
    \ 1);\n    base::init(w);\n  }\n};\n\n}  // namespace SegmentTreeUtil\nusing SegmentTreeUtil::AddMax_LazySegmentTree;\n\
    using SegmentTreeUtil::AddMin_LazySegmentTree;\nusing SegmentTreeUtil::AddSum_LazySegmentTree;\n\
    using SegmentTreeUtil::UpdateMax_LazySegmentTree;\nusing SegmentTreeUtil::UpdateMin_LazySegmentTree;\n\
    using SegmentTreeUtil::UpdateSum_LazySegmentTree;\n\n/**\n * @brief \u4F7F\u7528\
    \u983B\u5EA6\u306E\u9AD8\u3044\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n * @docs docs/segment-tree/lazy-segment-tree-utility.md\n */\n#line 7 \"verify/verify-unit-test/lazyseg-setval.test.cpp\"\
    \n\nusing namespace Nyaan;\n\nvoid Nyaan::solve() {\n  int N = 100000;\n  int\
    \ Q = 1000000;\n  vl init(N);\n  AddSum_LazySegmentTree<ll> seg(init);\n\n  rep(i,\
    \ Q) {\n    if (rng() & 1) {\n      int l, r;\n      l = randint(0, N);\n    \
    \  r = randint(0, N);\n      if (l > r) swap(l, r);\n      r++;\n      seg.update(l,\
    \ r, randint(0, TEN(6)));\n    } else {\n      int x = randint(0, N);\n      ll\
    \ v = seg.get_val(x);\n      ll w = seg.query(x, x + 1);\n      assert(v == w);\n\
    \    }\n  }\n\n  {\n    ini(n);\n    rep(i, n) {\n      ini(a, b);\n      out(a\
    \ + b);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../misc/rng.hpp\"\n#include\
    \ \"../../segment-tree/lazy-segment-tree-utility.hpp\"\n\nusing namespace Nyaan;\n\
    \nvoid Nyaan::solve() {\n  int N = 100000;\n  int Q = 1000000;\n  vl init(N);\n\
    \  AddSum_LazySegmentTree<ll> seg(init);\n\n  rep(i, Q) {\n    if (rng() & 1)\
    \ {\n      int l, r;\n      l = randint(0, N);\n      r = randint(0, N);\n   \
    \   if (l > r) swap(l, r);\n      r++;\n      seg.update(l, r, randint(0, TEN(6)));\n\
    \    } else {\n      int x = randint(0, N);\n      ll v = seg.get_val(x);\n  \
    \    ll w = seg.query(x, x + 1);\n      assert(v == w);\n    }\n  }\n\n  {\n \
    \   ini(n);\n    rep(i, n) {\n      ini(a, b);\n      out(a + b);\n    }\n  }\n\
    }"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - misc/rng.hpp
  - segment-tree/lazy-segment-tree-utility.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/lazyseg-setval.test.cpp
  requiredBy: []
  timestamp: '2021-04-18 02:36:23+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/verify-unit-test/lazyseg-setval.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/lazyseg-setval.test.cpp
- /verify/verify/verify-unit-test/lazyseg-setval.test.cpp.html
title: verify/verify-unit-test/lazyseg-setval.test.cpp
---
