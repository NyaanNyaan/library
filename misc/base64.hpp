#pragma once

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

namespace Base64 {
using L = long long;
char base[66] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/.";
int ibase(char c) {
  return 'a' <= c   ? 0x1A + c - 'a'
         : 'A' <= c ? 0x00 + c - 'A'
         : '0' <= c ? 0x34 + c - '0'
         : '+' == c ? 0x3E
         : '/' == c ? 0x3F
                    : 0x40;
}
template <typename T>
string encode(vector<T> &a) {
  T x = a[0], y = a[0];
  for (auto &z : a) x = max(x, z), y = min(y, z);
  L N = a.size(),
    B = max<L>(6, y < 0 ? sizeof(T) * 8 : 64 - __builtin_clzll(x));
  string S((B * N + 11) / 6, 0);
  S[0] = B;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < B; j++) {
      if ((a[i] >> j) & 1) S[(i * B + j) / 6 + 1] |= 1 << ((i * B + j) % 6);
    }
  }
  for (auto &c : S) c = base[(int)c];
  return S;
}
vector<L> decode(string S) {
  for (auto &c : S) c = ibase(c);
  L B = S[0], M = S.size() - 1;
  vector<L> a(6 * M / B, 0);
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < 6; j++) {
      if ((S[i + 1] >> j) & 1) a[(i * 6 + j) / B] |= 1LL << ((i * 6 + j) % B);
    }
  }
  return a;
}
}  // namespace Base64

/**
 * @brief Base64 (ソースコードに数列を圧縮して埋め込む用の符号化・復号化ライブラリ)
 */
