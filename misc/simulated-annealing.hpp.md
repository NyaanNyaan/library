---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: misc/timer.hpp
    title: misc/timer.hpp
  - icon: ':question:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"misc/simulated-annealing.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 3 \"misc/timer.hpp\"\nusing namespace std;\n\nstruct\
    \ Timer {\n  chrono::high_resolution_clock::time_point st;\n\n  Timer() { reset();\
    \ }\n\n  void reset() { st = chrono::high_resolution_clock::now(); }\n\n  chrono::milliseconds::rep\
    \ elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n    return\
    \ chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n};\n#line\
    \ 3 \"misc/rng.hpp\"\nusing namespace std;\n\nunsigned long long rng() {\n  static\
    \ unsigned long long x_ = 88172645463325252ULL;\n  x_ = x_ ^ (x_ << 7);\n  return\
    \ x_ = x_ ^ (x_ >> 9);\n}\n#line 7 \"misc/simulated-annealing.hpp\"\n\nnamespace\
    \ Simulated_Annealing {\n\n// exp\u9AD8\u901F\u5316\u7528\u306Elog\u30C6\u30FC\
    \u30D6\u30EB\n// exp(d/T) > rng()  <=>  d > T * log(rng)\u3092\u4F7F\u3044\u524D\
    \u8A08\u7B97\nstruct gen_log {\n  double l[65536];\n  constexpr gen_log() : l()\
    \ {\n    unsigned long long x = 88172645463325252ULL;\n    double log_u64max =\
    \ log(2) * 64;\n    for (int i = 0; i < 65536; i++) {\n      x = x ^ (x << 7);\n\
    \      x = x ^ (x >> 9);\n      l[i] = log(double(x)) - log_u64max;\n    }\n \
    \ }\n};\nconstexpr auto rnd_log = gen_log();\n\n// \u6642\u9593\ndouble start_time\
    \ = 0;\nconstexpr double end_time = 1980;\ndouble inv_time = 1.0 / (end_time -\
    \ start_time);\ndouble cur_time = 0;\n\n// \u6E29\u5EA6 \u958B\u59CB\u6E29\u5EA6\
    \u306F\u5B9F\u884C\u6642\u306B\u6E21\u3059\nconstexpr double end_temp = 1;\ndouble\
    \ cur_temp;\n\nvoid set_time(double start) {\n  start_time = start;\n  inv_time\
    \ = 1.0 / (end_time - start_time);\n  cur_time = start_time;\n}\n\nvoid set_temp(double\
    \ startTemp) {\n  cur_temp =\n      end_temp + (startTemp - end_temp) * (end_time\
    \ - cur_time) * inv_time;\n}\n\n// \u30B9\u30B3\u30A2\nusing score_t = long long;\n\
    score_t score = 0, diff = 0;\n\n// \u5165\u529B\u7528,\u7B54\u3048\u7528\u5909\
    \u6570\n\n// \u5165\u529B\nvoid input() {\n  // \u5165\u529B\n}\n\nvoid output()\
    \ {\n  // \u51FA\u529B\n}\n\nvoid init() {\n  score = diff = 0;\n  // \u521D\u671F\
    \u89E3\u3092\u69CB\u7BC9\u3057\u3066\u30B9\u30B3\u30A2\u3092\u8A08\u7B97\n}\n\n\
    // \u72B6\u614B\u5909\u6570(\u53E4\u3044\u72B6\u614B\u3068\u65B0\u3057\u3044\u72B6\
    \u614B\u3092\u30E1\u30E2\u3059\u308B\u7528)\nint mode = 0;  // \u9077\u79FB\u306E\
    \u30D1\u30BF\u30FC\u30F3\u7528\u306E\u5909\u6570\n\nvoid set_state(int iter) {\n\
    \  // \u9077\u79FB\u5148\u3092\u8A2D\u5B9A\n}\n\nvoid calc_diff() {\n  // \u5DEE\
    \u5206\u3092\u8A08\u7B97(\u9077\u79FB\u3092\u3059\u308B\u304B\u306F\u554F\u984C\
    \u306B\u3088\u3063\u3066\u6C7A\u3081\u308B)\n}\n\nvoid update() {\n  // \u9077\
    \u79FB\u3092\u63A1\u7528\u3057\u3066\u66F4\u65B0\n  score += diff;\n}\n\nvoid\
    \ undo() {\n  // \u5FA9\u5143\n}\n\n// \u5B9F\u884C\nvoid simulated_annealing(double\
    \ startTemp, Timer *timer = nullptr,\n                         bool is_tuning\
    \ = false) {\n  // \u30BF\u30A4\u30DE\u30FC\u306E\u8A2D\u5B9A\n  if (timer ==\
    \ nullptr) timer = new Timer();\n  //\u30C1\u30E5\u30FC\u30CB\u30F3\u30B0\u6642\
    \u306F\u30BF\u30A4\u30DE\u30FC\u3092\u30EA\u30BB\u30C3\u30C8\n  if (is_tuning)\
    \ timer->reset();\n\n  // \u30B9\u30B3\u30A2\u306E\u521D\u671F\u5316\n  score\
    \ = diff = 0;\n\n  // \u521D\u671F\u89E3\u306E\u69CB\u7BC9\n  init();\n\n  //\
    \ \u713C\u304D\u306A\u307E\u3057\u95A2\u9023\u306Econst\u3067\u306A\u3044\u5909\
    \u6570\u306E\u521D\u671F\u5316\n  set_time(timer->elapsed());\n  set_temp(startTemp);\n\
    \n  // \u30A4\u30C6\u30EC\u30FC\u30B7\u30E7\u30F3\u306E\u56DE\u6570\n  int iter\
    \ = 0;\n  while (true) {\n    // 256\u56DE\u306B1\u56DE\u3001\u6642\u9593\u3068\
    \u6E29\u5EA6\u3092\u66F4\u65B0\u3059\u308B\n    if ((++iter & 0xFF) == 0) {\n\
    \      if ((cur_time = timer->elapsed()) > end_time) break;\n      set_temp(startTemp);\n\
    \    }\n\n    // \u6B21\u306E\u9077\u79FB\u3092\u8A2D\u5B9A\n    set_state(iter);\n\
    \n    // \u5DEE\u5206\u3092\u8A08\u7B97\n    calc_diff();\n\n    // \u6761\u4EF6\
    \u3092\u6E80\u305F\u3057\u305F\u3068\u304D\u306B\u9077\u79FB\u3092\u63A1\u7528\
    \n    if (double(diff) > cur_temp * rnd_log.l[iter & 0xFFFF])\n      // \u30B9\
    \u30B3\u30A2\u3068\u72B6\u614B\u3092\u66F4\u65B0\n      update();\n    else\n\
    \      undo();\n\n// \u30C7\u30D0\u30C3\u30B0\u7528\u306B 65536 iteration\u6BCE\
    \u306B\u51FA\u529B\n#ifdef NyaanDebug\n    if (!is_tuning and (iter & 0x3FFFFF)\
    \ == 0) {\n      cerr << cur_time << \"\\t\" << iter << \"\\t\" << score << endl;\n\
    \    }\n#endif\n  }\n// \u7D50\u679C\u3092\u51FA\u529B\n#ifdef NyaanDebug\n  cerr\
    \ << iter << \"\\t\" << score << endl;\n#endif\n}\n\n// \u5B9F\u884C\u7528\nvoid\
    \ run(double temp) {\n  Timer timer;\n  input();\n  simulated_annealing(temp,\
    \ &timer);\n  output();\n  return;\n}\n\n// \u30C6\u30B9\u30C8\u7528\nvoid test(const\
    \ vector<string> &filenames, double temp, int loop = 1) {\n  double result = 0.0;\n\
    \  Timer timer;\n  for (int i = 0; i < loop; i++) {\n    for (auto &filename :\
    \ filenames) {\n      cerr << filename << \"\\t\" << temp << \"\\t\";\n      ifstream\
    \ is(filename);\n      cin.rdbuf(is.rdbuf());\n      input();\n      simulated_annealing(temp,\
    \ &timer, true);\n      result += score;\n    }\n  }\n  result /= 1.0 * loop *\
    \ filenames.size();\n  cerr << \"result : \" << result << endl;\n}\n\n}  // namespace\
    \ Simulated_Annealing\nnamespace SA = Simulated_Annealing;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"./timer.hpp\"\n#include \"./rng.hpp\"\n\nnamespace Simulated_Annealing {\n\
    \n// exp\u9AD8\u901F\u5316\u7528\u306Elog\u30C6\u30FC\u30D6\u30EB\n// exp(d/T)\
    \ > rng()  <=>  d > T * log(rng)\u3092\u4F7F\u3044\u524D\u8A08\u7B97\nstruct gen_log\
    \ {\n  double l[65536];\n  constexpr gen_log() : l() {\n    unsigned long long\
    \ x = 88172645463325252ULL;\n    double log_u64max = log(2) * 64;\n    for (int\
    \ i = 0; i < 65536; i++) {\n      x = x ^ (x << 7);\n      x = x ^ (x >> 9);\n\
    \      l[i] = log(double(x)) - log_u64max;\n    }\n  }\n};\nconstexpr auto rnd_log\
    \ = gen_log();\n\n// \u6642\u9593\ndouble start_time = 0;\nconstexpr double end_time\
    \ = 1980;\ndouble inv_time = 1.0 / (end_time - start_time);\ndouble cur_time =\
    \ 0;\n\n// \u6E29\u5EA6 \u958B\u59CB\u6E29\u5EA6\u306F\u5B9F\u884C\u6642\u306B\
    \u6E21\u3059\nconstexpr double end_temp = 1;\ndouble cur_temp;\n\nvoid set_time(double\
    \ start) {\n  start_time = start;\n  inv_time = 1.0 / (end_time - start_time);\n\
    \  cur_time = start_time;\n}\n\nvoid set_temp(double startTemp) {\n  cur_temp\
    \ =\n      end_temp + (startTemp - end_temp) * (end_time - cur_time) * inv_time;\n\
    }\n\n// \u30B9\u30B3\u30A2\nusing score_t = long long;\nscore_t score = 0, diff\
    \ = 0;\n\n// \u5165\u529B\u7528,\u7B54\u3048\u7528\u5909\u6570\n\n// \u5165\u529B\
    \nvoid input() {\n  // \u5165\u529B\n}\n\nvoid output() {\n  // \u51FA\u529B\n\
    }\n\nvoid init() {\n  score = diff = 0;\n  // \u521D\u671F\u89E3\u3092\u69CB\u7BC9\
    \u3057\u3066\u30B9\u30B3\u30A2\u3092\u8A08\u7B97\n}\n\n// \u72B6\u614B\u5909\u6570\
    (\u53E4\u3044\u72B6\u614B\u3068\u65B0\u3057\u3044\u72B6\u614B\u3092\u30E1\u30E2\
    \u3059\u308B\u7528)\nint mode = 0;  // \u9077\u79FB\u306E\u30D1\u30BF\u30FC\u30F3\
    \u7528\u306E\u5909\u6570\n\nvoid set_state(int iter) {\n  // \u9077\u79FB\u5148\
    \u3092\u8A2D\u5B9A\n}\n\nvoid calc_diff() {\n  // \u5DEE\u5206\u3092\u8A08\u7B97\
    (\u9077\u79FB\u3092\u3059\u308B\u304B\u306F\u554F\u984C\u306B\u3088\u3063\u3066\
    \u6C7A\u3081\u308B)\n}\n\nvoid update() {\n  // \u9077\u79FB\u3092\u63A1\u7528\
    \u3057\u3066\u66F4\u65B0\n  score += diff;\n}\n\nvoid undo() {\n  // \u5FA9\u5143\
    \n}\n\n// \u5B9F\u884C\nvoid simulated_annealing(double startTemp, Timer *timer\
    \ = nullptr,\n                         bool is_tuning = false) {\n  // \u30BF\u30A4\
    \u30DE\u30FC\u306E\u8A2D\u5B9A\n  if (timer == nullptr) timer = new Timer();\n\
    \  //\u30C1\u30E5\u30FC\u30CB\u30F3\u30B0\u6642\u306F\u30BF\u30A4\u30DE\u30FC\u3092\
    \u30EA\u30BB\u30C3\u30C8\n  if (is_tuning) timer->reset();\n\n  // \u30B9\u30B3\
    \u30A2\u306E\u521D\u671F\u5316\n  score = diff = 0;\n\n  // \u521D\u671F\u89E3\
    \u306E\u69CB\u7BC9\n  init();\n\n  // \u713C\u304D\u306A\u307E\u3057\u95A2\u9023\
    \u306Econst\u3067\u306A\u3044\u5909\u6570\u306E\u521D\u671F\u5316\n  set_time(timer->elapsed());\n\
    \  set_temp(startTemp);\n\n  // \u30A4\u30C6\u30EC\u30FC\u30B7\u30E7\u30F3\u306E\
    \u56DE\u6570\n  int iter = 0;\n  while (true) {\n    // 256\u56DE\u306B1\u56DE\
    \u3001\u6642\u9593\u3068\u6E29\u5EA6\u3092\u66F4\u65B0\u3059\u308B\n    if ((++iter\
    \ & 0xFF) == 0) {\n      if ((cur_time = timer->elapsed()) > end_time) break;\n\
    \      set_temp(startTemp);\n    }\n\n    // \u6B21\u306E\u9077\u79FB\u3092\u8A2D\
    \u5B9A\n    set_state(iter);\n\n    // \u5DEE\u5206\u3092\u8A08\u7B97\n    calc_diff();\n\
    \n    // \u6761\u4EF6\u3092\u6E80\u305F\u3057\u305F\u3068\u304D\u306B\u9077\u79FB\
    \u3092\u63A1\u7528\n    if (double(diff) > cur_temp * rnd_log.l[iter & 0xFFFF])\n\
    \      // \u30B9\u30B3\u30A2\u3068\u72B6\u614B\u3092\u66F4\u65B0\n      update();\n\
    \    else\n      undo();\n\n// \u30C7\u30D0\u30C3\u30B0\u7528\u306B 65536 iteration\u6BCE\
    \u306B\u51FA\u529B\n#ifdef NyaanDebug\n    if (!is_tuning and (iter & 0x3FFFFF)\
    \ == 0) {\n      cerr << cur_time << \"\\t\" << iter << \"\\t\" << score << endl;\n\
    \    }\n#endif\n  }\n// \u7D50\u679C\u3092\u51FA\u529B\n#ifdef NyaanDebug\n  cerr\
    \ << iter << \"\\t\" << score << endl;\n#endif\n}\n\n// \u5B9F\u884C\u7528\nvoid\
    \ run(double temp) {\n  Timer timer;\n  input();\n  simulated_annealing(temp,\
    \ &timer);\n  output();\n  return;\n}\n\n// \u30C6\u30B9\u30C8\u7528\nvoid test(const\
    \ vector<string> &filenames, double temp, int loop = 1) {\n  double result = 0.0;\n\
    \  Timer timer;\n  for (int i = 0; i < loop; i++) {\n    for (auto &filename :\
    \ filenames) {\n      cerr << filename << \"\\t\" << temp << \"\\t\";\n      ifstream\
    \ is(filename);\n      cin.rdbuf(is.rdbuf());\n      input();\n      simulated_annealing(temp,\
    \ &timer, true);\n      result += score;\n    }\n  }\n  result /= 1.0 * loop *\
    \ filenames.size();\n  cerr << \"result : \" << result << endl;\n}\n\n}  // namespace\
    \ Simulated_Annealing\nnamespace SA = Simulated_Annealing;"
  dependsOn:
  - misc/timer.hpp
  - misc/rng.hpp
  isVerificationFile: false
  path: misc/simulated-annealing.hpp
  requiredBy: []
  timestamp: '2020-07-28 11:29:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/simulated-annealing.hpp
layout: document
redirect_from:
- /library/misc/simulated-annealing.hpp
- /library/misc/simulated-annealing.hpp.html
title: misc/simulated-annealing.hpp
---
