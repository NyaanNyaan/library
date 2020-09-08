#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

#include "./internal_scc.hpp"

namespace atcoder {

struct scc_graph {
 private:
  internal::scc_graph internal;

 public:
  scc_graph() : internal(0) {}
  scc_graph(int n) : internal(n) {}

  void add_edge(int from, int to) {
    int n = internal.num_vertices();
    assert(0 <= from && from < n);
    assert(0 <= to && to < n);
    internal.add_edge(from, to);
  }

  std::vector<std::vector<int>> scc() { return internal.scc(); }
};

}  // namespace atcoder
using namespace atcoder;
