#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../segment-tree/segment-tree-beats.hpp"

using namespace Nyaan;

#include "../../misc/rng.hpp"
void verify(int n, int coeff = 100) {
  vl a(n);
  rep(i, n) a[i] = randint(-TEN(10), TEN(10));

  AngelBeats seg(a);
  int q = n * n * coeff;
  while (q--) {
    int cmd = randint(0, 7);
    if (cmd == 3) cmd = randint(0, 7);
    int l, r;
    do {
      l = randint(0, n);
      r = randint(0, n + 1);
    } while (l > r);
    i64 x = randint(-TEN(10), TEN(10));
    if (cmd == 0) {
      // range chmin
      seg.range_chmin(l, r, x);
      for (int i = l; i < r; i++) a[i] = min(a[i], x);
    } else if (cmd == 1) {
      // range chmax
      seg.range_chmax(l, r, x);
      for (int i = l; i < r; i++) a[i] = max(a[i], x);
    } else if (cmd == 2) {
      // range add
      seg.range_add(l, r, x);
      for (int i = l; i < r; i++) a[i] += x;
    } else if (cmd == 3) {
      // range update
      seg.range_update(l, r, x);
      for (int i = l; i < r; i++) a[i] = x;
    } else if (cmd == 4) {
      // range min
      ll s1 = seg.range_min(l, r);
      ll s2 = seg.INF;
      for (int i = l; i < r; i++) s2 = min(s2, a[i]);
      assert(s1 == s2 && "range min");
    } else if (cmd == 5) {
      // range max
      ll s1 = seg.range_max(l, r);
      ll s2 = -seg.INF;
      for (int i = l; i < r; i++) s2 = max(s2, a[i]);
      assert(s1 == s2 && "range max");
    } else if (cmd == 6) {
      // range sum
      ll s1 = seg.range_sum(l, r);
      ll s2 = 0;
      for (int i = l; i < r; i++) s2 += a[i];
      assert(s1 == s2 && "range sum");
    }
  }
}

void Nyaan::solve() {
  int a, b;
  cin >> a >> b;
  cout << (a + b) << endl;

  verify(1);
  verify(2);
  verify(63);
  verify(64);
  verify(65);
}
