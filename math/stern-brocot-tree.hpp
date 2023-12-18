#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

// x / y (x > 0, y > 0) を管理、デフォルトで 1 / 1
// 入力が互いに素でない場合は gcd を取って格納
// seq : (1, 1) から (x, y) へのパス。右の子が正/左の子が負
template <typename Int>
struct SternBrocotTreeNode {
  using Node = SternBrocotTreeNode;

  Int lx, ly, x, y, rx, ry;
  vector<Int> seq;

  SternBrocotTreeNode() : lx(0), ly(1), x(1), y(1), rx(1), ry(0) {}

  SternBrocotTreeNode(Int X, Int Y) : SternBrocotTreeNode() {
    assert(1 <= X && 1 <= Y);
    Int g = gcd(X, Y);
    X /= g, Y /= g;
    while (min(X, Y) > 0) {
      if (X > Y) {
        Int d = X / Y;
        X -= d * Y;
        go_right(d - (X == 0 ? 1 : 0));
      } else {
        Int d = Y / X;
        Y -= d * X;
        go_left(d - (Y == 0 ? 1 : 0));
      }
    }
  }
  SternBrocotTreeNode(const pair<Int, Int> &xy)
      : SternBrocotTreeNode(xy.first, xy.second) {}
  SternBrocotTreeNode(const vector<Int> &_seq) : SternBrocotTreeNode() {
    for (const Int &d : _seq) {
      assert(d != 0);
      if (d > 0) go_right(d);
      if (d < 0) go_left(d);
    }
    assert(seq == _seq);
  }

  // pair<Int, Int> 型で分数を get
  pair<Int, Int> get() const { return make_pair(x, y); }
  // 区間の下限
  pair<Int, Int> lower_bound() const { return make_pair(lx, ly); }
  // 区間の上限
  pair<Int, Int> upper_bound() const { return make_pair(rx, ry); }

  // 根からの深さ
  Int depth() const {
    Int res = 0;
    for (auto &s : seq) res += abs(s);
    return res;
  }
  // 左の子に d 進む
  void go_left(Int d = 1) {
    if (d <= 0) return;
    if (seq.empty() or seq.back() > 0) seq.push_back(0);
    seq.back() -= d;
    rx += lx * d, ry += ly * d;
    x = rx + lx, y = ry + ly;
  }
  // 右の子に d 進む
  void go_right(Int d = 1) {
    if (d <= 0) return;
    if (seq.empty() or seq.back() < 0) seq.push_back(0);
    seq.back() += d;
    lx += rx * d, ly += ry * d;
    x = rx + lx, y = ry + ly;
  }
  // 親の方向に d 進む
  // d 進めたら true, 進めなかったら false を返す
  bool go_parent(Int d = 1) {
    if (d <= 0) return true;
    while (d != 0) {
      if (seq.empty()) return false;
      Int d2 = min(d, abs(seq.back()));
      if (seq.back() > 0) {
        x -= rx * d2, y -= ry * d2;
        lx = x - rx, ly = y - ry;
        seq.back() -= d2;
      } else {
        x -= lx * d2, y -= ly * d2;
        rx = x - lx, ry = y - ly;
        seq.back() += d2;
      }
      d -= d2;
      if (seq.back() == 0) seq.pop_back();
      if (d2 == Int{0}) break;
    }
    return true;
  }
  // SBT 上の LCA
  static Node lca(const Node &lhs, const Node &rhs) {
    Node n;
    for (int i = 0; i < min<int>(lhs.seq.size(), rhs.seq.size()); i++) {
      Int val1 = lhs.seq[i], val2 = rhs.seq[i];
      if ((val1 < 0) != (val2 < 0)) break;
      if (val1 < 0) n.go_left(min(-val1, -val2));
      if (val1 > 0) n.go_right(min(val1, val2));
      if (val1 != val2) break;
    }
    return n;
  }
  friend ostream &operator<<(ostream &os, const Node &rhs) {
    os << "\n";
    os << "L : ( " << rhs.lx << ", " << rhs.ly << " )\n";
    os << "M : ( " << rhs.x << ", " << rhs.y << " )\n";
    os << "R : ( " << rhs.rx << ", " << rhs.ry << " )\n";
    os << "seq : {";
    for (auto &x : rhs.seq) os << x << ", ";
    os << "} \n";
    return os;
  }
  friend bool operator<(const Node &lhs, const Node &rhs) {
    return lhs.x * rhs.y < rhs.x * lhs.y;
  }
  friend bool operator==(const Node &lhs, const Node &rhs) {
    return lhs.x == rhs.x and lhs.y == rhs.y;
  }
};

/**
 *  @brief Stern-Brocot Tree
 */
