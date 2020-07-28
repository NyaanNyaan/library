import optuna
import time
import subprocess


def objective(trial):
  x = trial.suggest_uniform('ratio1', -3.0, -0.0)
  y = trial.suggest_uniform('ratio2', -1.0, 2.0)
  cmd = "./a "
  cmd += str(pow(10, x))
  cmd += " "
  cmd += str(pow(10, y))
  d = subprocess.check_output(cmd.split())
  return -float(d)


start = time.time()
study = optuna.create_study()
# optuna.logging.disable_default_handler()
study.optimize(objective, n_trials=60)

print("f(x) = ", study.best_value)
print("x = ", study.best_params)
print(time.time() - start, "ms")
