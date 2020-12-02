---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: multiplicative-function/divisor-multiple-transform.hpp
    title: "\u500D\u6570\u5909\u63DB\u30FB\u7D04\u6570\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: prime/prime-enumerate.hpp
    title: prime/prime-enumerate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/multiplicative-function.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"competitive-template.hpp\"\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"misc/rng.hpp\"\nusing namespace\
    \ std;\n\nnamespace my_rand {\n\n// [0, 2^64 - 1)\nuint64_t rng() {\n  static\
    \ uint64_t x_ =\n      uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                   chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count()) *\n      10150724397891781847ULL;\n  x_ ^= x_ <<\
    \ 7;\n  return x_ ^= x_ >> 9;\n}\n\n// [l, r)\nint64_t randint(int64_t l, int64_t\
    \ r) {\n  assert(l < r);\n  return l + rng() % (r - l);\n}\n\n// choose n numbers\
    \ from [l, r) without overlapping\nvector<int64_t> randset(int64_t l, int64_t\
    \ r, int64_t n) {\n  assert(l <= r && n <= r - l);\n  unordered_set<int64_t> s;\n\
    \  for (int64_t i = n; i; --i) {\n    int64_t m = randint(l, r + 1 - i);\n   \
    \ if (s.find(m) != s.end()) m = r - i;\n    s.insert(m);\n  }\n  vector<int64_t>\
    \ ret;\n  for (auto& x : s) ret.push_back(x);\n  return ret;\n}\n\n// [0.0, 1.0)\n\
    double rnd() {\n  union raw_cast {\n    double t;\n    uint64_t u;\n  };\n  constexpr\
    \ uint64_t p = uint64_t(1023 - 64) << 52;\n  return rnd() * ((raw_cast*)(&p))->t;\n\
    }\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n\
    \  for (int loop = 0; loop < 2; loop++)\n    for (int i = 0; i < n; i++) swap(v[i],\
    \ v[randint(0, n)]);\n}\n\n}  // namespace my_rand\n\nusing my_rand::randint;\n\
    using my_rand::randset;\nusing my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n\
    #line 3 \"modint/montgomery-modint.hpp\"\nusing namespace std;\n\ntemplate <uint32_t\
    \ mod>\nstruct LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n\
    \  using i32 = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n\
    \  static constexpr u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i <\
    \ 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n  static constexpr u32\
    \ r = get_r();\n  static constexpr u32 n2 = -u64(mod) % mod;\n  static_assert(r\
    \ * mod == 1, \"invalid, r * mod != 1\");\n  static_assert(mod < (1 << 30), \"\
    invalid, mod >= 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"invalid, mod % 2\
    \ == 0\");\n\n  u32 a;\n\n  constexpr LazyMontgomeryModInt() : a(0) {}\n  constexpr\
    \ LazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b % mod + mod)\
    \ * n2)){};\n\n  static constexpr u32 reduce(const u64 &b) {\n    return (b +\
    \ u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  constexpr mint &operator+=(const\
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
    \ { return mod; }\n};\n#line 6 \"verify/verify-unit-test/multiplicative-function.test.cpp\"\
    \nusing mint = LazyMontgomeryModInt<998244353>;\nusing vm = vector<mint>;\nusing\
    \ vvm = vector<vm>;\n\n#line 3 \"multiplicative-function/divisor-multiple-transform.hpp\"\
    \nusing namespace std;\n\n#line 3 \"prime/prime-enumerate.hpp\"\nusing namespace\
    \ std;\n\n// Prime Sieve {2, 3, 5, 7, 11, 13, 17, ...}\nvector<int> prime_enumerate(int\
    \ N) {\n  vector<bool> sieve(N / 3 + 1, 1);\n  for (int p = 5, d = 4, i = 1, sqn\
    \ = sqrt(N); p <= sqn; p += d = 6 - d, i++) {\n    if (!sieve[i]) continue;\n\
    \    for (int q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p,\n  \
    \           qe = sieve.size();\n         q < qe; q += r = s - r)\n      sieve[q]\
    \ = 0;\n  }\n  vector<int> ret{2, 3};\n  for (int p = 5, d = 4, i = 1; p <= N;\
    \ p += d = 6 - d, i++)\n    if (sieve[i]) ret.push_back(p);\n  while (!ret.empty()\
    \ && ret.back() > N) ret.pop_back();\n  return ret;\n}\n#line 6 \"multiplicative-function/divisor-multiple-transform.hpp\"\
    \n\nstruct divisor_transform {\n  template <typename T>\n  static void zeta_transform(vector<T>\
    \ &a) {\n    int N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n   \
    \ for (auto &p : sieve)\n      for (int k = 1; k * p <= N; ++k) a[k * p] += a[k];\n\
    \  }\n  template <typename T>\n  static void mobius_transform(T &a) {\n    int\
    \ N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n    for (auto &p :\
    \ sieve)\n      for (int k = N / p; k > 0; --k) a[k * p] -= a[k];\n  }\n\n  template\
    \ <typename T>\n  static void zeta_transform(map<long long, T> &a) {\n    for\
    \ (auto p = rbegin(a); p != rend(a); p++)\n      for (auto &x : a) {\n       \
    \ if (p->first == x.first) break;\n        if (p->first % x.first == 0) p->second\
    \ += x.second;\n      }\n  }\n  template <typename T>\n  static void mobius_transform(map<long\
    \ long, T> &a) {\n    for (auto &x : a)\n      for (auto p = rbegin(a); p != rend(a);\
    \ p++) {\n        if (x.first == p->first) break;\n        if (p->first % x.first\
    \ == 0) p->second -= x.second;\n      }\n  }\n};\n\nstruct multiple_transform\
    \ {\n  template <typename T>\n  static void zeta_transform(vector<T> &a) {\n \
    \   int N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n    for (auto\
    \ &p : sieve)\n      for (int k = N / p; k > 0; --k) a[k] += a[k * p];\n  }\n\
    \  template <typename T>\n  static void mobius_transform(vector<T> &a) {\n   \
    \ int N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n    for (auto &p\
    \ : sieve)\n      for (int k = 1; k * p <= N; ++k) a[k] -= a[k * p];\n  }\n\n\
    \  template <typename T>\n  static void zeta_transform(map<long long, T> &a) {\n\
    \    for (auto &x : a)\n      for (auto p = rbegin(a); p->first != x.first; p++)\n\
    \        if (p->first % x.first == 0) x.second += p->second;\n  }\n  template\
    \ <typename T>\n  static void mobius_transform(map<long long, T> &a) {\n    for\
    \ (auto p1 = rbegin(a); p1 != rend(a); p1++)\n      for (auto p2 = rbegin(a);\
    \ p2 != p1; p2++)\n        if (p2->first % p1->first == 0) p1->second -= p2->second;\n\
    \  }\n};\n\n/**\n * @brief \u500D\u6570\u5909\u63DB\u30FB\u7D04\u6570\u5909\u63DB\
    \n * @docs docs/multiplicative-function/divisor-multiple-transform.md\n */\n#line\
    \ 11 \"verify/verify-unit-test/multiplicative-function.test.cpp\"\nvoid test()\
    \ {\n  // \u7D04\u6570\u30FB\u500D\u6570\u30BC\u30FC\u30BF/\u30E1\u30D3\u30A6\u30B9\
    \u5909\u63DB\u306Everify\n  auto map_transform = [](int n) {\n    map<ll, mint>\
    \ a;\n    for (ll i = 1; i * i <= n; i++) {\n      if (n % i == 0) {\n       \
    \ a[i] = rng();\n        a[n / i] = rng();\n      }\n    }\n    auto a1 = a;\n\
    \    divisor_transform::zeta_transform(a1);\n    divisor_transform::mobius_transform(a1);\n\
    \    assert(a1 == a && \"divisor_transform\");\n\n    multiple_transform::zeta_transform(a1);\n\
    \    multiple_transform::mobius_transform(a1);\n    assert(a1 == a && \"multiple_transform\"\
    );\n  };\n  rep(i, 1000) { map_transform(rng() % 100000 + 1); }\n  rep1(i, 100)\
    \ { map_transform(840 * i); }\n\n  \n\n}\n\nvoid solve() {\n  test();\n  trc(\"\
    test OK\");\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../competitive-template.hpp\"\n#include \"../../misc/rng.hpp\"\n#include \"\
    ../../modint/montgomery-modint.hpp\"\nusing mint = LazyMontgomeryModInt<998244353>;\n\
    using vm = vector<mint>;\nusing vvm = vector<vm>;\n\n#include \"../../multiplicative-function/divisor-multiple-transform.hpp\"\
    \nvoid test() {\n  // \u7D04\u6570\u30FB\u500D\u6570\u30BC\u30FC\u30BF/\u30E1\u30D3\
    \u30A6\u30B9\u5909\u63DB\u306Everify\n  auto map_transform = [](int n) {\n   \
    \ map<ll, mint> a;\n    for (ll i = 1; i * i <= n; i++) {\n      if (n % i ==\
    \ 0) {\n        a[i] = rng();\n        a[n / i] = rng();\n      }\n    }\n   \
    \ auto a1 = a;\n    divisor_transform::zeta_transform(a1);\n    divisor_transform::mobius_transform(a1);\n\
    \    assert(a1 == a && \"divisor_transform\");\n\n    multiple_transform::zeta_transform(a1);\n\
    \    multiple_transform::mobius_transform(a1);\n    assert(a1 == a && \"multiple_transform\"\
    );\n  };\n  rep(i, 1000) { map_transform(rng() % 100000 + 1); }\n  rep1(i, 100)\
    \ { map_transform(840 * i); }\n\n  \n\n}\n\nvoid solve() {\n  test();\n  trc(\"\
    test OK\");\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n}"
  dependsOn:
  - competitive-template.hpp
  - misc/rng.hpp
  - modint/montgomery-modint.hpp
  - multiplicative-function/divisor-multiple-transform.hpp
  - prime/prime-enumerate.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/multiplicative-function.test.cpp
  requiredBy: []
  timestamp: '2020-12-03 00:21:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/multiplicative-function.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/multiplicative-function.test.cpp
- /verify/verify/verify-unit-test/multiplicative-function.test.cpp.html
title: verify/verify-unit-test/multiplicative-function.test.cpp
---
