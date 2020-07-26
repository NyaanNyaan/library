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


# :heavy_check_mark: tree/rerooting.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/rerooting.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-27 00:33:16+09:00




## Depends on

* :heavy_check_mark: <a href="../competitive-template.cpp.html">competitive-template.cpp</a>
* :heavy_check_mark: <a href="../graph/graph-template.cpp.html">graph/graph-template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify-aoj-grl/aoj-grl-5-b.test.cpp.html">verify-aoj-grl/aoj-grl-5-b.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

#include "../graph/graph-template.cpp"

// Rerooting
// f1(c1, c2) ... merge value of child node
// f2(memo[i], chd, par) ... return value from child node to parent node
// memo[i] ... result of subtree rooted i
// dp[i] ... result of tree rooted i
template <typename T, typename G, typename F1, typename F2>
struct Rerooting {
  const G &g;
  const F1 f1;
  const F2 f2;
  vector<T> memo, dp;
  T I;

  Rerooting(const G &g, const F1 f1, const F2 f2, const T &I)
      : g(g), f1(f1), f2(f2), memo(g.size(), I), dp(g.size(), I), I(I) {
    dfs(0, -1);
    efs(0, -1, I);
  }

  const T &operator[](int i) const { return dp[i]; }

  void dfs(int cur, int par) {
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      dfs(dst, cur);
      memo[cur] = f1(memo[cur], f2(memo[dst], dst, cur));
    }
  }

  void efs(int cur, int par, const T &pval) {
    // get cumulative sum
    vector<T> buf;
    for (auto dst : g[cur]) {
      if (dst == par) continue;
      buf.push_back(f2(memo[dst], dst, cur));
    }
    vector<T> head(buf.size() + 1), tail(buf.size() + 1);
    head[0] = tail[buf.size()] = I;
    for (int i = 0; i < (int)buf.size(); i++) head[i + 1] = f1(head[i], buf[i]);
    for (int i = (int)buf.size() - 1; i >= 0; i--)
      tail[i] = f1(tail[i + 1], buf[i]);

    // update
    dp[cur] = par == -1 ? head.back() : f1(pval, head.back());

    // propagate
    int idx = 0;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      efs(dst, cur, f2(f1(pval, f1(head[idx], tail[idx + 1])), cur, dst));
      idx++;
    }
  }
};

/*

using T = ;
// identify element of f1, and answer of leaf
T I = ;
// merge value of child node
auto f1 = [&](T x, T y) -> T {

};
// return value from child node to parent node
auto f2 = [&](T x, int chd, int par) -> T {

};
Rerooting<T, decltype(g), decltype(f1), decltype(f2)> dp(g, f1, f2, I);

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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: tree/rerooting.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

