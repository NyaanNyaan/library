#pragma once

// Prime -> {0, 0, 1, 1, 0, 1, 0, 1, ...}
vector<bool> prime_sieve(int N) {
  vector<bool> sieve(max(1, N) + 1, 1);
  sieve[0] = sieve[1] = false;
  for (int i = 2; i * i <= N; i++)
    if (sieve[i] == true)
      for (int j = i * i; j <= N; j += i) sieve[j] = false;
  return sieve;
}
