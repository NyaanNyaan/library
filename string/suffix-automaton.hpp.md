---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/string/suffix-automaton.md
    document_title: Suffix Automaton
    links: []
  bundledCode: "#line 2 \"string/suffix-automaton.hpp\"\n\n\n\ntemplate <int margin\
    \ = 'a'>\nstruct SuffixAutomaton {\n  struct state {\n    vector<pair<char, int>>\
    \ next;\n    uint64_t hit;\n    int len, link, origin, id;\n    char key;\n  \
    \  bool sorted;\n\n    state()\n        : hit(0), len(0), link(-1), origin(-1),\
    \ id(-1), key(0), sorted(false) {}\n    state(int l, char k)\n        : hit(0),\
    \ len(l), link(-1), origin(-1), id(-1), key(k), sorted(false) {}\n\n    __attribute__((target(\"\
    popcnt\"))) int find(char c) {\n      c -= margin;\n      if (((hit >> c) & 1)\
    \ == 0) return -1;\n      if (sorted) {\n        return _mm_popcnt_u64(hit & ((1ull\
    \ << c) - 1));\n      } else {\n        c += margin;\n        for (int i = 0;\
    \ i < (int)next.size(); i++) {\n          if (next[i].first == c) return i;\n\
    \        }\n        assert(0);\n      }\n    }\n\n    int to(char c) { return\
    \ next[find(c)].second; }\n\n    void add(char c, int i) {\n      c -= margin;\n\
    \      assert(((hit >> c) & 1) == 0);\n      next.emplace_back(c + margin, i);\n\
    \      hit |= 1ull << c;\n    }\n  };\n  vector<state> st;\n  vector<int> topo;\n\
    \n  SuffixAutomaton() = default;\n\n  SuffixAutomaton(const string &S) { build(S);\
    \ }\n\n  void build(const string &S) {\n    st.push_back(state());\n    int last\
    \ = 0;\n    for (int i = 0; i < (int)S.size(); i++) extend(S[i], last);\n    tsort();\n\
    \  }\n\n  int size() const { return st.size(); }\n\n  state &operator[](int i)\
    \ { return st[i]; }\n\n private:\n  void extend(char c, int &last) {\n    int\
    \ cur = st.size();\n    st.emplace_back(st[last].len + 1, c);\n    int p = last;\n\
    \    for (; p != -1 && st[p].find(c) == -1; p = st[p].link) {\n      st[p].add(c,\
    \ cur);\n    }\n    if (p == -1) {\n      st[cur].link = 0;\n    } else {\n  \
    \    int q = st[p].to(c);\n      if (st[p].len + 1 == st[q].len)\n        st[cur].link\
    \ = q;\n      else {\n        int clone = st.size();\n        {\n          state\
    \ cl = st[q];\n          cl.len = st[p].len + 1;\n          cl.origin = q;\n \
    \         st.push_back(std::move(cl));\n        }\n        for (; p != -1; p =\
    \ st[p].link) {\n          int i = st[p].find(c);\n          assert(i != -1);\n\
    \          if (st[p].next[i].second != q) break;\n          st[p].next[i].second\
    \ = clone;\n        }\n        st[q].link = st[cur].link = clone;\n      }\n \
    \   }\n    last = cur;\n  }\n\n  vector<bool> marked, temp;\n  vector<vector<int>>\
    \ buf;\n\n  void dfs(int i) {\n    temp[i] = 1;\n    for (auto &[_, j] : st[i].next)\n\
    \      if (!marked[j]) dfs(j);\n    for (auto &j : buf[i])\n      if (!marked[j])\
    \ dfs(j);\n    marked[i] = 1;\n    topo.push_back(i);\n    temp[i] = 0;\n  }\n\
    \n  void tsort() {\n    int n = st.size();\n    marked.resize(n), temp.resize(n),\
    \ buf.resize(n);\n    for (int i = 1; i < n; i++) buf[st[i].link].push_back(i);\n\
    \    for (int i = 0; i < n; i++)\n      if (!marked[i]) dfs(i);\n    reverse(begin(topo),\
    \ end(topo));\n    buf.clear();\n    buf.shrink_to_fit();\n    marked.clear();\n\
    \    marked.shrink_to_fit();\n    temp.clear();\n    temp.shrink_to_fit();\n\n\
    \    vector<int> inv(n);\n    for (int i = 0; i < n; i++) inv[topo[i]] = i;\n\
    \    {\n      vector<state> st2;\n      for (int i = 0; i < n; i++) st2.emplace_back(std::move(st[topo[i]]));\n\
    \      st.swap(st2);\n    }\n    for (int i = 0; i < n; i++) {\n      state &s\
    \ = st[i];\n      s.id = i;\n      sort(begin(s.next), end(s.next));\n      s.sorted\
    \ = true;\n      for (auto &[_, y] : s.next) y = inv[y];\n      if (s.link !=\
    \ -1) s.link = inv[s.link];\n      if (s.origin != -1) s.origin = inv[s.origin];\n\
    \    }\n    topo.clear();\n    topo.shrink_to_fit();\n  }\n};\n\n/**\n * @brief\
    \ Suffix Automaton\n * @docs docs/string/suffix-automaton.md\n */\n"
  code: "#pragma once\n\n\n\ntemplate <int margin = 'a'>\nstruct SuffixAutomaton {\n\
    \  struct state {\n    vector<pair<char, int>> next;\n    uint64_t hit;\n    int\
    \ len, link, origin, id;\n    char key;\n    bool sorted;\n\n    state()\n   \
    \     : hit(0), len(0), link(-1), origin(-1), id(-1), key(0), sorted(false) {}\n\
    \    state(int l, char k)\n        : hit(0), len(l), link(-1), origin(-1), id(-1),\
    \ key(k), sorted(false) {}\n\n    __attribute__((target(\"popcnt\"))) int find(char\
    \ c) {\n      c -= margin;\n      if (((hit >> c) & 1) == 0) return -1;\n    \
    \  if (sorted) {\n        return _mm_popcnt_u64(hit & ((1ull << c) - 1));\n  \
    \    } else {\n        c += margin;\n        for (int i = 0; i < (int)next.size();\
    \ i++) {\n          if (next[i].first == c) return i;\n        }\n        assert(0);\n\
    \      }\n    }\n\n    int to(char c) { return next[find(c)].second; }\n\n   \
    \ void add(char c, int i) {\n      c -= margin;\n      assert(((hit >> c) & 1)\
    \ == 0);\n      next.emplace_back(c + margin, i);\n      hit |= 1ull << c;\n \
    \   }\n  };\n  vector<state> st;\n  vector<int> topo;\n\n  SuffixAutomaton() =\
    \ default;\n\n  SuffixAutomaton(const string &S) { build(S); }\n\n  void build(const\
    \ string &S) {\n    st.push_back(state());\n    int last = 0;\n    for (int i\
    \ = 0; i < (int)S.size(); i++) extend(S[i], last);\n    tsort();\n  }\n\n  int\
    \ size() const { return st.size(); }\n\n  state &operator[](int i) { return st[i];\
    \ }\n\n private:\n  void extend(char c, int &last) {\n    int cur = st.size();\n\
    \    st.emplace_back(st[last].len + 1, c);\n    int p = last;\n    for (; p !=\
    \ -1 && st[p].find(c) == -1; p = st[p].link) {\n      st[p].add(c, cur);\n   \
    \ }\n    if (p == -1) {\n      st[cur].link = 0;\n    } else {\n      int q =\
    \ st[p].to(c);\n      if (st[p].len + 1 == st[q].len)\n        st[cur].link =\
    \ q;\n      else {\n        int clone = st.size();\n        {\n          state\
    \ cl = st[q];\n          cl.len = st[p].len + 1;\n          cl.origin = q;\n \
    \         st.push_back(std::move(cl));\n        }\n        for (; p != -1; p =\
    \ st[p].link) {\n          int i = st[p].find(c);\n          assert(i != -1);\n\
    \          if (st[p].next[i].second != q) break;\n          st[p].next[i].second\
    \ = clone;\n        }\n        st[q].link = st[cur].link = clone;\n      }\n \
    \   }\n    last = cur;\n  }\n\n  vector<bool> marked, temp;\n  vector<vector<int>>\
    \ buf;\n\n  void dfs(int i) {\n    temp[i] = 1;\n    for (auto &[_, j] : st[i].next)\n\
    \      if (!marked[j]) dfs(j);\n    for (auto &j : buf[i])\n      if (!marked[j])\
    \ dfs(j);\n    marked[i] = 1;\n    topo.push_back(i);\n    temp[i] = 0;\n  }\n\
    \n  void tsort() {\n    int n = st.size();\n    marked.resize(n), temp.resize(n),\
    \ buf.resize(n);\n    for (int i = 1; i < n; i++) buf[st[i].link].push_back(i);\n\
    \    for (int i = 0; i < n; i++)\n      if (!marked[i]) dfs(i);\n    reverse(begin(topo),\
    \ end(topo));\n    buf.clear();\n    buf.shrink_to_fit();\n    marked.clear();\n\
    \    marked.shrink_to_fit();\n    temp.clear();\n    temp.shrink_to_fit();\n\n\
    \    vector<int> inv(n);\n    for (int i = 0; i < n; i++) inv[topo[i]] = i;\n\
    \    {\n      vector<state> st2;\n      for (int i = 0; i < n; i++) st2.emplace_back(std::move(st[topo[i]]));\n\
    \      st.swap(st2);\n    }\n    for (int i = 0; i < n; i++) {\n      state &s\
    \ = st[i];\n      s.id = i;\n      sort(begin(s.next), end(s.next));\n      s.sorted\
    \ = true;\n      for (auto &[_, y] : s.next) y = inv[y];\n      if (s.link !=\
    \ -1) s.link = inv[s.link];\n      if (s.origin != -1) s.origin = inv[s.origin];\n\
    \    }\n    topo.clear();\n    topo.shrink_to_fit();\n  }\n};\n\n/**\n * @brief\
    \ Suffix Automaton\n * @docs docs/string/suffix-automaton.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix-automaton.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/suffix-automaton.hpp
layout: document
redirect_from:
- /library/string/suffix-automaton.hpp
- /library/string/suffix-automaton.hpp.html
title: Suffix Automaton
---
## Suffix Automaton

これはなに？



#### アルゴリズム

なにも理解していない　いつか[CP-Algorithms](https://cp-algorithms.com/string/suffix-automaton.html)を読む

#### 重要な性質

参考：[uwiさんの記事](https://w.atwiki.jp/uwicoder/pages/2842.html)

- 図を見ながら説明する
  - 黒線→遷移、赤線→suffix link、c→cloneされたノードを意味している

![nyaan](https://nyaannyaan.github.io/library/nyaan.png)

書きかけ　(画像が貼れねえ～)

- ノード数/辺数は$\mathrm{O}(\lvert S\lvert)$

- 任意のcloneされたノードnについて、clone元のsuffix link先はnである