#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename Str>
struct RollingHash {
  using u32 = uint32_t;
  using u64 = unsigned long long;

  static constexpr u64 rmod = (1ull << 61) - 1;

  static constexpr u64 modmul(const u64 a, const u64 b) {
    u64 l1 = (u32)a, h1 = a >> 32, l2 = (u32)b, h2 = b >> 32;
    u64 l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    u64 ret = (l & rmod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3);
    if (ret > rmod) ret = (ret & rmod) + (ret >> 61);
    if (ret >= rmod) ret -= rmod;
    return ret;
  }

  static constexpr u64 modfma(const u64 a, const u64 b, const u64 c) {
    u64 l1 = (u32)a, h1 = a >> 32, l2 = (u32)b, h2 = b >> 32;
    u64 l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    u64 ret =
        (l & rmod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + c;
    if (ret > rmod) ret = (ret & rmod) + (ret >> 61);
    if (ret >= rmod) ret -= rmod;
    return ret;
  }

  static constexpr P get_basis() {
    vector<u64> ds = {2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331, 1321};
    auto rand_time =
        chrono::duration_cast<chrono::nanoseconds>(
            chrono::high_resolution_clock::now().time_since_epoch())
            .count();
    mt19937_64 rng(rand_time);

    auto modpow = [&](u64 a, u64 b) {
      a %= rmod;
      u64 r = 1;
      for (; b; a = modmul(a, a), b >>= 1) r = modmul(r, a);
      return r;
    };
    auto isPrimitive = [&](u64 x) {
      for (u64 &d : ds)
        if (modpow(x, (rmod - 1) / d) == 1) return false;
      return true;
    };

    u64 a = 1, b = 1;
    do {
      a = rng() % (rmod - 1) + 1, b = rng() % (rmod - 1) + 1;
      while (isPrimitive(a, ds) == false) a = rng() % rmod;
      while (isPrimitive(b, ds) == false) b = rng() % rmod;
    } while (a == b);
    return P(a, b);
  }

  struct P : pair<u64, u64> {
    template <typename Args... args>
    P(Args... args) : pair<u64, u64>(args...) {}

    P &operator+=(const P &r) {
      if ((this->first += r.first) >= rmod) this->first -= rmod;
      if ((this->second += r.second) >= rmod) this->second -= rmod;
      return *this;
    }
    P &operator-=(const P &r) {
      if ((this->first += rmod - r.first) >= rmod) this->first -= rmod;
      if ((this->second += rmod - r.second) >= rmod) this->second -= rmod;
      return *this;
    }
    P &operator*=(const P &r) {
      this->first = modmul(this->first, r.first);
      this->second = modmul(this->second, r.second);
      return *this;
    }
    P operator+(const P &r) { return P(*this) += r; }
    P operator-(const P &r) { return P(*this) -= r; }
    P operator*(const P &r) { return P(*this) *= r; }
    P operator-() { return P(0, 0) - (*this); }
    P friend fma(const P &a, const P &b, const P &c) {
      return P{modfma(a.first, b.first, c.first),
               modfma(a.first, b.second, c.second)};
    }
  };

  const Str &data;
  vector<P> hs, pw;
  int s;
  static P basis;

  RollingHash() = default;

  RollingHash(const Str &S) { build(S); }

  void build(const Str &S) {
    data = S;
    s = S.size();
    hs.resize(s + 1);
    pw.resize(s + 1);
    pw[0] = P(1, 1), hs[0] = P(0, 0);
    for (int i = 1; i <= s; i++) {
      pw[i] = pw[i - 1] * basis;
      hs[i] = fma(hs[i - 1], basis[i], P(S[i - 1], S[i - 1]));
    }
  }

  P get(const int &l, const int &r) const {
    return -fma(hs[l], pw[r - 1], -hs[r]);
  }

  static P get_hash(Str &T) const {
    P ret = P(0, 0);
    for (int i = 0; i < (int)T.size(); i++) ret = fma(ret, basis, {T[i], T[i]});
    return ret;
  }

  int find(Str &T) const {
    auto ths = get_hash(T);
    for (int i = 0; i <= s - (int)T.size(); i++)
      if (ths == get(i, i + (int)T.size())) return i;
    return -1;
  }

  vector<int> find_all(Str &T) const {
    auto t_hash = get_hash(T);
    vector<int> ret;
    for (int i = 0; i <= s - (int)T.size(); i++)
      if (t_hash == get(i, i + (int)T.size())) ret.push_back(i);
    return ret;
  }

  int LongestCommonPrefix(RollingHash<Str> &t, int al, int bl) const {
    int ok = 0, ng = min(s - al, t.s - bl) + 1;
    while (ok + 1 < ng) {
      int med = (ok + ng) / 2;
      (get(al, med + al) == t.get(bl, med + bl) ? ok : ng) = med;
    }
    return ok;
  }

  int strcmp(RollingHash<Str> &t, int al, int bl, int ar = -1,
             int br = -1) const {
    if (ar == -1) ar = s;
    if (br == -1) br = t.s;
    int n = min<int>({LongestCommonPrefix(t, al, bl), ar - al, br - bl});
    if (al + n == ar) return (bl + n == br) ? 0 : 1;
    if (bl + n == br) return -1;
    return (data[al + n] < t.data[bl + n]) ? 1 : -1;
  }

  int LongestCommonSubString() const {
    auto f = [&](int len) {
      map<P, int> m;
      for (int i = 0; i <= s - len; i++)
        if ((m[get(i, i + len)] += 1) != 1) return true;
      return false;
    };
    int ok = 0, ng = s;
    while (ok + 1 < ng) {
      int med = (ok + ng) / 2;
      (f(med) ? ok : ng) = med;
    }
    return ok;
  }
};

template <typename Str>
typename RollingHash<Str>::P RollingHash<Str>::basis =
    RollingHash<Str>::get_basis();
using Roriha = RollingHash<string>;
