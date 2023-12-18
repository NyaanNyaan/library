#pragma once

#include <functional>
#include <utility>
using namespace std;

#include "stern-brocot-tree.hpp"

// 分子と分母が INF 以下である非負の既約分数のうち次のものを返す
// first : f(x) が false である最大の既約分数 x
// second : f(x) が true である最小の既約分数 x
// ただし
// - f(0) = true の場合は (0/1, 0/1) を返す
// - true になる分数が存在しない場合は (?, 1/0) を返す
// - INF = 0 の場合は (0/1, 1/0) を返す
template <typename I>
pair<pair<I, I>, pair<I, I>> binary_search_on_stern_brocot_tree(
    function<bool(pair<I, I>)> f, const I &INF) {
  // INF >= 0
  assert(0 <= INF);
  SternBrocotTreeNode<I> m;
  if (INF == 0) return {m.lower_bound(), m.upper_bound()};

  // INF 条件を超える or f(m) = return_value である
  auto over = [&](bool return_value) {
    return max(m.x, m.y) > INF or f(m.get()) == return_value;
  };

  if (f(make_pair(0, 1))) return {m.lower_bound(), m.lower_bound()};
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
      for (a /= 2; a != 0; a /= 2) {
        m.go_left(a);
        if (over(false)) m.go_parent(a);
      }
      m.go_left(1);
      if (max(m.get().first, m.get().second) > INF)
        return {m.lower_bound(), m.upper_bound()};
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
      for (a /= 2; a != 0; a /= 2) {
        m.go_right(a);
        if (over(true)) m.go_parent(a);
      }
      m.go_right(1);
      if (max(m.get().first, m.get().second) > INF)
        return {m.lower_bound(), m.upper_bound()};
    }
  }
}
