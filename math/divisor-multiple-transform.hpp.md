---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://atcoder.jp/contests/abc020/submissions/7695313
    - https://atcoder.jp/contests/agc038/submissions/7683063
    - https://atcoder.jp/contests/arc064/submissions/7707249
    - https://onlinejudge.u-aizu.ac.jp/status/users/NyaanNyaan/submissions/1/NTL_1_D/judge/3892694/C++14
    - https://www.codechef.com/viewsolution/26767783
  bundledCode: "#line 2 \"math/divisor-multiple-transform.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct divisor_transform{\n  template <typename T>\n \
    \ static constexpr void zeta_transform(vector<T> &a){\n    int N = a.size() -\
    \ 1; \n    vector<int> sieve(N + 1, true);\n    for(int p = 2; p <= N; p++)\n\
    \      if(sieve[p])\n        for(int k = 1; k * p <= N; ++k)\n          sieve[k\
    \ * p] = false , a[k * p] += a[k];    \n  }\n\n  template<typename T>\n  static\
    \ constexpr void mobius_transform(T &a){\n    int N = a.size() - 1; \n    vector<int>\
    \ sieve(N + 1, true);\n    for(int p = 2; p <= N; p++)\n      if(sieve[p])\n \
    \       for(int k = N / p; k > 0; --k)\n          sieve[k * p] = false , a[k *\
    \ p] -= a[k];    \n  }\n  \n  // verify \n  // https://atcoder.jp/contests/arc064/submissions/7707249\n\
    \  template<typename T>\n  static constexpr void zeta_transform(map<long long,\
    \ T> &a){\n    for(auto &x : a) for(auto &y : a){\n      if(x == y) break;\n \
    \     if(x.first % y.first == 0) x.second += y.second;\n    }\n  }\n  template<typename\
    \ T>\n  static constexpr void mobius_transform(map<long long, T> &a){\n    for(auto\
    \ &x : a) for(auto &y : a){\n      if(x == y) break;\n      if(x.first % y.first\
    \ == 0) x.second -= y.second;\n    }\n  }\n\n};\n\n// verify\n// https://atcoder.jp/contests/agc038/submissions/7683063\n\
    // https://www.codechef.com/viewsolution/26767783\nstruct multiple_transform{\n\
    \  template <typename T>\n  static constexpr void zeta_transform(vector<T> &a){\n\
    \    int N = a.size() - 1;\n    vector<int> sieve(N + 1, true);\n    for(int p\
    \ = 2; p <= N; ++p)\n      if(sieve[p])\n        for(int k = N / p; k > 0; --k)\n\
    \          sieve[k * p] = false , a[k] += a[k * p];\n  }\n  template <typename\
    \ T>\n  static constexpr void mobius_transform(vector<T> &a){\n    int N = a.size()\
    \ - 1;\n    vector<int> sieve(N + 1, true);\n    for(int p = 2; p <= N; ++p)\n\
    \      if(sieve[p])\n        for(int k = 1; k * p <= N; ++k)\n          sieve[k\
    \ * p] = false , a[k] -= a[k * p];\n  }\n\n  template<typename T>\n  static constexpr\
    \ void zeta_transform(map<long long, T> &a){\n    for(auto it=a.rbegin(); it!=a.rend();\
    \ it++)\n      for(auto it2=a.rbegin(); it2!=it; it2++)\n        if(it2->first\
    \ % it->first == 0)\n          it->second += it2->second;\n  }\n  template<typename\
    \ T>\n  static constexpr void mobius_transform(map<long long, T> &a){\n    for(auto\
    \ it=a.rbegin(); it!=a.rend(); it++)\n      for(auto it2=a.rbegin(); it2!=it;\
    \ it2++)\n        if(it2->first % it->first == 0)\n          it->second -= it2->second;\n\
    \  }\n\n};\n\ntemplate<typename T>\nstatic constexpr vector<T> mobius_function(int\
    \ N){\n  vector<T> a(N + 1 , 0);\n  a[1] = 1;\n  divisor_transform::mobius_transform(a);\n\
    \  return a;\n}\n\ntemplate<int N>\nstruct constexpr_mobius_function{\n  int mobius[N\
    \ + 1] , sieve[N + 1];\n  constexpr constexpr_mobius_function(): mobius() , sieve(){\n\
    \    for(int i=1; i<=N; i++) sieve[i] = 1, mobius[i] = 0;\n    mobius[1] = 1;\n\
    \    for(int p = 2; p <= N; p++)\n      if(sieve[p])\n        for(int k = N /\
    \ p; k > 0; --k)\n          sieve[k * p] = false , mobius[k * p] -= mobius[k];\
    \    \n  }\n  const int& operator[](int i)const{return mobius[i];}\n};\n\n// N\
    \ = 1000000 , pnum = 78498\ntemplate<int N,int pnum> struct constexpr_prime{\n\
    \  int prime[pnum];\n  int sieve[N + 1];\n  constexpr_prime() : prime() , sieve()\
    \ {\n    for(int i=2;i<=N;i++) sieve[i]=1;\n    int idx = 0;\n    for(long long\
    \ p = 2; p <= N; p++){\n      if(sieve[p]){\n        prime[idx++] = p;\n     \
    \   for(long long j = p * p; j <= N; j += p) sieve[j] = 0;\n      }\n    }\n \
    \ }\n  const long long& operator[](long long i) const{return prime[i];}\n};\n\n\
    // verify\ntemplate<typename T,typename F>\nstatic constexpr unordered_map<long\
    \ long,T> divisor_zeta_transform(long long N, F f){\n  // factorization\n  unordered_map<long\
    \ long,long long> factors;\n  {\n    long long M = N;\n    for(long long i = 2;\
    \ i * i <= M; i++)\n      while(M % i == 0) factors[i]++ , M /= i;\n    if(M !=\
    \ 1) factors[M]++;\n  }\n  unordered_map<long long,T> ret;\n  ret.emplace(1 ,\
    \ 1);\n  for(auto &d : factors){\n    auto ret2 = ret;\n    T prev = 1;\n    for(long\
    \ long i = 1 , cur = d.first; \n      i <= d.second;\n      i++ , cur *= d.first){\n\
    \      T val = ( prev += f(cur) );\n      for(auto &x : ret) \n        ret2.emplace(x.first*cur\
    \ , x.second*val);\n    }\n    swap(ret , ret2);\n  }\n  return ret;\n}\n\n//\
    \ verify\n// https://onlinejudge.u-aizu.ac.jp/status/users/NyaanNyaan/submissions/1/NTL_1_D/judge/3892694/C++14\n\
    // https://atcoder.jp/contests/abc020/submissions/7695313\ntemplate<typename T,typename\
    \ F>\nstatic constexpr unordered_map<long long,T> divisor_mobius_transform(long\
    \ long N, F f){\n  // factorization\n  unordered_map<long long,long long> factors;\n\
    \  {\n    long long M = N;\n    for(long long i = 2; i * i <= M; i++)\n      while(M\
    \ % i == 0) factors[i]++ , M /= i;\n    if(M != 1) factors[M]++;\n  }\n  unordered_map<long\
    \ long,T> ret;\n  ret.emplace(1 , 1);\n  for(auto &d : factors){\n    auto ret2\
    \ = ret;\n    for(long long i = 1,cur = d.first , prev = 1; \n      i <= d.second;\
    \ \n      i++ , cur *= d.first , prev *= d.first){\n      T val = f(cur) - f(prev);\n\
    \      for(auto &x : ret) \n        ret2.emplace(x.first*cur , x.second*val);\n\
    \    }\n    swap(ret , ret2);\n  }\n  return ret;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct divisor_transform{\n\
    \  template <typename T>\n  static constexpr void zeta_transform(vector<T> &a){\n\
    \    int N = a.size() - 1; \n    vector<int> sieve(N + 1, true);\n    for(int\
    \ p = 2; p <= N; p++)\n      if(sieve[p])\n        for(int k = 1; k * p <= N;\
    \ ++k)\n          sieve[k * p] = false , a[k * p] += a[k];    \n  }\n\n  template<typename\
    \ T>\n  static constexpr void mobius_transform(T &a){\n    int N = a.size() -\
    \ 1; \n    vector<int> sieve(N + 1, true);\n    for(int p = 2; p <= N; p++)\n\
    \      if(sieve[p])\n        for(int k = N / p; k > 0; --k)\n          sieve[k\
    \ * p] = false , a[k * p] -= a[k];    \n  }\n  \n  // verify \n  // https://atcoder.jp/contests/arc064/submissions/7707249\n\
    \  template<typename T>\n  static constexpr void zeta_transform(map<long long,\
    \ T> &a){\n    for(auto &x : a) for(auto &y : a){\n      if(x == y) break;\n \
    \     if(x.first % y.first == 0) x.second += y.second;\n    }\n  }\n  template<typename\
    \ T>\n  static constexpr void mobius_transform(map<long long, T> &a){\n    for(auto\
    \ &x : a) for(auto &y : a){\n      if(x == y) break;\n      if(x.first % y.first\
    \ == 0) x.second -= y.second;\n    }\n  }\n\n};\n\n// verify\n// https://atcoder.jp/contests/agc038/submissions/7683063\n\
    // https://www.codechef.com/viewsolution/26767783\nstruct multiple_transform{\n\
    \  template <typename T>\n  static constexpr void zeta_transform(vector<T> &a){\n\
    \    int N = a.size() - 1;\n    vector<int> sieve(N + 1, true);\n    for(int p\
    \ = 2; p <= N; ++p)\n      if(sieve[p])\n        for(int k = N / p; k > 0; --k)\n\
    \          sieve[k * p] = false , a[k] += a[k * p];\n  }\n  template <typename\
    \ T>\n  static constexpr void mobius_transform(vector<T> &a){\n    int N = a.size()\
    \ - 1;\n    vector<int> sieve(N + 1, true);\n    for(int p = 2; p <= N; ++p)\n\
    \      if(sieve[p])\n        for(int k = 1; k * p <= N; ++k)\n          sieve[k\
    \ * p] = false , a[k] -= a[k * p];\n  }\n\n  template<typename T>\n  static constexpr\
    \ void zeta_transform(map<long long, T> &a){\n    for(auto it=a.rbegin(); it!=a.rend();\
    \ it++)\n      for(auto it2=a.rbegin(); it2!=it; it2++)\n        if(it2->first\
    \ % it->first == 0)\n          it->second += it2->second;\n  }\n  template<typename\
    \ T>\n  static constexpr void mobius_transform(map<long long, T> &a){\n    for(auto\
    \ it=a.rbegin(); it!=a.rend(); it++)\n      for(auto it2=a.rbegin(); it2!=it;\
    \ it2++)\n        if(it2->first % it->first == 0)\n          it->second -= it2->second;\n\
    \  }\n\n};\n\ntemplate<typename T>\nstatic constexpr vector<T> mobius_function(int\
    \ N){\n  vector<T> a(N + 1 , 0);\n  a[1] = 1;\n  divisor_transform::mobius_transform(a);\n\
    \  return a;\n}\n\ntemplate<int N>\nstruct constexpr_mobius_function{\n  int mobius[N\
    \ + 1] , sieve[N + 1];\n  constexpr constexpr_mobius_function(): mobius() , sieve(){\n\
    \    for(int i=1; i<=N; i++) sieve[i] = 1, mobius[i] = 0;\n    mobius[1] = 1;\n\
    \    for(int p = 2; p <= N; p++)\n      if(sieve[p])\n        for(int k = N /\
    \ p; k > 0; --k)\n          sieve[k * p] = false , mobius[k * p] -= mobius[k];\
    \    \n  }\n  const int& operator[](int i)const{return mobius[i];}\n};\n\n// N\
    \ = 1000000 , pnum = 78498\ntemplate<int N,int pnum> struct constexpr_prime{\n\
    \  int prime[pnum];\n  int sieve[N + 1];\n  constexpr_prime() : prime() , sieve()\
    \ {\n    for(int i=2;i<=N;i++) sieve[i]=1;\n    int idx = 0;\n    for(long long\
    \ p = 2; p <= N; p++){\n      if(sieve[p]){\n        prime[idx++] = p;\n     \
    \   for(long long j = p * p; j <= N; j += p) sieve[j] = 0;\n      }\n    }\n \
    \ }\n  const long long& operator[](long long i) const{return prime[i];}\n};\n\n\
    // verify\ntemplate<typename T,typename F>\nstatic constexpr unordered_map<long\
    \ long,T> divisor_zeta_transform(long long N, F f){\n  // factorization\n  unordered_map<long\
    \ long,long long> factors;\n  {\n    long long M = N;\n    for(long long i = 2;\
    \ i * i <= M; i++)\n      while(M % i == 0) factors[i]++ , M /= i;\n    if(M !=\
    \ 1) factors[M]++;\n  }\n  unordered_map<long long,T> ret;\n  ret.emplace(1 ,\
    \ 1);\n  for(auto &d : factors){\n    auto ret2 = ret;\n    T prev = 1;\n    for(long\
    \ long i = 1 , cur = d.first; \n      i <= d.second;\n      i++ , cur *= d.first){\n\
    \      T val = ( prev += f(cur) );\n      for(auto &x : ret) \n        ret2.emplace(x.first*cur\
    \ , x.second*val);\n    }\n    swap(ret , ret2);\n  }\n  return ret;\n}\n\n//\
    \ verify\n// https://onlinejudge.u-aizu.ac.jp/status/users/NyaanNyaan/submissions/1/NTL_1_D/judge/3892694/C++14\n\
    // https://atcoder.jp/contests/abc020/submissions/7695313\ntemplate<typename T,typename\
    \ F>\nstatic constexpr unordered_map<long long,T> divisor_mobius_transform(long\
    \ long N, F f){\n  // factorization\n  unordered_map<long long,long long> factors;\n\
    \  {\n    long long M = N;\n    for(long long i = 2; i * i <= M; i++)\n      while(M\
    \ % i == 0) factors[i]++ , M /= i;\n    if(M != 1) factors[M]++;\n  }\n  unordered_map<long\
    \ long,T> ret;\n  ret.emplace(1 , 1);\n  for(auto &d : factors){\n    auto ret2\
    \ = ret;\n    for(long long i = 1,cur = d.first , prev = 1; \n      i <= d.second;\
    \ \n      i++ , cur *= d.first , prev *= d.first){\n      T val = f(cur) - f(prev);\n\
    \      for(auto &x : ret) \n        ret2.emplace(x.first*cur , x.second*val);\n\
    \    }\n    swap(ret , ret2);\n  }\n  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/divisor-multiple-transform.hpp
  requiredBy: []
  timestamp: '2020-07-28 11:29:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisor-multiple-transform.hpp
layout: document
redirect_from:
- /library/math/divisor-multiple-transform.hpp
- /library/math/divisor-multiple-transform.hpp.html
title: math/divisor-multiple-transform.hpp
---
