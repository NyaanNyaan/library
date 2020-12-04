#pragma once

namespace StaticGraphImpl {

template <typename T, bool Cond = is_void<T>::value>
struct E;
template <typename T>
struct E<T, false> {
  int to;
  T cost;
  E() {}
  E(const int& v, const T& c) : to(v), cost(c) {}
  operator int() const { return to; }
};
template <typename T>
struct E<T, true> {
  int to;
  E() {}
  E(const int& v) : to(v) {}
  operator int() const { return to; }
};

template <typename T = void>
struct StaticGraph {
 private:
  template <typename It>
  struct Es {
    It b, e;
    It begin() const { return b; }
    It end() const { return e; }
    int size() const { return int(e - b); }
    auto&& operator[](int i) const { return b[i]; }
  };
  
  int N, M, ec;
  vector<int> head;
  vector<pair<int, E<T>>> buf;
  vector<E<T>> es;

  void build() {
    partial_sum(begin(head), end(head), begin(head));
    es.resize(M);
    for (auto&& [u, e] : buf) es[--head[u]] = e;
  }

 public:
  StaticGraph(int _n, int _m) : N(_n), M(_m), ec(0), head(N + 1, 0) {
    buf.reserve(M);
  }

  template <typename... Args>
  void add_edge(int u, Args&&... args) {
#pragma GCC diagnostic ignored "-Wnarrowing"
    buf.emplace_back(u, E<T>{std::forward<Args>(args)...});
#pragma GCC diagnostic warning "-Wnarrowing"
    ++head[u];
    if ((int)buf.size() == M) build();
  }

  Es<typename vector<E<T>>::iterator> operator[](int u) {
    return {begin(es) + head[u], begin(es) + head[u + 1]};
  }
  const Es<typename vector<E<T>>::const_iterator> operator[](int u) const {
    return {begin(es) + head[u], begin(es) + head[u + 1]};
  }
  int size() const { return N; }
};

}  // namespace StaticGraphImpl

using StaticGraphImpl::StaticGraph;

/**
 * @brief Static Graph
 * @docs docs/graph/static-graph.md
 */