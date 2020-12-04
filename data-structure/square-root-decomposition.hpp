#pragma once

template <typename MERGE, typename block, int B>
struct SquareRootDecomposition {
  int N;
  vector<block> sq;
  MERGE merge;
  typename block::T UNIT;
  SquareRootDecomposition(int N_, MERGE merge_, typename block::T UNIT_)
      : N(N_), sq(N / B + 1), merge(merge_), UNIT(UNIT_) {
    for(int i = 0; i < (int)sq.size(); i++) sq[i].init(i);
  }

  void update(int l, int r, typename block::S x) {
    if (l / B == r / B) {
      sq[l / B].update_part(l % B, r % B, x);
    } else {
      sq[l / B].update_part(l % B, B, x);
      for (int i = l / B + 1; i < r / B; i++) sq[i].update_all(x);
      sq[r / B].update_part(0, r % B, x);
    }
  }

  typename block::T query(int l, int r) {
    if (l / B == r / B) return sq[l / B].query_part(l % B, r % B);
    typename block::T ret = UNIT;
    ret = merge(ret, sq[l / B].query_part(l % B, B));
    for (int i = l / B + 1; i < r / B; i++) ret = merge(ret, sq[i].query_all());
    ret = merge(ret, sq[r / B].query_part(0, r % B));
    return ret;
  }
};

/**
 * @brief 平方分割
 * @docs docs/data-structure/sqrt-dec.md
 */
