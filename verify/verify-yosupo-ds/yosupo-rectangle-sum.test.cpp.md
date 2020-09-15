---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/rectangle-sum.hpp
    title: data-structure/rectangle-sum.hpp
  - icon: ':heavy_check_mark:'
    path: segment-tree/persistent-segment-tree.hpp
    title: "\u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#line 1 \"\
    competitive-template.hpp\"\n#pragma region kyopro_template\n#define Nyaan_template\n\
    #include <immintrin.h>\n#include <bits/stdc++.h>\n#define pb push_back\n#define\
    \ eb emplace_back\n#define fi first\n#define se second\n#define each(x, v) for\
    \ (auto &x : v)\n#define all(v) (v).begin(), (v).end()\n#define sz(v) ((int)(v).size())\n\
    #define mem(a, val) memset(a, val, sizeof(a))\n#define ini(...)   \\\n  int __VA_ARGS__;\
    \ \\\n  in(__VA_ARGS__)\n#define inl(...)         \\\n  long long __VA_ARGS__;\
    \ \\\n  in(__VA_ARGS__)\n#define ins(...)      \\\n  string __VA_ARGS__; \\\n\
    \  in(__VA_ARGS__)\n#define inc(...)    \\\n  char __VA_ARGS__; \\\n  in(__VA_ARGS__)\n\
    #define in2(s, t)                           \\\n  for (int i = 0; i < (int)s.size();\
    \ i++) { \\\n    in(s[i], t[i]);                         \\\n  }\n#define in3(s,\
    \ t, u)                        \\\n  for (int i = 0; i < (int)s.size(); i++) {\
    \ \\\n    in(s[i], t[i], u[i]);                   \\\n  }\n#define in4(s, t, u,\
    \ v)                     \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n\
    \    in(s[i], t[i], u[i], v[i]);             \\\n  }\n#define rep(i, N) for (long\
    \ long i = 0; i < (long long)(N); i++)\n#define repr(i, N) for (long long i =\
    \ (long long)(N)-1; i >= 0; i--)\n#define rep1(i, N) for (long long i = 1; i <=\
    \ (long long)(N); i++)\n#define repr1(i, N) for (long long i = (N); (long long)(i)\
    \ > 0; i--)\n#define reg(i, a, b) for (long long i = (a); i < (b); i++)\n#define\
    \ die(...)      \\\n  do {                \\\n    out(__VA_ARGS__); \\\n    return;\
    \           \\\n  } while (0)\nusing namespace std;\nusing ll = long long;\ntemplate\
    \ <class T>\nusing V = vector<T>;\nusing vi = vector<int>;\nusing vl = vector<long\
    \ long>;\nusing vvi = vector<vector<int>>;\nusing vd = V<double>;\nusing vs =\
    \ V<string>;\nusing vvl = vector<vector<long long>>;\nusing P = pair<long long,\
    \ long long>;\nusing vp = vector<P>;\nusing pii = pair<int, int>;\nusing vpi =\
    \ vector<pair<int, int>>;\nconstexpr int inf = 1001001001;\nconstexpr long long\
    \ infLL = (1LL << 61) - 1;\ntemplate <typename T, typename U>\ninline bool amin(T\
    \ &x, U y) {\n  return (y < x) ? (x = y, true) : false;\n}\ntemplate <typename\
    \ T, typename U>\ninline bool amax(T &x, U y) {\n  return (x < y) ? (x = y, true)\
    \ : false;\n}\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n  os << p.first << \" \" << p.second;\n  return\
    \ os;\n}\ntemplate <typename T, typename U>\nistream &operator>>(istream &is,\
    \ pair<T, U> &p) {\n  is >> p.first >> p.second;\n  return is;\n}\ntemplate <typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n  int s = (int)v.size();\n\
    \  for (int i = 0; i < s; i++) os << (i ? \" \" : \"\") << v[i];\n  return os;\n\
    }\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T> &v) {\n \
    \ for (auto &x : v) is >> x;\n  return is;\n}\nvoid in() {}\ntemplate <typename\
    \ T, class... U>\nvoid in(T &t, U &... u) {\n  cin >> t;\n  in(u...);\n}\nvoid\
    \ out() { cout << \"\\n\"; }\ntemplate <typename T, class... U>\nvoid out(const\
    \ T &t, const U &... u) {\n  cout << t;\n  if (sizeof...(u)) cout << \" \";\n\
    \  out(u...);\n}\n\n#ifdef NyaanDebug\n#define trc(...)                   \\\n\
    \  do {                             \\\n    cerr << #__VA_ARGS__ << \" = \"; \\\
    \n    dbg_out(__VA_ARGS__);          \\\n  } while (0)\n#define trca(v, N)   \
    \    \\\n  do {                   \\\n    cerr << #v << \" = \"; \\\n    array_out(v,\
    \ N);     \\\n  } while (0)\n#define trcc(v)                             \\\n\
    \  do {                                      \\\n    cerr << #v << \" = {\"; \
    \                  \\\n    each(x, v) { cerr << \" \" << x << \",\"; } \\\n  \
    \  cerr << \"}\" << endl;                    \\\n  } while (0)\ntemplate <typename\
    \ T>\nvoid _cout(const T &c) {\n  cerr << c;\n}\nvoid _cout(const int &c) {\n\
    \  if (c == 1001001001)\n    cerr << \"inf\";\n  else if (c == -1001001001)\n\
    \    cerr << \"-inf\";\n  else\n    cerr << c;\n}\nvoid _cout(const unsigned int\
    \ &c) {\n  if (c == 1001001001)\n    cerr << \"inf\";\n  else\n    cerr << c;\n\
    }\nvoid _cout(const long long &c) {\n  if (c == 1001001001 || c == (1LL << 61)\
    \ - 1)\n    cerr << \"inf\";\n  else if (c == -1001001001 || c == -((1LL << 61)\
    \ - 1))\n    cerr << \"-inf\";\n  else\n    cerr << c;\n}\nvoid _cout(const unsigned\
    \ long long &c) {\n  if (c == 1001001001 || c == (1LL << 61) - 1)\n    cerr <<\
    \ \"inf\";\n  else\n    cerr << c;\n}\ntemplate <typename T, typename U>\nvoid\
    \ _cout(const pair<T, U> &p) {\n  cerr << \"{ \";\n  _cout(p.fi);\n  cerr << \"\
    , \";\n  _cout(p.se);\n  cerr << \" } \";\n}\ntemplate <typename T>\nvoid _cout(const\
    \ vector<T> &v) {\n  int s = v.size();\n  cerr << \"{ \";\n  for (int i = 0; i\
    \ < s; i++) {\n    cerr << (i ? \", \" : \"\");\n    _cout(v[i]);\n  }\n  cerr\
    \ << \" } \";\n}\ntemplate <typename T>\nvoid _cout(const vector<vector<T>> &v)\
    \ {\n  cerr << \"[ \";\n  for (const auto &x : v) {\n    cerr << endl;\n    _cout(x);\n\
    \    cerr << \", \";\n  }\n  cerr << endl << \" ] \";\n}\nvoid dbg_out() { cerr\
    \ << endl; }\ntemplate <typename T, class... U>\nvoid dbg_out(const T &t, const\
    \ U &... u) {\n  _cout(t);\n  if (sizeof...(u)) cerr << \", \";\n  dbg_out(u...);\n\
    }\ntemplate <typename T>\nvoid array_out(const T &v, int s) {\n  cerr << \"{ \"\
    ;\n  for (int i = 0; i < s; i++) {\n    cerr << (i ? \", \" : \"\");\n    _cout(v[i]);\n\
    \  }\n  cerr << \" } \" << endl;\n}\ntemplate <typename T>\nvoid array_out(const\
    \ T &v, int H, int W) {\n  cerr << \"[ \";\n  for (int i = 0; i < H; i++) {\n\
    \    cerr << (i ? \", \" : \"\");\n    array_out(v[i], W);\n  }\n  cerr << \"\
    \ ] \" << endl;\n}\n#else\n#define trc(...)\n#define trca(...)\n#define trcc(...)\n\
    #endif\n\ninline int popcnt(unsigned long long a) { return __builtin_popcountll(a);\
    \ }\ninline int lsb(unsigned long long a) { return __builtin_ctzll(a); }\ninline\
    \ int msb(unsigned long long a) { return 63 - __builtin_clzll(a); }\ntemplate\
    \ <typename T>\ninline int getbit(T a, int i) {\n  return (a >> i) & 1;\n}\ntemplate\
    \ <typename T>\ninline void setbit(T &a, int i) {\n  a |= (1LL << i);\n}\ntemplate\
    \ <typename T>\ninline void delbit(T &a, int i) {\n  a &= ~(1LL << i);\n}\ntemplate\
    \ <typename T>\nint lb(const vector<T> &v, const T &a) {\n  return lower_bound(begin(v),\
    \ end(v), a) - begin(v);\n}\ntemplate <typename T>\nint ub(const vector<T> &v,\
    \ const T &a) {\n  return upper_bound(begin(v), end(v), a) - begin(v);\n}\ntemplate\
    \ <typename T>\nint btw(T a, T x, T b) {\n  return a <= x && x < b;\n}\ntemplate\
    \ <typename T, typename U>\nT ceil(T a, U b) {\n  return (a + b - 1) / b;\n}\n\
    constexpr long long TEN(int n) {\n  long long ret = 1, x = 10;\n  while (n) {\n\
    \    if (n & 1) ret *= x;\n    x *= x;\n    n >>= 1;\n  }\n  return ret;\n}\n\
    template <typename T>\nvector<T> mkrui(const vector<T> &v) {\n  vector<T> ret(v.size()\
    \ + 1);\n  for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];\n\
    \  return ret;\n};\ntemplate <typename T>\nvector<T> mkuni(const vector<T> &v)\
    \ {\n  vector<T> ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(),\
    \ ret.end()), ret.end());\n  return ret;\n}\ntemplate <typename F>\nvector<int>\
    \ mkord(int N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n\
    \  sort(begin(ord), end(ord), f);\n  return ord;\n}\ntemplate <typename T = int>\n\
    vector<T> mkiota(int N) {\n  vector<T> ret(N);\n  iota(begin(ret), end(ret), 0);\n\
    \  return ret;\n}\ntemplate <typename T>\nvector<int> mkinv(vector<T> &v) {\n\
    \  vector<int> inv(v.size());\n  for (int i = 0; i < (int)v.size(); i++) inv[v[i]]\
    \ = i;\n  return inv;\n}\n\nstruct IoSetupNya {\n  IoSetupNya() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(15);\n  \
    \  cerr << fixed << setprecision(7);\n  }\n} iosetupnya;\n\nvoid solve();\nint\
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"data-structure/rectangle-sum.hpp\"\
    \nusing namespace std;\n\n#line 3 \"segment-tree/persistent-segment-tree.hpp\"\
    \nusing namespace std;\n\ntemplate <typename T, typename F, int NODES = 20000000>\n\
    struct PersistentSegmentTree {\n  using ll = long long;\n  struct Node {\n   \
    \ T data;\n    Node *l, *r;\n    Node() {}\n    Node(const T &_data) : data(_data),\
    \ l(nullptr), r(nullptr) {}\n  };\n\n  Node *pool;\n  int pid;\n  ll N;\n  const\
    \ F f;\n  const T ID;\n  Node *nil;\n  vector<Node *> roots;\n\n  PersistentSegmentTree(const\
    \ vector<T> &v, const F &f_, const T &ID_)\n      : pid(0), f(f_), ID(ID_), nil(nullptr)\
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
    \ docs/segment-tree/persistent-segtree.md\n */\n#line 6 \"data-structure/rectangle-sum.hpp\"\
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
    \ begin(ys);\n    return seg.query(u, l, r) - seg.query(d, l, r);\n  }\n};\n#line\
    \ 5 \"verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp\"\n\nvoid solve()\
    \ {\n  ini(N, Q);\n  vl xs(N), ys(N), ws(N);\n  in3(xs, ys, ws);\n  auto f = [](ll\
    \ u, ll v) { return u + v; };\n  RectangleSum<ll, ll, decltype(f)> rect(xs, ys,\
    \ ws, f);\n  rep(_, Q) {\n    inl(l, d, r, u);\n    out(rect.rect_sum(l, d, r,\
    \ u));\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ \"../../competitive-template.hpp\"\n#include \"../../data-structure/rectangle-sum.hpp\"\
    \n\nvoid solve() {\n  ini(N, Q);\n  vl xs(N), ys(N), ws(N);\n  in3(xs, ys, ws);\n\
    \  auto f = [](ll u, ll v) { return u + v; };\n  RectangleSum<ll, ll, decltype(f)>\
    \ rect(xs, ys, ws, f);\n  rep(_, Q) {\n    inl(l, d, r, u);\n    out(rect.rect_sum(l,\
    \ d, r, u));\n  }\n}"
  dependsOn:
  - competitive-template.hpp
  - data-structure/rectangle-sum.hpp
  - segment-tree/persistent-segment-tree.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp
  requiredBy: []
  timestamp: '2020-08-20 12:40:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp
---
