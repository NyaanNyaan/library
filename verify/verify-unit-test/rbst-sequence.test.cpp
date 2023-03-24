#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../segment-tree/rbst-sequence.hpp"
//
#include "../../misc/rng.hpp"

using namespace Nyaan;

// min add
namespace SequenceTestImpl {

using T = ll;
using E = ll;
T f(T a, T b) { return min(a, b); }
E g(T a, E b) { return a + b; }
E h(T a, E b) { return a + b; }
T ti() { return infLL; }
E ei() { return 0; }

using Seq = Sequence<T, E, f, g, h, ti, ei>;

void test() {
  Seq s;
  vl v;

  // constructor
  if (rng(0, 2)) {
    int n = rng(0, 10);
    if (rng(0, 1)) {
      s = Seq{n};
      v = vl(n, ti());
    } else {
      rep(_, n) v.push_back(rng(0, TEN(9)));
      s = Seq{v};
    }

    auto v2 = s.get_vector();
    auto v3 = s.make_array();
    if (v != v2) {
      trc2(v);
      trc2(v2);
    }
    assert(v == v2);
    rep(i, sz(v)) assert(v3[i].fi == i);

    if (s.fold_all() == ti()) v.clear(), s.clear();
  }

  rep(t, 1000) {
    // if (t % 100 == 0) cerr << sz(v) << " ";
    // if (t == 999) cerr << "\n";
    int cmd = rng(0, 10);
    if (cmd == 0) {
      // insert
      int i = rng(0, sz(v));
      ll x = rng(0, TEN(9));
      s.insert(i, x);
      v.insert(begin(v) + i, x);
    } else if (cmd == 1) {
      // push_back
      ll x = rng(0, TEN(9));
      s.push_back(x);
      v.push_back(x);
    } else if (cmd == 2) {
      // erase
      if (sz(v) != 0) {
        int i = rng(0, sz(v) - 1);
        s.erase(i);
        v.erase(begin(v) + i);
      }
    } else if (cmd == 3) {
      // pop_back
      if (sz(v) != 0) {
        s.pop_back();
        v.pop_back();
      }
    } else if (cmd == 4) {
      // apply
      int l = rng(0, sz(v));
      int r = rng(0, sz(v));
      if (l > r) swap(l, r);
      ll x = rng(0, TEN(9));

      s.apply(l, r, x);
      reg(i, l, r) v[i] += x;
    } else if (cmd == 5) {
      // fold
      int l = rng(0, sz(v));
      int r = rng(0, sz(v));
      if (l > r) swap(l, r);

      ll f1 = s.fold(l, r);
      ll f2 = ti();
      reg(i, l, r) f2 = f(f2, v[i]);
      /*
      if (f1 != f2) {
        auto w = s.get_vector();
        trc2(v);
        trc2(w);
        trc2(l, r, f1, f2);
      }
      */
      assert(f1 == f2);
    } else if (cmd == 6) {
      // append
      int n = rng(0, 15);
      vector<ll> w(n);
      each(x, w) x = rng(1, TEN(9));
      copy(all(w), back_inserter(v));
      s.append(w);
    } else if (cmd == 7) {
      // erase(range)
      if (sz(v)) {
        int l = rng(0, sz(v));
        int r = rng(0, sz(v));
        if (l > r) swap(l, r);
        if (r - l > 8) r = l + 8;
        s.erase(l, r);
        v.erase(begin(v) + l, begin(v) + r);
      }
    }

    auto v2 = s.get_vector();
    auto v3 = s.make_array();

    /*
    if (v != v2) {
      trc2(cmd);
      trc2(sz(v), v);
      trc2(sz(v2), v2);
    }
    */
    assert(v == v2);
    rep(i, sz(v3)) assert(v3[i].fi == i);
  }
}

}  // namespace SequenceTestImpl

void q() {
  rep(_, 1000) SequenceTestImpl::test();
  cerr << "OK" << endl;

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
