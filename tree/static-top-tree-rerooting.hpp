#pragma once

#include <optional>
using namespace std;

#include "static-top-tree-vertex-based.hpp"

namespace StaticTopTreeVertexBasedImpl {

template <typename G, typename Path, typename Point, typename Vertex,
          typename Compress, typename Rake, typename Add_edge,
          typename Add_vertex>
struct RerootingDPonStaticTopTree {
  const StaticTopTreeVertexBased<G> tt;
  vector<Path> path, htap;
  vector<Point> point;
  const Vertex vertex;
  const Compress compress;
  const Rake rake;
  const Add_edge add_edge;
  const Add_vertex add_vertex;

  RerootingDPonStaticTopTree(const HeavyLightDecomposition<G>& hld,
                             const Vertex& _vertex, const Compress& _compress,
                             const Rake& _rake, const Add_edge& _add_edge,
                             const Add_vertex& _add_vertex)
      : tt(hld),
        vertex(_vertex),
        compress(_compress),
        rake(_rake),
        add_edge(_add_edge),
        add_vertex(_add_vertex) {
    int n = tt.P.size();
    path.resize(n), htap.resize(n), point.resize(n);
    dfs(tt.tt_root);
  }

  void update(int k) {
    while (k != -1) _update(k), k = tt.P[k];
  }

  Path get(const int v) {
    if (v == tt.root) return path[tt.tt_root];
    vector<int> dists;
    for (int k = v; k != tt.tt_root;) {
      int p = tt.P[k];
      dists.push_back(tt.L[p] == k ? 0 : 1);
      k = p;
    }
    reverse(begin(dists), end(dists));
    Path pa, pl, pr;
    Point po;
    int laz;
    bool fpa = 0, fpl = 0, fpr = 0, fpo = 0, flaz = 0;
    int k = tt.tt_root;
    auto shrink = [&]() {
      assert(!fpo);
      if (fpa) {
        if (fpl) pa = compress(pl, pa);
      } else {
        if (fpl) pa = pl, fpa = 1;
      }
      po = fpa and fpr ? rake(add_edge(pa), add_edge(pr))
           : fpa       ? add_edge(pa)
                       : add_edge(pr);
      fpl = fpr = fpa = 0, fpo = 1;
    };
    for (int dist : dists) {
      if (tt.T[k] == Type::Compress) {
        if (dist) {
          pl = fpl ? compress(htap[tt.L[k]], pl) : htap[tt.L[k]];
          fpl = 1;
        } else {
          pr = fpr ? compress(path[tt.R[k]], pr) : path[tt.R[k]];
          fpr = 1;
        }
      } else {
        if (fpl or fpr) shrink();
        if (tt.T[k] == Type::Vertex) {
          assert(false);
        } else if (tt.T[k] == Type::Rake) {
          assert(fpo);
          po = rake(po, dist ? point[tt.L[k]] : point[tt.R[k]]);
        } else if (tt.T[k] == Type::Add_Edge) {
          if (flaz) {
            assert(fpo);
            pa = add_vertex(po, laz);
            fpo = flaz = 0, fpa = 1;
          }
          assert(fpa);
        } else if (tt.T[k] == Type::Add_Vertex) {
          assert(!flaz);
          laz = k, flaz = 1;
        }
      }
      k = dist ? tt.R[k] : tt.L[k];
    }
    assert(k == v);
    if (fpl or fpr) shrink();
    if (fpa) {
      assert(!fpo);
      po = add_edge(pa);
      fpa = 0, fpo = 1;
    }
    assert(fpo and !fpa and !flaz);
    if (tt.T[k] == Type::Add_Vertex) {
      pa = add_vertex(rake(po, point[tt.L[k]]), k);
    } else {
      pa = add_vertex(po, k);
    }
    return pa;
  }

 private:
  void _update(int k) {
    if (tt.T[k] == Type::Vertex) {
      path[k] = htap[k] = vertex(k);
    } else if (tt.T[k] == Type::Compress) {
      path[k] = compress(path[tt.L[k]], path[tt.R[k]]);
      htap[k] = compress(htap[tt.R[k]], htap[tt.L[k]]);
    } else if (tt.T[k] == Type::Rake) {
      point[k] = rake(point[tt.L[k]], point[tt.R[k]]);
    } else if (tt.T[k] == Type::Add_Edge) {
      point[k] = add_edge(path[tt.L[k]]);
    } else {
      path[k] = htap[k] = add_vertex(point[tt.L[k]], k);
    }
  }

  void dfs(int k) {
    if (tt.L[k] != -1) dfs(tt.L[k]);
    if (tt.R[k] != -1) dfs(tt.R[k]);
    _update(k);
  }
};
}  // namespace StaticTopTreeVertexBasedImpl
using StaticTopTreeVertexBasedImpl::RerootingDPonStaticTopTree;
