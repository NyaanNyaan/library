#pragma once



#include "../data-structure/hash-map-variable-length.hpp"

template <typename T, T INF>
struct DynamicLiChaoTree {
  struct Line {
    T slope, intercept;
    Line() : slope(0), intercept(INF) {}
    Line(T slope, T intercept) : slope(slope), intercept(intercept) {}
    inline T get(T x) const { return slope * x + intercept; }
    inline bool over(const Line &other, const T &x) const {
      return get(x) < other.get(x);
    }
  };

  // remind セグ木は1-indexedの実装
  T xmin, xmax, _size;
  HashMap<T, Line> seg;

  // [l , r]におけるLi Chao Tree
  DynamicLiChaoTree(T xmin, T xmax) : xmin(xmin), xmax(xmax) {
    _size = 1;
    while (_size < xmax - xmin + 1) _size <<= 1;
  }

 private:
  // 内部用の関数
  void update(T a, T b, T left, T right, T seg_idx) {
    Line line(a, b);
    while (1) {
      T mid = (left + right) >> 1;
      bool l_over = line.over(seg[seg_idx], min(xmax, left + xmin));
      bool r_over = line.over(seg[seg_idx], min(xmax, right - 1 + xmin));
      if (l_over == r_over) {
        if (l_over) swap(seg[seg_idx], line);
        return;
      }
      bool m_over = line.over(seg[seg_idx], min(xmax, mid + xmin));
      if (m_over) swap(seg[seg_idx], line);
      if (l_over != m_over)
        seg_idx = (seg_idx << 1), right = mid;
      else
        seg_idx = (seg_idx << 1) | 1, left = mid;
    }
  }
  // 内部用の関数
  void update(T a, T b, T seg_idx) {
    T left, right;
    T upper_bit = 63 - __builtin_clzll(seg_idx);
    left = (_size >> upper_bit) * (seg_idx - (1 << upper_bit));
    right = left + (_size >> upper_bit);
    update(a, b, left, right, seg_idx);
  }

 public:
  // y = ax + bなる直線を追加
  void update(T a, T b) { update(a, b, 0, _size, 1); }

  // 閉区間x in [left , right]に線分y = ax + bを追加するクエリ
  void update_line_segment(T a, T b, T left, T right) {
    left -= xmin - _size, right -= xmin - _size - 1;
    for (; left < right; left >>= 1, right >>= 1) {
      if (left & 1) update(a, b, left++);
      if (right & 1) update(a, b, --right);
    }
  }

  // xにおける最小値クエリ
  T query(T x) {
    T left = 0, right = _size, seg_idx = 1, idx = x - xmin, ret = INF;
    while (1) {
      T cur = seg[seg_idx].get(x);
      // 線分追加クエリがない場合はここのコメントアウトを外して高速化可能(1.5倍程度？)
      // if(cur == INF) break;
      ret = min(ret, cur);
      if (left + 1 >= right) break;
      T mid = (left + right) >> 1;
      if (idx < mid)
        seg_idx = (seg_idx << 1), right = mid;
      else
        seg_idx = (seg_idx << 1) | 1, left = mid;
    }
    return ret;
  }
};