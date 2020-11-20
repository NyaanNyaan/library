#include <bits/stdc++.h>
using namespace std;

namespace HashTableImpl {
using u32 = uint32_t;
using u64 = uint64_t;

template <typename Key, typename DS>
struct itrB : iterator<bidirectional_iterator_tag, Key, ptrdiff_t, Key*, Key&> {
  using base = iterator<bidirectional_iterator_tag, Key, ptrdiff_t, Key*, Key&>;
  using ptr = typename base::pointer;
  using ref = typename base::reference;

  u32 i;
  DS* p;
  explicit constexpr itrB() : i(0), p(nullptr) {}
  explicit constexpr itrB(u32 _i, DS* _p) : i(_i), p(_p) {}
  constexpr itrB(const itrB& r) : i(r.i), p(r.p) {}
  itrB& operator=(const itrB& r) { i = r.i, p = r.p; }
  ~itrB() noexcept {}
  friend void swap(itrB& l, itrB& r) { swap(l.i, r.i), swap(l.p, r.p); }
  friend bool operator==(const itrB& l, const itrB& r) { return l.i == r.i; }
  friend bool operator!=(const itrB& l, const itrB& r) { return l.i != r.i; }

  ref operator*() const { return p->data[i]; }
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
struct HashTableBase {
  using u32 = uint32_t;
  using u64 = uint64_t;
  using itr = itrB<Data, HashTableBase>;

 protected:
  template <typename K,
            enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,
            enable_if_t<is_integral<K>::value, nullptr_t> = nullptr>
  inline u32 inner_hash(const K& key) {
    return u32((u64(key) * 11995408973635179863ULL) >> shift);
  }
  template <
      typename K, enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,
      enable_if_t<is_integral<decltype(K::first)>::value, nullptr_t> = nullptr,
      enable_if_t<is_integral<decltype(K::second)>::value, nullptr_t> = nullptr>
  inline u32 inner_hash(const K& key) {
    u64 a = key.first;
    u64 b = key.second;
    a *= 11995408973635179863ULL;
    b *= 10150724397891781847ULL;
    return u32((a + b) >> shift);
  }
  template <typename D = Data,
            enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr>
  inline u32 hash(const D& dat) {
    return inner_hash(dat);
  }
  template <
      typename D = Data,
      enable_if_t<is_same<decltype(D::first), Key>::value, nullptr_t> = nullptr>
  inline u32 hash(const D& dat) {
    return inner_hash(dat.first);
  }

  template <typename D = Data,
            enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr>
  inline u32 is_same_key(const D& l, const D& r) const {
    return l == r;
  }
  template <
      typename D = Data,
      enable_if_t<is_same<decltype(D::first), Key>::value, nullptr_t> = nullptr>
  inline u32 is_same_key(const D& l, const D& r) const {
    return l.first == r.first;
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

  inline bool extend_rate() const { return s + s / 2 >= cap; }

  inline bool shrink_rate() const { return 8 < cap && s * 6 <= cap; }

  inline void extend() { reallocate(cap << 1); }

  inline void shrink() { reallocate(cap >> 1); }

 public:
  u32 cap, s;
  vector<Data> data;
  vector<bool> flag, dflag;
  u32 shift;

  explicit HashTableBase()
      : cap(8), s(0), data(cap), flag(cap), dflag(cap), shift(64 - __lg(cap)) {}

  itr begin() { return ++itr(u32(-1), this); }
  itr end() { return itr(this->cap, this); }

  itr find(const Data & d) {
    u32 h = hash(d);
    while (true) {
      if (flag[h] == false) return this->end();
      if (is_same_key(data[h], d)) {
        if (dflag[h] == true) dflag[h] = false;
        data[h] = d;
        return itr(h, this);
      }
      h = (h + 1) & (cap - 1);
    }
  }

  itr insert(const Data& d) {
    u32 h = hash(d);
    while (true) {
      if (flag[h] == false) {
        if (extend_rate()) {
          extend();
          h = hash(d);
          continue;
        }
        data[h] = d;
        flag[h] = true;
        ++s;
        return itr(h, this);
      }
      if (is_same_key(data[h], d)) {
        if (dflag[h] == true) dflag[h] = false;
        data[h] = d;
        return itr(h, this);
      }
      h = (h + 1) & (cap - 1);
    }
  }

  // tips for speed up :
  // if return value is unnecessary, make argument_2 false.
  itr erase(const itr& it, bool get_next = true) {
    assert(it != this->end() && "itr erase(const itr& it)");
    s--;
    if (shrink_rate()) {
      Data d = data[it.i];
      shrink();
      // find key
      it = find(d);
    }
    this->dflag[it.i] = true;
    itr res = it;
    if (get_next) ++res;
    return res;
  }
};

}  // namespace HashTableImpl

template <typename Key, typename Val>
struct HashMap : HashTableImpl::HashTableBase<Key, pair<Key, Val>> {
  using base = typename HashTableImpl::HashTableBase<Key, pair<Key, Val>>;
  using base::HashTableBase;
  using Data = pair<Key, Val>;

  Val& operator[](const Key& k) {
    typename base::u32 h = base::hash(k);
    while (true) {
      if (base::flag[h] == false) {
        if (base::extend_rate()) {
          base::extend();
          h = base::hash(k);
          continue;
        }
        base::data[h].first = k;
        base::data[h].second = Val();
        base::flag[h] = true;
        ++base::s;
        return base::data[h].second;
      }
      if (base::data[h].first == k) {
        if (base::dflag[h] == true) base::data[h].second = Val();
        return base::data[h].second;
      }
      h = (h + 1) & (base::cap - 1);
    }
  }
};
