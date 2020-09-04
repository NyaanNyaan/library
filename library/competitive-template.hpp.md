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
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :heavy_check_mark: competitive-template.hpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/competitive-template.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Required by

* :warning: <a href="arbitrary-length-test.cpp.html">arbitrary-length-test.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-1-a-dynamic.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-1-a-dynamic.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-1-a.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-1-a.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-1-b.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-1-b.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-2-a-segtree.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-2-a-segtree.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-2-b-bit.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-2-b-bit.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-2-b-segtree.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-2-b-segtree.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-2-d.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-2-d.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-2-e-imos.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-2-e-imos.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-2-e.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-2-e.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-2-f-max.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-2-f-max.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-2-f.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-2-f.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-2-g.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-2-g.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-2-h-max.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-2-h-max.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-2-h.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-2-h.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-2-i.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-2-i.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-3-d-cartesiantree.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-3-d-cartesiantree.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-3-d.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-3-d.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-5-b-bit2d.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-5-b-bit2d.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-dsl/aoj-dsl-5-b.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-5-b.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-grl/aoj-grl-1-a.test.cpp.html">verify/verify-aoj-grl/aoj-grl-1-a.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-grl/aoj-grl-1-b.test.cpp.html">verify/verify-aoj-grl/aoj-grl-1-b.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-grl/aoj-grl-1-c.test.cpp.html">verify/verify-aoj-grl/aoj-grl-1-c.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-grl/aoj-grl-2-a.test.cpp.html">verify/verify-aoj-grl/aoj-grl-2-a.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-grl/aoj-grl-3-a.test.cpp.html">verify/verify-aoj-grl/aoj-grl-3-a.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-grl/aoj-grl-3-b.test.cpp.html">verify/verify-aoj-grl/aoj-grl-3-b.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-grl/aoj-grl-3-c.test.cpp.html">verify/verify-aoj-grl/aoj-grl-3-c.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-grl/aoj-grl-4-a.test.cpp.html">verify/verify-aoj-grl/aoj-grl-4-a.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-grl/aoj-grl-4-b.test.cpp.html">verify/verify-aoj-grl/aoj-grl-4-b.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-grl/aoj-grl-5-a-rerooting.test.cpp.html">verify/verify-aoj-grl/aoj-grl-5-a-rerooting.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-grl/aoj-grl-5-a.test.cpp.html">verify/verify-aoj-grl/aoj-grl-5-a.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-grl/aoj-grl-5-b.test.cpp.html">verify/verify-aoj-grl/aoj-grl-5-b.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-grl/aoj-grl-5-c.test.cpp.html">verify/verify-aoj-grl/aoj-grl-5-c.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-grl/aoj-grl-5-d.test.cpp.html">verify/verify-aoj-grl/aoj-grl-5-d.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-grl/aoj-grl-5-e.test.cpp.html">verify/verify-aoj-grl/aoj-grl-5-e.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-ntl/aoj-ntl-1-a.test.cpp.html">verify/verify-aoj-ntl/aoj-ntl-1-a.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-ntl/aoj-ntl-1-b.test.cpp.html">verify/verify-aoj-ntl/aoj-ntl-1-b.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-ntl/aoj-ntl-1-c.test.cpp.html">verify/verify-aoj-ntl/aoj-ntl-1-c.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-ntl/aoj-ntl-1-d.test.cpp.html">verify/verify-aoj-ntl/aoj-ntl-1-d.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-aoj-ntl/aoj-ntl-1-e.test.cpp.html">verify/verify-aoj-ntl/aoj-ntl-1-e.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ds/yosupo-binary-trie.test.cpp.html">verify/verify-yosupo-ds/yosupo-binary-trie.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ds/yosupo-lazysegtree.test.cpp.html">verify/verify-yosupo-ds/yosupo-lazysegtree.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ds/yosupo-line-add-get-min.test.cpp.html">verify/verify-yosupo-ds/yosupo-line-add-get-min.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ds/yosupo-persistent-queue.test.cpp.html">verify/verify-yosupo-ds/yosupo-persistent-queue.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ds/yosupo-persistent-unionfind.test.cpp.html">verify/verify-yosupo-ds/yosupo-persistent-unionfind.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ds/yosupo-point-add-range-sum.test.cpp.html">verify/verify-yosupo-ds/yosupo-point-add-range-sum.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp.html">verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp.html">verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp.html">verify/verify-yosupo-ds/yosupo-segment-add-get-min.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp.html">verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ds/yosupo-static-rmq.test.cpp.html">verify/verify-yosupo-ds/yosupo-static-rmq.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ds/yosupo-swag.test.cpp.html">verify/verify-yosupo-ds/yosupo-swag.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ds/yosupo-vertex-add-path-sum.test.cpp.html">verify/verify-yosupo-ds/yosupo-vertex-add-path-sum.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp.html">verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp.html">verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-fps/yosupo-composition.test.cpp.html">verify/verify-yosupo-fps/yosupo-composition.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-fps/yosupo-exp-arb.test.cpp.html">verify/verify-yosupo-fps/yosupo-exp-arb.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-fps/yosupo-exp.test.cpp.html">verify/verify-yosupo-fps/yosupo-exp.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-fps/yosupo-interpolation.test.cpp.html">verify/verify-yosupo-fps/yosupo-interpolation.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-fps/yosupo-inv-arb.test.cpp.html">verify/verify-yosupo-fps/yosupo-inv-arb.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-fps/yosupo-inv.test.cpp.html">verify/verify-yosupo-fps/yosupo-inv.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp.html">verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-fps/yosupo-log-arb.test.cpp.html">verify/verify-yosupo-fps/yosupo-log-arb.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-fps/yosupo-log.test.cpp.html">verify/verify-yosupo-fps/yosupo-log.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-fps/yosupo-multieval.test.cpp.html">verify/verify-yosupo-fps/yosupo-multieval.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-fps/yosupo-pow-arb.test.cpp.html">verify/verify-yosupo-fps/yosupo-pow-arb.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-fps/yosupo-pow.test.cpp.html">verify/verify-yosupo-fps/yosupo-pow.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-fps/yosupo-sqrt.test.cpp.html">verify/verify-yosupo-fps/yosupo-sqrt.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp.html">verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp.html">verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp.html">verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-graph/yosupo-cartesian.test.cpp.html">verify/verify-yosupo-graph/yosupo-cartesian.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-graph/yosupo-diameter.test.cpp.html">verify/verify-yosupo-graph/yosupo-diameter.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp.html">verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-graph/yosupo-lowest-common-ancestor.test.cpp.html">verify/verify-yosupo-graph/yosupo-lowest-common-ancestor.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-graph/yosupo-max-independent-set.test.cpp.html">verify/verify-yosupo-graph/yosupo-max-independent-set.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-graph/yosupo-shortest-path.test.cpp.html">verify/verify-yosupo-graph/yosupo-shortest-path.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-graph/yosupo-strongly-connected-components.test.cpp.html">verify/verify-yosupo-graph/yosupo-strongly-connected-components.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-graph/yosupo-two-edge-cc.test.cpp.html">verify/verify-yosupo-graph/yosupo-two-edge-cc.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp.html">verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-math/yosupo-counting-primes.test.cpp.html">verify/verify-yosupo-math/yosupo-counting-primes.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-math/yosupo-determinant.test.cpp.html">verify/verify-yosupo-math/yosupo-determinant.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-math/yosupo-factrization.test.cpp.html">verify/verify-yosupo-math/yosupo-factrization.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-math/yosupo-kth-root-integral.test.cpp.html">verify/verify-yosupo-math/yosupo-kth-root-integral.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-math/yosupo-linear-equation.test.cpp.html">verify/verify-yosupo-math/yosupo-linear-equation.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-math/yosupo-mod-log.test.cpp.html">verify/verify-yosupo-math/yosupo-mod-log.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp.html">verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-math/yosupo-prime-table.test.cpp.html">verify/verify-yosupo-math/yosupo-prime-table.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-math/yosupo-sparse-determinant.test.cpp.html">verify/verify-yosupo-math/yosupo-sparse-determinant.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-math/yosupo-subset-convolution.test.cpp.html">verify/verify-yosupo-math/yosupo-subset-convolution.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-math/yosupo-sum-of-floor.test.cpp.html">verify/verify-yosupo-math/yosupo-sum-of-floor.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-math/yosupo-sum-of-totient.test.cpp.html">verify/verify-yosupo-math/yosupo-sum-of-totient.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-math/yosupo-tetration-mod.test.cpp.html">verify/verify-yosupo-math/yosupo-tetration-mod.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-math/yosupo-two-sat.test.cpp.html">verify/verify-yosupo-math/yosupo-two-sat.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp.html">verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitrarymodint.test.cpp.html">verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitrarymodint.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitraryprimemodint.test.cpp.html">verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitraryprimemodint.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt.test.cpp.html">verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ntt/yosupo-convolution-ntt-avx2.test.cpp.html">verify/verify-yosupo-ntt/yosupo-convolution-ntt-avx2.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ntt/yosupo-convolution-ntt-normalmodint.test.cpp.html">verify/verify-yosupo-ntt/yosupo-convolution-ntt-normalmodint.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ntt/yosupo-convolution-ntt-sse42.test.cpp.html">verify/verify-yosupo-ntt/yosupo-convolution-ntt-sse42.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-ntt/yosupo-convolution-ntt.test.cpp.html">verify/verify-yosupo-ntt/yosupo-convolution-ntt.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-other/yosupo-a-plus-b.test.cpp.html">verify/verify-yosupo-other/yosupo-a-plus-b.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-other/yosupo-argument-sort.test.cpp.html">verify/verify-yosupo-other/yosupo-argument-sort.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-other/yosupo-many-a-plus-b.test.cpp.html">verify/verify-yosupo-other/yosupo-many-a-plus-b.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-other/yosupo-number-of-substrings.test.cpp.html">verify/verify-yosupo-other/yosupo-number-of-substrings.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-other/yosupo-suffix-array.test.cpp.html">verify/verify-yosupo-other/yosupo-suffix-array.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yosupo-other/yosupo-zalgo-suffixarray.test.cpp.html">verify/verify-yosupo-other/yosupo-zalgo-suffixarray.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yuki/yuki-0214.test.cpp.html">verify/verify-yuki/yuki-0214.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yuki/yuki-0215.test.cpp.html">verify/verify-yuki/yuki-0215.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yuki/yuki-0789.test.cpp.html">verify/verify-yuki/yuki-0789.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yuki/yuki-0875-binary-search-on-segtree.test.cpp.html">verify/verify-yuki/yuki-0875-binary-search-on-segtree.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yuki/yuki-0963-circular.test.cpp.html">verify/verify-yuki/yuki-0963-circular.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yuki/yuki-0963.test.cpp.html">verify/verify-yuki/yuki-0963.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yuki/yuki-1080.test.cpp.html">verify/verify-yuki/yuki-1080.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yuki/yuki-1145.test.cpp.html">verify/verify-yuki/yuki-1145.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yuki/yuki-1170.test.cpp.html">verify/verify-yuki/yuki-1170.test.cpp</a>
* :heavy_check_mark: <a href="../verify/verify/verify-yuki/yuki-1220.test.cpp.html">verify/verify-yuki/yuki-1220.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma region kyopro_template
#define Nyaan_template
#include <immintrin.h>
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define each(x, v) for (auto &x : v)
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define mem(a, val) memset(a, val, sizeof(a))
#define ini(...)   \
  int __VA_ARGS__; \
  in(__VA_ARGS__)
#define inl(...)         \
  long long __VA_ARGS__; \
  in(__VA_ARGS__)
#define ins(...)      \
  string __VA_ARGS__; \
  in(__VA_ARGS__)
#define inc(...)    \
  char __VA_ARGS__; \
  in(__VA_ARGS__)
#define in2(s, t)                           \
  for (int i = 0; i < (int)s.size(); i++) { \
    in(s[i], t[i]);                         \
  }
#define in3(s, t, u)                        \
  for (int i = 0; i < (int)s.size(); i++) { \
    in(s[i], t[i], u[i]);                   \
  }
#define in4(s, t, u, v)                     \
  for (int i = 0; i < (int)s.size(); i++) { \
    in(s[i], t[i], u[i], v[i]);             \
  }
#define rep(i, N) for (long long i = 0; i < (long long)(N); i++)
#define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)
#define rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)
#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)
#define reg(i, a, b) for (long long i = (a); i < (b); i++)
#define die(...)      \
  do {                \
    out(__VA_ARGS__); \
    return;           \
  } while (0)
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vector<int>>;
using vd = V<double>;
using vs = V<string>;
using vvl = vector<vector<long long>>;
using P = pair<long long, long long>;
using vp = vector<P>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;
constexpr int inf = 1001001001;
constexpr long long infLL = (1LL << 61) - 1;
template <typename T, typename U>
inline bool amin(T &x, U y) {
  return (y < x) ? (x = y, true) : false;
}
template <typename T, typename U>
inline bool amax(T &x, U y) {
  return (x < y) ? (x = y, true) : false;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << p.first << " " << p.second;
  return os;
}
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  int s = (int)v.size();
  for (int i = 0; i < s; i++) os << (i ? " " : "") << v[i];
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}
void in() {}
template <typename T, class... U>
void in(T &t, U &... u) {
  cin >> t;
  in(u...);
}
void out() { cout << "\n"; }
template <typename T, class... U>
void out(const T &t, const U &... u) {
  cout << t;
  if (sizeof...(u)) cout << " ";
  out(u...);
}

#ifdef NyaanDebug
#define trc(...)                   \
  do {                             \
    cerr << #__VA_ARGS__ << " = "; \
    dbg_out(__VA_ARGS__);          \
  } while (0)
#define trca(v, N)       \
  do {                   \
    cerr << #v << " = "; \
    array_out(v, N);     \
  } while (0)
#define trcc(v)                             \
  do {                                      \
    cerr << #v << " = {";                   \
    each(x, v) { cerr << " " << x << ","; } \
    cerr << "}" << endl;                    \
  } while (0)
template <typename T>
void _cout(const T &c) {
  cerr << c;
}
void _cout(const int &c) {
  if (c == 1001001001)
    cerr << "inf";
  else if (c == -1001001001)
    cerr << "-inf";
  else
    cerr << c;
}
void _cout(const unsigned int &c) {
  if (c == 1001001001)
    cerr << "inf";
  else
    cerr << c;
}
void _cout(const long long &c) {
  if (c == 1001001001 || c == (1LL << 61) - 1)
    cerr << "inf";
  else if (c == -1001001001 || c == -((1LL << 61) - 1))
    cerr << "-inf";
  else
    cerr << c;
}
void _cout(const unsigned long long &c) {
  if (c == 1001001001 || c == (1LL << 61) - 1)
    cerr << "inf";
  else
    cerr << c;
}
template <typename T, typename U>
void _cout(const pair<T, U> &p) {
  cerr << "{ ";
  _cout(p.fi);
  cerr << ", ";
  _cout(p.se);
  cerr << " } ";
}
template <typename T>
void _cout(const vector<T> &v) {
  int s = v.size();
  cerr << "{ ";
  for (int i = 0; i < s; i++) {
    cerr << (i ? ", " : "");
    _cout(v[i]);
  }
  cerr << " } ";
}
template <typename T>
void _cout(const vector<vector<T>> &v) {
  cerr << "[ ";
  for (const auto &x : v) {
    cerr << endl;
    _cout(x);
    cerr << ", ";
  }
  cerr << endl << " ] ";
}
void dbg_out() { cerr << endl; }
template <typename T, class... U>
void dbg_out(const T &t, const U &... u) {
  _cout(t);
  if (sizeof...(u)) cerr << ", ";
  dbg_out(u...);
}
template <typename T>
void array_out(const T &v, int s) {
  cerr << "{ ";
  for (int i = 0; i < s; i++) {
    cerr << (i ? ", " : "");
    _cout(v[i]);
  }
  cerr << " } " << endl;
}
template <typename T>
void array_out(const T &v, int H, int W) {
  cerr << "[ ";
  for (int i = 0; i < H; i++) {
    cerr << (i ? ", " : "");
    array_out(v[i], W);
  }
  cerr << " ] " << endl;
}
#else
#define trc(...)
#define trca(...)
#define trcc(...)
#endif

inline int popcnt(unsigned long long a) { return __builtin_popcountll(a); }
inline int lsb(unsigned long long a) { return __builtin_ctzll(a); }
inline int msb(unsigned long long a) { return 63 - __builtin_clzll(a); }
template <typename T>
inline int getbit(T a, int i) {
  return (a >> i) & 1;
}
template <typename T>
inline void setbit(T &a, int i) {
  a |= (1LL << i);
}
template <typename T>
inline void delbit(T &a, int i) {
  a &= ~(1LL << i);
}
template <typename T>
int lb(const vector<T> &v, const T &a) {
  return lower_bound(begin(v), end(v), a) - begin(v);
}
template <typename T>
int ub(const vector<T> &v, const T &a) {
  return upper_bound(begin(v), end(v), a) - begin(v);
}
template <typename T>
int btw(T a, T x, T b) {
  return a <= x && x < b;
}
template <typename T, typename U>
T ceil(T a, U b) {
  return (a + b - 1) / b;
}
constexpr long long TEN(int n) {
  long long ret = 1, x = 10;
  while (n) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}
template <typename T>
vector<T> mkrui(const vector<T> &v) {
  vector<T> ret(v.size() + 1);
  for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];
  return ret;
};
template <typename T>
vector<T> mkuni(const vector<T> &v) {
  vector<T> ret(v);
  sort(ret.begin(), ret.end());
  ret.erase(unique(ret.begin(), ret.end()), ret.end());
  return ret;
}
template <typename F>
vector<int> mkord(int N, F f) {
  vector<int> ord(N);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), f);
  return ord;
}
template <typename T = int>
vector<T> mkiota(int N) {
  vector<T> ret(N);
  iota(begin(ret), end(ret), 0);
  return ret;
}
template <typename T>
vector<int> mkinv(vector<T> &v) {
  vector<int> inv(v.size());
  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;
  return inv;
}

struct IoSetupNya {
  IoSetupNya() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(7);
  }
} iosetupnya;

void solve();
int main() { solve(); }

#pragma endregion
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "competitive-template.hpp"
#pragma region kyopro_template
#define Nyaan_template
#include <immintrin.h>
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define each(x, v) for (auto &x : v)
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define mem(a, val) memset(a, val, sizeof(a))
#define ini(...)   \
  int __VA_ARGS__; \
  in(__VA_ARGS__)
#define inl(...)         \
  long long __VA_ARGS__; \
  in(__VA_ARGS__)
#define ins(...)      \
  string __VA_ARGS__; \
  in(__VA_ARGS__)
#define inc(...)    \
  char __VA_ARGS__; \
  in(__VA_ARGS__)
#define in2(s, t)                           \
  for (int i = 0; i < (int)s.size(); i++) { \
    in(s[i], t[i]);                         \
  }
#define in3(s, t, u)                        \
  for (int i = 0; i < (int)s.size(); i++) { \
    in(s[i], t[i], u[i]);                   \
  }
#define in4(s, t, u, v)                     \
  for (int i = 0; i < (int)s.size(); i++) { \
    in(s[i], t[i], u[i], v[i]);             \
  }
#define rep(i, N) for (long long i = 0; i < (long long)(N); i++)
#define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)
#define rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)
#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)
#define reg(i, a, b) for (long long i = (a); i < (b); i++)
#define die(...)      \
  do {                \
    out(__VA_ARGS__); \
    return;           \
  } while (0)
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vector<int>>;
using vd = V<double>;
using vs = V<string>;
using vvl = vector<vector<long long>>;
using P = pair<long long, long long>;
using vp = vector<P>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;
constexpr int inf = 1001001001;
constexpr long long infLL = (1LL << 61) - 1;
template <typename T, typename U>
inline bool amin(T &x, U y) {
  return (y < x) ? (x = y, true) : false;
}
template <typename T, typename U>
inline bool amax(T &x, U y) {
  return (x < y) ? (x = y, true) : false;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << p.first << " " << p.second;
  return os;
}
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  int s = (int)v.size();
  for (int i = 0; i < s; i++) os << (i ? " " : "") << v[i];
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}
void in() {}
template <typename T, class... U>
void in(T &t, U &... u) {
  cin >> t;
  in(u...);
}
void out() { cout << "\n"; }
template <typename T, class... U>
void out(const T &t, const U &... u) {
  cout << t;
  if (sizeof...(u)) cout << " ";
  out(u...);
}

#ifdef NyaanDebug
#define trc(...)                   \
  do {                             \
    cerr << #__VA_ARGS__ << " = "; \
    dbg_out(__VA_ARGS__);          \
  } while (0)
#define trca(v, N)       \
  do {                   \
    cerr << #v << " = "; \
    array_out(v, N);     \
  } while (0)
#define trcc(v)                             \
  do {                                      \
    cerr << #v << " = {";                   \
    each(x, v) { cerr << " " << x << ","; } \
    cerr << "}" << endl;                    \
  } while (0)
template <typename T>
void _cout(const T &c) {
  cerr << c;
}
void _cout(const int &c) {
  if (c == 1001001001)
    cerr << "inf";
  else if (c == -1001001001)
    cerr << "-inf";
  else
    cerr << c;
}
void _cout(const unsigned int &c) {
  if (c == 1001001001)
    cerr << "inf";
  else
    cerr << c;
}
void _cout(const long long &c) {
  if (c == 1001001001 || c == (1LL << 61) - 1)
    cerr << "inf";
  else if (c == -1001001001 || c == -((1LL << 61) - 1))
    cerr << "-inf";
  else
    cerr << c;
}
void _cout(const unsigned long long &c) {
  if (c == 1001001001 || c == (1LL << 61) - 1)
    cerr << "inf";
  else
    cerr << c;
}
template <typename T, typename U>
void _cout(const pair<T, U> &p) {
  cerr << "{ ";
  _cout(p.fi);
  cerr << ", ";
  _cout(p.se);
  cerr << " } ";
}
template <typename T>
void _cout(const vector<T> &v) {
  int s = v.size();
  cerr << "{ ";
  for (int i = 0; i < s; i++) {
    cerr << (i ? ", " : "");
    _cout(v[i]);
  }
  cerr << " } ";
}
template <typename T>
void _cout(const vector<vector<T>> &v) {
  cerr << "[ ";
  for (const auto &x : v) {
    cerr << endl;
    _cout(x);
    cerr << ", ";
  }
  cerr << endl << " ] ";
}
void dbg_out() { cerr << endl; }
template <typename T, class... U>
void dbg_out(const T &t, const U &... u) {
  _cout(t);
  if (sizeof...(u)) cerr << ", ";
  dbg_out(u...);
}
template <typename T>
void array_out(const T &v, int s) {
  cerr << "{ ";
  for (int i = 0; i < s; i++) {
    cerr << (i ? ", " : "");
    _cout(v[i]);
  }
  cerr << " } " << endl;
}
template <typename T>
void array_out(const T &v, int H, int W) {
  cerr << "[ ";
  for (int i = 0; i < H; i++) {
    cerr << (i ? ", " : "");
    array_out(v[i], W);
  }
  cerr << " ] " << endl;
}
#else
#define trc(...)
#define trca(...)
#define trcc(...)
#endif

inline int popcnt(unsigned long long a) { return __builtin_popcountll(a); }
inline int lsb(unsigned long long a) { return __builtin_ctzll(a); }
inline int msb(unsigned long long a) { return 63 - __builtin_clzll(a); }
template <typename T>
inline int getbit(T a, int i) {
  return (a >> i) & 1;
}
template <typename T>
inline void setbit(T &a, int i) {
  a |= (1LL << i);
}
template <typename T>
inline void delbit(T &a, int i) {
  a &= ~(1LL << i);
}
template <typename T>
int lb(const vector<T> &v, const T &a) {
  return lower_bound(begin(v), end(v), a) - begin(v);
}
template <typename T>
int ub(const vector<T> &v, const T &a) {
  return upper_bound(begin(v), end(v), a) - begin(v);
}
template <typename T>
int btw(T a, T x, T b) {
  return a <= x && x < b;
}
template <typename T, typename U>
T ceil(T a, U b) {
  return (a + b - 1) / b;
}
constexpr long long TEN(int n) {
  long long ret = 1, x = 10;
  while (n) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}
template <typename T>
vector<T> mkrui(const vector<T> &v) {
  vector<T> ret(v.size() + 1);
  for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];
  return ret;
};
template <typename T>
vector<T> mkuni(const vector<T> &v) {
  vector<T> ret(v);
  sort(ret.begin(), ret.end());
  ret.erase(unique(ret.begin(), ret.end()), ret.end());
  return ret;
}
template <typename F>
vector<int> mkord(int N, F f) {
  vector<int> ord(N);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), f);
  return ord;
}
template <typename T = int>
vector<T> mkiota(int N) {
  vector<T> ret(N);
  iota(begin(ret), end(ret), 0);
  return ret;
}
template <typename T>
vector<int> mkinv(vector<T> &v) {
  vector<int> inv(v.size());
  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;
  return inv;
}

struct IoSetupNya {
  IoSetupNya() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(7);
  }
} iosetupnya;

void solve();
int main() { solve(); }

#pragma endregion

```
{% endraw %}

<a href="../index.html">Back to top page</a>

