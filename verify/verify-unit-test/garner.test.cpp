#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../atcoder/math.hpp"
#include "../../math/garner.hpp"
#include "../../misc/rng.hpp"

using namespace Nyaan;

void Nyaan::solve() {
  {
    V<u64> m{3, 5, 17, 257, 65537}, r;
    each(x, m) r.push_back(x - 1);
    auto [R, M] = garner(r, m);
    assert(R + 1 == M && M == unsigned(-1));
  }
  {
    V<u64> m{3, 5, 17, 257, 65537, 641, 6700417}, r;
    each(x, m) r.push_back(x - 1);
    auto [R, M] = garner(r, m);
    assert(R + 1 == M && M == u64(-1));
  }
  {
    V<u64> base{3, 5, 17, 257, 65537, 641, 6700417};
    vl bs(128);
    iota(all(bs), 0);
    rep(t, 10000) {
      V<u64> m, r;
      u64 x = rng();
      randshf(bs);
      u64 th = rng();
      u64 l = 1;
      each(b, bs) {
        if (b == 0 or rng() > th) continue;
        u64 md = 1;
        rep(j, 7) if (gbit(b, j)) md *= base[j];
        m.push_back(md);
        r.push_back(x % md);
        l = lcm(l, md);
      }
      if (m.empty()) continue;
      auto [R, M] = garner(r, m);
      assert(M != 0 && u64(-1) % M == 0);
      assert(R == x % M && M == l);
    }
  }
  rep(t, 30030) {
    vl m{2, 3, 5, 7, 11, 13}, r;
    each(x, m) r.push_back(t % x);
    auto [R, M] = garner(r, m);
    assert(int(R) == t and M == 30030);
  }
  rep(t, 10000) {
    vl r, m;
    ll x = randint(1, 2 * TEN(17));
    reg(y, 2, 42) {
      r.push_back(x % y);
      m.push_back(y);
    }
    auto [r0, m0] = atcoder::crt(r, m);
    auto [r1, m1] = garner(r, m);
    assert(r0 == i64(r1));
    assert(r0 == x);
    assert(m0 == i64(m1));
  }
  rep(t, 100000) {
    vl r, m;
    rep(i, 3) {
      ll x = randint(1 << 20, 1 << 21);
      ll y = randint(0, x);
      r.push_back(y);
      m.push_back(x);
    }
    auto [r0, m0] = atcoder::crt(r, m);
    auto [r1, m1] = garner(r, m);
    assert(r0 == i64(r1));
    assert(m0 == i64(m1));
  }
  {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
  }
}
