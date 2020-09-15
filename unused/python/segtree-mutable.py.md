---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import copy\nclass SegmentTree:\n    def __init__(self, N, func, I):\n  \
    \      self.sz = 2**(N-1).bit_length()\n        self.func = copy.deepcopy(func)\n\
    \        self.I = copy.deepcopy(I)\n        self.seg = [copy.deepcopy(I) for i\
    \ in range(self.sz * 2)]\n\n    def assign(self, k, x):\n        self.seg[k +\
    \ self.sz] = copy.deepcopy(x)\n\n    def build(self):\n        for i in range(self.sz\
    \ - 1, 0, -1):\n            self.seg[i] = self.func(self.seg[2 * i], self.seg[2\
    \ * i + 1])\n\n    def update(self, k, x):\n        k += self.sz\n        self.seg[k]\
    \ = copy.deepcopy(x)\n        while k > 1:\n            k >>= 1\n            self.seg[k]\
    \ = self.func(self.seg[2 * k], self.seg[2 * k + 1])\n\n    def query(self, a,\
    \ b):\n        L = copy.deepcopy(self.I)\n        R = copy.deepcopy(self.I)\n\
    \        a += self.sz\n        b += self.sz\n        while a < b:\n          \
    \  if a & 1:\n                L = self.func(L, self.seg[a])\n                a\
    \ += 1\n            if b & 1:\n                b -= 1\n                R = self.func(self.seg[b],\
    \ R)\n            a >>= 1\n            b >>= 1\n        return self.func(L, R)"
  dependsOn: []
  isVerificationFile: false
  path: unused/python/segtree-mutable.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unused/python/segtree-mutable.py
layout: document
redirect_from:
- /library/unused/python/segtree-mutable.py
- /library/unused/python/segtree-mutable.py.html
title: unused/python/segtree-mutable.py
---
