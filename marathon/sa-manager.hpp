#pragma once

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include "../misc/rng.hpp"
#include "../misc/timer.hpp"
#include "log_table.hpp"

template <typename state_t, typename score_t>
struct SA_manager {
 private:
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
    double n = 1.0 - max(0.0, passed_time * inv_time * 1.05 - 0.05);
    state_size = int(max(1., state_max * n) + 0.5);
  }

  // update すべきかどうかのしきい値を計算する
  double get_thresfold() { return cur_temp * rand_log(iter); }

 public:
  using pair_t = pair<state_t, score_t>;
  long long iter = 0, loop_count = 0;
  vector<pair_t> states;

#ifdef NyaanLocal
#define debug true
#else
#define debug false
#endif

  void dump() {
    // 重いので適宜コメントアウトする
    /**/
    if constexpr (debug) {
      if ((loop_count & 0x3FFF) == 0) {
        if (loop_count == 0) {
          cerr << "     iter | ";
          cerr << "    loops | ";
          cerr << "   time | ";
          cerr << "  cur temp | ";
          cerr << "size | ";
          cerr << "      cur score | ";
          cerr << endl;
        }
        cerr << setprecision(3);
        cerr << setw(9) << iter << " | ";
        cerr << setw(9) << loop_count << " | ";
        cerr << setw(7) << int(cur_time) << " | ";
        cerr << setw(10) << cur_temp << " | ";
        cerr << setw(4) << states.size() << " | ";
        auto comp_pair = [](const pair_t& lhs, const pair_t& rhs) {
          return lhs.second > rhs.second;
        };
        sort(begin(states), end(states), comp_pair);
        for (int i = 0; i < min<int>(states.size(), 5); i++) {
          cerr << " " << setw(14) << states[i].second << " | ";
        }
        cerr << endl;
      }
    }
    //*/
  }

  template <pair_t (*get_init_state)(),
            void (*update_state)(state_t&, score_t&, double)>
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
    if (end_time <= cur_time) return states[0];

    iter = loop_count = 0;
    state_size = state_max;  // 現在の states のサイズ
    constexpr int L = 256;

    while (state_size != 1) {
      if ((loop_count & (L - 1)) == 0) {
        set_time();
        if (cur_time >= end_time) break;
        set_temp();
      }
      dump();
      loop_count++;
      for (auto& state : states) {
        iter++;
        double thresfold = get_thresfold();
        update_state(state.first, state.second, thresfold);
      }
      set_state_size();
      while (state_size < (int)states.size()) {
        sort(begin(states), end(states), comp_pair);
        states.pop_back();
      }
    }
    loop_count &= ~(L - 1);
    while (true) {
      set_time();
      if (cur_time >= end_time) break;
      set_temp();
      dump();
      for (int t = 0; t < L; t++) {
        double thresfold = get_thresfold();
        update_state(states[0].first, states[0].second, thresfold);
      }
      loop_count += L, iter += L;
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
    assert(_start_temp >= _end_temp);
    assert(_state_max > 0);
  }
};

#undef debug

/**
 * @brief Multipoint Simulated Annealing
 * @docs docs/marathon/sa-manager.md
 */
