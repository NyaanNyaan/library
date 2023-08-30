#pragma once

#include <cassert>
#include <chrono>
#include <functional>
#include <vector>
using namespace std;

#include "../internal/internal-hash-function.hpp"

// 削除不可能な hashmap
//
// テンプレート引数
// fixed_size : これを true にするするとバケットサイズが固定になる
// get_hash : ハッシュ関数の指定
// 引数
// _default_value : val の初期値, この値で初期化
// _default_size :
// バケットサイズ, max(4, _default_size) 以上の 2 べきで初期化
// ただし fixed_size が true の時にしかサイズを変更できない

template <typename Key, typename Val, bool fixed_size = false,
          unsigned long long (*get_hash)(const Key&) =
              internal::hash_function<Key>>
struct UnerasableHashMap {
  int N, occupied_num, shift;
  vector<Key> keys;
  vector<Val> vals;
  vector<char> flag;

  Val default_value;
  int default_size;

  // サイズを n に変更する
  void init(int n, bool reset = false) {
    assert(n >= 4 && (n & (n - 1)) == 0);
    if constexpr (fixed_size) {
      assert(reset == true);
      n = N;
    }
    if (reset == true) {
      N = n, occupied_num = 0, shift = 64 - __builtin_ctz(n);
      keys.resize(n);
      vals.resize(n);
      flag.resize(n);
      fill(begin(vals), end(vals), default_value);
      fill(begin(flag), end(flag), 0);
    } else {
      N = n, shift = 64 - __builtin_ctz(n);
      vector<Key> keys2(n);
      vector<Val> vals2(n, default_value);
      vector<char> flag2(n);
      swap(keys, keys2), swap(vals, vals2), swap(flag, flag2);
      for (int i = 0; i < (int)flag2.size(); i++) {
        if (flag2[i]) {
          int j = hint(keys2[i]);
          keys[j] = keys2[i], vals[j] = vals2[i], flag[j] = 1;
        }
      }
    }
  }

  UnerasableHashMap(const Val& _default_value = Val{}, int _default_size = 4)
      : occupied_num(0), default_value(_default_value) {
    if (fixed_size == false) _default_size = 4;
    N = 4;
    while (N < _default_size) N *= 2;
    default_size = N;
    init(N, true);
  }

  int hint(const Key& k) {
    int hash = get_hash(k) >> shift;
    while (flag[hash] && keys[hash] != k) hash = (hash + 1) & (N - 1);
    return hash;
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
  void reset() { init(default_size, true); }
  void clear() { init(default_size, true); }
};
