---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segment-tree/li-chao-tree.hpp
    title: segment-tree/li-chao-tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\n\
    #line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n#include\
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
    inline int lsb(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }\ninline int\
    \ ctz(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }\ninline int msb(const\
    \ u64 &a) { return a ? 63 - __builtin_clzll(a) : -1; }\ntemplate <typename T>\n\
    inline int gbit(const T &a, int i) {\n  return (a >> i) & 1;\n}\ntemplate <typename\
    \ T>\ninline void sbit(T &a, int i, bool b) {\n  if (gbit(a, i) != b) a ^= T(1)\
    \ << i;\n}\nconstexpr long long PW(int n) { return 1LL << n; }\nconstexpr long\
    \ long MSK(int n) { return (1LL << n) - 1; }\n}  // namespace Nyaan\n#line 61\
    \ \"template/template.hpp\"\n\n// inout\n#line 1 \"template/inout.hpp\"\nnamespace\
    \ Nyaan {\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream &os,\
    \ const pair<T, U> &p) {\n  os << p.first << \" \" << p.second;\n  return os;\n\
    }\ntemplate <typename T, typename U>\nistream &operator>>(istream &is, pair<T,\
    \ U> &p) {\n  is >> p.first >> p.second;\n  return is;\n}\n\ntemplate <typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n  int s = (int)v.size();\n\
    \  for (int i = 0; i < s; i++) os << (i ? \" \" : \"\") << v[i];\n  return os;\n\
    }\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T> &v) {\n \
    \ for (auto &x : v) is >> x;\n  return is;\n}\n\nvoid in() {}\ntemplate <typename\
    \ T, class... U>\nvoid in(T &t, U &... u) {\n  cin >> t;\n  in(u...);\n}\n\nvoid\
    \ out() { cout << \"\\n\"; }\ntemplate <typename T, class... U, char sep = ' '>\n\
    void out(const T &t, const U &... u) {\n  cout << t;\n  if (sizeof...(u)) cout\
    \ << sep;\n  out(u...);\n}\n\nvoid outr() {}\ntemplate <typename T, class... U,\
    \ char sep = ' '>\nvoid outr(const T &t, const U &... u) {\n  cout << t;\n  outr(u...);\n\
    }\n\nstruct IoSetupNya {\n  IoSetupNya() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(15);\n    cerr << fixed << setprecision(7);\n\
    \  }\n} iosetupnya;\n\n}  // namespace Nyaan\n#line 64 \"template/template.hpp\"\
    \n\n// debug\n#line 1 \"template/debug.hpp\"\nnamespace DebugImpl {\n\ntemplate\
    \ <typename U, typename = void>\nstruct is_specialize : false_type {};\ntemplate\
    \ <typename U>\nstruct is_specialize<\n    U, typename conditional<false, typename\
    \ U::iterator, void>::type>\n    : true_type {};\ntemplate <typename U>\nstruct\
    \ is_specialize<\n    U, typename conditional<false, decltype(U::first), void>::type>\n\
    \    : true_type {};\ntemplate <typename U>\nstruct is_specialize<U, enable_if_t<is_integral<U>::value,\
    \ void>> : true_type {\n};\n\nvoid dump(const char& t) { cerr << t; }\n\nvoid\
    \ dump(const string& t) { cerr << t; }\n\nvoid dump(const bool& t) { cerr << (t\
    \ ? \"true\" : \"false\"); }\n\ntemplate <typename U,\n          enable_if_t<!is_specialize<U>::value,\
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
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line 2 \"segment-tree/li-chao-tree.hpp\"\
    \n\n\n\ntemplate <typename T, T INF>\nstruct LiChaoTree {\n  struct Line {\n \
    \   T slope, intercept;\n    Line(T slope, T intercept) : slope(slope), intercept(intercept)\
    \ {}\n    inline T get(T x) const { return slope * x + intercept; }\n    inline\
    \ bool over(const Line &other, const T &x) const {\n      return get(x) < other.get(x);\n\
    \    }\n  };\n\n  // remind \u30BB\u30B0\u6728\u306F0-indexed\u306E\u5B9F\u88C5\
    \n  vector<T> xset;\n  vector<Line> seg;\n  int _size;\n\n  // \u5F15\u6570x\u306B\
    \u306Fx\u5EA7\u6A19\u306E\u96C6\u5408\u3092\u5165\u308C\u308B\n  LiChaoTree(const\
    \ vector<T> &x) : xset(x) {\n    sort(xset.begin(), xset.end());\n    xset.erase(unique(xset.begin(),\
    \ xset.end()), xset.end());\n    _size = 1;\n    while (_size < (int)xset.size())\
    \ _size <<= 1;\n    while ((int)xset.size() < _size) xset.push_back(xset.back()\
    \ + 1);\n    seg.assign(2 * _size, Line(0, INF));\n  }\n\n  // \u4EE5\u4E0A xset[max]\u4EE5\
    \u4E0B\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\n  int get_more_idx(T k)\
    \ {\n    return lower_bound(xset.begin(), xset.end(), k) - xset.begin();\n  }\n\
    \  // \u4EE5\u4E0B xset[0]\u4EE5\u4E0A\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\
    \u5B9A\n  int get_less_idx(T k) {\n    int ret = upper_bound(xset.begin(), xset.end(),\
    \ k) - xset.begin();\n    return max(0, ret - 1);\n  }\n\n  // \u5185\u90E8\u7528\
    \n  void inner_update(T a, T b, int left, int right, int seg_idx) {\n    Line\
    \ line(a, b);\n    while (1) {\n      int mid = (left + right) >> 1;\n      bool\
    \ l_over = line.over(seg[seg_idx], xset[left]);\n      bool r_over = line.over(seg[seg_idx],\
    \ xset[right - 1]);\n      if (l_over == r_over) {\n        if (l_over) swap(seg[seg_idx],\
    \ line);\n        return;\n      }\n      bool m_over = line.over(seg[seg_idx],\
    \ xset[mid]);\n      if (m_over) swap(seg[seg_idx], line);\n      if (l_over !=\
    \ m_over)\n        seg_idx = (seg_idx << 1), right = mid;\n      else\n      \
    \  seg_idx = (seg_idx << 1) | 1, left = mid;\n    }\n  }\n\n  // \u5185\u90E8\u7528\
    \n  void inner_update(T a, T b, int seg_idx) {\n    int left, right;\n    int\
    \ upper_bit = 31 - __builtin_clz(seg_idx);\n    left = (_size >> upper_bit) *\
    \ (seg_idx - (1 << upper_bit));\n    right = left + (_size >> upper_bit);\n  \
    \  inner_update(a, b, left, right, seg_idx);\n  }\n\n  // y = ax + b\u306A\u308B\
    \u76F4\u7DDA\u3092\u8FFD\u52A0\n  void update(T a, T b) { inner_update(a, b, 0,\
    \ _size, 1); }\n\n  // \u9589\u533A\u9593x in [left , right]\u306B\u7DDA\u5206\
    y = ax + b\u3092\u8FFD\u52A0\u3059\u308B\u30AF\u30A8\u30EA\n  void update_segment(T\
    \ a, T b, T low, T high) {\n    int left = get_more_idx(low) + _size;\n    int\
    \ right = get_less_idx(high) + _size + 1;\n    for (; left < right; left >>= 1,\
    \ right >>= 1) {\n      if (left & 1) inner_update(a, b, left++);\n      if (right\
    \ & 1) inner_update(a, b, --right);\n    }\n  }\n\n  T inner_query(int x, int\
    \ segidx) {\n    T ret = seg[segidx].get(x);\n    while (segidx > 1) {\n     \
    \ segidx = segidx >> 1;\n      ret = min(ret, seg[segidx].get(x));\n    }\n  \
    \  return ret;\n  }\n\n  // x = xset[k]\u306A\u308B\u70B9\u306B\u304A\u3051\u308B\
    \u6700\u5C0F\u5024\u30AF\u30A8\u30EA\n  T query_idx(int k) {\n    const T x =\
    \ xset[k];\n    k += _size;\n    return inner_query(x, k);\n  }\n\n  // x\u306B\
    \u304A\u3051\u308B\u6700\u5C0F\u30AF\u30A8\u30EA\n  T query(T x) { return query_idx(get_more_idx(x));\
    \ }\n};\n#line 5 \"verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve() {\n  ini(N, Q);\n  vl a(N), b(N),\
    \ l(N), r(N);\n  in4(l, r, a, b);\n  vl c(Q), d(Q), e(Q), f(Q), g(Q);\n  vl xs;\n\
    \  rep(i, Q) {\n    in(c[i]);\n    if (c[i])\n      in(d[i]), xs.push_back(d[i]);\n\
    \    else\n      in(d[i], e[i], f[i], g[i]);\n  }\n  xs.push_back(-inf);\n  xs.push_back(inf);\n\
    \  LiChaoTree<ll, infLL> lichao(xs);\n  rep(_, N) lichao.update_segment(a[_],\
    \ b[_], l[_], r[_] - 1);\n\n  rep(i, Q) {\n    if (c[i]) {\n      ll ans = lichao.query(d[i]);\n\
    \      if (ans == infLL)\n        out(\"INFINITY\");\n      else\n        out(ans);\n\
    \    } else {\n      lichao.update_segment(f[i], g[i], d[i], e[i] - 1);\n    }\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    \n#include \"../../template/template.hpp\"\n#include \"../../segment-tree/li-chao-tree.hpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve() {\n  ini(N, Q);\n  vl a(N), b(N),\
    \ l(N), r(N);\n  in4(l, r, a, b);\n  vl c(Q), d(Q), e(Q), f(Q), g(Q);\n  vl xs;\n\
    \  rep(i, Q) {\n    in(c[i]);\n    if (c[i])\n      in(d[i]), xs.push_back(d[i]);\n\
    \    else\n      in(d[i], e[i], f[i], g[i]);\n  }\n  xs.push_back(-inf);\n  xs.push_back(inf);\n\
    \  LiChaoTree<ll, infLL> lichao(xs);\n  rep(_, N) lichao.update_segment(a[_],\
    \ b[_], l[_], r[_] - 1);\n\n  rep(i, Q) {\n    if (c[i]) {\n      ll ans = lichao.query(d[i]);\n\
    \      if (ans == infLL)\n        out(\"INFINITY\");\n      else\n        out(ans);\n\
    \    } else {\n      lichao.update_segment(f[i], g[i], d[i], e[i] - 1);\n    }\n\
    \  }\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - segment-tree/li-chao-tree.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp
  requiredBy: []
  timestamp: '2021-05-04 19:34:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp
---
