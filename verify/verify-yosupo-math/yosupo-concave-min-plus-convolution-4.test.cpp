#define PROBLEM "https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex"
//
#include "../../template/template.hpp"
//
#include "../../segment-tree/li-chao-tree-abstruct.hpp"
using namespace Nyaan;

vl c, d;
struct D {
  ll i;
  ll operator()(ll x) {
    if (i == -1) return infLL;
    return d[i] + c[x - i];
  };
};

vl conv(vl a, vl b) {
  if (a.empty() or b.empty()) return {};
  c = a, d = b;
  int s = sz(a) + sz(b) - 1;
  LiChaoTree<D, true, false> lct(s, D{-1});
  rep(j, sz(b)) lct.add_segment(j, j + sz(a), D{j});
  vl res(s);
  rep(i, s) res[i] = lct.get_val(i).fi;
  return res;
}

void q() {
  ini(N, M);
  vl a(N), b(M);
  in(a, b);
  out(conv(a, b));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
