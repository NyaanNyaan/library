---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse-table.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: internal/internal-hash.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash.hpp
    title: Rolling Hash
  - icon: ':heavy_check_mark:'
    path: string/string-search.hpp
    title: string/string-search.hpp
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
  bundledCode: "#line 1 \"verify/verify-unit-test/string-search.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#line 2 \"template/template.hpp\"\
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
    \ N,F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n  sort(begin(ord),\
    \ end(ord), f);\n  return ord;\n}\n\ntemplate <typename T>\nvector<int> mkinv(vector<T>\
    \ &v) {\n  int max_val = *max_element(begin(v), end(v));\n  vector<int> inv(max_val\
    \ + 1, -1);\n  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;\n  return\
    \ inv;\n}\n\nvector<int> mkiota(int n) {\n  vector<int> ret(n);\n  iota(begin(ret),\
    \ end(ret), 0);\n  return ret;\n}\n\ntemplate <typename T>\nT mkrev(const T &v)\
    \ {\n  T w{v};\n  reverse(begin(w), end(w));\n  return w;\n}\n\ntemplate <typename\
    \ T>\nbool nxp(vector<T> &v) {\n  return next_permutation(begin(v), end(v));\n\
    }\n\ntemplate <typename T>\nusing minpq = priority_queue<T, vector<T>, greater<T>>;\n\
    \n}  // namespace Nyaan\n#line 58 \"template/template.hpp\"\n\n// bit operation\n\
    #line 1 \"template/bitop.hpp\"\nnamespace Nyaan {\n__attribute__((target(\"popcnt\"\
    ))) inline int popcnt(const u64 &a) {\n  return _mm_popcnt_u64(a);\n}\ninline\
    \ int lsb(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }\ninline int ctz(const\
    \ u64 &a) { return a ? __builtin_ctzll(a) : 64; }\ninline int msb(const u64 &a)\
    \ { return a ? 63 - __builtin_clzll(a) : -1; }\ntemplate <typename T>\ninline\
    \ int gbit(const T &a, int i) {\n  return (a >> i) & 1;\n}\ntemplate <typename\
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
    \ for (auto &x : v) is >> x;\n  return is;\n}\n\nistream &operator>>(istream &is,\
    \ __int128_t &x) {\n  string S;\n  is >> S;\n  x = 0;\n  int flag = 0;\n  for\
    \ (auto &c : S) {\n    if (c == '-') {\n      flag = true;\n      continue;\n\
    \    }\n    x *= 10;\n    x += c - '0';\n  }\n  if (flag) x = -x;\n  return is;\n\
    }\n\nistream &operator>>(istream &is, __uint128_t &x) {\n  string S;\n  is >>\
    \ S;\n  x = 0;\n  for (auto &c : S) {\n    x *= 10;\n    x += c - '0';\n  }\n\
    \  return is;\n}\n\nostream &operator<<(ostream &os, __int128_t x) {\n  if (x\
    \ == 0) return os << 0;\n  if (x < 0) os << '-', x = -x;\n  string S;\n  while\
    \ (x) S.push_back('0' + x % 10), x /= 10;\n  reverse(begin(S), end(S));\n  return\
    \ os << S;\n}\nostream &operator<<(ostream &os, __uint128_t x) {\n  if (x == 0)\
    \ return os << 0;\n  string S;\n  while (x) S.push_back('0' + x % 10), x /= 10;\n\
    \  reverse(begin(S), end(S));\n  return os << S;\n}\n\nvoid in() {}\ntemplate\
    \ <typename T, class... U>\nvoid in(T &t, U &...u) {\n  cin >> t;\n  in(u...);\n\
    }\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename T, class... U, char sep\
    \ = ' '>\nvoid out(const T &t, const U &...u) {\n  cout << t;\n  if (sizeof...(u))\
    \ cout << sep;\n  out(u...);\n}\n\nstruct IoSetupNya {\n  IoSetupNya() {\n   \
    \ cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(15);\n\
    \    cerr << fixed << setprecision(7);\n  }\n} iosetupnya;\n\n}  // namespace\
    \ Nyaan\n#line 64 \"template/template.hpp\"\n\n// debug\n#line 1 \"template/debug.hpp\"\
    \nnamespace DebugImpl {\n\ntemplate <typename U, typename = void>\nstruct is_specialize\
    \ : false_type {};\ntemplate <typename U>\nstruct is_specialize<\n    U, typename\
    \ conditional<false, typename U::iterator, void>::type>\n    : true_type {};\n\
    template <typename U>\nstruct is_specialize<\n    U, typename conditional<false,\
    \ decltype(U::first), void>::type>\n    : true_type {};\ntemplate <typename U>\n\
    struct is_specialize<U, enable_if_t<is_integral<U>::value, void>> : true_type\
    \ {\n};\n\nvoid dump(const char& t) { cerr << t; }\n\nvoid dump(const string&\
    \ t) { cerr << t; }\n\nvoid dump(const bool& t) { cerr << (t ? \"true\" : \"false\"\
    ); }\n\nvoid dump(__int128_t t) {\n  if (t == 0) cerr << 0;\n  if (t < 0) cerr\
    \ << '-', t = -t;\n  string S;\n  while (t) S.push_back('0' + t % 10), t /= 10;\n\
    \  reverse(begin(S), end(S));\n  cerr << S;\n}\n\nvoid dump(__uint128_t t) {\n\
    \  if (t == 0) cerr << 0;\n  string S;\n  while (t) S.push_back('0' + t % 10),\
    \ t /= 10;\n  reverse(begin(S), end(S));\n  cerr << S;\n}\n\ntemplate <typename\
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
    \ 4 \"verify/verify-unit-test/string-search.test.cpp\"\n//\n#line 2 \"string/string-search.hpp\"\
    \n\n#line 1 \"atcoder/string.hpp\"\n\n\n\n#line 9 \"atcoder/string.hpp\"\n\nnamespace\
    \ atcoder {\n\nnamespace internal {\n\nstd::vector<int> sa_naive(const std::vector<int>&\
    \ s) {\n    int n = int(s.size());\n    std::vector<int> sa(n);\n    std::iota(sa.begin(),\
    \ sa.end(), 0);\n    std::sort(sa.begin(), sa.end(), [&](int l, int r) {\n   \
    \     if (l == r) return false;\n        while (l < n && r < n) {\n          \
    \  if (s[l] != s[r]) return s[l] < s[r];\n            l++;\n            r++;\n\
    \        }\n        return l == n;\n    });\n    return sa;\n}\n\nstd::vector<int>\
    \ sa_doubling(const std::vector<int>& s) {\n    int n = int(s.size());\n    std::vector<int>\
    \ sa(n), rnk = s, tmp(n);\n    std::iota(sa.begin(), sa.end(), 0);\n    for (int\
    \ k = 1; k < n; k *= 2) {\n        auto cmp = [&](int x, int y) {\n          \
    \  if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];\n            int rx = x + k <\
    \ n ? rnk[x + k] : -1;\n            int ry = y + k < n ? rnk[y + k] : -1;\n  \
    \          return rx < ry;\n        };\n        std::sort(sa.begin(), sa.end(),\
    \ cmp);\n        tmp[sa[0]] = 0;\n        for (int i = 1; i < n; i++) {\n    \
    \        tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);\n    \
    \    }\n        std::swap(tmp, rnk);\n    }\n    return sa;\n}\n\n// SA-IS, linear-time\
    \ suffix array construction\n// Reference:\n// G. Nong, S. Zhang, and W. H. Chan,\n\
    // Two Efficient Algorithms for Linear Time Suffix Array Construction\ntemplate\
    \ <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>\nstd::vector<int> sa_is(const\
    \ std::vector<int>& s, int upper) {\n    int n = int(s.size());\n    if (n ==\
    \ 0) return {};\n    if (n == 1) return {0};\n    if (n == 2) {\n        if (s[0]\
    \ < s[1]) {\n            return {0, 1};\n        } else {\n            return\
    \ {1, 0};\n        }\n    }\n    if (n < THRESHOLD_NAIVE) {\n        return sa_naive(s);\n\
    \    }\n    if (n < THRESHOLD_DOUBLING) {\n        return sa_doubling(s);\n  \
    \  }\n\n    std::vector<int> sa(n);\n    std::vector<bool> ls(n);\n    for (int\
    \ i = n - 2; i >= 0; i--) {\n        ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] :\
    \ (s[i] < s[i + 1]);\n    }\n    std::vector<int> sum_l(upper + 1), sum_s(upper\
    \ + 1);\n    for (int i = 0; i < n; i++) {\n        if (!ls[i]) {\n          \
    \  sum_s[s[i]]++;\n        } else {\n            sum_l[s[i] + 1]++;\n        }\n\
    \    }\n    for (int i = 0; i <= upper; i++) {\n        sum_s[i] += sum_l[i];\n\
    \        if (i < upper) sum_l[i + 1] += sum_s[i];\n    }\n\n    auto induce =\
    \ [&](const std::vector<int>& lms) {\n        std::fill(sa.begin(), sa.end(),\
    \ -1);\n        std::vector<int> buf(upper + 1);\n        std::copy(sum_s.begin(),\
    \ sum_s.end(), buf.begin());\n        for (auto d : lms) {\n            if (d\
    \ == n) continue;\n            sa[buf[s[d]]++] = d;\n        }\n        std::copy(sum_l.begin(),\
    \ sum_l.end(), buf.begin());\n        sa[buf[s[n - 1]]++] = n - 1;\n        for\
    \ (int i = 0; i < n; i++) {\n            int v = sa[i];\n            if (v >=\
    \ 1 && !ls[v - 1]) {\n                sa[buf[s[v - 1]]++] = v - 1;\n         \
    \   }\n        }\n        std::copy(sum_l.begin(), sum_l.end(), buf.begin());\n\
    \        for (int i = n - 1; i >= 0; i--) {\n            int v = sa[i];\n    \
    \        if (v >= 1 && ls[v - 1]) {\n                sa[--buf[s[v - 1] + 1]] =\
    \ v - 1;\n            }\n        }\n    };\n\n    std::vector<int> lms_map(n +\
    \ 1, -1);\n    int m = 0;\n    for (int i = 1; i < n; i++) {\n        if (!ls[i\
    \ - 1] && ls[i]) {\n            lms_map[i] = m++;\n        }\n    }\n    std::vector<int>\
    \ lms;\n    lms.reserve(m);\n    for (int i = 1; i < n; i++) {\n        if (!ls[i\
    \ - 1] && ls[i]) {\n            lms.push_back(i);\n        }\n    }\n\n    induce(lms);\n\
    \n    if (m) {\n        std::vector<int> sorted_lms;\n        sorted_lms.reserve(m);\n\
    \        for (int v : sa) {\n            if (lms_map[v] != -1) sorted_lms.push_back(v);\n\
    \        }\n        std::vector<int> rec_s(m);\n        int rec_upper = 0;\n \
    \       rec_s[lms_map[sorted_lms[0]]] = 0;\n        for (int i = 1; i < m; i++)\
    \ {\n            int l = sorted_lms[i - 1], r = sorted_lms[i];\n            int\
    \ end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;\n            int end_r\
    \ = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;\n            bool same = true;\n\
    \            if (end_l - l != end_r - r) {\n                same = false;\n  \
    \          } else {\n                while (l < end_l) {\n                   \
    \ if (s[l] != s[r]) {\n                        break;\n                    }\n\
    \                    l++;\n                    r++;\n                }\n     \
    \           if (l == n || s[l] != s[r]) same = false;\n            }\n       \
    \     if (!same) rec_upper++;\n            rec_s[lms_map[sorted_lms[i]]] = rec_upper;\n\
    \        }\n\n        auto rec_sa =\n            sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s,\
    \ rec_upper);\n\n        for (int i = 0; i < m; i++) {\n            sorted_lms[i]\
    \ = lms[rec_sa[i]];\n        }\n        induce(sorted_lms);\n    }\n    return\
    \ sa;\n}\n\n}  // namespace internal\n\nstd::vector<int> suffix_array(const std::vector<int>&\
    \ s, int upper) {\n    assert(0 <= upper);\n    for (int d : s) {\n        assert(0\
    \ <= d && d <= upper);\n    }\n    auto sa = internal::sa_is(s, upper);\n    return\
    \ sa;\n}\n\ntemplate <class T> std::vector<int> suffix_array(const std::vector<T>&\
    \ s) {\n    int n = int(s.size());\n    std::vector<int> idx(n);\n    iota(idx.begin(),\
    \ idx.end(), 0);\n    sort(idx.begin(), idx.end(), [&](int l, int r) { return\
    \ s[l] < s[r]; });\n    std::vector<int> s2(n);\n    int now = 0;\n    for (int\
    \ i = 0; i < n; i++) {\n        if (i && s[idx[i - 1]] != s[idx[i]]) now++;\n\
    \        s2[idx[i]] = now;\n    }\n    return internal::sa_is(s2, now);\n}\n\n\
    std::vector<int> suffix_array(const std::string& s) {\n    int n = int(s.size());\n\
    \    std::vector<int> s2(n);\n    for (int i = 0; i < n; i++) {\n        s2[i]\
    \ = s[i];\n    }\n    return internal::sa_is(s2, 255);\n}\n\n// Reference:\n//\
    \ T. Kasai, G. Lee, H. Arimura, S. Arikawa, and K. Park,\n// Linear-Time Longest-Common-Prefix\
    \ Computation in Suffix Arrays and Its\n// Applications\ntemplate <class T>\n\
    std::vector<int> lcp_array(const std::vector<T>& s,\n                        \
    \   const std::vector<int>& sa) {\n    int n = int(s.size());\n    assert(n >=\
    \ 1);\n    std::vector<int> rnk(n);\n    for (int i = 0; i < n; i++) {\n     \
    \   rnk[sa[i]] = i;\n    }\n    std::vector<int> lcp(n - 1);\n    int h = 0;\n\
    \    for (int i = 0; i < n; i++) {\n        if (h > 0) h--;\n        if (rnk[i]\
    \ == 0) continue;\n        int j = sa[rnk[i] - 1];\n        for (; j + h < n &&\
    \ i + h < n; h++) {\n            if (s[j + h] != s[i + h]) break;\n        }\n\
    \        lcp[rnk[i] - 1] = h;\n    }\n    return lcp;\n}\n\nstd::vector<int> lcp_array(const\
    \ std::string& s, const std::vector<int>& sa) {\n    int n = int(s.size());\n\
    \    std::vector<int> s2(n);\n    for (int i = 0; i < n; i++) {\n        s2[i]\
    \ = s[i];\n    }\n    return lcp_array(s2, sa);\n}\n\n// Reference:\n// D. Gusfield,\n\
    // Algorithms on Strings, Trees, and Sequences: Computer Science and\n// Computational\
    \ Biology\ntemplate <class T> std::vector<int> z_algorithm(const std::vector<T>&\
    \ s) {\n    int n = int(s.size());\n    if (n == 0) return {};\n    std::vector<int>\
    \ z(n);\n    z[0] = 0;\n    for (int i = 1, j = 0; i < n; i++) {\n        int&\
    \ k = z[i];\n        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);\n\
    \        while (i + k < n && s[k] == s[i + k]) k++;\n        if (j + z[j] < i\
    \ + z[i]) j = i;\n    }\n    z[0] = n;\n    return z;\n}\n\nstd::vector<int> z_algorithm(const\
    \ std::string& s) {\n    int n = int(s.size());\n    std::vector<int> s2(n);\n\
    \    for (int i = 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n    return z_algorithm(s2);\n\
    }\n\n}  // namespace atcoder\n\n\n#line 2 \"data-structure/sparse-table.hpp\"\n\
    \n#line 6 \"data-structure/sparse-table.hpp\"\nusing namespace std;\n\ntemplate\
    \ <typename T>\nstruct SparseTable {\n  inline static constexpr T INF = numeric_limits<T>::max()\
    \ / 2;\n  int N;\n  vector<vector<T> > table;\n  T f(T a, T b) { return min(a,\
    \ b); }\n  SparseTable() {}\n  SparseTable(const vector<T> &v) : N(v.size()) {\n\
    \    int b = 1;\n    while ((1 << b) <= N) ++b;\n    table.push_back(v);\n   \
    \ for (int i = 1; i < b; i++) {\n      table.push_back(vector<T>(N, INF));\n \
    \     for (int j = 0; j + (1 << i) <= N; j++) {\n        table[i][j] = f(table[i\
    \ - 1][j], table[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n  }\n  // [l, r)\n\
    \  T query(int l, int r) {\n    assert(0 <= l and l <= r and r <= N);\n    if\
    \ (l == r) return INF;\n    int b = 31 - __builtin_clz(r - l);\n    return f(table[b][l],\
    \ table[b][r - (1 << b)]);\n  }\n};\n\n/**\n * @brief Sparse Table\n */\n#line\
    \ 5 \"string/string-search.hpp\"\n\ntemplate <typename Container>\nstruct StringSearch\
    \ {\n  const Container& S;\n  int N;\n  vector<int> sa, la, invsa;\n  SparseTable<int>\
    \ sparse;\n\n  StringSearch(const Container& _s) : S(_s), N(S.size()) {\n    sa\
    \ = atcoder::suffix_array(S);\n    la = atcoder::lcp_array(S, sa);\n    invsa.resize(N);\n\
    \    for (int i = 0; i < N; i++) invsa[sa[i]] = i;\n    sparse = SparseTable<int>{la};\n\
    \  }\n\n  // lcp(s[i, N), s[j, N))\n  int lcp(int i, int j) {\n    assert(0 <=\
    \ min(i, j) and max(i, j) < N);\n    if (i == j) return N - i;\n    int x = min(invsa[i],\
    \ invsa[j]);\n    int y = max(invsa[i], invsa[j]);\n    return sparse.query(x,\
    \ y);\n  }\n  // lcp(s[a, b), s[c, d))\n  int lcp(int a, int b, int c, int d)\
    \ {\n    assert(0 <= a and a <= b and b <= N);\n    assert(0 <= c and c <= d and\
    \ d <= N);\n    int l = lcp(a, c);\n    return min({l, b - a, d - c});\n  }\n\
    \  // lcp(s[a, b), s[c, d))\n  template <typename Int>\n  int lcp(pair<Int, Int>\
    \ p, pair<Int, Int> q) {\n    return lcp(p.first, p.second, q.first, q.second);\n\
    \  }\n\n  // s[i, N) > s[j, N) : 1\n  // s[i, N) = s[j, N) : 0\n  // s[i, N) <\
    \ s[j, N) : -1\n  int strcmp(int i, int j) {\n    assert(0 <= min(i, j) and max(i,\
    \ j) < N);\n    if (i == j) return 0;\n    return invsa[i] < invsa[j] ? -1 : 1;\n\
    \  }\n\n  // s[a, b) > s[c, d) : 1\n  // s[a, b) = s[c, d) : 0\n  // s[a, b) <\
    \ s[c, d) : -1\n  int strcmp(int a, int b, int c, int d) {\n    int l = lcp(a,\
    \ b, c, d);\n    return a + l == b            ? (c + l == d ? 0 : -1)\n      \
    \     : c + l == d          ? 1\n           : S[a + l] < S[c + l] ? -1\n     \
    \                            : 1;\n  }\n  // s[a, b) > s[c, d) : 1\n  // s[a,\
    \ b) = s[c, d) : 0\n  // s[a, b) < s[c, d) : -1\n  template <typename Int>\n \
    \ int strcmp(pair<Int, Int> p, pair<Int, Int> q) {\n    return strcmp(p.first,\
    \ p.second, q.first, q.second);\n  }\n};\n#line 6 \"verify/verify-unit-test/string-search.test.cpp\"\
    \n//\n#line 2 \"string/rolling-hash.hpp\"\n\n#line 5 \"string/rolling-hash.hpp\"\
    \nusing namespace std;\n\n#line 2 \"internal/internal-hash.hpp\"\n\nnamespace\
    \ internal {\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing u128\
    \ = __uint128_t;\n\ntemplate <int BASE_NUM = 2>\nstruct Hash : array<u64, BASE_NUM>\
    \ {\n  using array<u64, BASE_NUM>::operator[];\n  static constexpr int n = BASE_NUM;\n\
    \n  Hash() : array<u64, BASE_NUM>() {}\n\n  static constexpr u64 md = (1ull <<\
    \ 61) - 1;\n\n  constexpr static Hash set(const i64 &a) {\n    Hash res;\n   \
    \ fill(begin(res), end(res), cast(a));\n    return res;\n  }\n  Hash &operator+=(const\
    \ Hash &r) {\n    for (int i = 0; i < n; i++)\n      if (((*this)[i] += r[i])\
    \ >= md) (*this)[i] -= md;\n    return *this;\n  }\n  Hash &operator+=(const i64\
    \ &r) {\n    u64 s = cast(r);\n    for (int i = 0; i < n; i++)\n      if (((*this)[i]\
    \ += s) >= md) (*this)[i] -= md;\n    return *this;\n  }\n  Hash &operator-=(const\
    \ Hash &r) {\n    for (int i = 0; i < n; i++)\n      if (((*this)[i] += md - r[i])\
    \ >= md) (*this)[i] -= md;\n    return *this;\n  }\n  Hash &operator-=(const i64\
    \ &r) {\n    u64 s = cast(r);\n    for (int i = 0; i < n; i++)\n      if (((*this)[i]\
    \ += md - s) >= md) (*this)[i] -= md;\n    return *this;\n  }\n  Hash &operator*=(const\
    \ Hash &r) {\n    for (int i = 0; i < n; i++) (*this)[i] = modmul((*this)[i],\
    \ r[i]);\n    return *this;\n  }\n  Hash &operator*=(const i64 &r) {\n    u64\
    \ s = cast(r);\n    for (int i = 0; i < n; i++) (*this)[i] = modmul((*this)[i],\
    \ s);\n    return *this;\n  }\n\n  Hash operator+(const Hash &r) { return Hash(*this)\
    \ += r; }\n  Hash operator+(const i64 &r) { return Hash(*this) += r; }\n  Hash\
    \ operator-(const Hash &r) { return Hash(*this) -= r; }\n  Hash operator-(const\
    \ i64 &r) { return Hash(*this) -= r; }\n  Hash operator*(const Hash &r) { return\
    \ Hash(*this) *= r; }\n  Hash operator*(const i64 &r) { return Hash(*this) *=\
    \ r; }\n  Hash operator-() const {\n    Hash res;\n    for (int i = 0; i < n;\
    \ i++) res[i] = (*this)[i] == 0 ? 0 : md - (*this)[i];\n    return res;\n  }\n\
    \  friend Hash pfma(const Hash &a, const Hash &b, const Hash &c) {\n    Hash res;\n\
    \    for (int i = 0; i < n; i++) res[i] = modfma(a[i], b[i], c[i]);\n    return\
    \ res;\n  }\n  friend Hash pfma(const Hash &a, const Hash &b, const i64 &c) {\n\
    \    Hash res;\n    u64 s = cast(c);\n    for (int i = 0; i < n; i++) res[i] =\
    \ modfma(a[i], b[i], s);\n    return res;\n  }\n\n  Hash pow(long long e) {\n\
    \    Hash a{*this}, res{Hash::set(1)};\n    for (; e; a *= a, e >>= 1) {\n   \
    \   if (e & 1) res *= a;\n    }\n    return res;\n  }\n\n  static Hash get_basis()\
    \ {\n    static auto rand_time =\n        chrono::duration_cast<chrono::nanoseconds>(\n\
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
    \ u64 &b) {\n    u128 ret = u128(a) * b;\n    ret = (ret & md) + (ret >> 61);\n\
    \    return ret >= md ? ret - md : ret;\n  }\n  static inline constexpr u64 modfma(const\
    \ u64 &a, const u64 &b, const u64 &c) {\n    u128 ret = u128(a) * b + c;\n   \
    \ ret = (ret & md) + (ret >> 61);\n    return ret >= md ? ret - md : ret;\n  }\n\
    };\n\n}  // namespace internal\n\n/**\n * @brief \u30CF\u30C3\u30B7\u30E5\u69CB\
    \u9020\u4F53\n * @docs docs/internal/internal-hash.md\n */\n#line 8 \"string/rolling-hash.hpp\"\
    \n\ntemplate <typename Str, int BASE_NUM = 2>\nstruct RollingHash {\n  using Hash\
    \ = internal::Hash<BASE_NUM>;\n  Str data;\n  vector<Hash> hs, pw;\n  int s;\n\
    \  static Hash basis;\n\n  RollingHash(const Str &S = Str()) { build(S); }\n\n\
    \  void build(const Str &S) {\n    data = S;\n    s = S.size();\n    hs.resize(s\
    \ + 1);\n    pw.resize(s + 1);\n    pw[0] = Hash::set(1);\n    hs[0] = Hash::set(0);\n\
    \    for (int i = 1; i <= s; i++) {\n      pw[i] = pw[i - 1] * basis;\n      hs[i]\
    \ = pfma(hs[i - 1], basis, S[i - 1]);\n    }\n  }\n\n  Hash get(int l, int r =\
    \ -1) const {\n    if (r == -1) r = s;\n    return pfma(hs[l], -pw[r - l], hs[r]);\n\
    \  }\n\n  // T \u306E hash \u3092\u8FD4\u3059\n  static Hash get_hash(const Str\
    \ &T) {\n    Hash ret = Hash::set(0);\n    for (int i = 0; i < (int)T.size();\
    \ i++) ret = pfma(ret, basis, T[i]);\n    return ret;\n  }\n\n  // a + b \u306E\
    \ hash \u3092\u8FD4\u3059\n  // \u5F15\u6570 : a, b, b \u306E\u9577\u3055\n  static\
    \ Hash unite(Hash a, Hash b, long long bsize) {\n    return pfma(a, basis.pow(bsize),\
    \ b);\n  }\n\n  int find(Str &T, int lower = 0) const {\n    auto ths = get_hash(T);\n\
    \    for (int i = lower; i <= s - (int)T.size(); i++)\n      if (ths == get(i,\
    \ i + (int)T.size())) return i;\n    return -1;\n  }\n\n  static int lcp(const\
    \ RollingHash &a, const RollingHash &b, int al, int bl) {\n    int ok = 0, ng\
    \ = min(a.size() - al, b.size() - bl) + 1;\n    while (ok + 1 < ng) {\n      int\
    \ med = (ok + ng) / 2;\n      (a.get(al, med + al) == b.get(bl, med + bl) ? ok\
    \ : ng) = med;\n    }\n    return ok;\n  }\n\n  static int strcmp(const RollingHash\
    \ &a, const RollingHash &b, int al, int bl,\n                    int ar = -1,\
    \ int br = -1) {\n    if (ar == -1) ar = a.size();\n    if (br == -1) br = b.size();\n\
    \    int n = min<int>({lcp(a, b, al, bl), ar - al, br - bl});\n    return al +\
    \ n == ar                      ? bl + n == br ? 0 : -1\n           : bl + n ==\
    \ br                    ? 1\n           : a.data[al + n] < b.data[bl + n] ? -1\n\
    \                                             : 1;\n  }\n\n  int size() const\
    \ { return s; }\n};\n\ntemplate <typename Str, int BASE_NUM>\ntypename RollingHash<Str,\
    \ BASE_NUM>::Hash RollingHash<Str, BASE_NUM>::basis =\n    internal::Hash<BASE_NUM>::get_basis();\n\
    using roriha = RollingHash<string, 2>;\n\n/**\n * @brief Rolling Hash\n * @docs\
    \ docs/string/rolling-hash.md\n */\n#line 8 \"verify/verify-unit-test/string-search.test.cpp\"\
    \n//\n#line 2 \"misc/rng.hpp\"\n\nnamespace my_rand {\nusing i64 = long long;\n\
    using u64 = unsigned long long;\n\n// [0, 2^64 - 1)\nu64 rng() {\n  static u64\
    \ _x =\n      u64(chrono::duration_cast<chrono::nanoseconds>(\n              chrono::high_resolution_clock::now().time_since_epoch())\n\
    \              .count()) *\n      10150724397891781847ULL;\n  _x ^= _x << 7;\n\
    \  return _x ^= _x >> 9;\n}\n\n// [l, r]\ni64 rng(i64 l, i64 r) {\n  assert(l\
    \ <= r);\n  return l + rng() % (r - l + 1);\n}\n\n// [l, r)\ni64 randint(i64 l,\
    \ i64 r) {\n  assert(l < r);\n  return l + rng() % (r - l);\n}\n\n// choose n\
    \ numbers from [l, r) without overlapping\nvector<i64> randset(i64 l, i64 r, i64\
    \ n) {\n  assert(l <= r && n <= r - l);\n  unordered_set<i64> s;\n  for (i64 i\
    \ = n; i; --i) {\n    i64 m = randint(l, r + 1 - i);\n    if (s.find(m) != s.end())\
    \ m = r - i;\n    s.insert(m);\n  }\n  vector<i64> ret;\n  for (auto& x : s) ret.push_back(x);\n\
    \  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() { return rng() * 5.42101086242752217004e-20;\
    \ }\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n\
    \  for (int i = 1; i < n; i++) swap(v[i], v[randint(0, i + 1)]);\n}\n\n}  // namespace\
    \ my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\nusing my_rand::randshf;\n\
    using my_rand::rnd;\nusing my_rand::rng;\n#line 10 \"verify/verify-unit-test/string-search.test.cpp\"\
    \n\nusing namespace Nyaan;\n\nvoid test() {\n  int N = rng(5, 20);\n  string S;\n\
    \  int upper = rng(1, 10);\n  rep(i, N) S.push_back('a' + rng(0, upper - 1));\n\
    \n  vp ps1;\n  rep(i, N) reg(j, i, N + 1) ps1.push_back({i, j});\n  vp ps2 = ps1;\n\
    \n  // trc2(S);\n\n  StringSearch ss{S};\n  roriha rh{S};\n\n  each(p, ps1) each(q,\
    \ ps1) {\n    string s1 = S.substr(p.fi, p.se - p.fi);\n    string s2 = S.substr(q.fi,\
    \ q.se - q.fi);\n\n    // trc(p, q, s1, s2);\n\n    // lcp\n    {\n      int l\
    \ = 0;\n      while (l < min(sz(s1), sz(s2)) and s1[l] == s2[l]) l++;\n      assert(ss.lcp(p.fi,\
    \ p.se, q.fi, q.se) == l);\n      assert(ss.lcp(p, q) == l);\n      if (p.se ==\
    \ N and q.se == N) assert(ss.lcp(p.fi, q.fi) == l);\n    }\n\n    // strcmp\n\
    \    {\n      int c2 = s1 < s2 ? -1 : s1 == s2 ? 0 : 1;\n      int c3 = ss.strcmp(p.fi,\
    \ p.se, q.fi, q.se);\n      int c4 = ss.strcmp(p, q);\n      int c5 = rh.strcmp(rh,\
    \ rh, p.fi, q.fi, p.se, q.se);\n      assert(c2 == c3 and c3 == c4 and c4 == c5);\n\
    \      if (p.se == N and q.se == N) assert(ss.strcmp(p.fi, q.fi) == c2);\n   \
    \ }\n  }\n}\n\nvoid Nyaan::solve() {\n  rep(t, 1000) test();\n  cerr << \"OK\"\
    \ << endl;\n\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../string/string-search.hpp\"\
    \n//\n#include \"../../string/rolling-hash.hpp\"\n//\n#include \"../../misc/rng.hpp\"\
    \n\nusing namespace Nyaan;\n\nvoid test() {\n  int N = rng(5, 20);\n  string S;\n\
    \  int upper = rng(1, 10);\n  rep(i, N) S.push_back('a' + rng(0, upper - 1));\n\
    \n  vp ps1;\n  rep(i, N) reg(j, i, N + 1) ps1.push_back({i, j});\n  vp ps2 = ps1;\n\
    \n  // trc2(S);\n\n  StringSearch ss{S};\n  roriha rh{S};\n\n  each(p, ps1) each(q,\
    \ ps1) {\n    string s1 = S.substr(p.fi, p.se - p.fi);\n    string s2 = S.substr(q.fi,\
    \ q.se - q.fi);\n\n    // trc(p, q, s1, s2);\n\n    // lcp\n    {\n      int l\
    \ = 0;\n      while (l < min(sz(s1), sz(s2)) and s1[l] == s2[l]) l++;\n      assert(ss.lcp(p.fi,\
    \ p.se, q.fi, q.se) == l);\n      assert(ss.lcp(p, q) == l);\n      if (p.se ==\
    \ N and q.se == N) assert(ss.lcp(p.fi, q.fi) == l);\n    }\n\n    // strcmp\n\
    \    {\n      int c2 = s1 < s2 ? -1 : s1 == s2 ? 0 : 1;\n      int c3 = ss.strcmp(p.fi,\
    \ p.se, q.fi, q.se);\n      int c4 = ss.strcmp(p, q);\n      int c5 = rh.strcmp(rh,\
    \ rh, p.fi, q.fi, p.se, q.se);\n      assert(c2 == c3 and c3 == c4 and c4 == c5);\n\
    \      if (p.se == N and q.se == N) assert(ss.strcmp(p.fi, q.fi) == c2);\n   \
    \ }\n  }\n}\n\nvoid Nyaan::solve() {\n  rep(t, 1000) test();\n  cerr << \"OK\"\
    \ << endl;\n\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - string/string-search.hpp
  - data-structure/sparse-table.hpp
  - string/rolling-hash.hpp
  - internal/internal-hash.hpp
  - misc/rng.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/string-search.test.cpp
  requiredBy: []
  timestamp: '2023-05-19 10:25:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/string-search.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/string-search.test.cpp
- /verify/verify/verify-unit-test/string-search.test.cpp.html
title: verify/verify-unit-test/string-search.test.cpp
---
