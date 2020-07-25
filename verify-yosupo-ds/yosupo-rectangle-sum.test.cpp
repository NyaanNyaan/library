#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../competitive-template.cpp"
#include "../data-structure/rectangle-sum.cpp"

void solve() {
  ini(N, Q);
  vl xs(N), ys(N), ws(N);
  in3(xs, ys, ws);
  auto f = [](ll u, ll v) { return u + v; };
  RectangleSum<ll, ll, decltype(f)> rect(xs, ys, ws, f);
  rep(_, Q) {
    inl(l, d, r, u);
    out(rect.rect_sum(l, d, r, u));
  }
}