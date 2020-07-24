#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

// T : data type
// A : vector array
// F : function
// UNIT : UNIT
template<typename T, typename A, typename F, T UNIT>
struct Slide{
  vector<T> dat;
  Slide(A &v , int N , int K , F f){
    dat.resize(N + 1);
    dat[0] = UNIT;
    deque<int> q;
    for(int i = 0; i < K - 1; i++){
      while(!q.empty() && ( f(v[i] , v[q.back()]) == v[i] ) )
        q.pop_back();
      q.push_back(i);
      dat[i + 1] = v[q.front()];
    }
    for(int i = K; i < N + 1; i++){
      T cur = v[i - 1];
      while(!q.empty() && ( f(cur , v[q.back()]) == cur) ) 
        q.pop_back();
      q.push_back(i - 1);
      dat[i] = v[q.front()];
      if(q.front() == i - K) q.pop_front();
    }
  }
};