#include "../../template/template.hpp"
//
#include "../../misc/rng.hpp"
#include "../../orderedmap/orderedmap.hpp"
using namespace Nyaan;

void orderdmap_test() {
  OrderedMap<ll, ll> mp;
  vector<pl> vc;

  auto same_map = [&]() -> void {
    for (int i = 0; i < mp.size(); i++) {
      auto kth = mp.kth_element(i);
      assert(kth->key == vc[i].first && "same_map");
      assert(kth->val == vc[i].second && "same_map");
    }
  };

  rep(i, 5000) {
    ll key = rng() % 2048;
    ll val = rng() % 2048;
    {
      // size
      int s1 = mp.size();
      int s2 = vc.size();
      assert(s1 == s2 and "size");
      // lower_bound
      int l1 = mp.lower_bound(key);
      int l2 = lb(vc, pl(key, -inf));
      assert(l1 == l2 and "lower_bound");
      // upper_bound
      int u1 = mp.upper_bound(key);
      int u2 = ub(vc, pl(key, inf));
      assert(u1 == u2 and "upper_bound");
      // count
      int c1 = mp.count(key);
      assert(c1 == u1 - l1 and "count");
      // find
      auto f = mp.find(key);
      assert(!!f == c1 && "find");
      // kth-element
      if (l1 != s1) {
        auto kth = mp.kth_element(l1);
        assert(kth->key == vc[l1].first);
        assert(kth->val == vc[l1].second);
      }
    }

    // insert
    {
      mp[key] = val;
      int l = lb(vc, pl(key, -inf));
      if (l != sz(vc) and vc[l].first == key)
        vc[l].second = val;
      else
        vc.insert(begin(vc) + l, pl(key, val));
      same_map();
    }

    // erase(key)
    if (mp.size() != 0 and (rng() % 15) == 0) {
      int l = rng() % mp.size();
      mp.erase(vc[l].first);
      vc.erase(begin(vc) + l);
      same_map();
    }
    
    // erase(ptr)
    if (mp.size() != 0 and (rng() % 15) == 0) {
      int l = rng() % mp.size();
      mp.erase(mp.find(vc[l].first));
      vc.erase(begin(vc) + l);
      same_map();
    }
  }
}

void Nyaan::solve() { 
  orderdmap_test(); 
  ini(a,b);
  out(a+b);
}
