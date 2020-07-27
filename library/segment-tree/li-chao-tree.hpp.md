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


# :warning: segment-tree/li-chao-tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cf992883f659a62542b674f4570b728a">segment-tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/segment-tree/li-chao-tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 03:32:31+09:00




## Depends on

* :question: <a href="../competitive-template.hpp.html">competitive-template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.hpp"
#endif

template <typename T, T INF>
struct LiChaoTree {
  struct Line {
    T slope, intercept;
    Line(T slope, T intercept) : slope(slope), intercept(intercept) {}
    inline T get(T x) const { return slope * x + intercept; }
    inline bool over(const Line &other, const T &x) const {
      return get(x) < other.get(x);
    }
  };

  // remind セグ木は0-indexedの実装
  vector<T> xset;
  vector<Line> seg;
  int _size;

  // 引数xにはx座標の集合を入れる
  LiChaoTree(const vector<T> &x) : xset(x) {
    sort(xset.begin(), xset.end());
    xset.erase(unique(xset.begin(), xset.end()), xset.end());
    _size = 1;
    while (_size < (int)xset.size()) _size <<= 1;
    while ((int)xset.size() < _size) xset.push_back(xset.back() + 1);
    seg.assign(2 * _size, Line(0, INF));
  }

  // 以上 xset[max]以下であることを仮定
  int get_more_idx(T k) {
    return lower_bound(xset.begin(), xset.end(), k) - xset.begin();
  }
  // 以下 xset[0]以上であることを仮定
  int get_less_idx(T k) {
    int ret = upper_bound(xset.begin(), xset.end(), k) - xset.begin();
    return max(0, ret - 1);
  }

  // 内部用
  void inner_update(T a, T b, int left, int right, int seg_idx) {
    Line line(a, b);
    while (1) {
      int mid = (left + right) >> 1;
      bool l_over = line.over(seg[seg_idx], xset[left]);
      bool r_over = line.over(seg[seg_idx], xset[right - 1]);
      if (l_over == r_over) {
        if (l_over) swap(seg[seg_idx], line);
        return;
      }
      bool m_over = line.over(seg[seg_idx], xset[mid]);
      if (m_over) swap(seg[seg_idx], line);
      if (l_over != m_over)
        seg_idx = (seg_idx << 1), right = mid;
      else
        seg_idx = (seg_idx << 1) | 1, left = mid;
    }
  }

  // 内部用
  void inner_update(T a, T b, int seg_idx) {
    int left, right;
    int upper_bit = 31 - __builtin_clz(seg_idx);
    left = (_size >> upper_bit) * (seg_idx - (1 << upper_bit));
    right = left + (_size >> upper_bit);
    inner_update(a, b, left, right, seg_idx);
  }

  // y = ax + bなる直線を追加
  void update(T a, T b) { inner_update(a, b, 0, _size, 1); }

  // 閉区間x in [left , right]に線分y = ax + bを追加するクエリ
  void update_line_segment(T a, T b, T low, T high) {
    int left = get_more_idx(low) + _size;
    int right = get_less_idx(high) + _size + 1;
    for (; left < right; left >>= 1, right >>= 1) {
      if (left & 1) inner_update(a, b, left++);
      if (right & 1) inner_update(a, b, --right);
    }
  }

  T inner_query(int x, int segidx) {
    T ret = seg[segidx].get(x);
    while (segidx > 1) {
      segidx = segidx >> 1;
      ret = min(ret, seg[segidx].get(x));
    }
    return ret;
  }

  // x = xset[k]なる点における最小値クエリ
  T query_idx(int k) {
    const T x = xset[k];
    k += _size;
    return inner_query(x, k);
  }

  // xにおける最小クエリ
  T query(T x) { return query_idx(get_more_idx(x)); }
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: segment-tree/li-chao-tree.hpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

