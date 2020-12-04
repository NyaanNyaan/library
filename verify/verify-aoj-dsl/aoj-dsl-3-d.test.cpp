#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include "../../template/template.hpp"
#include "../../data-structure/sliding-window-minimum.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(N, L);
  vi a(N);
  in(a);
  auto f = [](int a, int b) { return min(a, b); };
  auto dat = SlideWindowMinimum<int, decltype(f)>(a, f, L);
  dat.erase(begin(dat), begin(dat) + L);
  out(dat);
}