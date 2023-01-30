---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/manacher.test.cpp
    title: verify/verify-unit-test/manacher.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Manacher's algorithm
    links: []
  bundledCode: "#line 2 \"string/manacher.hpp\"\n\n#include <vector>\nusing namespace\
    \ std;\n\ntemplate <typename Container>\nvector<int> manacher(const Container&\
    \ S) {\n  vector<int> res(S.size());\n  int i = 0, j = 0;\n  while (i < int(S.size()))\
    \ {\n    while (i - j >= 0 and i + j < int(S.size()) and S[i - j] == S[i + j])\
    \ j++;\n    res[i] = j;\n    int k = 1;\n    while (i - k >= 0 and i + k < int(S.size())\
    \ and k + res[i - k] < j)\n      res[i + k] = res[i - k], k++;\n    i += k, j\
    \ -= k;\n  }\n  return res;\n}\n\n// \u4E2D\u5FC3\u8EF8\u3092\u56FA\u5B9A\u3057\
    \u305F\u3068\u304D\u306E\u5404\u8EF8\u306B\u5BFE\u3057\u3066\u6975\u5927\u306A\
    \u56DE\u6587\u3092\u5DE6\u304B\u3089\u5217\u6319(\u7A7A\u6587\u5B57\u5217\u3092\
    \u542B\u3080)\ntemplate <typename Container>\nvector<pair<int, int>> enumerate_palindromes(const\
    \ Container& vec) {\n  using T = typename Container::value_type;\n  vector<T>\
    \ v;\n  const int N = vec.size();\n  for (int i = 0; i < N - 1; i++) {\n    v.push_back(vec[i]);\n\
    \    v.push_back(-1);\n  }\n  v.push_back(vec.back());\n  const auto man = manacher(v);\n\
    \  vector<pair<int, int>> ret;\n  for (int i = 0; i < N * 2 - 1; i++) {\n    if\
    \ (i & 1) {\n      int w = man[i] / 2;\n      ret.emplace_back((i + 1) / 2 - w,\
    \ (i + 1) / 2 + w);\n    } else {\n      int w = (man[i] - 1) / 2;\n      ret.emplace_back(i\
    \ / 2 - w, i / 2 + w + 1);\n    }\n  }\n  return ret;\n}\n\n// ret[r] : s[l, r]\
    \ \u304C\u56DE\u6587\u3067\u3042\u308B\u6700\u5C0F\u306E l\ntemplate <typename\
    \ Container>\nvector<int> enumerate_leftmost_palindromes(const Container& vec)\
    \ {\n  vector<int> v(vec.size(), 1);\n  for (auto& [l, r] : enumerate_palindromes(vec))\
    \ {\n    v[r - 1] = max(v[r - 1], r - l);\n  }\n  for (int i = (int)vec.size()\
    \ - 2; i >= 0; i--) v[i] = max(v[i], v[i + 1] - 2);\n  vector<int> ret(vec.size());\n\
    \  for (int i = 0; i < (int)vec.size(); i++) ret[i] = i + 1 - v[i];\n  return\
    \ ret;\n}\n\n/**\n * @brief Manacher's algorithm\n */\n"
  code: "#pragma once\n\n#include <vector>\nusing namespace std;\n\ntemplate <typename\
    \ Container>\nvector<int> manacher(const Container& S) {\n  vector<int> res(S.size());\n\
    \  int i = 0, j = 0;\n  while (i < int(S.size())) {\n    while (i - j >= 0 and\
    \ i + j < int(S.size()) and S[i - j] == S[i + j]) j++;\n    res[i] = j;\n    int\
    \ k = 1;\n    while (i - k >= 0 and i + k < int(S.size()) and k + res[i - k] <\
    \ j)\n      res[i + k] = res[i - k], k++;\n    i += k, j -= k;\n  }\n  return\
    \ res;\n}\n\n// \u4E2D\u5FC3\u8EF8\u3092\u56FA\u5B9A\u3057\u305F\u3068\u304D\u306E\
    \u5404\u8EF8\u306B\u5BFE\u3057\u3066\u6975\u5927\u306A\u56DE\u6587\u3092\u5DE6\
    \u304B\u3089\u5217\u6319(\u7A7A\u6587\u5B57\u5217\u3092\u542B\u3080)\ntemplate\
    \ <typename Container>\nvector<pair<int, int>> enumerate_palindromes(const Container&\
    \ vec) {\n  using T = typename Container::value_type;\n  vector<T> v;\n  const\
    \ int N = vec.size();\n  for (int i = 0; i < N - 1; i++) {\n    v.push_back(vec[i]);\n\
    \    v.push_back(-1);\n  }\n  v.push_back(vec.back());\n  const auto man = manacher(v);\n\
    \  vector<pair<int, int>> ret;\n  for (int i = 0; i < N * 2 - 1; i++) {\n    if\
    \ (i & 1) {\n      int w = man[i] / 2;\n      ret.emplace_back((i + 1) / 2 - w,\
    \ (i + 1) / 2 + w);\n    } else {\n      int w = (man[i] - 1) / 2;\n      ret.emplace_back(i\
    \ / 2 - w, i / 2 + w + 1);\n    }\n  }\n  return ret;\n}\n\n// ret[r] : s[l, r]\
    \ \u304C\u56DE\u6587\u3067\u3042\u308B\u6700\u5C0F\u306E l\ntemplate <typename\
    \ Container>\nvector<int> enumerate_leftmost_palindromes(const Container& vec)\
    \ {\n  vector<int> v(vec.size(), 1);\n  for (auto& [l, r] : enumerate_palindromes(vec))\
    \ {\n    v[r - 1] = max(v[r - 1], r - l);\n  }\n  for (int i = (int)vec.size()\
    \ - 2; i >= 0; i--) v[i] = max(v[i], v[i + 1] - 2);\n  vector<int> ret(vec.size());\n\
    \  for (int i = 0; i < (int)vec.size(); i++) ret[i] = i + 1 - v[i];\n  return\
    \ ret;\n}\n\n/**\n * @brief Manacher's algorithm\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.hpp
  requiredBy: []
  timestamp: '2023-01-31 00:28:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/manacher.test.cpp
documentation_of: string/manacher.hpp
layout: document
redirect_from:
- /library/string/manacher.hpp
- /library/string/manacher.hpp.html
title: Manacher's algorithm
---
