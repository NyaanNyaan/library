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


# :heavy_check_mark: tree/heavy-light-decomposition.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/heavy-light-decomposition.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-27 00:00:31+09:00




## Depends on

* :heavy_check_mark: <a href="../competitive-template.cpp.html">competitive-template.cpp</a>
* :heavy_check_mark: <a href="../graph/graph-template.cpp.html">graph/graph-template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify-aoj-dsl/aoj-dsl-3-d-cartesiantree.test.cpp.html">verify-aoj-dsl/aoj-dsl-3-d-cartesiantree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-aoj-grl/aoj-grl-5-c.test.cpp.html">verify-aoj-grl/aoj-grl-5-c.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-aoj-grl/aoj-grl-5-d.test.cpp.html">verify-aoj-grl/aoj-grl-5-d.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

#include "../graph/graph-template.cpp"

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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: tree/heavy-light-decomposition.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

