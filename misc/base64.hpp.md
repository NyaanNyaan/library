---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0502-base64.test.cpp
    title: verify/verify-yuki/yuki-0502-base64.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Base64 (\u30BD\u30FC\u30B9\u30B3\u30FC\u30C9\u306B\u6570\u5217\
      \u3092\u5727\u7E2E\u3057\u3066\u57CB\u3081\u8FBC\u3080\u7528\u306E\u7B26\u53F7\
      \u5316\u30FB\u5FA9\u53F7\u5316\u30E9\u30A4\u30D6\u30E9\u30EA)"
    links: []
  bundledCode: "#line 2 \"misc/base64.hpp\"\n\n#include <algorithm>\n#include <string>\n\
    #include <vector>\nusing namespace std;\n\nnamespace Base64 {\nusing L = long\
    \ long;\nchar base[66] =\n    \"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/.\"\
    ;\nint ibase(char c) {\n  return 'a' <= c   ? 0x1A + c - 'a'\n         : 'A' <=\
    \ c ? 0x00 + c - 'A'\n         : '0' <= c ? 0x34 + c - '0'\n         : '+' ==\
    \ c ? 0x3E\n         : '/' == c ? 0x3F\n                    : 0x40;\n}\ntemplate\
    \ <typename T>\nstring encode(vector<T> &a) {\n  T x = a[0], y = a[0];\n  for\
    \ (auto &z : a) x = max(x, z), y = min(y, z);\n  L N = a.size(),\n    B = max<L>(6,\
    \ y < 0 ? sizeof(T) * 8 : 64 - __builtin_clzll(x));\n  string S((B * N + 11) /\
    \ 6, 0);\n  S[0] = B;\n  for (int i = 0; i < N; i++) {\n    for (int j = 0; j\
    \ < B; j++) {\n      if ((a[i] >> j) & 1) S[(i * B + j) / 6 + 1] |= 1 << ((i *\
    \ B + j) % 6);\n    }\n  }\n  for (auto &c : S) c = base[(int)c];\n  return S;\n\
    }\nvector<L> decode(string S) {\n  for (auto &c : S) c = ibase(c);\n  L B = S[0],\
    \ M = S.size() - 1;\n  vector<L> a(6 * M / B, 0);\n  for (int i = 0; i < M; i++)\
    \ {\n    for (int j = 0; j < 6; j++) {\n      if ((S[i + 1] >> j) & 1) a[(i *\
    \ 6 + j) / B] |= 1LL << ((i * 6 + j) % B);\n    }\n  }\n  return a;\n}\n}  //\
    \ namespace Base64\n\n/**\n * @brief Base64 (\u30BD\u30FC\u30B9\u30B3\u30FC\u30C9\
    \u306B\u6570\u5217\u3092\u5727\u7E2E\u3057\u3066\u57CB\u3081\u8FBC\u3080\u7528\
    \u306E\u7B26\u53F7\u5316\u30FB\u5FA9\u53F7\u5316\u30E9\u30A4\u30D6\u30E9\u30EA\
    )\n */\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <string>\n#include <vector>\n\
    using namespace std;\n\nnamespace Base64 {\nusing L = long long;\nchar base[66]\
    \ =\n    \"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/.\"\
    ;\nint ibase(char c) {\n  return 'a' <= c   ? 0x1A + c - 'a'\n         : 'A' <=\
    \ c ? 0x00 + c - 'A'\n         : '0' <= c ? 0x34 + c - '0'\n         : '+' ==\
    \ c ? 0x3E\n         : '/' == c ? 0x3F\n                    : 0x40;\n}\ntemplate\
    \ <typename T>\nstring encode(vector<T> &a) {\n  T x = a[0], y = a[0];\n  for\
    \ (auto &z : a) x = max(x, z), y = min(y, z);\n  L N = a.size(),\n    B = max<L>(6,\
    \ y < 0 ? sizeof(T) * 8 : 64 - __builtin_clzll(x));\n  string S((B * N + 11) /\
    \ 6, 0);\n  S[0] = B;\n  for (int i = 0; i < N; i++) {\n    for (int j = 0; j\
    \ < B; j++) {\n      if ((a[i] >> j) & 1) S[(i * B + j) / 6 + 1] |= 1 << ((i *\
    \ B + j) % 6);\n    }\n  }\n  for (auto &c : S) c = base[(int)c];\n  return S;\n\
    }\nvector<L> decode(string S) {\n  for (auto &c : S) c = ibase(c);\n  L B = S[0],\
    \ M = S.size() - 1;\n  vector<L> a(6 * M / B, 0);\n  for (int i = 0; i < M; i++)\
    \ {\n    for (int j = 0; j < 6; j++) {\n      if ((S[i + 1] >> j) & 1) a[(i *\
    \ 6 + j) / B] |= 1LL << ((i * 6 + j) % B);\n    }\n  }\n  return a;\n}\n}  //\
    \ namespace Base64\n\n/**\n * @brief Base64 (\u30BD\u30FC\u30B9\u30B3\u30FC\u30C9\
    \u306B\u6570\u5217\u3092\u5727\u7E2E\u3057\u3066\u57CB\u3081\u8FBC\u3080\u7528\
    \u306E\u7B26\u53F7\u5316\u30FB\u5FA9\u53F7\u5316\u30E9\u30A4\u30D6\u30E9\u30EA\
    )\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/base64.hpp
  requiredBy: []
  timestamp: '2023-04-11 21:34:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-0502-base64.test.cpp
documentation_of: misc/base64.hpp
layout: document
redirect_from:
- /library/misc/base64.hpp
- /library/misc/base64.hpp.html
title: "Base64 (\u30BD\u30FC\u30B9\u30B3\u30FC\u30C9\u306B\u6570\u5217\u3092\u5727\
  \u7E2E\u3057\u3066\u57CB\u3081\u8FBC\u3080\u7528\u306E\u7B26\u53F7\u5316\u30FB\u5FA9\
  \u53F7\u5316\u30E9\u30A4\u30D6\u30E9\u30EA)"
---
