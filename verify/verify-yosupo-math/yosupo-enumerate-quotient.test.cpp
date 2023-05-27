#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"
//
#include "../../template/template.hpp"
//
#include "../../misc/fastio.hpp"
//
#include "../../math/enumerate-quotient.hpp"

using namespace Nyaan;

void q() {
  ll N;
  rd(N);
  vector<ll> v;
  enumerate_quotient(N, [&](ll q, ll l, ll r) {
    assert(l == 0 or N / l > q);
    assert(N / (l + 1) == q);

    assert(N / r == q);
    assert(N / (r + 1) < q);
    v.push_back(q);
  });
  wtn(sz(v));
  for (auto& x : v) wt(x, ' ');
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
