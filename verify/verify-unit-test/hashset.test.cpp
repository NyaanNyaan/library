#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../hashmap/hashset.hpp"

uint64_t rng() {
  static uint64_t x_ = 10150724397891781847ULL;
  return x_ ^= (x_ << 7), x_ ^= (x_ >> 9);
}
// [l, r)
int64_t randint(int64_t l, int64_t r) {
  assert(l < r);
  return l + rng() % (r - l);
}

namespace HashSetTest {

template <typename HS, typename Data_t>
void same_set(HS& hs, set<Data_t>& us, int mx) {
  assert(mx > 0);
  // iterator
  {
    set<Data_t> buf;
    for (auto& x : hs) buf.insert(x);
    assert(buf == us && "The range-based for statement");
  }
  // itr::operator++(), itr::operator++(int)
  {
    set<Data_t> buf;
    for (auto it = hs.begin(); it != hs.end();) {
      buf.insert(*it);

      auto oit = it;
      assert(oit == it++ && "itr::operator++(int)");
      ++oit;
      assert(oit == it && "itr::operator++()");
    }
    assert(buf == us && "itr::operator++()");
  }

  // itr::operator--(), itr::operator--(int)
  {
    set<Data_t> buf;
    for (auto it = hs.end(); it != hs.begin();) {
      auto oit = it;
      assert(oit == it-- && "itr::operator--(int)");
      --oit;
      assert(oit == it && "itr::operator--()");

      buf.insert(*it);
    }
    assert(buf == us && "itr::operator--()");
  }

  // begin(*this), end(*this)
  assert(begin(hs) == hs.begin() && "begin(*this)");
  assert(end(hs) == hs.end() && "end(*this)");

  // ensure empty space in hash table
  {
    uint32_t s = 0;
    for (uint32_t i = 0; i < hs.cap; ++i) s += hs.occupied_flag[i];
    assert(s != hs.cap && "hash table is full!");
  }

  // find, contain
  if constexpr (is_integral<Data_t>::value) {
    for (Data_t k = 0; k < mx; ++k) {
      auto flg1 = hs.find(k) != hs.end();
      auto flg2 = us.find(k) != us.end();
      auto flg3 = hs.contain(k);
      assert(flg1 == flg2 && "find(k)");
      assert(flg1 == flg3 && "contain(k)");
    }
  } else {
    for (int t = 0; t < 2 * mx; ++t) {
      Data_t k{rng() % mx, rng() % mx};
      auto flg1 = hs.find(k) != hs.end();
      auto flg2 = us.find(k) != us.end();
      auto flg3 = hs.contain(k);
      assert(flg1 == flg2 && "find(k)");
      assert(flg1 == flg3 && "contain(k)");
    }
  }

  // empty
  assert(hs.empty() == us.empty() && "empty()");
  // size
  assert(hs.size() == (int)us.size() && "size()");
}

#include <cxxabi.h>
string get_name(const type_info& id) {
  int stat;
  char* name = abi::__cxa_demangle(id.name(), 0, 0, &stat);
  assert(name != NULL && stat == 0);
  string res = string(name);
  free(name);
  return res;
}

template <typename T>
void stress_test(int mx, int loop_time) {
  cerr << "type : " << get_name(typeid(T)) << ", ";
  cerr << "loop : " << loop_time << ", ";
  cerr << "max : " << mx << endl;
  HashSet<T> hs;
  set<T> us;
  vector<T> ord;
  if constexpr (is_integral<T>::value) {
    ord.resize(mx);
    iota(begin(ord), end(ord), mx);
  } else {
    set<T> s;
    while ((int)s.size() < mx) s.insert(T{rng() % mx, rng() % mx});
    for (auto& x : s) ord.push_back(x);
  }

  mt19937_64 mt(rng());

  // insert, erase
  for (int _ = 0; _ < loop_time; _++) {
    shuffle(begin(ord), end(ord), mt);
    for (auto& i : ord) {
      hs.insert(i);
      us.insert(i);
      same_set<HashSet<T>, T>(hs, us, mx);
      same_set<const HashSet<T>, T>(hs, us, mx);
    }
    assert(hs.size() == mx && "insert(k)");
    shuffle(begin(ord), end(ord), mt);
    for (auto& i : ord) {
      hs.erase(i);
      us.erase(i);
      same_set<HashSet<T>, T>(hs, us, mx);
      same_set<const HashSet<T>, T>(hs, us, mx);
    }
    assert(hs.size() == 0 && "erase(k)");
  }

  // insert, erase
  for (int _ = 0; _ < 20; _++) {
    double ratio = rng() * pow(2, -64);
    for (int t = 0; t < loop_time / 5 * mx; t++) {
      T i{};
      if constexpr (is_integral<T>::value) {
        i = rng() % mx;
      } else {
        i = T{rng() % mx, rng() % mx};
      }
      double th = rng() * pow(2, -64);
      if (th < ratio) {
        // if constexpr (is_integral<T>::value)  cerr<<"insert "<<i<<endl;
        hs.insert(i);
        us.insert(i);
        same_set<HashSet<T>, T>(hs, us, mx);
        same_set<const HashSet<T>, T>(hs, us, mx);
      } else {
        // if constexpr (is_integral<T>::value) cerr<<"erase "<<i<<endl;
        hs.erase(i);
        us.erase(i);
        same_set<HashSet<T>, T>(hs, us, mx);
        same_set<const HashSet<T>, T>(hs, us, mx);
      }
    }
  }
  hs.clear();
  us.clear();

  // clear
  for (int _ = 0; _ < loop_time; _++) {
    shuffle(begin(ord), end(ord), mt);
    for (auto& i : ord) {
      hs.insert(i);
      us.insert(i);
    }
    same_set<HashSet<T>, T>(hs, us, mx);
    same_set<const HashSet<T>, T>(hs, us, mx);
    assert(hs.size() == mx && "clear()");
    hs.clear();
    us.clear();
    same_set<HashSet<T>, T>(hs, us, mx);
    same_set<const HashSet<T>, T>(hs, us, mx);
    assert(hs.size() == 0 && "clear()");
  }

  // reserve
  for (int _ = 0; _ < loop_time; _++) {
    hs.reserve(mx);
    uint32_t pcap = hs.cap;
    shuffle(begin(ord), end(ord), mt);
    for (auto& i : ord) {
      hs.insert(i);
      us.insert(i);
    }
    same_set<HashSet<T>, T>(hs, us, mx);
    same_set<const HashSet<T>, T>(hs, us, mx);
    assert(hs.size() == mx && "reserve()");
    assert(hs.cap == pcap && "reserve()");
    hs.clear();
    us.clear();
    same_set<HashSet<T>, T>(hs, us, mx);
    same_set<const HashSet<T>, T>(hs, us, mx);
    assert(hs.size() == 0 && "reserve()");
  }
}

template <typename T>
void unit_test() {
  stress_test<T>(1, 1000);
  stress_test<T>(2, 1000);
  stress_test<T>(4, 1000);
  stress_test<T>(8, 1000);
  stress_test<T>(16, 100);
  stress_test<T>(64, 10);
  stress_test<T>(256, 5);
}

}  // namespace HashSetTest

void Nyaan::solve() {
  HashSetTest::unit_test<int>();
  HashSetTest::unit_test<int64_t>();
  HashSetTest::unit_test<pair<int, int>>();
  int64_t a, b;
  cin >> a >> b;
  cout << (a + b) << endl;
}
