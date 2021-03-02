---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u591A\u6B21\u5143FFT"
    links: []
  bundledCode: "#line 2 \"ntt/multidimensional-ntt.hpp\"\n\ntemplate <typename T,\
    \ typename F>\nstruct MultidimensionalFourierTransform {\n  vector<int> base;\n\
    \  F dft1d;\n\n  MultidimensionalFourierTransform(const vector<int>& bs, const\
    \ F& f)\n      : base(bs), dft1d(f) {}\n\n  bool ascend(vector<int>& v) {\n  \
    \  int i = 0;\n    v[i] += 1;\n    while (v[i] == base[i]) {\n      if (i == (int)v.size()\
    \ - 1) return false;\n      v[i] = 0;\n      v[++i] += 1;\n    }\n    return true;\n\
    \  }\n\n  int operator()(vector<int>& a) {\n    int res = a[0], coeff = 1;\n \
    \   for (int i = 1; i < (int)a.size(); i++)\n      coeff *= base[i - 1], res +=\
    \ coeff * a[i];\n    return res;\n  }\n\n  void inner(vector<T>& a, int dim, bool\
    \ rev = false) {\n    vector<T> f(base[dim]);\n    vector<int> id(base[dim]);\n\
    \    int i = 0, shift = 1;\n    for (int j = 0; j < dim; j++) shift *= base[j];\n\
    \    do {\n      if (id[dim] != 0) continue;\n      for (int j = 0, t = i; j <\
    \ 7; j++, t += shift) f[j] = a[t];\n      dft1d(f, rev);\n      for (int j = 0,\
    \ t = i; j < 7; j++, t += shift) a[t] = f[j];\n      id[dim] = 0;\n    } while\
    \ (++i && ascend(id));\n  }\n\n  void fft(vector<T>& a, bool rev = false) {\n\
    \    if (!rev)\n      for (int i = 0; i < (int)base.size(); i++) inner(a, i);\n\
    \    else\n      for (int i = (int)base.size(); i--;) inner(a, i, true);\n  }\n\
    };\n\n/**\n * @brief \u591A\u6B21\u5143FFT\n */\n"
  code: "#pragma once\n\ntemplate <typename T, typename F>\nstruct MultidimensionalFourierTransform\
    \ {\n  vector<int> base;\n  F dft1d;\n\n  MultidimensionalFourierTransform(const\
    \ vector<int>& bs, const F& f)\n      : base(bs), dft1d(f) {}\n\n  bool ascend(vector<int>&\
    \ v) {\n    int i = 0;\n    v[i] += 1;\n    while (v[i] == base[i]) {\n      if\
    \ (i == (int)v.size() - 1) return false;\n      v[i] = 0;\n      v[++i] += 1;\n\
    \    }\n    return true;\n  }\n\n  int operator()(vector<int>& a) {\n    int res\
    \ = a[0], coeff = 1;\n    for (int i = 1; i < (int)a.size(); i++)\n      coeff\
    \ *= base[i - 1], res += coeff * a[i];\n    return res;\n  }\n\n  void inner(vector<T>&\
    \ a, int dim, bool rev = false) {\n    vector<T> f(base[dim]);\n    vector<int>\
    \ id(base[dim]);\n    int i = 0, shift = 1;\n    for (int j = 0; j < dim; j++)\
    \ shift *= base[j];\n    do {\n      if (id[dim] != 0) continue;\n      for (int\
    \ j = 0, t = i; j < 7; j++, t += shift) f[j] = a[t];\n      dft1d(f, rev);\n \
    \     for (int j = 0, t = i; j < 7; j++, t += shift) a[t] = f[j];\n      id[dim]\
    \ = 0;\n    } while (++i && ascend(id));\n  }\n\n  void fft(vector<T>& a, bool\
    \ rev = false) {\n    if (!rev)\n      for (int i = 0; i < (int)base.size(); i++)\
    \ inner(a, i);\n    else\n      for (int i = (int)base.size(); i--;) inner(a,\
    \ i, true);\n  }\n};\n\n/**\n * @brief \u591A\u6B21\u5143FFT\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: ntt/multidimensional-ntt.hpp
  requiredBy: []
  timestamp: '2021-03-03 00:28:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ntt/multidimensional-ntt.hpp
layout: document
redirect_from:
- /library/ntt/multidimensional-ntt.hpp
- /library/ntt/multidimensional-ntt.hpp.html
title: "\u591A\u6B21\u5143FFT"
---
