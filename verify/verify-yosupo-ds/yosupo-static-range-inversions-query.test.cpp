#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include "../../template/template.hpp"
#include "../../data-structure/binary-indexed-tree.hpp"
#include "../../misc/compress.hpp"
#include "../../misc/fastio.hpp"
#include "../../misc/mo.hpp"

using namespace Nyaan; void Nyaan::solve() {
  int N, Q;
  rd(N);
  rd(Q);
  vi a(N);
  rep(i, N) rd(a[i]);
  Mo mo(N, Q);
  rep(i, Q) {
    int l, r;
    rd(l);
    rd(r);
    mo.insert(l, r);
  }
  compress<int> zip(a);
  BinaryIndexedTree<int> bit(zip.size() + 1);
  rep(i, N) a[i] = zip.get(a[i]);

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
  mo.run(addleft,addright,delleft,delright,rem);
  each(x, ans) {
    wt(x);
    wt('\n');
  }
}