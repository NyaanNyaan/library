#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "../competitive-template.cpp"
#include "../string/suffix-array.cpp"

void solve() {
  ins(S);
  SuffixArray sa(S);
  LCPArray lcp(sa);
  ll ans = 1LL * sz(S) * (sz(S) + 1) / 2;
  each(x,lcp.LCP) ans -= x;
  out(ans);
}