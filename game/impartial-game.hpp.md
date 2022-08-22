---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u975E\u4E0D\u504F\u30B2\u30FC\u30E0"
    links: []
  bundledCode: "#line 2 \"game/impartial-game.hpp\"\n\n#include <functional>\n#include\
    \ <map>\n#include <type_traits>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n\n/**\n * Board \u306F\u76E4\u9762\u306E\u578B, Move \u306F\u7740\
    \u624B\u306E\u578B (void OK)\n *\n * Game \u306F vector<Board> (\u30B2\u30FC\u30E0\
    \u304C\u5206\u5272\u3055\u308C\u308B\u5834\u5408\u306B\u5BFE\u5FDC)\n * State\
    \ \u306F\u6B21\u306E\u3088\u3046\u306A\u578B\n * - Move \u304C void \u306E\u5834\
    \u5408, Game\n * - Move \u304C \u975E void \u306E\u5834\u5408, pair<Game, Move>\n\
    \ * Games \u306F vector<State>\n *\n * F \u306F Board \u3092\u5F15\u6570, Games\
    \ \u3092\u8FD4\u308A\u5024\u306B\u53D6\u308B\u95A2\u6570\u3002\n * 1 \u624B\u524D\
    \u306E\u60C5\u5831\u304C\u5FC5\u8981\u304B\u3069\u3046\u304B\u5FDC\u3058\u3066\
    \ Move \u306E\u5F15\u6570\u3092\u5909\u3048\u308B\n */\n\ntemplate <typename Board,\
    \ typename Move = void>\nstruct ImpartialGameSolver {\n  using Game = vector<Board>;\n\
    \  using State = conditional_t<is_void_v<Move>, Game, pair<Game, Move>>;\n  using\
    \ Games = vector<State>;\n  using Nimber = long long;\n  using F = function<Games(Board)>;\n\
    \n  const Game& get_game(const State& s) {\n    if constexpr (is_void_v<Move>)\
    \ {\n      return s;\n    } else {\n      return s.first;\n    }\n  }\n\n  map<Board,\
    \ Nimber> mp;\n  F f;\n\n  ImpartialGameSolver() = default;\n  ImpartialGameSolver(const\
    \ F& _f) : f(_f) {}\n  void set_func(const F& _f) { f = _f; }\n\n  Nimber get(const\
    \ Board& b) {\n    if (mp.count(b)) return mp[b];\n    return mp[b] = _get(b);\n\
    \  }\n  Nimber get(const Game& g) {\n    Nimber n = 0;\n    for (const Board&\
    \ s : g) n ^= get(s);\n    return n;\n  }\n  Nimber get_from_state(const State&\
    \ s) { return get(get_game(s)); }\n\n  Move get_best_move(const Board& b) {\n\
    \    assert(is_void_v<Move> == false);\n    Nimber n = get(b);\n    assert(n !=\
    \ 0 and \"get_best_move(const Board& b)\");\n    Games gs = f(b);\n    for (State&\
    \ st : gs) {\n      if (get_from_state(st) == 0) return st.second;\n    }\n  \
    \  assert(false and \"get_best_move(const Board& b)\");\n    exit(1);\n  }\n\n\
    \  // \u9078\u3076 Board \u306E index, \u304A\u3088\u3073 Move \u3092\u8FD4\u3059\
    \n  pair<int, Move> get_best_move(const Game& g) {\n    assert(is_void_v<Move>\
    \ == false);\n    Nimber n = get(g);\n    assert(n != 0 and \"get_best_move(const\
    \ Game& g)\");\n    for (int i = 0; i < (int)g.size(); i++) {\n      Board& b\
    \ = g[i];\n      Nimber bn = get(b);\n      if (bn < (n ^ bn)) continue;\n   \
    \   Games gs = f(b);\n      for (State& cur_st : gs) {\n        if (get_from_state(cur_st)\
    \ == (n ^ bn)) {\n          return {b, g.second};\n        }\n      }\n    }\n\
    \    assert(false and \"get_best_move(const Game& g)\");\n    exit(1);\n  }\n\n\
    \ private:\n  Nimber _get(const Board& b) {\n    Games gs = f(b);\n    if (gs.empty())\
    \ return {};\n    vector<Nimber> ns;\n    for (State& st : gs) ns.push_back(get_from_state(st));\n\
    \    sort(begin(ns), end(ns));\n    ns.erase(unique(begin(ns), end(ns)), end(ns));\n\
    \    for (int i = 0; i < (int)ns.size(); i++) {\n      if (ns[i] != i) return\
    \ i;\n    }\n    return ns.size();\n  }\n};\n\n/**\n * @brief \u975E\u4E0D\u504F\
    \u30B2\u30FC\u30E0\n */\n"
  code: "#pragma once\n\n#include <functional>\n#include <map>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\n/**\n * Board \u306F\
    \u76E4\u9762\u306E\u578B, Move \u306F\u7740\u624B\u306E\u578B (void OK)\n *\n\
    \ * Game \u306F vector<Board> (\u30B2\u30FC\u30E0\u304C\u5206\u5272\u3055\u308C\
    \u308B\u5834\u5408\u306B\u5BFE\u5FDC)\n * State \u306F\u6B21\u306E\u3088\u3046\
    \u306A\u578B\n * - Move \u304C void \u306E\u5834\u5408, Game\n * - Move \u304C\
    \ \u975E void \u306E\u5834\u5408, pair<Game, Move>\n * Games \u306F vector<State>\n\
    \ *\n * F \u306F Board \u3092\u5F15\u6570, Games \u3092\u8FD4\u308A\u5024\u306B\
    \u53D6\u308B\u95A2\u6570\u3002\n * 1 \u624B\u524D\u306E\u60C5\u5831\u304C\u5FC5\
    \u8981\u304B\u3069\u3046\u304B\u5FDC\u3058\u3066 Move \u306E\u5F15\u6570\u3092\
    \u5909\u3048\u308B\n */\n\ntemplate <typename Board, typename Move = void>\nstruct\
    \ ImpartialGameSolver {\n  using Game = vector<Board>;\n  using State = conditional_t<is_void_v<Move>,\
    \ Game, pair<Game, Move>>;\n  using Games = vector<State>;\n  using Nimber = long\
    \ long;\n  using F = function<Games(Board)>;\n\n  const Game& get_game(const State&\
    \ s) {\n    if constexpr (is_void_v<Move>) {\n      return s;\n    } else {\n\
    \      return s.first;\n    }\n  }\n\n  map<Board, Nimber> mp;\n  F f;\n\n  ImpartialGameSolver()\
    \ = default;\n  ImpartialGameSolver(const F& _f) : f(_f) {}\n  void set_func(const\
    \ F& _f) { f = _f; }\n\n  Nimber get(const Board& b) {\n    if (mp.count(b)) return\
    \ mp[b];\n    return mp[b] = _get(b);\n  }\n  Nimber get(const Game& g) {\n  \
    \  Nimber n = 0;\n    for (const Board& s : g) n ^= get(s);\n    return n;\n \
    \ }\n  Nimber get_from_state(const State& s) { return get(get_game(s)); }\n\n\
    \  Move get_best_move(const Board& b) {\n    assert(is_void_v<Move> == false);\n\
    \    Nimber n = get(b);\n    assert(n != 0 and \"get_best_move(const Board& b)\"\
    );\n    Games gs = f(b);\n    for (State& st : gs) {\n      if (get_from_state(st)\
    \ == 0) return st.second;\n    }\n    assert(false and \"get_best_move(const Board&\
    \ b)\");\n    exit(1);\n  }\n\n  // \u9078\u3076 Board \u306E index, \u304A\u3088\
    \u3073 Move \u3092\u8FD4\u3059\n  pair<int, Move> get_best_move(const Game& g)\
    \ {\n    assert(is_void_v<Move> == false);\n    Nimber n = get(g);\n    assert(n\
    \ != 0 and \"get_best_move(const Game& g)\");\n    for (int i = 0; i < (int)g.size();\
    \ i++) {\n      Board& b = g[i];\n      Nimber bn = get(b);\n      if (bn < (n\
    \ ^ bn)) continue;\n      Games gs = f(b);\n      for (State& cur_st : gs) {\n\
    \        if (get_from_state(cur_st) == (n ^ bn)) {\n          return {b, g.second};\n\
    \        }\n      }\n    }\n    assert(false and \"get_best_move(const Game& g)\"\
    );\n    exit(1);\n  }\n\n private:\n  Nimber _get(const Board& b) {\n    Games\
    \ gs = f(b);\n    if (gs.empty()) return {};\n    vector<Nimber> ns;\n    for\
    \ (State& st : gs) ns.push_back(get_from_state(st));\n    sort(begin(ns), end(ns));\n\
    \    ns.erase(unique(begin(ns), end(ns)), end(ns));\n    for (int i = 0; i < (int)ns.size();\
    \ i++) {\n      if (ns[i] != i) return i;\n    }\n    return ns.size();\n  }\n\
    };\n\n/**\n * @brief \u975E\u4E0D\u504F\u30B2\u30FC\u30E0\n */"
  dependsOn: []
  isVerificationFile: false
  path: game/impartial-game.hpp
  requiredBy: []
  timestamp: '2022-08-22 19:46:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: game/impartial-game.hpp
layout: document
redirect_from:
- /library/game/impartial-game.hpp
- /library/game/impartial-game.hpp.html
title: "\u975E\u4E0D\u504F\u30B2\u30FC\u30E0"
---
