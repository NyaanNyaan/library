## 遅延伝搬反転可能乱択平衡二分木

強すぎてAtCoderRated出禁になった最強データ構造・平衡二分木のRBSTによる実装。

#### 使い方

計算量は木の大きさを$N$として表記している。

- `build(v)`: 列vを初期値とした新たな木を作る。$\mathrm{O}(N)$
- `merge(l, r)`: lとrをマージして新たに出来た木のポインタを返す。$\mathrm{O}(\log N)$
- `split(t, k)`: tを$[0,k)$と$[k, \lvert t\lvert)$の二つの木に分割する。$\mathrm{O}(\log N)$
- `insert(t, k, args...)`: tのk番目に`Node(args...)`を挿入する。$\mathrm{O}(\log N)$
- `erase(t, k)`: tのk番目のノードを削除する。$\mathrm{O}(\log N)$
- `fold(t, a, b)`: $[a,b)$の和を返す。$\mathrm{O}(\log N)$
- `apply(t, a, b, e)`: $[a, b)$に作用素eを作用させる。$\mathrm{O}(\log N)$
- `reverse(t, a, b)`:$[a, b)$を反転する。$\mathrm{O}(\log N)$
- `toggle(t)`: tを反転する。$\mathrm{O}(1)$
- `size(t)`: tの大きさを返す。$\mathrm{O}(1)$
- `make_tree()`: 空の木を返す。$\mathrm{O}(1)$
