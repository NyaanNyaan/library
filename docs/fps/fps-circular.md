## fps-三角関数

$N$次の形式的冪級数$f(x)$に対して$g(x) \equiv \cos(f(x)) , h(x) \equiv \sin(f(x)) \mod x^N$を満たす$g(x)$を$\mathrm{O}(N \log N)$で計算するライブラリ。

#### 概要

$g \equiv \cos f, h \equiv \sin f \mod x^n$を求めたい。

これはオイラーの公式$e^{if}=\cos f+i\sin f$を利用すると$\mathrm{exp}$と同様の方法で求まる。

なお、計算は実部と虚部に分けて行う必要がある。例えば掛け算の時は4回乗算して適切に足し合わせる。

#### 使い方

- `circular(fre, fim, deg)` : $Re[f]=fre,Im[f]=fim$であるFPS $f$について$\cos f,\sin f$をdeg次の項まで求める。
