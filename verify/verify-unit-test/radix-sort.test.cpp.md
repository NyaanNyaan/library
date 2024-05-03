---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-seed.hpp
    title: internal/internal-seed.hpp
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  - icon: ':heavy_check_mark:'
    path: math-fast/radix-sort.hpp
    title: radix sort
  - icon: ':heavy_check_mark:'
    path: misc/all.hpp
    title: misc/all.hpp
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: misc/timer.hpp
    title: misc/timer.hpp
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
  bundledCode: "#line 1 \"verify/verify-unit-test/radix-sort.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#line 2 \"template/template.hpp\"\
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
    \ T>\nbool nxp(T &v) {\n  return next_permutation(begin(v), end(v));\n}\n\n//\
    \ \u8FD4\u308A\u5024\u306E\u578B\u306F\u5165\u529B\u306E T \u306B\u4F9D\u5B58\n\
    // i \u8981\u7D20\u76EE : [0, a[i])\ntemplate <typename T>\nvector<vector<T>>\
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
    \u308B\ntemplate <typename T>\nT Power(T a, long long n, const T &I = T{1}) {\n\
    \  return Power(a, n, I, function<void(T &)>{[](T &) -> void {}});\n}\n\ntemplate\
    \ <typename T>\nT Rev(const T &v) {\n  T res = v;\n  reverse(begin(res), end(res));\n\
    \  return res;\n}\n\ntemplate <typename T>\nvector<T> Transpose(const vector<T>\
    \ &v) {\n  using U = typename T::value_type;\n  if(v.empty()) return {};\n  int\
    \ H = v.size(), W = v[0].size();\n  vector res(W, T(H, U{}));\n  for (int i =\
    \ 0; i < H; i++) {\n    for (int j = 0; j < W; j++) {\n      res[j][i] = v[i][j];\n\
    \    }\n  }\n  return res;\n}\n\ntemplate <typename T>\nvector<T> Rotate(const\
    \ vector<T> &v, int clockwise = true) {\n  using U = typename T::value_type;\n\
    \  int H = v.size(), W = v[0].size();\n  vector res(W, T(H, U{}));\n  for (int\
    \ i = 0; i < H; i++) {\n    for (int j = 0; j < W; j++) {\n      if (clockwise)\
    \ {\n        res[W - 1 - j][i] = v[i][j];\n      } else {\n        res[j][H -\
    \ 1 - i] = v[i][j];\n      }\n    }\n  }\n  return res;\n}\n\n}  // namespace\
    \ Nyaan\n#line 58 \"template/template.hpp\"\n\n// bit operation\n#line 1 \"template/bitop.hpp\"\
    \nnamespace Nyaan {\n__attribute__((target(\"popcnt\"))) inline int popcnt(const\
    \ u64 &a) {\n  return __builtin_popcountll(a);\n}\ninline int lsb(const u64 &a)\
    \ { return a ? __builtin_ctzll(a) : 64; }\ninline int ctz(const u64 &a) { return\
    \ a ? __builtin_ctzll(a) : 64; }\ninline int msb(const u64 &a) { return a ? 63\
    \ - __builtin_clzll(a) : -1; }\ntemplate <typename T>\ninline int gbit(const T\
    \ &a, int i) {\n  return (a >> i) & 1;\n}\ntemplate <typename T>\ninline void\
    \ sbit(T &a, int i, bool b) {\n  if (gbit(a, i) != b) a ^= T(1) << i;\n}\nconstexpr\
    \ long long PW(int n) { return 1LL << n; }\nconstexpr long long MSK(int n) { return\
    \ (1LL << n) - 1; }\n}  // namespace Nyaan\n#line 61 \"template/template.hpp\"\
    \n\n// inout\n#line 1 \"template/inout.hpp\"\nnamespace Nyaan {\n\ntemplate <typename\
    \ T, typename U>\nostream &operator<<(ostream &os, const pair<T, U> &p) {\n  os\
    \ << p.first << \" \" << p.second;\n  return os;\n}\ntemplate <typename T, typename\
    \ U>\nistream &operator>>(istream &is, pair<T, U> &p) {\n  is >> p.first >> p.second;\n\
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
    \ \" \";\n  dump(head);\n  if (sizeof...(tail) != 0) cerr << \",\";\n  trace(std::forward<Tail>(tail)...);\n\
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
    \ 4 \"verify/verify-unit-test/radix-sort.test.cpp\"\n//\n#line 2 \"math-fast/radix-sort.hpp\"\
    \n\n#line 6 \"math-fast/radix-sort.hpp\"\nusing namespace std;\n\nnamespace RadixSortImpl\
    \ {\nconstexpr int b = 8;\nconstexpr int powb = 1 << b;\nconstexpr int mask =\
    \ powb - 1;\n\nint cnt0[powb];\nint cnt1[powb];\nint cnt2[powb];\nint cnt3[powb];\n\
    \ntemplate <typename T>\nvoid radix_sort(int N, T* p) {\n  static_assert(sizeof(T)\
    \ == 4 or sizeof(T) == 8);\n  if (!N) return;\n  if (N <= 64) {\n    sort(p, p\
    \ + N);\n    return;\n  }\n  static T* tmp = nullptr;\n  static int tmp_size =\
    \ 0;\n  if (!tmp or tmp_size < N) {\n    if (tmp) delete[] tmp;\n    tmp_size\
    \ = 1;\n    while (tmp_size < N) tmp_size *= 2;\n    tmp = new T[tmp_size];\n\
    \  }\n\n  memset(cnt0, 0, sizeof(cnt0));\n  memset(cnt1, 0, sizeof(cnt1));\n \
    \ memset(cnt2, 0, sizeof(cnt2));\n  memset(cnt3, 0, sizeof(cnt3));\n  for (int\
    \ i = 0; i < N; i++) {\n    cnt0[p[i] & mask]++;\n    cnt1[(p[i] >> b) & mask]++;\n\
    \    cnt2[(p[i] >> b * 2) & mask]++;\n    cnt3[(p[i] >> b * 3) & mask]++;\n  }\n\
    \  for (int i = 0; i < powb - 1; i++) {\n    cnt0[i + 1] += cnt0[i];\n    cnt1[i\
    \ + 1] += cnt1[i];\n    cnt2[i + 1] += cnt2[i];\n    cnt3[i + 1] += cnt3[i];\n\
    \  }\n  for (int i = N; i--;) tmp[--cnt0[p[i] & mask]] = p[i];\n  for (int i =\
    \ N; i--;) p[--cnt1[tmp[i] >> b & mask]] = tmp[i];\n  for (int i = N; i--;) tmp[--cnt2[p[i]\
    \ >> b * 2 & mask]] = p[i];\n  for (int i = N; i--;) p[--cnt3[tmp[i] >> b * 3\
    \ & mask]] = tmp[i];\n\n  if constexpr (sizeof(T) == 8) {\n    memset(cnt0, 0,\
    \ sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[p[i] >> b * 4 & mask]++;\n\
    \    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n    for (int\
    \ i = N; i--;) tmp[--cnt0[p[i] >> b * 4 & mask]] = p[i];\n    memset(cnt0, 0,\
    \ sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[tmp[i] >> b * 5 & mask]++;\n\
    \    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n    for (int\
    \ i = N; i--;) p[--cnt0[tmp[i] >> b * 5 & mask]] = tmp[i];\n    memset(cnt0, 0,\
    \ sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[p[i] >> b * 6 & mask]++;\n\
    \    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n    for (int\
    \ i = N; i--;) tmp[--cnt0[p[i] >> b * 6 & mask]] = p[i];\n    memset(cnt0, 0,\
    \ sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[tmp[i] >> b * 7 & mask]++;\n\
    \    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n    for (int\
    \ i = N; i--;) p[--cnt0[tmp[i] >> b * 7 & mask]] = tmp[i];\n  }\n  if constexpr\
    \ (is_signed<T>::value) {\n    int i = N;\n    while (i and p[i - 1] < 0) i--;\n\
    \    rotate(p, p + i, p + N);\n  }\n}\n\n// N 10^7 int :  90 ms\n// N 10^7 ll\
    \  : 220 ms\ntemplate <typename T>\nvoid radix_sort(vector<T>& v) {\n  radix_sort(v.size(),\
    \ v.data());\n}\n\n// first \u306E\u9806\u306B\u30BD\u30FC\u30C8, second \u306F\
    \u4E0D\u554F\ntemplate <typename T, typename U>\nvoid radix_sort_compare_first(int\
    \ N, pair<T, U>* p) {\n  static_assert(sizeof(T) == 4 or sizeof(T) == 8);\n\n\
    \  if (!N) return;\n  if (N <= 64) {\n    stable_sort(p, p + N, [](const pair<T,\
    \ U>& s, const pair<T, U>& t) {\n      return s.first < t.first;\n    });\n  \
    \  return;\n  }\n  static pair<T, U>* tmp = nullptr;\n  static int tmp_size =\
    \ 0;\n  if (!tmp or tmp_size < N) {\n    if (tmp) delete[] tmp;\n    tmp_size\
    \ = 1;\n    while (tmp_size < N) tmp_size *= 2;\n    tmp = new pair<T, U>[tmp_size];\n\
    \  }\n\n  memset(cnt0, 0, sizeof(cnt0));\n  for (int i = 0; i < N; i++) cnt0[p[i].first\
    \ & mask]++;\n  for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n \
    \ for (int i = N; i--;) tmp[--cnt0[p[i].first & mask]] = p[i];\n  memset(cnt0,\
    \ 0, sizeof(cnt0));\n  for (int i = 0; i < N; i++) cnt0[tmp[i].first >> b & mask]++;\n\
    \  for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n  for (int i =\
    \ N; i--;) p[--cnt0[tmp[i].first >> b & mask]] = tmp[i];\n  memset(cnt0, 0, sizeof(cnt0));\n\
    \  for (int i = 0; i < N; i++) cnt0[p[i].first >> b * 2 & mask]++;\n  for (int\
    \ i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n  for (int i = N; i--;) tmp[--cnt0[p[i].first\
    \ >> b * 2 & mask]] = p[i];\n  memset(cnt0, 0, sizeof(cnt0));\n  for (int i =\
    \ 0; i < N; i++) cnt0[tmp[i].first >> b * 3 & mask]++;\n  for (int i = 0; i <\
    \ powb - 1; i++) cnt0[i + 1] += cnt0[i];\n  for (int i = N; i--;) p[--cnt0[tmp[i].first\
    \ >> b * 3 & mask]] = tmp[i];\n\n  if constexpr (sizeof(T) == 8) {\n    memset(cnt0,\
    \ 0, sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[p[i].first >> b * 4\
    \ & mask]++;\n    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n\
    \    for (int i = N; i--;) tmp[--cnt0[p[i].first >> b * 4 & mask]] = p[i];\n \
    \   memset(cnt0, 0, sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[tmp[i].first\
    \ >> b * 5 & mask]++;\n    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n\
    \    for (int i = N; i--;) p[--cnt0[tmp[i].first >> b * 5 & mask]] = tmp[i];\n\
    \    memset(cnt0, 0, sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[p[i].first\
    \ >> b * 6 & mask]++;\n    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n\
    \    for (int i = N; i--;) tmp[--cnt0[p[i].first >> b * 6 & mask]] = p[i];\n \
    \   memset(cnt0, 0, sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[tmp[i].first\
    \ >> b * 7 & mask]++;\n    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n\
    \    for (int i = N; i--;) p[--cnt0[tmp[i].first >> b * 7 & mask]] = tmp[i];\n\
    \  }\n\n  if constexpr (is_signed<T>::value) {\n    int i = N;\n    while (i and\
    \ p[i - 1].first < 0) i--;\n    rotate(p, p + i, p + N);\n  }\n}\n\n// first \u306E\
    \u9806\u306B\u30BD\u30FC\u30C8, second \u306F\u4E0D\u554F\n// N 10^7 int : 130\
    \ ms\n// N 10^7 ll  : 370 ms\ntemplate <typename T, typename U>\nvoid radix_sort_compare_first(vector<pair<T,\
    \ U>>& v) {\n  radix_sort_compare_first(v.size(), v.data());\n}\n\n}  // namespace\
    \ RadixSortImpl\n\nusing RadixSortImpl::radix_sort;\nusing RadixSortImpl::radix_sort_compare_first;\n\
    \n/*\n  @brief radix sort\n*/\n#line 6 \"verify/verify-unit-test/radix-sort.test.cpp\"\
    \n//\n#line 2 \"misc/all.hpp\"\n\n#line 2 \"misc/fastio.hpp\"\n\n#line 8 \"misc/fastio.hpp\"\
    \n\nusing namespace std;\n\n#line 2 \"internal/internal-type-traits.hpp\"\n\n\
    #line 4 \"internal/internal-type-traits.hpp\"\nusing namespace std;\n\nnamespace\
    \ internal {\ntemplate <typename T>\nusing is_broadly_integral =\n    typename\
    \ conditional_t<is_integral_v<T> || is_same_v<T, __int128_t> ||\n            \
    \                   is_same_v<T, __uint128_t>,\n                           true_type,\
    \ false_type>::type;\n\ntemplate <typename T>\nusing is_broadly_signed =\n   \
    \ typename conditional_t<is_signed_v<T> || is_same_v<T, __int128_t>,\n       \
    \                    true_type, false_type>::type;\n\ntemplate <typename T>\n\
    using is_broadly_unsigned =\n    typename conditional_t<is_unsigned_v<T> || is_same_v<T,\
    \ __uint128_t>,\n                           true_type, false_type>::type;\n\n\
    #define ENABLE_VALUE(x) \\\n  template <typename T> \\\n  constexpr bool x##_v\
    \ = x<T>::value;\n\nENABLE_VALUE(is_broadly_integral);\nENABLE_VALUE(is_broadly_signed);\n\
    ENABLE_VALUE(is_broadly_unsigned);\n#undef ENABLE_VALUE\n\n#define ENABLE_HAS_TYPE(var)\
    \                                   \\\n  template <class, class = void>     \
    \                          \\\n  struct has_##var : false_type {};           \
    \                 \\\n  template <class T>                                   \
    \        \\\n  struct has_##var<T, void_t<typename T::var>> : true_type {}; \\\
    \n  template <class T>                                           \\\n  constexpr\
    \ auto has_##var##_v = has_##var<T>::value;\n\n#define ENABLE_HAS_VAR(var)   \
    \                                  \\\n  template <class, class = void>      \
    \                          \\\n  struct has_##var : false_type {};           \
    \                  \\\n  template <class T>                                  \
    \          \\\n  struct has_##var<T, void_t<decltype(T::var)>> : true_type {};\
    \ \\\n  template <class T>                                            \\\n  constexpr\
    \ auto has_##var##_v = has_##var<T>::value;\n\n}  // namespace internal\n#line\
    \ 12 \"misc/fastio.hpp\"\n\nnamespace fastio {\nstatic constexpr int SZ = 1 <<\
    \ 17;\nstatic constexpr int offset = 64;\nchar inbuf[SZ], outbuf[SZ];\nint in_left\
    \ = 0, in_right = 0, out_right = 0;\n\nstruct Pre {\n  char num[40000];\n  constexpr\
    \ Pre() : num() {\n    for (int i = 0; i < 10000; i++) {\n      int n = i;\n \
    \     for (int j = 3; j >= 0; j--) {\n        num[i * 4 + j] = n % 10 + '0';\n\
    \        n /= 10;\n      }\n    }\n  }\n} constexpr pre;\n\nvoid load() {\n  int\
    \ len = in_right - in_left;\n  memmove(inbuf, inbuf + in_left, len);\n  in_right\
    \ = len + fread(inbuf + len, 1, SZ - len, stdin);\n  in_left = 0;\n}\nvoid flush()\
    \ {\n  fwrite(outbuf, 1, out_right, stdout);\n  out_right = 0;\n}\nvoid skip_space()\
    \ {\n  if (in_left + offset > in_right) load();\n  while (inbuf[in_left] <= '\
    \ ') in_left++;\n}\n\nvoid single_read(char& c) {\n  if (in_left + offset > in_right)\
    \ load();\n  skip_space();\n  c = inbuf[in_left++];\n}\nvoid single_read(string&\
    \ S) {\n  skip_space();\n  while (true) {\n    if (in_left == in_right) load();\n\
    \    int i = in_left;\n    for (; i != in_right; i++) {\n      if (inbuf[i] <=\
    \ ' ') break;\n    }\n    copy(inbuf + in_left, inbuf + i, back_inserter(S));\n\
    \    in_left = i;\n    if (i != in_right) break;\n  }\n}\ntemplate <typename T,\n\
    \          enable_if_t<internal::is_broadly_integral_v<T>>* = nullptr>\nvoid single_read(T&\
    \ x) {\n  if (in_left + offset > in_right) load();\n  skip_space();\n  char c\
    \ = inbuf[in_left++];\n  [[maybe_unused]] bool minus = false;\n  if constexpr\
    \ (internal::is_broadly_signed_v<T>) {\n    if (c == '-') minus = true, c = inbuf[in_left++];\n\
    \  }\n  x = 0;\n  while (c >= '0') {\n    x = x * 10 + (c & 15);\n    c = inbuf[in_left++];\n\
    \  }\n  if constexpr (internal::is_broadly_signed_v<T>) {\n    if (minus) x =\
    \ -x;\n  }\n}\nvoid rd() {}\ntemplate <typename Head, typename... Tail>\nvoid\
    \ rd(Head& head, Tail&... tail) {\n  single_read(head);\n  rd(tail...);\n}\n\n\
    void single_write(const char& c) {\n  if (out_right > SZ - offset) flush();\n\
    \  outbuf[out_right++] = c;\n}\nvoid single_write(const bool& b) {\n  if (out_right\
    \ > SZ - offset) flush();\n  outbuf[out_right++] = b ? '1' : '0';\n}\nvoid single_write(const\
    \ string& S) {\n  flush(), fwrite(S.data(), 1, S.size(), stdout);\n}\nvoid single_write(const\
    \ char* p) { flush(), fwrite(p, 1, strlen(p), stdout); }\ntemplate <typename T,\n\
    \          enable_if_t<internal::is_broadly_integral_v<T>>* = nullptr>\nvoid single_write(const\
    \ T& _x) {\n  if (out_right > SZ - offset) flush();\n  if (_x == 0) {\n    outbuf[out_right++]\
    \ = '0';\n    return;\n  }\n  T x = _x;\n  if constexpr (internal::is_broadly_signed_v<T>)\
    \ {\n    if (x < 0) outbuf[out_right++] = '-', x = -x;\n  }\n  constexpr int buffer_size\
    \ = sizeof(T) * 10 / 4;\n  char buf[buffer_size];\n  int i = buffer_size;\n  while\
    \ (x >= 10000) {\n    i -= 4;\n    memcpy(buf + i, pre.num + (x % 10000) * 4,\
    \ 4);\n    x /= 10000;\n  }\n  if (x < 100) {\n    if (x < 10) {\n      outbuf[out_right]\
    \ = '0' + x;\n      ++out_right;\n    } else {\n      uint32_t q = (uint32_t(x)\
    \ * 205) >> 11;\n      uint32_t r = uint32_t(x) - q * 10;\n      outbuf[out_right]\
    \ = '0' + q;\n      outbuf[out_right + 1] = '0' + r;\n      out_right += 2;\n\
    \    }\n  } else {\n    if (x < 1000) {\n      memcpy(outbuf + out_right, pre.num\
    \ + (x << 2) + 1, 3);\n      out_right += 3;\n    } else {\n      memcpy(outbuf\
    \ + out_right, pre.num + (x << 2), 4);\n      out_right += 4;\n    }\n  }\n  memcpy(outbuf\
    \ + out_right, buf + i, buffer_size - i);\n  out_right += buffer_size - i;\n}\n\
    void wt() {}\ntemplate <typename Head, typename... Tail>\nvoid wt(const Head&\
    \ head, const Tail&... tail) {\n  single_write(head);\n  wt(std::forward<const\
    \ Tail>(tail)...);\n}\ntemplate <typename... Args>\nvoid wtn(const Args&... x)\
    \ {\n  wt(std::forward<const Args>(x)...);\n  wt('\\n');\n}\n\nstruct Dummy {\n\
    \  Dummy() { atexit(flush); }\n} dummy;\n\n}  // namespace fastio\nusing fastio::rd;\n\
    using fastio::skip_space;\nusing fastio::wt;\nusing fastio::wtn;\n#line 2 \"misc/rng.hpp\"\
    \n\n#line 2 \"internal/internal-seed.hpp\"\n\n#line 4 \"internal/internal-seed.hpp\"\
    \nusing namespace std;\n\nnamespace internal {\nunsigned long long non_deterministic_seed()\
    \ {\n  unsigned long long m =\n      chrono::duration_cast<chrono::nanoseconds>(\n\
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \  .count();\n  m ^= 9845834732710364265uLL;\n  m ^= m << 24, m ^= m >> 31, m\
    \ ^= m << 35;\n  return m;\n}\nunsigned long long deterministic_seed() { return\
    \ 88172645463325252UL; }\n\n// 64 bit \u306E seed \u5024\u3092\u751F\u6210 (\u624B\
    \u5143\u3067\u306F seed \u56FA\u5B9A)\n// \u9023\u7D9A\u3067\u547C\u3073\u51FA\
    \u3059\u3068\u540C\u3058\u5024\u304C\u4F55\u5EA6\u3082\u8FD4\u3063\u3066\u304F\
    \u308B\u306E\u3067\u6CE8\u610F\n// #define RANDOMIZED_SEED \u3059\u308B\u3068\u30B7\
    \u30FC\u30C9\u304C\u30E9\u30F3\u30C0\u30E0\u306B\u306A\u308B\nunsigned long long\
    \ seed() {\n#if defined(NyaanLocal) && !defined(RANDOMIZED_SEED)\n  return deterministic_seed();\n\
    #else\n  return non_deterministic_seed();\n#endif\n}\n\n}  // namespace internal\n\
    #line 4 \"misc/rng.hpp\"\n\nnamespace my_rand {\nusing i64 = long long;\nusing\
    \ u64 = unsigned long long;\n\n// [0, 2^64 - 1)\nu64 rng() {\n  static u64 _x\
    \ = internal::seed();\n  return _x ^= _x << 7, _x ^= _x >> 9;\n}\n\n// [l, r]\n\
    i64 rng(i64 l, i64 r) {\n  assert(l <= r);\n  return l + rng() % u64(r - l + 1);\n\
    }\n\n// [l, r)\ni64 randint(i64 l, i64 r) {\n  assert(l < r);\n  return l + rng()\
    \ % u64(r - l);\n}\n\n// choose n numbers from [l, r) without overlapping\nvector<i64>\
    \ randset(i64 l, i64 r, i64 n) {\n  assert(l <= r && n <= r - l);\n  unordered_set<i64>\
    \ s;\n  for (i64 i = n; i; --i) {\n    i64 m = randint(l, r + 1 - i);\n    if\
    \ (s.find(m) != s.end()) m = r - i;\n    s.insert(m);\n  }\n  vector<i64> ret;\n\
    \  for (auto& x : s) ret.push_back(x);\n  sort(begin(ret), end(ret));\n  return\
    \ ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() { return rng() * 5.42101086242752217004e-20;\
    \ }\n// [l, r)\ndouble rnd(double l, double r) {\n  assert(l < r);\n  return l\
    \ + rnd() * (r - l);\n}\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n\
    \  int n = v.size();\n  for (int i = 1; i < n; i++) swap(v[i], v[randint(0, i\
    \ + 1)]);\n}\n\n}  // namespace my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\n\
    using my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n#line 2 \"\
    misc/timer.hpp\"\n\n#line 4 \"misc/timer.hpp\"\nusing namespace std;\n\nstruct\
    \ Timer {\n  chrono::high_resolution_clock::time_point st;\n\n  Timer() { reset();\
    \ }\n  void reset() { st = chrono::high_resolution_clock::now(); }\n\n  long long\
    \ elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n    return\
    \ chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n  long long\
    \ operator()() { return elapsed(); }\n};\n#line 8 \"verify/verify-unit-test/radix-sort.test.cpp\"\
    \nusing namespace Nyaan;\n\ntemplate <typename T>\nvoid test(int N) {\n  ll mx\
    \ = numeric_limits<T>::max();\n  if (N <= 300) {\n    mx = pow(2.0, rnd() * log2(numeric_limits<T>::max()));\n\
    \    mx = clamp<T>(mx, 1, numeric_limits<T>::max());\n  }\n\n  Timer timer;\n\
    \  {\n    V<T> v(N);\n    each(x, v) x = rng(-mx, mx);\n\n    auto w = v;\n\n\
    \    timer.reset();\n    radix_sort(v);\n    ll t1 = timer.elapsed();\n\n    timer.reset();\n\
    \    sort(all(w));\n    ll t2 = timer.elapsed();\n\n    assert(v == w);\n    if\
    \ (N >= TEN(8)) DebugImpl::trace(\"N\", N, \"radix\", t1, \"std\", t2);\n  }\n\
    \n  if (N <= 300) {\n    V<pair<T, T>> v(N);\n    each(x, v) {\n      x.fi = rng(-mx,\
    \ mx);\n      x.se = rng(-mx, mx);\n    }\n\n    auto w = v;\n    radix_sort_compare_first(v);\n\
    \    stable_sort(all(w), [](const pair<T, T>& a, const pair<T, T>& b) {\n    \
    \  return a.first < b.first;\n    });\n\n    if (v != w) {\n      trc2(v);\n \
    \     trc2(w);\n    }\n    assert(v == w);\n  }\n}\n\nvoid q() {\n  {\n    vector<int>\
    \ v{2, 0, 1, -1, -2};\n    radix_sort(v);\n    vector<int> w{-2, -1, 0, 1, 2};\n\
    \    assert(v == w);\n  }\n  {\n    vector<int> v{2, 0, 2, -1, 1, 2, 0, -1, -2};\n\
    \    radix_sort(v);\n    vector<int> w{-2, -1, -1, 0, 0, 1, 2, 2, 2};\n    assert(v\
    \ == w);\n  }\n  {\n    vector<ll> v{2, 0, 2, -1, 1, 2, 0, -1, -2};\n    radix_sort(v);\n\
    \    vector<ll> w{-2, -1, -1, 0, 0, 1, 2, 2, 2};\n    assert(v == w);\n  }\n\n\
    \  rep(N, 200) rep(t, 200) {\n    test<int>(N);\n    test<uint32_t>(N);\n    test<ll>(N);\n\
    \  }\n  rep(e, 6) {\n    test<int>(TEN(e));\n    test<uint32_t>(TEN(e));\n   \
    \ test<ll>(TEN(e));\n  }\n  cerr << \"OK\" << endl;\n\n  /*\n  cerr << \"OK\"\
    \ << endl;\n  rep(t, 3) test<int>(TEN(7));\n  rep(t, 3) test<ll>(TEN(7));\n  */\n\
    \n  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n}\n\nvoid Nyaan::solve()\
    \ {\n  int t = 1;\n  // in(t);\n  while (t--) q();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../math-fast/radix-sort.hpp\"\
    \n//\n#include \"../../misc/all.hpp\"\nusing namespace Nyaan;\n\ntemplate <typename\
    \ T>\nvoid test(int N) {\n  ll mx = numeric_limits<T>::max();\n  if (N <= 300)\
    \ {\n    mx = pow(2.0, rnd() * log2(numeric_limits<T>::max()));\n    mx = clamp<T>(mx,\
    \ 1, numeric_limits<T>::max());\n  }\n\n  Timer timer;\n  {\n    V<T> v(N);\n\
    \    each(x, v) x = rng(-mx, mx);\n\n    auto w = v;\n\n    timer.reset();\n \
    \   radix_sort(v);\n    ll t1 = timer.elapsed();\n\n    timer.reset();\n    sort(all(w));\n\
    \    ll t2 = timer.elapsed();\n\n    assert(v == w);\n    if (N >= TEN(8)) DebugImpl::trace(\"\
    N\", N, \"radix\", t1, \"std\", t2);\n  }\n\n  if (N <= 300) {\n    V<pair<T,\
    \ T>> v(N);\n    each(x, v) {\n      x.fi = rng(-mx, mx);\n      x.se = rng(-mx,\
    \ mx);\n    }\n\n    auto w = v;\n    radix_sort_compare_first(v);\n    stable_sort(all(w),\
    \ [](const pair<T, T>& a, const pair<T, T>& b) {\n      return a.first < b.first;\n\
    \    });\n\n    if (v != w) {\n      trc2(v);\n      trc2(w);\n    }\n    assert(v\
    \ == w);\n  }\n}\n\nvoid q() {\n  {\n    vector<int> v{2, 0, 1, -1, -2};\n   \
    \ radix_sort(v);\n    vector<int> w{-2, -1, 0, 1, 2};\n    assert(v == w);\n \
    \ }\n  {\n    vector<int> v{2, 0, 2, -1, 1, 2, 0, -1, -2};\n    radix_sort(v);\n\
    \    vector<int> w{-2, -1, -1, 0, 0, 1, 2, 2, 2};\n    assert(v == w);\n  }\n\
    \  {\n    vector<ll> v{2, 0, 2, -1, 1, 2, 0, -1, -2};\n    radix_sort(v);\n  \
    \  vector<ll> w{-2, -1, -1, 0, 0, 1, 2, 2, 2};\n    assert(v == w);\n  }\n\n \
    \ rep(N, 200) rep(t, 200) {\n    test<int>(N);\n    test<uint32_t>(N);\n    test<ll>(N);\n\
    \  }\n  rep(e, 6) {\n    test<int>(TEN(e));\n    test<uint32_t>(TEN(e));\n   \
    \ test<ll>(TEN(e));\n  }\n  cerr << \"OK\" << endl;\n\n  /*\n  cerr << \"OK\"\
    \ << endl;\n  rep(t, 3) test<int>(TEN(7));\n  rep(t, 3) test<ll>(TEN(7));\n  */\n\
    \n  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n}\n\nvoid Nyaan::solve()\
    \ {\n  int t = 1;\n  // in(t);\n  while (t--) q();\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - math-fast/radix-sort.hpp
  - misc/all.hpp
  - misc/fastio.hpp
  - internal/internal-type-traits.hpp
  - misc/rng.hpp
  - internal/internal-seed.hpp
  - misc/timer.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/radix-sort.test.cpp
  requiredBy: []
  timestamp: '2024-05-03 23:21:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/radix-sort.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/radix-sort.test.cpp
- /verify/verify/verify-unit-test/radix-sort.test.cpp.html
title: verify/verify-unit-test/radix-sort.test.cpp
---
