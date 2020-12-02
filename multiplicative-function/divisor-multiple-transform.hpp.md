---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: prime/prime-enumerate.hpp
    title: prime/prime-enumerate.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: multiplicative-function/gcd-convolution.hpp
    title: "GCD\u7573\u307F\u8FBC\u307F"
  - icon: ':warning:'
    path: multiplicative-function/mf-famous-series.hpp
    title: multiplicative-function/mf-famous-series.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/multiplicative-function.test.cpp
    title: verify/verify-unit-test/multiplicative-function.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0125.test.cpp
    title: verify/verify-yuki/yuki-0125.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0886.test.cpp
    title: verify/verify-yuki/yuki-0886.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0890.test.cpp
    title: verify/verify-yuki/yuki-0890.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0896.test.cpp
    title: verify/verify-yuki/yuki-0896.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/multiplicative-function/divisor-multiple-transform.md
    document_title: "\u500D\u6570\u5909\u63DB\u30FB\u7D04\u6570\u5909\u63DB"
    links: []
  bundledCode: "#line 2 \"multiplicative-function/divisor-multiple-transform.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"prime/prime-enumerate.hpp\"\
    \nusing namespace std;\n\n// Prime Sieve {2, 3, 5, 7, 11, 13, 17, ...}\nvector<int>\
    \ prime_enumerate(int N) {\n  vector<bool> sieve(N / 3 + 1, 1);\n  for (int p\
    \ = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn; p += d = 6 - d, i++) {\n    if (!sieve[i])\
    \ continue;\n    for (int q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s =\
    \ 2 * p,\n             qe = sieve.size();\n         q < qe; q += r = s - r)\n\
    \      sieve[q] = 0;\n  }\n  vector<int> ret{2, 3};\n  for (int p = 5, d = 4,\
    \ i = 1; p <= N; p += d = 6 - d, i++)\n    if (sieve[i]) ret.push_back(p);\n \
    \ while (!ret.empty() && ret.back() > N) ret.pop_back();\n  return ret;\n}\n#line\
    \ 6 \"multiplicative-function/divisor-multiple-transform.hpp\"\n\nstruct divisor_transform\
    \ {\n  template <typename T>\n  static void zeta_transform(vector<T> &a) {\n \
    \   int N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n    for (auto\
    \ &p : sieve)\n      for (int k = 1; k * p <= N; ++k) a[k * p] += a[k];\n  }\n\
    \  template <typename T>\n  static void mobius_transform(T &a) {\n    int N =\
    \ a.size() - 1;\n    auto sieve = prime_enumerate(N);\n    for (auto &p : sieve)\n\
    \      for (int k = N / p; k > 0; --k) a[k * p] -= a[k];\n  }\n\n  template <typename\
    \ T>\n  static void zeta_transform(map<long long, T> &a) {\n    for (auto p =\
    \ rbegin(a); p != rend(a); p++)\n      for (auto &x : a) {\n        if (p->first\
    \ == x.first) break;\n        if (p->first % x.first == 0) p->second += x.second;\n\
    \      }\n  }\n  template <typename T>\n  static void mobius_transform(map<long\
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
    \n * @docs docs/multiplicative-function/divisor-multiple-transform.md\n */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../prime/prime-enumerate.hpp\"\n\nstruct divisor_transform {\n  template <typename\
    \ T>\n  static void zeta_transform(vector<T> &a) {\n    int N = a.size() - 1;\n\
    \    auto sieve = prime_enumerate(N);\n    for (auto &p : sieve)\n      for (int\
    \ k = 1; k * p <= N; ++k) a[k * p] += a[k];\n  }\n  template <typename T>\n  static\
    \ void mobius_transform(T &a) {\n    int N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n\
    \    for (auto &p : sieve)\n      for (int k = N / p; k > 0; --k) a[k * p] -=\
    \ a[k];\n  }\n\n  template <typename T>\n  static void zeta_transform(map<long\
    \ long, T> &a) {\n    for (auto p = rbegin(a); p != rend(a); p++)\n      for (auto\
    \ &x : a) {\n        if (p->first == x.first) break;\n        if (p->first % x.first\
    \ == 0) p->second += x.second;\n      }\n  }\n  template <typename T>\n  static\
    \ void mobius_transform(map<long long, T> &a) {\n    for (auto &x : a)\n     \
    \ for (auto p = rbegin(a); p != rend(a); p++) {\n        if (x.first == p->first)\
    \ break;\n        if (p->first % x.first == 0) p->second -= x.second;\n      }\n\
    \  }\n};\n\nstruct multiple_transform {\n  template <typename T>\n  static void\
    \ zeta_transform(vector<T> &a) {\n    int N = a.size() - 1;\n    auto sieve =\
    \ prime_enumerate(N);\n    for (auto &p : sieve)\n      for (int k = N / p; k\
    \ > 0; --k) a[k] += a[k * p];\n  }\n  template <typename T>\n  static void mobius_transform(vector<T>\
    \ &a) {\n    int N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n   \
    \ for (auto &p : sieve)\n      for (int k = 1; k * p <= N; ++k) a[k] -= a[k *\
    \ p];\n  }\n\n  template <typename T>\n  static void zeta_transform(map<long long,\
    \ T> &a) {\n    for (auto &x : a)\n      for (auto p = rbegin(a); p->first !=\
    \ x.first; p++)\n        if (p->first % x.first == 0) x.second += p->second;\n\
    \  }\n  template <typename T>\n  static void mobius_transform(map<long long, T>\
    \ &a) {\n    for (auto p1 = rbegin(a); p1 != rend(a); p1++)\n      for (auto p2\
    \ = rbegin(a); p2 != p1; p2++)\n        if (p2->first % p1->first == 0) p1->second\
    \ -= p2->second;\n  }\n};\n\n/**\n * @brief \u500D\u6570\u5909\u63DB\u30FB\u7D04\
    \u6570\u5909\u63DB\n * @docs docs/multiplicative-function/divisor-multiple-transform.md\n\
    \ */\n"
  dependsOn:
  - prime/prime-enumerate.hpp
  isVerificationFile: false
  path: multiplicative-function/divisor-multiple-transform.hpp
  requiredBy:
  - multiplicative-function/mf-famous-series.hpp
  - multiplicative-function/gcd-convolution.hpp
  timestamp: '2020-12-03 00:21:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/multiplicative-function.test.cpp
  - verify/verify-yuki/yuki-0886.test.cpp
  - verify/verify-yuki/yuki-0890.test.cpp
  - verify/verify-yuki/yuki-0896.test.cpp
  - verify/verify-yuki/yuki-0125.test.cpp
documentation_of: multiplicative-function/divisor-multiple-transform.hpp
layout: document
redirect_from:
- /library/multiplicative-function/divisor-multiple-transform.hpp
- /library/multiplicative-function/divisor-multiple-transform.hpp.html
title: "\u500D\u6570\u5909\u63DB\u30FB\u7D04\u6570\u5909\u63DB"
---
## 倍数変換/約数変換

(約数/倍数)(ゼータ/メビウス)変換を$\mathrm{O}(N\log \log N)$で行うライブラリ。

#### 概要

このライブラリに出てくる4種の変換を理解すると、約数系包除原理やBurnSideの補題が関係する問題をライブラリを使用して殴れる…かもしれない。

以下に簡潔に内容を解説する。

##### メビウス関数　$\mu(n)$

メビウス関数とは自然数$n$に対して次のように定義される関数である。

$$\mu(n)=\begin{cases}1 & (n=1)\\ 0 & (nが平方因子を持つ) \\ (-1)^k & (nがk個の素因数を持つ)\end{cases}$$

メビウス関数には以下の基本公式が成り立つ。(包除原理で証明できる。)

$$\sum_{d\mid n}\mu (d)=\begin{cases}1 & (n=1) \\ 0 & (n\neq 1)\end{cases}$$

また、メビウス関数が登場する基本的な公式としてメビウスの反転公式が挙げられる。

##### メビウスの反転公式

関数$f,g$が全ての正の整数$n$に対して
$$g(n) = \sum_{d\mid n}f(d)$$

を満たしているとする。上の式を言い換えると、$g(n)$は全ての$n$の約数$d$について$f(d)$を足し合わせたものである。競技プログラミングの文脈では「$g$は$f$の**約数ゼータ変換**である」としばしば表現される。(正式な呼称ではない。)

このとき$f$と$g$の間には次の関係式が成り立つ。(**メビウスの反転公式**)

$$f(n) = \sum_{d\mid n}\mu(d)g\left(\frac{n}{d}\right)=\sum_{d\mid n}\mu\left(\frac{n}{d}\right)g(d)$$

証明は[高校数学の美しい物語](https://mathtrain.jp/mobiusinversion)に詳しい。また、$g$から$f$への変換を**約数メビウス変換**と呼ぶ。

##### もう一つのゼータ/メビウス変換

集合関数に対して上位集合へのゼータ/メビウス変換と下位集合へのゼータ/メビウス変換が定義されるように、**倍数ゼータ変換/メビウス変換**を定義することが出来る。

関数$f,g$が全ての正の整数$n$に対して
$$g(n) = \sum_{n\mid m}f(m)$$

を満たしているとする。上の式を言い換えると、$g(n)$は全ての$n$の倍数$m$について$f(m)$を足し合わせたものである。競技プログラミングの文脈では「$g$は$f$の**倍数ゼータ変換**である」としばしば表現される。

このとき$f$と$g$の間には次の関係式が成り立つ。**(倍数メビウス変換)**

$$f(n) = \sum_{n\mid m}\mu\left(\frac{m}{n}\right)g(m)$$

#### バーンサイドの補題

TODO: 書く
(Burnsideの補題と同じ計算が倍数メビウス変換でもできますねという話を書きたかった　Burnsideの補題は前に頑張って理解したが全て忘却した、悲しいね)
(あと関係ない疑問だけどバーンサイドの補題は競プロでは「Polyaの定理」という名前で広まっている？)

関連問題：[yukicoder No.125 悪の花弁](https://yukicoder.me/problems/no/125)

#### アルゴリズムの解説および正当性

実際に変換を行うアルゴリズムはkazumaさんのブログ
が初出のようです。[参考](https://kazuma8128.hatenablog.com/entry/2018/07/29/231819)

$\mathrm{O}(N\log \log N)$の実装についてはnoshiさんが解説しています。[参考](https://noshi91.hatenablog.com/entry/2018/12/27/121649)

#### ライブラリの使い方

競技プログラミングで倍数・約数変換を使う場面は主に以下の二つが考えられる。

- (1) $f(i)\ (1\leq i\leq n)$が与えられた時に$g(j) \ (1\leq j\leq n)$を求める
- (2) $f(i)\ (i|n$または$n|i)$が与えられた時に$g(n)$を求める

以下のライブラリでは、(1)は`vector<T>`を、(2)は`map<ll, T>`を入力する仕様となっている。

##### 関数一覧

- `divisor_transform::zeta_transform(a)`: aを約数ゼータ変換する。
- `divisor_transform::mobius_transform(a)`: aを約数メビウス変換する。
- `multiple_transform::zeta_transform(a)`: aを倍数ゼータ変換する。
- `multiple_transform::mobius_transform(a)`: aを倍数メビウス変換する。

計算量は(1)が$\mathrm{O}(n\log \log n)$、(2)が$\mathrm{O}(\sigma(n)^2)$である。
