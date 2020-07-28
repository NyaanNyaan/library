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


# :warning: string/subsequence-dp.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/subsequence-dp.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> CalcNext(const string &S, char offset = 'a', int w = 26) {
  int n = (int)S.size();
  vector<vector<int>> res(n + 1, vector<int>(w, n));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < w; ++j) res[i][j] = res[i + 1][j];
    res[i][S[i] - offset] = i;
  }
  return res;
};

template <typename T>
vector<T> SubSequenceDP(const string &S, char offset = 'a', int w = 26) {
  auto nxt = CalcNext(S, offset, w);
  int n = S.size();
  vector<T> dp(n + 1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < w; j++) {
      if (nxt[i][j] >= n) continue;
      dp[nxt[i][j] + 1] += dp[i];
    }
  }
  dp.erase(begin(dp));
  return dp;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "string/subsequence-dp.hpp"
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> CalcNext(const string &S, char offset = 'a', int w = 26) {
  int n = (int)S.size();
  vector<vector<int>> res(n + 1, vector<int>(w, n));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < w; ++j) res[i][j] = res[i + 1][j];
    res[i][S[i] - offset] = i;
  }
  return res;
};

template <typename T>
vector<T> SubSequenceDP(const string &S, char offset = 'a', int w = 26) {
  auto nxt = CalcNext(S, offset, w);
  int n = S.size();
  vector<T> dp(n + 1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < w; j++) {
      if (nxt[i][j] >= n) continue;
      dp[nxt[i][j] + 1] += dp[i];
    }
  }
  dp.erase(begin(dp));
  return dp;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

