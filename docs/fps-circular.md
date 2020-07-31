## fps-三角関数


$g \equiv \cos f, h \equiv \sin f \mod x^n$を求めたい。

これはオイラーの公式$e^{if}=\cos f+i\sin f$を利用すると$exp$と同様の方法で求まる。

なお、計算は実部と虚部に分けて行う必要がある。例えば掛け算の時は4回乗算して適切に足し合わせる。

#### 実装

- `circular(fre, fim, deg)` : $Re[f]=fre,Im[f]=fim$であるFPS $f$について$\cos f,\sin f$を求める。
