## DSU on Tree

DSU on Treeとは、全ての部分木に対するクエリを高速に処理するアルゴリズムである。

#### 使い方&テンプレート

ライブラリと一緒に下のテンプレートを貼って使用する。

```
  // reflect data of node i
  auto update = [&](int i) {

  };
  // answer queries of subtree i
  auto query = [&](int i) {

  };
  // below two function are called if all data must be deleted
  // delete data of node i (if necesarry)
  auto clear = [&](int i) {

  };
  // delete data related to all (if necesarry)
  auto reset = [&]() {

  };
  DSUonTree<decltype(g)> dsu(g, 0);
  dsu.run(update, query, clear, reset);
```

#### 概要

前に手元のメモに書いた落書きを貼る。


##### 参考にしたサイト
- [kimiyukiさんの解説。非常にわかりやすい](https://wiki.kimiyuki.net/DSU%20on%20tree)
- [CodeForcesの記事](https://codeforces.com/blog/entry/44351)
- [謎の記事](http://codingwithrajarshi.blogspot.com/2018/06/small-to-large.html)


##### 説明

Python風コードによるアルゴリズムの動作の説明を以下に示す。

```python=
# c ... current node
# p ... parent node
# keep ... condition variable of reserving data

def dsu(c, p, keep):
    # light edge -> run dfs and clear data
    for d in 'light edge of c':
        dsu(d, c, false)
    
    # heavy edge -> run dfs and reserve data
    dsu('heavy edge of c', c, true)
    
    # light edge -> reserve data
    for d in 'light edge of c':
        for n in 'subtree of d':
            add(n)
     
    # current node -> reserve data
    add(c)

    # answer queries related to subtree of current node
    query(c)

    # if keep is false, clear all data
    if keep = false:
          reset()
    return
```

##### 計算量
- add()を呼び出す回数を考える
- 各ノードがaddされる回数を考えるとそれぞれ$\rm O(\log N)$回
    - 全てのノードがdsu関数を1回ずつ実行
    - 関数内ではlight edgeでつながる子孫 + 自分をaddしている
    - よってノードがaddされる回数は$($根とのパスに存在するlight edgeの本数 + $1)$回
    - 重軽木の深さは$\rm O(\log N)$なので回数も同じ
- eraseされる回数はaddされる回数と同じ
- 以上より、全体の計算量はadd,eraseを$\rm O(1)$として$\rm O(N \log N)$

##### DSU on TreeとWeighted Union Heuristic(マージテク)の違い

- Weighted Union Heuristic…競プロで広く一般に使われるテクニック
- 大きい部分木を小さい部分木にマージすることで$\rm{O}(N \log N)$
- 例えば下のような問題

> 頂点$1$を根とする$N$頂点の根付き木がある。
> 木の頂点には数字$(1 \leq c \leq N)$が書かれている。
> 次のオフラインクエリを$Q$個処理せよ。
> $n\ x \ldots$ 頂点$n$を根とする部分木の全ての頂点のうち$x$の書かれた頂点の個数を出力。

- これはマージテクだと$\rm{O}(N \log N)$で解ける(実装も簡単だが、hash tableが必要)
    - DSU on Treeだと配列のみで$\rm O(N \log N)$が達成できる
    - [類題](https://codeforces.com/contest/600/problem/E)

```cpp=
int a[N]; // number of nodes
using M = unordered_map<int, int>;
M dp[N];

void merge(M &a, M &b) {
    if (a.size() < b.size()) swap(a, b);
    for (auto &x : b) a[x.first] += x.second;
}

void dfs(int c, int p) {
    dp[c][a[c]] += 1;
    for (auto &d : g[c]){
        if (d == p) continue;
        dfs(d, c);
        merge(dp[c], dp[d]);
    }
    // answer queries of subtree c
}
```

- ではこの問題は？

> 頂点$1$を根とする$N$頂点の根付き木がある。
> 木の頂点には数字$(1 \leq c \leq N)$が書かれている。
> 次のクエリを$Q$個処理せよ。
> $n\ x\ \ldots$ 頂点$n$を根とする部分木の全ての頂点のうち$x$<strong>以下</strong>の書かれた頂点個数を出力。
> 制約：$1 \leq N = Q \leq 200000$
- これをマージテクで解こうとすると...?
    1. hash mapをマージ
        + クエリが$\rm{O}($要素数$)$になり壊れる
    2. vectorをマージ(クエリを二分探索で処理)
        + マージが$\rm{O}($小さい方$)$にならない
    3. Segment Treeをノードごとに構築、一方hash mapでも頂点を管理
        hash mapをマージする時に小さい方のデータを大きい方のセグ木に反映
        + 一見うまくいきそうだが… 
        + セグ木の構築にノードごとに$\rm{O}(N)$かかるので最悪$\rm O(N^2)$
    4. 動的Segment Treeや平衡二分木をマージ
        + 構築 ノードごとに$\rm{O}(1)$か$\rm{O}(\log N)$
        + マージ 全体で$\rm{O}(N \log ^ 2 N)$
        + クエリ クエリごとに$\rm{O}(\log N)$
        + よって高速に動作する
        + ただし、最悪ケースで$\rm{O}(N)$個のセグ木が同時に構築される
    5. Heavy Light Decomposition + 4.の解法
        + heavyな部分木から動的セグ木を参照渡しでもらう
        + 同時に構築される動的セグ木の数は$\rm{O}(\log N)$個となり空間計算量が改善された

- 一方、DSU on Treeだとセグメント木1本で解ける(計算量は$\rm O(N \log ^2 N)$)
    - なおこの問題はEuler Tour + 領域木で$\rm{O}(N \log N)$と高速かつオンラインで解ける
    - 動的木のマージも実は工夫すると全体で$\rm O(N \log N)$らしい [(参考)](https://codeforces.com/blog/entry/49446)のでマージテク+永続セグ木でも$\rm O(N \log N)$か

- DSU on Treeのメリット
    + データ構造が一つでいい
        + メモリ確保の回数や空間計算量少ない分、高速なことが多いらしい(要出典)
    + ライブラリ化できる
        + 実装の手間が省けてありがたい

- DSU on Treeのデメリット
    + 値の追加だけでなく削除ができる必要がある
    + 削除が面倒な例: priority_queue
        + 初期状態に戻せば問題ないので、例えば
            `auto clear=[&](){};`
            `auto reset=[&](){Q.swap(priority_queue<int>());};`
            のようにすればよいが、1個のデータ構造で出来るというメリットが失われている
- 疑問：DSU on Treeで解けてマージテクで解けない問題(あるいはその逆)は存在するのか？
    - 存在しない気がする
    - それはそれとしてDSU on Treeの方が(ライブラリがあれば)簡単に書けそう
    - 親に返す時に操作が必要な場合は上記のライブラリでは対応できない？
