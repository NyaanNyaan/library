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
  code: "import optuna\nimport time\nimport subprocess\n\n\ndef objective(trial):\n\
    \  x = trial.suggest_uniform('ratio1', -3.0, -0.0)\n  y = trial.suggest_uniform('ratio2',\
    \ -1.0, 2.0)\n  cmd = \"./a \"\n  cmd += str(pow(10, x))\n  cmd += \" \"\n  cmd\
    \ += str(pow(10, y))\n  d = subprocess.check_output(cmd.split())\n  return -float(d)\n\
    \n\nstart = time.time()\nstudy = optuna.create_study()\n# optuna.logging.disable_default_handler()\n\
    study.optimize(objective, n_trials=60)\n\nprint(\"f(x) = \", study.best_value)\n\
    print(\"x = \", study.best_params)\nprint(time.time() - start, \"ms\")\n"
  dependsOn: []
  isVerificationFile: false
  path: unused/python/tuning_optuna.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unused/python/tuning_optuna.py
layout: document
redirect_from:
- /library/unused/python/tuning_optuna.py
- /library/unused/python/tuning_optuna.py.html
title: unused/python/tuning_optuna.py
---
