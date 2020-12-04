## 二次元Rolling Hash

二次元の列の一致判定を前計算$\mathrm{O}(n)$クエリ$\mathrm{O}(1)$で処理するライブラリ。

#### 使い方

- `RollingHash<Str>(S)`: コンストラクタ。Sを対象としたRollingHashを構築する。$\mathrm{O}(\lvert S\lvert)$
- `build(S)`: Sを対象としたRollingHashを構築する。$\mathrm{O}(\lvert S\lvert)$
- `get(l, r)`: 区間[l, r)のハッシュを返す。$\mathrm{O}(1)$
- `get_hash(T)`: Tのハッシュ値を返す。$\mathrm{O}(\lvert T\lvert)$
