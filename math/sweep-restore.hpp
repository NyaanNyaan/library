#pragma once

template <typename T>
struct Sweep {
  using P = pair<T, unordered_set<int>>;
  vector<P> basis;

  Sweep() {}
  Sweep(const vector<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) add(v[i], i);
  }

  // x を id と共に追加
  void add(T x, int id) {
    P v{x, {id}};
    for (P& b : basis) {
      if (v.first > (v.first ^ b.first)) apply(v, b);
    }
    if (v.first != T{}) basis.push_back(v);
  }

  // pair(x を復元できるか？, {復元した時の ID の集合})
  pair<bool, vector<int>> restore(T x) {
    P v{x, {}};
    for (P& b : basis) {
      if (v.first > (v.first ^ b.first)) apply(v, b);
    }
    if (v.first != T{}) return {false, {}};
    vector<int> res;
    for (auto& n : v.second) res.push_back(n);
    sort(begin(res), end(res));
    return {true, res};
  }

 private:
  void apply(P& p, const P& o) {
    p.first ^= o.first;
    for (auto& x : o.second) apply(p.second, x);
  }
  void apply(unordered_set<int>& s, int x) {
    if (s.count(x)) {
      s.erase(x);
    } else {
      s.insert(x);
    }
  }
};

/**
 * @brief 掃き出し法(復元付き)
 */
