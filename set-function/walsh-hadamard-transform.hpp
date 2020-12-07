#pragma once

template <typename T>
void walsh_hadamard_transform(vector<T>& f, bool inverse = false) {
  int n = f.size();
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        T x = f[j], y = f[j | i];
        f[j] = x + y, f[j | i] = x - y;
      }
    }
  }
  if (inverse) {
    if constexpr (is_integral<T>::value) {
      for (auto& x : f) x /= n;
    } else {
      T invn = T(1) / T(f.size());
      for (auto& x : f) x *= invn;
    }
  }
}

/**
 * @brief Walsh Hadamard Transform
 */
