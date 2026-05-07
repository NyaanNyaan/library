#pragma once

#include <functional>
#include <utility>
#include <vector>
using namespace std;

#include "stern-brocot-tree.hpp"

// 極小から始まる下向き凸包の頂点列挙
// (xl, yl) 始点, x in [xl, xr]
// inside(x, y) : (x, y) が凸包内部か？
// candicate(x, y, c, d) : (x, y) が凸包外部にあるとする。
// 凸包内部の点 (x + sc, y + sd) が存在すればそのような s を返す
// (ただし s は誤差でズレてもいいように s ± 2 を探索する仕様)
// 存在しなければ任意の値 (-1 でもよい) を返す
template <typename Int>
vector<pair<Int, Int>> enumerate_convex(
    Int xl, Int yl, Int xr, const function<bool(Int, Int)>& inside,
    const function<Int(Int, Int, Int, Int)>& candicate) {
  assert(xl <= xr);

  // inside かつ x <= xr
  auto f = [&](Int x, Int y) { return x <= xr && inside(x, y); };

  // (a, b) から (c, d) 方向に進めるだけ進む
  auto go = [&](Int a, Int b, Int c, Int d) -> Int {
    assert(f(a, b));
    Int r = 1, s = 0;
    while (f(a + r * c, b + r * d)) r *= 2;
    while ((r /= 2) != 0) {
      if (f(a + r * c, b + r * d)) s += r, a += r * c, b += r * d;
    }
    return s;
  };

  // (a, b) が out, (a + c * k, b + d * k) が in とする
  // out の間進めるだけ進む
  auto go2 = [&](Int a, Int b, Int c, Int d, Int k) {
    assert(!f(a, b) and f(a + c * k, b + d * k));
    Int ok = 0, ng = k;
    while (ok + 1 < ng) {
      Int m = (ok + ng) / 2;
      (f(a + c * m, b + d * m) ? ng : ok) = m;
    }
    return ok;
  };

  vector<pair<Int, Int>> ps;
  Int x = xl, y = yl;
  assert(f(x, y) and go(x, y, 0, -1) == 0);
  ps.emplace_back(x, y);
  SternBrocotTreeNode<Int> sb;
  while (x < xr) {
    Int a, b;
    if (f(x + 1, y)) {
      a = 1, b = 0;
    } else {
      while (!f(x + sb.lx, y + sb.ly)) {
        assert(!sb.seq.empty());
        Int bc = sb.seq.back();
        sb.go_parent(bc < 0 ? -bc : bc);
      }
      while (true) {
        assert(f(x + sb.lx, y + sb.ly));
        assert(!f(x + sb.rx, y + sb.ry));
        if (f(x + sb.lx + sb.rx, y + sb.ly + sb.ry)) {
          Int s = go(x + sb.lx, y + sb.ly, sb.rx, sb.ry);
          assert(s > 0);
          sb.go_right(s);
        } else {
          Int c = candicate(x + sb.rx, y + sb.ry, sb.lx, sb.ly);
          if (sb.lx) c = min(c, (xr - x - sb.rx) / sb.lx);
          Int s = -1;
          // 念のため周囲を調べる(フェイルセーフ)
          for (Int d = -2; d <= 2; d++) {
            Int v = c + d;
            if (v > 0 && f(x + sb.lx * v + sb.rx, y + sb.ly * v + sb.ry)) {
              s = v;
              break;
            }
          }
          if (s == -1) {
            a = sb.lx, b = sb.ly;
            break;
          } else {
            Int t = go2(x + sb.rx, y + sb.ry, sb.lx, sb.ly, s);
            sb.go_left(t);
          }
        }
      }
    }
    Int s = go(x, y, a, b);
    x += a * s, y += b * s;
    ps.emplace_back(x, y);
  }
  return ps;
}
