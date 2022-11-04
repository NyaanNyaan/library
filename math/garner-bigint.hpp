
#include "multiprecision-integer.hpp"

namespace GarnerImpl {
template <typename T>
constexpr T safe_mod(T x, T m) {
  x %= m;
  if (x < 0) x += m;
  return x;
}
template <typename T>
constexpr std::pair<T, T> inv_gcd(T a, T b) {
  a = safe_mod(a, b);
  if (a == 0) return {b, 0};
  T s = b, t = a;
  T m0 = 0, m1 = 1;
  while (t) {
    T u = s / t;
    s -= t * u;
    m0 -= m1 * u;
    auto tmp = s;
    s = t;
    t = tmp;
    tmp = m0;
    m0 = m1;
    m1 = tmp;
  }
  if (m0 < 0) m0 += b / s;
  return {s, m0};
}
template <typename T>
T inv_mod(T x, T m) {
  assert(1 <= m);
  auto z = inv_gcd(x, m);
  assert(z.first == 1);
  return z.second;
}
bigint garner_bigint(const vector<long long>& a, const vector<long long>& m) {
  int ms = a.size();
  vector<long long> coffs(ms, 1), constants(ms), digs(ms);
  for (int i = 0; i < ms; ++i) {
    long long v = (a[i] - constants[i]) * inv_mod(coffs[i], m[i]) % m[i];
    if (v < 0) v += m[i];
    digs[i] = v;
    for (int j = i + 1; j < ms; j++) {
      constants[j] += coffs[j] * v;
      constants[j] %= m[j];
      coffs[j] *= m[i];
      coffs[j] %= m[j];
    }
  }
  bigint ans = bigint{0}, c = bigint{1};
  for (int i = ms - 1; i >= 0; --i) {
    c *= bigint{m[i]};
    ans *= bigint{m[i]};
    ans += bigint{digs[i]};
  }
  if (ans > c / 2) ans -= c;
  if (ans < 0) ans += c;
  return ans;
}

bigint crt_bigint(const vector<long long>& a, const vector<long long>& m) {
  return garner_bigint(a, m);
}
}  // namespace Garner

using GarnerImpl::crt_bigint;
using GarnerImpl::garner_bigint;