#pragma once

template <int DIM, typename Data_t = long long>
struct DimensionExpandedGraph {
  static_assert(is_signed<Data_t>::value, "Data_t must be signed.");
  using DG = DimensionExpandedGraph;

  struct A : array<int, DIM> {
    using array<int, DIM>::operator[];
#pragma GCC diagnostic ignored "-Wnarrowing"
    template <typename... Args>
    A(Args... args) : array<int, DIM>({args...}) {}
#pragma GCC diagnostic warning "-Wnarrowing"

    A &operator+=(const A &r) {
      for (int i = 0; i < DIM; i++) (*this)[i] += r[i];
      return *this;
    }
    A &operator-=(const A &r) {
      for (int i = 0; i < DIM; i++) (*this)[i] -= r[i];
      return *this;
    }
    A operator+(const A &r) { return (*this) += r; }
    A operator-(const A &r) { return (*this) -= r; }

    int id() const { return DG::id(*this); }
    friend int id(const A &a) { return DG::id(a); }

    bool ok() const { return DG::ok(*this); }
    friend bool ok(const A &a) { return DG::ok(a); }

    inline bool is_add() const { return (*this)[0] == ADD; }
    friend inline bool is_add(const A &a) { return a[0] == ADD; }

    vector<A> near() const {
      static vector<A> res;
      res.clear();
      if (is_add() == true) return res;
      for (int i = 0; i < DIM; i++) {
        A asc(*this), dec(*this);
        asc[i]++;
        dec[i]--;
        if (asc[i] != g_size[i]) res.push_back(asc);
        if (dec[i] != -1) res.push_back(dec);
      }
      return res;
    }
    friend vector<A> near(const A &a) { return a.near(); }
  };

  static int N, add_node;
  static A g_size, coeff;
  static constexpr int ADD = numeric_limits<int>::max();

  static int id(const A &a) {
    if (a[0] == ADD) return N + a[1];
    int ret = 0;
    for (int i = 0; i < DIM; i++) {
      ret += a[i] * coeff[i];
    }
    return ret;
  }
  template <typename... T>
  static int id(const T &... t) {
    return id(A{t...});
  }

  static bool ok(const A &a) {
    if (a[0] == ADD) {
      return 0 <= a[1] && a[1] < add_node;
    }
    for (int i = 0; i < DIM; i++)
      if (a[i] < 0 or g_size[i] <= a[i]) return false;
    return true;
  }
  template <typename... T>
  static bool ok(const T &... t) {
    return ok(A{t...});
  }

  template <typename... Args>
  static A cast(Args... args) {
    return A(args...);
  }
  static A ad(int n) { return A{DG::ADD, n}; };

  vector<char> grid;

  explicit DimensionExpandedGraph() = default;
  template <typename... T>
  explicit DimensionExpandedGraph(const T &... t) {
    set(t...);
  }

  template <typename... T>
  void set(const T &... t) {
    N = 1;
    g_size = A{t...};
    coeff.fill(1);
    for (int i = 0; i < DIM; i++) {
      assert(g_size[i] != 0);
      for (int j = 0; j < i; j++) coeff[j] *= g_size[i];
      N *= g_size[i];
    }
  }

  void add(int n) { add_node = n; }

  void scan(istream &is = std::cin) {
    grid.reserve(N);
    int l = g_size[DIM - 1];
    for (int i = 0; i < N; i += l) {
      string s;
      is >> s;
      copy(begin(s), end(s), back_inserter(grid));
    }
  }

  friend istream &operator>>(istream &is, DG &g) {
    g.scan(is);
    return is;
  }

  vector<char> &get_grid() { return grid; }
  char &operator()(const A &a) { return grid[id(a)]; }
  template <typename... T>
  char &operator()(const T &... t) {
    return grid[id(t...)];
  }

  A find(const char &c) {
    A a{};
    fill(begin(a), end(a), 0);
    a[DIM - 1] = -1;
    while (true) {
      a[DIM - 1]++;
      for (int i = DIM - 1;; i--) {
        if (a[i] != g_size[i]) break;
        if (i == 0) return a;
        a[i] = 0;
        a[i - 1]++;
      }
      if ((*this)(a) == c) return a;
    }
  }

  template <typename F, typename Dist_t = Data_t>
  vector<Dist_t> bfs(F f, A s) {
    vector<Dist_t> dist(N + add_node, -1);
    if (!ok(s)) return dist;
    vector<A> Q;
    dist[id(s)] = 0;
    Q.push_back(s);
    while (!Q.empty()) {
      A c = Q.back();
      Q.pop_back();
      int dc = dist[id(c)];
      f(c, [&](A d) {
        if (!ok(d)) return;
        if (dist[id(d)] == -1) {
          dist[id(d)] = dc + 1;
          Q.push_back(d);
        }
      });
    }
    return dist;
  }

  template <typename F, typename Dist_t = Data_t>
  vector<Dist_t> bfs01(F f, A s) {
    vector<Dist_t> dist(N + add_node, -1);
    if (!ok(s)) return dist;
    deque<A> Q;
    dist[id(s)] = 0;
    Q.push_back(s);
    while (!Q.empty()) {
      A c = Q.front();
      Q.pop_front();
      int dc = dist[id(c)];
      f(c, [&](A d, Data_t w) {
        if (!ok(d)) return;
        if (dist[id(d)] == -1) {
          dist[id(d)] = dc + w;
          if (w == 0)
            Q.push_front(d);
          else
            Q.push_back(d);
        }
      });
    }
    return dist;
  }

  template <typename F, typename Dist_t = Data_t>
  static vector<Dist_t> dijkstra(F f, A s) {
    vector<Dist_t> dist(N, -1);
    using P = pair<Dist_t, A>;
    auto cmp = [](P &a, P &b) { return a.first > b.first; };
    priority_queue<P, vector<P>, decltype(cmp)> Q(cmp);
    assert(id(s) != -1);
    dist[id(s)] = 0;
    Q.emplace(0, s);
    while (!Q.empty()) {
      Dist_t dc;
      A c;
      tie(dc, c) = Q.top();
      Q.pop();
      if (dist[id(c)] < dc) continue;
      f(c, [&](A d, Dist_t w) {
        if (!ok(d)) return;
        if (dist[id(d)] == -1 || dist[id(d)] > dc + w) {
          dist[id(d)] = dc + w;
          Q.emplace(dc + w, d);
        }
      });
    }
    return dist;
  }

  vector<A> dat;

  template <typename F>
  void uf(F f) {
    A dflt;
    dflt[0] = -1;
    dat.resize(N + add_node, dflt);
    A a{};
    fill(begin(a), end(a), 0);
    a[DIM - 1] = -1;
    while (true) {
      a[DIM - 1]++;
      for (int i = DIM - 1;; i--) {
        if (a[i] != g_size[i]) break;
        if (i == 0) return;
        a[i] = 0;
        a[i - 1]++;
      }
      f(a, [&](A u, A v) { unite(u, v); });
    }
  }

  // Union Find
  A find(A u) { return dat[id(u)][0] < 0 ? u : dat[id(u)] = find(dat[id(u)]); }
  bool same(A u, A v) { return find(u) == find(v); }
  bool unite(A u, A v) {
    if ((u = find(u)) == (v = find(v))) return false;
    int iu = id(u), iv = id(v);
    if (dat[iu] > dat[iv]) swap(u, v), swap(iu, iv);
    dat[iu] += dat[iv];
    dat[iv] = u;
    return true;
  }
  Data_t size(A u) { return -dat[id(find(u))][0]; }
};

template <int DIM, typename Data_t>
int DimensionExpandedGraph<DIM, Data_t>::N = 0;
template <int DIM, typename Data_t>
int DimensionExpandedGraph<DIM, Data_t>::add_node = 0;
template <int DIM, typename Data_t>
typename DimensionExpandedGraph<DIM, Data_t>::A
    DimensionExpandedGraph<DIM, Data_t>::g_size;
template <int DIM, typename Data_t>
typename DimensionExpandedGraph<DIM, Data_t>::A
    DimensionExpandedGraph<DIM, Data_t>::coeff;

/**
 * @brief 次元拡張グラフ
 */
