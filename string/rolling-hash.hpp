#pragma once
#include <bits/stdc++.h>
using namespace std;

// 使い方
// 文字列のハッシュ列 Roriha s_rori(S);
// 配列のハッシュ列 RollingHash<vector<int>> vrori(v);
template<typename string_t> struct RollingHash{
  using ull = unsigned long long;
  using Pu = pair<ull , ull>;
  string_t& data;
  vector<Pu> hashed , power;
  int size_;
  static Pu basis;
  
  static constexpr ull rmod = (1ull << 61) - 1;
  
  static constexpr ull mul(const ull a,const ull b){
    ull l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;
    ull l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
    ull ret = (l & rmod) + (l>>61) + (h << 3) + (m >> 29) + (m << 35 >> 3);
    if(ret > rmod) ret = (ret & rmod) + (ret>>61);
    if(ret >= rmod) ret -= rmod;
    return ret;
  }
  static constexpr ull mul_plus(const ull a,const ull b,const ull c){
    ull l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;
    ull l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
    ull ret = (l & rmod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + c;
    if(ret > rmod) ret = (ret & rmod) + (ret>>61);
    if(ret >= rmod) ret -= rmod;
    return ret;
  }
  static constexpr ull modpow(ull a,ull b){
    a %= rmod;
    ull r = 1;
    while(b) {
      if(b & 1) r = mul(r , a);
      a = mul(a , a);
      b >>= 1;
    }
    return r;
  }
  static constexpr bool isPrimitive(ull x, vector<ull> &ds) {
    for(ll d : ds)
      if(d != rmod - 1) {
        if(modpow( x, (rmod - 1) / d ) == 1) return false;
      }
    return true;
  }
  static constexpr Pu get_basis(){
    vector<ull> ds = {2,3,5,7,11,13,31,41,61,151,331,1321};
    auto rand_time = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
    mt19937_64 rng(rand_time);
    ull a = -1 , b = -1;
    do{ a = rng() % rmod; }while(isPrimitive(a , ds) == false);
    do{ b = rng() % rmod; }while(a == b || isPrimitive(b , ds) == false);
    return Pu(a , b);
  }

  // Rolling Hashの構築　O( |S| )
  RollingHash(string_t &S) : data(S) , size_((int)S.size()){
    // hashed[i] 部分列[0 , i)のハッシュを記録 hashed[0] = (0,0)
    // power[i] basisのi乗を記録
    hashed.resize(size_ + 1);
    power.resize(size_ + 1);
    power[0] = Pu(1 , 1); hashed[0] = Pu(0 , 0);
    for(int i = 1 ; i <= size_ ; i++ ){
      power[i].fi = mul( power[i - 1].fi , basis.fi);
      power[i].se = mul( power[i - 1].se , basis.se);
      hashed[i].fi = mul_plus( hashed[i - 1].fi , basis.fi , S[i - 1]);
      hashed[i].se = mul_plus( hashed[i - 1].se , basis.se , S[i - 1]);
    }
  }

  // 部分文字列[ l , r )のハッシュを取得 O(1)
  Pu get(const int l , const int r){
    Pu ret;
    ret.fi = rmod - mul_plus( hashed[l].fi , power[r-l].fi , rmod - hashed[r].fi );
    ret.se = rmod - mul_plus( hashed[l].se , power[r-l].se , rmod - hashed[r].se );
    return ret;
  }

  // 別の文字列のハッシュを取得　O( |T| )
  Pu get_hash(string_t &T){
    Pu ret = Pu(0 , 0);
    for(int i = 0 ; i < (int)T.size() ; i++){
      ret.fi = mul_plus(ret.fi , basis.fi , T[i]);
      ret.se = mul_plus(ret.se , basis.se , T[i]);
    }
    return ret;
  }

  // 別の文字列と一致判定 O ( |S| + |T| )
  // 存在するときは最初の文字を、存在しないときは-1を返す
  int find(string_t &T){
    auto t_hash = get_hash(T);
    int t_size = (int)(T.size());
    // |S| < |T|の時はfor文の中に入らないことに留意する
    for(int i = 0 ; i <= size_ - t_size ; i++){
      if(t_hash == get( i , i + t_size ) ) return i;
    }
    return -1;
  }

  // 別の文字列と一致判定 O ( |S| + |T| )
  // 一致する文字列のindexをすべて返す
  vector<int> find_all(string_t &T){
    auto t_hash = get_hash(T);
    int t_size = (int)(T.size());
    vector<int> ret;
    // |S| < |T|の時はfor文の中に入らないことに留意する
    for(int i = 0 ; i <= size_ - t_size ; i++){
      if(t_hash == get( i , i + t_size ) ) ret.push_back(i);
    }
    return ret;
  }

  // Longest Common Prefix(最長共通接頭辞) O( log |S| )
  // Sの[al , ar)とTの[bl , br)の最長共通接頭辞の長さを求める
  // 引数 (文字列Tのハッシュ列 , 文字列Sの開始地点a , 文字列Tの開始地点b)
  // 返り値　最長共通接頭辞の長さ
  int LongestCommonPrefix(RollingHash<string_t> &t , int al , int bl , int ar = -1 , int br = -1){
    if(ar == -1) ar = size_;
    if(br == -1) br = t.size_;
    int ok = 0 , ng = min(ar - al , br - bl)  + 1;
    while(ok + 1 < ng){
      int med = (ok + ng) / 2;
      if( get(al , med + al) == t.get(bl , med + bl) ) ok = med;
      else ng = med;
    }
    return ok;
  }

  // 文字列の大小比較 O( log |S + T| )　
  // Sの[al , ar)とTの[bl , br)の最長共通接頭辞の長さを求める
  // 返り値 1 Sのほうが大きい 0 同じ -1 Tのほうが大きい
  int strcmp(RollingHash<string_t> &t , int al , int bl , int ar = -1 , int br = -1){
    if(ar == -1) ar = size_;
    if(br == -1) br = t.size_;
    int n = LongestCommonPrefix(t , al , bl , ar , br);
    if(al + n == ar)
      return (bl + n == br) ? 0 : 1;
    else if(bl + n == br)
      return -1;
    else return ( data[al + n] < t.data[bl + n] ) ? 1 : -1; 
  }
  
  // 文字列内の最長一致部分文字列を検索 O ( |S| (log|S|)^2 )
  int LongestCommonSubString(){
    auto func = [&](int len) -> bool {
      map < Pu , int > m;
      for(int i = 0 ; i <= size_ - len ; i++){
        if( (m[get(i , i + len)] += 1) != 1) return true;
      }
      return false; 
    };
    int ok = 0 , ng = size_ ;
    while(ok + 1 < ng){
      int med = (ok + ng) / 2;
      if(func(med)) ok = med;
      else ng = med;
    }
    return ok;
  }

};
// ロリハのハッシュの初期化
template<typename T> pair<unsigned long long,unsigned long long> RollingHash<T>::basis = RollingHash<T>::get_basis();
using Roriha = RollingHash<string>;