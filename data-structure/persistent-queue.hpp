#pragma once

template <typename T>
struct PersistentQueue {
  struct Node {
    int d;
    T val;
    vector<Node*> par;
    Node(int d_) : d(d_) {}
    Node(int d_, const T& val_, Node* n) : d(d_), val(val_), par({n}) {}
  };

  using P = pair<Node*, Node*>;
  vector<P> roots;

  PersistentQueue() {
    Node* root = new Node(0);
    roots.emplace_back(root, root);
  }

  int push(const T& val, int id = -1) {
    Node *s, *e;
    tie(s, e) = id == -1 ? roots.back() : roots[id];
    Node* ne = new Node(e->d + 1, val, e);
    roots.emplace_back(s, ne);
    for (int i = 0;; i++) {
      if ((int)e->par.size() <= i) break;
      Node* nxt = e->par[i];
      ne->par.push_back(e = nxt);
    }
    return (int)roots.size() - 1;
  }

  pair<T, int> pop(int id = -1) {
    Node *s, *e;
    tie(s, e) = id == -1 ? roots.back() : roots[id];
    Node* ns = e;
    for (int x = e->d - s->d - 1; x;) {
      int d = __builtin_ctz(x);
      ns = ns->par[d];
      x -= 1 << d;
    }
    roots.emplace_back(ns, e);
    return make_pair(ns->val, (int)roots.size() - 1);
  }
};