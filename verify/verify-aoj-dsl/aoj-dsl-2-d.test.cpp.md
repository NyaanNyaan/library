---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: segment-tree/range-update-range-sum-lazyseg.hpp
    title: segment-tree/range-update-range-sum-lazyseg.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
  bundledCode: "#line 1 \"verify/verify-aoj-dsl/aoj-dsl-2-d.test.cpp\"\n#define PROBLEM\
    \ \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\n\
    \n#line 1 \"competitive-template.hpp\"\n#pragma region kyopro_template\n#define\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"segment-tree/range-update-range-sum-lazyseg.hpp\"\
    \nusing namespace std;\n\ntemplate <typename E, E UNUSED_VALUE>\nstruct UpdateSum_LazySegmentTree\
    \ {\n  int n, height;\n  using T = pair<E, E>;\n  T f(T a, T b) { return T(a.first\
    \ + b.first, a.second + b.second); };\n  T g(T a, E b) { return T(b * a.second,\
    \ a.second); };\n  E h(E, E b) { return b; };\n  T ti = P(0, 0);\n  E ei = UNUSED_VALUE;\n\
    \  vector<T> dat;\n  vector<E> laz;\n\n  UpdateSum_LazySegmentTree(const vector<E>\
    \ &v) { build(v); }\n\n  void init(int n_) {\n    n = 1;\n    height = 0;\n  \
    \  while (n < n_) n <<= 1, height++;\n    dat.assign(2 * n, ti);\n    laz.assign(2\
    \ * n, ei);\n  }\n\n  void build(const vector<E> &v) {\n    int n_ = v.size();\n\
    \    init(n_);\n    for (int i = 0; i < n_; i++) dat[n + i] = T(v[i], 1);\n  \
    \  for (int i = n - 1; i; i--)\n      dat[i] = f(dat[(i << 1) | 0], dat[(i <<\
    \ 1) | 1]);\n  }\n\n  inline T reflect(int k) { return laz[k] == ei ? dat[k] :\
    \ g(dat[k], laz[k]); }\n\n  inline void propagate(int k) {\n    if (laz[k] ==\
    \ ei) return;\n    laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);\n    laz[(k\
    \ << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);\n    dat[k] = reflect(k);\n    laz[k]\
    \ = ei;\n  }\n\n  inline void thrust(int k) {\n    for (int i = height; i; i--)\
    \ propagate(k >> i);\n  }\n\n  inline void recalc(int k) {\n    while (k >>= 1)\
    \ dat[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));\n  }\n\n  void update(int\
    \ a, int b, E x) {\n    if (a >= b) return;\n    thrust(a += n);\n    thrust(b\
    \ += n - 1);\n    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n    \
    \  if (l & 1) laz[l] = h(laz[l], x), l++;\n      if (r & 1) --r, laz[r] = h(laz[r],\
    \ x);\n    }\n    recalc(a);\n    recalc(b);\n  }\n\n  void set_val(int a, T x)\
    \ {\n    thrust(a += n);\n    dat[a] = x;\n    laz[a] = ei;\n    recalc(a);\n\
    \  }\n\n  E query(int a, int b) {\n    if (a >= b) return ti.first;\n    thrust(a\
    \ += n);\n    thrust(b += n - 1);\n    T vl = ti, vr = ti;\n    for (int l = a,\
    \ r = b + 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) vl = f(vl, reflect(l++));\n\
    \      if (r & 1) vr = f(reflect(--r), vr);\n    }\n    return f(vl, vr).first;\n\
    \  }\n};\n#line 6 \"verify/verify-aoj-dsl/aoj-dsl-2-d.test.cpp\"\n\nvoid solve()\
    \ {\n  ini(N, Q);\n  int I = (1LL << 31) - 1;\n  UpdateSum_LazySegmentTree<ll,\
    \ infLL> seg{vl(N, I)};\n  rep(_, Q) {\n    ini(c);\n    if (c == 0) {\n     \
    \ ini(s, t, x);\n      t++;\n      seg.update(s, t, x);\n    } else {\n      ini(i);\n\
    \      out(seg.query(i, i + 1));\n    }\n  }\n}\n"
  code: "#define PROBLEM \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n\n#include \"../../competitive-template.hpp\"\n#include \"../../segment-tree/range-update-range-sum-lazyseg.hpp\"\
    \n\nvoid solve() {\n  ini(N, Q);\n  int I = (1LL << 31) - 1;\n  UpdateSum_LazySegmentTree<ll,\
    \ infLL> seg{vl(N, I)};\n  rep(_, Q) {\n    ini(c);\n    if (c == 0) {\n     \
    \ ini(s, t, x);\n      t++;\n      seg.update(s, t, x);\n    } else {\n      ini(i);\n\
    \      out(seg.query(i, i + 1));\n    }\n  }\n}"
  dependsOn:
  - competitive-template.hpp
  - segment-tree/range-update-range-sum-lazyseg.hpp
  isVerificationFile: true
  path: verify/verify-aoj-dsl/aoj-dsl-2-d.test.cpp
  requiredBy: []
  timestamp: '2020-08-30 00:52:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-aoj-dsl/aoj-dsl-2-d.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-aoj-dsl/aoj-dsl-2-d.test.cpp
- /verify/verify/verify-aoj-dsl/aoj-dsl-2-d.test.cpp.html
title: verify/verify-aoj-dsl/aoj-dsl-2-d.test.cpp
---
