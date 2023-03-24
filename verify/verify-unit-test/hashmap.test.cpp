#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../hashmap/hashmap.hpp"

namespace HashMapTest {

uint64_t rng() {
  static uint64_t x_ =
      chrono::duration_cast<chrono::nanoseconds>(
          chrono::high_resolution_clock::now().time_since_epoch())
          .count();
  return x_ ^= (x_ << 7), x_ ^= (x_ >> 9);
}
// [l, r)
int64_t randint(int64_t l, int64_t r) {
  assert(l < r);
  return l + rng() % (r - l);
}

template <typename K, enable_if_t<is_integral<K>::value, nullptr_t> = nullptr>
K random_key(int mx) {
  return K{K(randint(0, mx))};
}
template <typename K, enable_if_t<is_integral<decltype(K::first)>::value,
                                  nullptr_t> = nullptr>
K random_key(int mx) {
  return K{decltype(K::first)(randint(0, mx)),
           decltype(K::second)(randint(0, mx))};
}

template <typename HM, typename M, typename K>
void same_map(HM& hm, M& m, int mx) {
  // iterator
  {
    M buf;
    for (auto& x : hm) buf[x.first] = x.second;
    assert(buf == m);
  }

  // ensure empty space in hash table
  {
    uint32_t s = 0;
    for (uint32_t i = 0; i < hm.cap; ++i) s += hm.occupied_flag[i];
    assert(s != hm.cap && "hash table is full!");
  }

  // find
  {
    for (int i = 0; i < 2 * mx; i++) {
      K k = random_key<K>(mx);
      auto flg1 = hm.find(k) != hm.end();
      auto flg2 = m.find(k) != m.end();
      auto flg3 = hm.contain(k);
      assert(flg1 == flg2 && "find(k)");
      assert(flg1 == flg3 && "contain(k)");
    }
  }

  // empty
  assert(hm.empty() == m.empty() && "empty()");
  // size
  assert(hm.size() == (int)m.size() && "size()");
}

template <typename Key, typename Val>
void stress_test(int mx, int loop_time) {
  using HM = HashMap<Key, Val>;
  using M = map<Key, Val>;

  HM hm;
  M m;

  // insert [], erase(key)
  for (int loop = 0; loop < loop_time; loop++) {
    vector<Key> key;
    vector<Val> val;
    for (int i = mx; i--;) {
      key.push_back(random_key<Key>(mx));
      val.push_back(random_key<Val>(mx));
    }
    for (int i = 0; i < mx; i++) {
      hm[key[i]] = val[i];
      m[key[i]] = val[i];
      same_map<HM, M, Key>(hm, m, mx);
      same_map<const HM, M, Key>(hm, m, mx);
    }
    assert(hm.size() == int(m.size()));
    for (int i = 0; i < mx; i++) {
      hm.erase(key[i]);
      m.erase(key[i]);
      same_map<HM, M, Key>(hm, m, mx);
      same_map<const HM, M, Key>(hm, m, mx);
    }
    assert(hm.size() == int(m.size()));
    assert(hm.empty() == true);
  }

  // insert(Data), erase(it)
  for (int loop = 0; loop < loop_time; loop++) {
    vector<Key> key;
    vector<Val> val;
    for (int i = mx; i--;) {
      key.push_back(random_key<Key>(mx));
      val.push_back(random_key<Val>(mx));
    }
    for (int i = 0; i < mx; i++) {
      hm.emplace(key[i], val[i]);
      m.emplace(key[i], val[i]);
      same_map<HM, M, Key>(hm, m, mx);
      same_map<const HM, M, Key>(hm, m, mx);
    }
    assert(hm.size() == int(m.size()));
    for (int i = 0; i < mx; i++) {
      hm.erase(key[i]);
      m.erase(key[i]);
      same_map<HM, M, Key>(hm, m, mx);
      same_map<const HM, M, Key>(hm, m, mx);
    }
    assert(hm.size() == int(m.size()));
    assert(hm.empty() == true);
  }
  {
    vector<Key> key;
    vector<Val> val;
    for (int i = mx; i--;) {
      key.push_back(random_key<Key>(mx));
      val.push_back(random_key<Val>(mx));
    }
    for (int i = 0; i < mx; i++) {
      hm.emplace(key[i], val[i]);
      m.emplace(key[i], val[i]);
      same_map<HM, M, Key>(hm, m, mx);
      same_map<const HM, M, Key>(hm, m, mx);
    }
    // clear
    hm.clear();
    m.clear();
    same_map<HM, M, Key>(hm, m, mx);
    same_map<const HM, M, Key>(hm, m, mx);
    assert(hm.size() == int(m.size()));
    assert(hm.empty() == true);

    // reverse
    hm.reserve(mx);
    uint32_t cap = hm.cap;
    for (int i = 0; i < mx; i++) {
      hm.emplace(key[i], val[i]);
      m.emplace(key[i], val[i]);
      same_map<HM, M, Key>(hm, m, mx);
      same_map<const HM, M, Key>(hm, m, mx);
    }
    assert(hm.cap == cap);
  }
}

template <typename Key, typename Val = int>
void test() {
  stress_test<Key, Val>(1, 100);
  stress_test<Key, Val>(2, 100);
  stress_test<Key, Val>(4, 100);
  stress_test<Key, Val>(8, 100);
  stress_test<Key, Val>(16, 100);
  stress_test<Key, Val>(32, 10);
  stress_test<Key, Val>(64, 10);
  stress_test<Key, Val>(128, 3);
  stress_test<Key, Val>(256, 3);
}

}  // namespace HashMapTest

void Nyaan::solve() {
  HashMapTest::test<int, int>();
  HashMapTest::test<long long, int>();
  HashMapTest::test<pair<int, int>, int>();
  HashMapTest::test<pair<long long, int>, int>();
  HashMapTest::test<pair<int, long long>, int>();
  HashMapTest::test<pair<long long, long long>, int>();

  int64_t a, b;
  cin >> a >> b;
  cout << (a + b) << endl;
}
