---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/constexpr-primitive-root.hpp
    title: math/constexpr-primitive-root.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/dual-fps.test.cpp
    title: verify/verify-unit-test/dual-fps.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1504.test.cpp
    title: verify/verify-yuki/yuki-1504.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5468\u6CE2\u6570\u9818\u57DF\u3067\u306E\u5024\u3092\u4FDD\u6301\
      \u3059\u308BFPS"
    links: []
  bundledCode: "#line 2 \"fps/dual-fps.hpp\"\n\n#pragma GCC target(\"avx2\")\n#pragma\
    \ GCC optimize(\"O3,unroll-loops\")\n\n#line 2 \"math/constexpr-primitive-root.hpp\"\
    \n\nconstexpr unsigned int constexpr_primitive_root(unsigned int mod) {\n  using\
    \ u32 = unsigned int;\n  using u64 = unsigned long long;\n  if(mod == 2) return\
    \ 1;\n  u64 m = mod - 1, ds[32] = {}, idx = 0;\n  for (u64 i = 2; i * i <= m;\
    \ ++i) {\n    if (m % i == 0) {\n      ds[idx++] = i;\n      while (m % i == 0)\
    \ m /= i;\n    }\n  }\n  if (m != 1) ds[idx++] = m;\n  for (u32 _pr = 2, flg =\
    \ true;; _pr++, flg = true) {\n    for (u32 i = 0; i < idx && flg; ++i) {\n  \
    \    u64 a = _pr, b = (mod - 1) / ds[i], r = 1;\n      for (; b; a = a * a % mod,\
    \ b >>= 1)\n        if (b & 1) r = r * a % mod;\n      if (r == 1) flg = false;\n\
    \    }\n    if (flg == true) return _pr;\n  }\n}\n\n#line 7 \"fps/dual-fps.hpp\"\
    \n\n/**\n * (1) deg(f) <= 1 (\u5B9A\u6570\u95A2\u6570) ... top\u306B\u5024\u3092\
    \u4FDD\u6301\n * (2) deg(f) >= 2\n *   (a) deg == 2^b + 1\n *     len(F) = 2^b,\
    \ top = [x^{2^b}] f \u3068\u3057\u3066\u4FDD\u6301\n *   (b) otherwise\n *   \
    \  F = ntt(f)\u3068\u3057\u3066\u666E\u901A\u306B\u4FDD\u6301\n */\n\ntemplate\
    \ <typename mint>\nstruct Zeta {\n  static constexpr int pr = constexpr_primitive_root(mint::get_mod());\n\
    \  static constexpr int S = __builtin_ctz(mint::get_mod() - 1);\n  static constexpr\
    \ mint one{1};\n  mint zeta[S + 1];\n  constexpr Zeta() : zeta() {\n    zeta[S]\
    \ = mint(constexpr_primitive_root(mint::get_mod()));\n    zeta[S] = zeta[S].pow((mint::get_mod()\
    \ - 1) >> S);\n    for (int i = S - 1; i >= 0; i--) {\n      zeta[i] = zeta[i\
    \ + 1] * zeta[i + 1];\n    }\n  }\n  inline mint operator[](int i) const { return\
    \ zeta[i]; }\n};\n\ntemplate <typename fps>\nstruct DualFPS {\n  using mint =\
    \ typename fps::value_type;\n  fps f;\n  int deg;\n  mint top;\n  static constexpr\
    \ Zeta<mint> zeta{};\n  static vector<int> btr;\n\n  explicit DualFPS() : deg(0),\
    \ top() {}\n  explicit DualFPS(const fps& g) : f(g), deg(g.size()), top() {\n\
    \    if (g.empty()) return;\n    if (g.size() == 1) {\n      f.clear();\n    \
    \  top = g[0];\n      if (top == mint()) deg = 0;\n      return;\n    }\n    top\
    \ = g.back();\n    int cap = get_cap(deg);\n    if (deg == cap + 1) {\n      f.pop_back();\n\
    \      f[0] += top;\n    } else {\n      f.resize(cap);\n    }\n    f.ntt();\n\
    \  }\n\n  DualFPS& operator+=(const mint& r) {\n    if (r == mint()) return *this;\n\
    \    if (f.empty()) {\n      top += r;\n      (*this).deg = 1;\n    } else {\n\
    \      for (auto& x : f) x += r;\n    }\n    return *this;\n  }\n\n  DualFPS&\
    \ operator*=(const mint& r) {\n    if (r == mint()) {\n      f.clear();\n    \
    \  deg = 0, top = mint();\n    } else {\n      for (auto& x : f) x *= r;\n   \
    \   top *= r;\n    }\n    return *this;\n  }\n\n  DualFPS& operator+=(DualFPS&\
    \ r) {\n    DualFPS& l{*this};\n    if (r.deg <= 1) return l += r.top;\n    if\
    \ (l.deg <= 1) {\n      mint lt = l.top;\n      return l = r + lt;\n    }\n\n\
    \    int d = max(l.deg, r.deg);\n    int cap = max<int>(get_cap(d), max(l.f.size(),\
    \ r.f.size()));\n    l.change_factor(cap);\n    r.change_factor(cap);\n\n    for\
    \ (int i = 0; i < cap; i++) l.f[i] += r.f[i];\n    if (l.deg == r.deg) {\n   \
    \   l.top += r.top;\n    } else if (r.deg > l.deg) {\n      l.top = r.top;\n \
    \   }\n    l.deg = d;\n    return l;\n  }\n\n  DualFPS& operator-=(DualFPS& r)\
    \ {\n    DualFPS& l{*this};\n    if (r.deg <= 1) return l -= r.top;\n    if (l.deg\
    \ <= 1) {\n      mint lt = l.top;\n      return l = (-r) + lt;\n    }\n\n    int\
    \ d = max(l.deg, r.deg);\n    int cap = max<int>(get_cap(d), max(l.f.size(), r.f.size()));\n\
    \    l.change_factor(cap);\n    r.change_factor(cap);\n\n    for (int i = 0; i\
    \ < cap; i++) l.f[i] -= r.f[i];\n    if (l.deg == r.deg) {\n      l.top -= r.top;\n\
    \    } else if (r.deg > l.deg) {\n      l.top = -r.top;\n    }\n    l.deg = d;\n\
    \    return l;\n  }\n\n  DualFPS& operator*=(DualFPS& r) {\n    DualFPS& l{*this};\n\
    \    if (r.deg <= 1) return l *= r.top;\n    if (l.deg <= 1) {\n      mint lt\
    \ = l.top;\n      return l = r * lt;\n    }\n\n    int d = l.deg + r.deg - 1;\n\
    \    int cap = max<int>(get_cap(d), max(l.f.size(), r.f.size()));\n    l.change_factor(cap);\n\
    \    r.change_factor(cap);\n\n    for (int i = 0; i < cap; i++) l.f[i] *= r.f[i];\n\
    \    l.deg = d;\n    l.top *= r.top;\n    return l;\n  }\n\n  friend DualFPS operator+(DualFPS&\
    \ l, DualFPS& r) {\n    if (r.deg <= 1) return l + r.top;\n    if (l.deg <= 1)\
    \ return r + l.top;\n\n    int d = max(l.deg, r.deg);\n    int cap = max<int>(get_cap(d),\
    \ max(l.f.size(), r.f.size()));\n    l.change_factor(cap);\n    r.change_factor(cap);\n\
    \n    DualFPS res{l};\n    for (int i = 0; i < cap; i++) res.f[i] += r.f[i];\n\
    \    if (l.deg == r.deg) {\n      res.top += r.top;\n    } else if (r.deg > l.deg)\
    \ {\n      res.top = r.top;\n    }\n    res.deg = d;\n    return res;\n  }\n\n\
    \  friend DualFPS operator-(DualFPS& l, DualFPS& r) {\n    if (r.deg <= 1) return\
    \ l - r.top;\n    if (l.deg <= 1) return (-r) += l.top;\n\n    int d = max(l.deg,\
    \ r.deg);\n    int cap = max<int>(get_cap(d), max(l.f.size(), r.f.size()));\n\
    \    l.change_factor(cap);\n    r.change_factor(cap);\n\n    DualFPS res{l};\n\
    \    for (int i = 0; i < cap; i++) res.f[i] -= r.f[i];\n    if (l.deg == r.deg)\
    \ {\n      res.top -= r.top;\n    } else if (r.deg > l.deg) {\n      res.top =\
    \ -r.top;\n    }\n    res.deg = d;\n    return res;\n  }\n\n  friend DualFPS operator*(DualFPS&\
    \ l, DualFPS& r) {\n    if (r.deg <= 1) return l * r.top;\n    if (l.deg <= 1)\
    \ return r * l.top;\n\n    int d = l.deg + r.deg - 1;\n    int cap = max<int>(get_cap(d),\
    \ max(l.f.size(), r.f.size()));\n    l.change_factor(cap);\n    r.change_factor(cap);\n\
    \n    DualFPS res{l};\n    for (int i = 0; i < cap; i++) res.f[i] *= r.f[i];\n\
    \    res.deg = d;\n    res.top = l.top * r.top;\n    return res;\n  }\n\n  DualFPS\
    \ operator-() const {\n    DualFPS buf{*this};\n    buf.top = -buf.top;\n    for\
    \ (auto& x : buf.f) x = -x;\n    return buf;\n  }\n\n  DualFPS& operator-=(const\
    \ mint& r) { return (*this) += -r; }\n  DualFPS operator+(const mint& r) const\
    \ { return DualFPS{*this} += r; }\n  DualFPS operator-(const mint& r) const {\
    \ return DualFPS{*this} += -r; }\n  DualFPS operator*(const mint& r) const { return\
    \ DualFPS{*this} *= r; }\n\n  DualFPS operator<<(int s) {\n    if (s == 0) return\
    \ *this;\n    if (deg <= 1 and top == mint()) return DualFPS{};\n\n    // deg\
    \ >= 1, s >= 1 => d >= 2, cap >= 1\n    int d = deg + s;\n    int cap = max<int>(get_cap(d),\
    \ f.size());\n    (*this).change_factor(cap);\n\n    if ((int)btr.size() < cap)\
    \ {\n      btr.resize(cap);\n      for (int i = 0, lg = __builtin_ctz(cap); i\
    \ < (1 << lg); i++) {\n        btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (lg -\
    \ 1));\n      }\n    }\n\n    int lg1 = __builtin_ctz(cap);\n    int lg2 = __builtin_ctz(btr.size());\n\
    \n    DualFPS res{*this};\n    mint w = zeta[lg1].pow(s), buf{1};\n    for (int\
    \ i = 0; i < cap; i++) {\n      res.f[btr[i] >> (lg2 - lg1)] *= buf;\n      buf\
    \ *= w;\n    }\n    res.deg = d;\n    return res;\n  }\n\n  fps get() const {\n\
    \    if (deg < 2) return fps{top};\n    fps res = f;\n    res.intt();\n    if\
    \ ((int)f.size() + 1 == deg) {\n      res.push_back(top);\n      res[0] -= top;\n\
    \    }\n    return res;\n  }\n\n  friend ostream& operator<<(ostream& os, const\
    \ DualFPS& r) {\n    os << \"deg = \" << r.deg;\n    os << \", cap = \" << r.f.size();\n\
    \    os << \", top = \" << r.top;\n    os << \", ele = [ \";\n    for (auto& x\
    \ : r.get()) os << x << \", \";\n    os << \"]\";\n    return os;\n  }\n\n private:\n\
    \  static inline int get_cap(int d) {\n    if (d <= 1) return 0;\n    if (d ==\
    \ 2) return 1;\n    return 1 << (32 - __builtin_clz(d - 2));\n  }\n\n  void doubling()\
    \ {\n    fps g = f;\n    g.intt();\n    if ((int)f.size() + 1 == deg) g[0] -=\
    \ top + top;\n    int M = g.size();\n    mint r = 1, z = zeta[__builtin_ctz(M)\
    \ + 1];\n    for (int i = 0; i < M; i++) g[i] *= r, r *= z;\n    g.ntt();\n  \
    \  copy(begin(g), end(g), back_inserter(f));\n  }\n\n  void change_factor(unsigned\
    \ int cap) {\n    assert(this->f.size() <= cap);\n    if (this->f.size() == cap)\
    \ return;\n    if (this->f.size() * 2 == cap) {\n      doubling();\n      return;\n\
    \    }\n    if (f.empty()) {\n      f.resize(cap, top);\n    } else {\n      int\
    \ s = this->f.size();\n      f.intt();\n      f.resize(cap);\n      if (s + 1\
    \ == deg) f[0] -= top, f[s] += top;\n      f.ntt();\n    }\n  }\n};\n\ntemplate\
    \ <typename fps>\nvector<int> DualFPS<fps>::btr;\n\n/**\n * @brief \u5468\u6CE2\
    \u6570\u9818\u57DF\u3067\u306E\u5024\u3092\u4FDD\u6301\u3059\u308BFPS\n */\n"
  code: "#pragma once\n\n#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"O3,unroll-loops\"\
    )\n\n#include \"../math/constexpr-primitive-root.hpp\"\n\n/**\n * (1) deg(f) <=\
    \ 1 (\u5B9A\u6570\u95A2\u6570) ... top\u306B\u5024\u3092\u4FDD\u6301\n * (2) deg(f)\
    \ >= 2\n *   (a) deg == 2^b + 1\n *     len(F) = 2^b, top = [x^{2^b}] f \u3068\
    \u3057\u3066\u4FDD\u6301\n *   (b) otherwise\n *     F = ntt(f)\u3068\u3057\u3066\
    \u666E\u901A\u306B\u4FDD\u6301\n */\n\ntemplate <typename mint>\nstruct Zeta {\n\
    \  static constexpr int pr = constexpr_primitive_root(mint::get_mod());\n  static\
    \ constexpr int S = __builtin_ctz(mint::get_mod() - 1);\n  static constexpr mint\
    \ one{1};\n  mint zeta[S + 1];\n  constexpr Zeta() : zeta() {\n    zeta[S] = mint(constexpr_primitive_root(mint::get_mod()));\n\
    \    zeta[S] = zeta[S].pow((mint::get_mod() - 1) >> S);\n    for (int i = S -\
    \ 1; i >= 0; i--) {\n      zeta[i] = zeta[i + 1] * zeta[i + 1];\n    }\n  }\n\
    \  inline mint operator[](int i) const { return zeta[i]; }\n};\n\ntemplate <typename\
    \ fps>\nstruct DualFPS {\n  using mint = typename fps::value_type;\n  fps f;\n\
    \  int deg;\n  mint top;\n  static constexpr Zeta<mint> zeta{};\n  static vector<int>\
    \ btr;\n\n  explicit DualFPS() : deg(0), top() {}\n  explicit DualFPS(const fps&\
    \ g) : f(g), deg(g.size()), top() {\n    if (g.empty()) return;\n    if (g.size()\
    \ == 1) {\n      f.clear();\n      top = g[0];\n      if (top == mint()) deg =\
    \ 0;\n      return;\n    }\n    top = g.back();\n    int cap = get_cap(deg);\n\
    \    if (deg == cap + 1) {\n      f.pop_back();\n      f[0] += top;\n    } else\
    \ {\n      f.resize(cap);\n    }\n    f.ntt();\n  }\n\n  DualFPS& operator+=(const\
    \ mint& r) {\n    if (r == mint()) return *this;\n    if (f.empty()) {\n     \
    \ top += r;\n      (*this).deg = 1;\n    } else {\n      for (auto& x : f) x +=\
    \ r;\n    }\n    return *this;\n  }\n\n  DualFPS& operator*=(const mint& r) {\n\
    \    if (r == mint()) {\n      f.clear();\n      deg = 0, top = mint();\n    }\
    \ else {\n      for (auto& x : f) x *= r;\n      top *= r;\n    }\n    return\
    \ *this;\n  }\n\n  DualFPS& operator+=(DualFPS& r) {\n    DualFPS& l{*this};\n\
    \    if (r.deg <= 1) return l += r.top;\n    if (l.deg <= 1) {\n      mint lt\
    \ = l.top;\n      return l = r + lt;\n    }\n\n    int d = max(l.deg, r.deg);\n\
    \    int cap = max<int>(get_cap(d), max(l.f.size(), r.f.size()));\n    l.change_factor(cap);\n\
    \    r.change_factor(cap);\n\n    for (int i = 0; i < cap; i++) l.f[i] += r.f[i];\n\
    \    if (l.deg == r.deg) {\n      l.top += r.top;\n    } else if (r.deg > l.deg)\
    \ {\n      l.top = r.top;\n    }\n    l.deg = d;\n    return l;\n  }\n\n  DualFPS&\
    \ operator-=(DualFPS& r) {\n    DualFPS& l{*this};\n    if (r.deg <= 1) return\
    \ l -= r.top;\n    if (l.deg <= 1) {\n      mint lt = l.top;\n      return l =\
    \ (-r) + lt;\n    }\n\n    int d = max(l.deg, r.deg);\n    int cap = max<int>(get_cap(d),\
    \ max(l.f.size(), r.f.size()));\n    l.change_factor(cap);\n    r.change_factor(cap);\n\
    \n    for (int i = 0; i < cap; i++) l.f[i] -= r.f[i];\n    if (l.deg == r.deg)\
    \ {\n      l.top -= r.top;\n    } else if (r.deg > l.deg) {\n      l.top = -r.top;\n\
    \    }\n    l.deg = d;\n    return l;\n  }\n\n  DualFPS& operator*=(DualFPS& r)\
    \ {\n    DualFPS& l{*this};\n    if (r.deg <= 1) return l *= r.top;\n    if (l.deg\
    \ <= 1) {\n      mint lt = l.top;\n      return l = r * lt;\n    }\n\n    int\
    \ d = l.deg + r.deg - 1;\n    int cap = max<int>(get_cap(d), max(l.f.size(), r.f.size()));\n\
    \    l.change_factor(cap);\n    r.change_factor(cap);\n\n    for (int i = 0; i\
    \ < cap; i++) l.f[i] *= r.f[i];\n    l.deg = d;\n    l.top *= r.top;\n    return\
    \ l;\n  }\n\n  friend DualFPS operator+(DualFPS& l, DualFPS& r) {\n    if (r.deg\
    \ <= 1) return l + r.top;\n    if (l.deg <= 1) return r + l.top;\n\n    int d\
    \ = max(l.deg, r.deg);\n    int cap = max<int>(get_cap(d), max(l.f.size(), r.f.size()));\n\
    \    l.change_factor(cap);\n    r.change_factor(cap);\n\n    DualFPS res{l};\n\
    \    for (int i = 0; i < cap; i++) res.f[i] += r.f[i];\n    if (l.deg == r.deg)\
    \ {\n      res.top += r.top;\n    } else if (r.deg > l.deg) {\n      res.top =\
    \ r.top;\n    }\n    res.deg = d;\n    return res;\n  }\n\n  friend DualFPS operator-(DualFPS&\
    \ l, DualFPS& r) {\n    if (r.deg <= 1) return l - r.top;\n    if (l.deg <= 1)\
    \ return (-r) += l.top;\n\n    int d = max(l.deg, r.deg);\n    int cap = max<int>(get_cap(d),\
    \ max(l.f.size(), r.f.size()));\n    l.change_factor(cap);\n    r.change_factor(cap);\n\
    \n    DualFPS res{l};\n    for (int i = 0; i < cap; i++) res.f[i] -= r.f[i];\n\
    \    if (l.deg == r.deg) {\n      res.top -= r.top;\n    } else if (r.deg > l.deg)\
    \ {\n      res.top = -r.top;\n    }\n    res.deg = d;\n    return res;\n  }\n\n\
    \  friend DualFPS operator*(DualFPS& l, DualFPS& r) {\n    if (r.deg <= 1) return\
    \ l * r.top;\n    if (l.deg <= 1) return r * l.top;\n\n    int d = l.deg + r.deg\
    \ - 1;\n    int cap = max<int>(get_cap(d), max(l.f.size(), r.f.size()));\n   \
    \ l.change_factor(cap);\n    r.change_factor(cap);\n\n    DualFPS res{l};\n  \
    \  for (int i = 0; i < cap; i++) res.f[i] *= r.f[i];\n    res.deg = d;\n    res.top\
    \ = l.top * r.top;\n    return res;\n  }\n\n  DualFPS operator-() const {\n  \
    \  DualFPS buf{*this};\n    buf.top = -buf.top;\n    for (auto& x : buf.f) x =\
    \ -x;\n    return buf;\n  }\n\n  DualFPS& operator-=(const mint& r) { return (*this)\
    \ += -r; }\n  DualFPS operator+(const mint& r) const { return DualFPS{*this} +=\
    \ r; }\n  DualFPS operator-(const mint& r) const { return DualFPS{*this} += -r;\
    \ }\n  DualFPS operator*(const mint& r) const { return DualFPS{*this} *= r; }\n\
    \n  DualFPS operator<<(int s) {\n    if (s == 0) return *this;\n    if (deg <=\
    \ 1 and top == mint()) return DualFPS{};\n\n    // deg >= 1, s >= 1 => d >= 2,\
    \ cap >= 1\n    int d = deg + s;\n    int cap = max<int>(get_cap(d), f.size());\n\
    \    (*this).change_factor(cap);\n\n    if ((int)btr.size() < cap) {\n      btr.resize(cap);\n\
    \      for (int i = 0, lg = __builtin_ctz(cap); i < (1 << lg); i++) {\n      \
    \  btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (lg - 1));\n      }\n    }\n\n  \
    \  int lg1 = __builtin_ctz(cap);\n    int lg2 = __builtin_ctz(btr.size());\n\n\
    \    DualFPS res{*this};\n    mint w = zeta[lg1].pow(s), buf{1};\n    for (int\
    \ i = 0; i < cap; i++) {\n      res.f[btr[i] >> (lg2 - lg1)] *= buf;\n      buf\
    \ *= w;\n    }\n    res.deg = d;\n    return res;\n  }\n\n  fps get() const {\n\
    \    if (deg < 2) return fps{top};\n    fps res = f;\n    res.intt();\n    if\
    \ ((int)f.size() + 1 == deg) {\n      res.push_back(top);\n      res[0] -= top;\n\
    \    }\n    return res;\n  }\n\n  friend ostream& operator<<(ostream& os, const\
    \ DualFPS& r) {\n    os << \"deg = \" << r.deg;\n    os << \", cap = \" << r.f.size();\n\
    \    os << \", top = \" << r.top;\n    os << \", ele = [ \";\n    for (auto& x\
    \ : r.get()) os << x << \", \";\n    os << \"]\";\n    return os;\n  }\n\n private:\n\
    \  static inline int get_cap(int d) {\n    if (d <= 1) return 0;\n    if (d ==\
    \ 2) return 1;\n    return 1 << (32 - __builtin_clz(d - 2));\n  }\n\n  void doubling()\
    \ {\n    fps g = f;\n    g.intt();\n    if ((int)f.size() + 1 == deg) g[0] -=\
    \ top + top;\n    int M = g.size();\n    mint r = 1, z = zeta[__builtin_ctz(M)\
    \ + 1];\n    for (int i = 0; i < M; i++) g[i] *= r, r *= z;\n    g.ntt();\n  \
    \  copy(begin(g), end(g), back_inserter(f));\n  }\n\n  void change_factor(unsigned\
    \ int cap) {\n    assert(this->f.size() <= cap);\n    if (this->f.size() == cap)\
    \ return;\n    if (this->f.size() * 2 == cap) {\n      doubling();\n      return;\n\
    \    }\n    if (f.empty()) {\n      f.resize(cap, top);\n    } else {\n      int\
    \ s = this->f.size();\n      f.intt();\n      f.resize(cap);\n      if (s + 1\
    \ == deg) f[0] -= top, f[s] += top;\n      f.ntt();\n    }\n  }\n};\n\ntemplate\
    \ <typename fps>\nvector<int> DualFPS<fps>::btr;\n\n/**\n * @brief \u5468\u6CE2\
    \u6570\u9818\u57DF\u3067\u306E\u5024\u3092\u4FDD\u6301\u3059\u308BFPS\n */\n"
  dependsOn:
  - math/constexpr-primitive-root.hpp
  isVerificationFile: false
  path: fps/dual-fps.hpp
  requiredBy: []
  timestamp: '2023-08-31 20:44:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1504.test.cpp
  - verify/verify-unit-test/dual-fps.test.cpp
documentation_of: fps/dual-fps.hpp
layout: document
redirect_from:
- /library/fps/dual-fps.hpp
- /library/fps/dual-fps.hpp.html
title: "\u5468\u6CE2\u6570\u9818\u57DF\u3067\u306E\u5024\u3092\u4FDD\u6301\u3059\u308B\
  FPS"
---
