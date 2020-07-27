#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../competitive-template.hpp"
#include "../string/suffix-array.hpp"

void solve() {
  ins(S);
  SuffixArray sa(S);
  sa.sa.erase(begin(sa.sa));
  out(sa.sa);
}