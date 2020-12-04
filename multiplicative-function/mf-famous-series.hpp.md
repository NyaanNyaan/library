---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: multiplicative-function/divisor-multiple-transform.hpp
    title: "\u500D\u6570\u5909\u63DB\u30FB\u7D04\u6570\u5909\u63DB"
  - icon: ':question:'
    path: prime/prime-enumerate.hpp
    title: prime/prime-enumerate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/multiplicative-function/mf-famous-series.md
    document_title: "\u6709\u540D\u306A\u4E57\u6CD5\u7684\u95A2\u6570"
    links: []
  bundledCode: "#line 2 \"multiplicative-function/mf-famous-series.hpp\"\n\n\n\n#line\
    \ 2 \"multiplicative-function/divisor-multiple-transform.hpp\"\n\n\n\n#line 2\
    \ \"prime/prime-enumerate.hpp\"\n\n// Prime Sieve {2, 3, 5, 7, 11, 13, 17, ...}\n\
    vector<int> prime_enumerate(int N) {\n  vector<bool> sieve(N / 3 + 1, 1);\n  for\
    \ (int p = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn; p += d = 6 - d, i++) {\n\
    \    if (!sieve[i]) continue;\n    for (int q = p * p / 3, r = d * p / 3 + (d\
    \ * p % 3 == 2), s = 2 * p,\n             qe = sieve.size();\n         q < qe;\
    \ q += r = s - r)\n      sieve[q] = 0;\n  }\n  vector<int> ret{2, 3};\n  for (int\
    \ p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)\n    if (sieve[i]) ret.push_back(p);\n\
    \  while (!ret.empty() && ret.back() > N) ret.pop_back();\n  return ret;\n}\n\
    #line 6 \"multiplicative-function/divisor-multiple-transform.hpp\"\n\nstruct divisor_transform\
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
    \n * @docs docs/multiplicative-function/divisor-multiple-transform.md\n */\n#line\
    \ 6 \"multiplicative-function/mf-famous-series.hpp\"\n\ntemplate <typename T>\n\
    static constexpr vector<T> mobius_function(int N) {\n  vector<T> a(N + 1, 0);\n\
    \  a[1] = 1;\n  divisor_transform::mobius_transform(a);\n  return a;\n}\n\n/**\n\
    \ * @brief \u6709\u540D\u306A\u4E57\u6CD5\u7684\u95A2\u6570\n * @docs docs/multiplicative-function/mf-famous-series.md\n\
    \ */\n"
  code: "#pragma once\n\n\n\n#include \"divisor-multiple-transform.hpp\"\n\ntemplate\
    \ <typename T>\nstatic constexpr vector<T> mobius_function(int N) {\n  vector<T>\
    \ a(N + 1, 0);\n  a[1] = 1;\n  divisor_transform::mobius_transform(a);\n  return\
    \ a;\n}\n\n/**\n * @brief \u6709\u540D\u306A\u4E57\u6CD5\u7684\u95A2\u6570\n *\
    \ @docs docs/multiplicative-function/mf-famous-series.md\n */\n"
  dependsOn:
  - multiplicative-function/divisor-multiple-transform.hpp
  - prime/prime-enumerate.hpp
  isVerificationFile: false
  path: multiplicative-function/mf-famous-series.hpp
  requiredBy: []
  timestamp: '2020-12-05 08:35:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: multiplicative-function/mf-famous-series.hpp
layout: document
redirect_from:
- /library/multiplicative-function/mf-famous-series.hpp
- /library/multiplicative-function/mf-famous-series.hpp.html
title: "\u6709\u540D\u306A\u4E57\u6CD5\u7684\u95A2\u6570"
---
## 有名な乗法的関数

#### メビウス関数　$\mu(n)$

メビウス関数に関する説明は[ここ](https://nyaannyaan.github.io/library/multiplicative-function/divisor-multiple-transform.hpp)に詳しい。

競技プログラミングにおいてのメビウス関数の利用法は(雑に説明すると)包除原理の$(-1)^k$と似た使い方をすることが多い。実際に具体例を見てみる。

##### 例題1

- $N$の約数$n$に対して$g(n)=\sum_{d\mid n}f(d)$と$\mu(n)$がわかっているとする。この時$f(N)$を$\mathrm{O}(\sigma(N))$で計算せよ。

約数系包除を使えば$\mathrm{O}(\sigma(N)^2)$で解けるがより高速な解法を考えたい。
まずは$\mu(n)$や反転公式を使わずに包除原理で考察してみる。

具体的な$N$についていくつか実験してみると、

$$f(16)=g(16)-g(8)$$

$$f(12)=g(12)-g(6)-g(4)+g(2)$$

$$f(30)=g(30)-g(15)-g(10)-g(6)+g(5)+g(3)+g(2)-g(1)$$

のようになる。

(TODO: 疲れたので飛ばす。いつの日かここを真面目に書く 書きたいこと：包除の式が立つけどこれはメビウス関数+反転公式と一緒だねという話 [関連:tsutajさんの非常にわかりやすい包除PDF](https://compro.tsutaj.com//archive/181015_incexc.pdf) )

##### 例題2：[Cube-loving Numbers　(HackerRank)](https://www.hackerrank.com/contests/university-codesprint-5/challenges)

- $N$が与えられるので、「自然数$a>1,b\geq 1$を用いて$a^3\times b$と表せる$N$以下の自然数の個数」を$\mathrm{O}(\sqrt[3]{N})$で計算せよ。

$1\leq n\leq N$において自然数$a,b$を用いて$n=a^3\times b$と表せる$n$の個数$g(a)$は$g(a)=\lfloor\frac{N}{a^3}\rfloor$と容易に表せるので、この式をうまく利用して答えを求めたい。(直感的には、$g(n)$は一つの自然数を複数回カウントする関数なのでメビウス変換したいという気持ちになる。)

対象を重複なく数え上げるために、自然数$n$に一対一対応する$(a,b)$を決定したい。具体的には、「$n=A^3\times B$を満たす自然数の組$(A,B)$の中で最も$B$が小さい組」を$n$に対応する組$(a,b)$とおく。そして、$f(a)$を「$(a,\frac{n}{a^3})$と対応している$N$以下の自然数$n$の個数」とおく。

$f$と$g$の関係式を得るために、$g(a)$でカウントされている自然数$n$が$f$のどこでカウントされているかを考える。$n=a^3\times b$としたとき、$b$に一対一対応する整数の組を$(c,d)$とおくと、$n$に対応する組は$(ca,d)$であるから$f(ca)$で数え上げられていることが分かる。逆に$f(ca)$で数え上げられた$n$が$g(a)$で数えられていることも示せる。よって$f(a)$と$g(a)$の間には

$$g(a)=\sum_{a\mid m}f(m) \leftrightarrow f(a)=\sum_{a\mid m}\mu\left(\frac{m}{a}\right)g(m)$$

という倍数変換の関係式が成り立つことがわかる。また、求める答えは$M=\lfloor\sqrt[3]{N}\rfloor$と置いたとき$\sum_{a=2}^Mf(a)$である。
($M\lt a$のとき$f(a)=g(a)=0$である事実を利用している。)

よって倍数メビウス変換を用いれば$\mathrm{O}(M\log \log M)$で計算できることが示せたが、メビウス関数を用いることでさらなる高速化を図りたい。$\sum_{a=2}^Mf(a)$を$g(m)$の線形和に分解したときの$g(m)$の寄与を考察すると、

$$\sum_{a=2}^M f(a)=\sum_{2\leq a\leq M, a\mid m} \left( \mu\left(\frac{m}{a}\right)g(m)\right)$$

$$=\sum_{2\leq m\leq M} g(m)\left(\sum_{a\mid m,a\neq 1}\mu\left(\frac{m}{a}\right)\right)$$

$$=\sum_{2\leq m\leq M} g(m)(-\mu(m)+\sum_{a\mid m}\mu(a))=-\sum_{2\leq m\leq M} g(m)\mu(m)$$

と非常にきれいな式になる。$\mu(m)$および$g(m)$は線形で列挙できるため、求める答えも線形で列挙できる。寄ってこの問題を$\mathrm{O}(\sqrt[3]{N})$で解くことが出来た。

TODO: 他の関数を書く
