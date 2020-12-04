#pragma once

template <typename T, int shift = 4>
struct PersistentArray {
  struct Node {
    Node *ns[1 << shift];
    Node() { memset(ns, 0, sizeof(ns)); }
    Node(const Node &other) { memcpy(ns, other.ns, sizeof(ns)); }
    Node(const Node *other) { memcpy(ns, other->ns, sizeof(ns)); }
  };
  inline Node *my_new() { return new Node(); }
  inline Node *my_new(const Node &other) { return new Node(other); }
  inline Node *my_new(const Node *other) { return new Node(other); }
  inline T *my_new_leaf(const T &val) { return new T{val}; }

  using i64 = long long;
  static constexpr int mask = (1 << shift) - 1;
  Node *root;
  int depth;
  T ID;

  PersistentArray() {}

  PersistentArray(i64 MAX, T ID_ = T(0)) : root(my_new()), depth(0), ID(ID_) {
    while (MAX) ++depth, MAX >>= shift;
  }

  PersistentArray(const vector<T> &v, T ID_ = T(0))
      : root(my_new()), depth(0), ID(ID_) {
    i64 MAX = v.size();
    while (MAX) ++depth, MAX >>= shift;
    for (int i = 0; i < (int)v.size(); i++) {
      Node *n = root;
      for (int k = i, d = depth; d; d--) {
        if (!(n->ns[k & mask])) {
          if (d == 1)
            n->ns[k & mask] = reinterpret_cast<Node *>(my_new_leaf(v[i]));
          else
            n->ns[k & mask] = my_new();
        }
        n = n->ns[k & mask];
        k >>= shift;
      }
    }
  }

  T get(Node *n, i64 k) const {
    for (int i = depth; i; --i) {
      n = n ? n->ns[k & mask] : nullptr;
      k >>= shift;
    }
    return n ? *reinterpret_cast<T *>(n) : ID;
  }
  T get(i64 k) const { return get(root, k); }

  Node *update(Node *n, i64 k, const T &val) {
    stack<pair<Node *, int>> st;
    for (int i = depth; i; --i) {
      st.emplace(n, k & mask);
      n = n ? n->ns[k & mask] : nullptr;
      k >>= shift;
    }
    Node *chd = reinterpret_cast<Node *>(my_new_leaf(val));
    while (!st.empty()) {
      Node *par;
      int k;
      tie(par, k) = st.top();
      st.pop();
      Node *nxt = par ? my_new(par) : my_new();
      nxt->ns[k] = chd;
      chd = nxt;
    }
    return root = chd;
  }
  Node *update(i64 k, const T &val) { return update(root, k, val); }
};

/**
 * @brief 永続配列
 */
