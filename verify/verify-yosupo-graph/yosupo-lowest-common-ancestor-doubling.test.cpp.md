---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/doubling.hpp
    title: "Binary Lifting(\u30C0\u30D6\u30EA\u30F3\u30B0)"
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#line 2 \"template/template.hpp\"\
    \nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cctype>\n#include\
    \ <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <cstdarg>\n#include\
    \ <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
    #include <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include\
    \ <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <streambuf>\n#include <string>\n#include <tuple>\n\
    #include <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <vector>\n\n// utility\n#line\
    \ 1 \"template/util.hpp\"\nnamespace Nyaan {\nusing ll = long long;\nusing i64\
    \ = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\nusing\
    \ u128 = __uint128_t;\n\ntemplate <typename T>\nusing V = vector<T>;\ntemplate\
    \ <typename T>\nusing VV = vector<vector<T>>;\nusing vi = vector<int>;\nusing\
    \ vl = vector<long long>;\nusing vd = V<double>;\nusing vs = V<string>;\nusing\
    \ vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\n\ntemplate\
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
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line 4 \"verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp\"\
    \n//\n#line 2 \"misc/doubling.hpp\"\n\ntemplate <typename T>\nstruct BinaryLifting\
    \ {\n  using Data = pair<int, T>;\n\n  const int N, LOG;\n  vector<vector<Data>>\
    \ table;\n  T I;\n\n  BinaryLifting(int n, uint64_t lim, const T I_ = T())\n \
    \     : N(n), LOG(__lg(lim) + 2), I(I_) {\n    table.resize(n, vector<Data>(LOG,\
    \ Data(-1, I)));\n  }\n\n  void set_next(int k, int nxt, const T& t) { table[k][0]\
    \ = Data(nxt, t); }\n\n  void build() {\n    for (int k = 0; k + 1 < LOG; ++k)\n\
    \      for (int i = 0; i < N; ++i) {\n        int pre = table[i][k].first;\n \
    \       if (pre == -1) {\n          table[i][k + 1] = table[i][k];\n        }\
    \ else {\n          table[i][k + 1].first = table[pre][k].first;\n          table[i][k\
    \ + 1].second = table[i][k].second + table[pre][k].second;\n        }\n      }\n\
    \  }\n\n  // from i, move t times\n  Data query(int i, uint64_t t) const {\n \
    \   T d = I;\n    for (int k = LOG - 1; k >= 0; k--) {\n      if ((t >> k) & 1)\
    \ {\n        d = d + table[i][k].second;\n        i = table[i][k].first;\n   \
    \   }\n      if (i == -1) break;\n    }\n    return Data(i, d);\n  }\n\n  // query(i,\
    \ pow(2, k))\n  inline Data query_pow(int i, int k) const { return table[i][k];\
    \ }\n\n  // assuming graph is DAG ( edge(u, v) <-> u < v )\n  // find max j |\
    \ j <= t, path from i to j exists\n  inline pair<uint64_t, Data> binary_search(int\
    \ i, int t) {\n    int thres = i;\n    T d = I;\n    uint64_t times = 0;\n   \
    \ for (int k = LOG - 1; k >= 0; k--) {\n      int nxt = table[thres][k].first;\n\
    \      if (nxt != -1 && nxt <= t) {\n        d = d + table[thres][k].second;\n\
    \        thres = nxt;\n        times += 1LL << k;\n      }\n    }\n    return\
    \ make_pair(times, Data(thres, d));\n  }\n\n  // assuming graph is DAG ( edge(u,\
    \ v) <-> u < v )\n  // find min j | j >= t, path from i to j exists\n  inline\
    \ pair<uint64_t, Data> binary_search2(int i, int t) {\n    int thres = i;\n  \
    \  T d = I;\n    uint64_t times = 0;\n    for (int k = LOG - 1; k >= 0; k--) {\n\
    \      int nxt = table[thres][k].first;\n      if (nxt != -1 && nxt >= t) {\n\
    \        d = d + table[thres][k].second;\n        thres = nxt;\n        times\
    \ += 1LL << k;\n      }\n    }\n    return make_pair(times, Data(thres, d));\n\
    \  }\n};\n\ntemplate <typename T>\nusing Doubling = BinaryLifting<T>;\n\n/**\n\
    \ * @brief Binary Lifting(\u30C0\u30D6\u30EA\u30F3\u30B0)\n * @docs docs/misc/doubling.md\n\
    \ */\n#line 2 \"misc/fastio.hpp\"\n\n#line 6 \"misc/fastio.hpp\"\n\nusing namespace\
    \ std;\n\nnamespace fastio {\nstatic constexpr int SZ = 1 << 17;\nchar inbuf[SZ],\
    \ outbuf[SZ];\nint in_left = 0, in_right = 0, out_right = 0;\n\nstruct Pre {\n\
    \  char num[40000];\n  constexpr Pre() : num() {\n    for (int i = 0; i < 10000;\
    \ i++) {\n      int n = i;\n      for (int j = 3; j >= 0; j--) {\n        num[i\
    \ * 4 + j] = n % 10 + '0';\n        n /= 10;\n      }\n    }\n  }\n} constexpr\
    \ pre;\n\ninline void load() {\n  int len = in_right - in_left;\n  memmove(inbuf,\
    \ inbuf + in_left, len);\n  in_right = len + fread(inbuf + len, 1, SZ - len, stdin);\n\
    \  in_left = 0;\n}\n\ninline void flush() {\n  fwrite(outbuf, 1, out_right, stdout);\n\
    \  out_right = 0;\n}\n\ninline void skip_space() {\n  if (in_left + 32 > in_right)\
    \ load();\n  while (inbuf[in_left] <= ' ') in_left++;\n}\n\ninline void rd(char&\
    \ c) {\n  if (in_left + 32 > in_right) load();\n  c = inbuf[in_left++];\n}\ntemplate\
    \ <typename T>\ninline void rd(T& x) {\n  if (in_left + 32 > in_right) load();\n\
    \  char c;\n  do c = inbuf[in_left++];\n  while (c < '-');\n  [[maybe_unused]]\
    \ bool minus = false;\n  if constexpr (is_signed<T>::value == true) {\n    if\
    \ (c == '-') minus = true, c = inbuf[in_left++];\n  }\n  x = 0;\n  while (c >=\
    \ '0') {\n    x = x * 10 + (c & 15);\n    c = inbuf[in_left++];\n  }\n  if constexpr\
    \ (is_signed<T>::value == true) {\n    if (minus) x = -x;\n  }\n}\ninline void\
    \ rd() {}\ntemplate <typename Head, typename... Tail>\ninline void rd(Head& head,\
    \ Tail&... tail) {\n  rd(head);\n  rd(tail...);\n}\n\ninline void wt(char c) {\n\
    \  if (out_right > SZ - 32) flush();\n  outbuf[out_right++] = c;\n}\ninline void\
    \ wt(bool b) {\n  if (out_right > SZ - 32) flush();\n  outbuf[out_right++] = b\
    \ ? '1' : '0';\n}\ninline void wt(const string &s) {\n  if (out_right + s.size()\
    \ > SZ - 32) flush();\n  memcpy(outbuf + out_right, s.data(), sizeof(char) * s.size());\n\
    \  out_right += s.size();\n}\ntemplate <typename T>\ninline void wt(T x) {\n \
    \ if (out_right > SZ - 32) flush();\n  if (!x) {\n    outbuf[out_right++] = '0';\n\
    \    return;\n  }\n  if constexpr (is_signed<T>::value == true) {\n    if (x <\
    \ 0) outbuf[out_right++] = '-', x = -x;\n  }\n  int i = 12;\n  char buf[16];\n\
    \  while (x >= 10000) {\n    memcpy(buf + i, pre.num + (x % 10000) * 4, 4);\n\
    \    x /= 10000;\n    i -= 4;\n  }\n  if (x < 100) {\n    if (x < 10) {\n    \
    \  outbuf[out_right] = '0' + x;\n      ++out_right;\n    } else {\n      uint32_t\
    \ q = (uint32_t(x) * 205) >> 11;\n      uint32_t r = uint32_t(x) - q * 10;\n \
    \     outbuf[out_right] = '0' + q;\n      outbuf[out_right + 1] = '0' + r;\n \
    \     out_right += 2;\n    }\n  } else {\n    if (x < 1000) {\n      memcpy(outbuf\
    \ + out_right, pre.num + (x << 2) + 1, 3);\n      out_right += 3;\n    } else\
    \ {\n      memcpy(outbuf + out_right, pre.num + (x << 2), 4);\n      out_right\
    \ += 4;\n    }\n  }\n  memcpy(outbuf + out_right, buf + i + 4, 12 - i);\n  out_right\
    \ += 12 - i;\n}\ninline void wt() {}\ntemplate <typename Head, typename... Tail>\n\
    inline void wt(Head&& head, Tail&&... tail) {\n  wt(head);\n  wt(forward<Tail>(tail)...);\n\
    }\ntemplate <typename... Args>\ninline void wtn(Args&&... x) {\n  wt(forward<Args>(x)...);\n\
    \  wt('\\n');\n}\n\nstruct Dummy {\n  Dummy() { atexit(flush); }\n} dummy;\n\n\
    }  // namespace fastio\nusing fastio::rd;\nusing fastio::skip_space;\nusing fastio::wt;\n\
    using fastio::wtn;\n#line 7 \"verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp\"\
    \n\nvoid Nyaan::solve() {\n  int N, Q;\n  rd(N, Q);\n  Doubling<int> db(N, N,\
    \ 0);\n  for (int i = 1; i < N; i++) {\n    int p;\n    rd(p);\n    db.set_next(i,\
    \ p, 1);\n  }\n  db.build();\n\n  while (Q--) {\n    int u, v;\n    rd(u, v);\n\
    \    int du = db.query_pow(u, db.LOG - 1).second;\n    int dv = db.query_pow(v,\
    \ db.LOG - 1).second;\n    if (du > dv) swap(u, v), swap(du, dv);\n    int t =\
    \ dv - du;\n    for (int k = 0; t; k++) {\n      if ((t >> k) & 1) {\n       \
    \ v = db.query_pow(v, k).first;\n        t ^= (1 << k);\n      }\n    }\n    if\
    \ (u != v) {\n      for (int k = db.LOG - 1; k >= 0; --k) {\n        int pu =\
    \ db.query_pow(u, k).first;\n        int pv = db.query_pow(v, k).first;\n    \
    \    if (pu != pv) u = pu, v = pv;\n      }\n      u = db.query_pow(u, 0).first;\n\
    \    }\n    wtn(u);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../template/template.hpp\"\
    \n//\n#include \"../../misc/doubling.hpp\"\n#include \"../../misc/fastio.hpp\"\
    \n\nvoid Nyaan::solve() {\n  int N, Q;\n  rd(N, Q);\n  Doubling<int> db(N, N,\
    \ 0);\n  for (int i = 1; i < N; i++) {\n    int p;\n    rd(p);\n    db.set_next(i,\
    \ p, 1);\n  }\n  db.build();\n\n  while (Q--) {\n    int u, v;\n    rd(u, v);\n\
    \    int du = db.query_pow(u, db.LOG - 1).second;\n    int dv = db.query_pow(v,\
    \ db.LOG - 1).second;\n    if (du > dv) swap(u, v), swap(du, dv);\n    int t =\
    \ dv - du;\n    for (int k = 0; t; k++) {\n      if ((t >> k) & 1) {\n       \
    \ v = db.query_pow(v, k).first;\n        t ^= (1 << k);\n      }\n    }\n    if\
    \ (u != v) {\n      for (int k = db.LOG - 1; k >= 0; --k) {\n        int pu =\
    \ db.query_pow(u, k).first;\n        int pv = db.query_pow(v, k).first;\n    \
    \    if (pu != pv) u = pu, v = pv;\n      }\n      u = db.query_pow(u, 0).first;\n\
    \    }\n    wtn(u);\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - misc/doubling.hpp
  - misc/fastio.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp
  requiredBy: []
  timestamp: '2021-11-14 23:34:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp
- /verify/verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp.html
title: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp
---
