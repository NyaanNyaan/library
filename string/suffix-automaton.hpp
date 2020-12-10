#pragma once

template <int margin = 'a'>
struct SuffixAutomaton {
  struct state {
    vector<pair<char, int>> next;
    uint64_t hit;
    int len, link, origin;
    char key;
    bool sorted;

    state() : hit(0), len(0), link(-1), origin(-1), key(0), sorted(false) {}
    state(int l, char k)
        : hit(0), len(l), link(-1), origin(-1), key(k), sorted(false) {}

    __attribute__((target("popcnt"))) int find(char c) const {
      c -= margin;
      if (((hit >> c) & 1) == 0) return -1;
      if (sorted) {
        return _mm_popcnt_u64(hit & ((1ull << c) - 1));
      } else {
        c += margin;
        for (int i = 0; i < (int)next.size(); i++) {
          if (next[i].first == c) return i;
        }
        assert(0);
      }
    }

    inline int to(char c) const { 
      int f = find(c);
      return ~f ? next[find(c)].second : -1; 
    }

    void add(char c, int i) {
      c -= margin;
      assert(((hit >> c) & 1) == 0);
      next.emplace_back(c + margin, i);
      hit |= 1ull << c;
    }
  };
  vector<state> st;
  vector<int> topo;

  SuffixAutomaton() = default;

  SuffixAutomaton(const string &S) {
    build(S);
    st.push_back(state());
  }

  void build(const string &S) {
    int last = 0;
    for (int i = 0; i < (int)S.size(); i++) extend(S[i], last);
    tsort();
  }

  [[deprecated]] void build(const vector<string> &S) {
    for (auto &s : S) {
      int i = 0, last = 0;
      while (i < (int)s.size()) {
        int f = st[last].find(s[i]);
        if (f == -1) break;
        last = st[last].next[f].second;
        i++;
      }
      for (; i < (int)s.size(); i++) extend(s[i], last);
    }
  }

  int size() const { return st.size(); }

  int find(const string &s) const {
    int last = 0;
    for (auto &c : s) {
      int nx = st[last].find(c);
      if (nx == -1) return -1;
      last = st[last].next[nx].second;
    }
    return last;
  }

  state &operator[](int i) { return st[i]; }

 private:
  void extend(char c, int &last) {
    int cur = st.size();
    st.emplace_back(st[last].len + 1, c);
    int p = last;
    for (; p != -1 && st[p].find(c) == -1; p = st[p].link) {
      st[p].add(c, cur);
    }
    if (p == -1) {
      st[cur].link = 0;
    } else {
      int q = st[p].to(c);
      if (st[p].len + 1 == st[q].len)
        st[cur].link = q;
      else {
        int clone = st.size();
        {
          state cl = st[q];
          cl.len = st[p].len + 1;
          cl.origin = q;
          st.push_back(std::move(cl));
        }
        for (; p != -1; p = st[p].link) {
          int i = st[p].find(c);
          assert(i != -1);
          if (st[p].next[i].second != q) break;
          st[p].next[i].second = clone;
        }
        st[q].link = st[cur].link = clone;
      }
    }
    last = cur;
  }

  vector<bool> marked, temp;
  vector<vector<int>> buf;

  void dfs(int i) {
    temp[i] = 1;
    for (auto &[_, j] : st[i].next)
      if (!marked[j]) dfs(j);
    for (auto &j : buf[i])
      if (!marked[j]) dfs(j);
    marked[i] = 1;
    topo.push_back(i);
    temp[i] = 0;
  }

  void tsort() {
    int n = st.size();
    marked.resize(n), temp.resize(n), buf.resize(n);
    for (int i = 1; i < n; i++) buf[st[i].link].push_back(i);
    for (int i = 0; i < n; i++)
      if (!marked[i]) dfs(i);
    reverse(begin(topo), end(topo));
    buf.clear();
    buf.shrink_to_fit();
    marked.clear();
    marked.shrink_to_fit();
    temp.clear();
    temp.shrink_to_fit();

    vector<int> inv(n);
    for (int i = 0; i < n; i++) inv[topo[i]] = i;
    {
      vector<state> st2;
      for (int i = 0; i < n; i++) st2.emplace_back(std::move(st[topo[i]]));
      st.swap(st2);
    }
    for (int i = 0; i < n; i++) {
      state &s = st[i];
      sort(begin(s.next), end(s.next));
      s.sorted = true;
      for (auto &[_, y] : s.next) y = inv[y];
      if (s.link != -1) s.link = inv[s.link];
      if (s.origin != -1) s.origin = inv[s.origin];
    }
    topo.clear();
    topo.shrink_to_fit();
  }
};

/**
 * @brief Suffix Automaton
 * @docs docs/string/suffix-automaton.md
 */
