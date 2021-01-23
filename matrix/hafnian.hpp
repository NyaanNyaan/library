#pragma once

template <typename mint>
mint Hafnian(vector<vector<mint>> &mat) {
  using vm = vector<mint>;
  using vvm = vector<vector<mint>>;

  int n = mat.size();
  assert(n % 2 == 0);
  int h = n / 2 + 1;

  auto ad = [&h](vm &x, const vm &a, const vm &b) -> void {
    for (int i = 0; i < h - 1; i++)
      for (int j = 0; j < h - 1 - i; j++) x[i + j + 1] += a[i] * b[j];
  };
  auto solve = [&](auto rc, const vector<vvm> &v) -> vm {
    vm ans(h);
    if (sz(v) == 0) {
      ans[0] = 1;
      return ans;
    }
    int m = v.size() - 2;
    auto V = v;
    V.resize(m);
    vm zero = rc(rc, V);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < i; j++) {
        ad(V[i][j], v[m][i], v[m + 1][j]);
        ad(V[i][j], v[m + 1][i], v[m][j]);
      }
    vm one = rc(rc, V);
    for (int i = 0; i < h; i++) ans[i] += one[i] - zero[i];
    ad(ans, one, v[m + 1][m]);
    return ans;
  };

  vector<vvm> v(n);
  for (int i = 0; i < n; i++) {
    v[i].resize(i, vm(h, 0));
    for (int j = 0; j < i; j++) v[i][j][0] = mat[i][j];
  }
  return solve(solve, v).back();
}
