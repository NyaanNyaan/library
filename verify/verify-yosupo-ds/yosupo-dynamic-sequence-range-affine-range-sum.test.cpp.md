---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/affine-transformation.hpp
    title: "\u30A2\u30D5\u30A3\u30F3\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: rbst/lazy-reversible-rbst.hpp
    title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u4E71\u629E\u5E73\u8861\
      \u4E8C\u5206\u6728"
  - icon: ':heavy_check_mark:'
    path: rbst/rbst-base.hpp
    title: "\u4E71\u629E\u5E73\u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9\
      )"
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n\
    #include <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <csetjmp>\n#include <csignal>\n#include <cstdarg>\n#include\
    \ <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <ctime>\n#include <deque>\n#include <exception>\n#include\
    \ <forward_list>\n#include <fstream>\n#include <functional>\n#include <initializer_list>\n\
    #include <iomanip>\n#include <ios>\n#include <iosfwd>\n#include <iostream>\n#include\
    \ <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n#include\
    \ <locale>\n#include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n\
    #include <ostream>\n#include <queue>\n#include <random>\n#include <ratio>\n#include\
    \ <regex>\n#include <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n\
    #include <streambuf>\n#include <string>\n#include <system_error>\n#include <tuple>\n\
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
    \ 5 \"verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp\"\
    \n//\n#line 2 \"rbst/lazy-reversible-rbst.hpp\"\n\n#line 2 \"rbst/rbst-base.hpp\"\
    \n\ntemplate <typename Node>\nstruct RBSTBase {\n  using Ptr = Node *;\n  template\
    \ <typename... Args>\n  inline Ptr my_new(Args... args) {\n    return new Node(args...);\n\
    \  }\n  inline void my_del(Ptr t) { delete t; }\n  inline Ptr make_tree() const\
    \ { return nullptr; }\n\n  // for avoiding memory leak, activate below\n  /*\n\
    \  using Ptr = shared_ptr<Node>;\n  template <typename... Args>\n  inline Ptr\
    \ my_new(Args... args) {\n    return make_shared<Node>(args...);\n  }\n  inline\
    \ void my_del(Ptr t) {}\n  Ptr make_tree() {return Ptr();}\n  */\n\n  int size(Ptr\
    \ t) const { return count(t); }\n\n  Ptr merge(Ptr l, Ptr r) {\n    if (!l ||\
    \ !r) return l ? l : r;\n    if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt)\
    \ {\n      push(l);\n      l->r = merge(l->r, r);\n      return update(l);\n \
    \   } else {\n      push(r);\n      r->l = merge(l, r->l);\n      return update(r);\n\
    \    }\n  }\n\n  pair<Ptr, Ptr> split(Ptr t, int k) {\n    if (!t) return {nullptr,\
    \ nullptr};\n    push(t);\n    if (k <= count(t->l)) {\n      auto s = split(t->l,\
    \ k);\n      t->l = s.second;\n      return {s.first, update(t)};\n    } else\
    \ {\n      auto s = split(t->r, k - count(t->l) - 1);\n      t->r = s.first;\n\
    \      return {update(t), s.second};\n    }\n  }\n\n  Ptr build(int l, int r,\
    \ const vector<decltype(Node::key)> &v) {\n    if (l + 1 == r) return my_new(v[l]);\n\
    \    int m = (l + r) >> 1;\n    Ptr pm = my_new(v[m]);\n    if (l < m) pm->l =\
    \ build(l, m, v);\n    if (m + 1 < r) pm->r = build(m + 1, r, v);\n    return\
    \ update(pm);\n  }\n\n  Ptr build(const vector<decltype(Node::key)> &v) {\n  \
    \  return build(0, (int)v.size(), v);\n  }\n\n  template <typename... Args>\n\
    \  void insert(Ptr &t, int k, const Args &... args) {\n    auto x = split(t, k);\n\
    \    t = merge(merge(x.first, my_new(args...)), x.second);\n  }\n\n  void erase(Ptr\
    \ &t, int k) {\n    auto x = split(t, k);\n    auto y = split(x.second, 1);\n\
    \    my_del(y.first);\n    t = merge(x.first, y.second);\n  }\n\n protected:\n\
    \  static uint64_t rng() {\n    static uint64_t x_ = 88172645463325252ULL;\n \
    \   return x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;\n  }\n\n  inline\
    \ int count(const Ptr t) const { return t ? t->cnt : 0; }\n\n  virtual void push(Ptr)\
    \ = 0;\n\n  virtual Ptr update(Ptr) = 0;\n};\n\n/**\n * @brief \u4E71\u629E\u5E73\
    \u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)\n */\n#line 4 \"rbst/lazy-reversible-rbst.hpp\"\
    \n\ntemplate <typename T, typename E>\nstruct LazyReversibleRBSTNode {\n  typename\
    \ RBSTBase<LazyReversibleRBSTNode>::Ptr l, r;\n  T key, sum;\n  E lazy;\n  int\
    \ cnt;\n  bool rev;\n\n  LazyReversibleRBSTNode(const T &t = T(), const E &e =\
    \ E())\n      : l(), r(), key(t), sum(t), lazy(e), cnt(1), rev(false) {}\n};\n\
    \ntemplate <typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),\n\
    \          T (*ts)(T)>\nstruct LazyReversibleRBST : RBSTBase<LazyReversibleRBSTNode<T,\
    \ E>> {\n  using Node = LazyReversibleRBSTNode<T, E>;\n  using base = RBSTBase<LazyReversibleRBSTNode<T,\
    \ E>>;\n  using base::merge;\n  using base::split;\n  using typename base::Ptr;\n\
    \n  LazyReversibleRBST() = default;\n\n  void toggle(Ptr t) {\n    swap(t->l,\
    \ t->r);\n    t->sum = ts(t->sum);\n    t->rev ^= true;\n  }\n\n  T fold(Ptr &t,\
    \ int a, int b) {\n    auto x = split(t, a);\n    auto y = split(x.second, b -\
    \ a);\n    auto ret = sum(y.first);\n    t = merge(x.first, merge(y.first, y.second));\n\
    \    return ret;\n  }\n\n  void reverse(Ptr &t, int a, int b) {\n    auto x =\
    \ split(t, a);\n    auto y = split(x.second, b - a);\n    toggle(y.first);\n \
    \   t = merge(x.first, merge(y.first, y.second));\n  }\n\n  void apply(Ptr &t,\
    \ int a, int b, const E &e) {\n    auto x = split(t, a);\n    auto y = split(x.second,\
    \ b - a);\n    propagate(y.first, e);\n    t = merge(x.first, merge(y.first, y.second));\n\
    \  }\n\n protected:\n  inline T sum(const Ptr t) const { return t ? t->sum : T();\
    \ }\n\n  Ptr update(Ptr t) override {\n    push(t);\n    t->cnt = 1;\n    t->sum\
    \ = t->key;\n    if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n\
    \    if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);\n    return\
    \ t;\n  }\n\n  void push(Ptr t) override {\n    if (t->rev) {\n      if (t->l)\
    \ toggle(t->l);\n      if (t->r) toggle(t->r);\n      t->rev = false;\n    }\n\
    \    if (t->lazy != E()) {\n      if (t->l) propagate(t->l, t->lazy);\n      if\
    \ (t->r) propagate(t->r, t->lazy);\n      t->lazy = E();\n    }\n  }\n\n  void\
    \ propagate(Ptr t, const E &x) {\n    t->lazy = h(t->lazy, x);\n    t->key = g(t->key,\
    \ x);\n    t->sum = g(t->sum, x);\n  }\n};\n\n/**\n * @brief \u9045\u5EF6\u4F1D\
    \u642C\u53CD\u8EE2\u53EF\u80FD\u4E71\u629E\u5E73\u8861\u4E8C\u5206\u6728\n * @docs\
    \ docs/rbst/lazy-reversible-rbst.md\n */\n#line 7 \"verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp\"\
    \n//\n#line 2 \"modint/montgomery-modint.hpp\"\n\n\n\ntemplate <uint32_t mod>\n\
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
    \ { return mod; }\n};\n#line 9 \"verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp\"\
    \nusing mint = LazyMontgomeryModInt<998244353>;\nusing vm = vector<mint>;\nusing\
    \ vvm = vector<vm>;\n#line 2 \"math/affine-transformation.hpp\"\n\ntemplate <typename\
    \ mint>\nstruct Affine {\n  mint a, b;\n  constexpr Affine() : a(1), b(0) {}\n\
    \  constexpr Affine(mint _a, mint _b) : a(_a), b(_b) {}\n  mint operator()(mint\
    \ x) { return a * x + b; }\n  friend Affine operator*(const Affine& l, const Affine&\
    \ r) {\n    return Affine(l.a * r.a, l.b * r.a + r.b);\n  }\n  bool operator==(const\
    \ Affine& r) const { return a == r.a && b == r.b; }\n  bool operator!=(const Affine&\
    \ r) const { return a != r.a || b != r.b; }\n  friend ostream& operator<<(ostream&\
    \ os, const Affine& r) {\n    os << \"( \" << r.a << \", \" << r.b << \" )\";\n\
    \    return os;\n  }\n};\n\n/**\n * @brief \u30A2\u30D5\u30A3\u30F3\u5909\u63DB\
    \n */\n#line 2 \"misc/fastio.hpp\"\n\n\n\nnamespace fastio {\nstatic constexpr\
    \ int SZ = 1 << 17;\nchar ibuf[SZ], obuf[SZ];\nint pil = 0, pir = 0, por = 0;\n\
    \nstruct Pre {\n  char num[40000];\n  constexpr Pre() : num() {\n    for (int\
    \ i = 0; i < 10000; i++) {\n      int n = i;\n      for (int j = 3; j >= 0; j--)\
    \ {\n        num[i * 4 + j] = n % 10 + '0';\n        n /= 10;\n      }\n    }\n\
    \  }\n} constexpr pre;\n\ninline void load() {\n  memcpy(ibuf, ibuf + pil, pir\
    \ - pil);\n  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);\n\
    \  pil = 0;\n}\ninline void flush() {\n  fwrite(obuf, 1, por, stdout);\n  por\
    \ = 0;\n}\n\ninline void rd(char& c) { c = ibuf[pil++]; }\ntemplate <typename\
    \ T>\ninline void rd(T& x) {\n  if (pil + 32 > pir) load();\n  char c;\n  do\n\
    \    c = ibuf[pil++];\n  while (c < '-');\n  bool minus = 0;\n  if (c == '-')\
    \ {\n    minus = 1;\n    c = ibuf[pil++];\n  }\n  x = 0;\n  while (c >= '0') {\n\
    \    x = x * 10 + (c & 15);\n    c = ibuf[pil++];\n  }\n  if (minus) x = -x;\n\
    }\ninline void rd() {}\ntemplate <typename Head, typename... Tail>\ninline void\
    \ rd(Head& head, Tail&... tail) {\n  rd(head);\n  rd(tail...);\n}\n\ninline void\
    \ wt(char c) { obuf[por++] = c; }\ntemplate <typename T>\ninline void wt(T x)\
    \ {\n  if (por > SZ - 32) flush();\n  if (!x) {\n    obuf[por++] = '0';\n    return;\n\
    \  }\n  if (x < 0) {\n    obuf[por++] = '-';\n    x = -x;\n  }\n  int i = 12;\n\
    \  char buf[16];\n  while (x >= 10000) {\n    memcpy(buf + i, pre.num + (x % 10000)\
    \ * 4, 4);\n    x /= 10000;\n    i -= 4;\n  }\n  if (x < 100) {\n    if (x < 10)\
    \ {\n      wt(char('0' + char(x)));\n    } else {\n      uint32_t q = (uint32_t(x)\
    \ * 205) >> 11;\n      uint32_t r = uint32_t(x) - q * 10;\n      obuf[por + 0]\
    \ = '0' + q;\n      obuf[por + 1] = '0' + r;\n      por += 2;\n    }\n  } else\
    \ {\n    if (x < 1000) {\n      memcpy(obuf + por, pre.num + (x << 2) + 1, 3);\n\
    \      por += 3;\n    } else {\n      memcpy(obuf + por, pre.num + (x << 2), 4);\n\
    \      por += 4;\n    }\n  }\n  memcpy(obuf + por, buf + i + 4, 12 - i);\n  por\
    \ += 12 - i;\n}\n\ninline void wt() {}\ntemplate <typename Head, typename... Tail>\n\
    inline void wt(Head head, Tail... tail) {\n  wt(head);\n  wt(tail...);\n}\ntemplate\
    \ <typename T>\ninline void wtn(T x) {\n  wt(x, '\\n');\n}\n\nstruct Dummy {\n\
    \  Dummy() { atexit(flush); }\n} dummy;\n\n}  // namespace fastio\nusing fastio::rd;\n\
    using fastio::wt;\nusing fastio::wtn;\n#line 14 \"verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp\"\
    \n\nusing T = pair<mint, mint>;\nusing E = Affine<mint>;\nT f(T a, T b) { return\
    \ T(a.first + b.first, a.second + b.second); }\nT g(T a, E b) { return T(b.a *\
    \ a.first + b.b * a.second, a.second); }\nE h(E a, E b) { return a * b; }\nT ts(T\
    \ a) { return a; }\n\nusing namespace Nyaan;\nvoid Nyaan::solve() {\n  int N,\
    \ Q;\n  rd(N, Q);\n\n  V<T> a(N);\n  each(i, a) {\n    int n;\n    rd(n);\n  \
    \  i = mkp(n, 1);\n  }\n\n  LazyReversibleRBST<T, E, f, g, h, ts> rbst;\n  auto\
    \ root = rbst.build(a);\n\n  while (Q--) {\n    int cmd;\n    rd(cmd);\n    if\
    \ (cmd == 0) {\n      int i, x;\n      rd(i, x);\n      rbst.insert(root, i, T(x,\
    \ 1));\n    } else if (cmd == 1) {\n      int i;\n      rd(i);\n      rbst.erase(root,\
    \ i);\n    } else if (cmd == 2) {\n      int l, r;\n      rd(l, r);\n      rbst.reverse(root,\
    \ l, r);\n    } else if (cmd == 3) {\n      int l, r, b, c;\n      rd(l, r, b,\
    \ c);\n      rbst.apply(root, l, r, E(b, c));\n    } else {\n      int l, r;\n\
    \      rd(l, r);\n      wtn(rbst.fold(root, l, r).first.get());\n    }\n  }\n\
    }\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include \"../../template/template.hpp\"\n//\n#include \"../../rbst/lazy-reversible-rbst.hpp\"\
    \n//\n#include \"../../modint/montgomery-modint.hpp\"\nusing mint = LazyMontgomeryModInt<998244353>;\n\
    using vm = vector<mint>;\nusing vvm = vector<vm>;\n#include \"../../math/affine-transformation.hpp\"\
    \n#include \"../../misc/fastio.hpp\"\n\nusing T = pair<mint, mint>;\nusing E =\
    \ Affine<mint>;\nT f(T a, T b) { return T(a.first + b.first, a.second + b.second);\
    \ }\nT g(T a, E b) { return T(b.a * a.first + b.b * a.second, a.second); }\nE\
    \ h(E a, E b) { return a * b; }\nT ts(T a) { return a; }\n\nusing namespace Nyaan;\n\
    void Nyaan::solve() {\n  int N, Q;\n  rd(N, Q);\n\n  V<T> a(N);\n  each(i, a)\
    \ {\n    int n;\n    rd(n);\n    i = mkp(n, 1);\n  }\n\n  LazyReversibleRBST<T,\
    \ E, f, g, h, ts> rbst;\n  auto root = rbst.build(a);\n\n  while (Q--) {\n   \
    \ int cmd;\n    rd(cmd);\n    if (cmd == 0) {\n      int i, x;\n      rd(i, x);\n\
    \      rbst.insert(root, i, T(x, 1));\n    } else if (cmd == 1) {\n      int i;\n\
    \      rd(i);\n      rbst.erase(root, i);\n    } else if (cmd == 2) {\n      int\
    \ l, r;\n      rd(l, r);\n      rbst.reverse(root, l, r);\n    } else if (cmd\
    \ == 3) {\n      int l, r, b, c;\n      rd(l, r, b, c);\n      rbst.apply(root,\
    \ l, r, E(b, c));\n    } else {\n      int l, r;\n      rd(l, r);\n      wtn(rbst.fold(root,\
    \ l, r).first.get());\n    }\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - rbst/lazy-reversible-rbst.hpp
  - rbst/rbst-base.hpp
  - modint/montgomery-modint.hpp
  - math/affine-transformation.hpp
  - misc/fastio.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
  requiredBy: []
  timestamp: '2020-12-17 01:20:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
---