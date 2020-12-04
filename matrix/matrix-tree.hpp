#pragma once



#include "matrix.hpp"
#include "polynomial-matrix-determinant.hpp"

template <typename T>
struct MatrixTree {
  int n;
  Matrix<T> m;
  MatrixTree(int _n) : n(_n), m(_n) { assert(n > 0); }

  void add(int i, int j, const T& x) {
    if (i < n) m[i][i] += x;
    if (j < n) m[j][j] += x;
    if (i < n and j < n) {
      m[i][j] -= x;
      m[j][i] -= x;
    }
  }

  Matrix<T> get() const { return m; }

  template <typename U, typename = void>
  struct has_value_type : false_type {};
  template <typename U>
  struct has_value_type<
      U, typename conditional<false, typename U::value_type, void>::type>
      : true_type {};

  template <typename U = T,
            enable_if_t<has_value_type<U>::value, nullptr_t> = nullptr>
  T calc() {
    return PolynomialMatrixDeterminant(m);
  }
  template <typename U = T,
            enable_if_t<!has_value_type<U>::value, nullptr_t> = nullptr>
  T calc() {
    return m.determinant();
  }
};

/**
 * @brief 行列木定理(ラプラシアン行列)
 */
