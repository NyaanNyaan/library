#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include "../../competitive-template.hpp"
#include "../../geometry/integer-geometry.hpp"

void solve() {
  ini(N);
  Points ps(N);
  in(ps);
  ArgumentSort(ps);
  each(p, ps) out(p);
}