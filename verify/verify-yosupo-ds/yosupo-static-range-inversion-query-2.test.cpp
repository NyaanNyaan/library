#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"
//
#include "../../template/template.hpp"
//
#include "../../data-structure/binary-indexed-tree.hpp"
//
#include "../../misc/mo-fast.hpp"
//
#include "../../misc/fastio.hpp"
using namespace Nyaan;

void q() {
  int N, Q;
  rd(N);
  rd(Q);
  vi a(N);
  rep(i, N) rd(a[i]);
  Fast_Mo mo(N, Q);
  rep(i, Q) {
    int l, r;
    rd(l);
    rd(r);
    mo.insert(l, r);
  }
  auto zip = mkuni(a);
  BinaryIndexedTree<int> bit(zip.size() + 1);
  rep(i, N) a[i] = lb(zip, a[i]);

  ll cnt = 0;
  vl ans(Q);
  auto addleft = [&](int idx) {
    cnt += bit.sum(0, a[idx] - 1);
    bit.add(a[idx], 1);
  };
  auto addright = [&](int idx) {
    cnt += bit.sum(a[idx] + 1, zip.size());
    bit.add(a[idx], 1);
  };
  auto delleft = [&](int idx) {
    cnt -= bit.sum(0, a[idx] - 1);
    bit.add(a[idx], -1);
  };
  auto delright = [&](int idx) {
    cnt -= bit.sum(a[idx] + 1, zip.size());
    bit.add(a[idx], -1);
  };
  auto rem = [&](int idx) { ans[idx] = cnt; };
  mo.run(addleft, addright, delleft, delright, rem);
  each(x, ans) {
    wt(x);
    wt('\n');
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
