---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0002.test.cpp
    title: verify/verify-yuki/yuki-0002.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0102.test.cpp
    title: verify/verify-yuki/yuki-0102.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0361.test.cpp
    title: verify/verify-yuki/yuki-0361.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4E0D\u504F\u30B2\u30FC\u30E0"
    links: []
  bundledCode: "#line 2 \"game/impartial-game.hpp\"\n\n#include <functional>\n#include\
    \ <map>\n#include <type_traits>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n\n/**\n * \u30B2\u30FC\u30E0\u306E\u9077\u79FB\u304C DAG \u3067\
    \u8868\u305B\u308B\u4E0D\u504F\u30B2\u30FC\u30E0\u306E solver\n *\n * Board\uFF1A\
    \u76E4\u9762\u306E\u578B\n * Move \u306F\u7740\u624B\u306E\u578B or void\n * Game\
    \ \u306F\n *\n * - splittable = true \u306E\u5834\u5408\u306F vector<Board> (\u30B2\
    \u30FC\u30E0\u306E\u5206\u5272\u306B\u5BFE\u5FDC)\n * - splittable = false\u306E\
    \u5834\u5408\u306F Board\n *\n * State \u306F\u6B21\n *\n * - Move \u304C void\
    \ \u3067\u3042\u308B\u5834\u5408, Game\n * - Move \u304C void \u3067\u306A\u3044\
    \u5834\u5408, pair<Game, Move>\n *\n * States \u306F vector<State>\n *\n * F \u306F\
    \ Board \u3092\u5F15\u6570, States \u3092\u8FD4\u308A\u5024\u306B\u53D6\u308B\u95A2\
    \u6570\u3002\u3064\u307E\u308A\n *\n * - \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\u5834\
    \u5408   : function<vector<Board>(Board)>\n * - splittable \u306E\u5834\u5408\
    \ : function<vector<vector<Board>(Board)>\n * - Move != void \u306E\u5834\u5408\
    \u306F\u8FD4\u308A\u5024\u306E value_type \u304C pair(*, move) \u306B\u306A\u308B\
    \n *\n * \u96D1\u306B\u30B2\u30FC\u30E0\u306E\u52DD\u6557\u3092\u77E5\u308A\u305F\
    \u3044\u3068\u304D\u306F\u30C7\u30D5\u30A9\u30EB\u30C8\u3067\u3088\u3044\n * \u6700\
    \u5584\u624B\u306E\u60C5\u5831\u304C\u6B32\u3057\u3044\u3068\u304D\u306F Move\
    \ \u306E\u5F15\u6570\u3092\u5909\u3048\u3066\u9811\u5F35\u308B\n */\n\ntemplate\
    \ <typename Board, typename Move = void, bool splittable = false>\nstruct ImpartialGameSolver\
    \ {\n  using Boards = vector<Board>;\n  using Game = conditional_t<splittable,\
    \ vector<Board>, Board>;\n  using State = conditional_t<is_void_v<Move>, Game,\
    \ pair<Game, Move>>;\n  using States = vector<State>;\n  using Nimber = long long;\n\
    \  using F = function<States(Board)>;\n\n  map<Board, Nimber> mp;\n  F f;\n\n\
    \  ImpartialGameSolver() = default;\n  ImpartialGameSolver(const F& _f) : f(_f)\
    \ {}\n  void set_func(const F& _f) { f = _f; }\n\n  template <typename T>\n  Nimber\
    \ get(const T& t) {\n    if constexpr (is_same_v<T, Board>) {\n      if (mp.count(t))\
    \ return mp[t];\n      return mp[t] = _get(t);\n    } else if constexpr (is_same_v<T,\
    \ Boards>) {\n      Nimber n = 0;\n      for (const Board& s : t) n ^= get(s);\n\
    \      return n;\n    } else {\n      static_assert(is_same_v<T, pair<Game, Move>>);\n\
    \      return get(t.first);\n    }\n  }\n\n  // \u8CA0\u3051\u5C40\u9762\u3067\
    \u547C\u3076\u3068 RE \u3059\u308B\n  template <typename T>\n  conditional_t<is_same_v<T,\
    \ Board>, Move, pair<int, Move>> get_best_move(\n      const T& t) {\n    static_assert(is_void_v<Move>\
    \ == false);\n    Nimber n = get(t);\n    assert(n != 0 and \"No Best Move.\"\
    );\n    if constexpr (is_same_v<T, Board>) {\n      auto res = change_x(t, n);\n\
    \      if (res.first) return res.second;\n    } else {\n      static_assert(is_same_v<T,\
    \ Boards>);\n      for (int i = 0; i < (int)t.size(); i++) {\n        auto res\
    \ = change_x(t[i], n);\n        if (res.first) return {i, res.second};\n     \
    \ }\n    }\n    assert(false and \"Error in get_best_move().\");\n    exit(1);\n\
    \  }\n\n private:\n  Nimber _get(const Board& b) {\n    States gs = f(b);\n  \
    \  if (gs.empty()) return {};\n    vector<Nimber> ns;\n    for (State& st : gs)\
    \ ns.push_back(get(st));\n    sort(begin(ns), end(ns));\n    ns.erase(unique(begin(ns),\
    \ end(ns)), end(ns));\n    for (int i = 0; i < (int)ns.size(); i++) {\n      if\
    \ (ns[i] != i) return i;\n    }\n    return ns.size();\n  }\n\n  // nimber \u304C\
    \ x \u5909\u308F\u308B\u3088\u3046\u306A\u7740\u624B\u3092\u8FD4\u3059\n  pair<bool,\
    \ Move> change_x(const Board& b, Nimber x) {\n    assert(is_void_v<Move> == false);\n\
    \    Nimber n = get(b);\n    for (auto& st : f(b)) {\n      if (get(st) == (x\
    \ ^ n)) return {true, st.second};\n    }\n    return {false, Move{}};\n  }\n};\n\
    \n/**\n * @brief \u4E0D\u504F\u30B2\u30FC\u30E0\n */\n"
  code: "#pragma once\n\n#include <functional>\n#include <map>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\n/**\n * \u30B2\u30FC\
    \u30E0\u306E\u9077\u79FB\u304C DAG \u3067\u8868\u305B\u308B\u4E0D\u504F\u30B2\u30FC\
    \u30E0\u306E solver\n *\n * Board\uFF1A\u76E4\u9762\u306E\u578B\n * Move \u306F\
    \u7740\u624B\u306E\u578B or void\n * Game \u306F\n *\n * - splittable = true \u306E\
    \u5834\u5408\u306F vector<Board> (\u30B2\u30FC\u30E0\u306E\u5206\u5272\u306B\u5BFE\
    \u5FDC)\n * - splittable = false\u306E\u5834\u5408\u306F Board\n *\n * State \u306F\
    \u6B21\n *\n * - Move \u304C void \u3067\u3042\u308B\u5834\u5408, Game\n * - Move\
    \ \u304C void \u3067\u306A\u3044\u5834\u5408, pair<Game, Move>\n *\n * States\
    \ \u306F vector<State>\n *\n * F \u306F Board \u3092\u5F15\u6570, States \u3092\
    \u8FD4\u308A\u5024\u306B\u53D6\u308B\u95A2\u6570\u3002\u3064\u307E\u308A\n *\n\
    \ * - \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\u5834\u5408   : function<vector<Board>(Board)>\n\
    \ * - splittable \u306E\u5834\u5408 : function<vector<vector<Board>(Board)>\n\
    \ * - Move != void \u306E\u5834\u5408\u306F\u8FD4\u308A\u5024\u306E value_type\
    \ \u304C pair(*, move) \u306B\u306A\u308B\n *\n * \u96D1\u306B\u30B2\u30FC\u30E0\
    \u306E\u52DD\u6557\u3092\u77E5\u308A\u305F\u3044\u3068\u304D\u306F\u30C7\u30D5\
    \u30A9\u30EB\u30C8\u3067\u3088\u3044\n * \u6700\u5584\u624B\u306E\u60C5\u5831\u304C\
    \u6B32\u3057\u3044\u3068\u304D\u306F Move \u306E\u5F15\u6570\u3092\u5909\u3048\
    \u3066\u9811\u5F35\u308B\n */\n\ntemplate <typename Board, typename Move = void,\
    \ bool splittable = false>\nstruct ImpartialGameSolver {\n  using Boards = vector<Board>;\n\
    \  using Game = conditional_t<splittable, vector<Board>, Board>;\n  using State\
    \ = conditional_t<is_void_v<Move>, Game, pair<Game, Move>>;\n  using States =\
    \ vector<State>;\n  using Nimber = long long;\n  using F = function<States(Board)>;\n\
    \n  map<Board, Nimber> mp;\n  F f;\n\n  ImpartialGameSolver() = default;\n  ImpartialGameSolver(const\
    \ F& _f) : f(_f) {}\n  void set_func(const F& _f) { f = _f; }\n\n  template <typename\
    \ T>\n  Nimber get(const T& t) {\n    if constexpr (is_same_v<T, Board>) {\n \
    \     if (mp.count(t)) return mp[t];\n      return mp[t] = _get(t);\n    } else\
    \ if constexpr (is_same_v<T, Boards>) {\n      Nimber n = 0;\n      for (const\
    \ Board& s : t) n ^= get(s);\n      return n;\n    } else {\n      static_assert(is_same_v<T,\
    \ pair<Game, Move>>);\n      return get(t.first);\n    }\n  }\n\n  // \u8CA0\u3051\
    \u5C40\u9762\u3067\u547C\u3076\u3068 RE \u3059\u308B\n  template <typename T>\n\
    \  conditional_t<is_same_v<T, Board>, Move, pair<int, Move>> get_best_move(\n\
    \      const T& t) {\n    static_assert(is_void_v<Move> == false);\n    Nimber\
    \ n = get(t);\n    assert(n != 0 and \"No Best Move.\");\n    if constexpr (is_same_v<T,\
    \ Board>) {\n      auto res = change_x(t, n);\n      if (res.first) return res.second;\n\
    \    } else {\n      static_assert(is_same_v<T, Boards>);\n      for (int i =\
    \ 0; i < (int)t.size(); i++) {\n        auto res = change_x(t[i], n);\n      \
    \  if (res.first) return {i, res.second};\n      }\n    }\n    assert(false and\
    \ \"Error in get_best_move().\");\n    exit(1);\n  }\n\n private:\n  Nimber _get(const\
    \ Board& b) {\n    States gs = f(b);\n    if (gs.empty()) return {};\n    vector<Nimber>\
    \ ns;\n    for (State& st : gs) ns.push_back(get(st));\n    sort(begin(ns), end(ns));\n\
    \    ns.erase(unique(begin(ns), end(ns)), end(ns));\n    for (int i = 0; i < (int)ns.size();\
    \ i++) {\n      if (ns[i] != i) return i;\n    }\n    return ns.size();\n  }\n\
    \n  // nimber \u304C x \u5909\u308F\u308B\u3088\u3046\u306A\u7740\u624B\u3092\u8FD4\
    \u3059\n  pair<bool, Move> change_x(const Board& b, Nimber x) {\n    assert(is_void_v<Move>\
    \ == false);\n    Nimber n = get(b);\n    for (auto& st : f(b)) {\n      if (get(st)\
    \ == (x ^ n)) return {true, st.second};\n    }\n    return {false, Move{}};\n\
    \  }\n};\n\n/**\n * @brief \u4E0D\u504F\u30B2\u30FC\u30E0\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: game/impartial-game.hpp
  requiredBy: []
  timestamp: '2023-08-10 13:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-0102.test.cpp
  - verify/verify-yuki/yuki-0361.test.cpp
  - verify/verify-yuki/yuki-0002.test.cpp
documentation_of: game/impartial-game.hpp
layout: document
redirect_from:
- /library/game/impartial-game.hpp
- /library/game/impartial-game.hpp.html
title: "\u4E0D\u504F\u30B2\u30FC\u30E0"
---
