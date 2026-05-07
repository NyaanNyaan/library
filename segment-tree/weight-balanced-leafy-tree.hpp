#pragma once

#include <vector>
using namespace std;

#include "../internal/internal-type-traits.hpp"

ENABLE_HAS_FUNCTION(push);

template <typename Node>
struct WBLTBase {
  using DATA_T = decltype(Node::dat);
  using SIZE_T = decltype(Node::size);
  vector<Node> n;
  int top;
  static constexpr double ALPHA = 0.292;
  bool too_heavy(SIZE_T x, SIZE_T y) { return y < ALPHA * (x + y); }

  WBLTBase(int size) : n(size), top(1) {}

  const Node& operator[](int x) { return n[x]; }

  template <typename... Args>
  int alloc(Args... args) {
    n[top] = Node(args...);
    return top++;
  }
  bool almost_full() const { return top >= int(n.size()) * 0.95; }
  void reset() { top = 1; }

  void push([[maybe_unused]] int x) {
    if constexpr (has_push_v<Node>) n[x].push(n.data(), top);
  }
  pair<int, int> cut(int t) {
    push(t);
    return {n[t].l, n[t].r};
  }
  int join(int l, int r) {
    int t = alloc(l, r);
    n[t].pull(n.data());
    return t;
  }

  int merge(int x, int y) {
    if (!x || !y) return x + y;
    if (too_heavy(n[x].size, n[y].size)) {
      auto [a, b] = cut(x);
      if (too_heavy(n[b].size + n[y].size, n[a].size)) {
        auto [c, d] = cut(b);
        return merge(merge(a, c), merge(d, y));
      } else {
        return merge(a, merge(b, y));
      }
    } else if (too_heavy(n[y].size, n[x].size)) {
      auto [a, b] = cut(y);
      if (too_heavy(n[x].size + n[a].size, n[b].size)) {
        auto [c, d] = cut(a);
        return merge(merge(x, c), merge(d, b));
      } else {
        return merge(merge(x, a), b);
      }
    } else {
      return join(x, y);
    }
  }
  pair<int, int> split(int x, SIZE_T k) {
    if (!x or !k) return {0, x};
    if (k >= n[x].size) return {x, 0};
    auto [a, b] = cut(x);
    if (k <= n[a].size) {
      auto [l, r] = split(a, k);
      return {l, merge(r, b)};
    } else {
      auto [l, r] = split(b, k - n[a].size);
      return {merge(a, l), r};
    }
  }
  int shrink(int x, SIZE_T k) {
    if (!x or !k) return 0;
    if (k >= n[x].size) return x;
    auto [a, b] = cut(x);
    if (k <= n[a].size) return shrink(a, k);
    return merge(a, shrink(b, k - n[a].size));
  }
  int k_times(int x, SIZE_T k) {
    if (!x or !k) return 0;
    if (k == 1) return x;
    if (k % 2 == 0) {
      int half = k_times(x, k / 2);
      return join(half, half);
    }
    auto dfs = [&](auto rc, SIZE_T s) -> pair<int, int> {
      if (s == 2) return {x, join(x, x)};
      if (s % 2 == 0) {
        auto [a, b] = rc(rc, s / 2);
        return {join(b, a), join(b, b)};
      } else {
        auto [a, b] = rc(rc, (s + 1) / 2);
        return {join(a, a), join(b, a)};
      }
    };
    return dfs(dfs, k).second;
  }
  // 0-indexed, 配列外参照は壊れる
  DATA_T get_kth(int x, SIZE_T k) {
    push(x);
    if (!n[x].l) return n[x].dat;
    if (k < n[n[x].l].size) return get_kth(n[x].l, k);
    return get_kth(n[x].r, k - n[n[x].l].size);
  }

  int build(const vector<DATA_T>& v, int l = -1, int r = -1) {
    if (l == -1) l = 0, r = v.size();
    if (l == r) return 0;
    if (l + 1 == r) return alloc(v[l]);
    int m = (l + r) / 2;
    return join(build(v, l, m), build(v, m, r));
  }

  virtual vector<DATA_T> dump(int t) {
    if (!t) return {};
    vector<DATA_T> res;
    auto dfs = [&](auto rc, int x) -> void {
      if (!n[x].l) {
        res.push_back(n[x].dat);
        return;
      }
      rc(rc, n[x].l);
      rc(rc, n[x].r);
    };
    dfs(dfs, t);
    return res;
  }
};

namespace RopeImpl {
template <typename DATA_T, typename SIZE_T>
struct Node {
  int l;
  union {
    int r;
    DATA_T dat;
  };
  SIZE_T size;
  Node() = default;
  Node(DATA_T _dat) : l(0), dat(_dat), size(1) {}
  Node(int _l, int _r) : l(_l), r(_r) {}
  void pull(Node* n) { size = n[l].size + n[r].size; }
};

template <typename DATA_T, typename SIZE_T = long long>
using Rope = WBLTBase<Node<DATA_T, SIZE_T>>;
}  // namespace RopeImpl

namespace PersistentWBLTImpl {
template <typename DATA_T, DATA_T (*f)(DATA_T, DATA_T), typename SIZE_T>
struct Node {
  int l, r;
  DATA_T dat;
  SIZE_T size;
  Node() = default;
  Node(DATA_T _dat) : l(0), dat(_dat), size(1) {}
  Node(int _l, int _r) : l(_l), r(_r) {}
  void pull(Node* n) {
    dat = f(n[l].dat, n[r].dat);
    size = n[l].size + n[r].size;
  }
};

template <typename DATA_T, DATA_T (*f)(DATA_T, DATA_T), DATA_T (*e)(),
          typename SIZE_T = long long>
struct PersistentWBLT : WBLTBase<Node<DATA_T, f, SIZE_T>> {
  using Base = WBLTBase<Node<DATA_T, f, SIZE_T>>;
  using Base::n;
  using Base::push;

  PersistentWBLT(int size) : Base(size) {}

  DATA_T fold(int x, SIZE_T l, SIZE_T r) {
    if (!x or l >= r) return e();
    if (!n[x].l) return (l <= 0 and 0 < r) ? n[x].dat : e();
    SIZE_T ls = n[n[x].l].size, rs = n[n[x].r].size;
    l = clamp<SIZE_T>(l, 0, ls + rs), r = clamp<SIZE_T>(r, 0, ls + rs);
    if (l >= r) return e();
    if (r - l == ls + rs) return n[x].dat;
    if (r <= ls) return fold(n[x].l, l, r);
    if (ls <= l) return fold(n[x].r, l - ls, r - ls);
    DATA_T L = fold(n[x].l, l, ls);
    DATA_T R = fold(n[x].r, 0, r - ls);
    return f(L, R);
  }
};

};  // namespace PersistentWBLTImpl

namespace PersistentLazyWBLTImpl {
template <typename DATA_T, typename LAZY_T, DATA_T (*f)(DATA_T, DATA_T),
          DATA_T (*g)(DATA_T, LAZY_T), LAZY_T (*h)(LAZY_T, LAZY_T),
          LAZY_T (*ei)(), typename SIZE_T = long long>
struct Node {
  int l, r;
  DATA_T dat;
  LAZY_T laz;
  SIZE_T size;
  Node() = default;
  Node(DATA_T _dat) : l(0), dat(_dat), laz(ei()), size(1) {}
  Node(int _l, int _r) : l(_l), r(_r), laz(ei()) {}
  void pull(Node* n) {
    dat = f(n[l].dat, n[r].dat);
    size = n[l].size + n[r].size;
  }
  void push(Node* n, int& top) {
    if (!l or laz == ei()) return;
    n[top] = n[l], n[top + 1] = n[r];
    l = top, r = top + 1, top += 2;
    n[l].dat = g(n[l].dat, laz), n[l].laz = h(n[l].laz, laz);
    n[r].dat = g(n[r].dat, laz), n[r].laz = h(n[r].laz, laz);
    laz = ei();
  }
};

template <typename DATA_T, typename LAZY_T, DATA_T (*f)(DATA_T, DATA_T),
          DATA_T (*g)(DATA_T, LAZY_T), LAZY_T (*h)(LAZY_T, LAZY_T),
          DATA_T (*ti)(), LAZY_T (*ei)(), typename SIZE_T = long long>
struct PersistentLazyWBLT
    : WBLTBase<Node<DATA_T, LAZY_T, f, g, h, ei, SIZE_T>> {
  using Base = WBLTBase<Node<DATA_T, LAZY_T, f, g, h, ei, SIZE_T>>;
  static_assert(has_push_v<Node<DATA_T, LAZY_T, f, g, h, ei, SIZE_T>>);
  using Base::join;
  using Base::n;
  using Base::push;
  using Base::top;
  PersistentLazyWBLT(int size) : Base(size) {}

  DATA_T fold(int x, SIZE_T l, SIZE_T r) {
    if (!x or l >= r) return ti();
    push(x);
    if (!n[x].l) return (l <= 0 and 0 < r) ? n[x].dat : ti();
    SIZE_T ls = n[n[x].l].size, rs = n[n[x].r].size;
    l = clamp<SIZE_T>(l, 0, ls + rs), r = clamp<SIZE_T>(r, 0, ls + rs);
    if (l >= r) return ti();
    if (r - l == ls + rs) return n[x].dat;
    if (r <= ls) return fold(n[x].l, l, r);
    if (ls <= l) return fold(n[x].r, l - ls, r - ls);
    DATA_T L = fold(n[x].l, l, ls);
    DATA_T R = fold(n[x].r, 0, r - ls);
    return f(L, R);
  }

  int affect(int x, LAZY_T laz) {
    if (!x) return x;
    n[top] = n[x];
    n[top].dat = g(n[top].dat, laz);
    n[top].laz = h(n[top].laz, laz);
    return top++;
  }

  int apply(int x, SIZE_T l, SIZE_T r, LAZY_T laz) {
    if (!x or l >= r) return x;
    push(x);
    if (!n[x].l) return (l <= 0 and 0 < r) ? affect(x, laz) : x;
    SIZE_T ls = n[n[x].l].size, rs = n[n[x].r].size;
    l = clamp<SIZE_T>(l, 0, ls + rs), r = clamp<SIZE_T>(r, 0, ls + rs);
    if (l >= r) return x;
    if (r - l == ls + rs) return affect(x, laz);
    if (r <= ls) return join(apply(n[x].l, l, r, laz), n[x].r);
    if (ls <= l) return join(n[x].l, apply(n[x].r, l - ls, r - ls, laz));
    return join(apply(n[x].l, l, ls, laz), apply(n[x].r, 0, r - ls, laz));
  }

  vector<DATA_T> dump(int t) override {
    if (!t) return {};
    vector<DATA_T> res;
    auto dfs = [&](auto rc, int x, LAZY_T e) -> void {
      if (!n[x].l) {
        res.push_back(g(n[x].dat, e));
        return;
      }
      e = h(n[x].laz, e);
      rc(rc, n[x].l, e);
      rc(rc, n[x].r, e);
    };
    dfs(dfs, t, ei());
    return res;
  }
};
};  // namespace PersistentLazyWBLTImpl

using RopeImpl::Rope;
using PersistentWBLTImpl::PersistentWBLT;
using PersistentLazyWBLTImpl::PersistentLazyWBLT;
