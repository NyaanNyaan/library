#pragma once

#include <functional>
using namespace std;

// G(f) = 0 mod x^{deg} を満たす f を返す
// f0 : 初期解, 非空な fps か mint を入れる
// g : (g(f), g'(f)) を返す
template <typename fps>
fps newton_method(function<pair<fps, fps>(fps, int)> calc_g, fps f0, int deg) {
  assert(!f0.empty());
  if (deg <= (int)f0.size()) return f0.pre(deg);
  fps f = newton_method(calc_g, f0, (deg + 1) / 2);
  int extra = 10, offset = 0;
  auto [g, dgdf] = calc_g(f, deg + extra);
  while (offset < (int)dgdf.size() && dgdf[offset] == 0) offset++;
  assert(offset <= extra);
  dgdf = dgdf >> offset, g = g >> offset;
  return (f - g * dgdf.inv()).pre(deg);
}
// G(f) = 0 mod x^{deg} を満たす f を返す
// f0 : 初期解, 非空な fps か mint を入れる
// g : (g(f), g'(f)) を返す
template <typename fps>
fps newton_method(function<pair<fps, fps>(fps, int)> calc_g,
                  typename fps::value_type f0, int deg) {
  return newton_method(calc_g, fps{f0}, deg);
}

/**
 * @brief ニュートン法
 */
