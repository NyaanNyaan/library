#pragma once

#include <utility>
#include <vector>
using namespace std;

#include "../atcoder/segtree.hpp"
#include "../segment-tree/lazy-segment-tree-utility.hpp"

namespace PartiallyRetroactivePriorityQueueImpl {

template <typename T>
pair<T, int> op1(pair<T, int> a, pair<T, int> b) {
  return min(a, b);
}
template <typename T>
pair<T, int> e1() {
  return make_pair(numeric_limits<T>::max(), -1);
}
template <typename T>
pair<T, int> op2(pair<T, int> a, pair<T, int> b) {
  return max(a, b);
}
template <typename T>
pair<T, int> e2() {
  return make_pair(numeric_limits<T>::min(), -1);
}

// 補助的なデータ構造
template <typename T, bool minimize>
struct Aux_Segtree1 {
  using Seg =
      conditional_t<minimize, atcoder::segtree<pair<T, int>, op1<T>, e1<T>>,
                    atcoder::segtree<pair<T, int>, op2<T>, e2<T>>>;
  int N, size;
  T sum;
  Seg seg;
  vector<multiset<T>> st;

  Aux_Segtree1(int n) : N(n), size(0), sum(0), seg(N), st(N) {}

  void insert(int t, T x = 1) {
    st[t].insert(x);
    size++, sum += x;
    update_t(t);
  }
  void erase(int t, T x = 1) {
    assert(st[t].find(x) != end(st[t]));
    st[t].erase(st[t].find(x));
    size--, sum -= x;
    update_t(t);
  }
  bool find(int t, T x = 1) { return st[t].find(x) != end(st[t]); }
  pair<T, int> get(int l, int r) { return seg.prod(l, r); }
  int get_size() const { return size; }
  T get_sum() const { return sum; }

 private:
  void update_t(int t) {
    T val{};
    int u{};
    if (st[t].empty()) {
      if constexpr (minimize) {
        val = numeric_limits<T>::max();
      } else {
        val = numeric_limits<T>::min();
      }
      u = -1;
    } else {
      if constexpr (minimize) {
        val = *begin(st[t]);
      } else {
        val = *rbegin(st[t]);
      }
      u = t;
    }
    seg.set(t, make_pair(val, u));
  }
};

// 最大値を pop する pq
template <typename T>
struct PartiallyRetroactivePriorityQueue {
  int N;
  AddMin_LazySegmentTree<int, 1001001001> flow;
  Aux_Segtree1<T, true> used;
  Aux_Segtree1<T, false> unused, pop_used, pop_unused;

  PartiallyRetroactivePriorityQueue(int n)
      : N(n),
        flow(vector<int>(N, 0)),
        used(N),
        unused(N),
        pop_used(N),
        pop_unused(N) {}

  void add_insert(int t, const T& x) {
    int l = find_left(t);
    if (int u = pop_unused.get(l, N).second; u != -1) {
      used.insert(t, x);
      pop_unused.erase(u);
      pop_used.insert(u);
      if (u < t) {
        flow.update(u, t, -1);
      } else {
        flow.update(t, u, +1);
      }
      return;
    }
    auto [val, u] = used.get(l, N);
    if (u != -1 and val < x) {
      used.insert(t, x);
      used.erase(u, val);
      unused.insert(u, val);
      if (u < t) {
        flow.update(u, t, -1);
      } else {
        flow.update(t, u, +1);
      }
    } else {
      unused.insert(t, x);
    }
  }

  void del_insert(int t, const T& x) {
    if (unused.find(t, x)) {
      unused.erase(t, x);
      return;
    }
    assert(used.find(t, x));
    int r = find_right(t);
    if (auto [val, u] = unused.get(0, r); u != -1) {
      used.erase(t, x);
      used.insert(u, val);
      unused.erase(u, val);
      if (u < t) {
        flow.update(u, t, +1);
      } else {
        flow.update(t, u, -1);
      }
      return;
    }
    int u = pop_used.get(t, r).second;
    assert(u != -1);
    used.erase(t, x);
    pop_used.erase(u);
    pop_unused.insert(u);
    flow.update(t, u, -1);
  }

  void add_erase(int t) {
    int r = find_right(t);
    if (auto [val, u] = unused.get(0, r); u != -1) {
      used.insert(u, val);
      unused.erase(u, val);
      pop_used.insert(t);
      if (u < t) {
        flow.update(u, t, +1);
      } else {
        flow.update(t, u, -1);
      }
      return;
    }
    pop_unused.insert(t);
  }

  void del_erase(int t) {
    if (pop_unused.find(t)) {
      pop_unused.erase(t);
      return;
    }
    assert(pop_used.find(t));
    int l = find_left(t);
    if (int u = pop_unused.get(l, N).second; u != -1) {
      pop_used.erase(t);
      pop_used.insert(u);
      pop_unused.erase(u);
      if (u < t) {
        flow.update(u, t, -1);
      } else {
        flow.update(t, u, +1);
      }
      return;
    }
    auto [val, u] = used.get(l, N);
    assert(u != -1);
    used.erase(u, val);
    unused.insert(u, val);
    pop_used.erase(t);
    if (u < t) {
      flow.update(u, t, -1);
    } else {
      flow.update(t, u, +1);
    }
  }

  void clear(int t) {
    do {
      auto [val, u] = used.get(t, t + 1);
      if (u == -1) break;
      del_insert(t, val);
    } while (1);
    do {
      auto [val, u] = unused.get(t, t + 1);
      if (u == -1) break;
      del_insert(t, val);
    } while (1);
    while (pop_used.find(t) or pop_unused.find(t)) {
      del_erase(t);
    }
  }

  int get_size() { return unused.get_size(); }
  T get_popped_sum() const { return used.get_sum(); }
  T get_unpopped_sum() const { return unused.get_sum(); }
  int is_error() { return pop_unused.get_size() > 0; }

 private:
  int find_left(int t) {
    assert(flow.query(0, N) >= 0);
    return flow.min_left(t, [](int x) { return x > 0; });
  }
  int find_right(int t) {
    assert(flow.query(0, N) >= 0);
    return flow.max_right(t, [](int x) { return x > 0; }) + 1;
  }
};

}  // namespace PartiallyRetroactivePriorityQueueImpl
using PartiallyRetroactivePriorityQueueImpl::PartiallyRetroactivePriorityQueue;
