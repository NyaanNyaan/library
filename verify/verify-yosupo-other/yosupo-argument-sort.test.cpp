#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include "../../template/template.hpp"
#include "../../geometry/integer-geometry.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(N);
  Points ps(N);
  in(ps);
  ArgumentSort(ps);
  each(p, ps) out(p);
}