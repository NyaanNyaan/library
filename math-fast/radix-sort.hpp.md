---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/radix-sort.test.cpp
    title: verify/verify-unit-test/radix-sort.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: radix sort
    links: []
  bundledCode: "#line 2 \"math-fast/radix-sort.hpp\"\n\n#include <algorithm>\n#include\
    \ <limits>\n#include <utility>\nusing namespace std;\n\nnamespace RadixSortImpl\
    \ {\nconstexpr int b = 8;\nconstexpr int powb = 1 << b;\nconstexpr int mask =\
    \ powb - 1;\n\nint cnt0[powb];\nint cnt1[powb];\nint cnt2[powb];\nint cnt3[powb];\n\
    \ntemplate <typename T>\nvoid radix_sort(int N, T* p) {\n  static_assert(sizeof(T)\
    \ == 4 or sizeof(T) == 8);\n  if (!N) return;\n  if (N <= 64) {\n    sort(p, p\
    \ + N);\n    return;\n  }\n  static T* tmp = nullptr;\n  static int tmp_size =\
    \ 0;\n  if (!tmp or tmp_size < N) {\n    if (tmp) delete[] tmp;\n    tmp_size\
    \ = 1;\n    while (tmp_size < N) tmp_size *= 2;\n    tmp = new T[tmp_size];\n\
    \  }\n\n  memset(cnt0, 0, sizeof(cnt0));\n  memset(cnt1, 0, sizeof(cnt1));\n \
    \ memset(cnt2, 0, sizeof(cnt2));\n  memset(cnt3, 0, sizeof(cnt3));\n  for (int\
    \ i = 0; i < N; i++) {\n    cnt0[p[i] & mask]++;\n    cnt1[(p[i] >> b) & mask]++;\n\
    \    cnt2[(p[i] >> b * 2) & mask]++;\n    cnt3[(p[i] >> b * 3) & mask]++;\n  }\n\
    \  for (int i = 0; i < powb - 1; i++) {\n    cnt0[i + 1] += cnt0[i];\n    cnt1[i\
    \ + 1] += cnt1[i];\n    cnt2[i + 1] += cnt2[i];\n    cnt3[i + 1] += cnt3[i];\n\
    \  }\n  for (int i = N; i--;) tmp[--cnt0[p[i] & mask]] = p[i];\n  for (int i =\
    \ N; i--;) p[--cnt1[tmp[i] >> b & mask]] = tmp[i];\n  for (int i = N; i--;) tmp[--cnt2[p[i]\
    \ >> b * 2 & mask]] = p[i];\n  for (int i = N; i--;) p[--cnt3[tmp[i] >> b * 3\
    \ & mask]] = tmp[i];\n\n  if constexpr (sizeof(T) == 8) {\n    memset(cnt0, 0,\
    \ sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[p[i] >> b * 4 & mask]++;\n\
    \    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n    for (int\
    \ i = N; i--;) tmp[--cnt0[p[i] >> b * 4 & mask]] = p[i];\n    memset(cnt0, 0,\
    \ sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[tmp[i] >> b * 5 & mask]++;\n\
    \    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n    for (int\
    \ i = N; i--;) p[--cnt0[tmp[i] >> b * 5 & mask]] = tmp[i];\n    memset(cnt0, 0,\
    \ sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[p[i] >> b * 6 & mask]++;\n\
    \    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n    for (int\
    \ i = N; i--;) tmp[--cnt0[p[i] >> b * 6 & mask]] = p[i];\n    memset(cnt0, 0,\
    \ sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[tmp[i] >> b * 7 & mask]++;\n\
    \    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n    for (int\
    \ i = N; i--;) p[--cnt0[tmp[i] >> b * 7 & mask]] = tmp[i];\n  }\n  if constexpr\
    \ (is_signed<T>::value) {\n    int i = N;\n    while (i and p[i - 1] < 0) i--;\n\
    \    rotate(p, p + i, p + N);\n  }\n}\n\n// N 10^7 int :  90 ms\n// N 10^7 ll\
    \  : 220 ms\ntemplate <typename T>\nvoid radix_sort(vector<T>& v) {\n  radix_sort(v.size(),\
    \ v.data());\n}\n\n// first \u306E\u9806\u306B\u30BD\u30FC\u30C8, second \u306F\
    \u4E0D\u554F\ntemplate <typename T, typename U>\nvoid radix_sort_compare_first(int\
    \ N, pair<T, U>* p) {\n  static_assert(sizeof(T) == 4 or sizeof(T) == 8);\n\n\
    \  if (!N) return;\n  if (N <= 64) {\n    stable_sort(p, p + N, [](const pair<T,\
    \ U>& s, const pair<T, U>& t) {\n      return s.first < t.first;\n    });\n  \
    \  return;\n  }\n  static pair<T, U>* tmp = nullptr;\n  static int tmp_size =\
    \ 0;\n  if (!tmp or tmp_size < N) {\n    if (tmp) delete[] tmp;\n    tmp_size\
    \ = 1;\n    while (tmp_size < N) tmp_size *= 2;\n    tmp = new pair<T, U>[tmp_size];\n\
    \  }\n\n  memset(cnt0, 0, sizeof(cnt0));\n  for (int i = 0; i < N; i++) cnt0[p[i].first\
    \ & mask]++;\n  for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n \
    \ for (int i = N; i--;) tmp[--cnt0[p[i].first & mask]] = p[i];\n  memset(cnt0,\
    \ 0, sizeof(cnt0));\n  for (int i = 0; i < N; i++) cnt0[tmp[i].first >> b & mask]++;\n\
    \  for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n  for (int i =\
    \ N; i--;) p[--cnt0[tmp[i].first >> b & mask]] = tmp[i];\n  memset(cnt0, 0, sizeof(cnt0));\n\
    \  for (int i = 0; i < N; i++) cnt0[p[i].first >> b * 2 & mask]++;\n  for (int\
    \ i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n  for (int i = N; i--;) tmp[--cnt0[p[i].first\
    \ >> b * 2 & mask]] = p[i];\n  memset(cnt0, 0, sizeof(cnt0));\n  for (int i =\
    \ 0; i < N; i++) cnt0[tmp[i].first >> b * 3 & mask]++;\n  for (int i = 0; i <\
    \ powb - 1; i++) cnt0[i + 1] += cnt0[i];\n  for (int i = N; i--;) p[--cnt0[tmp[i].first\
    \ >> b * 3 & mask]] = tmp[i];\n\n  if constexpr (sizeof(T) == 8) {\n    memset(cnt0,\
    \ 0, sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[p[i].first >> b * 4\
    \ & mask]++;\n    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n\
    \    for (int i = N; i--;) tmp[--cnt0[p[i].first >> b * 4 & mask]] = p[i];\n \
    \   memset(cnt0, 0, sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[tmp[i].first\
    \ >> b * 5 & mask]++;\n    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n\
    \    for (int i = N; i--;) p[--cnt0[tmp[i].first >> b * 5 & mask]] = tmp[i];\n\
    \    memset(cnt0, 0, sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[p[i].first\
    \ >> b * 6 & mask]++;\n    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n\
    \    for (int i = N; i--;) tmp[--cnt0[p[i].first >> b * 6 & mask]] = p[i];\n \
    \   memset(cnt0, 0, sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[tmp[i].first\
    \ >> b * 7 & mask]++;\n    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n\
    \    for (int i = N; i--;) p[--cnt0[tmp[i].first >> b * 7 & mask]] = tmp[i];\n\
    \  }\n\n  if constexpr (is_signed<T>::value) {\n    int i = N;\n    while (i and\
    \ p[i - 1].first < 0) i--;\n    rotate(p, p + i, p + N);\n  }\n}\n\n// first \u306E\
    \u9806\u306B\u30BD\u30FC\u30C8, second \u306F\u4E0D\u554F\n// N 10^7 int : 130\
    \ ms\n// N 10^7 ll  : 370 ms\ntemplate <typename T, typename U>\nvoid radix_sort_compare_first(vector<pair<T,\
    \ U>>& v) {\n  radix_sort_compare_first(v.size(), v.data());\n}\n\n}  // namespace\
    \ RadixSortImpl\n\nusing RadixSortImpl::radix_sort;\nusing RadixSortImpl::radix_sort_compare_first;\n\
    \n/*\n  @brief radix sort\n*/\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <limits>\n#include <utility>\n\
    using namespace std;\n\nnamespace RadixSortImpl {\nconstexpr int b = 8;\nconstexpr\
    \ int powb = 1 << b;\nconstexpr int mask = powb - 1;\n\nint cnt0[powb];\nint cnt1[powb];\n\
    int cnt2[powb];\nint cnt3[powb];\n\ntemplate <typename T>\nvoid radix_sort(int\
    \ N, T* p) {\n  static_assert(sizeof(T) == 4 or sizeof(T) == 8);\n  if (!N) return;\n\
    \  if (N <= 64) {\n    sort(p, p + N);\n    return;\n  }\n  static T* tmp = nullptr;\n\
    \  static int tmp_size = 0;\n  if (!tmp or tmp_size < N) {\n    if (tmp) delete[]\
    \ tmp;\n    tmp_size = 1;\n    while (tmp_size < N) tmp_size *= 2;\n    tmp =\
    \ new T[tmp_size];\n  }\n\n  memset(cnt0, 0, sizeof(cnt0));\n  memset(cnt1, 0,\
    \ sizeof(cnt1));\n  memset(cnt2, 0, sizeof(cnt2));\n  memset(cnt3, 0, sizeof(cnt3));\n\
    \  for (int i = 0; i < N; i++) {\n    cnt0[p[i] & mask]++;\n    cnt1[(p[i] >>\
    \ b) & mask]++;\n    cnt2[(p[i] >> b * 2) & mask]++;\n    cnt3[(p[i] >> b * 3)\
    \ & mask]++;\n  }\n  for (int i = 0; i < powb - 1; i++) {\n    cnt0[i + 1] +=\
    \ cnt0[i];\n    cnt1[i + 1] += cnt1[i];\n    cnt2[i + 1] += cnt2[i];\n    cnt3[i\
    \ + 1] += cnt3[i];\n  }\n  for (int i = N; i--;) tmp[--cnt0[p[i] & mask]] = p[i];\n\
    \  for (int i = N; i--;) p[--cnt1[tmp[i] >> b & mask]] = tmp[i];\n  for (int i\
    \ = N; i--;) tmp[--cnt2[p[i] >> b * 2 & mask]] = p[i];\n  for (int i = N; i--;)\
    \ p[--cnt3[tmp[i] >> b * 3 & mask]] = tmp[i];\n\n  if constexpr (sizeof(T) ==\
    \ 8) {\n    memset(cnt0, 0, sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[p[i]\
    \ >> b * 4 & mask]++;\n    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n\
    \    for (int i = N; i--;) tmp[--cnt0[p[i] >> b * 4 & mask]] = p[i];\n    memset(cnt0,\
    \ 0, sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[tmp[i] >> b * 5 & mask]++;\n\
    \    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n    for (int\
    \ i = N; i--;) p[--cnt0[tmp[i] >> b * 5 & mask]] = tmp[i];\n    memset(cnt0, 0,\
    \ sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[p[i] >> b * 6 & mask]++;\n\
    \    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n    for (int\
    \ i = N; i--;) tmp[--cnt0[p[i] >> b * 6 & mask]] = p[i];\n    memset(cnt0, 0,\
    \ sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[tmp[i] >> b * 7 & mask]++;\n\
    \    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n    for (int\
    \ i = N; i--;) p[--cnt0[tmp[i] >> b * 7 & mask]] = tmp[i];\n  }\n  if constexpr\
    \ (is_signed<T>::value) {\n    int i = N;\n    while (i and p[i - 1] < 0) i--;\n\
    \    rotate(p, p + i, p + N);\n  }\n}\n\n// N 10^7 int :  90 ms\n// N 10^7 ll\
    \  : 220 ms\ntemplate <typename T>\nvoid radix_sort(vector<T>& v) {\n  radix_sort(v.size(),\
    \ v.data());\n}\n\n// first \u306E\u9806\u306B\u30BD\u30FC\u30C8, second \u306F\
    \u4E0D\u554F\ntemplate <typename T, typename U>\nvoid radix_sort_compare_first(int\
    \ N, pair<T, U>* p) {\n  static_assert(sizeof(T) == 4 or sizeof(T) == 8);\n\n\
    \  if (!N) return;\n  if (N <= 64) {\n    stable_sort(p, p + N, [](const pair<T,\
    \ U>& s, const pair<T, U>& t) {\n      return s.first < t.first;\n    });\n  \
    \  return;\n  }\n  static pair<T, U>* tmp = nullptr;\n  static int tmp_size =\
    \ 0;\n  if (!tmp or tmp_size < N) {\n    if (tmp) delete[] tmp;\n    tmp_size\
    \ = 1;\n    while (tmp_size < N) tmp_size *= 2;\n    tmp = new pair<T, U>[tmp_size];\n\
    \  }\n\n  memset(cnt0, 0, sizeof(cnt0));\n  for (int i = 0; i < N; i++) cnt0[p[i].first\
    \ & mask]++;\n  for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n \
    \ for (int i = N; i--;) tmp[--cnt0[p[i].first & mask]] = p[i];\n  memset(cnt0,\
    \ 0, sizeof(cnt0));\n  for (int i = 0; i < N; i++) cnt0[tmp[i].first >> b & mask]++;\n\
    \  for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n  for (int i =\
    \ N; i--;) p[--cnt0[tmp[i].first >> b & mask]] = tmp[i];\n  memset(cnt0, 0, sizeof(cnt0));\n\
    \  for (int i = 0; i < N; i++) cnt0[p[i].first >> b * 2 & mask]++;\n  for (int\
    \ i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n  for (int i = N; i--;) tmp[--cnt0[p[i].first\
    \ >> b * 2 & mask]] = p[i];\n  memset(cnt0, 0, sizeof(cnt0));\n  for (int i =\
    \ 0; i < N; i++) cnt0[tmp[i].first >> b * 3 & mask]++;\n  for (int i = 0; i <\
    \ powb - 1; i++) cnt0[i + 1] += cnt0[i];\n  for (int i = N; i--;) p[--cnt0[tmp[i].first\
    \ >> b * 3 & mask]] = tmp[i];\n\n  if constexpr (sizeof(T) == 8) {\n    memset(cnt0,\
    \ 0, sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[p[i].first >> b * 4\
    \ & mask]++;\n    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n\
    \    for (int i = N; i--;) tmp[--cnt0[p[i].first >> b * 4 & mask]] = p[i];\n \
    \   memset(cnt0, 0, sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[tmp[i].first\
    \ >> b * 5 & mask]++;\n    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n\
    \    for (int i = N; i--;) p[--cnt0[tmp[i].first >> b * 5 & mask]] = tmp[i];\n\
    \    memset(cnt0, 0, sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[p[i].first\
    \ >> b * 6 & mask]++;\n    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n\
    \    for (int i = N; i--;) tmp[--cnt0[p[i].first >> b * 6 & mask]] = p[i];\n \
    \   memset(cnt0, 0, sizeof(cnt0));\n    for (int i = 0; i < N; i++) cnt0[tmp[i].first\
    \ >> b * 7 & mask]++;\n    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];\n\
    \    for (int i = N; i--;) p[--cnt0[tmp[i].first >> b * 7 & mask]] = tmp[i];\n\
    \  }\n\n  if constexpr (is_signed<T>::value) {\n    int i = N;\n    while (i and\
    \ p[i - 1].first < 0) i--;\n    rotate(p, p + i, p + N);\n  }\n}\n\n// first \u306E\
    \u9806\u306B\u30BD\u30FC\u30C8, second \u306F\u4E0D\u554F\n// N 10^7 int : 130\
    \ ms\n// N 10^7 ll  : 370 ms\ntemplate <typename T, typename U>\nvoid radix_sort_compare_first(vector<pair<T,\
    \ U>>& v) {\n  radix_sort_compare_first(v.size(), v.data());\n}\n\n}  // namespace\
    \ RadixSortImpl\n\nusing RadixSortImpl::radix_sort;\nusing RadixSortImpl::radix_sort_compare_first;\n\
    \n/*\n  @brief radix sort\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: math-fast/radix-sort.hpp
  requiredBy: []
  timestamp: '2023-03-24 20:50:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/radix-sort.test.cpp
documentation_of: math-fast/radix-sort.hpp
layout: document
redirect_from:
- /library/math-fast/radix-sort.hpp
- /library/math-fast/radix-sort.hpp.html
title: radix sort
---
