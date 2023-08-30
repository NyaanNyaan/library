#pragma once

#include <algorithm>
#include <vector>
using namespace std;

#include "../hashmap/hashmap-unerasable.hpp"

// コストの小さい順に K 個選ぶ
// hash が衝突したらコストの小さい方を選ぶ
//
// Data : bool operator< が定義されている必要がある
template <typename Data, unsigned long long (*get_hash)(const Data&)>
struct Top_K {
  int K;
  vector<Data> v;
  UnerasableHashMap<unsigned long long, int, true> mp;

  Top_K(int k) : K(k), mp(-1u, 2 * K) {}

  void normalize() {
    if ((int)v.size() < K) return;
    nth_element(begin(v), begin(v) + K, end(v));
    v.resize(K);

    mp.clear();
    for (int i = 0; i < K; i++) mp[get_hash(v[i])] = i;
  }

  // d を挿入
  void insert(const Data& d) {
    unsigned long long ha = get_hash(d);
    int hint = mp.hint(ha);

    // 既に要素が存在する場合は何もしない
    if (mp.flag[hint]) {
      int idx = mp.vals[hint];
      if (d < v[idx]) v[idx] = d;
      return;
    }

    // v と map を更新する
    v.push_back(d);
    mp.keys[hint] = ha;
    mp.vals[hint] = v.size() - 1;
    mp.flag[hint] = 1;
    mp.occupied_num++;
    if ((int)v.size() >= 2 * K) normalize();
  }

  // 参照を返す
  vector<Data>& get() {
    normalize();
    return v;
  }
};
