---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"simple_template.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <chrono>\n#include <cstring>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <string>\n#include <utility>\n#include <vector>\n\
    using namespace std;\nstruct IoSetupNya {\n  IoSetupNya() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(15);\n  \
    \  cerr << fixed << setprecision(7);\n  }\n} iosetupnya;\nconstexpr long long\
    \ TEN(int n) { return n ? TEN(n - 1) * 10 : 1; }\n\n#define rep(i, n) for (int\
    \ i = 0; i < (int)(n); i++)\nusing ll = long long;\nusing vl = vector<ll>;\nusing\
    \ pl = pair<ll, ll>;\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <chrono>\n#include <cstring>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <map>\n\
    #include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n#include\
    \ <string>\n#include <utility>\n#include <vector>\nusing namespace std;\nstruct\
    \ IoSetupNya {\n  IoSetupNya() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(15);\n    cerr << fixed << setprecision(7);\n\
    \  }\n} iosetupnya;\nconstexpr long long TEN(int n) { return n ? TEN(n - 1) *\
    \ 10 : 1; }\n\n#define rep(i, n) for (int i = 0; i < (int)(n); i++)\nusing ll\
    \ = long long;\nusing vl = vector<ll>;\nusing pl = pair<ll, ll>;\n"
  dependsOn: []
  isVerificationFile: false
  path: simple_template.hpp
  requiredBy: []
  timestamp: '2022-08-22 19:21:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: simple_template.hpp
layout: document
redirect_from:
- /library/simple_template.hpp
- /library/simple_template.hpp.html
title: simple_template.hpp
---
