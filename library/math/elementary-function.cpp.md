---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: math/elementary-function.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/elementary-function.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-27 02:01:03+09:00




## Depends on

* :question: <a href="../competitive-template.cpp.html">competitive-template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify-aoj-ntl/aoj-ntl-1-a.test.cpp.html">verify-aoj-ntl/aoj-ntl-1-a.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-aoj-ntl/aoj-ntl-1-b.test.cpp.html">verify-aoj-ntl/aoj-ntl-1-b.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-aoj-ntl/aoj-ntl-1-c.test.cpp.html">verify-aoj-ntl/aoj-ntl-1-c.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-aoj-ntl/aoj-ntl-1-d.test.cpp.html">verify-aoj-ntl/aoj-ntl-1-d.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-aoj-ntl/aoj-ntl-1-e.test.cpp.html">verify-aoj-ntl/aoj-ntl-1-e.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 306, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: math/elementary-function.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

