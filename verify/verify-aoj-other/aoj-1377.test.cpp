#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1377"
//
#include "../../template/template.hpp"
//
#include "../../game/partisan-game.hpp"
//
#include "../../hashmap/hashmap-unerasable.hpp"
using namespace Nyaan;

void q() {
  auto f = [&](const string& S) {
    V<string> a, b;
    rep(i, sz(S)) {
      string T = S.substr(0, i);
      (S[i] == 'B' ? a : b).push_back(T);
    }
    return make_pair(a, b);
  };
  PartisanGameSolver<string, decltype(f)> game(f);

  auto gen = [&](V<string> v) {
    int M = sz(v);
    V<SurrealNumber> w(M);
    rep(i, M) w[i] = game.get(v[i]);
    V<pair<SurrealNumber, int>> r(PW(M));
    rep1(b, PW(M) - 1) {
      int t = msb(b);
      r[b] = r[b - PW(t)];
      r[b].first += w[t];
      r[b].second += sz(v[t]);
    }
    return r;
  };

  ini(N);
  V<string> P(N);
  in(P);
  int M = N / 2;
  auto v = gen({begin(P), begin(P) + M});
  auto w = gen({begin(P) + M, end(P)});
  ll ans = 0;

  UnerasableHashMap<pl, int> mp;
  each(p, v) amax(mp[{p.first.p, p.first.q}], p.second);
  each(p, w) {
    pl key{-p.first.p, p.first.q};
    if (mp.count(key)) amax(ans, p.second + mp[key]);
  }
  out(ans);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
