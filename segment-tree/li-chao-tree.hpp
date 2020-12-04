#pragma once



template <typename T, T INF>
struct LiChaoTree {
  struct Line {
    T slope, intercept;
    Line(T slope, T intercept) : slope(slope), intercept(intercept) {}
    inline T get(T x) const { return slope * x + intercept; }
    inline bool over(const Line &other, const T &x) const {
      return get(x) < other.get(x);
    }
  };

  // remind セグ木は0-indexedの実装
  vector<T> xset;
  vector<Line> seg;
  int _size;

  // 引数xにはx座標の集合を入れる
  LiChaoTree(const vector<T> &x) : xset(x) {
    sort(xset.begin(), xset.end());
    xset.erase(unique(xset.begin(), xset.end()), xset.end());
    _size = 1;
    while (_size < (int)xset.size()) _size <<= 1;
    while ((int)xset.size() < _size) xset.push_back(xset.back() + 1);
    seg.assign(2 * _size, Line(0, INF));
  }

  // 以上 xset[max]以下であることを仮定
  int get_more_idx(T k) {
    return lower_bound(xset.begin(), xset.end(), k) - xset.begin();
  }
  // 以下 xset[0]以上であることを仮定
  int get_less_idx(T k) {
    int ret = upper_bound(xset.begin(), xset.end(), k) - xset.begin();
    return max(0, ret - 1);
  }

  // 内部用
  void inner_update(T a, T b, int left, int right, int seg_idx) {
    Line line(a, b);
    while (1) {
      int mid = (left + right) >> 1;
      bool l_over = line.over(seg[seg_idx], xset[left]);
      bool r_over = line.over(seg[seg_idx], xset[right - 1]);
      if (l_over == r_over) {
        if (l_over) swap(seg[seg_idx], line);
        return;
      }
      bool m_over = line.over(seg[seg_idx], xset[mid]);
      if (m_over) swap(seg[seg_idx], line);
      if (l_over != m_over)
        seg_idx = (seg_idx << 1), right = mid;
      else
        seg_idx = (seg_idx << 1) | 1, left = mid;
    }
  }

  // 内部用
  void inner_update(T a, T b, int seg_idx) {
    int left, right;
    int upper_bit = 31 - __builtin_clz(seg_idx);
    left = (_size >> upper_bit) * (seg_idx - (1 << upper_bit));
    right = left + (_size >> upper_bit);
    inner_update(a, b, left, right, seg_idx);
  }

  // y = ax + bなる直線を追加
  void update(T a, T b) { inner_update(a, b, 0, _size, 1); }

  // 閉区間x in [left , right]に線分y = ax + bを追加するクエリ
  void update_segment(T a, T b, T low, T high) {
    int left = get_more_idx(low) + _size;
    int right = get_less_idx(high) + _size + 1;
    for (; left < right; left >>= 1, right >>= 1) {
      if (left & 1) inner_update(a, b, left++);
      if (right & 1) inner_update(a, b, --right);
    }
  }

  T inner_query(int x, int segidx) {
    T ret = seg[segidx].get(x);
    while (segidx > 1) {
      segidx = segidx >> 1;
      ret = min(ret, seg[segidx].get(x));
    }
    return ret;
  }

  // x = xset[k]なる点における最小値クエリ
  T query_idx(int k) {
    const T x = xset[k];
    k += _size;
    return inner_query(x, k);
  }

  // xにおける最小クエリ
  T query(T x) { return query_idx(get_more_idx(x)); }
};