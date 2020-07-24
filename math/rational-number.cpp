struct RationalNumber {
  pair<long long, long long> a;

  RationalNumber(pair<long long, long long> p) { a = init(p.first, p.second); }
  RationalNumber(long long x, long long y) { a = init(x, y); }

  pair<long long, long long> init(long long x, long long y) {
    if (x == 0 && y == 0) return pair<long long, long long>(0, 0);
    long long g = this->gcd(abs(x), abs(y));
    x /= g;
    y /= g;
    if (x < 0) x = -x, y = -y;
    if (x == 0 && y < 0) y = -y;
    return pair<long long, long long>(x, y);
  }

  long long gcd(long long x, long long y) {
    long long z;
    if (x > y) swap(x, y);
    while (x) {
      x = y % (z = x);
      y = z;
    }
    return y;
  }
  bool zero() const { return a.first == 0 && a.second == 0; }
  RationalNumber orth() const { return RationalNumber{-a.second, a.first}; }
};
namespace std {
bool operator<(const RationalNumber &x, const RationalNumber &y) {
  return x.a < y.a;
}
bool operator==(const RationalNumber &x, const RationalNumber &y) {
  return x.a == y.a;
}
bool operator!=(const RationalNumber &x, const RationalNumber &y) {
  return x.a != y.a;
}
}  // namespace std