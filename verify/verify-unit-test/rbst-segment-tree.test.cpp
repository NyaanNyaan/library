#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../segment-tree/rbst-segment-tree.hpp"
//
#include "../../misc/all.hpp"
//
#include "../../segment-tree/lazy-segment-tree.hpp"
//
#include "../../math/affine-transformation.hpp"
#include "../../modint/montgomery-modint.hpp"

using mint = LazyMontgomeryModInt<998244353>;
using T = pair<mint, mint>;
using E = Affine<mint>;
T f(T a, T b) { return T(a.first + b.first, a.second + b.second); }
T g(T a, E b) { return T(a.first * b.a + a.second * b.b, a.second); }
E h(E a, E b) { return a * b; };
T ti() { return T{}; }
E ei() { return E{}; }

using namespace Nyaan;

// すべての関数のテスト。ただしセグ木にぶたん系は別途 verify する
void test(const int N = 100, const int Q = 100) {
  RBSTLazySegmentTree<int, T, E, f, g, h, ti, ei> seg1;
  LazySegmentTree seg2(N, f, g, h, ti(), ei());

  ll MOD = 998244353;
  vector<function<void(void)>> funcs{
      [&]() {
        // set_val
        int i = rng(0, N - 1);
        T x{rng(0, MOD - 1), 1};
        seg1.set_val(i, x);
        seg2.set_val(i, x);
      },
      [&]() {
        // set_val_fast
        int i = rng(0, N - 1);
        T x{rng(0, MOD - 1), 1};
        seg1.set_val_fast(i, x);
        seg2.set_val(i, x);
      },
      [&]() {
        // get_val
        int i = rng(0, N - 1);
        T v1 = seg1.get_val(i);
        T v2 = seg2.get_val(i);
        assert(v1 == v2 and "get_val");
      },
      [&]() {
        // apply_val
        int i = rng(0, N - 1);
        E x{rng(0, MOD - 1), rng(0, MOD - 1)};
        seg1.apply_val(i, [&](T& t) { t = g(t, x); });
        seg2.update(i, i + 1, x);
      },
      [&]() {
        // apply_val_fast
        int i = rng(0, N - 1);
        E x{rng(0, MOD - 1), rng(0, MOD - 1)};
        seg1.apply_val_fast(i, [&](T& t) { t = g(t, x); });
        seg2.update(i, i + 1, x);
      },
      [&]() {
        // erase
        int i = rng(0, N - 1);
        seg1.erase(i);
        seg2.set_val(i, T{});
      },
      [&]() {
        // apply
        int l = rng(0, N - 1);
        int r = rng(0, N - 1);
        if (l > r) swap(l, r);
        r++;
        E x{rng(0, MOD - 1), rng(0, MOD - 1)};
        seg1.apply(l, r, x);
        seg2.update(l, r, x);
      },
      [&]() {
        // fold
        int l = rng(0, N - 1);
        int r = rng(0, N - 1);
        if (l > r) swap(l, r);
        r++;
        auto v1 = seg1.fold(l, r);
        auto v2 = seg2.query(l, r);
        assert(v1 == v2 and "fold");
      },
      [&]() {
        // get_min_key, get_min_keyval
        int v1 = -1;
        while (true) {
          v1 = seg1.get_min_key();
          if (v1 == -1) break;
          T val = seg2.get_val(v1);
          if (val.second == 1) break;
          if (val.second == 0) {
            seg1.erase(v1);
            seg2.set_val(v1, T{});
          } else {
            assert(false and "get_min_key");
          }
        }

        int v2 = -1;
        if (seg2.query(0, N).second != 0) {
          // [0, n) は非ゼロですか？
          int ng = 0, ok = N;
          while (ng + 1 < ok) {
            int m = (ng + ok) / 2;
            mint x = seg2.query(0, m).second;
            (x == 0 ? ng : ok) = m;
          }
          v2 = ok - 1;
        }
        assert(v1 == v2 && "get_min_key");

        if (v1 == -1) {
          auto kv1 = seg1.get_min_keyval();
          assert(kv1.second == T{} && "get_min_keyval");
        } else {
          auto kv1 = seg1.get_min_keyval();
          auto kv2 = make_pair(v2, seg2.get_val(v2));
          assert(kv1 == kv2 && "get_min_keyval");
        }
      },
      [&]() {
        // get_max_key, get_max_keyval
        int v1 = -1;
        while (true) {
          v1 = seg1.get_max_key();
          if (v1 == -1) break;
          T val = seg2.get_val(v1);
          if (val.second == 1) break;
          if (val.second == 0) {
            seg1.erase(v1);
            seg2.set_val(v1, T{});
          } else {
            assert(false and "get_max_key");
          }
        }

        int v2 = -1;
        if (seg2.query(0, N).second != 0) {
          // [i, N) は非ゼロですか？
          int ok = 0, ng = N;
          while (ok + 1 < ng) {
            int m = (ng + ok) / 2;
            mint x = seg2.query(m, N).second;
            (x == 0 ? ng : ok) = m;
          }
          v2 = ok;
        }
        assert(v1 == v2 && "get_max_key");

        if (v1 == -1) {
          auto kv1 = seg1.get_max_keyval();
          assert(kv1.second == T{} && "get_max_keyval");
        } else {
          auto kv1 = seg1.get_max_keyval();
          auto kv2 = make_pair(v2, seg2.get_val(v2));
          assert(kv1 == kv2 && "get_mix_keyval");
        }
      },
      [&]() {
        // pop_min_key
        int v2 = -1;
        if (seg2.query(0, N).second != 0) {
          // [0, n) は非ゼロですか？
          int ng = 0, ok = N;
          while (ng + 1 < ok) {
            int m = (ng + ok) / 2;
            mint x = seg2.query(0, m).second;
            (x == 0 ? ng : ok) = m;
          }
          v2 = ok - 1;
        }
        if (v2 != -1) {
          pair<int, T> kv1;
          do {
            kv1 = seg1.pop_min_keyval();
          } while (kv1.second.second == 0);
          auto kv2 = make_pair(v2, seg2.get_val(v2));
          assert(kv1 == kv2 && "pop_min_keyval");
          seg2.set_val(v2, T{});
        }
      },
      [&]() {
        // pop_max_key
        int v2 = -1;
        if (seg2.query(0, N).second != 0) {
          // [i, N) は非ゼロですか？
          int ok = 0, ng = N;
          while (ok + 1 < ng) {
            int m = (ng + ok) / 2;
            mint x = seg2.query(m, N).second;
            (x == 0 ? ng : ok) = m;
          }
          v2 = ok;
        }
        if (v2 != -1) {
          pair<int, T> kv1;
          do {
            kv1 = seg1.pop_max_keyval();
          } while (kv1.second.second == 0);
          auto kv2 = make_pair(v2, seg2.get_val(v2));
          assert(kv1 == kv2 && "pop_max_keyval");
          seg2.set_val(v2, T{});
        }
      },
  };

  rep(_, 10) {
    int qq = vector<ll>{0LL, rng(1, 10), rng(1, Q)}[rng(0, 2)];
    rep(qnum, qq) {
      int c = rng(0, sz(funcs) - 1);
      // trc(c, "cmd");
      funcs[c]();
    }
    {
      // make_array
      auto vec1 = seg1.make_array();
      rep(i, sz(vec1) - 1) assert(vec1[i].fi < vec1[i + 1].fi); 

      vector<pair<int, T>> vec2;
      rep(i, N) {
        T val = seg2.get_val(i);
        if (val != T{}) vec2.push_back({i, val});
      }
      // trc(vec1);
      // trc(vec2);
      int i1 = 0, i2 = 0;
      while (i1 != sz(vec1) and i2 != sz(vec2)) {
        while (i1 != sz(vec1) and vec1[i1].second == T{}) i1++;
        if (i1 == sz(vec1)) break;
        assert(vec1[i1] == vec2[i2] and "make_array");
        i1++, i2++;
      }
      while (i1 != sz(vec1) and vec1[i1].second == T{}) i1++;
      assert(i1 == sz(vec1) and i2 == sz(vec2) and "make_array");
      // trc("make_array ok");
    }
    seg1.clear();
    rep(i, N) seg2.set_val(i, T{});
  }
}

void test_tl(const int N = 5 * TEN(5), const int Q = 5 * TEN(5)) {
  ll MOD = 998244353;
  V<T> init;
  rep(i, N) init.emplace_back(rng(0, MOD - 1), rng(0, MOD - 1));

  RBSTLazySegmentTree<int, T, E, f, g, h, ti, ei> seg1(init);
  LazySegmentTree seg2(init, f, g, h, ti(), ei());

  vector<function<void(void)>> funcs{
      [&]() {
        // apply
        int l = +rng(0, 10);
        int r = -rng(0, 10) + N;
        E x{rng(0, MOD - 1), rng(0, MOD - 1)};
        seg1.apply(l, r, x);
        seg2.update(l, r, x);
      },
      [&]() {
        // fold
        int l = +rng(0, 10);
        int r = -rng(0, 10) + N;
        auto v1 = seg1.fold(l, r);
        auto v2 = seg2.query(l, r);
        assert(v1 == v2 and "fold");
      },
  };

  rep(qnum, Q) {
    int c = rng(0, sz(funcs) - 1);
    // trc(c, "cmd");
    funcs[c]();
  }
}

void q() {
  rep(t, 10) test(10, TEN(4));
  //
  rep(t, 10) test(100, TEN(4));
  //
  rep(t, 2) test(TEN(4), TEN(2));
  //
  test(10, TEN(4));
  test(2, TEN(4));
  test(1, TEN(4));
  cerr << "test OK" << endl;

  Timer timer;
  test_tl();
  cerr << "test_tl OK" << endl;
  cerr << "time : " << timer.elapsed() << endl;
}

void Nyaan::solve() {
  q();
  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}