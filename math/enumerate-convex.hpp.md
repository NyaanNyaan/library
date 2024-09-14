---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/stern-brocot-tree.hpp
    title: Stern-Brocot Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/enumerate-convex.test.cpp
    title: verify/verify-unit-test/enumerate-convex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/enumerate-convex.hpp\"\n\n#include <functional>\n#include\
    \ <utility>\n#include <vector>\nusing namespace std;\n\n#line 2 \"math/stern-brocot-tree.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#line 6 \"math/stern-brocot-tree.hpp\"\
    \nusing namespace std;\n\n// x / y (x > 0, y > 0) \u3092\u7BA1\u7406\u3001\u30C7\
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
    \  }\n};\n\n/**\n *  @brief Stern-Brocot Tree\n */\n#line 9 \"math/enumerate-convex.hpp\"\
    \n\n// \u4E0B\u5411\u304D\u51F8\u5305\u306E\u9802\u70B9\u5217\u6319\n// (xl, yl)\
    \ \u59CB\u70B9, x in [xl, xr]\n// inside(x, y) : (x, y) \u304C\u51F8\u5305\u5185\
    \u90E8\u304B\uFF1F\n// candicate(x, y, c, d) : (x, y) \u304C\u51F8\u5305\u5916\
    \u90E8\u306B\u3042\u308B\u3068\u3059\u308B\u3002\n// \u51F8\u5305\u5185\u90E8\u306E\
    \u70B9 (x + sc, y + sd) \u304C\u5B58\u5728\u3059\u308C\u3070\u305D\u306E\u3088\
    \u3046\u306A s \u3092\u8FD4\u3059\n// \u5B58\u5728\u3057\u306A\u3051\u308C\u3070\
    \u4EFB\u610F\u306E\u5024 (-1 \u3067\u3082\u3088\u3044) \u3092\u8FD4\u3059\ntemplate\
    \ <typename Int>\nvector<pair<Int, Int>> enumerate_convex(\n    Int xl, Int yl,\
    \ Int xr, const function<bool(Int, Int)>& inside,\n    const function<Int(Int,\
    \ Int, Int, Int)>& candicate) {\n  assert(xl <= xr);\n\n  // inside \u304B\u3064\
    \ x <= xr\n  auto f = [&](Int x, Int y) { return x <= xr && inside(x, y); };\n\
    \n  // (a, b) \u304B\u3089 (c, d) \u65B9\u5411\u306B\u9032\u3081\u308B\u3060\u3051\
    \u9032\u3080\n  auto go = [&](Int a, Int b, Int c, Int d) -> Int {\n    assert(f(a,\
    \ b));\n    Int r = 1, s = 0;\n    while (f(a + r * c, b + r * d)) r *= 2;\n \
    \   while ((r /= 2) != 0) {\n      if (f(a + r * c, b + r * d)) s += r, a += r\
    \ * c, b += r * d;\n    }\n    return s;\n  };\n\n  // (a, b) \u304C out, (a +\
    \ c * k, b + d * k) \u304C in \u3068\u3059\u308B\n  // out \u306E\u9593\u9032\u3081\
    \u308B\u3060\u3051\u9032\u3080\n  auto go2 = [&](Int a, Int b, Int c, Int d, Int\
    \ k) {\n    assert(!inside(a, b) and inside(a + c * k, b + d * k));\n    Int ok\
    \ = 0, ng = k;\n    while (ok + 1 < ng) {\n      Int m = (ok + ng) / 2;\n    \
    \  (inside(a + c * m, b + d * m) ? ng : ok) = m;\n    }\n    return ok;\n  };\n\
    \n  vector<pair<Int, Int>> ps;\n  Int x = xl, y = yl;\n  assert(inside(x, y) and\
    \ go(x, y, 0, -1) == 0);\n  ps.emplace_back(x, y);\n  while (x < xr) {\n    Int\
    \ a, b;\n    if (f(x + 1, y)) {\n      a = 1, b = 0;\n    } else {\n      SternBrocotTreeNode<Int>\
    \ sb;\n      while (true) {\n        assert(f(x + sb.lx, y + sb.ly));\n      \
    \  assert(!f(x + sb.rx, y + sb.ry));\n        if (f(x + sb.lx + sb.rx, y + sb.ly\
    \ + sb.ry)) {\n          Int s = go(x + sb.lx, y + sb.ly, sb.rx, sb.ry);\n   \
    \       assert(s > 0);\n          sb.go_right(s);\n        } else {\n        \
    \  Int s = candicate(x + sb.rx, y + sb.ry, sb.lx, sb.ly);\n          if (s <=\
    \ 0 || !inside(x + sb.lx * s + sb.rx, y + sb.ly * s + sb.ry)) {\n            a\
    \ = sb.lx, b = sb.ly;\n            break;\n          } else {\n            Int\
    \ t = go2(x + sb.rx, y + sb.ry, sb.lx, sb.ly, s);\n            sb.go_left(t);\n\
    \          }\n        }\n      }\n    }\n    Int s = go(x, y, a, b);\n    x +=\
    \ a * s, y += b * s;\n    ps.emplace_back(x, y);\n  }\n  return ps;\n}\n"
  code: "#pragma once\n\n#include <functional>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\n#include \"stern-brocot-tree.hpp\"\n\n// \u4E0B\u5411\u304D\
    \u51F8\u5305\u306E\u9802\u70B9\u5217\u6319\n// (xl, yl) \u59CB\u70B9, x in [xl,\
    \ xr]\n// inside(x, y) : (x, y) \u304C\u51F8\u5305\u5185\u90E8\u304B\uFF1F\n//\
    \ candicate(x, y, c, d) : (x, y) \u304C\u51F8\u5305\u5916\u90E8\u306B\u3042\u308B\
    \u3068\u3059\u308B\u3002\n// \u51F8\u5305\u5185\u90E8\u306E\u70B9 (x + sc, y +\
    \ sd) \u304C\u5B58\u5728\u3059\u308C\u3070\u305D\u306E\u3088\u3046\u306A s \u3092\
    \u8FD4\u3059\n// \u5B58\u5728\u3057\u306A\u3051\u308C\u3070\u4EFB\u610F\u306E\u5024\
    \ (-1 \u3067\u3082\u3088\u3044) \u3092\u8FD4\u3059\ntemplate <typename Int>\n\
    vector<pair<Int, Int>> enumerate_convex(\n    Int xl, Int yl, Int xr, const function<bool(Int,\
    \ Int)>& inside,\n    const function<Int(Int, Int, Int, Int)>& candicate) {\n\
    \  assert(xl <= xr);\n\n  // inside \u304B\u3064 x <= xr\n  auto f = [&](Int x,\
    \ Int y) { return x <= xr && inside(x, y); };\n\n  // (a, b) \u304B\u3089 (c,\
    \ d) \u65B9\u5411\u306B\u9032\u3081\u308B\u3060\u3051\u9032\u3080\n  auto go =\
    \ [&](Int a, Int b, Int c, Int d) -> Int {\n    assert(f(a, b));\n    Int r =\
    \ 1, s = 0;\n    while (f(a + r * c, b + r * d)) r *= 2;\n    while ((r /= 2)\
    \ != 0) {\n      if (f(a + r * c, b + r * d)) s += r, a += r * c, b += r * d;\n\
    \    }\n    return s;\n  };\n\n  // (a, b) \u304C out, (a + c * k, b + d * k)\
    \ \u304C in \u3068\u3059\u308B\n  // out \u306E\u9593\u9032\u3081\u308B\u3060\u3051\
    \u9032\u3080\n  auto go2 = [&](Int a, Int b, Int c, Int d, Int k) {\n    assert(!inside(a,\
    \ b) and inside(a + c * k, b + d * k));\n    Int ok = 0, ng = k;\n    while (ok\
    \ + 1 < ng) {\n      Int m = (ok + ng) / 2;\n      (inside(a + c * m, b + d *\
    \ m) ? ng : ok) = m;\n    }\n    return ok;\n  };\n\n  vector<pair<Int, Int>>\
    \ ps;\n  Int x = xl, y = yl;\n  assert(inside(x, y) and go(x, y, 0, -1) == 0);\n\
    \  ps.emplace_back(x, y);\n  while (x < xr) {\n    Int a, b;\n    if (f(x + 1,\
    \ y)) {\n      a = 1, b = 0;\n    } else {\n      SternBrocotTreeNode<Int> sb;\n\
    \      while (true) {\n        assert(f(x + sb.lx, y + sb.ly));\n        assert(!f(x\
    \ + sb.rx, y + sb.ry));\n        if (f(x + sb.lx + sb.rx, y + sb.ly + sb.ry))\
    \ {\n          Int s = go(x + sb.lx, y + sb.ly, sb.rx, sb.ry);\n          assert(s\
    \ > 0);\n          sb.go_right(s);\n        } else {\n          Int s = candicate(x\
    \ + sb.rx, y + sb.ry, sb.lx, sb.ly);\n          if (s <= 0 || !inside(x + sb.lx\
    \ * s + sb.rx, y + sb.ly * s + sb.ry)) {\n            a = sb.lx, b = sb.ly;\n\
    \            break;\n          } else {\n            Int t = go2(x + sb.rx, y\
    \ + sb.ry, sb.lx, sb.ly, s);\n            sb.go_left(t);\n          }\n      \
    \  }\n      }\n    }\n    Int s = go(x, y, a, b);\n    x += a * s, y += b * s;\n\
    \    ps.emplace_back(x, y);\n  }\n  return ps;\n}\n"
  dependsOn:
  - math/stern-brocot-tree.hpp
  isVerificationFile: false
  path: math/enumerate-convex.hpp
  requiredBy: []
  timestamp: '2024-09-14 23:22:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/enumerate-convex.test.cpp
documentation_of: math/enumerate-convex.hpp
layout: document
redirect_from:
- /library/math/enumerate-convex.hpp
- /library/math/enumerate-convex.hpp.html
title: math/enumerate-convex.hpp
---
