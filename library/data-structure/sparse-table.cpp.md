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


# :heavy_check_mark: data-structure/sparse-table.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/sparse-table.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-24 20:19:03+09:00




## Depends on

* :question: <a href="../competitive-template.cpp.html">competitive-template.cpp</a>


## Required by

* :heavy_check_mark: <a href="../string/suffix-array.cpp.html">string/suffix-array.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify-yosupo-ds/yosupo-static-rmq.test.cpp.html">verify-yosupo-ds/yosupo-static-rmq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-yosupo-other/yosupo-number-of-substrings.test.cpp.html">verify-yosupo-other/yosupo-number-of-substrings.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-yosupo-other/yosupo-suffix-array.test.cpp.html">verify-yosupo-other/yosupo-suffix-array.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-yosupo-other/yosupo-zalgo-suffixarray.test.cpp.html">verify-yosupo-other/yosupo-zalgo-suffixarray.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

template <typename T>
struct SparseTable {
  vector<vector<T> > table;
  vector<int> log_table;

  inline T f(T a, T b) { return min(a, b); }

  SparseTable(const vector<T> &v) {
    int b = 0;
    while ((1 << b) <= (int)v.size()) ++b;
    table.assign(b, vector<T>(1 << b));
    for (int i = 0; i < (int)v.size(); i++) {
      table[0][i] = v[i];
    }
    for (int i = 1; i < b; i++) {
      for (int j = 0; j + (1 << i) <= (1 << b); j++) {
        table[i][j] = f(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
    log_table.resize(v.size() + 1);
    for (int i = 2; i < (int)log_table.size(); i++) {
      log_table[i] = log_table[i >> 1] + 1;
    }
  }

  // [l, r)
  inline T query(int l, int r) {
    int b = log_table[r - l];
    return f(table[b][l], table[b][r - (1 << b)]);
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data-structure/sparse-table.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

