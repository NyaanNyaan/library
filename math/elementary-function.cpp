#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

long long my_gcd(long long x, long long y) {
  long long z;
  if (x > y) swap(x, y);
  while (x) {
    x = y % (z = x);
    y = z;
  }
  return y;
}
long long my_lcm(long long x, long long y) {
  return 1LL * x / my_gcd(x, y) * y;
}
#define gcd my_gcd
#define lcm my_lcm

// Prime -> 1 {0, 0, 1, 1, 0, 1, 0, 1, ...}
vector<int> Primes(int N) {
  vector<int> A(N + 1, 1);
  A[0] = A[1] = 0;
  for (int i = 2; i * i <= N; i++)
    if (A[i] == 1)
      for (int j = i << 1; j <= N; j += i) A[j] = 0;
  return A;
}

// Prime Sieve {2, 3, 5, 7, 11, 13, 17, ...}
vector<long long> PrimeSieve(int N) {
  vector<int> prime = Primes(N);
  vector<long long> ret;
  for (int i = 0; i < (int)prime.size(); i++)
    if (prime[i] == 1) ret.push_back(i);
  return ret;
}

// Factors (using for fast factorization)
// {0, 0, 1, 1, 2, 1, 2, 1, 2, 3, ...}
vector<int> Factors(int N) {
  vector<int> A(N + 1, 1);
  A[0] = A[1] = 0;
  for (int i = 2; i * i <= N; i++)
    if (A[i] == 1)
      for (int j = i << 1; j <= N; j += i) A[j] = i;
  return A;
}

// totient function φ(N)=(1 ~ N , gcd(i,N) = 1)
// {0, 1, 1, 2, 4, 2, 6, 4, ... }
vector<int> EulersTotientFunction(int N) {
  vector<int> ret(N + 1, 0);
  for (int i = 0; i <= N; i++) ret[i] = i;
  for (int i = 2; i <= N; i++) {
    if (ret[i] == i)
      for (int j = i; j <= N; j += i) ret[j] = ret[j] / i * (i - 1);
  }
  return ret;
}

// Divisor ex) 12 -> {1, 2, 3, 4, 6, 12}
vector<long long> Divisor(long long N) {
  vector<long long> v;
  for (long long i = 1; i * i <= N; i++) {
    if (N % i == 0) {
      v.push_back(i);
      if (i * i != N) v.push_back(N / i);
    }
  }
  return v;
}

// Factorization
// ex) 18 -> { (2,1) , (3,2) }
vector<pair<long long, int> > PrimeFactors(long long N) {
  vector<pair<long long, int> > ret;
  for (long long p = 2; p * p <= N; p++)
    if (N % p == 0) {
      ret.emplace_back(p, 0);
      while (N % p == 0) N /= p, ret.back().second++;
    }
  if (N >= 2) ret.emplace_back(N, 1);
  return ret;
}

// Factorization with Prime Sieve
// ex) 18 -> { (2,1) , (3,2) }
vector<pair<long long, int> > PrimeFactors(long long N,
                                           const vector<long long> &prime) {
  vector<pair<long long, int> > ret;
  for (auto &p : prime) {
    if (p * p > N) break;
    if (N % p == 0) {
      ret.emplace_back(p, 0);
      while (N % p == 0) N /= p, ret.back().second++;
    }
  }
  if (N >= 2) ret.emplace_back(N, 1);
  return ret;
}

// modpow for mod < 2 ^ 31
long long modpow(long long a, long long n, long long mod) {
  a %= mod;
  long long ret = 1;
  while (n > 0) {
    if (n & 1) ret = ret * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ret % mod;
};

// Check if r is Primitive Root
bool isPrimitiveRoot(long long r, long long mod) {
  r %= mod;
  if (r == 0) return false;
  auto pf = PrimeFactors(mod - 1);
  for (auto &x : pf) {
    if (modpow(r, (mod - 1) / x.first, mod) == 1) return false;
  }
  return true;
}

// Get Primitive Root
long long PrimitiveRoot(long long mod) {
  long long ret = 1;
  while (isPrimitiveRoot(ret, mod) == false) ret++;
  return ret;
}

// Euler's phi function
long long phi(long long n) {
  auto pf = PrimeFactors(n);
  long long ret = n;
  for (auto p : pf) {
    ret /= p.first;
    ret *= (p.first - 1);
  }
  return ret;
}

// Extended Euclidean algorithm
// solve : ax + by = gcd(a, b)
// return : pair(x, y)
pair<long long, long long> extgcd(long long a, long long b) {
  if (b == 0) return make_pair(1, 0);
  long long x, y;
  tie(y, x) = extgcd(b, a % b);
  y -= a / b * x;
  return make_pair(x, y);
}

// Check if n is Square Number
bool isSquare(long long n) {
  if (n == 0 || n == 1) return true;
  long long d = (long long)sqrt(n) - 1;
  while (d * d < n) ++d;
  return d * d == n;
}

// return a number of n's digit
// zero ... return value if n = 0 (default -> 1)
int isDigit(long long n, int zero = 1) {
  if (n == 0) return zero;
  int ret = 0;
  while (n) {
    n /= 10;
    ret++;
  }
  return ret;
}