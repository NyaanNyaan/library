---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-1130-DG-bfs.test.cpp
    title: verify/verify-aoj-other/aoj-1130-DG-bfs.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-2945-01bfs.test.cpp
    title: verify/verify-aoj-other/aoj-2945-01bfs.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-2945-DG-01bfs.test.cpp
    title: verify/verify-aoj-other/aoj-2945-DG-01bfs.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/debug.test.cpp
    title: verify/verify-unit-test/debug.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
    title: verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
    title: verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0697.test.cpp
    title: verify/verify-yuki/yuki-0697.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1283.test.cpp
    title: verify/verify-yuki/yuki-1283.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/inout.hpp\"\nnamespace Nyaan {\n\ntemplate <typename\
    \ T, typename U>\nostream &operator<<(ostream &os, const pair<T, U> &p) {\n  os\
    \ << p.first << \" \" << p.second;\n  return os;\n}\ntemplate <typename T, typename\
    \ U>\nistream &operator>>(istream &is, pair<T, U> &p) {\n  is >> p.first >> p.second;\n\
    \  return is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const\
    \ vector<T> &v) {\n  int s = (int)v.size();\n  for (int i = 0; i < s; i++) os\
    \ << (i ? \" \" : \"\") << v[i];\n  return os;\n}\ntemplate <typename T>\nistream\
    \ &operator>>(istream &is, vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return\
    \ is;\n}\n\nvoid in() {}\ntemplate <typename T, class... U>\nvoid in(T &t, U &...\
    \ u) {\n  cin >> t;\n  in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\ntemplate\
    \ <typename T, class... U, char sep = ' '>\nvoid out(const T &t, const U &...\
    \ u) {\n  cout << t;\n  if (sizeof...(u)) cout << sep;\n  out(u...);\n}\n\nvoid\
    \ outr() {}\ntemplate <typename T, class... U, char sep = ' '>\nvoid outr(const\
    \ T &t, const U &... u) {\n  cout << t;\n  outr(u...);\n}\n\nstruct IoSetupNya\
    \ {\n  IoSetupNya() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(15);\n    cerr << fixed << setprecision(7);\n\
    \  }\n} iosetupnya;\n\n}  // namespace Nyaan\n"
  code: "namespace Nyaan {\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n  os << p.first << \" \" << p.second;\n  return\
    \ os;\n}\ntemplate <typename T, typename U>\nistream &operator>>(istream &is,\
    \ pair<T, U> &p) {\n  is >> p.first >> p.second;\n  return is;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n  int\
    \ s = (int)v.size();\n  for (int i = 0; i < s; i++) os << (i ? \" \" : \"\") <<\
    \ v[i];\n  return os;\n}\ntemplate <typename T>\nistream &operator>>(istream &is,\
    \ vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return is;\n}\n\nvoid in()\
    \ {}\ntemplate <typename T, class... U>\nvoid in(T &t, U &... u) {\n  cin >> t;\n\
    \  in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename T, class...\
    \ U, char sep = ' '>\nvoid out(const T &t, const U &... u) {\n  cout << t;\n \
    \ if (sizeof...(u)) cout << sep;\n  out(u...);\n}\n\nvoid outr() {}\ntemplate\
    \ <typename T, class... U, char sep = ' '>\nvoid outr(const T &t, const U &...\
    \ u) {\n  cout << t;\n  outr(u...);\n}\n\nstruct IoSetupNya {\n  IoSetupNya()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(15);\n    cerr << fixed << setprecision(7);\n  }\n} iosetupnya;\n\
    \n}  // namespace Nyaan\n"
  dependsOn: []
  isVerificationFile: false
  path: template/inout.hpp
  requiredBy:
  - template/template.hpp
  timestamp: '2020-11-30 18:57:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-other/aoj-2945-DG-01bfs.test.cpp
  - verify/verify-aoj-other/aoj-1130-DG-bfs.test.cpp
  - verify/verify-aoj-other/aoj-2945-01bfs.test.cpp
  - verify/verify-unit-test/debug.test.cpp
  - verify/verify-yuki/yuki-1283.test.cpp
  - verify/verify-yuki/yuki-0697.test.cpp
  - verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  - verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
documentation_of: template/inout.hpp
layout: document
redirect_from:
- /library/template/inout.hpp
- /library/template/inout.hpp.html
title: template/inout.hpp
---
