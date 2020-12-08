## Suffix Automaton

これはなに？

#### 概要

TODO:なにも理解していない　[CP-Algorithms](https://cp-algorithms.com/string/suffix-automaton.html)を読む

参考：[uwiさんの記事](https://w.atwiki.jp/uwicoder/pages/2842.html)　[迷路さんの記事](https://pazzle1230.hatenablog.com/entry/2020/04/10/030325)

- 図

![nyaan](https://nyaannyaan.github.io/library/nyaan.png)

###### 図の説明
- Suffix Automaton：文字列のsuffixを受理するオートマトン
- 図の黒線：次の文字の状態への遷移
- 図の赤線：次の文字の遷移が無かった場合に辿るsuffix link
- 図のc→cloneされたノード

###### 仕組み
- 次のように$\mathrm{endpos}$を定義する
  - $\mathrm{Suf}(S)$:=文字列$S$のsuffixの集合
  - $\mathrm{endpos}(T)$:=$T$が$\mathrm{Suf}(S[0 : i])$に含まれる$i$の集合
- この時$T \in suf(T') \Leftrightarrow \mathrm{endpos}(T) \supset \mathrm{endpos}(T')$

![nyaan](https://nyaannyaan.github.io/library/suffix_link.png)

#### 重要な性質

- 図を見ながら説明する
  


書きかけ　



- ノード数/辺数は$\mathrm{O}(\lvert S\lvert)$

- 任意のcloneされたノードnについて、clone元のsuffix link先はnである