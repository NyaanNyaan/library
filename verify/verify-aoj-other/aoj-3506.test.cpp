#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3506"
//
#include "../../template/template.hpp"
//
#include "../../data-structure/divide-interval.hpp"
#include "../../graph/graph-template.hpp"
#include "../../shortest-path/bfs01.hpp"
using namespace Nyaan;

void q() {
  inl(N);
  vl X(N), Y(N);
  in2(X, Y);

  {
    auto xs = mkuni(X);
    rep(i, N) X[i] = lb(xs, X[i]);
    auto ys = mkuni(Y);
    rep(i, N) Y[i] = lb(ys, Y[i]);
  }

  DivideInterval dv(N);
  int B = dv.B;
  WeightedGraph<int> g(8 * B);
  auto add = [&](int i, int j, int c) { g[i].emplace_back(i, j, c); };

  // [0B, 2B) : X 側の頂点, 親->子
  // [2B, 4B) : X 側の頂点, 子->親
  // [4B, 6B) : Y 側の頂点, 親->子
  // [6B, 8B) : Y 側の頂点, 子->親

  int offy = 4 * B;
  for (int off : vector{0, offy}) {
    rep(i, N) {
      add(i + 1 * B + off, i + 3 * B + off, 0);
      add(i + 3 * B + off, i + 1 * B + off, 0);
    }
    dv.push([&](int p, int c) {
      add(p + 0 * B + off, c + 0 * B + off, 0);
      add(c + 2 * B + off, p + 2 * B + off, 0);
    });
  }
  // 元々貼られている辺は？
  rep(i, N) {
    int x = X[i] + B;
    int y = Y[i] + B + offy;
    add(x, y, 0), add(y, x, 0);
  }

  // 辺を追加
  rep(t, 2) {
    int off1 = t ? offy : 0;
    int off2 = t ? 0 : offy;
    map<ll, vl> mp;
    rep(i, N) mp[X[i]].push_back(Y[i]);
    each2(k, v, mp) {
      int l = Min(v);
      int r = Max(v);
      if (l == r) continue;
      dv.apply(l, r + 1, [&](int i) {
        // X[k] -> Y[l, r] へ 重み 1 の有向辺
        add(off1 + k + B, off2 + i, 1);
        // Y[l, r] -> X[k] へ 重み 1 の有向辺
        add(off2 + 2 * B + i, off1 + k + B, 1);
      });
    }
    swap(X, Y);
  }
  out(bfs01(g, X[0] + B)[X[N - 1] + B]);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
