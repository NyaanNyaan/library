#pragma once

#include <vector>
using namespace std;

#include "../atcoder/segtree.hpp"
#include "../internal/internal-hash.hpp"

namespace RollingHashonSegmentTreeImpl {

constexpr int BASE_NUM = 1;
using Hash = internal::Hash<BASE_NUM>;
using T = pair<Hash, int>;

vector<Hash> Pow{Hash::set(1)};
const Hash Basis = Hash::get_basis();
const Hash Zero = Hash::set(0);

T op(T a, T b) {
  while (b.second >= (int)Pow.size()) {
    Hash h = Pow.back();
    Pow.push_back(h * Basis);
  }
  Hash h = pfma(a.first, Pow[b.second], b.first);
  int len = a.second + b.second;
  return make_pair(h, len);
}
T e() { return make_pair(Zero, 0); }

template <typename Str>
struct RollingHashonSegmentTree {
  using Value = typename Str::value_type;
  int n;
  atcoder::segtree<T, op, e> seg;

  RollingHashonSegmentTree() : n(0) {}

  RollingHashonSegmentTree(const Str& S) : n(S.size()) {
    vector<T> init(n);
    for (int i = 0; i < n; i++) {
      init[i] = make_pair(Hash::set(S[i]), 1);
    }
    seg = {init};
  }

  void update(int i, const Value& v) {
    assert(0 <= i and i < n);
    seg.set(i, make_pair(Hash::set(v), 1));
  }

  // [l1, r1) と [l2, r2) が一致するかを判定
  bool same(int l1, int r1, int l2, int r2) {
    assert(0 <= l1 and l1 <= r1 and r1 <= n);
    assert(0 <= l2 and l2 <= r2 and r2 <= n);
    if (r1 - l1 != r2 - l2) return false;
    return seg.prod(l1, r1) == seg.prod(l2, r2);
  }
};
}  // namespace RollingHashonSegmentTreeImpl

using RollingHashonSegmentTreeImpl::RollingHashonSegmentTree;
