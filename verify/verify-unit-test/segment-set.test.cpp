#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../data-structure/segment-set.hpp"
//
#include "../../misc/rng.hpp"

// 区間を管理
using namespace Nyaan;

void test() {
  vi a(128);
  SegmentSet<int> seg;
  rep(__, TEN(5) * 2) {
    int c = rng() & 1;
    int l, r;
    do {
      l = rng() & 127;
      r = rng() & 127;
    } while (l >= r);
    if (c == 0) {
      // insert
      reg(i, l, r) a[i] = 1;
      seg.insert(l, r);
    } else if (c == 1) {
      // erase
      reg(i, l, r) a[i] = 0;
      seg.erase(l, r);
    }
    rep(i, 128) {
      bool f = seg.find(i) != seg.end();
      assert(f == a[i]);
    }
    assert(seg.size() == (int)seg.st.size());
  }
}

void Nyaan::solve() {
  test();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
