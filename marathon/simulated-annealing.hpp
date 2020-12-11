#pragma once

#include "../misc/timer.hpp"
#include "log_table.hpp"

template <typename Input, typename State, typename Diff>
struct Simulated_Annealing {
 private:
  log_table rand_log;
  double end_time, inv_time, cur_time;
  double start_temp, diff_temp, cur_temp;
  Timer *timer;

  void set_time(double start_time) {
    inv_time = 1.0 / (end_time - start_time);
    cur_time = start_time;
  }
  void set_temp() {
    cur_temp = max(0.0, start_temp - cur_time * diff_temp * inv_time);
  }

 public:
  Simulated_Annealing(double _end_time, double _start_temp, double _end_temp,
                      Timer *_timer = nullptr)
      : end_time(_end_time),
        start_temp(_start_temp),
        diff_temp(_start_temp - _end_temp),
        timer(_timer) {
    if (timer == nullptr) timer = new Timer;
    set_time(timer->elapsed());
    set_temp();
  }

  void reset() { timer->reset(); }

  State run(const Input &input) {
    State st(input);
    for (int iter = 0;; iter++) {
      if ((iter & 0xFF) == 0) {
        st.dump();
        if ((cur_time = timer->elapsed()) > end_time) break;
        set_temp();
      }
      Diff d(st);
      if (d.diff() > cur_temp * rand_log.l[iter & 0xFFFF]) {
        st.update(d);
      } else {
        st.undo(d);
      }
    }
    return st;
  }

  decltype(State().score()) test(const vector<string> &filenames) {
    decltype(State().score()) scores = 0.0;
    for (auto &filename : filenames) {
      timer->reset();
      ifstream is(filename);
      cin.rdbuf(is.rdbuf());
      Input input;
      input.scan();
      auto res = run(input);
      scores += res.score();
    }
    return scores;
  }
};

/**
 * @brief Simulated Annealing
 * @docs docs/marathon/simulated-annealing.md
 */