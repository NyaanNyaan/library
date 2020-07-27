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


# :warning: tree/dsu-on-tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/dsu-on-tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 03:32:31+09:00




## Depends on

* :question: <a href="../competitive-template.hpp.html">competitive-template.hpp</a>
* :question: <a href="../graph/graph-template.hpp.html">graph/graph-template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.hpp"
#endif

#include "../graph/graph-template.hpp"

template <typename G, typename UPDATE, typename QUERY, typename CLEAR,
          typename RESET>
struct DSUonTree {
  G &g;
  int N;
  vector<int> sub_sz, euler, li, ri;
  int idx;
  UPDATE &update;
  QUERY &query;
  CLEAR &clear;
  RESET &reset;

  DSUonTree(G &_g, UPDATE &_update, QUERY &_query, CLEAR &_clear, RESET &_reset)
      : g(_g),
        N(_g.size()),
        sub_sz(_g.size()),
        euler(_g.size()),
        li(_g.size()),
        ri(_g.size()),
        idx(0),
        update(_update),
        query(_query),
        clear(_clear),
        reset(_reset) {
    dfs1();
    dfs2();
  }

  int dfs1(int cur = 0, int par = -1) {
    sub_sz[cur] = 1;
    if ((int)g[cur].size() >= 2 and g[cur][0] == par) {
      swap(g[cur][0], g[cur][1]);
    }
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      sub_sz[cur] += dfs1(dst, cur);
      if (sub_sz[dst] > sub_sz[g[cur][0]]) swap(dst, g[cur][0]);
    }
    return sub_sz[cur];
  }

  void dfs2(int cur = 0, int par = -1) {
    euler[idx] = cur;
    li[cur] = idx++;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      dfs2(dst, cur);
    }
    ri[cur] = idx;
  }

  void dsu(int cur = 0, int par = -1, int keep = 1) {
    // light edge -> run dfs and clear data
    for (int i = 1; i < (int)g[cur].size(); i++)
      if (g[cur][i] != par) dsu(g[cur][i], cur, false);

    // heavy edge -> run dfs and reserve data
    if (sub_sz[cur] != 1) dsu(g[cur][0], cur, true);

    // light edge -> reserve data
    if (sub_sz[cur] != 1)
      for (int i = ri[g[cur][0]]; i < ri[cur]; i++) update(euler[i]);

    // current node -> reserve data
    update(cur);

    // answer queries related to subtree of current node
    query(cur);

    // if keep is false, clear all data
    if (!keep) {
      for (int i = li[cur]; i < ri[cur]; i++) clear(euler[i]);
      reset();
    }
    return;
  }

  void run() { dsu(); }
};

/*
  // reflect data of node i
  auto update = [&](int i) {

  };
  // answer queries of subtree i
  auto query = [&](int i) {

  };
  // below two function are called if all data must be deleted
  // delete data of node i (if necesarry)
  auto clear = [&](int i) {

  };
  // delete data related to all (if necesarry)
  auto reset = [&]() {

  };
  DSUonTree<decltype(g), decltype(update), decltype(query), decltype(clear),
            decltype(reset)>
      dsu(g, update, query, clear, reset);
  dsu.run();
*/
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: tree/dsu-on-tree.hpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

