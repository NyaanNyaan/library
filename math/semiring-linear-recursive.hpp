#pragma once

template <typename rig>
struct LinearRecursive {
  vector<rig> C;
  int N;
  LinearRecursive(const vector<rig>& c) : C(c), N(c.size()) {}

  rig kth_term(vector<rig> a, long long k) {
    assert(a.size() == C.size());
    if (k < (int)a.size()) return a[k];
    auto coeff = get_coeff(k);
    rig res = rig::id0();
    for (int i = 0; i < N; i++) res += a[i] * coeff[N - 1 - i];
    return res;
  }

  vector<rig> get_coeff(long long k) {
    if (k == 0) {
      vector<rig> b(N, rig::id0());
      b.back() = rig::id1();
      return b;
    }
    auto half = get_coeff(k / 2);
    doubling(half);
    if (k & 1) increment(half);
    return half;
  }

  void increment(vector<rig>& b) {
    vector<rig> v{begin(b) + 1, end(b)};
    v.push_back(rig::id0());
    for (int i = 0; i < N; i++) v[i] += b[0] * C[i];
    b.swap(v);
  }

  void doubling(vector<rig>& b) {
    vector<rig> v(N, rig::id0()), bb{b};
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        v[j] += bb[j] * b[N - 1 - i];
      }
      increment(bb);
    }
    swap(b, v);
  }
};
