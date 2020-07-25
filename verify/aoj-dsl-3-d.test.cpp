#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include "../competitive-template.cpp"
#include "../data-structure/sliding-window-minimum.cpp"

void solve() {
  ini(N, L);
  vi a(N);
  in(a);
  auto f = [](int a, int b) { return min(a, b); };
  auto dat = SlideWindowMinimum<int, decltype(f)>(a, f, L);
  dat.erase(begin(dat), begin(dat) + L);
  out(dat);
}