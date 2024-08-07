#define PROBLEM "https://yukicoder.me/problems/no/1269"
//
#include "../../template/template.hpp"
//
#include "../../modint/montgomery-modint.hpp"
#include "../../string/aho-corasick.hpp"
using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;

void Nyaan::solve() {
  inl(N, L, R);
  vl fs;
  {
    ll f = 1;
    ll g = 1;
    while (g <= R) {
      if (L <= g) fs.push_back(g);
      swap(f += g, g);
    }
  }
  vs ss;
  each(x, fs) ss.push_back(to_string(x));

  AhoCorasick<10, '0'> aho;
  rep(i, sz(ss)) aho.add(ss[i], i);
  aho.build();

  vm dp(aho.size());
  dp[0] = 1;
  rep(_, N) {
    vm nx(aho.size());
    rep(i, sz(aho)) {
      if (aho.count(i)) continue;
      rep(j, 10) {
        auto n = aho.next(i, j);
        nx[n] += dp[i];
      }
    }
    swap(dp, nx);
  }

  mint ans = 0;
  rep(i, sz(aho)) if (!aho.count(i)) ans += dp[i];
  out(ans - 1);
}
