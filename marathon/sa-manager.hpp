#pragma once 

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include "misc/rng.hpp"
#include "misc/timer.hpp"

template <typename state_t, typename score_t>
struct SA_manager {
 private:
  struct log_table {
    static constexpr int M = 65536;
    static constexpr int mask = M - 1;
    double l[M];
    log_table() : l() {
      unsigned long long x = 88172645463325252ULL;
      double log_u64max = log(2) * 64;
      for (int i = 0; i < M; i++) {
        x = x ^ (x << 7);
        x = x ^ (x >> 9);
        l[i] = log(double(x)) - log_u64max;
      }
    }
    double operator()(int i) const { return l[i & mask]; }
  };

  log_table rand_log;
  Timer timer;
  double start_time, end_time, inv_time, cur_time;
  double start_temp, diff_temp, cur_temp;
  int state_max, state_size;

  // 時間をセットする関数
  void set_time() { cur_time = timer.elapsed(); }

  // 時間を色々初期化する関数
  void init_time() {
    set_time();
    start_time = cur_time;
    inv_time = 1. / (end_time - start_time);
  }

  // 気温を設定して cur_temp に代入する関数
  void set_temp() {
    double passed_time = max(0., cur_time - start_time);
    cur_temp = max(0., start_temp - passed_time * inv_time * diff_temp);
  }

  // 焼きなましで持つ状態の個数の max を代入する関数
  void set_state_size() {
    double passed_time = max(0., cur_time - start_time);
    double n = 1.0 - passed_time * inv_time;
    state_size = llround(max(1., state_max * n));
  }

  // update すべきかどうかのしきい値を計算する
  double get_thresfold() { return cur_temp * rand_log(iter); }

 public:
  using pair_t = pair<state_t, score_t>;
  long long iter = 0;
  vector<pair_t> states;

#ifdef NyaanDebug
#define debug true
#else
#define debug false
#endif

  template <pair_t (*get_init_state)(),
            pair_t (*update_state)(const state_t&, const score_t&)>
  pair_t run() {
    auto comp_pair = [](const pair_t& lhs, const pair_t& rhs) {
      return lhs.second > rhs.second;
    };

    // states の初期化
    set_time();
    if constexpr (debug) cerr << "init start : " << int(cur_time) << endl;
    states.clear();
    for (int i = 0; i < state_max; i++) states.push_back(get_init_state());
    sort(begin(states), end(states), comp_pair);

    // 時間・温度の初期化
    init_time(), set_temp();
    if constexpr (debug) cerr << "SA start   : " << int(cur_time) << endl;
    if (end_time <= start_time) return states[0];

    // iteration を行う
    iter = 0;                  // update を行った回数
    state_size = state_max;    // 現在の states のサイズ
    long long loop_count = 0;  // 外側の loop をカウント
    bool end_flag = false;     // loop の終了条件
    for (; !end_flag; loop_count++) {
      // 暫定スコアを出力。重いので適宜コメントアウトしてよい
      /**/
      if constexpr (debug) {
        if ((loop_count & 0xFFFF) == 0) {
          if (loop_count == 0) {
            cerr << "iter     | ";
            cerr << "loops    | ";
            cerr << "cur_time | ";
            cerr << "cur_temp   | ";
            cerr << "size | ";
            cerr << "cur_score       | ";
            cerr << endl;
          }
          cerr << setprecision(3);
          cerr << setw(8) << iter << " | ";
          cerr << setw(8) << loop_count << " | ";
          cerr << setw(8) << int(cur_time) << " | ";
          cerr << setw(10) << cur_temp << " | ";
          cerr << setw(4) << states.size() << " | ";
          sort(begin(states), end(states), comp_pair);
          for (int i = 0; i < min<int>(states.size(), 3); i++) {
            cerr << " " << setw(14) << states[i].second << " | ";
          }
          cerr << endl;
        }
      }
      //*/
      for (auto& state : states) {
        if ((iter++ & 0xFF) == 0) {
          set_time(), set_temp();
          if (cur_time >= end_time) end_flag = true;
          if (end_flag) break;
        }
        pair_t nxt = update_state(state.first, state.second);
        score_t diff = nxt.second - state.second;
        if (diff > get_thresfold()) state = nxt;
      }
      set_state_size();
      while (state_size < (int)states.size()) {
        sort(begin(states), end(states), comp_pair);
        states.pop_back();
      }
    }
    sort(begin(states), end(states), comp_pair);
    if constexpr (debug) {
      cerr << "SA end     : " << int(cur_time) << endl;
      cerr << "iteration  : " << iter << endl;
      cerr << "loops      : " << loop_count << endl;
      cerr << "score      : " << states[0].second << endl;
      cerr << string(50, '*') << endl;
    }
    return states[0];
  }

  SA_manager(Timer& _timer, double _start_temp, double _end_temp,
             double _end_time, int _state_max = 1)
      : timer(_timer),
        start_time(0.),
        end_time(_end_time),
        inv_time(1. / _end_time),
        cur_time(0.),
        start_temp(_start_temp),
        diff_temp(_start_temp - _end_temp),
        cur_temp(_start_temp),
        state_max(_state_max),
        state_size(_state_max) {
    assert(_start_temp > _end_temp);
    assert(_state_max > 0);
  }
};

#undef debug

/**
 * @brief Multipoint Simulated Annealing
 * @docs docs/marathon/sa-manager.md
 */
