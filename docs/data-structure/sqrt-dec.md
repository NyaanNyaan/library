## 平方分割

要素数$N$の列を$\mathrm{O}(\sqrt{N})$個のバケットに分割して管理することで列上のクエリを高速に答えるアルゴリズムを平方分割と呼ぶ。

セグメント木にない特長として、バケット上に重たいデータ構造を乗せることが出来るという点がある。例えば次の二つのクエリに答える問題を考える。

- `add(l,r,x)` : $[a_l,a_r)$に$x$を足す
- `count[l,r,x)` : $[a_l,a_r)$内にある$x$の個数を数える
- $1 \leq l < r \leq N=10^5,$クエリ数$Q=10^5,a_i \leq 10^9, x \leq 10^9$

この問題にセグメント木を適用するとノード上に大量のhashmapを乗せることになり計算量が悪化するが、平方分割ならばhashmapの空間計算量が$\mathrm{O}(N)$で抑えられるため$\mathrm{O}((N+Q)\sqrt{N})$で解くことが出来る。(range addは適切に遅延評価すればよい。)

#### 使い方

次のようなblockを作成して本体に乗せると上手く動く。

```cpp=
struct block {
  // S 作用素の型 T 要素の型
  using S = ;
  using T = ;

  int i;

  block() {}

  // i ... 何個目のブロックか
  // i * B + j ... (jをブロック内のidxとして)全体でのidx
  int idx(int j) const { return i * B + j; }
  
  // 変数とブロックの初期化を忘れない！
  void init(int _) { 
    i = _; 
  }

  void build() {

  }

  void update_all(S x) {

  }

  void update_part(int l, int r, S x) { 
    
    build(); 
  }

  T query_all() {

  }

  T query_part(int l, int r) {

  }
};
```