#pragma once

#include <string>
#include <vector>
using namespace std;

#include "../internal/internal-hash.hpp"

template <typename Str, int BASE_NUM = 2>
struct RollingHash2D {
  using Hash = internal::Hash<BASE_NUM>;
  using u64 = unsigned long long;
  vector<Str> data;
  vector<vector<Hash>> hs;
  vector<Hash> pw[2];
  int h, w;
  static Hash basis[2];

  RollingHash2D(const vector<Str> &S = vector<Str>()) { build(S); }

  void build(const vector<Str> &S) {
    data = S;
    h = S.size();
    w = S[0].size();
    pw[0].resize(h + 1);
    pw[1].resize(w + 1);
    pw[0][0] = pw[1][0] = Hash::set(1);
    for (int i = 1; i <= h; i++) pw[0][i] = pw[0][i - 1] * basis[0];
    for (int i = 1; i <= w; i++) pw[1][i] = pw[1][i - 1] * basis[1];
    hs.resize(h + 1, vector<Hash>(w + 1));
    hs[0][0] = Hash::set(0);
    for (int i = 1; i <= h; i++) {
      hs[i][0] = Hash::set(0);
      for (int j = 1; j <= w; j++)
        hs[i][j] = pfma(hs[i][j - 1], basis[1], S[i - 1][j - 1]);
    }
    for (int j = 1; j <= w; j++) {
      hs[0][j] = Hash::set(0);
      for (int i = 1; i <= h; i++)
        hs[i][j] = pfma(hs[i - 1][j], basis[0], hs[i][j]);
    }
  }

  Hash get(int u, int l, int d, int r) {
    return hs[d][r] - hs[u][r] * pw[0][d - u] - hs[d][l] * pw[1][r - l] +
           hs[u][l] * pw[0][d - u] * pw[1][r - l];
  }

  static Hash get_hash(const vector<Str> &T) {
    Hash ret = Hash::set(0);
    for (int i = 0; i < (int)T.size(); i++) {
      Hash h = Hash::set(0);
      for (int j = 0; j < (int)T[0].size(); j++) h = pfma(h, basis[1], T[i][j]);
      ret = pfma(ret, basis[0], h);
    }
    return ret;
  }
};

template <typename Str, int BASE_NUM>
typename RollingHash2D<Str, BASE_NUM>::Hash
    RollingHash2D<Str, BASE_NUM>::basis[2] = {
        internal::Hash<BASE_NUM>::get_basis(),
        internal::Hash<BASE_NUM>::get_basis()};
using roriha2d = RollingHash2D<string, 1>;

/**
 * @brief 二次元Rolling Hash
 * @docs docs/string/rolling-hash-2d.md
 */
