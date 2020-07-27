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


# :warning: string/run-length-encoding.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/run-length-encoding.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 03:32:31+09:00




## Depends on

* :heavy_check_mark: <a href="../competitive-template.hpp.html">competitive-template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.hpp"
#endif

vector<pair<char, int>> RunLengthEncoding(string& S) {
  vector<pair<char, int>> ret;
  char c = -1;
  int n = 0;
  for (char x : S) {
    if (c == x)
      n++;
    else {
      if (n) ret.emplace_back(c, n);
      c = x, n = 1;
    }
  }
  if (n) ret.emplace_back(c, n);
  return ret;
}

template <typename T>
vector<pair<T, int>> RunLengthEncoding(vector<T>& S) {
  vector<pair<T, int>> ret;
  T c = -1;
  int n = 0;
  for (T& x : S) {
    if (c == x)
      n++;
    else {
      if (n) ret.emplace_back(c, n);
      c = x, n = 1;
    }
  }
  if (n) ret.emplace_back(c, n);
  return ret;
}
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/run-length-encoding.hpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

