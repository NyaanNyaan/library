#pragma once

template <typename V, typename W, typename D = long double>
struct BranchAndBound {
  vector<pair<V, W>> c;
  V best;

  BranchAndBound(const vector<V>& v, const vector<W>& w) {
    assert(v.size() == w.size());
    vector<int> ord(v.size());
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord),
         [&](int i, int j) { return D(v[i]) * w[j] > D(v[j]) * w[i]; });
    for (auto& i : ord) c.emplace_back(v[i], w[i]);
  }

  pair<D, bool> relax(int i, V v, W w) {
    D ret = v;
    bool f = true;
    while (i < (int)c.size()) {
      if (w == 0) break;
      if (w >= c[i].second) {
        w -= c[i].second, ret += c[i].first, ++i;
        continue;
      }
      f = false, ret += (D(c[i].first) * w) / c[i].second;
      break;
    }
    return make_pair(ret, f);
  }

  void dfs(int i, V v, W w) {
    if (i == (int)c.size()) {
      best = max(v, best);
      return;
    }
    auto [rel, flg] = relax(i, v, w);
    if (flg) {
      best = max(best, V(rel));
      return;
    }
    if (V(rel) < best) return;
    if (w >= c[i].second) dfs(i + 1, v + c[i].first, w - c[i].second);
    dfs(i + 1, v, w);
    return;
  }

  V run(W w) {
    dfs(0, best = 0, w);
    return best;
  }
};

/**
 * @brief 0-1ナップサック問題の分枝限定法による解法
 * @docs docs/dp/branch-and-bound.md
 */
