---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/run-length-encoding.test.cpp
    title: verify/verify-unit-test/run-length-encoding.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Run Length Encoding(\u9023\u9577\u5727\u7E2E)"
    links: []
  bundledCode: "#line 2 \"string/run-length-encoding.hpp\"\n\ntemplate <typename C>\n\
    vector<pair<typename C::value_type, int>> RunLengthEncoding(const C& S) {\n  using\
    \ T = typename C::value_type;\n  if (S.empty()) return {};\n  vector<pair<T, int>>\
    \ ret;\n  T c = S[0];\n  int n = 1;\n  for (int i = 1; i < (int)S.size(); i++)\
    \ {\n    if (S[i] == c)\n      n++;\n    else {\n      ret.emplace_back(c, n);\n\
    \      c = S[i], n = 1;\n    }\n  }\n  ret.emplace_back(c, n);\n  return ret;\n\
    }\n\n/**\n * @brief Run Length Encoding(\u9023\u9577\u5727\u7E2E)\n */\n"
  code: "#pragma once\n\ntemplate <typename C>\nvector<pair<typename C::value_type,\
    \ int>> RunLengthEncoding(const C& S) {\n  using T = typename C::value_type;\n\
    \  if (S.empty()) return {};\n  vector<pair<T, int>> ret;\n  T c = S[0];\n  int\
    \ n = 1;\n  for (int i = 1; i < (int)S.size(); i++) {\n    if (S[i] == c)\n  \
    \    n++;\n    else {\n      ret.emplace_back(c, n);\n      c = S[i], n = 1;\n\
    \    }\n  }\n  ret.emplace_back(c, n);\n  return ret;\n}\n\n/**\n * @brief Run\
    \ Length Encoding(\u9023\u9577\u5727\u7E2E)\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: string/run-length-encoding.hpp
  requiredBy: []
  timestamp: '2023-12-22 19:57:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/run-length-encoding.test.cpp
documentation_of: string/run-length-encoding.hpp
layout: document
redirect_from:
- /library/string/run-length-encoding.hpp
- /library/string/run-length-encoding.hpp.html
title: "Run Length Encoding(\u9023\u9577\u5727\u7E2E)"
---
