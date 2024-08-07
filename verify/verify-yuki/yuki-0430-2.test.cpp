#define PROBLEM "https://yukicoder.me/problems/no/430"
//
#include "../../template/template.hpp"
//
#include "../../string/aho-corasick.hpp"
using namespace Nyaan;

void q() {
  ins(S);
  ini(M);
  AhoCorasick<26, 'A', true> ac;
  rep(i, M) {
    ins(C);
    ac.add(C, i);
  }
  ac.build();
  auto ans = ac.match(S);
  ll bns = 0;
  each2(key, val, ans) bns += val;
  out(bns);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
