#define PROBLEM "https://yukicoder.me/problems/no/879"
//
#include "../../template/template.hpp"
//
#include "../../segment-tree/segment-tree-beats-abstract.hpp"

using namespace Nyaan;

struct Node {
  ll sum, laz1 = 0, laz2 = 0;
  int c[2] = {};
  bool md = false;

  Node() : sum(0) {}
  Node(ll k) : sum(k) { c[k & 1]++; }

  void getmod() {
    sum = c[1];
    if (laz2 == 0) {
      md = true;
    } else {
      laz1 += laz2;
      laz2 = 0;
    }
  }

  void add(ll x) {
    (md ? laz2 : laz1) += x;
    sum += x * (c[0] + c[1]);
    if (x & 1) swap(c[0], c[1]);
  }

  void update(Node& l, Node& r) {
    sum = l.sum + r.sum;
    c[0] = l.c[0] + r.c[0];
    c[1] = l.c[1] + r.c[1];
    laz1 = laz2 = 0, md = false;
  }
  
  void push(Node& l, Node& r) {
    if (laz1 != 0) {
      l.add(laz1);
      r.add(laz1);
      laz1 = 0;
    }
    if (md) {
      l.getmod();
      r.getmod();
      md = false;
    }
    if (laz2 != 0) {
      l.add(laz2);
      r.add(laz2);
      laz2 = 0;
    }
  }
  
  bool apply(pl x) {
    if (x.first == 1) {
      getmod();
    } else {
      add(x.second);
    }
    return true;
  }
};

void Nyaan::solve() {
  ini(N, Q);
  vl a(N);
  in(a);
  Beats<Node> seg(a);
  while (Q--) {
    ini(c, l, r);
    --l;
    trc(c, l, r);
    if (c == 1) {
      seg.apply(l, r, pl{1, 0});
    } else if (c == 2) {
      inl(x);
      seg.apply(l, r, pl{2, x});
    } else {
      ll ans = 0;
      seg.query(l, r, [&](Node& n) { ans += n.sum; });
      out(ans);
    }
  }
}
