## fps-三角関数

$N$次の形式的冪級数 $f(x)$ に対して $g(x) \equiv \cos(f(x)), h(x) \equiv \sin(f(x)) \mod x^N$ を満たす $g(x)$ を $\mathrm{O}(N \log N)$ で計算するライブラリ。

#### 概要

$g \equiv \cos f, h \equiv \sin f \pmod{x^n}$ を求めたい。  
これはオイラーの公式 $e^{if}=\cos f+i\sin f$ を利用すると $\mathrm{exp}(f)$ と同様にニュートン法で求まる。(詳細は割愛する。)

#### 使い方

- `circular(fre, fim, deg)` : $Re[f]=fre,Im[f]=fim$ である FPS $f$ について $\cos f,\sin f$ を $\deg$ 次の項まで求める。
