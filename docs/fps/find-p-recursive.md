## P-recursiveの高速計算

P-recursiveの第$k$項を$\mathrm{O}(\sqrt{k} \log k)$で計算出来たり出来なかったりするライブラリ。

#### 使い方

- `find_p_recursive(a, d)`

十分長い数列$a$および次数$d$が与えられたとき、

$$a_{i+n} f_n(i) + \ldots + a_{i}f_0(i) \equiv 0 \pmod {p} $$

を満たす$d$次多項式の列$f_n(i),\ldots,f_1(i),f_0(i)$を返すライブラリ。他のライブラリとの関係上、列が降順($(f_n,\ldots,f_1,f_0)$の順番)になっているのに注意。

適切に立式すれば一次連立方程式に帰着するのでガウスの掃き出し法を使えば求まる。計算量は$\mathrm{O}((dn)^3)$程度。

- `kth_term_of_p_recursive(a, k, d)`

十分長い数列$a$および次数$d$、整数$k$が与えられたとき、$a_k$を返すライブラリ。

計算量は数列が$n$項間漸化式で表せるときに$\mathrm{O}(n^2 \sqrt{kd} (\log p + \log kd))$程度。

アルゴリズム初出の日本語記事は削除済みだが、[CF 1479E editorial](https://codeforces.com/blog/entry/87598)に関連するアルゴリズムの解説がある。

- `kth_term_of_p_recursive(a, k)`

エスパー用の関数。

##### verification codeの出力(一部加筆)

P-recursiveの例も兼ねて貼る。

```
Constant Function
a_{k+1} = a_{k}
Identity Function (a_i = i + 1)
(k + 1)a_{k+1} = (k + 2)a_{k}
Factorial
a_{k+1} = (k + 1)a_{k}
Inversion of Factorial
(k + 1)a_{k+1} = a_{k}
Binomial (a_i = binom(i + 3, 3))
(k + 1)a_{k+1} = (k + 4)a_{k}
Montmort Number
a_{k+2} = (k + 1)a_{k+1} + (k + 1)a_{k}
Catalan Number
(k + 2)a_{k+1} = (4k + 2)a_{k}
Motzkin Number
(k + 4)a_{k+2} = (2k + 5)a_{k+1} + (3k + 3)a_{k}
Schroder number
(k + 3)a_{k+2} = (6k + 9)a_{k+1} + (998244352k + 0)a_{k}
```

#### 注意点

バグりやすい上に数列によっては正しい値を求められない。

- $d$に正しい値を指定しないと、バグる(誤った関係式を導出する)
- $i + k \leq n$について$f_{n}(i) \not \equiv 0$が必要。そうでない場合、バグる(そもそも漸化式から正しい値を求めることが不可能？)

また、P-recursiveで表せない列の第$k$項は当然求められない。

- 例えばBell Numberや$S(n,k)$は二項係数の和で表せるのでP-recursiveのような気がしてくるが(本当？)、実際は違うので高速計算できない(と思う)。