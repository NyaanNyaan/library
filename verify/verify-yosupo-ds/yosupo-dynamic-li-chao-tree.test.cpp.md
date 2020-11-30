---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/hash-map-variable-length.hpp
    title: "Hash Map(\u53EF\u5909\u9577\u7248)"
  - icon: ':heavy_check_mark:'
    path: segment-tree/dynamic-li-chao-tree.hpp
    title: segment-tree/dynamic-li-chao-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-dynamic-li-chao-tree.test.cpp\"\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"segment-tree/dynamic-li-chao-tree.hpp\"\
    \nusing namespace std;\n\n#line 3 \"data-structure/hash-map-variable-length.hpp\"\
    \nusing namespace std;\n\ntemplate <typename Key, typename Val>\nstruct HashMap\
    \ {\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  u32 cap, s;\n  vector<Key>\
    \ keys;\n  vector<Val> vals;\n  vector<bool> flag;\n  u64 r;\n  u32 shift;\n \
    \ Val DefaultValue;\n\n  static u64 rng() {\n    u64 m = chrono::duration_cast<chrono::nanoseconds>(\n\
    \                chrono::high_resolution_clock::now().time_since_epoch())\n  \
    \              .count();\n    m ^= m >> 16;\n    m ^= m << 32;\n    return m;\n\
    \  }\n\n  void reallocate() {\n    cap <<= 1;\n    vector<Key> k(cap);\n    vector<Val>\
    \ v(cap);\n    vector<bool> f(cap);\n    u32 sh = shift - 1;\n    for (int i =\
    \ 0; i < (int)flag.size(); i++) {\n      if (flag[i]) {\n        u32 hash = (u64(keys[i])\
    \ * r) >> sh;\n        while (f[hash]) hash = (hash + 1) & (cap - 1);\n      \
    \  k[hash] = keys[i];\n        v[hash] = vals[i];\n        f[hash] = 1;\n    \
    \  }\n    }\n    keys.swap(k);\n    vals.swap(v);\n    flag.swap(f);\n    --shift;\n\
    \  }\n\n  explicit HashMap()\n      : cap(8),\n        s(0),\n        keys(cap),\n\
    \        vals(cap),\n        flag(cap),\n        r(rng()),\n        shift(64 -\
    \ __lg(cap)),\n        DefaultValue(Val()) {}\n\n  Val& operator[](const Key&\
    \ i) {\n    u32 hash = (u64(i) * r) >> shift;\n    while (true) {\n      if (!flag[hash])\
    \ {\n        if (s + s / 4 >= cap) {\n          reallocate();\n          return\
    \ (*this)[i];\n        }\n        keys[hash] = i;\n        flag[hash] = 1;\n \
    \       ++s;\n        return vals[hash] = DefaultValue;\n      }\n      if (keys[hash]\
    \ == i) return vals[hash];\n      hash = (hash + 1) & (cap - 1);\n    }\n  }\n\
    \n  // exist -> return pointer of Val\n  // not exist -> return nullptr\n  const\
    \ Val* find(const Key& i) const {\n    u32 hash = (u64(i) * r) >> shift;\n   \
    \ while (true) {\n      if (!flag[hash]) return nullptr;\n      if (keys[hash]\
    \ == i) return &(vals[hash]);\n      hash = (hash + 1) & (cap - 1);\n    }\n \
    \ }\n\n  // return vector< pair<const Key&, val& > >\n  vector<pair<Key, Val>>\
    \ enumerate() const {\n    vector<pair<Key, Val>> ret;\n    for (u32 i = 0; i\
    \ < cap; ++i)\n      if (flag[i]) ret.emplace_back(keys[i], vals[i]);\n    return\
    \ ret;\n  }\n\n  int size() const { return s; }\n\n  // set default_value\n  void\
    \ set_default(const Val& val) { DefaultValue = val; }\n};\n\n/**\n * @brief Hash\
    \ Map(\u53EF\u5909\u9577\u7248)\n * @docs docs/data-structure/hash-map.md\n */\n\
    #line 6 \"segment-tree/dynamic-li-chao-tree.hpp\"\n\ntemplate <typename T, T INF>\n\
    struct DynamicLiChaoTree {\n  struct Line {\n    T slope, intercept;\n    Line()\
    \ : slope(0), intercept(INF) {}\n    Line(T slope, T intercept) : slope(slope),\
    \ intercept(intercept) {}\n    inline T get(T x) const { return slope * x + intercept;\
    \ }\n    inline bool over(const Line &other, const T &x) const {\n      return\
    \ get(x) < other.get(x);\n    }\n  };\n\n  // remind \u30BB\u30B0\u6728\u306F\
    1-indexed\u306E\u5B9F\u88C5\n  T xmin, xmax, _size;\n  HashMap<T, Line> seg;\n\
    \n  // [l , r]\u306B\u304A\u3051\u308BLi Chao Tree\n  DynamicLiChaoTree(T xmin,\
    \ T xmax) : xmin(xmin), xmax(xmax) {\n    _size = 1;\n    while (_size < xmax\
    \ - xmin + 1) _size <<= 1;\n  }\n\n private:\n  // \u5185\u90E8\u7528\u306E\u95A2\
    \u6570\n  void update(T a, T b, T left, T right, T seg_idx) {\n    Line line(a,\
    \ b);\n    while (1) {\n      T mid = (left + right) >> 1;\n      bool l_over\
    \ = line.over(seg[seg_idx], min(xmax, left + xmin));\n      bool r_over = line.over(seg[seg_idx],\
    \ min(xmax, right - 1 + xmin));\n      if (l_over == r_over) {\n        if (l_over)\
    \ swap(seg[seg_idx], line);\n        return;\n      }\n      bool m_over = line.over(seg[seg_idx],\
    \ min(xmax, mid + xmin));\n      if (m_over) swap(seg[seg_idx], line);\n     \
    \ if (l_over != m_over)\n        seg_idx = (seg_idx << 1), right = mid;\n    \
    \  else\n        seg_idx = (seg_idx << 1) | 1, left = mid;\n    }\n  }\n  // \u5185\
    \u90E8\u7528\u306E\u95A2\u6570\n  void update(T a, T b, T seg_idx) {\n    T left,\
    \ right;\n    T upper_bit = 63 - __builtin_clzll(seg_idx);\n    left = (_size\
    \ >> upper_bit) * (seg_idx - (1 << upper_bit));\n    right = left + (_size >>\
    \ upper_bit);\n    update(a, b, left, right, seg_idx);\n  }\n\n public:\n  //\
    \ y = ax + b\u306A\u308B\u76F4\u7DDA\u3092\u8FFD\u52A0\n  void update(T a, T b)\
    \ { update(a, b, 0, _size, 1); }\n\n  // \u9589\u533A\u9593x in [left , right]\u306B\
    \u7DDA\u5206y = ax + b\u3092\u8FFD\u52A0\u3059\u308B\u30AF\u30A8\u30EA\n  void\
    \ update_line_segment(T a, T b, T left, T right) {\n    left -= xmin - _size,\
    \ right -= xmin - _size - 1;\n    for (; left < right; left >>= 1, right >>= 1)\
    \ {\n      if (left & 1) update(a, b, left++);\n      if (right & 1) update(a,\
    \ b, --right);\n    }\n  }\n\n  // x\u306B\u304A\u3051\u308B\u6700\u5C0F\u5024\
    \u30AF\u30A8\u30EA\n  T query(T x) {\n    T left = 0, right = _size, seg_idx =\
    \ 1, idx = x - xmin, ret = INF;\n    while (1) {\n      T cur = seg[seg_idx].get(x);\n\
    \      // \u7DDA\u5206\u8FFD\u52A0\u30AF\u30A8\u30EA\u304C\u306A\u3044\u5834\u5408\
    \u306F\u3053\u3053\u306E\u30B3\u30E1\u30F3\u30C8\u30A2\u30A6\u30C8\u3092\u5916\
    \u3057\u3066\u9AD8\u901F\u5316\u53EF\u80FD(1.5\u500D\u7A0B\u5EA6\uFF1F)\n    \
    \  // if(cur == INF) break;\n      ret = min(ret, cur);\n      if (left + 1 >=\
    \ right) break;\n      T mid = (left + right) >> 1;\n      if (idx < mid)\n  \
    \      seg_idx = (seg_idx << 1), right = mid;\n      else\n        seg_idx = (seg_idx\
    \ << 1) | 1, left = mid;\n    }\n    return ret;\n  }\n};\n#line 5 \"verify/verify-yosupo-ds/yosupo-dynamic-li-chao-tree.test.cpp\"\
    \n\nvoid solve() {\n  ini(N, Q);\n  DynamicLiChaoTree<ll, infLL> lichao(-1001001001,\
    \ 1001001001);\n  rep(i, N) {\n    inl(l, r, a, b);\n    lichao.update_line_segment(a,\
    \ b, l, r - 1);\n  }\n  rep(i, Q) {\n    inl(c);\n    if (c == 0) {\n      inl(l,\
    \ r, a, b);\n      lichao.update_line_segment(a, b, l, r - 1);\n    } else {\n\
    \      ini(x);\n      ll ans = lichao.query(x);\n      if (ans >= infLL)\n   \
    \     out(\"INFINITY\");\n      else\n        out(ans);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    \n#include \"../../competitive-template.hpp\"\n#include \"../../segment-tree/dynamic-li-chao-tree.hpp\"\
    \n\nvoid solve() {\n  ini(N, Q);\n  DynamicLiChaoTree<ll, infLL> lichao(-1001001001,\
    \ 1001001001);\n  rep(i, N) {\n    inl(l, r, a, b);\n    lichao.update_line_segment(a,\
    \ b, l, r - 1);\n  }\n  rep(i, Q) {\n    inl(c);\n    if (c == 0) {\n      inl(l,\
    \ r, a, b);\n      lichao.update_line_segment(a, b, l, r - 1);\n    } else {\n\
    \      ini(x);\n      ll ans = lichao.query(x);\n      if (ans >= infLL)\n   \
    \     out(\"INFINITY\");\n      else\n        out(ans);\n    }\n  }\n}"
  dependsOn:
  - competitive-template.hpp
  - segment-tree/dynamic-li-chao-tree.hpp
  - data-structure/hash-map-variable-length.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-dynamic-li-chao-tree.test.cpp
  requiredBy: []
  timestamp: '2020-11-19 22:42:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-dynamic-li-chao-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-dynamic-li-chao-tree.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-dynamic-li-chao-tree.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-dynamic-li-chao-tree.test.cpp
---
