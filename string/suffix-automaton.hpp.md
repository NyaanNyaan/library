---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-number-of-substrings-suffixautomaton.test.cpp
    title: verify/verify-yosupo-string/yosupo-number-of-substrings-suffixautomaton.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/suffix-automaton.md
    document_title: Suffix Automaton
    links: []
  bundledCode: "#line 2 \"string/suffix-automaton.hpp\"\n\ntemplate <int margin =\
    \ 'a'>\nstruct SuffixAutomaton {\n  struct state {\n    vector<pair<char, int>>\
    \ nxt;\n    uint64_t hit;\n    int len, link, origin;\n    char key;\n\n    state()\
    \ : hit(0), len(0), link(-1), origin(-1), key(0) {}\n    state(int l, char k)\
    \ : hit(0), len(l), link(-1), origin(-1), key(k) {}\n\n    __attribute__((target(\"\
    popcnt\"))) int get_idx(char c) const {\n      c -= margin;\n      if (((hit >>\
    \ c) & 1) == 0) return -1;\n      if (sorted) {\n        return _mm_popcnt_u64(hit\
    \ & ((1ull << c) - 1));\n      } else {\n        c += margin;\n        for (int\
    \ i = 0; i < (int)nxt.size(); i++) {\n          if (nxt[i].first == c) return\
    \ i;\n        }\n      }\n      exit(1);\n    }\n\n    inline int next(char c)\
    \ const {\n      int f = get_idx(c);\n      return ~f ? nxt[f].second : -1;\n\
    \    }\n\n    void add(char c, int i) {\n      c -= margin;\n      assert(((hit\
    \ >> c) & 1) == 0);\n      nxt.emplace_back(c + margin, i);\n      hit |= 1ull\
    \ << c;\n    }\n  };\n\n  inline int next(int i, char c) { return st[i].next(c);\
    \ }\n  inline vector<pair<char, int>> &chd(int i) { return st[i].nxt; }\n  inline\
    \ int link(int i) { return st[i].link; }\n\n  vector<state> st;\n  static bool\
    \ sorted;\n\n  SuffixAutomaton() : st(1) {}\n  SuffixAutomaton(const string &S)\
    \ : st(1) { build(S); }\n\n  void build(const string &S) {\n    int last = 0;\n\
    \    for (int i = 0; i < (int)S.size(); i++) extend(S[i], last);\n    tsort();\n\
    \  }\n\n  int size() const { return st.size(); }\n\n  int find(const string &s)\
    \ const {\n    int last = 0;\n    for (auto &c : s)\n      if ((last = next(last,\
    \ c)) == -1) return -1;\n    return last;\n  }\n\n  state &operator[](int i) {\
    \ return st[i]; }\n\n private:\n  void extend(char c, int &last) {\n    int cur\
    \ = st.size();\n    st.emplace_back(st[last].len + 1, c);\n    int p = last;\n\
    \    for (; p != -1 && st[p].get_idx(c) == -1; p = st[p].link) {\n      st[p].add(c,\
    \ cur);\n    }\n    if (p == -1) {\n      st[cur].link = 0;\n    } else {\n  \
    \    int q = st[p].next(c);\n      if (st[p].len + 1 == st[q].len)\n        st[cur].link\
    \ = q;\n      else {\n        int clone = st.size();\n        {\n          state\
    \ cl = st[q];\n          cl.len = st[p].len + 1, cl.origin = q;\n          st.push_back(std::move(cl));\n\
    \        }\n        for (; p != -1; p = st[p].link) {\n          int i = st[p].get_idx(c);\n\
    \          if (st[p].nxt[i].second != q) break;\n          st[p].nxt[i].second\
    \ = clone;\n        }\n        st[q].link = st[cur].link = clone;\n      }\n \
    \   }\n    last = cur;\n  }\n\n  void tsort() {\n    int n = st.size();\n    vector<int>\
    \ topo;\n    {\n      topo.reserve(n);\n      vector<vector<int>> base(n + 1);\n\
    \      for (int i = 0; i < n; i++) base[st[i].len].push_back(i);\n      for (int\
    \ i = 0; i < n; i++)\n        if (!base[i].empty())\n          copy(begin(base[i]),\
    \ end(base[i]), back_inserter(topo));\n    }\n    {\n      vector<state> st2;\n\
    \      st2.reserve(n);\n      for (int i = 0; i < n; i++) st2.emplace_back(std::move(st[topo[i]]));\n\
    \      st.swap(st2);\n    }\n    vector<int> inv(n);\n    for (int i = 0; i <\
    \ n; i++) inv[topo[i]] = i;\n    for (int i = 0; i < n; i++) {\n      state &s\
    \ = st[i];\n      sort(begin(s.nxt), end(s.nxt));\n      for (auto &[_, y] : s.nxt)\
    \ y = inv[y];\n      if (s.link != -1) s.link = inv[s.link];\n      if (s.origin\
    \ != -1) s.origin = inv[s.origin];\n    }\n    sorted = true;\n  }\n};\n\ntemplate\
    \ <int margin>\nbool SuffixAutomaton<margin>::sorted = false;\n\n/**\n * @brief\
    \ Suffix Automaton\n * @docs docs/string/suffix-automaton.md\n */\n"
  code: "#pragma once\n\ntemplate <int margin = 'a'>\nstruct SuffixAutomaton {\n \
    \ struct state {\n    vector<pair<char, int>> nxt;\n    uint64_t hit;\n    int\
    \ len, link, origin;\n    char key;\n\n    state() : hit(0), len(0), link(-1),\
    \ origin(-1), key(0) {}\n    state(int l, char k) : hit(0), len(l), link(-1),\
    \ origin(-1), key(k) {}\n\n    __attribute__((target(\"popcnt\"))) int get_idx(char\
    \ c) const {\n      c -= margin;\n      if (((hit >> c) & 1) == 0) return -1;\n\
    \      if (sorted) {\n        return _mm_popcnt_u64(hit & ((1ull << c) - 1));\n\
    \      } else {\n        c += margin;\n        for (int i = 0; i < (int)nxt.size();\
    \ i++) {\n          if (nxt[i].first == c) return i;\n        }\n      }\n   \
    \   exit(1);\n    }\n\n    inline int next(char c) const {\n      int f = get_idx(c);\n\
    \      return ~f ? nxt[f].second : -1;\n    }\n\n    void add(char c, int i) {\n\
    \      c -= margin;\n      assert(((hit >> c) & 1) == 0);\n      nxt.emplace_back(c\
    \ + margin, i);\n      hit |= 1ull << c;\n    }\n  };\n\n  inline int next(int\
    \ i, char c) { return st[i].next(c); }\n  inline vector<pair<char, int>> &chd(int\
    \ i) { return st[i].nxt; }\n  inline int link(int i) { return st[i].link; }\n\n\
    \  vector<state> st;\n  static bool sorted;\n\n  SuffixAutomaton() : st(1) {}\n\
    \  SuffixAutomaton(const string &S) : st(1) { build(S); }\n\n  void build(const\
    \ string &S) {\n    int last = 0;\n    for (int i = 0; i < (int)S.size(); i++)\
    \ extend(S[i], last);\n    tsort();\n  }\n\n  int size() const { return st.size();\
    \ }\n\n  int find(const string &s) const {\n    int last = 0;\n    for (auto &c\
    \ : s)\n      if ((last = next(last, c)) == -1) return -1;\n    return last;\n\
    \  }\n\n  state &operator[](int i) { return st[i]; }\n\n private:\n  void extend(char\
    \ c, int &last) {\n    int cur = st.size();\n    st.emplace_back(st[last].len\
    \ + 1, c);\n    int p = last;\n    for (; p != -1 && st[p].get_idx(c) == -1; p\
    \ = st[p].link) {\n      st[p].add(c, cur);\n    }\n    if (p == -1) {\n     \
    \ st[cur].link = 0;\n    } else {\n      int q = st[p].next(c);\n      if (st[p].len\
    \ + 1 == st[q].len)\n        st[cur].link = q;\n      else {\n        int clone\
    \ = st.size();\n        {\n          state cl = st[q];\n          cl.len = st[p].len\
    \ + 1, cl.origin = q;\n          st.push_back(std::move(cl));\n        }\n   \
    \     for (; p != -1; p = st[p].link) {\n          int i = st[p].get_idx(c);\n\
    \          if (st[p].nxt[i].second != q) break;\n          st[p].nxt[i].second\
    \ = clone;\n        }\n        st[q].link = st[cur].link = clone;\n      }\n \
    \   }\n    last = cur;\n  }\n\n  void tsort() {\n    int n = st.size();\n    vector<int>\
    \ topo;\n    {\n      topo.reserve(n);\n      vector<vector<int>> base(n + 1);\n\
    \      for (int i = 0; i < n; i++) base[st[i].len].push_back(i);\n      for (int\
    \ i = 0; i < n; i++)\n        if (!base[i].empty())\n          copy(begin(base[i]),\
    \ end(base[i]), back_inserter(topo));\n    }\n    {\n      vector<state> st2;\n\
    \      st2.reserve(n);\n      for (int i = 0; i < n; i++) st2.emplace_back(std::move(st[topo[i]]));\n\
    \      st.swap(st2);\n    }\n    vector<int> inv(n);\n    for (int i = 0; i <\
    \ n; i++) inv[topo[i]] = i;\n    for (int i = 0; i < n; i++) {\n      state &s\
    \ = st[i];\n      sort(begin(s.nxt), end(s.nxt));\n      for (auto &[_, y] : s.nxt)\
    \ y = inv[y];\n      if (s.link != -1) s.link = inv[s.link];\n      if (s.origin\
    \ != -1) s.origin = inv[s.origin];\n    }\n    sorted = true;\n  }\n};\n\ntemplate\
    \ <int margin>\nbool SuffixAutomaton<margin>::sorted = false;\n\n/**\n * @brief\
    \ Suffix Automaton\n * @docs docs/string/suffix-automaton.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix-automaton.hpp
  requiredBy: []
  timestamp: '2020-12-11 17:45:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-string/yosupo-number-of-substrings-suffixautomaton.test.cpp
documentation_of: string/suffix-automaton.hpp
layout: document
redirect_from:
- /library/string/suffix-automaton.hpp
- /library/string/suffix-automaton.hpp.html
title: Suffix Automaton
---
## Suffix Automaton

#### 概要

これはなに？

参考文献：[CP-Algorithms](https://cp-algorithms.com/string/suffix-automaton.html)　[uwiさんの記事](https://w.atwiki.jp/uwicoder/pages/2842.html)　[迷路さんの記事](https://pazzle1230.hatenablog.com/entry/2020/04/10/030325)

##### 図

文字列$S="\mathrm{nyaan}"$に対応するオートマトンを書いたものが下図
![nyaan](https://nyaannyaan.github.io/library/nyaan.png)

##### 図の説明

- 頂点：部分列と対応した状態
- 図の黒線：次の文字の状態への遷移
- 図の赤線：次の文字の遷移が無かった場合に辿るsuffix link
- 図のc→cloneされたノード
  - この説明ではなんのこっちゃという感じなので、$\mathrm{endpos}(T)$を定義して詳しく仕組みを見ていく

#### $\mathrm{endpos}$

##### $\mathrm{endpos}$とは？

- 次のように$\mathrm{endpos}$を定義する
  - $\mathrm{Suf}(S)$:=文字列$S$のsuffixの集合
  - $\mathrm{endpos}(T)$:=$T$が$\mathrm{Suf}(S[0 : i])$に含まれる$i$の集合
  - 例:$\mathrm{endpos}(\mathrm{nyaa})=\mathrm{endpos}(\mathrm{aa})=\lbrace 1,3\rbrace$
- $\mathrm{endpos}(T_1)=\mathrm{endpos}(T_2)$であるとき、$T_1$と$T_2$はendpos-equivalentであると呼ぶ
- Suffix Automatonの各ノードは、全てのendpos-equivalentな部分文字列の集合を一つのノードに対応させている
  - 言い換えると、Suffix Automatonのノード数は$\mathrm{endpos}(T)$の種類数+初期状態$t_0$の1つである

##### $\mathrm{endpos}$の性質

- 性質1:部分文字列$u,w(0\lt \mathrm{len}(u) \leq \mathrm{len}(w))$は$u \in \mathrm{Suf}(w)$である場合に限ってendpos-equivalentである。
- 性質2:部分文字列$u,w(0\lt \mathrm{len}(u) \leq \mathrm{len}(w))$は以下の関係が成り立つ。
$$\begin{cases}
\mathrm{endpos}(w) \subseteq \mathrm{endpos}(u) & \mathrm{if}\ u\ \in \mathrm{Suf}(w) \\
\mathrm{endpos}(w) \cap \mathrm{endpos}(u) = \phi & \mathrm{otherwise}
\end{cases}$$
- 性質3:endpos-equivalentな部分文字列の集合について考える。この集合に含まれる全ての部分文字列をnon-increasingな順番に並び替えると$\mathrm{"nyaan","yaan","aan","an"}$のように長さが1ずつ減少する。
- ここで、**Suffix Link**を次のように貼る。
  - オートマトンのある状態$v\neq t_0$に含まれる部分文字列のうち最も長いものを$w$とする。この時、$v$に含まれない部分文字列のうち最も長い文字列を$t$とおき、$t$が含まれる状態を$u$として$v$から$u$にSuffix Linkを貼る。
  - 頂点に含まれる部分文字列とSuffix Linkのみを図に書いたものが下の図である。

![nyaan](https://nyaannyaan.github.io/library/suffix_link.png)

- 性質4:Suffix Linkは$t_0$を根とした木になる。
- 性質5:次のルールのみを用いて木を構築したとき、その構造はSuffix Linkによって作られた木と一致する。
  - $\mathrm{endpos}(T_1) \in \mathrm{endpos}(T_2),T_1 \in u,T_2 \in v$であるとき、かつその時に限り$u$は$v$の子孫である。(ただし$\mathrm{endpos}(\phi)=\lbrace{-1,0,\ldots,\mathrm{len}(S)-1\rbrace}$とおく。)

#### Suffix Automatonの概要
 
##### 今までのまとめ

- 文字列$S$の部分文字列$T$は$\mathrm{endpos}(T)$の値によっていくつかの集合に分類できる。

- Suffix Automatonは初期状態$t_0$とendpos-equivalentな集合に一対一対応する状態から構成される。

- 状態$v$に対して一つ以上の部分文字列が対応する。このような部分列のうち一番長いものを$\mathrm{longest}(v)$としてその長さを$\mathrm{len}(v)$とおく。また、一番短い部分文字列の長さを$\mathrm{minlen}(v)$とおく。このとき、状態$v$に対応する全ての文字列は$\mathrm{longest}(v)$のSuffixであり、区間$[\mathrm{minlen}(v), len(v)]$に含まれる全ての長さに対応する全ての部分列のみを含む。

- 状態$v \neq t_0$に対して、長さ$\mathrm{minlen}(v)-1$の$\mathrm{longest}(v)$のSuffixに対応する状態に繋がるリンクをSuffix Linkと定義する。Suffix Linkは$t_0$を根とする木を形成し、同時にこの木は集合$\mathrm{endpos}$の間の包含関係を表している。

- 状態$v \neq t_0$について、$\mathrm{minlen}(v)$はSuffix Linkの接続先$\mathrm{link}(v)$を用いて次のように表される。
$$\mathrm{minlen}(v) = \mathrm{len}(\mathrm{link}(v)) + 1$$

- 任意の状態$v_0$からスタートしてSuffix Linkをたどると$t_0$に到達する。経由した頂点ごとの区間を連結すると連続区間$[0, \mathrm{len}(v_0)]$を得る。

##### 実装

- TODO:なにも理解していない　[CP-Algorithms](https://cp-algorithms.com/string/suffix-automaton.html)を読む

- なんか頂点をcloneするとうまくいくらしい

- $t_0$から文字列$T$に遷移を辿って状態$v$にたどり着いたとき、$T$は状態$v$に含まれている

##### 性質

- ノード数/辺数は$\mathrm{O}(\lvert S\lvert)$

- 任意のcloneされたノードnについて、clone元のsuffix link先はnである

##### 