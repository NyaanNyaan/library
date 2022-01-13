---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segment-tree/rbst-segment-tree.hpp
    title: RBST-based Dynamic Lazy Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-associative-array-rbstseg.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n//\n\
    #line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n#include\
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
    \ t.size();\n}\n\ntemplate <typename T, typename U>\ninline bool amin(T &x, U\
    \ y) {\n  return (y < x) ? (x = y, true) : false;\n}\ntemplate <typename T, typename\
    \ U>\ninline bool amax(T &x, U y) {\n  return (x < y) ? (x = y, true) : false;\n\
    }\n\ntemplate <typename T>\ninline T Max(const vector<T> &v) {\n  return *max_element(begin(v),\
    \ end(v));\n}\ntemplate <typename T>\ninline T Min(const vector<T> &v) {\n  return\
    \ *min_element(begin(v), end(v));\n}\ntemplate <typename T>\ninline long long\
    \ Sum(const vector<T> &v) {\n  return accumulate(begin(v), end(v), 0LL);\n}\n\n\
    template <typename T>\nint lb(const vector<T> &v, const T &a) {\n  return lower_bound(begin(v),\
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
    \ end(ord), f);\n  return ord;\n}\n\ntemplate <typename T>\nvector<int> mkinv(vector<T>\
    \ &v) {\n  int max_val = *max_element(begin(v), end(v));\n  vector<int> inv(max_val\
    \ + 1, -1);\n  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;\n  return\
    \ inv;\n}\n\n}  // namespace Nyaan\n#line 58 \"template/template.hpp\"\n\n// bit\
    \ operation\n#line 1 \"template/bitop.hpp\"\nnamespace Nyaan {\n__attribute__((target(\"\
    popcnt\"))) inline int popcnt(const u64 &a) {\n  return _mm_popcnt_u64(a);\n}\n\
    inline int lsb(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }\ninline int\
    \ ctz(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }\ninline int msb(const\
    \ u64 &a) { return a ? 63 - __builtin_clzll(a) : -1; }\ntemplate <typename T>\n\
    inline int gbit(const T &a, int i) {\n  return (a >> i) & 1;\n}\ntemplate <typename\
    \ T>\ninline void sbit(T &a, int i, bool b) {\n  if (gbit(a, i) != b) a ^= T(1)\
    \ << i;\n}\nconstexpr long long PW(int n) { return 1LL << n; }\nconstexpr long\
    \ long MSK(int n) { return (1LL << n) - 1; }\n}  // namespace Nyaan\n#line 61\
    \ \"template/template.hpp\"\n\n// inout\n#line 1 \"template/inout.hpp\"\nnamespace\
    \ Nyaan {\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream &os,\
    \ const pair<T, U> &p) {\n  os << p.first << \" \" << p.second;\n  return os;\n\
    }\ntemplate <typename T, typename U>\nistream &operator>>(istream &is, pair<T,\
    \ U> &p) {\n  is >> p.first >> p.second;\n  return is;\n}\n\ntemplate <typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n  int s = (int)v.size();\n\
    \  for (int i = 0; i < s; i++) os << (i ? \" \" : \"\") << v[i];\n  return os;\n\
    }\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T> &v) {\n \
    \ for (auto &x : v) is >> x;\n  return is;\n}\n\nvoid in() {}\ntemplate <typename\
    \ T, class... U>\nvoid in(T &t, U &... u) {\n  cin >> t;\n  in(u...);\n}\n\nvoid\
    \ out() { cout << \"\\n\"; }\ntemplate <typename T, class... U, char sep = ' '>\n\
    void out(const T &t, const U &... u) {\n  cout << t;\n  if (sizeof...(u)) cout\
    \ << sep;\n  out(u...);\n}\n\nvoid outr() {}\ntemplate <typename T, class... U,\
    \ char sep = ' '>\nvoid outr(const T &t, const U &... u) {\n  cout << t;\n  outr(u...);\n\
    }\n\nstruct IoSetupNya {\n  IoSetupNya() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
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
    \ ? \"true\" : \"false\"); }\n\ntemplate <typename U,\n          enable_if_t<!is_specialize<U>::value,\
    \ nullptr_t> = nullptr>\nvoid dump(const U& t) {\n  cerr << t;\n}\n\ntemplate\
    \ <typename T>\nvoid dump(const T& t, enable_if_t<is_integral<T>::value>* = nullptr)\
    \ {\n  string res;\n  if (t == Nyaan::inf) res = \"inf\";\n  if constexpr (is_signed<T>::value)\
    \ {\n    if (t == -Nyaan::inf) res = \"-inf\";\n  }\n  if constexpr (sizeof(T)\
    \ == 8) {\n    if (t == Nyaan::infLL) res = \"inf\";\n    if constexpr (is_signed<T>::value)\
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
    \          \\\n  } while (0)\n#else\n#define trc(...) (void(0))\n#endif\n#line\
    \ 67 \"template/template.hpp\"\n\n// macro\n#line 1 \"template/macro.hpp\"\n#define\
    \ each(x, v) for (auto&& x : v)\n#define each2(x, y, v) for (auto&& [x, y] : v)\n\
    #define all(v) (v).begin(), (v).end()\n#define rep(i, N) for (long long i = 0;\
    \ i < (long long)(N); i++)\n#define repr(i, N) for (long long i = (long long)(N)-1;\
    \ i >= 0; i--)\n#define rep1(i, N) for (long long i = 1; i <= (long long)(N);\
    \ i++)\n#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)\n\
    #define reg(i, a, b) for (long long i = (a); i < (b); i++)\n#define regr(i, a,\
    \ b) for (long long i = (b)-1; i >= (a); i--)\n#define fi first\n#define se second\n\
    #define ini(...)   \\\n  int __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define inl(...)\
    \         \\\n  long long __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define ins(...)\
    \      \\\n  string __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define in2(s, t)    \
    \                       \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n \
    \   in(s[i], t[i]);                         \\\n  }\n#define in3(s, t, u)    \
    \                    \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i],\
    \ t[i], u[i]);                   \\\n  }\n#define in4(s, t, u, v)            \
    \         \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i],\
    \ u[i], v[i]);             \\\n  }\n#define die(...)             \\\n  do {  \
    \                     \\\n    Nyaan::out(__VA_ARGS__); \\\n    return;       \
    \           \\\n  } while (0)\n#line 70 \"template/template.hpp\"\n\nnamespace\
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line 4 \"verify/verify-yosupo-ds/yosupo-associative-array-rbstseg.test.cpp\"\
    \n//\n#line 2 \"segment-tree/rbst-segment-tree.hpp\"\n\ntemplate <typename I,\
    \ typename T, typename E, T (*f)(T, T), T (*g)(T, E),\n          E (*h)(E, E),\
    \ T (*ti)(), E (*ei)()>\nstruct RBSTLazySegmentTree {\n  struct Node {\n    Node\
    \ *l, *r;\n    I index;\n    T key, sum;\n    E lazy;\n    int cnt;\n    Node(const\
    \ I &i, const T &t = ti())\n        : l(), r(), index(i), key(t), sum(t), lazy(ei()),\
    \ cnt(1) {}\n  };\n\n protected:\n  using Ptr = Node *;\n  template <typename...\
    \ Args>\n  inline Ptr my_new(Args... args) {\n    return new Node(args...);\n\
    \  }\n  inline void my_del(Ptr t) { delete t; }\n\n  inline int count(const Ptr\
    \ t) const { return t ? t->cnt : 0; }\n\n  static uint64_t rng() {\n    static\
    \ uint64_t x_ = 88172645463325252ULL;\n    return x_ ^= x_ << 7, x_ ^= x_ >> 9,\
    \ x_ & 0xFFFFFFFFull;\n  }\n\n  Ptr merge(Ptr l, Ptr r) {\n    if (!l || !r) return\
    \ l ? l : r;\n    if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n   \
    \   push(l);\n      l->r = merge(l->r, r);\n      return update(l);\n    } else\
    \ {\n      push(r);\n      r->l = merge(l, r->l);\n      return update(r);\n \
    \   }\n  }\n\n  Ptr build(int l, int r, const vector<pair<I, T>> &dat) {\n   \
    \ if (l == r) return nullptr;\n    if (l + 1 == r) return my_new(dat[l].first,\
    \ dat[l].second);\n    int m = (l + r) / 2;\n    return merge(build(l, m, dat),\
    \ build(m, r, dat));\n  };\n\n  void push(Ptr t) {\n    if (!t) return;\n    if\
    \ (t->lazy != ei()) {\n      if (t->l) propagate(t->l, t->lazy);\n      if (t->r)\
    \ propagate(t->r, t->lazy);\n      t->lazy = ei();\n    }\n  }\n\n  Ptr update(Ptr\
    \ t) {\n    if (!t) return t;\n    //push(t);\n    t->cnt = 1;\n    t->sum = t->key;\n\
    \    if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n    if (t->r)\
    \ t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);\n    return t;\n  }\n\n\
    \  void propagate(Ptr t, const E &x) {\n    if (!t) return;\n    t->lazy = h(t->lazy,\
    \ x);\n    t->key = g(t->key, x);\n    t->sum = g(t->sum, x);\n  }\n\n  // index\
    \ \u304C k \u3067\u3042\u308B\u30CE\u30FC\u30C9\u3092\u63A2\u3059, \u306A\u3051\
    \u308C\u3070 nullptr\n  Ptr find(Ptr t, I k) {\n    while (t) {\n      push(t);\n\
    \      if (k == t->index) return t;\n      if (k < t->index) {\n        t = t->l;\n\
    \      } else {\n        t = t->r;\n      }\n    }\n    return nullptr;\n  }\n\
    \n  // [k \u672A\u6E80, k \u4EE5\u4E0A]\n  pair<Ptr, Ptr> split_left(Ptr t, I\
    \ k) {\n    if (!t) return {nullptr, nullptr};\n    push(t);\n    if (k == t->index)\
    \ {\n      Ptr tl = t->l;\n      t->l = nullptr;\n      return {tl, update(t)};\n\
    \    } else if (k < t->index) {\n      auto s = split_left(t->l, k);\n      t->l\
    \ = s.second;\n      return {s.first, update(t)};\n    } else {\n      auto s\
    \ = split_left(t->r, k);\n      t->r = s.first;\n      return {update(t), s.second};\n\
    \    }\n  }\n\n  // [k \u672A\u6E80, k, k \u8D85\u904E]\n  array<Ptr, 3> split_by_index(Ptr\
    \ t, I k) {\n    if (!t) return {{nullptr, nullptr, nullptr}};\n    push(t);\n\
    \    if (k == t->index) {\n      Ptr tl = t->l, tr = t->r;\n      t->l = t->r\
    \ = nullptr;\n      return {{tl, update(t), tr}};\n    } else if (k < t->index)\
    \ {\n      auto s = split_by_index(t->l, k);\n      t->l = s[2];\n      return\
    \ {{s[0], s[1], update(t)}};\n    } else {\n      auto s = split_by_index(t->r,\
    \ k);\n      t->r = s[0];\n      return {{update(t), s[1], s[2]}};\n    }\n  }\n\
    \n  // r \u672A\u6E80\n  T _fold_left(Ptr t, I r) {\n    if (!t) return ti();\n\
    \    push(t);\n    if (t->index == r) {\n      return t->l ? t->l->sum : ti();\n\
    \    } else if (t->index > r) {\n      return _fold_left(t->l, r);\n    } else\
    \ {\n      T l = t->l ? t->l->sum : ti();\n      l = f(l, t->key);\n      return\
    \ f(l, _fold_left(t->r, r));\n    }\n  }\n\n  // l \u4EE5\u4E0A\n  T _fold_right(Ptr\
    \ t, I l) {\n    if (!t) return ti();\n    push(t);\n    if (t->index == l) {\n\
    \      T r = t->r ? t->r->sum : ti();\n      return f(t->key, r);\n    } else\
    \ if (t->index < l) {\n      return _fold_right(t->r, l);\n    } else {\n    \
    \  T r = t->r ? t->r->sum : ti();\n      r = f(t->key, r);\n      return f(_fold_right(t->l,\
    \ l), r);\n    }\n  }\n\n  T _fold(Ptr t, I l, I r) {\n    if (!t) return ti();\n\
    \    push(t);\n    if (t->index < l) return _fold(t->r, l, r);\n    if (t->index\
    \ >= r) return _fold(t->l, l, r);\n    // l <= t->index < r\n    T tl = _fold_right(t->l,\
    \ l);\n    T tr = _fold_left(t->r, r);\n    return f(f(tl, t->key), tr);\n  }\n\
    \n  // t \u3092\u6839\u3068\u3059\u308B\u6728\u306E\u4E0A\u3067\u6700\u5C0F\u306E\
    \ index \u306F\uFF1F (t \u304C\u7A7A\u306E\u5834\u5408\u306F failed)\n  I _min_index(Ptr\
    \ t, const I &failed) {\n    if (t == nullptr) return failed;\n    while (t->l)\
    \ t = t->l;\n    return t->index;\n  }\n\n  // t \u3092\u6839\u3068\u3059\u308B\
    \u6728\u306E\u4E0A\u3067\u6700\u5927\u306E index \u306F\uFF1F (t \u304C\u7A7A\u306E\
    \u5834\u5408\u306F failed)\n  I _max_index(Ptr t, const I &failed) {\n    if (t\
    \ == nullptr) return failed;\n    while (t->r) t = t->r;\n    return t->index;\n\
    \  }\n\n  // t \u3092\u6839\u3068\u3059\u308B\u6728\u306E\u3046\u3061\u3001[0,\
    \ i \u306E\u533A\u9593 fold \u304C true \u306B\u306A\u308B\u6700\u5927\u306E i\
    \ \u306F\u4F55\u304B\uFF1F\n  // exclusive \u304B\u3064 (\u7A7A \u307E\u305F\u306F\
    [0,\u53F3]\u304C\u771F\u306E\u5834\u5408) \u306E\u5834\u5408\u306F failed(inf)\n\
    \  // inclusive \u304B\u3064 (\u7A7A \u307E\u305F\u306F[0,0] \u304C\u507D\u306E\
    \u5834\u5408) \u306E\u5834\u5408\u306F failed\n  template <typename C, bool exclusive>\n\
    \  I _max_right(Ptr t, C check, const I &failed) {\n    if (t == nullptr) return\
    \ failed;\n    push(t);\n    Ptr now = t;\n    T prod_now = ti();\n    [[maybe_unused]]\
    \ I prev = failed;\n    while (true) {\n      if (now->l != nullptr) {\n     \
    \   push(now->l);\n        auto pl = f(prod_now, now->l->sum);\n        if (check(pl))\
    \ {\n          prod_now = pl;\n        } else {\n          now = now->l;\n   \
    \       continue;\n        }\n      }\n      auto pl = f(prod_now, now->key);\n\
    \      if (!check(pl)) {\n        if constexpr (exclusive) {\n          return\
    \ now->index;\n        } else {\n          return now->l ? _max_index(now->l,\
    \ failed) : prev;\n        }\n      }\n      prod_now = pl;\n      if (now->r\
    \ == nullptr) {\n        if constexpr (exclusive) {\n          return failed;\n\
    \        } else {\n          return now->index;\n        }\n      }\n      push(now->r);\n\
    \      if constexpr (!exclusive) prev = now->index;\n      now = now->r;\n   \
    \ }\n  }\n\n  // t \u3092\u6839\u3068\u3059\u308B\u6728\u306E\u3046\u3061\u3001\
    i, inf) \u306E\u533A\u9593 fold \u304C true \u306B\u306A\u308B\u6700\u5C0F\u306E\
    \ i \u306F\u4F55\u304B\uFF1F\n  // inclusive \u304B\u3064 (\u7A7A \u307E\u305F\
    \u306F \u5B58\u5728\u3057\u306A\u3044) \u5834\u5408\u306F failed\n  // exlucisve\
    \ \u304B\u3064 (\u7A7A \u307E\u305F\u306F [\u5DE6, inf) \u304C\u771F) \u306E\u5834\
    \u5408\u306F failed\n  template <typename C, bool inclusive>\n  I _min_left(Ptr\
    \ t, C check, const I &failed) {\n    if (t == nullptr) return failed;\n    push(t);\n\
    \    Ptr now = t;\n    T prod_now = ti();\n    [[maybe_unused]] I prev = failed;\n\
    \    while (true) {\n      if (now->r != nullptr) {\n        push(now->r);\n \
    \       auto pr = f(now->r->sum, prod_now);\n        if (check(pr)) {\n      \
    \    prod_now = pr;\n        } else {\n          now = now->r;\n          continue;\n\
    \        }\n      }\n      auto pr = f(now->key, prod_now);\n      if (!check(pr))\
    \ {\n        if constexpr (inclusive) {\n          return now->r ? _min_index(now->r,\
    \ failed) : prev;\n        } else {\n          return now->index;\n        }\n\
    \      }\n      prod_now = pr;\n      if (now->l == nullptr) {\n        if constexpr\
    \ (inclusive) {\n          return now->index;\n        } else {\n          return\
    \ failed;\n        }\n      }\n      push(now->l);\n      if constexpr (inclusive)\
    \ prev = now->index;\n      now = now->l;\n    }\n  }\n\n  void inner_dump(Ptr\
    \ t) {\n    push(t);\n    if (t->l) inner_dump(t->l);\n    cerr << \"## i = \"\
    \ << t->index << \", \";\n    cerr << \"\\tkey = \" << t->key << \", \";\n   \
    \ cerr << \"\\tsum = \" << t->sum << \", \";\n    cerr << \"\\tchild = \";\n \
    \   cerr << \"( \" << (t->l ? to_string(t->l->index) : \"nil\");\n    cerr <<\
    \ \", \";\n    cerr << (t->r ? to_string(t->r->index) : \"nil\");\n    cerr <<\
    \ \" )\" << endl;\n    if (t->r) inner_dump(t->r);\n  }\n\n public:\n  Ptr root;\n\
    \n  RBSTLazySegmentTree() : root(nullptr) {}\n  RBSTLazySegmentTree(const vector<T>\
    \ xs, const vector<I> &is = {}) {\n    if (!is.empty()) assert(xs.size() == is.size());\n\
    \    int n = xs.size();\n    vector<pair<I, T>> dat(n);\n    for (int i = 0; i\
    \ < n; i++) dat[i] = {is.empty() ? i : is[i], xs[i]};\n    root = build(0, n,\
    \ dat);\n  }\n\n  // 1 \u70B9 \u5024\u306E\u66F8\u304D\u63DB\u3048\n  void set_val(I\
    \ i, T x) {\n    auto s = split_by_index(root, i);\n    if (s[1] == nullptr) {\n\
    \      s[1] = my_new(i, x);\n    } else {\n      s[1]->key = x;\n    }\n    root\
    \ = merge(merge(s[0], update(s[1])), s[2]);\n  }\n\n  // \u3059\u3067\u306B\u8981\
    \u7D20\u304C\u5B58\u5728\u3059\u308B\u3068\u304D\u306B\u5024\u3092 set \u3059\u308B\
    \u3002\u304A\u305D\u3089\u304F\u5C11\u3057\u65E9\u3044\n  void set_val_fast(I\
    \ i, T x) {\n    static vector<Ptr> ps;\n    ps.clear();\n\n    Ptr t = root;\n\
    \    while (t) {\n      push(t);\n      ps.push_back(t);\n      if (i == t->index)\
    \ break;\n      if (i < t->index) {\n        t = t->l;\n      } else {\n     \
    \   t = t->r;\n      }\n    }\n    if (!t) {\n      set_val(i, x);\n      return;\n\
    \    }\n    t->key = x;\n    for (int j = ps.size() - 1; j >= 0; j--) update(ps[j]);\n\
    \  }\n\n  // 1 \u70B9\u53D6\u5F97\n  T get_val(I i) {\n    Ptr p = find(root,\
    \ i);\n    return p ? p->key : ti();\n  }\n\n  // \u9802\u70B9\u306E\u524A\u9664\
    \n  void erase(I i) {\n    auto s = split_by_index(root, i);\n    if (s[1]) my_del(s[1]);\n\
    \    root = merge(s[0], s[2]);\n  }\n\n  // \u7BC4\u56F2\u4F5C\u7528\n  void apply(I\
    \ l, I r, const E &e) {\n    auto [x, aux] = split_left(root, l);\n    auto [y,\
    \ z] = split_left(aux, r);\n    propagate(y, e);\n    root = merge(merge(x, y),\
    \ z);\n  }\n\n  // \u7BC4\u56F2\u53D6\u5F97\n  T fold(I l, I r) {\n    return\
    \ _fold(root, l, r);\n    // auto [x, aux] = split_left(root, l);\n    // auto\
    \ [y, z] = split_left(aux, r);\n    // T res = y ? y->sum : ti();\n    // root\
    \ = merge(merge(x, y), z);\n    // return res;\n  }\n\n  // n \u672A\u6E80\u306E\
    \ i \u306E\u3046\u3061\u3001[i, n) \u306E\u533A\u9593 fold \u304C true \u306B\u306A\
    \u308B\u6700\u5C0F\u306E i \u306F\u4F55\u304B\uFF1F\n  // (\u5B58\u5728\u3057\u306A\
    \u3044\u5834\u5408\u306F failed \u3092\u8FD4\u3059)\n  template <typename C>\n\
    \  I min_left(I n, C check, I failed) {\n    assert(check(ti()) == true);\n  \
    \  auto [x, y] = split_left(root, n);\n    I res = _min_left<C, true>(x, check,\
    \ failed);\n    root = merge(x, y);\n    return res;\n  }\n\n  // n \u672A\u6E80\
    \u306E i \u306E\u3046\u3061\u3001(i, n) \u306E\u533A\u9593 fold \u304C true \u306B\
    \u306A\u308B\u6700\u5C0F\u306E i \u306F\u4F55\u304B\uFF1F\n  // (\u7A7A\u3060\u3063\
    \u305F\u308A (\u5DE6\u7AEF, n) \u304C \u771F\u306E\u5834\u5408\u306F minus_infty\
    \ \u3092\u8FD4\u3059)\n  template <typename C>\n  I min_left_exclusive(I n, C\
    \ check, I minus_infty) {\n    assert(check(ti()) == true);\n    auto [x, y] =\
    \ split_left(root, n);\n    I res = _min_left<C, false>(x, check, minus_infty);\n\
    \    root = merge(x, y);\n    return res;\n  }\n\n  // n \u4EE5\u4E0A\u306E i\
    \ \u306E\u3046\u3061\u3001[n, i) \u306E\u533A\u9593 fold \u304C true \u306B\u306A\
    \u308B\u6700\u5927\u306E i \u306F\u4F55\u304B\uFF1F\n  // (\u7A7A\u3060\u3063\u305F\
    \u308A [n, \u53F3\u7AEF] \u304C true \u306E\u5834\u5408\u306F infty \u3092\u8FD4\
    \u3059)\n  template <typename C>\n  I max_right(I n, C check, I infty) {\n   \
    \ assert(check(ti()) == true);\n    auto [x, y] = split_left(root, n);\n    I\
    \ res = _max_right<C, true>(y, check, infty);\n    root = merge(x, y);\n    return\
    \ res;\n  }\n\n  // n \u4EE5\u4E0A\u306E i \u306E\u3046\u3061\u3001[n, i] \u306E\
    \u533A\u9593 fold \u304C true \u306B\u306A\u308B\u6700\u5927\u306E i \u306F\u4F55\
    \u304B\uFF1F\n  // (\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F failed \u3092\
    \u8FD4\u3059)\n  template <typename C>\n  I max_right_inclusive(I n, C check,\
    \ I failed) {\n    assert(check(ti()) == true);\n    auto [x, y] = split_left(root,\
    \ n);\n    I res = _max_right<C, false>(y, check, failed);\n    root = merge(x,\
    \ y);\n    return res;\n  }\n\n  void dump() { inner_dump(root); }\n};\n\nnamespace\
    \ RBSTSegmentTreeImpl {\n\ntemplate <typename T>\nT g(T l, bool) {\n  return l;\n\
    }\nbool h(bool, bool) { return false; }\nbool ei() { return false; }\n\ntemplate\
    \ <typename I, typename T, T (*f)(T, T), T (*ti)()>\nusing RBSTSegmentTree = RBSTLazySegmentTree<I,\
    \ T, bool, f, g, h, ti, ei>;\n}  // namespace RBSTSegmentTreeImpl\n\nusing RBSTSegmentTreeImpl::RBSTSegmentTree;\n\
    \n/**\n * @brief RBST-based Dynamic Lazy Segment Tree\n */\n#line 6 \"verify/verify-yosupo-ds/yosupo-associative-array-rbstseg.test.cpp\"\
    \n//\nusing namespace Nyaan;\n\nll f(ll, ll) { return 0; }\nll ti() { return 0;\
    \ }\nusing Seg = RBSTSegmentTree<ll, ll, f, ti>;\n\nvoid Nyaan::solve() {\n  Seg\
    \ seg;\n  inl(Q);\n  while (Q--) {\n    ini(cmd);\n    if (cmd == 0) {\n     \
    \ inl(k, v);\n      seg.set_val(k, v);\n    } else {\n      inl(k);\n      out(seg.get_val(k));\n\
    \    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n//\n\
    #include \"../../template/template.hpp\"\n//\n#include \"../../segment-tree/rbst-segment-tree.hpp\"\
    \n//\nusing namespace Nyaan;\n\nll f(ll, ll) { return 0; }\nll ti() { return 0;\
    \ }\nusing Seg = RBSTSegmentTree<ll, ll, f, ti>;\n\nvoid Nyaan::solve() {\n  Seg\
    \ seg;\n  inl(Q);\n  while (Q--) {\n    ini(cmd);\n    if (cmd == 0) {\n     \
    \ inl(k, v);\n      seg.set_val(k, v);\n    } else {\n      inl(k);\n      out(seg.get_val(k));\n\
    \    }\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - segment-tree/rbst-segment-tree.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-associative-array-rbstseg.test.cpp
  requiredBy: []
  timestamp: '2022-01-13 15:07:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-associative-array-rbstseg.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-associative-array-rbstseg.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-associative-array-rbstseg.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-associative-array-rbstseg.test.cpp
---
