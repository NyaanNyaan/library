#pragma once

#include <utility>
using namespace std;

template <typename T = double, T INF = 1e100, bool PERSISTENT = false,
          int DEPTH_LIMIT = 40>
struct DynamicLiChaoTree {
  struct Line {
    T a, b;
    Line(T _a, T _b) : a(_a), b(_b) {}
    T operator()(T x) const { return a * x + b; }
  };

  struct Node {
    Line line;
    Node* p[2];
    Node(T a, T b) : line(a, b) { p[0] = p[1] = nullptr; }
  };
  Node* alloc(T a, T b) { return new Node(a, b); }
  Node* clone(Node* p) { return PERSISTENT ? new Node(*p) : p; }

  Node* root;
  T L_root, R_root;
  DynamicLiChaoTree(T l, T r) : root(nullptr), L_root(l), R_root(r) {
    assert(L_root <= R_root);
  }

  Node* _dfs(Node* p, Line cur, T l, T r, int depth) {
    if (!p) {
      p = alloc(cur.a, cur.b);
      return p;
    }
    p = clone(p);
    bool fl = cur(l) < p->line(l);
    bool fr = cur(r) < p->line(r);
    if (fl == fr) {
      if (fl) p->line = cur;
      return p;
    }
    if (l == r) return p;
    T m = (l + r) / 2;
    bool fm = cur(m) < p->line(m);
    if (fm) swap(p->line, cur);
    if (depth < DEPTH_LIMIT) {
      if (fl ^ fm) {
        p->p[0] = _dfs(p->p[0], cur, l, m, depth + 1);
      } else {
        p->p[1] = _dfs(p->p[1], cur, m, r, depth + 1);
      }
    }
    return p;
  }
  void add_line(T a, T b) { root = _dfs(root, Line{a, b}, L_root, R_root, 0); }

  T get(T x) const {
    assert(L_root <= x and x <= R_root);
    T l = L_root, r = R_root, y = INF;
    Node* p = root;
    while (p) {
      y = min(y, p->line(x));
      T m = (l + r) / 2;
      if (x <= m) {
        p = p->p[0], r = m;
      } else {
        p = p->p[1], l = m;
      }
    }
    return y;
  }
};
