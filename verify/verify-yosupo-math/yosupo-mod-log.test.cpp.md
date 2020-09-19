---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/mod-log.hpp
    title: modulo/mod-log.hpp
  - icon: ':heavy_check_mark:'
    path: math/elementary-function.hpp
    title: math/elementary-function.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"verify/verify-yosupo-math/yosupo-mod-log.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n\n#line\
    \ 1 \"competitive-template.hpp\"\n#pragma region kyopro_template\n#define Nyaan_template\n\
    #include <immintrin.h>\n#include <bits/stdc++.h>\n#define pb push_back\n#define\
    \ eb emplace_back\n#define fi first\n#define se second\n#define each(x, v) for\
    \ (auto &x : v)\n#define all(v) (v).begin(), (v).end()\n#define sz(v) ((int)(v).size())\n\
    #define mem(a, val) memset(a, val, sizeof(a))\n#define ini(...)   \\\n  int __VA_ARGS__;\
    \ \\\n  in(__VA_ARGS__)\n#define inl(...)         \\\n  long long __VA_ARGS__;\
    \ \\\n  in(__VA_ARGS__)\n#define ins(...)      \\\n  string __VA_ARGS__; \\\n\
    \  in(__VA_ARGS__)\n#define inc(...)    \\\n  char __VA_ARGS__; \\\n  in(__VA_ARGS__)\n\
    #define in2(s, t)                           \\\n  for (int i = 0; i < (int)s.size();\
    \ i++) { \\\n    in(s[i], t[i]);                         \\\n  }\n#define in3(s,\
    \ t, u)                        \\\n  for (int i = 0; i < (int)s.size(); i++) {\
    \ \\\n    in(s[i], t[i], u[i]);                   \\\n  }\n#define in4(s, t, u,\
    \ v)                     \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n\
    \    in(s[i], t[i], u[i], v[i]);             \\\n  }\n#define rep(i, N) for (long\
    \ long i = 0; i < (long long)(N); i++)\n#define repr(i, N) for (long long i =\
    \ (long long)(N)-1; i >= 0; i--)\n#define rep1(i, N) for (long long i = 1; i <=\
    \ (long long)(N); i++)\n#define repr1(i, N) for (long long i = (N); (long long)(i)\
    \ > 0; i--)\n#define reg(i, a, b) for (long long i = (a); i < (b); i++)\n#define\
    \ die(...)      \\\n  do {                \\\n    out(__VA_ARGS__); \\\n    return;\
    \           \\\n  } while (0)\nusing namespace std;\nusing ll = long long;\ntemplate\
    \ <class T>\nusing V = vector<T>;\nusing vi = vector<int>;\nusing vl = vector<long\
    \ long>;\nusing vvi = vector<vector<int>>;\nusing vd = V<double>;\nusing vs =\
    \ V<string>;\nusing vvl = vector<vector<long long>>;\nusing P = pair<long long,\
    \ long long>;\nusing vp = vector<P>;\nusing pii = pair<int, int>;\nusing vpi =\
    \ vector<pair<int, int>>;\nconstexpr int inf = 1001001001;\nconstexpr long long\
    \ infLL = (1LL << 61) - 1;\ntemplate <typename T, typename U>\ninline bool amin(T\
    \ &x, U y) {\n  return (y < x) ? (x = y, true) : false;\n}\ntemplate <typename\
    \ T, typename U>\ninline bool amax(T &x, U y) {\n  return (x < y) ? (x = y, true)\
    \ : false;\n}\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n  os << p.first << \" \" << p.second;\n  return\
    \ os;\n}\ntemplate <typename T, typename U>\nistream &operator>>(istream &is,\
    \ pair<T, U> &p) {\n  is >> p.first >> p.second;\n  return is;\n}\ntemplate <typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n  int s = (int)v.size();\n\
    \  for (int i = 0; i < s; i++) os << (i ? \" \" : \"\") << v[i];\n  return os;\n\
    }\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T> &v) {\n \
    \ for (auto &x : v) is >> x;\n  return is;\n}\nvoid in() {}\ntemplate <typename\
    \ T, class... U>\nvoid in(T &t, U &... u) {\n  cin >> t;\n  in(u...);\n}\nvoid\
    \ out() { cout << \"\\n\"; }\ntemplate <typename T, class... U>\nvoid out(const\
    \ T &t, const U &... u) {\n  cout << t;\n  if (sizeof...(u)) cout << \" \";\n\
    \  out(u...);\n}\n\n#ifdef NyaanDebug\n#define trc(...)                   \\\n\
    \  do {                             \\\n    cerr << #__VA_ARGS__ << \" = \"; \\\
    \n    dbg_out(__VA_ARGS__);          \\\n  } while (0)\n#define trca(v, N)   \
    \    \\\n  do {                   \\\n    cerr << #v << \" = \"; \\\n    array_out(v,\
    \ N);     \\\n  } while (0)\n#define trcc(v)                             \\\n\
    \  do {                                      \\\n    cerr << #v << \" = {\"; \
    \                  \\\n    each(x, v) { cerr << \" \" << x << \",\"; } \\\n  \
    \  cerr << \"}\" << endl;                    \\\n  } while (0)\ntemplate <typename\
    \ T>\nvoid _cout(const T &c) {\n  cerr << c;\n}\nvoid _cout(const int &c) {\n\
    \  if (c == 1001001001)\n    cerr << \"inf\";\n  else if (c == -1001001001)\n\
    \    cerr << \"-inf\";\n  else\n    cerr << c;\n}\nvoid _cout(const unsigned int\
    \ &c) {\n  if (c == 1001001001)\n    cerr << \"inf\";\n  else\n    cerr << c;\n\
    }\nvoid _cout(const long long &c) {\n  if (c == 1001001001 || c == (1LL << 61)\
    \ - 1)\n    cerr << \"inf\";\n  else if (c == -1001001001 || c == -((1LL << 61)\
    \ - 1))\n    cerr << \"-inf\";\n  else\n    cerr << c;\n}\nvoid _cout(const unsigned\
    \ long long &c) {\n  if (c == 1001001001 || c == (1LL << 61) - 1)\n    cerr <<\
    \ \"inf\";\n  else\n    cerr << c;\n}\ntemplate <typename T, typename U>\nvoid\
    \ _cout(const pair<T, U> &p) {\n  cerr << \"{ \";\n  _cout(p.fi);\n  cerr << \"\
    , \";\n  _cout(p.se);\n  cerr << \" } \";\n}\ntemplate <typename T>\nvoid _cout(const\
    \ vector<T> &v) {\n  int s = v.size();\n  cerr << \"{ \";\n  for (int i = 0; i\
    \ < s; i++) {\n    cerr << (i ? \", \" : \"\");\n    _cout(v[i]);\n  }\n  cerr\
    \ << \" } \";\n}\ntemplate <typename T>\nvoid _cout(const vector<vector<T>> &v)\
    \ {\n  cerr << \"[ \";\n  for (const auto &x : v) {\n    cerr << endl;\n    _cout(x);\n\
    \    cerr << \", \";\n  }\n  cerr << endl << \" ] \";\n}\nvoid dbg_out() { cerr\
    \ << endl; }\ntemplate <typename T, class... U>\nvoid dbg_out(const T &t, const\
    \ U &... u) {\n  _cout(t);\n  if (sizeof...(u)) cerr << \", \";\n  dbg_out(u...);\n\
    }\ntemplate <typename T>\nvoid array_out(const T &v, int s) {\n  cerr << \"{ \"\
    ;\n  for (int i = 0; i < s; i++) {\n    cerr << (i ? \", \" : \"\");\n    _cout(v[i]);\n\
    \  }\n  cerr << \" } \" << endl;\n}\ntemplate <typename T>\nvoid array_out(const\
    \ T &v, int H, int W) {\n  cerr << \"[ \";\n  for (int i = 0; i < H; i++) {\n\
    \    cerr << (i ? \", \" : \"\");\n    array_out(v[i], W);\n  }\n  cerr << \"\
    \ ] \" << endl;\n}\n#else\n#define trc(...)\n#define trca(...)\n#define trcc(...)\n\
    #endif\n\ninline int popcnt(unsigned long long a) { return __builtin_popcountll(a);\
    \ }\ninline int lsb(unsigned long long a) { return __builtin_ctzll(a); }\ninline\
    \ int msb(unsigned long long a) { return 63 - __builtin_clzll(a); }\ntemplate\
    \ <typename T>\ninline int getbit(T a, int i) {\n  return (a >> i) & 1;\n}\ntemplate\
    \ <typename T>\ninline void setbit(T &a, int i) {\n  a |= (1LL << i);\n}\ntemplate\
    \ <typename T>\ninline void delbit(T &a, int i) {\n  a &= ~(1LL << i);\n}\ntemplate\
    \ <typename T>\nint lb(const vector<T> &v, const T &a) {\n  return lower_bound(begin(v),\
    \ end(v), a) - begin(v);\n}\ntemplate <typename T>\nint ub(const vector<T> &v,\
    \ const T &a) {\n  return upper_bound(begin(v), end(v), a) - begin(v);\n}\ntemplate\
    \ <typename T>\nint btw(T a, T x, T b) {\n  return a <= x && x < b;\n}\ntemplate\
    \ <typename T, typename U>\nT ceil(T a, U b) {\n  return (a + b - 1) / b;\n}\n\
    constexpr long long TEN(int n) {\n  long long ret = 1, x = 10;\n  while (n) {\n\
    \    if (n & 1) ret *= x;\n    x *= x;\n    n >>= 1;\n  }\n  return ret;\n}\n\
    template <typename T>\nvector<T> mkrui(const vector<T> &v) {\n  vector<T> ret(v.size()\
    \ + 1);\n  for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];\n\
    \  return ret;\n};\ntemplate <typename T>\nvector<T> mkuni(const vector<T> &v)\
    \ {\n  vector<T> ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(),\
    \ ret.end()), ret.end());\n  return ret;\n}\ntemplate <typename F>\nvector<int>\
    \ mkord(int N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n\
    \  sort(begin(ord), end(ord), f);\n  return ord;\n}\ntemplate <typename T = int>\n\
    vector<T> mkiota(int N) {\n  vector<T> ret(N);\n  iota(begin(ret), end(ret), 0);\n\
    \  return ret;\n}\ntemplate <typename T>\nvector<int> mkinv(vector<T> &v) {\n\
    \  vector<int> inv(v.size());\n  for (int i = 0; i < (int)v.size(); i++) inv[v[i]]\
    \ = i;\n  return inv;\n}\n\nstruct IoSetupNya {\n  IoSetupNya() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(15);\n  \
    \  cerr << fixed << setprecision(7);\n  }\n} iosetupnya;\n\nvoid solve();\nint\
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"misc/fastio.hpp\"\nusing\
    \ namespace std;\n\nnamespace fastio {\nstatic constexpr int SZ = 1 << 17;\nchar\
    \ ibuf[SZ], obuf[SZ];\nint pil = 0, pir = 0, por = 0;\n\nstruct Pre {\n  char\
    \ num[40000];\n  constexpr Pre() : num() {\n    for (int i = 0; i < 10000; i++)\
    \ {\n      int n = i;\n      for (int j = 3; j >= 0; j--) {\n        num[i * 4\
    \ + j] = n % 10 + '0';\n        n /= 10;\n      }\n    }\n  }\n} constexpr pre;\n\
    \ninline void load() {\n  memcpy(ibuf, ibuf + pil, pir - pil);\n  pir = pir -\
    \ pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);\n  pil = 0;\n}\ninline\
    \ void flush() {\n  fwrite(obuf, 1, por, stdout);\n  por = 0;\n}\n\ninline void\
    \ rd(char& c) { c = ibuf[pil++]; }\ntemplate <typename T>\ninline void rd(T& x)\
    \ {\n  if (pil + 32 > pir) load();\n  char c;\n  do\n    c = ibuf[pil++];\n  while\
    \ (c < '-');\n  bool minus = 0;\n  if (c == '-') {\n    minus = 1;\n    c = ibuf[pil++];\n\
    \  }\n  x = 0;\n  while (c >= '0') {\n    x = x * 10 + (c & 15);\n    c = ibuf[pil++];\n\
    \  }\n  if (minus) x = -x;\n}\ninline void rd() {}\ntemplate <typename Head, typename...\
    \ Tail>\ninline void rd(Head& head, Tail&... tail) {\n  rd(head);\n  rd(tail...);\n\
    }\n\ninline void wt(char c) { obuf[por++] = c; }\ntemplate <typename T>\ninline\
    \ void wt(T x) {\n  if (por > SZ - 32) flush();\n  if (!x) {\n    obuf[por++]\
    \ = '0';\n    return;\n  }\n  if (x < 0) {\n    obuf[por++] = '-';\n    x = -x;\n\
    \  }\n  int i = 12;\n  char buf[16];\n  while (x >= 10000) {\n    memcpy(buf +\
    \ i, pre.num + (x % 10000) * 4, 4);\n    x /= 10000;\n    i -= 4;\n  }\n  if (x\
    \ < 100) {\n    if (x < 10) {\n      wt(char('0' + char(x)));\n    } else {\n\
    \      uint32_t q = (uint32_t(x) * 205) >> 11;\n      uint32_t r = uint32_t(x)\
    \ - q * 10;\n      obuf[por + 0] = '0' + q;\n      obuf[por + 1] = '0' + r;\n\
    \      por += 2;\n    }\n  } else {\n    if (x < 1000) {\n      memcpy(obuf +\
    \ por, pre.num + (x << 2) + 1, 3);\n      por += 3;\n    } else {\n      memcpy(obuf\
    \ + por, pre.num + (x << 2), 4);\n      por += 4;\n    }\n  }\n  memcpy(obuf +\
    \ por, buf + i + 4, 12 - i);\n  por += 12 - i;\n}\n\ninline void wt() {}\ntemplate\
    \ <typename Head, typename... Tail>\ninline void wt(Head head, Tail... tail) {\n\
    \  wt(head);\n  wt(tail...);\n}\ntemplate <typename T>\ninline void wtn(T x) {\n\
    \  wt(x, '\\n');\n}\n\nstruct Dummy {\n  Dummy() { atexit(flush); }\n} dummy;\n\
    \n}  // namespace fastio\nusing fastio::rd;\nusing fastio::wt;\nusing fastio::wtn;\n\
    #line 3 \"modulo/mod-log.hpp\"\nusing namespace std;\n\n#line 3 \"math/elementary-function.hpp\"\
    \nusing namespace std;\n\nlong long my_gcd(long long x, long long y) {\n  long\
    \ long z;\n  if (x > y) swap(x, y);\n  while (x) {\n    x = y % (z = x);\n   \
    \ y = z;\n  }\n  return y;\n}\nlong long my_lcm(long long x, long long y) {\n\
    \  return 1LL * x / my_gcd(x, y) * y;\n}\n#define gcd my_gcd\n#define lcm my_lcm\n\
    \n// totient function \u03C6(N)=(1 ~ N , gcd(i,N) = 1)\n// {0, 1, 1, 2, 4, 2,\
    \ 6, 4, ... }\nvector<int> EulersTotientFunction(int N) {\n  vector<int> ret(N\
    \ + 1, 0);\n  for (int i = 0; i <= N; i++) ret[i] = i;\n  for (int i = 2; i <=\
    \ N; i++) {\n    if (ret[i] == i)\n      for (int j = i; j <= N; j += i) ret[j]\
    \ = ret[j] / i * (i - 1);\n  }\n  return ret;\n}\n\n// Divisor ex) 12 -> {1, 2,\
    \ 3, 4, 6, 12}\nvector<long long> Divisor(long long N) {\n  vector<long long>\
    \ v;\n  for (long long i = 1; i * i <= N; i++) {\n    if (N % i == 0) {\n    \
    \  v.push_back(i);\n      if (i * i != N) v.push_back(N / i);\n    }\n  }\n  return\
    \ v;\n}\n\n// Factorization\n// ex) 18 -> { (2,1) , (3,2) }\nvector<pair<long\
    \ long, int> > PrimeFactors(long long N) {\n  vector<pair<long long, int> > ret;\n\
    \  for (long long p = 2; p * p <= N; p++)\n    if (N % p == 0) {\n      ret.emplace_back(p,\
    \ 0);\n      while (N % p == 0) N /= p, ret.back().second++;\n    }\n  if (N >=\
    \ 2) ret.emplace_back(N, 1);\n  return ret;\n}\n\n// Factorization with Prime\
    \ Sieve\n// ex) 18 -> { (2,1) , (3,2) }\nvector<pair<long long, int> > PrimeFactors(long\
    \ long N,\n                                           const vector<long long>\
    \ &prime) {\n  vector<pair<long long, int> > ret;\n  for (auto &p : prime) {\n\
    \    if (p * p > N) break;\n    if (N % p == 0) {\n      ret.emplace_back(p, 0);\n\
    \      while (N % p == 0) N /= p, ret.back().second++;\n    }\n  }\n  if (N >=\
    \ 2) ret.emplace_back(N, 1);\n  return ret;\n}\n\n// modpow for mod < 2 ^ 31\n\
    long long modpow(long long a, long long n, long long mod) {\n  a %= mod;\n  long\
    \ long ret = 1;\n  while (n > 0) {\n    if (n & 1) ret = ret * a % mod;\n    a\
    \ = a * a % mod;\n    n >>= 1;\n  }\n  return ret % mod;\n};\n\n// Check if r\
    \ is Primitive Root\nbool isPrimitiveRoot(long long r, long long mod) {\n  r %=\
    \ mod;\n  if (r == 0) return false;\n  auto pf = PrimeFactors(mod - 1);\n  for\
    \ (auto &x : pf) {\n    if (modpow(r, (mod - 1) / x.first, mod) == 1) return false;\n\
    \  }\n  return true;\n}\n\n// Get Primitive Root\nlong long PrimitiveRoot(long\
    \ long mod) {\n  long long ret = 1;\n  while (isPrimitiveRoot(ret, mod) == false)\
    \ ret++;\n  return ret;\n}\n\n// Euler's phi function\nlong long phi(long long\
    \ n) {\n  auto pf = PrimeFactors(n);\n  long long ret = n;\n  for (auto p : pf)\
    \ {\n    ret /= p.first;\n    ret *= (p.first - 1);\n  }\n  return ret;\n}\n\n\
    // Extended Euclidean algorithm\n// solve : ax + by = gcd(a, b)\n// return : pair(x,\
    \ y)\npair<long long, long long> extgcd(long long a, long long b) {\n  if (b ==\
    \ 0) return make_pair(1, 0);\n  long long x, y;\n  tie(y, x) = extgcd(b, a % b);\n\
    \  y -= a / b * x;\n  return make_pair(x, y);\n}\n\n// Check if n is Square Number\n\
    // true : return d s.t. d * d == n\n// false : return -1\nlong long SqrtInt(long\
    \ long n) {\n  if (n == 0 || n == 1) return n;\n  long long d = (long long)sqrt(n)\
    \ - 1;\n  while (d * d < n) ++d;\n  return (d * d == n) ? d : -1;\n}\n\n// return\
    \ a number of n's digit\n// zero ... return value if n = 0 (default -> 1)\nint\
    \ isDigit(long long n, int zero = 1) {\n  if (n == 0) return zero;\n  int ret\
    \ = 0;\n  while (n) {\n    n /= 10;\n    ret++;\n  }\n  return ret;\n}\n#line\
    \ 6 \"modulo/mod-log.hpp\"\n\nint64_t mod_log(int64_t a, int64_t b, int64_t p)\
    \ {\n  if ((a %= p) < 0) a += p;\n  if ((b %= p) < 0) b += p;\n  int64_t f, g,\
    \ r = 1 % p;\n  for (f = 0; (g = __gcd(a, p)) > 1; ++f) {\n    if (b % g) return\
    \ (r == b) ? f : -1;\n    b /= g;\n    p /= g;\n    (r *= (a / g)) %= p;\n  }\n\
    \  if (p == 1) return f;\n  auto ir = extgcd(r, p);\n  (b *= (ir.first + p)) %=\
    \ p;\n  int64_t k = 0, ak = 1;\n  unordered_map<int64_t, int64_t> baby;\n  for\
    \ (; k * k < p; ++k) {\n    if (!baby.count(ak)) baby[ak] = k;\n    (ak *= a)\
    \ %= p;\n  }\n  auto iak = extgcd(ak, p);\n  if(iak.first < 0) iak.first += p;\n\
    \  for (int64_t i = 0; i < k; ++i) {\n    if (baby.count(b)) return f + i * k\
    \ + baby[b];\n    (b *= iak.first) %= p;\n  }\n  return -1;\n}\n#line 6 \"verify/verify-yosupo-math/yosupo-mod-log.test.cpp\"\
    \n\nvoid solve() {\n  int T;\n  rd(T);\n  rep(_, T) {\n    ll x, y, m;\n    rd(x,\
    \ y, m);\n    wt(mod_log(x, y, m));\n    wt('\\n');\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include \"../../competitive-template.hpp\"\n#include \"../../misc/fastio.hpp\"\
    \n#include \"../../modulo/mod-log.hpp\"\n\nvoid solve() {\n  int T;\n  rd(T);\n\
    \  rep(_, T) {\n    ll x, y, m;\n    rd(x, y, m);\n    wt(mod_log(x, y, m));\n\
    \    wt('\\n');\n  }\n}"
  dependsOn:
  - competitive-template.hpp
  - misc/fastio.hpp
  - modulo/mod-log.hpp
  - math/elementary-function.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
  requiredBy: []
  timestamp: '2020-09-18 02:08:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-math/yosupo-mod-log.test.cpp
- /verify/verify/verify-yosupo-math/yosupo-mod-log.test.cpp.html
title: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
---
