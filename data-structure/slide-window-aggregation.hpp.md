---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-swag.test.cpp
    title: verify/verify-yosupo-ds/yosupo-swag.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/slide-window-aggregation.md
    document_title: Slide Window Aggrigation
    links: []
  bundledCode: "#line 2 \"data-structure/slide-window-aggregation.hpp\"\n\ntemplate\
    \ <typename T, typename F>\nstruct SlideWindowAggregation {\n  stack<T> a0, a1;\n\
    \  stack<T> r0, r1;\n  F f;\n  T I, f0, f1;\n\n  SlideWindowAggregation(F f_,\
    \ T I_) : f(f_), I(I_), f0(I_), f1(I_) {}\n\n private:\n  void push_s0(const T\
    \ &x) {\n    a0.push(x);\n    r0.push(f0 = f(x, f0));\n  }\n  void push_s1(const\
    \ T &x) {\n    a1.push(x);\n    r1.push(f1 = f(f1, x));\n  }\n  void transfer()\
    \ {\n    while (!a1.empty()) {\n      push_s0(a1.top());\n      a1.pop();\n  \
    \  }\n    while (!r1.empty()) r1.pop();\n    f1 = I;\n  }\n\n public:\n  void\
    \ push(const T &x) {\n    if (a0.empty()) {\n      push_s0(x);\n      transfer();\n\
    \    } else {\n      push_s1(x);\n    }\n  }\n  void pop() {\n    if (a0.empty())\
    \ transfer();\n    a0.pop();\n    r0.pop();\n    f0 = r0.empty() ? I : r0.top();\n\
    \  }\n  T query() { return f(f0, f1); }\n};\n\n/**\n * @brief Slide Window Aggrigation\n\
    \ * @docs docs/data-structure/slide-window-aggregation.md\n */\n"
  code: "#pragma once\n\ntemplate <typename T, typename F>\nstruct SlideWindowAggregation\
    \ {\n  stack<T> a0, a1;\n  stack<T> r0, r1;\n  F f;\n  T I, f0, f1;\n\n  SlideWindowAggregation(F\
    \ f_, T I_) : f(f_), I(I_), f0(I_), f1(I_) {}\n\n private:\n  void push_s0(const\
    \ T &x) {\n    a0.push(x);\n    r0.push(f0 = f(x, f0));\n  }\n  void push_s1(const\
    \ T &x) {\n    a1.push(x);\n    r1.push(f1 = f(f1, x));\n  }\n  void transfer()\
    \ {\n    while (!a1.empty()) {\n      push_s0(a1.top());\n      a1.pop();\n  \
    \  }\n    while (!r1.empty()) r1.pop();\n    f1 = I;\n  }\n\n public:\n  void\
    \ push(const T &x) {\n    if (a0.empty()) {\n      push_s0(x);\n      transfer();\n\
    \    } else {\n      push_s1(x);\n    }\n  }\n  void pop() {\n    if (a0.empty())\
    \ transfer();\n    a0.pop();\n    r0.pop();\n    f0 = r0.empty() ? I : r0.top();\n\
    \  }\n  T query() { return f(f0, f1); }\n};\n\n/**\n * @brief Slide Window Aggrigation\n\
    \ * @docs docs/data-structure/slide-window-aggregation.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/slide-window-aggregation.hpp
  requiredBy: []
  timestamp: '2021-11-15 21:47:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-swag.test.cpp
documentation_of: data-structure/slide-window-aggregation.hpp
layout: document
redirect_from:
- /library/data-structure/slide-window-aggregation.hpp
- /library/data-structure/slide-window-aggregation.hpp.html
title: Slide Window Aggrigation
---
## Slide Window Aggrigation

#### 概要

Slide Window Aggrigation は、モノイド$(S,\bullet,I)$の$S$の要素の列$A$に対して、以下の操作を高速に実行できる構造である。
- 末尾への要素の挿入
- 先頭の要素の削除
- $A$全体の集約値$A_0 \bullet A_1 \bullet A_2 \bullet \cdots \bullet A_{\vert A \vert -1}$の取得

構造は、挿入用と削除用の$2$つのスタックを持ち、削除用のスタックの中身が尽きたときに挿入用からすべての要素を移し替える。

#### 使い方

- テンプレート引数 `typename T`: $S$の要素の型。
- テンプレート引数 `typename F`: 演算$\bullet$を定義するオブジェクトの型。オブジェクトは`T f(const T& a,const T& b);`の形の関数として呼び出せて、$a \bullet b$の値を返す。
- `SlideWindowAggregation<F, T>(f_, I_)`: `f_`を演算、`I_`を単位元として設定し、$A$を空の列で初期化する。
- `push(x)`: 要素`x`を$A$の末尾に挿入する。計算量均し$\mathrm{O}(1)$。
- `pop()`: $A$から先頭の要素を削除する。計算量均し$\mathrm{O}(1)$。
- `query()`: 集約値$A_0 \bullet A_1 \bullet A_2 \bullet \cdots \bullet A_ {\vert A \vert -1}$を返す。計算量$\mathrm{O}(1)$。

#### 注意点

- $A$が空のときに`pop`を呼んではならない。
- 上記の計算量では`f_`の計算量を$\mathrm{O}(1)$と仮定している。
