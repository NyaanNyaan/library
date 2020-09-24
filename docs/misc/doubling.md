## Binary Lifting(ダブリング)

辺の重みがモノイドであり、各頂点の出次数が高々1のグラフが存在したとき、$i$を始点として$t$回グラフを移動したときの終点$j$とパス$(i,j)$の重みの和を前計算$\mathrm{O}(N \log \max(t))$、クエリ$\mathrm{O}(\log t)$計算するライブラリ。

TODO: 書く　[わかりやすい解説](https://ei1333.github.io/luzhiled/snippets/memo/doubling.html)

#### 使い方

- `template<typename T> BinaryLifting(k, lim, I)`　$\cdots$　コンストラクタ。
  - `T`は`operator +`が定義されているモノイド
  - `k`はグラフの頂点数
  - `lim`は移動回数の最大値
  - `I`はモノイドの単位元
- `set_next(k, nxt, t)`　$\cdots$　$k$から$nxt$に重み$t$の辺を貼る。
- `build()` $\cdots$ データ構造を構築する。
- `query(i, t)` $\cdots$ $i$を始点として$t$回移動したときの(遷移先,始点と終点の間のパスの重みの和)を返す。遷移先が存在しない場合は($-1$, 最後に到達した点までのパスの重みの和)を返す。
