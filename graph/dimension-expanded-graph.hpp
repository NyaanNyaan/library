#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "./graph-template.hpp"

template <int64_t DIM>
struct DimensionExpandedGraph {
  using i64 = long long;
  using A = array<i64, DIM>;

  i64 N;
  A g_size, coeff;

  template <typename... T>
  DimensionExpandedGraph(const T &... t) : N(1), g_size({t...}) {
    set_coeff();
  }

  void set_coeff() {
    coeff.fill(1);
    for (i64 i = 0; i < DIM; i++) {
      assert(g_size[i] != 0);
      for (i64 j = 0; j < i; j++) coeff[j] *= g_size[i];
      N *= g_size[i];
    }
  }

  i64 operator()(const A &a) {
    i64 ret = 0;
    for (i64 i = 0; i < DIM; i++) {
      if (a[i] < 0 or g_size[i] <= a[i]) return -1;
      ret += a[i] * coeff[i];
    }
    return ret;
  }

  A inv(i64 n) {
    A ret{};
    for (i64 i = 0; i < DIM; i++) {
      ret[i] = n / coeff[i];
      n %= coeff[i];
    }
    return ret;
  }

  i64 inner_id(i64, i64 n) { return n; }
  template <typename T, typename... U>
  i64 inner_id(i64 i, i64 n, T &&t, U &&... u) {
    if (t < 0 or g_size[i] <= t) return -1;
    n += coeff[i++] * t;
    return inner_id(i, n, forward<U>(u)...);
  }
  template <typename... T>
  i64 operator()(const T &... t) {
    return inner_id(0, 0, t...);
  }

  i64 ok(const A &a) {
    for (i64 i = 0; i < DIM; i++)
      if (a[i] < 0 or g_size[i] <= a[i]) return 0;
    return 1;
  }

  i64 inner_ok(i64) { return 1; }
  template <typename T, typename... U>
  i64 inner_ok(i64 idx, T &&t, U &&... u) {
    if (t < 0 or g_size[idx++] <= t) return 0;
    return inner_ok(idx, forward<U>(u)...);
  }
  template <typename... T>
  i64 ok(const T &... t) {
    return inner_ok(0, t...);
  }

  template <typename F>
  vector<i64> bfs(F f, A s = {}) {
    vector<i64> dist(N, -1);
    queue<A> Q;
    assert((*this)(s) != -1);
    dist[(*this)(s)] = 0;
    Q.push(s);
    while (!Q.empty()) {
      A c = Q.front();
      Q.pop();
      i64 idc = (*this)(c);
      f(c, [&](A d) {
        i64 idd = (*this)(d);
        if (idd == -1) return;
        if (dist[idd] == -1) {
          dist[idd] = dist[idc] + 1;
          Q.push(d);
        }
      });
    }
    return dist;
  }

  template <typename F>
  vector<i64> bfs01(F f, A s = {}) {
    vector<i64> dist(N, -1);
    vector<bool> vis(N, 0);
    deque<A> Q;
    assert((*this)(s) != -1);
    dist[(*this)(s)] = 0;
    Q.push_back(s);
    while (!Q.empty()) {
      A c = Q.front();
      Q.pop_front();
      i64 idc = (*this)(c);
      if (vis[idc]) continue;
      vis[idc] = true;
      i64 dc = dist[idc];
      f(c, [&](A d, i64 w) {
        i64 idd = (*this)(d);
        if (idd == -1) return;
        i64 dd = dist[idd];
        if (dd == -1 || dc + w < dd) {
          dist[idd] = dc + w;
          if (w == 0)
            Q.push_front(d);
          else
            Q.push_back(d);
        }
      });
    }
    return dist;
  }

  vector<i64> dijkstra(function<void(A, function<void(A, i64)>)> f, A s = {}) {
    vector<i64> dist(N, -1);
    using P = pair<i64, A>;
    priority_queue<P, vector<P>, greater<P>> Q;
    assert((*this)(s) != -1);
    Q.emplace(dist[(*this)(s)] = 0, s);
    while (!Q.empty()) {
      i64 dc;
      A c;
      tie(dc, c) = Q.top();
      Q.pop();
      i64 idc = (*this)(c);
      if (dist[idc] < dc) continue;
      f(c, [&](const A &d, i64 w) {
        i64 idd = (*this)(d);
        if (idd == -1) return;
        i64 dd = dist[idd];
        if (dd == -1 || dd > dc + w) {
          dist[idd] = dc + w;
          Q.emplace(dc + w, d);
        }
      });
    }
    return dist;
  }

  static vector<array<i64, 2>> direction4() {
    return {{{1, 0}}, {{0, 1}}, {{-1, 0}}, {{0, -1}}};
  }
};
