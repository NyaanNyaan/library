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


# :heavy_check_mark: atcoder/two-sat.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#554e0d24f25abaa0e2922c944fbc560c">atcoder</a>
* <a href="{{ site.github.repository_url }}/blob/master/atcoder/two-sat.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 23:53:33+09:00




## Depends on

* :heavy_check_mark: <a href="internal_scc.hpp.html">atcoder/internal_scc.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-two-sat-atcoder.test.cpp.html">verify/verify-yosupo-math/yosupo-two-sat-atcoder.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <cassert>
#include <vector>

#include "internal_scc.hpp"

namespace atcoder {

// Reference:
// B. Aspvall, M. Plass, and R. Tarjan,
// A Linear-Time Algorithm for Testing the Truth of Certain Quantified Boolean
// Formulas
struct two_sat {
 public:
  two_sat() : _n(0), scc(0) {}
  two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

  void add_clause(int i, bool f, int j, bool g) {
    assert(0 <= i && i < _n);
    assert(0 <= j && j < _n);
    scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
    scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
  }
  bool satisfiable() {
    auto id = scc.scc_ids().second;
    for (int i = 0; i < _n; i++) {
      if (id[2 * i] == id[2 * i + 1]) return false;
      _answer[i] = id[2 * i] < id[2 * i + 1];
    }
    return true;
  }
  std::vector<bool> answer() { return _answer; }

 private:
  int _n;
  std::vector<bool> _answer;
  internal::scc_graph scc;
};

}  // namespace atcoder
using namespace atcoder;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "atcoder/two-sat.hpp"

#include <cassert>
#include <vector>

#line 2 "atcoder/internal_scc.hpp"
#include <algorithm>
#include <utility>
#line 5 "atcoder/internal_scc.hpp"

namespace atcoder {
namespace internal {

template <class E>
struct csr {
  std::vector<int> start;
  std::vector<E> elist;
  csr(int n, const std::vector<std::pair<int, E>>& edges)
      : start(n + 1), elist(edges.size()) {
    for (auto e : edges) {
      start[e.first + 1]++;
    }
    for (int i = 1; i <= n; i++) {
      start[i] += start[i - 1];
    }
    auto counter = start;
    for (auto e : edges) {
      elist[counter[e.first]++] = e.second;
    }
  }
};

// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
struct scc_graph {
 public:
  scc_graph(int n) : _n(n) {}

  int num_vertices() { return _n; }

  void add_edge(int from, int to) { edges.push_back({from, {to}}); }

  // @return pair of (# of scc, scc id)
  std::pair<int, std::vector<int>> scc_ids() {
    auto g = csr<edge>(_n, edges);
    int now_ord = 0, group_num = 0;
    std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
    visited.reserve(_n);
    auto dfs = [&](auto self, int v) -> void {
      low[v] = ord[v] = now_ord++;
      visited.push_back(v);
      for (int i = g.start[v]; i < g.start[v + 1]; i++) {
        auto to = g.elist[i].to;
        if (ord[to] == -1) {
          self(self, to);
          low[v] = std::min(low[v], low[to]);
        } else {
          low[v] = std::min(low[v], ord[to]);
        }
      }
      if (low[v] == ord[v]) {
        while (true) {
          int u = visited.back();
          visited.pop_back();
          ord[u] = _n;
          ids[u] = group_num;
          if (u == v) break;
        }
        group_num++;
      }
    };
    for (int i = 0; i < _n; i++) {
      if (ord[i] == -1) dfs(dfs, i);
    }
    for (auto& x : ids) {
      x = group_num - 1 - x;
    }
    return {group_num, ids};
  }

  std::vector<std::vector<int>> scc() {
    auto ids = scc_ids();
    int group_num = ids.first;
    std::vector<int> counts(group_num);
    for (auto x : ids.second) counts[x]++;
    std::vector<std::vector<int>> groups(ids.first);
    for (int i = 0; i < group_num; i++) {
      groups[i].reserve(counts[i]);
    }
    for (int i = 0; i < _n; i++) {
      groups[ids.second[i]].push_back(i);
    }
    return groups;
  }

 private:
  int _n;
  struct edge {
    int to;
  };
  std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder
#line 7 "atcoder/two-sat.hpp"

namespace atcoder {

// Reference:
// B. Aspvall, M. Plass, and R. Tarjan,
// A Linear-Time Algorithm for Testing the Truth of Certain Quantified Boolean
// Formulas
struct two_sat {
 public:
  two_sat() : _n(0), scc(0) {}
  two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

  void add_clause(int i, bool f, int j, bool g) {
    assert(0 <= i && i < _n);
    assert(0 <= j && j < _n);
    scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
    scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
  }
  bool satisfiable() {
    auto id = scc.scc_ids().second;
    for (int i = 0; i < _n; i++) {
      if (id[2 * i] == id[2 * i + 1]) return false;
      _answer[i] = id[2 * i] < id[2 * i + 1];
    }
    return true;
  }
  std::vector<bool> answer() { return _answer; }

 private:
  int _n;
  std::vector<bool> _answer;
  internal::scc_graph scc;
};

}  // namespace atcoder
using namespace atcoder;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

