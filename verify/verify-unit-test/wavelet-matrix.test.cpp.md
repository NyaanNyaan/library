---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure-2d/wavelet-matrix.hpp
    title: Wavelet Matrix
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/wavelet-matrix.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"template/template.hpp\"\
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
    \ vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\ntemplate\
    \ <typename T>\nusing minpq = priority_queue<T, vector<T>, greater<T>>;\n\ntemplate\
    \ <typename T, typename U>\nstruct P : pair<T, U> {\n  template <typename... Args>\n\
    \  P(Args... args) : pair<T, U>(args...) {}\n\n  using pair<T, U>::first;\n  using\
    \ pair<T, U>::second;\n\n  P &operator+=(const P &r) {\n    first += r.first;\n\
    \    second += r.second;\n    return *this;\n  }\n  P &operator-=(const P &r)\
    \ {\n    first -= r.first;\n    second -= r.second;\n    return *this;\n  }\n\
    \  P &operator*=(const P &r) {\n    first *= r.first;\n    second *= r.second;\n\
    \    return *this;\n  }\n  template <typename S>\n  P &operator*=(const S &r)\
    \ {\n    first *= r, second *= r;\n    return *this;\n  }\n  P operator+(const\
    \ P &r) const { return P(*this) += r; }\n  P operator-(const P &r) const { return\
    \ P(*this) -= r; }\n  P operator*(const P &r) const { return P(*this) *= r; }\n\
    \  template <typename S>\n  P operator*(const S &r) const {\n    return P(*this)\
    \ *= r;\n  }\n  P operator-() const { return P{-first, -second}; }\n};\n\nusing\
    \ pl = P<ll, ll>;\nusing pi = P<int, int>;\nusing vp = V<pl>;\n\nconstexpr int\
    \ inf = 1001001001;\nconstexpr long long infLL = 4004004004004004004LL;\n\ntemplate\
    \ <typename T>\nint sz(const T &t) {\n  return t.size();\n}\n\ntemplate <typename\
    \ T, typename U>\ninline bool amin(T &x, U y) {\n  return (y < x) ? (x = y, true)\
    \ : false;\n}\ntemplate <typename T, typename U>\ninline bool amax(T &x, U y)\
    \ {\n  return (x < y) ? (x = y, true) : false;\n}\n\ntemplate <typename T>\ninline\
    \ T Max(const vector<T> &v) {\n  return *max_element(begin(v), end(v));\n}\ntemplate\
    \ <typename T>\ninline T Min(const vector<T> &v) {\n  return *min_element(begin(v),\
    \ end(v));\n}\ntemplate <typename T>\ninline long long Sum(const vector<T> &v)\
    \ {\n  return accumulate(begin(v), end(v), 0LL);\n}\n\ntemplate <typename T>\n\
    int lb(const vector<T> &v, const T &a) {\n  return lower_bound(begin(v), end(v),\
    \ a) - begin(v);\n}\ntemplate <typename T>\nint ub(const vector<T> &v, const T\
    \ &a) {\n  return upper_bound(begin(v), end(v), a) - begin(v);\n}\n\nconstexpr\
    \ long long TEN(int n) {\n  long long ret = 1, x = 10;\n  for (; n; x *= x, n\
    \ >>= 1) ret *= (n & 1 ? x : 1);\n  return ret;\n}\n\ntemplate <typename T, typename\
    \ U>\npair<T, U> mkp(const T &t, const U &u) {\n  return make_pair(t, u);\n}\n\
    \ntemplate <typename T>\nvector<T> mkrui(const vector<T> &v, bool rev = false)\
    \ {\n  vector<T> ret(v.size() + 1);\n  if (rev) {\n    for (int i = int(v.size())\
    \ - 1; i >= 0; i--) ret[i] = v[i] + ret[i + 1];\n  } else {\n    for (int i =\
    \ 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];\n  }\n  return ret;\n\
    };\n\ntemplate <typename T>\nvector<T> mkuni(const vector<T> &v) {\n  vector<T>\
    \ ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(), ret.end()),\
    \ ret.end());\n  return ret;\n}\n\ntemplate <typename F>\nvector<int> mkord(int\
    \ N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n  sort(begin(ord),\
    \ end(ord), f);\n  return ord;\n}\n\ntemplate <typename T>\nvector<int> mkinv(vector<T>\
    \ &v) {\n  int max_val = *max_element(begin(v), end(v));\n  vector<int> inv(max_val\
    \ + 1, -1);\n  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;\n  return\
    \ inv;\n}\n\nvector<int> mkiota(int n) {\n  vector<int> ret(n);\n  iota(begin(ret),\
    \ end(ret), 0);\n  return ret;\n}\n\ntemplate <typename T>\nT mkrev(const T &v)\
    \ {\n  T w{v};\n  reverse(begin(w), end(w));\n  return w;\n}\n\ntemplate <typename\
    \ T>\nbool nxp(vector<T> &v) {\n  return next_permutation(begin(v), end(v));\n\
    }\n\n// \u8FD4\u308A\u5024\u306E\u578B\u306F\u5165\u529B\u306E T \u306B\u4F9D\u5B58\
    \n// i \u8981\u7D20\u76EE : [0, a[i])\ntemplate <typename T>\nvector<vector<T>>\
    \ product(const vector<T> &a) {\n  vector<vector<T>> ret;\n  vector<T> v;\n  auto\
    \ dfs = [&](auto rc, int i) -> void {\n    if (i == (int)a.size()) {\n      ret.push_back(v);\n\
    \      return;\n    }\n    for (int j = 0; j < a[i]; j++) v.push_back(j), rc(rc,\
    \ i + 1), v.pop_back();\n  };\n  dfs(dfs, 0);\n  return ret;\n}\n\n// F : function(void(T&)),\
    \ mod \u3092\u53D6\u308B\u64CD\u4F5C\n// T : \u6574\u6570\u578B\u306E\u3068\u304D\
    \u306F\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306B\u6CE8\u610F\u3059\u308B\
    \ntemplate <typename T>\nT Power(T a, long long n, const T &I, const function<void(T\
    \ &)> &f) {\n  T res = I;\n  for (; n; f(a = a * a), n >>= 1) {\n    if (n & 1)\
    \ f(res = res * a);\n  }\n  return res;\n}\n// T : \u6574\u6570\u578B\u306E\u3068\
    \u304D\u306F\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306B\u6CE8\u610F\u3059\
    \u308B\ntemplate <typename T>\nT Power(T a, long long n, const T &I) {\n  return\
    \ Power(a, n, I, function<void(T &)>{[](T &) -> void {}});\n}\n\n}  // namespace\
    \ Nyaan\n#line 58 \"template/template.hpp\"\n\n// bit operation\n#line 1 \"template/bitop.hpp\"\
    \nnamespace Nyaan {\n__attribute__((target(\"popcnt\"))) inline int popcnt(const\
    \ u64 &a) {\n  return _mm_popcnt_u64(a);\n}\ninline int lsb(const u64 &a) { return\
    \ a ? __builtin_ctzll(a) : 64; }\ninline int ctz(const u64 &a) { return a ? __builtin_ctzll(a)\
    \ : 64; }\ninline int msb(const u64 &a) { return a ? 63 - __builtin_clzll(a) :\
    \ -1; }\ntemplate <typename T>\ninline int gbit(const T &a, int i) {\n  return\
    \ (a >> i) & 1;\n}\ntemplate <typename T>\ninline void sbit(T &a, int i, bool\
    \ b) {\n  if (gbit(a, i) != b) a ^= T(1) << i;\n}\nconstexpr long long PW(int\
    \ n) { return 1LL << n; }\nconstexpr long long MSK(int n) { return (1LL << n)\
    \ - 1; }\n}  // namespace Nyaan\n#line 61 \"template/template.hpp\"\n\n// inout\n\
    #line 1 \"template/inout.hpp\"\nnamespace Nyaan {\n\ntemplate <typename T, typename\
    \ U>\nostream &operator<<(ostream &os, const pair<T, U> &p) {\n  os << p.first\
    \ << \" \" << p.second;\n  return os;\n}\ntemplate <typename T, typename U>\n\
    istream &operator>>(istream &is, pair<T, U> &p) {\n  is >> p.first >> p.second;\n\
    \  return is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const\
    \ vector<T> &v) {\n  int s = (int)v.size();\n  for (int i = 0; i < s; i++) os\
    \ << (i ? \" \" : \"\") << v[i];\n  return os;\n}\ntemplate <typename T>\nistream\
    \ &operator>>(istream &is, vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return\
    \ is;\n}\n\nistream &operator>>(istream &is, __int128_t &x) {\n  string S;\n \
    \ is >> S;\n  x = 0;\n  int flag = 0;\n  for (auto &c : S) {\n    if (c == '-')\
    \ {\n      flag = true;\n      continue;\n    }\n    x *= 10;\n    x += c - '0';\n\
    \  }\n  if (flag) x = -x;\n  return is;\n}\n\nistream &operator>>(istream &is,\
    \ __uint128_t &x) {\n  string S;\n  is >> S;\n  x = 0;\n  for (auto &c : S) {\n\
    \    x *= 10;\n    x += c - '0';\n  }\n  return is;\n}\n\nostream &operator<<(ostream\
    \ &os, __int128_t x) {\n  if (x == 0) return os << 0;\n  if (x < 0) os << '-',\
    \ x = -x;\n  string S;\n  while (x) S.push_back('0' + x % 10), x /= 10;\n  reverse(begin(S),\
    \ end(S));\n  return os << S;\n}\nostream &operator<<(ostream &os, __uint128_t\
    \ x) {\n  if (x == 0) return os << 0;\n  string S;\n  while (x) S.push_back('0'\
    \ + x % 10), x /= 10;\n  reverse(begin(S), end(S));\n  return os << S;\n}\n\n\
    void in() {}\ntemplate <typename T, class... U>\nvoid in(T &t, U &...u) {\n  cin\
    \ >> t;\n  in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename\
    \ T, class... U, char sep = ' '>\nvoid out(const T &t, const U &...u) {\n  cout\
    \ << t;\n  if (sizeof...(u)) cout << sep;\n  out(u...);\n}\n\nstruct IoSetupNya\
    \ {\n  IoSetupNya() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
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
    \ ? \"true\" : \"false\"); }\n\nvoid dump(__int128_t t) {\n  if (t == 0) cerr\
    \ << 0;\n  if (t < 0) cerr << '-', t = -t;\n  string S;\n  while (t) S.push_back('0'\
    \ + t % 10), t /= 10;\n  reverse(begin(S), end(S));\n  cerr << S;\n}\n\nvoid dump(__uint128_t\
    \ t) {\n  if (t == 0) cerr << 0;\n  string S;\n  while (t) S.push_back('0' + t\
    \ % 10), t /= 10;\n  reverse(begin(S), end(S));\n  cerr << S;\n}\n\ntemplate <typename\
    \ U,\n          enable_if_t<!is_specialize<U>::value, nullptr_t> = nullptr>\n\
    void dump(const U& t) {\n  cerr << t;\n}\n\ntemplate <typename T>\nvoid dump(const\
    \ T& t, enable_if_t<is_integral<T>::value>* = nullptr) {\n  string res;\n  if\
    \ (t == Nyaan::inf) res = \"inf\";\n  if constexpr (is_signed<T>::value) {\n \
    \   if (t == -Nyaan::inf) res = \"-inf\";\n  }\n  if constexpr (sizeof(T) == 8)\
    \ {\n    if (t == Nyaan::infLL) res = \"inf\";\n    if constexpr (is_signed<T>::value)\
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
    \          \\\n  } while (0)\n#else\n#define trc(...) (void(0))\n#endif\n\n#ifdef\
    \ NyaanLocal\n#define trc2(...)                           \\\n  do {         \
    \                             \\\n    cerr << \"## \" << #__VA_ARGS__ << \" =\
    \ \"; \\\n    DebugImpl::trace(__VA_ARGS__);          \\\n  } while (0)\n#else\n\
    #define trc2(...) (void(0))\n#endif\n#line 67 \"template/template.hpp\"\n\n//\
    \ macro\n#line 1 \"template/macro.hpp\"\n#define each(x, v) for (auto&& x : v)\n\
    #define each2(x, y, v) for (auto&& [x, y] : v)\n#define all(v) (v).begin(), (v).end()\n\
    #define rep(i, N) for (long long i = 0; i < (long long)(N); i++)\n#define repr(i,\
    \ N) for (long long i = (long long)(N)-1; i >= 0; i--)\n#define rep1(i, N) for\
    \ (long long i = 1; i <= (long long)(N); i++)\n#define repr1(i, N) for (long long\
    \ i = (N); (long long)(i) > 0; i--)\n#define reg(i, a, b) for (long long i = (a);\
    \ i < (b); i++)\n#define regr(i, a, b) for (long long i = (b)-1; i >= (a); i--)\n\
    #define fi first\n#define se second\n#define ini(...)   \\\n  int __VA_ARGS__;\
    \ \\\n  in(__VA_ARGS__)\n#define inl(...)         \\\n  long long __VA_ARGS__;\
    \ \\\n  in(__VA_ARGS__)\n#define ins(...)      \\\n  string __VA_ARGS__; \\\n\
    \  in(__VA_ARGS__)\n#define in2(s, t)                           \\\n  for (int\
    \ i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i]);                   \
    \      \\\n  }\n#define in3(s, t, u)                        \\\n  for (int i =\
    \ 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i], u[i]);                 \
    \  \\\n  }\n#define in4(s, t, u, v)                     \\\n  for (int i = 0;\
    \ i < (int)s.size(); i++) { \\\n    in(s[i], t[i], u[i], v[i]);             \\\
    \n  }\n#define die(...)             \\\n  do {                       \\\n    Nyaan::out(__VA_ARGS__);\
    \ \\\n    return;                  \\\n  } while (0)\n#line 70 \"template/template.hpp\"\
    \n\nnamespace Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line\
    \ 2 \"data-structure-2d/wavelet-matrix.hpp\"\n\n#line 4 \"data-structure-2d/wavelet-matrix.hpp\"\
    \n\nstruct bit_vector {\n  using u32 = uint32_t;\n  using i64 = int64_t;\n  using\
    \ u64 = uint64_t;\n\n  static constexpr u32 w = 64;\n  vector<u64> block;\n  vector<u32>\
    \ count;\n  u32 n, zeros;\n\n  inline u32 get(u32 i) const { return u32(block[i\
    \ / w] >> (i % w)) & 1u; }\n  inline void set(u32 i) { block[i / w] |= 1LL <<\
    \ (i % w); }\n\n  bit_vector() {}\n  bit_vector(int _n) { init(_n); }\n  __attribute__((optimize(\"\
    O3\", \"unroll-loops\"))) void init(int _n) {\n    n = zeros = _n;\n    block.resize(n\
    \ / w + 1, 0);\n    count.resize(block.size(), 0);\n  }\n\n  __attribute__((target(\"\
    popcnt\"))) void build() {\n    for (u32 i = 1; i < block.size(); ++i)\n     \
    \ count[i] = count[i - 1] + _mm_popcnt_u64(block[i - 1]);\n    zeros = rank0(n);\n\
    \  }\n\n  inline u32 rank0(u32 i) const { return i - rank1(i); }\n  __attribute__((target(\"\
    bmi2,popcnt\"))) inline u32 rank1(u32 i) const {\n    return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i\
    \ / w], i % w));\n  }\n};\n\ntemplate <typename T>\nstruct WaveletMatrix {\n \
    \ using u32 = uint32_t;\n  using i64 = int64_t;\n  using u64 = uint64_t;\n\n \
    \ int n, lg;\n  vector<T> a;\n  vector<bit_vector> bv;\n\n  WaveletMatrix(u32\
    \ _n) : n(max<u32>(_n, 1)), a(n) {}\n  WaveletMatrix(const vector<T>& _a) : n(_a.size()),\
    \ a(_a) { build(); }\n\n  __attribute__((optimize(\"O3\"))) void build() {\n \
    \   lg = __lg(max<T>(*max_element(begin(a), end(a)), 1)) + 1;\n    bv.assign(lg,\
    \ n);\n    vector<T> cur = a, nxt(n);\n    for (int h = lg - 1; h >= 0; --h) {\n\
    \      for (int i = 0; i < n; ++i)\n        if ((cur[i] >> h) & 1) bv[h].set(i);\n\
    \      bv[h].build();\n      array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt)\
    \ + bv[h].zeros};\n      for (int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];\n\
    \      swap(cur, nxt);\n    }\n    return;\n  }\n\n  void set(u32 i, const T&\
    \ x) { \n    assert(x >= 0);\n    a[i] = x; \n  }\n\n  inline pair<u32, u32> succ0(int\
    \ l, int r, int h) const {\n    return make_pair(bv[h].rank0(l), bv[h].rank0(r));\n\
    \  }\n\n  inline pair<u32, u32> succ1(int l, int r, int h) const {\n    u32 l0\
    \ = bv[h].rank0(l);\n    u32 r0 = bv[h].rank0(r);\n    u32 zeros = bv[h].zeros;\n\
    \    return make_pair(l + zeros - l0, r + zeros - r0);\n  }\n\n  // return a[k]\n\
    \  T access(u32 k) const {\n    T ret = 0;\n    for (int h = lg - 1; h >= 0; --h)\
    \ {\n      u32 f = bv[h].get(k);\n      ret |= f ? T(1) << h : 0;\n      k = f\
    \ ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);\n    }\n    return ret;\n \
    \ }\n\n  // k-th (0-indexed) smallest number in a[l, r)\n  T kth_smallest(u32\
    \ l, u32 r, u32 k) const {\n    T res = 0;\n    for (int h = lg - 1; h >= 0; --h)\
    \ {\n      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n      if (k < r0 - l0)\n\
    \        l = l0, r = r0;\n      else {\n        k -= r0 - l0;\n        res |=\
    \ (T)1 << h;\n        l += bv[h].zeros - l0;\n        r += bv[h].zeros - r0;\n\
    \      }\n    }\n    return res;\n  }\n\n  // k-th (0-indexed) largest number\
    \ in a[l, r)\n  T kth_largest(int l, int r, int k) {\n    return kth_smallest(l,\
    \ r, r - l - k - 1);\n  }\n\n  // count i s.t. (l <= i < r) && (v[i] < upper)\n\
    \  int range_freq(int l, int r, T upper) {\n    if (upper >= (T(1) << lg)) return\
    \ r - l;\n    int ret = 0;\n    for (int h = lg - 1; h >= 0; --h) {\n      bool\
    \ f = (upper >> h) & 1;\n      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n\
    \      if (f) {\n        ret += r0 - l0;\n        l += bv[h].zeros - l0;\n   \
    \     r += bv[h].zeros - r0;\n      } else {\n        l = l0;\n        r = r0;\n\
    \      }\n    }\n    return ret;\n  }\n\n  int range_freq(int l, int r, T lower,\
    \ T upper) {\n    return range_freq(l, r, upper) - range_freq(l, r, lower);\n\
    \  }\n\n  // max v[i] s.t. (l <= i < r) && (v[i] < upper)\n  T prev_value(int\
    \ l, int r, T upper) {\n    int cnt = range_freq(l, r, upper);\n    return cnt\
    \ == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);\n  }\n\n  // min v[i] s.t. (l <=\
    \ i < r) && (lower <= v[i])\n  T next_value(int l, int r, T lower) {\n    int\
    \ cnt = range_freq(l, r, lower);\n    return cnt == r - l ? T(-1) : kth_smallest(l,\
    \ r, cnt);\n  }\n};\n\n/*\n * @brief Wavelet Matrix\n * @docs docs/data-structure-2d/wavelet-matrix.md\n\
    \ */\n#line 5 \"verify/verify-unit-test/wavelet-matrix.test.cpp\"\n\nuint64_t\
    \ rng() {\n  static uint64_t x_ =\n      chrono::duration_cast<chrono::nanoseconds>(\n\
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \  .count();\n  return x_ ^= (x_ << 7), x_ ^= (x_ >> 9);\n}\n\nint randint(int\
    \ l, int r) {\n  assert(l < r);\n  return rng() % (r - l) + l;\n}\n\nvoid test(int\
    \ n, int q, bool all_zero = false, bool large = false) {\n  assert(n > 0);\n \
    \ WaveletMatrix<int> wm(n);\n  vector<int> v(n, 0);\n  vector<int> buffer;\n\n\
    \  if (large) {\n    for (int i = 0; i < n; ++i) v[i] = randint(0, 1 << 30);\n\
    \  } else if (!all_zero) {\n    iota(begin(v), end(v), 0);\n  }\n\n  mt19937_64\
    \ mt;\n  shuffle(begin(v), end(v), mt);\n  for (int i = n; i--;) wm.set(i, v[i]);\n\
    \  wm.build();\n\n  // access\n  for (int Q = q; Q--;) {\n    int i = randint(0,\
    \ n);\n    assert(wm.access(i) == v[i]);\n  }\n\n  // kth-smallest / kth-largest\n\
    \  for (int Q = q; Q--;) {\n    int len = randint(1, n + 1);\n    int l = randint(0,\
    \ n - len + 1);\n    int r = l + len;\n    int k = randint(0, len);\n\n    buffer.clear();\n\
    \    copy(begin(v) + l, begin(v) + r, back_inserter(buffer));\n    sort(begin(buffer),\
    \ end(buffer));\n\n    assert(wm.kth_smallest(l, r, k) == buffer[k]);\n    assert(wm.kth_largest(l,\
    \ r, k) == buffer[len - k - 1]);\n  }\n\n  // range-freq\n  for (int Q = q; Q--;)\
    \ {\n    int len = randint(1, n + 1);\n    int l = randint(0, n - len + 1);\n\
    \    int r = l + len;\n    int lower, upper;\n    do {\n      lower = randint(0,\
    \ n + 5);\n      upper = randint(0, n + 5);\n      if (lower > upper) swap(lower,\
    \ upper);\n    } while (lower != upper);\n\n    buffer.clear();\n    copy(begin(v)\
    \ + l, begin(v) + r, back_inserter(buffer));\n    sort(begin(buffer), end(buffer));\n\
    \n    int up = lower_bound(begin(buffer), end(buffer), upper) - begin(buffer);\n\
    \    assert(wm.range_freq(l, r, upper) == up);\n    int lo = lower_bound(begin(buffer),\
    \ end(buffer), lower) - begin(buffer);\n    assert(wm.range_freq(l, r, lower,\
    \ upper) == up - lo);\n\n    int pv = len - 1;\n    while (pv != -1 and buffer[pv]\
    \ >= upper) --pv;\n    assert(wm.prev_value(l, r, upper) == (pv == -1 ? -1 : buffer[pv]));\n\
    \n    int nv = 0;\n    while (nv != len and buffer[nv] < lower) ++nv;\n    assert(wm.next_value(l,\
    \ r, lower) == (nv == len ? -1 : buffer[nv]));\n  }\n}\n\nvoid Nyaan::solve()\
    \ {\n  test(63, 1000);\n  test(64, 1000);\n  test(65, 1000);\n  test(63, 1000,\
    \ true);\n  test(64, 1000, true);\n  test(65, 1000, true);\n  test(63, 1000, false,\
    \ true);\n  test(64, 1000, false, true);\n  test(65, 1000, false, true);\n  for\
    \ (int i = 100; i--;) {\n    test(1, 1);\n    test(1, 1, true);\n    test(1, 1,\
    \ false, true);\n    test(2, 10);\n    test(2, 10, true);\n    test(2, 10, false,\
    \ true);\n  }\n\n  test(65535, 10);\n  test(65536, 10);\n  test(65537, 10);\n\
    \  test(65535, 10, false, true);\n  test(65536, 10, false, true);\n  test(65537,\
    \ 10, false, true);\n  \n  int a, b;\n  cin >> a >> b;\n  cout << (a + b) << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../template/template.hpp\"\n#include \"../../data-structure-2d/wavelet-matrix.hpp\"\
    \n\nuint64_t rng() {\n  static uint64_t x_ =\n      chrono::duration_cast<chrono::nanoseconds>(\n\
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \  .count();\n  return x_ ^= (x_ << 7), x_ ^= (x_ >> 9);\n}\n\nint randint(int\
    \ l, int r) {\n  assert(l < r);\n  return rng() % (r - l) + l;\n}\n\nvoid test(int\
    \ n, int q, bool all_zero = false, bool large = false) {\n  assert(n > 0);\n \
    \ WaveletMatrix<int> wm(n);\n  vector<int> v(n, 0);\n  vector<int> buffer;\n\n\
    \  if (large) {\n    for (int i = 0; i < n; ++i) v[i] = randint(0, 1 << 30);\n\
    \  } else if (!all_zero) {\n    iota(begin(v), end(v), 0);\n  }\n\n  mt19937_64\
    \ mt;\n  shuffle(begin(v), end(v), mt);\n  for (int i = n; i--;) wm.set(i, v[i]);\n\
    \  wm.build();\n\n  // access\n  for (int Q = q; Q--;) {\n    int i = randint(0,\
    \ n);\n    assert(wm.access(i) == v[i]);\n  }\n\n  // kth-smallest / kth-largest\n\
    \  for (int Q = q; Q--;) {\n    int len = randint(1, n + 1);\n    int l = randint(0,\
    \ n - len + 1);\n    int r = l + len;\n    int k = randint(0, len);\n\n    buffer.clear();\n\
    \    copy(begin(v) + l, begin(v) + r, back_inserter(buffer));\n    sort(begin(buffer),\
    \ end(buffer));\n\n    assert(wm.kth_smallest(l, r, k) == buffer[k]);\n    assert(wm.kth_largest(l,\
    \ r, k) == buffer[len - k - 1]);\n  }\n\n  // range-freq\n  for (int Q = q; Q--;)\
    \ {\n    int len = randint(1, n + 1);\n    int l = randint(0, n - len + 1);\n\
    \    int r = l + len;\n    int lower, upper;\n    do {\n      lower = randint(0,\
    \ n + 5);\n      upper = randint(0, n + 5);\n      if (lower > upper) swap(lower,\
    \ upper);\n    } while (lower != upper);\n\n    buffer.clear();\n    copy(begin(v)\
    \ + l, begin(v) + r, back_inserter(buffer));\n    sort(begin(buffer), end(buffer));\n\
    \n    int up = lower_bound(begin(buffer), end(buffer), upper) - begin(buffer);\n\
    \    assert(wm.range_freq(l, r, upper) == up);\n    int lo = lower_bound(begin(buffer),\
    \ end(buffer), lower) - begin(buffer);\n    assert(wm.range_freq(l, r, lower,\
    \ upper) == up - lo);\n\n    int pv = len - 1;\n    while (pv != -1 and buffer[pv]\
    \ >= upper) --pv;\n    assert(wm.prev_value(l, r, upper) == (pv == -1 ? -1 : buffer[pv]));\n\
    \n    int nv = 0;\n    while (nv != len and buffer[nv] < lower) ++nv;\n    assert(wm.next_value(l,\
    \ r, lower) == (nv == len ? -1 : buffer[nv]));\n  }\n}\n\nvoid Nyaan::solve()\
    \ {\n  test(63, 1000);\n  test(64, 1000);\n  test(65, 1000);\n  test(63, 1000,\
    \ true);\n  test(64, 1000, true);\n  test(65, 1000, true);\n  test(63, 1000, false,\
    \ true);\n  test(64, 1000, false, true);\n  test(65, 1000, false, true);\n  for\
    \ (int i = 100; i--;) {\n    test(1, 1);\n    test(1, 1, true);\n    test(1, 1,\
    \ false, true);\n    test(2, 10);\n    test(2, 10, true);\n    test(2, 10, false,\
    \ true);\n  }\n\n  test(65535, 10);\n  test(65536, 10);\n  test(65537, 10);\n\
    \  test(65535, 10, false, true);\n  test(65536, 10, false, true);\n  test(65537,\
    \ 10, false, true);\n  \n  int a, b;\n  cin >> a >> b;\n  cout << (a + b) << endl;\n\
    }"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - data-structure-2d/wavelet-matrix.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/wavelet-matrix.test.cpp
  requiredBy: []
  timestamp: '2023-08-10 13:25:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/wavelet-matrix.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/wavelet-matrix.test.cpp
- /verify/verify/verify-unit-test/wavelet-matrix.test.cpp.html
title: verify/verify-unit-test/wavelet-matrix.test.cpp
---
