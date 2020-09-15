---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-trie.hpp
    title: Binary Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-binary-trie.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#line 1 \"\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"data-structure/binary-trie.hpp\"\
    \nusing namespace std;\n\ntemplate <typename T, int MAX_LOG, int NODES = 16777216>\n\
    struct BinaryTrie {\n  using Container = vector<int>;\n  struct Node {\n    Node\
    \ *nxt[2];\n    int exist;\n    Container accept;\n    Node() {}\n  };\n\n  Node\
    \ *pool;\n  int pid;\n  T lazy;\n  Node *nil;\n  Node *root;\n\n  BinaryTrie()\
    \ : pid(0), lazy(T(0)), nil(nullptr) {\n    pool = new Node[NODES];\n    nil =\
    \ my_new();\n    nil->nxt[0] = nil->nxt[1] = root = nil;\n  }\n\n  Node *my_new(int\
    \ exist_ = 0, int id = -1) {\n    pool[pid].nxt[0] = pool[pid].nxt[1] = nil;\n\
    \    pool[pid].exist = exist_;\n    if (id != -1) pool[pid].accept.push_back(id);\n\
    \    return &(pool[pid++]);\n  }\n\n  Node *merge(Node *l, Node *r) {\n    pool[pid].nxt[0]\
    \ = l;\n    pool[pid].nxt[1] = r;\n    pool[pid].exist = l->exist + r->exist;\n\
    \    return &(pool[pid++]);\n  }\n\n private:\n  Node *add_(const T &x, int id,\
    \ Node *n, int bit_idx) {\n    if (bit_idx == -1) {\n      if (n == nil) return\
    \ my_new(1, id);\n      n->exist++;\n      n->accept.push_back(id);\n      return\
    \ n;\n    } else {\n      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))\n\
    \        return merge(add_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);\n     \
    \ else\n        return merge(n->nxt[0], add_(x, id, n->nxt[1], bit_idx - 1));\n\
    \    }\n  }\n\n public:\n  void add(const T &x, int id = -1) { root = add_(x,\
    \ id, root, MAX_LOG); }\n\n private:\n  Node *del_(const T &x, int id, Node *n,\
    \ int bit_idx) {\n    if (bit_idx == -1) {\n      n->exist--;\n      return n;\n\
    \    } else {\n      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))\n  \
    \      return merge(del_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);\n      else\n\
    \        return merge(n->nxt[0], del_(x, id, n->nxt[1], bit_idx - 1));\n    }\n\
    \  }\n\n public:\n  void del(const T &x, int id = -1) { root = del_(x, id, root,\
    \ MAX_LOG); }\n\n private:\n  pair<int, Container &> find_(const T &x, Node *n,\
    \ int bit_idx) {\n    if (bit_idx == -1)\n      return pair<int, Container &>(n->exist,\
    \ n->accept);\n    else {\n      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx)\
    \ & 1))\n        return find_(x, n->nxt[0], bit_idx - 1);\n      else\n      \
    \  return find_(x, n->nxt[1], bit_idx - 1);\n    }\n  }\n\n public:\n  pair<int,\
    \ Container &> find(const T &x) { return find_(x, root, MAX_LOG); }\n\n private:\n\
    \  pair<T, Container &> max_element_(Node *n, int bit_idx) {\n    if (bit_idx\
    \ == -1) return pair<T, Container &>(0, n->accept);\n    if (n->nxt[~(lazy >>\
    \ bit_idx) & 1]->exist) {\n      auto ret = max_element_(n->nxt[~(lazy >> bit_idx)\
    \ & 1], bit_idx - 1);\n      ret.first |= T(1) << bit_idx;\n      return ret;\n\
    \    } else {\n      return max_element_(n->nxt[(lazy >> bit_idx) & 1], bit_idx\
    \ - 1);\n    }\n  }\n\n public:\n  pair<T, Container &> max_element() { return\
    \ max_element_(root, MAX_LOG); }\n\n private:\n  pair<T, Container &> min_element_(Node\
    \ *n, int bit_idx) {\n    if (bit_idx == -1) return pair<T, Container &>(0, n->accept);\n\
    \    if (n->nxt[(lazy >> bit_idx) & 1]->exist) {\n      return min_element_(n->nxt[(lazy\
    \ >> bit_idx) & 1], bit_idx - 1);\n    } else {\n      auto ret = min_element_(n->nxt[~(lazy\
    \ >> bit_idx) & 1], bit_idx - 1);\n      ret.first |= T(1) << bit_idx;\n     \
    \ return ret;\n    }\n  }\n\n public:\n  pair<T, Container &> min_element() {\
    \ return min_element_(root, MAX_LOG); }\n\n private:\n  pair<T, Container &> get_kth_(Node\
    \ *n, int64_t k, int bit_idx) {\n    if (bit_idx == -1) return pair<T, Container\
    \ &>(0, n->accept);\n    int ex0 = n->nxt[(lazy >> bit_idx) & 1]->exist;\n   \
    \ if (ex0 < k) {\n      auto ret = get_kth_(n->nxt[~(lazy >> bit_idx) & 1], k\
    \ - ex0, bit_idx - 1);\n      ret.first |= T(1) << bit_idx;\n      return ret;\n\
    \    } else {\n      return get_kth_(n->nxt[(lazy >> bit_idx) & 1], k, bit_idx\
    \ - 1);\n    }\n  }\n\n public:\n  pair<T, Container &> get_kth(int64_t k) { return\
    \ get_kth_(root, k, MAX_LOG); }\n\n  void operate_xor(T x) { lazy ^= x; }\n};\n\
    \n/**\n * @brief Binary Trie\n * @docs docs/data-structure/binary-trie.md\n */\n\
    #line 5 \"verify/verify-yosupo-ds/yosupo-binary-trie.test.cpp\"\n\nvoid solve()\
    \ {\n  ini(Q);\n  BinaryTrie<int, 30> trie;\n  rep(_, Q) {\n    ini(c, x);\n \
    \   if (c == 0) {\n      if (trie.find(x).first == 0) {\n        trie.add(x);\n\
    \      }\n    } else if (c == 1) {\n      if (trie.find(x).first != 0) {\n   \
    \     trie.del(x);\n      }\n    } else {\n      trie.operate_xor(x);\n      out(trie.min_element().first);\n\
    \      trie.operate_xor(x);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ \"../../competitive-template.hpp\"\n#include \"../../data-structure/binary-trie.hpp\"\
    \n\nvoid solve() {\n  ini(Q);\n  BinaryTrie<int, 30> trie;\n  rep(_, Q) {\n  \
    \  ini(c, x);\n    if (c == 0) {\n      if (trie.find(x).first == 0) {\n     \
    \   trie.add(x);\n      }\n    } else if (c == 1) {\n      if (trie.find(x).first\
    \ != 0) {\n        trie.del(x);\n      }\n    } else {\n      trie.operate_xor(x);\n\
    \      out(trie.min_element().first);\n      trie.operate_xor(x);\n    }\n  }\n\
    }"
  dependsOn:
  - competitive-template.hpp
  - data-structure/binary-trie.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-binary-trie.test.cpp
  requiredBy: []
  timestamp: '2020-08-18 23:32:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-binary-trie.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-binary-trie.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-binary-trie.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-binary-trie.test.cpp
---
