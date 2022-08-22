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
    _deprecated_at_docs: docs/marathon/sa-manager.md
    document_title: Multipoint Simulated Annealing
    links: []
  bundledCode: "#line 2 \"marathon/sa-manager.hpp\"\n\n#include <cassert>\n#include\
    \ <iostream>\n#include <vector>\nusing namespace std;\n\n#line 2 \"misc/rng.hpp\"\
    \n\nnamespace my_rand {\nusing i64 = long long;\nusing u64 = unsigned long long;\n\
    \n// [0, 2^64 - 1)\nu64 rng() {\n  static u64 _x =\n      u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \              chrono::high_resolution_clock::now().time_since_epoch())\n    \
    \          .count()) *\n      10150724397891781847ULL;\n  _x ^= _x << 7;\n  return\
    \ _x ^= _x >> 9;\n}\n\n// [l, r]\ni64 rng(i64 l, i64 r) {\n  assert(l <= r);\n\
    \  return l + rng() % (r - l + 1);\n}\n\n// [l, r)\ni64 randint(i64 l, i64 r)\
    \ {\n  assert(l < r);\n  return l + rng() % (r - l);\n}\n\n// choose n numbers\
    \ from [l, r) without overlapping\nvector<i64> randset(i64 l, i64 r, i64 n) {\n\
    \  assert(l <= r && n <= r - l);\n  unordered_set<i64> s;\n  for (i64 i = n; i;\
    \ --i) {\n    i64 m = randint(l, r + 1 - i);\n    if (s.find(m) != s.end()) m\
    \ = r - i;\n    s.insert(m);\n  }\n  vector<i64> ret;\n  for (auto& x : s) ret.push_back(x);\n\
    \  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() { return rng() * 5.42101086242752217004e-20;\
    \ }\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n\
    \  for (int i = 1; i < n; i++) swap(v[i], v[randint(0, i + 1)]);\n}\n\n}  // namespace\
    \ my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\nusing my_rand::randshf;\n\
    using my_rand::rnd;\nusing my_rand::rng;\n#line 2 \"misc/timer.hpp\"\n\n#include\
    \ <chrono>\n\nstruct Timer {\n  chrono::high_resolution_clock::time_point st;\n\
    \n  Timer() { reset(); }\n\n  void reset() { st = chrono::high_resolution_clock::now();\
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
    \ - max(0.0, passed_time * inv_time * 1.05 - 0.05);\n    state_size = int(max(1.,\
    \ state_max * n) + 0.5);\n  }\n\n  // update \u3059\u3079\u304D\u304B\u3069\u3046\
    \u304B\u306E\u3057\u304D\u3044\u5024\u3092\u8A08\u7B97\u3059\u308B\n  double get_thresfold()\
    \ { return cur_temp * rand_log(iter); }\n\n public:\n  using pair_t = pair<state_t,\
    \ score_t>;\n  long long iter = 0, loop_count = 0;\n  vector<pair_t> states;\n\
    \n#ifdef NyaanLocal\n#define debug true\n#else\n#define debug false\n#endif\n\n\
    \  void dump() {\n    // \u91CD\u3044\u306E\u3067\u9069\u5B9C\u30B3\u30E1\u30F3\
    \u30C8\u30A2\u30A6\u30C8\u3059\u308B\n    /**/\n    if constexpr (debug) {\n \
    \     if ((loop_count & 0x3FFF) == 0) {\n        if (loop_count == 0) {\n    \
    \      cerr << \"     iter | \";\n          cerr << \"    loops | \";\n      \
    \    cerr << \"   time | \";\n          cerr << \"  cur temp | \";\n         \
    \ cerr << \"size | \";\n          cerr << \"      cur score | \";\n          cerr\
    \ << endl;\n        }\n        cerr << setprecision(3);\n        cerr << setw(9)\
    \ << iter << \" | \";\n        cerr << setw(9) << loop_count << \" | \";\n   \
    \     cerr << setw(7) << int(cur_time) << \" | \";\n        cerr << setw(10) <<\
    \ cur_temp << \" | \";\n        cerr << setw(4) << states.size() << \" | \";\n\
    \        auto comp_pair = [](const pair_t& lhs, const pair_t& rhs) {\n       \
    \   return lhs.second > rhs.second;\n        };\n        sort(begin(states), end(states),\
    \ comp_pair);\n        for (int i = 0; i < min<int>(states.size(), 5); i++) {\n\
    \          cerr << \" \" << setw(14) << states[i].second << \" | \";\n       \
    \ }\n        cerr << endl;\n      }\n    }\n    //*/\n  }\n\n  template <pair_t\
    \ (*get_init_state)(),\n            void (*update_state)(state_t&, score_t&, double)>\n\
    \  pair_t run() {\n    auto comp_pair = [](const pair_t& lhs, const pair_t& rhs)\
    \ {\n      return lhs.second > rhs.second;\n    };\n\n    // states \u306E\u521D\
    \u671F\u5316\n    set_time();\n    if constexpr (debug) cerr << \"init start :\
    \ \" << int(cur_time) << endl;\n    states.clear();\n    for (int i = 0; i < state_max;\
    \ i++) states.push_back(get_init_state());\n    sort(begin(states), end(states),\
    \ comp_pair);\n\n    // \u6642\u9593\u30FB\u6E29\u5EA6\u306E\u521D\u671F\u5316\
    \n    init_time(), set_temp();\n    if constexpr (debug) cerr << \"SA start  \
    \ : \" << int(cur_time) << endl;\n    if (end_time <= cur_time) return states[0];\n\
    \n    iter = loop_count = 0;\n    state_size = state_max;  // \u73FE\u5728\u306E\
    \ states \u306E\u30B5\u30A4\u30BA\n    constexpr int L = 256;\n\n    while (state_size\
    \ != 1) {\n      if ((loop_count & (L - 1)) == 0) {\n        set_time();\n   \
    \     if (cur_time >= end_time) break;\n        set_temp();\n      }\n      dump();\n\
    \      loop_count++;\n      for (auto& state : states) {\n        iter++;\n  \
    \      double thresfold = get_thresfold();\n        update_state(state.first,\
    \ state.second, thresfold);\n      }\n      set_state_size();\n      while (state_size\
    \ < (int)states.size()) {\n        sort(begin(states), end(states), comp_pair);\n\
    \        states.pop_back();\n      }\n    }\n    loop_count &= ~(L - 1);\n   \
    \ while (true) {\n      set_time();\n      if (cur_time >= end_time) break;\n\
    \      set_temp();\n      dump();\n      for (int t = 0; t < L; t++) {\n     \
    \   double thresfold = get_thresfold();\n        update_state(states[0].first,\
    \ states[0].second, thresfold);\n      }\n      loop_count += L, iter += L;\n\
    \    }\n    sort(begin(states), end(states), comp_pair);\n    if constexpr (debug)\
    \ {\n      cerr << \"SA end     : \" << int(cur_time) << endl;\n      cerr <<\
    \ \"iteration  : \" << iter << endl;\n      cerr << \"loops      : \" << loop_count\
    \ << endl;\n      cerr << \"score      : \" << states[0].second << endl;\n   \
    \   cerr << string(50, '*') << endl;\n    }\n    return states[0];\n  }\n\n  SA_manager(Timer&\
    \ _timer, double _start_temp, double _end_temp,\n             double _end_time,\
    \ int _state_max = 1)\n      : timer(_timer),\n        start_time(0.),\n     \
    \   end_time(_end_time),\n        inv_time(1. / _end_time),\n        cur_time(0.),\n\
    \        start_temp(_start_temp),\n        diff_temp(_start_temp - _end_temp),\n\
    \        cur_temp(_start_temp),\n        state_max(_state_max),\n        state_size(_state_max)\
    \ {\n    assert(_start_temp >= _end_temp);\n    assert(_state_max > 0);\n  }\n\
    };\n\n#undef debug\n\n/**\n * @brief Multipoint Simulated Annealing\n * @docs\
    \ docs/marathon/sa-manager.md\n */\n"
  code: "#pragma once\n\n#include <cassert>\n#include <iostream>\n#include <vector>\n\
    using namespace std;\n\n#include \"../misc/rng.hpp\"\n#include \"../misc/timer.hpp\"\
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
    \    double n = 1.0 - max(0.0, passed_time * inv_time * 1.05 - 0.05);\n    state_size\
    \ = int(max(1., state_max * n) + 0.5);\n  }\n\n  // update \u3059\u3079\u304D\u304B\
    \u3069\u3046\u304B\u306E\u3057\u304D\u3044\u5024\u3092\u8A08\u7B97\u3059\u308B\
    \n  double get_thresfold() { return cur_temp * rand_log(iter); }\n\n public:\n\
    \  using pair_t = pair<state_t, score_t>;\n  long long iter = 0, loop_count =\
    \ 0;\n  vector<pair_t> states;\n\n#ifdef NyaanLocal\n#define debug true\n#else\n\
    #define debug false\n#endif\n\n  void dump() {\n    // \u91CD\u3044\u306E\u3067\
    \u9069\u5B9C\u30B3\u30E1\u30F3\u30C8\u30A2\u30A6\u30C8\u3059\u308B\n    /**/\n\
    \    if constexpr (debug) {\n      if ((loop_count & 0x3FFF) == 0) {\n       \
    \ if (loop_count == 0) {\n          cerr << \"     iter | \";\n          cerr\
    \ << \"    loops | \";\n          cerr << \"   time | \";\n          cerr << \"\
    \  cur temp | \";\n          cerr << \"size | \";\n          cerr << \"      cur\
    \ score | \";\n          cerr << endl;\n        }\n        cerr << setprecision(3);\n\
    \        cerr << setw(9) << iter << \" | \";\n        cerr << setw(9) << loop_count\
    \ << \" | \";\n        cerr << setw(7) << int(cur_time) << \" | \";\n        cerr\
    \ << setw(10) << cur_temp << \" | \";\n        cerr << setw(4) << states.size()\
    \ << \" | \";\n        auto comp_pair = [](const pair_t& lhs, const pair_t& rhs)\
    \ {\n          return lhs.second > rhs.second;\n        };\n        sort(begin(states),\
    \ end(states), comp_pair);\n        for (int i = 0; i < min<int>(states.size(),\
    \ 5); i++) {\n          cerr << \" \" << setw(14) << states[i].second << \" |\
    \ \";\n        }\n        cerr << endl;\n      }\n    }\n    //*/\n  }\n\n  template\
    \ <pair_t (*get_init_state)(),\n            void (*update_state)(state_t&, score_t&,\
    \ double)>\n  pair_t run() {\n    auto comp_pair = [](const pair_t& lhs, const\
    \ pair_t& rhs) {\n      return lhs.second > rhs.second;\n    };\n\n    // states\
    \ \u306E\u521D\u671F\u5316\n    set_time();\n    if constexpr (debug) cerr <<\
    \ \"init start : \" << int(cur_time) << endl;\n    states.clear();\n    for (int\
    \ i = 0; i < state_max; i++) states.push_back(get_init_state());\n    sort(begin(states),\
    \ end(states), comp_pair);\n\n    // \u6642\u9593\u30FB\u6E29\u5EA6\u306E\u521D\
    \u671F\u5316\n    init_time(), set_temp();\n    if constexpr (debug) cerr << \"\
    SA start   : \" << int(cur_time) << endl;\n    if (end_time <= cur_time) return\
    \ states[0];\n\n    iter = loop_count = 0;\n    state_size = state_max;  // \u73FE\
    \u5728\u306E states \u306E\u30B5\u30A4\u30BA\n    constexpr int L = 256;\n\n \
    \   while (state_size != 1) {\n      if ((loop_count & (L - 1)) == 0) {\n    \
    \    set_time();\n        if (cur_time >= end_time) break;\n        set_temp();\n\
    \      }\n      dump();\n      loop_count++;\n      for (auto& state : states)\
    \ {\n        iter++;\n        double thresfold = get_thresfold();\n        update_state(state.first,\
    \ state.second, thresfold);\n      }\n      set_state_size();\n      while (state_size\
    \ < (int)states.size()) {\n        sort(begin(states), end(states), comp_pair);\n\
    \        states.pop_back();\n      }\n    }\n    loop_count &= ~(L - 1);\n   \
    \ while (true) {\n      set_time();\n      if (cur_time >= end_time) break;\n\
    \      set_temp();\n      dump();\n      for (int t = 0; t < L; t++) {\n     \
    \   double thresfold = get_thresfold();\n        update_state(states[0].first,\
    \ states[0].second, thresfold);\n      }\n      loop_count += L, iter += L;\n\
    \    }\n    sort(begin(states), end(states), comp_pair);\n    if constexpr (debug)\
    \ {\n      cerr << \"SA end     : \" << int(cur_time) << endl;\n      cerr <<\
    \ \"iteration  : \" << iter << endl;\n      cerr << \"loops      : \" << loop_count\
    \ << endl;\n      cerr << \"score      : \" << states[0].second << endl;\n   \
    \   cerr << string(50, '*') << endl;\n    }\n    return states[0];\n  }\n\n  SA_manager(Timer&\
    \ _timer, double _start_temp, double _end_temp,\n             double _end_time,\
    \ int _state_max = 1)\n      : timer(_timer),\n        start_time(0.),\n     \
    \   end_time(_end_time),\n        inv_time(1. / _end_time),\n        cur_time(0.),\n\
    \        start_temp(_start_temp),\n        diff_temp(_start_temp - _end_temp),\n\
    \        cur_temp(_start_temp),\n        state_max(_state_max),\n        state_size(_state_max)\
    \ {\n    assert(_start_temp >= _end_temp);\n    assert(_state_max > 0);\n  }\n\
    };\n\n#undef debug\n\n/**\n * @brief Multipoint Simulated Annealing\n * @docs\
    \ docs/marathon/sa-manager.md\n */\n"
  dependsOn:
  - misc/rng.hpp
  - misc/timer.hpp
  isVerificationFile: false
  path: marathon/sa-manager.hpp
  requiredBy: []
  timestamp: '2022-08-22 19:46:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: marathon/sa-manager.hpp
layout: document
redirect_from:
- /library/marathon/sa-manager.hpp
- /library/marathon/sa-manager.hpp.html
title: Multipoint Simulated Annealing
---
## 焼きなまし法

焼きなまし法のライブラリを自分が使いやすいように改良したもの。

#### テンプレート

```cpp
// 状態を持つ型
using state_t = vector<int>;
// スコアを持つ型
using score_t = double;
using pair_t = pair<state_t, score_t>;

// 焼きなましの初期解を入れる関数
pair_t get_init_state() {
  state_t ans;
  score_t score;
  // ans, score に初期解を入れる。
  // 多点焼きなましを行う場合は初期解に多様性が生まれるようにする。

  return {ans, score};
}

//　状態を更新する関数
void update_state(state_t& ans, score_t& score, double th) {
  // 遷移を作る
  // 基本的には以下のように値を複製して遷移先を作っていい
  // (差分更新したい場合は適宜頑張る)
  state_t nxt{ans};
  score_t nxt_score{score};

  // スコアの伸びを変数 diff に格納して値を元に遷移を採用するか決める。
  double diff = -1;
  if (diff > th) {
    // 遷移を採用して ans, score を更新 or 差分更新する。

  } else {
    // (必要があれば)元に戻す。
  }
}

pair_t sa(Timer& t) {
  SA_manager<state_t, score_t> sa(t, 1000, 10, 1900, 1);
  return sa.run<get_init_state,update_state>();
}
```

#### 注意点

- 入力はグローバル領域に置いてよしなにする
- `state_t` が高次元のときは適宜 `std::array` を使うのが楽だと思う
- `score_t` は値が大きければ大きいほど憂愁になるようにする
- 焼きなましのループ回数 / 実行回数によってはエラー出力が重いのでコメントアウトする
- `end_temp` は **負数を指定できる**。 温度は `0.0` との `max` を取るので負である間は山登り法と等価の挙動をする。
  - 温度は線形に変化するので、 `start_temp`, `0.0` 間との外分比を考えれば山登り法の動作時間を制御できる。
  - `get_init_state` や `update_state` はメンバ変数として実装する方が楽かもしれない。
  
#### お気持ち

- (普段の短期マラソンで焼いたコード) - (問題特有のコード) になるようにできるだけ頑張ろうとした
- 入力はグローバルに配列で置きたい(余計な思考がいらなくなるので)
- 書く必要がある関数は必要最小限にしたい(上に同じ)
- 思いつく定数倍高速化は要れた
  - スコアは毎回わざわざ計算する必要はないが「スコアを陽に持たないことで高速化」はどうせ短期でそこまで実装しきれないので大丈夫だと思う