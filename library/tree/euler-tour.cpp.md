---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: tree/euler-tour.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/euler-tour.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-27 01:16:41+09:00




## Depends on

* :heavy_check_mark: <a href="../competitive-template.cpp.html">competitive-template.cpp</a>
* :heavy_check_mark: <a href="../graph/graph-template.cpp.html">graph/graph-template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

#include "../graph/graph-template.cpp"

// ** NOT RECOMMEND TO USE **
// euler tour of node 
struct EulerTour {
  struct UnionFind {
    vector<int> data;
    UnionFind(int N) : data(N, -1) {}

    int find(int k) { return data[k] < 0 ? k : data[k] = find(data[k]); }

    int unite(int x, int y) {
      if ((x = find(x)) == (y = find(y))) return false;
      if (data[x] > data[y]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
      return true;
    }

    int size(int k) { return -data[find(k)]; }

    int same(int x, int y) { return find(x) == find(y); }
  };

  struct SegmentTree_RangeMin {
    int size;
    using P = pair<int, int>;
    vector<P> seg;
    P UNIT = P(1 << 30, -1);

    SegmentTree_RangeMin() {}

    SegmentTree_RangeMin(int N) {
      size = 1;
      while (size < N) size <<= 1;
      seg.assign(2 * size, UNIT);
    }

    void set(int k, P x) { seg[k + size] = x; }

    void build() {
      for (int k = size - 1; k > 0; k--) {
        seg[k] = min(seg[2 * k], seg[2 * k + 1]);
      }
    }

    // query to [a, b)
    P query(int a, int b) {
      P L = UNIT, R = UNIT;
      for (a += size, b += size; a < b; a >>= 1, b >>= 1) {
        if (a & 1) L = min(L, seg[a++]);
        if (b & 1) R = min(seg[--b], R);
      }
      return min(L, R);
    }
  };

  using G = vector<vector<int>>;

  UnionFind uf;
  vector<int> down, up, tour, par, depth;
  int i_;
  SegmentTree_RangeMin lca_seg;

  EulerTour(G &g)
      : uf(g.size()),
        down(g.size(), -1),
        up(g.size()),
        tour(g.size() * 2),
        par(g.size()),
        depth(g.size(), -1),
        i_(0),
        lca_seg(2 * g.size()) {
    vector<int> isroot(g.size(), 1);
    for (int i = 0; i < (int)g.size(); i++) {
      for (auto &d : g[i]) isroot[d] = 0;
    }
    for (int i = 0; i < (int)g.size(); i++) {
      if (!isroot[i]) continue;
      dfs(g, i, -1);
    }
    lca_seg.build();
  }

  void dfs(G &g, int c, int p) {
    down[c] = i_;
    par[c] = p;
    depth[c] = ~p ? depth[p] + 1 : 0;
    lca_seg.set(i_, {depth[c], c});
    tour[i_++] = c;
    if (~p) uf.unite(c, p);
    for (auto &d : g[c]) {
      if (d == p) continue;
      dfs(g, d, c);
    }
    up[c] = i_;
    if (~p) lca_seg.set(i_, {depth[p], p});
    tour[i_++] = c;
  }

  int lca(int a, int b) {
    if (!uf.same(a, b)) return -1;
    if (down[a] > down[b]) swap(a, b);
    return lca_seg.query(down[a], down[b] + 1).second;
  }

  template <typename F>
  void node_query(int a, int b, F &f) {
    int l = lca(a, b);
    assert(l != -1);
    f(down[l], down[a] + 1);
    f(down[l] + 1, down[b] + 1);
  }

  template <typename F>
  void edge_query(int a, int b, F &f) {
    int l = lca(a, b);
    assert(l != -1);
    f(down[l] + 1, down[a] + 1);
    f(down[l] + 1, down[b] + 1);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 306, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: tree/euler-tour.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

