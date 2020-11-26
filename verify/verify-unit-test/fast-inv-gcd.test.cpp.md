---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: misc/timer.hpp
    title: misc/timer.hpp
  - icon: ':heavy_check_mark:'
    path: trial/fast-gcd.hpp
    title: "\u9AD8\u901FGCD"
  - icon: ':heavy_check_mark:'
    path: trial/fast-inv.hpp
    title: "\u9AD8\u901Fmodulo\u9006\u5143"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/fast-inv-gcd.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"competitive-template.hpp\"\
    \n#pragma region kyopro_template\n#define Nyaan_template\n#include <immintrin.h>\n\
    #include <bits/stdc++.h>\n#define pb push_back\n#define eb emplace_back\n#define\
    \ fi first\n#define se second\n#define each(x, v) for (auto &x : v)\n#define all(v)\
    \ (v).begin(), (v).end()\n#define sz(v) ((int)(v).size())\n#define mem(a, val)\
    \ memset(a, val, sizeof(a))\n#define ini(...)   \\\n  int __VA_ARGS__; \\\n  in(__VA_ARGS__)\n\
    #define inl(...)         \\\n  long long __VA_ARGS__; \\\n  in(__VA_ARGS__)\n\
    #define ins(...)      \\\n  string __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define\
    \ inc(...)    \\\n  char __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define in2(s, t)\
    \                           \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\
    \n    in(s[i], t[i]);                         \\\n  }\n#define in3(s, t, u)  \
    \                      \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n  \
    \  in(s[i], t[i], u[i]);                   \\\n  }\n#define in4(s, t, u, v)  \
    \                   \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i],\
    \ t[i], u[i], v[i]);             \\\n  }\n#define rep(i, N) for (long long i =\
    \ 0; i < (long long)(N); i++)\n#define repr(i, N) for (long long i = (long long)(N)-1;\
    \ i >= 0; i--)\n#define rep1(i, N) for (long long i = 1; i <= (long long)(N);\
    \ i++)\n#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)\n\
    #define reg(i, a, b) for (long long i = (a); i < (b); i++)\n#define die(...) \
    \     \\\n  do {                \\\n    out(__VA_ARGS__); \\\n    return;    \
    \       \\\n  } while (0)\nusing namespace std;\nusing ll = long long;\ntemplate\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"trial/fast-inv.hpp\"\nusing\
    \ namespace std;\n\n#line 3 \"misc/timer.hpp\"\nusing namespace std;\n\nstruct\
    \ Timer {\n  chrono::high_resolution_clock::time_point st;\n\n  Timer() { reset();\
    \ }\n\n  void reset() { st = chrono::high_resolution_clock::now(); }\n\n  chrono::milliseconds::rep\
    \ elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n    return\
    \ chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n};\n#line\
    \ 6 \"trial/fast-inv.hpp\"\n\nnamespace fast_inv {\nusing u64 = uint64_t;\nusing\
    \ u32 = uint32_t;\nusing i32 = int32_t;\nconstexpr u32 MOD = 998244353;\n\nstruct\
    \ Pre {\n  u32 a[64];\n  constexpr Pre() : a() {\n    static_assert(MOD & 1);\n\
    \    a[0] = 1;\n    for (int i = 1; i < 64; i++) a[i] = u64(a[i - 1]) * ((MOD\
    \ + 1) >> 1) % MOD;\n  }\n} constexpr pre;\n\n__attribute__((target(\"bmi\")))\
    \ u32 bgcd_inv(u32 a) {\n  u32 b = MOD, s = 1, t = 0;\n  int n = __builtin_ctz(a);\n\
    \  a >>= n;\n  if (__builtin_expect(a < 1 << 20, false)) {\n    if (a == 1) return\
    \ pre.a[n];\n    t = -(b / a);\n    b %= a;\n    int m = __builtin_ctz(b);\n \
    \   b >>= m;\n    s = 1u << m;\n    n += m;\n  }\n  while (a != b) {\n    int\
    \ m = __builtin_ctz(a - b);\n    n += m;\n    if (a > b) {\n      a -= b;\n  \
    \    s -= t;\n      a >>= m;\n      t <<= m;\n    } else {\n      b -= a;\n  \
    \    t -= s;\n      b >>= m;\n      s <<= m;\n    }\n  }\n  return u64(s) * pre.a[n]\
    \ % MOD;\n}\n\n}  // namespace fast_inv\n\nnamespace fast_inv {\n\n__attribute__((optimize(\"\
    unroll-loops\"))) u32 pow_inv(u32 a) {\n  u32 ret = 1;\n  for (u32 p = MOD - 2;\
    \ p; a = u64(a) * a % MOD, p >>= 1)\n    if (p & 1) ret = u64(ret) * a % MOD;\n\
    \  return ret;\n}\n\nu32 egcd_inv(u32 a) {\n  u32 b = MOD, s = 1, t = 0;\n  while\
    \ (true) {\n    if (a == 1) return s;\n    t -= b / a * s;\n    b %= a;\n    if\
    \ (b == 1) return t + MOD;\n    s -= a / b * t;\n    a %= b;\n  }\n}\n\nu32 reduce(const\
    \ u64 &b) { return (b + u64(u32(b) * 998244351u) * MOD) >> 32; }\n\nu32 mul(const\
    \ u32 &a, const u32 &b) { return reduce(u64(a) * b); }\n\n__attribute__((optimize(\"\
    unroll-loops\"))) u32 montgomery_pow_inv(u32 a) {\n  u32 ret = 301989884u;\n \
    \ for (u32 p = MOD - 2; p; a = mul(a, a), p >>= 1)\n    if (p & 1) ret = mul(ret,\
    \ a);\n  return reduce(reduce(ret));\n}\n\nu64 x_;\nvoid rng_init() { x_ = 88172645463325252ULL;\
    \ }\nu64 rng() { return x_ = x_ ^ (x_ << 7), x_ = x_ ^ (x_ >> 9); }\n\nvoid test_inner(u32\
    \ (*f)(u32)) {\n  auto test = [](u32 (*f)(u32), int n, u32 upper, string s) {\n\
    \    assert((upper & (upper - 1)) == 0);\n    --upper;\n\n    // set timer\n \
    \   Timer timer;\n    timer.reset();\n\n    // calculation\n    u64 res = 0;\n\
    \    while (n--) {\n      u32 a;\n      do {\n        a = rng() & upper;\n   \
    \     a = a >= MOD ? a - MOD : a;\n      } while (a == 0);\n      res += f(a);\n\
    \    }\n\n    // output results\n    cerr << s << \" \" << res << \" \" << timer.elapsed()\
    \ << endl;\n  };\n\n  rng_init();\n  test(f, 1e5, 1 << 10, \"small\");\n  test(f,\
    \ 1e5, 1 << 20, \"medium\");\n  test(f, 1e5, 1 << 30, \"large\");\n}\n\nvoid unit_test()\
    \ {\n  using F = u32 (*)(u32);\n\n  vector<u32> testcase;\n  for (u32 i = 1; i\
    \ <= 100000; ++i) testcase.emplace_back(i);\n  rng_init();\n  for (u32 loop =\
    \ 100000; --loop;) {\n    u32 r = rng() % MOD;\n    if (r != 0) testcase.emplace_back(r);\n\
    \  }\n  vector<F> functions = {pow_inv, egcd_inv, montgomery_pow_inv, bgcd_inv};\n\
    \n  for (auto t : testcase) {\n    unordered_set<u32> s;\n    for (auto &f : functions)\
    \ {\n      s.insert(f(t));\n    }\n    if (s.size() != 1u) {\n      cerr << \"\
    verify failed.\" << endl;\n      cerr << \"case : \" << t << endl;\n      cerr\
    \ << \"output : \";\n      for (auto &f : functions) cerr << f(t) << \", \";\n\
    \      cerr << endl;\n      exit(1);\n    }\n  }\n  cerr << \"verify passed.\"\
    \ << endl;\n\n  // pow-inv\n  cerr << \"pow-inv\" << endl;\n  test_inner(pow_inv);\n\
    \n  // extgcd-inv\n  cerr << \"extgcd-inv\" << endl;\n  test_inner(egcd_inv);\n\
    \n  // montgomery-inv\n  cerr << \"montgomery-inv\" << endl;\n  test_inner(montgomery_pow_inv);\n\
    \n  // binary-gcd-inv\n  cerr << \"binary-gcd-inv\" << endl;\n  test_inner(bgcd_inv);\n\
    }\n\n}  // namespace fast_inv\n\n/**\n * @brief \u9AD8\u901Fmodulo\u9006\u5143\
    \n * @docs docs/trial/fast-inv.md\n */\n#line 3 \"trial/fast-gcd.hpp\"\nusing\
    \ namespace std;\n\n#line 6 \"trial/fast-gcd.hpp\"\n\nnamespace fast_gcd {\nusing\
    \ u64 = uint64_t;\nusing u32 = uint32_t;\n\n__attribute__((target(\"bmi\"))) u64\
    \ binary_gcd(u64 a, u64 b) {\n  if (a == 0 || b == 0) return a + b;\n  int n =\
    \ __builtin_ctzll(a);\n  int m = __builtin_ctzll(b);\n  a >>= n;\n  b >>= m;\n\
    \  while (a != b) {\n    int m = __builtin_ctzll(a - b);\n    bool f = a > b;\n\
    \    u64 c = f ? a : b;\n    b = f ? b : a;\n    a = (c - b) >> m;\n  }\n  return\
    \ a << min(n, m);\n}\n}  // namespace fast_gcd\n\nnamespace fast_gcd {\n\nuint64_t\
    \ naive_gcd(uint64_t a, uint64_t b) {\n  while (b) swap(a %= b, b);\n  return\
    \ a;\n}\n\nu64 x_;\nvoid rng_init() { x_ = 88172645463325252ULL; }\nu64 rng()\
    \ { return x_ = x_ ^ (x_ << 7), x_ = x_ ^ (x_ >> 9); }\n\nvoid test_inner(u64\
    \ (*f)(u64, u64)) {\n  auto test = [&](u64 (*f)(u64, u64), int n, u64 upper, string\
    \ s) {\n    assert((upper & (upper - 1)) == 0);\n    --upper;\n\n    // set timer\n\
    \    Timer timer;\n    timer.reset();\n\n    // calculation\n    u64 res = 0;\n\
    \    while (n--) {\n      u64 a = rng() & upper;\n      u64 b = rng() & upper;\n\
    \      res += f(a, b);\n    }\n\n    // output results\n    cerr << s << \" \"\
    \ << res << \" \" << timer.elapsed() << endl;\n  };\n\n  rng_init();\n  test(f,\
    \ 1e5, 1LL << 16, \"small\");\n  test(f, 1e5, 1LL << 32, \"medium\");\n  test(f,\
    \ 1e5, 0, \"large\");\n}\n\nvoid unit_test() {\n  using P = pair<u64, u64>;\n\
    \  using F = u64 (*)(u64, u64);\n\n  vector<P> testcase{P(2, 4),\n           \
    \          P(100000, 10000),\n                     P(998244353, 1000000007),\n\
    \                     P(1LL << 40, 1LL << 60),\n                     P((1LL <<\
    \ 61) - 1, 11111111111111111),\n                     P((1LL << 60) + 1, (1LL <<\
    \ 59) + 1),\n                     P(1LL << 63, 1LL << 63),\n                 \
    \    P(1LL << 63, 1LL << 62),\n                     P(3LL << 61, 9LL << 60)};\n\
    \  for (u64 i = 1000; i--;)\n    for (u64 j = 1000; j--;) testcase.emplace_back(i,\
    \ j);\n  rng_init();\n  for (u64 n = 10000; n--;) {\n    u64 i = rng(), j = rng();\n\
    \    testcase.emplace_back(i, j);\n  }\n\n  vector<F> functions{\n      std::__gcd<uint64_t>,\n\
    \      naive_gcd,\n      binary_gcd,\n  };\n\n  for (auto p : testcase) {\n  \
    \  unordered_set<u64> s;\n    for (auto &f : functions) {\n      s.insert(f(p.first,\
    \ p.second));\n    }\n    if (s.size() != 1u) {\n      cerr << \"verify failed.\"\
    \ << endl;\n      cerr << \"case : \" << p.first << \" \" << p.second << endl;\n\
    \      cerr << \"output : \";\n      for (auto &f : functions) cerr << f(p.first,\
    \ p.second) << \", \";\n      cerr << endl;\n      exit(1);\n    }\n  }\n  cerr\
    \ << \"verify passed.\" << endl;\n\n  // std::__gcd\n  cerr << \"std::__gcd\"\
    \ << endl;\n  test_inner(std::__gcd<uint64_t>);\n\n  // naive-gcd\n  cerr << \"\
    naive-gcd\" << endl;\n  test_inner(naive_gcd);\n\n  // binary-gcd\n  cerr << \"\
    binary-gcd\" << endl;\n  test_inner(binary_gcd);\n}\n\n}  // namespace fast_gcd\n\
    \n/**\n * @brief \u9AD8\u901FGCD\n * @docs docs/trial/fast-gcd.md\n */\n#line\
    \ 6 \"verify/verify-unit-test/fast-inv-gcd.test.cpp\"\n\nvoid solve(){\n  fast_inv::unit_test();\n\
    \  fast_gcd::unit_test();\n\n  int a,b;\n  cin >> a >> b;\n  cout << (a + b) <<\
    \ endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../competitive-template.hpp\"\n#include \"../../trial/fast-inv.hpp\"\n#include\
    \ \"../../trial/fast-gcd.hpp\"\n\nvoid solve(){\n  fast_inv::unit_test();\n  fast_gcd::unit_test();\n\
    \n  int a,b;\n  cin >> a >> b;\n  cout << (a + b) << endl;\n}"
  dependsOn:
  - competitive-template.hpp
  - trial/fast-inv.hpp
  - misc/timer.hpp
  - trial/fast-gcd.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/fast-inv-gcd.test.cpp
  requiredBy: []
  timestamp: '2020-11-26 20:10:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/fast-inv-gcd.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/fast-inv-gcd.test.cpp
- /verify/verify/verify-unit-test/fast-inv-gcd.test.cpp.html
title: verify/verify-unit-test/fast-inv-gcd.test.cpp
---
