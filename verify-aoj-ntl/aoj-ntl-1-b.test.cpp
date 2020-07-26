#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include "../competitive-template.cpp"
#include "../math/elementary-function.cpp"

void solve() {
  ini(N,M);
  out(modpow(N,M,1000000007));
}