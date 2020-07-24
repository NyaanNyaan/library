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


# :warning: string/run-length-encoding.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/run-length-encoding.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-24 09:47:03+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
#line 1 "string/run-length-encoding.cpp"
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

<a href="../../index.html">Back to top page</a>

