#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include "../../competitive-template.hpp"
#include "../../prime/prime-sieve.hpp"

void solve() { 
  ini(N, A, B); 
  auto sieve = prime_sieve(N);
  vi ans;
  int cnt = 0;
  for(int i = 0, j = 0; i <= N; ++i){
    if(sieve[i]){
      if(j == B) ans.push_back(i);
      if(++j == A) j = 0;
      ++cnt;
    }
  }
  out(cnt, sz(ans));
  out(ans);
}
