#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../string/string-search.hpp"
//
#include "../../string/rolling-hash.hpp"
//
#include "../../misc/rng.hpp"

using namespace Nyaan;

void test() {
  int N = rng(5, 20);
  string S;
  int upper = rng(1, 10);
  rep(i, N) S.push_back('a' + rng(0, upper - 1));

  vp ps1;
  rep(i, N) reg(j, i, N + 1) ps1.push_back({i, j});
  vp ps2 = ps1;

  // trc2(S);

  StringSearch ss{S};
  roriha rh{S};

  each(p, ps1) each(q, ps1) {
    string s1 = S.substr(p.fi, p.se - p.fi);
    string s2 = S.substr(q.fi, q.se - q.fi);

    // trc(p, q, s1, s2);

    // lcp
    {
      int l = 0;
      while (l < min(sz(s1), sz(s2)) and s1[l] == s2[l]) l++;
      assert(ss.lcp(p.fi, p.se, q.fi, q.se) == l);
      assert(ss.lcp(p, q) == l);
      if (p.se == N and q.se == N) assert(ss.lcp(p.fi, q.fi) == l);
    }

    // strcmp
    {
      int c1 = strcmp(s1.c_str(), s2.c_str());
      int c2 = s1 < s2 ? -1 : s1 == s2 ? 0 : 1;
      int c3 = ss.strcmp(p.fi, p.se, q.fi, q.se);
      int c4 = ss.strcmp(p, q);
      int c5 = rh.strcmp(rh, rh, p.fi, q.fi, p.se, q.se);
      assert(c1 == c2 and c2 == c3 and c3 == c4);
      if (p.se == N and q.se == N) assert(ss.strcmp(p.fi, q.fi) == c1);
    }
  }
}

void Nyaan::solve() {
  rep(t, 1000) test();
  cerr << "OK" << endl;

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
