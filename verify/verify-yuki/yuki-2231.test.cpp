#define PROBLEM "https://yukicoder.me/problems/no/2231"
//
#include "../../template/template.hpp"
//
using namespace Nyaan;

#include "../../string/string-search.hpp"
#include "../../string/wildcard-pattern-matching.hpp"

void q() {
  ini(N, M);
  ins(S1, S2);

  auto wpm = wildcard_pattern_matching(S1, S2, '?');

  string U;
  each(c, S1) U.push_back(c == '?' ? 'a' : c);
  each(c, S2) U.push_back(c);
  StringSearch ss{U};

  auto comp = [&](vp a, vp b) {
    reverse(all(a)), reverse(all(b));
    while (sz(a) and sz(b)) {
      auto p = a.back();
      auto q = b.back();
      int m = min(p.se - p.fi, q.se - q.fi);
      a.back().fi += m;
      b.back().fi += m;
      if (a.back().fi == a.back().se) a.pop_back();
      if (b.back().fi == b.back().se) b.pop_back();
      int c = ss.strcmp(p.fi, p.fi + m, q.fi, q.fi + m);
      if (c != 0) return c < 0;
    }
    if (sz(b)) return true;
    return false;
  };

  pair<int, vp> ans{-1, {}};
  rep(i, N - M + 1) {
    if (wpm[i] == 1) {
      vp v;
      v.emplace_back(0, i);
      v.emplace_back(N, N + M);
      v.emplace_back(i + M, N);
      if (ans.fi == -1 or comp(v, ans.se)) {
        ans = {i, v};
      }
    }
  }
  if (ans.fi == -1) {
    out(-1);
  } else {
    int i = ans.fi;
    rep(j, M) S1[j + i] = S2[j];
    rep(j, N) if (S1[j] == '?') S1[j] = 'a';
    out(S1);
  }
}

void Nyaan::solve() {
  int t = 1;
  in(t);
  while (t--) q();
}
