#pragma once

#include <functional>
#include <utility>
using namespace std;

#include "stern-brocot-tree.hpp"

// f(x) が true, かつ分子と分母が INF 以下である最小の既約分数 x を求める
// f(0) = true の場合は 0 を, true になる分数が存在しない場合は 1/0 を返す
template <typename I>
pair<I, I> binary_search_on_stern_brocot_tree(function<bool(pair<I, I>)> f,
                                              const I &INF) {
  // INF >= 1
  assert(1 <= INF);
  SternBrocotTreeNode<I> m;

  // INF 条件を超える or f(m) = return_value である
  auto over = [&](bool return_value) {
    return max(m.x, m.y) > INF or f(m.get()) == return_value;
  };

  if (f(make_pair(0, 1))) return m.lower_bound();
  int go_left = over(true);
  for (; true; go_left ^= 1) {
    if (go_left) {
      // f(M) = true -> (L, M] に答えがある
      // (f(L * b + M) = false) or (INF 超え) になる b の最小は？
      I a = 1;
      for (; true; a *= 2) {
        m.go_left(a);
        if (over(false)) {
          m.go_parent(a);
          break;
        }
      }
      for (a /= 2; a; a /= 2) {
        m.go_left(a);
        if (over(false)) m.go_parent(a);
      }
      m.go_left(1);
      if (max(m.get().first, m.get().second) > INF) return m.upper_bound();
    } else {
      // f(M) = false -> (M, R] に答えがある
      // (f(M + R * b) = true) or (INF 超え) になる b の最小は？
      I a = 1;
      for (; true; a *= 2) {
        m.go_right(a);
        if (over(true)) {
          m.go_parent(a);
          break;
        }
      }
      for (a /= 2; a; a /= 2) {
        m.go_right(a);
        if (over(true)) m.go_parent(a);
      }
      m.go_right(1);
      if (max(m.get().first, m.get().second) > INF) return m.upper_bound();
    }
  }
}
