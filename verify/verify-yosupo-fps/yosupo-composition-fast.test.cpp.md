---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: fps/fps-composition-fast.hpp
    title: "\u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}(N^2)$ )"
  - icon: ':heavy_check_mark:'
    path: fps/ntt-friendly-fps.hpp
    title: "NTT mod\u7528FPS\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: misc/timer.hpp
    title: misc/timer.hpp
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: modint/simd-montgomery.hpp
    title: modint/simd-montgomery.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/strassen.hpp
    title: modulo/strassen.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/ntt-avx2.hpp
    title: ntt/ntt-avx2.hpp
  - icon: ':question:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':question:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':question:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/composition_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/composition_of_formal_power_series
  bundledCode: "#line 1 \"verify/verify-yosupo-fps/yosupo-composition-fast.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/composition_of_formal_power_series\"\
    \n\n#line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n\
    #include <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <csetjmp>\n#include <csignal>\n#include <cstdarg>\n#include\
    \ <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <ctime>\n#include <deque>\n#include <exception>\n#include\
    \ <forward_list>\n#include <fstream>\n#include <functional>\n#include <initializer_list>\n\
    #include <iomanip>\n#include <ios>\n#include <iosfwd>\n#include <iostream>\n#include\
    \ <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n#include\
    \ <locale>\n#include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n\
    #include <ostream>\n#include <queue>\n#include <random>\n#include <ratio>\n#include\
    \ <regex>\n#include <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n\
    #include <streambuf>\n#include <string>\n#include <system_error>\n#include <tuple>\n\
    #include <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <valarray>\n#include <vector>\n\
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
    \ t.size();\n}\ntemplate <typename T, size_t N>\nvoid mem(T (&a)[N], int c) {\n\
    \  memset(a, c, sizeof(T) * N);\n}\n\ntemplate <typename T, typename U>\ninline\
    \ bool amin(T &x, U y) {\n  return (y < x) ? (x = y, true) : false;\n}\ntemplate\
    \ <typename T, typename U>\ninline bool amax(T &x, U y) {\n  return (x < y) ?\
    \ (x = y, true) : false;\n}\n\ntemplate <typename T>\nint lb(const vector<T> &v,\
    \ const T &a) {\n  return lower_bound(begin(v), end(v), a) - begin(v);\n}\ntemplate\
    \ <typename T>\nint ub(const vector<T> &v, const T &a) {\n  return upper_bound(begin(v),\
    \ end(v), a) - begin(v);\n}\n\nconstexpr long long TEN(int n) {\n  long long ret\
    \ = 1, x = 10;\n  for (; n; x *= x, n >>= 1) ret *= (n & 1 ? x : 1);\n  return\
    \ ret;\n}\n\ntemplate <typename T, typename U>\npair<T, U> mkp(const T &t, const\
    \ U &u) {\n  return make_pair(t, u);\n}\n\ntemplate <typename T>\nvector<T> mkrui(const\
    \ vector<T> &v, bool rev = false) {\n  vector<T> ret(v.size() + 1);\n  if (rev)\
    \ {\n    for (int i = int(v.size()) - 1; i >= 0; i--) ret[i] = v[i] + ret[i +\
    \ 1];\n  } else {\n    for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i]\
    \ + v[i];\n  }\n  return ret;\n};\n\ntemplate <typename T>\nvector<T> mkuni(const\
    \ vector<T> &v) {\n  vector<T> ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(),\
    \ ret.end()), ret.end());\n  return ret;\n}\n\ntemplate <typename F>\nvector<int>\
    \ mkord(int N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n\
    \  sort(begin(ord), end(ord), f);\n  return ord;\n}\n\ntemplate <typename T>\n\
    vector<T> reord(const vector<T> &v, const vector<T> &ord) {\n  int N = v.size();\n\
    \  vector<T> ret(N);\n  for (int i = 0; i < N; i++) ret[i] = v[ord[i]];\n  return\
    \ ret;\n};\n\ntemplate <typename T = int>\nvector<T> mkiota(int N) {\n  vector<T>\
    \ ret(N);\n  iota(begin(ret), end(ret), 0);\n  return ret;\n}\n\ntemplate <typename\
    \ T>\nvector<int> mkinv(vector<T> &v, int max_val = -1) {\n  if (max_val < (int)v.size())\
    \ max_val = v.size() - 1;\n  vector<int> inv(max_val + 1, -1);\n  for (int i =\
    \ 0; i < (int)v.size(); i++) inv[v[i]] = i;\n  return inv;\n}\n\n}  // namespace\
    \ Nyaan\n#line 70 \"template/template.hpp\"\n\n// bit operation\n#line 1 \"template/bitop.hpp\"\
    \nnamespace Nyaan {\n\n__attribute__((target(\"popcnt\"))) inline int popcnt(const\
    \ u64 &a) {\n  return _mm_popcnt_u64(a);\n}\n\n__attribute__((target(\"bmi\")))\
    \ inline int lsb(const u64 &a) {\n  return _tzcnt_u64(a);\n}\n__attribute__((target(\"\
    bmi\"))) inline int ctz(const u64 &a) {\n  return _tzcnt_u64(a);\n}\n\n__attribute__((target(\"\
    lzcnt\"))) inline int msb(const u64 &a) {\n  return 63 - _lzcnt_u64(a);\n}\n__attribute__((target(\"\
    lzcnt\"))) inline int clz64(const u64 &a) {\n  return _lzcnt_u64(a);\n}\n\ntemplate\
    \ <typename T>\ninline int gbit(const T &a, int i) {\n  return (a >> i) & 1;\n\
    }\ntemplate <typename T>\ninline void sbit(T &a, int i, bool b) {\n  a ^= (gbit(a,\
    \ i) == b ? 0 : (T(b) << i));\n}\n\nconstexpr long long PW(int n) { return 1LL\
    \ << n; }\n\nconstexpr long long MSK(int n) { return (1LL << n) - 1; }\n\n}  //\
    \ namespace Nyaan\n#line 73 \"template/template.hpp\"\n\n// inout\n#line 1 \"\
    template/inout.hpp\"\nnamespace Nyaan {\n\ntemplate <typename T, typename U>\n\
    ostream &operator<<(ostream &os, const pair<T, U> &p) {\n  os << p.first << \"\
    \ \" << p.second;\n  return os;\n}\ntemplate <typename T, typename U>\nistream\
    \ &operator>>(istream &is, pair<T, U> &p) {\n  is >> p.first >> p.second;\n  return\
    \ is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const vector<T>\
    \ &v) {\n  int s = (int)v.size();\n  for (int i = 0; i < s; i++) os << (i ? \"\
    \ \" : \"\") << v[i];\n  return os;\n}\ntemplate <typename T>\nistream &operator>>(istream\
    \ &is, vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return is;\n}\n\nvoid\
    \ in() {}\ntemplate <typename T, class... U>\nvoid in(T &t, U &... u) {\n  cin\
    \ >> t;\n  in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename\
    \ T, class... U, char sep = ' '>\nvoid out(const T &t, const U &... u) {\n  cout\
    \ << t;\n  if (sizeof...(u)) cout << sep;\n  out(u...);\n}\n\nvoid outr() {}\n\
    template <typename T, class... U, char sep = ' '>\nvoid outr(const T &t, const\
    \ U &... u) {\n  cout << t;\n  outr(u...);\n}\n\nstruct IoSetupNya {\n  IoSetupNya()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(15);\n    cerr << fixed << setprecision(7);\n  }\n} iosetupnya;\n\
    \n}  // namespace Nyaan\n#line 76 \"template/template.hpp\"\n\n// debug\n#line\
    \ 1 \"template/debug.hpp\"\nnamespace DebugImpl {\n\ntemplate <typename U, typename\
    \ = void>\nstruct is_specialize : false_type {};\ntemplate <typename U>\nstruct\
    \ is_specialize<\n    U, typename conditional<false, typename U::iterator, void>::type>\n\
    \    : true_type {};\ntemplate <typename U>\nstruct is_specialize<\n    U, typename\
    \ conditional<false, decltype(U::first), void>::type>\n    : true_type {};\ntemplate\
    \ <typename U>\nstruct is_specialize<U, enable_if_t<is_integral<U>::value, void>>\
    \ : true_type {\n};\n\nvoid dump(const char& t) { cerr << t; }\n\nvoid dump(const\
    \ string& t) { cerr << t; }\n\ntemplate <typename U,\n          enable_if_t<!is_specialize<U>::value,\
    \ nullptr_t> = nullptr>\nvoid dump(const U& t) {\n  cerr << t;\n}\n\ntemplate\
    \ <typename T>\nvoid dump(const T& t, enable_if_t<is_integral<T>::value>* = nullptr)\
    \ {\n  string res;\n  if (t == Nyaan::inf) res = \"inf\";\n  if (is_signed<T>::value)\n\
    \    if (t == -Nyaan::inf) res = \"-inf\";\n  if (sizeof(T) == 8) {\n    if (t\
    \ == Nyaan::infLL) res = \"inf\";\n    if (is_signed<T>::value)\n      if (t ==\
    \ -Nyaan::infLL) res = \"-inf\";\n  }\n  if (res.empty()) res = to_string(t);\n\
    \  cerr << res;\n}\n\ntemplate <typename T, typename U>\nvoid dump(const pair<T,\
    \ U>&);\ntemplate <typename T>\nvoid dump(const pair<T*, int>&);\n\ntemplate <typename\
    \ T>\nvoid dump(const T& t,\n          enable_if_t<!is_void<typename T::iterator>::value>*\
    \ = nullptr) {\n  cerr << \"[ \";\n  for (auto it = t.begin(); it != t.end();)\
    \ {\n    dump(*it);\n    cerr << (++it == t.end() ? \"\" : \", \");\n  }\n  cerr\
    \ << \" ]\";\n}\n\ntemplate <typename T, typename U>\nvoid dump(const pair<T,\
    \ U>& t) {\n  cerr << \"( \";\n  dump(t.first);\n  cerr << \", \";\n  dump(t.second);\n\
    \  cerr << \" )\";\n}\n\ntemplate <typename T>\nvoid dump(const pair<T*, int>&\
    \ t) {\n  cerr << \"[ \";\n  for (int i = 0; i < t.second; i++) {\n    dump(t.first[i]);\n\
    \    cerr << (i == t.second - 1 ? \"\" : \", \");\n  }\n  cerr << \" ]\";\n}\n\
    \nvoid trace() { cerr << endl; }\ntemplate <typename Head, typename... Tail>\n\
    void trace(Head&& head, Tail&&... tail) {\n  cerr << \" \";\n  dump(head);\n \
    \ if (sizeof...(tail) != 0) cerr << \",\";\n  trace(forward<Tail>(tail)...);\n\
    }\n\n}  // namespace DebugImpl\n\n#ifdef NyaanDebug\n#define trc(...)        \
    \                    \\\n  do {                                      \\\n    cerr\
    \ << \"## \" << #__VA_ARGS__ << \" = \"; \\\n    DebugImpl::trace(__VA_ARGS__);\
    \          \\\n  } while (0)\n#else\n#define trc(...)\n#endif\n#line 79 \"template/template.hpp\"\
    \n\n// macro\n#line 1 \"template/macro.hpp\"\n#define each(x, v) for (auto&& x\
    \ : v)\n#define each2(x, y, v) for (auto&& [x, y] : v)\n#define all(v) (v).begin(),\
    \ (v).end()\n#define rep(i, N) for (long long i = 0; i < (long long)(N); i++)\n\
    #define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)\n#define\
    \ rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)\n#define repr1(i,\
    \ N) for (long long i = (N); (long long)(i) > 0; i--)\n#define reg(i, a, b) for\
    \ (long long i = (a); i < (b); i++)\n#define regr(i, a, b) for (long long i =\
    \ (b)-1; i >= (a); i--)\n#define repc(i, a, cond) for (long long i = (a); (cond);\
    \ i++)\n#define enm(i, val, vec)                                  \\\n  for (long\
    \ long i = 0; i < (long long)(vec).size(); i++) \\\n    if (auto& val = vec[i];\
    \ false)                        \\\n      ;                                  \
    \                 \\\n    else\n\n#define ini(...)   \\\n  int __VA_ARGS__; \\\
    \n  in(__VA_ARGS__)\n#define inl(...)         \\\n  long long __VA_ARGS__; \\\n\
    \  in(__VA_ARGS__)\n#define ins(...)      \\\n  string __VA_ARGS__; \\\n  in(__VA_ARGS__)\n\
    #define inc(...)    \\\n  char __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define in2(s,\
    \ t)                           \\\n  for (int i = 0; i < (int)s.size(); i++) {\
    \ \\\n    in(s[i], t[i]);                         \\\n  }\n#define in3(s, t, u)\
    \                        \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n\
    \    in(s[i], t[i], u[i]);                   \\\n  }\n#define in4(s, t, u, v)\
    \                     \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n   \
    \ in(s[i], t[i], u[i], v[i]);             \\\n  }\n\n#define die(...)        \
    \     \\\n  do {                       \\\n    Nyaan::out(__VA_ARGS__); \\\n \
    \   return;                  \\\n  } while (0)\n#line 82 \"template/template.hpp\"\
    \n\nnamespace Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line\
    \ 2 \"fps/formal-power-series.hpp\"\n\ntemplate <typename mint>\nstruct FormalPowerSeries\
    \ : vector<mint> {\n  using vector<mint>::vector;\n  using FPS = FormalPowerSeries;\n\
    \n  FPS &operator+=(const FPS &r) {\n    if (r.size() > this->size()) this->resize(r.size());\n\
    \    for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
    \  }\n\n  FPS &operator+=(const mint &r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] += r;\n    return *this;\n  }\n\n  FPS &operator-=(const FPS &r)\
    \ {\n    if (r.size() > this->size()) this->resize(r.size());\n    for (int i\
    \ = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n    return *this;\n  }\n\n\
    \  FPS &operator-=(const mint &r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] -= r;\n    return *this;\n  }\n\n  FPS &operator*=(const mint\
    \ &v) {\n    for (int k = 0; k < (int)this->size(); k++) (*this)[k] *= v;\n  \
    \  return *this;\n  }\n\n  FPS &operator/=(const FPS &r) {\n    if (this->size()\
    \ < r.size()) {\n      this->clear();\n      return *this;\n    }\n    int n =\
    \ this->size() - r.size() + 1;\n    if ((int)r.size() <= 64) {\n      FPS f(*this),\
    \ g(r);\n      g.shrink();\n      mint coeff = g.back().inverse();\n      for\
    \ (auto &x : g) x *= coeff;\n      int deg = (int)f.size() - (int)g.size() + 1;\n\
    \      int gs = g.size();\n      FPS quo(deg);\n      for (int i = deg - 1; i\
    \ >= 0; i--) {\n        quo[i] = f[i + gs - 1];\n        for (int j = 0; j < gs;\
    \ j++) f[i + j] -= quo[i] * g[j];\n      }\n      *this = quo * coeff;\n     \
    \ this->resize(n, mint(0));\n      return *this;\n    }\n    return *this = ((*this).rev().pre(n)\
    \ * r.rev().inv(n)).pre(n).rev();\n  }\n\n  FPS &operator%=(const FPS &r) {\n\
    \    *this -= *this / r * r;\n    shrink();\n    return *this;\n  }\n\n  FPS operator+(const\
    \ FPS &r) const { return FPS(*this) += r; }\n  FPS operator+(const mint &v) const\
    \ { return FPS(*this) += v; }\n  FPS operator-(const FPS &r) const { return FPS(*this)\
    \ -= r; }\n  FPS operator-(const mint &v) const { return FPS(*this) -= v; }\n\
    \  FPS operator*(const FPS &r) const { return FPS(*this) *= r; }\n  FPS operator*(const\
    \ mint &v) const { return FPS(*this) *= v; }\n  FPS operator/(const FPS &r) const\
    \ { return FPS(*this) /= r; }\n  FPS operator%(const FPS &r) const { return FPS(*this)\
    \ %= r; }\n  FPS operator-() const {\n    FPS ret(this->size());\n    for (int\
    \ i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];\n    return ret;\n\
    \  }\n\n  void shrink() {\n    while (this->size() && this->back() == mint(0))\
    \ this->pop_back();\n  }\n\n  FPS rev() const {\n    FPS ret(*this);\n    reverse(begin(ret),\
    \ end(ret));\n    return ret;\n  }\n\n  FPS dot(FPS r) const {\n    FPS ret(min(this->size(),\
    \ r.size()));\n    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i]\
    \ * r[i];\n    return ret;\n  }\n\n  FPS pre(int sz) const {\n    return FPS(begin(*this),\
    \ begin(*this) + min((int)this->size(), sz));\n  }\n\n  FPS operator>>(int sz)\
    \ const {\n    if ((int)this->size() <= sz) return {};\n    FPS ret(*this);\n\
    \    ret.erase(ret.begin(), ret.begin() + sz);\n    return ret;\n  }\n\n  FPS\
    \ operator<<(int sz) const {\n    FPS ret(*this);\n    ret.insert(ret.begin(),\
    \ sz, mint(0));\n    return ret;\n  }\n\n  FPS diff() const {\n    const int n\
    \ = (int)this->size();\n    FPS ret(max(0, n - 1));\n    mint one(1), coeff(1);\n\
    \    for (int i = 1; i < n; i++) {\n      ret[i - 1] = (*this)[i] * coeff;\n \
    \     coeff += one;\n    }\n    return ret;\n  }\n\n  FPS integral() const {\n\
    \    const int n = (int)this->size();\n    FPS ret(n + 1);\n    ret[0] = mint(0);\n\
    \    if (n > 0) ret[1] = mint(1);\n    auto mod = mint::get_mod();\n    for (int\
    \ i = 2; i <= n; i++) ret[i] = (-ret[mod % i]) * (mod / i);\n    for (int i =\
    \ 0; i < n; i++) ret[i + 1] *= (*this)[i];\n    return ret;\n  }\n\n  mint eval(mint\
    \ x) const {\n    mint r = 0, w = 1;\n    for (auto &v : *this) r += w * v, w\
    \ *= x;\n    return r;\n  }\n\n  FPS log(int deg = -1) const {\n    assert((*this)[0]\
    \ == mint(1));\n    if (deg == -1) deg = (int)this->size();\n    return (this->diff()\
    \ * this->inv(deg)).pre(deg - 1).integral();\n  }\n\n  FPS pow(int64_t k, int\
    \ deg = -1) const {\n    const int n = (int)this->size();\n    if (deg == -1)\
    \ deg = n;\n    for (int i = 0; i < n; i++) {\n      if ((*this)[i] != mint(0))\
    \ {\n        if (i * k > deg) return FPS(deg, mint(0));\n        mint rev = mint(1)\
    \ / (*this)[i];\n        FPS ret =\n            (((*this * rev) >> i).log(deg)\
    \ * k).exp(deg) * ((*this)[i].pow(k));\n        ret = (ret << (i * k)).pre(deg);\n\
    \        if ((int)ret.size() < deg) ret.resize(deg, mint(0));\n        return\
    \ ret;\n      }\n    }\n    return FPS(deg, mint(0));\n  }\n\n  static void *ntt_ptr;\n\
    \  static void set_fft();\n  FPS &operator*=(const FPS &r);\n  void ntt();\n \
    \ void intt();\n  void ntt_doubling();\n  static int ntt_pr();\n  FPS inv(int\
    \ deg = -1) const;\n  FPS exp(int deg = -1) const;\n};\ntemplate <typename mint>\n\
    void *FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\n/**\n * @brief \u591A\u9805\
    \u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\u30E9\u30EA\n *\
    \ @docs docs/fps/formal-power-series.md\n */\n#line 2 \"modint/montgomery-modint.hpp\"\
    \n\n\n\ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt {\n  using mint =\
    \ LazyMontgomeryModInt;\n  using i32 = int32_t;\n  using u32 = uint32_t;\n  using\
    \ u64 = uint64_t;\n\n  static constexpr u32 get_r() {\n    u32 ret = mod;\n  \
    \  for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n\
    \  static constexpr u32 r = get_r();\n  static constexpr u32 n2 = -u64(mod) %\
    \ mod;\n  static_assert(r * mod == 1, \"invalid, r * mod != 1\");\n  static_assert(mod\
    \ < (1 << 30), \"invalid, mod >= 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"\
    invalid, mod % 2 == 0\");\n\n  u32 a;\n\n  constexpr LazyMontgomeryModInt() :\
    \ a(0) {}\n  constexpr LazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b\
    \ % mod + mod) * n2)){};\n\n  static constexpr u32 reduce(const u64 &b) {\n  \
    \  return (b + u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  constexpr mint &operator+=(const\
    \ mint &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n\
    \  }\n\n  constexpr mint &operator-=(const mint &b) {\n    if (i32(a -= b.a) <\
    \ 0) a += 2 * mod;\n    return *this;\n  }\n\n  constexpr mint &operator*=(const\
    \ mint &b) {\n    a = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  constexpr\
    \ mint &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return *this;\n\
    \  }\n\n  constexpr mint operator+(const mint &b) const { return mint(*this) +=\
    \ b; }\n  constexpr mint operator-(const mint &b) const { return mint(*this) -=\
    \ b; }\n  constexpr mint operator*(const mint &b) const { return mint(*this) *=\
    \ b; }\n  constexpr mint operator/(const mint &b) const { return mint(*this) /=\
    \ b; }\n  constexpr bool operator==(const mint &b) const {\n    return (a >= mod\
    \ ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n  constexpr bool operator!=(const\
    \ mint &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a -\
    \ mod : b.a);\n  }\n  constexpr mint operator-() const { return mint() - mint(*this);\
    \ }\n\n  constexpr mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n   \
    \ while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>=\
    \ 1;\n    }\n    return ret;\n  }\n  \n  constexpr mint inverse() const { return\
    \ pow(mod - 2); }\n\n  friend ostream &operator<<(ostream &os, const mint &b)\
    \ {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is,\
    \ mint &b) {\n    int64_t t;\n    is >> t;\n    b = LazyMontgomeryModInt<mod>(t);\n\
    \    return (is);\n  }\n  \n  constexpr u32 get() const {\n    u32 ret = reduce(a);\n\
    \    return ret >= mod ? ret - mod : ret;\n  }\n\n  static constexpr u32 get_mod()\
    \ { return mod; }\n};\n#line 3 \"modulo/strassen.hpp\"\n//\n\n\n\n#line 2 \"modint/simd-montgomery.hpp\"\
    \n\n\n#line 5 \"modint/simd-montgomery.hpp\"\n\n__attribute__((target(\"sse4.2\"\
    ))) __attribute__((always_inline)) __m128i\nmy128_mullo_epu32(const __m128i &a,\
    \ const __m128i &b) {\n  return _mm_mullo_epi32(a, b);\n}\n\n__attribute__((target(\"\
    sse4.2\"))) __attribute__((always_inline)) __m128i\nmy128_mulhi_epu32(const __m128i\
    \ &a, const __m128i &b) {\n  __m128i a13 = _mm_shuffle_epi32(a, 0xF5);\n  __m128i\
    \ b13 = _mm_shuffle_epi32(b, 0xF5);\n  __m128i prod02 = _mm_mul_epu32(a, b);\n\
    \  __m128i prod13 = _mm_mul_epu32(a13, b13);\n  __m128i prod = _mm_unpackhi_epi64(_mm_unpacklo_epi32(prod02,\
    \ prod13),\n                                    _mm_unpackhi_epi32(prod02, prod13));\n\
    \  return prod;\n}\n\n__attribute__((target(\"sse4.2\"))) __attribute__((always_inline))\
    \ __m128i\nmontgomery_mul_128(const __m128i &a, const __m128i &b, const __m128i\
    \ &r,\n                   const __m128i &m1) {\n  return _mm_sub_epi32(\n    \
    \  _mm_add_epi32(my128_mulhi_epu32(a, b), m1),\n      my128_mulhi_epu32(my128_mullo_epu32(my128_mullo_epu32(a,\
    \ b), r), m1));\n}\n\n__attribute__((target(\"sse4.2\"))) __attribute__((always_inline))\
    \ __m128i\nmontgomery_add_128(const __m128i &a, const __m128i &b, const __m128i\
    \ &m2,\n                   const __m128i &m0) {\n  __m128i ret = _mm_sub_epi32(_mm_add_epi32(a,\
    \ b), m2);\n  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2),\
    \ ret);\n}\n\n__attribute__((target(\"sse4.2\"))) __attribute__((always_inline))\
    \ __m128i\nmontgomery_sub_128(const __m128i &a, const __m128i &b, const __m128i\
    \ &m2,\n                   const __m128i &m0) {\n  __m128i ret = _mm_sub_epi32(a,\
    \ b);\n  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2), ret);\n\
    }\n\n__attribute__((target(\"avx2\"))) __attribute__((always_inline)) __m256i\n\
    my256_mullo_epu32(const __m256i &a, const __m256i &b) {\n  return _mm256_mullo_epi32(a,\
    \ b);\n}\n\n__attribute__((target(\"avx2\"))) __attribute__((always_inline)) __m256i\n\
    my256_mulhi_epu32(const __m256i &a, const __m256i &b) {\n  __m256i a13 = _mm256_shuffle_epi32(a,\
    \ 0xF5);\n  __m256i b13 = _mm256_shuffle_epi32(b, 0xF5);\n  __m256i prod02 = _mm256_mul_epu32(a,\
    \ b);\n  __m256i prod13 = _mm256_mul_epu32(a13, b13);\n  __m256i prod = _mm256_unpackhi_epi64(_mm256_unpacklo_epi32(prod02,\
    \ prod13),\n                                       _mm256_unpackhi_epi32(prod02,\
    \ prod13));\n  return prod;\n}\n\n__attribute__((target(\"avx2\"))) __attribute__((always_inline))\
    \ __m256i\nmontgomery_mul_256(const __m256i &a, const __m256i &b, const __m256i\
    \ &r,\n                   const __m256i &m1) {\n  return _mm256_sub_epi32(\n \
    \     _mm256_add_epi32(my256_mulhi_epu32(a, b), m1),\n      my256_mulhi_epu32(my256_mullo_epu32(my256_mullo_epu32(a,\
    \ b), r), m1));\n}\n\n__attribute__((target(\"avx2\"))) __attribute__((always_inline))\
    \ __m256i\nmontgomery_add_256(const __m256i &a, const __m256i &b, const __m256i\
    \ &m2,\n                   const __m256i &m0) {\n  __m256i ret = _mm256_sub_epi32(_mm256_add_epi32(a,\
    \ b), m2);\n  return _mm256_add_epi32(_mm256_and_si256(_mm256_cmpgt_epi32(m0,\
    \ ret), m2),\n                          ret);\n}\n\n__attribute__((target(\"avx2\"\
    ))) __attribute__((always_inline)) __m256i\nmontgomery_sub_256(const __m256i &a,\
    \ const __m256i &b, const __m256i &m2,\n                   const __m256i &m0)\
    \ {\n  __m256i ret = _mm256_sub_epi32(a, b);\n  return _mm256_add_epi32(_mm256_and_si256(_mm256_cmpgt_epi32(m0,\
    \ ret), m2),\n                          ret);\n}\n#line 10 \"modulo/strassen.hpp\"\
    \n\nnamespace FastMatProd {\n\nusing mint = LazyMontgomeryModInt<998244353>;\n\
    using vm = vector<mint>;\nusing vvm = vector<vm>;\nusing fps = FormalPowerSeries<mint>;\n\
    using u32 = uint32_t;\nusing i32 = int32_t;\nusing u64 = uint64_t;\nusing m256\
    \ = __m256i;\n\nconstexpr u32 SHIFT_ = 6;\nu32 a[1 << (SHIFT_ * 2)] __attribute__((aligned(64)));\n\
    u32 b[1 << (SHIFT_ * 2)] __attribute__((aligned(64)));\nu32 c[1 << (SHIFT_ * 2)]\
    \ __attribute__((aligned(64)));\n\n__attribute__((target(\"avx2\"), optimize(\"\
    O3\", \"unroll-loops\"))) void\ninner_simd_mul(u32 n, u32 m, u32 p) {\n  memset(c,\
    \ 0, sizeof(c));\n  const m256 R = _mm256_set1_epi32(mint::r);\n  const m256 M0\
    \ = _mm256_set1_epi32(0);\n  const m256 M1 = _mm256_set1_epi32(mint::get_mod());\n\
    \  const m256 M2 = _mm256_set1_epi32(mint::get_mod() << 1);\n\n  u32 k0 = 0;\n\
    \  for (; i32(k0) < i32(p) - 3; k0 += 4) {\n    const u32 k1 = k0 + 1;\n    const\
    \ u32 k2 = k0 + 2;\n    const u32 k3 = k0 + 3;\n    u32 j0 = 0;\n    for (; i32(j0)\
    \ < i32(m) - 7; j0 += 8) {\n      const m256 B00 = _mm256_load_si256((m256*)(b\
    \ + (k0 << SHIFT_) + j0));\n      const m256 B10 = _mm256_load_si256((m256*)(b\
    \ + (k1 << SHIFT_) + j0));\n      const m256 B20 = _mm256_load_si256((m256*)(b\
    \ + (k2 << SHIFT_) + j0));\n      const m256 B30 = _mm256_load_si256((m256*)(b\
    \ + (k3 << SHIFT_) + j0));\n      for (u32 i0 = 0; i0 < n; ++i0) {\n        const\
    \ m256 A00 = _mm256_set1_epi32(a[(i0 << SHIFT_) | k0]);\n        const m256 A01\
    \ = _mm256_set1_epi32(a[(i0 << SHIFT_) | k1]);\n        const m256 A02 = _mm256_set1_epi32(a[(i0\
    \ << SHIFT_) | k2]);\n        const m256 A03 = _mm256_set1_epi32(a[(i0 << SHIFT_)\
    \ | k3]);\n        const m256 A00B00 = montgomery_mul_256(A00, B00, R, M1);\n\
    \        const m256 A01B10 = montgomery_mul_256(A01, B10, R, M1);\n        const\
    \ m256 A02B20 = montgomery_mul_256(A02, B20, R, M1);\n        const m256 A03B30\
    \ = montgomery_mul_256(A03, B30, R, M1);\n        const u32* pc00 = c + (i0 <<\
    \ SHIFT_) + j0;\n        const m256 C00 = _mm256_load_si256((m256*)pc00);\n  \
    \      const m256 C00_01 = montgomery_add_256(A00B00, A01B10, M2, M0);\n     \
    \   const m256 C00_23 = montgomery_add_256(A02B20, A03B30, M2, M0);\n        const\
    \ m256 C00_al = montgomery_add_256(C00_01, C00_23, M2, M0);\n        const m256\
    \ C00_ad = montgomery_add_256(C00, C00_al, M2, M0);\n        _mm256_store_si256((m256*)pc00,\
    \ C00_ad);\n      }\n    }\n    for (; j0 < m; j0++) {\n      for (u32 i0 = 0;\
    \ i0 < n; ++i0) {\n        u32 ab0 =\n            mint::reduce(u64(a[(i0 << SHIFT_)\
    \ | k0]) * b[(k0 << SHIFT_) | j0]);\n        u32 ab1 =\n            mint::reduce(u64(a[(i0\
    \ << SHIFT_) | k1]) * b[(k1 << SHIFT_) | j0]);\n        u32 ab2 =\n          \
    \  mint::reduce(u64(a[(i0 << SHIFT_) | k2]) * b[(k2 << SHIFT_) | j0]);\n     \
    \   u32 ab3 =\n            mint::reduce(u64(a[(i0 << SHIFT_) | k3]) * b[(k3 <<\
    \ SHIFT_) | j0]);\n        if ((ab0 += ab1) >= 2 * mint::get_mod()) ab0 -= 2 *\
    \ mint::get_mod();\n        if ((ab2 += ab3) >= 2 * mint::get_mod()) ab2 -= 2\
    \ * mint::get_mod();\n        if ((ab0 += ab2) >= 2 * mint::get_mod()) ab0 -=\
    \ 2 * mint::get_mod();\n        if ((c[(i0 << SHIFT_) | j0] += ab0) >= 2 * mint::get_mod())\n\
    \          c[(i0 << SHIFT_) | j0] -= 2 * mint::get_mod();\n      }\n    }\n  }\n\
    \n  for (; k0 < p; k0++) {\n    u32 j0 = 0;\n    for (; i32(j0) < i32(m) - 7;\
    \ j0 += 8) {\n      const m256 B00 = _mm256_load_si256((m256*)(b + (k0 << SHIFT_)\
    \ + j0));\n      for (u32 i0 = 0; i0 < n; ++i0) {\n        const m256 A00 = _mm256_set1_epi32(a[(i0\
    \ << SHIFT_) | k0]);\n        const m256 A00B00 = montgomery_mul_256(A00, B00,\
    \ R, M1);\n        const u32* pc00 = c + (i0 << SHIFT_) + j0;\n        const m256\
    \ C00 = _mm256_load_si256((m256*)pc00);\n        const m256 C00_ad = montgomery_add_256(C00,\
    \ A00B00, M2, M0);\n        _mm256_store_si256((m256*)pc00, C00_ad);\n      }\n\
    \    }\n    for (; j0 < m; j0++) {\n      for (u32 i0 = 0; i0 < n; ++i0) {\n \
    \       u32 ab0 =\n            mint::reduce(u64(a[(i0 << SHIFT_) | k0]) * b[(k0\
    \ << SHIFT_) | j0]);\n        if ((c[(i0 << SHIFT_) | j0] += ab0) >= 2 * mint::get_mod())\n\
    \          c[(i0 << SHIFT_) | j0] -= 2 * mint::get_mod();\n      }\n    }\n  }\n\
    }\n\n// for debug\n__attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"\
    ))) vvm naive_mul(\n    const vvm& a, const vvm& b) {\n  int n = a.size(), m =\
    \ b[0].size(), p = b.size();\n  assert(p == (int)a[0].size());\n  vvm c(n, fps(m,\
    \ 0));\n  for (int i = 0; i < n; i++)\n    for (int k = 0; k < p; k++)\n     \
    \ for (int j = 0; j < m; j++) c[i][j] += a[i][k] * b[k][j];\n  return c;\n}\n\n\
    struct Mat {\n  int H, W, HM, WM;\n  mint* a;\n\n  Mat(int H_, int W_, mint* a_)\
    \ : H(H_), W(W_), a(a_) {\n    HM = (H >> 1) + (H & 1);\n    WM = (W >> 1) + (W\
    \ & 1);\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"\
    ))) void\n  range_add(mint* b, int as, int ae, int bs) const {\n    const m256\
    \ M0 = _mm256_set1_epi32(0);\n    const m256 M2 = _mm256_set1_epi32(mint::get_mod()\
    \ * 2);\n    for (; as < ae - 31; as += 32, bs += 32) {\n      int a0 = as;\n\
    \      int a1 = as + 8;\n      int a2 = as + 16;\n      int a3 = as + 24;\n  \
    \    int b0 = bs;\n      int b1 = bs + 8;\n      int b2 = bs + 16;\n      int\
    \ b3 = bs + 24;\n      const m256 A0 = _mm256_loadu_si256((m256*)(a + a0));\n\
    \      const m256 A1 = _mm256_loadu_si256((m256*)(a + a1));\n      const m256\
    \ A2 = _mm256_loadu_si256((m256*)(a + a2));\n      const m256 A3 = _mm256_loadu_si256((m256*)(a\
    \ + a3));\n      const m256 B0 = _mm256_loadu_si256((m256*)(b + b0));\n      const\
    \ m256 B1 = _mm256_loadu_si256((m256*)(b + b1));\n      const m256 B2 = _mm256_loadu_si256((m256*)(b\
    \ + b2));\n      const m256 B3 = _mm256_loadu_si256((m256*)(b + b3));\n      const\
    \ m256 BA0 = montgomery_add_256(B0, A0, M2, M0);\n      const m256 BA1 = montgomery_add_256(B1,\
    \ A1, M2, M0);\n      const m256 BA2 = montgomery_add_256(B2, A2, M2, M0);\n \
    \     const m256 BA3 = montgomery_add_256(B3, A3, M2, M0);\n      _mm256_storeu_si256((m256*)(b\
    \ + b0), BA0);\n      _mm256_storeu_si256((m256*)(b + b1), BA1);\n      _mm256_storeu_si256((m256*)(b\
    \ + b2), BA2);\n      _mm256_storeu_si256((m256*)(b + b3), BA3);\n    }\n    for\
    \ (; as < ae; ++as, ++bs) b[bs] += a[as];\n  }\n\n  __attribute__((target(\"avx2\"\
    ), optimize(\"O3\", \"unroll-loops\"))) void\n  range_sub(mint* b, int as, int\
    \ ae, int bs) const {\n    const m256 M0 = _mm256_set1_epi32(0);\n    const m256\
    \ M2 = _mm256_set1_epi32(mint::get_mod() * 2);\n    for (; as < ae - 31; as +=\
    \ 32, bs += 32) {\n      int a0 = as;\n      int a1 = as + 8;\n      int a2 =\
    \ as + 16;\n      int a3 = as + 24;\n      int b0 = bs;\n      int b1 = bs + 8;\n\
    \      int b2 = bs + 16;\n      int b3 = bs + 24;\n      const m256 A0 = _mm256_loadu_si256((m256*)(a\
    \ + a0));\n      const m256 A1 = _mm256_loadu_si256((m256*)(a + a1));\n      const\
    \ m256 A2 = _mm256_loadu_si256((m256*)(a + a2));\n      const m256 A3 = _mm256_loadu_si256((m256*)(a\
    \ + a3));\n      const m256 B0 = _mm256_loadu_si256((m256*)(b + b0));\n      const\
    \ m256 B1 = _mm256_loadu_si256((m256*)(b + b1));\n      const m256 B2 = _mm256_loadu_si256((m256*)(b\
    \ + b2));\n      const m256 B3 = _mm256_loadu_si256((m256*)(b + b3));\n      const\
    \ m256 BA0 = montgomery_sub_256(B0, A0, M2, M0);\n      const m256 BA1 = montgomery_sub_256(B1,\
    \ A1, M2, M0);\n      const m256 BA2 = montgomery_sub_256(B2, A2, M2, M0);\n \
    \     const m256 BA3 = montgomery_sub_256(B3, A3, M2, M0);\n      _mm256_storeu_si256((m256*)(b\
    \ + b0), BA0);\n      _mm256_storeu_si256((m256*)(b + b1), BA1);\n      _mm256_storeu_si256((m256*)(b\
    \ + b2), BA2);\n      _mm256_storeu_si256((m256*)(b + b3), BA3);\n    }\n    for\
    \ (; as < ae; ++as, ++bs) b[bs] -= a[as];\n  }\n\n  __attribute__((target(\"avx2\"\
    ), optimize(\"O3\", \"unroll-loops\"))) void\n  op_range_add(mint* b, int as,\
    \ int ae, int bs) const {\n    const m256 M0 = _mm256_set1_epi32(0);\n    const\
    \ m256 M2 = _mm256_set1_epi32(mint::get_mod() * 2);\n    for (; as < ae - 31;\
    \ as += 32, bs += 32) {\n      int a0 = as;\n      int a1 = as + 8;\n      int\
    \ a2 = as + 16;\n      int a3 = as + 24;\n      int b0 = bs;\n      int b1 = bs\
    \ + 8;\n      int b2 = bs + 16;\n      int b3 = bs + 24;\n      const m256 A0\
    \ = _mm256_loadu_si256((m256*)(a + a0));\n      const m256 A1 = _mm256_loadu_si256((m256*)(a\
    \ + a1));\n      const m256 A2 = _mm256_loadu_si256((m256*)(a + a2));\n      const\
    \ m256 A3 = _mm256_loadu_si256((m256*)(a + a3));\n      const m256 B0 = _mm256_loadu_si256((m256*)(b\
    \ + b0));\n      const m256 B1 = _mm256_loadu_si256((m256*)(b + b1));\n      const\
    \ m256 B2 = _mm256_loadu_si256((m256*)(b + b2));\n      const m256 B3 = _mm256_loadu_si256((m256*)(b\
    \ + b3));\n      const m256 BA0 = montgomery_add_256(B0, A0, M2, M0);\n      const\
    \ m256 BA1 = montgomery_add_256(B1, A1, M2, M0);\n      const m256 BA2 = montgomery_add_256(B2,\
    \ A2, M2, M0);\n      const m256 BA3 = montgomery_add_256(B3, A3, M2, M0);\n \
    \     _mm256_storeu_si256((m256*)(a + a0), BA0);\n      _mm256_storeu_si256((m256*)(a\
    \ + a1), BA1);\n      _mm256_storeu_si256((m256*)(a + a2), BA2);\n      _mm256_storeu_si256((m256*)(a\
    \ + a3), BA3);\n    }\n    for (; as < ae; ++as, ++bs) a[as] += b[bs];\n  }\n\n\
    \  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"))) void\n\
    \  op_range_sub(mint* b, int as, int ae, int bs) const {\n    const m256 M0 =\
    \ _mm256_set1_epi32(0);\n    const m256 M2 = _mm256_set1_epi32(mint::get_mod()\
    \ * 2);\n    for (; as < ae - 31; as += 32, bs += 32) {\n      int a0 = as;\n\
    \      int a1 = as + 8;\n      int a2 = as + 16;\n      int a3 = as + 24;\n  \
    \    int b0 = bs;\n      int b1 = bs + 8;\n      int b2 = bs + 16;\n      int\
    \ b3 = bs + 24;\n      const m256 A0 = _mm256_loadu_si256((m256*)(a + a0));\n\
    \      const m256 A1 = _mm256_loadu_si256((m256*)(a + a1));\n      const m256\
    \ A2 = _mm256_loadu_si256((m256*)(a + a2));\n      const m256 A3 = _mm256_loadu_si256((m256*)(a\
    \ + a3));\n      const m256 B0 = _mm256_loadu_si256((m256*)(b + b0));\n      const\
    \ m256 B1 = _mm256_loadu_si256((m256*)(b + b1));\n      const m256 B2 = _mm256_loadu_si256((m256*)(b\
    \ + b2));\n      const m256 B3 = _mm256_loadu_si256((m256*)(b + b3));\n      const\
    \ m256 BA0 = montgomery_sub_256(A0, B0, M2, M0);\n      const m256 BA1 = montgomery_sub_256(A1,\
    \ B1, M2, M0);\n      const m256 BA2 = montgomery_sub_256(A2, B2, M2, M0);\n \
    \     const m256 BA3 = montgomery_sub_256(A3, B3, M2, M0);\n      _mm256_storeu_si256((m256*)(a\
    \ + a0), BA0);\n      _mm256_storeu_si256((m256*)(a + a1), BA1);\n      _mm256_storeu_si256((m256*)(a\
    \ + a2), BA2);\n      _mm256_storeu_si256((m256*)(a + a3), BA3);\n    }\n    for\
    \ (; as < ae; ++as, ++bs) a[as] -= b[bs];\n  }\n\n  __attribute__((target(\"avx2\"\
    ), optimize(\"O3\", \"unroll-loops\"))) inline void\n  A11(mint* b) const {\n\
    \    for (int i = 0; i < HM; i++)\n      memcpy(b + i * WM, a + i * W, WM * sizeof(int));\n\
    \  }\n\n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\")))\
    \ inline void\n  A12(mint* b) const {\n    for (int i = 0; i < HM; i++)\n    \
    \  memcpy(b + i * WM, a + i * W + WM, (W - WM) * sizeof(int));\n  }\n\n  __attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) inline void\n  A21(mint* b) const\
    \ {\n    for (int i = 0; i < H - HM; i++)\n      memcpy(b + i * WM, a + (i + HM)\
    \ * W, WM * sizeof(int));\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"\
    O3\", \"unroll-loops\"))) inline void\n  A22(mint* b) const {\n    for (int i\
    \ = 0; i < H - HM; i++)\n      memcpy(b + i * WM, a + (i + HM) * W + WM, (W -\
    \ WM) * sizeof(int));\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"O3\"\
    , \"unroll-loops\"))) inline void\n  subA11(mint* b) const {\n    for (int i =\
    \ 0; i < HM; i++) {\n      int as = i * W;\n      int ae = i * W + WM;\n     \
    \ int bs = i * WM;\n      range_sub(b, as, ae, bs);\n    }\n  }\n\n  __attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) inline void\n  addA12(mint* b) const\
    \ {\n    for (int i = 0; i < HM; i++) {\n      int as = i * W + WM;\n      int\
    \ ae = i * W + W;\n      int bs = i * WM;\n      range_add(b, as, ae, bs);\n \
    \   }\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"\
    ))) inline void\n  addA22(mint* b) const {\n    for (int i = 0; i < H - HM; i++)\
    \ {\n      int as = (i + HM) * W + WM;\n      int ae = as + W - WM;\n      int\
    \ bs = i * WM;\n      range_add(b, as, ae, bs);\n    }\n  }\n\n  __attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) inline void\n  subA22(mint* b) const\
    \ {\n    for (int i = 0; i < H - HM; i++) {\n      int as = (i + HM) * W + WM;\n\
    \      int ae = as + W - WM;\n      int bs = i * WM;\n      range_sub(b, as, ae,\
    \ bs);\n    }\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"\
    ))) inline void\n  updA11(mint* b) const {\n    for (int i = 0; i < HM; i++)\n\
    \      memcpy(a + i * W, b + i * WM, WM * sizeof(int));\n  }\n\n  __attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) inline void\n  updA12(mint* b) const\
    \ {\n    for (int i = 0; i < HM; i++)\n      memcpy(a + i * W + WM, b + i * WM,\
    \ (W - WM) * sizeof(int));\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"\
    O3\", \"unroll-loops\"))) inline void\n  updA21(mint* b) const {\n    for (int\
    \ i = 0; i < H - HM; i++)\n      memcpy(a + (i + HM) * W, b + i * WM, WM * sizeof(int));\n\
    \  }\n\n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\")))\
    \ inline void\n  updA22(mint* b) const {\n    for (int i = 0; i < H - HM; i++)\n\
    \      memcpy(a + (i + HM) * W + WM, b + i * WM, (W - WM) * sizeof(int));\n  }\n\
    \n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"))) inline\
    \ void\n  opaddA11(mint* b) const {\n    for (int i = 0; i < HM; i++) {\n    \
    \  int as = i * W;\n      int ae = i * W + WM;\n      int bs = i * WM;\n     \
    \ op_range_add(b, as, ae, bs);\n    }\n  }\n\n  __attribute__((target(\"avx2\"\
    ), optimize(\"O3\", \"unroll-loops\"))) inline void\n  opaddA12(mint* b) const\
    \ {\n    for (int i = 0; i < HM; i++) {\n      int as = i * W + WM;\n      int\
    \ ae = i * W + W;\n      int bs = i * WM;\n      op_range_add(b, as, ae, bs);\n\
    \    }\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"\
    ))) inline void\n  opaddA21(mint* b) const {\n    for (int i = 0; i < H - HM;\
    \ i++) {\n      int as = (i + HM) * W;\n      int ae = (i + HM) * W + WM;\n  \
    \    int bs = i * WM;\n      op_range_add(b, as, ae, bs);\n    }\n    //  for\
    \ (int j = 0; j < WM; j++) a[(i + HM) * W + j] += b[i * WM + j];\n  }\n\n  __attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) inline void\n  opaddA22(mint* b)\
    \ const {\n    for (int i = 0; i < H - HM; i++) {\n      int as = (i + HM) * W\
    \ + WM;\n      int ae = (i + HM) * W + W;\n      int bs = i * WM;\n      op_range_add(b,\
    \ as, ae, bs);\n    }\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"O3\"\
    , \"unroll-loops\"))) inline void\n  opsubA11(mint* b) const {\n    for (int i\
    \ = 0; i < HM; i++) {\n      int as = i * W;\n      int ae = i * W + WM;\n   \
    \   int bs = i * WM;\n      op_range_sub(b, as, ae, bs);\n    }\n  }\n\n  __attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) inline void\n  opsubA22(mint* b)\
    \ const {\n    for (int i = 0; i < H - HM; i++) {\n      int as = (i + HM) * W\
    \ + WM;\n      int ae = (i + HM) * W + W;\n      int bs = i * WM;\n      op_range_sub(b,\
    \ as, ae, bs);\n    }\n  }\n\n  void dump() const {\n    cerr << \"[ \" << endl\
    \ << \" \";\n    for (int i = 0; i < H; i++)\n      for (int j = 0; j < W; j++)\n\
    \        cerr << a[i * W + j] << (j == W - 1 ? \",\\n \" : \" \");\n    cerr <<\
    \ \"] \" << endl;\n  }\n};\n\n#ifndef BUFFER_SIZE\n#define BUFFER_SIZE (1 << 21)\n\
    #endif\nmint A[BUFFER_SIZE] __attribute__((aligned(64)));\nmint B[BUFFER_SIZE]\
    \ __attribute__((aligned(64)));\nmint C[BUFFER_SIZE] __attribute__((aligned(64)));\n\
    \n__attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"))) void\n\
    inner_fast_mul(const Mat* s, const Mat* t, const Mat* u) {\n  int n = s->H, m\
    \ = t->W, p = s->W;\n  for (int i = 0; i < n; i++)\n    memcpy((mint*)(a + (i\
    \ << SHIFT_)), s->a + i * p, p * sizeof(int));\n  for (int i = 0; i < p; i++)\n\
    \    memcpy((mint*)(b + (i << SHIFT_)), t->a + i * m, m * sizeof(int));\n  inner_simd_mul(n,\
    \ m, p);\n  for (int i = 0; i < n; i++)\n    memcpy(u->a + i * m, (mint*)(c +\
    \ (i << SHIFT_)), m * sizeof(int));\n}\n\n__attribute__((target(\"avx2\"), optimize(\"\
    O3\", \"unroll-loops\"))) void\ninner_block_dec_mul(const Mat* s, const Mat* t,\
    \ const Mat* u) {\n  int n = s->H, m = t->W, p = s->W;\n  memset((int*)(u->a),\
    \ 0, n * m * sizeof(int));\n  for (int is = 0; is < n; is += (1 << SHIFT_))\n\
    \    for (int ks = 0; ks < p; ks += (1 << SHIFT_))\n      for (int js = 0; js\
    \ < m; js += (1 << SHIFT_)) {\n        int ie = min(is + (1 << SHIFT_), n);\n\
    \        int je = min(js + (1 << SHIFT_), m);\n        int ke = min(ks + (1 <<\
    \ SHIFT_), p);\n        for (int l = is; l < ie; l++)\n          memcpy((mint*)(a\
    \ + ((l - is) << SHIFT_)), s->a + l * p + ks,\n                 (ke - ks) * sizeof(int));\n\
    \        for (int l = ks; l < ke; l++)\n          memcpy((mint*)(b + ((l - ks)\
    \ << SHIFT_)), t->a + l * m + js,\n                 (je - js) * sizeof(int));\n\
    \        inner_simd_mul(ie - is, je - js, ke - ks);\n        for (int l = is;\
    \ l < ie; l++) {\n          for (int ll = js; ll < je; ll++) {\n            u->a[l\
    \ * m + ll] +=\n                *reinterpret_cast<mint*>(c + ((l - is) << SHIFT_)\
    \ + (ll - js));\n          }\n        }\n      }\n}\n\n__attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) void\ninner_strassen(const Mat*\
    \ a, const Mat* b, const Mat* c) {\n  int n = a->H, m = b->W, p = a->W;\n  if\
    \ (max({n, m, p}) <= (1 << SHIFT_)) {\n    inner_fast_mul(a, b, c);\n    return;\n\
    \  }\n  if (min({n, m, p}) <= (1 << (SHIFT_ - 2))) {\n    inner_block_dec_mul(a,\
    \ b, c);\n    return;\n  }\n  int nm = n / 2 + (n & 1);\n  int mm = m / 2 + (m\
    \ & 1);\n  int pm = p / 2 + (p & 1);\n\n  Mat s(nm, pm, a->a + n * p);\n  Mat\
    \ t(pm, mm, b->a + p * m);\n  Mat u(nm, mm, c->a + n * m);\n\n  // P1 = (A11 +\
    \ A22) * (B11 + B22)\n  a->A11(s.a);\n  a->addA22(s.a);\n  b->A11(t.a);\n  b->addA22(t.a);\n\
    \  inner_strassen(&s, &t, &u);\n  c->updA11(u.a);\n  c->updA22(u.a);\n\n  // P2\
    \ = (A21 + A22) * B11\n  memset((int*)s.a, 0, nm * pm * sizeof(int));\n  a->A21(s.a);\n\
    \  a->addA22(s.a);\n  b->A11(t.a);\n  inner_strassen(&s, &t, &u);\n  c->updA21(u.a);\n\
    \  c->opsubA22(u.a);\n\n  // P3 = A11 (B12 - B22)\n  a->A11(s.a);\n  memset((int*)t.a,\
    \ 0, pm * mm * sizeof(int));\n  b->A12(t.a);\n  b->subA22(t.a);\n  inner_strassen(&s,\
    \ &t, &u);\n  c->updA12(u.a);\n  c->opaddA22(u.a);\n\n  // P4 = A22 (B21 - B11)\n\
    \  memset((int*)s.a, 0, nm * pm * sizeof(int));\n  a->A22(s.a);\n  memset((int*)t.a\
    \ + (pm - 1) * mm, 0, mm * sizeof(int));\n  b->A21(t.a);\n  b->subA11(t.a);\n\
    \  inner_strassen(&s, &t, &u);\n  c->opaddA11(u.a);\n  c->opaddA21(u.a);\n\n \
    \ // P5 = (A11 + A12) B22\n  memset((int*)t.a, 0, pm * mm * sizeof(int));\n  a->A11(s.a);\n\
    \  a->addA12(s.a);\n  b->A22(t.a);\n  inner_strassen(&s, &t, &u);\n  c->opsubA11(u.a);\n\
    \  c->opaddA12(u.a);\n\n  // P6 = (A21 - A11) (B11 + B12)\n  memset((int*)s.a\
    \ + (nm - 1) * pm, 0, pm * sizeof(int));\n  a->A21(s.a);\n  a->subA11(s.a);\n\
    \  b->A11(t.a);\n  b->addA12(t.a);\n  inner_strassen(&s, &t, &u);\n  c->opaddA22(u.a);\n\
    \n  // P7 = (A12 - A22) (B21 + B22)\n  memset((int*)s.a, 0, nm * pm * sizeof(int));\n\
    \  a->A12(s.a);\n  a->subA22(s.a);\n  memset((int*)t.a + (pm - 1) * mm, 0, mm\
    \ * sizeof(int));\n  b->A21(t.a);\n  b->addA22(t.a);\n  inner_strassen(&s, &t,\
    \ &u);\n  c->opaddA11(u.a);\n}\n\nusing vfps = vector<fps>;\n\n__attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) vvm block_dec(\n    const vvm& s,\
    \ const vvm& t) {\n  int n = s.size(), p = s[0].size(), m = t[0].size();\n  assert(int(n\
    \ * p * 1.4) <= BUFFER_SIZE);\n  assert(int(p * m * 1.4) <= BUFFER_SIZE);\n  assert(int(n\
    \ * m * 1.4) <= BUFFER_SIZE);\n  memset(A, 0, int(n * p * 1.4) * sizeof(int));\n\
    \  memset(B, 0, int(p * m * 1.4) * sizeof(int));\n  memset(C, 0, int(m * n * 1.4)\
    \ * sizeof(int));\n\n  for (int i = 0; i < n; i++) memcpy(A + i * p, s[i].data(),\
    \ p * sizeof(int));\n  for (int i = 0; i < p; i++) memcpy(B + i * m, t[i].data(),\
    \ m * sizeof(int));\n\n  Mat S(n, p, A), T(p, m, B), U(n, m, C);\n  inner_block_dec_mul(&S,\
    \ &T, &U);\n  vvm u(n, vm(m));\n  for (int i = 0; i < n; i++) memcpy(u[i].data(),\
    \ C + i * m, m * sizeof(int));\n  return std::move(u);\n}\n\n__attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) vfps block_dec(\n    const vfps&\
    \ s, const vfps& t) {\n  int n = s.size(), p = s[0].size(), m = t[0].size();\n\
    \  assert(int(n * p * 1.4) <= BUFFER_SIZE);\n  assert(int(p * m * 1.4) <= BUFFER_SIZE);\n\
    \  assert(int(n * m * 1.4) <= BUFFER_SIZE);\n  memset(A, 0, int(n * p * 1.4) *\
    \ sizeof(int));\n  memset(B, 0, int(p * m * 1.4) * sizeof(int));\n  memset(C,\
    \ 0, int(m * n * 1.4) * sizeof(int));\n\n  for (int i = 0; i < n; i++) memcpy(A\
    \ + i * p, s[i].data(), p * sizeof(int));\n  for (int i = 0; i < p; i++) memcpy(B\
    \ + i * m, t[i].data(), m * sizeof(int));\n\n  Mat S(n, p, A), T(p, m, B), U(n,\
    \ m, C);\n  inner_block_dec_mul(&S, &T, &U);\n  vfps u(n, fps(m));\n  for (int\
    \ i = 0; i < n; i++) memcpy(u[i].data(), C + i * m, m * sizeof(int));\n  return\
    \ std::move(u);\n}\n\n__attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"\
    ))) vvm strassen(\n    const vvm& s, const vvm& t) {\n  int n = s.size(), p =\
    \ s[0].size(), m = t[0].size();\n  assert(int(n * p * 1.4) <= BUFFER_SIZE);\n\
    \  assert(int(p * m * 1.4) <= BUFFER_SIZE);\n  assert(int(n * m * 1.4) <= BUFFER_SIZE);\n\
    \  memset(A, 0, int(n * p * 1.4) * sizeof(int));\n  memset(B, 0, int(p * m * 1.4)\
    \ * sizeof(int));\n  memset(C, 0, int(m * n * 1.4) * sizeof(int));\n\n  for (int\
    \ i = 0; i < n; i++) memcpy(A + i * p, s[i].data(), p * sizeof(int));\n  for (int\
    \ i = 0; i < p; i++) memcpy(B + i * m, t[i].data(), m * sizeof(int));\n\n  Mat\
    \ S(n, p, A), T(p, m, B), U(n, m, C);\n  inner_strassen(&S, &T, &U);\n  vvm u(n,\
    \ vm(m));\n  for (int i = 0; i < n; i++) memcpy(u[i].data(), C + i * m, m * sizeof(int));\n\
    \  return std::move(u);\n}\n\n__attribute__((target(\"avx2\"), optimize(\"O3\"\
    , \"unroll-loops\"))) vfps strassen(\n    const vfps& s, const vfps& t) {\n  int\
    \ n = s.size(), p = s[0].size(), m = t[0].size();\n  assert(int(n * p * 1.4) <=\
    \ BUFFER_SIZE);\n  assert(int(p * m * 1.4) <= BUFFER_SIZE);\n  assert(int(n *\
    \ m * 1.4) <= BUFFER_SIZE);\n  memset(A, 0, int(n * p * 1.4) * sizeof(int));\n\
    \  memset(B, 0, int(p * m * 1.4) * sizeof(int));\n  memset(C, 0, int(m * n * 1.4)\
    \ * sizeof(int));\n\n  for (int i = 0; i < n; i++) memcpy(A + i * p, s[i].data(),\
    \ p * sizeof(int));\n  for (int i = 0; i < p; i++) memcpy(B + i * m, t[i].data(),\
    \ m * sizeof(int));\n\n  Mat S(n, p, A), T(p, m, B), U(n, m, C);\n  inner_strassen(&S,\
    \ &T, &U);\n  vfps u(n, fps(m));\n  for (int i = 0; i < n; i++) memcpy(u[i].data(),\
    \ C + i * m, m * sizeof(int));\n  return std::move(u);\n}\n\n#ifdef BUFFER_SIZE\n\
    #undef BUFFER_SIZE\n#endif\n\n#line 2 \"misc/timer.hpp\"\n\nstruct Timer {\n \
    \ chrono::high_resolution_clock::time_point st;\n\n  Timer() { reset(); }\n\n\
    \  void reset() { st = chrono::high_resolution_clock::now(); }\n\n  chrono::milliseconds::rep\
    \ elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n    return\
    \ chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n};\n#line\
    \ 635 \"modulo/strassen.hpp\"\nvoid time_test() {\n  int N = 1024;\n  int P =\
    \ N, M = N;\n  mt19937 rng(58);\n  vvm s(N, vm(P)), t(P, vm(M));\n  for (int i\
    \ = 0; i < N; i++)\n    for (int j = 0; j < P; j++) s[i][j] = rng() % 998244353;\n\
    \  for (int i = 0; i < P; i++)\n    for (int j = 0; j < M; j++) t[i][j] = rng()\
    \ % 998244353;\n  vvm u, u2;\n  Timer timer;\n\n  int loop = 5;\n  timer.reset();\n\
    \  for (int i = 0; i < loop; i++) u = FastMatProd::strassen(s, t);\n  cout <<\
    \ \"strassen \" << (timer.elapsed() / loop) << endl;\n\n  timer.reset();\n  u2\
    \ = FastMatProd::naive_mul(s, t);\n  cout << \"naive \" << (timer.elapsed() /\
    \ loop) << endl;\n\n  timer.reset();\n  auto u3 = FastMatProd::block_dec(s, t);\n\
    \  cout << \"block dec \" << (timer.elapsed() / loop) << endl;\n\n  assert(u ==\
    \ u2);\n  assert(u == u3);\n}\n\nvoid debug_test() {\n  // time_test();\n  int\
    \ N, P, M;\n  mt19937 rng(58);\n  int loop = 1000;\n  while (loop--) {\n    N\
    \ = rng() % 500 + 1;\n    M = rng() % 500 + 1;\n    P = rng() % 500 + 1;\n   \
    \ vvm s(N, vm(P)), t(P, vm(M));\n    for (int i = 0; i < N; i++)\n      for (int\
    \ j = 0; j < P; j++) s[i][j] = rng() % 998244353;\n    for (int i = 0; i < P;\
    \ i++)\n      for (int j = 0; j < M; j++) t[i][j] = rng() % 998244353;\n    auto\
    \ u = strassen(s, t);\n    auto u2 = naive_mul(s, t);\n    auto u3 = block_dec(s,\
    \ t);\n    if (u != u2) {\n      cout << \"ng u1 \" << N << \" \" << P << \" \"\
    \ << M << endl;\n      exit(1);\n    } else if (u != u3) {\n      cout << \"ng\
    \ u1 \" << N << \" \" << P << \" \" << M << endl;\n      exit(1);\n    } else\
    \ {\n      cout << \"ok \" << N << \" \" << P << \" \" << M << endl;\n    }\n\
    \  }\n  cout << \"all ok\";\n}\n}  // namespace FastMatProd\n#line 5 \"fps/fps-composition-fast.hpp\"\
    \n\nusing mint = LazyMontgomeryModInt<998244353>;\nusing fps = FormalPowerSeries<mint>;\n\
    \n__attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"))) fps Composition(\n\
    \    fps P, fps Q, int deg = -1) {\n  int N = (deg == -1) ? min(P.size(), Q.size())\
    \ : deg;\n  if (N == 0) return fps{};\n  P.shrink();\n  if (P.size() == 0) {\n\
    \    fps R(N, mint(0));\n    R[0] = Q.empty() ? mint(0) : Q[0];\n    return R;\n\
    \  }\n  if (N == 1) return fps{Q.eval(P[0])};\n\n  int K = max<int>(ceil(sqrt(N)),\
    \ 2);\n  assert(N <= K * K);\n\n  vector<fps> PS(K + 1);\n  {\n    // step 1\n\
    \    PS[0].resize(N, mint());\n    PS[0][0] = 1;\n    PS[1] = P;\n    fps::set_fft();\n\
    \    if (fps::ntt_ptr == nullptr) {\n      for (int i = 2; i <= K; i++) PS[i]\
    \ = (PS[i - 1] * P).pre(N);\n    } else {\n      int len = 1 << (32 - __builtin_clz(2\
    \ * N - 2));\n      fps Pomega = P;\n      Pomega.resize(len);\n      Pomega.ntt();\n\
    \      for (int i = 2; i <= K; i++) {\n        PS[i].resize(len);\n        for\
    \ (int j = 0; j < N; j++) PS[i][j] = PS[i - 1][j];\n        PS[i].ntt();\n   \
    \     for (int j = 0; j < len; j++) PS[i][j] *= Pomega[j];\n        PS[i].intt();\n\
    \        PS[i].resize(N);\n        PS[i].shrink_to_fit();\n      }\n    }\n  }\n\
    \n  vector<fps> TS(K);\n  {\n    // step 2\n    TS[0].resize(N, mint());\n   \
    \ TS[0][0] = 1;\n    TS[1] = PS[K];\n    if (fps::ntt_ptr == nullptr) {\n    \
    \  for (int i = 2; i < K; i++) TS[i] = (TS[i - 1] * TS[1]).pre(N);\n    } else\
    \ {\n      int len = 1 << (32 - __builtin_clz(2 * N - 2));\n      fps Tomega =\
    \ TS[1];\n      Tomega.resize(len);\n      Tomega.ntt();\n      for (int i = 2;\
    \ i < K; i++) {\n        TS[i].resize(len);\n        for (int j = 0; j < N; j++)\
    \ TS[i][j] = TS[i - 1][j];\n        TS[i].ntt();\n        for (int j = 0; j <\
    \ len; j++) TS[i][j] *= Tomega[j];\n        TS[i].intt();\n        TS[i].resize(N);\n\
    \        TS[i].shrink_to_fit();\n      }\n    }\n  }\n\n  // step 3\n  vector<fps>\
    \ QP;\n  {\n    PS.pop_back();\n    vector<fps> QS(K, fps(K, mint()));\n    for\
    \ (int i = 0; i < K; i++)\n      for (int j = 0; j < K; j++) {\n        QS[i][j]\
    \ = (i * K + j) < (int)Q.size() ? Q[i * K + j] : mint();\n      }\n    QP = FastMatProd::strassen(QS,\
    \ PS);\n  }\n\n  fps ans(N, mint());\n  {\n    // step 4,5\n    for (int i = 0;\
    \ i < K; i++) ans += (QP[i] * TS[i]).pre(N);\n  }\n  return ans;\n}\n\n/**\n *\
    \ @brief \u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}(N^2)$ )\n */\n#line 2 \"\
    fps/ntt-friendly-fps.hpp\"\n\n#line 2 \"ntt/ntt-avx2.hpp\"\n\n#line 4 \"ntt/ntt-avx2.hpp\"\
    \n\nnamespace ntt_inner {\nusing u64 = uint64_t;\nconstexpr uint32_t get_pr(uint32_t\
    \ mod) {\n  if (mod == 2) return 1;\n  u64 ds[32] = {};\n  int idx = 0;\n  u64\
    \ m = mod - 1;\n  for (u64 i = 2; i * i <= m; ++i) {\n    if (m % i == 0) {\n\
    \      ds[idx++] = i;\n      while (m % i == 0) m /= i;\n    }\n  }\n  if (m !=\
    \ 1) ds[idx++] = m;\n\n  uint32_t pr = 2;\n  while (1) {\n    int flg = 1;\n \
    \   for (int i = 0; i < idx; ++i) {\n      u64 a = pr, b = (mod - 1) / ds[i],\
    \ r = 1;\n      while (b) {\n        if (b & 1) r = r * a % mod;\n        a =\
    \ a * a % mod;\n        b >>= 1;\n      }\n      if (r == 1) {\n        flg =\
    \ 0;\n        break;\n      }\n    }\n    if (flg == 1) break;\n    ++pr;\n  }\n\
    \  return pr;\n}\n\nconstexpr int SZ_FFT_BUF = 1 << 23;\nuint32_t _buf1[SZ_FFT_BUF]\
    \ __attribute__((aligned(64)));\nuint32_t _buf2[SZ_FFT_BUF] __attribute__((aligned(64)));\n\
    }  // namespace ntt_inner\n\ntemplate <typename mint>\nstruct NTT {\n  static\
    \ constexpr uint32_t mod = mint::get_mod();\n  static constexpr uint32_t pr =\
    \ ntt_inner::get_pr(mint::get_mod());\n  static constexpr int level = __builtin_ctzll(mod\
    \ - 1);\n  mint dw[level], dy[level];\n  mint *buf1, *buf2;\n\n  constexpr NTT()\
    \ {\n    setwy(level);\n    union raw_cast {\n      mint dat;\n      uint32_t\
    \ _;\n    };\n    buf1 = &(((raw_cast *)(ntt_inner::_buf1))->dat);\n    buf2 =\
    \ &(((raw_cast *)(ntt_inner::_buf2))->dat);\n  }\n\n  constexpr void setwy(int\
    \ k) {\n    mint w[level], y[level];\n    w[k - 1] = mint(pr).pow((mod - 1) /\
    \ (1 << k));\n    y[k - 1] = w[k - 1].inverse();\n    for (int i = k - 2; i >\
    \ 0; --i)\n      w[i] = w[i + 1] * w[i + 1], y[i] = y[i + 1] * y[i + 1];\n   \
    \ dw[0] = dy[0] = w[1] * w[1];\n    dw[1] = w[1], dy[1] = y[1], dw[2] = w[2],\
    \ dy[2] = y[2];\n    for (int i = 3; i < k; ++i) {\n      dw[i] = dw[i - 1] *\
    \ y[i - 2] * w[i];\n      dy[i] = dy[i - 1] * w[i - 2] * y[i];\n    }\n  }\n\n\
    \  __attribute__((target(\"avx2\"))) void ntt(mint *a, int n) {\n    int k = n\
    \ ? __builtin_ctz(n) : 0;\n    if (k == 0) return;\n    if (k == 1) {\n      mint\
    \ a1 = a[1];\n      a[1] = a[0] - a[1];\n      a[0] = a[0] + a1;\n      return;\n\
    \    }\n    if (k & 1) {\n      int v = 1 << (k - 1);\n      if (v < 8) {\n  \
    \      for (int j = 0; j < v; ++j) {\n          mint ajv = a[j + v];\n       \
    \   a[j + v] = a[j] - ajv;\n          a[j] += ajv;\n        }\n      } else {\n\
    \        const __m256i m0 = _mm256_set1_epi32(0);\n        const __m256i m2 =\
    \ _mm256_set1_epi32(mod + mod);\n        int j0 = 0;\n        int j1 = v;\n  \
    \      for (; j0 < v; j0 += 8, j1 += 8) {\n          __m256i T0 = _mm256_loadu_si256((__m256i\
    \ *)(a + j0));\n          __m256i T1 = _mm256_loadu_si256((__m256i *)(a + j1));\n\
    \          __m256i naj = montgomery_add_256(T0, T1, m2, m0);\n          __m256i\
    \ najv = montgomery_sub_256(T0, T1, m2, m0);\n          _mm256_storeu_si256((__m256i\
    \ *)(a + j0), naj);\n          _mm256_storeu_si256((__m256i *)(a + j1), najv);\n\
    \        }\n      }\n    }\n    int u = 1 << (2 + (k & 1));\n    int v = 1 <<\
    \ (k - 2 - (k & 1));\n    mint one = mint(1);\n    mint imag = dw[1];\n    while\
    \ (v) {\n      if (v == 1) {\n        mint ww = one, xx = one, wx = one;\n   \
    \     for (int jh = 0; jh < u;) {\n          ww = xx * xx, wx = ww * xx;\n   \
    \       mint t0 = a[jh + 0], t1 = a[jh + 1] * xx;\n          mint t2 = a[jh +\
    \ 2] * ww, t3 = a[jh + 3] * wx;\n          mint t0p2 = t0 + t2, t1p3 = t1 + t3;\n\
    \          mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;\n          a[jh + 0]\
    \ = t0p2 + t1p3, a[jh + 1] = t0p2 - t1p3;\n          a[jh + 2] = t0m2 + t1m3,\
    \ a[jh + 3] = t0m2 - t1m3;\n          xx *= dw[__builtin_ctz((jh += 4))];\n  \
    \      }\n      } else if (v == 4) {\n        const __m128i m0 = _mm_set1_epi32(0);\n\
    \        const __m128i m1 = _mm_set1_epi32(mod);\n        const __m128i m2 = _mm_set1_epi32(mod\
    \ + mod);\n        const __m128i r = _mm_set1_epi32(mint::r);\n        const __m128i\
    \ Imag = _mm_set1_epi32(imag.a);\n        mint ww = one, xx = one, wx = one;\n\
    \        for (int jh = 0; jh < u;) {\n          if (jh == 0) {\n            int\
    \ j0 = 0;\n            int j1 = v;\n            int j2 = j1 + v;\n           \
    \ int j3 = j2 + v;\n            int je = v;\n            for (; j0 < je; j0 +=\
    \ 4, j1 += 4, j2 += 4, j3 += 4) {\n              const __m128i T0 = _mm_loadu_si128((__m128i\
    \ *)(a + j0));\n              const __m128i T1 = _mm_loadu_si128((__m128i *)(a\
    \ + j1));\n              const __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));\n\
    \              const __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));\n    \
    \          const __m128i T0P2 = montgomery_add_128(T0, T2, m2, m0);\n        \
    \      const __m128i T1P3 = montgomery_add_128(T1, T3, m2, m0);\n            \
    \  const __m128i T0M2 = montgomery_sub_128(T0, T2, m2, m0);\n              const\
    \ __m128i T1M3 = montgomery_mul_128(\n                  montgomery_sub_128(T1,\
    \ T3, m2, m0), Imag, r, m1);\n              _mm_storeu_si128((__m128i *)(a + j0),\n\
    \                               montgomery_add_128(T0P2, T1P3, m2, m0));\n   \
    \           _mm_storeu_si128((__m128i *)(a + j1),\n                          \
    \     montgomery_sub_128(T0P2, T1P3, m2, m0));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j2),\n                               montgomery_add_128(T0M2, T1M3, m2,\
    \ m0));\n              _mm_storeu_si128((__m128i *)(a + j3),\n               \
    \                montgomery_sub_128(T0M2, T1M3, m2, m0));\n            }\n   \
    \       } else {\n            ww = xx * xx, wx = ww * xx;\n            const __m128i\
    \ WW = _mm_set1_epi32(ww.a);\n            const __m128i WX = _mm_set1_epi32(wx.a);\n\
    \            const __m128i XX = _mm_set1_epi32(xx.a);\n            int j0 = jh\
    \ * v;\n            int j1 = j0 + v;\n            int j2 = j1 + v;\n         \
    \   int j3 = j2 + v;\n            int je = j1;\n            for (; j0 < je; j0\
    \ += 4, j1 += 4, j2 += 4, j3 += 4) {\n              const __m128i T0 = _mm_loadu_si128((__m128i\
    \ *)(a + j0));\n              const __m128i T1 = _mm_loadu_si128((__m128i *)(a\
    \ + j1));\n              const __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));\n\
    \              const __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));\n    \
    \          const __m128i MT1 = montgomery_mul_128(T1, XX, r, m1);\n          \
    \    const __m128i MT2 = montgomery_mul_128(T2, WW, r, m1);\n              const\
    \ __m128i MT3 = montgomery_mul_128(T3, WX, r, m1);\n              const __m128i\
    \ T0P2 = montgomery_add_128(T0, MT2, m2, m0);\n              const __m128i T1P3\
    \ = montgomery_add_128(MT1, MT3, m2, m0);\n              const __m128i T0M2 =\
    \ montgomery_sub_128(T0, MT2, m2, m0);\n              const __m128i T1M3 = montgomery_mul_128(\n\
    \                  montgomery_sub_128(MT1, MT3, m2, m0), Imag, r, m1);\n     \
    \         _mm_storeu_si128((__m128i *)(a + j0),\n                            \
    \   montgomery_add_128(T0P2, T1P3, m2, m0));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j1),\n                               montgomery_sub_128(T0P2, T1P3, m2,\
    \ m0));\n              _mm_storeu_si128((__m128i *)(a + j2),\n               \
    \                montgomery_add_128(T0M2, T1M3, m2, m0));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j3),\n                               montgomery_sub_128(T0M2, T1M3, m2,\
    \ m0));\n            }\n          }\n          xx *= dw[__builtin_ctz((jh += 4))];\n\
    \        }\n      } else {\n        const __m256i m0 = _mm256_set1_epi32(0);\n\
    \        const __m256i m1 = _mm256_set1_epi32(mod);\n        const __m256i m2\
    \ = _mm256_set1_epi32(mod + mod);\n        const __m256i r = _mm256_set1_epi32(mint::r);\n\
    \        const __m256i Imag = _mm256_set1_epi32(imag.a);\n        mint ww = one,\
    \ xx = one, wx = one;\n        for (int jh = 0; jh < u;) {\n          if (jh ==\
    \ 0) {\n            int j0 = 0;\n            int j1 = v;\n            int j2 =\
    \ j1 + v;\n            int j3 = j2 + v;\n            int je = v;\n           \
    \ for (; j0 < je; j0 += 8, j1 += 8, j2 += 8, j3 += 8) {\n              const __m256i\
    \ T0 = _mm256_loadu_si256((__m256i *)(a + j0));\n              const __m256i T1\
    \ = _mm256_loadu_si256((__m256i *)(a + j1));\n              const __m256i T2 =\
    \ _mm256_loadu_si256((__m256i *)(a + j2));\n              const __m256i T3 = _mm256_loadu_si256((__m256i\
    \ *)(a + j3));\n              const __m256i T0P2 = montgomery_add_256(T0, T2,\
    \ m2, m0);\n              const __m256i T1P3 = montgomery_add_256(T1, T3, m2,\
    \ m0);\n              const __m256i T0M2 = montgomery_sub_256(T0, T2, m2, m0);\n\
    \              const __m256i T1M3 = montgomery_mul_256(\n                  montgomery_sub_256(T1,\
    \ T3, m2, m0), Imag, r, m1);\n              _mm256_storeu_si256((__m256i *)(a\
    \ + j0),\n                                  montgomery_add_256(T0P2, T1P3, m2,\
    \ m0));\n              _mm256_storeu_si256((__m256i *)(a + j1),\n            \
    \                      montgomery_sub_256(T0P2, T1P3, m2, m0));\n            \
    \  _mm256_storeu_si256((__m256i *)(a + j2),\n                                \
    \  montgomery_add_256(T0M2, T1M3, m2, m0));\n              _mm256_storeu_si256((__m256i\
    \ *)(a + j3),\n                                  montgomery_sub_256(T0M2, T1M3,\
    \ m2, m0));\n            }\n          } else {\n            ww = xx * xx, wx =\
    \ ww * xx;\n            const __m256i WW = _mm256_set1_epi32(ww.a);\n        \
    \    const __m256i WX = _mm256_set1_epi32(wx.a);\n            const __m256i XX\
    \ = _mm256_set1_epi32(xx.a);\n            int j0 = jh * v;\n            int j1\
    \ = j0 + v;\n            int j2 = j1 + v;\n            int j3 = j2 + v;\n    \
    \        int je = j1;\n            for (; j0 < je; j0 += 8, j1 += 8, j2 += 8,\
    \ j3 += 8) {\n              const __m256i T0 = _mm256_loadu_si256((__m256i *)(a\
    \ + j0));\n              const __m256i T1 = _mm256_loadu_si256((__m256i *)(a +\
    \ j1));\n              const __m256i T2 = _mm256_loadu_si256((__m256i *)(a + j2));\n\
    \              const __m256i T3 = _mm256_loadu_si256((__m256i *)(a + j3));\n \
    \             const __m256i MT1 = montgomery_mul_256(T1, XX, r, m1);\n       \
    \       const __m256i MT2 = montgomery_mul_256(T2, WW, r, m1);\n             \
    \ const __m256i MT3 = montgomery_mul_256(T3, WX, r, m1);\n              const\
    \ __m256i T0P2 = montgomery_add_256(T0, MT2, m2, m0);\n              const __m256i\
    \ T1P3 = montgomery_add_256(MT1, MT3, m2, m0);\n              const __m256i T0M2\
    \ = montgomery_sub_256(T0, MT2, m2, m0);\n              const __m256i T1M3 = montgomery_mul_256(\n\
    \                  montgomery_sub_256(MT1, MT3, m2, m0), Imag, r, m1);\n     \
    \         _mm256_storeu_si256((__m256i *)(a + j0),\n                         \
    \         montgomery_add_256(T0P2, T1P3, m2, m0));\n              _mm256_storeu_si256((__m256i\
    \ *)(a + j1),\n                                  montgomery_sub_256(T0P2, T1P3,\
    \ m2, m0));\n              _mm256_storeu_si256((__m256i *)(a + j2),\n        \
    \                          montgomery_add_256(T0M2, T1M3, m2, m0));\n        \
    \      _mm256_storeu_si256((__m256i *)(a + j3),\n                            \
    \      montgomery_sub_256(T0M2, T1M3, m2, m0));\n            }\n          }\n\
    \          xx *= dw[__builtin_ctz((jh += 4))];\n        }\n      }\n      u <<=\
    \ 2;\n      v >>= 2;\n    }\n  }\n\n  __attribute__((target(\"avx2\"))) void intt(mint\
    \ *a, int n,\n                                            int normalize = true)\
    \ {\n    int k = n ? __builtin_ctz(n) : 0;\n    if (k == 0) return;\n    if (k\
    \ == 1) {\n      mint a1 = a[1];\n      a[1] = a[0] - a[1];\n      a[0] = a[0]\
    \ + a1;\n      if (normalize) {\n        a[0] *= mint(2).inverse();\n        a[1]\
    \ *= mint(2).inverse();\n      }\n      return;\n    }\n    int u = 1 << (k -\
    \ 2);\n    int v = 1;\n    mint one = mint(1);\n    mint imag = dy[1];\n    while\
    \ (u) {\n      if (v == 1) {\n        mint ww = one, xx = one, yy = one;\n   \
    \     u <<= 2;\n        for (int jh = 0; jh < u;) {\n          ww = xx * xx, yy\
    \ = xx * imag;\n          mint t0 = a[jh + 0], t1 = a[jh + 1];\n          mint\
    \ t2 = a[jh + 2], t3 = a[jh + 3];\n          mint t0p1 = t0 + t1, t2p3 = t2 +\
    \ t3;\n          mint t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;\n        \
    \  a[jh + 0] = t0p1 + t2p3, a[jh + 2] = (t0p1 - t2p3) * ww;\n          a[jh +\
    \ 1] = t0m1 + t2m3, a[jh + 3] = (t0m1 - t2m3) * ww;\n          xx *= dy[__builtin_ctz(jh\
    \ += 4)];\n        }\n      } else if (v == 4) {\n        const __m128i m0 = _mm_set1_epi32(0);\n\
    \        const __m128i m1 = _mm_set1_epi32(mod);\n        const __m128i m2 = _mm_set1_epi32(mod\
    \ + mod);\n        const __m128i r = _mm_set1_epi32(mint::r);\n        const __m128i\
    \ Imag = _mm_set1_epi32(imag.a);\n        mint ww = one, xx = one, yy = one;\n\
    \        u <<= 2;\n        for (int jh = 0; jh < u;) {\n          if (jh == 0)\
    \ {\n            int j0 = 0;\n            int j1 = v;\n            int j2 = v\
    \ + v;\n            int j3 = j2 + v;\n            for (; j0 < v; j0 += 4, j1 +=\
    \ 4, j2 += 4, j3 += 4) {\n              const __m128i T0 = _mm_loadu_si128((__m128i\
    \ *)(a + j0));\n              const __m128i T1 = _mm_loadu_si128((__m128i *)(a\
    \ + j1));\n              const __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));\n\
    \              const __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));\n    \
    \          const __m128i T0P1 = montgomery_add_128(T0, T1, m2, m0);\n        \
    \      const __m128i T2P3 = montgomery_add_128(T2, T3, m2, m0);\n            \
    \  const __m128i T0M1 = montgomery_sub_128(T0, T1, m2, m0);\n              const\
    \ __m128i T2M3 = montgomery_mul_128(\n                  montgomery_sub_128(T2,\
    \ T3, m2, m0), Imag, r, m1);\n              _mm_storeu_si128((__m128i *)(a + j0),\n\
    \                               montgomery_add_128(T0P1, T2P3, m2, m0));\n   \
    \           _mm_storeu_si128((__m128i *)(a + j2),\n                          \
    \     montgomery_sub_128(T0P1, T2P3, m2, m0));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j1),\n                               montgomery_add_128(T0M1, T2M3, m2,\
    \ m0));\n              _mm_storeu_si128((__m128i *)(a + j3),\n               \
    \                montgomery_sub_128(T0M1, T2M3, m2, m0));\n            }\n   \
    \       } else {\n            ww = xx * xx, yy = xx * imag;\n            const\
    \ __m128i WW = _mm_set1_epi32(ww.a);\n            const __m128i XX = _mm_set1_epi32(xx.a);\n\
    \            const __m128i YY = _mm_set1_epi32(yy.a);\n            int j0 = jh\
    \ * v;\n            int j1 = j0 + v;\n            int j2 = j1 + v;\n         \
    \   int j3 = j2 + v;\n            int je = j1;\n            for (; j0 < je; j0\
    \ += 4, j1 += 4, j2 += 4, j3 += 4) {\n              const __m128i T0 = _mm_loadu_si128((__m128i\
    \ *)(a + j0));\n              const __m128i T1 = _mm_loadu_si128((__m128i *)(a\
    \ + j1));\n              const __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));\n\
    \              const __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));\n    \
    \          const __m128i T0P1 = montgomery_add_128(T0, T1, m2, m0);\n        \
    \      const __m128i T2P3 = montgomery_add_128(T2, T3, m2, m0);\n            \
    \  const __m128i T0M1 = montgomery_mul_128(\n                  montgomery_sub_128(T0,\
    \ T1, m2, m0), XX, r, m1);\n              __m128i T2M3 = montgomery_mul_128(\n\
    \                  montgomery_sub_128(T2, T3, m2, m0), YY, r, m1);\n         \
    \     _mm_storeu_si128((__m128i *)(a + j0),\n                               montgomery_add_128(T0P1,\
    \ T2P3, m2, m0));\n              _mm_storeu_si128(\n                  (__m128i\
    \ *)(a + j2),\n                  montgomery_mul_128(montgomery_sub_128(T0P1, T2P3,\
    \ m2, m0), WW,\n                                     r, m1));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j1),\n                               montgomery_add_128(T0M1, T2M3, m2,\
    \ m0));\n              _mm_storeu_si128(\n                  (__m128i *)(a + j3),\n\
    \                  montgomery_mul_128(montgomery_sub_128(T0M1, T2M3, m2, m0),\
    \ WW,\n                                     r, m1));\n            }\n        \
    \  }\n          xx *= dy[__builtin_ctz(jh += 4)];\n        }\n      } else {\n\
    \        const __m256i m0 = _mm256_set1_epi32(0);\n        const __m256i m1 =\
    \ _mm256_set1_epi32(mod);\n        const __m256i m2 = _mm256_set1_epi32(mod +\
    \ mod);\n        const __m256i r = _mm256_set1_epi32(mint::r);\n        const\
    \ __m256i Imag = _mm256_set1_epi32(imag.a);\n        mint ww = one, xx = one,\
    \ yy = one;\n        u <<= 2;\n        for (int jh = 0; jh < u;) {\n         \
    \ if (jh == 0) {\n            int j0 = 0;\n            int j1 = v;\n         \
    \   int j2 = v + v;\n            int j3 = j2 + v;\n            for (; j0 < v;\
    \ j0 += 8, j1 += 8, j2 += 8, j3 += 8) {\n              const __m256i T0 = _mm256_loadu_si256((__m256i\
    \ *)(a + j0));\n              const __m256i T1 = _mm256_loadu_si256((__m256i *)(a\
    \ + j1));\n              const __m256i T2 = _mm256_loadu_si256((__m256i *)(a +\
    \ j2));\n              const __m256i T3 = _mm256_loadu_si256((__m256i *)(a + j3));\n\
    \              const __m256i T0P1 = montgomery_add_256(T0, T1, m2, m0);\n    \
    \          const __m256i T2P3 = montgomery_add_256(T2, T3, m2, m0);\n        \
    \      const __m256i T0M1 = montgomery_sub_256(T0, T1, m2, m0);\n            \
    \  const __m256i T2M3 = montgomery_mul_256(\n                  montgomery_sub_256(T2,\
    \ T3, m2, m0), Imag, r, m1);\n              _mm256_storeu_si256((__m256i *)(a\
    \ + j0),\n                                  montgomery_add_256(T0P1, T2P3, m2,\
    \ m0));\n              _mm256_storeu_si256((__m256i *)(a + j2),\n            \
    \                      montgomery_sub_256(T0P1, T2P3, m2, m0));\n            \
    \  _mm256_storeu_si256((__m256i *)(a + j1),\n                                \
    \  montgomery_add_256(T0M1, T2M3, m2, m0));\n              _mm256_storeu_si256((__m256i\
    \ *)(a + j3),\n                                  montgomery_sub_256(T0M1, T2M3,\
    \ m2, m0));\n            }\n          } else {\n            ww = xx * xx, yy =\
    \ xx * imag;\n            const __m256i WW = _mm256_set1_epi32(ww.a);\n      \
    \      const __m256i XX = _mm256_set1_epi32(xx.a);\n            const __m256i\
    \ YY = _mm256_set1_epi32(yy.a);\n            int j0 = jh * v;\n            int\
    \ j1 = j0 + v;\n            int j2 = j1 + v;\n            int j3 = j2 + v;\n \
    \           int je = j1;\n            for (; j0 < je; j0 += 8, j1 += 8, j2 +=\
    \ 8, j3 += 8) {\n              const __m256i T0 = _mm256_loadu_si256((__m256i\
    \ *)(a + j0));\n              const __m256i T1 = _mm256_loadu_si256((__m256i *)(a\
    \ + j1));\n              const __m256i T2 = _mm256_loadu_si256((__m256i *)(a +\
    \ j2));\n              const __m256i T3 = _mm256_loadu_si256((__m256i *)(a + j3));\n\
    \              const __m256i T0P1 = montgomery_add_256(T0, T1, m2, m0);\n    \
    \          const __m256i T2P3 = montgomery_add_256(T2, T3, m2, m0);\n        \
    \      const __m256i T0M1 = montgomery_mul_256(\n                  montgomery_sub_256(T0,\
    \ T1, m2, m0), XX, r, m1);\n              const __m256i T2M3 = montgomery_mul_256(\n\
    \                  montgomery_sub_256(T2, T3, m2, m0), YY, r, m1);\n         \
    \     _mm256_storeu_si256((__m256i *)(a + j0),\n                             \
    \     montgomery_add_256(T0P1, T2P3, m2, m0));\n              _mm256_storeu_si256(\n\
    \                  (__m256i *)(a + j2),\n                  montgomery_mul_256(montgomery_sub_256(T0P1,\
    \ T2P3, m2, m0), WW,\n                                     r, m1));\n        \
    \      _mm256_storeu_si256((__m256i *)(a + j1),\n                            \
    \      montgomery_add_256(T0M1, T2M3, m2, m0));\n              _mm256_storeu_si256(\n\
    \                  (__m256i *)(a + j3),\n                  montgomery_mul_256(montgomery_sub_256(T0M1,\
    \ T2M3, m2, m0), WW,\n                                     r, m1));\n        \
    \    }\n          }\n          xx *= dy[__builtin_ctz(jh += 4)];\n        }\n\
    \      }\n      u >>= 4;\n      v <<= 2;\n    }\n    if (k & 1) {\n      v = 1\
    \ << (k - 1);\n      if (v < 8) {\n        for (int j = 0; j < v; ++j) {\n   \
    \       mint ajv = a[j] - a[j + v];\n          a[j] += a[j + v];\n          a[j\
    \ + v] = ajv;\n        }\n      } else {\n        const __m256i m0 = _mm256_set1_epi32(0);\n\
    \        const __m256i m2 = _mm256_set1_epi32(mod + mod);\n        int j0 = 0;\n\
    \        int j1 = v;\n        for (; j0 < v; j0 += 8, j1 += 8) {\n          const\
    \ __m256i T0 = _mm256_loadu_si256((__m256i *)(a + j0));\n          const __m256i\
    \ T1 = _mm256_loadu_si256((__m256i *)(a + j1));\n          __m256i naj = montgomery_add_256(T0,\
    \ T1, m2, m0);\n          __m256i najv = montgomery_sub_256(T0, T1, m2, m0);\n\
    \          _mm256_storeu_si256((__m256i *)(a + j0), naj);\n          _mm256_storeu_si256((__m256i\
    \ *)(a + j1), najv);\n        }\n      }\n    }\n    if (normalize) {\n      mint\
    \ invn = mint(n).inverse();\n      for (int i = 0; i < n; i++) a[i] *= invn;\n\
    \    }\n  }\n\n  __attribute__((target(\"avx2\"))) void inplace_multiply(\n  \
    \    int l1, int l2, int zero_padding = true) {\n    int l = l1 + l2 - 1;\n  \
    \  int M = 4;\n    while (M < l) M <<= 1;\n    if (zero_padding) {\n      for\
    \ (int i = l1; i < M; i++) ntt_inner::_buf1[i] = 0;\n      for (int i = l2; i\
    \ < M; i++) ntt_inner::_buf2[i] = 0;\n    }\n    const __m256i m0 = _mm256_set1_epi32(0);\n\
    \    const __m256i m1 = _mm256_set1_epi32(mod);\n    const __m256i r = _mm256_set1_epi32(mint::r);\n\
    \    const __m256i N2 = _mm256_set1_epi32(mint::n2);\n    for (int i = 0; i <\
    \ l1; i += 8) {\n      __m256i a = _mm256_loadu_si256((__m256i *)(ntt_inner::_buf1\
    \ + i));\n      __m256i b = montgomery_mul_256(a, N2, r, m1);\n      _mm256_storeu_si256((__m256i\
    \ *)(ntt_inner::_buf1 + i), b);\n    }\n    for (int i = 0; i < l2; i += 8) {\n\
    \      __m256i a = _mm256_loadu_si256((__m256i *)(ntt_inner::_buf2 + i));\n  \
    \    __m256i b = montgomery_mul_256(a, N2, r, m1);\n      _mm256_storeu_si256((__m256i\
    \ *)(ntt_inner::_buf2 + i), b);\n    }\n    ntt(buf1, M);\n    ntt(buf2, M);\n\
    \    for (int i = 0; i < M; i += 8) {\n      __m256i a = _mm256_loadu_si256((__m256i\
    \ *)(ntt_inner::_buf1 + i));\n      __m256i b = _mm256_loadu_si256((__m256i *)(ntt_inner::_buf2\
    \ + i));\n      __m256i c = montgomery_mul_256(a, b, r, m1);\n      _mm256_storeu_si256((__m256i\
    \ *)(ntt_inner::_buf1 + i), c);\n    }\n    intt(buf1, M, false);\n    const __m256i\
    \ INVM = _mm256_set1_epi32((mint(M).inverse()).a);\n    for (int i = 0; i < l;\
    \ i += 8) {\n      __m256i a = _mm256_loadu_si256((__m256i *)(ntt_inner::_buf1\
    \ + i));\n      __m256i b = montgomery_mul_256(a, INVM, r, m1);\n      __m256i\
    \ c = my256_mulhi_epu32(my256_mullo_epu32(b, r), m1);\n      __m256i d = _mm256_and_si256(_mm256_cmpgt_epi32(c,\
    \ m0), m1);\n      __m256i e = _mm256_sub_epi32(d, c);\n      _mm256_storeu_si256((__m256i\
    \ *)(ntt_inner::_buf1 + i), e);\n    }\n  }\n\n  void ntt(vector<mint> &a) {\n\
    \    int M = (int)a.size();\n    for (int i = 0; i < M; i++) buf1[i].a = a[i].a;\n\
    \    ntt(buf1, M);\n    for (int i = 0; i < M; i++) a[i].a = buf1[i].a;\n  }\n\
    \n  void intt(vector<mint> &a) {\n    int M = (int)a.size();\n    for (int i =\
    \ 0; i < M; i++) buf1[i].a = a[i].a;\n    intt(buf1, M, true);\n    for (int i\
    \ = 0; i < M; i++) a[i].a = buf1[i].a;\n  }\n\n  vector<mint> multiply(const vector<mint>\
    \ &a, const vector<mint> &b) {\n    if (a.size() == 0 && b.size() == 0) return\
    \ vector<mint>{};\n    int l = a.size() + b.size() - 1;\n    if (min<int>(a.size(),\
    \ b.size()) <= 40) {\n      vector<mint> s(l);\n      for (int i = 0; i < (int)a.size();\
    \ ++i)\n        for (int j = 0; j < (int)b.size(); ++j) s[i + j] += a[i] * b[j];\n\
    \      return s;\n    }\n    assert(l <= ntt_inner::SZ_FFT_BUF);\n    int M =\
    \ 4;\n    while (M < l) M <<= 1;\n    for (int i = 0; i < (int)a.size(); ++i)\
    \ buf1[i].a = a[i].a;\n    for (int i = (int)a.size(); i < M; ++i) buf1[i].a =\
    \ 0;\n    for (int i = 0; i < (int)b.size(); ++i) buf2[i].a = b[i].a;\n    for\
    \ (int i = (int)b.size(); i < M; ++i) buf2[i].a = 0;\n    ntt(buf1, M);\n    ntt(buf2,\
    \ M);\n    for (int i = 0; i < M; ++i)\n      buf1[i].a = mint::reduce(uint64_t(buf1[i].a)\
    \ * buf2[i].a);\n    intt(buf1, M, false);\n    vector<mint> s(l);\n    mint invm\
    \ = mint(M).inverse();\n    for (int i = 0; i < l; ++i) s[i] = buf1[i] * invm;\n\
    \    return s;\n  }\n\n  void ntt_doubling(vector<mint> &a) {\n    int M = (int)a.size();\n\
    \    for (int i = 0; i < M; i++) buf1[i].a = a[i].a;\n    intt(buf1, M);\n   \
    \ mint r = 1, zeta = mint(pr).pow((mint::get_mod() - 1) / (M << 1));\n    for\
    \ (int i = 0; i < M; i++) buf1[i] *= r, r *= zeta;\n    ntt(buf1, M);\n    a.resize(2\
    \ * M);\n    for (int i = 0; i < M; i++) a[M + i].a = buf1[i].a;\n  }\n};\n#line\
    \ 5 \"fps/ntt-friendly-fps.hpp\"\n\ntemplate <typename mint>\nvoid FormalPowerSeries<mint>::set_fft()\
    \ {\n  if (!ntt_ptr) ntt_ptr = new NTT<mint>;\n}\n\ntemplate <typename mint>\n\
    FormalPowerSeries<mint>& FormalPowerSeries<mint>::operator*=(\n    const FormalPowerSeries<mint>&\
    \ r) {\n  if (this->empty() || r.empty()) {\n    this->clear();\n    return *this;\n\
    \  }\n  set_fft();\n  auto ret = static_cast<NTT<mint>*>(ntt_ptr)->multiply(*this,\
    \ r);\n  return *this = FormalPowerSeries<mint>(ret.begin(), ret.end());\n}\n\n\
    template <typename mint>\nvoid FormalPowerSeries<mint>::ntt() {\n  set_fft();\n\
    \  static_cast<NTT<mint>*>(ntt_ptr)->ntt(*this);\n}\n\ntemplate <typename mint>\n\
    void FormalPowerSeries<mint>::intt() {\n  set_fft();\n  static_cast<NTT<mint>*>(ntt_ptr)->intt(*this);\n\
    }\n\ntemplate <typename mint>\nvoid FormalPowerSeries<mint>::ntt_doubling() {\n\
    \  set_fft();\n  static_cast<NTT<mint>*>(ntt_ptr)->ntt_doubling(*this);\n}\n\n\
    template <typename mint>\nint FormalPowerSeries<mint>::ntt_pr() {\n  set_fft();\n\
    \  return static_cast<NTT<mint>*>(ntt_ptr)->pr;\n}\n\ntemplate <typename mint>\n\
    FormalPowerSeries<mint> FormalPowerSeries<mint>::inv(int deg) const {\n  assert((*this)[0]\
    \ != mint(0));\n  if (deg == -1) deg = (int)this->size();\n  FormalPowerSeries<mint>\
    \ res(deg);\n  res[0] = {mint(1) / (*this)[0]};\n  for (int d = 1; d < deg; d\
    \ <<= 1) {\n    FormalPowerSeries<mint> f(2 * d), g(2 * d);\n    for (int j =\
    \ 0; j < min((int)this->size(), 2 * d); j++) f[j] = (*this)[j];\n    for (int\
    \ j = 0; j < d; j++) g[j] = res[j];\n    f.ntt();\n    g.ntt();\n    for (int\
    \ j = 0; j < 2 * d; j++) f[j] *= g[j];\n    f.intt();\n    for (int j = 0; j <\
    \ d; j++) f[j] = 0;\n    f.ntt();\n    for (int j = 0; j < 2 * d; j++) f[j] *=\
    \ g[j];\n    f.intt();\n    for (int j = d; j < min(2 * d, deg); j++) res[j] =\
    \ -f[j];\n  }\n  return res.pre(deg);\n}\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ FormalPowerSeries<mint>::exp(int deg) const {\n  using fps = FormalPowerSeries<mint>;\n\
    \  assert((*this).size() == 0 || (*this)[0] == mint(0));\n  if (deg == -1) deg\
    \ = this->size();\n\n  fps inv;\n  inv.reserve(deg + 1);\n  inv.push_back(mint(0));\n\
    \  inv.push_back(mint(1));\n\n  auto inplace_integral = [&](fps& F) -> void {\n\
    \    const int n = (int)F.size();\n    auto mod = mint::get_mod();\n    while\
    \ ((int)inv.size() <= n) {\n      int i = inv.size();\n      inv.push_back((-inv[mod\
    \ % i]) * (mod / i));\n    }\n    F.insert(begin(F), mint(0));\n    for (int i\
    \ = 1; i <= n; i++) F[i] *= inv[i];\n  };\n\n  auto inplace_diff = [](fps& F)\
    \ -> void {\n    if (F.empty()) return;\n    F.erase(begin(F));\n    mint coeff\
    \ = 1, one = 1;\n    for (int i = 0; i < (int)F.size(); i++) {\n      F[i] *=\
    \ coeff;\n      coeff += one;\n    }\n  };\n\n  fps b{1, 1 < (int)this->size()\
    \ ? (*this)[1] : 0}, c{1}, z1, z2{1, 1};\n  for (int m = 2; m < deg; m *= 2) {\n\
    \    auto y = b;\n    y.resize(2 * m);\n    y.ntt();\n    z1 = z2;\n    fps z(m);\n\
    \    for (int i = 0; i < m; ++i) z[i] = y[i] * z1[i];\n    z.intt();\n    fill(begin(z),\
    \ begin(z) + m / 2, mint(0));\n    z.ntt();\n    for (int i = 0; i < m; ++i) z[i]\
    \ *= -z1[i];\n    z.intt();\n    c.insert(end(c), begin(z) + m / 2, end(z));\n\
    \    z2 = c;\n    z2.resize(2 * m);\n    z2.ntt();\n    fps x(begin(*this), begin(*this)\
    \ + min<int>(this->size(), m));\n    x.resize(m);\n    inplace_diff(x);\n    x.push_back(mint(0));\n\
    \    x.ntt();\n    for (int i = 0; i < m; ++i) x[i] *= y[i];\n    x.intt();\n\
    \    x -= b.diff();\n    x.resize(2 * m);\n    for (int i = 0; i < m - 1; ++i)\
    \ x[m + i] = x[i], x[i] = mint(0);\n    x.ntt();\n    for (int i = 0; i < 2 *\
    \ m; ++i) x[i] *= z2[i];\n    x.intt();\n    x.pop_back();\n    inplace_integral(x);\n\
    \    for (int i = m; i < min<int>(this->size(), 2 * m); ++i) x[i] += (*this)[i];\n\
    \    fill(begin(x), begin(x) + m, mint(0));\n    x.ntt();\n    for (int i = 0;\
    \ i < 2 * m; ++i) x[i] *= y[i];\n    x.intt();\n    b.insert(end(b), begin(x)\
    \ + m, end(x));\n  }\n  return fps{begin(b), begin(b) + deg};\n}\n\n/**\n * @brief\
    \ NTT mod\u7528FPS\u30E9\u30A4\u30D6\u30E9\u30EA\n * @docs docs/fps/ntt-friendly-fps.md\n\
    \ */\n#line 2 \"misc/fastio.hpp\"\n\n#line 6 \"misc/fastio.hpp\"\n\nusing namespace\
    \ std;\n\nnamespace fastio {\nstatic constexpr int SZ = 1 << 17;\nchar ibuf[SZ],\
    \ obuf[SZ];\nint pil = 0, pir = 0, por = 0;\n\nstruct Pre {\n  char num[40000];\n\
    \  constexpr Pre() : num() {\n    for (int i = 0; i < 10000; i++) {\n      int\
    \ n = i;\n      for (int j = 3; j >= 0; j--) {\n        num[i * 4 + j] = n % 10\
    \ + '0';\n        n /= 10;\n      }\n    }\n  }\n} constexpr pre;\n\ninline void\
    \ load() {\n  memcpy(ibuf, ibuf + pil, pir - pil);\n  pir = pir - pil + fread(ibuf\
    \ + pir - pil, 1, SZ - pir + pil, stdin);\n  pil = 0;\n}\ninline void flush()\
    \ {\n  fwrite(obuf, 1, por, stdout);\n  por = 0;\n}\n\ninline void skip_space()\
    \ {\n  if (pil + 32 > pir) load();\n  while (ibuf[pil] <= ' ') pil++;\n}\n\ninline\
    \ void rd(char& c) {\n  if (pil + 32 > pir) load();\n  c = ibuf[pil++];\n}\ntemplate\
    \ <typename T>\ninline void rd(T& x) {\n  if (pil + 32 > pir) load();\n  char\
    \ c;\n  do c = ibuf[pil++];\n  while (c < '-');\n  [[maybe_unused]] bool minus\
    \ = false;\n  if constexpr (is_signed<T>::value == true) {\n    if (c == '-')\
    \ minus = true, c = ibuf[pil++];\n  }\n  x = 0;\n  while (c >= '0') {\n    x =\
    \ x * 10 + (c & 15);\n    c = ibuf[pil++];\n  }\n  if constexpr (is_signed<T>::value\
    \ == true) {\n    if (minus) x = -x;\n  }\n}\ninline void rd() {}\ntemplate <typename\
    \ Head, typename... Tail>\ninline void rd(Head& head, Tail&... tail) {\n  rd(head);\n\
    \  rd(tail...);\n}\n\ninline void wt(char c) {\n  if (por > SZ - 32) flush();\n\
    \  obuf[por++] = c;\n}\ninline void wt(bool b) { \n  if (por > SZ - 32) flush();\n\
    \  obuf[por++] = b ? '1' : '0'; \n}\ntemplate <typename T>\ninline void wt(T x)\
    \ {\n  if (por > SZ - 32) flush();\n  if (!x) {\n    obuf[por++] = '0';\n    return;\n\
    \  }\n  if constexpr (is_signed<T>::value == true) {\n    if (x < 0) obuf[por++]\
    \ = '-', x = -x;\n  }\n  int i = 12;\n  char buf[16];\n  while (x >= 10000) {\n\
    \    memcpy(buf + i, pre.num + (x % 10000) * 4, 4);\n    x /= 10000;\n    i -=\
    \ 4;\n  }\n  if (x < 100) {\n    if (x < 10) {\n      obuf[por] = '0' + x;\n \
    \     ++por;\n    } else {\n      uint32_t q = (uint32_t(x) * 205) >> 11;\n  \
    \    uint32_t r = uint32_t(x) - q * 10;\n      obuf[por] = '0' + q;\n      obuf[por\
    \ + 1] = '0' + r;\n      por += 2;\n    }\n  } else {\n    if (x < 1000) {\n \
    \     memcpy(obuf + por, pre.num + (x << 2) + 1, 3);\n      por += 3;\n    } else\
    \ {\n      memcpy(obuf + por, pre.num + (x << 2), 4);\n      por += 4;\n    }\n\
    \  }\n  memcpy(obuf + por, buf + i + 4, 12 - i);\n  por += 12 - i;\n}\n\ninline\
    \ void wt() {}\ntemplate <typename Head, typename... Tail>\ninline void wt(Head&&\
    \ head, Tail&&... tail) {\n  wt(head);\n  wt(forward<Tail>(tail)...);\n}\ntemplate\
    \ <typename... Args>\ninline void wtn(Args&&... x) {\n  wt(forward<Args>(x)...);\n\
    \  wt('\\n');\n}\n\nstruct Dummy {\n  Dummy() { atexit(flush); }\n} dummy;\n\n\
    }  // namespace fastio\nusing fastio::rd;\nusing fastio::skip_space;\nusing fastio::wt;\n\
    using fastio::wtn;\n#line 10 \"verify/verify-yosupo-fps/yosupo-composition-fast.test.cpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve() {\n  using mint = LazyMontgomeryModInt<998244353>;\n\
    \  using fps = FormalPowerSeries<mint>;\n  int N;\n  rd(N);\n  fps f(N), g(N);\n\
    \  for (int i = 0; i < N; i++) {\n    int n;\n    rd(n);\n    f[i] = n;\n  }\n\
    \  for (int i = 0; i < N; i++) {\n    int n;\n    rd(n);\n    g[i] = n;\n  }\n\
    \  fps R = Composition(g, f);\n  for (int i = 0; i < (int)R.size(); i++) {\n \
    \   if (i) wt(' ');\n    wt(R[i].get());\n  }\n  wt('\\n');\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/composition_of_formal_power_series\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../fps/formal-power-series.hpp\"\
    \n#include \"../../fps/fps-composition-fast.hpp\"\n#include \"../../fps/ntt-friendly-fps.hpp\"\
    \n#include \"../../misc/fastio.hpp\"\n#include \"../../modint/montgomery-modint.hpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve() {\n  using mint = LazyMontgomeryModInt<998244353>;\n\
    \  using fps = FormalPowerSeries<mint>;\n  int N;\n  rd(N);\n  fps f(N), g(N);\n\
    \  for (int i = 0; i < N; i++) {\n    int n;\n    rd(n);\n    f[i] = n;\n  }\n\
    \  for (int i = 0; i < N; i++) {\n    int n;\n    rd(n);\n    g[i] = n;\n  }\n\
    \  fps R = Composition(g, f);\n  for (int i = 0; i < (int)R.size(); i++) {\n \
    \   if (i) wt(' ');\n    wt(R[i].get());\n  }\n  wt('\\n');\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - fps/formal-power-series.hpp
  - fps/fps-composition-fast.hpp
  - modint/montgomery-modint.hpp
  - modulo/strassen.hpp
  - modint/simd-montgomery.hpp
  - misc/timer.hpp
  - fps/ntt-friendly-fps.hpp
  - ntt/ntt-avx2.hpp
  - misc/fastio.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-fps/yosupo-composition-fast.test.cpp
  requiredBy: []
  timestamp: '2021-03-07 00:59:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-fps/yosupo-composition-fast.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-fps/yosupo-composition-fast.test.cpp
- /verify/verify/verify-yosupo-fps/yosupo-composition-fast.test.cpp.html
title: verify/verify-yosupo-fps/yosupo-composition-fast.test.cpp
---
