#pragma once
#include <bits/stdc++.h>
using namespace std;

template<typename T,typename F>
struct SegmentTree{

  int size;
  vector<T> seg;
  const F func;
  const T UNIT;
  
  SegmentTree(int N,F func , T UNIT): func(func) , UNIT(UNIT) {
    size = 1;
    while(size < N) size <<= 1;
    seg.assign(2 * size, UNIT);
  }

  SegmentTree(const vector<T> &v,F func , T UNIT) : func(func) , UNIT(UNIT){
    int N = (int)v.size();
    size = 1;
    while(size < N) size <<= 1;
    seg.assign(2 * size , UNIT);
    for(int i = 0; i < N; i++){
      seg[i + size] = v[i];
    }
    build();
  }

  void set(int k, T x){
    seg[k + size] = x;
  }

  void build(){
    for(int k = size-1; k > 0; k--){
      seg[k] = func(seg[2 * k] , seg[2 * k + 1] );
    }
  }
  
  void update(int k, T x){
    k += size; seg[k] = x;
    while(k >>= 1){
      seg[k] = func( seg[2 * k] , seg[2 * k + 1] );
    }
  }

  void add(int k , T x){
    k += size; seg[k] += x;
    while(k >>= 1){
      seg[k] = func(seg[2 * k] , seg[2 * k + 1] );
    }
  }
  
  // query to [a, b) 
  T query(int a, int b){
    T L = UNIT, R = UNIT;
    for(a+=size,b+=size; a<b; a>>=1,b>>=1){
      if(a & 1) L = func(L,seg[a++]);
      if(b & 1) R = func(seg[--b],R);
    }
    return func(L, R);
  }

  T& operator[](const int &k){
    return seg[k + size];
  }

};