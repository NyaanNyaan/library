---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/ahc012/tasks/ahc012_a
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import ctypes\n\nENABLE_PROCESSED_OUTPUT = 0x0001\nENABLE_WRAP_AT_EOL_OUTPUT\
    \ = 0x0002\nENABLE_VIRTUAL_TERMINAL_PROCESSING = 0x0004\nMODE = ENABLE_PROCESSED_OUTPUT\
    \ + ENABLE_WRAP_AT_EOL_OUTPUT + ENABLE_VIRTUAL_TERMINAL_PROCESSING\n\nkernel32\
    \ = ctypes.windll.kernel32\nhandle = kernel32.GetStdHandle(-11)\nkernel32.SetConsoleMode(handle,\
    \ MODE)\n\ndef color_words(s: str, word: str, num: int):\n  escape_seq = \"\\\
    033[\" + str(num) + \"m\"\n  end = '\\033[0m'\n  return s.replace(word, escape_seq\
    \ + word + end)\n\ndef coloring(s: str):\n  res = s[:]\n  res = color_words(res,\
    \ \"FAILURE\", 31)\n  res = color_words(res, \"SUCCESS\", 32)\n  res = color_words(res,\
    \ \"WARNING\", 33)\n  res = color_words(res, \"INFO\", 34)\n  res = color_words(res,\
    \ \"NETWORK\", 35)\n  return res\n\n\nimport subprocess\nimport re\nimport time\n\
    \nurl = \"https://atcoder.jp/contests/ahc012/tasks/ahc012_a\"\ncmd = [\"oj\",\
    \ \"submit\", \"--no-open\", \"--yes\", url, \"./unused/a.cpp\"]\noverhead = 2.5\n\
    interval = 300.0\nepsilon = 0.1\n\nwhile True:\n  while True:\n    print(\"Start\
    \ submission...\", flush=True)\n    proc = subprocess.run(cmd, stdout=subprocess.PIPE)\n\
    \    err = proc.stdout.decode()\n    returncode = proc.returncode\n\n    print(coloring(err),\
    \ flush=True)\n    print(\"return code : \", returncode, flush=True)\n    if returncode\
    \ == 0:\n      break\n    pattern = r\"Wait for [0-9]* second to submit again.\"\
    \n    sentence = re.search(pattern, err)[0]\n    print(sentence, type(sentence))\n\
    \    must_wait = int(re.findall(r\"\\d+\", sentence)[0])\n    print(\"second :\
    \ \", must_wait)\n    time.sleep(max(epsilon, must_wait - overhead))\n\n  s =\
    \ time.time()\n  while time.time() - s < interval - overhead:\n    time.sleep(epsilon)\n"
  dependsOn: []
  isVerificationFile: false
  path: auto_submit.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: auto_submit.py
layout: document
redirect_from:
- /library/auto_submit.py
- /library/auto_submit.py.html
title: auto_submit.py
---
