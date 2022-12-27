## 焼きなまし法

焼きなまし法のライブラリを自分が使いやすいように改良したもの。

#### テンプレート

```cpp
// 状態を持つ型
using state_t = vector<int>;
// スコアを持つ型
using score_t = double;
using pair_t = pair<state_t, score_t>;

// 焼きなましの初期解を入れる関数
pair_t get_init_state() {
  state_t ans;
  score_t score;
  // ans, score に初期解を入れる。
  // 多点焼きなましを行う場合は初期解に多様性が生まれるようにする。

  return {ans, score};
}

//　状態を更新する関数
void update_state(state_t& ans, score_t& score, double th) {
  // 遷移を作る
  // 基本的には以下のように値を複製して遷移先を作っていい
  // (差分更新したい場合は適宜頑張る)
  state_t nxt{ans};
  score_t nxt_score{score};

  // スコアの伸びを変数 diff に格納して値を元に遷移を採用するか決める。
  double diff = -1;
  if (diff > th) {
    // 遷移を採用して ans, score を更新 or 差分更新する。

  } else {
    // (必要があれば)元に戻す。
  }
}

pair_t sa(Timer& t) {
  SA_manager<state_t, score_t> sa(t, 1000, 10, 1900, 1);
  return sa.run<get_init_state,update_state>();
}
```

#### 注意点

- 入力はグローバル領域に置いてよしなにする
- `state_t` が高次元のときは適宜 `std::array` を使うのが楽だと思う
- `score_t` は値が大きければ大きいほど憂愁になるようにする
- 焼きなましのループ回数 / 実行回数によってはエラー出力が重いのでコメントアウトする
- `end_temp` は **負数を指定できる**。 温度は `0.0` との `max` を取るので負である間は山登り法と等価の挙動をする。
  - 温度は線形に変化するので、 `start_temp`, `0.0` 間との外分比を考えれば山登り法の動作時間を制御できる。
  - `get_init_state` や `update_state` はメンバ変数として実装する方が楽かもしれない。
  
#### お気持ち

- (普段の短期マラソンで焼いたコード) - (問題特有のコード) になるようにできるだけ頑張ろうとした
- 入力はグローバルに配列で置きたい(余計な思考がいらなくなるので)
- 書く必要がある関数は必要最小限にしたい(上に同じ)
- 思いつく定数倍高速化は要れた
  - スコアは毎回わざわざ計算する必要はないが「スコアを陽に持たないことで高速化」はどうせ短期でそこまで実装しきれないので大丈夫だと思う