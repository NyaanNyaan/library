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
  code: "class SegmentTree:\n    def __init__(self, N, func, I):\n        self.sz\
    \ = 2**(N-1).bit_length()\n        self.func = func\n        self.I = I\n    \
    \    self.seg = [I] * (self.sz * 2)\n \n    def assign(self, k, x):\n        self.seg[k\
    \ + self.sz] = x\n \n    def build(self):\n        for i in range(self.sz - 1,\
    \ 0, -1):\n            self.seg[i] = self.func(self.seg[2 * i], self.seg[2 * i\
    \ + 1])\n \n    def update(self, k, x):\n        k += self.sz\n        self.seg[k]\
    \ = x\n        while k > 1:\n            k >>= 1\n            self.seg[k] = self.func(self.seg[2\
    \ * k], self.seg[2 * k + 1])\n \n    def query(self, a, b):\n        L = self.I\n\
    \        R = self.I\n        a += self.sz\n        b += self.sz\n        while\
    \ a < b:\n            if a & 1:\n                L = self.func(L, self.seg[a])\n\
    \                a += 1\n            if b & 1:\n                b -= 1\n     \
    \           R = self.func(self.seg[b], R)\n            a >>= 1\n            b\
    \ >>= 1\n        return self.func(L, R)"
  dependsOn: []
  isVerificationFile: false
  path: unused/python/segtree-immutable.py
  requiredBy: []
  timestamp: '2020-08-01 13:45:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unused/python/segtree-immutable.py
layout: document
redirect_from:
- /library/unused/python/segtree-immutable.py
- /library/unused/python/segtree-immutable.py.html
title: unused/python/segtree-immutable.py
---
