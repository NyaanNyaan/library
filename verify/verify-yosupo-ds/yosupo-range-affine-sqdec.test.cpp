#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../../template/template.hpp"
#include "../../data-structure/square-root-decomposition.hpp"
#include "../../modint/montgomery-modint.hpp"

constexpr int B = 300;
using mint = LazyMontgomeryModInt<998244353>;
struct affine {
  mint a, b;
  affine() = default;
  affine(mint a_, mint b_) : a(a_), b(b_) {}
};
affine operator*(const  affine &l,const affine &r) {
  return affine{r.a * l.a, r.a * l.b + r.b};
};

int N, Q;
V<affine> a;
affine id = {1, 0};

using namespace Nyaan; void Nyaan::solve() {
  in(N, Q);
  a.resize(N);
  rep(i, N) in(a[i].a, a[i].b);

  struct block {
    // S 作用素の型 T 要素の型
    using S = affine;
    using T = affine;

    int i;

    block() {}

    // i ... 何個目のブロックか
    // i * B + j ... (jをブロック内のidxとして)全体でのidx
    int idx(int j) const { return i * B + j; }

    affine fold;

    // 変数とブロックの初期化を忘れない！
    void init(int _) {
      i = _;
      build();
    }

    void build() {
      fold = {1, 0};
      rep(j, B) if (idx(j) < N) fold = fold * a[idx(j)];
    }

    void update_all(S) { exit(1); }

    void update_part(int l, int r, S x) {
      for (int j = l; j < r; j++) a[idx(j)] = x;
      build();
    }

    T query_all() { return fold; }

    T query_part(int l, int r) {
      affine ret = id;
      for (int i = l; i < r; i++) ret = ret * a[idx(i)];
      return ret;
    }
  };

  auto merge = [](const affine &a,const affine &b) { return a * b; };
  SquareRootDecomposition<decltype(merge), block, B> sqd(N, merge, id);

  rep(_, Q) {
    ini(cmd);
    if (cmd == 0) {
      ini(p, c, d);
      sqd.update(p, p + 1, {c, d});
    } else {
      ini(l, r, x);
      affine sm = sqd.query(l, r);
      out(sm.a * x + sm.b);
    }
  }
}