#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename Str = string, int BASE_NUM = 1>
struct RollingHash {
  using u64 = unsigned long long;
  using u128 = __uint128_t;

  static constexpr u64 md = (1ull << 61) - 1;

  static inline constexpr u64 modmul(const u64 &a, const u64 &b) {
    u128 ret = u128(a) * b;
    ret = (ret & md) + (ret >> 61);
    return ret >= md ? ret - md : ret;
  }
  static inline constexpr u64 modfma(const u64 &a, const u64 &b, const u64 &c) {
    u128 ret = u128(a) * b + c;
    ret = (ret & md) + (ret >> 61);
    return ret >= md ? ret - md : ret;
  }

  struct Hash : array<u64, BASE_NUM> {
    using array<u64, BASE_NUM>::operator[];

    Hash() : array<u64, BASE_NUM>() {}
    constexpr static Hash set(u64 a) {
      Hash res;
      for (int i = 0; i < BASE_NUM; i++) res[i] = a;
      return res;
    }
    Hash &operator+=(const Hash &r) {
      for (int i = 0; i < BASE_NUM; i++)
        if (((*this)[i] += r[i]) >= md) (*this)[i] -= md;
      return *this;
    }
    Hash &operator+=(const u64 &r) {
      for (int i = 0; i < BASE_NUM; i++)
        if (((*this)[i] += r) >= md) (*this)[i] -= md;
      return *this;
    }
    Hash &operator-=(const Hash &r) {
      for (int i = 0; i < BASE_NUM; i++)
        if (((*this)[i] += md - r[i]) >= md) (*this)[i] -= md;
      return *this;
    }
    Hash &operator-=(const u64 &r) {
      for (int i = 0; i < BASE_NUM; i++)
        if (((*this)[i] += md - r) >= md) (*this)[i] -= md;
      return *this;
    }
    inline Hash &operator*=(const Hash &r) {
      for (int i = 0; i < BASE_NUM; i++) (*this)[i] = modmul((*this)[i], r[i]);
      return *this;
    }
    Hash operator+(const Hash &r) { return Hash(*this) += r; }
    Hash operator+(const u64 &r) { return Hash(*this) += r; }
    Hash operator-(const Hash &r) { return Hash(*this) -= r; }
    Hash operator-(const u64 &r) { return Hash(*this) -= r; }
    inline Hash operator*(const Hash &r) { return Hash(*this) *= r; }
    Hash operator-() const {
      Hash res;
      for (int i = 0; i < BASE_NUM; i++)
        res[i] = (*this)[i] == 0 ? 0 : md - (*this)[i];
      return res;
    }
    friend Hash pfma(const Hash &a, const Hash &b, const Hash &c) {
      Hash res;
      for (int i = 0; i < BASE_NUM; i++) res[i] = modfma(a[i], b[i], c[i]);
      return res;
    }
    friend Hash pfma(const Hash &a, const Hash &b, const u64 &c) {
      Hash res;
      for (int i = 0; i < BASE_NUM; i++) res[i] = modfma(a[i], b[i], c);
      return res;
    }
  };

  static Hash get_basis() {
    constexpr u64 ds[] = {2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331, 1321};
    static auto rand_time =
        chrono::duration_cast<chrono::nanoseconds>(
            chrono::high_resolution_clock::now().time_since_epoch())
            .count();
    static mt19937_64 rng(rand_time);

    auto modpow = [&](u64 a, u64 b) {
      u64 r = 1;
      for (a %= md; b; a = modmul(a, a), b >>= 1) r = modmul(r, a);
      return r;
    };
    auto isPrimitive = [&](u64 x) {
      for (auto &d : ds)
        if (modpow(x, (md - 1) / d) <= 1) return false;
      return true;
    };

    Hash h;
    for (int i = 0; i < BASE_NUM; i++) {
      while (isPrimitive(h[i] = rng() % (md - 1) + 1) == false)
        ;
    }
    return h;
  }

  Str data;
  vector<Hash> hs, pw;
  int s;
  static Hash basis;

  RollingHash() { build(string()); }

  RollingHash(const Str &S) { build(S); }

  void build(const Str &S) {
    data = S;
    s = S.size();
    hs.resize(s + 1);
    pw.resize(s + 1);
    pw[0] = Hash::set(1);
    hs[0] = Hash::set(0);
    for (int i = 1; i <= s; i++) {
      pw[i] = pw[i - 1] * basis;
      hs[i] = pfma(hs[i - 1], basis, u64(S[i - 1]));
    }
  }

  Hash get(int l, int r = -1) const {
    if (r == -1) r = s;
    return pfma(hs[l], -pw[r - l], hs[r]);
  }

  static Hash get_hash(const Str &T) {
    Hash ret = Hash::set(0);
    for (int i = 0; i < (int)T.size(); i++) ret = pfma(ret, basis, u64(T[i]));
    return ret;
  }

  int find(Str &T, int lower = 0) const {
    auto ths = get_hash(T);
    for (int i = lower; i <= s - (int)T.size(); i++)
      if (ths == get(i, i + (int)T.size())) return i;
    return -1;
  }

  friend int LCP(const RollingHash &a, const RollingHash &b, int al, int bl) {
    int ok = 0, ng = min(a.size() - al, b.size() - bl) + 1;
    while (ok + 1 < ng) {
      int med = (ok + ng) / 2;
      (a.get(al, med + al) == b.get(bl, med + bl) ? ok : ng) = med;
    }
    return ok;
  }

  friend int strcmp(const RollingHash &a, const RollingHash &b, int al, int bl,
                    int ar = -1, int br = -1) {
    if (ar == -1) ar = a.size();
    if (br == -1) br = b.size();
    int n = min<int>({LCP(a, b, al, bl), ar - al, br - bl});
    return al + n == ar
               ? bl + n == br ? 0 : 1
               : bl + n == br ? -1 : a.data[al + n] < b.data[bl + n] ? 1 : -1;
  }

  int size() const { return s; }
};

template <typename Str, int BASE_NUM>
typename RollingHash<Str, BASE_NUM>::Hash RollingHash<Str, BASE_NUM>::basis =
    RollingHash<Str, BASE_NUM>::get_basis();
using roriha = RollingHash<string, 1>;
