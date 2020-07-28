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


# :warning: math/matrix-fast.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/matrix-fast.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T, int H, int W>
struct Matrix {
  using Array = array<array<T, W>, H>;
  Array A;

  Matrix() : A({}) {}

  int height() const { return H; }

  int width() const { return W; }

  inline const array<T, W> &operator[](int k) const { return A[k]; }

  inline array<T, W> &operator[](int k) { return A[k]; }

  static Matrix I() {
    assert(H == W);
    Matrix mat;
    for (int i = 0; i < H; i++) mat[i][i] = 1;
    return (mat);
  }

  Matrix &operator+=(const Matrix &B) {
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++) A[i][j] += B[i][j];
    return (*this);
  }

  Matrix &operator-=(const Matrix &B) {
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++) A[i][j] -= B[i][j];
    return (*this);
  }

  Matrix &operator*=(const Matrix &B) {
    assert(H == W);
    Matrix C;
    for (int i = 0; i < H; i++)
      for (int j = 0; j < H; j++)
        for (int k = 0; k < H; k++) C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
    A.swap(C.A);
    return (*this);
  }

  Matrix &operator^=(long long k) {
    Matrix B = Matrix::I();
    while (k > 0) {
      if (k & 1) B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return (*this);
  }

  Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); }

  Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }

  Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); }

  Matrix operator^(const long long k) const { return (Matrix(*this) ^= k); }

  friend ostream &operator<<(ostream &os, Matrix &p) {
    for (int i = 0; i < H; i++) {
      os << "[";
      for (int j = 0; j < W; j++) {
        os << p[i][j] << (j + 1 == W ? "]\n" : ",");
      }
    }
    return (os);
  }

  T determinant() {
    Matrix B(*this);
    assert(H == W);
    T ret = 1;
    for (int i = 0; i < H; i++) {
      int idx = -1;
      for (int j = i; j < W; j++) {
        if (B[j][i] != 0) idx = j;
      }
      if (idx == -1) return (0);
      if (i != idx) {
        ret *= -1;
        swap(B[i], B[idx]);
      }
      ret *= B[i][i];
      T vv = B[i][i];
      for (int j = 0; j < W; j++) {
        B[i][j] /= vv;
      }
      for (int j = i + 1; j < H; j++) {
        T a = B[j][i];
        for (int k = 0; k < W; k++) {
          B[j][k] -= B[i][k] * a;
        }
      }
    }
    return (ret);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/matrix-fast.hpp"
#include <bits/stdc++.h>
using namespace std;

template <class T, int H, int W>
struct Matrix {
  using Array = array<array<T, W>, H>;
  Array A;

  Matrix() : A({}) {}

  int height() const { return H; }

  int width() const { return W; }

  inline const array<T, W> &operator[](int k) const { return A[k]; }

  inline array<T, W> &operator[](int k) { return A[k]; }

  static Matrix I() {
    assert(H == W);
    Matrix mat;
    for (int i = 0; i < H; i++) mat[i][i] = 1;
    return (mat);
  }

  Matrix &operator+=(const Matrix &B) {
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++) A[i][j] += B[i][j];
    return (*this);
  }

  Matrix &operator-=(const Matrix &B) {
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++) A[i][j] -= B[i][j];
    return (*this);
  }

  Matrix &operator*=(const Matrix &B) {
    assert(H == W);
    Matrix C;
    for (int i = 0; i < H; i++)
      for (int j = 0; j < H; j++)
        for (int k = 0; k < H; k++) C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
    A.swap(C.A);
    return (*this);
  }

  Matrix &operator^=(long long k) {
    Matrix B = Matrix::I();
    while (k > 0) {
      if (k & 1) B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return (*this);
  }

  Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); }

  Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }

  Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); }

  Matrix operator^(const long long k) const { return (Matrix(*this) ^= k); }

  friend ostream &operator<<(ostream &os, Matrix &p) {
    for (int i = 0; i < H; i++) {
      os << "[";
      for (int j = 0; j < W; j++) {
        os << p[i][j] << (j + 1 == W ? "]\n" : ",");
      }
    }
    return (os);
  }

  T determinant() {
    Matrix B(*this);
    assert(H == W);
    T ret = 1;
    for (int i = 0; i < H; i++) {
      int idx = -1;
      for (int j = i; j < W; j++) {
        if (B[j][i] != 0) idx = j;
      }
      if (idx == -1) return (0);
      if (i != idx) {
        ret *= -1;
        swap(B[i], B[idx]);
      }
      ret *= B[i][i];
      T vv = B[i][i];
      for (int j = 0; j < W; j++) {
        B[i][j] /= vv;
      }
      for (int j = i + 1; j < H; j++) {
        T a = B[j][i];
        for (int k = 0; k < W; k++) {
          B[j][k] -= B[i][k] * a;
        }
      }
    }
    return (ret);
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

