#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../modint/montgomery-modint.hpp"
//
#include "../../misc/rng.hpp"
//
using namespace Nyaan;

// bitop.hpp

void verify_bitop() {
  // popcnt
  assert(popcnt(7) == 3);
  assert(popcnt(0) == 0);
  assert(popcnt(1LL << 40) == 1);
  rep(loop, 100) {
    u64 x = rng();
    int pc = popcnt(x);
    rep(i, 64) if ((x >> i) & 1) pc--;
    assert(pc == 0 && "popcnt");
  }

  // lsb
  assert(lsb(0) == 64);
  assert(lsb(1) == 0);
  assert(lsb(1LL << 40) == 40);
  assert(lsb(100) == 2);

  // ctz
  assert(ctz(0) == 64);
  assert(ctz(1) == 0);
  assert(ctz(1LL << 40) == 40);
  assert(ctz(100) == 2);

  rep(loop, 100) {
    u64 x = rng();
    int n = lsb(x);
    assert(ctz(x) == n);
    while (n--) {
      assert((x & 1) == 0 && "lsb");
      x >>= 1;
    }
    assert((x & 1) == 1 && "lsb");
  }

  // msb
  assert(msb(0) == -1);
  assert(msb(1) == 0);
  assert(msb(1LL << 40) == 40);
  assert(msb(100) == 6);

  rep(loop, 100) {
    u64 x = rng();
    int m = msb(x);
    if (m != -1) {
      assert(((x >> m) & 1) == 1 && "msb");
    }
    for (int i = m + 1; i < 64; i++) {
      assert(((x >> i) & 1) == 0 && "msb");
    }
  }

  // gbit, sbit
  // sbitは現在バグり中
  assert(gbit(5, 0) == 1);
  assert(gbit(5, 1) == 0);
  assert(gbit(5, 2) == 1);
  assert(gbit(1LL << 40, 40) == 1);

  rep(loop, 100) {
    u64 x = rng();
    for (int i = 0; i < 64; i++) {
      u64 g = gbit(x, i);
      assert(((x >> i) & 1) == g && "gbit");
      sbit(x, i, 1);
      assert(((x >> i) & 1) == 1u && "sbit");
      sbit(x, i, 0);
      assert(((x >> i) & 1) == 0u && "sbit");
      sbit(x, i, g);
      assert(((x >> i) & 1) == g && "sbit");
    }
  }

  // PW,MSK
  rep(i, 63) {
    assert(1LL << i == PW(i));
    assert(1LL << i == MSK(i) + 1);
  }
}

void verify_util() {
  // P, mkp
  {
    pl x(3, 2);
    pl y(2, 3);
    assert(x + y == pl(5, 5));
    assert(x - y == pl(1, -1));
    assert(x * y == pl(6, 6));
    x += y;
    assert(x == pl(5, 5));
    x -= y;
    assert(x == pl(3, 2));
    x *= y;
    assert(x == pl(6, 6));
    x *= -3;
    assert(x == pl(-18, -18));

    // mkp
    auto p0 = mkp(1, 1);
    static_assert(is_same<decltype(p0), pair<int, int>>::value);
    auto p1 = mkp(1LL, double(2.0));
    static_assert(is_same<decltype(p1), pair<long long, double>>::value);
    assert(p0.first == 1 && p0.second == 1);
    assert(p1.first == 1LL && p1.second == 2.0);
  }

  // P, modint
  {
    using mint = LazyMontgomeryModInt<998244353>;
    using pm = P<mint, mint>;
    pm x(3, 2);
    pm y(2, 3);
    assert(x + y == pm(5, 5));
    assert(x - y == pm(1, -1));
    assert(x * y == pm(6, 6));
    x += y;
    assert(x == pm(5, 5));
    x -= y;
    assert(x == pm(3, 2));
    x *= y;
    assert(x == pm(6, 6));
    x *= -3;
    assert(x == pm(-18, -18));
    x *= mint{-3}.inverse();
    assert(x == pm(6, 6));
  }

  // amin, amax
  {
    int x = 5;
    amin(x, 4);
    assert(x == 4);
    amax(x, 5);
    assert(x == 5);
  }

  // sz, Max, Min, Sum, mkrui, lb, ub, mkuni
  {
    // sz, Max, Min, Sum
    vector<int> v;
    for (int i = 0; i < 100; i++) {
      assert(sz(v) == i);
      v.push_back(randint(0, 10));
      assert(Max(v) == *max_element(all(v)));
      assert(Min(v) == *min_element(all(v)));
      assert(Sum(v) == accumulate(all(v), 0LL));
    }

    // mkrui
    auto rui = mkrui(v);
    int buf = 0;
    assert(rui[0] == 0);
    rep(i, sz(v)) {
      buf += v[i];
      assert(rui[i + 1] == buf);
    }
    rui = mkrui(v, true);
    buf = 0;
    assert(rui.back() == 0);
    repr(i, sz(v)) {
      buf += v[i];
      assert(rui[i] == buf);
    }

    // lb, ub
    sort(all(v));
    for (int i = 0; i < sz(v); i++) {
      if (i != 0 and v[i - 1] == v[i]) continue;
      int x = v[i];
      assert(lb(v, x) == i);
      assert(ub(v, x - 1) == i);
    }
    for (int x = 0; x < 10; x++) {
      int l = lb(v, x);
      int u = ub(v, x);
      for (int i = 0; i < sz(v); i++) {
        assert((l <= i) == (x <= v[i]) && "lb");
        assert((u <= i) == (x < v[i]) && "ub");
      }
    }

    // mkuni
    set<int> s1, s2;
    for (int i : v) s1.insert(i);
    v = mkuni(v);
    for (int i : v) s2.insert(i);
    assert(s1 == s2);
  }

  // TEN
  for (long long i = 0, x = 1; i <= 18; i++, x *= 10) {
    assert(TEN(i) == x);
  }

  // mkord, mkinv(100個, 1~1000)
  {
    vector<int> v;
    rep(loop, 100) { v.push_back(loop); }
    auto ord = mkord(sz(v), [&v](int i, int j) { return v[i] < v[j]; });
    rep(i, sz(ord) - 1) { assert(v[ord[i]] <= v[ord[i + 1]] && "mkord"); }

    randshf(v);
    auto inv = mkinv(v);
    assert(inv.size() == 100 && "mkinv");
    set<int> st;
    each(x, v) st.insert(x);
    rep(i, sz(inv)) {
      if (inv[i] == -1) {
        assert(st.find(i) == st.end() && "mkinv");
      } else {
        assert(0 <= inv[i] && inv[i] < sz(v) && "mkinv");
        assert(v[inv[i]] == i && "mkinv");
      }
    }
  }

  // mkord, mkinv(100個, 1~1000)
  {
    vector<int> v;
    rep(loop, 100) { v.push_back(randint(0, 1000)); }
    auto ord = mkord(sz(v), [&v](int i, int j) { return v[i] < v[j]; });
    rep(i, sz(ord) - 1) { assert(v[ord[i]] <= v[ord[i + 1]] && "mkord"); }

    v = mkuni(v);
    randshf(v);
    auto inv = mkinv(v);
    assert(sz(inv) == Max(v) + 1 && "mkinv");
    set<int> st;
    each(x, v) st.insert(x);
    rep(i, sz(inv)) {
      if (inv[i] == -1) {
        assert(st.find(i) == st.end() && "mkinv");
      } else {
        assert(0 <= inv[i] && inv[i] < sz(v) && "mkinv");
        assert(v[inv[i]] == i);
      }
    }
  }

  // mkiota
  {
    for (int n = 0; n < 100; n++) {
      auto v = mkiota(n);
      rep(i, n) assert(v[i] == i && "mkiota");
    }
  }

  // mkrev
  {
    for (int n = 0; n < 100; n++) {
      vi v(n);
      each(x, v) x = randint(0, TEN(9));
      vi w{v};
      reverse(all(w));
      assert(mkrev(v) == w && "mkrev");
    }

    for (int n = 0; n < 100; n++) {
      string s;
      rep(t, n) s.push_back(rng() % 26 + 'a');
      string t{s};
      reverse(all(t));
      assert(mkrev(s) == t && "mkrev");
    }
  }

  // nxp
  {
    for (int n = 0; n <= 6; n++) {
      vvi v, w;
      vi o = mkiota(n);
      do {
        v.push_back(o);
      } while (nxp(o));
      o = mkiota(n);
      do {
        w.push_back(o);
      } while (next_permutation(all(o)));
      assert(v == w && "nxp");
    }
  }
}

void Nyaan::solve() {
  verify_bitop();
  verify_util();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
