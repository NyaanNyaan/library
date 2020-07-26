#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../competitive-template.cpp"
#include "../string/suffix-array.cpp"

void solve() {
  ins(S);
  SuffixArray sa(S);
  sa.sa.erase(begin(sa.sa));
  out(sa.sa);
}