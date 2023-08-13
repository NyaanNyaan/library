#pragma once

#include <unordered_set>
#include <vector>
using namespace std;

// https://github.com/not522/CompetitiveProgramming/blob/master/old2/include/math/sat.hpp
class SatSolver {
 private:
  int n, qi;
  vector<vector<pair<int, bool>>> cl;
  vector<vector<int>> w[2];
  vector<int> reason, level, que, activity;

  void enqueue(int v, bool a, int r = -1) {
    assigns[v] = a;
    reason[v] = r;
    level[v] = (que.empty() ? 1 : level[que.back()]);
    que.emplace_back(v);
  }

  void add(const vector<pair<int, bool>> &clause) {
    for (auto l : clause) w[l.second][l.first].emplace_back(cl.size());
    cl.emplace_back(clause);
  }

  void analyze(int confl) {
    int i = que.size(), lv = 1;
    unordered_set<int> used;
    vector<pair<int, bool>> learnt;
    for (int cnt = 0; cnt || used.empty(); --cnt) {
      for (auto q : cl[confl]) {
        if (!used.emplace(q.first).second) continue;
        activity[q.first] += 1e5;
        if (level[q.first] == level[que.back()]) {
          ++cnt;
        } else {
          learnt.emplace_back(q);
          lv = max(lv, level[q.first]);
        }
      }
      while (!used.count(que[--i]))
        ;
      confl = reason[que[i]];
    }
    learnt.emplace_back(que[i], !assigns[que[i]]);
    for (; !que.empty() && level[que.back()] > lv; que.pop_back()) {
      level[que.back()] = 0;
    }
    qi = que.size();
    enqueue(learnt.back().first, learnt.back().second, cl.size());
    add(learnt);
  }

  int propagate() {
    for (; qi < int(que.size()); ++qi) {
      for (int cr : w[!assigns[que[qi]]][que[qi]]) {
        int cnt = 0;
        for (auto &lit : cl[cr]) {
          if (level[lit.first] == 0) {
            activity[lit.first] += 1e3;
            swap(lit, cl[cr][0]);
            ++cnt;
          } else if (assigns[lit.first] == lit.second) {
            swap(lit, cl[cr][0]);
            cnt = -1;
            break;
          }
        }
        if (cnt == 0) return cr;
        if (cnt == 1) enqueue(cl[cr][0].first, cl[cr][0].second, cr);
      }
    }
    return -1;
  }

 public:
  vector<bool> assigns;

  SatSolver(int _n)
      : n(_n), qi(0), reason(n), level(n), activity(n), assigns(n) {
    w[0].resize(n), w[1].resize(n);
  }

  void add_clause(const vector<pair<int, bool>> &clause) { add(clause); }

  void if_then(int v1, bool a1, int v2, bool a2) {
    add(vector{make_pair(v1, !a1), make_pair(v2, a2)});
  }
  void set_val(int v, bool a) { add(vector{make_pair(v, a)}); }

  bool solve() {
    while (true) {
      int confl = propagate();
      if (confl != -1) {
        if (level[que.back()] == 1u) return false;
        for (auto &a : activity) a /= 1.05;
        analyze(confl);
      } else {
        int k = -1;
        for (int i = 0; i < n; ++i) {
          if (level[i] == 0 && (k == -1 || activity[k] < activity[i])) k = i;
        }
        if (k == -1) return true;
        enqueue(k, assigns[k]);
        ++level[k];
      }
    }
  }
};
