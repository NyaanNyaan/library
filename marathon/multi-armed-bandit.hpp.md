---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-seed.hpp
    title: internal/internal-seed.hpp
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"marathon/multi-armed-bandit.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <numeric>\n#include <vector>\n\
    using namespace std;\n\n#line 2 \"misc/rng.hpp\"\n\n#line 2 \"internal/internal-seed.hpp\"\
    \n\n#include <chrono>\nusing namespace std;\n\nnamespace internal {\nunsigned\
    \ long long non_deterministic_seed() {\n  unsigned long long m =\n      chrono::duration_cast<chrono::nanoseconds>(\n\
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
    \  for (auto& x : s) ret.push_back(x);\n  return ret;\n}\n\n// [0.0, 1.0)\ndouble\
    \ rnd() { return rng() * 5.42101086242752217004e-20; }\n// [l, r)\ndouble rnd(double\
    \ l, double r) {\n  assert(l < r);\n  return l + rnd() * (r - l);\n}\n\ntemplate\
    \ <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n  for (int\
    \ i = 1; i < n; i++) swap(v[i], v[randint(0, i + 1)]);\n}\n\n}  // namespace my_rand\n\
    \nusing my_rand::randint;\nusing my_rand::randset;\nusing my_rand::randshf;\n\
    using my_rand::rnd;\nusing my_rand::rng;\n#line 9 \"marathon/multi-armed-bandit.hpp\"\
    \n\n// N \u629E, \u5831\u916C\u6700\u5927\u5316\nstruct MultiArmedBandit {\n \
    \ MultiArmedBandit(int n)\n      : N(n), last(-1), iter(0), thres(N * 5), num(N),\
    \ v(N), e(N), t(1) {}\n\n  int N, last;\n  long long iter, thres;\n  vector<long\
    \ long> num;\n  vector<double> v, e;\n  double t;\n\n  int play() {\n    assert(last\
    \ == -1);\n    iter++;\n    if (iter <= thres) return last = iter % N;\n\n   \
    \ double s = accumulate(begin(e), end(e), 0.0);\n    double x = rnd() * s;\n \
    \   for (int i = 0; i < N; i++) {\n      if ((x -= e[i]) <= 0) return last = i;\n\
    \    }\n    return last = N - 1;\n  }\n\n  // \u91CD\u307F\u4ED8\u3051\u7528\u306E\
    \u95A2\u6570\n  double f(double x) { return exp(x / t); }\n\n  void reward(double\
    \ y) {\n    assert(last != -1);\n    v[last] += y;\n    num[last] += 1;\n    e[last]\
    \ = f(v[last] / num[last]);\n    last = -1;\n\n    static double u = 1.0;\n  \
    \  static double du = 0.01;\n    // iter % thres == 0 \u306B\u306A\u3063\u305F\
    \u3089 t \u3092\u518D\u6C7A\u5B9A\n    if (iter % thres == 0) {\n      u = max(0.7,\
    \ u - du);\n      double average = accumulate(begin(v), end(v), 0.0) / thres;\n\
    \      t = average < 0.0 ? 1.0 : pow(average, u);\n      for (int i = 0; i < N;\
    \ i++) e[i] = f(v[i] / num[i]);\n    }\n  }\n  int best() { return max_element(begin(e),\
    \ end(e)) - begin(e); }\n};\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <numeric>\n\
    #include <vector>\nusing namespace std;\n\n#include \"../misc/rng.hpp\"\n\n//\
    \ N \u629E, \u5831\u916C\u6700\u5927\u5316\nstruct MultiArmedBandit {\n  MultiArmedBandit(int\
    \ n)\n      : N(n), last(-1), iter(0), thres(N * 5), num(N), v(N), e(N), t(1)\
    \ {}\n\n  int N, last;\n  long long iter, thres;\n  vector<long long> num;\n \
    \ vector<double> v, e;\n  double t;\n\n  int play() {\n    assert(last == -1);\n\
    \    iter++;\n    if (iter <= thres) return last = iter % N;\n\n    double s =\
    \ accumulate(begin(e), end(e), 0.0);\n    double x = rnd() * s;\n    for (int\
    \ i = 0; i < N; i++) {\n      if ((x -= e[i]) <= 0) return last = i;\n    }\n\
    \    return last = N - 1;\n  }\n\n  // \u91CD\u307F\u4ED8\u3051\u7528\u306E\u95A2\
    \u6570\n  double f(double x) { return exp(x / t); }\n\n  void reward(double y)\
    \ {\n    assert(last != -1);\n    v[last] += y;\n    num[last] += 1;\n    e[last]\
    \ = f(v[last] / num[last]);\n    last = -1;\n\n    static double u = 1.0;\n  \
    \  static double du = 0.01;\n    // iter % thres == 0 \u306B\u306A\u3063\u305F\
    \u3089 t \u3092\u518D\u6C7A\u5B9A\n    if (iter % thres == 0) {\n      u = max(0.7,\
    \ u - du);\n      double average = accumulate(begin(v), end(v), 0.0) / thres;\n\
    \      t = average < 0.0 ? 1.0 : pow(average, u);\n      for (int i = 0; i < N;\
    \ i++) e[i] = f(v[i] / num[i]);\n    }\n  }\n  int best() { return max_element(begin(e),\
    \ end(e)) - begin(e); }\n};\n"
  dependsOn:
  - misc/rng.hpp
  - internal/internal-seed.hpp
  isVerificationFile: false
  path: marathon/multi-armed-bandit.hpp
  requiredBy: []
  timestamp: '2023-09-02 22:21:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: marathon/multi-armed-bandit.hpp
layout: document
redirect_from:
- /library/marathon/multi-armed-bandit.hpp
- /library/marathon/multi-armed-bandit.hpp.html
title: marathon/multi-armed-bandit.hpp
---
