#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

template<class T>
struct compress{
  vector<T> xs;
  compress(const vector<T>& v){
    xs.reserve(v.size());
    for(T x : v) xs.push_back(x);
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()) , xs.end());
  }

  int get(const T& x){
    return lower_bound(xs.begin(),xs.end(),x) - xs.begin();
  }
  int size(){
    return xs.size();
  }
  T& operator[](int i){
    return xs[i];
  }
};