---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-indexed-tree.hpp
    title: Binary Indexed Tree(Fenwick Tree)
  - icon: ':heavy_check_mark:'
    path: data-structure/range-sum-range-add-bit.hpp
    title: data-structure/range-sum-range-add-bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp\"\n#define\
    \ PROBLEM \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#line 1 \"competitive-template.hpp\"\n#pragma region kyopro_template\n#define\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"data-structure/range-sum-range-add-bit.hpp\"\
    \nusing namespace std;\n\n#line 3 \"data-structure/binary-indexed-tree.hpp\"\n\
    using namespace std;\n\ntemplate <typename T>\nstruct BinaryIndexedTree {\n  int\
    \ N;\n  vector<T> data;\n\n  BinaryIndexedTree() = default;\n\n  BinaryIndexedTree(int\
    \ size) { init(size); }\n\n  void init(int size) {\n    N = size + 2;\n    data.assign(N\
    \ + 1, 0);\n  }\n\n  // get sum of [0,k]\n  T sum(int k) const {\n    if (k <\
    \ 0) return 0;  // return 0 if k < 0\n    T ret = 0;\n    for (++k; k > 0; k -=\
    \ k & -k) ret += data[k];\n    return ret;\n  }\n\n  // getsum of [l,r]\n  inline\
    \ T sum(int l, int r) const { return sum(r) - sum(l - 1); }\n\n  // get value\
    \ of k\n  inline T operator[](int k) const { return sum(k) - sum(k - 1); }\n\n\
    \  // data[k] += x\n  void add(int k, T x) {\n    for (++k; k < N; k += k & -k)\
    \ data[k] += x;\n  }\n\n  // range add x to [l,r]\n  void imos(int l, int r, T\
    \ x) {\n    add(l, x);\n    add(r + 1, -x);\n  }\n\n  // minimize i s.t. sum(i)\
    \ >= w\n  int lower_bound(T w) {\n    if (w <= 0) return 0;\n    int x = 0;\n\
    \    for (int k = 1 << __lg(N); k; k >>= 1) {\n      if (x + k <= N - 1 && data[x\
    \ + k] < w) {\n        w -= data[x + k];\n        x += k;\n      }\n    }\n  \
    \  return x;\n  }\n\n  // minimize i s.t. sum(i) > w\n  int upper_bound(T w) {\n\
    \    if (w < 0) return 0;\n    int x = 0;\n    for (int k = 1 << __lg(N); k; k\
    \ >>= 1) {\n      if (x + k <= N - 1 && data[x + k] <= w) {\n        w -= data[x\
    \ + k];\n        x += k;\n      }\n    }\n    return x;\n  }\n};\n\n/**\n * @brief\
    \ Binary Indexed Tree(Fenwick Tree)\n * @docs docs/data-structure/binary-indexed-tree.md\n\
    \ */\n#line 6 \"data-structure/range-sum-range-add-bit.hpp\"\n\ntemplate <typename\
    \ T>\nstruct RangeAddRangeSumBIT {\n  BinaryIndexedTree<T> a, b;\n  RangeAddRangeSumBIT(int\
    \ N) : a(N + 1), b(N + 1) {}\n\n  // add x to [l, r)\n  void add(int l, int r,\
    \ T x) {\n    a.add(l, x);\n    a.add(r, -x);\n    b.add(l, x * (1 - l));\n  \
    \  b.add(r, x * (r - 1));\n  }\n\n  // return sum of [l, r)\n  T sum(T l, T r)\
    \ {\n    --r, --l;\n    return a.sum(r) * r + b.sum(r) - a.sum(l) * l - b.sum(l);\n\
    \  }\n};\n#line 6 \"verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp\"\n\nvoid solve()\
    \ {\n  ini(N, Q);\n  RangeAddRangeSumBIT<ll> bit(N);\n  rep(_, Q) {\n    ini(c);\n\
    \    if (c == 0) {\n      ini(s, t, x);\n      s--;\n      bit.add(s, t, x);\n\
    \    } else {\n      ini(s, t);\n      s--;\n      out(bit.sum(s, t));\n    }\n\
    \  }\n}\n"
  code: "#define PROBLEM \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#include \"../../competitive-template.hpp\"\n#include \"../../data-structure/range-sum-range-add-bit.hpp\"\
    \n\nvoid solve() {\n  ini(N, Q);\n  RangeAddRangeSumBIT<ll> bit(N);\n  rep(_,\
    \ Q) {\n    ini(c);\n    if (c == 0) {\n      ini(s, t, x);\n      s--;\n    \
    \  bit.add(s, t, x);\n    } else {\n      ini(s, t);\n      s--;\n      out(bit.sum(s,\
    \ t));\n    }\n  }\n}"
  dependsOn:
  - competitive-template.hpp
  - data-structure/range-sum-range-add-bit.hpp
  - data-structure/binary-indexed-tree.hpp
  isVerificationFile: true
  path: verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp
  requiredBy: []
  timestamp: '2020-10-28 23:43:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp
- /verify/verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp.html
title: verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp
---