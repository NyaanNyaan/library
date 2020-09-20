## Hash Map

ハッシュマップとは、$\mathrm{O}(1)$で一点更新・一点取得を行うことのできるデータ構造である。

#### 概要

ハッシュマップとは、ハッシュをkeyとして値を管理することで、keyの値の範囲によらず一点取得・更新が\mathrm{O}(1)で行えるデータ構造を実現したものである。

同様のデータ構造にC++の`unordered_map`があるが、`unordered_map`はハッシュ衝突の脆弱性があり、CodeForcesのようなHackの存在するコンテストで無造作に使用するのは危険である。([参考](https://kimiyuki.net/blog/2017/03/08/unordered-map-hash-collision/))

このライブラリでは最低限の機能を持ったHash Mapを実装している。実装には大きく分けて連鎖法と開番地法があり、開番地法の方が定数倍がよいらしいが、簡単のため連鎖法で実装している。そのため定数倍はあまりよくないが、それでも`unordered_map`より2倍程度の速さで動作する。

- [自作のHash Map](https://judge.yosupo.jp/submission/23579)　141ms
- [ハッシュ衝突の対策をしたunordered_map](https://judge.yosupo.jp/submission/23582) 263ms
- (入出力にかかる時間はともに最大50ms程度と考えられる。)
