#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../math-fast/radix-sort.hpp"
//
#include "../../misc/all.hpp"
using namespace Nyaan;

template <typename T>
void test(int N) {
  ll mx = numeric_limits<T>::max();
  if (N <= 300) {
    mx = pow(2.0, rnd() * log2(numeric_limits<T>::max()));
    mx = clamp<T>(mx, 1, numeric_limits<T>::max());
  }

  Timer timer;
  {
    V<T> v(N);
    each(x, v) x = rng(-mx, mx);

    auto w = v;

    timer.reset();
    radix_sort(v);
    ll t1 = timer.elapsed();

    timer.reset();
    sort(all(w));
    ll t2 = timer.elapsed();

    assert(v == w);
    if (N >= TEN(8)) DebugImpl::trace("N", N, "radix", t1, "std", t2);
  }

  if (N <= 300) {
    V<pair<T, T>> v(N);
    each(x, v) {
      x.fi = rng(-mx, mx);
      x.se = rng(-mx, mx);
    }

    auto w = v;
    radix_sort_compare_first(v);
    stable_sort(all(w), [](const pair<T, T>& a, const pair<T, T>& b) {
      return a.first < b.first;
    });

    if (v != w) {
      trc2(v);
      trc2(w);
    }
    assert(v == w);
  }
}

void q() {
  {
    vector<int> v{2, 0, 1, -1, -2};
    radix_sort(v);
    vector<int> w{-2, -1, 0, 1, 2};
    assert(v == w);
  }
  {
    vector<int> v{2, 0, 2, -1, 1, 2, 0, -1, -2};
    radix_sort(v);
    vector<int> w{-2, -1, -1, 0, 0, 1, 2, 2, 2};
    assert(v == w);
  }
  {
    vector<ll> v{2, 0, 2, -1, 1, 2, 0, -1, -2};
    radix_sort(v);
    vector<ll> w{-2, -1, -1, 0, 0, 1, 2, 2, 2};
    assert(v == w);
  }

  rep(N, 200) rep(t, 200) {
    test<int>(N);
    test<uint32_t>(N);
    test<ll>(N);
  }
  rep(e, 6) {
    test<int>(TEN(e));
    test<uint32_t>(TEN(e));
    test<ll>(TEN(e));
  }
  cerr << "OK" << endl;

  /*
  cerr << "OK" << endl;
  rep(t, 3) test<int>(TEN(7));
  rep(t, 3) test<ll>(TEN(7));
  */

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
