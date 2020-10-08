---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 85, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "class NumberTheroemTransform:\n  def __init__(self, mod, pr):\n    self.mod\
    \ = mod\n    self.pr = pr\n    self.M = 2\n    self.w = [1]\n    self.y = [1]\n\
    \n  def setwy(self, M):\n    if M <= self.M: return\n    self.w += [0] * ((M -\
    \ self.M) // 2)\n    self.y += [0] * ((M - self.M) // 2)\n    self.M = M\n   \
    \ z = pow(self.pr, (self.mod - 1) // self.M, self.mod)\n    x = pow(z, self.mod\
    \ - 2, self.mod)\n    j = M // 4\n    while j:\n      self.w[j] = z\n      z =\
    \ z * z % self.mod\n      self.y[j] = x\n      x = x * x % self.mod\n      j //=\
    \ 2\n    self.y[0] = 1\n    self.w[0] = 1\n    j = self.M // 2\n    js = 2\n \
    \   while js < j:\n      z = self.w[js]\n      x = self.y[js]\n      for k2 in\
    \ range(js):\n        self.w[k2 + js] = self.w[k2] * z % self.mod\n        self.y[k2\
    \ + js] = self.y[k2] * x % self.mod\n      js *= 2\n\n  def fft(self, a):\n  \
    \  mod = self.mod\n    self.setwy(len(a))\n    u = 1\n    v = len(a) >> 1\n  \
    \  while v:\n      for j in range(v):\n        a[j], a[j + v] = a[j] + a[j + v],\
    \ a[j] - a[j + v]\n        if a[j] >= mod:\n          a[j] -= mod\n        if\
    \ a[j + v] < 0:\n          a[j + v] += mod\n      for jh in range(1, u):\n   \
    \     wj = self.w[jh]\n        js = jh * v * 2\n        je = js + v\n        for\
    \ j in range(js, je):\n          ajv = wj * a[j + v] % mod\n          a[j + v]\
    \ = a[j] - ajv\n          if a[j + v] < 0:\n            a[j + v] += mod\n    \
    \      a[j] = a[j] + ajv\n          if a[j] >= mod:\n            a[j] -= mod\n\
    \      u *= 2\n      v >>= 1\n\n  def ifft(self, a):\n    mod = self.mod\n   \
    \ self.setwy(len(a))\n    u = len(a) >> 1\n    v = 1\n    while u:\n      for\
    \ j in range(v):\n        a[j], a[j + v] = a[j] + a[j + v], a[j] - a[j + v]\n\
    \        if a[j] >= mod:\n          a[j] -= mod\n        if a[j + v] < 0:\n  \
    \        a[j + v] += mod\n      for jh in range(1, u):\n        wj = self.y[jh]\n\
    \        js = jh * v * 2\n        je = js + v\n        for j in range(js, je):\n\
    \          ajv = a[j] - a[j + v]\n          if ajv < 0:\n            ajv += mod\n\
    \          a[j] = a[j] + a[j + v]\n          if a[j] >= mod:\n            a[j]\
    \ -= mod\n          a[j + v] = wj * ajv % mod\n      u >>= 1\n      v *= 2\n\n\
    \  def multiply(self, s, t):\n    sl, tl = len(s), len(t)\n    L = sl + tl - 1\n\
    \    M = 2 ** (L - 1).bit_length()\n    s += [0] * (M - sl)\n    t += [0] * (M\
    \ - tl)\n    self.fft(s)\n    self.fft(t)\n    for i in range(M):\n      s[i]\
    \ = s[i] * t[i] % self.mod\n    self.ifft(s)\n    invk = pow(M, self.mod - 2,\
    \ self.mod)\n    for i in range(L):\n      s[i] = s[i] * invk % self.mod\n   \
    \ del s[L:]\n    return s"
  dependsOn: []
  isVerificationFile: false
  path: unused/python/ntt.py
  requiredBy: []
  timestamp: '2020-08-01 13:45:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unused/python/ntt.py
layout: document
redirect_from:
- /library/unused/python/ntt.py
- /library/unused/python/ntt.py.html
title: unused/python/ntt.py
---
