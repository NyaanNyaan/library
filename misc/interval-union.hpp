#pragma once

// Union of [a_1, b_1), [a_2, b_2), ...
template <typename T>
vector<pair<T, T>> interval_union(const vector<pair<T, T>> &v) {
  vector<pair<T, T>> buf{v}, res;
  sort(begin(buf), end(buf));
  for (auto &p : buf) {
    res.push_back(p);
    while ((int)res.size() >= 2) {
      int n = res.size();
      if (res[n - 2].second < res[n - 1].first) break;
      pair<T, T> q;
      q.first = res[n - 2].first;
      q.second = max<T>(res[n - 2].second, res[n - 1].second);
      res.pop_back();
      res.pop_back();
      res.push_back(q);
    }
  }
  return res;
}

/**
 * @brief 区間の集合の直和
 */
