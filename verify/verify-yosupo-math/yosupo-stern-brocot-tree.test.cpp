#define PROBLEM "https://judge.yosupo.jp/problem/stern_brocot_tree"
//
#include "../../template/template.hpp"
//
#include "../../math/stern-brocot-tree.hpp"

using namespace Nyaan;

using SBT = SternBrocotTreeNode<ll>;

void q() {
  ins(cmd);
  if (cmd == "DECODE_PATH") {
    ini(n);
    SBT f;
    rep(_, n) {
      char c;
      in(c);
      inl(x);
      if (c == 'R') f.go_right(x);
      if (c == 'L') f.go_left(x);
    }
    out(f.x, f.y);
  } else if (cmd == "ENCODE_PATH") {
    inl(x, y);
    SBT f{x, y};
    cout << f.seq.size() << " ";
    each(s, f.seq) {
      cout << (s > 0 ? 'R' : 'L') << " ";
      cout << abs(s) << " ";
    }
    cout << "\n";
  } else if (cmd == "LCA") {
    inl(x1, y1, x2, y2);
    SBT f{x1, y1}, g{x2, y2};
    SBT h = SBT::lca(f, g);
    out(h.x, h.y);
  } else if (cmd == "ANCESTOR") {
    inl(k, x, y);
    SBT f{x, y};

    ll l = f.depth() - k;
    if (l < 0) {
      out(-1);
    } else {
      bool b = f.go_parent(l);
      assert(b == true);
      out(f.x, f.y);
    }
  } else {
    inl(x, y);
    SBT f{x, y};
    out(f.lower_bound(), f.upper_bound());
  }
}

void Nyaan::solve() {
  int t = 1;
  in(t);
  while (t--) q();
}
