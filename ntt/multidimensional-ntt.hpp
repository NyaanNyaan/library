#pragma once

// f(vector<mint>& a, bool rev) : 1 次元 DFT (rev は逆変換かどうか)
template <typename T>
struct MultidimensionalFourierTransform {
  vector<int> base;
  function<void(vector<T>&, bool)> dft1d;

  MultidimensionalFourierTransform(const vector<int>& bs,
                                   const function<void(vector<T>&, bool)>& f)
      : base(bs), dft1d(f) {}

  bool ascend(vector<int>& v) {
    int i = 0;
    v[i] += 1;
    while (v[i] == base[i]) {
      if (i == (int)v.size() - 1) return false;
      v[i] = 0;
      v[++i] += 1;
    }
    return true;
  }

  int operator()(vector<int>& a) {
    int res = a[0], coeff = 1;
    for (int i = 1; i < (int)a.size(); i++)
      coeff *= base[i - 1], res += coeff * a[i];
    return res;
  }

  void inner(vector<T>& a, int dim, bool rev = false) {
    int i = 0, shift = 1, n = base[dim];
    vector<T> f(n);
    vector<int> id(base.size());
    for (int j = 0; j < dim; j++) shift *= base[j];
    do {
      if (id[dim] != 0) continue;
      for (int j = 0, t = i; j < n; j++, t += shift) f[j] = a[t];
      dft1d(f, rev);
      for (int j = 0, t = i; j < n; j++, t += shift) a[t] = f[j];
      id[dim] = 0;
    } while (++i && ascend(id));
  }
  void fft(vector<T>& a, bool rev = false) {
    if (!rev)
      for (int i = 0; i < (int)base.size(); i++) inner(a, i);
    else
      for (int i = (int)base.size(); i--;) inner(a, i, true);
  }
};

/**
 * @brief 多次元FFT
 */
