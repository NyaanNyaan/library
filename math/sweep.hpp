#pragma once

template <typename T>
struct Sweep {
  using P = pair<T, unordered_set<int>>;
  vector<P> basis;
  int num;

  Sweep() : num(0) {}
  Sweep(const vector<T>& v) : num(0) {
    for (auto& x : v) add(x, num++);
  }

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

  void add(T x, int id) {
    P v{x, {id}};
    for (P& b : basis) {
      if (v.first > (v.first ^ b.first)) apply(v, b);
    }
    if (v.first != T{}) basis.push_back(v);
  }

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
};

/**
 * @brief 掃き出し法(復元付き)
 */
