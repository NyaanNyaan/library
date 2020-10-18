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
  code: "import atexit\nimport os\nimport sys\nimport __pypy__\n\n\nclass Fastio:\n\
    \  def __init__(self):\n    self.ibuf = bytes()\n    self.pil = 0\n    self.pir\
    \ = 0\n    self.sb = __pypy__.builders.StringBuilder()\n\n  def load(self):\n\
    \    self.ibuf = self.ibuf[self.pil:]\n    self.ibuf += os.read(0, 131072)\n \
    \   self.pil = 0\n    self.pir = len(self.ibuf)\n\n  def flush(self):\n    os.write(1,\
    \ self.sb.build().encode())\n\n  def fastin(self):\n    if self.pir - self.pil\
    \ < 32:\n      self.load()\n    minus = 0\n    x = 0\n    while self.ibuf[self.pil]\
    \ < 45:\n      self.pil += 1\n    if self.ibuf[self.pil] == 45:\n      minus =\
    \ 1\n      self.pil += 1\n    while self.ibuf[self.pil] >= 48:\n      x = x *\
    \ 10 + (self.ibuf[self.pil] & 15)\n      self.pil += 1\n    if minus:\n      x\
    \ = -x\n    return x\n\n  def fastout(self, x):\n    self.sb.append(str(x))\n\n\
    \  def fastoutln(self, x):\n    self.sb.append(str(x))\n    self.sb.append('\\\
    n')\n\n\nfastio = Fastio()\nrd = fastio.fastin\nwt = fastio.fastout\nwtn = fastio.fastoutln\n\
    atexit.register(fastio.flush)\nsys.stdin, sys.stdout = None, None\n"
  dependsOn: []
  isVerificationFile: false
  path: unused/python/fastio.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unused/python/fastio.py
layout: document
redirect_from:
- /library/unused/python/fastio.py
- /library/unused/python/fastio.py.html
title: unused/python/fastio.py
---
