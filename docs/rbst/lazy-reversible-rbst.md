## 遅延伝搬反転可能乱択平衡二分木

強すぎてAtCoderRated出禁になった最強データ構造。

#### 使い方

- `build(v)`: vを初期値とした新たな木を作る。
- `merge(l, r)`: lとrをマージして新たに出来た木のポインタを返す。
- `split(t, k)`: tを$[0,k)$と$[k, \lvert t\lvert)$の二つの木に分割する。
- `insert(t, k, args...)`: tのk番目に`Node(args...)`を挿入する。
- `erase(t, k)`: tのk番目のノードを削除する。
- `fold(t, a, b)`: $[a,b)$の和を返す。
- `apply(t, a, b, e)`: $[a, b)$に作用素eを作用させる。
- `reverse(t, a, b)`:$[a, b)$を反転する。
- `toggle(t)`: tを反転する。
- `size(t)`: tの大きさを返す。
- `make_tree()`: 空の木を返す。

