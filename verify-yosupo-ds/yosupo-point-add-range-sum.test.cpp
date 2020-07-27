#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../competitive-template.cpp"
#include "../data-structure/binary-indexed-tree.cpp"

void solve() {
  ini(N, Q);
  vl a(N);
  in(a);
  BinaryIndexedTree<ll> bit(N);
  rep(i, N) bit.add(i, a[i]);
  rep(_, Q) {
    inl(c, x, y);
    if (c)
      out(bit.sum(x, y - 1));
    else
      bit.add(x, y);
  }
}