---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-unit-test/run-length-encoding.test.cpp
    title: verify/verify-unit-test/run-length-encoding.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Run Length Encoding(\u9023\u9577\u5727\u7E2E)"
    links: []
  bundledCode: "#line 2 \"string/run-length-encoding.hpp\"\n\ntemplate <typename C>\n\
    vector<pair<typename C::value_type, int>> RunLengthEncoding(C& S) {\n  using T\
    \ = typename C::value_type;\n  if (S.empty()) return {};\n  vector<pair<T, int>>\
    \ ret;\n  T c = S[0];\n  int n = 1;\n  for (int i = 1; i < (int)S.size(); i++)\
    \ {\n    if (S[i] == c)\n      n++;\n    else {\n      ret.emplace_back(c, n);\n\
    \      c = S[i], n = 1;\n    }\n  }\n  ret.emplace_back(c, n);\n  return ret;\n\
    }\n\n/**\n * @brief Run Length Encoding(\u9023\u9577\u5727\u7E2E)\n */\n"
  code: "#pragma once\n\ntemplate <typename C>\nvector<pair<typename C::value_type,\
    \ int>> RunLengthEncoding(C& S) {\n  using T = typename C::value_type;\n  if (S.empty())\
    \ return {};\n  vector<pair<T, int>> ret;\n  T c = S[0];\n  int n = 1;\n  for\
    \ (int i = 1; i < (int)S.size(); i++) {\n    if (S[i] == c)\n      n++;\n    else\
    \ {\n      ret.emplace_back(c, n);\n      c = S[i], n = 1;\n    }\n  }\n  ret.emplace_back(c,\
    \ n);\n  return ret;\n}\n\n/**\n * @brief Run Length Encoding(\u9023\u9577\u5727\
    \u7E2E)\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: string/run-length-encoding.hpp
  requiredBy: []
  timestamp: '2021-01-01 19:43:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-unit-test/run-length-encoding.test.cpp
documentation_of: string/run-length-encoding.hpp
layout: document
redirect_from:
- /library/string/run-length-encoding.hpp
- /library/string/run-length-encoding.hpp.html
title: "Run Length Encoding(\u9023\u9577\u5727\u7E2E)"
---
