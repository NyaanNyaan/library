---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: segment-tree/li-chao-tree.hpp
    title: segment-tree/li-chao-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\n\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"segment-tree/li-chao-tree.hpp\"\
    \nusing namespace std;\n\ntemplate <typename T, T INF>\nstruct LiChaoTree {\n\
    \  struct Line {\n    T slope, intercept;\n    Line(T slope, T intercept) : slope(slope),\
    \ intercept(intercept) {}\n    inline T get(T x) const { return slope * x + intercept;\
    \ }\n    inline bool over(const Line &other, const T &x) const {\n      return\
    \ get(x) < other.get(x);\n    }\n  };\n\n  // remind \u30BB\u30B0\u6728\u306F\
    0-indexed\u306E\u5B9F\u88C5\n  vector<T> xset;\n  vector<Line> seg;\n  int _size;\n\
    \n  // \u5F15\u6570x\u306B\u306Fx\u5EA7\u6A19\u306E\u96C6\u5408\u3092\u5165\u308C\
    \u308B\n  LiChaoTree(const vector<T> &x) : xset(x) {\n    sort(xset.begin(), xset.end());\n\
    \    xset.erase(unique(xset.begin(), xset.end()), xset.end());\n    _size = 1;\n\
    \    while (_size < (int)xset.size()) _size <<= 1;\n    while ((int)xset.size()\
    \ < _size) xset.push_back(xset.back() + 1);\n    seg.assign(2 * _size, Line(0,\
    \ INF));\n  }\n\n  // \u4EE5\u4E0A xset[max]\u4EE5\u4E0B\u3067\u3042\u308B\u3053\
    \u3068\u3092\u4EEE\u5B9A\n  int get_more_idx(T k) {\n    return lower_bound(xset.begin(),\
    \ xset.end(), k) - xset.begin();\n  }\n  // \u4EE5\u4E0B xset[0]\u4EE5\u4E0A\u3067\
    \u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\n  int get_less_idx(T k) {\n    int\
    \ ret = upper_bound(xset.begin(), xset.end(), k) - xset.begin();\n    return max(0,\
    \ ret - 1);\n  }\n\n  // \u5185\u90E8\u7528\n  void inner_update(T a, T b, int\
    \ left, int right, int seg_idx) {\n    Line line(a, b);\n    while (1) {\n   \
    \   int mid = (left + right) >> 1;\n      bool l_over = line.over(seg[seg_idx],\
    \ xset[left]);\n      bool r_over = line.over(seg[seg_idx], xset[right - 1]);\n\
    \      if (l_over == r_over) {\n        if (l_over) swap(seg[seg_idx], line);\n\
    \        return;\n      }\n      bool m_over = line.over(seg[seg_idx], xset[mid]);\n\
    \      if (m_over) swap(seg[seg_idx], line);\n      if (l_over != m_over)\n  \
    \      seg_idx = (seg_idx << 1), right = mid;\n      else\n        seg_idx = (seg_idx\
    \ << 1) | 1, left = mid;\n    }\n  }\n\n  // \u5185\u90E8\u7528\n  void inner_update(T\
    \ a, T b, int seg_idx) {\n    int left, right;\n    int upper_bit = 31 - __builtin_clz(seg_idx);\n\
    \    left = (_size >> upper_bit) * (seg_idx - (1 << upper_bit));\n    right =\
    \ left + (_size >> upper_bit);\n    inner_update(a, b, left, right, seg_idx);\n\
    \  }\n\n  // y = ax + b\u306A\u308B\u76F4\u7DDA\u3092\u8FFD\u52A0\n  void update(T\
    \ a, T b) { inner_update(a, b, 0, _size, 1); }\n\n  // \u9589\u533A\u9593x in\
    \ [left , right]\u306B\u7DDA\u5206y = ax + b\u3092\u8FFD\u52A0\u3059\u308B\u30AF\
    \u30A8\u30EA\n  void update_segment(T a, T b, T low, T high) {\n    int left =\
    \ get_more_idx(low) + _size;\n    int right = get_less_idx(high) + _size + 1;\n\
    \    for (; left < right; left >>= 1, right >>= 1) {\n      if (left & 1) inner_update(a,\
    \ b, left++);\n      if (right & 1) inner_update(a, b, --right);\n    }\n  }\n\
    \n  T inner_query(int x, int segidx) {\n    T ret = seg[segidx].get(x);\n    while\
    \ (segidx > 1) {\n      segidx = segidx >> 1;\n      ret = min(ret, seg[segidx].get(x));\n\
    \    }\n    return ret;\n  }\n\n  // x = xset[k]\u306A\u308B\u70B9\u306B\u304A\
    \u3051\u308B\u6700\u5C0F\u5024\u30AF\u30A8\u30EA\n  T query_idx(int k) {\n   \
    \ const T x = xset[k];\n    k += _size;\n    return inner_query(x, k);\n  }\n\n\
    \  // x\u306B\u304A\u3051\u308B\u6700\u5C0F\u30AF\u30A8\u30EA\n  T query(T x)\
    \ { return query_idx(get_more_idx(x)); }\n};\n#line 5 \"verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp\"\
    \n\nvoid solve() {\n  ini(N, Q);\n  vl a(N), b(N), l(N), r(N);\n  in4(l, r, a,\
    \ b);\n  vl c(Q), d(Q), e(Q), f(Q), g(Q);\n  vl xs;\n  rep(i, Q) {\n    in(c[i]);\n\
    \    if (c[i])\n      in(d[i]), xs.pb(d[i]);\n    else\n      in(d[i], e[i], f[i],\
    \ g[i]);\n  }\n  xs.pb(-inf);\n  xs.pb(inf);\n  LiChaoTree<ll, infLL> lichao(xs);\n\
    \  rep(_, N) lichao.update_segment(a[_], b[_], l[_], r[_] - 1);\n\n  rep(i, Q)\
    \ {\n    if (c[i]) {\n      ll ans = lichao.query(d[i]);\n      if (ans == infLL)\n\
    \        out(\"INFINITY\");\n      else\n        out(ans);\n    } else {\n   \
    \   lichao.update_segment(f[i], g[i], d[i], e[i] - 1);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    \n#include \"../../competitive-template.hpp\"\n#include \"../../segment-tree/li-chao-tree.hpp\"\
    \n\nvoid solve() {\n  ini(N, Q);\n  vl a(N), b(N), l(N), r(N);\n  in4(l, r, a,\
    \ b);\n  vl c(Q), d(Q), e(Q), f(Q), g(Q);\n  vl xs;\n  rep(i, Q) {\n    in(c[i]);\n\
    \    if (c[i])\n      in(d[i]), xs.pb(d[i]);\n    else\n      in(d[i], e[i], f[i],\
    \ g[i]);\n  }\n  xs.pb(-inf);\n  xs.pb(inf);\n  LiChaoTree<ll, infLL> lichao(xs);\n\
    \  rep(_, N) lichao.update_segment(a[_], b[_], l[_], r[_] - 1);\n\n  rep(i, Q)\
    \ {\n    if (c[i]) {\n      ll ans = lichao.query(d[i]);\n      if (ans == infLL)\n\
    \        out(\"INFINITY\");\n      else\n        out(ans);\n    } else {\n   \
    \   lichao.update_segment(f[i], g[i], d[i], e[i] - 1);\n    }\n  }\n}"
  dependsOn:
  - competitive-template.hpp
  - segment-tree/li-chao-tree.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp
  requiredBy: []
  timestamp: '2020-08-02 17:27:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp
---
