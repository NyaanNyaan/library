---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/fixpoint.hpp\"\n\n\n\ntemplate< typename F >\nstruct\
    \ FixPoint : F {\n  FixPoint(F &&f) : F(forward< F >(f)) {}\n \n  template< typename...\
    \ Args >\n  decltype(auto) operator()(Args &&... args) const {\n    return F::operator()(*this,\
    \ forward< Args >(args)...);\n  }\n};\n \ntemplate< typename F >\ninline decltype(auto)\
    \ MFP(F &&f) {\n  return FixPoint< F >{forward< F >(f)};\n}\n"
  code: "#pragma once\n\n\n\ntemplate< typename F >\nstruct FixPoint : F {\n  FixPoint(F\
    \ &&f) : F(forward< F >(f)) {}\n \n  template< typename... Args >\n  decltype(auto)\
    \ operator()(Args &&... args) const {\n    return F::operator()(*this, forward<\
    \ Args >(args)...);\n  }\n};\n \ntemplate< typename F >\ninline decltype(auto)\
    \ MFP(F &&f) {\n  return FixPoint< F >{forward< F >(f)};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/fixpoint.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/fixpoint.hpp
layout: document
redirect_from:
- /library/misc/fixpoint.hpp
- /library/misc/fixpoint.hpp.html
title: misc/fixpoint.hpp
---
