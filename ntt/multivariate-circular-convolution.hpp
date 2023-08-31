#pragma once
//
#include <cassert>
#include <unordered_map>
#include <vector>
using namespace std;

#include "../fps/formal-power-series.hpp"
#include "../internal/internal-math.hpp"
#include "../math/constexpr-primitive-root.hpp"
#include "../modint/arbitrary-modint.hpp"
#include "../prime/fast-factorize.hpp"
#include "chirp-z.hpp"
#include "multidimensional-ntt.hpp"

template <typename mint>
FormalPowerSeries<mint> multivariate_circular_convolution(
    const FormalPowerSeries<mint>& f, const FormalPowerSeries<mint>& g,
    const vector<int>& base) {
  int prod = 1;
  for (auto& b : base) prod *= b;
  assert((int)f.size() == prod && (int)g.size() == prod);

  vector<int> primes;
  for (int p = 900000000 / prod * prod + 1; (int)primes.size() < 3; p += prod) {
    if (is_prime(p)) primes.push_back(p);
  }

  vector<vector<int>> buf;
  using submint = ArbitraryModIntBase<20230528>;
  for (int p : primes) {
    submint::set_mod(p);
    int proot = constexpr_primitive_root(p);
    unordered_map<int, pair<submint, submint>> len_to_W;
    for (auto& b : base) {
      submint w = submint{proot}.pow((p - 1) / b);
      submint iw = w.inverse();
      len_to_W[b] = {w, iw};
    }
    FormalPowerSeries<submint> s(prod), t(prod);
    for (int i = 0; i < prod; i++) s[i] = f[i].get(), t[i] = g[i].get();
    auto dft = [&](vector<submint>& v, bool rev) -> void {
      auto& val = len_to_W[v.size()];
      submint w = rev ? val.second : val.first;
      auto res = ChirpZ<FormalPowerSeries<submint>>({begin(v), end(v)}, w);
      v = vector<submint>{begin(res), end(res)};
    };
    MultidimensionalFourierTransform<submint> mdft(base, dft);
    mdft.fft(s), mdft.fft(t);
    for (int i = 0; i < prod; i++) s[i] *= t[i];
    mdft.fft(s, true);
    submint iprod = submint{prod}.inverse();
    vector<int> res;
    for (auto& x : s) res.push_back((x * iprod).get());
    buf.push_back(res);
  }

  FormalPowerSeries<mint> h;
  auto m = mint::get_mod();
  vector<__int128_t> rem(3), mod(3);
  for (int j = 0; j < 3; j++) mod[j] = primes[j];
  for (int i = 0; i < prod; i++) {
    for (int j = 0; j < 3; j++) rem[j] = buf[j][i];
    h.push_back(internal::crt(rem, mod).first % m);
  }
  return h;
}

/**
 * @brief 多変数巡回畳み込み
 */
