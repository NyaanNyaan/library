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


# :heavy_check_mark: fps/multipoint-evaluation.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05934928102b17827b8f03ed60c3e6e0">fps</a>
* <a href="{{ site.github.repository_url }}/blob/master/fps/multipoint-evaluation.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-02 00:26:11+09:00




## Depends on

* :heavy_check_mark: <a href="formal-power-series.hpp.html">多項式/形式的冪級数ライブラリ <small>(fps/formal-power-series.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-multieval.test.cpp.html">verify/verify-yosupo-fps/yosupo-multieval.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "./formal-power-series.hpp"

template <typename mint>
struct ProductTree {
  using fps = FormalPowerSeries<mint>;
  const vector<mint> &xs;
  vector<fps> buf;
  int N, xsz;
  vector<int> l, r;
  ProductTree(const vector<mint> &xs_) : xs(xs_), xsz(xs.size()) {
    N = 1;
    while (N < (int)xs.size()) N *= 2;
    buf.resize(2 * N);
    l.resize(2 * N, xs.size());
    r.resize(2 * N, xs.size());
    fps::set_fft();
    if (fps::ntt_ptr == nullptr)
      build();
    else
      build_ntt();
  }

  void build() {
    for (int i = 0; i < xsz; i++) {
      l[i + N] = i;
      r[i + N] = i + 1;
      buf[i + N] = {-xs[i], 1};
    }
    for (int i = N - 1; i > 0; i--) {
      l[i] = l[(i << 1) | 0];
      r[i] = r[(i << 1) | 1];
      if (buf[(i << 1) | 0].empty())
        continue;
      else if (buf[(i << 1) | 1].empty())
        buf[i] = buf[(i << 1) | 0];
      else
        buf[i] = buf[(i << 1) | 0] * buf[(i << 1) | 1];
    }
  }

  void build_ntt() {
    fps f;
    f.reserve(N * 2);
    for (int i = 0; i < xsz; i++) {
      l[i + N] = i;
      r[i + N] = i + 1;
      buf[i + N] = {-xs[i] + 1, -xs[i] - 1};
    }
    for (int i = N - 1; i > 0; i--) {
      l[i] = l[(i << 1) | 0];
      r[i] = r[(i << 1) | 1];
      if (buf[(i << 1) | 0].empty())
        continue;
      else if (buf[(i << 1) | 1].empty())
        buf[i] = buf[(i << 1) | 0];
      else if (buf[(i << 1) | 0].size() == buf[(i << 1) | 1].size()) {
        buf[i] = buf[(i << 1) | 0];
        f.clear();
        copy(begin(buf[(i << 1) | 1]), end(buf[(i << 1) | 1]), back_inserter(f));
        buf[i].ntt_doubling();
        f.ntt_doubling();
        for (int j = 0; j < (int)buf[i].size(); j++) buf[i][j] *= f[j];
      } else {
        buf[i] = buf[(i << 1) | 0];
        f.clear();
        copy(begin(buf[(i << 1) | 1]), end(buf[(i << 1) | 1]), back_inserter(f));
        buf[i].ntt_doubling();
        f.intt();
        f.resize(buf[i].size(), mint(0));
        f.ntt();
        for (int j = 0; j < (int)buf[i].size(); j++) buf[i][j] *= f[j];
      }
    }
    for (int i = 0; i < 2 * N; i++) {
      buf[i].intt();
      buf[i].shrink();
    }
  }
};

template <typename mint>
vector<mint> MultipointEvaluation(const FormalPowerSeries<mint> &f,
                                  const vector<mint> &xs) {
  using fps = FormalPowerSeries<mint>;
  ProductTree<mint> ptree(xs);
  vector<mint> ret;
  ret.reserve(2 * ptree.N);
  auto rec = [&](auto self, fps a, int idx) {
    if(ptree.l[idx] == ptree.r[idx]) return;
    a %= ptree.buf[idx];
    if ((int)a.size() <= 64) {
      for (int i = ptree.l[idx]; i < ptree.r[idx]; i++)
        ret.push_back(a.eval(xs[i]));
      return;
    }
    self(self, a, (idx << 1) | 0);
    self(self, a, (idx << 1) | 1);
  };
  rec(rec, f, 1);
  return ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "fps/formal-power-series.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename mint>
struct FormalPowerSeries : vector<mint> {
  using vector<mint>::vector;
  using FPS = FormalPowerSeries;

  FPS &operator+=(const FPS &r) {
    if (r.size() > this->size()) this->resize(r.size());
    for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];
    return *this;
  }

  FPS &operator+=(const mint &r) {
    if (this->empty()) this->resize(1);
    (*this)[0] += r;
    return *this;
  }

  FPS &operator-=(const FPS &r) {
    if (r.size() > this->size()) this->resize(r.size());
    for (int i = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];
    return *this;
  }

  FPS &operator-=(const mint &r) {
    if (this->empty()) this->resize(1);
    (*this)[0] -= r;
    return *this;
  }

  FPS &operator*=(const mint &v) {
    for (int k = 0; k < (int)this->size(); k++) (*this)[k] *= v;
    return *this;
  }

  FPS &operator/=(const FPS &r) {
    if (this->size() < r.size()) {
      this->clear();
      return *this;
    }
    int n = this->size() - r.size() + 1;
    return *this = ((*this).rev().pre(n) * r.rev().inv(n)).pre(n).rev();
  }

  FPS &operator%=(const FPS &r) {
    *this -= *this / r * r;
    shrink();
    return *this;
  }

  FPS operator+(const FPS &r) const { return FPS(*this) += r; }
  FPS operator+(const mint &v) const { return FPS(*this) += v; }
  FPS operator-(const FPS &r) const { return FPS(*this) -= r; }
  FPS operator-(const mint &v) const { return FPS(*this) -= v; }
  FPS operator*(const FPS &r) const { return FPS(*this) *= r; }
  FPS operator*(const mint &v) const { return FPS(*this) *= v; }
  FPS operator/(const FPS &r) const { return FPS(*this) /= r; }
  FPS operator%(const FPS &r) const { return FPS(*this) %= r; }
  FPS operator-() const {
    FPS ret(this->size());
    for (int i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];
    return ret;
  }

  void shrink() {
    while (this->size() && this->back() == mint(0)) this->pop_back();
  }

  FPS rev() const {
    FPS ret(*this);
    reverse(begin(ret), end(ret));
    return ret;
  }

  FPS dot(FPS r) const {
    FPS ret(min(this->size(), r.size()));
    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i] * r[i];
    return ret;
  }

  FPS pre(int sz) const {
    return FPS(begin(*this), begin(*this) + min((int)this->size(), sz));
  }

  FPS operator>>(int sz) const {
    if ((int)this->size() <= sz) return {};
    FPS ret(*this);
    ret.erase(ret.begin(), ret.begin() + sz);
    return ret;
  }

  FPS operator<<(int sz) const {
    FPS ret(*this);
    ret.insert(ret.begin(), sz, mint(0));
    return ret;
  }

  FPS diff() const {
    const int n = (int)this->size();
    FPS ret(max(0, n - 1));
    for (int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * mint(i);
    return ret;
  }

  FPS integral() const {
    const int n = (int)this->size();
    FPS ret(n + 1);
    ret[0] = mint(0);
    for (int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / mint(i + 1);
    return ret;
  }

  mint eval(mint x) const {
    mint r = 0, w = 1;
    for (auto &v : *this) r += w * v, w *= x;
    return r;
  }

  FPS log(int deg = -1) const {
    assert((*this)[0] == mint(1));
    if (deg == -1) deg = (int)this->size();
    return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
  }

  FPS pow(int64_t k, int deg = -1) const {
    const int n = (int)this->size();
    if (deg == -1) deg = n;
    for (int i = 0; i < n; i++) {
      if ((*this)[i] != mint(0)) {
        if (i * k > deg) return FPS(deg, mint(0));
        mint rev = mint(1) / (*this)[i];
        FPS ret = (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));
        ret = (ret << (i * k)).pre(deg);
        if ((int)ret.size() < deg) ret.resize(deg, mint(0));
        return ret;
      }
    }
    return FPS(deg, mint(0));
  }

  static void *ntt_ptr;
  static void set_fft();
  FPS &operator*=(const FPS &r);
  void ntt();
  void intt();
  void ntt_doubling();
  static int ntt_pr();
  FPS inv(int deg = -1) const;
  FPS exp(int deg = -1) const;
};
template <typename mint>
void *FormalPowerSeries<mint>::ntt_ptr = nullptr;

/**
 * @brief 多項式/形式的冪級数ライブラリ
 * @docs docs/formal-power-series.md
 */
#line 2 "fps/multipoint-evaluation.hpp"

template <typename mint>
struct ProductTree {
  using fps = FormalPowerSeries<mint>;
  const vector<mint> &xs;
  vector<fps> buf;
  int N, xsz;
  vector<int> l, r;
  ProductTree(const vector<mint> &xs_) : xs(xs_), xsz(xs.size()) {
    N = 1;
    while (N < (int)xs.size()) N *= 2;
    buf.resize(2 * N);
    l.resize(2 * N, xs.size());
    r.resize(2 * N, xs.size());
    fps::set_fft();
    if (fps::ntt_ptr == nullptr)
      build();
    else
      build_ntt();
  }

  void build() {
    for (int i = 0; i < xsz; i++) {
      l[i + N] = i;
      r[i + N] = i + 1;
      buf[i + N] = {-xs[i], 1};
    }
    for (int i = N - 1; i > 0; i--) {
      l[i] = l[(i << 1) | 0];
      r[i] = r[(i << 1) | 1];
      if (buf[(i << 1) | 0].empty())
        continue;
      else if (buf[(i << 1) | 1].empty())
        buf[i] = buf[(i << 1) | 0];
      else
        buf[i] = buf[(i << 1) | 0] * buf[(i << 1) | 1];
    }
  }

  void build_ntt() {
    fps f;
    f.reserve(N * 2);
    for (int i = 0; i < xsz; i++) {
      l[i + N] = i;
      r[i + N] = i + 1;
      buf[i + N] = {-xs[i] + 1, -xs[i] - 1};
    }
    for (int i = N - 1; i > 0; i--) {
      l[i] = l[(i << 1) | 0];
      r[i] = r[(i << 1) | 1];
      if (buf[(i << 1) | 0].empty())
        continue;
      else if (buf[(i << 1) | 1].empty())
        buf[i] = buf[(i << 1) | 0];
      else if (buf[(i << 1) | 0].size() == buf[(i << 1) | 1].size()) {
        buf[i] = buf[(i << 1) | 0];
        f.clear();
        copy(begin(buf[(i << 1) | 1]), end(buf[(i << 1) | 1]), back_inserter(f));
        buf[i].ntt_doubling();
        f.ntt_doubling();
        for (int j = 0; j < (int)buf[i].size(); j++) buf[i][j] *= f[j];
      } else {
        buf[i] = buf[(i << 1) | 0];
        f.clear();
        copy(begin(buf[(i << 1) | 1]), end(buf[(i << 1) | 1]), back_inserter(f));
        buf[i].ntt_doubling();
        f.intt();
        f.resize(buf[i].size(), mint(0));
        f.ntt();
        for (int j = 0; j < (int)buf[i].size(); j++) buf[i][j] *= f[j];
      }
    }
    for (int i = 0; i < 2 * N; i++) {
      buf[i].intt();
      buf[i].shrink();
    }
  }
};

template <typename mint>
vector<mint> MultipointEvaluation(const FormalPowerSeries<mint> &f,
                                  const vector<mint> &xs) {
  using fps = FormalPowerSeries<mint>;
  ProductTree<mint> ptree(xs);
  vector<mint> ret;
  ret.reserve(2 * ptree.N);
  auto rec = [&](auto self, fps a, int idx) {
    if(ptree.l[idx] == ptree.r[idx]) return;
    a %= ptree.buf[idx];
    if ((int)a.size() <= 64) {
      for (int i = ptree.l[idx]; i < ptree.r[idx]; i++)
        ret.push_back(a.eval(xs[i]));
      return;
    }
    self(self, a, (idx << 1) | 0);
    self(self, a, (idx << 1) | 1);
  };
  rec(rec, f, 1);
  return ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

