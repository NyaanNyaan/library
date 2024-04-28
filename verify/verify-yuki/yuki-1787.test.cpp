#define PROBLEM "https://yukicoder.me/problems/no/1787"
//
#include "../../template/template.hpp"
//
#include "../../tree/dynamic-rerooting.hpp"
using namespace Nyaan;

struct Path {
  int val, idx, all, tail;
};
struct Point {
  int val, idx;
};
struct Info {
  int val, idx;
};
Path vertex(const Info &i) {
  Path r;
  r.val = i.val;
  r.idx = i.idx;
  r.all = true;
  r.tail = -1;
  return r;
}
Path compress(const Path &p, const Path &c) {
  Path r;
  r.val = p.val;
  r.tail = c.tail;
  if (p.all) {
    if (p.tail > c.val) {
      r.idx = p.idx;
      r.all = false;
    } else {
      r.idx = c.idx;
      r.all = c.all;
    }
  } else {
    r.idx = p.idx;
    r.all = false;
  }
  return r;
}
Point rake(const Point &a, const Point &b) { return a.val > b.val ? a : b; }
Point add_edge(const Path &a) { return {a.val, a.idx}; }
Path add_vertex(const Point &a, const Info &i) {
  return {i.val, a.idx, true, a.val};
}
using DR = DynamicRerooting<Path, Point, Info, vertex, compress, rake, add_edge,
                            add_vertex>;

void q() {
  ini(N);
  V<Info> init(N);
  rep(i, N) init[i].idx = init[i].val = i;
  DR dr(N, init);
  rep(i, N - 1) {
    ini(a, b);
    --a, --b;
    dr.add_edge(a, b);
  }
  ini(Q);
  int x = 0;
  rep(_, Q) {
    ini(u, v);
    u = (u + N - 1 + x) % N;
    v = (v + N - 1 + x) % N;
    auto uinfo = dr.get_info(u);
    auto vinfo = dr.get_info(v);
    swap(uinfo.val, vinfo.val);
    dr.set_info(v, vinfo);
    dr.set_info(u, uinfo);
    auto p = dr.query(u);
    out(x = p.idx + 1);
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
