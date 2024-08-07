#define PROBLEM "https://yukicoder.me/problems/no/430"
//
#include "../../template/template.hpp"
//
#include "../../string/aho-corasick.hpp"
using namespace Nyaan;

void q() {
  ins(S);
  ini(M);
  AhoCorasick<26, 'A', false> ac;
  rep(i, M) {
    ins(C);
    ac.add(C, 0);
  }
  ac.build();
  out(ac.match(S));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
