---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: orderedmap/orderedmap-base.hpp
    title: "Ordered Set(base)\u3000(\u9806\u5E8F\u4ED8\u304D\u96C6\u5408\u30FB\u57FA\
      \u5E95\u30AF\u30E9\u30B9)"
  - icon: ':heavy_check_mark:'
    path: orderedmap/orderedmap.hpp
    title: "Ordered Map(\u9806\u5E8F\u4ED8\u304D\u9023\u60F3\u914D\u5217)"
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/orderedmap.test.cpp\"\n#define PROBLEM\
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
    \ 4 \"verify/verify-unit-test/orderedmap.test.cpp\"\n//\n#line 2 \"misc/rng.hpp\"\
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
    orderedmap/orderedmap.hpp\"\n\n#line 2 \"orderedmap/orderedmap-base.hpp\"\n\n\
    #line 2 \"rbst/rbst-base.hpp\"\n\ntemplate <typename Node>\nstruct RBSTBase {\n\
    \  using Ptr = Node *;\n  template <typename... Args>\n  inline Ptr my_new(Args...\
    \ args) {\n    return new Node(args...);\n  }\n  inline void my_del(Ptr t) { delete\
    \ t; }\n  inline Ptr make_tree() const { return nullptr; }\n\n  // for avoiding\
    \ memory leak, activate below\n  /*\n  using Ptr = shared_ptr<Node>;\n  template\
    \ <typename... Args>\n  inline Ptr my_new(Args... args) {\n    return make_shared<Node>(args...);\n\
    \  }\n  inline void my_del(Ptr t) {}\n  Ptr make_tree() {return Ptr();}\n  */\n\
    \n  int size(Ptr t) const { return count(t); }\n\n  Ptr merge(Ptr l, Ptr r) {\n\
    \    if (!l || !r) return l ? l : r;\n    if (int((rng() * (l->cnt + r->cnt))\
    \ >> 32) < l->cnt) {\n      push(l);\n      l->r = merge(l->r, r);\n      return\
    \ update(l);\n    } else {\n      push(r);\n      r->l = merge(l, r->l);\n   \
    \   return update(r);\n    }\n  }\n\n  pair<Ptr, Ptr> split(Ptr t, int k) {\n\
    \    if (!t) return {nullptr, nullptr};\n    push(t);\n    if (k <= count(t->l))\
    \ {\n      auto s = split(t->l, k);\n      t->l = s.second;\n      return {s.first,\
    \ update(t)};\n    } else {\n      auto s = split(t->r, k - count(t->l) - 1);\n\
    \      t->r = s.first;\n      return {update(t), s.second};\n    }\n  }\n\n  Ptr\
    \ build(int l, int r, const vector<decltype(Node::key)> &v) {\n    if (l + 1 ==\
    \ r) return my_new(v[l]);\n    int m = (l + r) >> 1;\n    Ptr pm = my_new(v[m]);\n\
    \    if (l < m) pm->l = build(l, m, v);\n    if (m + 1 < r) pm->r = build(m +\
    \ 1, r, v);\n    return update(pm);\n  }\n\n  Ptr build(const vector<decltype(Node::key)>\
    \ &v) {\n    return build(0, (int)v.size(), v);\n  }\n\n  template <typename...\
    \ Args>\n  void insert(Ptr &t, int k, const Args &... args) {\n    auto x = split(t,\
    \ k);\n    t = merge(merge(x.first, my_new(args...)), x.second);\n  }\n\n  void\
    \ erase(Ptr &t, int k) {\n    auto x = split(t, k);\n    auto y = split(x.second,\
    \ 1);\n    my_del(y.first);\n    t = merge(x.first, y.second);\n  }\n\n protected:\n\
    \  static uint64_t rng() {\n    static uint64_t x_ = 88172645463325252ULL;\n \
    \   return x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;\n  }\n\n  inline\
    \ int count(const Ptr t) const { return t ? t->cnt : 0; }\n\n  virtual void push(Ptr)\
    \ = 0;\n\n  virtual Ptr update(Ptr) = 0;\n};\n\n/**\n * @brief \u4E71\u629E\u5E73\
    \u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)\n */\n#line 4 \"orderedmap/orderedmap-base.hpp\"\
    \n\ntemplate <typename Node, bool multi>\nstruct OrderedMapBase : RBSTBase<Node>\
    \ {\n  using base = RBSTBase<Node>;\n  using Ptr = typename base::Ptr;\n  using\
    \ Key = decltype(Node::key);\n\n  Ptr root;\n  OrderedMapBase() : root(base::make_tree())\
    \ {}\n\n  Ptr find(const Key& k) const {\n    Ptr p = root;\n    while (p) {\n\
    \      if (k == p->key) return p;\n      p = k < p->key ? p->l : p->r;\n    }\n\
    \    return base::make_tree();\n  }\n\n  int lower_bound(const Key& k) const {\n\
    \    Ptr p = root;\n    int ret = 0;\n    while (p) {\n      if (k <= p->key)\
    \ {\n        p = p->l;\n      } else {\n        ret += base::count(p->l) + 1;\n\
    \        p = p->r;\n      }\n    }\n    return ret;\n  }\n\n  int upper_bound(const\
    \ Key& k) const {\n    Ptr p = root;\n    int ret = 0;\n    while (p) {\n    \
    \  if (k < p->key) {\n        p = p->l;\n      } else {\n        ret += base::count(p->l)\
    \ + 1;\n        p = p->r;\n      }\n    }\n    return ret;\n  }\n\n  int count(const\
    \ Key& k) const {\n    if constexpr (multi) {\n      return upper_bound(k) - lower_bound(k);\n\
    \    } else {\n      return !!find(k);\n    }\n  }\n\n  Ptr kth_element(int k)\
    \ const {\n    Ptr p = root;\n    while (p) {\n      int lc = base::count(p->l);\n\
    \      if (lc == k) return p;\n      if (k < lc) {\n        p = p->l;\n      }\
    \ else {\n        k -= lc + 1;\n        p = p->r;\n      }\n    }\n    return\
    \ p;\n  }\n\n  void erase(const Key& k) {\n    Ptr p = root;\n    int ret = 0;\n\
    \    bool flg = false;\n    while (p) {\n      if (k == p->key) flg = true;\n\
    \      if (k <= p->key) {\n        p = p->l;\n      } else {\n        ret += base::count(p->l)\
    \ + 1;\n        p = p->r;\n      }\n    }\n    if (flg) base::erase(root, ret);\n\
    \  }\n\n  void erase(Ptr p) { erase(p->key); }\n\n  int size() const { return\
    \ base::size(root); }\n\n protected:\n\n  void push(Ptr) override {}\n  \n  Ptr\
    \ update(Ptr n) override {\n    n->cnt = 1 + base::count(n->l) + base::count(n->r);\n\
    \    return n;\n  }\n\n  Ptr insert_key(const Key& k) {\n    Ptr p = root;\n \
    \   int ret = 0;\n    while (p) {\n      if constexpr (multi == false) {\n   \
    \     if (k == p->key) return p;\n      }\n      if (k < p->key) {\n        p\
    \ = p->l;\n      } else {\n        ret += base::count(p->l) + 1;\n        p =\
    \ p->r;\n      }\n    }\n    Ptr n = base::my_new(k);\n    auto x = base::split(root,\
    \ ret);\n    root = base::merge(base::merge(x.first, n), x.second);\n    return\
    \ n;\n  }\n};\n\n/**\n * @brief Ordered Set(base)\u3000(\u9806\u5E8F\u4ED8\u304D\
    \u96C6\u5408\u30FB\u57FA\u5E95\u30AF\u30E9\u30B9)\n */\n#line 4 \"orderedmap/orderedmap.hpp\"\
    \n\ntemplate <typename Key, typename Val, bool multi>\nstruct OrderedMapNode {\n\
    \  using Ptr = typename RBSTBase<OrderedMapNode>::Ptr;\n  Ptr l, r;\n  Key key;\n\
    \  Val val;\n  int cnt;\n\n  OrderedMapNode(const Key& k = Key(), const Val& v\
    \ = Val())\n      : l(), r(), key(k), val(v), cnt(1) {}\n};\n\ntemplate <typename\
    \ Key, typename Val>\nstruct OrderedMap : OrderedMapBase<OrderedMapNode<Key, Val,\
    \ false>, false> {\n  using base = OrderedMapBase<OrderedMapNode<Key, Val, false>,\
    \ false>;\n\n  OrderedMap() : base() {}\n\n  Val& operator[](const Key& key) {\
    \ return base::insert_key(key)->val; };\n\n};\n\n/**\n * @brief Ordered Map(\u9806\
    \u5E8F\u4ED8\u304D\u9023\u60F3\u914D\u5217)\n */\n#line 7 \"verify/verify-unit-test/orderedmap.test.cpp\"\
    \nusing namespace Nyaan;\n\nvoid orderdmap_test() {\n  OrderedMap<ll, ll> mp;\n\
    \  vector<pl> vc;\n\n  auto same_map = [&]() -> void {\n    for (int i = 0; i\
    \ < mp.size(); i++) {\n      auto kth = mp.kth_element(i);\n      assert(kth->key\
    \ == vc[i].first && \"same_map\");\n      assert(kth->val == vc[i].second && \"\
    same_map\");\n    }\n  };\n\n  rep(i, 5000) {\n    ll key = rng() % 2048;\n  \
    \  ll val = rng() % 2048;\n    {\n      // size\n      int s1 = mp.size();\n \
    \     int s2 = vc.size();\n      assert(s1 == s2 and \"size\");\n      // lower_bound\n\
    \      int l1 = mp.lower_bound(key);\n      int l2 = lb(vc, pl(key, -inf));\n\
    \      assert(l1 == l2 and \"lower_bound\");\n      // upper_bound\n      int\
    \ u1 = mp.upper_bound(key);\n      int u2 = ub(vc, pl(key, inf));\n      assert(u1\
    \ == u2 and \"upper_bound\");\n      // count\n      int c1 = mp.count(key);\n\
    \      assert(c1 == u1 - l1 and \"count\");\n      // find\n      auto f = mp.find(key);\n\
    \      assert(!!f == c1 && \"find\");\n      // kth-element\n      if (l1 != s1)\
    \ {\n        auto kth = mp.kth_element(l1);\n        assert(kth->key == vc[l1].first);\n\
    \        assert(kth->val == vc[l1].second);\n      }\n    }\n\n    // insert\n\
    \    {\n      mp[key] = val;\n      int l = lb(vc, pl(key, -inf));\n      if (l\
    \ != sz(vc) and vc[l].first == key)\n        vc[l].second = val;\n      else\n\
    \        vc.insert(begin(vc) + l, pl(key, val));\n      same_map();\n    }\n\n\
    \    // erase(key)\n    if (mp.size() != 0 and (rng() % 15) == 0) {\n      int\
    \ l = rng() % mp.size();\n      mp.erase(vc[l].first);\n      vc.erase(begin(vc)\
    \ + l);\n      same_map();\n    }\n    \n    // erase(ptr)\n    if (mp.size()\
    \ != 0 and (rng() % 15) == 0) {\n      int l = rng() % mp.size();\n      mp.erase(mp.find(vc[l].first));\n\
    \      vc.erase(begin(vc) + l);\n      same_map();\n    }\n  }\n}\n\nvoid Nyaan::solve()\
    \ { \n  orderdmap_test(); \n  ini(a,b);\n  out(a+b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../template/template.hpp\"\n//\n#include \"../../misc/rng.hpp\"\n#include \"\
    ../../orderedmap/orderedmap.hpp\"\nusing namespace Nyaan;\n\nvoid orderdmap_test()\
    \ {\n  OrderedMap<ll, ll> mp;\n  vector<pl> vc;\n\n  auto same_map = [&]() ->\
    \ void {\n    for (int i = 0; i < mp.size(); i++) {\n      auto kth = mp.kth_element(i);\n\
    \      assert(kth->key == vc[i].first && \"same_map\");\n      assert(kth->val\
    \ == vc[i].second && \"same_map\");\n    }\n  };\n\n  rep(i, 5000) {\n    ll key\
    \ = rng() % 2048;\n    ll val = rng() % 2048;\n    {\n      // size\n      int\
    \ s1 = mp.size();\n      int s2 = vc.size();\n      assert(s1 == s2 and \"size\"\
    );\n      // lower_bound\n      int l1 = mp.lower_bound(key);\n      int l2 =\
    \ lb(vc, pl(key, -inf));\n      assert(l1 == l2 and \"lower_bound\");\n      //\
    \ upper_bound\n      int u1 = mp.upper_bound(key);\n      int u2 = ub(vc, pl(key,\
    \ inf));\n      assert(u1 == u2 and \"upper_bound\");\n      // count\n      int\
    \ c1 = mp.count(key);\n      assert(c1 == u1 - l1 and \"count\");\n      // find\n\
    \      auto f = mp.find(key);\n      assert(!!f == c1 && \"find\");\n      //\
    \ kth-element\n      if (l1 != s1) {\n        auto kth = mp.kth_element(l1);\n\
    \        assert(kth->key == vc[l1].first);\n        assert(kth->val == vc[l1].second);\n\
    \      }\n    }\n\n    // insert\n    {\n      mp[key] = val;\n      int l = lb(vc,\
    \ pl(key, -inf));\n      if (l != sz(vc) and vc[l].first == key)\n        vc[l].second\
    \ = val;\n      else\n        vc.insert(begin(vc) + l, pl(key, val));\n      same_map();\n\
    \    }\n\n    // erase(key)\n    if (mp.size() != 0 and (rng() % 15) == 0) {\n\
    \      int l = rng() % mp.size();\n      mp.erase(vc[l].first);\n      vc.erase(begin(vc)\
    \ + l);\n      same_map();\n    }\n    \n    // erase(ptr)\n    if (mp.size()\
    \ != 0 and (rng() % 15) == 0) {\n      int l = rng() % mp.size();\n      mp.erase(mp.find(vc[l].first));\n\
    \      vc.erase(begin(vc) + l);\n      same_map();\n    }\n  }\n}\n\nvoid Nyaan::solve()\
    \ { \n  orderdmap_test(); \n  ini(a,b);\n  out(a+b);\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - misc/rng.hpp
  - orderedmap/orderedmap.hpp
  - orderedmap/orderedmap-base.hpp
  - rbst/rbst-base.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/orderedmap.test.cpp
  requiredBy: []
  timestamp: '2020-12-17 02:52:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/orderedmap.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/orderedmap.test.cpp
- /verify/verify/verify-unit-test/orderedmap.test.cpp.html
title: verify/verify-unit-test/orderedmap.test.cpp
---
