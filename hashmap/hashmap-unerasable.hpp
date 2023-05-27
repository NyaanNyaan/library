#pragma once

#include <cassert>
#include <chrono>
#include <vector>
using namespace std;

#include "../internal/internal-hash-function.hpp"

// 削除不可能な hashmap
//
// テンプレート引数
// Key : Int, string, vector 辺りは何でも (小数系は無理)
// Val : 何でも
// init_size : 初期バケットサイズ
// fixed_size : これを true にするするとバケットサイズが固定になる
// 引数
// _default_value : Val の初期値, この値で初期化される
template <typename Key, typename Val, int init_size = 4,
          bool fixed_size = false>
struct UnerasableHashMap {
  static_assert(init_size >= 1 && (init_size & (init_size - 1)) == 0);

 private:
  int N, occupied_num;
  vector<Key> keys;
  vector<Val> vals;
  vector<char> flag;
  int shift;
  Val default_value;

  // 64 bit の hash を返す
  static unsigned long long get_hash(const Key& x) {
    return internal::hash_function(x);
  }

  // サイズを n に拡張する
  void init(int n = init_size, bool reset = false) {
    vector<Key> keys2(n);
    vector<Val> vals2(n, default_value);
    vector<char> flag2(n);
    int shift2 = 64 - __builtin_ctz(n);
    swap(N, n), swap(keys, keys2);
    swap(vals, vals2), swap(flag, flag2), swap(shift, shift2);
    if (reset == false) {
      for (int i = 0; i < (int)flag2.size(); i++) {
        if (flag2[i]) {
          int j = hint(keys2[i]);
          keys[j] = keys2[i];
          vals[j] = vals2[i];
          flag[j] = 1;
        }
      }
    }
  }

  int hint(const Key& k) {
    int hash = get_hash(k) >> shift;
    while (flag[hash] && keys[hash] != k) hash = (hash + 1) & (N - 1);
    return hash;
  }

 public:
  UnerasableHashMap(const Val& _default_value = Val{})
      : occupied_num(0), default_value(_default_value) {
    init(init_size, true);
  }

  // key が i である要素への参照を返す
  Val& operator[](const Key& k) {
    int i = hint(k);
    if (!flag[i]) {
      if constexpr (fixed_size == false) {
        if (occupied_num * 2 >= N) {
          init(2 * N), i = hint(k);
        }
      }
      keys[i] = k, flag[i] = 1, occupied_num++;
    }
    return vals[i];
  }

  Val get(const Key& k) {
    int i = hint(k);
    return flag[i] ? vals[i] : default_value;
  }

  // 走査, f に関数 f(key, val) を入れる
  template <typename F>
  void enumerate(const F f) {
    for (int i = 0; i < (int)flag.size(); i++) {
      if (flag[i]) f(keys[i], vals[i]);
    }
  }

  int count(const Key& k) { return flag[hint(k)]; }
  bool contain(const Key& k) { return flag[hint(k)]; }
  int size() const { return occupied_num; }
  void reset() { init(init_size, true); }
  void clear() { init(init_size, true); }
};
