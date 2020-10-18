---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 85, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: 'from sys import setrecursionlimit, stdin

    from functools import lru_cache

    from bisect import bisect_left as lb, bisect_right as ub

    from collections import deque, defaultdict

    from heapq import heapify, heappop, heappush

    from math import gcd, ceil, sqrt

    setrecursionlimit(10 ** 7)

    inf = 1 << 61

    rg, wt = range, print

    rd = lambda: int(stdin.readline())

    rds = lambda: map(int, stdin.readline().split())

    rdl = lambda: list(map(int, stdin.readline().split()))

    '
  dependsOn: []
  isVerificationFile: false
  path: unused/python/template.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unused/python/template.py
layout: document
redirect_from:
- /library/unused/python/template.py
- /library/unused/python/template.py.html
title: unused/python/template.py
---
