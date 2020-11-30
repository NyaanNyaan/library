#define PROBLEM "https://yukicoder.me/problems/no/103"
//
#include "../../template/template.hpp"
//
#include "../../math/grundy-number.hpp"
#include "../../prime/fast-factorize.hpp"
//
using namespace Nyaan;
void Nyaan::solve() {
  ini(n);
  vi m(n);
  in(m);

  vvi g(10001);
  rep1(i, 10000) {
    auto fc = factor_count(i);
    for (auto [p, c] : fc) {
      g[i].push_back(i / p);
      if (c >= 2) g[i].push_back(i / (p * p));
    }
  }

  auto gn = GrundyNumber(g);
  ll x = 0;
  each(i, m) x ^= gn[i];
  out(x ? "Alice" : "Bob");
}
