---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/debug.test.cpp
    title: verify/verify-unit-test/debug.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30C7\u30D0\u30C3\u30B0\u7528\u30C0\u30F3\u30D7\u95A2\u6570"
    links: []
  bundledCode: "#line 2 \"template/debug.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nnamespace DebugImpl {\n\nvoid dump(const char& t) { cerr << t; }\n\n\
    void dump(const string& t) { cerr << t; }\n\ntemplate <typename T>\nvoid dump(const\
    \ T& t, enable_if_t<is_integral<T>::value>* = nullptr) {\n  string res;\n  if\
    \ (t == inf) res = \"inf\";\n  if (is_signed<T>::value && t == -inf) res = \"\
    -inf\";\n  if (sizeof(T) == 8) {\n    if (t == infLL) res = \"inf\";\n    if (is_signed<T>::value\
    \ && t == -infLL) res = \"-inf\";\n  }\n  if (res.empty()) res = to_string(t);\n\
    \  cerr << res;\n}\n\ntemplate <typename T, typename U>\nvoid dump(const pair<T,\
    \ U>&);\ntemplate <typename T>\nvoid dump(const pair<T*, int>&);\n\ntemplate <typename\
    \ T>\nvoid dump(const T& t,\n          enable_if_t<!is_void<typename T::iterator>::value>*\
    \ = nullptr) {\n  cerr << \"[ \";\n  for (auto it = t.begin(); it != t.end();)\
    \ {\n    dump(*it);\n    cerr << (++it == t.end() ? \" ]\" : \", \");\n  }\n}\n\
    \ntemplate <typename T, typename U>\nvoid dump(const pair<T, U>& t) {\n  cerr\
    \ << \"( \";\n  dump(t.first);\n  cerr << \", \";\n  dump(t.second);\n  cerr <<\
    \ \" )\";\n}\n\ntemplate <typename T>\nvoid dump(const pair<T*, int>& t) {\n \
    \ cerr << \"[ \";\n  for (int i = 0; i < t.second; i++) {\n    dump(t.first[i]);\n\
    \    cerr << (i == t.second - 1 ? \" ]\" : \", \");\n  }\n}\n\nvoid trace() {\
    \ cerr << endl; }\ntemplate <typename Head, typename... Tail>\nvoid trace(Head&&\
    \ head, Tail&&... tail) {\n  cerr << \" \";\n  dump(head);\n  if (sizeof...(tail)\
    \ != 0) cerr << \",\";\n  trace(forward<Tail>(tail)...);\n}\n\n}  // namespace\
    \ DebugImpl\nusing DebugImpl::trace;\n\n/**\n * @brief \u30C7\u30D0\u30C3\u30B0\
    \u7528\u30C0\u30F3\u30D7\u95A2\u6570\n */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nnamespace\
    \ DebugImpl {\n\nvoid dump(const char& t) { cerr << t; }\n\nvoid dump(const string&\
    \ t) { cerr << t; }\n\ntemplate <typename T>\nvoid dump(const T& t, enable_if_t<is_integral<T>::value>*\
    \ = nullptr) {\n  string res;\n  if (t == inf) res = \"inf\";\n  if (is_signed<T>::value\
    \ && t == -inf) res = \"-inf\";\n  if (sizeof(T) == 8) {\n    if (t == infLL)\
    \ res = \"inf\";\n    if (is_signed<T>::value && t == -infLL) res = \"-inf\";\n\
    \  }\n  if (res.empty()) res = to_string(t);\n  cerr << res;\n}\n\ntemplate <typename\
    \ T, typename U>\nvoid dump(const pair<T, U>&);\ntemplate <typename T>\nvoid dump(const\
    \ pair<T*, int>&);\n\ntemplate <typename T>\nvoid dump(const T& t,\n         \
    \ enable_if_t<!is_void<typename T::iterator>::value>* = nullptr) {\n  cerr <<\
    \ \"[ \";\n  for (auto it = t.begin(); it != t.end();) {\n    dump(*it);\n   \
    \ cerr << (++it == t.end() ? \" ]\" : \", \");\n  }\n}\n\ntemplate <typename T,\
    \ typename U>\nvoid dump(const pair<T, U>& t) {\n  cerr << \"( \";\n  dump(t.first);\n\
    \  cerr << \", \";\n  dump(t.second);\n  cerr << \" )\";\n}\n\ntemplate <typename\
    \ T>\nvoid dump(const pair<T*, int>& t) {\n  cerr << \"[ \";\n  for (int i = 0;\
    \ i < t.second; i++) {\n    dump(t.first[i]);\n    cerr << (i == t.second - 1\
    \ ? \" ]\" : \", \");\n  }\n}\n\nvoid trace() { cerr << endl; }\ntemplate <typename\
    \ Head, typename... Tail>\nvoid trace(Head&& head, Tail&&... tail) {\n  cerr <<\
    \ \" \";\n  dump(head);\n  if (sizeof...(tail) != 0) cerr << \",\";\n  trace(forward<Tail>(tail)...);\n\
    }\n\n}  // namespace DebugImpl\nusing DebugImpl::trace;\n\n/**\n * @brief \u30C7\
    \u30D0\u30C3\u30B0\u7528\u30C0\u30F3\u30D7\u95A2\u6570\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: template/debug.hpp
  requiredBy: []
  timestamp: '2020-11-27 19:57:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/debug.test.cpp
documentation_of: template/debug.hpp
layout: document
redirect_from:
- /library/template/debug.hpp
- /library/template/debug.hpp.html
title: "\u30C7\u30D0\u30C3\u30B0\u7528\u30C0\u30F3\u30D7\u95A2\u6570"
---
