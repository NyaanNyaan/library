#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
//
#include "../../template/template.hpp"
//
#include "../../string/suffix-automaton.hpp"

using namespace Nyaan;
void Nyaan::solve() {
  ins(s);
  SuffixAutomaton sa(s);

  vl dp(sz(sa));
  dp[0] = 1;
  rep(i, sz(sa)) { each(p, sa.chd(i)) dp[p.second] += dp[i]; }
  out(accumulate(all(dp),0LL) - 1);
}
