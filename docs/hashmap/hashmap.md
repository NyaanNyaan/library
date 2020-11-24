## HashMap(連想配列)

## 概要

TODO:書く

- アピールポイント
  - `std::unordered_map`より3~4倍速い(要出典)
  - Keyの型は`Integral`だけでなく`pair<Integral, Integral>`を取れる
  - ハッシュに実行時乱数を採用している

## 使い方

`unordered_map`と基本的に同じだがいくつか相違点がある。
- Keyに`pair<Integral, Integral>`を取れる
- `const_iterator`は存在しない
- `size()`の型は`int`
- Keyの型が`const`じゃないので書き換えられる(当然壊れる)
- たぶん他にもたくさんありそう

使える関数は以下の通り。(使用方法および計算量は`std::unordered_set`とだいたい同じなので略)

- `find, contain`
- `insert`
- `erase`
- `empty`
- `size`
- `clear`
- `reserve`
- `begin(), end(), begin(*this), end(*this)`
- `operator[]`
- `emplace`
- `iterator`および`iterator`のメンバ関数
