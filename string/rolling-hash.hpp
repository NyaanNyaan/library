#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../inner/inner-hash.hpp"

template <typename Str, int BASE_NUM = 1>
struct RollingHash {
  using Hash = inner::Hash<BASE_NUM>;
  Str data;
  vector<Hash> hs, pw;
  int s;
  static Hash basis;

  RollingHash(const Str &S = Str()) { build(S); }

  void build(const Str &S) {
    data = S;
    s = S.size();
    hs.resize(s + 1);
    pw.resize(s + 1);
    pw[0] = Hash::set(1);
    hs[0] = Hash::set(0);
    for (int i = 1; i <= s; i++) {
      pw[i] = pw[i - 1] * basis;
      hs[i] = pfma(hs[i - 1], basis, Hash::cast(S[i - 1]));
    }
  }

  Hash get(int l, int r = -1) const {
    if (r == -1) r = s;
    return pfma(hs[l], -pw[r - l], hs[r]);
  }

  static Hash get_hash(const Str &T) {
    Hash ret = Hash::set(0);
    for (int i = 0; i < (int)T.size(); i++)
      ret = pfma(ret, basis, Hash::cast(T[i]));
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
    inner::Hash<BASE_NUM>::get_basis();
using roriha = RollingHash<string, 1>;
