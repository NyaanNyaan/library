#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"

#include "../../template/template.hpp"
//
#include "../../graph/chromatic-number.hpp"
#include "../../graph/graph-template.hpp"

using namespace Nyaan;
void Nyaan::solve() {
  ini(N, M);
  auto g = graph(N, M, false, false);
  out(ChromaticNumber<vvi>(g));
}
