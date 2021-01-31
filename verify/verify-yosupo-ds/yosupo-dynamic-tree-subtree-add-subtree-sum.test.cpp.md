---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lct/link-cut-tree-subtree-add.hpp
    title: "\u90E8\u5206\u6728\u52A0\u7B97\u30AF\u30A8\u30EALink/Cut Tree"
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-dynamic-tree-subtree-add-subtree-sum.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum\"\
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
    \ 5 \"verify/verify-yosupo-ds/yosupo-dynamic-tree-subtree-add-subtree-sum.test.cpp\"\
    \n//\n#line 2 \"lct/link-cut-tree-subtree-add.hpp\"\n\ntemplate <typename T, T\
    \ (*add)(T, T), T (*sub)(T, T), T (*mul)(T, long long)>\nstruct LinkCutForSubtreeNode\
    \ {\n  using Node = LinkCutForSubtreeNode;\n  using Ptr = LinkCutForSubtreeNode*;\n\
    \  Ptr l, r, p;\n  T key, sum, lazy, cancel, subsum;\n  int cnt, subcnt;\n  bool\
    \ rev;\n\n  LinkCutForSubtreeNode(const T& t = T())\n      : l(),\n        r(),\n\
    \        p(),\n        key(t),\n        sum(t),\n        lazy(T()),\n        cancel(T()),\n\
    \        subsum(T()),\n        cnt(1),\n        subcnt(0),\n        rev(false)\
    \ {}\n  void make_normal(Ptr other) {\n    subsum = add(subsum, other->sum);\n\
    \    subcnt += other->cnt;\n  }\n  void make_prefer(Ptr other) {\n    subsum =\
    \ sub(subsum, other->sum);\n    subcnt -= other->cnt;\n  }\n  void merge(Ptr n1,\
    \ Ptr n2) {\n    sum = add(add(n1 ? n1->sum : T(), key), add(subsum, n2 ? n2->sum\
    \ : T()));\n    cnt = 1 + (n1 ? n1->cnt : 0) + (n2 ? n2->cnt : 0) + subcnt;\n\
    \    if (n1) n1->cancel = lazy;\n    if (n2) n2->cancel = lazy;\n  }\n  void apply(const\
    \ T& add_val) {\n    key = add(key, add_val);\n    sum = add(sum, mul(add_val,\
    \ cnt));\n    lazy = add(lazy, add_val);\n    subsum = add(subsum, mul(add_val,\
    \ subcnt));\n  }\n  void fetch() {\n    if (!p) return;\n    apply(p->lazy - cancel);\n\
    \    cancel = p->lazy;\n  }\n};\n\ntemplate <typename T, T (*add)(T, T), T (*sub)(T,\
    \ T), T (*mul)(T, long long)>\nstruct LinkCutTreeSubtreeQuery {\n  using Node\
    \ = LinkCutForSubtreeNode<T, add, sub, mul>;\n  using Ptr = Node*;\n\n  void push_rev(Ptr\
    \ t) {\n    if (!t) return;\n    if (t->rev) {\n      if (t->l) toggle(t->l);\n\
    \      if (t->r) toggle(t->r);\n      t->rev = false;\n    }\n  }\n\n  void push(Ptr\
    \ t) {\n    if (!t) return;\n    if (t->rev) {\n      if (t->l) toggle(t->l);\n\
    \      if (t->r) toggle(t->r);\n      t->rev = false;\n    }\n    if (t->l) t->l->fetch();\n\
    \    if (t->r) t->r->fetch();\n  }\n\n  Ptr update(Ptr t) {\n    if (!t) return\
    \ t;\n    t->merge(t->l, t->r);\n    return t;\n  }\n\n  void splay(Ptr t) {\n\
    \    push(t);\n    while (!is_root(t)) {\n      Ptr q = t->p;\n      if (is_root(q))\
    \ {\n        push_rev(q), push_rev(t);\n        rot(t);\n      } else {\n    \
    \    Ptr r = q->p;\n        push_rev(r), push_rev(q), push_rev(t);\n        if\
    \ (pos(q) == pos(t))\n          rot(q), rot(t);\n        else\n          rot(t),\
    \ rot(t);\n      }\n    }\n  }\n\n  Ptr expose(Ptr t) {\n    Ptr rp = nullptr;\n\
    \    for (Ptr cur = t; cur; cur = cur->p) {\n      splay(cur), push(cur);\n  \
    \    if (cur->r) cur->make_normal(cur->r);\n      if (rp) rp->fetch(), cur->make_prefer(rp);\n\
    \      cur->r = rp;\n      rp = cur;\n    }\n    splay(t);\n    return rp;\n \
    \ }\n\n  void evert(Ptr t) {\n    expose(t);\n    toggle(t);\n    push(t);\n \
    \ }\n\n  void link(Ptr u, Ptr v) {\n    evert(u);\n    expose(v);\n    u->p =\
    \ v, v->r = u;\n    update(v);\n  }\n\n  void cut(Ptr u, Ptr v) {\n    evert(u);\n\
    \    expose(v);\n    v->l = u->p = nullptr;\n    update(v);\n  }\n\n  void toggle(Ptr\
    \ t) {\n    swap(t->l, t->r);\n    t->rev ^= true;\n  }\n\n  T get_key(Ptr t)\
    \ {\n    expose(t);\n    return t->key;\n  }\n\n  void set_key(Ptr t, const T&\
    \ key) {\n    expose(t);\n    t->key = key;\n    update(t);\n  }\n\n  void subtree_add(Ptr\
    \ t, const T& add_val) {\n    expose(t);\n    Ptr l = t->l;\n    if (l) t->l =\
    \ nullptr, update(t);\n    t->apply(add_val);\n    if (l) t->l = l, update(t);\n\
    \  }\n\n  T subtree_sum(Ptr t) {\n    expose(t);\n    return add(t->key, t->subsum);\n\
    \  }\n\n  Ptr get_root(Ptr x) {\n    expose(x);\n    while (x->l) this->push(x),\
    \ x = x->l;\n    return x;\n  }\n\n protected:\n  bool is_root(Ptr t) { return\
    \ !(t->p) || (t->p->l != t && t->p->r != t); }\n\n  inline int pos(Ptr t) {\n\
    \    if (t->p) {\n      if (t->p->l == t) return -1;\n      if (t->p->r == t)\
    \ return 1;\n    }\n    return 0;\n  }\n\n  void rot(Ptr t) {\n    Ptr x = t->p,\
    \ y = x->p;\n    push(x), push(t);\n    if (pos(t) == -1) {\n      if ((x->l =\
    \ t->r)) t->r->p = x;\n      t->r = x, x->p = t;\n    } else {\n      if ((x->r\
    \ = t->l)) t->l->p = x;\n      t->l = x, x->p = t;\n    }\n    T xc = x->cancel;\n\
    \    update(x), update(t);\n    t->cancel = xc;\n    if ((t->p = y)) {\n     \
    \ if (y->l == x) y->l = t;\n      if (y->r == x) y->r = t;\n    }\n  }\n};\n\n\
    /**\n * @brief \u90E8\u5206\u6728\u52A0\u7B97\u30AF\u30A8\u30EALink/Cut Tree\n\
    \ */\n#line 7 \"verify/verify-yosupo-ds/yosupo-dynamic-tree-subtree-add-subtree-sum.test.cpp\"\
    \n\nusing namespace Nyaan;\nll add(ll a, ll b) { return a + b; }\nll sub(ll a,\
    \ ll b) { return a - b; }\nll mul(ll a, ll b) { return a * b; }\n\n#line 2 \"\
    misc/fastio.hpp\"\n\n\n\nnamespace fastio {\nstatic constexpr int SZ = 1 << 17;\n\
    char ibuf[SZ], obuf[SZ];\nint pil = 0, pir = 0, por = 0;\n\nstruct Pre {\n  char\
    \ num[40000];\n  constexpr Pre() : num() {\n    for (int i = 0; i < 10000; i++)\
    \ {\n      int n = i;\n      for (int j = 3; j >= 0; j--) {\n        num[i * 4\
    \ + j] = n % 10 + '0';\n        n /= 10;\n      }\n    }\n  }\n} constexpr pre;\n\
    \ninline void load() {\n  memcpy(ibuf, ibuf + pil, pir - pil);\n  pir = pir -\
    \ pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);\n  pil = 0;\n}\ninline\
    \ void flush() {\n  fwrite(obuf, 1, por, stdout);\n  por = 0;\n}\n\ninline void\
    \ rd(char& c) { c = ibuf[pil++]; }\ntemplate <typename T>\ninline void rd(T& x)\
    \ {\n  if (pil + 32 > pir) load();\n  char c;\n  do\n    c = ibuf[pil++];\n  while\
    \ (c < '-');\n  bool minus = 0;\n  if (c == '-') {\n    minus = 1;\n    c = ibuf[pil++];\n\
    \  }\n  x = 0;\n  while (c >= '0') {\n    x = x * 10 + (c & 15);\n    c = ibuf[pil++];\n\
    \  }\n  if (minus) x = -x;\n}\ninline void rd() {}\ntemplate <typename Head, typename...\
    \ Tail>\ninline void rd(Head& head, Tail&... tail) {\n  rd(head);\n  rd(tail...);\n\
    }\n\ninline void wt(char c) { obuf[por++] = c; }\ntemplate <typename T>\ninline\
    \ void wt(T x) {\n  if (por > SZ - 32) flush();\n  if (!x) {\n    obuf[por++]\
    \ = '0';\n    return;\n  }\n  if (x < 0) {\n    obuf[por++] = '-';\n    x = -x;\n\
    \  }\n  int i = 12;\n  char buf[16];\n  while (x >= 10000) {\n    memcpy(buf +\
    \ i, pre.num + (x % 10000) * 4, 4);\n    x /= 10000;\n    i -= 4;\n  }\n  if (x\
    \ < 100) {\n    if (x < 10) {\n      wt(char('0' + char(x)));\n    } else {\n\
    \      uint32_t q = (uint32_t(x) * 205) >> 11;\n      uint32_t r = uint32_t(x)\
    \ - q * 10;\n      obuf[por + 0] = '0' + q;\n      obuf[por + 1] = '0' + r;\n\
    \      por += 2;\n    }\n  } else {\n    if (x < 1000) {\n      memcpy(obuf +\
    \ por, pre.num + (x << 2) + 1, 3);\n      por += 3;\n    } else {\n      memcpy(obuf\
    \ + por, pre.num + (x << 2), 4);\n      por += 4;\n    }\n  }\n  memcpy(obuf +\
    \ por, buf + i + 4, 12 - i);\n  por += 12 - i;\n}\n\ninline void wt() {}\ntemplate\
    \ <typename Head, typename... Tail>\ninline void wt(Head head, Tail... tail) {\n\
    \  wt(head);\n  wt(tail...);\n}\ntemplate <typename T>\ninline void wtn(T x) {\n\
    \  wt(x, '\\n');\n}\n\nstruct Dummy {\n  Dummy() { atexit(flush); }\n} dummy;\n\
    \n}  // namespace fastio\nusing fastio::rd;\nusing fastio::wt;\nusing fastio::wtn;\n\
    #line 14 \"verify/verify-yosupo-ds/yosupo-dynamic-tree-subtree-add-subtree-sum.test.cpp\"\
    \nvoid Nyaan::solve() {\n  using LCT = LinkCutTreeSubtreeQuery<ll, add, sub, mul>;\n\
    \  LCT lct;\n\n  int N, Q;\n  rd(N, Q);\n\n  vector<LCT::Ptr> vs(N);\n  rep(i,\
    \ N) {\n    int a;\n    rd(a);\n    vs[i] = new LCT::Node(a);\n  }\n  for (int\
    \ i = 1; i < N; i++) {\n    int a, b;\n    rd(a, b);\n    lct.link(vs[a], vs[b]);\n\
    \  }\n\n  while (Q--) {\n    int cmd;\n    rd(cmd);\n    if (cmd == 0) {\n   \
    \   int u, v, w, x;\n      rd(u, v, w, x);\n      lct.cut(vs[u], vs[v]);\n   \
    \   lct.link(vs[w], vs[x]);\n    } else if (cmd == 1) {\n      int v, p, x;\n\
    \      rd(v, p, x);\n      lct.evert(vs[p]);\n      lct.subtree_add(vs[v], x);\n\
    \    } else {\n      int v, p;\n      rd(v, p);\n      lct.evert(vs[p]);\n   \
    \   wtn(lct.subtree_sum(vs[v]));\n    }\n  }\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum\"\
    \n\n#include \"../../template/template.hpp\"\n//\n#include \"../../lct/link-cut-tree-subtree-add.hpp\"\
    \n\nusing namespace Nyaan;\nll add(ll a, ll b) { return a + b; }\nll sub(ll a,\
    \ ll b) { return a - b; }\nll mul(ll a, ll b) { return a * b; }\n\n#include \"\
    ../../misc/fastio.hpp\"\nvoid Nyaan::solve() {\n  using LCT = LinkCutTreeSubtreeQuery<ll,\
    \ add, sub, mul>;\n  LCT lct;\n\n  int N, Q;\n  rd(N, Q);\n\n  vector<LCT::Ptr>\
    \ vs(N);\n  rep(i, N) {\n    int a;\n    rd(a);\n    vs[i] = new LCT::Node(a);\n\
    \  }\n  for (int i = 1; i < N; i++) {\n    int a, b;\n    rd(a, b);\n    lct.link(vs[a],\
    \ vs[b]);\n  }\n\n  while (Q--) {\n    int cmd;\n    rd(cmd);\n    if (cmd ==\
    \ 0) {\n      int u, v, w, x;\n      rd(u, v, w, x);\n      lct.cut(vs[u], vs[v]);\n\
    \      lct.link(vs[w], vs[x]);\n    } else if (cmd == 1) {\n      int v, p, x;\n\
    \      rd(v, p, x);\n      lct.evert(vs[p]);\n      lct.subtree_add(vs[v], x);\n\
    \    } else {\n      int v, p;\n      rd(v, p);\n      lct.evert(vs[p]);\n   \
    \   wtn(lct.subtree_sum(vs[v]));\n    }\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - lct/link-cut-tree-subtree-add.hpp
  - misc/fastio.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-dynamic-tree-subtree-add-subtree-sum.test.cpp
  requiredBy: []
  timestamp: '2021-01-31 21:16:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-dynamic-tree-subtree-add-subtree-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-dynamic-tree-subtree-add-subtree-sum.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-dynamic-tree-subtree-add-subtree-sum.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-dynamic-tree-subtree-add-subtree-sum.test.cpp
---
