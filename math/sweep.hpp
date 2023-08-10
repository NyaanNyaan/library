#pragma once

#include <array>
#include <vector>
using namespace std;

// MAX bit
template <typename Int, int MAX>
struct Basis {
  array<Int, MAX> v;

  Basis() : _size(0) { fill(begin(v), end(v), Int{0}); }
  Basis(const vector<Int>& a) : _size(0) {
    fill(begin(v), end(v), Int{0});
    for (auto& x : a) add(x);
  }
  const Int operator[](int i) const { return v[i]; }

  // 追加成功かどうかを返す
  bool add(Int x) {
    int t = _msb(x);
    assert(t < MAX);
    while (t != -1 && v[t]) t = _msb(x ^= v[t]);
    return t == -1 ? false : (v[t] = x, _size++, true);
  }

  // rhs との和を求める
  void merge(const Basis& rhs) {
    for (int _t = MAX - 1; _t >= 0; _t--) {
      if (rhs.v[_t] == Int{0}) continue;
      int t = _t;
      Int x = rhs.v[t];
      while (t != -1 && v[t]) t = _msb(x ^= v[t]);
      if (x) v[t] = x, _size++;
    }
  }

  // 正規化された基底を得る (O(MAX^2))
  vector<Int> get_basis() {
    normalize();
    vector<Int> res;
    for (int t = 0; t < MAX; t++) {
      if (v[t]) res.push_back(v[t]);
    }
    reverse(begin(res), end(res));
    return res;
  }

  // x を作れるか？ TODO:verify
  bool test(Int x) {
    if (x == 0) return true;
    int t = _msb(x);
    if (t >= MAX) return false;
    while (t != -1 && v[t]) t = _msb(x ^= v[t]);
    return x == 0;
  }

  // 作れる x の最大値 TODO:verify
  Int get_max() const {
    Int res = 0;
    for (int t = MAX - 1; t >= 0; t--) res = max(res, res ^ v[t]);
    return res;
  }

  // 行列を標準化する
  void normalize() {
    for (int t = MAX - 1; t >= 0; t--) {
      if (v[t]) {
        for (int u = MAX - 1; u > t; u--) v[u] = min(v[u], v[u] ^ v[t]);
      }
    }
  }

  vector<Int> orthogonal_complement(int N = MAX) {
    normalize();
    vector<int> b;
    for (int t = N - 1; t >= 0; t--) {
      if (v[t]) b.push_back(t);
    }
    int rank = b.size();
    for (int t = N - 1; t >= 0; t--) {
      if (!v[t]) b.push_back(t);
    }
    vector<Int> res(N - rank);
    for (int i = rank; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (j < rank ? ((v[b[j]] >> b[i]) & 1) : i == j) {
          res[i - rank] |= Int{1} << b[j];
        }
      }
    }
    return res;
  }

  int size() const { return _size; }

  friend ostream& operator<<(ostream& os, const Basis<Int, MAX>& b) {
    os << "{ ";
    for (int i = 0; i < MAX; i++) {
      if (b.v[i]) os << b.v[i] << ", ";
    }
    return os << "}";
  }

 private:
  int _size;
  int _msb(Int x) { return x ? 63 - __builtin_clzll(x) : -1; }
};

/*
 * @brief 掃き出し法
 */
