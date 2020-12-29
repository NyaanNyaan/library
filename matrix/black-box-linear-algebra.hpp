
#include "../fps/berlekamp-massey.hpp"
#include "../fps/formal-power-series.hpp"
#include "../fps/mod-pow.hpp"
#include "../misc/rng.hpp"
//
namespace BBLAImpl {

template <typename mint>
mint inner_product(const FormalPowerSeries<mint>& a,
                   const FormalPowerSeries<mint>& b) {
  mint res = 0;
  int n = a.size();
  assert(n == (int)b.size());
  for (int i = 0; i < n; i++) res += a[i] * b[i];
  return res;
}

template <typename mint>
FormalPowerSeries<mint> random_poly(int n) {
  FormalPowerSeries<mint> res(n);
  for (auto& x : res) x = randint(0, mint::get_mod());
  return res;
}

template <typename mint>
struct ModMatrix : vector<FormalPowerSeries<mint>> {
  using fps = FormalPowerSeries<mint>;

  ModMatrix(int n) : vector<fps>(n, fps(n)) {}

  inline void add(int i, int j, mint x) { (*this)[i][j] += x; }

  friend fps operator*(const ModMatrix& m, const fps& r) {
    int n = m.size();
    assert(n == (int)r.size());
    fps res(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) res[i] += m[i][j] * r[j];
    return res;
  }

  void apply(int i, mint r) {
    int n = (*this).size();
    for (int j = 0; j < n; j++) (*this)[i][j] *= r;
  }
};

template <typename mint>
struct SparseMatrix : vector<vector<pair<int, mint>>> {
  using fps = FormalPowerSeries<mint>;

  template <typename... Args>
  SparseMatrix(Args... args) : vector<vector<pair<int, mint>>>(args...) {}

  inline void add(int i, int j, mint x) { (*this)[i].emplace_back(j, x); }

  friend fps operator*(const SparseMatrix& m, const fps& r) {
    int n = m.size();
    assert(n == (int)r.size());
    fps res(n);
    for (int i = 0; i < n; i++)
      for (auto&& [j, x] : m[i]) res[i] += x * r[j];
    return res;
  }

  void apply(int i, mint r) {
    for (auto&& [_, x] : (*this)[i]) x *= r;
  }
};

template <typename mint>
FormalPowerSeries<mint> vector_minpoly(
    const vector<FormalPowerSeries<mint>>& b) {
  assert(!b.empty());
  int n = b.size(), m = b[0].size();
  FormalPowerSeries<mint> u = random_poly<mint>(m), a(n);
  for (int i = 0; i < n; i++) a[i] = inner_product(b[i], u);
  auto mp = BerlekampMassey<mint>(a);
  return {mp.begin(), mp.end()};
}

template <typename mint, typename Mat>
FormalPowerSeries<mint> mat_minpoly(const Mat& A) {
  int n = A.size();
  FormalPowerSeries<mint> u = random_poly<mint>(n);
  vector<FormalPowerSeries<mint>> b(n * 2 + 1);
  for (int i = 0; i < (int)b.size(); i++) b[i] = u, u = A * u;
  FormalPowerSeries<mint> mp = vector_minpoly(b);
  return mp;
}

// calculate A^k b
template <typename mint, typename Mat>
FormalPowerSeries<mint> fast_pow(const Mat& A, FormalPowerSeries<mint> b,
                                 int64_t k) {
  using fps = FormalPowerSeries<mint>;
  int n = b.size();
  fps mp = mat_minpoly<mint, Mat>(A);
  fps c = mod_pow<mint>(k, fps{0, 1}, mp.rev());
  fps res(n);
  for (int i = 0; i < (int)c.size(); i++) res += b * c[i], b = A * b;
  return res;
}

template <typename mint, typename Mat>
mint fast_det(const Mat& A) {
  using fps = FormalPowerSeries<mint>;
  int n = A.size();
  fps D;
  while (true) {
    do {
      D = random_poly<mint>(n);
    } while (any_of(begin(D), end(D), [](mint x) { return x == mint(0); }));

    Mat AD = A;
    for (int i = 0; i < n; i++) AD.apply(i, D[i]);
    fps mp = mat_minpoly<mint, Mat>(AD);
    if (mp.back() == 0) return 0;
    if ((int)mp.size() != n + 1) continue;
    mint det = n & 1 ? -mp.back() : mp.back();
    mint Ddet = 1;
    for (auto& d : D) Ddet *= d;
    return det / Ddet;
  }
  exit(1);
}

template <typename mint, typename Mat>
FormalPowerSeries<mint> fast_linear_equation(const Mat& A, const FormalPowerSeries<mint>& b) {
  using fps = FormalPowerSeries<mint>;
  int n = A.size();
  fps mp = mat_minpoly<mint, Mat>(A).rev();
  fps buf = b, res(n);
  for (int i = 1; i < (int)mp.size(); i++) {
    res = buf * mp[i];
    buf = A * buf;
  }
  return buf * mp[0].inverse();
}

}  // namespace BBLAImpl

using BBLAImpl::fast_det;
using BBLAImpl::fast_pow;
using BBLAImpl::ModMatrix;
using BBLAImpl::SparseMatrix;

/**
 * @brief Black Box Linear Algebra
 */
