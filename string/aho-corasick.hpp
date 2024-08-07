#pragma once

#include "trie.hpp"

template <size_t X = 26, char margin = 'a', bool heavy = false>
struct AhoCorasick : Trie<X + 1, margin> {
  using TRIE = Trie<X + 1, margin>;
  using TRIE::next;
  using TRIE::st;
  using TRIE::TRIE;
  vector<int> cnt;

  void build() {
    int n = st.size();
    cnt.resize(n);
    for (int i = 0; i < n; i++) {
      if (heavy) sort(st[i].idxs.begin(), st[i].idxs.end());
      cnt[i] = st[i].idxs.size();
    }

    queue<int> que;
    for (int i = 0; i < (int)X; i++) {
      if (~next(0, i)) {
        next(next(0, i), X) = 0;
        que.emplace(next(0, i));
      } else {
        next(0, i) = 0;
      }
    }

    while (!que.empty()) {
      auto &x = st[que.front()];
      int fail = x.nxt[X];

      cnt[que.front()] += cnt[fail];
      que.pop();

      for (int i = 0; i < (int)X; i++) {
        int &nx = x.nxt[i];
        if (nx < 0) {
          nx = next(fail, i);
          continue;
        }
        que.emplace(nx);
        next(nx, X) = next(fail, i);
        if (heavy) {
          auto &idx = st[nx].idxs;
          auto &idy = st[next(fail, i)].idxs;
          vector<int> idz;
          set_union(idx.begin(), idx.end(), idy.begin(), idy.end(),
                    back_inserter(idz));
          idx = idz;
        }
      }
    }
  }

  // heavy
  // true  : 各パターン文字列に対してマッチした回数を計算
  // false : 全てのパターン文字列にマッチした回数の総和
  conditional_t<heavy, unordered_map<int, long long>, long long> match(
      string s) {
    unordered_map<int, int> pos_cnt;
    int pos = 0;
    for (auto &c : s) {
      pos = next(pos, c - margin);
      pos_cnt[pos]++;
    }
    conditional_t<heavy, unordered_map<int, long long>, long long> res{};
    for (auto &[key, val] : pos_cnt) {
      if constexpr (heavy) {
        for (auto &x : st[key].idxs) res[x] += val;
      } else {
        res += 1LL * cnt[key] * val;
      }
    }
    return res;
  }

  int count(int pos) { return cnt[pos]; }
};
