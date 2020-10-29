---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime-counting-o2d3.hpp
    title: "\u7D20\u6570\u30AB\u30A6\u30F3\u30C8( $\\mathrm{O}(N^{\\frac{2}{3}})$\
      \ )"
  - icon: ':heavy_check_mark:'
    path: prime/prime-enumerate.hpp
    title: prime/prime-enumerate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/counting_primes
    links:
    - https://judge.yosupo.jp/problem/counting_primes
  bundledCode: "#line 1 \"verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\n\n#line\
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
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"math/prime-counting-o2d3.hpp\"\
    \nusing namespace std;\n\n#line 3 \"prime/prime-enumerate.hpp\"\nusing namespace\
    \ std;\n\n// Prime Sieve {2, 3, 5, 7, 11, 13, 17, ...}\nvector<int> prime_enumerate(int\
    \ N) {\n  vector<bool> sieve(N / 3 + 1, 1);\n  for (int p = 5, d = 4, i = 1, sqn\
    \ = sqrt(N); p <= sqn; p += d = 6 - d, i++) {\n    if (!sieve[i]) continue;\n\
    \    for (int q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p,\n  \
    \           qe = sieve.size();\n         q < qe; q += r = s - r)\n      sieve[q]\
    \ = 0;\n  }\n  vector<int> ret{2, 3};\n  for (int p = 5, d = 4, i = 1; p <= N;\
    \ p += d = 6 - d, i++)\n    if (sieve[i]) ret.push_back(p);\n  while (!ret.empty()\
    \ && ret.back() > N) ret.pop_back();\n  return ret;\n}\n#line 6 \"math/prime-counting-o2d3.hpp\"\
    \n\ninline int64_t my_div(int64_t n, int64_t p) { return double(n) / p; };\n\n\
    int64_t prime_counting(long long N) {\n  using i64 = long long;\n\n  i64 N6, N3,\
    \ N2, N23, nsz;\n  vector<i64> ns, h;\n  vector<int> bit;\n\n  // calculate N^{1/2},\
    \ N^{1/3}, N{1/6}, N{2/3}\n  N2 = sqrt(N);\n  N3 = pow(N, 1.0 / 3.0);\n  while\
    \ (N3 * N3 * N3 > N) N3--;\n  while ((N3 + 1) * (N3 + 1) * (N3 + 1) <= N) N3++;\n\
    \  N6 = sqrt(N3);\n  N23 = N / N3;\n\n  // precalc prime sieve below N ^ {1/2}\n\
    \  auto prime = prime_enumerate(N2 + 1000);\n  // index of prime\n  int pidx =\
    \ 0;\n  // restore pi(p - 1)\n  i64 pi = 0;\n\n  // initialize ns\n  ns.reserve(N2\
    \ * 2 + 2);\n  ns.push_back(0);\n  for (int i = 1; i <= N2; i++) ns.push_back(my_div(N,\
    \ i));\n  for (int i = ns.back() - 1; i > 0; i--) ns.push_back(i);\n  nsz = ns.size();\n\
    \n  // initialize h\n  copy(begin(ns), end(ns), back_inserter(h));\n  for (auto\
    \ &i : h) --i;\n\n  // p <= N ^ {1/6}\n  while (prime[pidx] <= N6) {\n    int\
    \ p = prime[pidx];\n    i64 p2 = i64(p) * p;\n    for (i64 i = 1, n = ns[i]; i\
    \ < nsz && n >= p2; n = ns[++i])\n      h[i] -= h[i * p <= N2 ? i * p : nsz -\
    \ my_div(n, p)] - pi;\n    ++pidx;\n    ++pi;\n  }\n\n  // fenwick tree, which\
    \ restore [ h(p, 1), h(p, N ^ {2/3}) )\n  // bit[i] corresponds to h[i + N3] (1\
    \ <= i)\n  bit.resize(nsz - N3);\n\n  auto dfs = [&](auto rec, i64 cur, int pid,\
    \ int flag) -> void {\n    if (flag) {\n      // if cur > N^{1/2} :\n      //\
    \ cur <= floor(N / id)\n      // -> cur * id + n = N, n < id < cur\n      // ->\
    \ id <= floor(N / cur)\n      int id = cur <= N2 ? nsz - cur : my_div(N, cur);\n\
    \      // decrease h[N3] ~ h[id]\n      if (id > N3)\n        for (id -= N3; id;\
    \ id -= id & -id) --bit[id];\n    }\n    for (int dst = pid; cur * prime[dst]\
    \ < N23; dst++)\n      rec(rec, cur * prime[dst], dst, true);\n  };\n\n  // N\
    \ ^ {1/6} < p <= N ^ {1/3}\n  while (prime[pidx] <= N3) {\n    int p = prime[pidx];\n\
    \    i64 p2 = i64(p) * p;\n    // update N ^ {2/3} <= n <= N\n    for (i64 i =\
    \ 1; i <= N3; i++) {\n      // ns[i] >= p2 > N^{1/3}\n      if (p2 > ns[i]) break;\n\
    \      // id of floor(N/ip)\n      int id = i * p <= N2 ? i * p : nsz - my_div(ns[i],\
    \ p);\n      // current value of h[id]\n\n      i64 sm = h[id];\n      // if floor(N/ip)\
    \ < N^{2/3}, add sum of fenwick tree\n      if (id > N3)\n        for (id -= N3;\
    \ id < (int)bit.size(); id += id & -id) sm += bit[id];\n      h[i] -= sm - pi;\n\
    \    }\n\n    // update N ^ {1/3} <= n < N ^ {2/3}, using dfs\n    dfs(dfs, p,\
    \ pidx, false);\n\n    ++pidx;\n    ++pi;\n  }\n\n  // reflect fenwick tree\n\
    \  for (int i = (int)bit.size() - 1; i; i--) {\n    int j = i + (i & -i);\n  \
    \  if (j < (int)bit.size()) bit[i] += bit[j];\n  }\n  for (int i = 1; i < (int)bit.size();\
    \ i++) h[i + N3] += bit[i];\n\n  // N ^ {1/3} < p <= N ^ {1/2}\n  while (prime[pidx]\
    \ <= N2) {\n    int p = prime[pidx];\n    i64 p2 = i64(p) * p;\n    for (i64 i\
    \ = 1, n = ns[i]; i < nsz && n >= p2; n = ns[++i])\n      h[i] -= h[i * p <= N2\
    \ ? i * p : nsz - my_div(n, p)] - pi;\n    ++pidx;\n    ++pi;\n  }\n\n  return\
    \ h[1];\n}\n\n/**\n * @brief \u7D20\u6570\u30AB\u30A6\u30F3\u30C8( $\\mathrm{O}(N^{\\\
    frac{2}{3}})$ )\n * @docs docs/math/prime-counting-o2d3.md\n */\n#line 5 \"verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp\"\
    \n\nvoid solve() {\n  inl(N);\n  out(prime_counting(N));\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\n\n#include\
    \ \"../../competitive-template.hpp\"\n#include \"../../math/prime-counting-o2d3.hpp\"\
    \n\nvoid solve() {\n  inl(N);\n  out(prime_counting(N));\n}"
  dependsOn:
  - competitive-template.hpp
  - math/prime-counting-o2d3.hpp
  - prime/prime-enumerate.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp
  requiredBy: []
  timestamp: '2020-09-18 02:20:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp
- /verify/verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp.html
title: verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp
---
