#pragma once

#include <cstdint>
using namespace std;

namespace HashMapImpl {
using u32 = uint32_t;
using u64 = uint64_t;

template <typename Key, typename Data>
struct HashMapBase;

template <typename Key, typename Data>
struct itrB
    : iterator<bidirectional_iterator_tag, Data, ptrdiff_t, Data*, Data&> {
  using base =
      iterator<bidirectional_iterator_tag, Data, ptrdiff_t, Data*, Data&>;
  using ptr = typename base::pointer;
  using ref = typename base::reference;

  u32 i;
  HashMapBase<Key, Data>* p;

  explicit constexpr itrB() : i(0), p(nullptr) {}
  explicit constexpr itrB(u32 _i, HashMapBase<Key, Data>* _p) : i(_i), p(_p) {}
  explicit constexpr itrB(u32 _i, const HashMapBase<Key, Data>* _p)
      : i(_i), p(const_cast<HashMapBase<Key, Data>*>(_p)) {}
  friend void swap(itrB& l, itrB& r) { swap(l.i, r.i), swap(l.p, r.p); }
  friend bool operator==(const itrB& l, const itrB& r) { return l.i == r.i; }
  friend bool operator!=(const itrB& l, const itrB& r) { return l.i != r.i; }
  const ref operator*() const {
    return const_cast<const HashMapBase<Key, Data>*>(p)->data[i];
  }
  ref operator*() { return p->data[i]; }
  ptr operator->() const { return &(p->data[i]); }

  itrB& operator++() {
    assert(i != p->cap && "itr::operator++()");
    do {
      i++;
      if (i == p->cap) break;
      if (p->occupied_flag[i] && !p->deleted_flag[i]) break;
    } while (true);
    return (*this);
  }
  itrB operator++(int) {
    itrB it(*this);
    ++(*this);
    return it;
  }
  itrB& operator--() {
    do {
      i--;
      if (p->occupied_flag[i] && !p->deleted_flag[i]) break;
      assert(i != 0 && "itr::operator--()");
    } while (true);
    return (*this);
  }
  itrB operator--(int) {
    itrB it(*this);
    --(*this);
    return it;
  }
};

template <typename Key, typename Data>
struct HashMapBase {
  using u32 = uint32_t;
  using u64 = uint64_t;
  using iterator = itrB<Key, Data>;
  using itr = iterator;

 protected:
  template <typename K>
  inline u64 randomized(const K& key) const {
    return u64(key) ^ r;
  }

  template <typename K,
            enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,
            enable_if_t<is_integral<K>::value, nullptr_t> = nullptr>
  inline u32 inner_hash(const K& key) const {
    return (randomized(key) * 11995408973635179863ULL) >> shift;
  }
  template <
      typename K, enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,
      enable_if_t<is_integral<decltype(K::first)>::value, nullptr_t> = nullptr,
      enable_if_t<is_integral<decltype(K::second)>::value, nullptr_t> = nullptr>
  inline u32 inner_hash(const K& key) const {
    u64 a = randomized(key.first), b = randomized(key.second);
    a *= 11995408973635179863ULL;
    b *= 10150724397891781847ULL;
    return (a + b) >> shift;
  }
  template <typename K,
            enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,
            enable_if_t<is_integral<typename K::value_type>::value, nullptr_t> =
                nullptr>
  inline u32 inner_hash(const K& key) const {
    static constexpr u64 mod = (1LL << 61) - 1;
    static constexpr u64 base = 950699498548472943ULL;
    u64 res = 0;
    for (auto& elem : key) {
      __uint128_t x = __uint128_t(res) * base + (randomized(elem) & mod);
      res = (x & mod) + (x >> 61);
    }
    __uint128_t x = __uint128_t(res) * base;
    res = (x & mod) + (x >> 61);
    if (res >= mod) res -= mod;
    return res >> (shift - 3);
  }

  template <typename D = Data,
            enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr>
  inline u32 hash(const D& dat) const {
    return inner_hash(dat);
  }
  template <
      typename D = Data,
      enable_if_t<is_same<decltype(D::first), Key>::value, nullptr_t> = nullptr>
  inline u32 hash(const D& dat) const {
    return inner_hash(dat.first);
  }

  template <typename D = Data,
            enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr>
  inline Key data_to_key(const D& dat) const {
    return dat;
  }
  template <
      typename D = Data,
      enable_if_t<is_same<decltype(D::first), Key>::value, nullptr_t> = nullptr>
  inline Key data_to_key(const D& dat) const {
    return dat.first;
  }

  void reallocate(u32 ncap) {
    vector<Data> ndata(ncap);
    vector<bool> nf(ncap);
    shift = 64 - __lg(ncap);
    for (u32 i = 0; i < cap; i++) {
      if (occupied_flag[i] && !deleted_flag[i]) {
        u32 h = hash(data[i]);
        while (nf[h]) h = (h + 1) & (ncap - 1);
        ndata[h] = move(data[i]);
        nf[h] = true;
      }
    }
    data.swap(ndata);
    occupied_flag.swap(nf);
    cap = ncap;
    occupied = s;
    deleted_flag.resize(cap);
    fill(std::begin(deleted_flag), std::end(deleted_flag), false);
  }

  inline bool extend_rate(u32 x) const { return x * 2 >= cap; }

  inline bool shrink_rate(u32 x) const {
    return HASHMAP_DEFAULT_SIZE < cap && x * 10 <= cap;
  }

  inline void extend() { reallocate(cap << 1); }

  inline void shrink() { reallocate(cap >> 1); }

 public:
  u32 cap, s, occupied;
  vector<Data> data;
  vector<bool> occupied_flag, deleted_flag;
  u32 shift;
  static u64 r;
  static constexpr uint32_t HASHMAP_DEFAULT_SIZE = 4;

  explicit HashMapBase()
      : cap(HASHMAP_DEFAULT_SIZE),
        s(0),
        occupied(0),
        data(cap),
        occupied_flag(cap),
        deleted_flag(cap),
        shift(64 - __lg(cap)) {}

  itr begin() const {
    u32 h = 0;
    while (h != cap) {
      if (occupied_flag[h] && !deleted_flag[h]) break;
      h++;
    }
    return itr(h, this);
  }
  itr end() const { return itr(this->cap, this); }

  friend itr begin(const HashMapBase& h) { return h.begin(); }
  friend itr end(const HashMapBase& h) { return h.end(); }

  itr find(const Key& key) const {
    u32 h = inner_hash(key);
    while (true) {
      if (occupied_flag[h] == false) return this->end();
      if (data_to_key(data[h]) == key) {
        if (deleted_flag[h] == true) return this->end();
        return itr(h, this);
      }
      h = (h + 1) & (cap - 1);
    }
  }

  bool contain(const Key& key) const { return find(key) != this->end(); }

  itr insert(const Data& d) {
    u32 h = hash(d);
    while (true) {
      if (occupied_flag[h] == false) {
        if (extend_rate(occupied + 1)) {
          extend();
          h = hash(d);
          continue;
        }
        data[h] = d;
        occupied_flag[h] = true;
        ++occupied, ++s;
        return itr(h, this);
      }
      if (data_to_key(data[h]) == data_to_key(d)) {
        if (deleted_flag[h] == true) {
          data[h] = d;
          deleted_flag[h] = false;
          ++s;
        }
        return itr(h, this);
      }
      h = (h + 1) & (cap - 1);
    }
  }

  // tips for speed up :
  // if return value is unnecessary, make argument_2 false.
  itr erase(itr it, bool get_next = true) {
    if (it == this->end()) return this->end();
    s--;
    if (!get_next) {
      this->deleted_flag[it.i] = true;
      if (shrink_rate(s)) shrink();
      return this->end();
    }
    itr nxt = it;
    nxt++;
    this->deleted_flag[it.i] = true;
    if (shrink_rate(s)) {
      Data d = data[nxt.i];
      shrink();
      it = find(data_to_key(d));
    }
    return nxt;
  }

  itr erase(const Key& key) { return erase(find(key)); }

  int count(const Key& key) { return find(key) == end() ? 0 : 1; }

  bool empty() const { return s == 0; }

  int size() const { return s; }

  void clear() {
    fill(std::begin(occupied_flag), std::end(occupied_flag), false);
    fill(std::begin(deleted_flag), std::end(deleted_flag), false);
    s = occupied = 0;
  }

  void reserve(int n) {
    if (n <= 0) return;
    n = 1 << min(23, __lg(n) + 2);
    if (cap < u32(n)) reallocate(n);
  }
};

template <typename Key, typename Data>
uint64_t HashMapBase<Key, Data>::r =
    chrono::duration_cast<chrono::nanoseconds>(
        chrono::high_resolution_clock::now().time_since_epoch())
        .count();

}  // namespace HashMapImpl

/**
 * @brief Hash Map(base)　(ハッシュマップ・基底クラス)
 */
