#pragma once
#ifndef Nyaan_template
#include "../competitive-template.hpp"
#endif

struct divisor_transform{
  template <typename T>
  static constexpr void zeta_transform(vector<T> &a){
    int N = a.size() - 1; 
    vector<int> sieve(N + 1, true);
    for(int p = 2; p <= N; p++)
      if(sieve[p])
        for(int k = 1; k * p <= N; ++k)
          sieve[k * p] = false , a[k * p] += a[k];    
  }

  template<typename T>
  static constexpr void mobius_transform(T &a){
    int N = a.size() - 1; 
    vector<int> sieve(N + 1, true);
    for(int p = 2; p <= N; p++)
      if(sieve[p])
        for(int k = N / p; k > 0; --k)
          sieve[k * p] = false , a[k * p] -= a[k];    
  }
  
  // verify 
  // https://atcoder.jp/contests/arc064/submissions/7707249
  template<typename T>
  static constexpr void zeta_transform(map<long long, T> &a){
    for(auto &x : a) for(auto &y : a){
      if(x == y) break;
      if(x.first % y.first == 0) x.second += y.second;
    }
  }
  template<typename T>
  static constexpr void mobius_transform(map<long long, T> &a){
    for(auto &x : a) for(auto &y : a){
      if(x == y) break;
      if(x.first % y.first == 0) x.second -= y.second;
    }
  }

};

// verify
// https://atcoder.jp/contests/agc038/submissions/7683063
// https://www.codechef.com/viewsolution/26767783
struct multiple_transform{
  template <typename T>
  static constexpr void zeta_transform(vector<T> &a){
    int N = a.size() - 1;
    vector<int> sieve(N + 1, true);
    for(int p = 2; p <= N; ++p)
      if(sieve[p])
        for(int k = N / p; k > 0; --k)
          sieve[k * p] = false , a[k] += a[k * p];
  }
  template <typename T>
  static constexpr void mobius_transform(vector<T> &a){
    int N = a.size() - 1;
    vector<int> sieve(N + 1, true);
    for(int p = 2; p <= N; ++p)
      if(sieve[p])
        for(int k = 1; k * p <= N; ++k)
          sieve[k * p] = false , a[k] -= a[k * p];
  }

  template<typename T>
  static constexpr void zeta_transform(map<long long, T> &a){
    for(auto it=a.rbegin(); it!=a.rend(); it++)
      for(auto it2=a.rbegin(); it2!=it; it2++)
        if(it2->first % it->first == 0)
          it->second += it2->second;
  }
  template<typename T>
  static constexpr void mobius_transform(map<long long, T> &a){
    for(auto it=a.rbegin(); it!=a.rend(); it++)
      for(auto it2=a.rbegin(); it2!=it; it2++)
        if(it2->first % it->first == 0)
          it->second -= it2->second;
  }

};

template<typename T>
static constexpr vector<T> mobius_function(int N){
  vector<T> a(N + 1 , 0);
  a[1] = 1;
  divisor_transform::mobius_transform(a);
  return a;
}

template<int N>
struct constexpr_mobius_function{
  int mobius[N + 1] , sieve[N + 1];
  constexpr constexpr_mobius_function(): mobius() , sieve(){
    for(int i=1; i<=N; i++) sieve[i] = 1, mobius[i] = 0;
    mobius[1] = 1;
    for(int p = 2; p <= N; p++)
      if(sieve[p])
        for(int k = N / p; k > 0; --k)
          sieve[k * p] = false , mobius[k * p] -= mobius[k];    
  }
  const int& operator[](int i)const{return mobius[i];}
};

// N = 1000000 , pnum = 78498
template<int N,int pnum> struct constexpr_prime{
  int prime[pnum];
  int sieve[N + 1];
  constexpr_prime() : prime() , sieve() {
    for(int i=2;i<=N;i++) sieve[i]=1;
    int idx = 0;
    for(long long p = 2; p <= N; p++){
      if(sieve[p]){
        prime[idx++] = p;
        for(long long j = p * p; j <= N; j += p) sieve[j] = 0;
      }
    }
  }
  const long long& operator[](long long i) const{return prime[i];}
};

// verify
template<typename T,typename F>
static constexpr unordered_map<long long,T> divisor_zeta_transform(long long N, F f){
  // factorization
  unordered_map<long long,long long> factors;
  {
    long long M = N;
    for(long long i = 2; i * i <= M; i++)
      while(M % i == 0) factors[i]++ , M /= i;
    if(M != 1) factors[M]++;
  }
  unordered_map<long long,T> ret;
  ret.emplace(1 , 1);
  for(auto &d : factors){
    auto ret2 = ret;
    T prev = 1;
    for(long long i = 1 , cur = d.first; 
      i <= d.second;
      i++ , cur *= d.first){
      T val = ( prev += f(cur) );
      for(auto &x : ret) 
        ret2.emplace(x.first*cur , x.second*val);
    }
    swap(ret , ret2);
  }
  return ret;
}

// verify
// https://onlinejudge.u-aizu.ac.jp/status/users/NyaanNyaan/submissions/1/NTL_1_D/judge/3892694/C++14
// https://atcoder.jp/contests/abc020/submissions/7695313
template<typename T,typename F>
static constexpr unordered_map<long long,T> divisor_mobius_transform(long long N, F f){
  // factorization
  unordered_map<long long,long long> factors;
  {
    long long M = N;
    for(long long i = 2; i * i <= M; i++)
      while(M % i == 0) factors[i]++ , M /= i;
    if(M != 1) factors[M]++;
  }
  unordered_map<long long,T> ret;
  ret.emplace(1 , 1);
  for(auto &d : factors){
    auto ret2 = ret;
    for(long long i = 1,cur = d.first , prev = 1; 
      i <= d.second; 
      i++ , cur *= d.first , prev *= d.first){
      T val = f(cur) - f(prev);
      for(auto &x : ret) 
        ret2.emplace(x.first*cur , x.second*val);
    }
    swap(ret , ret2);
  }
  return ret;
}
