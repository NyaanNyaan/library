#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../data-structure/segment-set.hpp"
//
#include "../../misc/rng.hpp"

// 区間を管理
using namespace Nyaan;

void test() {
  int MX = 128;
  vi a(MX);

  auto gen = [&]() -> map<int, int> {
    map<int, int> res;
    int i = 0;
    while (true) {
      while (i != MX and a[i] == 0) i++;
      if (i == MX) break;
      int j = i;
      while (j != MX and a[j] == 1) j++;
      res.emplace(i, j);
      i = j;
    }
    return res;
  };

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
      // find
      bool f = seg.find(i) != seg.end();
      assert(f == a[i]);
    }
    auto mp = gen();
    auto it1 = begin(seg);
    auto it2 = begin(mp);
    while (it1 != end(seg)) {
      assert(*it1 == *it2);
      it1++, it2++;
    }

    // lower_bound, upper_bound
    vi rui(MX + 1);
    rui[MX] = MX;
    repr(i, MX) {
      rui[i] = rui[i + 1];
      if (a[i]) rui[i] = i;
    }
    rep(i, 128) {
      auto itl = seg.lower_bound(i);
      int xl;
      if (itl == end(seg)) {
        xl = MX;
      } else {
        xl = max<int>(i, itl->first);
      }
      assert(rui[i] == xl);
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
