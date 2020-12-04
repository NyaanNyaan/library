#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../../template/template.hpp"
#include "../../string/suffix-array.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ins(S);
  SuffixArray sa(S);
  sa.sa.erase(begin(sa.sa));
  out(sa.sa);
}