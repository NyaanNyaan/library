## 抽象化Segment Tree Beats

Segment Tree Beatsの抽象化ライブラリ。

#### 使い方

次の関数を備えた構造体`Node`を載せて使用する。

- `Node()`:　デフォルトコンストラクタ。
- `Node(T)`: コンストラクタ。
- `void update(Node& l, Node& r)`: 子の情報を元に更新する関数。
- `void push(Node& l, Node& r)`:　子に親の情報を遅延して伝える関数。
- `bool apply(U x)`:　作用素を作用させて、更新に成功したら`true`、失敗したら`false`を返す関数。

`Beats`構造体の持つ関数は以下の通り。

- `Beats(vector<T> &v)`:　`Node`構造体を初期化できる型`T`の列を初期値として初期化する。
- `apply(int l, int r, U x)`: `U`を区間$[l, r)$に作用させる。
- `query(int l, int r, const F& f)`: 各区間に対して`f(Node &n)`を行う関数。クエリの取得に利用する。
