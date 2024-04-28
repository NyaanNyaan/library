#define PROBLEM "https://yukicoder.me/problems/no/2360"
//
#include "../../template/template.hpp"
//
#include "../../tree/dynamic-rerooting.hpp"
//
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;

struct Path {
  mint a, b, s, x;
};
struct Point {
  mint s, x;
};
struct Info {
  mint a, b;
};
Path vertex(const Info &i) { return {i.a, i.b, i.b, 1}; }
Path compress(const Path &p, const Path &c) {
  return {p.a * c.a, p.a * c.b + p.b, p.s + p.a * c.s + p.b * c.x, p.x + c.x};
}
Point rake(const Point &a, const Point &b) { return {a.s + b.s, a.x + b.x}; }
Point add_edge(const Path &a) { return {a.s, a.x}; }
Path add_vertex(const Point &a, const Info &i) {
  return {i.a, i.b, a.s * i.a + i.b * a.x + i.b, a.x + 1};
}

using DR = DynamicRerooting<Path, Point, Info, vertex, compress, rake, add_edge,
                            add_vertex>;

void q() {
  ini(N);
  V<string> A(N);
  in(A);

  V<Info> init(N);
  rep(i, N) init[i] = {TEN(sz(A[i])), stoll(A[i])};
  DR dr{N, init};
  rep(i, N - 1) {
    ini(u, v);
    --u, --v;
    dr.add_edge(u, v);
  }

  mint ans = 0;
  rep(i, N) {
    auto p = dr.query(i);
    trc(p.a, p.b, p.s, p.x);
    ans += p.s;
  }
  out(ans);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
