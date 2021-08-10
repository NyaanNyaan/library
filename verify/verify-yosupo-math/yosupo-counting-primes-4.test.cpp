#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"
//
#include "../../template/template.hpp"
//
#include "../../math/enumerate-quotient.hpp"

using namespace Nyaan;

void Nyaan::solve() {
  inl(N);
  vl ns{0};
  enumerate_quotient(N, [&](ll, ll, ll r) { ns.push_back(r); });
  vector<i64> h(ns);
  for (auto& x : h) --x;
  for (i64 x = 2, sq = sqrtl(N), nsz = ns.size(); x <= sq; ++x) {
    if (h[nsz - x] == h[nsz - x + 1]) continue;
    i64 x2 = x * x, pi = h[nsz - x + 1];
    for (i64 i = 1, n = ns[i]; i < nsz && n >= x2; n = ns[++i])
      h[i] -= h[i * x <= sq ? i * x : nsz - n / x] - pi;
  }
  out(h[1]);
}
