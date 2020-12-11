#pragma once

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
      if (p->flag[i] == true && p->dflag[i] == false) break;
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
      if (p->flag[i] == true && p->dflag[i] == false) break;
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
  template <typename K,
            enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,
            enable_if_t<is_integral<K>::value, nullptr_t> = nullptr>
  inline u32 inner_hash(const K& key) const {
    return u32((u64(key ^ r) * 11995408973635179863ULL) >> shift);
  }
  template <
      typename K, enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,
      enable_if_t<is_integral<decltype(K::first)>::value, nullptr_t> = nullptr,
      enable_if_t<is_integral<decltype(K::second)>::value, nullptr_t> = nullptr>
  inline u32 inner_hash(const K& key) const {
    u64 a = key.first ^ r;
    u64 b = key.second ^ r;
    a *= 11995408973635179863ULL;
    b *= 10150724397891781847ULL;
    return u32((a + b) >> shift);
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
  inline Key dtok(const D& dat) const {
    return dat;
  }
  template <
      typename D = Data,
      enable_if_t<is_same<decltype(D::first), Key>::value, nullptr_t> = nullptr>
  inline Key dtok(const D& dat) const {
    return dat.first;
  }

  void reallocate(u32 ncap) {
    vector<Data> ndata(ncap);
    vector<bool> nf(ncap);
    shift = 64 - __lg(ncap);
    for (u32 i = 0; i < cap; i++) {
      if (flag[i] == true && dflag[i] == false) {
        u32 h = hash(data[i]);
        while (nf[h]) h = (h + 1) & (ncap - 1);
        ndata[h] = data[i];
        nf[h] = true;
      }
    }
    data.swap(ndata);
    flag.swap(nf);
    cap = ncap;
    dflag.resize(cap);
    fill(std::begin(dflag), std::end(dflag), false);
  }

  inline bool extend_rate(u32 x) const { return x * 2 >= cap; }

  inline bool shrink_rate(u32 x) const {
    return HASHMAP_DEFAULT_SIZE < cap && x * 10 <= cap;
  }

  inline void extend() { reallocate(cap << 1); }

  inline void shrink() { reallocate(cap >> 1); }

 public:
  u32 cap, s;
  vector<Data> data;
  vector<bool> flag, dflag;
  u32 shift;
  static u64 r;
  static constexpr uint32_t HASHMAP_DEFAULT_SIZE = 4;

  explicit HashMapBase()
      : cap(HASHMAP_DEFAULT_SIZE),
        s(0),
        data(cap),
        flag(cap),
        dflag(cap),
        shift(64 - __lg(cap)) {}

  itr begin() const {
    u32 h = 0;
    while (h != cap) {
      if (flag[h] == true && dflag[h] == false) break;
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
      if (flag[h] == false) return this->end();
      if (dtok(data[h]) == key) {
        if (dflag[h] == true) return this->end();
        return itr(h, this);
      }
      h = (h + 1) & (cap - 1);
    }
  }

  bool contain(const Key& key) const { return find(key) != this->end(); }

  itr insert(const Data& d) {
    u32 h = hash(d);
    while (true) {
      if (flag[h] == false) {
        if (extend_rate(s + 1)) {
          extend();
          h = hash(d);
          continue;
        }
        data[h] = d;
        flag[h] = true;
        ++s;
        return itr(h, this);
      }
      if (dtok(data[h]) == dtok(d)) {
        if (dflag[h] == true) {
          data[h] = d;
          dflag[h] = false;
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
    if (shrink_rate(s)) {
      Data d = data[it.i];
      shrink();
      it = find(dtok(d));
    }
    int ni = (it.i + 1) & (cap - 1);
    if (this->flag[ni]) {
      this->dflag[it.i] = true;
    } else {
      this->flag[it.i] = false;
    }
    if (get_next) ++it;
    return it;
  }

  itr erase(const Key& key) { return erase(find(key)); }

  bool empty() const { return s == 0; }

  int size() const { return s; }

  void clear() {
    fill(std::begin(flag), std::end(flag), false);
    fill(std::begin(dflag), std::end(dflag), false);
    s = 0;
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
