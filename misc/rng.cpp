unsigned long long rng() {
  static unsigned long long x_ = 88172645463325252ULL;
  x_ = x_ ^ (x_ << 7);
  return x_ = x_ ^ (x_ >> 9);
}