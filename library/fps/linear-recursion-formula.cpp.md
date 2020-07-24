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


# :warning: fps/linear-recursion-formula.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05934928102b17827b8f03ed60c3e6e0">fps</a>
* <a href="{{ site.github.repository_url }}/blob/master/fps/linear-recursion-formula.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-24 15:06:06+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
modint LinearRecursionFormula(long long N, FPS Q, FPS P) {
  int k = Q.size() - 1;
  P.resize(k);
  while (N) {
    auto Q2 = Q;
    for (int i = 1; i < (int)Q2.size(); i += 2) Q2[i] = -Q2[i];
    auto S = P * Q2;
    auto T = Q * Q2;
    if (N & 1) {
      for (int i = 1; i < (int)S.size(); i += 2) P[i >> 1] = S[i];
      for (int i = 0; i < (int)T.size(); i += 2) Q[i >> 1] = T[i];
    } else {
      for (int i = 0; i < (int)S.size(); i += 2) P[i >> 1] = S[i];
      for (int i = 0; i < (int)T.size(); i += 2) Q[i >> 1] = T[i];
    }
    N >>= 1;
  }
  return P[0];
}

modint kitamasa(long long N, FPS Q, FPS a) {
  int k = Q.size() - 1;
  assert((int)a.size() == k);
  FPS P = a * Q;
  P.resize(Q.size() - 1);
  return LinearRecursionFormula(N, Q, P);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "fps/linear-recursion-formula.cpp"
modint LinearRecursionFormula(long long N, FPS Q, FPS P) {
  int k = Q.size() - 1;
  P.resize(k);
  while (N) {
    auto Q2 = Q;
    for (int i = 1; i < (int)Q2.size(); i += 2) Q2[i] = -Q2[i];
    auto S = P * Q2;
    auto T = Q * Q2;
    if (N & 1) {
      for (int i = 1; i < (int)S.size(); i += 2) P[i >> 1] = S[i];
      for (int i = 0; i < (int)T.size(); i += 2) Q[i >> 1] = T[i];
    } else {
      for (int i = 0; i < (int)S.size(); i += 2) P[i >> 1] = S[i];
      for (int i = 0; i < (int)T.size(); i += 2) Q[i >> 1] = T[i];
    }
    N >>= 1;
  }
  return P[0];
}

modint kitamasa(long long N, FPS Q, FPS a) {
  int k = Q.size() - 1;
  assert((int)a.size() == k);
  FPS P = a * Q;
  P.resize(Q.size() - 1);
  return LinearRecursionFormula(N, Q, P);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

