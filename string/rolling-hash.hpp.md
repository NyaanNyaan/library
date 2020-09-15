---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"string/rolling-hash.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// \u4F7F\u3044\u65B9\n// \u6587\u5B57\u5217\u306E\u30CF\u30C3\
    \u30B7\u30E5\u5217 Roriha s_rori(S);\n// \u914D\u5217\u306E\u30CF\u30C3\u30B7\u30E5\
    \u5217 RollingHash<vector<int>> vrori(v);\ntemplate<typename string_t> struct\
    \ RollingHash{\n  using ull = unsigned long long;\n  using Pu = pair<ull , ull>;\n\
    \  const string_t& data;\n  vector<Pu> hashed , power;\n  int size_;\n  static\
    \ Pu basis;\n  \n  static constexpr ull rmod = (1ull << 61) - 1;\n  \n  static\
    \ constexpr ull mul(const ull a,const ull b){\n    ull l1 = (uint32_t)a, h1 =\
    \ a>>32, l2 = (uint32_t)b, h2 = b>>32;\n    ull l = l1*l2, m = l1*h2 + l2*h1,\
    \ h = h1*h2;\n    ull ret = (l & rmod) + (l>>61) + (h << 3) + (m >> 29) + (m <<\
    \ 35 >> 3);\n    if(ret > rmod) ret = (ret & rmod) + (ret>>61);\n    if(ret >=\
    \ rmod) ret -= rmod;\n    return ret;\n  }\n  static constexpr ull mul_plus(const\
    \ ull a,const ull b,const ull c){\n    ull l1 = (uint32_t)a, h1 = a>>32, l2 =\
    \ (uint32_t)b, h2 = b>>32;\n    ull l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;\n\
    \    ull ret = (l & rmod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3)\
    \ + c;\n    if(ret > rmod) ret = (ret & rmod) + (ret>>61);\n    if(ret >= rmod)\
    \ ret -= rmod;\n    return ret;\n  }\n  static constexpr ull modpow(ull a,ull\
    \ b){\n    a %= rmod;\n    ull r = 1;\n    while(b) {\n      if(b & 1) r = mul(r\
    \ , a);\n      a = mul(a , a);\n      b >>= 1;\n    }\n    return r;\n  }\n  static\
    \ constexpr bool isPrimitive(ull x, vector<ull> &ds) {\n    for(ll d : ds)\n \
    \     if(d != rmod - 1) {\n        if(modpow( x, (rmod - 1) / d ) == 1) return\
    \ false;\n      }\n    return true;\n  }\n  static constexpr Pu get_basis(){\n\
    \    vector<ull> ds = {2,3,5,7,11,13,31,41,61,151,331,1321};\n    auto rand_time\
    \ = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
    \    mt19937_64 rng(rand_time);\n    ull a = -1 , b = -1;\n    do{ a = rng() %\
    \ rmod; }while(isPrimitive(a , ds) == false);\n    do{ b = rng() % rmod; }while(a\
    \ == b || isPrimitive(b , ds) == false);\n    return Pu(a , b);\n  }\n\n  // Rolling\
    \ Hash\u306E\u69CB\u7BC9\u3000O( |S| )\n  RollingHash(const string_t &S) : data(S)\
    \ , size_((int)S.size()){\n    // hashed[i] \u90E8\u5206\u5217[0 , i)\u306E\u30CF\
    \u30C3\u30B7\u30E5\u3092\u8A18\u9332 hashed[0] = (0,0)\n    // power[i] basis\u306E\
    i\u4E57\u3092\u8A18\u9332\n    hashed.resize(size_ + 1);\n    power.resize(size_\
    \ + 1);\n    power[0] = Pu(1 , 1); hashed[0] = Pu(0 , 0);\n    for(int i = 1 ;\
    \ i <= size_ ; i++ ){\n      power[i].fi = mul( power[i - 1].fi , basis.fi);\n\
    \      power[i].se = mul( power[i - 1].se , basis.se);\n      hashed[i].fi = mul_plus(\
    \ hashed[i - 1].fi , basis.fi , S[i - 1]);\n      hashed[i].se = mul_plus( hashed[i\
    \ - 1].se , basis.se , S[i - 1]);\n    }\n  }\n\n  // \u90E8\u5206\u6587\u5B57\
    \u5217[ l , r )\u306E\u30CF\u30C3\u30B7\u30E5\u3092\u53D6\u5F97 O(1)\n  Pu get(const\
    \ int l , const int r){\n    Pu ret;\n    ret.fi = rmod - mul_plus( hashed[l].fi\
    \ , power[r-l].fi , rmod - hashed[r].fi );\n    ret.se = rmod - mul_plus( hashed[l].se\
    \ , power[r-l].se , rmod - hashed[r].se );\n    return ret;\n  }\n\n  // \u5225\
    \u306E\u6587\u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\u3092\u53D6\u5F97\u3000\
    O( |T| )\n  Pu get_hash(string_t &T){\n    Pu ret = Pu(0 , 0);\n    for(int i\
    \ = 0 ; i < (int)T.size() ; i++){\n      ret.fi = mul_plus(ret.fi , basis.fi ,\
    \ T[i]);\n      ret.se = mul_plus(ret.se , basis.se , T[i]);\n    }\n    return\
    \ ret;\n  }\n\n  // \u5225\u306E\u6587\u5B57\u5217\u3068\u4E00\u81F4\u5224\u5B9A\
    \ O ( |S| + |T| )\n  // \u5B58\u5728\u3059\u308B\u3068\u304D\u306F\u6700\u521D\
    \u306E\u6587\u5B57\u3092\u3001\u5B58\u5728\u3057\u306A\u3044\u3068\u304D\u306F\
    -1\u3092\u8FD4\u3059\n  int find(string_t &T){\n    auto t_hash = get_hash(T);\n\
    \    int t_size = (int)(T.size());\n    // |S| < |T|\u306E\u6642\u306Ffor\u6587\
    \u306E\u4E2D\u306B\u5165\u3089\u306A\u3044\u3053\u3068\u306B\u7559\u610F\u3059\
    \u308B\n    for(int i = 0 ; i <= size_ - t_size ; i++){\n      if(t_hash == get(\
    \ i , i + t_size ) ) return i;\n    }\n    return -1;\n  }\n\n  // \u5225\u306E\
    \u6587\u5B57\u5217\u3068\u4E00\u81F4\u5224\u5B9A O ( |S| + |T| )\n  // \u4E00\u81F4\
    \u3059\u308B\u6587\u5B57\u5217\u306Eindex\u3092\u3059\u3079\u3066\u8FD4\u3059\n\
    \  vector<int> find_all(string_t &T){\n    auto t_hash = get_hash(T);\n    int\
    \ t_size = (int)(T.size());\n    vector<int> ret;\n    // |S| < |T|\u306E\u6642\
    \u306Ffor\u6587\u306E\u4E2D\u306B\u5165\u3089\u306A\u3044\u3053\u3068\u306B\u7559\
    \u610F\u3059\u308B\n    for(int i = 0 ; i <= size_ - t_size ; i++){\n      if(t_hash\
    \ == get( i , i + t_size ) ) ret.push_back(i);\n    }\n    return ret;\n  }\n\n\
    \  // Longest Common Prefix(\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E) O( log\
    \ |S| )\n  // S\u306E[al , ar)\u3068T\u306E[bl , br)\u306E\u6700\u9577\u5171\u901A\
    \u63A5\u982D\u8F9E\u306E\u9577\u3055\u3092\u6C42\u3081\u308B\n  // \u5F15\u6570\
    \ (\u6587\u5B57\u5217T\u306E\u30CF\u30C3\u30B7\u30E5\u5217 , \u6587\u5B57\u5217\
    S\u306E\u958B\u59CB\u5730\u70B9a , \u6587\u5B57\u5217T\u306E\u958B\u59CB\u5730\
    \u70B9b)\n  // \u8FD4\u308A\u5024\u3000\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\
    \u306E\u9577\u3055\n  int LongestCommonPrefix(RollingHash<string_t> &t , int al\
    \ , int bl , int ar = -1 , int br = -1){\n    if(ar == -1) ar = size_;\n    if(br\
    \ == -1) br = t.size_;\n    int ok = 0 , ng = min(ar - al , br - bl)  + 1;\n \
    \   while(ok + 1 < ng){\n      int med = (ok + ng) / 2;\n      if( get(al , med\
    \ + al) == t.get(bl , med + bl) ) ok = med;\n      else ng = med;\n    }\n   \
    \ return ok;\n  }\n\n  // \u6587\u5B57\u5217\u306E\u5927\u5C0F\u6BD4\u8F03 O(\
    \ log |S + T| )\u3000\n  // S\u306E[al , ar)\u3068T\u306E[bl , br)\u306E\u6700\
    \u9577\u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\u3092\u6C42\u3081\u308B\
    \n  // \u8FD4\u308A\u5024 1 S\u306E\u307B\u3046\u304C\u5927\u304D\u3044 0 \u540C\
    \u3058 -1 T\u306E\u307B\u3046\u304C\u5927\u304D\u3044\n  int strcmp(RollingHash<string_t>\
    \ &t , int al , int bl , int ar = -1 , int br = -1){\n    if(ar == -1) ar = size_;\n\
    \    if(br == -1) br = t.size_;\n    int n = LongestCommonPrefix(t , al , bl ,\
    \ ar , br);\n    if(al + n == ar)\n      return (bl + n == br) ? 0 : 1;\n    else\
    \ if(bl + n == br)\n      return -1;\n    else return ( data[al + n] < t.data[bl\
    \ + n] ) ? 1 : -1; \n  }\n  \n  // \u6587\u5B57\u5217\u5185\u306E\u6700\u9577\u4E00\
    \u81F4\u90E8\u5206\u6587\u5B57\u5217\u3092\u691C\u7D22 O ( |S| (log|S|)^2 )\n\
    \  int LongestCommonSubString(){\n    auto func = [&](int len) -> bool {\n   \
    \   map < Pu , int > m;\n      for(int i = 0 ; i <= size_ - len ; i++){\n    \
    \    if( (m[get(i , i + len)] += 1) != 1) return true;\n      }\n      return\
    \ false; \n    };\n    int ok = 0 , ng = size_ ;\n    while(ok + 1 < ng){\n  \
    \    int med = (ok + ng) / 2;\n      if(func(med)) ok = med;\n      else ng =\
    \ med;\n    }\n    return ok;\n  }\n\n};\n// \u30ED\u30EA\u30CF\u306E\u30CF\u30C3\
    \u30B7\u30E5\u306E\u521D\u671F\u5316\ntemplate<typename T> pair<unsigned long\
    \ long,unsigned long long> RollingHash<T>::basis = RollingHash<T>::get_basis();\n\
    using Roriha = RollingHash<string>;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// \u4F7F\
    \u3044\u65B9\n// \u6587\u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\u5217 Roriha\
    \ s_rori(S);\n// \u914D\u5217\u306E\u30CF\u30C3\u30B7\u30E5\u5217 RollingHash<vector<int>>\
    \ vrori(v);\ntemplate<typename string_t> struct RollingHash{\n  using ull = unsigned\
    \ long long;\n  using Pu = pair<ull , ull>;\n  const string_t& data;\n  vector<Pu>\
    \ hashed , power;\n  int size_;\n  static Pu basis;\n  \n  static constexpr ull\
    \ rmod = (1ull << 61) - 1;\n  \n  static constexpr ull mul(const ull a,const ull\
    \ b){\n    ull l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;\n \
    \   ull l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;\n    ull ret = (l & rmod) + (l>>61)\
    \ + (h << 3) + (m >> 29) + (m << 35 >> 3);\n    if(ret > rmod) ret = (ret & rmod)\
    \ + (ret>>61);\n    if(ret >= rmod) ret -= rmod;\n    return ret;\n  }\n  static\
    \ constexpr ull mul_plus(const ull a,const ull b,const ull c){\n    ull l1 = (uint32_t)a,\
    \ h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;\n    ull l = l1*l2, m = l1*h2 + l2*h1,\
    \ h = h1*h2;\n    ull ret = (l & rmod) + (l >> 61) + (h << 3) + (m >> 29) + (m\
    \ << 35 >> 3) + c;\n    if(ret > rmod) ret = (ret & rmod) + (ret>>61);\n    if(ret\
    \ >= rmod) ret -= rmod;\n    return ret;\n  }\n  static constexpr ull modpow(ull\
    \ a,ull b){\n    a %= rmod;\n    ull r = 1;\n    while(b) {\n      if(b & 1) r\
    \ = mul(r , a);\n      a = mul(a , a);\n      b >>= 1;\n    }\n    return r;\n\
    \  }\n  static constexpr bool isPrimitive(ull x, vector<ull> &ds) {\n    for(ll\
    \ d : ds)\n      if(d != rmod - 1) {\n        if(modpow( x, (rmod - 1) / d ) ==\
    \ 1) return false;\n      }\n    return true;\n  }\n  static constexpr Pu get_basis(){\n\
    \    vector<ull> ds = {2,3,5,7,11,13,31,41,61,151,331,1321};\n    auto rand_time\
    \ = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
    \    mt19937_64 rng(rand_time);\n    ull a = -1 , b = -1;\n    do{ a = rng() %\
    \ rmod; }while(isPrimitive(a , ds) == false);\n    do{ b = rng() % rmod; }while(a\
    \ == b || isPrimitive(b , ds) == false);\n    return Pu(a , b);\n  }\n\n  // Rolling\
    \ Hash\u306E\u69CB\u7BC9\u3000O( |S| )\n  RollingHash(const string_t &S) : data(S)\
    \ , size_((int)S.size()){\n    // hashed[i] \u90E8\u5206\u5217[0 , i)\u306E\u30CF\
    \u30C3\u30B7\u30E5\u3092\u8A18\u9332 hashed[0] = (0,0)\n    // power[i] basis\u306E\
    i\u4E57\u3092\u8A18\u9332\n    hashed.resize(size_ + 1);\n    power.resize(size_\
    \ + 1);\n    power[0] = Pu(1 , 1); hashed[0] = Pu(0 , 0);\n    for(int i = 1 ;\
    \ i <= size_ ; i++ ){\n      power[i].fi = mul( power[i - 1].fi , basis.fi);\n\
    \      power[i].se = mul( power[i - 1].se , basis.se);\n      hashed[i].fi = mul_plus(\
    \ hashed[i - 1].fi , basis.fi , S[i - 1]);\n      hashed[i].se = mul_plus( hashed[i\
    \ - 1].se , basis.se , S[i - 1]);\n    }\n  }\n\n  // \u90E8\u5206\u6587\u5B57\
    \u5217[ l , r )\u306E\u30CF\u30C3\u30B7\u30E5\u3092\u53D6\u5F97 O(1)\n  Pu get(const\
    \ int l , const int r){\n    Pu ret;\n    ret.fi = rmod - mul_plus( hashed[l].fi\
    \ , power[r-l].fi , rmod - hashed[r].fi );\n    ret.se = rmod - mul_plus( hashed[l].se\
    \ , power[r-l].se , rmod - hashed[r].se );\n    return ret;\n  }\n\n  // \u5225\
    \u306E\u6587\u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\u3092\u53D6\u5F97\u3000\
    O( |T| )\n  Pu get_hash(string_t &T){\n    Pu ret = Pu(0 , 0);\n    for(int i\
    \ = 0 ; i < (int)T.size() ; i++){\n      ret.fi = mul_plus(ret.fi , basis.fi ,\
    \ T[i]);\n      ret.se = mul_plus(ret.se , basis.se , T[i]);\n    }\n    return\
    \ ret;\n  }\n\n  // \u5225\u306E\u6587\u5B57\u5217\u3068\u4E00\u81F4\u5224\u5B9A\
    \ O ( |S| + |T| )\n  // \u5B58\u5728\u3059\u308B\u3068\u304D\u306F\u6700\u521D\
    \u306E\u6587\u5B57\u3092\u3001\u5B58\u5728\u3057\u306A\u3044\u3068\u304D\u306F\
    -1\u3092\u8FD4\u3059\n  int find(string_t &T){\n    auto t_hash = get_hash(T);\n\
    \    int t_size = (int)(T.size());\n    // |S| < |T|\u306E\u6642\u306Ffor\u6587\
    \u306E\u4E2D\u306B\u5165\u3089\u306A\u3044\u3053\u3068\u306B\u7559\u610F\u3059\
    \u308B\n    for(int i = 0 ; i <= size_ - t_size ; i++){\n      if(t_hash == get(\
    \ i , i + t_size ) ) return i;\n    }\n    return -1;\n  }\n\n  // \u5225\u306E\
    \u6587\u5B57\u5217\u3068\u4E00\u81F4\u5224\u5B9A O ( |S| + |T| )\n  // \u4E00\u81F4\
    \u3059\u308B\u6587\u5B57\u5217\u306Eindex\u3092\u3059\u3079\u3066\u8FD4\u3059\n\
    \  vector<int> find_all(string_t &T){\n    auto t_hash = get_hash(T);\n    int\
    \ t_size = (int)(T.size());\n    vector<int> ret;\n    // |S| < |T|\u306E\u6642\
    \u306Ffor\u6587\u306E\u4E2D\u306B\u5165\u3089\u306A\u3044\u3053\u3068\u306B\u7559\
    \u610F\u3059\u308B\n    for(int i = 0 ; i <= size_ - t_size ; i++){\n      if(t_hash\
    \ == get( i , i + t_size ) ) ret.push_back(i);\n    }\n    return ret;\n  }\n\n\
    \  // Longest Common Prefix(\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E) O( log\
    \ |S| )\n  // S\u306E[al , ar)\u3068T\u306E[bl , br)\u306E\u6700\u9577\u5171\u901A\
    \u63A5\u982D\u8F9E\u306E\u9577\u3055\u3092\u6C42\u3081\u308B\n  // \u5F15\u6570\
    \ (\u6587\u5B57\u5217T\u306E\u30CF\u30C3\u30B7\u30E5\u5217 , \u6587\u5B57\u5217\
    S\u306E\u958B\u59CB\u5730\u70B9a , \u6587\u5B57\u5217T\u306E\u958B\u59CB\u5730\
    \u70B9b)\n  // \u8FD4\u308A\u5024\u3000\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\
    \u306E\u9577\u3055\n  int LongestCommonPrefix(RollingHash<string_t> &t , int al\
    \ , int bl , int ar = -1 , int br = -1){\n    if(ar == -1) ar = size_;\n    if(br\
    \ == -1) br = t.size_;\n    int ok = 0 , ng = min(ar - al , br - bl)  + 1;\n \
    \   while(ok + 1 < ng){\n      int med = (ok + ng) / 2;\n      if( get(al , med\
    \ + al) == t.get(bl , med + bl) ) ok = med;\n      else ng = med;\n    }\n   \
    \ return ok;\n  }\n\n  // \u6587\u5B57\u5217\u306E\u5927\u5C0F\u6BD4\u8F03 O(\
    \ log |S + T| )\u3000\n  // S\u306E[al , ar)\u3068T\u306E[bl , br)\u306E\u6700\
    \u9577\u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\u3092\u6C42\u3081\u308B\
    \n  // \u8FD4\u308A\u5024 1 S\u306E\u307B\u3046\u304C\u5927\u304D\u3044 0 \u540C\
    \u3058 -1 T\u306E\u307B\u3046\u304C\u5927\u304D\u3044\n  int strcmp(RollingHash<string_t>\
    \ &t , int al , int bl , int ar = -1 , int br = -1){\n    if(ar == -1) ar = size_;\n\
    \    if(br == -1) br = t.size_;\n    int n = LongestCommonPrefix(t , al , bl ,\
    \ ar , br);\n    if(al + n == ar)\n      return (bl + n == br) ? 0 : 1;\n    else\
    \ if(bl + n == br)\n      return -1;\n    else return ( data[al + n] < t.data[bl\
    \ + n] ) ? 1 : -1; \n  }\n  \n  // \u6587\u5B57\u5217\u5185\u306E\u6700\u9577\u4E00\
    \u81F4\u90E8\u5206\u6587\u5B57\u5217\u3092\u691C\u7D22 O ( |S| (log|S|)^2 )\n\
    \  int LongestCommonSubString(){\n    auto func = [&](int len) -> bool {\n   \
    \   map < Pu , int > m;\n      for(int i = 0 ; i <= size_ - len ; i++){\n    \
    \    if( (m[get(i , i + len)] += 1) != 1) return true;\n      }\n      return\
    \ false; \n    };\n    int ok = 0 , ng = size_ ;\n    while(ok + 1 < ng){\n  \
    \    int med = (ok + ng) / 2;\n      if(func(med)) ok = med;\n      else ng =\
    \ med;\n    }\n    return ok;\n  }\n\n};\n// \u30ED\u30EA\u30CF\u306E\u30CF\u30C3\
    \u30B7\u30E5\u306E\u521D\u671F\u5316\ntemplate<typename T> pair<unsigned long\
    \ long,unsigned long long> RollingHash<T>::basis = RollingHash<T>::get_basis();\n\
    using Roriha = RollingHash<string>;"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling-hash.hpp
  requiredBy: []
  timestamp: '2020-08-16 16:29:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling-hash.hpp
layout: document
redirect_from:
- /library/string/rolling-hash.hpp
- /library/string/rolling-hash.hpp.html
title: string/rolling-hash.hpp
---
