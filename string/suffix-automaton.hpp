#pragma once

template <int margin = 'a'>
struct SuffixAutomaton {
  struct state {
    vector<pair<char, int>> nxt;
    uint64_t hit;
    int len, link, origin;
    char key;

    state() : hit(0), len(0), link(-1), origin(-1), key(0) {}
    state(int l, char k) : hit(0), len(l), link(-1), origin(-1), key(k) {}

    __attribute__((target("popcnt"))) int get_idx(char c) const {
      c -= margin;
      if (((hit >> c) & 1) == 0) return -1;
      if (sorted) {
        return _mm_popcnt_u64(hit & ((1ull << c) - 1));
      } else {
        c += margin;
        for (int i = 0; i < (int)nxt.size(); i++) {
          if (nxt[i].first == c) return i;
        }
      }
      exit(1);
    }

    inline int next(char c) const {
      int f = get_idx(c);
      return ~f ? nxt[f].second : -1;
    }

    void add(char c, int i) {
      c -= margin;
      assert(((hit >> c) & 1) == 0);
      nxt.emplace_back(c + margin, i);
      hit |= 1ull << c;
    }
  };

  inline int next(int i, char c) { return st[i].next(c); }
  inline vector<pair<char, int>> &chd(int i) { return st[i].nxt; }
  inline int link(int i) { return st[i].link; }

  vector<state> st;
  static bool sorted;

  SuffixAutomaton() : st(1) {}
  SuffixAutomaton(const string &S) : st(1) { build(S); }

  void build(const string &S) {
    int last = 0;
    for (int i = 0; i < (int)S.size(); i++) extend(S[i], last);
    tsort();
  }

  int size() const { return st.size(); }

  int find(const string &s) const {
    int last = 0;
    for (auto &c : s)
      if ((last = next(last, c)) == -1) return -1;
    return last;
  }

  state &operator[](int i) { return st[i]; }

 private:
  void extend(char c, int &last) {
    int cur = st.size();
    st.emplace_back(st[last].len + 1, c);
    int p = last;
    for (; p != -1 && st[p].get_idx(c) == -1; p = st[p].link) {
      st[p].add(c, cur);
    }
    if (p == -1) {
      st[cur].link = 0;
    } else {
      int q = st[p].next(c);
      if (st[p].len + 1 == st[q].len)
        st[cur].link = q;
      else {
        int clone = st.size();
        {
          state cl = st[q];
          cl.len = st[p].len + 1, cl.origin = q;
          st.push_back(std::move(cl));
        }
        for (; p != -1; p = st[p].link) {
          int i = st[p].get_idx(c);
          if (st[p].nxt[i].second != q) break;
          st[p].nxt[i].second = clone;
        }
        st[q].link = st[cur].link = clone;
      }
    }
    last = cur;
  }

  void tsort() {
    int n = st.size();
    vector<int> topo;
    {
      topo.reserve(n);
      vector<vector<int>> base(n + 1);
      for (int i = 0; i < n; i++) base[st[i].len].push_back(i);
      for (int i = 0; i < n; i++)
        if (!base[i].empty())
          copy(begin(base[i]), end(base[i]), back_inserter(topo));
    }
    {
      vector<state> st2;
      st2.reserve(n);
      for (int i = 0; i < n; i++) st2.emplace_back(std::move(st[topo[i]]));
      st.swap(st2);
    }
    vector<int> inv(n);
    for (int i = 0; i < n; i++) inv[topo[i]] = i;
    for (int i = 0; i < n; i++) {
      state &s = st[i];
      sort(begin(s.nxt), end(s.nxt));
      for (auto &[_, y] : s.nxt) y = inv[y];
      if (s.link != -1) s.link = inv[s.link];
      if (s.origin != -1) s.origin = inv[s.origin];
    }
    sorted = true;
  }
};

template <int margin>
bool SuffixAutomaton<margin>::sorted = false;

/**
 * @brief Suffix Automaton
 * @docs docs/string/suffix-automaton.md
 */
