---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/fps/sum-of-exponential-times-poly.md
    document_title: $\sum_{i}a^i f(i)$
    links: []
  bundledCode: "#line 2 \"fps/sum-of-exponential-times-poly.hpp\"\n\n#line 2 \"modulo/binomial.hpp\"\
    \n\ntemplate <typename T>\nstruct Binomial {\n  vector<T> f, g, h;\n  Binomial(int\
    \ MAX = 0) {\n    assert(T::get_mod() != 0 && \"Binomial<mint>()\");\n    f.resize(1,\
    \ T{1});\n    g.resize(1, T{1});\n    h.resize(1, T{1});\n    while (MAX >= (int)f.size())\
    \ extend();\n  }\n\n  void extend() {\n    int n = f.size();\n    int m = n *\
    \ 2;\n    f.resize(m);\n    g.resize(m);\n    h.resize(m);\n    for (int i = n;\
    \ i < m; i++) f[i] = f[i - 1] * T(i);\n    g[m - 1] = f[m - 1].inverse();\n  \
    \  h[m - 1] = g[m - 1] * f[m - 2];\n    for (int i = m - 2; i >= n; i--) {\n \
    \     g[i] = g[i + 1] * T(i + 1);\n      h[i] = g[i] * f[i - 1];\n    }\n  }\n\
    \n  T fac(int i) {\n    if (i < 0) return T(0);\n    while (i >= (int)f.size())\
    \ extend();\n    return f[i];\n  }\n\n  T finv(int i) {\n    if (i < 0) return\
    \ T(0);\n    while (i >= (int)g.size()) extend();\n    return g[i];\n  }\n\n \
    \ T inv(int i) {\n    if (i < 0) return -inv(-i);\n    while (i >= (int)h.size())\
    \ extend();\n    return h[i];\n  }\n\n  T C(int n, int r) {\n    if (n < 0 ||\
    \ n < r || r < 0) return T(0);\n    return fac(n) * finv(n - r) * finv(r);\n \
    \ }\n\n  inline T operator()(int n, int r) { return C(n, r); }\n\n  template <typename\
    \ I>\n  T multinomial(const vector<I>& r) {\n    static_assert(is_integral<I>::value\
    \ == true);\n    int n = 0;\n    for (auto& x : r) {\n      if (x < 0) return\
    \ T(0);\n      n += x;\n    }\n    T res = fac(n);\n    for (auto& x : r) res\
    \ *= finv(x);\n    return res;\n  }\n\n  template <typename I>\n  T operator()(const\
    \ vector<I>& r) {\n    return multinomial(r);\n  }\n\n  T C_naive(int n, int r)\
    \ {\n    if (n < 0 || n < r || r < 0) return T(0);\n    T ret = T(1);\n    r =\
    \ min(r, n - r);\n    for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);\n  \
    \  return ret;\n  }\n\n  T P(int n, int r) {\n    if (n < 0 || n < r || r < 0)\
    \ return T(0);\n    return fac(n) * finv(n - r);\n  }\n\n  // [x^r] 1 / (1-x)^n\n\
    \  T H(int n, int r) {\n    if (n < 0 || r < 0) return T(0);\n    return r ==\
    \ 0 ? 1 : C(n + r - 1, r);\n  }\n};\n#line 4 \"fps/sum-of-exponential-times-poly.hpp\"\
    \n\n// given  : f(0)...f(k) (deg(f) = k), a, n\n// return : sum_{i=0...n-1} a^i\
    \ f(i)\ntemplate <typename mint>\nmint sum_of_exp(const vector<mint>& f, mint\
    \ a, long long n,\n                Binomial<mint>& C) {\n  if (n == 0) return\
    \ mint(0);\n  if (a == mint(0)) return f[0];\n  if (a == mint(1)) {\n    vector<mint>\
    \ g(f.size() + 1, mint(0));\n    for (int i = 1; i < (int)g.size(); i++) g[i]\
    \ = g[i - 1] + f[i - 1];\n    return lagrange_interpolation(g, n, C);\n  }\n \
    \ int K = f.size() - 1;\n  vector<mint> g(f.size());\n  mint buf = 1;\n  for (int\
    \ i = 0; i < (int)g.size(); i++) g[i] = f[i] * buf, buf *= a;\n  for (int i =\
    \ 1; i < (int)g.size(); i++) g[i] += g[i - 1];\n  mint c = 0, buf2 = 1;\n  for\
    \ (int i = 0; i <= K; i++) c += C.C(K + 1, i) * buf2 * g[K - i], buf2 *= -a;\n\
    \  c /= (-a + 1).pow(K + 1);\n  mint buf3 = 1, ia = a.inverse();\n  for (int i\
    \ = 0; i < (int)g.size(); i++) g[i] = (g[i] - c) * buf3, buf3 *= ia;\n  mint tn\
    \ = lagrange_interpolation(g, n - 1, C);\n  return tn * a.pow(n - 1) + c;\n}\n\
    \n// given  : f(0)...f(k) (deg(f) = k), a\n// return : sum_{i=0...infty} a^i f(i)\n\
    template <typename mint>\nmint sum_of_exp_limit(const vector<mint>& f, mint a,\
    \ Binomial<mint>& C) {\n  if (a == mint(0)) return f[0];\n  int K = f.size() -\
    \ 1;\n  vector<mint> g(f.size());\n  mint buf = 1;\n  for (int i = 0; i < (int)g.size();\
    \ i++) g[i] = f[i] * buf, buf *= a;\n  for (int i = 1; i < (int)g.size(); i++)\
    \ g[i] += g[i - 1];\n  mint c = 0, buf2 = 1;\n  for (int i = 0; i <= K; i++) c\
    \ += C.C(K + 1, i) * buf2 * g[K - i], buf2 *= -a;\n  c /= (-a + 1).pow(K + 1);\n\
    \  return c;\n}\n\n// given  : p, n\n// return : (0^p, 1^p, ... , n^p)\ntemplate\
    \ <typename mint>\nvector<mint> exp_enamurate(int p, int n) {\n  vector<mint>\
    \ f(n + 1, mint(0));\n  if (!p) {\n    f[0] = 1;\n    return std::move(f);\n \
    \ }\n  f[1] = 1;\n  vector<bool> sieve(n + 1, false);\n  vector<int> ps;\n  for\
    \ (int i = 2; i <= n; i++) {\n    if (!sieve[i]) {\n      f[i] = mint(i).pow(p);\n\
    \      ps.push_back(i);\n    }\n    for (int j = 0; j < (int)ps.size() && i *\
    \ ps[j] <= n; j++) {\n      sieve[i * ps[j]] = 1;\n      f[i * ps[j]] = f[i] *\
    \ f[ps[j]];\n      if (i % ps[j] == 0) break;\n    }\n  }\n  return std::move(f);\n\
    }\n\n// given  : d, r, n\n// return : sum_{i=0...n-1} r^i i^d\ntemplate <typename\
    \ mint>\nmint sum_of_exp2(int d, mint r, long long n, Binomial<mint>& C) {\n \
    \ vector<mint> f = exp_enamurate<mint>(d, d);\n  return sum_of_exp(f, r, n, C);\n\
    }\n\n// given  : d, r\n// return : sum_{i=0...infty} r^i i^d\ntemplate <typename\
    \ mint>\nmint sum_of_exp_limit2(int d, mint r, Binomial<mint>& C) {\n  vector<mint>\
    \ f = exp_enamurate<mint>(d, d);\n  return sum_of_exp_limit(f, r, C);\n}\n\n/**\n\
    \ * @brief $\\sum_{i}a^i f(i)$\n * @docs docs/fps/sum-of-exponential-times-poly.md\n\
    \ */\n"
  code: "#pragma once\n\n#include \"../modulo/binomial.hpp\"\n\n// given  : f(0)...f(k)\
    \ (deg(f) = k), a, n\n// return : sum_{i=0...n-1} a^i f(i)\ntemplate <typename\
    \ mint>\nmint sum_of_exp(const vector<mint>& f, mint a, long long n,\n       \
    \         Binomial<mint>& C) {\n  if (n == 0) return mint(0);\n  if (a == mint(0))\
    \ return f[0];\n  if (a == mint(1)) {\n    vector<mint> g(f.size() + 1, mint(0));\n\
    \    for (int i = 1; i < (int)g.size(); i++) g[i] = g[i - 1] + f[i - 1];\n   \
    \ return lagrange_interpolation(g, n, C);\n  }\n  int K = f.size() - 1;\n  vector<mint>\
    \ g(f.size());\n  mint buf = 1;\n  for (int i = 0; i < (int)g.size(); i++) g[i]\
    \ = f[i] * buf, buf *= a;\n  for (int i = 1; i < (int)g.size(); i++) g[i] += g[i\
    \ - 1];\n  mint c = 0, buf2 = 1;\n  for (int i = 0; i <= K; i++) c += C.C(K +\
    \ 1, i) * buf2 * g[K - i], buf2 *= -a;\n  c /= (-a + 1).pow(K + 1);\n  mint buf3\
    \ = 1, ia = a.inverse();\n  for (int i = 0; i < (int)g.size(); i++) g[i] = (g[i]\
    \ - c) * buf3, buf3 *= ia;\n  mint tn = lagrange_interpolation(g, n - 1, C);\n\
    \  return tn * a.pow(n - 1) + c;\n}\n\n// given  : f(0)...f(k) (deg(f) = k), a\n\
    // return : sum_{i=0...infty} a^i f(i)\ntemplate <typename mint>\nmint sum_of_exp_limit(const\
    \ vector<mint>& f, mint a, Binomial<mint>& C) {\n  if (a == mint(0)) return f[0];\n\
    \  int K = f.size() - 1;\n  vector<mint> g(f.size());\n  mint buf = 1;\n  for\
    \ (int i = 0; i < (int)g.size(); i++) g[i] = f[i] * buf, buf *= a;\n  for (int\
    \ i = 1; i < (int)g.size(); i++) g[i] += g[i - 1];\n  mint c = 0, buf2 = 1;\n\
    \  for (int i = 0; i <= K; i++) c += C.C(K + 1, i) * buf2 * g[K - i], buf2 *=\
    \ -a;\n  c /= (-a + 1).pow(K + 1);\n  return c;\n}\n\n// given  : p, n\n// return\
    \ : (0^p, 1^p, ... , n^p)\ntemplate <typename mint>\nvector<mint> exp_enamurate(int\
    \ p, int n) {\n  vector<mint> f(n + 1, mint(0));\n  if (!p) {\n    f[0] = 1;\n\
    \    return std::move(f);\n  }\n  f[1] = 1;\n  vector<bool> sieve(n + 1, false);\n\
    \  vector<int> ps;\n  for (int i = 2; i <= n; i++) {\n    if (!sieve[i]) {\n \
    \     f[i] = mint(i).pow(p);\n      ps.push_back(i);\n    }\n    for (int j =\
    \ 0; j < (int)ps.size() && i * ps[j] <= n; j++) {\n      sieve[i * ps[j]] = 1;\n\
    \      f[i * ps[j]] = f[i] * f[ps[j]];\n      if (i % ps[j] == 0) break;\n   \
    \ }\n  }\n  return std::move(f);\n}\n\n// given  : d, r, n\n// return : sum_{i=0...n-1}\
    \ r^i i^d\ntemplate <typename mint>\nmint sum_of_exp2(int d, mint r, long long\
    \ n, Binomial<mint>& C) {\n  vector<mint> f = exp_enamurate<mint>(d, d);\n  return\
    \ sum_of_exp(f, r, n, C);\n}\n\n// given  : d, r\n// return : sum_{i=0...infty}\
    \ r^i i^d\ntemplate <typename mint>\nmint sum_of_exp_limit2(int d, mint r, Binomial<mint>&\
    \ C) {\n  vector<mint> f = exp_enamurate<mint>(d, d);\n  return sum_of_exp_limit(f,\
    \ r, C);\n}\n\n/**\n * @brief $\\sum_{i}a^i f(i)$\n * @docs docs/fps/sum-of-exponential-times-poly.md\n\
    \ */\n"
  dependsOn:
  - modulo/binomial.hpp
  isVerificationFile: false
  path: fps/sum-of-exponential-times-poly.hpp
  requiredBy: []
  timestamp: '2023-03-24 20:50:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
  - verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
documentation_of: fps/sum-of-exponential-times-poly.hpp
layout: document
redirect_from:
- /library/fps/sum-of-exponential-times-poly.hpp
- /library/fps/sum-of-exponential-times-poly.hpp.html
title: $\sum_{i}a^i f(i)$
---

## $\sum_{i}a^i f(i)$

#### 問題

$k$次多項式$f(n)$に$f(0),f(1),\ldots,f(k)$を代入したものが与えられる。$\sum_{0\leq i \lt n}f(i)a^i$を求めよ。

[出題例(codechef)](https://www.codechef.com/problems/QPOLYSUM)

[参考文献(Min氏のブログ)](https://min-25.hatenablog.com/entry/2015/04/24/031413)

#### 概要

この問題は$\mathrm{mod}$を素数としたとき計算量$\mathrm{O}(N + \log \mathrm{mod})$で解くことが出来る。

以下の説明では、$f(t)$が$k$次の多項式であるとき、$f(t)$の母関数は$\frac{F(x)}{(1-x)^{k+1}}$と表せる事実を利用する。

(証明はニュートン基底$n_i(t)=t(t-1)\cdots(t-i+1)$の母関数が$\frac{i!x^i}{(1-x)^{i+1}}$と表されることが帰納的に示せることと、$f(t)$は$n_0(t)\ldots n_k(t)$の線形和で表せることから従う。)

数列$f(0)a^0, f(1)a^1, \ldots$の母関数は$k$次以下の多項式$G(x)$を用いて$\frac{G(x)}{(1-ax)^{k+1}}$と表せる。この時、求めたいものは

$$[x^{n-1}]\left(\frac{1}{1-x}\cdot \frac{G(x)}{(1-ax)^{k+1}}\right)$$

となる。上の式は定数$c$と$k$次以下の多項式$S(x)$を用いて

$$\frac{G(x)}{(1-x)(1-ax)^{k+1}}=\frac{c}{1-x}+\frac{S(x)}{(1-ax)^{k+1}}$$

と変形できるので、解は$k$次以下の多項式$t(n)$を用いて$c+a^nt(n)$と表せることがわかる。

次に$c$を具体的に求める。$c,G,S$の間には

$$G(x)=c(1-ax)^{k+1}+S(x)(1-x)$$

が成り立つ。多項式なので両辺に$x=1$を代入してもよく、

$$G(1)=c(1-a)^{k+1}$$

を得るので$G(1)$を求めればよい。$G(1)$は

$$G(x) = \left((1-ax)^{k+1}\sum_{i=0}^k f(i)(ax)^i \mod  x^{k+1}\right)$$

の右辺を累積和と階乗の前計算を使って$\mathrm{O}(k)$で計算できる。

$c$が計算できたので、あとは多項式補間を使えば答えが求まる。具体的には、

$$t(i) = a^{-n}\cdot\left(-c + \sum_{j=0}^i f(i)a^i \right)$$

とおいて$t(0),t(1)\ldots t(k)$を計算した後、ラグランジュ補間で$t(n-1)$を$\mathrm{O}(k)$で計算すればよい。

(注：この解法では$a$と$1-a$の逆元が必要なため、$a=0,a=1$の時は場合分けして別に実装する。)
