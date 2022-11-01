---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/affine-transformation.hpp
    title: "\u30A2\u30D5\u30A3\u30F3\u5909\u63DB"
  - icon: ':x:'
    path: misc/all.hpp
    title: misc/all.hpp
  - icon: ':question:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':question:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':question:'
    path: misc/timer.hpp
    title: misc/timer.hpp
  - icon: ':question:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':question:'
    path: segment-tree/lazy-segment-tree.hpp
    title: segment-tree/lazy-segment-tree.hpp
  - icon: ':question:'
    path: segment-tree/rbst-segment-tree.hpp
    title: RBST-based Dynamic Lazy Segment Tree
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
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n\
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
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line 2 \"verify/verify-unit-test/rbst-segment-tree.test.cpp\"\
    \n//\n#line 2 \"segment-tree/rbst-segment-tree.hpp\"\n\ntemplate <typename I,\
    \ typename T, typename E, T (*f)(T, T), T (*g)(T, E),\n          E (*h)(E, E),\
    \ T (*ti)(), E (*ei)()>\nstruct RBSTLazySegmentTree {\n  struct Node {\n    Node\
    \ *l, *r;\n    I key;\n    T val, sum;\n    E lazy;\n    int cnt;\n    Node(const\
    \ I &i, const T &t = ti())\n        : l(), r(), key(i), val(t), sum(t), lazy(ei()),\
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
    \ build(m, r, dat));\n  };\n\n  void push([[maybe_unused]] Ptr t) {\n#pragma GCC\
    \ diagnostic ignored \"-Waddress\"\n    if constexpr (g != nullptr) {\n#pragma\
    \ GCC diagnostic warning \"-Waddress\"\n      if (!t) return;\n      if (t->lazy\
    \ != ei()) {\n        if (t->l) propagate(t->l, t->lazy);\n        if (t->r) propagate(t->r,\
    \ t->lazy);\n        t->lazy = ei();\n      }\n    }\n  }\n\n  Ptr update(Ptr\
    \ t) {\n    if (!t) return t;\n    t->cnt = 1;\n    t->sum = t->val;\n    if (t->l)\
    \ t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n    if (t->r) t->cnt +=\
    \ t->r->cnt, t->sum = f(t->sum, t->r->sum);\n    return t;\n  }\n\n  void propagate([[maybe_unused]]\
    \ Ptr t, [[maybe_unused]] const E &x) {\n#pragma GCC diagnostic ignored \"-Waddress\"\
    \n    if constexpr (g != nullptr) {\n#pragma GCC diagnostic warning \"-Waddress\"\
    \n      if (!t) return;\n      t->lazy = h(t->lazy, x);\n      t->val = g(t->val,\
    \ x);\n      t->sum = g(t->sum, x);\n    }\n  }\n\n  // key \u304C k \u3067\u3042\
    \u308B\u30CE\u30FC\u30C9\u3092\u63A2\u3059, \u306A\u3051\u308C\u3070 nullptr\n\
    \  Ptr find(Ptr t, I k) {\n    while (t) {\n      push(t);\n      if (k == t->key)\
    \ return t;\n      t = k < t->key ? t->l : t->r;\n    }\n    return nullptr;\n\
    \  }\n\n  // [k \u672A\u6E80, k \u4EE5\u4E0A]\n  pair<Ptr, Ptr> split_left(Ptr\
    \ t, I k) {\n    if (!t) return {nullptr, nullptr};\n    push(t);\n    if (k ==\
    \ t->key) {\n      Ptr tl = t->l;\n      t->l = nullptr;\n      return {tl, update(t)};\n\
    \    } else if (k < t->key) {\n      auto s = split_left(t->l, k);\n      t->l\
    \ = s.second;\n      return {s.first, update(t)};\n    } else {\n      auto s\
    \ = split_left(t->r, k);\n      t->r = s.first;\n      return {update(t), s.second};\n\
    \    }\n  }\n\n  // [k \u672A\u6E80, k, k \u8D85\u904E]\n  array<Ptr, 3> split_by_key(Ptr\
    \ t, I k) {\n    if (!t) return {{nullptr, nullptr, nullptr}};\n    push(t);\n\
    \    if (k == t->key) {\n      Ptr tl = t->l, tr = t->r;\n      t->l = t->r =\
    \ nullptr;\n      return {{tl, update(t), tr}};\n    } else if (k < t->key) {\n\
    \      auto s = split_by_key(t->l, k);\n      t->l = s[2];\n      return {{s[0],\
    \ s[1], update(t)}};\n    } else {\n      auto s = split_by_key(t->r, k);\n  \
    \    t->r = s[0];\n      return {{update(t), s[1], s[2]}};\n    }\n  }\n\n  //\
    \ x \u4EE5\u4E0A\u306E key \u6700\u5C0F\u3002\u5B58\u5728\u3057\u306A\u3044\u5834\
    \u5408\u306F infty\n  I _lower_bound_key(Ptr t, I i, I infty) {\n    I res = infty;\n\
    \    while (!t) {\n      if (i == t->key) return i;\n      if (i < t->key) {\n\
    \        res = min(res, t->key);\n        t = t->l;\n      } else {\n        t\
    \ = t->l;\n      }\n    }\n    return res;\n  }\n\n  // x \u8D85\u904E\u306E key\
    \ \u6700\u5C0F\u3002\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F infty\n \
    \ I _upper_bound_key(Ptr t, I i, I infty) {\n    I res = infty;\n    while (!t)\
    \ {\n      if (i == t->key) return i;\n      if (i < t->key) {\n        res =\
    \ min(res, t->key);\n        t = t->l;\n      } else {\n        t = t->l;\n  \
    \    }\n    }\n    return res;\n  }\n\n  // [l, inf) \u3067\u3042\u308B\u5730\u70B9\
    \u306B apply\n  void _apply_left(Ptr t, I l, const E &e) {\n    if (!t) return;\n\
    \    push(t);\n    if (t->key < l) {\n      _apply_left(t->r, l, e);\n    } else\
    \ if (t->key == l) {\n      t->val = g(t->val, e);\n      propagate(t->r, e);\n\
    \    } else {\n      _apply_left(t->l, l, e);\n      t->val = g(t->val, e);\n\
    \      propagate(t->r, e);\n    }\n    update(t);\n  }\n\n  // [-inf, r) \u3067\
    \u3042\u308B\u5730\u70B9\u306B apply\n  void _apply_right(Ptr t, I r, const E\
    \ &e) {\n    if (!t) return;\n    push(t);\n    if (t->key < r) {\n      propagate(t->l,\
    \ e);\n      t->val = g(t->val, e);\n      _apply_right(t->r, r, e);\n    } else\
    \ if (t->key == r) {\n      propagate(t->l, e);\n    } else {\n      _apply_right(t->l,\
    \ r, e);\n    }\n    update(t);\n  }\n\n  void _apply(Ptr t, I l, I r, const E\
    \ &e) {\n    if (!t) return;\n    push(t);\n    if (t->key < l) {\n      _apply(t->r,\
    \ l, r, e);\n    } else if (t->key == l) {\n      t->val = g(t->val, e);\n   \
    \   _apply_right(t->r, r, e);\n    } else if (t->key < r) {\n      _apply_left(t->l,\
    \ l, e);\n      t->val = g(t->val, e);\n      _apply_right(t->r, r, e);\n    }\
    \ else if (t->key == r) {\n      _apply_left(t->l, l, e);\n    } else {\n    \
    \  _apply(t->l, l, r, e);\n    }\n    update(t);\n  }\n\n  T _sum(const Ptr &t)\
    \ { return t ? t->sum : ti(); }\n\n  // l \u4EE5\u4E0A\n  T _fold_left(Ptr t,\
    \ I l) {\n    if (!t) return ti();\n    push(t);\n    if (t->key < l) {\n    \
    \  return _fold_left(t->r, l);\n    } else if (t->key == l) {\n      return f(t->val,\
    \ _fold_left(t->r, l));\n    } else {\n      T tl = _fold_left(t->l, l);\n   \
    \   return f(f(tl, t->val), _sum(t->r));\n    }\n  }\n\n  // r \u672A\u6E80\n\
    \  T _fold_right(Ptr t, I r) {\n    if (!t) return ti();\n    push(t);\n    if\
    \ (t->key < r) {\n      T tr = _fold_right(t->r, r);\n      return f(f(_sum(t->l),\
    \ t->val), tr);\n    } else if (t->key == r) {\n      return _sum(t->l);\n   \
    \ } else {\n      return _fold_right(t->l, r);\n    }\n  }\n\n  T _fold(Ptr t,\
    \ I l, I r) {\n    if (!t) return ti();\n    push(t);\n    if (t->key < l) {\n\
    \      return _fold(t->r, l, r);\n    } else if (t->key == l) {\n      return\
    \ f(t->val, _fold_right(t->r, r));\n    } else if (t->key < r) {\n      T tl =\
    \ _fold_left(t->l, l);\n      T tr = _fold_right(t->r, r);\n      return f(f(tl,\
    \ t->val), tr);\n    } else if (t->key == r) {\n      return _fold_left(t->l,\
    \ l);\n    } else {\n      return _fold(t->l, l, r);\n    }\n  }\n\n  // t \u3092\
    \u6839\u3068\u3059\u308B\u6728\u306E\u4E0A\u3067\u6700\u5C0F\u306E key \u306F\uFF1F\
    \ (t \u304C\u7A7A\u306E\u5834\u5408\u306F failed)\n  I _get_min_key(Ptr t, const\
    \ I &failed) {\n    if (t == nullptr) return failed;\n    while (t->l) t = t->l;\n\
    \    return t->key;\n  }\n\n  // t \u3092\u6839\u3068\u3059\u308B\u6728\u306E\u4E0A\
    \u3067\u6700\u5927\u306E key \u306F\uFF1F (t \u304C\u7A7A\u306E\u5834\u5408\u306F\
    \ failed)\n  I _get_max_key(Ptr t, const I &failed) {\n    if (t == nullptr) return\
    \ failed;\n    while (t->r) t = t->r;\n    return t->key;\n  }\n\n  // t \u3092\
    \u6839\u3068\u3059\u308B\u6728\u306E\u4E0A\u3067\u6700\u5C0F\u306E key \u306F\uFF1F\
    \ (t \u304C\u7A7A\u306E\u5834\u5408\u306F failed)\n  pair<I, T> _get_min_keyval(Ptr\
    \ t, const I &failed) {\n    if (t == nullptr) return {failed, ti()};\n    while\
    \ (t->l) push(t), t = t->l;\n    return {t->key, t->val};\n  }\n\n  // t \u3092\
    \u6839\u3068\u3059\u308B\u6728\u306E\u4E0A\u3067\u6700\u5C0F\u306E key \u306F\uFF1F\
    \ (t \u304C\u7A7A\u306E\u5834\u5408\u306F failed)\n  pair<I, T> _get_max_keyval(Ptr\
    \ t, const I &failed) {\n    if (t == nullptr) return {failed, ti()};\n    while\
    \ (t->r) push(t), t = t->r;\n    return {t->key, t->val};\n  }\n\n  // t \u3092\
    \u6839\u3068\u3059\u308B\u6728\u306E\u3046\u3061\u3001[0, i \u306E\u533A\u9593\
    \ fold \u304C true \u306B\u306A\u308B\u6700\u5927\u306E i \u306F\u4F55\u304B\uFF1F\
    \n  // exclusive \u304B\u3064 (\u7A7A \u307E\u305F\u306F[0,\u53F3]\u304C\u771F\
    \u306E\u5834\u5408) \u306E\u5834\u5408\u306F failed(inf)\n  // inclusive \u304B\
    \u3064 (\u7A7A \u307E\u305F\u306F[0,0] \u304C\u507D\u306E\u5834\u5408) \u306E\u5834\
    \u5408\u306F failed\n  template <typename C, bool exclusive>\n  I _max_right(Ptr\
    \ t, C check, const I &failed) {\n    if (t == nullptr) return failed;\n    push(t);\n\
    \    Ptr now = t;\n    T prod_now = ti();\n    [[maybe_unused]] I prev = failed;\n\
    \    while (true) {\n      if (now->l != nullptr) {\n        push(now->l);\n \
    \       auto pl = f(prod_now, now->l->sum);\n        if (check(pl)) {\n      \
    \    prod_now = pl;\n        } else {\n          now = now->l;\n          continue;\n\
    \        }\n      }\n      auto pl = f(prod_now, now->val);\n      if (!check(pl))\
    \ {\n        if constexpr (exclusive) {\n          return now->key;\n        }\
    \ else {\n          return now->l ? _get_max_key(now->l, failed) : prev;\n   \
    \     }\n      }\n      prod_now = pl;\n      if (now->r == nullptr) {\n     \
    \   if constexpr (exclusive) {\n          return failed;\n        } else {\n \
    \         return now->key;\n        }\n      }\n      push(now->r);\n      if\
    \ constexpr (!exclusive) prev = now->key;\n      now = now->r;\n    }\n  }\n\n\
    \  // t \u3092\u6839\u3068\u3059\u308B\u6728\u306E\u3046\u3061\u3001i, inf) \u306E\
    \u533A\u9593 fold \u304C true \u306B\u306A\u308B\u6700\u5C0F\u306E i \u306F\u4F55\
    \u304B\uFF1F\n  // inclusive \u304B\u3064 (\u7A7A \u307E\u305F\u306F \u5B58\u5728\
    \u3057\u306A\u3044) \u5834\u5408\u306F failed\n  // exlucisve \u304B\u3064 (\u7A7A\
    \ \u307E\u305F\u306F [\u5DE6, inf) \u304C\u771F) \u306E\u5834\u5408\u306F failed\n\
    \  template <typename C, bool inclusive>\n  I _min_left(Ptr t, C check, const\
    \ I &failed) {\n    if (t == nullptr) return failed;\n    push(t);\n    Ptr now\
    \ = t;\n    T prod_now = ti();\n    [[maybe_unused]] I prev = failed;\n    while\
    \ (true) {\n      if (now->r != nullptr) {\n        push(now->r);\n        auto\
    \ pr = f(now->r->sum, prod_now);\n        if (check(pr)) {\n          prod_now\
    \ = pr;\n        } else {\n          now = now->r;\n          continue;\n    \
    \    }\n      }\n      auto pr = f(now->val, prod_now);\n      if (!check(pr))\
    \ {\n        if constexpr (inclusive) {\n          return now->r ? _get_min_key(now->r,\
    \ failed) : prev;\n        } else {\n          return now->key;\n        }\n \
    \     }\n      prod_now = pr;\n      if (now->l == nullptr) {\n        if constexpr\
    \ (inclusive) {\n          return now->key;\n        } else {\n          return\
    \ failed;\n        }\n      }\n      push(now->l);\n      if constexpr (inclusive)\
    \ prev = now->key;\n      now = now->l;\n    }\n  }\n\n  void _clear(Ptr t) {\n\
    \    if (!t) return;\n    if (t->l) _clear(t->l);\n    if (t->r) _clear(t->r);\n\
    \    my_del(t);\n  }\n\n  void inner_dump(Ptr t) {\n    push(t);\n    if (t->l)\
    \ inner_dump(t->l);\n    cerr << \"## i = \" << t->key << \", \";\n    cerr <<\
    \ \"\\tkey = \" << t->val << \", \";\n    cerr << \"\\tsum = \" << t->sum << \"\
    , \";\n    cerr << \"\\tchild = \";\n    cerr << \"( \" << (t->l ? to_string(t->l->key)\
    \ : \"nil\");\n    cerr << \", \";\n    cerr << (t->r ? to_string(t->r->key) :\
    \ \"nil\");\n    cerr << \" )\" << endl;\n    if (t->r) inner_dump(t->r);\n  }\n\
    \n  void inner_make_array(Ptr t, vector<pair<I, T>> &v) {\n    if (!t) return;\n\
    \    push(t);\n    if (t->l) inner_make_array(t->l, v);\n    v.emplace_back(t->key,\
    \ t->val);\n    if (t->r) inner_make_array(t->r, v);\n  }\n\n public:\n  Ptr root;\n\
    \n  RBSTLazySegmentTree() : root(nullptr) {}\n  RBSTLazySegmentTree(const vector<T>\
    \ xs, const vector<I> &is = {}) {\n    if (!is.empty()) assert(xs.size() == is.size());\n\
    \    int n = xs.size();\n    vector<pair<I, T>> dat(n);\n    for (int i = 0; i\
    \ < n; i++) dat[i] = {is.empty() ? i : is[i], xs[i]};\n    root = build(0, n,\
    \ dat);\n  }\n\n  // 1 \u70B9 \u5024\u306E\u66F8\u304D\u63DB\u3048\n  void set_val(I\
    \ i, T x) {\n    auto s = split_by_key(root, i);\n    if (s[1] == nullptr) {\n\
    \      s[1] = my_new(i, x);\n    } else {\n      s[1]->val = x;\n    }\n    root\
    \ = merge(merge(s[0], update(s[1])), s[2]);\n  }\n\n  // \u3059\u3067\u306B\u8981\
    \u7D20\u304C\u5B58\u5728\u3059\u308B\u3068\u304D\u306B\u5024\u3092 set \u3059\u308B\
    \u3002\u304A\u305D\u3089\u304F\u5C11\u3057\u65E9\u3044\n  void set_val_fast(I\
    \ i, T x) {\n    static vector<Ptr> ps;\n    ps.clear();\n\n    Ptr t = root;\n\
    \    while (t) {\n      push(t);\n      ps.push_back(t);\n      if (i == t->key)\
    \ break;\n      if (i < t->key) {\n        t = t->l;\n      } else {\n       \
    \ t = t->r;\n      }\n    }\n    if (!t) {\n      set_val(i, x);\n      return;\n\
    \    }\n    t->val = x;\n    for (int j = ps.size() - 1; j >= 0; j--) update(ps[j]);\n\
    \  }\n\n  // 1 \u70B9\u53D6\u5F97\n  T get_val(I i) {\n    Ptr p = find(root,\
    \ i);\n    return p ? p->val : ti();\n  }\n\n  // 1 \u70B9 \u5024\u306E\u66F8\u304D\
    \u63DB\u3048\n  // func \u306E\u8FD4\u308A\u5024\u306F void !!!!!!(\u53C2\u7167\
    \u3055\u308C\u305F\u5024\u3092\u76F4\u63A5\u66F4\u65B0\u3059\u308B)\n  void apply_val(I\
    \ i, const function<void(T &)> &func) {\n    auto s = split_by_key(root, i);\n\
    \    if (s[1] == nullptr) s[1] = my_new(i);\n    func(s[1]->val);\n    root =\
    \ merge(merge(s[0], update(s[1])), s[2]);\n  }\n  // 1 \u70B9 \u5024\u306E\u66F8\
    \u304D\u63DB\u3048 \u5024\u304C\u65E2\u306B\u5B58\u5728\u3059\u308B\u3068\u304D\
    \u306B\u65E9\u3044\n  // func \u306E\u8FD4\u308A\u5024\u306F void !!!!!!(\u53C2\
    \u7167\u3055\u308C\u305F\u5024\u3092\u76F4\u63A5\u66F4\u65B0\u3059\u308B)\n  void\
    \ apply_val_fast(I i, const function<void(T &)> &func) {\n    static vector<Ptr>\
    \ ps;\n    ps.clear();\n    Ptr t = root;\n    while (t) {\n      push(t);\n \
    \     ps.push_back(t);\n      if (i == t->key) break;\n      if (i < t->key) {\n\
    \        t = t->l;\n      } else {\n        t = t->r;\n      }\n    }\n    if\
    \ (!t) {\n      apply_val(i, func);\n      return;\n    }\n    func(t->val);\n\
    \    for (int j = ps.size() - 1; j >= 0; j--) update(ps[j]);\n  }\n\n  // \u9802\
    \u70B9\u306E\u524A\u9664\n  void erase(I i) {\n    auto s = split_by_key(root,\
    \ i);\n    if (s[1]) my_del(s[1]);\n    root = merge(s[0], s[2]);\n  }\n\n  //\
    \ \u7BC4\u56F2\u4F5C\u7528\n  void apply(I l, I r, const E &e) {\n    if (l >=\
    \ r) return;\n    _apply(root, l, r, e);\n  }\n\n  // \u7BC4\u56F2\u53D6\u5F97\
    \n  T fold(I l, I r) {\n    if (l >= r) return ti();\n    return _fold(root, l,\
    \ r);\n  }\n\n  // key \u6700\u5C0F\u3092\u53D6\u5F97\n  I get_min_key(I failed\
    \ = -1) { return _get_min_key(root, failed); }\n  // key \u6700\u5927\u3092\u53D6\
    \u5F97\n  I get_max_key(I failed = -1) { return _get_max_key(root, failed); }\n\
    \  // (key, val) \u6700\u5C0F\u3092\u53D6\u5F97\n  pair<I, T> get_min_keyval(I\
    \ failed = -1) {\n    return _get_min_keyval(root, failed);\n  }\n  // (key, val)\
    \ \u6700\u5927\u3092\u53D6\u5F97\n  pair<I, T> get_max_keyval(I failed = -1) {\n\
    \    return _get_max_keyval(root, failed);\n  }\n  // (key, val) \u6700\u5C0F\u3092\
    \ pop\n  pair<I, T> pop_min_keyval(I failed = -1) {\n    assert(root != nullptr);\n\
    \    auto kv = _get_min_keyval(root, failed);\n    erase(kv.first);\n    return\
    \ kv;\n  }\n  // (key, val) \u6700\u5927\u3092\u53D6\u5F97\n  pair<I, T> pop_max_keyval(I\
    \ failed = -1) {\n    assert(root != nullptr);\n    auto kv = _get_max_keyval(root,\
    \ failed);\n    erase(kv.first);\n    return kv;\n  }\n\n  // n \u672A\u6E80\u306E\
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
    \ y);\n    return res;\n  }\n\n  void clear() { _clear(root), root = nullptr;\
    \ }\n  int size() { return count(root); }\n  bool empty() { return !root; }\n\
    \  void dump() { inner_dump(root); }\n\n  // \u5217\u3092\u914D\u5217\u306B\u5909\
    \u63DB\u3057\u3066\u8FD4\u3059\n  vector<pair<I, T>> make_array() {\n    vector<pair<I,\
    \ T>> res;\n    inner_make_array(root, res);\n    return res;\n  }\n};\n\nnamespace\
    \ RBSTSegmentTreeImpl {\nbool ei() { return false; }\ntemplate <typename I, typename\
    \ T, T (*f)(T, T), T (*ti)()>\nusing RBSTSegmentTree =\n    RBSTLazySegmentTree<I,\
    \ T, bool, f, nullptr, nullptr, ti, ei>;\n}  // namespace RBSTSegmentTreeImpl\n\
    using RBSTSegmentTreeImpl::RBSTSegmentTree;\n\n/**\n * @brief RBST-based Dynamic\
    \ Lazy Segment Tree\n */\n#line 4 \"verify/verify-unit-test/rbst-segment-tree.test.cpp\"\
    \n//\n#line 2 \"misc/fastio.hpp\"\n\n#line 6 \"misc/fastio.hpp\"\n\nusing namespace\
    \ std;\n\nnamespace fastio {\nstatic constexpr int SZ = 1 << 17;\nchar inbuf[SZ],\
    \ outbuf[SZ];\nint in_left = 0, in_right = 0, out_right = 0;\n\nstruct Pre {\n\
    \  char num[40000];\n  constexpr Pre() : num() {\n    for (int i = 0; i < 10000;\
    \ i++) {\n      int n = i;\n      for (int j = 3; j >= 0; j--) {\n        num[i\
    \ * 4 + j] = n % 10 + '0';\n        n /= 10;\n      }\n    }\n  }\n} constexpr\
    \ pre;\n\ninline void load() {\n  int len = in_right - in_left;\n  memmove(inbuf,\
    \ inbuf + in_left, len);\n  in_right = len + fread(inbuf + len, 1, SZ - len, stdin);\n\
    \  in_left = 0;\n}\n\ninline void flush() {\n  fwrite(outbuf, 1, out_right, stdout);\n\
    \  out_right = 0;\n}\n\ninline void skip_space() {\n  if (in_left + 32 > in_right)\
    \ load();\n  while (inbuf[in_left] <= ' ') in_left++;\n}\n\ninline void rd(char&\
    \ c) {\n  if (in_left + 32 > in_right) load();\n  c = inbuf[in_left++];\n}\ntemplate\
    \ <typename T>\ninline void rd(T& x) {\n  if (in_left + 32 > in_right) load();\n\
    \  char c;\n  do c = inbuf[in_left++];\n  while (c < '-');\n  [[maybe_unused]]\
    \ bool minus = false;\n  if constexpr (is_signed<T>::value == true) {\n    if\
    \ (c == '-') minus = true, c = inbuf[in_left++];\n  }\n  x = 0;\n  while (c >=\
    \ '0') {\n    x = x * 10 + (c & 15);\n    c = inbuf[in_left++];\n  }\n  if constexpr\
    \ (is_signed<T>::value == true) {\n    if (minus) x = -x;\n  }\n}\ninline void\
    \ rd() {}\ntemplate <typename Head, typename... Tail>\ninline void rd(Head& head,\
    \ Tail&... tail) {\n  rd(head);\n  rd(tail...);\n}\n\ninline void wt(char c) {\n\
    \  if (out_right > SZ - 32) flush();\n  outbuf[out_right++] = c;\n}\ninline void\
    \ wt(bool b) {\n  if (out_right > SZ - 32) flush();\n  outbuf[out_right++] = b\
    \ ? '1' : '0';\n}\ninline void wt(const string &s) {\n  if (out_right + s.size()\
    \ > SZ - 32) flush();\n  memcpy(outbuf + out_right, s.data(), sizeof(char) * s.size());\n\
    \  out_right += s.size();\n}\ntemplate <typename T>\ninline void wt(T x) {\n \
    \ if (out_right > SZ - 32) flush();\n  if (!x) {\n    outbuf[out_right++] = '0';\n\
    \    return;\n  }\n  if constexpr (is_signed<T>::value == true) {\n    if (x <\
    \ 0) outbuf[out_right++] = '-', x = -x;\n  }\n  int i = 12;\n  char buf[16];\n\
    \  while (x >= 10000) {\n    memcpy(buf + i, pre.num + (x % 10000) * 4, 4);\n\
    \    x /= 10000;\n    i -= 4;\n  }\n  if (x < 100) {\n    if (x < 10) {\n    \
    \  outbuf[out_right] = '0' + x;\n      ++out_right;\n    } else {\n      uint32_t\
    \ q = (uint32_t(x) * 205) >> 11;\n      uint32_t r = uint32_t(x) - q * 10;\n \
    \     outbuf[out_right] = '0' + q;\n      outbuf[out_right + 1] = '0' + r;\n \
    \     out_right += 2;\n    }\n  } else {\n    if (x < 1000) {\n      memcpy(outbuf\
    \ + out_right, pre.num + (x << 2) + 1, 3);\n      out_right += 3;\n    } else\
    \ {\n      memcpy(outbuf + out_right, pre.num + (x << 2), 4);\n      out_right\
    \ += 4;\n    }\n  }\n  memcpy(outbuf + out_right, buf + i + 4, 12 - i);\n  out_right\
    \ += 12 - i;\n}\ninline void wt() {}\ntemplate <typename Head, typename... Tail>\n\
    inline void wt(Head&& head, Tail&&... tail) {\n  wt(head);\n  wt(forward<Tail>(tail)...);\n\
    }\ntemplate <typename... Args>\ninline void wtn(Args&&... x) {\n  wt(forward<Args>(x)...);\n\
    \  wt('\\n');\n}\n\nstruct Dummy {\n  Dummy() { atexit(flush); }\n} dummy;\n\n\
    }  // namespace fastio\nusing fastio::rd;\nusing fastio::skip_space;\nusing fastio::wt;\n\
    using fastio::wtn;\n#line 2 \"misc/rng.hpp\"\n\nnamespace my_rand {\nusing i64\
    \ = long long;\nusing u64 = unsigned long long;\n\n// [0, 2^64 - 1)\nu64 rng()\
    \ {\n  static u64 _x =\n      u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \              chrono::high_resolution_clock::now().time_since_epoch())\n    \
    \          .count()) *\n      10150724397891781847ULL;\n  _x ^= _x << 7;\n  return\
    \ _x ^= _x >> 9;\n}\n\n// [l, r]\ni64 rng(i64 l, i64 r) {\n  assert(l <= r);\n\
    \  return l + rng() % (r - l + 1);\n}\n\n// [l, r)\ni64 randint(i64 l, i64 r)\
    \ {\n  assert(l < r);\n  return l + rng() % (r - l);\n}\n\n// choose n numbers\
    \ from [l, r) without overlapping\nvector<i64> randset(i64 l, i64 r, i64 n) {\n\
    \  assert(l <= r && n <= r - l);\n  unordered_set<i64> s;\n  for (i64 i = n; i;\
    \ --i) {\n    i64 m = randint(l, r + 1 - i);\n    if (s.find(m) != s.end()) m\
    \ = r - i;\n    s.insert(m);\n  }\n  vector<i64> ret;\n  for (auto& x : s) ret.push_back(x);\n\
    \  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() { return rng() * 5.42101086242752217004e-20;\
    \ }\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n\
    \  for (int i = 1; i < n; i++) swap(v[i], v[randint(0, i + 1)]);\n}\n\n}  // namespace\
    \ my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\nusing my_rand::randshf;\n\
    using my_rand::rnd;\nusing my_rand::rng;\n#line 2 \"misc/timer.hpp\"\n\n#line\
    \ 4 \"misc/timer.hpp\"\n\nstruct Timer {\n  chrono::high_resolution_clock::time_point\
    \ st;\n\n  Timer() { reset(); }\n\n  void reset() { st = chrono::high_resolution_clock::now();\
    \ }\n\n  chrono::milliseconds::rep elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n\
    \    return chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n\
    };\n#line 6 \"verify/verify-unit-test/rbst-segment-tree.test.cpp\"\n//\n#line\
    \ 2 \"segment-tree/lazy-segment-tree.hpp\"\n\n// LazySegmentTree\ntemplate <typename\
    \ T, typename E, typename F, typename G, typename H>\nstruct LazySegmentTree {\n\
    \  int n, height;\n  F f;\n  G g;\n  H h;\n  T ti;\n  E ei;\n  vector<T> dat;\n\
    \  vector<E> laz;\n  LazySegmentTree(int _n, F _f, G _g, H _h, T _ti, E _ei)\n\
    \      : f(_f), g(_g), h(_h), ti(_ti), ei(_ei) {\n    init(_n);\n  }\n  LazySegmentTree(const\
    \ vector<T> &v, F _f, G _g, H _h, T _ti, E _ei)\n      : f(_f), g(_g), h(_h),\
    \ ti(_ti), ei(_ei) {\n    init((int)v.size());\n    build(v);\n  }\n  void init(int\
    \ _n) {\n    n = 1;\n    height = 0;\n    while (n < _n) n <<= 1, height++;\n\
    \    dat.assign(2 * n, ti);\n    laz.assign(2 * n, ei);\n  }\n  void build(const\
    \ vector<T> &v) {\n    int _n = v.size();\n    init(_n);\n    for (int i = 0;\
    \ i < _n; i++) dat[n + i] = v[i];\n    for (int i = n - 1; i; i--)\n      dat[i]\
    \ = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);\n  }\n  inline T reflect(int k) {\
    \ return laz[k] == ei ? dat[k] : g(dat[k], laz[k]); }\n  inline void eval(int\
    \ k) {\n    if (laz[k] == ei) return;\n    laz[(k << 1) | 0] = h(laz[(k << 1)\
    \ | 0], laz[k]);\n    laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);\n    dat[k]\
    \ = reflect(k);\n    laz[k] = ei;\n  }\n  inline void thrust(int k) {\n    for\
    \ (int i = height; i; i--) eval(k >> i);\n  }\n  inline void recalc(int k) {\n\
    \    while (k >>= 1) dat[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));\n\
    \  }\n  void update(int a, int b, E x) {\n    if (a >= b) return;\n    thrust(a\
    \ += n);\n    thrust(b += n - 1);\n    for (int l = a, r = b + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n      if (l & 1) laz[l] = h(laz[l], x), l++;\n      if (r & 1)\
    \ --r, laz[r] = h(laz[r], x);\n    }\n    recalc(a);\n    recalc(b);\n  }\n  void\
    \ set_val(int a, T x) {\n    thrust(a += n);\n    dat[a] = x;\n    laz[a] = ei;\n\
    \    recalc(a);\n  }\n  T get_val(int a) {\n    thrust(a += n);\n    return reflect(a);\n\
    \  }\n  T query(int a, int b) {\n    if (a >= b) return ti;\n    thrust(a += n);\n\
    \    thrust(b += n - 1);\n    T vl = ti, vr = ti;\n    for (int l = a, r = b +\
    \ 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) vl = f(vl, reflect(l++));\n\
    \      if (r & 1) vr = f(reflect(--r), vr);\n    }\n    return f(vl, vr);\n  }\n\
    };\n#line 8 \"verify/verify-unit-test/rbst-segment-tree.test.cpp\"\n//\n#line\
    \ 2 \"math/affine-transformation.hpp\"\n\ntemplate <typename mint>\nstruct Affine\
    \ {\n  mint a, b;\n  constexpr Affine() : a(1), b(0) {}\n  constexpr Affine(mint\
    \ _a, mint _b) : a(_a), b(_b) {}\n  mint operator()(mint x) { return a * x + b;\
    \ }\n  friend Affine operator*(const Affine& l, const Affine& r) {\n    return\
    \ Affine(l.a * r.a, l.b * r.a + r.b);\n  }\n  bool operator==(const Affine& r)\
    \ const { return a == r.a && b == r.b; }\n  bool operator!=(const Affine& r) const\
    \ { return a != r.a || b != r.b; }\n  friend ostream& operator<<(ostream& os,\
    \ const Affine& r) {\n    os << \"( \" << r.a << \", \" << r.b << \" )\";\n  \
    \  return os;\n  }\n};\n\n/**\n * @brief \u30A2\u30D5\u30A3\u30F3\u5909\u63DB\n\
    \ */\n#line 2 \"modint/montgomery-modint.hpp\"\n\n\n\ntemplate <uint32_t mod>\n\
    struct LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n  using i32\
    \ = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr\
    \ u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i < 4; ++i) ret *= 2\
    \ - mod * ret;\n    return ret;\n  }\n\n  static constexpr u32 r = get_r();\n\
    \  static constexpr u32 n2 = -u64(mod) % mod;\n  static_assert(r * mod == 1, \"\
    invalid, r * mod != 1\");\n  static_assert(mod < (1 << 30), \"invalid, mod >=\
    \ 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"invalid, mod % 2 == 0\");\n\n\
    \  u32 a;\n\n  constexpr LazyMontgomeryModInt() : a(0) {}\n  constexpr LazyMontgomeryModInt(const\
    \ int64_t &b)\n      : a(reduce(u64(b % mod + mod) * n2)){};\n\n  static constexpr\
    \ u32 reduce(const u64 &b) {\n    return (b + u64(u32(b) * u32(-r)) * mod) >>\
    \ 32;\n  }\n\n  constexpr mint &operator+=(const mint &b) {\n    if (i32(a +=\
    \ b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  constexpr mint\
    \ &operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2 * mod;\n   \
    \ return *this;\n  }\n\n  constexpr mint &operator*=(const mint &b) {\n    a =\
    \ reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  constexpr mint &operator/=(const\
    \ mint &b) {\n    *this *= b.inverse();\n    return *this;\n  }\n\n  constexpr\
    \ mint operator+(const mint &b) const { return mint(*this) += b; }\n  constexpr\
    \ mint operator-(const mint &b) const { return mint(*this) -= b; }\n  constexpr\
    \ mint operator*(const mint &b) const { return mint(*this) *= b; }\n  constexpr\
    \ mint operator/(const mint &b) const { return mint(*this) /= b; }\n  constexpr\
    \ bool operator==(const mint &b) const {\n    return (a >= mod ? a - mod : a)\
    \ == (b.a >= mod ? b.a - mod : b.a);\n  }\n  constexpr bool operator!=(const mint\
    \ &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod\
    \ : b.a);\n  }\n  constexpr mint operator-() const { return mint() - mint(*this);\
    \ }\n\n  constexpr mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n   \
    \ while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>=\
    \ 1;\n    }\n    return ret;\n  }\n  \n  constexpr mint inverse() const { return\
    \ pow(mod - 2); }\n\n  friend ostream &operator<<(ostream &os, const mint &b)\
    \ {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is,\
    \ mint &b) {\n    int64_t t;\n    is >> t;\n    b = LazyMontgomeryModInt<mod>(t);\n\
    \    return (is);\n  }\n  \n  constexpr u32 get() const {\n    u32 ret = reduce(a);\n\
    \    return ret >= mod ? ret - mod : ret;\n  }\n\n  static constexpr u32 get_mod()\
    \ { return mod; }\n};\n#line 11 \"verify/verify-unit-test/rbst-segment-tree.test.cpp\"\
    \n\nusing mint = LazyMontgomeryModInt<998244353>;\nusing T = pair<mint, mint>;\n\
    using E = Affine<mint>;\nT f(T a, T b) { return T(a.first + b.first, a.second\
    \ + b.second); }\nT g(T a, E b) { return T(a.first * b.a + a.second * b.b, a.second);\
    \ }\nE h(E a, E b) { return a * b; };\nT ti() { return T{}; }\nE ei() { return\
    \ E{}; }\n\nusing namespace Nyaan;\n\n// \u3059\u3079\u3066\u306E\u95A2\u6570\u306E\
    \u30C6\u30B9\u30C8\u3002\u305F\u3060\u3057\u30BB\u30B0\u6728\u306B\u3076\u305F\
    \u3093\u7CFB\u306F\u5225\u9014 verify \u3059\u308B\nvoid test(const int N = 100,\
    \ const int Q = 100) {\n  RBSTLazySegmentTree<int, T, E, f, g, h, ti, ei> seg1;\n\
    \  LazySegmentTree seg2(N, f, g, h, ti(), ei());\n\n  ll MOD = 998244353;\n  vector<function<void(void)>>\
    \ funcs{\n      [&]() {\n        // set_val\n        int i = rng(0, N - 1);\n\
    \        T x{rng(0, MOD - 1), 1};\n        seg1.set_val(i, x);\n        seg2.set_val(i,\
    \ x);\n      },\n      [&]() {\n        // set_val_fast\n        int i = rng(0,\
    \ N - 1);\n        T x{rng(0, MOD - 1), 1};\n        seg1.set_val_fast(i, x);\n\
    \        seg2.set_val(i, x);\n      },\n      [&]() {\n        // get_val\n  \
    \      int i = rng(0, N - 1);\n        T v1 = seg1.get_val(i);\n        T v2 =\
    \ seg2.get_val(i);\n        assert(v1 == v2 and \"get_val\");\n      },\n    \
    \  [&]() {\n        // apply_val\n        int i = rng(0, N - 1);\n        E x{rng(0,\
    \ MOD - 1), rng(0, MOD - 1)};\n        seg1.apply_val(i, [&](T& t) { t = g(t,\
    \ x); });\n        seg2.update(i, i + 1, x);\n      },\n      [&]() {\n      \
    \  // apply_val_fast\n        int i = rng(0, N - 1);\n        E x{rng(0, MOD -\
    \ 1), rng(0, MOD - 1)};\n        seg1.apply_val_fast(i, [&](T& t) { t = g(t, x);\
    \ });\n        seg2.update(i, i + 1, x);\n      },\n      [&]() {\n        //\
    \ erase\n        int i = rng(0, N - 1);\n        seg1.erase(i);\n        seg2.set_val(i,\
    \ T{});\n      },\n      [&]() {\n        // apply\n        int l = rng(0, N -\
    \ 1);\n        int r = rng(0, N - 1);\n        if (l > r) swap(l, r);\n      \
    \  r++;\n        E x{rng(0, MOD - 1), rng(0, MOD - 1)};\n        seg1.apply(l,\
    \ r, x);\n        seg2.update(l, r, x);\n      },\n      [&]() {\n        // fold\n\
    \        int l = rng(0, N - 1);\n        int r = rng(0, N - 1);\n        if (l\
    \ > r) swap(l, r);\n        r++;\n        auto v1 = seg1.fold(l, r);\n       \
    \ auto v2 = seg2.query(l, r);\n        assert(v1 == v2 and \"fold\");\n      },\n\
    \      [&]() {\n        // get_min_key, get_min_keyval\n        int v1 = -1;\n\
    \        while (true) {\n          v1 = seg1.get_min_key();\n          if (v1\
    \ == -1) break;\n          T val = seg2.get_val(v1);\n          if (val.second\
    \ == 1) break;\n          if (val.second == 0) {\n            seg1.erase(v1);\n\
    \            seg2.set_val(v1, T{});\n          } else {\n            assert(false\
    \ and \"get_min_key\");\n          }\n        }\n\n        int v2 = -1;\n    \
    \    if (seg2.query(0, N).second != 0) {\n          // [0, n) \u306F\u975E\u30BC\
    \u30ED\u3067\u3059\u304B\uFF1F\n          int ng = 0, ok = N;\n          while\
    \ (ng + 1 < ok) {\n            int m = (ng + ok) / 2;\n            mint x = seg2.query(0,\
    \ m).second;\n            (x == 0 ? ng : ok) = m;\n          }\n          v2 =\
    \ ok - 1;\n        }\n        assert(v1 == v2 && \"get_min_key\");\n\n       \
    \ if (v1 == -1) {\n          auto kv1 = seg1.get_min_keyval();\n          assert(kv1.second\
    \ == T{} && \"get_min_keyval\");\n        } else {\n          auto kv1 = seg1.get_min_keyval();\n\
    \          auto kv2 = make_pair(v2, seg2.get_val(v2));\n          assert(kv1 ==\
    \ kv2 && \"get_min_keyval\");\n        }\n      },\n      [&]() {\n        //\
    \ get_max_key, get_max_keyval\n        int v1 = -1;\n        while (true) {\n\
    \          v1 = seg1.get_max_key();\n          if (v1 == -1) break;\n        \
    \  T val = seg2.get_val(v1);\n          if (val.second == 1) break;\n        \
    \  if (val.second == 0) {\n            seg1.erase(v1);\n            seg2.set_val(v1,\
    \ T{});\n          } else {\n            assert(false and \"get_max_key\");\n\
    \          }\n        }\n\n        int v2 = -1;\n        if (seg2.query(0, N).second\
    \ != 0) {\n          // [i, N) \u306F\u975E\u30BC\u30ED\u3067\u3059\u304B\uFF1F\
    \n          int ok = 0, ng = N;\n          while (ok + 1 < ng) {\n           \
    \ int m = (ng + ok) / 2;\n            mint x = seg2.query(m, N).second;\n    \
    \        (x == 0 ? ng : ok) = m;\n          }\n          v2 = ok;\n        }\n\
    \        assert(v1 == v2 && \"get_max_key\");\n\n        if (v1 == -1) {\n   \
    \       auto kv1 = seg1.get_max_keyval();\n          assert(kv1.second == T{}\
    \ && \"get_max_keyval\");\n        } else {\n          auto kv1 = seg1.get_max_keyval();\n\
    \          auto kv2 = make_pair(v2, seg2.get_val(v2));\n          assert(kv1 ==\
    \ kv2 && \"get_mix_keyval\");\n        }\n      },\n      [&]() {\n        //\
    \ pop_min_key\n        int v2 = -1;\n        if (seg2.query(0, N).second != 0)\
    \ {\n          // [0, n) \u306F\u975E\u30BC\u30ED\u3067\u3059\u304B\uFF1F\n  \
    \        int ng = 0, ok = N;\n          while (ng + 1 < ok) {\n            int\
    \ m = (ng + ok) / 2;\n            mint x = seg2.query(0, m).second;\n        \
    \    (x == 0 ? ng : ok) = m;\n          }\n          v2 = ok - 1;\n        }\n\
    \        if (v2 != -1) {\n          pair<int, T> kv1;\n          do {\n      \
    \      kv1 = seg1.pop_min_keyval();\n          } while (kv1.second.second == 0);\n\
    \          auto kv2 = make_pair(v2, seg2.get_val(v2));\n          assert(kv1 ==\
    \ kv2 && \"pop_min_keyval\");\n          seg2.set_val(v2, T{});\n        }\n \
    \     },\n      [&]() {\n        // pop_max_key\n        int v2 = -1;\n      \
    \  if (seg2.query(0, N).second != 0) {\n          // [i, N) \u306F\u975E\u30BC\
    \u30ED\u3067\u3059\u304B\uFF1F\n          int ok = 0, ng = N;\n          while\
    \ (ok + 1 < ng) {\n            int m = (ng + ok) / 2;\n            mint x = seg2.query(m,\
    \ N).second;\n            (x == 0 ? ng : ok) = m;\n          }\n          v2 =\
    \ ok;\n        }\n        if (v2 != -1) {\n          pair<int, T> kv1;\n     \
    \     do {\n            kv1 = seg1.pop_max_keyval();\n          } while (kv1.second.second\
    \ == 0);\n          auto kv2 = make_pair(v2, seg2.get_val(v2));\n          assert(kv1\
    \ == kv2 && \"pop_max_keyval\");\n          seg2.set_val(v2, T{});\n        }\n\
    \      },\n  };\n\n  rep(_, 10) {\n    int qq = vector<ll>{0LL, rng(1, 10), rng(1,\
    \ Q)}[rng(0, 2)];\n    rep(qnum, qq) {\n      int c = rng(0, sz(funcs) - 1);\n\
    \      // trc(c, \"cmd\");\n      funcs[c]();\n    }\n    {\n      // make_array\n\
    \      auto vec1 = seg1.make_array();\n      vector<pair<int, T>> vec2;\n    \
    \  rep(i, N) {\n        T val = seg2.get_val(i);\n        if (val != T{}) vec2.push_back({i,\
    \ val});\n      }\n      // trc(vec1);\n      // trc(vec2);\n      int i1 = 0,\
    \ i2 = 0;\n      while (i1 != sz(vec1) and i2 != sz(vec2)) {\n        while (i1\
    \ != sz(vec1) and vec1[i1].second == T{}) i1++;\n        if (i1 == sz(vec1)) break;\n\
    \        assert(vec1[i1] == vec2[i2] and \"make_array\");\n        i1++, i2++;\n\
    \      }\n      while (i1 != sz(vec1) and vec1[i1].second == T{}) i1++;\n    \
    \  assert(i1 == sz(vec1) and i2 == sz(vec2) and \"make_array\");\n      // trc(\"\
    make_array ok\");\n    }\n    seg1.clear();\n    rep(i, N) seg2.set_val(i, T{});\n\
    \  }\n}\n\nvoid test_tl(const int N = 5 * TEN(5), const int Q = 5 * TEN(5)) {\n\
    \  ll MOD = 998244353;\n  V<T> init;\n  rep(i, N) init.emplace_back(rng(0, MOD\
    \ - 1), rng(0, MOD - 1));\n\n  RBSTLazySegmentTree<int, T, E, f, g, h, ti, ei>\
    \ seg1(init);\n  LazySegmentTree seg2(init, f, g, h, ti(), ei());\n\n  vector<function<void(void)>>\
    \ funcs{\n      [&]() {\n        // apply\n        int l = +rng(0, 10);\n    \
    \    int r = -rng(0, 10) + N;\n        E x{rng(0, MOD - 1), rng(0, MOD - 1)};\n\
    \        seg1.apply(l, r, x);\n        seg2.update(l, r, x);\n      },\n     \
    \ [&]() {\n        // fold\n        int l = +rng(0, 10);\n        int r = -rng(0,\
    \ 10) + N;\n        auto v1 = seg1.fold(l, r);\n        auto v2 = seg2.query(l,\
    \ r);\n        assert(v1 == v2 and \"fold\");\n      },\n  };\n\n  rep(qnum, Q)\
    \ {\n    int c = rng(0, sz(funcs) - 1);\n    // trc(c, \"cmd\");\n    funcs[c]();\n\
    \  }\n}\n\nvoid q() {\n  rep(t, 10) test(10, TEN(4));\n  //\n  rep(t, 10) test(100,\
    \ TEN(4));\n  //\n  rep(t, 2) test(TEN(4), TEN(2));\n  //\n  test(10, TEN(4));\n\
    \  test(2, TEN(4));\n  test(1, TEN(4));\n  cerr << \"test OK\" << endl;\n\n  Timer\
    \ timer;\n  test_tl();\n  cerr << \"test_tl OK\" << endl;\n  cerr << \"time :\
    \ \" << timer.elapsed() << endl;\n}\n\nvoid Nyaan::solve() { q(); }\n"
  code: "#include \"../../template/template.hpp\"\n//\n#include \"../../segment-tree/rbst-segment-tree.hpp\"\
    \n//\n#include \"../../misc/all.hpp\"\n//\n#include \"../../segment-tree/lazy-segment-tree.hpp\"\
    \n//\n#include \"../../math/affine-transformation.hpp\"\n#include \"../../modint/montgomery-modint.hpp\"\
    \n\nusing mint = LazyMontgomeryModInt<998244353>;\nusing T = pair<mint, mint>;\n\
    using E = Affine<mint>;\nT f(T a, T b) { return T(a.first + b.first, a.second\
    \ + b.second); }\nT g(T a, E b) { return T(a.first * b.a + a.second * b.b, a.second);\
    \ }\nE h(E a, E b) { return a * b; };\nT ti() { return T{}; }\nE ei() { return\
    \ E{}; }\n\nusing namespace Nyaan;\n\n// \u3059\u3079\u3066\u306E\u95A2\u6570\u306E\
    \u30C6\u30B9\u30C8\u3002\u305F\u3060\u3057\u30BB\u30B0\u6728\u306B\u3076\u305F\
    \u3093\u7CFB\u306F\u5225\u9014 verify \u3059\u308B\nvoid test(const int N = 100,\
    \ const int Q = 100) {\n  RBSTLazySegmentTree<int, T, E, f, g, h, ti, ei> seg1;\n\
    \  LazySegmentTree seg2(N, f, g, h, ti(), ei());\n\n  ll MOD = 998244353;\n  vector<function<void(void)>>\
    \ funcs{\n      [&]() {\n        // set_val\n        int i = rng(0, N - 1);\n\
    \        T x{rng(0, MOD - 1), 1};\n        seg1.set_val(i, x);\n        seg2.set_val(i,\
    \ x);\n      },\n      [&]() {\n        // set_val_fast\n        int i = rng(0,\
    \ N - 1);\n        T x{rng(0, MOD - 1), 1};\n        seg1.set_val_fast(i, x);\n\
    \        seg2.set_val(i, x);\n      },\n      [&]() {\n        // get_val\n  \
    \      int i = rng(0, N - 1);\n        T v1 = seg1.get_val(i);\n        T v2 =\
    \ seg2.get_val(i);\n        assert(v1 == v2 and \"get_val\");\n      },\n    \
    \  [&]() {\n        // apply_val\n        int i = rng(0, N - 1);\n        E x{rng(0,\
    \ MOD - 1), rng(0, MOD - 1)};\n        seg1.apply_val(i, [&](T& t) { t = g(t,\
    \ x); });\n        seg2.update(i, i + 1, x);\n      },\n      [&]() {\n      \
    \  // apply_val_fast\n        int i = rng(0, N - 1);\n        E x{rng(0, MOD -\
    \ 1), rng(0, MOD - 1)};\n        seg1.apply_val_fast(i, [&](T& t) { t = g(t, x);\
    \ });\n        seg2.update(i, i + 1, x);\n      },\n      [&]() {\n        //\
    \ erase\n        int i = rng(0, N - 1);\n        seg1.erase(i);\n        seg2.set_val(i,\
    \ T{});\n      },\n      [&]() {\n        // apply\n        int l = rng(0, N -\
    \ 1);\n        int r = rng(0, N - 1);\n        if (l > r) swap(l, r);\n      \
    \  r++;\n        E x{rng(0, MOD - 1), rng(0, MOD - 1)};\n        seg1.apply(l,\
    \ r, x);\n        seg2.update(l, r, x);\n      },\n      [&]() {\n        // fold\n\
    \        int l = rng(0, N - 1);\n        int r = rng(0, N - 1);\n        if (l\
    \ > r) swap(l, r);\n        r++;\n        auto v1 = seg1.fold(l, r);\n       \
    \ auto v2 = seg2.query(l, r);\n        assert(v1 == v2 and \"fold\");\n      },\n\
    \      [&]() {\n        // get_min_key, get_min_keyval\n        int v1 = -1;\n\
    \        while (true) {\n          v1 = seg1.get_min_key();\n          if (v1\
    \ == -1) break;\n          T val = seg2.get_val(v1);\n          if (val.second\
    \ == 1) break;\n          if (val.second == 0) {\n            seg1.erase(v1);\n\
    \            seg2.set_val(v1, T{});\n          } else {\n            assert(false\
    \ and \"get_min_key\");\n          }\n        }\n\n        int v2 = -1;\n    \
    \    if (seg2.query(0, N).second != 0) {\n          // [0, n) \u306F\u975E\u30BC\
    \u30ED\u3067\u3059\u304B\uFF1F\n          int ng = 0, ok = N;\n          while\
    \ (ng + 1 < ok) {\n            int m = (ng + ok) / 2;\n            mint x = seg2.query(0,\
    \ m).second;\n            (x == 0 ? ng : ok) = m;\n          }\n          v2 =\
    \ ok - 1;\n        }\n        assert(v1 == v2 && \"get_min_key\");\n\n       \
    \ if (v1 == -1) {\n          auto kv1 = seg1.get_min_keyval();\n          assert(kv1.second\
    \ == T{} && \"get_min_keyval\");\n        } else {\n          auto kv1 = seg1.get_min_keyval();\n\
    \          auto kv2 = make_pair(v2, seg2.get_val(v2));\n          assert(kv1 ==\
    \ kv2 && \"get_min_keyval\");\n        }\n      },\n      [&]() {\n        //\
    \ get_max_key, get_max_keyval\n        int v1 = -1;\n        while (true) {\n\
    \          v1 = seg1.get_max_key();\n          if (v1 == -1) break;\n        \
    \  T val = seg2.get_val(v1);\n          if (val.second == 1) break;\n        \
    \  if (val.second == 0) {\n            seg1.erase(v1);\n            seg2.set_val(v1,\
    \ T{});\n          } else {\n            assert(false and \"get_max_key\");\n\
    \          }\n        }\n\n        int v2 = -1;\n        if (seg2.query(0, N).second\
    \ != 0) {\n          // [i, N) \u306F\u975E\u30BC\u30ED\u3067\u3059\u304B\uFF1F\
    \n          int ok = 0, ng = N;\n          while (ok + 1 < ng) {\n           \
    \ int m = (ng + ok) / 2;\n            mint x = seg2.query(m, N).second;\n    \
    \        (x == 0 ? ng : ok) = m;\n          }\n          v2 = ok;\n        }\n\
    \        assert(v1 == v2 && \"get_max_key\");\n\n        if (v1 == -1) {\n   \
    \       auto kv1 = seg1.get_max_keyval();\n          assert(kv1.second == T{}\
    \ && \"get_max_keyval\");\n        } else {\n          auto kv1 = seg1.get_max_keyval();\n\
    \          auto kv2 = make_pair(v2, seg2.get_val(v2));\n          assert(kv1 ==\
    \ kv2 && \"get_mix_keyval\");\n        }\n      },\n      [&]() {\n        //\
    \ pop_min_key\n        int v2 = -1;\n        if (seg2.query(0, N).second != 0)\
    \ {\n          // [0, n) \u306F\u975E\u30BC\u30ED\u3067\u3059\u304B\uFF1F\n  \
    \        int ng = 0, ok = N;\n          while (ng + 1 < ok) {\n            int\
    \ m = (ng + ok) / 2;\n            mint x = seg2.query(0, m).second;\n        \
    \    (x == 0 ? ng : ok) = m;\n          }\n          v2 = ok - 1;\n        }\n\
    \        if (v2 != -1) {\n          pair<int, T> kv1;\n          do {\n      \
    \      kv1 = seg1.pop_min_keyval();\n          } while (kv1.second.second == 0);\n\
    \          auto kv2 = make_pair(v2, seg2.get_val(v2));\n          assert(kv1 ==\
    \ kv2 && \"pop_min_keyval\");\n          seg2.set_val(v2, T{});\n        }\n \
    \     },\n      [&]() {\n        // pop_max_key\n        int v2 = -1;\n      \
    \  if (seg2.query(0, N).second != 0) {\n          // [i, N) \u306F\u975E\u30BC\
    \u30ED\u3067\u3059\u304B\uFF1F\n          int ok = 0, ng = N;\n          while\
    \ (ok + 1 < ng) {\n            int m = (ng + ok) / 2;\n            mint x = seg2.query(m,\
    \ N).second;\n            (x == 0 ? ng : ok) = m;\n          }\n          v2 =\
    \ ok;\n        }\n        if (v2 != -1) {\n          pair<int, T> kv1;\n     \
    \     do {\n            kv1 = seg1.pop_max_keyval();\n          } while (kv1.second.second\
    \ == 0);\n          auto kv2 = make_pair(v2, seg2.get_val(v2));\n          assert(kv1\
    \ == kv2 && \"pop_max_keyval\");\n          seg2.set_val(v2, T{});\n        }\n\
    \      },\n  };\n\n  rep(_, 10) {\n    int qq = vector<ll>{0LL, rng(1, 10), rng(1,\
    \ Q)}[rng(0, 2)];\n    rep(qnum, qq) {\n      int c = rng(0, sz(funcs) - 1);\n\
    \      // trc(c, \"cmd\");\n      funcs[c]();\n    }\n    {\n      // make_array\n\
    \      auto vec1 = seg1.make_array();\n      vector<pair<int, T>> vec2;\n    \
    \  rep(i, N) {\n        T val = seg2.get_val(i);\n        if (val != T{}) vec2.push_back({i,\
    \ val});\n      }\n      // trc(vec1);\n      // trc(vec2);\n      int i1 = 0,\
    \ i2 = 0;\n      while (i1 != sz(vec1) and i2 != sz(vec2)) {\n        while (i1\
    \ != sz(vec1) and vec1[i1].second == T{}) i1++;\n        if (i1 == sz(vec1)) break;\n\
    \        assert(vec1[i1] == vec2[i2] and \"make_array\");\n        i1++, i2++;\n\
    \      }\n      while (i1 != sz(vec1) and vec1[i1].second == T{}) i1++;\n    \
    \  assert(i1 == sz(vec1) and i2 == sz(vec2) and \"make_array\");\n      // trc(\"\
    make_array ok\");\n    }\n    seg1.clear();\n    rep(i, N) seg2.set_val(i, T{});\n\
    \  }\n}\n\nvoid test_tl(const int N = 5 * TEN(5), const int Q = 5 * TEN(5)) {\n\
    \  ll MOD = 998244353;\n  V<T> init;\n  rep(i, N) init.emplace_back(rng(0, MOD\
    \ - 1), rng(0, MOD - 1));\n\n  RBSTLazySegmentTree<int, T, E, f, g, h, ti, ei>\
    \ seg1(init);\n  LazySegmentTree seg2(init, f, g, h, ti(), ei());\n\n  vector<function<void(void)>>\
    \ funcs{\n      [&]() {\n        // apply\n        int l = +rng(0, 10);\n    \
    \    int r = -rng(0, 10) + N;\n        E x{rng(0, MOD - 1), rng(0, MOD - 1)};\n\
    \        seg1.apply(l, r, x);\n        seg2.update(l, r, x);\n      },\n     \
    \ [&]() {\n        // fold\n        int l = +rng(0, 10);\n        int r = -rng(0,\
    \ 10) + N;\n        auto v1 = seg1.fold(l, r);\n        auto v2 = seg2.query(l,\
    \ r);\n        assert(v1 == v2 and \"fold\");\n      },\n  };\n\n  rep(qnum, Q)\
    \ {\n    int c = rng(0, sz(funcs) - 1);\n    // trc(c, \"cmd\");\n    funcs[c]();\n\
    \  }\n}\n\nvoid q() {\n  rep(t, 10) test(10, TEN(4));\n  //\n  rep(t, 10) test(100,\
    \ TEN(4));\n  //\n  rep(t, 2) test(TEN(4), TEN(2));\n  //\n  test(10, TEN(4));\n\
    \  test(2, TEN(4));\n  test(1, TEN(4));\n  cerr << \"test OK\" << endl;\n\n  Timer\
    \ timer;\n  test_tl();\n  cerr << \"test_tl OK\" << endl;\n  cerr << \"time :\
    \ \" << timer.elapsed() << endl;\n}\n\nvoid Nyaan::solve() { q(); }"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - segment-tree/rbst-segment-tree.hpp
  - misc/all.hpp
  - misc/fastio.hpp
  - misc/rng.hpp
  - misc/timer.hpp
  - segment-tree/lazy-segment-tree.hpp
  - math/affine-transformation.hpp
  - modint/montgomery-modint.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/rbst-segment-tree.test.cpp
  requiredBy: []
  timestamp: '2022-11-01 22:31:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/verify-unit-test/rbst-segment-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/rbst-segment-tree.test.cpp
- /verify/verify/verify-unit-test/rbst-segment-tree.test.cpp.html
title: verify/verify-unit-test/rbst-segment-tree.test.cpp
---
