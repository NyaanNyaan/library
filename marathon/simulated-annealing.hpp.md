---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: marathon/log_table.hpp
    title: marathon/log_table.hpp
  - icon: ':heavy_check_mark:'
    path: misc/timer.hpp
    title: misc/timer.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/simulated-annealing.test.cpp
    title: verify/verify-unit-test/simulated-annealing.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/marathon/simulated-annealing.md
    document_title: Simulated Annealing
    links: []
  bundledCode: "#line 2 \"marathon/simulated-annealing.hpp\"\n\n#line 2 \"misc/timer.hpp\"\
    \n\nstruct Timer {\n  chrono::high_resolution_clock::time_point st;\n\n  Timer()\
    \ { reset(); }\n\n  void reset() { st = chrono::high_resolution_clock::now();\
    \ }\n\n  chrono::milliseconds::rep elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n\
    \    return chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n\
    };\n#line 2 \"marathon/log_table.hpp\"\n\nstruct log_table {\n  double l[65536];\n\
    \  constexpr log_table() : l() {\n    unsigned long long x = 88172645463325252ULL;\n\
    \    double log_u64max = log(2) * 64;\n    for (int i = 0; i < 65536; i++) {\n\
    \      x = x ^ (x << 7);\n      x = x ^ (x >> 9);\n      l[i] = log(double(x))\
    \ - log_u64max;\n    }\n  }\n};\n#line 5 \"marathon/simulated-annealing.hpp\"\n\
    \ntemplate <typename Input, typename State, typename Diff>\nstruct Simulated_Annealing\
    \ {\n private:\n  log_table rand_log;\n  double end_time, inv_time, cur_time;\n\
    \  double start_temp, diff_temp, cur_temp;\n  Timer *timer;\n\n  void set_time(double\
    \ start_time) {\n    inv_time = 1.0 / (end_time - start_time);\n    cur_time =\
    \ start_time;\n  }\n  void set_temp() {\n    cur_temp = max(0.0, start_temp -\
    \ cur_time * diff_temp * inv_time);\n  }\n\n public:\n  Simulated_Annealing(double\
    \ _end_time, double _start_temp, double _end_temp,\n                      Timer\
    \ *_timer = nullptr)\n      : end_time(_end_time),\n        start_temp(_start_temp),\n\
    \        diff_temp(_start_temp - _end_temp),\n        timer(_timer) {\n    if\
    \ (timer == nullptr) timer = new Timer;\n    set_time(timer->elapsed());\n   \
    \ set_temp();\n  }\n\n  void reset() { timer->reset(); }\n\n  State run(const\
    \ Input &input) {\n    State st(input);\n    for (int iter = 0;; iter++) {\n \
    \     if ((iter & 0xFF) == 0) {\n        st.dump();\n        if ((cur_time = timer->elapsed())\
    \ > end_time) break;\n        set_temp();\n      }\n      Diff d(st);\n      if\
    \ (d.diff() > cur_temp * rand_log.l[iter & 0xFFFF]) {\n        st.update(d);\n\
    \      } else {\n        st.undo(d);\n      }\n    }\n    return st;\n  }\n\n\
    \  decltype(State().score()) test(const vector<string> &filenames) {\n    decltype(State().score())\
    \ scores = 0.0;\n    for (auto &filename : filenames) {\n      timer->reset();\n\
    \      ifstream is(filename);\n      cin.rdbuf(is.rdbuf());\n      Input input;\n\
    \      input.scan();\n      auto res = run(input);\n      scores += res.score();\n\
    \    }\n    return scores;\n  }\n};\n\n/**\n * @brief Simulated Annealing\n *\
    \ @docs docs/marathon/simulated-annealing.md\n */\n"
  code: "#pragma once\n\n#include \"../misc/timer.hpp\"\n#include \"log_table.hpp\"\
    \n\ntemplate <typename Input, typename State, typename Diff>\nstruct Simulated_Annealing\
    \ {\n private:\n  log_table rand_log;\n  double end_time, inv_time, cur_time;\n\
    \  double start_temp, diff_temp, cur_temp;\n  Timer *timer;\n\n  void set_time(double\
    \ start_time) {\n    inv_time = 1.0 / (end_time - start_time);\n    cur_time =\
    \ start_time;\n  }\n  void set_temp() {\n    cur_temp = max(0.0, start_temp -\
    \ cur_time * diff_temp * inv_time);\n  }\n\n public:\n  Simulated_Annealing(double\
    \ _end_time, double _start_temp, double _end_temp,\n                      Timer\
    \ *_timer = nullptr)\n      : end_time(_end_time),\n        start_temp(_start_temp),\n\
    \        diff_temp(_start_temp - _end_temp),\n        timer(_timer) {\n    if\
    \ (timer == nullptr) timer = new Timer;\n    set_time(timer->elapsed());\n   \
    \ set_temp();\n  }\n\n  void reset() { timer->reset(); }\n\n  State run(const\
    \ Input &input) {\n    State st(input);\n    for (int iter = 0;; iter++) {\n \
    \     if ((iter & 0xFF) == 0) {\n        st.dump();\n        if ((cur_time = timer->elapsed())\
    \ > end_time) break;\n        set_temp();\n      }\n      Diff d(st);\n      if\
    \ (d.diff() > cur_temp * rand_log.l[iter & 0xFFFF]) {\n        st.update(d);\n\
    \      } else {\n        st.undo(d);\n      }\n    }\n    return st;\n  }\n\n\
    \  decltype(State().score()) test(const vector<string> &filenames) {\n    decltype(State().score())\
    \ scores = 0.0;\n    for (auto &filename : filenames) {\n      timer->reset();\n\
    \      ifstream is(filename);\n      cin.rdbuf(is.rdbuf());\n      Input input;\n\
    \      input.scan();\n      auto res = run(input);\n      scores += res.score();\n\
    \    }\n    return scores;\n  }\n};\n\n/**\n * @brief Simulated Annealing\n *\
    \ @docs docs/marathon/simulated-annealing.md\n */"
  dependsOn:
  - misc/timer.hpp
  - marathon/log_table.hpp
  isVerificationFile: false
  path: marathon/simulated-annealing.hpp
  requiredBy: []
  timestamp: '2020-12-11 17:45:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/simulated-annealing.test.cpp
documentation_of: marathon/simulated-annealing.hpp
layout: document
redirect_from:
- /library/marathon/simulated-annealing.hpp
- /library/marathon/simulated-annealing.hpp.html
title: Simulated Annealing
---
#### テンプレート

```
using score_t = double;
struct Input {
  Input() = default;
  void scan() {}
};
struct State {
  struct Diff {
    const State *st;
    Diff() = default;
    Diff(const State &state) : st(&state) {}
    double diff() const {}
  };

  State() = default;
  State(const Input &input) {}
  void update(const Diff &b) {}
  void undo(const Diff &) {}
  score_t score() const {}
  bool operator>(const State &s) { return score() > s.score(); };
  void dump() {}
};
using SA = Simulated_Annealing<Input, State, typename State::Diff>;
```
