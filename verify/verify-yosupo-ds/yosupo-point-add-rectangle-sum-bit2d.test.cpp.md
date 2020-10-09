---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure-2d/dynamic-binary-indexed-tree-2d.hpp
    title: "\u52D5\u7684Binary Indexed Tree"
  - icon: ':heavy_check_mark:'
    path: data-structure/dynamic-binary-indexed-tree.hpp
    title: data-structure/dynamic-binary-indexed-tree.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/hash-map-variable-length.hpp
    title: "Hash Map(\u53EF\u5909\u9577\u7248)"
  - icon: ':heavy_check_mark:'
    path: misc/compress.hpp
    title: misc/compress.hpp
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-bit2d.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"data-structure/hash-map-variable-length.hpp\"\
    \nusing namespace std;\n\ntemplate <typename Key, typename Val>\nstruct HashMap\
    \ {\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  u32 cap, s;\n  Key*\
    \ keys;\n  Val* vals;\n  vector<bool> flag;\n  u64 r;\n  u32 shift;\n  Val DefaultValue;\n\
    \n  static u64 rng() {\n    u64 m = chrono::duration_cast<chrono::nanoseconds>(\n\
    \                chrono::high_resolution_clock::now().time_since_epoch())\n  \
    \              .count();\n    m ^= m >> 16;\n    m ^= m << 32;\n    return m;\n\
    \  }\n\n  void reallocate() {\n    cap <<= 1;\n    Key* k = new Key[cap];\n  \
    \  Val* v = new Val[cap];\n    vector<bool> f(cap);\n    u32 sh = shift - 1;\n\
    \    for (int i = 0; i < (int)flag.size(); i++) {\n      if (flag[i]) {\n    \
    \    u32 hash = (u64(keys[i]) * r) >> sh;\n        while (f[hash]) hash = (hash\
    \ + 1) & (cap - 1);\n        k[hash] = keys[i];\n        v[hash] = vals[i];\n\
    \        f[hash] = 1;\n      }\n    }\n    delete[](keys);\n    delete[](vals);\n\
    \    keys = k;\n    vals = v;\n    flag.swap(f);\n    --shift;\n  }\n\n  explicit\
    \ HashMap()\n      : cap(8),\n        s(0),\n        keys(new Key[cap]),\n   \
    \     vals(new Val[cap]),\n        flag(cap),\n        r(rng()),\n        shift(64\
    \ - __lg(cap)),\n        DefaultValue(Val()) {}\n\n  // copy constructor\n  HashMap(const\
    \ HashMap& obj) {\n    cap = obj.cap;\n    s = obj.s;\n    flag = obj.flag;\n\
    \    r = obj.r;\n    shift = obj.shift;\n    DefaultValue = obj.DefaultValue;\n\
    \    keys = new Key[cap];\n    vals = new Val[cap];\n    memcpy(keys, obj.keys,\
    \ sizeof(Key) * cap);\n    memcpy(vals, obj.vals, sizeof(Val) * cap);\n  }\n\n\
    \  ~HashMap() {\n    delete[](keys);\n    delete[](vals);\n  }\n\n  Val& operator[](const\
    \ Key& i) {\n    u32 hash = (u64(i) * r) >> shift;\n    while (true) {\n     \
    \ if (!flag[hash]) {\n        if (s + s / 4 >= cap) {\n          reallocate();\n\
    \          return (*this)[i];\n        }\n        keys[hash] = i;\n        flag[hash]\
    \ = 1;\n        ++s;\n        return vals[hash] = DefaultValue;\n      }\n   \
    \   if (keys[hash] == i) return vals[hash];\n      hash = (hash + 1) & (cap -\
    \ 1);\n    }\n  }\n\n  // exist -> return pointer of Val\n  // not exist -> return\
    \ nullptr\n  Val* find(const Key& i) const {\n    u32 hash = (u64(i) * r) >> shift;\n\
    \    while (true) {\n      if (!flag[hash]) return nullptr;\n      if (keys[hash]\
    \ == i) return &(vals[hash]);\n      hash = (hash + 1) & (cap - 1);\n    }\n \
    \ }\n\n  // return vector< pair<const Key&, val& > >\n  vector<pair<const Key&,\
    \ Val&>> enumerate() const {\n    vector<pair<const Key&, Val&>> ret;\n    for\
    \ (u32 i = 0; i < cap; ++i)\n      if (flag[i]) ret.emplace_back(keys[i], vals[i]);\n\
    \    return ret;\n  }\n\n  int size() const { return s; }\n\n  // set default_value\n\
    \  void set_default(const Val& val) { DefaultValue = val; }\n\n  // swap\n  friend\
    \ void swap(HashMap<Key, Val>& a, HashMap<Key, Val>& b) {\n    using std::swap;\n\
    \    swap(a.cap, b.cap);\n    swap(a.s, b.s);\n    swap(a.keys, b.keys);\n   \
    \ swap(a.vals, b.vals);\n    swap(a.flag, b.flag);\n    swap(a.r, b.r);\n    swap(a.shift,\
    \ b.shift);\n    swap(a.DefaultValue, b.DefaultValue);\n  }\n\n  HashMap<Key,\
    \ Val>& operator=(HashMap<Key, Val> b) {\n    swap(*this, b);\n    return *this;\n\
    \  }\n};\n\n/**\n * @brief Hash Map(\u53EF\u5909\u9577\u7248)\n * @docs docs/data-structure/hash-map.md\n\
    \ */\n#line 3 \"data-structure-2d/dynamic-binary-indexed-tree-2d.hpp\"\nusing\
    \ namespace std;\n\n#line 3 \"data-structure/dynamic-binary-indexed-tree.hpp\"\
    \nusing namespace std;\n\n#line 6 \"data-structure/dynamic-binary-indexed-tree.hpp\"\
    \n\ntemplate <typename S, typename T>\nstruct DynamicFenwickTree {\n  S N;\n \
    \ HashMap<S, T> data;\n  explicit DynamicFenwickTree() = default;\n  explicit\
    \ DynamicFenwickTree(S size) { N = size + 1; }\n\n  void add(S k, T x) {\n   \
    \ for (++k; k < N; k += k & -k) data[k] += x;\n  }\n\n  // [0, k)\n  T sum(S k)\
    \ const {\n    if (k < 0) return 0;\n    T ret = T();\n    for (; k > 0; k -=\
    \ k & -k) {\n      const T* p = data.find(k);\n      ret += p ? *p : T();\n  \
    \  }\n    return ret;\n  }\n\n  // [a, b)\n  T sum(S a, S b) const { return sum(b)\
    \ - sum(a); }\n\n  T operator[](S k) { return sum(k + 1) - sum(k); }\n\n  S lower_bound(T\
    \ w) {\n    if (w <= 0) return 0;\n    S x = 0;\n    for (S k = 1 << __lg(x);\
    \ k > 0; k >>= 1) {\n      if (x + k <= N - 1 && data[x + k] < w) {\n        w\
    \ -= data[x + k];\n        x += k;\n      }\n    }\n    return x;\n  }\n};\n#line\
    \ 6 \"data-structure-2d/dynamic-binary-indexed-tree-2d.hpp\"\n\ntemplate <typename\
    \ T>\nstruct DynamicFenwickTree2D {\n  using BIT = DynamicFenwickTree<int, T>;\n\
    \  int N, M;\n  vector<BIT*> bit;\n  DynamicFenwickTree2D() = default;\n  DynamicFenwickTree2D(int\
    \ n, int m) : N(n + 1), M(m) {\n    for (int _ = 0; _ < N; ++_) bit.push_back(new\
    \ BIT(M));\n  }\n  \n  void add(int i, int j, const T& x) {\n    for (++i; i <\
    \ N; i += i & -i) (*bit[i]).add(j, x);\n  }\n\n  // i = [0, n), j = [0, m)\n \
    \ T sum(int n, int m) const {\n    if (n < 0 || m < 0) return T();\n    T ret\
    \ = T();\n    for (; n; n -= n & -n) ret += (*bit[n]).sum(m);\n    return ret;\n\
    \  }\n\n  // i = [nl, nr), j = [ml, mr)\n  T sum(int nl, int ml, int nr, int mr)\
    \ const {\n    T ret = T();\n    while (nl != nr) {\n      if (nl < nr) {\n  \
    \      ret += (*bit[nr]).sum(ml, mr);\n        nr -= nr & -nr;\n      } else {\n\
    \        ret -= (*bit[nl]).sum(ml, mr);\n        nl -= nl & -nl;\n      }\n  \
    \  }\n    return ret;\n  }\n};\n\n/*\n * @brief \u52D5\u7684Binary Indexed Tree\n\
    \ * @docs docs/data-structure-2d/ds-2d.md\n */\n#line 3 \"misc/compress.hpp\"\n\
    using namespace std;\n\ntemplate<class T>\nstruct compress{\n  vector<T> xs;\n\
    \  compress(const vector<T>& v){\n    xs.reserve(v.size());\n    for(T x : v)\
    \ xs.push_back(x);\n    sort(xs.begin(),xs.end());\n    xs.erase(unique(xs.begin(),xs.end())\
    \ , xs.end());\n  }\n\n  int get(const T& x){\n    return lower_bound(xs.begin(),xs.end(),x)\
    \ - xs.begin();\n  }\n  int size(){\n    return xs.size();\n  }\n  T& operator[](int\
    \ i){\n    return xs[i];\n  }\n};\n#line 3 \"misc/fastio.hpp\"\nusing namespace\
    \ std;\n\nnamespace fastio {\nstatic constexpr int SZ = 1 << 17;\nchar ibuf[SZ],\
    \ obuf[SZ];\nint pil = 0, pir = 0, por = 0;\n\nstruct Pre {\n  char num[40000];\n\
    \  constexpr Pre() : num() {\n    for (int i = 0; i < 10000; i++) {\n      int\
    \ n = i;\n      for (int j = 3; j >= 0; j--) {\n        num[i * 4 + j] = n % 10\
    \ + '0';\n        n /= 10;\n      }\n    }\n  }\n} constexpr pre;\n\ninline void\
    \ load() {\n  memcpy(ibuf, ibuf + pil, pir - pil);\n  pir = pir - pil + fread(ibuf\
    \ + pir - pil, 1, SZ - pir + pil, stdin);\n  pil = 0;\n}\ninline void flush()\
    \ {\n  fwrite(obuf, 1, por, stdout);\n  por = 0;\n}\n\ninline void rd(char& c)\
    \ { c = ibuf[pil++]; }\ntemplate <typename T>\ninline void rd(T& x) {\n  if (pil\
    \ + 32 > pir) load();\n  char c;\n  do\n    c = ibuf[pil++];\n  while (c < '-');\n\
    \  bool minus = 0;\n  if (c == '-') {\n    minus = 1;\n    c = ibuf[pil++];\n\
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
    #line 8 \"verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-bit2d.test.cpp\"\
    \n\nvoid solve() {\n  int N, Q;\n  rd(N, Q);\n  vector<int> X(N), Y(N), W(N),\
    \ c(Q), s(Q), t(Q), u(Q), v(Q);\n  rep(i, N) rd(X[i], Y[i], W[i]);\n  rep(i, Q)\
    \ {\n    rd(c[i], s[i], t[i], u[i]);\n    if (c[i]) rd(v[i]);\n  }\n\n  vi xs{-1,\
    \ inf}, ys{-1, inf};\n  each(x, X) xs.push_back(x);\n  each(y, Y) ys.push_back(y);\n\
    \  rep(i, Q) {\n    if (!c[i]) {\n      xs.push_back(s[i]);\n      ys.push_back(t[i]);\n\
    \    }\n  }\n\n  auto zipx = compress<int>(xs);\n  auto zipy = compress<int>(ys);\n\
    \n  DynamicFenwickTree2D<ll> seg(zipx.size(), zipy.size());\n  rep(i, N) seg.add(zipx.get(X[i]),\
    \ zipy.get(Y[i]), W[i]);\n\n  rep(i, Q) {\n    if (c[i]) {\n      int nl = zipx.get(s[i]);\n\
    \      int ml = zipy.get(t[i]);\n      int nr = zipx.get(u[i]);\n      int mr\
    \ = zipy.get(v[i]);\n      out(seg.sum(nl, ml, nr, mr));\n    } else\n      seg.add(zipx.get(s[i]),\
    \ zipy.get(t[i]), u[i]);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../../competitive-template.hpp\"\n#include \"../../data-structure/hash-map-variable-length.hpp\"\
    \n#include \"../../data-structure-2d/dynamic-binary-indexed-tree-2d.hpp\"\n#include\
    \ \"../../misc/compress.hpp\"\n#include \"../../misc/fastio.hpp\"\n\nvoid solve()\
    \ {\n  int N, Q;\n  rd(N, Q);\n  vector<int> X(N), Y(N), W(N), c(Q), s(Q), t(Q),\
    \ u(Q), v(Q);\n  rep(i, N) rd(X[i], Y[i], W[i]);\n  rep(i, Q) {\n    rd(c[i],\
    \ s[i], t[i], u[i]);\n    if (c[i]) rd(v[i]);\n  }\n\n  vi xs{-1, inf}, ys{-1,\
    \ inf};\n  each(x, X) xs.push_back(x);\n  each(y, Y) ys.push_back(y);\n  rep(i,\
    \ Q) {\n    if (!c[i]) {\n      xs.push_back(s[i]);\n      ys.push_back(t[i]);\n\
    \    }\n  }\n\n  auto zipx = compress<int>(xs);\n  auto zipy = compress<int>(ys);\n\
    \n  DynamicFenwickTree2D<ll> seg(zipx.size(), zipy.size());\n  rep(i, N) seg.add(zipx.get(X[i]),\
    \ zipy.get(Y[i]), W[i]);\n\n  rep(i, Q) {\n    if (c[i]) {\n      int nl = zipx.get(s[i]);\n\
    \      int ml = zipy.get(t[i]);\n      int nr = zipx.get(u[i]);\n      int mr\
    \ = zipy.get(v[i]);\n      out(seg.sum(nl, ml, nr, mr));\n    } else\n      seg.add(zipx.get(s[i]),\
    \ zipy.get(t[i]), u[i]);\n  }\n}\n"
  dependsOn:
  - competitive-template.hpp
  - data-structure/hash-map-variable-length.hpp
  - data-structure-2d/dynamic-binary-indexed-tree-2d.hpp
  - data-structure/dynamic-binary-indexed-tree.hpp
  - misc/compress.hpp
  - misc/fastio.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-bit2d.test.cpp
  requiredBy: []
  timestamp: '2020-10-05 01:14:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-bit2d.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-bit2d.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-bit2d.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-bit2d.test.cpp
---