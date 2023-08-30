---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1777.test.cpp
    title: verify/verify-yuki/yuki-1777.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/not522/CompetitiveProgramming/blob/master/old2/include/math/sat.hpp
  bundledCode: "#line 2 \"math/sat-solver.hpp\"\n\n#include <unordered_set>\n#include\
    \ <vector>\nusing namespace std;\n\n// https://github.com/not522/CompetitiveProgramming/blob/master/old2/include/math/sat.hpp\n\
    class SatSolver {\n private:\n  int n, qi;\n  vector<vector<pair<int, bool>>>\
    \ cl;\n  vector<vector<int>> w[2];\n  vector<int> reason, level, que, activity;\n\
    \n  void enqueue(int v, bool a, int r = -1) {\n    assigns[v] = a;\n    reason[v]\
    \ = r;\n    level[v] = (que.empty() ? 1 : level[que.back()]);\n    que.emplace_back(v);\n\
    \  }\n\n  void add(const vector<pair<int, bool>> &clause) {\n    for (auto l :\
    \ clause) w[l.second][l.first].emplace_back(cl.size());\n    cl.emplace_back(clause);\n\
    \  }\n\n  void analyze(int confl) {\n    int i = que.size(), lv = 1;\n    unordered_set<int>\
    \ used;\n    vector<pair<int, bool>> learnt;\n    for (int cnt = 0; cnt || used.empty();\
    \ --cnt) {\n      for (auto q : cl[confl]) {\n        if (!used.emplace(q.first).second)\
    \ continue;\n        activity[q.first] += 1e5;\n        if (level[q.first] ==\
    \ level[que.back()]) {\n          ++cnt;\n        } else {\n          learnt.emplace_back(q);\n\
    \          lv = max(lv, level[q.first]);\n        }\n      }\n      while (!used.count(que[--i]))\n\
    \        ;\n      confl = reason[que[i]];\n    }\n    learnt.emplace_back(que[i],\
    \ !assigns[que[i]]);\n    for (; !que.empty() && level[que.back()] > lv; que.pop_back())\
    \ {\n      level[que.back()] = 0;\n    }\n    qi = que.size();\n    enqueue(learnt.back().first,\
    \ learnt.back().second, cl.size());\n    add(learnt);\n  }\n\n  int propagate()\
    \ {\n    for (; qi < int(que.size()); ++qi) {\n      for (int cr : w[!assigns[que[qi]]][que[qi]])\
    \ {\n        int cnt = 0;\n        for (auto &lit : cl[cr]) {\n          if (level[lit.first]\
    \ == 0) {\n            activity[lit.first] += 1e3;\n            swap(lit, cl[cr][0]);\n\
    \            ++cnt;\n          } else if (assigns[lit.first] == lit.second) {\n\
    \            swap(lit, cl[cr][0]);\n            cnt = -1;\n            break;\n\
    \          }\n        }\n        if (cnt == 0) return cr;\n        if (cnt ==\
    \ 1) enqueue(cl[cr][0].first, cl[cr][0].second, cr);\n      }\n    }\n    return\
    \ -1;\n  }\n\n public:\n  vector<bool> assigns;\n\n  SatSolver(int _n)\n     \
    \ : n(_n), qi(0), reason(n), level(n), activity(n), assigns(n) {\n    w[0].resize(n),\
    \ w[1].resize(n);\n  }\n\n  void add_clause(const vector<pair<int, bool>> &clause)\
    \ { add(clause); }\n\n  void if_then(int v1, bool a1, int v2, bool a2) {\n   \
    \ add(vector{make_pair(v1, !a1), make_pair(v2, a2)});\n  }\n  void set_val(int\
    \ v, bool a) { add(vector{make_pair(v, a)}); }\n\n  bool solve() {\n    while\
    \ (true) {\n      int confl = propagate();\n      if (confl != -1) {\n       \
    \ if (level[que.back()] == 1u) return false;\n        for (auto &a : activity)\
    \ a /= 1.05;\n        analyze(confl);\n      } else {\n        int k = -1;\n \
    \       for (int i = 0; i < n; ++i) {\n          if (level[i] == 0 && (k == -1\
    \ || activity[k] < activity[i])) k = i;\n        }\n        if (k == -1) return\
    \ true;\n        enqueue(k, assigns[k]);\n        ++level[k];\n      }\n    }\n\
    \  }\n};\n"
  code: "#pragma once\n\n#include <unordered_set>\n#include <vector>\nusing namespace\
    \ std;\n\n// https://github.com/not522/CompetitiveProgramming/blob/master/old2/include/math/sat.hpp\n\
    class SatSolver {\n private:\n  int n, qi;\n  vector<vector<pair<int, bool>>>\
    \ cl;\n  vector<vector<int>> w[2];\n  vector<int> reason, level, que, activity;\n\
    \n  void enqueue(int v, bool a, int r = -1) {\n    assigns[v] = a;\n    reason[v]\
    \ = r;\n    level[v] = (que.empty() ? 1 : level[que.back()]);\n    que.emplace_back(v);\n\
    \  }\n\n  void add(const vector<pair<int, bool>> &clause) {\n    for (auto l :\
    \ clause) w[l.second][l.first].emplace_back(cl.size());\n    cl.emplace_back(clause);\n\
    \  }\n\n  void analyze(int confl) {\n    int i = que.size(), lv = 1;\n    unordered_set<int>\
    \ used;\n    vector<pair<int, bool>> learnt;\n    for (int cnt = 0; cnt || used.empty();\
    \ --cnt) {\n      for (auto q : cl[confl]) {\n        if (!used.emplace(q.first).second)\
    \ continue;\n        activity[q.first] += 1e5;\n        if (level[q.first] ==\
    \ level[que.back()]) {\n          ++cnt;\n        } else {\n          learnt.emplace_back(q);\n\
    \          lv = max(lv, level[q.first]);\n        }\n      }\n      while (!used.count(que[--i]))\n\
    \        ;\n      confl = reason[que[i]];\n    }\n    learnt.emplace_back(que[i],\
    \ !assigns[que[i]]);\n    for (; !que.empty() && level[que.back()] > lv; que.pop_back())\
    \ {\n      level[que.back()] = 0;\n    }\n    qi = que.size();\n    enqueue(learnt.back().first,\
    \ learnt.back().second, cl.size());\n    add(learnt);\n  }\n\n  int propagate()\
    \ {\n    for (; qi < int(que.size()); ++qi) {\n      for (int cr : w[!assigns[que[qi]]][que[qi]])\
    \ {\n        int cnt = 0;\n        for (auto &lit : cl[cr]) {\n          if (level[lit.first]\
    \ == 0) {\n            activity[lit.first] += 1e3;\n            swap(lit, cl[cr][0]);\n\
    \            ++cnt;\n          } else if (assigns[lit.first] == lit.second) {\n\
    \            swap(lit, cl[cr][0]);\n            cnt = -1;\n            break;\n\
    \          }\n        }\n        if (cnt == 0) return cr;\n        if (cnt ==\
    \ 1) enqueue(cl[cr][0].first, cl[cr][0].second, cr);\n      }\n    }\n    return\
    \ -1;\n  }\n\n public:\n  vector<bool> assigns;\n\n  SatSolver(int _n)\n     \
    \ : n(_n), qi(0), reason(n), level(n), activity(n), assigns(n) {\n    w[0].resize(n),\
    \ w[1].resize(n);\n  }\n\n  void add_clause(const vector<pair<int, bool>> &clause)\
    \ { add(clause); }\n\n  void if_then(int v1, bool a1, int v2, bool a2) {\n   \
    \ add(vector{make_pair(v1, !a1), make_pair(v2, a2)});\n  }\n  void set_val(int\
    \ v, bool a) { add(vector{make_pair(v, a)}); }\n\n  bool solve() {\n    while\
    \ (true) {\n      int confl = propagate();\n      if (confl != -1) {\n       \
    \ if (level[que.back()] == 1u) return false;\n        for (auto &a : activity)\
    \ a /= 1.05;\n        analyze(confl);\n      } else {\n        int k = -1;\n \
    \       for (int i = 0; i < n; ++i) {\n          if (level[i] == 0 && (k == -1\
    \ || activity[k] < activity[i])) k = i;\n        }\n        if (k == -1) return\
    \ true;\n        enqueue(k, assigns[k]);\n        ++level[k];\n      }\n    }\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/sat-solver.hpp
  requiredBy: []
  timestamp: '2023-08-13 20:36:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1777.test.cpp
documentation_of: math/sat-solver.hpp
layout: document
redirect_from:
- /library/math/sat-solver.hpp
- /library/math/sat-solver.hpp.html
title: math/sat-solver.hpp
---
