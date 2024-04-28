---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/parallel-union-find.hpp
    title: data-structure/parallel-union-find.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find-enumerate.hpp
    title: data-structure/union-find-enumerate.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find.hpp
    title: Union Find(Disjoint Set Union)
  - icon: ':heavy_check_mark:'
    path: internal/internal-hash.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: internal/internal-seed.hpp
    title: internal/internal-seed.hpp
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash-on-segment-tree.hpp
    title: string/rolling-hash-on-segment-tree.hpp
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
  bundledCode: "#line 1 \"verify/verify-unit-test/parallel-union-find.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#line 2 \"template/template.hpp\"\
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
    \ 4 \"verify/verify-unit-test/parallel-union-find.test.cpp\"\n//\n#line 2 \"data-structure/parallel-union-find.hpp\"\
    \n\n#line 2 \"string/rolling-hash-on-segment-tree.hpp\"\n\n#line 4 \"string/rolling-hash-on-segment-tree.hpp\"\
    \nusing namespace std;\n\n#line 1 \"atcoder/segtree.hpp\"\n\n\n\n#line 7 \"atcoder/segtree.hpp\"\
    \n\n#line 1 \"atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n#include <intrin.h>\n\
    #endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n// @param n `0 <= n`\n\
    // @return minimum non-negative `x` s.t. `n <= 2**x`\nint ceil_pow2(int n) {\n\
    \    int x = 0;\n    while ((1U << x) < (unsigned int)(n)) x++;\n    return x;\n\
    }\n\n// @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 <<\
    \ x)) != 0`\nconstexpr int bsf_constexpr(unsigned int n) {\n    int x = 0;\n \
    \   while (!(n & (1 << x))) x++;\n    return x;\n}\n\n// @param n `1 <= n`\n//\
    \ @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\nint bsf(unsigned\
    \ int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n    _BitScanForward(&index,\
    \ n);\n    return index;\n#else\n    return __builtin_ctz(n);\n#endif\n}\n\n}\
    \  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 9 \"atcoder/segtree.hpp\"\
    \n\nnamespace atcoder {\n\ntemplate <class S, S (*op)(S, S), S (*e)()> struct\
    \ segtree {\n  public:\n    segtree() : segtree(0) {}\n    segtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\n    segtree(const std::vector<S>& v) : _n(int(v.size())) {\n     \
    \   log = internal::ceil_pow2(_n);\n        size = 1 << log;\n        d = std::vector<S>(2\
    \ * size, e());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n  \
    \      for (int i = size - 1; i >= 1; i--) {\n            update(i);\n       \
    \ }\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n\
    \        p += size;\n        d[p] = x;\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n\
    \        return d[p + size];\n    }\n\n    S prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        S sml = e(), smr = e();\n        l += size;\n\
    \        r += size;\n\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S\
    \ all_prod() { return d[1]; }\n\n    template <bool (*f)(S)> int max_right(int\
    \ l) {\n        return max_right(l, [](S x) { return f(x); });\n    }\n    template\
    \ <class F> int max_right(int l, F f) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(f(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n\
    \            if (!f(op(sm, d[l]))) {\n                while (l < size) {\n   \
    \                 l = (2 * l);\n                    if (f(op(sm, d[l]))) {\n \
    \                       sm = op(sm, d[l]);\n                        l++;\n   \
    \                 }\n                }\n                return l - size;\n   \
    \         }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*f)(S)> int\
    \ min_left(int r) {\n        return min_left(r, [](S x) { return f(x); });\n \
    \   }\n    template <class F> int min_left(int r, F f) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(f(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        S sm = e();\n        do {\n            r--;\n      \
    \      while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n\
    \                while (r < size) {\n                    r = (2 * r + 1);\n  \
    \                  if (f(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n  private:\n\
    \    int _n, size, log;\n    std::vector<S> d;\n\n    void update(int k) { d[k]\
    \ = op(d[2 * k], d[2 * k + 1]); }\n};\n\n}  // namespace atcoder\n\n\n#line 2\
    \ \"internal/internal-hash.hpp\"\n\nnamespace internal {\nusing i64 = long long;\n\
    using u64 = unsigned long long;\nusing u128 = __uint128_t;\n\ntemplate <int BASE_NUM\
    \ = 2>\nstruct Hash : array<u64, BASE_NUM> {\n  using array<u64, BASE_NUM>::operator[];\n\
    \  static constexpr int n = BASE_NUM;\n\n  Hash() : array<u64, BASE_NUM>() {}\n\
    \n  static constexpr u64 md = (1ull << 61) - 1;\n\n  constexpr static Hash set(const\
    \ i64 &a) {\n    Hash res;\n    fill(begin(res), end(res), cast(a));\n    return\
    \ res;\n  }\n  Hash &operator+=(const Hash &r) {\n    for (int i = 0; i < n; i++)\n\
    \      if (((*this)[i] += r[i]) >= md) (*this)[i] -= md;\n    return *this;\n\
    \  }\n  Hash &operator+=(const i64 &r) {\n    u64 s = cast(r);\n    for (int i\
    \ = 0; i < n; i++)\n      if (((*this)[i] += s) >= md) (*this)[i] -= md;\n   \
    \ return *this;\n  }\n  Hash &operator-=(const Hash &r) {\n    for (int i = 0;\
    \ i < n; i++)\n      if (((*this)[i] += md - r[i]) >= md) (*this)[i] -= md;\n\
    \    return *this;\n  }\n  Hash &operator-=(const i64 &r) {\n    u64 s = cast(r);\n\
    \    for (int i = 0; i < n; i++)\n      if (((*this)[i] += md - s) >= md) (*this)[i]\
    \ -= md;\n    return *this;\n  }\n  Hash &operator*=(const Hash &r) {\n    for\
    \ (int i = 0; i < n; i++) (*this)[i] = modmul((*this)[i], r[i]);\n    return *this;\n\
    \  }\n  Hash &operator*=(const i64 &r) {\n    u64 s = cast(r);\n    for (int i\
    \ = 0; i < n; i++) (*this)[i] = modmul((*this)[i], s);\n    return *this;\n  }\n\
    \n  Hash operator+(const Hash &r) { return Hash(*this) += r; }\n  Hash operator+(const\
    \ i64 &r) { return Hash(*this) += r; }\n  Hash operator-(const Hash &r) { return\
    \ Hash(*this) -= r; }\n  Hash operator-(const i64 &r) { return Hash(*this) -=\
    \ r; }\n  Hash operator*(const Hash &r) { return Hash(*this) *= r; }\n  Hash operator*(const\
    \ i64 &r) { return Hash(*this) *= r; }\n  Hash operator-() const {\n    Hash res;\n\
    \    for (int i = 0; i < n; i++) res[i] = (*this)[i] == 0 ? 0 : md - (*this)[i];\n\
    \    return res;\n  }\n  friend Hash pfma(const Hash &a, const Hash &b, const\
    \ Hash &c) {\n    Hash res;\n    for (int i = 0; i < n; i++) res[i] = modfma(a[i],\
    \ b[i], c[i]);\n    return res;\n  }\n  friend Hash pfma(const Hash &a, const\
    \ Hash &b, const i64 &c) {\n    Hash res;\n    u64 s = cast(c);\n    for (int\
    \ i = 0; i < n; i++) res[i] = modfma(a[i], b[i], s);\n    return res;\n  }\n\n\
    \  Hash pow(long long e) {\n    Hash a{*this}, res{Hash::set(1)};\n    for (;\
    \ e; a *= a, e >>= 1) {\n      if (e & 1) res *= a;\n    }\n    return res;\n\
    \  }\n\n  static Hash get_basis() {\n    static auto rand_time =\n        chrono::duration_cast<chrono::nanoseconds>(\n\
    \            chrono::high_resolution_clock::now().time_since_epoch())\n      \
    \      .count();\n    static mt19937_64 rng(rand_time);\n    Hash h;\n    for\
    \ (int i = 0; i < n; i++) {\n      while (isPrimitive(h[i] = rng() % (md - 1)\
    \ + 1) == false)\n        ;\n    }\n    return h;\n  }\n\n private:\n  static\
    \ u64 modpow(u64 a, u64 b) {\n    u64 r = 1;\n    for (a %= md; b; a = modmul(a,\
    \ a), b >>= 1) r = modmul(r, a);\n    return r;\n  }\n  static bool isPrimitive(u64\
    \ x) {\n    for (auto &d : vector<u64>{2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331,\
    \ 1321})\n      if (modpow(x, (md - 1) / d) <= 1) return false;\n    return true;\n\
    \  }\n  static inline constexpr u64 cast(const long long &a) {\n    return a <\
    \ 0 ? a + md : a;\n  }\n  static inline constexpr u64 modmul(const u64 &a, const\
    \ u64 &b) { \n    u128 d = u128(a) * b;\n    u64 ret = (u64(d) & md) + u64(d >>\
    \ 61);\n    return ret >= md ? ret - md : ret;\n  }\n  static inline constexpr\
    \ u64 modfma(const u64 &a, const u64 &b, const u64 &c) {\n    u128 d = u128(a)\
    \ * b + c;\n    u64 ret = (d >> 61) + (u64(d) & md);\n    return ret >= md ? ret\
    \ - md : ret;\n  }\n};\n\n}  // namespace internal\n\n/**\n * @brief \u30CF\u30C3\
    \u30B7\u30E5\u69CB\u9020\u4F53\n * @docs docs/internal/internal-hash.md\n */\n\
    #line 8 \"string/rolling-hash-on-segment-tree.hpp\"\n\nnamespace RollingHashonSegmentTreeImpl\
    \ {\n\nconstexpr int BASE_NUM = 1;\nusing Hash = internal::Hash<BASE_NUM>;\nusing\
    \ T = pair<Hash, int>;\n\nvector<Hash> Pow{Hash::set(1)};\nconst Hash Basis =\
    \ Hash::get_basis();\nconst Hash Zero = Hash::set(0);\n\nT op(T a, T b) {\n  while\
    \ (b.second >= (int)Pow.size()) {\n    Hash h = Pow.back();\n    Pow.push_back(h\
    \ * Basis);\n  }\n  Hash h = pfma(a.first, Pow[b.second], b.first);\n  int len\
    \ = a.second + b.second;\n  return make_pair(h, len);\n}\nT e() { return make_pair(Zero,\
    \ 0); }\n\ntemplate <typename Str>\nstruct RollingHashonSegmentTree {\n  using\
    \ Value = typename Str::value_type;\n  int n;\n  atcoder::segtree<T, op, e> seg;\n\
    \n  RollingHashonSegmentTree() : n(0) {}\n\n  RollingHashonSegmentTree(const Str&\
    \ S) : n(S.size()) {\n    vector<T> init(n);\n    for (int i = 0; i < n; i++)\
    \ {\n      init[i] = make_pair(Hash::set(S[i]), 1);\n    }\n    seg = {init};\n\
    \  }\n\n  void update(int i, const Value& v) {\n    assert(0 <= i and i < n);\n\
    \    seg.set(i, make_pair(Hash::set(v), 1));\n  }\n\n  // [l1, r1) \u3068 [l2,\
    \ r2) \u304C\u4E00\u81F4\u3059\u308B\u304B\u3092\u5224\u5B9A\n  bool same(int\
    \ l1, int r1, int l2, int r2) {\n    assert(0 <= l1 and l1 <= r1 and r1 <= n);\n\
    \    assert(0 <= l2 and l2 <= r2 and r2 <= n);\n    if (r1 - l1 != r2 - l2) return\
    \ false;\n    return seg.prod(l1, r1) == seg.prod(l2, r2);\n  }\n};\n}  // namespace\
    \ RollingHashonSegmentTreeImpl\n\nusing RollingHashonSegmentTreeImpl::RollingHashonSegmentTree;\n\
    #line 2 \"data-structure/union-find-enumerate.hpp\"\n\n#line 4 \"data-structure/union-find-enumerate.hpp\"\
    \nusing namespace std;\n\nstruct UnionFindEnumerate {\n  vector<int> data, nxt;\n\
    \  UnionFindEnumerate(int N) : data(N, -1), nxt(N) {\n    for (int i = 0; i <\
    \ N; i++) nxt[i] = i;\n  }\n\n  int find(int k) { return data[k] < 0 ? k : data[k]\
    \ = find(data[k]); }\n\n  int unite(int x, int y) {\n    if ((x = find(x)) ==\
    \ (y = find(y))) return false;\n    if (data[x] > data[y]) swap(x, y);\n    data[x]\
    \ += data[y];\n    data[y] = x;\n    swap(nxt[x], nxt[y]);\n    return true;\n\
    \  }\n\n  // f(x, y) : x \u306B y \u3092\u30DE\u30FC\u30B8\n  template <typename\
    \ F>\n  int unite(int x, int y, const F &f) {\n    if ((x = find(x)) == (y = find(y)))\
    \ return false;\n    if (data[x] > data[y]) swap(x, y);\n    data[x] += data[y];\n\
    \    data[y] = x;\n    f(x, y);\n    swap(nxt[x], nxt[y]);\n    return true;\n\
    \  }\n\n  int size(int k) { return -data[find(k)]; }\n\n  int same(int x, int\
    \ y) { return find(x) == find(y); }\n\n  vector<int> enumerate(int i) {\n    vector<int>\
    \ res{i};\n    for (int j = nxt[i]; j != i; j = nxt[j]) res.push_back(j);\n  \
    \  return res;\n  }\n};\n#line 5 \"data-structure/parallel-union-find.hpp\"\n\n\
    struct ParallelUnionFind {\n  int n;\n  UnionFindEnumerate uf;\n  RollingHashonSegmentTree<vector<int>>\
    \ seg;\n\n  ParallelUnionFind(int _n) : n(_n), uf(n) {\n    vector<int> init(n);\n\
    \    for (int i = 0; i < n; i++) init[i] = i;\n    seg = {init};\n  }\n\n  //\
    \ [l1, r1) \u3068 [l2, r2) \u3092 unite \u3059\u308B\n  void unite(int l1, int\
    \ r1, int l2, int r2) {\n    assert(0 <= l1 and l1 <= r1 and r1 <= n);\n    assert(0\
    \ <= l2 and l2 <= r2 and r2 <= n);\n    assert(r1 - l1 == r2 - l2);\n    while\
    \ (1) {\n      if (seg.same(l1, r1, l2, r2)) break;\n      int ok = 0, ng = r1\
    \ - l1;\n      while (ok + 1 < ng) {\n        int m = (ok + ng) / 2;\n       \
    \ (seg.same(l1, l1 + m, l2, l2 + m) ? ok : ng) = m;\n      }\n      uf.unite(l1\
    \ + ok, l2 + ok, [&](int x, int y) {\n        for (int z : uf.enumerate(y)) seg.update(z,\
    \ x);\n      });\n    }\n  }\n  void unite(int l, int r) { unite(l, l + 1, r,\
    \ r + 1); }\n  int find(int i) { return uf.find(i); }\n  int same(int l, int r)\
    \ { return uf.same(l, r); }\n  int size(int i) { return uf.size(i); }\n};\n#line\
    \ 2 \"data-structure/union-find.hpp\"\n\nstruct UnionFind {\n  vector<int> data;\n\
    \  UnionFind(int N) : data(N, -1) {}\n\n  int find(int k) { return data[k] < 0\
    \ ? k : data[k] = find(data[k]); }\n\n  int unite(int x, int y) {\n    if ((x\
    \ = find(x)) == (y = find(y))) return false;\n    if (data[x] > data[y]) swap(x,\
    \ y);\n    data[x] += data[y];\n    data[y] = x;\n    return true;\n  }\n\n  //\
    \ f ... merge function\n  template<typename F>\n  int unite(int x, int y,const\
    \ F &f) {\n    if ((x = find(x)) == (y = find(y))) return false;\n    if (data[x]\
    \ > data[y]) swap(x, y);\n    data[x] += data[y];\n    data[y] = x;\n    f(x,\
    \ y);\n    return true;\n  }\n\n  int size(int k) { return -data[find(k)]; }\n\
    \n  int same(int x, int y) { return find(x) == find(y); }\n};\n\n/**\n * @brief\
    \ Union Find(Disjoint Set Union)\n * @docs docs/data-structure/union-find.md\n\
    \ */\n#line 2 \"misc/rng.hpp\"\n\n#line 2 \"internal/internal-seed.hpp\"\n\n#line\
    \ 4 \"internal/internal-seed.hpp\"\nusing namespace std;\n\nnamespace internal\
    \ {\nunsigned long long non_deterministic_seed() {\n  unsigned long long m =\n\
    \      chrono::duration_cast<chrono::nanoseconds>(\n          chrono::high_resolution_clock::now().time_since_epoch())\n\
    \          .count();\n  m ^= 9845834732710364265uLL;\n  m ^= m << 24, m ^= m >>\
    \ 31, m ^= m << 35;\n  return m;\n}\nunsigned long long deterministic_seed() {\
    \ return 88172645463325252UL; }\n\n// 64 bit \u306E seed \u5024\u3092\u751F\u6210\
    \ (\u624B\u5143\u3067\u306F seed \u56FA\u5B9A)\n// \u9023\u7D9A\u3067\u547C\u3073\
    \u51FA\u3059\u3068\u540C\u3058\u5024\u304C\u4F55\u5EA6\u3082\u8FD4\u3063\u3066\
    \u304F\u308B\u306E\u3067\u6CE8\u610F\n// #define RANDOMIZED_SEED \u3059\u308B\u3068\
    \u30B7\u30FC\u30C9\u304C\u30E9\u30F3\u30C0\u30E0\u306B\u306A\u308B\nunsigned long\
    \ long seed() {\n#if defined(NyaanLocal) && !defined(RANDOMIZED_SEED)\n  return\
    \ deterministic_seed();\n#else\n  return non_deterministic_seed();\n#endif\n}\n\
    \n}  // namespace internal\n#line 4 \"misc/rng.hpp\"\n\nnamespace my_rand {\n\
    using i64 = long long;\nusing u64 = unsigned long long;\n\n// [0, 2^64 - 1)\n\
    u64 rng() {\n  static u64 _x = internal::seed();\n  return _x ^= _x << 7, _x ^=\
    \ _x >> 9;\n}\n\n// [l, r]\ni64 rng(i64 l, i64 r) {\n  assert(l <= r);\n  return\
    \ l + rng() % u64(r - l + 1);\n}\n\n// [l, r)\ni64 randint(i64 l, i64 r) {\n \
    \ assert(l < r);\n  return l + rng() % u64(r - l);\n}\n\n// choose n numbers from\
    \ [l, r) without overlapping\nvector<i64> randset(i64 l, i64 r, i64 n) {\n  assert(l\
    \ <= r && n <= r - l);\n  unordered_set<i64> s;\n  for (i64 i = n; i; --i) {\n\
    \    i64 m = randint(l, r + 1 - i);\n    if (s.find(m) != s.end()) m = r - i;\n\
    \    s.insert(m);\n  }\n  vector<i64> ret;\n  for (auto& x : s) ret.push_back(x);\n\
    \  sort(begin(ret), end(ret));\n  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd()\
    \ { return rng() * 5.42101086242752217004e-20; }\n// [l, r)\ndouble rnd(double\
    \ l, double r) {\n  assert(l < r);\n  return l + rnd() * (r - l);\n}\n\ntemplate\
    \ <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n  for (int\
    \ i = 1; i < n; i++) swap(v[i], v[randint(0, i + 1)]);\n}\n\n}  // namespace my_rand\n\
    \nusing my_rand::randint;\nusing my_rand::randset;\nusing my_rand::randshf;\n\
    using my_rand::rnd;\nusing my_rand::rng;\n#line 8 \"verify/verify-unit-test/parallel-union-find.test.cpp\"\
    \nusing namespace Nyaan;\n\nvoid test() {\n  rep(t, 1000) {\n    int N = rng(1,\
    \ 50);\n    UnionFind uf(N);\n    ParallelUnionFind puf(N);\n\n    rep(u, 100)\
    \ {\n      int len = rng(0, N);\n      int l = rng(0, N - len);\n      int r =\
    \ rng(0, N - len);\n      rep(i, len) uf.unite(l + i, r + i);\n      puf.unite(l,\
    \ l + len, r, r + len);\n      rep(i, N) rep(j, i) assert(uf.same(i, j) == puf.same(i,\
    \ j));\n    }\n  }\n  trc2(\"OK\");\n}\n\nvoid q() {\n  test();\n\n  int a, b;\n\
    \  cin >> a >> b;\n  cout << a + b << endl;\n}\n\nvoid Nyaan::solve() {\n  int\
    \ t = 1;\n  // in(t);\n  while (t--) q();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../data-structure/parallel-union-find.hpp\"\
    \n#include \"../../data-structure/union-find.hpp\"\n#include \"../../misc/rng.hpp\"\
    \nusing namespace Nyaan;\n\nvoid test() {\n  rep(t, 1000) {\n    int N = rng(1,\
    \ 50);\n    UnionFind uf(N);\n    ParallelUnionFind puf(N);\n\n    rep(u, 100)\
    \ {\n      int len = rng(0, N);\n      int l = rng(0, N - len);\n      int r =\
    \ rng(0, N - len);\n      rep(i, len) uf.unite(l + i, r + i);\n      puf.unite(l,\
    \ l + len, r, r + len);\n      rep(i, N) rep(j, i) assert(uf.same(i, j) == puf.same(i,\
    \ j));\n    }\n  }\n  trc2(\"OK\");\n}\n\nvoid q() {\n  test();\n\n  int a, b;\n\
    \  cin >> a >> b;\n  cout << a + b << endl;\n}\n\nvoid Nyaan::solve() {\n  int\
    \ t = 1;\n  // in(t);\n  while (t--) q();\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - data-structure/parallel-union-find.hpp
  - string/rolling-hash-on-segment-tree.hpp
  - internal/internal-hash.hpp
  - data-structure/union-find-enumerate.hpp
  - data-structure/union-find.hpp
  - misc/rng.hpp
  - internal/internal-seed.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/parallel-union-find.test.cpp
  requiredBy: []
  timestamp: '2024-04-28 09:13:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/parallel-union-find.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/parallel-union-find.test.cpp
- /verify/verify/verify-unit-test/parallel-union-find.test.cpp.html
title: verify/verify-unit-test/parallel-union-find.test.cpp
---
