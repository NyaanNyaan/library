#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include "../competitive-template.cpp"
#include "../data-structure/range-sum-range-add-bit.cpp"

void solve() {
  ini(N, Q);
  RangeAddRangeSumBIT<int> bit(N);
  rep(_, Q) {
    ini(c);
    if (c == 0) {
      ini(s, t, x);
      s--;
      bit.add(s, t, x);
    } else {
      ini(s, t);
      s--;
      out(bit.sum(s, t));
    }
  }
}