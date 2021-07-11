import subprocess

indir = "./in"

score_sum = 0

for t in range(30):
  s = str()
  x = t
  for i in range(4):
    s = str(x % 10) + s
    x //= 10

  filename = indir + "/" + s + ".txt"

  subprocess.run(
      [
          "a",
          "<",
          filename,
          ">",
          "output"
      ],
      shell=True
  )

  proc = subprocess.run(
      [
          "cargo",
          "run",
          "--release",
          "--bin",
          "vis",
          filename,
          "output"
      ], stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True
  )
  output = proc.stdout.decode("utf-8")

  score = int(output.split()[-1])
  print("Score : ", score)
  score_sum += score

print(score_sum)
