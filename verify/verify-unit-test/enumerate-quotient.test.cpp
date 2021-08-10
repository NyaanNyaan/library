#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../math/enumerate-quotient.hpp"
#include "../../misc/rng.hpp"
using namespace Nyaan;

V<vl> naive(ll N) {
  vl q, l, r;
  ll upper = N;
  while (upper) {
    ll quo = N / upper;
    ll thr = N / (quo + 1);
    q.push_back(quo);
    l.push_back(thr);
    r.push_back(upper);
    upper = thr;
  }
  return V<vl>{q, l, r};
}

void test(ll N) {
  vl Q, L, R;
  enumerate_quotient(N, [&](ll q, ll l, ll r) {
    Q.push_back(q);
    L.push_back(l);
    R.push_back(r);
  });
  V<vl> qlr{Q, L, R};
  assert(qlr == naive(N));
}

void Nyaan::solve() {
  rep(i, 10000) test(i);
  rep(_, 10000) test(randint(TEN(4), TEN(6)));
  rep(_, 20) test(randint(1, TEN(11)));

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
