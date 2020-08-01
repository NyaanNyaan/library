#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../../competitive-template.hpp"
#include "../../string/suffix-array.hpp"

void solve(){
  ins(S);
  SuffixArray sa(S);
  LCPArray lcp(sa);
  StringSearch search(lcp);
  rep(i,sz(S)){
    cout << (i?" ":"") << search.ArbitaryLCP(0 , i);
  }
  out();
}