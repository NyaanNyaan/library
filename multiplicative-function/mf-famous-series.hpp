#pragma once

#include "../template/template.hpp"
#include "enamurate-multiplicative-function.hpp"

namespace multiplicative_function {
template <typename T>
T moebius(int, int, int c) {
  return c == 0 ? 1 : c == 1 ? -1 : 0;
}
template <typename T>
T sigma0(int, int, int c) {
  return c + 1;
}
template <typename T>
T sigma1(int n, int p, int) {
  return (n - 1) / (p - 1) + n;
}
template <typename T>
T totient(int n, int p, int) {
  return n - n / p;
}
}  // namespace multiplicative_function

template <typename T>
static constexpr vector<T> mobius_function(int n) {
  enamurate_multiplicative_function<T, multiplicative_function::moebius<T>> em(
      n);
  return em.run();
}

template <typename T>
static constexpr vector<T> sigma0(int n) {
  enamurate_multiplicative_function<T, multiplicative_function::sigma0<T>> em(
      n);
  return em.run();
}

template <typename T>
static constexpr vector<T> sigma1(int n) {
  enamurate_multiplicative_function<T, multiplicative_function::sigma1<T>> em(
      n);
  return em.run();
}

template <typename T>
static constexpr vector<T> totient(int n) {
  enamurate_multiplicative_function<T, multiplicative_function::totient<T>> em(
      n);
  return em.run();
}

/**
 * @brief 有名な乗法的関数
 * @docs docs/multiplicative-function/mf-famous-series.md
 */
