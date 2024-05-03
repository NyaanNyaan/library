---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/arbitrary-montgomery-modint.hpp
    title: modint/arbitrary-montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/mod-sqrt.hpp
    title: mod sqrt(Tonelli-Shanks algorithm)
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
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n\n#line 2 \"template/template.hpp\"\
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
    \ 2 \"modint/arbitrary-montgomery-modint.hpp\"\n\n#line 4 \"modint/arbitrary-montgomery-modint.hpp\"\
    \nusing namespace std;\n\ntemplate <typename Int, typename UInt, typename Long,\
    \ typename ULong, int id>\nstruct ArbitraryLazyMontgomeryModIntBase {\n  using\
    \ mint = ArbitraryLazyMontgomeryModIntBase;\n\n  inline static UInt mod;\n  inline\
    \ static UInt r;\n  inline static UInt n2;\n  static constexpr int bit_length\
    \ = sizeof(UInt) * 8;\n\n  static UInt get_r() {\n    UInt ret = mod;\n    while\
    \ (mod * ret != 1) ret *= UInt(2) - mod * ret;\n    return ret;\n  }\n  static\
    \ void set_mod(UInt m) {\n    assert(m < (UInt(1u) << (bit_length - 2)));\n  \
    \  assert((m & 1) == 1);\n    mod = m, n2 = -ULong(m) % m, r = get_r();\n  }\n\
    \  UInt a;\n\n  ArbitraryLazyMontgomeryModIntBase() : a(0) {}\n  ArbitraryLazyMontgomeryModIntBase(const\
    \ Long &b)\n      : a(reduce(ULong(b % mod + mod) * n2)){};\n\n  static UInt reduce(const\
    \ ULong &b) {\n    return (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;\n\
    \  }\n\n  mint &operator+=(const mint &b) {\n    if (Int(a += b.a - 2 * mod) <\
    \ 0) a += 2 * mod;\n    return *this;\n  }\n  mint &operator-=(const mint &b)\
    \ {\n    if (Int(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n  mint\
    \ &operator*=(const mint &b) {\n    a = reduce(ULong(a) * b.a);\n    return *this;\n\
    \  }\n  mint &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return\
    \ *this;\n  }\n\n  mint operator+(const mint &b) const { return mint(*this) +=\
    \ b; }\n  mint operator-(const mint &b) const { return mint(*this) -= b; }\n \
    \ mint operator*(const mint &b) const { return mint(*this) *= b; }\n  mint operator/(const\
    \ mint &b) const { return mint(*this) /= b; }\n\n  bool operator==(const mint\
    \ &b) const {\n    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod\
    \ : b.a);\n  }\n  bool operator!=(const mint &b) const {\n    return (a >= mod\
    \ ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);\n  }\n  mint operator-() const\
    \ { return mint(0) - mint(*this); }\n  mint operator+() const { return mint(*this);\
    \ }\n\n  mint pow(ULong n) const {\n    mint ret(1), mul(*this);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul, n >>= 1;\n    }\n  \
    \  return ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const mint &b)\
    \ {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is,\
    \ mint &b) {\n    Long t;\n    is >> t;\n    b = ArbitraryLazyMontgomeryModIntBase(t);\n\
    \    return (is);\n  }\n\n  mint inverse() const {\n    Int x = get(), y = get_mod(),\
    \ u = 1, v = 0;\n    while (y > 0) {\n      Int t = x / y;\n      swap(x -= t\
    \ * y, y);\n      swap(u -= t * v, v);\n    }\n    return mint{u};\n  }\n\n  UInt\
    \ get() const {\n    UInt ret = reduce(a);\n    return ret >= mod ? ret - mod\
    \ : ret;\n  }\n\n  static UInt get_mod() { return mod; }\n};\n\n// id \u306B\u9069\
    \u5F53\u306A\u4E71\u6570\u3092\u5272\u308A\u5F53\u3066\u3066\u4F7F\u3046\ntemplate\
    \ <int id>\nusing ArbitraryLazyMontgomeryModInt =\n    ArbitraryLazyMontgomeryModIntBase<int,\
    \ unsigned int, long long,\n                                      unsigned long\
    \ long, id>;\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt64bit =\n\
    \    ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long, __int128_t,\n\
    \                                      __uint128_t, id>;\n#line 3 \"modulo/mod-sqrt.hpp\"\
    \n\nint64_t mod_sqrt(const int64_t &a, const int64_t &p) {\n  assert(0 <= a &&\
    \ a < p);\n  if (a < 2) return a;\n  using Mint = ArbitraryLazyMontgomeryModInt<409075245>;\n\
    \  Mint::set_mod(p);\n  if (Mint(a).pow((p - 1) >> 1) != 1) return -1;\n  Mint\
    \ b = 1, one = 1;\n  while (b.pow((p - 1) >> 1) == 1) b += one;\n  int64_t m =\
    \ p - 1, e = 0;\n  while (m % 2 == 0) m >>= 1, e += 1;\n  Mint x = Mint(a).pow((m\
    \ - 1) >> 1);\n  Mint y = Mint(a) * x * x;\n  x *= a;\n  Mint z = Mint(b).pow(m);\n\
    \  while (y != 1) {\n    int64_t j = 0;\n    Mint t = y;\n    while (t != one)\
    \ {\n      j += 1;\n      t *= t;\n    }\n    z = z.pow(int64_t(1) << (e - j -\
    \ 1));\n    x *= z;\n    z *= z;\n    y *= z;\n    e = j;\n  }\n  return x.get();\n\
    }\n\n/**\n * @brief mod sqrt(Tonelli-Shanks algorithm)\n * @docs docs/modulo/mod-sqrt.md\n\
    \ */\n#line 5 \"verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp\"\n\nusing\
    \ namespace Nyaan; void Nyaan::solve() {\n  ini(T);\n  rep(_, T) {\n    inl(y,\
    \ p);\n    out(mod_sqrt(y, p));\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n\n#include\
    \ \"../../template/template.hpp\"\n#include \"../../modulo/mod-sqrt.hpp\"\n\n\
    using namespace Nyaan; void Nyaan::solve() {\n  ini(T);\n  rep(_, T) {\n    inl(y,\
    \ p);\n    out(mod_sqrt(y, p));\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - modulo/mod-sqrt.hpp
  - modint/arbitrary-montgomery-modint.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp
  requiredBy: []
  timestamp: '2024-05-03 23:21:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp
- /verify/verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp.html
title: verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp
---
