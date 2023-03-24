#pragma once

#include <vector>
using namespace std;

#include "../modint/montgomery-modint.hpp"
#include "../ntt/ntt.hpp"

namespace WildcardPatternMatchingImpl {

template <typename Container, unsigned int MOD>
vector<int> inner(const Container& a, const Container& b,
                  const typename Container::value_type& wildcard = 0) {
  using mint = LazyMontgomeryModInt<MOD>;
  static NTT<mint> ntt;
  int N = a.size(), M = b.size();
  vector<mint> A1(N), A2(N), A3(N), B1(M), B2(M), B3(M);
  for (int i = 0; i < N; i++) {
    mint x = a[i] == wildcard ? 0 : a[i];
    mint y = a[i] == wildcard ? 0 : 1;
    A1[i] = y * x * x;
    A2[i] = y * x * (-2);
    A3[i] = y;
  }
  for (int i = 0; i < M; i++) {
    mint x = b[i] == wildcard ? 0 : b[i];
    mint y = b[i] == wildcard ? 0 : 1;
    B1[M - 1 - i] = y;
    B2[M - 1 - i] = y * x;
    B3[M - 1 - i] = y * x * x;
  }
  auto AB1 = ntt.multiply(A1, B1);
  auto AB2 = ntt.multiply(A2, B2);
  auto AB3 = ntt.multiply(A3, B3);
  vector<int> res(N - M + 1, 1);
  for (int i = 0; i < N - M + 1; i++) {
    mint x = AB1[i + M - 1] + AB2[i + M - 1] + AB3[i + M - 1];
    if (x != 0) res[i] = 0;
  }
  return res;
}

// 返り値 : 長さ |a| - |b| + 1 の配列 c
// c[i] := a[i, i+|b|) b とマッチするならば 1, しなければ 0)
// wildcard は引数に入れる (default で 0)
template <typename Container>
vector<int> wildcard_pattern_matching(
    const Container& a, const Container& b,
    const typename Container::value_type& wildcard = 0) {
  if ((int)b.size() == 0) return vector<int>(a.size() + 1, 1);
  if (a.size() < b.size()) return {};
  vector<int> res1 = inner<Container, 998244353>(a, b, wildcard);
  vector<int> res2 = inner<Container, 924844033>(a, b, wildcard);
  vector<int> res3 = inner<Container, 1012924417>(a, b, wildcard);
  for (int i = 0; i < (int)res1.size(); i++) res1[i] &= res2[i] & res3[i];
  return res1;
}

}  // namespace WildcardPatternMatchingImpl

using WildcardPatternMatchingImpl::wildcard_pattern_matching;

/**
 * @brief Wildcard Pattern Matching
 */
