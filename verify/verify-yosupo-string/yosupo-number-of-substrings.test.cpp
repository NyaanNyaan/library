#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "../../template/template.hpp"
#include "../../string/suffix-array.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ins(S);
  SuffixArray sa(S);
  LCPArray lcp(sa);
  ll ans = 1LL * sz(S) * (sz(S) + 1) / 2;
  each(x,lcp.LCP) ans -= x;
  out(ans);
}