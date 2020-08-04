#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../graph/graph-template.hpp"

template <typename G>
struct HeavyLightDecomposition {
  G& g;
  int idx;
  vector<int> size, depth, in, out, nxt, par;
  HeavyLightDecomposition(G& g, int root = 0)
      : g(g),
        idx(0),
        size(g.size(), 0),
        depth(g.size(), 0),
        in(g.size(), -1),
        out(g.size(), -1),
        nxt(g.size(), root),
        par(g.size(), root) {
    dfs_sz(root);
    dfs_hld(root);
  }

  void build(int root) {
    dfs_sz(root);
    dfs_hld(root);
  }

  void dfs_sz(int cur) {
    size[cur] = 1;
    for (auto& dst : g[cur]) {
      if (dst == par[cur]) {
        if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))
          swap(g[cur][0], g[cur][1]);
        else
          continue;
      }
      depth[dst] = depth[cur] + 1;
      par[dst] = cur;
      dfs_sz(dst);
      size[cur] += size[dst];
      if (size[dst] > size[g[cur][0]]) {
        swap(dst, g[cur][0]);
      }
    }
  }

  void dfs_hld(int cur) {
    in[cur] = idx++;
    for (auto dst : g[cur]) {
      if (dst == par[cur]) continue;
      nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));
      dfs_hld(dst);
    }
    out[cur] = idx;
  }

  template <typename F>
  void edge_query(int u, int v, const F& f) {
    while (1) {
      if (in[u] > in[v]) swap(u, v);
      if (nxt[u] != nxt[v]) {
        f(in[nxt[v]], in[v] + 1);
        v = par[nxt[v]];
      } else {
        if (u != v) f(in[u] + 1, in[v] + 1);
        break;
      }
    }
  }

  // TODO : verify
  template <typename F>
  void uncommutable_edge_query(int u, int v, const F& f) {
    while (1) {
      if (nxt[u] != nxt[v]) {
        if (in[u] > in[v]) {
          f(in[u] + 1, in[nxt[u]], true);
          u = par[nxt[u]];
        } else {
          f(in[nxt[v]], in[v] + 1, false);
          v = par[nxt[v]];
        }
      } else {
        if (in[u] != in[v]) {
          if (in[u] > in[v])
            f(in[u] + 1, in[v] + 1, true);
          else
            f(in[u] + 1, in[v] + 1, true);
        }
        break;
      }
    }
  }

  template <typename F>
  void node_query(int u, int v, const F& f) {
    while (1) {
      if (in[u] > in[v]) swap(u, v);
      if (nxt[u] != nxt[v]) {
        f(in[nxt[v]], in[v] + 1);
        v = par[nxt[v]];
      } else {
        f(in[u], in[v] + 1);
        break;
      }
    }
  }

  template <typename F>
  void uncommutable_node_query(int u, int v, const F& f) {
    while (1) {
      if (nxt[u] != nxt[v]) {
        if (in[u] > in[v]) {
          f(in[u] + 1, in[nxt[u]], true);
          u = par[nxt[u]];
        } else {
          f(in[nxt[v]], in[v] + 1, false);
          v = par[nxt[v]];
        }
      } else {
        if (in[u] > in[v])
          f(in[u] + 1, in[v], true);
        else
          f(in[u], in[v] + 1, true);
        break;
      }
    }
  }

  template <typename F>
  void sub_edge_query(int u, const F& f) {
    f(in[u] + 1, out[u]);
  }

  template <typename F>
  void sub_node_query(int u, const F& f) {
    f(in[u], out[u]);
  }

  int lca(int a, int b) {
    while (nxt[a] != nxt[b]) {
      if (in[a] < in[b]) swap(a, b);
      a = par[nxt[a]];
    }
    return depth[a] < depth[b] ? a : b;
  }
};