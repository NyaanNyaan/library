---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ntt/multivariate-circular-convolution.hpp
    title: "\u591A\u5909\u6570\u5DE1\u56DE\u7573\u307F\u8FBC\u307F"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1783.test.cpp
    title: verify/verify-yuki/yuki-1783.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u591A\u6B21\u5143FFT"
    links: []
  bundledCode: "#line 2 \"ntt/multidimensional-ntt.hpp\"\n\n// f(vector<mint>& a,\
    \ bool rev) : 1 \u6B21\u5143 DFT (rev \u306F\u9006\u5909\u63DB\u304B\u3069\u3046\
    \u304B)\ntemplate <typename T>\nstruct MultidimensionalFourierTransform {\n  vector<int>\
    \ base;\n  function<void(vector<T>&, bool)> dft1d;\n\n  MultidimensionalFourierTransform(const\
    \ vector<int>& bs,\n                                   const function<void(vector<T>&,\
    \ bool)>& f)\n      : base(bs), dft1d(f) {}\n\n  bool ascend(vector<int>& v) {\n\
    \    int i = 0;\n    v[i] += 1;\n    while (v[i] == base[i]) {\n      if (i ==\
    \ (int)v.size() - 1) return false;\n      v[i] = 0;\n      v[++i] += 1;\n    }\n\
    \    return true;\n  }\n\n  int operator()(vector<int>& a) {\n    int res = a[0],\
    \ coeff = 1;\n    for (int i = 1; i < (int)a.size(); i++)\n      coeff *= base[i\
    \ - 1], res += coeff * a[i];\n    return res;\n  }\n\n  void inner(vector<T>&\
    \ a, int dim, bool rev = false) {\n    int i = 0, shift = 1, n = base[dim];\n\
    \    vector<T> f(n);\n    vector<int> id(base.size());\n    for (int j = 0; j\
    \ < dim; j++) shift *= base[j];\n    do {\n      if (id[dim] != 0) continue;\n\
    \      for (int j = 0, t = i; j < n; j++, t += shift) f[j] = a[t];\n      dft1d(f,\
    \ rev);\n      for (int j = 0, t = i; j < n; j++, t += shift) a[t] = f[j];\n \
    \     id[dim] = 0;\n    } while (++i && ascend(id));\n  }\n  void fft(vector<T>&\
    \ a, bool rev = false) {\n    if (!rev)\n      for (int i = 0; i < (int)base.size();\
    \ i++) inner(a, i);\n    else\n      for (int i = (int)base.size(); i--;) inner(a,\
    \ i, true);\n  }\n};\n\n/**\n * @brief \u591A\u6B21\u5143FFT\n */\n"
  code: "#pragma once\n\n// f(vector<mint>& a, bool rev) : 1 \u6B21\u5143 DFT (rev\
    \ \u306F\u9006\u5909\u63DB\u304B\u3069\u3046\u304B)\ntemplate <typename T>\nstruct\
    \ MultidimensionalFourierTransform {\n  vector<int> base;\n  function<void(vector<T>&,\
    \ bool)> dft1d;\n\n  MultidimensionalFourierTransform(const vector<int>& bs,\n\
    \                                   const function<void(vector<T>&, bool)>& f)\n\
    \      : base(bs), dft1d(f) {}\n\n  bool ascend(vector<int>& v) {\n    int i =\
    \ 0;\n    v[i] += 1;\n    while (v[i] == base[i]) {\n      if (i == (int)v.size()\
    \ - 1) return false;\n      v[i] = 0;\n      v[++i] += 1;\n    }\n    return true;\n\
    \  }\n\n  int operator()(vector<int>& a) {\n    int res = a[0], coeff = 1;\n \
    \   for (int i = 1; i < (int)a.size(); i++)\n      coeff *= base[i - 1], res +=\
    \ coeff * a[i];\n    return res;\n  }\n\n  void inner(vector<T>& a, int dim, bool\
    \ rev = false) {\n    int i = 0, shift = 1, n = base[dim];\n    vector<T> f(n);\n\
    \    vector<int> id(base.size());\n    for (int j = 0; j < dim; j++) shift *=\
    \ base[j];\n    do {\n      if (id[dim] != 0) continue;\n      for (int j = 0,\
    \ t = i; j < n; j++, t += shift) f[j] = a[t];\n      dft1d(f, rev);\n      for\
    \ (int j = 0, t = i; j < n; j++, t += shift) a[t] = f[j];\n      id[dim] = 0;\n\
    \    } while (++i && ascend(id));\n  }\n  void fft(vector<T>& a, bool rev = false)\
    \ {\n    if (!rev)\n      for (int i = 0; i < (int)base.size(); i++) inner(a,\
    \ i);\n    else\n      for (int i = (int)base.size(); i--;) inner(a, i, true);\n\
    \  }\n};\n\n/**\n * @brief \u591A\u6B21\u5143FFT\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: ntt/multidimensional-ntt.hpp
  requiredBy:
  - ntt/multivariate-circular-convolution.hpp
  timestamp: '2023-05-28 20:44:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
  - verify/verify-yuki/yuki-1783.test.cpp
documentation_of: ntt/multidimensional-ntt.hpp
layout: document
redirect_from:
- /library/ntt/multidimensional-ntt.hpp
- /library/ntt/multidimensional-ntt.hpp.html
title: "\u591A\u6B21\u5143FFT"
---
