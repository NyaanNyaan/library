#include <algorithm>
#include <cassert>
#include <fstream>
#include <limits>
#include <string>
#include <vector>

// https://hitonanode.github.io/cplib-cpp/flow/b-flow.hpp
namespace hitonanode {

// MaxFlow based and AtCoder Library, single class, no namespace, no private
// variables, compatible with C++11 Reference:
// <https://atcoder.github.io/ac-library/production/document_ja/maxflow.html>
template <class Cap>
struct mf_graph {
  struct simple_queue_int {
    std::vector<int> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const int &t) { payload.push_back(t); }
    int &front() { return payload[pos]; }
    void clear() {
      payload.clear();
      pos = 0;
    }
    void pop() { pos++; }
  };

  mf_graph() : _n(0) {}
  mf_graph(int n) : _n(n), g(n) {}

  int add_edge(int from, int to, Cap cap) {
    assert(0 <= from && from < _n);
    assert(0 <= to && to < _n);
    assert(0 <= cap);
    int m = int(pos.size());
    pos.push_back({from, int(g[from].size())});
    int from_id = int(g[from].size());
    int to_id = int(g[to].size());
    if (from == to) to_id++;
    g[from].push_back(_edge{to, to_id, cap});
    g[to].push_back(_edge{from, from_id, 0});
    return m;
  }

  struct edge {
    int from, to;
    Cap cap, flow;
  };

  edge get_edge(int i) {
    int m = int(pos.size());
    assert(0 <= i && i < m);
    auto _e = g[pos[i].first][pos[i].second];
    auto _re = g[_e.to][_e.rev];
    return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
  }
  std::vector<edge> edges() {
    int m = int(pos.size());
    std::vector<edge> result;
    for (int i = 0; i < m; i++) {
      result.push_back(get_edge(i));
    }
    return result;
  }
  void change_edge(int i, Cap new_cap, Cap new_flow) {
    int m = int(pos.size());
    assert(0 <= i && i < m);
    assert(0 <= new_flow && new_flow <= new_cap);
    auto &_e = g[pos[i].first][pos[i].second];
    auto &_re = g[_e.to][_e.rev];
    _e.cap = new_cap - new_flow;
    _re.cap = new_flow;
  }

  std::vector<int> level, iter;
  simple_queue_int que;

  void _bfs(int s, int t) {
    std::fill(level.begin(), level.end(), -1);
    level[s] = 0;
    que.clear();
    que.push(s);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (auto e : g[v]) {
        if (e.cap == 0 || level[e.to] >= 0) continue;
        level[e.to] = level[v] + 1;
        if (e.to == t) return;
        que.push(e.to);
      }
    }
  }
  Cap _dfs(int v, int s, Cap up) {
    if (v == s) return up;
    Cap res = 0;
    int level_v = level[v];
    for (int &i = iter[v]; i < int(g[v].size()); i++) {
      _edge &e = g[v][i];
      if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
      Cap d = _dfs(e.to, s, std::min(up - res, g[e.to][e.rev].cap));
      if (d <= 0) continue;
      g[v][i].cap += d;
      g[e.to][e.rev].cap -= d;
      res += d;
      if (res == up) return res;
    }
    level[v] = _n;
    return res;
  }

  Cap flow(int s, int t) { return flow(s, t, std::numeric_limits<Cap>::max()); }
  Cap flow(int s, int t, Cap flow_limit) {
    assert(0 <= s && s < _n);
    assert(0 <= t && t < _n);
    assert(s != t);

    level.assign(_n, 0), iter.assign(_n, 0);
    que.clear();

    Cap flow = 0;
    while (flow < flow_limit) {
      _bfs(s, t);
      if (level[t] == -1) break;
      std::fill(iter.begin(), iter.end(), 0);
      Cap f = _dfs(t, s, flow_limit - flow);
      if (!f) break;
      flow += f;
    }
    return flow;
  }

  std::vector<bool> min_cut(int s) {
    std::vector<bool> visited(_n);
    simple_queue_int _que;
    _que.push(s);
    while (!_que.empty()) {
      int p = _que.front();
      _que.pop();
      visited[p] = true;
      for (auto e : g[p]) {
        if (e.cap && !visited[e.to]) {
          visited[e.to] = true;
          _que.push(e.to);
        }
      }
    }
    return visited;
  }

  void dump_graphviz(std::string filename = "maxflow") const {
    std::ofstream ss(filename + ".DOT");
    ss << "digraph{\n";
    for (int i = 0; i < _n; i++) {
      for (const auto &e : g[i]) {
        if (e.cap > 0) ss << i << "->" << e.to << "[label=" << e.cap << "];\n";
      }
    }
    ss << "}\n";
    ss.close();
    return;
  }

  int _n;
  struct _edge {
    int to, rev;
    Cap cap;
  };
  std::vector<std::pair<int, int>> pos;
  std::vector<std::vector<_edge>> g;
};

// Cost scaling
// https://people.orie.cornell.edu/dpw/orie633/
template <class Cap, class Cost, int SCALING = 1, int REFINEMENT_ITER = 20>
struct mcf_costscaling {
  mcf_costscaling() = default;
  mcf_costscaling(int n) : _n(n), to(n), b(n), p(n) {}

  int _n;
  std::vector<Cap> cap;
  std::vector<Cost> cost;
  std::vector<int> opposite;
  std::vector<std::vector<int>> to;
  std::vector<Cap> b;
  std::vector<Cost> p;

  int add_edge(int from_, int to_, Cap cap_, Cost cost_) {
    assert(0 <= from_ and from_ < _n);
    assert(0 <= to_ and to_ < _n);
    assert(0 <= cap_);
    cost_ *= (_n + 1);
    const int e = int(cap.size());
    to[from_].push_back(e);
    cap.push_back(cap_);
    cost.push_back(cost_);
    opposite.push_back(to_);

    to[to_].push_back(e + 1);
    cap.push_back(0);
    cost.push_back(-cost_);
    opposite.push_back(from_);
    return e / 2;
  }
  void add_supply(int v, Cap supply) { b[v] += supply; }
  void add_demand(int v, Cap demand) { add_supply(v, -demand); }

  template <typename RetCost = Cost>
  RetCost solve() {
    Cost eps = 1;
    std::vector<int> que;
    for (const auto c : cost) {
      while (eps <= -c) eps <<= SCALING;
    }
    for (; eps >>= SCALING;) {
      auto no_admissible_cycle = [&]() -> bool {
        for (int i = 0; i < _n; i++) {
          if (b[i]) return false;
        }
        std::vector<Cost> pp = p;
        for (int iter = 0; iter < REFINEMENT_ITER; iter++) {
          bool flg = false;
          for (int e = 0; e < int(cap.size()); e++) {
            if (!cap[e]) continue;
            int i = opposite[e ^ 1], j = opposite[e];
            if (pp[j] > pp[i] + cost[e] + eps)
              pp[j] = pp[i] + cost[e] + eps, flg = true;
          }
          if (!flg) return p = pp, true;
        }
        return false;
      };
      if (no_admissible_cycle()) continue;  // Refine

      for (int e = 0; e < int(cap.size()); e++) {
        const int i = opposite[e ^ 1], j = opposite[e];
        const Cost cp_ij = cost[e] + p[i] - p[j];
        if (cap[e] and cp_ij < 0)
          b[i] -= cap[e], b[j] += cap[e], cap[e ^ 1] += cap[e], cap[e] = 0;
      }
      que.clear();
      int qh = 0;
      for (int i = 0; i < _n; i++) {
        if (b[i] > 0) que.push_back(i);
      }
      std::vector<int> iters(_n);
      while (qh < int(que.size())) {
        const int i = que[qh++];
        for (; iters[i] < int(to[i].size()) and b[i]; ++iters[i]) {  // Push
          int e = to[i][iters[i]];
          if (!cap[e]) continue;
          int j = opposite[e];
          Cost cp_ij = cost[e] + p[i] - p[j];
          if (cp_ij >= 0) continue;
          Cap f = b[i] > cap[e] ? cap[e] : b[i];
          if (b[j] <= 0 and b[j] + f > 0) que.push_back(j);
          b[i] -= f, b[j] += f, cap[e] -= f, cap[e ^ 1] += f;
        }

        if (b[i] > 0) {  // Relabel
          bool flg = false;
          for (int e : to[i]) {
            if (!cap[e]) continue;
            Cost x = p[opposite[e]] - cost[e] - eps;
            if (!flg or x > p[i]) flg = true, p[i] = x;
          }
          que.push_back(i), iters[i] = 0;
        }
      }
    }
    RetCost ret = 0;
    for (int e = 0; e < int(cap.size()); e += 2)
      ret += RetCost(cost[e]) * cap[e ^ 1];
    return ret / (_n + 1);
  }
  std::vector<Cost> potential() const {
    std::vector<Cost> ret = p, c0 = cost;
    for (auto &x : ret) x /= (_n + 1);
    for (auto &x : c0) x /= (_n + 1);
    while (true) {
      bool flg = false;
      for (int i = 0; i < _n; i++) {
        for (const auto e : to[i]) {
          if (!cap[e]) continue;
          int j = opposite[e];
          auto y = ret[i] + c0[e];
          if (ret[j] > y) ret[j] = y, flg = true;
        }
      }
      if (!flg) break;
    }
    return ret;
  }
  struct edge {
    int from, to;
    Cap cap, flow;
    Cost cost;
  };
  edge get_edge(int e) const {
    int m = cap.size() / 2;
    assert(e >= 0 and e < m);
    return {opposite[e * 2 + 1], opposite[e * 2], cap[e * 2] + cap[e * 2 + 1],
            cap[e * 2 + 1], cost[e * 2] / (_n + 1)};
  }
  std::vector<edge> edges() const {
    int m = cap.size() / 2;
    std::vector<edge> result(m);
    for (int i = 0; i < m; i++) result[i] = get_edge(i);
    return result;
  }
};

// cost を N+1 倍する前処理を行うので inf の扱いに注意するか i128 を使う
template <typename CAP, typename COST>
struct B_Flow {
  int N, E;
  COST cost_bias;
  bool infeasible;
  mf_graph<CAP> mf;
  mcf_costscaling<CAP, COST> mcf;
  std::vector<CAP> b;
  std::vector<CAP> fbias;
  std::vector<int> fdir;
  std::vector<CAP> f;
  std::vector<COST> potential;

  B_Flow(int _n = 0)
      : N(_n),
        E(0),
        cost_bias(0),
        infeasible(false),
        mf(N + 2),
        mcf(N + 2),
        b(N) {}

  void add_supply(int v, CAP supply) { b[v] += supply; }
  void add_demand(int v, CAP demand) { b[v] -= demand; }
  void add_edge(int s, int t, CAP lower_cap, CAP upper_cap, COST cost) {
    assert(s >= 0 and s < N);
    assert(t >= 0 and t < N);
    if (lower_cap > upper_cap) {
      infeasible = true;
      return;
    }
    E++;
    if (s == t) {
      if (cost > 0) {
        upper_cap = lower_cap;
      } else {
        lower_cap = upper_cap;
      }
    }
    if (cost < 0) {
      fbias.emplace_back(lower_cap);
      fdir.emplace_back(-1);
      cost_bias += cost * upper_cap;
      b[s] -= upper_cap;
      b[t] += upper_cap;
      mf.add_edge(t, s, upper_cap - lower_cap);
      mcf.add_edge(t, s, upper_cap - lower_cap, -cost);
    } else {
      fbias.emplace_back(upper_cap);
      fdir.emplace_back(1);
      if (lower_cap < 0) {
        cost_bias += cost * lower_cap, b[s] -= lower_cap, b[t] += lower_cap;
        upper_cap -= lower_cap, lower_cap = 0;
      }
      if (lower_cap > 0) {
        cost_bias += cost * lower_cap;
        b[s] -= lower_cap;
        b[t] += lower_cap;
        upper_cap -= lower_cap;
      }
      mf.add_edge(s, t, upper_cap);
      mcf.add_edge(s, t, upper_cap, cost);
    }
  }

  std::pair<bool, COST> solve() {
    if (infeasible) return std::make_pair(false, 0);
    CAP bsum = 0, bsum_negative = 0;
    for (int i = 0; i < N; i++) {
      if (b[i] > 0) {
        mf.add_edge(N, i, b[i]), mcf.add_edge(N, i, b[i], 0), bsum += b[i];
      } else {
        mf.add_edge(i, N + 1, -b[i]), mcf.add_edge(i, N + 1, -b[i], 0),
            bsum_negative -= b[i];
      }
    }
    if (bsum != bsum_negative or mf.flow(N, N + 1) < bsum)
      return std::make_pair(false, 0);
    std::fill(b.begin(), b.end(), 0);
    mcf.add_supply(N, bsum);
    mcf.add_demand(N + 1, bsum);
    COST ret = mcf.solve();
    potential = mcf.potential(), potential.resize(N);
    COST cost_ret = cost_bias + ret;
    cost_bias = 0;
    f = fbias;
    auto edges = mcf.edges();
    for (int e = 0; e < E; e++)
      f[e] -= fdir[e] * (edges[e].cap - edges[e].flow);
    return std::make_pair(true, cost_ret);
  }
};

}  // namespace hitonanode
