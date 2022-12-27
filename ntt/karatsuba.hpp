#pragma once

namespace KaratsubaImpl {
  
template <typename T>
vector<T> naive(const vector<T>& a, const vector<T>& b) {
  if (a.empty() and b.empty()) return {};
  if (a.size() < b.size()) return naive(b, a);
  int s = a.size(), t = b.size();
  vector<T> c(s + t - 1);
  for (int i = 0; i < s; i++) {
    for (int j = 0; j < t; j++) c[i + j] += a[i] * b[j];
  }
  return c;
}

template <typename T>
void add(vector<T>& a, const vector<T>& b) {
  if (a.size() < b.size()) a.resize(b.size());
  for (int i = 0; i < (int)b.size(); i++) a[i] += b[i];
}
template <typename T>
void sub(vector<T>& a, const vector<T>& b) {
  if (a.size() < b.size()) a.resize(b.size());
  for (int i = 0; i < (int)b.size(); i++) a[i] -= b[i];
}

template <typename T>
vector<T> karatsuba(const vector<T>& a, const vector<T>& b) {
  if (a.empty() and b.empty()) return {};
  if (a.size() < b.size()) return karatsuba(b, a);
  if (a.size() < 32) return naive(a, b);
  int d = a.size() / 2;
  vector<T> al{begin(a), begin(a) + d}, au{begin(a) + d, end(a)};
  if ((int)b.size() < d + 10) {
    auto cl = karatsuba(al, b);
    auto cu = karatsuba(au, b);
    vector<T> c(a.size() + b.size() - 1);
    for (int i = 0; i < (int)cl.size(); i++) c[i] = cl[i];
    for (int i = 0; i < (int)cu.size(); i++) c[i + d] += cu[i];
    return c;
  }
  vector<T> bl{begin(b), begin(b) + d}, bu{begin(b) + d, end(b)};
  vector<T> alu{al}, blu{bl};
  add(alu, au), add(blu, bu);
  auto cll = karatsuba(al, bl);
  auto cuu = karatsuba(au, bu);
  auto clu = karatsuba(alu, blu);
  sub(clu, cll), sub(clu, cuu);
  vector<T> c(d);
  copy(begin(clu), end(clu), back_inserter(c));
  c.resize(a.size() + b.size() - 1);
  add(c, cll);
  for (int i = 0; i < (int)cuu.size(); i++) c[i + 2 * d] += cuu[i];
  c.resize(a.size() + b.size() - 1);
  return c;
}

}  // namespace KaratsubaImpl
using KaratsubaImpl::karatsuba;
