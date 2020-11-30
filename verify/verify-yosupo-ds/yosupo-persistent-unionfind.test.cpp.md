---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent-array.hpp
    title: "\u6C38\u7D9A\u914D\u5217"
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent-union-find.hpp
    title: "\u5B8C\u5168\u6C38\u7D9AUnion-Find"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-persistent-unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n\
    #line 1 \"competitive-template.hpp\"\n#pragma region kyopro_template\n#define\
    \ Nyaan_template\n#include <immintrin.h>\n#include <bits/stdc++.h>\n#define pb\
    \ push_back\n#define eb emplace_back\n#define fi first\n#define se second\n#define\
    \ each(x, v) for (auto &x : v)\n#define all(v) (v).begin(), (v).end()\n#define\
    \ sz(v) ((int)(v).size())\n#define mem(a, val) memset(a, val, sizeof(a))\n#define\
    \ ini(...)   \\\n  int __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define inl(...)  \
    \       \\\n  long long __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define ins(...) \
    \     \\\n  string __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define inc(...)    \\\n\
    \  char __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define in2(s, t)                \
    \           \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i]);\
    \                         \\\n  }\n#define in3(s, t, u)                      \
    \  \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i], u[i]);\
    \                   \\\n  }\n#define in4(s, t, u, v)                     \\\n\
    \  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i], u[i], v[i]);\
    \             \\\n  }\n#define rep(i, N) for (long long i = 0; i < (long long)(N);\
    \ i++)\n#define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)\n\
    #define rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)\n#define repr1(i,\
    \ N) for (long long i = (N); (long long)(i) > 0; i--)\n#define reg(i, a, b) for\
    \ (long long i = (a); i < (b); i++)\n#define die(...)      \\\n  do {        \
    \        \\\n    out(__VA_ARGS__); \\\n    return;           \\\n  } while (0)\n\
    using namespace std;\nusing ll = long long;\ntemplate <class T>\nusing V = vector<T>;\n\
    using vi = vector<int>;\nusing vl = vector<long long>;\nusing vvi = vector<vector<int>>;\n\
    using vd = V<double>;\nusing vs = V<string>;\nusing vvl = vector<vector<long long>>;\n\
    using P = pair<long long, long long>;\nusing vp = vector<P>;\nusing pii = pair<int,\
    \ int>;\nusing vpi = vector<pair<int, int>>;\nconstexpr int inf = 1001001001;\n\
    constexpr long long infLL = (1LL << 61) - 1;\ntemplate <typename T, typename U>\n\
    inline bool amin(T &x, U y) {\n  return (y < x) ? (x = y, true) : false;\n}\n\
    template <typename T, typename U>\ninline bool amax(T &x, U y) {\n  return (x\
    \ < y) ? (x = y, true) : false;\n}\ntemplate <typename T, typename U>\nostream\
    \ &operator<<(ostream &os, const pair<T, U> &p) {\n  os << p.first << \" \" <<\
    \ p.second;\n  return os;\n}\ntemplate <typename T, typename U>\nistream &operator>>(istream\
    \ &is, pair<T, U> &p) {\n  is >> p.first >> p.second;\n  return is;\n}\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n  int\
    \ s = (int)v.size();\n  for (int i = 0; i < s; i++) os << (i ? \" \" : \"\") <<\
    \ v[i];\n  return os;\n}\ntemplate <typename T>\nistream &operator>>(istream &is,\
    \ vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return is;\n}\nvoid in() {}\n\
    template <typename T, class... U>\nvoid in(T &t, U &... u) {\n  cin >> t;\n  in(u...);\n\
    }\nvoid out() { cout << \"\\n\"; }\ntemplate <typename T, class... U>\nvoid out(const\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"data-structure/persistent-union-find.hpp\"\
    \nusing namespace std;\n\n#line 3 \"data-structure/persistent-array.hpp\"\nusing\
    \ namespace std;\n\ntemplate <typename T, int shift = 4>\nstruct PersistentArray\
    \ {\n  struct Node {\n    Node *ns[1 << shift];\n    Node() { memset(ns, 0, sizeof(ns));\
    \ }\n    Node(const Node &other) { memcpy(ns, other.ns, sizeof(ns)); }\n    Node(const\
    \ Node *other) { memcpy(ns, other->ns, sizeof(ns)); }\n  };\n  inline Node *my_new()\
    \ { return new Node(); }\n  inline Node *my_new(const Node &other) { return new\
    \ Node(other); }\n  inline Node *my_new(const Node *other) { return new Node(other);\
    \ }\n  inline T *my_new_leaf(const T &val) { return new T{val}; }\n\n  using i64\
    \ = long long;\n  static constexpr int mask = (1 << shift) - 1;\n  Node *root;\n\
    \  int depth;\n  T ID;\n\n  PersistentArray() {}\n\n  PersistentArray(i64 MAX,\
    \ T ID_ = T(0)) : root(my_new()), depth(0), ID(ID_) {\n    while (MAX) ++depth,\
    \ MAX >>= shift;\n  }\n\n  PersistentArray(const vector<T> &v, T ID_ = T(0))\n\
    \      : root(my_new()), depth(0), ID(ID_) {\n    i64 MAX = v.size();\n    while\
    \ (MAX) ++depth, MAX >>= shift;\n    for (int i = 0; i < (int)v.size(); i++) {\n\
    \      Node *n = root;\n      for (int k = i, d = depth; d; d--) {\n        if\
    \ (!(n->ns[k & mask])) {\n          if (d == 1)\n            n->ns[k & mask] =\
    \ reinterpret_cast<Node *>(my_new_leaf(v[i]));\n          else\n            n->ns[k\
    \ & mask] = my_new();\n        }\n        n = n->ns[k & mask];\n        k >>=\
    \ shift;\n      }\n    }\n  }\n\n  T get(Node *n, i64 k) const {\n    for (int\
    \ i = depth; i; --i) {\n      n = n ? n->ns[k & mask] : nullptr;\n      k >>=\
    \ shift;\n    }\n    return n ? *reinterpret_cast<T *>(n) : ID;\n  }\n  T get(i64\
    \ k) const { return get(root, k); }\n\n  Node *update(Node *n, i64 k, const T\
    \ &val) {\n    stack<pair<Node *, int>> st;\n    for (int i = depth; i; --i) {\n\
    \      st.emplace(n, k & mask);\n      n = n ? n->ns[k & mask] : nullptr;\n  \
    \    k >>= shift;\n    }\n    Node *chd = reinterpret_cast<Node *>(my_new_leaf(val));\n\
    \    while (!st.empty()) {\n      Node *par;\n      int k;\n      tie(par, k)\
    \ = st.top();\n      st.pop();\n      Node *nxt = par ? my_new(par) : my_new();\n\
    \      nxt->ns[k] = chd;\n      chd = nxt;\n    }\n    return root = chd;\n  }\n\
    \  Node *update(i64 k, const T &val) { return update(root, k, val); }\n};\n\n\
    /**\n * @brief \u6C38\u7D9A\u914D\u5217\n */\n#line 6 \"data-structure/persistent-union-find.hpp\"\
    \n\nstruct PersistentUnionFind {\n  PersistentArray<int> arr;\n  using Node =\
    \ decltype(arr)::Node;\n  static Node *root;\n\n  PersistentUnionFind(int N) :\
    \ arr(vector<int>(N, -1)) { root = arr.root; }\n\n  pair<int, int> find_with_size(int\
    \ i, Node *r = root) {\n    int n = arr.get(r, i);\n    return n < 0 ? pair<int,\
    \ int>{i, n} : find_with_size(n, r);\n  }\n  inline int find(int i, Node *r =\
    \ root) { return find_with_size(i, r).first; }\n  inline int size(int i, Node\
    \ *r = root) { return -(find_with_size(i, r).second); }\n  inline int same(int\
    \ i, int j, Node *r = root) { return find(i, r) == find(j, r); }\n\n  int unite(int\
    \ i, int j, Node *r = root) {\n    int is, js;\n    tie(i, is) = find_with_size(i,\
    \ r);\n    tie(j, js) = find_with_size(j, r);\n    if (i == j) return false;\n\
    \    if (is > js) swap(i, j), swap(is, js);\n    r = arr.update(r, i, is + js);\n\
    \    r = arr.update(r, j, i);\n    root = r;\n    return true;\n  }\n\n  Node\
    \ *get_root() const { return root; }\n};\ntypename PersistentUnionFind::Node *PersistentUnionFind::root\
    \ = nullptr;\n\n/**\n * @brief \u5B8C\u5168\u6C38\u7D9AUnion-Find\n */\n#line\
    \ 5 \"verify/verify-yosupo-ds/yosupo-persistent-unionfind.test.cpp\"\n\nvoid solve()\
    \ {\n  ini(N, Q);\n  PersistentUnionFind uf(N);\n  V<decltype(uf)::Node *> roots(Q\
    \ + 1, nullptr);\n  roots[0] = uf.get_root();\n\n  rep(i, Q) {\n    ini(t, k,\
    \ u, v);\n    if (t) {\n      auto r = roots[k + 1];\n      out(uf.same(u, v,\
    \ r));\n    } else {\n      auto r = roots[k + 1];\n      uf.unite(u, v, r);\n\
    \      roots[i + 1] = uf.get_root();\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include \"../../competitive-template.hpp\"\n#include \"../../data-structure/persistent-union-find.hpp\"\
    \n\nvoid solve() {\n  ini(N, Q);\n  PersistentUnionFind uf(N);\n  V<decltype(uf)::Node\
    \ *> roots(Q + 1, nullptr);\n  roots[0] = uf.get_root();\n\n  rep(i, Q) {\n  \
    \  ini(t, k, u, v);\n    if (t) {\n      auto r = roots[k + 1];\n      out(uf.same(u,\
    \ v, r));\n    } else {\n      auto r = roots[k + 1];\n      uf.unite(u, v, r);\n\
    \      roots[i + 1] = uf.get_root();\n    }\n  }\n}"
  dependsOn:
  - competitive-template.hpp
  - data-structure/persistent-union-find.hpp
  - data-structure/persistent-array.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-persistent-unionfind.test.cpp
  requiredBy: []
  timestamp: '2020-11-27 13:31:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-persistent-unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-persistent-unionfind.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-persistent-unionfind.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-persistent-unionfind.test.cpp
---
