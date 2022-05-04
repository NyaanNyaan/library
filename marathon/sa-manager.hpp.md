---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: misc/timer.hpp
    title: misc/timer.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"marathon/sa-manager.hpp\"\n\n#include <cassert>\n#include\
    \ <iostream>\n#include <vector>\nusing namespace std;\n\n#line 2 \"misc/rng.hpp\"\
    \n\nnamespace my_rand {\n\n// [0, 2^64 - 1)\nuint64_t rng() {\n  static uint64_t\
    \ x_ =\n      uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n         \
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \           .count()) *\n      10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return\
    \ x_ ^= x_ >> 9;\n}\n\n// [l, r)\nint64_t randint(int64_t l, int64_t r) {\n  assert(l\
    \ < r);\n  return l + rng() % (r - l);\n}\n\n// choose n numbers from [l, r) without\
    \ overlapping\nvector<int64_t> randset(int64_t l, int64_t r, int64_t n) {\n  assert(l\
    \ <= r && n <= r - l);\n  unordered_set<int64_t> s;\n  for (int64_t i = n; i;\
    \ --i) {\n    int64_t m = randint(l, r + 1 - i);\n    if (s.find(m) != s.end())\
    \ m = r - i;\n    s.insert(m);\n  }\n  vector<int64_t> ret;\n  for (auto& x :\
    \ s) ret.push_back(x);\n  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() {\n  union\
    \ raw_cast {\n    double t;\n    uint64_t u;\n  };\n  constexpr uint64_t p = uint64_t(1023\
    \ - 64) << 52;\n  return rng() * ((raw_cast*)(&p))->t;\n}\n\ntemplate <typename\
    \ T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n  for (int loop = 0;\
    \ loop < 2; loop++)\n    for (int i = 0; i < n; i++) swap(v[i], v[randint(0, n)]);\n\
    }\n\n}  // namespace my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\n\
    using my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n#line 2 \"\
    misc/timer.hpp\"\n\n#include <chrono>\n\nstruct Timer {\n  chrono::high_resolution_clock::time_point\
    \ st;\n\n  Timer() { reset(); }\n\n  void reset() { st = chrono::high_resolution_clock::now();\
    \ }\n\n  chrono::milliseconds::rep elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n\
    \    return chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n\
    };\n#line 10 \"marathon/sa-manager.hpp\"\n\ntemplate <typename state_t, typename\
    \ score_t>\nstruct SA_manager {\n private:\n  struct log_table {\n    static constexpr\
    \ int M = 65536;\n    static constexpr int mask = M - 1;\n    double l[M];\n \
    \   log_table() : l() {\n      unsigned long long x = 88172645463325252ULL;\n\
    \      double log_u64max = log(2) * 64;\n      for (int i = 0; i < M; i++) {\n\
    \        x = x ^ (x << 7);\n        x = x ^ (x >> 9);\n        l[i] = log(double(x))\
    \ - log_u64max;\n      }\n    }\n    double operator()(int i) const { return l[i\
    \ & mask]; }\n  };\n\n  log_table rand_log;\n  Timer timer;\n  double start_time,\
    \ end_time, inv_time, cur_time;\n  double start_temp, diff_temp, cur_temp;\n \
    \ int state_max, state_size;\n\n  // \u6642\u9593\u3092\u30BB\u30C3\u30C8\u3059\
    \u308B\u95A2\u6570\n  void set_time() { cur_time = timer.elapsed(); }\n\n  //\
    \ \u6642\u9593\u3092\u8272\u3005\u521D\u671F\u5316\u3059\u308B\u95A2\u6570\n \
    \ void init_time() {\n    set_time();\n    start_time = cur_time;\n    inv_time\
    \ = 1. / (end_time - start_time);\n  }\n\n  // \u6C17\u6E29\u3092\u8A2D\u5B9A\u3057\
    \u3066 cur_temp \u306B\u4EE3\u5165\u3059\u308B\u95A2\u6570\n  void set_temp()\
    \ {\n    double passed_time = max(0., cur_time - start_time);\n    cur_temp =\
    \ max(0., start_temp - passed_time * inv_time * diff_temp);\n  }\n\n  // \u713C\
    \u304D\u306A\u307E\u3057\u3067\u6301\u3064\u72B6\u614B\u306E\u500B\u6570\u306E\
    \ max \u3092\u4EE3\u5165\u3059\u308B\u95A2\u6570\n  void set_state_size() {\n\
    \    double passed_time = max(0., cur_time - start_time);\n    double n = 1.0\
    \ - passed_time * inv_time;\n    state_size = llround(max(1., state_max * n));\n\
    \  }\n\n  // update \u3059\u3079\u304D\u304B\u3069\u3046\u304B\u306E\u3057\u304D\
    \u3044\u5024\u3092\u8A08\u7B97\u3059\u308B\n  double get_thresfold() { return\
    \ cur_temp * rand_log(iter); }\n\n public:\n  using pair_t = pair<state_t, score_t>;\n\
    \  long long iter = 0;\n  vector<pair_t> states;\n\n#ifdef NyaanDebug\n#define\
    \ debug true\n#else\n#define debug false\n#endif\n\n  template <pair_t (*get_init_state)(),\n\
    \            pair_t (*update_state)(const state_t&, const score_t&)>\n  pair_t\
    \ run() {\n    auto comp_pair = [](const pair_t& lhs, const pair_t& rhs) {\n \
    \     return lhs.second > rhs.second;\n    };\n\n    // states \u306E\u521D\u671F\
    \u5316\n    set_time();\n    if constexpr (debug) cerr << \"init start : \" <<\
    \ int(cur_time) << endl;\n    states.clear();\n    for (int i = 0; i < state_max;\
    \ i++) states.push_back(get_init_state());\n    sort(begin(states), end(states),\
    \ comp_pair);\n\n    // \u6642\u9593\u30FB\u6E29\u5EA6\u306E\u521D\u671F\u5316\
    \n    init_time(), set_temp();\n    if constexpr (debug) cerr << \"SA start  \
    \ : \" << int(cur_time) << endl;\n    if (end_time <= start_time) return states[0];\n\
    \n    // iteration \u3092\u884C\u3046\n    iter = 0;                  // update\
    \ \u3092\u884C\u3063\u305F\u56DE\u6570\n    state_size = state_max;    // \u73FE\
    \u5728\u306E states \u306E\u30B5\u30A4\u30BA\n    long long loop_count = 0;  //\
    \ \u5916\u5074\u306E loop \u3092\u30AB\u30A6\u30F3\u30C8\n    bool end_flag =\
    \ false;     // loop \u306E\u7D42\u4E86\u6761\u4EF6\n    for (; !end_flag; loop_count++)\
    \ {\n      // \u66AB\u5B9A\u30B9\u30B3\u30A2\u3092\u51FA\u529B\u3002\u91CD\u3044\
    \u306E\u3067\u9069\u5B9C\u30B3\u30E1\u30F3\u30C8\u30A2\u30A6\u30C8\u3057\u3066\
    \u3088\u3044\n      /**/\n      if constexpr (debug) {\n        if ((loop_count\
    \ & 0xFFFF) == 0) {\n          if (loop_count == 0) {\n            cerr << \"\
    iter     | \";\n            cerr << \"loops    | \";\n            cerr << \"cur_time\
    \ | \";\n            cerr << \"cur_temp   | \";\n            cerr << \"size |\
    \ \";\n            cerr << \"cur_score       | \";\n            cerr << endl;\n\
    \          }\n          cerr << setprecision(3);\n          cerr << setw(8) <<\
    \ iter << \" | \";\n          cerr << setw(8) << loop_count << \" | \";\n    \
    \      cerr << setw(8) << int(cur_time) << \" | \";\n          cerr << setw(10)\
    \ << cur_temp << \" | \";\n          cerr << setw(4) << states.size() << \" |\
    \ \";\n          sort(begin(states), end(states), comp_pair);\n          for (int\
    \ i = 0; i < min<int>(states.size(), 3); i++) {\n            cerr << \" \" <<\
    \ setw(14) << states[i].second << \" | \";\n          }\n          cerr << endl;\n\
    \        }\n      }\n      //*/\n      for (auto& state : states) {\n        if\
    \ ((iter++ & 0xFF) == 0) {\n          set_time(), set_temp();\n          if (cur_time\
    \ >= end_time) end_flag = true;\n          if (end_flag) break;\n        }\n \
    \       pair_t nxt = update_state(state.first, state.second);\n        score_t\
    \ diff = nxt.second - state.second;\n        if (diff > get_thresfold()) state\
    \ = nxt;\n      }\n      set_state_size();\n      while (state_size < (int)states.size())\
    \ {\n        sort(begin(states), end(states), comp_pair);\n        states.pop_back();\n\
    \      }\n    }\n    sort(begin(states), end(states), comp_pair);\n    if constexpr\
    \ (debug) {\n      cerr << \"SA end     : \" << int(cur_time) << endl;\n     \
    \ cerr << \"iteration  : \" << iter << endl;\n      cerr << \"loops      : \"\
    \ << loop_count << endl;\n      cerr << \"score      : \" << states[0].second\
    \ << endl;\n      cerr << string(50, '*') << endl;\n    }\n    return states[0];\n\
    \  }\n\n  SA_manager(Timer& _timer, double _start_temp, double _end_temp,\n  \
    \           double _end_time, int _state_max = 1)\n      : timer(_timer),\n  \
    \      start_time(0.),\n        end_time(_end_time),\n        inv_time(1. / _end_time),\n\
    \        cur_time(0.),\n        start_temp(_start_temp),\n        diff_temp(_start_temp\
    \ - _end_temp),\n        cur_temp(_start_temp),\n        state_max(_state_max),\n\
    \        state_size(_state_max) {\n    assert(_start_temp > _end_temp);\n    assert(_state_max\
    \ > 0);\n  }\n};\n\n#undef debug\n"
  code: "#pragma once \n\n#include <cassert>\n#include <iostream>\n#include <vector>\n\
    using namespace std;\n\n#include \"misc/rng.hpp\"\n#include \"misc/timer.hpp\"\
    \n\ntemplate <typename state_t, typename score_t>\nstruct SA_manager {\n private:\n\
    \  struct log_table {\n    static constexpr int M = 65536;\n    static constexpr\
    \ int mask = M - 1;\n    double l[M];\n    log_table() : l() {\n      unsigned\
    \ long long x = 88172645463325252ULL;\n      double log_u64max = log(2) * 64;\n\
    \      for (int i = 0; i < M; i++) {\n        x = x ^ (x << 7);\n        x = x\
    \ ^ (x >> 9);\n        l[i] = log(double(x)) - log_u64max;\n      }\n    }\n \
    \   double operator()(int i) const { return l[i & mask]; }\n  };\n\n  log_table\
    \ rand_log;\n  Timer timer;\n  double start_time, end_time, inv_time, cur_time;\n\
    \  double start_temp, diff_temp, cur_temp;\n  int state_max, state_size;\n\n \
    \ // \u6642\u9593\u3092\u30BB\u30C3\u30C8\u3059\u308B\u95A2\u6570\n  void set_time()\
    \ { cur_time = timer.elapsed(); }\n\n  // \u6642\u9593\u3092\u8272\u3005\u521D\
    \u671F\u5316\u3059\u308B\u95A2\u6570\n  void init_time() {\n    set_time();\n\
    \    start_time = cur_time;\n    inv_time = 1. / (end_time - start_time);\n  }\n\
    \n  // \u6C17\u6E29\u3092\u8A2D\u5B9A\u3057\u3066 cur_temp \u306B\u4EE3\u5165\u3059\
    \u308B\u95A2\u6570\n  void set_temp() {\n    double passed_time = max(0., cur_time\
    \ - start_time);\n    cur_temp = max(0., start_temp - passed_time * inv_time *\
    \ diff_temp);\n  }\n\n  // \u713C\u304D\u306A\u307E\u3057\u3067\u6301\u3064\u72B6\
    \u614B\u306E\u500B\u6570\u306E max \u3092\u4EE3\u5165\u3059\u308B\u95A2\u6570\n\
    \  void set_state_size() {\n    double passed_time = max(0., cur_time - start_time);\n\
    \    double n = 1.0 - passed_time * inv_time;\n    state_size = llround(max(1.,\
    \ state_max * n));\n  }\n\n  // update \u3059\u3079\u304D\u304B\u3069\u3046\u304B\
    \u306E\u3057\u304D\u3044\u5024\u3092\u8A08\u7B97\u3059\u308B\n  double get_thresfold()\
    \ { return cur_temp * rand_log(iter); }\n\n public:\n  using pair_t = pair<state_t,\
    \ score_t>;\n  long long iter = 0;\n  vector<pair_t> states;\n\n#ifdef NyaanDebug\n\
    #define debug true\n#else\n#define debug false\n#endif\n\n  template <pair_t (*get_init_state)(),\n\
    \            pair_t (*update_state)(const state_t&, const score_t&)>\n  pair_t\
    \ run() {\n    auto comp_pair = [](const pair_t& lhs, const pair_t& rhs) {\n \
    \     return lhs.second > rhs.second;\n    };\n\n    // states \u306E\u521D\u671F\
    \u5316\n    set_time();\n    if constexpr (debug) cerr << \"init start : \" <<\
    \ int(cur_time) << endl;\n    states.clear();\n    for (int i = 0; i < state_max;\
    \ i++) states.push_back(get_init_state());\n    sort(begin(states), end(states),\
    \ comp_pair);\n\n    // \u6642\u9593\u30FB\u6E29\u5EA6\u306E\u521D\u671F\u5316\
    \n    init_time(), set_temp();\n    if constexpr (debug) cerr << \"SA start  \
    \ : \" << int(cur_time) << endl;\n    if (end_time <= start_time) return states[0];\n\
    \n    // iteration \u3092\u884C\u3046\n    iter = 0;                  // update\
    \ \u3092\u884C\u3063\u305F\u56DE\u6570\n    state_size = state_max;    // \u73FE\
    \u5728\u306E states \u306E\u30B5\u30A4\u30BA\n    long long loop_count = 0;  //\
    \ \u5916\u5074\u306E loop \u3092\u30AB\u30A6\u30F3\u30C8\n    bool end_flag =\
    \ false;     // loop \u306E\u7D42\u4E86\u6761\u4EF6\n    for (; !end_flag; loop_count++)\
    \ {\n      // \u66AB\u5B9A\u30B9\u30B3\u30A2\u3092\u51FA\u529B\u3002\u91CD\u3044\
    \u306E\u3067\u9069\u5B9C\u30B3\u30E1\u30F3\u30C8\u30A2\u30A6\u30C8\u3057\u3066\
    \u3088\u3044\n      /**/\n      if constexpr (debug) {\n        if ((loop_count\
    \ & 0xFFFF) == 0) {\n          if (loop_count == 0) {\n            cerr << \"\
    iter     | \";\n            cerr << \"loops    | \";\n            cerr << \"cur_time\
    \ | \";\n            cerr << \"cur_temp   | \";\n            cerr << \"size |\
    \ \";\n            cerr << \"cur_score       | \";\n            cerr << endl;\n\
    \          }\n          cerr << setprecision(3);\n          cerr << setw(8) <<\
    \ iter << \" | \";\n          cerr << setw(8) << loop_count << \" | \";\n    \
    \      cerr << setw(8) << int(cur_time) << \" | \";\n          cerr << setw(10)\
    \ << cur_temp << \" | \";\n          cerr << setw(4) << states.size() << \" |\
    \ \";\n          sort(begin(states), end(states), comp_pair);\n          for (int\
    \ i = 0; i < min<int>(states.size(), 3); i++) {\n            cerr << \" \" <<\
    \ setw(14) << states[i].second << \" | \";\n          }\n          cerr << endl;\n\
    \        }\n      }\n      //*/\n      for (auto& state : states) {\n        if\
    \ ((iter++ & 0xFF) == 0) {\n          set_time(), set_temp();\n          if (cur_time\
    \ >= end_time) end_flag = true;\n          if (end_flag) break;\n        }\n \
    \       pair_t nxt = update_state(state.first, state.second);\n        score_t\
    \ diff = nxt.second - state.second;\n        if (diff > get_thresfold()) state\
    \ = nxt;\n      }\n      set_state_size();\n      while (state_size < (int)states.size())\
    \ {\n        sort(begin(states), end(states), comp_pair);\n        states.pop_back();\n\
    \      }\n    }\n    sort(begin(states), end(states), comp_pair);\n    if constexpr\
    \ (debug) {\n      cerr << \"SA end     : \" << int(cur_time) << endl;\n     \
    \ cerr << \"iteration  : \" << iter << endl;\n      cerr << \"loops      : \"\
    \ << loop_count << endl;\n      cerr << \"score      : \" << states[0].second\
    \ << endl;\n      cerr << string(50, '*') << endl;\n    }\n    return states[0];\n\
    \  }\n\n  SA_manager(Timer& _timer, double _start_temp, double _end_temp,\n  \
    \           double _end_time, int _state_max = 1)\n      : timer(_timer),\n  \
    \      start_time(0.),\n        end_time(_end_time),\n        inv_time(1. / _end_time),\n\
    \        cur_time(0.),\n        start_temp(_start_temp),\n        diff_temp(_start_temp\
    \ - _end_temp),\n        cur_temp(_start_temp),\n        state_max(_state_max),\n\
    \        state_size(_state_max) {\n    assert(_start_temp > _end_temp);\n    assert(_state_max\
    \ > 0);\n  }\n};\n\n#undef debug"
  dependsOn:
  - misc/rng.hpp
  - misc/timer.hpp
  isVerificationFile: false
  path: marathon/sa-manager.hpp
  requiredBy: []
  timestamp: '2022-05-05 00:11:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: marathon/sa-manager.hpp
layout: document
redirect_from:
- /library/marathon/sa-manager.hpp
- /library/marathon/sa-manager.hpp.html
title: marathon/sa-manager.hpp
---
