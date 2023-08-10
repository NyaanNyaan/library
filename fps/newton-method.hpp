#pragma once

#include <functional>
using namespace std;

// G(f) = 0 mod x^{deg} を満たす f を返す
// f0 : 初期解, 非空な fps か mint を入れる
// g : (g(f), g'(f)) を返す
template <typename fps>
fps newton_method(function<pair<fps, fps>(fps, int)> calc_g, fps f0, int deg) {
  assert(!f0.empty());
  fps f{f0};
  for (int d = f.size(); d < deg; d *= 2) {
    // 少し多めに計算しておく
    const int extra = d + 10;
    auto [g, dgdf] = calc_g(f, d * 2 + extra);
    int offset = 0;
    while (offset < (int)dgdf.size() && dgdf[offset] == 0) offset++;
    assert(offset <= extra);
    dgdf = dgdf >> offset;
    g = g >> offset;
    f = (f - g * dgdf.inv()).pre(d * 2);
  }
  return f.pre(deg);
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
