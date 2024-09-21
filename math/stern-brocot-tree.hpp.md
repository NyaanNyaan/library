---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/enumerate-convex.hpp
    title: math/enumerate-convex.hpp
  - icon: ':heavy_check_mark:'
    path: math/stern-brocot-tree-binary-search.hpp
    title: math/stern-brocot-tree-binary-search.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/enumerate-convex.test.cpp
    title: verify/verify-unit-test/enumerate-convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-rational-approximation.test.cpp
    title: verify/verify-yosupo-math/yosupo-rational-approximation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-stern-brocot-tree-2.test.cpp
    title: verify/verify-yosupo-math/yosupo-stern-brocot-tree-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-stern-brocot-tree.test.cpp
    title: verify/verify-yosupo-math/yosupo-stern-brocot-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2262.test.cpp
    title: verify/verify-yuki/yuki-2262.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2266.test.cpp
    title: verify/verify-yuki/yuki-2266.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Stern-Brocot Tree
    links: []
  bundledCode: "#line 2 \"math/stern-brocot-tree.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\nusing namespace std;\n\n// x / y (x > 0, y > 0)\
    \ \u3092\u7BA1\u7406\u3001\u30C7\u30D5\u30A9\u30EB\u30C8\u3067 1 / 1\n// \u5165\
    \u529B\u304C\u4E92\u3044\u306B\u7D20\u3067\u306A\u3044\u5834\u5408\u306F gcd \u3092\
    \u53D6\u3063\u3066\u683C\u7D0D\n// seq : (1, 1) \u304B\u3089 (x, y) \u3078\u306E\
    \u30D1\u30B9\u3002\u53F3\u306E\u5B50\u304C\u6B63/\u5DE6\u306E\u5B50\u304C\u8CA0\
    \ntemplate <typename Int>\nstruct SternBrocotTreeNode {\n  using Node = SternBrocotTreeNode;\n\
    \n  Int lx, ly, x, y, rx, ry;\n  vector<Int> seq;\n\n  SternBrocotTreeNode() :\
    \ lx(0), ly(1), x(1), y(1), rx(1), ry(0) {}\n\n  SternBrocotTreeNode(Int X, Int\
    \ Y) : SternBrocotTreeNode() {\n    assert(1 <= X && 1 <= Y);\n    Int g = gcd(X,\
    \ Y);\n    X /= g, Y /= g;\n    while (min(X, Y) > 0) {\n      if (X > Y) {\n\
    \        Int d = X / Y;\n        X -= d * Y;\n        go_right(d - (X == 0 ? 1\
    \ : 0));\n      } else {\n        Int d = Y / X;\n        Y -= d * X;\n      \
    \  go_left(d - (Y == 0 ? 1 : 0));\n      }\n    }\n  }\n  SternBrocotTreeNode(const\
    \ pair<Int, Int> &xy)\n      : SternBrocotTreeNode(xy.first, xy.second) {}\n \
    \ SternBrocotTreeNode(const vector<Int> &_seq) : SternBrocotTreeNode() {\n   \
    \ for (const Int &d : _seq) {\n      assert(d != 0);\n      if (d > 0) go_right(d);\n\
    \      if (d < 0) go_left(d);\n    }\n    assert(seq == _seq);\n  }\n\n  // pair<Int,\
    \ Int> \u578B\u3067\u5206\u6570\u3092 get\n  pair<Int, Int> get() const { return\
    \ make_pair(x, y); }\n  // \u533A\u9593\u306E\u4E0B\u9650\n  pair<Int, Int> lower_bound()\
    \ const { return make_pair(lx, ly); }\n  // \u533A\u9593\u306E\u4E0A\u9650\n \
    \ pair<Int, Int> upper_bound() const { return make_pair(rx, ry); }\n\n  // \u6839\
    \u304B\u3089\u306E\u6DF1\u3055\n  Int depth() const {\n    Int res = 0;\n    for\
    \ (auto &s : seq) res += abs(s);\n    return res;\n  }\n  // \u5DE6\u306E\u5B50\
    \u306B d \u9032\u3080\n  void go_left(Int d = 1) {\n    if (d <= 0) return;\n\
    \    if (seq.empty() or seq.back() > 0) seq.push_back(0);\n    seq.back() -= d;\n\
    \    rx += lx * d, ry += ly * d;\n    x = rx + lx, y = ry + ly;\n  }\n  // \u53F3\
    \u306E\u5B50\u306B d \u9032\u3080\n  void go_right(Int d = 1) {\n    if (d <=\
    \ 0) return;\n    if (seq.empty() or seq.back() < 0) seq.push_back(0);\n    seq.back()\
    \ += d;\n    lx += rx * d, ly += ry * d;\n    x = rx + lx, y = ry + ly;\n  }\n\
    \  // \u89AA\u306E\u65B9\u5411\u306B d \u9032\u3080\n  // d \u9032\u3081\u305F\
    \u3089 true, \u9032\u3081\u306A\u304B\u3063\u305F\u3089 false \u3092\u8FD4\u3059\
    \n  bool go_parent(Int d = 1) {\n    if (d <= 0) return true;\n    while (d !=\
    \ 0) {\n      if (seq.empty()) return false;\n      Int d2 = min(d, abs(seq.back()));\n\
    \      if (seq.back() > 0) {\n        x -= rx * d2, y -= ry * d2;\n        lx\
    \ = x - rx, ly = y - ry;\n        seq.back() -= d2;\n      } else {\n        x\
    \ -= lx * d2, y -= ly * d2;\n        rx = x - lx, ry = y - ly;\n        seq.back()\
    \ += d2;\n      }\n      d -= d2;\n      if (seq.back() == 0) seq.pop_back();\n\
    \      if (d2 == Int{0}) break;\n    }\n    return true;\n  }\n  // SBT \u4E0A\
    \u306E LCA\n  static Node lca(const Node &lhs, const Node &rhs) {\n    Node n;\n\
    \    for (int i = 0; i < min<int>(lhs.seq.size(), rhs.seq.size()); i++) {\n  \
    \    Int val1 = lhs.seq[i], val2 = rhs.seq[i];\n      if ((val1 < 0) != (val2\
    \ < 0)) break;\n      if (val1 < 0) n.go_left(min(-val1, -val2));\n      if (val1\
    \ > 0) n.go_right(min(val1, val2));\n      if (val1 != val2) break;\n    }\n \
    \   return n;\n  }\n  friend ostream &operator<<(ostream &os, const Node &rhs)\
    \ {\n    os << \"\\n\";\n    os << \"L : ( \" << rhs.lx << \", \" << rhs.ly <<\
    \ \" )\\n\";\n    os << \"M : ( \" << rhs.x << \", \" << rhs.y << \" )\\n\";\n\
    \    os << \"R : ( \" << rhs.rx << \", \" << rhs.ry << \" )\\n\";\n    os << \"\
    seq : {\";\n    for (auto &x : rhs.seq) os << x << \", \";\n    os << \"} \\n\"\
    ;\n    return os;\n  }\n  friend bool operator<(const Node &lhs, const Node &rhs)\
    \ {\n    return lhs.x * rhs.y < rhs.x * lhs.y;\n  }\n  friend bool operator==(const\
    \ Node &lhs, const Node &rhs) {\n    return lhs.x == rhs.x and lhs.y == rhs.y;\n\
    \  }\n};\n\n/**\n *  @brief Stern-Brocot Tree\n */\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    using namespace std;\n\n// x / y (x > 0, y > 0) \u3092\u7BA1\u7406\u3001\u30C7\
    \u30D5\u30A9\u30EB\u30C8\u3067 1 / 1\n// \u5165\u529B\u304C\u4E92\u3044\u306B\u7D20\
    \u3067\u306A\u3044\u5834\u5408\u306F gcd \u3092\u53D6\u3063\u3066\u683C\u7D0D\n\
    // seq : (1, 1) \u304B\u3089 (x, y) \u3078\u306E\u30D1\u30B9\u3002\u53F3\u306E\
    \u5B50\u304C\u6B63/\u5DE6\u306E\u5B50\u304C\u8CA0\ntemplate <typename Int>\nstruct\
    \ SternBrocotTreeNode {\n  using Node = SternBrocotTreeNode;\n\n  Int lx, ly,\
    \ x, y, rx, ry;\n  vector<Int> seq;\n\n  SternBrocotTreeNode() : lx(0), ly(1),\
    \ x(1), y(1), rx(1), ry(0) {}\n\n  SternBrocotTreeNode(Int X, Int Y) : SternBrocotTreeNode()\
    \ {\n    assert(1 <= X && 1 <= Y);\n    Int g = gcd(X, Y);\n    X /= g, Y /= g;\n\
    \    while (min(X, Y) > 0) {\n      if (X > Y) {\n        Int d = X / Y;\n   \
    \     X -= d * Y;\n        go_right(d - (X == 0 ? 1 : 0));\n      } else {\n \
    \       Int d = Y / X;\n        Y -= d * X;\n        go_left(d - (Y == 0 ? 1 :\
    \ 0));\n      }\n    }\n  }\n  SternBrocotTreeNode(const pair<Int, Int> &xy)\n\
    \      : SternBrocotTreeNode(xy.first, xy.second) {}\n  SternBrocotTreeNode(const\
    \ vector<Int> &_seq) : SternBrocotTreeNode() {\n    for (const Int &d : _seq)\
    \ {\n      assert(d != 0);\n      if (d > 0) go_right(d);\n      if (d < 0) go_left(d);\n\
    \    }\n    assert(seq == _seq);\n  }\n\n  // pair<Int, Int> \u578B\u3067\u5206\
    \u6570\u3092 get\n  pair<Int, Int> get() const { return make_pair(x, y); }\n \
    \ // \u533A\u9593\u306E\u4E0B\u9650\n  pair<Int, Int> lower_bound() const { return\
    \ make_pair(lx, ly); }\n  // \u533A\u9593\u306E\u4E0A\u9650\n  pair<Int, Int>\
    \ upper_bound() const { return make_pair(rx, ry); }\n\n  // \u6839\u304B\u3089\
    \u306E\u6DF1\u3055\n  Int depth() const {\n    Int res = 0;\n    for (auto &s\
    \ : seq) res += abs(s);\n    return res;\n  }\n  // \u5DE6\u306E\u5B50\u306B d\
    \ \u9032\u3080\n  void go_left(Int d = 1) {\n    if (d <= 0) return;\n    if (seq.empty()\
    \ or seq.back() > 0) seq.push_back(0);\n    seq.back() -= d;\n    rx += lx * d,\
    \ ry += ly * d;\n    x = rx + lx, y = ry + ly;\n  }\n  // \u53F3\u306E\u5B50\u306B\
    \ d \u9032\u3080\n  void go_right(Int d = 1) {\n    if (d <= 0) return;\n    if\
    \ (seq.empty() or seq.back() < 0) seq.push_back(0);\n    seq.back() += d;\n  \
    \  lx += rx * d, ly += ry * d;\n    x = rx + lx, y = ry + ly;\n  }\n  // \u89AA\
    \u306E\u65B9\u5411\u306B d \u9032\u3080\n  // d \u9032\u3081\u305F\u3089 true,\
    \ \u9032\u3081\u306A\u304B\u3063\u305F\u3089 false \u3092\u8FD4\u3059\n  bool\
    \ go_parent(Int d = 1) {\n    if (d <= 0) return true;\n    while (d != 0) {\n\
    \      if (seq.empty()) return false;\n      Int d2 = min(d, abs(seq.back()));\n\
    \      if (seq.back() > 0) {\n        x -= rx * d2, y -= ry * d2;\n        lx\
    \ = x - rx, ly = y - ry;\n        seq.back() -= d2;\n      } else {\n        x\
    \ -= lx * d2, y -= ly * d2;\n        rx = x - lx, ry = y - ly;\n        seq.back()\
    \ += d2;\n      }\n      d -= d2;\n      if (seq.back() == 0) seq.pop_back();\n\
    \      if (d2 == Int{0}) break;\n    }\n    return true;\n  }\n  // SBT \u4E0A\
    \u306E LCA\n  static Node lca(const Node &lhs, const Node &rhs) {\n    Node n;\n\
    \    for (int i = 0; i < min<int>(lhs.seq.size(), rhs.seq.size()); i++) {\n  \
    \    Int val1 = lhs.seq[i], val2 = rhs.seq[i];\n      if ((val1 < 0) != (val2\
    \ < 0)) break;\n      if (val1 < 0) n.go_left(min(-val1, -val2));\n      if (val1\
    \ > 0) n.go_right(min(val1, val2));\n      if (val1 != val2) break;\n    }\n \
    \   return n;\n  }\n  friend ostream &operator<<(ostream &os, const Node &rhs)\
    \ {\n    os << \"\\n\";\n    os << \"L : ( \" << rhs.lx << \", \" << rhs.ly <<\
    \ \" )\\n\";\n    os << \"M : ( \" << rhs.x << \", \" << rhs.y << \" )\\n\";\n\
    \    os << \"R : ( \" << rhs.rx << \", \" << rhs.ry << \" )\\n\";\n    os << \"\
    seq : {\";\n    for (auto &x : rhs.seq) os << x << \", \";\n    os << \"} \\n\"\
    ;\n    return os;\n  }\n  friend bool operator<(const Node &lhs, const Node &rhs)\
    \ {\n    return lhs.x * rhs.y < rhs.x * lhs.y;\n  }\n  friend bool operator==(const\
    \ Node &lhs, const Node &rhs) {\n    return lhs.x == rhs.x and lhs.y == rhs.y;\n\
    \  }\n};\n\n/**\n *  @brief Stern-Brocot Tree\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/stern-brocot-tree.hpp
  requiredBy:
  - math/stern-brocot-tree-binary-search.hpp
  - math/enumerate-convex.hpp
  timestamp: '2023-12-18 23:52:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/enumerate-convex.test.cpp
  - verify/verify-yuki/yuki-2262.test.cpp
  - verify/verify-yuki/yuki-2266.test.cpp
  - verify/verify-yosupo-math/yosupo-stern-brocot-tree.test.cpp
  - verify/verify-yosupo-math/yosupo-rational-approximation.test.cpp
  - verify/verify-yosupo-math/yosupo-stern-brocot-tree-2.test.cpp
documentation_of: math/stern-brocot-tree.hpp
layout: document
redirect_from:
- /library/math/stern-brocot-tree.hpp
- /library/math/stern-brocot-tree.hpp.html
title: Stern-Brocot Tree
---
