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
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 85, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from enum import Enum\n\nclass State(Enum):\n  CODE = 1\n  C_COMMENT = 2\n\
    \  CPP_COMMENT = 3\n  STRING_LITERAL = 4\n\ndef remove_garbage(text):\n  result\
    \ = []\n  prev = ''\n  prevprev = ''\n  state = State.CODE\n\n  for ch in text:\n\
    \    if state == State.C_COMMENT:\n      if prevprev != '\\\\' and prev == '*'\
    \ and ch == '/':\n        state = State.CODE\n        prevprev = prev = ''\n \
    \     elif ch == '\\n':\n        result.append('\\n')\n        prevprev = prev\
    \ = ''\n      else:\n        prevprev, prev = prev, ch\n      continue\n\n   \
    \ # Skip to the end of the line (C++ style comment)\n    if state == State.CPP_COMMENT:\n\
    \      if ch == '\\n':  # End comment\n        state = State.CODE\n        result.append('\\\
    n')\n        prevprev = prev = ''\n      continue\n\n    if state == State.STRING_LITERAL:\n\
    \      if prev != '\\\\' and ch == '\"':\n        state = State.CODE\n      result.append(prev)\n\
    \      prevprev, prev = prev, ch\n      continue\n\n    if prevprev != '\\\\'\
    \ and prev == '/' and ch == '*':\n      state = State.C_COMMENT\n      prevprev\
    \ = prev = ''\n      continue\n\n    if prevprev != '\\\\' and prev == '/' and\
    \ ch == '/':\n      state = State.CPP_COMMENT\n      prevprev = prev = ''\n  \
    \    continue\n\n    if prev:\n      if prev != ' ' or ch != ' ':\n        result.append(prev)\n\
    \n    if ch == '\"':\n      state = State.STRING_LITERAL\n    prevprev, prev =\
    \ prev, ch\n\n  if prev:\n    result.append(prev)\n  return ''.join(result)\n\n\
    if __name__ == '__main__':\n  p = \"C:\\\\Users\\\\denjo\\\\Desktop\\\\ABC\\\\\
    library\\\\unused\\\\a.cpp\"\n  with open(p, \"r\", encoding='utf-8') as f:\n\
    \    content = f.read()\n    compressed = remove_garbage(content)\n  with open(p,\
    \ \"w\", encoding='utf-8') as f:\n    f.write(compressed) "
  dependsOn: []
  isVerificationFile: false
  path: compress.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: compress.py
layout: document
redirect_from:
- /library/compress.py
- /library/compress.py.html
title: compress.py
---
