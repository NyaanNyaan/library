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


# :warning: graph/dimension-expanded-graph.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dimension-expanded-graph.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-24 15:38:36+09:00




## Depends on

* :heavy_check_mark: <a href="../competitive-template.cpp.html">competitive-template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

template <int DIM>
struct DimensionExpandedGraph {
  using i64 = long long;
  using A = array<int, DIM>;

  int N;
  A g_size, coeff;

  template <typename... T>
  DimensionExpandedGraph(const T &... t) : N(1), g_size({t...}) {
    set_coeff();
  }

  void set_coeff() {
    coeff.fill(1);
    for (int i = 0; i < DIM; i++) {
      for (int j = 0; j < i; j++) coeff[j] *= g_size[i];
      N *= g_size[i];
    }
  }

  int id(const A &a) {
    int ret = 0;
    for (int i = 0; i < DIM; i++) ret += a[i] * coeff[i];
    return ret;
  }

  int id_(int, int n) { return n; }
  template <typename T, typename... U>
  int id_(int idx, int n, T &&t, U &&... u) {
    n += coeff[idx++] * t;
    return id_(idx, n, forward<U>(u)...);
  }
  template <typename... T>
  int id(const T &... t) {
    return id_(0, 0, t...);
  }

  int ok(const A &a) {
    for (int i = 0; i < DIM; i++)
      if (a[i] < 0 or g_size[i] <= a[i]) return 0;
    return 1;
  }

  int ok_(int) { return 1; }
  template <typename T, typename... U>
  int ok_(int idx, T &&t, U &&... u) {
    if (t < 0 or g_size[idx++] <= t) return 0;
    return ok_(idx, forward<U>(u)...);
  }
  template <typename... T>
  int ok(const T &... t) {
    return ok_(0, t...);
  }

  template <typename F>
  vector<i64> bfs(F f, A s = {}) {
    vector<i64> dist(N, -1);
    queue<A> Q;
    dist[id(s)] = 0;
    Q.push(s);
    while (!Q.empty()) {
      A c = Q.front();
      Q.pop();
      f(c, [&](A d) {
        if (dist[id(d)] == -1) {
          dist[id(d)] = dist[id(c)] + 1;
          Q.push(d);
        }
      });
    }
    return dist;
  }

  template <typename F>
  vector<i64> bfs01(F f, A s = {}) {
    vector<i64> dist(N, -1);
    deque<A> Q;
    dist[id(s)] = 0;
    Q.push_back(s);
    while (!Q.empty()) {
      A c = Q.front();
      Q.pop_front();
      f(c, [&](A d, i64 w) {
        if (dist[id(d)] == -1) {
          dist[id(d)] = dist[id(c)] + w;
          if (w == 0)
            Q.push_front(d);
          else
            Q.push_back(d);
        }
      });
    }
    return dist;
  }

  template <typename F>
  vector<i64> dijkstra(F f, A s = {}) {
    vector<i64> dist(N, -1);
    using P = pair<i64, A>;
    priority_queue<P, vector<P>, greater<P>> Q;
    Q.emplace(dist[id(s)] = 0, s);
    while (!Q.empty()) {
      i64 d;
      A c;
      tie(d, c) = Q.top();
      Q.pop();
      if (dist[id(c)] < d) continue;
      f(c, [&](A d, i64 w) {
        if (dist[id(d)] == -1 or dist[id(d)] > dist[id(c)] + w) {
          Q.emplace(dist[id(d)] = dist[id(c)] + w, d);
        }
      });
    }
    return dist;
  }
};

struct GridGraph : DimensionExpandedGraph<2> {
  vector<string> str;
  char ng;
  int is_8_direction;

  template <typename... T>
  GridGraph(const T &... t) : ng('#'), is_8_direction(false) {
    N = 1;
    g_size = A({t...});
    set_coeff();
  }

  operator vector<string> &() { return str; }

  template <typename F>
  void adjacent(P c, F f) {
    int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
    int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
    int i, j;
    tie(i, j) = c;
    for (int k = 0; k < is_8_direction ? 8 : 4; k++) {
      int di = i + dx[k], dj = dy[k];
      if (ok(di, dj) and str[di][dj] != ng) f(di, dj);
    }
  }

  template <typename F>
  vector<i64> bfs(F f, A s = {}){
    vector<i64> dist(N, -1);
    queue<A> Q;
    dist[id(s)] = 0;
    Q.push(s);
    while (!Q.empty()) {
      A c = Q.front();
      Q.pop();
      adjacent(c, [&](A d) {
        if (dist[id(d)] == -1) {
          dist[id(d)] = dist[id(c)] + 1;
          Q.push(d);
        }
      });
    }
    return dist;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/dimension-expanded-graph.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

