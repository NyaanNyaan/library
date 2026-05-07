#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../math/nimber.hpp"
#include "../../misc/rng.hpp"
#include "../../misc/timer.hpp"
using namespace Nyaan;

void q() {
  {
    rep1(i, PW(16) - 1) {
      int j = NimberImpl::c16.inv(i);
      assert(Nimber16(i) * Nimber16(j) == Nimber16(1));
    }
  }

  {
    Timer timer;
    using u32 = unsigned;
    rep(t, TEN(7)) {
      u32 i = rng(1, PW(32) - 1);
      u32 j = NimberImpl::inv32(i);
      assert(Nimber32(i) * Nimber32(j) == Nimber32(1));
    }
    trc2(timer());
  }

  {
    Timer timer;
    rep(t, TEN(7)) {
      u64 i = 0;
      while (i == 0) i = rng();
      u64 j = NimberImpl::inv64(i);
      assert(Nimber64(i) * Nimber64(j) == Nimber64(1));
    }
    trc2(timer());
  }

  trc2("OK");

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
