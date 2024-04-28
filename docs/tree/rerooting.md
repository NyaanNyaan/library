## 全方位木DP

#### テンプレート

```
// 「T : 根が virtual である根付き木」に対応する情報を管理する
using T = ;
// 空の状態に対応する情報
T leaf = ;
// T 同士をマージ
auto f1 = [&](T x, T y) -> T {
  
};
// T の根に頂点 c および辺 c-p を追加する (p は virtual)
auto f2 = [&](T x, int c, int p) -> T {
  
};
Rerooting<T, decltype(g), decltype(f1), decltype(f2)> dp(g, f1, f2, leaf);
```


