---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure-2d/segment-tree-on-range-tree.hpp
    title: "\u9818\u57DF\u6728(Segment Tree)"
  - icon: ':heavy_check_mark:'
    path: misc/compress.hpp
    title: misc/compress.hpp
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: segment-tree/segment-tree.hpp
    title: segment-tree/segment-tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-dseg2d.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\
    \n#line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n#include\
    \ <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <initializer_list>\n#include <iomanip>\n\
    #include <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n\
    #include <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <streambuf>\n#include\
    \ <string>\n#include <tuple>\n#include <type_traits>\n#include <typeinfo>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include <vector>\n\
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
    \ t.size();\n}\n\ntemplate <typename T, typename U>\ninline bool amin(T &x, U\
    \ y) {\n  return (y < x) ? (x = y, true) : false;\n}\ntemplate <typename T, typename\
    \ U>\ninline bool amax(T &x, U y) {\n  return (x < y) ? (x = y, true) : false;\n\
    }\n\ntemplate <typename T>\ninline T Max(const vector<T> &v) {\n  return *max_element(begin(v),\
    \ end(v));\n}\ntemplate <typename T>\ninline T Min(const vector<T> &v) {\n  return\
    \ *min_element(begin(v), end(v));\n}\ntemplate <typename T>\ninline long long\
    \ Sum(const vector<T> &v) {\n  return accumulate(begin(v), end(v), 0LL);\n}\n\n\
    template <typename T>\nint lb(const vector<T> &v, const T &a) {\n  return lower_bound(begin(v),\
    \ end(v), a) - begin(v);\n}\ntemplate <typename T>\nint ub(const vector<T> &v,\
    \ const T &a) {\n  return upper_bound(begin(v), end(v), a) - begin(v);\n}\n\n\
    constexpr long long TEN(int n) {\n  long long ret = 1, x = 10;\n  for (; n; x\
    \ *= x, n >>= 1) ret *= (n & 1 ? x : 1);\n  return ret;\n}\n\ntemplate <typename\
    \ T, typename U>\npair<T, U> mkp(const T &t, const U &u) {\n  return make_pair(t,\
    \ u);\n}\n\ntemplate <typename T>\nvector<T> mkrui(const vector<T> &v, bool rev\
    \ = false) {\n  vector<T> ret(v.size() + 1);\n  if (rev) {\n    for (int i = int(v.size())\
    \ - 1; i >= 0; i--) ret[i] = v[i] + ret[i + 1];\n  } else {\n    for (int i =\
    \ 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];\n  }\n  return ret;\n\
    };\n\ntemplate <typename T>\nvector<T> mkuni(const vector<T> &v) {\n  vector<T>\
    \ ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(), ret.end()),\
    \ ret.end());\n  return ret;\n}\n\ntemplate <typename F>\nvector<int> mkord(int\
    \ N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n  sort(begin(ord),\
    \ end(ord), f);\n  return ord;\n}\n\ntemplate <typename T>\nvector<int> mkinv(vector<T>\
    \ &v) {\n  int max_val = *max_element(begin(v), end(v));\n  vector<int> inv(max_val\
    \ + 1, -1);\n  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;\n  return\
    \ inv;\n}\n\n}  // namespace Nyaan\n#line 58 \"template/template.hpp\"\n\n// bit\
    \ operation\n#line 1 \"template/bitop.hpp\"\nnamespace Nyaan {\n__attribute__((target(\"\
    popcnt\"))) inline int popcnt(const u64 &a) {\n  return _mm_popcnt_u64(a);\n}\n\
    inline int lsb(const u64 &a) {\n  return a ? __builtin_ctzll(a) : 64;\n}\ninline\
    \ int ctz(const u64 &a) {\n  return a ? __builtin_ctzll(a) : 64;\n}\ninline int\
    \ msb(const u64 &a) {\n  return a ? 63 - __builtin_clzll(a) : -1;\n}\ntemplate\
    \ <typename T>\ninline int gbit(const T &a, int i) {\n  return (a >> i) & 1;\n\
    }\ntemplate <typename T>\ninline void sbit(T &a, int i, bool b) {\n  a ^= (gbit(a,\
    \ i) == b ? 0 : (T(b) << i));\n}\nconstexpr long long PW(int n) { return 1LL <<\
    \ n; }\nconstexpr long long MSK(int n) { return (1LL << n) - 1; }\n}  // namespace\
    \ Nyaan\n#line 61 \"template/template.hpp\"\n\n// inout\n#line 1 \"template/inout.hpp\"\
    \nnamespace Nyaan {\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n  os << p.first << \" \" << p.second;\n  return\
    \ os;\n}\ntemplate <typename T, typename U>\nistream &operator>>(istream &is,\
    \ pair<T, U> &p) {\n  is >> p.first >> p.second;\n  return is;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n  int\
    \ s = (int)v.size();\n  for (int i = 0; i < s; i++) os << (i ? \" \" : \"\") <<\
    \ v[i];\n  return os;\n}\ntemplate <typename T>\nistream &operator>>(istream &is,\
    \ vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return is;\n}\n\nvoid in()\
    \ {}\ntemplate <typename T, class... U>\nvoid in(T &t, U &... u) {\n  cin >> t;\n\
    \  in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename T, class...\
    \ U, char sep = ' '>\nvoid out(const T &t, const U &... u) {\n  cout << t;\n \
    \ if (sizeof...(u)) cout << sep;\n  out(u...);\n}\n\nvoid outr() {}\ntemplate\
    \ <typename T, class... U, char sep = ' '>\nvoid outr(const T &t, const U &...\
    \ u) {\n  cout << t;\n  outr(u...);\n}\n\nstruct IoSetupNya {\n  IoSetupNya()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(15);\n    cerr << fixed << setprecision(7);\n  }\n} iosetupnya;\n\
    \n}  // namespace Nyaan\n#line 64 \"template/template.hpp\"\n\n// debug\n#line\
    \ 1 \"template/debug.hpp\"\nnamespace DebugImpl {\n\ntemplate <typename U, typename\
    \ = void>\nstruct is_specialize : false_type {};\ntemplate <typename U>\nstruct\
    \ is_specialize<\n    U, typename conditional<false, typename U::iterator, void>::type>\n\
    \    : true_type {};\ntemplate <typename U>\nstruct is_specialize<\n    U, typename\
    \ conditional<false, decltype(U::first), void>::type>\n    : true_type {};\ntemplate\
    \ <typename U>\nstruct is_specialize<U, enable_if_t<is_integral<U>::value, void>>\
    \ : true_type {\n};\n\nvoid dump(const char& t) { cerr << t; }\n\nvoid dump(const\
    \ string& t) { cerr << t; }\n\nvoid dump(const bool& t) { cerr << (t ? \"true\"\
    \ : \"false\"); }\n\ntemplate <typename U,\n          enable_if_t<!is_specialize<U>::value,\
    \ nullptr_t> = nullptr>\nvoid dump(const U& t) {\n  cerr << t;\n}\n\ntemplate\
    \ <typename T>\nvoid dump(const T& t, enable_if_t<is_integral<T>::value>* = nullptr)\
    \ {\n  string res;\n  if (t == Nyaan::inf) res = \"inf\";\n  if constexpr (is_signed<T>::value)\
    \ {\n    if (t == -Nyaan::inf) res = \"-inf\";\n  }\n  if constexpr (sizeof(T)\
    \ == 8) {\n    if (t == Nyaan::infLL) res = \"inf\";\n    if constexpr (is_signed<T>::value)\
    \ {\n      if (t == -Nyaan::infLL) res = \"-inf\";\n    }\n  }\n  if (res.empty())\
    \ res = to_string(t);\n  cerr << res;\n}\n\ntemplate <typename T, typename U>\n\
    void dump(const pair<T, U>&);\ntemplate <typename T>\nvoid dump(const pair<T*,\
    \ int>&);\n\ntemplate <typename T>\nvoid dump(const T& t,\n          enable_if_t<!is_void<typename\
    \ T::iterator>::value>* = nullptr) {\n  cerr << \"[ \";\n  for (auto it = t.begin();\
    \ it != t.end();) {\n    dump(*it);\n    cerr << (++it == t.end() ? \"\" : \"\
    , \");\n  }\n  cerr << \" ]\";\n}\n\ntemplate <typename T, typename U>\nvoid dump(const\
    \ pair<T, U>& t) {\n  cerr << \"( \";\n  dump(t.first);\n  cerr << \", \";\n \
    \ dump(t.second);\n  cerr << \" )\";\n}\n\ntemplate <typename T>\nvoid dump(const\
    \ pair<T*, int>& t) {\n  cerr << \"[ \";\n  for (int i = 0; i < t.second; i++)\
    \ {\n    dump(t.first[i]);\n    cerr << (i == t.second - 1 ? \"\" : \", \");\n\
    \  }\n  cerr << \" ]\";\n}\n\nvoid trace() { cerr << endl; }\ntemplate <typename\
    \ Head, typename... Tail>\nvoid trace(Head&& head, Tail&&... tail) {\n  cerr <<\
    \ \" \";\n  dump(head);\n  if (sizeof...(tail) != 0) cerr << \",\";\n  trace(forward<Tail>(tail)...);\n\
    }\n\n}  // namespace DebugImpl\n\n#ifdef NyaanDebug\n#define trc(...)        \
    \                    \\\n  do {                                      \\\n    cerr\
    \ << \"## \" << #__VA_ARGS__ << \" = \"; \\\n    DebugImpl::trace(__VA_ARGS__);\
    \          \\\n  } while (0)\n#else\n#define trc(...) (void(0))\n#endif\n#line\
    \ 67 \"template/template.hpp\"\n\n// macro\n#line 1 \"template/macro.hpp\"\n#define\
    \ each(x, v) for (auto&& x : v)\n#define each2(x, y, v) for (auto&& [x, y] : v)\n\
    #define all(v) (v).begin(), (v).end()\n#define rep(i, N) for (long long i = 0;\
    \ i < (long long)(N); i++)\n#define repr(i, N) for (long long i = (long long)(N)-1;\
    \ i >= 0; i--)\n#define rep1(i, N) for (long long i = 1; i <= (long long)(N);\
    \ i++)\n#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)\n\
    #define reg(i, a, b) for (long long i = (a); i < (b); i++)\n#define regr(i, a,\
    \ b) for (long long i = (b)-1; i >= (a); i--)\n#define fi first\n#define se second\n\
    #define ini(...)   \\\n  int __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define inl(...)\
    \         \\\n  long long __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define ins(...)\
    \      \\\n  string __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define in2(s, t)    \
    \                       \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n \
    \   in(s[i], t[i]);                         \\\n  }\n#define in3(s, t, u)    \
    \                    \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i],\
    \ t[i], u[i]);                   \\\n  }\n#define in4(s, t, u, v)            \
    \         \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i],\
    \ u[i], v[i]);             \\\n  }\n#define die(...)             \\\n  do {  \
    \                     \\\n    Nyaan::out(__VA_ARGS__); \\\n    return;       \
    \           \\\n  } while (0)\n#line 70 \"template/template.hpp\"\n\nnamespace\
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line 2 \"misc/compress.hpp\"\
    \n\ntemplate <class T>\nstruct compress {\n  vector<T> xs;\n  compress(const vector<T>&\
    \ v) {\n    xs.reserve(v.size());\n    for (T x : v) xs.push_back(x);\n    sort(xs.begin(),\
    \ xs.end());\n    xs.erase(unique(xs.begin(), xs.end()), xs.end());\n  }\n  int\
    \ get(const T& x) const {\n    return lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n\
    \  }\n  inline int operator()(const T& x) const { return get(x); }\n  T operator[](int\
    \ i) { return xs[i]; }\n  int size() const { return xs.size(); }\n};\n\n/**\n\
    \ * \u5EA7\u6A19\u5727\u7E2E\n */\n#line 2 \"misc/fastio.hpp\"\n\n#line 6 \"misc/fastio.hpp\"\
    \n\nusing namespace std;\n\nnamespace fastio {\nstatic constexpr int SZ = 1 <<\
    \ 17;\nchar ibuf[SZ], obuf[SZ];\nint pil = 0, pir = 0, por = 0;\n\nstruct Pre\
    \ {\n  char num[40000];\n  constexpr Pre() : num() {\n    for (int i = 0; i <\
    \ 10000; i++) {\n      int n = i;\n      for (int j = 3; j >= 0; j--) {\n    \
    \    num[i * 4 + j] = n % 10 + '0';\n        n /= 10;\n      }\n    }\n  }\n}\
    \ constexpr pre;\n\ninline void load() {\n  memcpy(ibuf, ibuf + pil, pir - pil);\n\
    \  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);\n  pil\
    \ = 0;\n}\ninline void flush() {\n  fwrite(obuf, 1, por, stdout);\n  por = 0;\n\
    }\n\ninline void skip_space() {\n  if (pil + 32 > pir) load();\n  while (ibuf[pil]\
    \ <= ' ') pil++;\n}\n\ninline void rd(char& c) {\n  if (pil + 32 > pir) load();\n\
    \  c = ibuf[pil++];\n}\ntemplate <typename T>\ninline void rd(T& x) {\n  if (pil\
    \ + 32 > pir) load();\n  char c;\n  do c = ibuf[pil++];\n  while (c < '-');\n\
    \  [[maybe_unused]] bool minus = false;\n  if constexpr (is_signed<T>::value ==\
    \ true) {\n    if (c == '-') minus = true, c = ibuf[pil++];\n  }\n  x = 0;\n \
    \ while (c >= '0') {\n    x = x * 10 + (c & 15);\n    c = ibuf[pil++];\n  }\n\
    \  if constexpr (is_signed<T>::value == true) {\n    if (minus) x = -x;\n  }\n\
    }\ninline void rd() {}\ntemplate <typename Head, typename... Tail>\ninline void\
    \ rd(Head& head, Tail&... tail) {\n  rd(head);\n  rd(tail...);\n}\n\ninline void\
    \ wt(char c) {\n  if (por > SZ - 32) flush();\n  obuf[por++] = c;\n}\ninline void\
    \ wt(bool b) { \n  if (por > SZ - 32) flush();\n  obuf[por++] = b ? '1' : '0';\
    \ \n}\ntemplate <typename T>\ninline void wt(T x) {\n  if (por > SZ - 32) flush();\n\
    \  if (!x) {\n    obuf[por++] = '0';\n    return;\n  }\n  if constexpr (is_signed<T>::value\
    \ == true) {\n    if (x < 0) obuf[por++] = '-', x = -x;\n  }\n  int i = 12;\n\
    \  char buf[16];\n  while (x >= 10000) {\n    memcpy(buf + i, pre.num + (x % 10000)\
    \ * 4, 4);\n    x /= 10000;\n    i -= 4;\n  }\n  if (x < 100) {\n    if (x < 10)\
    \ {\n      obuf[por] = '0' + x;\n      ++por;\n    } else {\n      uint32_t q\
    \ = (uint32_t(x) * 205) >> 11;\n      uint32_t r = uint32_t(x) - q * 10;\n   \
    \   obuf[por] = '0' + q;\n      obuf[por + 1] = '0' + r;\n      por += 2;\n  \
    \  }\n  } else {\n    if (x < 1000) {\n      memcpy(obuf + por, pre.num + (x <<\
    \ 2) + 1, 3);\n      por += 3;\n    } else {\n      memcpy(obuf + por, pre.num\
    \ + (x << 2), 4);\n      por += 4;\n    }\n  }\n  memcpy(obuf + por, buf + i +\
    \ 4, 12 - i);\n  por += 12 - i;\n}\n\ninline void wt() {}\ntemplate <typename\
    \ Head, typename... Tail>\ninline void wt(Head&& head, Tail&&... tail) {\n  wt(head);\n\
    \  wt(forward<Tail>(tail)...);\n}\ntemplate <typename... Args>\ninline void wtn(Args&&...\
    \ x) {\n  wt(forward<Args>(x)...);\n  wt('\\n');\n}\n\nstruct Dummy {\n  Dummy()\
    \ { atexit(flush); }\n} dummy;\n\n}  // namespace fastio\nusing fastio::rd;\n\
    using fastio::skip_space;\nusing fastio::wt;\nusing fastio::wtn;\n#line 2 \"data-structure-2d/segment-tree-on-range-tree.hpp\"\
    \n\n\n\n#line 2 \"segment-tree/segment-tree.hpp\"\n\n\n\ntemplate <typename T,\
    \ typename F>\nstruct SegmentTree {\n  int size;\n  vector<T> seg;\n  const F\
    \ f;\n  const T I;\n\n  SegmentTree(F _f, const T &I_) : size(0), f(_f), I(I_)\
    \ {}\n\n  SegmentTree(int N, F _f, const T &I_) : f(_f), I(I_) { init(N); }\n\n\
    \  SegmentTree(const vector<T> &v, F _f, T I_) : f(_f), I(I_) {\n    init(v.size());\n\
    \    for (int i = 0; i < (int)v.size(); i++) {\n      seg[i + size] = v[i];\n\
    \    }\n    build();\n  }\n\n  void init(int N) {\n    size = 1;\n    while (size\
    \ < N) size <<= 1;\n    seg.assign(2 * size, I);\n  }\n\n  void set(int k, T x)\
    \ { seg[k + size] = x; }\n\n  void build() {\n    for (int k = size - 1; k > 0;\
    \ k--) {\n      seg[k] = f(seg[2 * k], seg[2 * k + 1]);\n    }\n  }\n\n  void\
    \ update(int k, T x) {\n    k += size;\n    seg[k] = x;\n    while (k >>= 1) {\n\
    \      seg[k] = f(seg[2 * k], seg[2 * k + 1]);\n    }\n  }\n\n  void add(int k,\
    \ T x) {\n    k += size;\n    seg[k] += x;\n    while (k >>= 1) {\n      seg[k]\
    \ = f(seg[2 * k], seg[2 * k + 1]);\n    }\n  }\n\n  // query to [a, b)\n  T query(int\
    \ a, int b) {\n    T L = I, R = I;\n    for (a += size, b += size; a < b; a >>=\
    \ 1, b >>= 1) {\n      if (a & 1) L = f(L, seg[a++]);\n      if (b & 1) R = f(seg[--b],\
    \ R);\n    }\n    return f(L, R);\n  }\n\n  T &operator[](const int &k) { return\
    \ seg[k + size]; }\n\n  template <typename C>\n  int find_subtree(int a, const\
    \ C &check, T &M, bool type) {\n    while (a < size) {\n      T nxt = type ? f(seg[2\
    \ * a + type], M) : f(M, seg[2 * a + type]);\n      if (check(nxt))\n        a\
    \ = 2 * a + type;\n      else\n        M = nxt, a = 2 * a + 1 - type;\n    }\n\
    \    return a - size;\n  }\n\n  template <typename C>\n  int find_first(int a,\
    \ const C &check) {\n    T L = I;\n    if (a <= 0) {\n      if (check(f(L, seg[1])))\
    \ return find_subtree(1, check, L, false);\n      return -1;\n    }\n    int b\
    \ = size;\n    for (a += size, b += size; a < b; a >>= 1, b >>= 1) {\n      if\
    \ (a & 1) {\n        T nxt = f(L, seg[a]);\n        if (check(nxt)) return find_subtree(a,\
    \ check, L, false);\n        L = nxt;\n        ++a;\n      }\n    }\n    return\
    \ -1;\n  }\n\n  template <typename C>\n  int find_last(int b, const C &check)\
    \ {\n    T R = I;\n    if (b >= size) {\n      if (check(f(seg[1], R))) return\
    \ find_subtree(1, check, R, true);\n      return -1;\n    }\n    int a = size;\n\
    \    for (b += size; a < b; a >>= 1, b >>= 1) {\n      if (b & 1) {\n        T\
    \ nxt = f(seg[--b], R);\n        if (check(nxt)) return find_subtree(b, check,\
    \ R, true);\n        R = nxt;\n      }\n    }\n    return -1;\n  }\n};\n#line\
    \ 6 \"data-structure-2d/segment-tree-on-range-tree.hpp\"\n\n// S ... index_type\n\
    // T ... value_type\n// F ... function_type\ntemplate <typename S, typename T,\
    \ typename F>\nstruct RangeTree {\n  using Seg = SegmentTree<T, F>;\n  using P\
    \ = pair<S, S>;\n\n  S N, M;\n  const F f;\n  T ti;\n  vector<SegmentTree<T, F>>\
    \ seg;\n  vector<vector<S>> ys;\n  vector<P> ps;\n\n  RangeTree(const F& f_, const\
    \ T& ti_) : f(f_), ti(ti_) {}\n\n  void add_point(S x, S y) { ps.push_back(make_pair(x,\
    \ y)); }\n\n  void build() {\n    sort(begin(ps), end(ps));\n    ps.erase(unique(begin(ps),\
    \ end(ps)), end(ps));\n    N = ps.size();\n    for (int i = 0; i < 2 * N; ++i)\
    \ seg.push_back(Seg{f, ti});\n    ys.resize(2 * N);\n    for (int i = 0; i < N;\
    \ ++i) {\n      ys[i + N].push_back(ps[i].second);\n      seg[i + N].init(1);\n\
    \    }\n    for (int i = N - 1; i > 0; --i) {\n      ys[i].resize(ys[i << 1].size()\
    \ + ys[(i << 1) | 1].size());\n      merge(begin(ys[(i << 1) | 0]), end(ys[(i\
    \ << 1) | 0]),\n            begin(ys[(i << 1) | 1]), end(ys[(i << 1) | 1]), begin(ys[i]));\n\
    \      ys[i].erase(unique(begin(ys[i]), end(ys[i])), end(ys[i]));\n      seg[i].init(ys[i].size());\n\
    \    }\n  }\n\n  int id(S x) const {\n    return lower_bound(\n              \
    \ begin(ps), end(ps), make_pair(x, S()),\n               [](const P& a, const\
    \ P& b) { return a.first < b.first; }) -\n           begin(ps);\n  }\n\n  int\
    \ id(int i, S y) const {\n    return lower_bound(begin(ys[i]), end(ys[i]), y)\
    \ - begin(ys[i]);\n  }\n\n  void add(S x, S y, T a) {\n    int i = lower_bound(begin(ps),\
    \ end(ps), make_pair(x, y)) - begin(ps);\n    assert(ps[i] == make_pair(x, y));\n\
    \    for (i += N; i; i >>= 1) seg[i].add(id(i, y), a);\n  }\n\n  T sum(S xl, S\
    \ yl, S xr, S yr) {\n    T L = ti, R = ti;\n    int a = id(xl), b = id(xr);\n\
    \    for (a += N, b += N; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) L = f(L,\
    \ seg[a].query(id(a, yl), id(a, yr))), ++a;\n      if (b & 1) --b, R = f(seg[b].query(id(b,\
    \ yl), id(b, yr)), R);\n    }\n    return f(L, R);\n  }\n};\n\n/*\n * @brief \u9818\
    \u57DF\u6728(Segment Tree)\n * @docs docs/data-structure-2d/ds-2d.md\n */\n#line\
    \ 7 \"verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-dseg2d.test.cpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve() {\n  auto f = [](ll a, ll b) {\
    \ return a + b; };\n\n  RangeTree<int, ll, decltype(f)> rtree(f, 0);\n\n  int\
    \ N, Q;\n  rd(N, Q);\n  vector<int> X(N), Y(N), W(N), c(Q), s(Q), t(Q), u(Q),\
    \ v(Q);\n  rep(i, N) {\n    rd(X[i], Y[i], W[i]);\n    rtree.add_point(X[i], Y[i]);\n\
    \  }\n  rep(i, Q) {\n    rd(c[i], s[i], t[i], u[i]);\n    if (c[i])\n      rd(v[i]);\n\
    \    else\n      rtree.add_point(s[i], t[i]);\n  }\n\n  rtree.build();\n  rep(i,\
    \ N) rtree.add(X[i], Y[i], W[i]);\n  rep(i, Q) {\n    if (c[i]) {\n      out(rtree.sum(s[i],\
    \ t[i], u[i], v[i]));\n    } else\n      rtree.add(s[i], t[i], u[i]);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../misc/compress.hpp\"\
    \n#include \"../../misc/fastio.hpp\"\n#include \"../../data-structure-2d/segment-tree-on-range-tree.hpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve() {\n  auto f = [](ll a, ll b) {\
    \ return a + b; };\n\n  RangeTree<int, ll, decltype(f)> rtree(f, 0);\n\n  int\
    \ N, Q;\n  rd(N, Q);\n  vector<int> X(N), Y(N), W(N), c(Q), s(Q), t(Q), u(Q),\
    \ v(Q);\n  rep(i, N) {\n    rd(X[i], Y[i], W[i]);\n    rtree.add_point(X[i], Y[i]);\n\
    \  }\n  rep(i, Q) {\n    rd(c[i], s[i], t[i], u[i]);\n    if (c[i])\n      rd(v[i]);\n\
    \    else\n      rtree.add_point(s[i], t[i]);\n  }\n\n  rtree.build();\n  rep(i,\
    \ N) rtree.add(X[i], Y[i], W[i]);\n  rep(i, Q) {\n    if (c[i]) {\n      out(rtree.sum(s[i],\
    \ t[i], u[i], v[i]));\n    } else\n      rtree.add(s[i], t[i], u[i]);\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - misc/compress.hpp
  - misc/fastio.hpp
  - data-structure-2d/segment-tree-on-range-tree.hpp
  - segment-tree/segment-tree.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-dseg2d.test.cpp
  requiredBy: []
  timestamp: '2021-04-26 17:20:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-dseg2d.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-dseg2d.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-dseg2d.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-dseg2d.test.cpp
---
