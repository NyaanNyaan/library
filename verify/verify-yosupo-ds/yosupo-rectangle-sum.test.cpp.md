---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure-2d/rectangle-sum.hpp
    title: "\u77E9\u5F62\u548C(\u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':x:'
    path: segment-tree/persistent-segment-tree.hpp
    title: "\u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
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
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#line 2 \"\
    template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include\
    \ <cinttypes>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
    \ <csetjmp>\n#include <csignal>\n#include <cstdarg>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <ctime>\n#include <deque>\n#include <exception>\n#include <forward_list>\n#include\
    \ <fstream>\n#include <functional>\n#include <initializer_list>\n#include <iomanip>\n\
    #include <ios>\n#include <iosfwd>\n#include <iostream>\n#include <istream>\n#include\
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
    \ 2 \"data-structure-2d/rectangle-sum.hpp\"\n\n\n\n#line 2 \"segment-tree/persistent-segment-tree.hpp\"\
    \n\n\n\ntemplate <typename T, typename F, int NODES = 20000000>\nstruct PersistentSegmentTree\
    \ {\n  using ll = long long;\n  struct Node {\n    T data;\n    Node *l, *r;\n\
    \    Node() {}\n    Node(const T &_data) : data(_data), l(nullptr), r(nullptr)\
    \ {}\n  };\n\n  Node *pool;\n  int pid;\n  ll N;\n  const F f;\n  const T ID;\n\
    \  Node *nil;\n  vector<Node *> roots;\n\n  PersistentSegmentTree(const vector<T>\
    \ &v, const F &f_, const T &ID_)\n      : pid(0), f(f_), ID(ID_), nil(nullptr)\
    \ {\n    pool = new Node[NODES];\n    nil = my_new(ID);\n    nil->l = nil->r =\
    \ nil;\n    roots.reserve(262144);\n    roots.push_back(build(v));\n  }\n\n  PersistentSegmentTree(const\
    \ ll &N_, const F &f_, const T &ID_)\n      : pid(0), N(N_), f(f_), ID(ID_), nil(nullptr)\
    \ {\n    pool = new Node[NODES];\n    nil = my_new(ID);\n    nil->l = nil->r =\
    \ nil;\n    roots.reserve(262144);\n    roots.push_back(nil);\n  }\n\n  Node *my_new(const\
    \ T &data) {\n    pool[pid].data = data;\n    pool[pid].l = pool[pid].r = nil;\n\
    \    return &(pool[pid++]);\n  }\n\n  Node *merge(Node *l, Node *r) {\n    pool[pid].data\
    \ = f(l->data, r->data);\n    pool[pid].l = l;\n    pool[pid].r = r;\n    return\
    \ &(pool[pid++]);\n  }\n\n  Node *build(const vector<T> &v) {\n    N = (ll)v.size();\n\
    \    return build(0, (ll)v.size(), v);\n  }\n\n  Node *build(ll l, ll r, const\
    \ vector<T> &v) {\n    if (l + 1 == r) return my_new(v[l]);\n    ll m = (l + r)\
    \ >> 1;\n    return merge(build(l, m, v), build(m, r, v));\n  }\n\n private:\n\
    \  Node *update_(ll a, const T &x, Node *n, ll l, ll r) {\n    if (l + 1 == r)\
    \ return my_new(x);\n    ll m = (l + r) >> 1;\n    if (a < m) return merge(update_(a,\
    \ x, n->l, l, m), n->r);\n    return merge(n->l, update_(a, x, n->r, m, r));\n\
    \  }\n  Node *add_(ll a, const T &x, Node *n, ll l, ll r) {\n    if (l + 1 ==\
    \ r) return my_new(f(x, n->data));\n    ll m = (l + r) >> 1;\n    if (a < m) return\
    \ merge(add_(a, x, n->l, l, m), n->r);\n    return merge(n->l, add_(a, x, n->r,\
    \ m, r));\n  }\n  T query_(ll a, ll b, Node *n, ll l, ll r) {\n    if (n == nil)\
    \ return ID;\n    if (r <= a or b <= l) return ID;\n    if (a <= l and r <= b)\
    \ return n->data;\n    ll m = (l + r) >> 1;\n    return f(query_(a, b, n->l, l,\
    \ m), query_(a, b, n->r, m, r));\n  }\n\n public:\n  Node *update(Node *n, ll\
    \ k, const T &x) {\n    Node *root = update_(k, x, n, 0, N);\n    roots.push_back(root);\n\
    \    return root;\n  }\n  Node *update(int t, ll k, const T &x) {\n    Node *root\
    \ = update_(k, x, roots[t], 0, N);\n    roots.push_back(root);\n    return root;\n\
    \  }\n  Node *update(ll k, const T &x) {\n    Node *root = update_(k, x, roots.back(),\
    \ 0, N);\n    roots.push_back(root);\n    return root;\n  }\n\n  Node *add(Node\
    \ *n, ll k, const T &x) {\n    Node *root = add_(k, x, n, 0, N);\n    roots.push_back(root);\n\
    \    return root;\n  }\n  Node *add(int t, ll k, const T &x) {\n    Node *root\
    \ = add_(k, x, roots[t], 0, N);\n    roots.push_back(root);\n    return root;\n\
    \  }\n  Node *add(ll k, const T &x) {\n    Node *root = add_(k, x, roots.back(),\
    \ 0, N);\n    roots.push_back(root);\n    return root;\n  }\n\n  T query(Node\
    \ *n, ll a, ll b) { return query_(a, b, n, 0, N); }\n  T query(int t, ll a, ll\
    \ b) { return query_(a, b, roots[t], 0, N); }\n  T query(ll a, ll b) { return\
    \ query_(a, b, roots.back(), 0, N); }\n\n  Node *new_tree() { return nil; }\n\
    };\n\n/**\n * @brief \u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs\
    \ docs/segment-tree/persistent-segtree.md\n */\n#line 6 \"data-structure-2d/rectangle-sum.hpp\"\
    \n\ntemplate <typename T, typename U, typename F>\nstruct RectangleSum {\n  PersistentSegmentTree<U,\
    \ F> seg;\n  vector<T> xs, ys;\n  vector<U> ws;\n  vector<int> ord;\n\n  RectangleSum(const\
    \ vector<T> &xs_, const vector<T> &ys_, const vector<U> &ws_,\n              \
    \ const F &f)\n      : seg({(int)xs_.size() + 1, f, U(0)}) {\n    int N = xs_.size();\n\
    \    xs.reserve(N);\n    ys.reserve(N);\n    ws.reserve(N);\n    ord.resize(N);\n\
    \    iota(begin(ord), end(ord), 0);\n    sort(begin(ord), end(ord), [&](int i,\
    \ int j) { return xs_[i] < xs_[j]; });\n    for (auto &i : ord) {\n      xs.push_back(xs_[i]);\n\
    \      ys.push_back(ys_[i]);\n      ws.push_back(ws_[i]);\n    }\n    iota(begin(ord),\
    \ end(ord), 0);\n    sort(begin(ord), end(ord), [&](int i, int j) { return ys[i]\
    \ < ys[j]; });\n    vector<T> ys2;\n    ys2.reserve(N);\n    for (auto &i : ord)\
    \ {\n      seg.add(i, ws[i]);\n      ys2.push_back(ys[i]);\n    }\n    ys.swap(ys2);\n\
    \  }\n\n  // [ [x1, 0], [x2, y] )\n  U rect_sum(T x1, T x2, T y) {\n    int l\
    \ = lower_bound(begin(xs), end(xs), x1) - begin(xs);\n    int r = lower_bound(begin(xs),\
    \ end(xs), x2) - begin(xs);\n    int u = lower_bound(begin(ys), end(ys), y) -\
    \ begin(ys);\n    return seg.query(u, l, r);\n  }\n\n  // [ [x1, y1], [x2, y2]\
    \ )\n  U rect_sum(T x1, T y1, T x2, T y2) {\n    if (x1 >= x2 || y1 >= y2) return\
    \ U(0);\n    int l = lower_bound(begin(xs), end(xs), x1) - begin(xs);\n    int\
    \ r = lower_bound(begin(xs), end(xs), x2) - begin(xs);\n    int d = lower_bound(begin(ys),\
    \ end(ys), y1) - begin(ys);\n    int u = lower_bound(begin(ys), end(ys), y2) -\
    \ begin(ys);\n    return seg.query(u, l, r) - seg.query(d, l, r);\n  }\n};\n\n\
    /*\n * @brief \u77E9\u5F62\u548C(\u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    )\n * @docs docs/data-structure-2d/ds-2d.md\n */\n#line 5 \"verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve() {\n  ini(N, Q);\n  vl xs(N), ys(N),\
    \ ws(N);\n  in3(xs, ys, ws);\n  auto f = [](ll u, ll v) { return u + v; };\n \
    \ RectangleSum<ll, ll, decltype(f)> rect(xs, ys, ws, f);\n  rep(_, Q) {\n    inl(l,\
    \ d, r, u);\n    out(rect.rect_sum(l, d, r, u));\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ \"../../template/template.hpp\"\n#include \"../../data-structure-2d/rectangle-sum.hpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve() {\n  ini(N, Q);\n  vl xs(N), ys(N),\
    \ ws(N);\n  in3(xs, ys, ws);\n  auto f = [](ll u, ll v) { return u + v; };\n \
    \ RectangleSum<ll, ll, decltype(f)> rect(xs, ys, ws, f);\n  rep(_, Q) {\n    inl(l,\
    \ d, r, u);\n    out(rect.rect_sum(l, d, r, u));\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - data-structure-2d/rectangle-sum.hpp
  - segment-tree/persistent-segment-tree.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp
---
