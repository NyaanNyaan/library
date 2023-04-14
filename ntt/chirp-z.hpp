#pragma once

#include "arbitrary-ntt.hpp"

// f(A W^0), f(A W^1), ..., f(A W^{N-1}) を返す
template <typename fps>
fps ChirpZ(fps f, typename fps::value_type W, int N = -1,
           typename fps::value_type A = 1) {
  using mint = typename fps::value_type;
  if (N == -1) N = f.size();
  if (f.empty() or N == 0) return fps(N, mint{});
  int M = f.size();
  if (A != 1) {
    mint x = 1;
    for (int i = 0; i < M; i++) f[i] *= x, x *= A;
  }
  if (W == 0) {
    fps F(N, f[0]);
    for (int i = 1; i < M; i++) F[0] += f[i];
    return F;
  }
  fps wc(N + M), iwc(max(N, M));
  mint ws = 1, iW = W.inverse(), iws = 1;
  wc[0] = 1, iwc[0] = 1;
  for (int i = 1; i < N + M; i++) wc[i] = ws * wc[i - 1], ws *= W;
  for (int i = 1; i < max(N, M); i++) iwc[i] = iws * iwc[i - 1], iws *= iW;
  for (int i = 0; i < M; i++) f[i] *= iwc[i];
  reverse(begin(f), end(f));
  fps g = f * wc;
  fps F{begin(g) + M - 1, begin(g) + M + N - 1};
  for (int i = 0; i < N; i++) F[i] *= iwc[i];
  return F;
}

/**
 * @brief Chirp Z-transform(Bluestein's algorithm)
 */
