#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
//
#include "../../template/template.hpp"
//
#include "../../hashmap/hashmap-unerasable.hpp"
using namespace Nyaan;

void q() {
  UnerasableHashMap<ll, ll> mp;
  UnerasableHashMap<ll, ll, true> mp2(0, TEN(6));
  UnerasableHashMap<i128, ll> mp3;
  UnerasableHashMap<u128, ll> mp4;

  ini(Q);
  while (Q--) {
    ini(cmd);
    if (cmd == 0) {
      inl(k, v);
      mp[k] = mp2[k] = mp3[k] = mp4[k] = v;
    } else {
      inl(k);
      ll a1 = mp[k];
      ll a2 = mp2[k];
      ll a3 = mp3[k];
      ll a4 = mp4[k];
      assert(a1 == a2 and a2 == a3 and a3 == a4);
      out(a1);
    }
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
