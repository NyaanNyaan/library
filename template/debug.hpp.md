---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/debug.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nnamespace DebugImpl {\n\ntemplate <typename T, enable_if_t<is_integral<T>::value,\
    \ nullptr_t> = nullptr>\nvoid print(const T& t) {\n  if (t == inf) {\n    cerr\
    \ << \"inf\";\n    return;\n  }\n  if constexpr (is_signed<T>::value) {\n    if\
    \ (t == -inf) {\n      cerr << \"-inf\";\n      return;\n    }\n  }\n  if constexpr\
    \ (sizeof(T) == 8) {\n    if constexpr (is_signed<T>::value) {\n      if (t ==\
    \ -infLL) {\n        cerr << \"-inf\";\n        return;\n      }\n    }\n    if\
    \ (t == infLL) {\n      cerr << \"inf\";\n      return;\n    }\n  }\n  cerr <<\
    \ t;\n  return;\n}\n\ntemplate <typename T, enable_if_t<!is_void<typename T::iterator>::value,\n\
    \                                  nullptr_t> = nullptr>\nvoid print(const T&\
    \ t) {\n  cerr << \"{ \";\n  for (auto it = t.begin(); it != t.end();) {\n   \
    \ print(*it);\n    cerr << (++it == t.end() ? \" }\" : \", \");\n  }\n}\n\nvoid\
    \ trace() { cerr << endl; }\ntemplate <typename Head, typename... Tail>\nvoid\
    \ trace(Head&& head, Tail&&... tail) {\n  print(head);\n  if (sizeof...(tail)\
    \ != 0) cerr << \", \";\n  trace(forward<Tail>(tail)...);\n}\n\n}  // namespace\
    \ DebugImpl\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nnamespace\
    \ DebugImpl {\n\ntemplate <typename T, enable_if_t<is_integral<T>::value, nullptr_t>\
    \ = nullptr>\nvoid print(const T& t) {\n  if (t == inf) {\n    cerr << \"inf\"\
    ;\n    return;\n  }\n  if constexpr (is_signed<T>::value) {\n    if (t == -inf)\
    \ {\n      cerr << \"-inf\";\n      return;\n    }\n  }\n  if constexpr (sizeof(T)\
    \ == 8) {\n    if constexpr (is_signed<T>::value) {\n      if (t == -infLL) {\n\
    \        cerr << \"-inf\";\n        return;\n      }\n    }\n    if (t == infLL)\
    \ {\n      cerr << \"inf\";\n      return;\n    }\n  }\n  cerr << t;\n  return;\n\
    }\n\ntemplate <typename T, enable_if_t<!is_void<typename T::iterator>::value,\n\
    \                                  nullptr_t> = nullptr>\nvoid print(const T&\
    \ t) {\n  cerr << \"{ \";\n  for (auto it = t.begin(); it != t.end();) {\n   \
    \ print(*it);\n    cerr << (++it == t.end() ? \" }\" : \", \");\n  }\n}\n\nvoid\
    \ trace() { cerr << endl; }\ntemplate <typename Head, typename... Tail>\nvoid\
    \ trace(Head&& head, Tail&&... tail) {\n  print(head);\n  if (sizeof...(tail)\
    \ != 0) cerr << \", \";\n  trace(forward<Tail>(tail)...);\n}\n\n}  // namespace\
    \ DebugImpl"
  dependsOn: []
  isVerificationFile: false
  path: template/debug.hpp
  requiredBy: []
  timestamp: '2020-11-27 13:31:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/debug.hpp
layout: document
redirect_from:
- /library/template/debug.hpp
- /library/template/debug.hpp.html
title: template/debug.hpp
---
