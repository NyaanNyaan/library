## 全方位木DP

#### テンプレート

```
using T = ;
// identify element of f1, and answer of leaf
T I = ;

// merge value of child node
auto f1 = [&](T x, T y) -> T {

};

// return value from child node to parent node
auto f2 = [&](T x, int chd, int par) -> T {

};

Rerooting<T, decltype(g), decltype(f1), decltype(f2)> dp(g, f1, f2, I);
```


