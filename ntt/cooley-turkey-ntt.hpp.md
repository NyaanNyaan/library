---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ntt/cooley-turkey-ntt.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nnamespace FastFourierTransform {\nusing real = double;\n\
    \nstruct C {\n  real x, y;\n\n  C() : x(0), y(0) {}\n\n  C(real x, real y) : x(x),\
    \ y(y) {}\n\n  inline C operator+(const C &c) const { return C(x + c.x, y + c.y);\
    \ }\n\n  inline C operator-(const C &c) const { return C(x - c.x, y - c.y); }\n\
    \n  inline C operator*(const C &c) const {\n    return C(x * c.x - y * c.y, x\
    \ * c.y + y * c.x);\n  }\n\n  inline C conj() const { return C(x, -y); }\n};\n\
    \nconst real PI = acosl(-1);\nint base = 1;\nvector<C> rts = {{0, 0}, {1, 0}};\n\
    vector<int> rev = {0, 1};\n\nvoid ensure_base(int nbase) {\n  if (nbase <= base)\
    \ return;\n  rev.resize(1 << nbase);\n  rts.resize(1 << nbase);\n  for (int i\
    \ = 0; i < (1 << nbase); i++) {\n    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) <<\
    \ (nbase - 1));\n  }\n  while (base < nbase) {\n    real angle = PI * 2.0 / (1\
    \ << (base + 1));\n    for (int i = 1 << (base - 1); i < (1 << base); i++) {\n\
    \      rts[i << 1] = rts[i];\n      real angle_i = angle * (2 * i + 1 - (1 <<\
    \ base));\n      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\n    }\n \
    \   ++base;\n  }\n}\n\nvoid fft(vector<C> &a, int n) {\n  assert((n & (n - 1))\
    \ == 0);\n  int zeros = __builtin_ctz(n);\n  ensure_base(zeros);\n  int shift\
    \ = base - zeros;\n  for (int i = 0; i < n; i++) {\n    if (i < (rev[i] >> shift))\
    \ {\n      swap(a[i], a[rev[i] >> shift]);\n    }\n  }\n  for (int k = 1; k <\
    \ n; k <<= 1) {\n    for (int i = 0; i < n; i += 2 * k) {\n      for (int j =\
    \ 0; j < k; j++) {\n        C z = a[i + j + k] * rts[j + k];\n        a[i + j\
    \ + k] = a[i + j] - z;\n        a[i + j] = a[i + j] + z;\n      }\n    }\n  }\n\
    }\n\ntemplate <typename mint>\nvector<mint> multiply(const vector<mint> &a, const\
    \ vector<mint> &b) {\n  int need = (int)a.size() + (int)b.size() - 1;\n  int nbase\
    \ = 1;\n  while ((1 << nbase) < need) nbase++;\n  ensure_base(nbase);\n  int sz\
    \ = 1 << nbase;\n  vector<C> fa(sz);\n  for (int i = 0; i < sz; i++) {\n    int\
    \ x = (i < (int)a.size() ? a[i].get() : 0);\n    int y = (i < (int)b.size() ?\
    \ b[i].get() : 0);\n    fa[i] = C(x, y);\n  }\n  fft(fa, sz);\n  C r(0, -0.25\
    \ / (sz >> 1)), s(0, 1), t(0.5, 0);\n  for (int i = 0; i <= (sz >> 1); i++) {\n\
    \    int j = (sz - i) & (sz - 1);\n    C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj())\
    \ * r;\n    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;\n    fa[i] =\
    \ z;\n  }\n  for (int i = 0; i < (sz >> 1); i++) {\n    C A0 = (fa[i] + fa[i +\
    \ (sz >> 1)]) * t;\n    C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1)\
    \ + i];\n    fa[i] = A0 + A1 * s;\n  }\n  fft(fa, sz >> 1);\n  vector<mint> ret(need);\n\
    \  for (int i = 0; i < need; i++) {\n    ret[i] = llround(i & 1 ? fa[i >> 1].y\
    \ : fa[i >> 1].x);\n  }\n  return ret;\n}\n};  // namespace FastFourierTransform\n\
    \ntemplate <typename T>\nstruct ArbitraryModConvolution {\n  using real = FastFourierTransform::real;\n\
    \  using C = FastFourierTransform::C;\n\n  ArbitraryModConvolution() = default;\n\
    \n  static vector<T> multiply(const vector<T> &a, const vector<T> &b,\n      \
    \                      int need = -1) {\n    if (need == -1) need = a.size() +\
    \ b.size() - 1;\n    int nbase = 0;\n    while ((1 << nbase) < need) nbase++;\n\
    \    FastFourierTransform::ensure_base(nbase);\n    int sz = 1 << nbase;\n   \
    \ vector<C> fa(sz);\n    for (int i = 0; i < (int)a.size(); i++) {\n      fa[i]\
    \ = C(a[i].get() & ((1 << 15) - 1), a[i].get() >> 15);\n    }\n    fft(fa, sz);\n\
    \    vector<C> fb(sz);\n    if (a == b) {\n      fb = fa;\n    } else {\n    \
    \  for (int i = 0; i < (int)b.size(); i++) {\n        fb[i] = C(b[i].get() & ((1\
    \ << 15) - 1), b[i].get() >> 15);\n      }\n      fft(fb, sz);\n    }\n    real\
    \ ratio = 0.25 / sz;\n    C r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);\n\
    \    for (int i = 0; i <= (sz >> 1); i++) {\n      int j = (sz - i) & (sz - 1);\n\
    \      C a1 = (fa[i] + fa[j].conj());\n      C a2 = (fa[i] - fa[j].conj()) * r2;\n\
    \      C b1 = (fb[i] + fb[j].conj()) * r3;\n      C b2 = (fb[i] - fb[j].conj())\
    \ * r4;\n      if (i != j) {\n        C c1 = (fa[j] + fa[i].conj());\n       \
    \ C c2 = (fa[j] - fa[i].conj()) * r2;\n        C d1 = (fb[j] + fb[i].conj()) *\
    \ r3;\n        C d2 = (fb[j] - fb[i].conj()) * r4;\n        fa[i] = c1 * d1 +\
    \ c2 * d2 * r5;\n        fb[i] = c1 * d2 + c2 * d1;\n      }\n      fa[j] = a1\
    \ * b1 + a2 * b2 * r5;\n      fb[j] = a1 * b2 + a2 * b1;\n    }\n    fft(fa, sz);\n\
    \    fft(fb, sz);\n    vector<T> ret(need);\n    for (int i = 0; i < need; i++)\
    \ {\n      int64_t aa = llround(fa[i].x);\n      int64_t bb = llround(fb[i].x);\n\
    \      int64_t cc = llround(fa[i].y);\n      aa = T(aa).get(), bb = T(bb).get(),\
    \ cc = T(cc).get();\n      ret[i] = aa + (bb << 15) + (cc << 30);\n    }\n   \
    \ return ret;\n  }\n};\n\ntemplate <typename mint>\nstruct ArbitraryLengthNTT\
    \ {\n  using i64 = long long;\n\n  static int modpow(i64 a, i64 p, int m) {\n\
    \    i64 r = 1 % m;\n    for (a %= m; p; a = a * a % m, p >>= 1)\n      if (p\
    \ & 1) r = r * a % m;\n    return r;\n  }\n\n  static int factor(int n) {\n  \
    \  for (int i = 2; i * i <= n; i++)\n      if (n % i == 0) return i;\n    return\
    \ n;\n  }\n\n  static vector<int> divisor(int n) {\n    vector<int> ret;\n   \
    \ for (int i = 2; i * i <= n; i++) {\n      if (n % i == 0) {\n        ret.push_back(i);\n\
    \        ret.push_back(n / i);\n      }\n    }\n    ret.push_back(n);\n    sort(begin(ret),\
    \ end(ret));\n    ret.erase(unique(begin(ret), end(ret)), end(ret));\n    return\
    \ ret;\n  }\n\n  static int get_pr(int m) {\n    vector<int> st;\n    for (int\
    \ i = m - 1; i != 1; i /= st.back()) st.push_back(factor(i));\n    st.erase(unique(begin(st),\
    \ end(st)), end(st));\n    for (int pr = 1, flg = 1; pr < m; ++pr, flg = 1) {\n\
    \      for (auto &x : st)\n        if (modpow(pr, (m - 1) / x, m) == 1) flg =\
    \ 0;\n      if (flg) return pr;\n    }\n    exit(1);\n  }\n\n  struct LaderNTT\
    \ {\n    int p, pr;\n    vector<int> prs, iprs;\n    LaderNTT() {}\n    LaderNTT(int\
    \ p_) : p(p_), pr(get_pr(p_)), prs(p_ - 1), iprs(p_, -1) {\n      for (int i =\
    \ 0; i < p - 1; i++) prs[i] = i ? prs[i - 1] * pr % p : 1;\n      for (int i =\
    \ 0; i < p - 1; i++) iprs[prs[i]] = i;\n    }\n\n    void ntt(vector<mint> &a)\
    \ {\n      vector<mint> s(p - 1), t(p - 1);\n      for (int i = 0; i < p - 1;\
    \ i++) s[i] = a[prs[i]];\n      for (int i = 0, ldp = len / p; i < p - 1; i++)\n\
    \        t[i] = w[ldp * prs[i ? p - 1 - i : 0]];\n      vector<mint> u = ArbitraryModConvolution<mint>::multiply(s,\
    \ t);\n      s.resize(p);\n      fill(begin(s), end(s), a[0]);\n      for (int\
    \ i = 1; i < p; i++) s[0] += a[i];\n      for (int i = 0, y = 0; i < (int)u.size();\
    \ i++) {\n        s[prs[y]] += u[i];\n        if (--y < 0) y += p - 1;\n     \
    \ }\n      swap(a, s);\n    }\n  };\n\n  static int len;\n  static vector<mint>\
    \ w;\n  static vector<int> divisors;\n  static map<int, LaderNTT *> lader;\n\n\
    \  ArbitraryLengthNTT(int len_ = -1) {\n    int mod = mint::get_mod();\n    if\
    \ ((len = len_) == -1) len = mod - 1;\n    if (mod >= 3 && len <= 1) len = 2;\n\
    \    while ((mod - 1) % len != 0) ++len;\n    w.resize(len + 1);\n    mint pr\
    \ = mint(get_pr(mod)).pow((mod - 1) / len);\n    for (int i = 0; i <= len; i++)\
    \ w[i] = i ? w[i - 1] * pr : mint(1);\n    divisors = divisor(len);\n  }\n\n \
    \ static void dft(vector<mint> &a) {\n    int N = a.size();\n    if (N == 2) {\n\
    \      mint a01 = a[0] + a[1];\n      a[1] = a[0] - a[1];\n      a[0] = a01;\n\
    \      return;\n    }\n    int d = len / N;\n    vector<mint> b(N);\n    for (int\
    \ i = 0, dk = 0; i < N; i++, dk += d) {\n      for (int j = 0, k = 0; j < N; j++)\
    \ {\n        b[j] += a[i] * w[k];\n        if ((k += dk) >= len) k -= len;\n \
    \     }\n    }\n    swap(a, b);\n  }\n\n  static void ntt_base2(vector<mint> &a)\
    \ {\n    static vector<int> btr;\n    int N = a.size();\n    assert(N % 2 == 0);\n\
    \n    if (btr.size() != a.size()) {\n      btr.resize(N);\n      int b = __builtin_ctz(N);\n\
    \      assert(N == (1 << b));\n      for (int i = 0; i < N; i++) {\n        btr[i]\
    \ = (btr[i >> 1] >> 1) + ((i & 1) << (b - 1));\n      }\n    }\n\n    static vector<mint>\
    \ basis;\n    if (basis.size() < a.size()) {\n      basis.resize(N);\n      mint\
    \ b = w[len / N];\n      for (int i = N >> 1; i > 0; i >>= 1) {\n        mint\
    \ c = 1;\n        for (int j = 0; j < i; ++j) {\n          basis[i + j] = c;\n\
    \          c *= b;\n        }\n        b *= b;\n      }\n    }\n\n    for (int\
    \ i = 0; i < N; i++)\n      if (i < btr[i]) swap(a[i], a[btr[i]]);\n\n    for\
    \ (int k = 1; k < N; k <<= 1) {\n      for (int i = 0; i < N; i += 2 * k) {\n\
    \        for (int j = 0; j < k; j++) {\n          mint z = a[i + j + k] * basis[j\
    \ + k];\n          a[i + j + k] = a[i + j] - z;\n          a[i + j] = a[i + j]\
    \ + z;\n        }\n      }\n    }\n  }\n\n  static void pntt(vector<mint> &a)\
    \ {\n    int P = a.size();\n    if (P <= 64) {\n      dft(a);\n      return;\n\
    \    }\n    if (lader.find(P) == end(lader)) lader[P] = new LaderNTT(P);\n   \
    \ lader[P]->ntt(a);\n  }\n\n  static void ntt(vector<mint> &a) {\n    assert(len\
    \ % a.size() == 0);\n    int N = (int)a.size();\n    if(N <= 1) return;\n    if\
    \ (N <= 64) {\n      dft(a);\n      return;\n    }\n\n    int P = factor(N);\n\
    \    if (P == N) {\n      pntt(a);\n      return;\n    }\n    if (P == 2) {\n\
    \      P = 1 << __builtin_ctz(N);\n      if (N == P) {\n        ntt_base2(a);\n\
    \        return;\n      }\n    }\n\n    int Q = N / P;\n    vector<mint> s(Q),\
    \ t(N), u(P);\n    for (int p = 0, lN = len / N, d = 0; p < P; p++, d += lN) {\n\
    \      for (int q = 0, qP = 0; q < Q; q++, qP += P) s[q] = a[qP + p];\n      ntt(s);\n\
    \      for (int r = 0, n = 0, pQ = p * Q; r < Q; ++r, n += d) {\n        t[pQ\
    \ + r] = w[n] * s[r];\n      }\n    }\n    for (int r = 0; r < Q; r++) {\n   \
    \   for (int p = 0, pQ = 0; p < P; p++, pQ += Q) u[p] = t[pQ + r];\n      if (P\
    \ <= 64)\n        dft(u);\n      else if (P & 1)\n        pntt(u);\n      else\n\
    \        ntt_base2(u);\n      for (int s = 0, sQ = 0; s < P; s++, sQ += Q) a[sQ\
    \ + r] = u[s];\n    }\n  }\n\n  static void intt(vector<mint> &a) {\n    reverse(begin(a)\
    \ + 1, end(a));\n    ntt(a);\n    mint invn = mint(a.size()).inverse();\n    for\
    \ (auto &x : a) x *= invn;\n  }\n\n  static vector<mint> multiply(const vector<mint>\
    \ &a, const vector<mint> &b) {\n    int N = (int)a.size() + (int)b.size() - 1;\n\
    \    assert(N <= len);\n    vector<mint> s(a), t(b);\n    int l = *lower_bound(begin(divisors),\
    \ end(divisors), N);\n    s.resize(l, mint(0));\n    t.resize(l, mint(0));\n \
    \   ntt(s);\n    ntt(t);\n    for (int i = 0; i < l; i++) s[i] *= t[i];\n    intt(s);\n\
    \    s.resize(N);\n    return s;\n  }\n};\ntemplate <typename mint>\nint ArbitraryLengthNTT<mint>::len;\n\
    template <typename mint>\nvector<mint> ArbitraryLengthNTT<mint>::w;\ntemplate\
    \ <typename mint>\nvector<int> ArbitraryLengthNTT<mint>::divisors;\ntemplate <typename\
    \ mint>\nmap<int, typename ArbitraryLengthNTT<mint>::LaderNTT *>\n    ArbitraryLengthNTT<mint>::lader;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nnamespace\
    \ FastFourierTransform {\nusing real = double;\n\nstruct C {\n  real x, y;\n\n\
    \  C() : x(0), y(0) {}\n\n  C(real x, real y) : x(x), y(y) {}\n\n  inline C operator+(const\
    \ C &c) const { return C(x + c.x, y + c.y); }\n\n  inline C operator-(const C\
    \ &c) const { return C(x - c.x, y - c.y); }\n\n  inline C operator*(const C &c)\
    \ const {\n    return C(x * c.x - y * c.y, x * c.y + y * c.x);\n  }\n\n  inline\
    \ C conj() const { return C(x, -y); }\n};\n\nconst real PI = acosl(-1);\nint base\
    \ = 1;\nvector<C> rts = {{0, 0}, {1, 0}};\nvector<int> rev = {0, 1};\n\nvoid ensure_base(int\
    \ nbase) {\n  if (nbase <= base) return;\n  rev.resize(1 << nbase);\n  rts.resize(1\
    \ << nbase);\n  for (int i = 0; i < (1 << nbase); i++) {\n    rev[i] = (rev[i\
    \ >> 1] >> 1) + ((i & 1) << (nbase - 1));\n  }\n  while (base < nbase) {\n   \
    \ real angle = PI * 2.0 / (1 << (base + 1));\n    for (int i = 1 << (base - 1);\
    \ i < (1 << base); i++) {\n      rts[i << 1] = rts[i];\n      real angle_i = angle\
    \ * (2 * i + 1 - (1 << base));\n      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\n\
    \    }\n    ++base;\n  }\n}\n\nvoid fft(vector<C> &a, int n) {\n  assert((n &\
    \ (n - 1)) == 0);\n  int zeros = __builtin_ctz(n);\n  ensure_base(zeros);\n  int\
    \ shift = base - zeros;\n  for (int i = 0; i < n; i++) {\n    if (i < (rev[i]\
    \ >> shift)) {\n      swap(a[i], a[rev[i] >> shift]);\n    }\n  }\n  for (int\
    \ k = 1; k < n; k <<= 1) {\n    for (int i = 0; i < n; i += 2 * k) {\n      for\
    \ (int j = 0; j < k; j++) {\n        C z = a[i + j + k] * rts[j + k];\n      \
    \  a[i + j + k] = a[i + j] - z;\n        a[i + j] = a[i + j] + z;\n      }\n \
    \   }\n  }\n}\n\ntemplate <typename mint>\nvector<mint> multiply(const vector<mint>\
    \ &a, const vector<mint> &b) {\n  int need = (int)a.size() + (int)b.size() - 1;\n\
    \  int nbase = 1;\n  while ((1 << nbase) < need) nbase++;\n  ensure_base(nbase);\n\
    \  int sz = 1 << nbase;\n  vector<C> fa(sz);\n  for (int i = 0; i < sz; i++) {\n\
    \    int x = (i < (int)a.size() ? a[i].get() : 0);\n    int y = (i < (int)b.size()\
    \ ? b[i].get() : 0);\n    fa[i] = C(x, y);\n  }\n  fft(fa, sz);\n  C r(0, -0.25\
    \ / (sz >> 1)), s(0, 1), t(0.5, 0);\n  for (int i = 0; i <= (sz >> 1); i++) {\n\
    \    int j = (sz - i) & (sz - 1);\n    C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj())\
    \ * r;\n    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;\n    fa[i] =\
    \ z;\n  }\n  for (int i = 0; i < (sz >> 1); i++) {\n    C A0 = (fa[i] + fa[i +\
    \ (sz >> 1)]) * t;\n    C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1)\
    \ + i];\n    fa[i] = A0 + A1 * s;\n  }\n  fft(fa, sz >> 1);\n  vector<mint> ret(need);\n\
    \  for (int i = 0; i < need; i++) {\n    ret[i] = llround(i & 1 ? fa[i >> 1].y\
    \ : fa[i >> 1].x);\n  }\n  return ret;\n}\n};  // namespace FastFourierTransform\n\
    \ntemplate <typename T>\nstruct ArbitraryModConvolution {\n  using real = FastFourierTransform::real;\n\
    \  using C = FastFourierTransform::C;\n\n  ArbitraryModConvolution() = default;\n\
    \n  static vector<T> multiply(const vector<T> &a, const vector<T> &b,\n      \
    \                      int need = -1) {\n    if (need == -1) need = a.size() +\
    \ b.size() - 1;\n    int nbase = 0;\n    while ((1 << nbase) < need) nbase++;\n\
    \    FastFourierTransform::ensure_base(nbase);\n    int sz = 1 << nbase;\n   \
    \ vector<C> fa(sz);\n    for (int i = 0; i < (int)a.size(); i++) {\n      fa[i]\
    \ = C(a[i].get() & ((1 << 15) - 1), a[i].get() >> 15);\n    }\n    fft(fa, sz);\n\
    \    vector<C> fb(sz);\n    if (a == b) {\n      fb = fa;\n    } else {\n    \
    \  for (int i = 0; i < (int)b.size(); i++) {\n        fb[i] = C(b[i].get() & ((1\
    \ << 15) - 1), b[i].get() >> 15);\n      }\n      fft(fb, sz);\n    }\n    real\
    \ ratio = 0.25 / sz;\n    C r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);\n\
    \    for (int i = 0; i <= (sz >> 1); i++) {\n      int j = (sz - i) & (sz - 1);\n\
    \      C a1 = (fa[i] + fa[j].conj());\n      C a2 = (fa[i] - fa[j].conj()) * r2;\n\
    \      C b1 = (fb[i] + fb[j].conj()) * r3;\n      C b2 = (fb[i] - fb[j].conj())\
    \ * r4;\n      if (i != j) {\n        C c1 = (fa[j] + fa[i].conj());\n       \
    \ C c2 = (fa[j] - fa[i].conj()) * r2;\n        C d1 = (fb[j] + fb[i].conj()) *\
    \ r3;\n        C d2 = (fb[j] - fb[i].conj()) * r4;\n        fa[i] = c1 * d1 +\
    \ c2 * d2 * r5;\n        fb[i] = c1 * d2 + c2 * d1;\n      }\n      fa[j] = a1\
    \ * b1 + a2 * b2 * r5;\n      fb[j] = a1 * b2 + a2 * b1;\n    }\n    fft(fa, sz);\n\
    \    fft(fb, sz);\n    vector<T> ret(need);\n    for (int i = 0; i < need; i++)\
    \ {\n      int64_t aa = llround(fa[i].x);\n      int64_t bb = llround(fb[i].x);\n\
    \      int64_t cc = llround(fa[i].y);\n      aa = T(aa).get(), bb = T(bb).get(),\
    \ cc = T(cc).get();\n      ret[i] = aa + (bb << 15) + (cc << 30);\n    }\n   \
    \ return ret;\n  }\n};\n\ntemplate <typename mint>\nstruct ArbitraryLengthNTT\
    \ {\n  using i64 = long long;\n\n  static int modpow(i64 a, i64 p, int m) {\n\
    \    i64 r = 1 % m;\n    for (a %= m; p; a = a * a % m, p >>= 1)\n      if (p\
    \ & 1) r = r * a % m;\n    return r;\n  }\n\n  static int factor(int n) {\n  \
    \  for (int i = 2; i * i <= n; i++)\n      if (n % i == 0) return i;\n    return\
    \ n;\n  }\n\n  static vector<int> divisor(int n) {\n    vector<int> ret;\n   \
    \ for (int i = 2; i * i <= n; i++) {\n      if (n % i == 0) {\n        ret.push_back(i);\n\
    \        ret.push_back(n / i);\n      }\n    }\n    ret.push_back(n);\n    sort(begin(ret),\
    \ end(ret));\n    ret.erase(unique(begin(ret), end(ret)), end(ret));\n    return\
    \ ret;\n  }\n\n  static int get_pr(int m) {\n    vector<int> st;\n    for (int\
    \ i = m - 1; i != 1; i /= st.back()) st.push_back(factor(i));\n    st.erase(unique(begin(st),\
    \ end(st)), end(st));\n    for (int pr = 1, flg = 1; pr < m; ++pr, flg = 1) {\n\
    \      for (auto &x : st)\n        if (modpow(pr, (m - 1) / x, m) == 1) flg =\
    \ 0;\n      if (flg) return pr;\n    }\n    exit(1);\n  }\n\n  struct LaderNTT\
    \ {\n    int p, pr;\n    vector<int> prs, iprs;\n    LaderNTT() {}\n    LaderNTT(int\
    \ p_) : p(p_), pr(get_pr(p_)), prs(p_ - 1), iprs(p_, -1) {\n      for (int i =\
    \ 0; i < p - 1; i++) prs[i] = i ? prs[i - 1] * pr % p : 1;\n      for (int i =\
    \ 0; i < p - 1; i++) iprs[prs[i]] = i;\n    }\n\n    void ntt(vector<mint> &a)\
    \ {\n      vector<mint> s(p - 1), t(p - 1);\n      for (int i = 0; i < p - 1;\
    \ i++) s[i] = a[prs[i]];\n      for (int i = 0, ldp = len / p; i < p - 1; i++)\n\
    \        t[i] = w[ldp * prs[i ? p - 1 - i : 0]];\n      vector<mint> u = ArbitraryModConvolution<mint>::multiply(s,\
    \ t);\n      s.resize(p);\n      fill(begin(s), end(s), a[0]);\n      for (int\
    \ i = 1; i < p; i++) s[0] += a[i];\n      for (int i = 0, y = 0; i < (int)u.size();\
    \ i++) {\n        s[prs[y]] += u[i];\n        if (--y < 0) y += p - 1;\n     \
    \ }\n      swap(a, s);\n    }\n  };\n\n  static int len;\n  static vector<mint>\
    \ w;\n  static vector<int> divisors;\n  static map<int, LaderNTT *> lader;\n\n\
    \  ArbitraryLengthNTT(int len_ = -1) {\n    int mod = mint::get_mod();\n    if\
    \ ((len = len_) == -1) len = mod - 1;\n    if (mod >= 3 && len <= 1) len = 2;\n\
    \    while ((mod - 1) % len != 0) ++len;\n    w.resize(len + 1);\n    mint pr\
    \ = mint(get_pr(mod)).pow((mod - 1) / len);\n    for (int i = 0; i <= len; i++)\
    \ w[i] = i ? w[i - 1] * pr : mint(1);\n    divisors = divisor(len);\n  }\n\n \
    \ static void dft(vector<mint> &a) {\n    int N = a.size();\n    if (N == 2) {\n\
    \      mint a01 = a[0] + a[1];\n      a[1] = a[0] - a[1];\n      a[0] = a01;\n\
    \      return;\n    }\n    int d = len / N;\n    vector<mint> b(N);\n    for (int\
    \ i = 0, dk = 0; i < N; i++, dk += d) {\n      for (int j = 0, k = 0; j < N; j++)\
    \ {\n        b[j] += a[i] * w[k];\n        if ((k += dk) >= len) k -= len;\n \
    \     }\n    }\n    swap(a, b);\n  }\n\n  static void ntt_base2(vector<mint> &a)\
    \ {\n    static vector<int> btr;\n    int N = a.size();\n    assert(N % 2 == 0);\n\
    \n    if (btr.size() != a.size()) {\n      btr.resize(N);\n      int b = __builtin_ctz(N);\n\
    \      assert(N == (1 << b));\n      for (int i = 0; i < N; i++) {\n        btr[i]\
    \ = (btr[i >> 1] >> 1) + ((i & 1) << (b - 1));\n      }\n    }\n\n    static vector<mint>\
    \ basis;\n    if (basis.size() < a.size()) {\n      basis.resize(N);\n      mint\
    \ b = w[len / N];\n      for (int i = N >> 1; i > 0; i >>= 1) {\n        mint\
    \ c = 1;\n        for (int j = 0; j < i; ++j) {\n          basis[i + j] = c;\n\
    \          c *= b;\n        }\n        b *= b;\n      }\n    }\n\n    for (int\
    \ i = 0; i < N; i++)\n      if (i < btr[i]) swap(a[i], a[btr[i]]);\n\n    for\
    \ (int k = 1; k < N; k <<= 1) {\n      for (int i = 0; i < N; i += 2 * k) {\n\
    \        for (int j = 0; j < k; j++) {\n          mint z = a[i + j + k] * basis[j\
    \ + k];\n          a[i + j + k] = a[i + j] - z;\n          a[i + j] = a[i + j]\
    \ + z;\n        }\n      }\n    }\n  }\n\n  static void pntt(vector<mint> &a)\
    \ {\n    int P = a.size();\n    if (P <= 64) {\n      dft(a);\n      return;\n\
    \    }\n    if (lader.find(P) == end(lader)) lader[P] = new LaderNTT(P);\n   \
    \ lader[P]->ntt(a);\n  }\n\n  static void ntt(vector<mint> &a) {\n    assert(len\
    \ % a.size() == 0);\n    int N = (int)a.size();\n    if(N <= 1) return;\n    if\
    \ (N <= 64) {\n      dft(a);\n      return;\n    }\n\n    int P = factor(N);\n\
    \    if (P == N) {\n      pntt(a);\n      return;\n    }\n    if (P == 2) {\n\
    \      P = 1 << __builtin_ctz(N);\n      if (N == P) {\n        ntt_base2(a);\n\
    \        return;\n      }\n    }\n\n    int Q = N / P;\n    vector<mint> s(Q),\
    \ t(N), u(P);\n    for (int p = 0, lN = len / N, d = 0; p < P; p++, d += lN) {\n\
    \      for (int q = 0, qP = 0; q < Q; q++, qP += P) s[q] = a[qP + p];\n      ntt(s);\n\
    \      for (int r = 0, n = 0, pQ = p * Q; r < Q; ++r, n += d) {\n        t[pQ\
    \ + r] = w[n] * s[r];\n      }\n    }\n    for (int r = 0; r < Q; r++) {\n   \
    \   for (int p = 0, pQ = 0; p < P; p++, pQ += Q) u[p] = t[pQ + r];\n      if (P\
    \ <= 64)\n        dft(u);\n      else if (P & 1)\n        pntt(u);\n      else\n\
    \        ntt_base2(u);\n      for (int s = 0, sQ = 0; s < P; s++, sQ += Q) a[sQ\
    \ + r] = u[s];\n    }\n  }\n\n  static void intt(vector<mint> &a) {\n    reverse(begin(a)\
    \ + 1, end(a));\n    ntt(a);\n    mint invn = mint(a.size()).inverse();\n    for\
    \ (auto &x : a) x *= invn;\n  }\n\n  static vector<mint> multiply(const vector<mint>\
    \ &a, const vector<mint> &b) {\n    int N = (int)a.size() + (int)b.size() - 1;\n\
    \    assert(N <= len);\n    vector<mint> s(a), t(b);\n    int l = *lower_bound(begin(divisors),\
    \ end(divisors), N);\n    s.resize(l, mint(0));\n    t.resize(l, mint(0));\n \
    \   ntt(s);\n    ntt(t);\n    for (int i = 0; i < l; i++) s[i] *= t[i];\n    intt(s);\n\
    \    s.resize(N);\n    return s;\n  }\n};\ntemplate <typename mint>\nint ArbitraryLengthNTT<mint>::len;\n\
    template <typename mint>\nvector<mint> ArbitraryLengthNTT<mint>::w;\ntemplate\
    \ <typename mint>\nvector<int> ArbitraryLengthNTT<mint>::divisors;\ntemplate <typename\
    \ mint>\nmap<int, typename ArbitraryLengthNTT<mint>::LaderNTT *>\n    ArbitraryLengthNTT<mint>::lader;\n"
  dependsOn: []
  isVerificationFile: false
  path: ntt/cooley-turkey-ntt.hpp
  requiredBy: []
  timestamp: '2020-08-26 14:16:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
documentation_of: ntt/cooley-turkey-ntt.hpp
layout: document
redirect_from:
- /library/ntt/cooley-turkey-ntt.hpp
- /library/ntt/cooley-turkey-ntt.hpp.html
title: ntt/cooley-turkey-ntt.hpp
---
