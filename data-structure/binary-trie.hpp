#pragma once

template <typename T, int MAX_LOG, int NODES = 16777216>
struct BinaryTrie {
  using Container = vector<int>;
  struct Node {
    Node *nxt[2];
    int exist;
    Container accept;
    Node() {}
  };

  Node *pool;
  int pid;
  T lazy;
  Node *nil;
  Node *root;

  BinaryTrie() : pid(0), lazy(T(0)), nil(nullptr) {
    pool = new Node[NODES];
    nil = my_new();
    nil->nxt[0] = nil->nxt[1] = root = nil;
  }

  Node *my_new(int exist_ = 0, int id = -1) {
    pool[pid].nxt[0] = pool[pid].nxt[1] = nil;
    pool[pid].exist = exist_;
    if (id != -1) pool[pid].accept.push_back(id);
    return &(pool[pid++]);
  }

  Node *merge(Node *l, Node *r) {
    pool[pid].nxt[0] = l;
    pool[pid].nxt[1] = r;
    pool[pid].exist = l->exist + r->exist;
    return &(pool[pid++]);
  }

 private:
  Node *add_(const T &x, int id, Node *n, int bit_idx) {
    if (bit_idx == -1) {
      if (n == nil) return my_new(1, id);
      n->exist++;
      n->accept.push_back(id);
      return n;
    } else {
      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))
        return merge(add_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);
      else
        return merge(n->nxt[0], add_(x, id, n->nxt[1], bit_idx - 1));
    }
  }

 public:
  void add(const T &x, int id = -1) { root = add_(x, id, root, MAX_LOG); }

 private:
  Node *del_(const T &x, int id, Node *n, int bit_idx) {
    if (bit_idx == -1) {
      n->exist--;
      return n;
    } else {
      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))
        return merge(del_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);
      else
        return merge(n->nxt[0], del_(x, id, n->nxt[1], bit_idx - 1));
    }
  }

 public:
  void del(const T &x, int id = -1) { root = del_(x, id, root, MAX_LOG); }

 private:
  pair<int, Container &> find_(const T &x, Node *n, int bit_idx) {
    if (bit_idx == -1)
      return pair<int, Container &>(n->exist, n->accept);
    else {
      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))
        return find_(x, n->nxt[0], bit_idx - 1);
      else
        return find_(x, n->nxt[1], bit_idx - 1);
    }
  }

 public:
  pair<int, Container &> find(const T &x) { return find_(x, root, MAX_LOG); }

 private:
  pair<T, Container &> max_element_(Node *n, int bit_idx) {
    if (bit_idx == -1) return pair<T, Container &>(0, n->accept);
    if (n->nxt[~(lazy >> bit_idx) & 1]->exist) {
      auto ret = max_element_(n->nxt[~(lazy >> bit_idx) & 1], bit_idx - 1);
      ret.first |= T(1) << bit_idx;
      return ret;
    } else {
      return max_element_(n->nxt[(lazy >> bit_idx) & 1], bit_idx - 1);
    }
  }

 public:
  pair<T, Container &> max_element() { return max_element_(root, MAX_LOG); }

 private:
  pair<T, Container &> min_element_(Node *n, int bit_idx) {
    if (bit_idx == -1) return pair<T, Container &>(0, n->accept);
    if (n->nxt[(lazy >> bit_idx) & 1]->exist) {
      return min_element_(n->nxt[(lazy >> bit_idx) & 1], bit_idx - 1);
    } else {
      auto ret = min_element_(n->nxt[~(lazy >> bit_idx) & 1], bit_idx - 1);
      ret.first |= T(1) << bit_idx;
      return ret;
    }
  }

 public:
  pair<T, Container &> min_element() { return min_element_(root, MAX_LOG); }

 private:
  pair<T, Container &> get_kth_(Node *n, int64_t k, int bit_idx) {
    if (bit_idx == -1) return pair<T, Container &>(0, n->accept);
    int ex0 = n->nxt[(lazy >> bit_idx) & 1]->exist;
    if (ex0 < k) {
      auto ret = get_kth_(n->nxt[~(lazy >> bit_idx) & 1], k - ex0, bit_idx - 1);
      ret.first |= T(1) << bit_idx;
      return ret;
    } else {
      return get_kth_(n->nxt[(lazy >> bit_idx) & 1], k, bit_idx - 1);
    }
  }

 public:
  pair<T, Container &> get_kth(int64_t k) { return get_kth_(root, k, MAX_LOG); }

  void operate_xor(T x) { lazy ^= x; }
};

/**
 * @brief Binary Trie
 * @docs docs/data-structure/binary-trie.md
 */
