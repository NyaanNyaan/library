---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/integer-geometry.hpp
    title: geometry/integer-geometry.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  bundledCode: "#line 1 \"verify/verify-yosupo-other/yosupo-argument-sort.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\n\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"geometry/integer-geometry.hpp\"\
    \nusing namespace std;\n\nstruct Point {\n  using T = long long;\n  T x, y;\n\
    \  Point() : x(0), y(0) {}\n  Point(T x_, T y_) : x(x_), y(y_) {}\n\n  Point &operator+=(const\
    \ Point &p) {\n    this->x += p.x;\n    this->y += p.y;\n    return *this;\n \
    \ }\n\n  Point &operator-=(const Point &p) {\n    this->x -= p.x;\n    this->y\
    \ -= p.y;\n    return *this;\n  }\n\n  int pos() const {\n    if (y < 0) return\
    \ -1;\n    if (y == 0 && 0 <= x) return 0;\n    return 1;\n  }\n\n  Point operator+(const\
    \ Point &p) const { return Point(*this) += p; }\n  Point operator-(const Point\
    \ &p) const { return Point(*this) -= p; }\n  Point operator-() const { return\
    \ Point(-this->x, -this->y); }\n  bool operator==(const Point &p) const { return\
    \ x == p.x && y == p.y; }\n  bool operator!=(const Point &p) const { return x\
    \ != p.x || y != p.y; }\n  bool operator<(const Point &p) const { return x ==\
    \ p.x ? y < p.y : x < p.x; }\n\n  friend istream &operator>>(istream &is, Point\
    \ &p) {\n    cin >> p.x >> p.y;\n    return is;\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const Point &p) {\n    os << p.x << \" \" << p.y;\n    return os;\n  }\n\
    };\nusing Points = vector<Point>;\n\nPoint::T dot(const Point &a, const Point\
    \ &b) { return a.x * b.x + a.y * b.y; }\nPoint::T cross(const Point &a, const\
    \ Point &b) { return a.x * b.y - a.y * b.x; }\n\n// sort by argument (-Pi ~ Pi)\n\
    void ArgumentSort(Points &v) {\n  sort(begin(v), end(v), [](Point a, Point b)\
    \ {\n    if (a.pos() != b.pos()) return a.pos() < b.pos();\n    return cross(a,\
    \ b) > 0;\n  });\n}\n\n// 1 ... counterclockwise / 0 straight / -1 clockwise\n\
    int ccw(const Point &a, const Point &b, const Point &c) {\n  ll t = cross(b -\
    \ a, c - a);\n  return t < 0 ? -1 : t == 0 ? 0 : 1;\n}\n\n// v must have sorted\
    \ by x-coordinate\nPoints LowerHull(const Points &ps) {\n  int N = (int)ps.size();\n\
    \  for (int i = 0; i < N - 1; i++) assert(ps[i].x <= ps[i + 1].x);\n  if (N <=\
    \ 2) return ps;\n  Points convex(N);\n  int k = 0;\n  for (int i = 0; i < N; convex[k++]\
    \ = ps[i++]) {\n    while (k >= 2 && ccw(convex[k - 2], convex[k - 1], ps[i])\
    \ <= 0) --k;\n  }\n  convex.resize(k);\n  return convex;\n}\n\nPoints UpperHull(const\
    \ Points &ps) {\n  int N = (int)ps.size();\n  for (int i = 0; i < N - 1; i++)\
    \ assert(ps[i].x <= ps[i + 1].x);\n  if (N <= 2) return ps;\n  Points convex(N);\n\
    \  int k = 0;\n  for (int i = 0; i < N; convex[k++] = ps[i++]) {\n    while (k\
    \ >= 2 && ccw(convex[k - 2], convex[k - 1], ps[i]) >= 0) --k;\n  }\n  convex.resize(k);\n\
    \  return convex;\n}\n\nPoints ConvexHull(const Points &ps) {\n  int N = (int)ps.size();\n\
    \  for (int i = 0; i < N - 1; i++) assert(ps[i].x <= ps[i + 1].x);\n  if (N <=\
    \ 2) return ps;\n  Points convex(2 * N);\n  int k = 0;\n  for (int i = 0; i <\
    \ N; convex[k++] = ps[i++]) {\n    while (k >= 2 && ccw(convex[k - 2], convex[k\
    \ - 1], ps[i]) <= 0) --k;\n  }\n  for (int i = N - 2, t = k + 1; i >= 0; convex[k++]\
    \ = ps[i--]) {\n    while (k >= t && ccw(convex[k - 2], convex[k - 1], ps[i])\
    \ <= 0) --k;\n  }\n  convex.resize(k - 1);\n  return convex;\n}\n#line 5 \"verify/verify-yosupo-other/yosupo-argument-sort.test.cpp\"\
    \n\nvoid solve() {\n  ini(N);\n  Points ps(N);\n  in(ps);\n  ArgumentSort(ps);\n\
    \  each(p, ps) out(p);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n\n#include \"../../competitive-template.hpp\"\n#include \"../../geometry/integer-geometry.hpp\"\
    \n\nvoid solve() {\n  ini(N);\n  Points ps(N);\n  in(ps);\n  ArgumentSort(ps);\n\
    \  each(p, ps) out(p);\n}"
  dependsOn:
  - competitive-template.hpp
  - geometry/integer-geometry.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-other/yosupo-argument-sort.test.cpp
  requiredBy: []
  timestamp: '2020-08-07 18:12:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-other/yosupo-argument-sort.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-other/yosupo-argument-sort.test.cpp
- /verify/verify/verify-yosupo-other/yosupo-argument-sort.test.cpp.html
title: verify/verify-yosupo-other/yosupo-argument-sort.test.cpp
---
