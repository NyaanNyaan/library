---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/geometry-base.hpp
    title: geometry/geometry-base.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: geometry/segment.hpp
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
    ERROR: '0.00000001'
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
  bundledCode: "#line 1 \"verify/verify-aoj-cgl/aoj-cgl-2-d.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D\"\n#define\
    \ ERROR 0.00000001\n//\n#line 2 \"template/template.hpp\"\nusing namespace std;\n\
    \n// intrinstic\n#include <immintrin.h>\n\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <cctype>\n#include <cfenv>\n#include\
    \ <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include <climits>\n#include\
    \ <cmath>\n#include <complex>\n#include <cstdarg>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <initializer_list>\n\
    #include <iomanip>\n#include <ios>\n#include <iostream>\n#include <istream>\n\
    #include <iterator>\n#include <limits>\n#include <list>\n#include <map>\n#include\
    \ <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <random>\n#include <set>\n#include <sstream>\n#include <stack>\n#include\
    \ <streambuf>\n#include <string>\n#include <tuple>\n#include <type_traits>\n#include\
    \ <typeinfo>\n#include <unordered_map>\n#include <unordered_set>\n#include <utility>\n\
    #include <vector>\n\n// utility\n#line 1 \"template/util.hpp\"\nnamespace Nyaan\
    \ {\nusing ll = long long;\nusing i64 = long long;\nusing u64 = unsigned long\
    \ long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\ntemplate <typename\
    \ T>\nusing V = vector<T>;\ntemplate <typename T>\nusing VV = vector<vector<T>>;\n\
    using vi = vector<int>;\nusing vl = vector<long long>;\nusing vd = V<double>;\n\
    using vs = V<string>;\nusing vvi = vector<vector<int>>;\nusing vvl = vector<vector<long\
    \ long>>;\ntemplate <typename T>\nusing minpq = priority_queue<T, vector<T>, greater<T>>;\n\
    \ntemplate <typename T, typename U>\nstruct P : pair<T, U> {\n  template <typename...\
    \ Args>\n  P(Args... args) : pair<T, U>(args...) {}\n\n  using pair<T, U>::first;\n\
    \  using pair<T, U>::second;\n\n  P &operator+=(const P &r) {\n    first += r.first;\n\
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
    \ 5 \"verify/verify-aoj-cgl/aoj-cgl-2-d.test.cpp\"\n//\n#line 2 \"geometry/segment.hpp\"\
    \n\n#line 2 \"geometry/geometry-base.hpp\"\n\n#line 9 \"geometry/geometry-base.hpp\"\
    \nusing namespace std;\n\nusing Real = long double;\nconstexpr Real EPS = 1e-10;\n\
    constexpr Real pi = 3.141592653589793238462643383279L;\nbool equals(Real a, Real\
    \ b) { return fabs(b - a) < EPS; }\nint sign(Real a) { return equals(a, 0) ? 0\
    \ : a > 0 ? 1 : -1; }\n\ntemplate <typename R>\nstruct PointBase {\n  using P\
    \ = PointBase;\n  R x, y;\n  PointBase() : x(0), y(0) {}\n  PointBase(R _x, R\
    \ _y) : x(_x), y(_y) {}\n  template <typename T, typename U>\n  PointBase(const\
    \ pair<T, U>& p) : x(p.first), y(p.second) {}\n\n  P operator+(const P& r) const\
    \ { return {x + r.x, y + r.y}; }\n  P operator-(const P& r) const { return {x\
    \ - r.x, y - r.y}; }\n  P operator*(R r) const { return {x * r, y * r}; }\n  P\
    \ operator/(R r) const { return {x / r, y / r}; }\n\n  P& operator+=(const P&\
    \ r) { return (*this) = (*this) + r; }\n  P& operator-=(const P& r) { return (*this)\
    \ = (*this) - r; }\n  P& operator*=(R r) { return (*this) = (*this) * r; }\n \
    \ P& operator/=(R r) { return (*this) = (*this) / r; }\n\n  bool operator<(const\
    \ P& r) const { return x != r.x ? x < r.x : y < r.y; }\n  bool operator==(const\
    \ P& r) const { return x == r.x and y == r.y; }\n  bool operator!=(const P& r)\
    \ const { return !((*this) == r); }\n\n  P rotate(R rad) const {\n    return {x\
    \ * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)};\n  }\n\n  R real()\
    \ const { return x; }\n  R imag() const { return y; }\n  friend R real(const P&\
    \ p) { return p.x; }\n  friend R imag(const P& p) { return p.y; }\n  friend R\
    \ dot(const P& l, const P& r) { return l.x * r.x + l.y * r.y; }\n  friend R cross(const\
    \ P& l, const P& r) { return l.x * r.y - l.y * r.x; }\n  friend R abs(const P&\
    \ p) { return sqrt(p.x * p.x + p.y * p.y); }\n  friend R norm(const P& p) { return\
    \ p.x * p.x + p.y * p.y; }\n  friend R arg(const P& p) { return atan2(p.y, p.x);\
    \ }\n\n  friend istream& operator>>(istream& is, P& p) {\n    R a, b;\n    is\
    \ >> a >> b;\n    p = P{a, b};\n    return is;\n  }\n  friend ostream& operator<<(ostream&\
    \ os, const P& p) {\n    return os << p.x << \" \" << p.y;\n  }\n};\nusing Point\
    \ = PointBase<Real>;\nusing Points = vector<Point>;\n\n// ccw, \u70B9\u306E\u9032\
    \u884C\u65B9\u5411\nint ccw(const Point& a, const Point& b, const Point& c) {\n\
    \  Point x = b - a, y = c - a;\n  if (cross(x, y) > EPS) return +1;          \
    \       // \u53CD\u6642\u8A08\u56DE\u308A\n  if (cross(x, y) < -EPS) return -1;\
    \                // \u6642\u8A08\u56DE\u308A\n  if (min(norm(x), norm(y)) < EPS\
    \ * EPS) return 0;  // c=a \u307E\u305F\u306F c=b\n  if (dot(x, y) < EPS) return\
    \ +2;                   // c-a-b \u306E\u9806\u3067\u4E00\u76F4\u7DDA\n  if (norm(x)\
    \ < norm(y)) return -2;                 // a-b-c \u306E\u9806\u3067\u4E00\u76F4\
    \u7DDA\n  return 0;                                         // a-c-b \u306E\u9806\
    \u3067\u4E00\u76F4\u7DDA\n}\n#line 4 \"geometry/segment.hpp\"\n//\n#line 2 \"\
    geometry/line.hpp\"\n\n#line 2 \"geometry/polygon.hpp\"\n\n#line 4 \"geometry/polygon.hpp\"\
    \n\nusing Polygon = vector<Point>;\n\n// \u591A\u89D2\u5F62\u306E\u5185\u90E8\u306B\
    \u70B9\u304C\u3042\u308B\u304B\uFF1F\n// OUT : 0, ON : 1, IN : 2\nint contains_polygon(const\
    \ Polygon &Q, const Point &p) {\n  bool in = false;\n  for (int i = 0; i < (int)Q.size();\
    \ i++) {\n    Point a = Q[i] - p, b = Q[(i + 1) % Q.size()] - p;\n    if (imag(a)\
    \ > imag(b)) swap(a, b);\n    if (sign(imag(a)) <= 0 && 0 < sign(imag(b)) && sign(cross(a,\
    \ b)) < 0)\n      in = !in;\n    if (equals(cross(a, b), 0) && sign(dot(a, b))\
    \ <= 0) return 1;\n  }\n  return in ? 2 : 0;\n}\n\n// \u591A\u89D2\u5F62\u306E\
    \u9762\u7A4D\nReal area(const Polygon &p) {\n  Real A = 0;\n  for (int i = 0;\
    \ i < (int)p.size(); ++i) {\n    A += cross(p[i], p[(i + 1) % p.size()]);\n  }\n\
    \  return A * 0.5;\n}\n\n// \u9802\u70B9\u96C6\u5408\u304B\u3089\u51F8\u5305\u3092\
    \u751F\u6210\n// boundary : \u5468\u4E0A\u306E\u70B9\u3082\u5217\u6319\u3059\u308B\
    \u5834\u5408 true\ntemplate <bool boundary = false>\nPolygon convex_hull(vector<Point>\
    \ ps) {\n  sort(begin(ps), end(ps));\n  ps.erase(unique(begin(ps), end(ps)), end(ps));\n\
    \  int n = ps.size(), k = 0;\n  if (n <= 2) return ps;\n  vector<Point> ch(2 *\
    \ n);\n  // \u53CD\u6642\u8A08\u5468\u308A\n  Real th = boundary ? -EPS : +EPS;\n\
    \  for (int i = 0; i < n; ch[k++] = ps[i++]) {\n    while (k >= 2 && cross(ch[k\
    \ - 1] - ch[k - 2], ps[i] - ch[k - 1]) < th) --k;\n  }\n  for (int i = n - 2,\
    \ t = k + 1; i >= 0; ch[k++] = ps[i--]) {\n    while (k >= t && cross(ch[k - 1]\
    \ - ch[k - 2], ps[i] - ch[k - 1]) < th) --k;\n  }\n  ch.resize(k - 1);\n  return\
    \ ch;\n}\n\n// \u51F8\u5305\u306E\u5185\u90E8\u306B\u70B9\u304C\u3042\u308B\u304B\
    \uFF1F\n// OUT : 0, ON : 1, IN : 2\nint contains_convex(const Polygon &C, const\
    \ Point &p) {\n  int N = C.size();\n  auto b1 = cross(C[1] - C[0], p - C[0]);\n\
    \  auto b2 = cross(C[N - 1] - C[0], p - C[0]);\n  if (b1 < -EPS or b2 > EPS) return\
    \ 0;\n  int L = 1, R = N - 1;\n  while (L + 1 < R) {\n    int M = (L + R) / 2;\n\
    \    (cross(p - C[0], C[M] - C[0]) >= 0 ? R : L) = M;\n  }\n  auto v = cross(C[L]\
    \ - p, C[R] - p);\n  if (equals(v, 0)) {\n    return 1;\n  } else if (v > 0) {\n\
    \    return equals(b1, 0) or equals(b2, 0) ? 1 : 2;\n  } else {\n    return 0;\n\
    \  }\n}\n\n// \u51F8\u5305\u304C\u4E0E\u3048\u3089\u308C\u308B\u306E\u3067\u6700\
    \u9060\u70B9\u5BFE\u3092\u8FD4\u3059\n// \u8FD4\u308A\u5024\uFF1A\u9802\u70B9\u756A\
    \u53F7\u306E\u30DA\u30A2\npair<int, int> convex_polygon_diameter(const Polygon\
    \ &p) {\n  int N = (int)p.size();\n  int is = 0, js = 0;\n  for (int i = 1; i\
    \ < N; i++) {\n    if (imag(p[i]) > imag(p[is])) is = i;\n    if (imag(p[i]) <\
    \ imag(p[js])) js = i;\n  }\n  Real maxdis = norm(p[is] - p[js]);\n\n  int maxi,\
    \ maxj, i, j;\n  i = maxi = is;\n  j = maxj = js;\n  do {\n    if (cross(p[(i\
    \ + 1) % N] - p[i], p[(j + 1) % N] - p[j]) >= 0) {\n      j = (j + 1) % N;\n \
    \   } else {\n      i = (i + 1) % N;\n    }\n    if (norm(p[i] - p[j]) > maxdis)\
    \ {\n      maxdis = norm(p[i] - p[j]);\n      maxi = i;\n      maxj = j;\n   \
    \ }\n  } while (i != is || j != js);\n  return minmax(maxi, maxj);\n}\n#line 5\
    \ \"geometry/line.hpp\"\n\nstruct Line {\n  Point a, b;\n\n  Line() = default;\n\
    \  Line(const Point &_a, const Point &_b) : a(_a), b(_b) {}\n  // Ax+By=C\n  Line(const\
    \ Real &A, const Real &B, const Real &C) {\n    if (equals(A, 0)) {\n      assert(!equals(B,\
    \ 0));\n      a = Point(0, C / B);\n      b = Point(1, C / B);\n    } else if\
    \ (equals(B, 0)) {\n      a = Point(C / A, 0);\n      b = Point(C / A, 1);\n \
    \   } else if (equals(C, 0)) {\n      a = Point(0, C / B);\n      b = Point(1,\
    \ (C - A) / B);\n    } else {\n      a = Point(0, C / B);\n      b = Point(C /\
    \ A, 0);\n    }\n  }\n  friend ostream &operator<<(ostream &os, const Line &l)\
    \ {\n    return os << l.a << \" to \" << l.b;\n  }\n  friend istream &operator>>(istream\
    \ &is, Line &l) { return is >> l.a >> l.b; }\n};\nusing Lines = vector<Line>;\n\
    \nbool is_parallel(const Line &a, const Line &b) {\n  return equals(cross(a.b\
    \ - a.a, b.b - b.a), 0);\n}\nbool is_orthogonal(const Line &a, const Line &b)\
    \ {\n  return equals(dot(a.a - a.b, b.a - b.b), 0);\n}\nPoint cross_point_ll(const\
    \ Line &l, const Line &m) {\n  Real A = cross(l.b - l.a, m.b - m.a);\n  Real B\
    \ = cross(l.b - l.a, l.b - m.a);\n  if (equals(abs(A), 0) && equals(abs(B), 0))\
    \ return m.a;\n  return m.a + (m.b - m.a) * B / A;\n}\nbool is_intersect_ll(const\
    \ Line &l, const Line &m) {\n  Real A = cross(l.b - l.a, m.b - m.a);\n  Real B\
    \ = cross(l.b - l.a, l.b - m.a);\n  if (equals(abs(A), 0) && equals(abs(B), 0))\
    \ return true;\n  return !is_parallel(l, m);\n}\n\n// \u76F4\u7DDA\u306B\u9802\
    \u70B9\u304B\u3089\u5782\u7DDA\u3092\u4E0B\u308D\u3057\u305F\u6642\u306E\u4EA4\
    \u70B9\nPoint projection(const Line &l, const Point &p) {\n  Real t = dot(p -\
    \ l.a, l.a - l.b) / norm(l.a - l.b);\n  return l.a + (l.a - l.b) * t;\n}\n\n//\
    \ \u51F8\u5305\u3092\u76F4\u7DDA\u3067\u5207\u3063\u305F\u6642\u306E\u7247\u65B9\
    \ (\u76F4\u7DDA a->b \u306E\u9032\u884C\u65B9\u5411\u5DE6\u5074) \u3092\u8FD4\u3059\
    \nPolygon convex_polygon_cut(const Polygon &U, const Line &l) {\n  Polygon ret;\n\
    \  for (int i = 0; i < (int)U.size(); i++) {\n    const Point &now = U[i];\n \
    \   const Point &nxt = U[(i + 1) % U.size()];\n    auto cf = cross(l.a - now,\
    \ l.b - now);\n    auto cs = cross(l.a - nxt, l.b - nxt);\n    if (sign(cf) >=\
    \ 0) {\n      ret.emplace_back(now);\n    }\n    if (sign(cf) * sign(cs) < 0)\
    \ {\n      ret.emplace_back(cross_point_ll(Line(now, nxt), l));\n    }\n  }\n\
    \  return ret;\n}\n#line 6 \"geometry/segment.hpp\"\n\nstruct Segment : Line {\n\
    \  Segment() = default;\n  using Line::Line;\n};\n\nusing Segments = vector<Segment>;\n\
    \nbool is_intersect_sp(const Segment &s, const Point &p) {\n  return ccw(s.a,\
    \ s.b, p) == 0;\n}\nbool is_intersect_ss(const Segment &s, const Segment &t) {\n\
    \  return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&\n         ccw(t.a, t.b,\
    \ s.a) * ccw(t.a, t.b, s.b) <= 0;\n}\n\nReal distance_sp(const Segment &s, const\
    \ Point &p) {\n  Point r = projection(s, p);\n  if (is_intersect_sp(s, r)) return\
    \ abs(r - p);\n  return min(abs(s.a - p), abs(s.b - p));\n}\nReal distance_ss(const\
    \ Segment &a, const Segment &b) {\n  if (is_intersect_ss(a, b)) return 0;\n  return\
    \ min({distance_sp(a, b.a), distance_sp(a, b.b), distance_sp(b, a.a),\n      \
    \        distance_sp(b, a.b)});\n}\n#line 7 \"verify/verify-aoj-cgl/aoj-cgl-2-d.test.cpp\"\
    \nusing namespace Nyaan;\n\nvoid q() {\n  ini(Q);\n  while (Q--) {\n    Point\
    \ p0, p1, p2, p3;\n    in(p0, p1, p2, p3);\n    Segment s1{p0, p1}, s2{p2, p3};\n\
    \    out(distance_ss(s1, s2));\n  }\n}\n\nvoid Nyaan::solve() {\n  int t = 1;\n\
    \  // in(t);\n  while (t--) q();\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D\"\
    \n#define ERROR 0.00000001\n//\n#include \"../../template/template.hpp\"\n//\n\
    #include \"../../geometry/segment.hpp\"\nusing namespace Nyaan;\n\nvoid q() {\n\
    \  ini(Q);\n  while (Q--) {\n    Point p0, p1, p2, p3;\n    in(p0, p1, p2, p3);\n\
    \    Segment s1{p0, p1}, s2{p2, p3};\n    out(distance_ss(s1, s2));\n  }\n}\n\n\
    void Nyaan::solve() {\n  int t = 1;\n  // in(t);\n  while (t--) q();\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - geometry/segment.hpp
  - geometry/geometry-base.hpp
  - geometry/line.hpp
  - geometry/polygon.hpp
  isVerificationFile: true
  path: verify/verify-aoj-cgl/aoj-cgl-2-d.test.cpp
  requiredBy: []
  timestamp: '2024-05-03 21:06:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-aoj-cgl/aoj-cgl-2-d.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-aoj-cgl/aoj-cgl-2-d.test.cpp
- /verify/verify/verify-aoj-cgl/aoj-cgl-2-d.test.cpp.html
title: verify/verify-aoj-cgl/aoj-cgl-2-d.test.cpp
---
