
#include "bigint.hpp"

namespace GarnerImpl {

template <typename T,
          enable_if_t<is_integral_v<T> || is_same_v<T, __int128_t>>* = nullptr>
T inv_mod(T a, T m) {
  assert(0 <= a);
  if (a >= m) a %= m;
  T b = m, s = 1, t = 0;
  while (true) {
    if (a == 1) return s;
    t -= b / a * s;
    b %= a;
    if (b == 1) return t + m;
    s -= a / b * t;
    a %= b;
  }
}

pair<bigint, bigint> garner_dc(const vector<int>& r, const vector<int>& m) {
  int N = m.size();
  if (N == 0) return {0, 1};
  int B = 1;
  while (B < N) B *= 2;
  vector<bigint> tree(2 * B);
  for (int i = 0; i < B; i++) tree[B + i] = i < (int)m.size() ? m[i] : 1;
  for (int i = B - 1; i; i--) tree[i] = tree[i * 2 + 0] * tree[i * 2 + 1];
  auto calc = [&](auto&& rc, int ti, bigint X, bigint Y, int L,
                  int R) -> bigint {
    if (N <= L) return 0;
    X %= tree[ti], Y %= tree[ti];
    if (L + 1 == R) {
      int xl = X.to_ll(), yl = Y.to_ll();
      int t = (1LL * (r[L] - xl) * inv_mod(yl, m[L])) % m[L];
      return t < 0 ? t + m[L] : t;
    }
    auto& prod = tree[ti * 2 + 0];
    int M = (L + R) / 2;
    auto xl = rc(rc, ti * 2 + 0, X, Y, L, M);
    auto xr = rc(rc, ti * 2 + 1, X + xl * Y, Y * prod, M, R);
    return xl + xr * prod;
  };
  bigint ans = calc(calc, 1, 0, 1, 0, B);
  return {ans, tree[1]};
}

pair<bigint, bigint> garner_naive(const vector<int>& r, const vector<int>& m) {
  int N = r.size();
  if (N == 0) return {0, 1};
  vector<int> y(N), x(N), t(N);
  for (int i = 0; i < N; i++) y[i] = 1 % m[i];
  for (int i = 0; i < N; ++i) {
    t[i] = (1LL * (r[i] - x[i]) * inv_mod(y[i], m[i])) % m[i];
    if (t[i] < 0) t[i] += m[i];
    for (int j = i + 1; j < N; j++) {
      x[j] = (x[j] + 1LL * y[j] * t[i]) % m[j];
      y[j] = 1LL * y[j] * m[i] % m[j];
    }
  }
  bigint ans = 0, mod = 1;
  for (int i = N - 1; i >= 0; --i) ans = ans * m[i] + t[i], mod *= m[i];
  return {ans, mod};
}

// 1 <= m[i] <= 2 * 10^9
// m が互いに素でない場合：未定義
pair<bigint, bigint> garner_bigint(const vector<int>& r, const vector<int>& m) {
  assert(r.size() == m.size());
  if ((int)m.size() <= 3000) return garner_naive(r, m);
  return garner_dc(r, m);
}
// 1 <= m[i] <= 2 * 10^9
// m が互いに素でない場合：未定義
pair<bigint, bigint> crt_bigint(const vector<int>& r, const vector<int>& m) {
  return garner_bigint(r, m);
}
}  // namespace GarnerImpl

using GarnerImpl::crt_bigint;
using GarnerImpl::garner_bigint;

/**
 * @brief Garner's algorithm for bigint
 */
