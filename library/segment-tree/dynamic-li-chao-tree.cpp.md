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


# :warning: segment-tree/dynamic-li-chao-tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cf992883f659a62542b674f4570b728a">segment-tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/segment-tree/dynamic-li-chao-tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-24 20:19:03+09:00




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

template <typename T, T INF>
struct DynamicLiChaoTree {
  struct Line {
    T slope, intercept;
    Line() : slope(0), intercept(INF) {}
    Line(T slope, T intercept) : slope(slope), intercept(intercept) {}
    inline T get(T x) const { return slope * x + intercept; }
    inline bool over(const Line &other, const T &x) const {
      return get(x) < other.get(x);
    }
  };

  // remind セグ木は1-indexedの実装
  T xmin, xmax, _size;
  unordered_map<T, Line> seg;

  // [l , r]におけるLi Chao Tree
  DynamicLiChaoTree(T xmin, T xmax) : xmin(xmin), xmax(xmax) {
    _size = 1;
    while (_size < xmax - xmin + 1) _size <<= 1;
  }

  // 内部用の関数
  void update(T a, T b, T left, T right, T seg_idx) {
    Line line(a, b);
    while (1) {
      T mid = (left + right) >> 1;
      bool l_over = line.over(seg[seg_idx], min(xmax, left + xmin));
      bool r_over = line.over(seg[seg_idx], min(xmax, right - 1 + xmin));
      if (l_over == r_over) {
        if (l_over) swap(seg[seg_idx], line);
        return;
      }
      bool m_over = line.over(seg[seg_idx], min(xmax, mid + xmin));
      if (m_over) swap(seg[seg_idx], line);
      if (l_over != m_over)
        seg_idx = (seg_idx << 1), right = mid;
      else
        seg_idx = (seg_idx << 1) | 1, left = mid;
    }
  }
  // 内部用の関数
  void update(T a, T b, T seg_idx) {
    T left, right;
    T upper_bit = 63 - __builtin_clzll(seg_idx);
    left = (_size >> upper_bit) * (seg_idx - (1 << upper_bit));
    right = left + (_size >> upper_bit);
    update(a, b, left, right, seg_idx);
  }
  /*
  void update(T a,T b,T left,T right){
    T lower_bit = (left | right) & (- (left | right) );
    T seg_idx = ( _size + left ) / lower_bit;
    update(a , b , left , right , seg_idx);
  }
  */
  // y = ax + bなる直線を追加
  void update(T a, T b) { update(a, b, 0, _size, 1); }

  // 閉区間x in [left , right]に線分y = ax + bを追加するクエリ
  void update_line_segment(T a, T b, T left, T right) {
    left -= xmin - _size, right -= xmin - _size - 1;
    for (; left < right; left >>= 1, right >>= 1) {
      if (left & 1) update(a, b, left++);
      if (right & 1) update(a, b, --right);
    }
  }

  // xにおける最小値クエリ
  T query(T x) {
    T left = 0, right = _size, seg_idx = 1, idx = x - xmin, ret = INF;
    while (1) {
      T cur = seg[seg_idx].get(x);
      // 線分追加クエリがない場合はここのコメントアウトを外して高速化可能(1.5倍程度？)
      // if(cur == INF) break;
      ret = min(ret, cur);
      if (left + 1 >= right) break;
      T mid = (left + right) >> 1;
      if (idx < mid)
        seg_idx = (seg_idx << 1), right = mid;
      else
        seg_idx = (seg_idx << 1) | 1, left = mid;
    }
    return ret;
  }

  void merge(DynamicLiChaoTree<T, INF> &other) {
    if (seg.size() < other.seg.size()) seg.swap(other.seg);
    for (auto &x : other.seg) {
      if (x.second.intercept == INF) continue;
      update(x.second.slope, x.second.intercept, x.first);
    }
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: segment-tree/dynamic-li-chao-tree.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

