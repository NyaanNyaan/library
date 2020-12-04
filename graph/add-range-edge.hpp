#pragma once

// do not forget setting graph_size !!
struct RangeEdges {
  int N, idx;

 private:
  int graph_size_;

 public:
  RangeEdges(int n, int q) {
    N = 1;
    while (N < n) N *= 2;
    graph_size_ = N * 3 + q * __builtin_ctz(N) + 10;
    idx = 3 * N;
  };

  int graph_size() const { return graph_size_; }

  template <typename F>
  void build(const F& add_edge) {
    for (int i = 0; i < N; i++) {
      if (i) {
        add_edge(N + i, N + (i >> 1) + 0);
        add_edge(N + i, N + (i >> 1) + 1);
        add_edge((N << 1) + (i >> 1) + 0, (N << 1) + i);
        add_edge((N << 1) + (i >> 1) + 1, (N << 1) + i);
      }
      add_edge(i + N, i);
      add_edge(i, i + (N << 1));
    }
  }

  // from [fl, fr) to [to, tr)
  template <typename F>
  void range_add(const F& add_edge, int fl, int fr, int tl, int tr) {
    int fn = idx++;
    int tn = idx++;
    add_edge(tn, fn);
    for (fl += N, fr += N; fl < fr; fl >>= 1, fr >>= 1) {
      if (fl & 1) add_edge(fn, N + (fl++));
      if (fr & 1) add_edge(fn, N + (--fr));
    }
    for (tl += N, tr += N; tl < tr; tl >>= 1, tr >>= 1) {
      if (tl & 1) add_edge((tl++) + (N << 1), tn);
      if (tr & 1) add_edge((--tr) + (N << 1), tn);
    }
  }

  // from [fl, fr) to [to, tr)
  template <typename C, typename F>
  void weighted_range_add(const F& add_edge, int fl, int fr, int tl, int tr,
                          C cost) {
    int fn = idx++;
    int tn = idx++;
    add_edge(tn, fn, cost);
    for (fl += N, fr += N; fl < fr; fl >>= 1, fr >>= 1) {
      if (fl & 1) add_edge(fn, N + (fl++), C(0));
      if (fr & 1) add_edge(fn, N + (--fr), C(0));
    }
    for (tl += N, tr += N; tl < tr; tl >>= 1, tr >>= 1) {
      if (tl & 1) add_edge((tl++) + (N << 1), tn, C(0));
      if (tr & 1) add_edge((--tr) + (N << 1), tn, C(0));
    }
  }
};
