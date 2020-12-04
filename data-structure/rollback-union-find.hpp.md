---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-ds/yosupo-rollback-union-find.test.cpp
    title: verify/verify-yosupo-ds/yosupo-rollback-union-find.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/data-structure/rollback-union-find.md
    document_title: "Rollback\u3064\u304DUnion Find"
    links: []
  bundledCode: "#line 2 \"data-structure/rollback-union-find.hpp\"\n\nstruct RollbackUnionFind\
    \ {\n  vector<int> data;\n  stack<pair<int, int> > history;\n  int inner_snap;\n\
    \n  RollbackUnionFind(int sz) : inner_snap(0) { data.assign(sz, -1); }\n\n  bool\
    \ unite(int x, int y) {\n    x = find(x), y = find(y);\n    history.emplace(x,\
    \ data[x]);\n    history.emplace(y, data[y]);\n    if (x == y) return false;\n\
    \    if (data[x] > data[y]) swap(x, y);\n    data[x] += data[y];\n    data[y]\
    \ = x;\n    return true;\n  }\n\n  int find(int k) {\n    if (data[k] < 0) return\
    \ k;\n    return find(data[k]);\n  }\n\n  int same(int x, int y) { return find(x)\
    \ == find(y); }\n\n  int size(int k) { return (-data[find(k)]); }\n\n  void undo()\
    \ {\n    data[history.top().first] = history.top().second;\n    history.pop();\n\
    \    data[history.top().first] = history.top().second;\n    history.pop();\n \
    \ }\n\n  void snapshot() { inner_snap = int(history.size() >> 1); }\n\n  int get_state()\
    \ { return int(history.size() >> 1); }\n\n  void rollback(int state = -1) {\n\
    \    if (state == -1) state = inner_snap;\n    state <<= 1;\n    assert(state\
    \ <= (int)history.size());\n    while (state < (int)history.size()) undo();\n\
    \  }\n};\n\n/**\n * @brief Rollback\u3064\u304DUnion Find\n * @docs docs/data-structure/rollback-union-find.md\n\
    \ */\n"
  code: "#pragma once\n\nstruct RollbackUnionFind {\n  vector<int> data;\n  stack<pair<int,\
    \ int> > history;\n  int inner_snap;\n\n  RollbackUnionFind(int sz) : inner_snap(0)\
    \ { data.assign(sz, -1); }\n\n  bool unite(int x, int y) {\n    x = find(x), y\
    \ = find(y);\n    history.emplace(x, data[x]);\n    history.emplace(y, data[y]);\n\
    \    if (x == y) return false;\n    if (data[x] > data[y]) swap(x, y);\n    data[x]\
    \ += data[y];\n    data[y] = x;\n    return true;\n  }\n\n  int find(int k) {\n\
    \    if (data[k] < 0) return k;\n    return find(data[k]);\n  }\n\n  int same(int\
    \ x, int y) { return find(x) == find(y); }\n\n  int size(int k) { return (-data[find(k)]);\
    \ }\n\n  void undo() {\n    data[history.top().first] = history.top().second;\n\
    \    history.pop();\n    data[history.top().first] = history.top().second;\n \
    \   history.pop();\n  }\n\n  void snapshot() { inner_snap = int(history.size()\
    \ >> 1); }\n\n  int get_state() { return int(history.size() >> 1); }\n\n  void\
    \ rollback(int state = -1) {\n    if (state == -1) state = inner_snap;\n    state\
    \ <<= 1;\n    assert(state <= (int)history.size());\n    while (state < (int)history.size())\
    \ undo();\n  }\n};\n\n/**\n * @brief Rollback\u3064\u304DUnion Find\n * @docs\
    \ docs/data-structure/rollback-union-find.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/rollback-union-find.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-rollback-union-find.test.cpp
documentation_of: data-structure/rollback-union-find.hpp
layout: document
redirect_from:
- /library/data-structure/rollback-union-find.hpp
- /library/data-structure/rollback-union-find.hpp.html
title: "Rollback\u3064\u304DUnion Find"
---
## rollbackつきUnion-Find

#### 概要

Union-FindにUndo機能やrollback機能をつけたライブラリ。

UnionFindの内部実装をQuickFindと呼ばれる経路圧縮を行わない実装にすることで、マージ1回ごとに値が変更される箇所が高々2か所になる。よってマージするごとにマージ前の配列の値を保存すれば、Undoはunite前の値を復元することで$\mathrm{O}(1)$で実行することが出来る。同様にしてrollbackも高速に処理できる。

#### 使い方

- `RollbackUnionFind(int sz)`：サイズ$sz$のUnionFindを生成する。計算量$\mathrm{O}(1)$
- `unite(int x, int y)`：xとyをマージする。返り値はマージに成功したら`true`、失敗したら`false`を返す。計算量$\mathrm{O}(\log n)$($n$はUnionFindのサイズ)
- `find(int k)`：kの根を返す。計算量$\mathrm{O}(\log n)$
- `same(int x, int y)`：xとyが同じ連結成分に所属しているかを返す。計算量$\mathrm{O}(\log n)$
- `undo()`：直前のuniteの操作を取り消す。計算量$\mathrm{O}(1)$
- `snapshot()`：現在のUnionFindの状態を保存する。(保存した状態はrollback()で再現できる。)計算量$\mathrm{O}(1)$
- `get_state()`：現在の`unite`が呼ばれた回数を返す。
- `rollback(int state = -1)`：UnionFindをロールバックする。計算量は状況による。(ボトルネックにはならない)
  - `state = -1`のとき：`snapshot()`で保存した状態にロールバックする。
  - そうでないとき：`unite`が`state`回呼び出された時の状態にロールバックする。