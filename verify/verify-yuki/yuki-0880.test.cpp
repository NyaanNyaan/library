#define PROBLEM "https://yukicoder.me/problems/no/880"

#include "../../template/template.hpp"
//
#include "../../segment-tree/segment-tree-beats-abstract.hpp"

using namespace Nyaan;

i64 LCM(i64 a, i64 b) { return a / __gcd(a, b) * b; }

struct Node {
  i64 mx, lcm, sz, sm, same;
  Node(i64 n = 0) : mx(n), lcm(n ? n : 1), sz(1), sm(n), same(1) {}

  void change(i64 x) {
    mx = x;
    lcm = x ? x : 1;
    sm = sz * x;
    same = true;
  }

  void update(Node& l, Node& r) {
    mx = max(l.mx, r.mx);
    lcm = min(TEN(9), LCM(l.lcm, r.lcm));
    sz = l.sz + r.sz;
    sm = l.sm + r.sm;
    same = l.same and r.same and l.mx == r.mx;
    assert(lcm != 0);
  }

  void push(Node& l, Node& r) {
    if (same) l.change(mx), r.change(mx);
  }

  bool apply(pl p) {
    auto [cmd, x] = p;
    if (cmd == 1) {
      change(x);
    } else {
      if (same) {
        change(__gcd(x, mx));
      } else if (lcm >= TEN(9) or x % lcm != 0) {
        return false;
      }
    }
    return true;
  }
};

void Nyaan::solve() {
  ini(N, Q);
  vl a(N);
  in(a);

  Beats<Node> seg(a);
  rep(_, Q) {
    ini(cmd, l, r);
    --l;
    if (cmd == 1) {
      inl(x);
      seg.apply(l, r, pl(1, x));
    } else if (cmd == 2) {
      inl(x);
      seg.apply(l, r, pl(2, x));
    } else if (cmd == 3) {
      ll ans = 0;
      seg.query(l, r, [&](Node& n) { ans = max(n.mx, ans); });
      out(ans);
    } else {
      ll ans = 0;
      seg.query(l, r, [&](Node& n) { ans += n.sm; });
      out(ans);
    }
  }
}