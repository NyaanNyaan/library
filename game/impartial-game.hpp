#pragma once

#include <functional>
#include <map>
#include <type_traits>
#include <utility>
#include <vector>
using namespace std;

/**
 * Board は盤面の型, Move は着手の型 (void OK)
 *
 * Game は vector<Board> (ゲームが分割される場合に対応)
 * State は次のような型
 * - Move が void の場合, Game
 * - Move が 非 void の場合, pair<Game, Move>
 * Games は vector<State>
 *
 * F は Board を引数, Games を返り値に取る関数。
 * 1 手前の情報が必要かどうか応じて Move の引数を変える
 */

template <typename Board, typename Move = void>
struct ImpartialGameSolver {
  using Game = vector<Board>;
  using State = conditional_t<is_void_v<Move>, Game, pair<Game, Move>>;
  using Games = vector<State>;
  using Nimber = long long;
  using F = function<Games(Board)>;

  const Game& get_game(const State& s) {
    if constexpr (is_void_v<Move>) {
      return s;
    } else {
      return s.first;
    }
  }

  map<Board, Nimber> mp;
  F f;

  ImpartialGameSolver() = default;
  ImpartialGameSolver(const F& _f) : f(_f) {}
  void set_func(const F& _f) { f = _f; }

  Nimber get(const Board& b) {
    if (mp.count(b)) return mp[b];
    return mp[b] = _get(b);
  }
  Nimber get(const Game& g) {
    Nimber n = 0;
    for (const Board& s : g) n ^= get(s);
    return n;
  }
  Nimber get_from_state(const State& s) { return get(get_game(s)); }

  Move get_best_move(const Board& b) {
    assert(is_void_v<Move> == false);
    Nimber n = get(b);
    assert(n != 0 and "get_best_move(const Board& b)");
    Games gs = f(b);
    for (State& st : gs) {
      if (get_from_state(st) == 0) return st.second;
    }
    assert(false and "get_best_move(const Board& b)");
    exit(1);
  }

  // 選ぶ Board の index, および Move を返す
  pair<int, Move> get_best_move(const Game& g) {
    assert(is_void_v<Move> == false);
    Nimber n = get(g);
    assert(n != 0 and "get_best_move(const Game& g)");
    for (int i = 0; i < (int)g.size(); i++) {
      Board& b = g[i];
      Nimber bn = get(b);
      if (bn < (n ^ bn)) continue;
      Games gs = f(b);
      for (State& cur_st : gs) {
        if (get_from_state(cur_st) == (n ^ bn)) {
          return {b, g.second};
        }
      }
    }
    assert(false and "get_best_move(const Game& g)");
    exit(1);
  }

 private:
  Nimber _get(const Board& b) {
    Games gs = f(b);
    if (gs.empty()) return {};
    vector<Nimber> ns;
    for (State& st : gs) ns.push_back(get_from_state(st));
    sort(begin(ns), end(ns));
    ns.erase(unique(begin(ns), end(ns)), end(ns));
    for (int i = 0; i < (int)ns.size(); i++) {
      if (ns[i] != i) return i;
    }
    return ns.size();
  }
};

/**
 * @brief 非不偏ゲーム
 */
