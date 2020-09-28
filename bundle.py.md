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
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 85, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import subprocess\nimport sys\nimport re\nimport io\n\n# oj-bundle\u3092\u4F7F\
    \u7528\u3057\u305F\u969B\u3001Windows\u74B0\u5883\u3060\u3068\n# \u300C#line 3\
    \ \"ntt\\ntt.hpp\"\u300D\u306E\u3088\u3046\u306A\u884C\u304C\u767A\u751F\u3057\
    \u3066\u3057\u307E\u3044\u3001\n# yosupo judge\u3067\u306F'\\n'\u304C\u6539\u884C\
    \u6587\u5B57\u3068\u8A8D\u8B58\u3055\u308C\u308B\u306E\u304BCE\u306B\u306A\u308B\
    \n# \u305D\u308C\u3092\u9632\u3050\u305F\u3081\u306B\u4F5C\u3063\u305F\u96D1\u306A\
    \u30E9\u30C3\u30D1\u30FC\n\n# \u51FA\u529B\u3092utf-8\u306B\u3059\u308B(\u3053\
    \u308C\u3092\u3057\u306A\u3044\u3068win\u3067\u306F\u6587\u5B57\u5316\u3051\u3059\
    \u308B)\nsys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')\n\n\
    args = sys.argv\nif len(args) < 2:\n    exit()\nbuffer = 'buf.cpp'\n\nbuf = open(buffer,\
    \ mode='w', encoding='utf-8')\nwith open(args[1], mode='r', encoding='utf-8')\
    \ as f:\n    lines = f.readlines()   \n    for line in lines:\n        buf.write(line)\n\
    \        # #include\u540C\u58EB\u306F1\u884C\u7A7A\u3051\u308B\n        if len(line)\
    \ > 0 and line[0] == '#':\n            buf.write('\\n')\nbuf.close()\n\nimport\
    \ datetime\nprint(\"// \" + str(datetime.datetime.now()))\ncmd = \"oj-bundle \"\
    \ + buffer\nsrc = subprocess.check_output(cmd.split()).decode(\"utf-8\")\nlines\
    \ = src.split('\\n')\nfor line in lines:\n    if not re.match('^#line', line):\n\
    \        print(line, end='')\n"
  dependsOn: []
  isVerificationFile: false
  path: bundle.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bundle.py
layout: document
redirect_from:
- /library/bundle.py
- /library/bundle.py.html
title: bundle.py
---
