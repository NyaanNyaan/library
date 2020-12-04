---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/run-length-encoding.hpp\"\n\n\n\nvector<pair<char,\
    \ int>> RunLengthEncoding(string& S) {\n  vector<pair<char, int>> ret;\n  char\
    \ c = -1;\n  int n = 0;\n  for (char x : S) {\n    if (c == x)\n      n++;\n \
    \   else {\n      if (n) ret.emplace_back(c, n);\n      c = x, n = 1;\n    }\n\
    \  }\n  if (n) ret.emplace_back(c, n);\n  return ret;\n}\n\ntemplate <typename\
    \ T>\nvector<pair<T, int>> RunLengthEncoding(vector<T>& S) {\n  vector<pair<T,\
    \ int>> ret;\n  T c = -1;\n  int n = 0;\n  for (T& x : S) {\n    if (c == x)\n\
    \      n++;\n    else {\n      if (n) ret.emplace_back(c, n);\n      c = x, n\
    \ = 1;\n    }\n  }\n  if (n) ret.emplace_back(c, n);\n  return ret;\n}\n"
  code: "#pragma once\n\n\n\nvector<pair<char, int>> RunLengthEncoding(string& S)\
    \ {\n  vector<pair<char, int>> ret;\n  char c = -1;\n  int n = 0;\n  for (char\
    \ x : S) {\n    if (c == x)\n      n++;\n    else {\n      if (n) ret.emplace_back(c,\
    \ n);\n      c = x, n = 1;\n    }\n  }\n  if (n) ret.emplace_back(c, n);\n  return\
    \ ret;\n}\n\ntemplate <typename T>\nvector<pair<T, int>> RunLengthEncoding(vector<T>&\
    \ S) {\n  vector<pair<T, int>> ret;\n  T c = -1;\n  int n = 0;\n  for (T& x :\
    \ S) {\n    if (c == x)\n      n++;\n    else {\n      if (n) ret.emplace_back(c,\
    \ n);\n      c = x, n = 1;\n    }\n  }\n  if (n) ret.emplace_back(c, n);\n  return\
    \ ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/run-length-encoding.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/run-length-encoding.hpp
layout: document
redirect_from:
- /library/string/run-length-encoding.hpp
- /library/string/run-length-encoding.hpp.html
title: string/run-length-encoding.hpp
---
