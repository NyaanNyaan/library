#pragma once

#include <functional>
#include <map>
#include <type_traits>
#include <utility>
#include <vector>
using namespace std;

/**
 * ゲームの遷移が DAG で表せる不偏ゲームの solver
 *
 * Board：盤面の型
 * Move は着手の型 or void
 * Game は
 *
 * - splittable = true の場合は vector<Board> (ゲームの分割に対応)
 * - splittable = falseの場合は Board
 *
 * State は次
 *
 * - Move が void である場合, Game
 * - Move が void でない場合, pair<Game, Move>
 *
 * States は vector<State>
 *
 * F は Board を引数, States を返り値に取る関数。つまり
 *
 * - デフォルトの場合   : function<vector<Board>(Board)>
 * - splittable の場合 : function<vector<vector<Board>(Board)>
 * - Move != void の場合は返り値の value_type が pair(*, move) になる
 *
 * 雑にゲームの勝敗を知りたいときはデフォルトでよい
 * 最善手の情報が欲しいときは Move の引数を変えて頑張る
 */

template <typename Board, typename Move = void, bool splittable = false>
struct ImpartialGameSolver {
  using Boards = vector<Board>;
  using Game = conditional_t<splittable, vector<Board>, Board>;
  using State = conditional_t<is_void_v<Move>, Game, pair<Game, Move>>;
  using States = vector<State>;
  using Nimber = long long;
  using F = function<States(Board)>;

  map<Board, Nimber> mp;
  F f;

  ImpartialGameSolver() = default;
  ImpartialGameSolver(const F& _f) : f(_f) {}
  void set_func(const F& _f) { f = _f; }

  template <typename T>
  Nimber get(const T& t) {
    if constexpr (is_same_v<T, Board>) {
      if (mp.count(t)) return mp[t];
      return mp[t] = _get(t);
    } else if constexpr (is_same_v<T, Boards>) {
      Nimber n = 0;
      for (const Board& s : t) n ^= get(s);
      return n;
    } else {
      static_assert(is_same_v<T, pair<Game, Move>>);
      return get(t.first);
    }
  }

  // 負け局面で呼ぶと RE する
  template <typename T>
  conditional_t<is_same_v<T, Board>, Move, pair<int, Move>> get_best_move(
      const T& t) {
    static_assert(is_void_v<Move> == false);
    Nimber n = get(t);
    assert(n != 0 and "No Best Move.");
    if constexpr (is_same_v<T, Board>) {
      auto res = change_x(t, n);
      if (res.first) return res.second;
    } else {
      static_assert(is_same_v<T, Boards>);
      for (int i = 0; i < (int)t.size(); i++) {
        auto res = change_x(t[i], n);
        if (res.first) return {i, res.second};
      }
    }
    assert(false and "Error in get_best_move().");
    exit(1);
  }

 private:
  Nimber _get(const Board& b) {
    States gs = f(b);
    if (gs.empty()) return {};
    vector<Nimber> ns;
    for (State& st : gs) ns.push_back(get(st));
    sort(begin(ns), end(ns));
    ns.erase(unique(begin(ns), end(ns)), end(ns));
    for (int i = 0; i < (int)ns.size(); i++) {
      if (ns[i] != i) return i;
    }
    return ns.size();
  }

  // nimber が x 変わるような着手を返す
  pair<bool, Move> change_x(const Board& b, Nimber x) {
    assert(is_void_v<Move> == false);
    Nimber n = get(b);
    for (auto& st : f(b)) {
      if (get(st) == (x ^ n)) return {true, st.second};
    }
    return {false, Move{}};
  }
};

/**
 * @brief 不偏ゲーム
 */
