## 半環ライブラリ

#### 概要

半環(semiring, rig)とは集合$R$と二つの二項演算(加法$+$と乗法$\cdot$)からなる代数的構造である。$R,+,\cdot$は以下の関係を満たしている。

- $(R, +)$は$0$を単位元とする可換モノイドをなす
- $(R, \cdot)$は$1$を単位元とするモノイドをなす
- $+,\cdot$に対して分配法則が成り立つ
- $\forall r\in R$を$0$倍すると$0$になる

特にmax-plus半環/min-plus半環はトロピカル半環と呼ばれていて、グラフ上の最短経路の計算などに利用される。

#### テンプレート

- `U`: 集合$R$
- `add`: 二項演算$(R,+)$
- `mul`: 二項演算$(R,\cdot)$
- `i0()`: 単位元$0$
- `i1()`: 単位元$1$

```
// max-plus semiring
/**
using U = long long;
U add(U a, U b) { return max(a, b); }
U mul(U a, U b) { return a + b; }
U i0() { return -infLL; }
U i1() { return 0; }
//*/

// min-plus semiring
/**
using U = long long;
U add(U a, U b) { return min(a, b); }
U mul(U a, U b) { return a + b; }
U i0() { return infLL; }
U i1() { return 0; }
//*/

// max(x + a, b)
// verify: DDCC2020-final-b
/**
using U = pair<long long, long long>;
U add(U a, U b) {
  long long f = max(a.first, b.first);
  long long g = max(a.second, b.second);
  return U(f, g);
}
U mul(U a, U b) {
  long long f = a.first + b.first;
  long long g = max(a.second + b.first, b.second);
  return U(f, g);
}
U i0() { return U(-infLL, -infLL); }
U i1() { return U(0, -infLL); }
//*/

// xor-and semiring
/**
using U = unsigned long long;
U add(U a, U b) { return a ^ b; }
U mul(U a, U b) { return a & b; }
U i0() { return 0; }
U i1() { return U(-1); }
//*/
```