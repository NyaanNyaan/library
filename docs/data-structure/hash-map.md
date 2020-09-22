## Hash Map

ハッシュマップとは、$\mathrm{O}(1)$で一点更新・一点取得を行うことのできるデータ構造である。

#### 概要

ハッシュマップとは、ハッシュをkeyとして値を管理することで、keyの値の範囲によらず一点取得・更新が$\mathrm{O}(1)$で行えるデータ構造を実現したものである。

同様のデータ構造にC++の`unordered_map`があるが、`unordered_map`はハッシュ衝突の脆弱性があり、CodeForcesのようなHackの存在するコンテストで無造作に使用するのは危険である。([参考](https://kimiyuki.net/blog/2017/03/08/unordered-map-hash-collision/))

このライブラリでは最低限の機能を持ったHash Mapを実装している。実装には大きく分けて連鎖法と開番地法があるが、開番地法の方がメモリの消費が少なく定数倍もよい。yosupo judgeの提出は以下の通りで、入出力の時間も考慮すると開番地法は`unordered_map`のおよそ4倍程度の速さで動作しているとわかる。

- [自作Hash Map(開番地法)](https://judge.yosupo.jp/submission/23703) 100ms
- [自作Hash Map(連鎖法)](https://judge.yosupo.jp/submission/23726)　146ms
- [ハッシュ衝突の対策をしたunordered_map](https://judge.yosupo.jp/submission/23582) 263ms
- (入出力にかかる時間は最大50ms程度と考えられる。)
