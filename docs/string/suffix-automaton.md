## Suffix Automaton

これはなに？

#### 概要



#### アルゴリズム

なにも理解していない　いつか[CP-Algorithms](https://cp-algorithms.com/string/suffix-automaton.html)を読む

#### 重要な性質

参考：[uwiさんの記事](https://w.atwiki.jp/uwicoder/pages/2842.html)

- 図を見ながら説明する
  - 黒線→遷移、赤線→suffix link、c→cloneされたノードを意味している

![nyaan](https://nyaannyaan.github.io/library/nyaan.png)

書きかけ　



- ノード数/辺数は$\mathrm{O}(\lvert S\lvert)$

- 任意のcloneされたノードnについて、clone元のsuffix link先はnである